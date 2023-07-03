#ifndef WolfH
#define WolfH

#include "Mammal.h"

class Wolf:public Mammal{
	private:
		int tail_length;
	public:
		Wolf(string,string,int,int,int,int);
		string toString();
		void GetParam(int&);
		virtual string eat();
		virtual string drink();
};

#endif
