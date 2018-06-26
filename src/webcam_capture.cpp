#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<stdio.h>
#include<iostream>

#define JETSON_TX2	1

using namespace cv;

Mat img,gray,res;
char str[]=" \n0.Color \n1.Grayscale \nPress 'c/C' to capture \n Press ESC to exit",k;
const int max_opt=1;
const int min_opt=0;
int opt=0;
char name[20];
int main() 
{
#ifdef JETSON_TX2
    VideoCapture cap=VideoCapture("nvcamerasrc ! video/x-raw(memory:NVMM), width=(int)1280, height=(int)720, format=(string)I420, framerate=(fraction)30/1 ! nvvidconv ! video/x-raw, format=(string)I420 ! videoconvert ! video/x-raw ! appsink");
#else
    VideoCapture cap=VideoCapture(0);
#endif
    if(!cap.isOpened()){  // check if we succeeded
	std::cout << "\nERROR: Failed to VideoCapture\n";
        return -1;
    }

    cap>>img;
    cv::namedWindow("Webcam PhotoCapture");
    createTrackbar(str,"Webcam PhotoCapture",&opt,max_opt,NULL);
    while(true)
    {
	cap>>img;
	k=waitKey(100);
	if(opt==0&&k!=27) {	
	    imshow("Webcam PhotoCapture",img);
	    if(k==99||k==67)
		cv::imwrite("YourImage.jpg",img);
	} else if(opt==1&&k!=27) {
	    cv::cvtColor(img,gray,CV_RGB2GRAY);
	    imshow("Webcam PhotoCapture",gray);
	    if(k==99||k==67)
		cv::imwrite("YourGrayImage.jpg",gray);		
	}
	else if(k==27)
	    break;
    }
}

