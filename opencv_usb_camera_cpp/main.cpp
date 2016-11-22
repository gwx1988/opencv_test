/*************************************************************************
	> File Name: main.cpp
	> Author: Sun Shujun
	> Mail: bisunshujun@163.com 
	> Created Time: 2016年11月21日 星期一 19时29分56秒
 ************************************************************************/
//**[参考]http://www.cnblogs.com/liu-jun/archive/2013/12/24/3489675.html**/
#include <cv.h>
#include <opencv/highgui.h>
#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;

int main(int argc, char *argv[])
{
	CvCapture* pCapture = cvCreateCameraCapture(1);
	cvNamedWindow("Video", 1);

	while(1)
	{
		IplImage* pFrame=cvQueryFrame( pCapture );
		if(!pFrame)break;
		cvShowImage("Video",pFrame);
		char c=cvWaitKey(33);
		if(c==27)break;
	}
	cvReleaseCapture(&pCapture);
	cvDestroyWindow("Video");
	return 0;
}
