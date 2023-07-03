# include "Wolf.h"

Wolf::Wolf(string _name, string _what_food, int _weight, int _danger_level, int _age_sep, int _tail_len):
	Mammal(_name,_what_food,_weight,_danger_level,_age_sep){
		tail_length=_tail_len;
	}

void Wolf::GetParam(int &_tail_len){
	_tail_len=tail_length;
}

string Wolf::eat(){
	return string("I am a Wolf, my name is ")+name+". "+Mammal::eat();
}

string Wolf::drink(){
	return string("I am a Wolf, my name is ")+name+". "+Mammal::drink();
}

string Wolf::toString(){
	char buffw[256];
	sprintf(buffw,"Wolf, %s, tail_length:%d",
	Mammal::toString().c_str(),tail_length);
	return string(buffw);
}


