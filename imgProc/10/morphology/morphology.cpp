//
//  contour4student.cpp
//
//
//  Created by Masashi Morimoto on 2024/06/11.
//

#include <iostream>
#include <opencv2/opencv.hpp>

// ファイル
#define FILE_NAME "a_img.jpg"
#define TH (100)

// 二値化しきい値
#define BIN_TH (100)

int main(int argc, const char *argv[])
{

    cv::Mat src_img;

    // 3. 画像の入力 (カラーで入力)
    src_img = cv::imread(FILE_NAME, 0);
    if (src_img.empty())
    { // 入力失敗の場合
        fprintf(stderr, "File is not opened.\n");
        return (-1);
    }
    cv::Mat bin_img = cv::Mat(src_img.size(), CV_8UC1); // 出力画像のメモリ確保
    cv::Mat dst_img /*= cv::Mat(src_img.size(), CV_8UC1)*/;
    for (int y = 0; y < bin_img.rows; y++)
    { // 縦

        for (int x = 0; x < bin_img.cols; x++)
        { // 横

            uchar s = src_img.at<uchar>(y, x);
            if (s > TH)
                s = 255;
            else
                s = 0;
            bin_img.at<uchar>(y, x) = s;
        }
    }

    for (int i = 0; i < 10; i++)
    {

        //収縮
        cv::erode(bin_img, dst_img, cv::Mat(), cv::Point(-1, -1), i);
        // 膨張
        cv::dilate(dst_img, dst_img, cv::Mat(), cv::Point(-1, -1), i);
        cv::imshow("output", dst_img); // 表示
        cv::waitKey();
    }

    return 0;
}
