# include "Mammal.h"

Mammal::Mammal(string _name, string _what_food, int _weight, int _danger_level, int _age_sep):
	Animal(_name,_what_food,_weight, _danger_level){
		age_seperation_from_parent=_age_sep;
	}

string Mammal::toString(){
	char buffw[256];
	sprintf(buffw,"%s, age of seperation from parents:%d",
	Animal::toString().c_str(),age_seperation_from_parent);
	return string(buffw);
}

void Mammal::GetGroupParams(int &age){
	age=age_seperation_from_parent;
}

