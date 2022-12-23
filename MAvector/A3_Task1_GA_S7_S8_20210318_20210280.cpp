/**
 * @file A3_Task1_GA_S7_S8_20210318_20210280.cpp
 * @author Amr Hesham Mohamed (20210280) 
 * @author Mazen Mahmoud Shokry (20210318)
 * @brief this is the file where all the class functions are developed
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include"A3_Task1_GA_S7_S8_20210318_20210280.h"

/**
 * @brief first constructor
 * 
 * @tparam T
 * @param n te initial capacity
 */
template<class T>
MAvector<T>::MAvector(int n){
    this->capacity = n;
    this->size = 0;
    this->arr = new T [this->capacity];
   
}

/**
 * @brief second constructor
 * 
 * @tparam T 
 * @param a pointer to array
 * @param n initial capacity
 */
template<class T>
MAvector<T>::MAvector(T *a, int n){
    strcpy_s(arr, a);
    this->capacity = n;
    this->size = 0;
    this->arr = new T [this->capacity];
}

/**
 * @brief destructor
 * 
 * @tparam T 
 */
template<class T>
MAvector<T>::~MAvector(){
    delete[] this->arr;
    arr = nullptr;
}

/**
 * @brief overloading operator =
 * 
 * @tparam T 
 * @param vec copy refrence
 * @return MAvector<T>& 
 */
template<class T>
MAvector<T> & MAvector<T>::operator=(const MAvector<T> &vec){
    arr = vec->arr;
    size = vec.size;
    capacity = vec.capacity;
}

/**
 * @brief overloading operator =
 * 
 * @tparam T 
 * @param vec move refrence
 * @return MAvector<T>& 
 */
template<class T>
MAvector<T>& MAvector<T>::operator=(const MAvector &&vec){
    arr = vec->arr;
    size = vec.size;
    capacity = vec.capacity;
}

/**
 * @brief overloading operator []
 * 
 * @tparam T 
 * @param i index
 * @return T& vector element
 */
template<class T>
T& MAvector<T>::operator[](const int i){
    if (i < 0 || i >= this->size){
        throw "range error";
    }
    return this->arr[i];
}

/**
 * @brief add element to vector
 * 
 * @tparam T 
 * @param ob object to be added
 * @return int 
 */
template<class T>
int MAvector<T>::push_back(const T &ob){
    if(size >= this->capacity){
        resize();
    }
    arr[size++] = T(ob);
    return size;
}

/**
 * @brief remove last element of the vector
 * 
 * @tparam T 
 * @return T 
 */
template<class T>
void MAvector<T>::pop_back(){ 
    if(size == 0){
        cout << "vector is empty\n"; 
    }
    else{
        size--;
    }
}

/**
 * @brief begining of the vector
 * 
 * @tparam T 
 * @return T* 
 */
template<class T>
T* MAvector<T>::begin(){ 
    return &arr[0]; 
}

/**
 * @brief end of the vector
 * 
 * @tparam T 
 * @return T* 
 */
template<class T>
T* MAvector<T>::end(){ 
    return begin() + size;
}

/**
 * @brief erase index by iterator
 * 
 * @tparam T 
 * @param iter 
 */
template<class T>
void MAvector<T>::erase(iterator iter){
   while ((iter+1) != end()){
        *iter = *(iter + 1);
        iter++;
    }
    size--;
}

/**
 * @brief erase range of indexes by iterators
 * 
 * @tparam T 
 * @param i1 first iterator to be erased
 * @param i2 last iterator to be erased
 */
template<class T>
void MAvector<T>::erase(iterator i1, iterator i2){
    for (auto it = i1, end = i2; end >= it; end--) {
        erase(end);
    }
}

/**
 * @brief insert a value by iterator
 * 
 * @tparam T 
 * @param it iteator of the new value position
 * @param n the value to be added
 * @return T* 
 */
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

/**
 * @brief clear the elements in the vector
 * 
 * @tparam T 
 */
template<class T>
void MAvector<T>::clear(){
    for (int i = 0; i < this->size; i++){
        delete this->arr[i];
    }
    delete[] this->arr;
}

/**
 * @brief operator to for cout (<<)
 * 
 * @tparam T 
 * @param out type
 * @param vec vector to be printed
 * @return ostream& 
 */
template<class T>
 ostream& operator<<(ostream& out,MAvector<T>& vec){
    for(T it:vec){
        out << it << " ";
    }
    return out;
}

/**
 * @brief two vectors comparision (using overloading of (==))
 * 
 * @tparam T 
 * @param ob second object to be compared
 * @return true if two vectors are equal
 * @return false if two vectors are not equal
 */
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

/**
 * @brief overloading (<) to check if one is smaller than the other
 * 
 * @tparam T 
 * @param ob object to be compared
 * @return true if is smaller than the main vector
 * @return false if is greater than the main vector
 */
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

/**
 * @brief function to get vector's size
 * 
 * @tparam T 
 * @return int vector's size 
 */
template<class T>
int MAvector<T>::vecSize(){
    return size;
}

/**
 * @brief function to get vector's capacity
 * 
 * @tparam T 
 * @return const int vector's capacity
 */
template<class T>
const int MAvector<T>::vecCapacity(){
    return capacity;
}

/**
 * @brief function to resize vector's capacity if size > capacity
 * 
 * @tparam T 
 * @return const int capacity
 */
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

/**
 * @brief function to check if vector is emoty
 * 
 * @tparam T 
 * @return true if no elements are found
 * @return false if elements are found
 */
template<class T>
bool MAvector<T>::empty(){
    if(size == 0){
        return true;
    }
    else{
        return false;
    }
}