#include"A3_Task1_GA_S7_S8_20210318_20210280.cpp"
#include<vector>
using namespace std;

int main(){
    MAvector<int> g1(5);

    for (int i = 0; i < 5; i++){ // 0 1 2 3 4 
        g1.push_back(i);
    }
    g1.pop_back();

    for (int i = 0; i < 5; i++){
        cout << g1[i] << " ";
    }

    g1.push_back(8); // 0 1 2 3 4 8
    cout << endl;

    cout << g1.vecCapacity(); // 10
    cout << endl;
}