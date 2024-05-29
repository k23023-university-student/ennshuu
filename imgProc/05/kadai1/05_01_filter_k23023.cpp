#include <iostream>
// OpenCV用のヘッダファイル
#include <opencv2/opencv.hpp>
//画像ファイル (サイズは小さめが良い)
#define FILE_NAME "apple_grayscale.jpg"
#define WINDOW_NAME_INPUT "input"
#define WINDOW_NAME_OUTPUT "output"

#define FILTER_SIZE (5)

int main(int argc, const char * argv[]) {



 //画像の入力
 cv::Mat src_img; //画像の型と変数

 src_img = cv::imread(FILE_NAME, 0); //画像の読み込みグレースケール
 


 if (src_img.empty() || FILTER_SIZE % 2 == 0) { //入力失敗の場合
 fprintf(stderr, "Error\n");
 
 return (-1);
 }
 //3x3用
 cv::Mat dst_img;


//  double filter_h[] = { 1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0,
//                       1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0,
//                       1.0 / 9.0, 1.0 / 9.0, 1.0 / 9.0 };

 
 double filter_h[FILTER_SIZE * FILTER_SIZE] = {0};

 for(int i=0;i<FILTER_SIZE * FILTER_SIZE;i++){
    filter_h[i] = 1.0 / (FILTER_SIZE * FILTER_SIZE);
 }

 //配列をフィルタ行列に変換
 //3x3のフィルタサイズ
 cv::Mat kernel = cv::Mat(FILTER_SIZE, FILTER_SIZE, CV_32F, filter_h);

 //255を超えないようにするために正規化
 cv::normalize(kernel, kernel, 1.0, 1.0, cv::NORM_L1);


 cv::filter2D(src_img, dst_img, -1, kernel);

 cv::imshow(WINDOW_NAME_INPUT, src_img);
 cv::imshow(WINDOW_NAME_OUTPUT, dst_img);
 cv::waitKey();
 return 0;
}