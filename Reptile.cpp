# include "Reptile.h"

Reptile::Reptile(string _name, string _what_food, int _weight, int _danger_level, int _enc_temp):
	Animal(_name,_what_food,_weight, _danger_level){
		enclosure_temperature=_enc_temp;
	}

string Reptile::toString(){
	char buffw[256];
	sprintf(buffw,"%s, temperature in the enclosure:%d",
	Animal::toString().c_str(),enclosure_temperature);
	return string(buffw);
}

void Reptile::GetGroupParams(int &temp){
	temp=enclosure_temperature;
}


