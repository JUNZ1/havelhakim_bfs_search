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
#include "nokta.h"

using namespace std;

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
void komsulari_yaz(vector<nokta>&);
int randla(int);
#endif /* ARITMETIK_H_ */

