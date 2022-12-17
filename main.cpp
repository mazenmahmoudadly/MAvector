#include"A3_Task1_GA_S7_S8_20210318_20210280.cpp"
#include<vector>
using namespace std;

int main(){
    MAvector<int> g1;


    for (int i = 0; i < 5; i++){ // 0 1 2 3 4 
        g1.push_back(i);
    }

    for (int i = 0; i < 5; i++){
        cout << g1[i] << " ";
    }

    g1.push_back(8); // 0 1 2 3 4 8
    cout << endl;

    cout << g1.vecCapacity(); // 8
    cout << endl;

    g1.erase(g1.begin() + 2, g1.begin() + 4); // 0 1 3 4 8
    cout << g1;
}