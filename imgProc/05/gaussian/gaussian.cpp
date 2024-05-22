#include <iostream>
// OpenCV用のヘッダファイル
#include <opencv2/opencv.hpp>
//画像ファイル (サイズは小さめが良い)
#define FILE_NAME "apple_grayscale.jpg"
#define WINDOW_NAME_INPUT "input"
#define WINDOW_NAME_OUTPUT "output"
#define WINDOW_NAME_OUTPUT2 "output2"
#define FILTER_SIZE (5)
int main(int argc, const char * argv[]) {



 //画像の入力
 cv::Mat src_img; //画像の型と変数

 src_img = cv::imread(FILE_NAME, 0); //画像の読み込みグレースケール
 


 if (src_img.empty()) { //入力失敗の場合
 fprintf(stderr, "File is not opened.\n");
 return (-1);
 }
 //3x3用
 cv::Mat dst_img;


 //配列をフィルタ行列に変換
 //3x3のフィルタサイズ
 cv::GaussianBlur(src_img, dst_img,cv::Size(FILTER_SIZE, FILTER_SIZE), 0);

 cv::imshow(WINDOW_NAME_INPUT, src_img);
 cv::imshow(WINDOW_NAME_OUTPUT, dst_img);
 cv::waitKey();
 return 0;
}