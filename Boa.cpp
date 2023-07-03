# include "Boa.h"

Boa::Boa(string _name, string _what_food, int _weight, int _danger_level, int _enc_temp,float _hug_strength):
	Reptile(_name,_what_food,_weight,_danger_level,_enc_temp){
		constriction_strength=_hug_strength;
	}

void Boa::GetParam(float &_hug_strength){
	_hug_strength=constriction_strength;
}

string Boa::eat(){
	return string("I am a Boa snake, my name is ")+name+". "+Reptile::eat();
}

string Boa::drink(){
	return string("I am a Boa snake, my name is ")+name+". "+Reptile::drink();
}

string Boa::toString(){
	char buffw[256];
	sprintf(buffw,"Boa, %s, constriction_strength:%f",
	Reptile::toString().c_str(),constriction_strength);
	return string(buffw);
}

