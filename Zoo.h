#ifndef ZooH
#define ZooH

#include "Animal.h"
#include "Zoo.h"

template <class T>
class ZOO{
	private:
		vector<T*> animals;
		int max_animals;
	public:
		ZOO(int);
		void operator += (T*);
		void operator -= (T*);
		void list(void);
		~ZOO();
		int GetSize();
		T* GetElement(int);
		bool ZooFull();
};

template <class T>
ZOO<T>::ZOO(int _max_animals):max_animals(_max_animals)
{}

template<class T>
void ZOO<T>::operator+=(T*val){
	if (max_animals>animals.size())
		animals.push_back(val);
}

template<class T>
void ZOO<T>::operator-=(T*val){
	if(!val)
		return;
	T* ptr;
	for(int i=0;i<animals.size();i++){
		if(animals[i]==val){
			ptr=animals[i];
			animals.erase(animals.begin()+i);
			delete ptr;
			return;
		}
	}
	cout<<"No such animal in ZOO\n";
}

template <class T>
void ZOO<T>::list(){
	if(animals.size()==0)
		cout<<"No animals in the ZOO\n";
	for(int i=0;i<animals.size();i++){
		cout<<animals[i]->toString().c_str()<<"\n";
	}
}

template <class T>
int ZOO<T>::GetSize(){
	return animals.size();
}

template <class T>
bool ZOO<T>::ZooFull(){
	return animals.size()>=max_animals;
}

template <class T>
ZOO<T>::~ZOO(){
	while(animals.size()>0){
		*this-=animals[0];
	}
}

template <class T>
T *ZOO<T>::GetElement(int idx){
	return animals[idx];
}

#endif
