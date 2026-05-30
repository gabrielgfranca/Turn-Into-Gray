# turnIntoGray

Projeto desenvolvido para praticar a linguagem C e a manipulação de imagens diretamente via código, sem o uso de bibliotecas externas de processamento. O programa converte uma imagem colorida para escala de cinza aplicando a fórmula de luminância perceptual:

```
gray = 0.299×R + 0.587×G + 0.114×B
```

> - **Formato suportado:** apenas imagens PPM (P6).\
> - As imagens do README estão em PNG pois o GitHub não renderiza PPM.\
> - Os arquivos originais `.ppm` e são ignorados pelo `.gitignore`

## Compilando

```bash
cmake -B build
cmake --build build
./build/turnIntoGray <imagem.ppm>
```

A imagem convertida é salva no mesmo diretório com o sufixo `_gray`:

```
imagem.ppm → imagem_gray.ppm
```

## Exemplos

| Antes | Depois |
|-------|--------|
| ![](image.png) | ![](image_gray.png) |
| ![](image2.png) | ![](image2_gray.png) |
| ![](image3.png) | ![](image3_gray.png) |
