//
//  gem_binarize.cpp
//
//
//  Created by Masashi Morimoto on 2024/07/09.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#define FILE_NAME "gem2.jpg"

#define TH (20)
#define MAX_VAL (255)
// ウィンドウ名
#define WINDOW_NAME_INPUT "input"
#define WINDOW_NAME_GRAYSCALE "grayimage"
#define WINDOW_NAME_OUTPUT "output"

// 緑石の検出に必要な定数たち
#define R_MIN (0)   // Rの最小値
#define R_MAX (50)  // Rの最大値
#define G_MIN (70)  // Gの最小値
#define G_MAX (120) // Gの最大値

//黄石の検出に執拗な定数たち
#define HUE_MIN (25.0) // Hの最小値
#define HUE_MAX (30.0) // Hの最大値
#define SAT_MIN (140.0) // Sの最小値
#define SAT_MAX (200.0) // Sの最大値

#define MAX_VAL (255)
// 膨張収縮用
#define COUNT (15)

void removeNoise(cv::Mat &input_img, cv::Mat &output_img); // 膨張収縮する関数

int main(int argc, const char *argv[])
{
    // 画像変数の宣言
    cv::Mat gray_img, mask_img, bin_img;
    cv::Mat dst_img;

    // 1. 入力画像をカラーで入力
    cv::Mat src_img = cv::imread(FILE_NAME, cv::IMREAD_COLOR);

    // 輪郭の座標リストの宣言
    std::vector<std::vector<cv::Point>> contours;

    if (src_img.empty())
    { // 入力失敗の場合
        fprintf(stderr, "Cannot read image file: %s.\n", FILE_NAME);
        return (-1);
    }
    dst_img = src_img.clone();
    cv::cvtColor(src_img, gray_img, cv::COLOR_BGR2GRAY);
    cv::threshold(gray_img, bin_img, TH, 255, cv::THRESH_BINARY_INV);

    // 黒石の検出

    removeNoise(bin_img, mask_img);
    cv::findContours(mask_img, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);

    for (int i = 0; i < contours.size(); i++)
    {

        cv::Rect bb = cv::boundingRect(contours[i]);
        cv::rectangle(dst_img, bb, CV_RGB(255, 0, 0), 3);
    }
    printf("Black gem = %d\n", (int)contours.size());

    // 緑石の検出
    contours.clear();//輪郭情報のクリア
    mask_img = cv::Mat::zeros(src_img.size(), CV_8UC1);//マスク画像用の配列を一旦リセット
    for (int y = 0; y < src_img.rows; y++)
    {
        for (int x = 0; x < src_img.cols; x++)
        {

            cv::Vec3b s = src_img.at<cv::Vec3b>(y, x);
            uchar s_r;
            if (R_MIN < s[2] && s[2] < R_MAX && G_MIN < s[1] && s[1] < G_MAX) {

                s_r = 255;
            }else {
                s_r = 0;
            }

            mask_img.at<uchar>(y, x) = s_r;
        }
    }
    removeNoise(mask_img, mask_img);
    cv::findContours(mask_img, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);
    for (int i = 0; i < contours.size(); i++)
    {

        cv::drawContours(dst_img, contours, i, CV_RGB(0, 255, 0), -1);
    }
    printf("Green gem = %d\n", (int)contours.size());

    // 黄石の検出
    contours.clear();//輪郭情報のクリア
    mask_img = cv::Mat::zeros(src_img.size(), CV_8UC1);//マスク画像用の配列を一旦リセット

    cv::Mat hsv_img;

    cv::cvtColor(src_img,hsv_img,cv::COLOR_BGR2HSV);

    for (int y=0; y<hsv_img.rows; y++) {
        for(int x=0; x<hsv_img.cols; x++) {

            cv::Vec3b s  = hsv_img.at<cv::Vec3b>(y,x);
            uchar r_s;
            if(HUE_MIN < s[0] && s[0] < HUE_MAX && SAT_MIN < s[1] && s[1] < SAT_MAX){
                r_s = 255;
            }else{
                r_s = 0;
            }

            mask_img.at<uchar>(y,x) = r_s;

        }
    }
    
    removeNoise(mask_img, mask_img);
    cv::findContours(mask_img, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);
    for (int i = 0; i < contours.size(); i++)
    {
        float radius;       // 半径
        cv::Point2f center; // 中心座標
        cv::minEnclosingCircle(contours[i], center, radius);
        cv::circle(dst_img, center, (int)radius, CV_RGB(255, 255, 255), 2); // 赤色2画素
    }

    printf("Golden gem = %d\n", (int)contours.size());

    // 4. 表示
    cv::imshow(WINDOW_NAME_INPUT, src_img);
    cv::imshow(WINDOW_NAME_GRAYSCALE, gray_img);
    cv::imshow("bin", bin_img);
    cv::imshow("mask", mask_img);
    cv::imshow(WINDOW_NAME_OUTPUT, dst_img);
    cv::waitKey(); // キー入力待ち (止める)

    return 0;
}

void removeNoise(cv::Mat &input_img, cv::Mat &output_img)
{ // 膨張収縮によるノイズ除去関数
    output_img = input_img.clone();

    for (int i = 0; i < 10 * 2; i++)
    {

        // 膨張
        cv::dilate(output_img, output_img, cv::Mat(), cv::Point(-1, -1), i);
        // 収縮
        cv::erode(output_img, output_img, cv::Mat(), cv::Point(-1, -1), i);
    }
}
