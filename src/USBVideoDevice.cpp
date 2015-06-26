/* USBVideoDevice.cpp -- Implementation of USBVideoDevice class

   Copyright (C) 2012, 2013, 2014 Tushar Pankaj
   
   This file is part of San Diego Robotics 101 Robosub.
   
   San Diego Robotics 101 Robosub is free software: you can redistribute it
   and/or modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation, either version 3 of the License,
   or (at your option) any later version.
   
   San Diego Robotics 101 Robosub is distributed in the hope that it will be
   useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
   Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with San Diego Robotics 101 Robosub.  If not, see
   <http://www.gnu.org/licenses/>. */

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
