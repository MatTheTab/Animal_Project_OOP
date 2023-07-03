# include "Lion.h"

Lion::Lion(string _name, string _what_food, int _weight, int _danger_level, int _age_sep, int _mane_size):
	Mammal(_name,_what_food,_weight,_danger_level,_age_sep){
		mane_size=_mane_size;
	}

void Lion::GetParam(int &_mane_size){
	_mane_size=mane_size;
}

string Lion::eat(){
	return string("I am a Lion, my name is ")+name+". "+Mammal::eat();
}

string Lion::drink(){
	return string("I am a Lion, my name is ")+name+". "+Mammal::drink();
}

string Lion::toString(){
	char buffw[256];
	sprintf(buffw,"Lion, %s, mane_size:%d",
	Mammal::toString().c_str(),mane_size);
	return string(buffw);
}

