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

void komsulari_yaz(vector<nokta>& komsu)
{

	list<char>::iterator pkomsu;

	for(unsigned int a=0;a<komsu.size();++a)
	{
		pkomsu=komsu[a].komsular.begin();
		cout<<komsu[a].pt.x<<"  "<<komsu[a].pt.y
				<<"kordinatli  "<<komsu[a].isim<<"  nin komsulari.."<<endl;

		while(pkomsu!=komsu[a].komsular.end())
		{
			cout<<"   "<<*pkomsu<<endl;
			++pkomsu;
		}


	}
}

int randla(int w)
{
	return rand() %w + 1;
}
