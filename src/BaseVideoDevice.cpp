/* BaseVideoDevice.cpp -- Implementation of BaseVideoDevice class

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
