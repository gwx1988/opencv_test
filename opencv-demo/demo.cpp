//【参考】http://blog.sina.com.cn/s/blog_59fabe030101ib67.html
//【参考】http://blog.sina.com.cn/s/blog_c936dba00102vzhu.html
//【参考】http://blog.csdn.net/morewindows/article/details/8239625
//【参考】http://blog.csdn.net/augusdi/article/details/8876459
#include "opencv2/opencv.hpp"
using namespace cv;

int main(int argc, char **argv)
{
    VideoCapture cap(1); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;
 
    Mat edges;
    namedWindow("edges",1);
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        cvtColor(frame, edges, CV_BGR2GRAY);//彩色图像转化为灰度图像
        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);//OpenCV高斯滤波 
        Canny(edges, edges, 0, 30, 3);//OpenCV边缘检测
        imshow("edges", edges);
        if(waitKey(30) >= 0) break;//ESC(ASIIC:30)退出
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
