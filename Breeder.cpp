# include "Breeder.h"

Breeder::Breeder(int pB,int pE){
	pBreed=pB;
	pExtinct=pE;
};

void Breeder::Breed(ZOO<Animal>&zoo){
	int N=zoo.GetSize();
	int rd;
	vector<Animal*> toRemove;
	if(zoo.GetSize()<2){
		cout<<"No animals to breed\n";
		return;
	}
	Animal*parentMain,*parent2;
	for(int i=0;i<N;i++){
		if(zoo.ZooFull())
			break;
		parentMain=zoo.GetElement(i);
		if ((rand()%101)<=pExtinct)
			toRemove.push_back(parentMain);
		if((rand()%101)<=pBreed){
			rd=i;
			while(rd==i){
				rd=rand()%N;
			}
			parent2=zoo.GetElement(rd);
			if(rand()%2==1){
				Animal *tmp=parentMain;
				parentMain=parent2;
				parent2=tmp;
			}
		zoo+=Intersect(parentMain,parent2);
		}
	}
	for(int i=0;i<toRemove.size();i++){
		zoo-=toRemove[i];
	}
}

Animal *Breeder::Intersect(Animal *pMain, Animal *pOther){
	string food1,food2,foodchild;
	int weight1,weight2,weightchild, danger_level1,danger_level2,danger_level_child;
	int groupParamChild;
	int OwnIntParam;
	string ownStrParam;
	float ownFloatParam;
	pMain->GetAnimalParams(food1,weight1,danger_level1);
	pOther->GetAnimalParams(food2,weight2,danger_level2);
	
	mixVal<string>(foodchild,food1,food2);
	mixVal<int>(weightchild,weight1,weight2);
	mixVal<int>(danger_level_child,danger_level1,danger_level2);
	groupParamChild=IntersectGroup(pMain,pOther);
	IntersectAnimal(pMain,pOther,ownStrParam,OwnIntParam,ownFloatParam);
	
	Animal *child=0;
	if(isAnimal<Wolf>(pMain))
	child=new Wolf(names[rand()%MAX_NAMES],foodchild,weightchild,danger_level_child,groupParamChild,OwnIntParam);
	if(isAnimal<Tiger>(pMain))
	child=new Tiger(names[rand()%MAX_NAMES],foodchild,weightchild,danger_level_child,groupParamChild,OwnIntParam);
	if(isAnimal<Lion>(pMain))
	child=new Lion(names[rand()%MAX_NAMES],foodchild,weightchild,danger_level_child,groupParamChild,OwnIntParam);
	if(isAnimal<Bear>(pMain))
	child=new Bear(names[rand()%MAX_NAMES],foodchild,weightchild,danger_level_child,groupParamChild,ownStrParam);
	if(isAnimal<Crocodile>(pMain))
	child=new Crocodile(names[rand()%MAX_NAMES],foodchild,weightchild,danger_level_child,groupParamChild,ownFloatParam);
	if(isAnimal<Boa>(pMain))
	child=new Boa(names[rand()%MAX_NAMES],foodchild,weightchild,danger_level_child,groupParamChild,ownFloatParam);
	if(isAnimal<Iguana>(pMain))
	child=new Iguana(names[rand()%MAX_NAMES],foodchild,weightchild,danger_level_child,groupParamChild,OwnIntParam);
	
	return child;
}

int Breeder::IntersectGroup(Animal *pMain, Animal *pOther){
	int groupParam1,groupParam2,groupParamChild=0;
	if(isTheSame<Mammal>(pMain,pOther)){
		Mammal *ptr1=dynamic_cast<Mammal*>(pMain);
		Mammal *ptr2=dynamic_cast<Mammal*>(pOther);
		ptr1->GetGroupParams(groupParam1);
		ptr2->GetGroupParams(groupParam2);
		mixVal<int>(groupParamChild,groupParam1,groupParam2);
	}
	else{
		if(isTheSame<Reptile>(pMain,pOther)){
			Reptile *ptr1=dynamic_cast<Reptile*>(pMain);
			Reptile *ptr2=dynamic_cast<Reptile*>(pOther);
			ptr1->GetGroupParams(groupParam1);
			ptr2->GetGroupParams(groupParam2);
			mixVal<int>(groupParamChild,groupParam1,groupParam2);
		}
		else{
			if(isAnimal<Mammal>(pMain)){
				Mammal *ptr1=dynamic_cast<Mammal*>(pMain);
				ptr1->GetGroupParams(groupParamChild);
			}
			else{
				Reptile *ptr1=dynamic_cast<Reptile*>(pMain);
				ptr1->GetGroupParams(groupParamChild);
			}
		}
	}
	return groupParamChild;
}

void Breeder::GetAnimalParam(Animal *animal, string& sParam, int &iParam, float &dParam){
	sParam="";
	iParam=0;
	dParam=0;
	if(isAnimal<Wolf>(animal)){
		Wolf *ptr=dynamic_cast<Wolf*>(animal);
		ptr->GetParam(iParam);
	}
	if(isAnimal<Tiger>(animal)){
		Tiger *ptr=dynamic_cast<Tiger*>(animal);
		ptr->GetParam(iParam);
	}
	if(isAnimal<Lion>(animal)){
		Lion *ptr=dynamic_cast<Lion*>(animal);
		ptr->GetParam(iParam);
	}
	if(isAnimal<Bear>(animal)){
		Bear *ptr=dynamic_cast<Bear*>(animal);
		ptr->GetParam(sParam);
	}
	if(isAnimal<Crocodile>(animal)){
		Crocodile *ptr=dynamic_cast<Crocodile*>(animal);
		ptr->GetParam(dParam);
	}
	if(isAnimal<Boa>(animal)){
		Boa *ptr=dynamic_cast<Boa*>(animal);
		ptr->GetParam(dParam);
	}
	if(isAnimal<Iguana>(animal)){
		Iguana *ptr=dynamic_cast<Iguana*>(animal);
		ptr->GetParam(iParam);
	}
}

void Breeder::IntersectAnimal(Animal*pMain, Animal *pOther, string& sParamChild, int &iParamChild, float &dParamChild){
	int iParam1,iParam2;
	string sParam1,sParam2;
	float dParam1,dParam2;
	GetAnimalParam(pMain,sParam1,iParam1,dParam1);
	GetAnimalParam(pOther,sParam2,iParam2,dParam2);
	
	if(isTheSame<Wolf>(pMain,pOther) || isTheSame<Tiger>(pMain,pOther) || isTheSame<Lion>(pMain,pOther) || isTheSame<Iguana>(pMain,pOther)){
		mixVal<int>(iParamChild,iParam1,iParam2);
		return;
	}
	if(isTheSame<Bear>(pMain,pOther)){
		mixVal<string>(sParamChild,sParam1,sParam2);
		return;
	}
	if(isTheSame<Boa>(pMain,pOther) || isTheSame<Crocodile>(pMain,pOther)){
		mixVal<float>(dParamChild,dParam1,dParam2);
		return;
	}
	if(isAnimal<Wolf>(pMain) || isAnimal<Tiger>(pMain) || isAnimal<Lion>(pMain) || isAnimal<Iguana>(pMain)){
		iParamChild=iParam1;
		return;
	}
	if(isAnimal<Bear>(pMain)){
		sParamChild=sParam1;
		return;
	}
	if(isAnimal<Boa>(pMain) || isAnimal<Crocodile>(pMain)){
		dParamChild=dParam1;
		return;
	}
}
