

#include <iostream>
#include <opencv2/opencv.hpp>

// 入力画像
#define TARGET_IMG_FILE "issue6.jpg"

// テンプレート画像
#define TEMPLATE_IMG_FILE "red_fish.jpg"
#define MAX_H (180)
#define BIN_TH (20)

int main(int argc, const char *argv[])
{
    cv::Mat src_img, template_img, compare_img, result_img;
    cv::Mat src_gray_img, template_gray_img;
    cv::Mat src_bin_img, template_bin_img;
    cv::Mat src_hsv_img;

    cv::Point min_Point, max_Point;
    double min_val, max_val;

    float s; // 類似度マップ

    // 入力画像
    src_img = cv::imread(TARGET_IMG_FILE, cv::IMREAD_COLOR);

    if (src_img.empty())
    {
        fprintf(stderr, "File is not opened.\n");

        return (-1);
    }

    cv::cvtColor(src_img, src_hsv_img, cv::COLOR_BGR2HSV); // 入力画像のHSV版を生成

    cv::cvtColor(src_img, src_gray_img, cv::COLOR_BGR2GRAY); // 入力画像をグレースケールに

    cv::threshold(src_gray_img, src_bin_img, 20, 255, cv::THRESH_BINARY); // 入力画像を二値化

    // テンプレート画像
    template_img = cv::imread(TEMPLATE_IMG_FILE, cv::IMREAD_COLOR);

    cv::cvtColor(template_img, template_gray_img, cv::COLOR_BGR2GRAY);                  // テンプレート画像をグレースケールに
    cv::threshold(template_gray_img, template_bin_img, BIN_TH, 255, cv::THRESH_BINARY); // テンプレート画像を二値化

    // 類似度マップの初期化
    compare_img = cv::Mat(cv::Size(src_img.rows - template_img.rows + 1, src_img.cols - template_img.cols + 1), CV_32F, 1);

    // 結果画像の初期化、コピー
    result_img = cv::Mat(src_img.size(), CV_8UC1);
    result_img = src_img.clone(); // 画像のコピー

    int hist[MAX_H]; // 色相が幾つ存在するのかを示すヒストグラム

    for (int i = 0; i < MAX_H; i++)
    {
        hist[i] = 0; // ヒストグラムの初期化
    }


    int count = 0;
    do
    {
        // 類似度マップ作成
        //  テンプレートマッチング

        cv::matchTemplate(src_bin_img, template_bin_img, compare_img, cv::TM_SQDIFF_NORMED);

        // 最小値とその場所を求める
        cv::minMaxLoc(compare_img, &min_val, &max_val, &min_Point, &max_Point);

        if (min_val <= 0.033)
        {                           
            cv::Point p2 =  cv::Point(min_Point.x + template_img.cols, min_Point.y + template_img.rows);                                                                                                                // 類似度最小値が条件を満たせば
            cv::rectangle(result_img, min_Point, p2, CV_RGB(255, 0, 0), 3); // 出力画像に描画

            // 一時画像からその領域を削除（塗りつぶす）
            cv::rectangle(src_bin_img, min_Point, p2, CV_RGB(255, 255, 255), -1); // 出力画像に描画

            cv::Vec3b m = src_hsv_img.at<cv::Vec3b>((min_Point.y + p2.y) / 2, (min_Point.x + p2.x) / 2); // 画像中央の色相の取得
            
            hist[m[0]]++; // ヒストグラムに追加
            // 個数を1つ増加
            count++;
        }
    } while (min_val <= 0.033); // 条件を満たさなくなるまで続ける

    for (int i = 0; i < MAX_H; i++)
    {

        if (hist[i] != 0)
        {
            fprintf(stdout, "%d: %d\n", i, hist[i]);
        }
    }
    fprintf(stdout, "合計: %d\n", count);

    // 探索画像の描画
    // cv::imshow("input", src_img);         // 入力画像
    // cv::imshow("template", template_img); // テンプレート画像
    // cv::imshow("result", result_img);     // 結果画像
    // キー入力待ち
    // cv::waitKey(0);

    return 0;
}
