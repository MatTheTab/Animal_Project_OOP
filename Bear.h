#ifndef BearH
#define BearH

#include "Mammal.h"

class Bear:public Mammal{
	private:
		string fur_color;
	public:
		Bear(string,string,int,int,int,string);
		string toString();
		void GetParam(string&);
		virtual string eat();
		virtual string drink();
};

#endif
