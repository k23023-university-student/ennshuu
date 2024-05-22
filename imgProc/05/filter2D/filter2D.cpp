#include <iostream>
// OpenCV用のヘッダファイル
#include <opencv2/opencv.hpp>
//画像ファイル (サイズは小さめが良い)
#define FILE_NAME "apple_grayscale.jpg"
#define WINDOW_NAME_INPUT "input"
#define WINDOW_NAME_OUTPUT "output"

int main(int argc, const char * argv[]) {



 //画像の入力
 cv::Mat src_img; //画像の型と変数

 src_img = cv::imread(FILE_NAME, 0); //画像の読み込みグレースケール
 


 if (src_img.empty()) { //入力失敗の場合
 fprintf(stderr, "File is not opened.\n");
 return (-1);
 }
 cv::Mat dst_img;
 
 double filter_h[] = { 3., 3., 1.,
                       -1., 2., 1.,
                       0., 2., 2. };
 //配列をフィルタ行列に変換
 //3x3のフィルタサイズ
 cv::Mat kernel = cv::Mat(3, 3, CV_32F, filter_h);
 //正規化
 cv::normalize(kernel, kernel, 1.0, 0.0, cv::NORM_L1);

 cv::filter2D(src_img, dst_img, -1, kernel);

 cv::imshow(WINDOW_NAME_INPUT, src_img);
 cv::imshow(WINDOW_NAME_OUTPUT, dst_img);
 cv::waitKey();
 return 0;
}