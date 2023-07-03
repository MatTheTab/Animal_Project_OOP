#ifndef LionH
#define LionH

#include "Mammal.h"

class Lion:public Mammal{
	private:
		int mane_size;
	public:
		Lion(string,string,int,int,int,int);
		string toString();
		void GetParam(int&);
		virtual string eat();
		virtual string drink();
};

#endif
