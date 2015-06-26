#ifndef BaseVideoDevice_hpp
#define BaseVideoDevice_hpp

#include <thread>
#include <opencv2/opencv.hpp>

class BaseVideoDevice {
 public:
	BaseVideoDevice();
	virtual ~ BaseVideoDevice();
	virtual void start() = 0;
	 cv::Mat get_image();
	double pixels_to_angle(double pixels);
 protected:
	 virtual void init_camera() = 0;
	virtual void capture_from_camera() = 0;
	 std::thread * capture_thread;
	 cv::Mat image;
	bool is_finished;
	bool is_ready;
	double focal_length;
};

#endif				// BaseVideoDevice_hpp
