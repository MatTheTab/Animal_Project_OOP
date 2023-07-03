#ifndef BreederH
#define BreederH

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

class Breeder{
	private:
		int pBreed; //in %
		int pExtinct; // in %
		Animal *Intersect(Animal*,Animal*);
		int IntersectGroup(Animal*,Animal*);
		void IntersectAnimal(Animal*,Animal*,string&,int&,float&);
		void GetAnimalParam(Animal*,string&,int&,float&);
		template<class T>
		bool isAnimal(Animal *cl){T* inv=dynamic_cast<T*>(cl);
		if (inv)
			return true;
		return false;
		}
		template<class T>
		void mixVal(T& out, T in1, T in2){ out=in1; if(rand()%2==1) {
		out=in2;}}
		template<class T>
		bool isTheSame(Animal *cl1, Animal *cl2){
			return isAnimal<T>(cl1) && isAnimal<T>(cl2);
		}
	public:
		Breeder (int,int);
		void Breed(ZOO<Animal>&);
};

#endif
