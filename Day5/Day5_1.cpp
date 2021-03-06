#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <vector>

// Get thresholded image in HSV format
IplImage* GetThresholdedImageHSV( IplImage* img )
{
    // Create an HSV format image from image passed
    IplImage* imgHSV = cvCreateImage( cvGetSize( img ),
                                      8,
                                      3 );

    cvCvtColor( img, imgHSV, CV_BGR2HSV );

    // Create binary thresholded image acc. to max/min HSV ranges
    // For detecting blue gloves in "MOV.MPG - HSV mode
    IplImage* imgThresh = cvCreateImage( cvGetSize( img ),
                                         8,
                                         1 );

    cvInRangeS( imgHSV,
                cvScalar( 104, 178, 70  ),
                cvScalar( 130, 240, 124 ),
                imgThresh );

    cvReleaseImage( &imgHSV );
    return imgThresh;
}

int main()
{
    CvCapture* capture = cvCaptureFromFile(0);
    IplImage* frame = cvQueryFrame( capture );

    // Can't get device? Complain and quit
    if( !capture )
    {
        std::cout << "Could not initialize capturing...\n";
        return -1;
    }

    while (true)
    {
        frame = cvQueryFrame(capture);

        if( !frame ) break;

        IplImage* imgThresh = GetThresholdedImageHSV( frame );
        cv::Mat imageThreshMat = cv::Mat(imgThresh, false);
        cv::Mat frameMat = cv::Mat(frame, false);

        // Find the contours.
        std::vector<std::vector<cv::Point> > contours;
        cv::Mat contourOutput = imageThreshMat.clone();
        cv::findContours( contourOutput, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE );

        //Draw the contours
        cv::Mat contourImage = frameMat.clone();
        for (size_t idx = 0; idx < contours.size(); idx++)
        {
            cv::drawContours(contourImage, contours, idx, cv::Scalar(0, 255, 0));
        }

        cv::imshow("video", contourImage);
        cvWaitKey(40);
    }

    // We're through with using camera.
    cvReleaseCapture( &capture );

    return 0;
}
