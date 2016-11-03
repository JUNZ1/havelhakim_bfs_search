/*
 * nokta.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: junzi
 */

#include "nokta.h"


char nokta::sisim='a';
nokta::nokta(int girdi)
{
	// TODO Auto-generated constructor stub
	komsu=girdi;
	isim=sisim;
	++sisim;
	pt.x=rand() %400 + 1;
	pt.y=rand() %400 + 1;

}

nokta::~nokta()
{
	// TODO Auto-generated destructor stub
}

