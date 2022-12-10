#include "A3_Task1_GA_S7_S8_20210318_20210280.h"

template<class T>
MAvector<T>::MAvector(int a){}

template<class T>
MAvector<T>::MAvector(T **, int n){}

template<class T>
MAvector<T>::MAvector(const MAvector &){}

template<class T>
MAvector<T>::~MAvector(){}

// template<class T>
// MAvector& MAvector<T>::operator=(const MAvector &){}

// template<class T>
// MAvector& MAvector<T>::operator=(const MAvector &&){}

// template<class T>
// T& MAvector<T>::operator[](int){}

template<class T>
int MAvector<T>::push_back(T){}

template<class T>
T MAvector<T>::pop_back(){}

// template<class T>
// void MAvector<T>::erase(iterator){}

// template<class T>
// void MAvector<T>::erase(iterator1, iterator2){}

template<class T>
void MAvector<T>::clear(){}

// template<class T>
// void MAvector<T>::insert(iterator, T){}

// template<class T>
// void MAvector<T>::iterator begin(){}

// template<class T>
// void MAvector<T>::iterator end(){}

template<class T>
bool MAvector<T>::operator==(const MAvector<T> &){}

template<class T>
bool MAvector<T>::operator<(const MAvector<T> &){}

template<class T>
int MAvector<T>::vecSize(){
    return size;
}

template<class T>
const int MAvector<T>::vecCapacity(){}

template<class T>
const int MAvector<T>::resize(){}

template<class T>
bool MAvector<T>::empty(){}