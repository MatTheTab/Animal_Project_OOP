#ifndef IguanaH
#define IguanaH

#include "Reptile.h"

class Iguana:public Reptile{
	private:
		int cuteness;
	public:
		Iguana(string,string,int,int,int,int);
		string toString();
		void GetParam(int&);
		virtual string eat();
		virtual string drink();
};

#endif
