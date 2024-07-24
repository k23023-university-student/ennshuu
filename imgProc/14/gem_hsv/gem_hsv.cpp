//
//  gem_hsv.cpp
//  
//
//  Created by Masashi Morimoto on 2024/07/09.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#define FILE_NAME "gem1.jpg"

#define HUE_MIN (20.0) // Hの最小値
#define HUE_MAX (60.0) // Hの最大値
#define SAT_MIN (100.0) // Sの最小値
#define SAT_MAX (200.0) // Sの最小値
#define MAX_VAL (255)
//ウィンドウ名
#define WINDOW_NAME_INPUT "input"
#define WINDOW_NAME_OUTPUT "output"

int main(int argc, const char * argv[]) {
    //変数の宣言
    int x, y;    //走査用
    cv::Vec3b p; //色値(HSV)
    cv::Mat src_img, hsv_img, dst_img; //入力画像，HSV画像，出力画像
    
    // 1. 画像を入力
    src_img = cv::imread(FILE_NAME, cv::IMREAD_COLOR);
    if (src_img.empty()) { //入力失敗の場合
        fprintf(stderr, "Cannot read image file: %s.\n", FILE_NAME);
        return (-1);
    }
    // 2. 出力二値画像の領域を確保（初期値ゼロ：黒）
    dst_img = cv::Mat::zeros(src_img.size(), CV_8UC1);
    // 3. 色変換 (BGR → HSV)
    cv::cvtColor(src_img, hsv_img, cv::COLOR_BGR2HSV);

    // 4. しきい値処理
    for (y=0; y<hsv_img.rows; y++) {
        for (x=0; x<hsv_img.cols; x++) {

            cv::Vec3b s  = hsv_img.at<cv::Vec3b>(y,x);
            uchar r_s;
            if(HUE_MIN < s[0] && s[0] < HUE_MAX && SAT_MIN < s[1] && s[1] < SAT_MAX){
                r_s = 255;
            }else{
                r_s = 0;
            }

            dst_img.at<uchar>(y,x) = r_s;

        }
    }
    
    // 5. 表示
    cv::imshow(WINDOW_NAME_INPUT, src_img);
    cv::imshow(WINDOW_NAME_OUTPUT, dst_img);
    cv::waitKey(); //キー入力待ち (止める)
    
    return 0;
}
