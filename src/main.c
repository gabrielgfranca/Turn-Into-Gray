#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { unsigned char r, g, b; } Pixel;

void convertToGrayScale(unsigned char *imgData, int width, int height)
{
    int channels = 3;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int pixelStart = ((y * width) + x) * channels;

            unsigned char r = imgData[pixelStart];
            unsigned char g = imgData[pixelStart + 1];
            unsigned char b = imgData[pixelStart + 2];

            unsigned char gray = (unsigned char)(0.299*r + 0.587*g + 0.114*b);
            imgData[pixelStart] = gray;
            imgData[pixelStart + 1] = gray;
            imgData[pixelStart + 2] = gray;
        }
    }
}

int saveImage(const char *path, Pixel *imgData, int width, int height, int maxColor)
{
    FILE *file = fopen(path, "wb");
    if (!file)
    {
        printf("Could not open file for writing.\n");
        return 1;
    }

    fprintf(file, "P6\n%d %d\n%d\n", width, height, maxColor);
    fwrite(imgData, sizeof(Pixel), width * height, file);
    fclose(file);
    return 0;
}

void buildOutputPath(const char *inputPath, char *outputPath, size_t size)
{
    const char *dot = strrchr(inputPath, '.');
    size_t baseLength = dot ? (size_t)(dot - inputPath) : strlen(inputPath);
    snprintf(outputPath, size, "%.*s_gray.ppm", (int)baseLength, inputPath);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <input.ppm>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file)
    {
        printf("Could not open file.\n");
        return 1;
    }

    char format[3];
    int width, height, maxColor;

    fscanf(file, "%2s", format);
    fscanf(file, "%d %d", &width, &height);
    fscanf(file, "%d", &maxColor);
    fgetc(file);

    if (format[0] != 'P' || format[1] != '6')
    {
        printf("Unsupported file format. Use PPM (P6) format.\n");
        fclose(file);
        return 1;
    }

    Pixel *imgData = (Pixel *)malloc(width * height * sizeof(Pixel));
    if (!imgData)
    {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    if (fread(imgData, sizeof(Pixel), width * height, file) != (size_t)(width * height))
    {    
        printf("Error reading pixel data.\n");
        fclose(file);
        free(imgData);
        return 1;
    }
    fclose(file);

    convertToGrayScale((unsigned char *)imgData, width, height);

    char outputPath[1024];
    buildOutputPath(argv[1], outputPath, sizeof(outputPath));
    if (!saveImage(outputPath, imgData, width, height, maxColor))
    {
        free(imgData);
        return 1;
    }

    printf("Grayscale image saved as: %s\n", outputPath);
    free(imgData);
    return 0;
}
