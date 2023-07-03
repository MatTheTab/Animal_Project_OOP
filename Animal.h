#ifndef AnimalH
#define AnimalH

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

extern string names[];
extern string meat_names[];
extern string fur_colors[];
extern const int MAX_NAMES;
extern const int MAX_TYPES;
extern const int MAX_MEAT_NAMES;
extern const int MAX_FUR_COLORS;

class Animal{
	protected:
		string name,what_food;
		int weight,danger_level;
	public:
		Animal(string,string,int,int);
		virtual string toString()=0;
		virtual string eat()=0;
		virtual string drink()=0;
		virtual ~Animal(){};
		void GetAnimalParams(string&,int&,int&);
};

#endif

