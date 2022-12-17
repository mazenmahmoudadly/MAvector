#ifndef TEST_MARK_FUNCTION
#define TEST_MARK_FUNCTION
#include <iostream>
#include<iterator>
#include<stdexcept>
#include<algorithm>

using namespace std;

template<typename T>
class MAvector{
private:
    int capacity;
    int size;
    T *arr;    

public:
   
    typedef T* iterator;


    MAvector(int n=1);
    MAvector(T *a, int n=1);
    ~MAvector();


    MAvector &operator=(const MAvector &vec);
    MAvector &operator=(const MAvector &&vec);
    T &operator[](const int);
    int push_back(const T &ob);
    T pop_back();
    iterator begin(){return &arr[0];}
    iterator end(){return begin()+size;}
    void ensureCap(size_t cap){
      if(cap>capacity){
        size_t s=(cap>2*capacity)?cap :2*capacity;

      }
    }
    void erase(iterator iter){
   while ((iter+1)!=end()){
    *iter=*(iter+1);
    iter++;
   }
   size--;
 
   
    }
    void erase(iterator i1, iterator i2){
      for(MAvector<int>::iterator it =i1;it!=i2;it++){
        erase(it);
      }
    }
    void clear();
    iterator insert(iterator it, const T& n){
      size_t pos = it-begin();
      resize();
      for(size_t i=size;i>pos;i--){
        arr[i]=arr[i-1];
      }
      arr[pos]=n;
      size++;
      return begin()+pos;

    }

    bool operator==(const MAvector<T> &ob);
    bool operator<(const MAvector<T> &ob);
    int vecSize();
    const int vecCapacity();
    const int resize();
    bool empty();
    template<typename U>
    friend ostream& operator<<(ostream& out,MAvector<U>& vec );
};

#endif