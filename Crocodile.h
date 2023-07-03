#ifndef CrocodileH
#define CrocodileH

#include "Reptile.h"

class Crocodile:public Reptile{
	private:
		float swimming_speed;
	public:
		Crocodile(string,string,int,int,int,float);
		string toString();
		void GetParam(float&);
		virtual string eat();
		virtual string drink();
};

#endif
