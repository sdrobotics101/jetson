#include <vector>
#include <opencv2/opencv.hpp>
#include "HSVImage.hpp"

HSVImage::HSVImage()
{
}

HSVImage::HSVImage(cv::Mat & input_image)
{
	load_rgb_image(input_image);
}

void HSVImage::load_rgb_image(cv::Mat & input_image)
{
	rgb = input_image.clone();
	cvtColor(rgb, hsv, CV_RGB2HSV);
	std::vector < cv::Mat > slices;
	split(hsv, slices);
	hue = slices.at(0).clone();
	saturation = slices.at(1).clone();
	value = slices.at(2).clone();
}
