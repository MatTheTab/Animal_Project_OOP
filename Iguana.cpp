# include "Iguana.h"

Iguana::Iguana(string _name, string _what_food, int _weight, int _danger_level, int _enc_temp,int _cuteness):
	Reptile(_name,_what_food,_weight,_danger_level,_enc_temp){
		cuteness=_cuteness;
	}

void Iguana::GetParam(int &_cuteness){
	_cuteness=cuteness;
}

string Iguana::eat(){
	return string("I am an Iguana, my name is ")+name+". "+Reptile::eat();
}

string Iguana::drink(){
	return string("I am an Iguana, my name is ")+name+". "+Reptile::drink();
}

string Iguana::toString(){
	char buffw[256];
	sprintf(buffw,"Iguana, %s, cuteness:%d",
	Reptile::toString().c_str(),cuteness);
	return string(buffw);
}
