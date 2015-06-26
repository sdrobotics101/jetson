#include <opencv2/opencv.hpp>
#include "BaseVideoDevice.hpp"

BaseVideoDevice::BaseVideoDevice()
{
	is_finished = false;
	is_ready = false;
	focal_length = 1.0;
}

BaseVideoDevice::~BaseVideoDevice()
{
}

cv::Mat BaseVideoDevice::get_image()
{
	while (!is_ready) ;
	return image;
}

double BaseVideoDevice::pixels_to_angle(double pixels)
{
	return atan(pixels / focal_length) * 180.0 / M_PI;
}
