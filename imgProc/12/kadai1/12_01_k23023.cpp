

#include <iostream>
#include <opencv2/opencv.hpp>

//----------------------------

// 全体の画像 (探索対象画像) のファイル名
#define TARGET_IMG_FILE "gazoDora.jpg"

// テンプレート画像
#define TEMPLATE_IMG_YELLOW "yellow.jpg"
#define TEMPLATE_IMG_GREEN "green.jpg"
#define TEMPLATE_IMG_RED "red.jpg"
#define TEMPLATE_IMG_STAR "star.jpg"
#define TEMPLATE_IMG_ARRAY                                                           \
    {                                                                                \
        TEMPLATE_IMG_YELLOW, TEMPLATE_IMG_GREEN, TEMPLATE_IMG_RED, TEMPLATE_IMG_STAR \
    }
//----------------------------

int main(int argc, const char *argv[])
{
    cv::Mat src_img, result_img;
    char *template_img_path_array[] = TEMPLATE_IMG_ARRAY;

    // 入力画像
    src_img = cv::imread(TARGET_IMG_FILE, cv::IMREAD_COLOR);

    if (src_img.empty())
    {
        fprintf(stderr, "File is not opened.\n");

        return (-1);
    }

    // 結果画像
    result_img = cv::Mat(src_img.size(), CV_8UC1);
    result_img = src_img.clone(); // 画像のコピー

    // ここまでが初期化 (前処理)
    //------------------------------------------------------------

    // テンプレートマッチング
    fprintf(stderr, "テンプレートマッチングの開始\n");
    // 全てのテンプレート画像に対しループを回す
    for (const char *template_img_path : template_img_path_array)
    {
        cv::Scalar rgb;

        // テンプレート画像
        cv::Mat template_img = cv::imread(template_img_path, cv::IMREAD_COLOR);

        // 類似度マップ (1チャンネル)
        cv::Mat compare_img = cv::Mat(cv::Size(src_img.rows - template_img.rows + 1, src_img.cols - template_img.cols + 1), CV_32F, 1);
        // テンプレートマッチング
        cv::matchTemplate(src_img, template_img, compare_img, cv::TM_SQDIFF_NORMED);
        
        if (template_img_path == TEMPLATE_IMG_YELLOW)
        {
            rgb = CV_RGB(255, 255, 0);
        }
        else if (template_img_path == TEMPLATE_IMG_RED)
        {
            rgb = CV_RGB(255, 0, 0);
        }
        else if (template_img_path == TEMPLATE_IMG_GREEN)
        {
            rgb = CV_RGB(0, 255, 0);
        }
        else
        {
            rgb = CV_RGB(255, 0, 255);
        }

        for (int y = 0; y < compare_img.rows; y++)
        {

            for (int x = 0; x < compare_img.cols; x++)
            {

                float s = compare_img.at<float>(y, x);
                if (s < 0.1)
                { // 閾値以下

                    // 長方形の表示
                    cv::rectangle(result_img, cv::Point(x,y),
                                  cv::Point(x + template_img.cols,
                                            y + template_img.rows),
                                  rgb, 3);
                }
            }
        }
    }
    fprintf(stderr, "テンプレートマッチングの終了\n");

    // 類似度マップの最小値最大値の計算

    // ここに書く
    // cv::minMaxLoc(compare_img, &min_val, &max_val,
    //               &min_loc, &max_loc);
    // 長方形の表示

    // 探索画像の描画
    cv::imshow("input", src_img);     // 入力画像
    cv::imshow("result", result_img); // 結果画像
    // キー入力待ち
    cv::waitKey(0);

    return 0;
}
