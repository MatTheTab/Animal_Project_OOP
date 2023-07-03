#ifndef TigerH
#define TigerH

#include "Mammal.h"

class Tiger:public Mammal{
	private:
		int number_of_stripes;
	public:
		Tiger(string,string,int,int,int,int);
		string toString();
		void GetParam(int&);
		virtual string eat();
		virtual string drink();
};

#endif
