#ifndef BoaH
#define BoaH

#include "Reptile.h"

class Boa:public Reptile{
	private:
		float constriction_strength;
	public:
		Boa(string,string,int,int,int,float);
		string toString();
		void GetParam(float&);
		virtual string eat();
		virtual string drink();
};

#endif
