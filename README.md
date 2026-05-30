# turnIntoGray
Project developed to practice the C language and image manipulation directly via code, without the use of external processing libraries. The program converts a color image to grayscale using the perceptual luminance formula:

```
gray = 0.299×R + 0.587×G + 0.114×B
```

> - **Supported format:** PPM (P6) images only.\
> - README images are in PNG because GitHub does not render PPM.\
> - The original `.ppm` files are ignored by `.gitignore`.

## Compiling

```bash
cmake -B build
cmake --build build
./build/turnIntoGray <imagem.ppm>
```

The converted image is saved in the same directory with the `_gray` suffix:
```
imagem.ppm → imagem_gray.ppm
```

## Examples

| Before | After |
|-------|--------|
| ![](image.png) | ![](image_gray.png) |
| ![](image2.png) | ![](image2_gray.png) |
| ![](image3.png) | ![](image3_gray.png) |
