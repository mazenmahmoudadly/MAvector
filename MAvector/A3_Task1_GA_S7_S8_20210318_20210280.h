/**
 * @file A3_Task1_GA_S7_S8_20210318_20210280.h
 * @author Amr Hesham Mohamed (20210280)
 * @author Mazen Mahmoud Shokry (20210318)
 * @brief this is the header file of the vector class(MAvector)
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef A3_TASK1_GA_S7_S8_20210318_20210280_MARK_FUNCTION
#define A3_TASK1_GA_S7_S8_20210318_20210280_MARK_FUNCTION
#include<iostream>
#include<iterator>
#include<stdexcept>
#include<algorithm>

using namespace std;

/**
 * @brief The class of the vector
 * 
 * @tparam T
 */
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