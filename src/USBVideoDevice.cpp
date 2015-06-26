#include <cstdlib>
#include <iostream>
#include <thread>
#include <opencv2/opencv.hpp>
#include "BaseVideoDevice.hpp"
#include "USBVideoDevice.hpp"

USBVideoDevice::USBVideoDevice(int input_device_id):BaseVideoDevice()
{
	device_id = input_device_id;
}

void USBVideoDevice::start()
{
	init_camera();
	capture_thread =
	    new std::thread(&USBVideoDevice::capture_from_camera, this);
}

void USBVideoDevice::init_camera()
{
	camera.open(device_id);
	if (!camera.isOpened()) {
		std::cerr << "Unable to open capture device /dev/video" <<
		    device_id << std::endl;
		exit(EXIT_FAILURE);
	}
}

void USBVideoDevice::capture_from_camera()
{
	while (!is_finished) {
		camera >> image;
		is_ready = true;
	}
}

USBVideoDevice::~USBVideoDevice()
{
	is_finished = true;
	capture_thread->join();
	delete capture_thread;
}
