# include "Crocodile.h"

Crocodile::Crocodile(string _name, string _what_food, int _weight, int _danger_level, int _enc_temp,float _swim_speed):
	Reptile(_name,_what_food,_weight,_danger_level,_enc_temp){
		swimming_speed=_swim_speed;
	}

void Crocodile::GetParam(float &_swim_speed){
	_swim_speed=swimming_speed;
}

string Crocodile::eat(){
	return string("I am a Crocodile, my name is ")+name+". "+Reptile::eat();
}

string Crocodile::drink(){
	return string("I am a Crocodile, my name is ")+name+". "+Reptile::drink();
}

string Crocodile::toString(){
	char buffw[256];
	sprintf(buffw,"Crocodile, %s, swimming_speed:%f",
	Reptile::toString().c_str(),swimming_speed);
	return string(buffw);
}

