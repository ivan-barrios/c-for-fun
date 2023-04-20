#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int format;
    union{
        struct{
            unsigned red : 8;
            unsigned green : 8;
            unsigned blue : 8;
        }RGB24;

        struct{
            unsigned red : 5;
            unsigned green : 6;
            unsigned blue : 5;
        }RGB16;
    }rgbFormats;
} RGB;


void imprimirRGB24(RGB rgb);
void imprimirRGB16(RGB rgb);
void cambiarFormato24a16(RGB *rgb24);
void cambiarFormato16a24(RGB *rgb16);

int main()
{
    RGB color1;
    color1.rgbFormats.RGB16.red = 30;
    color1.rgbFormats.RGB16.green = 30;
    color1.rgbFormats.RGB16.blue = 30;

    imprimirRGB16(color1);

    cambiarFormato16a24(&color1);

    imprimirRGB24(color1);

    return 0;
}



void imprimirRGB24(RGB rgb) {
    printf("RGB: %u %u %u \n", rgb.rgbFormats.RGB24.red, rgb.rgbFormats.RGB24.green, rgb.rgbFormats.RGB24.blue);
}

void imprimirRGB16(RGB rgb) {
    printf("RGB: %u %u %u \n", rgb.rgbFormats.RGB16.red, rgb.rgbFormats.RGB16.green, rgb.rgbFormats.RGB16.blue);
}

void cambiarFormato24a16(RGB *rgb24) {
    rgb24->rgbFormats.RGB16.red = rgb24->rgbFormats.RGB24.red;
    rgb24->rgbFormats.RGB16.green = rgb24->rgbFormats.RGB24.green;
    rgb24->rgbFormats.RGB16.blue = rgb24->rgbFormats.RGB24.blue;
}

void cambiarFormato16a24(RGB *rgb16) {
    rgb16->rgbFormats.RGB24.red = rgb16->rgbFormats.RGB24.red;
    rgb16->rgbFormats.RGB24.green = rgb16->rgbFormats.RGB24.green;
    rgb16->rgbFormats.RGB24.blue = rgb16->rgbFormats.RGB24.blue;
}
