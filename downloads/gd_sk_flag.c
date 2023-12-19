#include <stdio.h>
#include <gd.h>
#include <math.h>

#define PI 3.14159265358979323846

void draw_korean_flag(gdImagePtr img);
void draw_taegeuk(gdImagePtr img, int center_x, int center_y, int outer_radius, int inner_radius, int color);

int main() {
    // 設定圖片寬度和高度
    int width = 1200;
    int height = (int)(width * 2.0 / 3.0);

    // 創建一個 gdImage
    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    // 繪製韓國國旗
    draw_korean_flag(img);

    // 開啟輸出檔案
    FILE *outputFile = fopen("./korean_flag_in_gd.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }

    // 將圖片保存為PNG
    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);

    // 釋放記憶體
    gdImageDestroy(img);

    return 0;
}

void draw_korean_flag(gdImagePtr img) {
    // 獲取圖片的寬度和高度
    int width = gdImageSX(img);
    int height = gdImageSY(img);

    // 定義顏色
    int white = gdImageColorAllocate(img, 255, 255, 255);
    int blue = gdImageColorAllocate(img, 0, 0, 255);

    // 填充白色背景
    gdImageFilledRectangle(img, 0, 0, width, height, white);

    // 韓國國旗的 yin-yang 中央位置
    int center_x = (int)(width / 2.0);
    int center_y = (int)(height / 2.0);

    // 韓國國旗的外圈直徑
    int outer_radius = (int)(width / 3.0);

    // 韓國國旗的內圈直徑
    int inner_radius = (int)(outer_radius * 2 / 3.0);

    // 畫出太極圖案
    draw_taegeuk(img, center_x, center_y, outer_radius, inner_radius, blue);
}

void draw_taegeuk(gdImagePtr img, int center_x, int center_y, int outer_radius, int inner_radius, int color) {
    int num_points = 100;
    gdPoint points[100];

    // 外圈太極多邊形的點
    for (int i = 0; i < num_points; i++) {
        double angle = 2 * PI * i / num_points;
        points[i].x = center_x + outer_radius * cos(angle);
        points[i].y = center_y + outer_radius * sin(angle);
    }

    // 繪製外圈太極多邊形
    gdImageFilledPolygon(img, points, num_points, color);

    // 內圈太極多邊形的點
    for (int i = 0; i < num_points; i++) {
        double angle = 2 * PI * i / num_points;
        points[i].x = center_x + inner_radius * cos(angle);
        points[i].y = center_y + inner_radius * sin(angle);
    }

    // 繪製內圈太極多邊形
    gdImageFilledPolygon(img, points, num_points, white);
  




