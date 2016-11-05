//============================================================================
// Name        : havel_grafik.cpp
// Author      : JUNZI
// Version     :
// Copyright   : #Ozgur Yazilim
// Description : Havel Grafik
//============================================================================

#include <iostream>
#include <random>
#include <opencv2/opencv.hpp>
#include <string>
#include "opencv2/highgui/highgui.hpp"
#include "cv.h"
#include "highgui.h"
#include "nokta.h"
#include "aritmetik.h"
using namespace std;
using namespace cv;
#define w 400


int main() {
	Mat resim = Mat::zeros( w, w, CV_8UC3 );

	vector<nokta> listem;
	vector<nokta> komsu;
	srand(time(NULL));
	int input;

	while(input!=999)
	{
		cout<<"Derece Gir, cikmak icin 999 yaz"<<endl;
		cin>>input;
		listem.push_back(nokta(input));
	}

	listem.pop_back();

	cout<<"Uzunluk "<<listem.size()<<endl;


	int stop=0;
	yaz(listem);
	while(stop==0)
	{
		sirala(listem);
		stop=dagit(listem);
		cikar(listem,komsu);
		if(listem.size()==0)
			break;
	}
	komsulari_yaz(komsu);
//line( resim, komsu[say].pt, Point( 50, 50), Scalar( 255 ), 1,1 );

	for(unsigned int say=0;say<komsu.size();++say)
	{
		string s;
		list<char>::iterator p;
		circle( resim,komsu[say].pt, w/32.0,Scalar( 0,255,0 ),-1, 2 );
		putText(resim,s+komsu[say].isim,komsu[say].pt, CV_FONT_HERSHEY_SIMPLEX, 0.5,cv::Scalar(0, 0, 255),1,8,false);

		p=komsu[say].komsular.begin();
		while(p!=komsu[say].komsular.end())
				{
				for(unsigned int say1=0;say1<komsu.size();++say1)
					{
						if(*p==komsu[say1].isim)
						{
							line( resim, komsu[say].pt, komsu[say1].pt, Scalar( rand() %255 + 1,rand() %255 + 1,rand() %255 + 1 ), 1,1 );
						}
					}
				++p;
				}



	}

	imshow( "pencere", resim );
	waitKey( 0 );
	cout<<"EOP";
	return(0);

}
