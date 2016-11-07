/*
 * aritmetik.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: junzi
 */

#include "aritmetik.h"
#include "nokta.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <unistd.h>
aritmetik::aritmetik()
{
	// TODO Auto-generated constructor stub


}

aritmetik::~aritmetik()
{
	// TODO Auto-generated destructor stub
}

void sirala(vector<nokta>& allocator)
{

	nokta temp(allocator[0]);
	bool changed=true;
	unsigned int say;

	while(changed)
	{
		say=0;
		for(unsigned int p=0;p<allocator.size()-1;++p)
		{
			if(allocator[p].komsu<allocator[p+1].komsu)
			{
				changed=true;
				nokta temp(allocator[p+1]);
				allocator[p+1]=allocator[p];
				allocator[p]=temp;
			}
			else
			{
				++say;
			}
		}

		if(say==allocator.size()-1)
			changed=false;
	}

}

void yaz(vector<nokta>& listem)
{
	for(unsigned int index=0;index<listem.size();++index)
	{
		cout<<index<<" indexli kosenin derecesi "<<
				listem[index].komsu<<" ismi "<<listem[index].isim<<endl;
	}

}

int dagit(vector<nokta>& allocator)
{
	vector<nokta>::iterator p;
	vector<nokta>::iterator ilk;
	p=allocator.begin();
	ilk=allocator.begin();
	++p;
	int temp;
	for(int index=0;index<allocator[0].komsu;++index)
	{
		ilk->komsular.push_back(p->isim);
		temp=p->komsu;
		--temp;
		if(temp<0)
		{
			cout<<"Havel Hakim Hatasi 1  " <<temp<<endl;
			return -1;
		}
		p->komsu=temp;
		if(++p>allocator.end())
		{
			cout<<"Havel Hakim Hatasi 2"<<endl;
			return -1;
		}
	}
	return 0;
}

void cikar(vector<nokta>& allocator, vector<nokta>& toplayan)
{
	toplayan.push_back(allocator[0]);

	vector<nokta>::iterator p;
	p=allocator.begin();

	allocator.erase(p);
}

void komsulari_yaz(vector<nokta>& komsu,vector<nokta> liste)
{
	list<char>::iterator pkomsu;

	for(unsigned int a=0;a<komsu.size();++a)
	{
		pkomsu=komsu[a].komsular.begin();
		cout<<komsu[a].pt.x<<"  "<<komsu[a].pt.y
				<<" kordinatli "<<komsu[a].isim<<"  nin komsulari.."<<endl;

		while(pkomsu!=komsu[a].komsular.end())
		{
			cout<<"   "<<*pkomsu<<endl;

			for(unsigned int index=0;index<komsu.size();++index)
			{
				unsigned int index2;
				if(komsu[index].isim==*pkomsu)
				{
					for(index2=0;index2<liste.size();++index2)
					{
						if(liste[index2].isim==komsu[index].isim)
							break;
					}

					if(liste[index2].komsu!=komsu[index].komsular.size())
					{
					komsu[index].komsular.push_back(komsu[a].isim);

					break;
					}
				}
			}
			++pkomsu;
		}


	}
}

int randla(int w)
{
	return rand() %w + 1;
}

void grafla(vector<nokta> komsu, Mat& resim,int w)
{
	for(unsigned int say=0;say<komsu.size();++say)
	{
		string s;
		list<char>::iterator p;
		circle( resim,komsu[say].pt, w/32.0,Scalar( rand() %255 + 1,rand() %255 + 1,rand() %255 + 1 ),-1, 2 );
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
}

void bfs(vector<nokta> allocator,int w)
{
	bool bulundu=false;
	char baslangic, son;
	list<char> sira;
	list<char> output;
	cout<<"Aramaya baslanacak noktanin ismini gir"<<endl;
	cin>>baslangic;
	cout<<"Aranacak noktanin ismini gir"<<endl;
	cin>>son;
	cout<<baslangic<<"  noktasindan -> "<<son<<"  noktasi aranacak"<<endl;

	output.push_back(baslangic);
	sira.push_back(baslangic);
	unsigned int index;

	while(bulundu==false)
	{

		for(index=0;index<allocator.size();++index)
			{
			if(allocator[index].isim==sira.front() && bulundu ==false) //outputun ilk elementi
				{
					//cout<<allocator[index].isim<<"    "<<sira.front()<<endl; //siranin ilk elementi bulunuyor allocator[index]
					allocator[index].visited=true;
					break;
				}
			}
		if(allocator[index].isim==son)
			bulundu=true;

		list<char>::iterator pkomsu;
		pkomsu=allocator[index].komsular.begin();

		//cout<<allocator[index].isim<<"  komsulari"<<endl;

		while(pkomsu!=allocator[index].komsular.end() && bulundu ==false) //uzerinde bulunan indexin komsularini siraya atiyoruz
			{
				for(unsigned int index2=0;index2<allocator.size();++index2)
					{
						if(allocator[index2].isim==*pkomsu && allocator[index2].visited==false)
							{
								if(allocator[index2].visited==false)
								{
									sira.push_back(allocator[index2].isim);
									allocator[index2].visited=true;
								}
							}
					}
				//cout<<"   "<<*pkomsu<<endl;
				++pkomsu;
			}
		output.push_back(allocator[index].isim);
		sira.pop_front();
	}

	output.pop_front();
	cout<<"Bulundu"<<endl;
	list<char>::iterator p;
	p=output.begin();
	while(p!=output.end())
	{
		cout<<*p<<" ";
		++p;
	}
	cout<<endl;

	//ciz
	Mat resim = Mat::zeros( w, w, CV_8UC3 );
	p=output.begin();
	imshow( "BFS", resim );
	while(p!=output.end())
		{
		for(unsigned int index=0;index<allocator.size();++index)
				{
					if(allocator[index].isim==*p)
					{
						string s;
						circle(resim,allocator[index].pt, w/32.0,Scalar( rand() %255 + 1,rand() %255 + 1,rand() %255 + 1 ),-1, 2 );
						putText(resim,s+allocator[index].isim,allocator[index].pt, CV_FONT_HERSHEY_SIMPLEX, 0.5,cv::Scalar(0, 0, 255),1,8,false);
						waitKey( 500 );
						//usleep();
						imshow( "BFS", resim );
					}
				}
			++p;
		}

	waitKey( 0 );

}





































