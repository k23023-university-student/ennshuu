#include <iostream>
// OpenCV用のヘッダファイル
#include <opencv2/opencv.hpp>
//画像ファイル (サイズは小さめが良い)
#define FILE_NAME "./red_rectangle.jpg"
#define WINDOW_NAME_INPUT "input"
#define WINDOW_NAME_OUTPUT "output"
#define COLOR_MAX (256)
int main(int argc, const char * argv[]) {

 int i, x, y;//アクセス用の変数
 int hist[COLOR_MAX];//ヒストグラム用配列

 for(i=0;i<COLOR_MAX;i++){//ヒストグラム用の配列の初期化

    hist[i] = 0;
}

 //画像の入力
 cv::Mat src_img; //画像の型と変数

 src_img = cv::imread(FILE_NAME, 0); //画像の読み込みグレースケール
 


 if (src_img.empty()) { //入力失敗の場合
 fprintf(stderr, "読み込み失敗\n");
 return (-1);
 }

//ヒストグラムの生成
for(int y=0;y<src_img.rows;y++){
    for(x=0;x<src_img.cols;x++){

        //画素値の取得
        unsigned char s = src_img.at<unsigned char>(y,x);
        hist[(int)s]++;//画素数の計算

    }

}
//出力
for(i=0;i<COLOR_MAX;i++){
    printf("%d %d\n", i, hist[i]);
    //printf("%d\n",hist[i]);
}
 //cv::imshow(WINDOW_NAME_INPUT, src_img);
 //cv::waitKey();
 return 0;
}