//
//  gem_count_black.cpp
//
//
//  Created by Masashi Morimoto on 2024/07/09.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#define FILE_NAME "gem1.jpg"

#define TH (20)
#define MAX_VAL (255)
#define COUNT (15)
// ウィンドウ名
#define WINDOW_NAME_INPUT "input"
#define WINDOW_NAME_BINARY "binary"
#define WINDOW_NAME_OUTPUT "output"

int main(int argc, const char *argv[])
{
    // 画像変数の宣言
    cv::Mat src_img, gray_img, bin_img, tmp_img, dst_img;
    // 輪郭の座標リストの宣言
    std::vector<std::vector<cv::Point>> contours;

    // 1. 画像を入力
    src_img = cv::imread(FILE_NAME, cv::IMREAD_COLOR);
    if (src_img.empty())
    { // 入力失敗の場合
        fprintf(stderr, "Cannot read image file: %s.\n", FILE_NAME);
        return (-1);
    }

    // 2. グレースケール画像
    cv::cvtColor(src_img, gray_img, cv::COLOR_BGR2GRAY);

    // 3. 二値化
    cv::threshold(gray_img, bin_img, TH, MAX_VAL, cv::THRESH_BINARY_INV);

    // 4. クロージング・オープニング

    for (int i = 0; i < COUNT * 2; i++)
    {

        // 膨張
        cv::dilate(bin_img, bin_img, cv::Mat(), cv::Point(-1, -1), i);
        // 収縮
        cv::erode(bin_img, bin_img, cv::Mat(), cv::Point(-1, -1), i);
    }
    dst_img = src_img.clone();

    // 5. 輪郭追跡による領域検出

    cv::findContours(bin_img, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);

    // 6. 外接円を描画
    // dst_img = src_img.clone();  //入力画像を出力画像にコピー
    for (int i = 0; i < contours.size(); i++)
    {

        float radius;       // 半径
        cv::Point2f center; // 中心座標
        cv::minEnclosingCircle(contours[i], center, radius);
        cv::circle(dst_img, center, (int)radius, CV_RGB(255, 0, 0), 2); // 赤色2画素
    }

    // 7. 個数を出力
    std::cout << "Black gem = " << contours.size() << std::endl;

    // 8. 表示
    cv::imshow(WINDOW_NAME_INPUT, src_img);
    cv::imshow(WINDOW_NAME_BINARY, bin_img);
    cv::imshow(WINDOW_NAME_OUTPUT, dst_img);
    cv::waitKey(); // キー入力待ち (止める)

    return 0;
}
