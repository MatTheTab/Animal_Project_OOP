#ifndef ReptileH
#define ReptileH

#include "Animal.h"

class Reptile:public Animal{
	protected:
		int enclosure_temperature;
	public:
		Reptile(string,string,int,int,int);
		virtual ~Reptile(){};
		virtual string toString()=0;
		void GetGroupParams(int&);
		
		virtual string eat(void){return string("I am a reptile and I eat ")+what_food+"; ";};
		virtual string drink(void){return string("I am a reptile and I drink water; ");};
};

#endif
