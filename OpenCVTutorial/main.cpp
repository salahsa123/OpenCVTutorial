#include<opencv2/opencv.hpp>//OpenCV header to use VideoCapture class//
#include<iostream>
using namespace std;
using namespace cv;
int main() {
    Mat myImage;//Declaring a matrix to load the frames//
    namedWindow("Video Player");//Declaring the video to show the video//
    VideoCapture cap(0);//Declaring an object to capture stream of frames from default camera//
    if (!cap.isOpened()) { //This section prompt an error message if no video stream is found//
        cout << "No video stream detected" << endl;
        system("pause");
        return-1;
    }
    while (true) { //Taking an everlasting loop to show the video//
        cap >> myImage;
        if (myImage.empty()) { //Breaking the loop if no video frame is detected//
            break;
        }
        imshow("Video Player", myImage);//Showing the video//
        char c = (char)waitKey(25);//Allowing 25 milliseconds frame processing time and initiating break condition//
        if (c == 27) { //If 'Esc' is entered break the loop//
            break;
        }
    }
    cap.release();//Releasing the buffer memory//
    return 0;
}
//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//int main() {
//    
//    cv::Mat image = cv::Mat::zeros(400, 400, CV_8UC3);
//
//    
//    cv::circle(image, cv::Point(200, 200), 100, cv::Scalar(255, 0, 0), 3);
//
//    
//    cv::imshow("Test OpenCV", image);
//
//    
//    cv::waitKey(0);
//
//    return 0;
//}
