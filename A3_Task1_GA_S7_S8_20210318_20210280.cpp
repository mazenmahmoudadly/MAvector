#include "A3_Task1_GA_S7_S8_20210318_20210280.h"

template<class T>
MAvector<T>::MAvector(int n){
    this->capacity = n;
    this->size = 0;
    this->arr = new T *[this->capacity];
    this->initialize(0);
}

template<class T>
MAvector<T>::MAvector(T **a, int n){
    strcpy_s(arr, a);
    this->capacity = n;
    this->size = 0;
    this->arr = new T *[this->capacity];
    this->initialize();
}

template<class T>
MAvector<T>::MAvector(const MAvector &){}

template<class T>
MAvector<T>::~MAvector(){
    for (int i = 0; i < this->size; i++){
        delete this->arr[i];
    }
    delete[] this->arr;
    this->initialize(this->size);
}

template<class T>
void MAvector<T>::initialize(int n){
    for (int i = n; i < this->capacity; i++){
            this->arr[i] = nullptr;
        }
}

// template<class T>
// MAvector& MAvector<T>::operator=(const MAvector &){}

// template<class T>
// MAvector& MAvector<T>::operator=(const MAvector &&){}

// template<class T>
// T& MAvector<T>::operator[](int){}

template<class T>
int MAvector<T>::push_back(T ob){
    if(this->size >= this->capacity){
        this->resize();
    }
    this->arr[this->size++] = new T(ob);
}

template<class T>
T MAvector<T>::pop_back(){
    delete this->arr[size-1];
}

// template<class T>
// void MAvector<T>::erase(iterator){}

// template<class T>
// void MAvector<T>::erase(iterator1, iterator2){}

template<class T>
void MAvector<T>::clear(){
    for (int i = 0; i < this->size; i++){
        delete this->arr[i];
    }
    delete[] this->arr;
}

// template<class T>
// void MAvector<T>::insert(iterator, T){}

// template<class T>
// void MAvector<T>::iterator begin(){}

// template<class T>
// void MAvector<T>::iterator end(){}

template<class T>
bool MAvector<T>::operator==(const MAvector<T> &ob){
    if(size != ob.size){
        return false;
    }
    else{
        for (int i = 0; i < size;i++){
            if(this->arr[i] == this->ob.arr[i]){
                return true;
            }
            else{
                return false;
                break;
            }
        }
    }
}

template<class T>
bool MAvector<T>::operator<(const MAvector<T> &ob){
    if(size < ob.size){
        return true;
    }
    else{
        for (int i = 0; i < size;i++){
            if(this->arr[i] < this->ob.arr[i]){
                return true;
            }
            else{
                return false;
                break;
            }
        }
    }
}

template<class T>
int MAvector<T>::vecSize(){
    return size;
}

template<class T>
const int MAvector<T>::vecCapacity(){
    return capacity;
}

template<class T>
const int MAvector<T>::resize(){
    this->capacity *= 2;
    T **tempArr = new T*[this->capacity];
    for (int i = 0; i < this->size; i++){
        tempArr[i] = new T(*this->arr[i]);
    }
    for (int i = 0; i < this->size; i++){
        delete this->arr[i];
    }
    delete[] this->arr;
    this->initialize(this->size);
}

template<class T>
bool MAvector<T>::empty(){
    if(size == 0){
        return true;
    }
}