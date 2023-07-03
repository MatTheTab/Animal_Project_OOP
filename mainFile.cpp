#include <iostream>
#include <stdio.h>
#include <limits>
#include "Animal.h"
#include "Breeder.h"
#include "Mammal.h"
#include "Reptile.h"
#include "Tiger.h"
#include "Lion.h"
#include "Bear.h"
#include "Wolf.h"
#include "Crocodile.h"
#include "Iguana.h"
#include "Boa.h"
#include "Zoo.h"


void FillRandomZoo(int population0,ZOO<Animal> & zoo)
{
  int animalCode;
  Animal *newAnimal;
  for(int i=0;i<population0;i++)
   {
	 animalCode=rand()%MAX_TYPES;
	 switch(animalCode)
	 {
	  case 0:
		newAnimal=new Tiger(names[rand()%MAX_NAMES],meat_names[rand()%MAX_MEAT_NAMES],
		rand()%10+50,rand()%5+5,1,rand()%3+1);
	  break;
	  case 1:
		newAnimal=new Wolf(names[rand()%MAX_NAMES],meat_names[rand()%MAX_MEAT_NAMES],
		rand()%10+2,rand()%5+2,1,rand()%10+20);
	  break;
	  case 2:
		newAnimal=new Lion(names[rand()%MAX_NAMES],meat_names[rand()%MAX_MEAT_NAMES],
		rand()%10+60,rand()%6+4,1,rand()%10+5);
	  break;
	  case 3:
		newAnimal=new Bear(names[rand()%MAX_NAMES],meat_names[rand()%MAX_MEAT_NAMES],
		rand()%30+150,rand()%7+5,2,fur_colors[rand()%MAX_FUR_COLORS]);
	  break;
	  case 4:
		newAnimal=new Crocodile(names[rand()%MAX_NAMES],meat_names[rand()%MAX_MEAT_NAMES],
		rand()%20+10,rand()%4+4,20,rand()%5+15);
	  break;
	   case 5:
		newAnimal=new Iguana(names[rand()%MAX_NAMES],meat_names[rand()%MAX_MEAT_NAMES],
		rand()%2+1,0,30,rand()%10+90);
	  break;
	  case 6:
		newAnimal=new Boa(names[rand()%MAX_NAMES],meat_names[rand()%MAX_MEAT_NAMES],
		rand()%3+15,rand()%5+3,35,rand()%10+90);
	  break;

	 }
	zoo+=newAnimal;
   }
}

 const int ZOO_CAPACITY=100;
 int pop0;
 int pBreed; //%
 int pExtinct;  //%

int main()
{

 ZOO<Animal> myZOO(ZOO_CAPACITY);

 
 cout<<"<<<<<<<<<<<<<This Program Simulates a Zoo>>>>>>>>>>>>>>>>>>>\n";
 cout<<"Please input the starting number of animals\n";
 cout<<"pop0=";
 try{
 	cin>>pop0;
 	if(cin.fail())
	 {
	    cin.clear(); 
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw("Unspecified Input Error, reseting the starting population to default value=20");
    }	 
 	if(pop0>ZOO_CAPACITY || pop0<1){
 		throw("Incorrect Starting Population Number, reseting starting population to default value=20");
	 }
	 	   
 }
 catch(const char *err){
 	cout<<err<<"\n";
 	pop0=20;
 }

 
 cout<<"Now please input the probability of breeding and extinction respectively (with integer representation of percent for \nexample pBreed=10 means 10%)\n";
 cout<<"pBreed=";
 try{
 cin>>pBreed;
 if(cin.fail()){
 	cin.clear();
 	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	throw("Unspecified Input Error, reseting the probability to pBreed=40");
 }
 if(pBreed>100 || pBreed<=0){
 	throw("Incorrect Breeding Probaility Error, reseting the probability to pBreed=40");
 }}
catch(const char* err){
	cout<<err<<"\n";
	pBreed=40;	
}
 cout<<"pExtinct=";
 try{
 cin>>pExtinct;
 if(cin.fail()){
 	cin.clear();
 	cin.ignore(numeric_limits<streamsize>::max(), '\n');
 	throw("Unspecified Input Error, reseting the probability to pExtinct=20");
 }
 if(pExtinct<0 || pExtinct>100){
 	throw("Incorrect Breeding Probaility Error, reseting the probability to pExtinct=20");
 }}
 catch(const char* err){
 	cout<<err<<"\n";
 	pExtinct=20;
 }

  FillRandomZoo(pop0,myZOO);
 cout<<"\n------------ Polulation 0 --------------\n"<<endl;
 myZOO.list();

 int step=1;
 Breeder MyBreeder(pBreed,pExtinct);
 while(1)
 {

	MyBreeder.Breed(myZOO);
	cout<<"\n------------ Step"<<step++<<" --------------\n"<<endl;
	myZOO.list();
	if(myZOO.ZooFull()){ 
		cout<<"Zoo is full-";
		break;}
	if(myZOO.GetSize()<=1) {
		cout<<"No Animals left to breed-";
		break;}
 }
 cout<<"End of simulation!"<<endl;
 char c;
 cin>>c;
 return 0;
}
