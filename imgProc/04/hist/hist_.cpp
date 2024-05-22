#include <iostream>
// OpenCV用のヘッダファイル
#include <opencv2/opencv.hpp>

//画像ファイル (サイズは小さめが良い)
#define FILE_NAME "./red_rectangle.jpg"
//ウィンドウ名
#define WINDOW_NAME_INPUT "input"
#define WINDOW_NAME_OUTPUT "output"
#define COLOR_MAX (256)


int main(int argc, const char * argv[]) {
    //変数宣言
    int i,x,y;
    int hist[COLOR_MAX] = {0}; //ヒストグラムで使用 //初期化
    
    //画像をグレースケールで入力
    cv::Mat src_img = cv::imread(FILE_NAME, 0);
    if (src_img.empty()) { //読み込み失敗の場合
            fprintf(stderr, "読み込み失敗\n");
            return (-1);
        }

    
    for(y=0; y<src_img.rows; y++){
        for (x=0; x<src_img.cols; x++) {
            //画素値の取得
            unsigned char s = src_img.at<unsigned char>(y,x);
            //画素値の取得
            hist[(int)s]++;
        }
    }
    
    //5.出力(Number or Excel用に印字)
    for(i=0; i<COLOR_MAX; i++){
        printf("%d %d\n", i, hist[i]);
    }
    
    return 0;
}