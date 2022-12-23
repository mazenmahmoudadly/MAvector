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
    arr = nullptr;
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
    if(size == 0){
        cout << "vector is empty\n"; 
    }
    else{
        size--;
    }
}

template<class T>
T* MAvector<T>::begin(){ 
    return &arr[0]; 
}

template<class T>
T* MAvector<T>::end(){ 
    return begin() + size;
}

template<class T>
void MAvector<T>::ensureCap(size_t cap){
    if (cap > capacity){
        size_t s = (cap > 2 * capacity) ? cap : 2 * capacity;
    }
    }

template<class T>
void MAvector<T>::erase(iterator iter){
   while ((iter+1) != end()){
        *iter = *(iter + 1);
        iter++;
    }
    size--;
}

template<class T>
void MAvector<T>::erase(iterator i1, iterator i2){
for (auto it = i1; it != i2; ++it) {
    erase(it);
}
}

template<class T>
T* MAvector<T>::insert(iterator it, const T &n){
    size_t pos = it - begin();
    resize();
    for (size_t i = size; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = n;
    size++;
    return begin() + pos;
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
    this->capacity *= 1.5;
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