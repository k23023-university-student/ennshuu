//
//  extractRegion4student.cpp
//  
//
//  Created by Masashi Morimoto on 2023/06/25.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#define FILE_NAME "hand.jpg"

//ウィンドウ名
#define WINDOW_NAME_INPUT "input"
#define WINDOW_NAME_OUTPUT "output"

#define H_MIN (0)
#define H_MAX (40)
#define H_LOW (15)

int main(int argc, const char * argv[]) {

    //画像の宣言 (入力画像，出力画像)
    cv::Mat src_img, dst_img;
    cv::Mat hsv_img;
    // 1. カラー画像の入力
    src_img = cv::imread(FILE_NAME, cv::IMREAD_COLOR);
    if (src_img.empty()) { //入力失敗の場合
        fprintf(stderr, "Cannot read image file: %s.\n", FILE_NAME);
        return (-1);
    }

    // 2. 出力二値画像の領域を確保（初期値ゼロ：黒）
    dst_img = cv::Mat::zeros(src_img.size(), CV_8UC1);
    // HSV変換
    cv::cvtColor(src_img, hsv_img, cv::COLOR_BGR2HSV);

    // 3. しきい値処理
    for (int y = 0; y < src_img.rows; y++) {
        for (int x = 0; x < src_img.cols; x++) {
            cv::Vec3b s = hsv_img.at<cv::Vec3b>(y, x);
            if (s[0] >= H_MIN && s[0] <= H_MAX) {
                s[0] = H_LOW;
            }
            hsv_img.at<cv::Vec3b>(y, x) = s;
        }
    }

    cv::cvtColor(hsv_img, dst_img, cv::COLOR_HSV2BGR);
    // 4. 表示
    cv::imshow(WINDOW_NAME_INPUT, src_img); //入力画像の表示
    cv::imshow(WINDOW_NAME_OUTPUT, dst_img); //出力画像の表示
    cv::waitKey(); //キー入力待ち (止める)
    
    return 0;
}
