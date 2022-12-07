#ifndef A3_TASK1_GA_S7_S8_20210318_20210280_MARK_FUNCTION
#define A3_TASK1_GA_S7_S8_20210318_20210280_MARK_FUNCTION
template<class T>
class MAvector{
private:
    int capacity;
    int size;
    T* arr;
    
public:

MAvector (int)

MAvector (T*, int  n )
MAvector (const MAvector&)
~MAvector()	
MAvector &operator=(const MAvector&)
MAvector &operator=(const MAvector&&)

 
T& operator[](int) 

int push_back(T) 
T pop_back()    
void erase(iterator)        
void erase(iterator1, iterator2)

void clear()     
void insert(iterator, T)       

void iterator begin()	
void iterator end()	

 
bool operator==(const MAvector<T>&) 
bool operator< (const MAvector<T>&) 
	

 
int size() const     
int capacity() const  
int resize()         
bool empty()         

};
#endif