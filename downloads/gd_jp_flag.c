#include <stdio.h>
#include <gd.h>
#include <math.h>

void draw_japan_flag(gdImagePtr img);
void draw_circle(gdImagePtr img, int x, int y, int radius, int color);

int main() {
    int width = 1200;
    int height = (int)(width * 2.0 / 3.0);

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    draw_japan_flag(img);

    FILE *outputFile = fopen("/tmp/japan_flag.png", "wb");  // 保存到 /tmp 目录
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }

    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);

    return 0;
}

void draw_japan_flag(gdImagePtr img) {
    int width = gdImageSX(img);
    int height = gdImageSY(img);
    int white, red;

    int circle_radius = width / 5;
    int circle_x = width / 2;
    int circle_y = height / 2;

    white = gdImageColorAllocate(img, 255, 255, 255); // 白色
    red = gdImageColorAllocate(img, 255, 0, 0);       // 红色

    // 画白色背景
    gdImageFilledRectangle(img, 0, 0, width, height, white);

    // 画红色圆
    draw_circle(img, circle_x, circle_y, circle_radius, red);
}

void draw_circle(gdImagePtr img, int x, int y, int radius, int color) {
    gdImageFilledEllipse(img, x, y, radius * 2, radius * 2, color);
}