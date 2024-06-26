//
//  labeling.cpp
//
//
//  Created by b21702bb on 2021/06/22.
//

#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>

// ファイル
#define FILE_NAME "issue1.jpg"
// ウィンドウ名
#define WINDOW_NAME_INPUT "input"
#define WINDOW_NAME_BINARY "binary"
#define WINDOW_NAME_OUTPUT "output"

// 二値化閾値
#define BIN_TH (100)

int main(int argc, const char *argv[])
{
    // 1. 画像の宣言 (入力画像，グレースケール画像，二値画像，一時的な画像，出力画像)
    cv::Mat src_img, gray_img, bin_img, tmp_img, dst_img;

    // 色値の設定

    // 2. 輪郭の座標リストの宣言
    std::vector<std::vector<cv::Point>> contours;
    std::vector<std::vector<cv::Point>> mask_contours;
    // 3. 画像の入力 (カラーで入力)
    src_img = cv::imread(FILE_NAME);
    if (src_img.empty())
    { // 入力失敗の場合
        fprintf(stderr, "File is not opened.\n");
        return (-1);
    }

    // 4. 入力画像を結果画像にコピー
    dst_img = src_img.clone();

    // 5. グレースケール化
    cv::cvtColor(src_img, gray_img, cv::COLOR_BGR2GRAY);

    // 6. 二値化 (固定閾値で実装．閾値: 100)
    cv::threshold(gray_img, bin_img, BIN_TH, 255, cv::THRESH_BINARY);

    // 二値画像コピー
    tmp_img = bin_img.clone();

    // 7. 輪郭抽出
    cv::findContours(tmp_img, contours, cv::RETR_LIST, cv::CHAIN_APPROX_NONE);

    // 8. 輪郭ループ
    for (int i = 0; i < contours.size(); i++)
    {

        double L = cv::arcLength(contours[i], true);
        double S = cv::contourArea(contours[i]);

        double R = (4 * M_PI) * S / (L * L);

        // 円の検出、消去
        if (R > 0.8)
        {
            cv::drawContours(dst_img, contours, i, CV_RGB(0, 0, 0), cv::FILLED);
            // 収縮
            cv::erode(dst_img, dst_img, cv::Mat(), cv::Point(-1, -1), 1);
            //  膨張
            cv::dilate(dst_img, dst_img, cv::Mat(), cv::Point(-1, -1), 1);
        }
    }
    // 9. マスク用画像の生成、それをグレースケールへ変換
    cv::Mat mask_img;
    cv::cvtColor(dst_img, mask_img, cv::COLOR_BGR2GRAY);
    // 9.1 図形の膨張
    cv::dilate(mask_img, mask_img, cv::Mat(), cv::Point(-1, -1), 20);

    // 10. マスク用画像中の図形の輪郭を求める

    cv::findContours(mask_img, mask_contours, cv::RETR_LIST, cv::CHAIN_APPROX_NONE);

    // 11. マスク画像のラベルによって覆われる領域を色で塗る

    // 色リスト {ピンク、赤}
    cv::Scalar color[] = { CV_RGB(255, 0, 255), CV_RGB(255, 0, 0)};
    for (int i = 0; i < mask_contours.size(); i++)
    {
        cv::Rect bb = cv::boundingRect(mask_contours[i]);

        for (int y = bb.y; y < bb.y + bb.height; y++)
        {

            for (int x = bb.x; x < bb.x + bb.width; x++)
            {
                //グレースケール画像を参考に
                uchar gray_s = gray_img.at<uchar>(y, x);

                cv::Vec3b s;
                if (gray_s > BIN_TH)
                { // グレースケールの閾値を超えたとき、ラベルに割り当てられた色で塗る

                    s[0] = color[i][0];
                    s[1] = color[i][1];
                    s[2] = color[i][2];
                }

                dst_img.at<cv::Vec3b>(y, x) = s;

            }
        }
    }

    //  表示
    cv::imshow(WINDOW_NAME_INPUT, src_img);
    cv::imshow(WINDOW_NAME_BINARY, bin_img);
    cv::imshow("mask img", mask_img);
    cv::imshow(WINDOW_NAME_OUTPUT, dst_img);

    // cv::imwrite("10_k23023.jpg",dst_img);
    cv::waitKey();
    return 0;
}
