/*
 * nokta.h
 *
 *  Created on: Nov 2, 2016
 *      Author: junzi
 */

#ifndef NOKTA_H_
#define NOKTA_H_
#include <iostream>
#include <list>
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "cv.h"
#include "highgui.h"
using namespace std;

class nokta
{
public:
	nokta(int);
	virtual ~nokta();
	int komsu;
	static char sisim;
	char isim;
	list<char> komsular;
	cv::Point pt;
};


#endif /* NOKTA_H_ */
