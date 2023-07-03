# include "Tiger.h"

Tiger::Tiger(string _name, string _what_food, int _weight, int _danger_level, int _age_sep, int _num_stripes):
	Mammal(_name,_what_food,_weight,_danger_level,_age_sep){
		number_of_stripes=_num_stripes;
	}

void Tiger::GetParam(int &_num_S){
	_num_S=number_of_stripes;
}

string Tiger::eat(){
	return string("I am a Tiger, my name is ")+name+". "+Mammal::eat();
}

string Tiger::drink(){
	return string("I am a Tiger, my name is ")+name+". "+Mammal::drink();
}

string Tiger::toString(){
	char buffw[256];
	sprintf(buffw,"Tiger, %s, number of stripes:%d",
	Mammal::toString().c_str(),number_of_stripes);
	return string(buffw);
}


