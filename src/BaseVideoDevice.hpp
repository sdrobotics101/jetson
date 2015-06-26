/* BaseVideoDevice.hpp -- Header file for BaseVideoDevice class

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
