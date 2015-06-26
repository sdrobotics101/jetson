#ifndef USBVideoDevice_hpp
#define USBVideoDevice_hpp

#include <thread>
#include <opencv2/opencv.hpp>
#include "BaseVideoDevice.hpp"

class USBVideoDevice:public BaseVideoDevice {
 public:
	USBVideoDevice(int input_device_id);
	virtual void start();
	 virtual ~ USBVideoDevice();
 protected:
	 virtual void init_camera();
	virtual void capture_from_camera();
	 cv::VideoCapture camera;
	int device_id;
};

#endif				// USBVideoDevice_hpp
