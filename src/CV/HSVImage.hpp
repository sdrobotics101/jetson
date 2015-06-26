#ifndef HSVImage_hpp
#define HSVImage_hpp

#include <opencv2/opencv.hpp>

class HSVImage {
 public:
	HSVImage();
	HSVImage(cv::Mat & rgb_img);
	void load_rgb_image(cv::Mat & rgb_img);
	 cv::Mat rgb;
	 cv::Mat hsv;
	 cv::Mat hue;
	 cv::Mat saturation;
	 cv::Mat value;
};

#endif				// HSVImage_hpp
