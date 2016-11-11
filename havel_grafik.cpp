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
#define w 1000


int main() {
	Mat resim = Mat::zeros( w, w, CV_8UC3 );

	vector<nokta> listem;
	vector<nokta> listem2;
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
	listem2=listem;
	while(stop==0)
	{
		sirala(listem);
		stop=dagit(listem);
		cikar(listem,komsu);
		if(listem.size()==0)
			break;
	}


	grafla(komsu,resim, w);
	komsulari_yaz(komsu,listem2);

	imshow( "pencere", resim );
	waitKey( 0 );
	//bfs(komsu,w);

	dfs(komsu,w);



	cout<<"EOP";
	return(0);

}
