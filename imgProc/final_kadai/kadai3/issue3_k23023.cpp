

#include <iostream>
#include <opencv2/opencv.hpp>


// 入力画像
#define TARGET_IMG_FILE "issue3.jpg"

// テンプレート画像
#define TEMPLATE_IMG_FILE "red_fish.jpg"


int main(int argc, const char *argv[])
{
    cv::Point min_Point, max_loc;
    cv::Mat src_img, template_img, compare_img, result_img;
    cv::Mat src_gray_img, template_gray_img;

    double min_val, max_val;

    float s; // 類似度マップ

    // 入力画像
    src_img = cv::imread(TARGET_IMG_FILE, cv::IMREAD_COLOR);

    if (src_img.empty())
    {
        fprintf(stderr, "File is not opened.\n");

        return (-1);
    }

    cv::cvtColor(src_img, src_gray_img, cv::COLOR_BGR2GRAY);//入力画像をグレースケールに

    // テンプレート画像
    template_img = cv::imread(TEMPLATE_IMG_FILE, cv::IMREAD_COLOR);

    cv::cvtColor(template_img, template_gray_img, cv::COLOR_BGR2GRAY);//テンプレート画像をグレースケールに

    // 類似度マップの初期化
    compare_img = cv::Mat(cv::Size(src_img.rows - template_img.rows + 1, src_img.cols - template_img.cols + 1), CV_32F, 1);

    // 結果画像の初期化、コピー
    result_img = cv::Mat(src_img.size(), CV_8UC1);
    result_img = src_img.clone(); // 画像のコピー


    // テンプレートマッチング

    cv::matchTemplate(src_gray_img, template_gray_img, compare_img, cv::TM_SQDIFF_NORMED);

    // 類似度マップの最小値の計算
    cv::minMaxLoc(compare_img, &min_val, &max_val,
                  &min_Point, &max_loc);


    // 長方形の表示

    cv::rectangle(result_img, min_Point,
                  cv::Point(min_Point.x + template_img.cols,
                            min_Point.y + template_img.rows),
                  CV_RGB(255, 0, 0), 2);

    // 探索画像の描画
    cv::imshow("input", src_img);         // 入力画像
    cv::imshow("template", template_img); // テンプレート画像
    cv::imshow("result", result_img);     // 結果画像
    // キー入力待ち
    cv::waitKey(0);

    return 0;
}
