#include <iostream>
// OpenCV用のヘッダファイル
#include <opencv2/opencv.hpp>
// 画像ファイル (サイズは小さめが良い)
#define FILE_NAME1 "issue_input1.jpg"
#define FILE_NAME2 "issue_input2.jpg"
#define WINDOW_NAME_INPUT1 "input1"
#define WINDOW_NAME_INPUT2 "input2"
#define WINDOW_NAME_GAU "gaussianed"
#define WINDOW_NAME_SUB "Sub"
#define WINDOW_NAME_OUTPUT "output"
#define THRESHOLD (20)//閾値
#define FILTER_SIZE (5)
int main(int argc, const char *argv[])
{

    // 画像の入力
    cv::Mat src_img1; //加工済みの画像
    cv::Mat src_img2;//オリジナル画像
    src_img1 = cv::imread(FILE_NAME1, 0); // 画像の読み込みグレースケール
    src_img2 = cv::imread(FILE_NAME2, 0); // 画像の読み込みグレースケール
    cv::Mat gaussian_img2 = cv::Mat(src_img1.size(), CV_8UC1);//input2にガウシアンフィルタをかけた画像
    cv::Mat sub_img = cv::Mat(src_img1.size(), CV_8UC1);//差分画像
    cv::Mat result_img = cv::Mat(src_img1.size(), CV_8UC3);//差分を赤くした画像

    if (src_img1.empty() || src_img2.empty())
    { // 入力失敗の場合
        fprintf(stderr, "File is not opened.\n");
        return (-1);
    }

    cv::GaussianBlur(src_img2, gaussian_img2,cv::Size(FILTER_SIZE, FILTER_SIZE), 0);//まず、無加工のオリジナル画像input2にガウシアンフィルタをかける(フィルタサイズ=5と推定)


    for(int y=0;y<gaussian_img2.rows;y++){//上記のガウシアンフィルタをかけた画像とinput1の画像との差を求める
        for(int x=0;x<gaussian_img2.cols;x++){
            //画素値の取得(double)
            int s1 = (int)gaussian_img2.at<unsigned char>(y, x);
            int s2 = (int)src_img1.at<unsigned char>(y, x);

            int s_result = abs(s1-s2);
            sub_img.at<unsigned char>(y,x) = s_result;

            cv::Vec3b s;
            if(s_result > THRESHOLD){//差分の明るさが閾値を超えていたら赤く塗る、それ以外は黒
                s[0] = 0;
                s[1] = 0;
                s[2] = 255;
            }else{
                s[0] = 0;
                s[1] = 0;
                s[2] = 0;
            }

            result_img.at<cv::Vec3b>(y,x) = s;
        }
    }
    
    cv::imshow(WINDOW_NAME_INPUT1, src_img1);//input1の画像を表示
    cv::imshow(WINDOW_NAME_INPUT2, src_img2);//input2の画像を表示
    cv::imshow(WINDOW_NAME_GAU, gaussian_img2);//input2のガウシアンフィルタ後の画像を表示
    cv::imshow(WINDOW_NAME_SUB, sub_img);//ガウシアンフィルタ後の両者の差分を表示
    cv::imshow(WINDOW_NAME_OUTPUT, result_img);//赤く塗った結果画像を表示
    cv::waitKey();
    return 0;
}