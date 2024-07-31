

#include <iostream>
#include <opencv2/opencv.hpp>


// 入力画像
#define TARGET_IMG_FILE "issue2.jpg"

// テンプレート画像
#define TEMPLATE_IMG_FILE "red_fish.jpg"


int main(int argc, const char *argv[])
{
    cv::Mat src_img, template_img, compare_img, result_img;

    float s; // 類似度マップ

    // 入力画像
    src_img = cv::imread(TARGET_IMG_FILE, cv::IMREAD_COLOR);

    if (src_img.empty())
    {
        fprintf(stderr, "File is not opened.\n");

        return (-1);
    }

    // テンプレート画像
    template_img = cv::imread(TEMPLATE_IMG_FILE, cv::IMREAD_COLOR);

    // 類似度マップの初期化
    compare_img = cv::Mat(cv::Size(src_img.rows - template_img.rows + 1, src_img.cols - template_img.cols + 1), CV_32F, 1);

    // 結果画像の初期化、コピー
    result_img = cv::Mat(src_img.size(), CV_8UC1);
    result_img = src_img.clone(); // 画像のコピー


    // テンプレートマッチング

    cv::matchTemplate(src_img, template_img, compare_img, cv::TM_SQDIFF_NORMED);

    // 長方形の表示

    for (int y = 0; y < compare_img.rows; y++)
        {

            for (int x = 0; x < compare_img.cols; x++)
            {

                float s = compare_img.at<float>(y, x);
                if (s < 0.08)
                { // 閾値以下

                    // 長方形の表示
                    cv::rectangle(result_img, cv::Point(x,y),
                                  cv::Point(x + template_img.cols,
                                            y + template_img.rows),
                                  CV_RGB(255,0,0), 2);
                                 
                                  
                }
            }
        }

    // 探索画像の描画
    cv::imshow("input", src_img);         // 入力画像
    cv::imshow("template", template_img); // テンプレート画像
    cv::imshow("result", result_img);     // 結果画像
    // キー入力待ち
    cv::waitKey(0);

    return 0;
}
