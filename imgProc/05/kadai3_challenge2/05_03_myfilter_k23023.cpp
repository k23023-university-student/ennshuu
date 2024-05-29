#include <iostream>
// OpenCV用のヘッダファイル
#include <opencv2/opencv.hpp>
//画像ファイル (サイズは小さめが良い)
#define FILE_NAME "dot_gray_rectangle.jpg"
#define WINDOW_NAME_INPUT "input"
#define WINDOW_NAME_OUTPUT "output"

#define FILTER_SIZE (5)




void printMatrix(const cv::Mat& matrix) {
    // 行列の内容を出力する
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            // 行列の要素を取得
            double element = matrix.at<double>(i, j);
            // fprintfを使用して出力
            fprintf(stdout, "%f ", element);
        }
        fprintf(stdout, "\n");
    }
}





int main(int argc, const char * argv[]) {



 //画像の入力
 cv::Mat src_img; //画像の型と変数

 src_img = cv::imread(FILE_NAME, 0); //画像の読み込みグレースケール
 


 if (src_img.empty()) { //入力失敗の場合
 fprintf(stderr, "File is not opened.\n");
 
 return (-1);
 }

 cv::Mat blur_img;
 
 //フィルタの初期化
 double filter_h[FILTER_SIZE][FILTER_SIZE] = {0};

 for(int i=0;i<FILTER_SIZE;i++){
    
    for(int j=0;j<FILTER_SIZE;j++){
        filter_h[i][j] = 1.0 / (FILTER_SIZE * FILTER_SIZE);
        fprintf(stdout,"%f ",filter_h[i][j]);
    }
    fprintf(stdout,"\n");

 }



 cv::Mat dst_img = cv::Mat(blur_img.size(), CV_8UC1);
 
//printMatrix(kernel);
  //閾値から2値化
//   for(int y=0;y<dst_img.rows;y++){//縦

//     for(int x=0;x<dst_img.cols;x++){//横

//         uchar s = blur_img.at<uchar>(y,x);
//         if(s < 70) dst_img.at<uchar>(y,x) = 255;
//         else dst_img.at<uchar>(y,x) = 0;
//     }

//  }



 cv::imshow(WINDOW_NAME_INPUT, src_img);
//  cv::imshow(WINDOW_NAME_OUTPUT, dst_img);

 cv::waitKey();
 return 0;
}
