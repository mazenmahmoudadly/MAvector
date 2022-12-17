#include"A3_Task1_GA_S7_S8_20210318_20210280.h"

template<class T>
MAvector<T>::MAvector(int n){
    this->capacity = n;
    this->size = 0;
    this->arr = new T [this->capacity];
   
}

template<class T>
MAvector<T>::MAvector(T *a, int n){
    strcpy_s(arr, a);
    this->capacity = n;
    this->size = 0;
    this->arr = new T [this->capacity];
    
}

template<class T>
MAvector<T>::~MAvector(){
    delete[] this->arr;
}


template<class T>
MAvector<T> & MAvector<T>::operator=(const MAvector<T> &vec){
    arr = vec->arr;
    size = vec.size;
    capacity = vec.capacity;
}

template<class T>
MAvector<T>& MAvector<T>::operator=(const MAvector &&vec){
    arr = vec->arr;
    size = vec.size;
    capacity = vec.capacity;
}

template<class T>
T& MAvector<T>::operator[](const int i){
    if (i < 0 || i >= this->size){
        throw "range error";
    }
    return this->arr[i];
}

template<class T>
int MAvector<T>::push_back(const T &ob){
    if(size >= this->capacity){
        resize();
    }
    arr[size++] = T(ob);
    return size;
}

template<class T>
T MAvector<T>::pop_back(){
    delete arr[size-1];
}

template<class T>
void MAvector<T>::clear(){
    for (int i = 0; i < this->size; i++){
        delete this->arr[i];
    }
    delete[] this->arr;
}


template<class T>
 ostream& operator<<(ostream& out,MAvector<T>& vec){
    for(T it:vec){
        out << it << " ";
    }
    return out;
}
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
    T *tempArr = new T[this->capacity];
    for (int i = 0; i < this->size; i++){
        tempArr[i] =  T(this->arr[i]);
    }

    delete[] arr;
    return capacity;
}

template<class T>
bool MAvector<T>::empty(){
    if(size == 0){
        return true;
    }
}