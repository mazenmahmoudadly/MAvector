#ifndef TEST_MARK_FUNCTION
#define TEST_MARK_FUNCTION
#include<iostream>
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
  typedef T *iterator;

  MAvector(int n = 1);
  MAvector(T *a, int n = 1);
  ~MAvector();

  MAvector &operator=(const MAvector &vec);
  MAvector &operator=(const MAvector &&vec);
  T &operator[](const int);
  int push_back(const T &ob);
  T pop_back();
  iterator begin();
  iterator end();
  void ensureCap(size_t cap);
  void erase(iterator iter);
  void erase(iterator i1, iterator i2);
  void clear();

  iterator insert(iterator it, const T &n);

  bool operator==(const MAvector<T> &ob);
  bool operator<(const MAvector<T> &ob);
  int vecSize();
  const int vecCapacity();
  const int resize();
  bool empty();
  template <typename U>
  friend ostream &operator<<(ostream &out, MAvector<U> &vec);
};

#endif