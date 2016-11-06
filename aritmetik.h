/*
 * aritmetik.h
 *
 *  Created on: Nov 2, 2016
 *      Author: junzi
 */

#ifndef ARITMETIK_H_
#define ARITMETIK_H_
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "cv.h"
#include "highgui.h"
#include "nokta.h"

using namespace std;
using namespace cv;
class aritmetik
{
public:
	aritmetik();
	virtual ~aritmetik();

};

void sirala(vector<nokta>&);
void yaz(vector<nokta>&);
int dagit(vector<nokta>&);
void cikar(vector<nokta>&,vector<nokta>&);
void komsulari_yaz(vector<nokta>&,const vector<nokta>);
int randla(int);
void grafla(vector<nokta>,Mat &,int);
void bfs(const vector<nokta>);

#endif /* ARITMETIK_H_ */

