#include <bits/stdc++.h>
using namespace std;

#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ll long long

template<class T>
class Set{
    private:
        vector<T> v;
    public:
        Set(){
            cout << "your set has been created.\n";
        }
        void Push(T itm){
            // vector<T>::iterator it;
            // it = find(v.begin(), v.end(), itm);
            if (find(v.begin(), v.end(), itm) == v.end()){
                v.push_back(itm);
            }
        }
        int Counter(){
            return v.size();
        }
        bool isExist(T itm){
            // vector<T>::iterator it;
            // it = find(v.begin(), v.end(), itm);
            if (find(v.begin(), v.end(), itm) != v.end()) return true;
            return false;
        }  
        void remove(T itm){
            for (auto i = v.begin(); i != v.end(); i++){
                if (*i == itm){
                    v.erase(i);
                    return;
                }
            }
        }
        bool operator==(Set& another){
            if (this->v.size() != another.v.size())return false;
            for (int i = 0; i < v.size(); i++){
                if (this->v[i] != another.v[i]) return false;
            }
            return true;
        }
        bool operator!=(Set& another){
            if (this->v.size() != another.v.size())return true;
            for (int i = 0; i < v.size(); i++){
                if (this->v[i] != another.v[i]) return true;
            }
            return false;
        }
        
    T* new_delete(){
        T* arr = new T[mylist.size()];
        auto it = mylist.begin() ;
        for( int i = 0;it != mylist.end() ; it++){
            arr[i] = *it ;
            i++ ;
        }
        mylist.clear();
        return arr ;
    }

};

int main(){
    Set<int> s;
    s.Push(5);
    s.Push(5);
    s.Push(5);
    s.remove(5);
    cout << s.Counter() << endl;

}
