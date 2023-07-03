# include "Animal.h"

const int MAX_TYPES=7;
const int MAX_NAMES=21;
const int MAX_MEAT_NAMES=7;
const int MAX_FUR_COLORS=3;

string names[]={"Tom","Jerry","Woody","Jacob","Kevin","Dante","Timmy","Jojo","Adrian","Kevin Jr.","Jan","Alfred","Phil","Goerge","David","Rebecca","Lucy",
"Ursula","Alice","Juliet","Caroline","Sandra"};
string meat_names[]={"Lamb","Chicken","Pork","Duck","Beef","Rabbit","Turkey"};
string fur_colors[]={"Black","Brown","Grey","White"};

Animal::Animal(string _name,string _what_food, int _weight, int _danger_level){
	name=_name;
	what_food=_what_food;
	weight=_weight;
	danger_level=_danger_level;
}

string Animal::toString(){
	char buffw[256];
	sprintf(buffw,"name:%s, food:%s, weight:%d, danger_level:%d",
	name.c_str(),what_food.c_str(),weight,danger_level);
	return string(buffw);
}

void Animal::GetAnimalParams(string &_what_food, int &_weight, int &_danger_level){
	_what_food=what_food;
	_weight=weight;
	_danger_level=danger_level;
}
