# include "Bear.h"

Bear::Bear(string _name, string _what_food, int _weight, int _danger_level, int _age_sep, string _fur_color):
	Mammal(_name,_what_food,_weight,_danger_level,_age_sep){
		fur_color=_fur_color;
	}

void Bear::GetParam(string &_fur_color){
	_fur_color=fur_color;
}

string Bear::eat(){
	return string("I am a Bear, my name is ")+name+". "+Mammal::eat();
}

string Bear::drink(){
	return string("I am a Bear, my name is ")+name+". "+Mammal::drink();
}

string Bear::toString(){
	char buffw[256];
	sprintf(buffw,"Bear, %s, fur_color:%s",
	Mammal::toString().c_str(),fur_color.c_str());
	return string(buffw);
}

