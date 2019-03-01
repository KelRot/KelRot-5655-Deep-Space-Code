#include <opencv2/opencv.hpp>
#define PI 3.14159265
#define FOCAL_DIST 635.7142857142//688.2352 
//14.8x8.5 gerçek 117 piksel 50 uzaklık

#define	CAM_INTAKE_DIST 0

float getDistance(cv::RotatedRect rect)
{
	int rectHeight= rect.size.height>rect.size.width ? rect.size.height : rect.size.width;
	return (14.0 * FOCAL_DIST) / (float)rectHeight;
}
float getAngle(float h_left, float h_right)
{
	return asin(abs(h_right - h_left) / 20);//radyan
}

float getHorizontalDistance(cv::RotatedRect leftRect, cv::RotatedRect rightRect, float leftDist, float rightDist, int imageCenter) {
	int middleX = (leftRect.center.x + rightRect.center.x) / 2;
	int offset = middleX - imageCenter;
	return ((leftDist+rightDist) / 2) * offset / FOCAL_DIST;
}

float calculateRadius(float h,float angle,float x) {
	if (angle == 0) {
		return 0;
	}
	else {
		return (h / tan(angle)) + x;
	}

}

std::vector<float> initialProcess()//returns dist_left,dist_right,targetMiddleOffset respectively in a vector
{ 
	int h = 41, s = 231, v = 41;
	int h_to=59,s_to = 255, v_to = 255;

	cv::VideoCapture cam(0);
	cam.set(cv::CAP_PROP_EXPOSURE, -13);
	cv::Mat original,hsv,thresh;

    cam >> original;
    //GaussianBlur(original, hsv, Size(5, 5), 2, 2);
    cvtColor(original, hsv, cv::COLOR_RGB2HSV);
    inRange(hsv, cv::Scalar(h, s, v), cv::Scalar(h_to,s_to,v_to), thresh);
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
    morphologyEx(thresh, thresh,cv::MORPH_OPEN, kernel);
    morphologyEx(thresh, thresh, cv::MORPH_CLOSE, kernel);
    
    std::vector<std::vector<cv::Point>> contours; std::vector<cv::Vec4i> hie; std::vector<cv::RotatedRect> minRects;
    findContours(thresh, contours, hie, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);
    cv::Point2f minRectPoints[4];
    for (int i = 0; i < contours.size(); i++)
    {
        cv::RotatedRect minRect = cv::minAreaRect(cv::Mat(contours[i]));
        minRect.points(minRectPoints);
        minRects.push_back(minRect);
    }
    std::vector<float> left_right_targetMiddleOffset;
    float dist_right=0, dist_left=0, angle=0, targetMiddleOffset=0, radius=0;
    if(minRects.size()>1)
    {
    cv::RotatedRect leftRect = minRects[0];
    cv::RotatedRect rightRect = minRects[1];
    dist_left = getDistance(leftRect);
    dist_right = getDistance(rightRect);
    targetMiddleOffset = getHorizontalDistance(leftRect, rightRect, dist_left, dist_right, hsv.cols / 2);
    left_right_targetMiddleOffset.push_back(dist_left);
    left_right_targetMiddleOffset.push_back(dist_right);
    left_right_targetMiddleOffset.push_back(targetMiddleOffset);
    }
    return  left_right_targetMiddleOffset;
}
