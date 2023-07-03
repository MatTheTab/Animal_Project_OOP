#ifndef MammalH
#define MammalH

#include "Animal.h"

class Mammal:public Animal{
	protected:
		int age_seperation_from_parent;
	public:
		Mammal(string,string,int,int,int);
		virtual ~Mammal(){};
		virtual string toString()=0;
		void GetGroupParams(int&);
		
		virtual string eat(void){return string("I am a mammal and I eat ")+what_food+"; ";};
		virtual string drink(void){return string("I am a mammal and I drink water or milk; ");};
};

#endif
