/**
 * @file main.cpp
 * @author Amr Hesham Mohamed (20210280)
 * @author Mazen Mahmoud Shokry (20210318)
 * @brief this is the main file of the vector class(MAvector)
 * @version 0.1
 * @date 2022-12-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include"A3_Task1_GA_S7_S8_20210318_20210280.cpp"
#include<vector>
using namespace std;

/**
 * @brief the main function
 * 
 * @return int 
 */
int main(){
    MAvector<int> g1(10);

    for (int i = 0; i < 9; i++){ // 0 1 2 3 4 5 6 7 8 
        g1.push_back(i);
    }
    g1.pop_back();// 0 1 2 3 4 5 6 7 
     g1.erase(g1.begin(),g1.begin()+4); //  5 6 7 
    g1.insert(g1.begin()+1,10); // 5 10 6 7
     g1.push_back(8); //5 10 6 7 8
    for (int i = 0; i < 5; i++){
        cout << g1[i] << " ";
    }
    cout << endl;
    cout << g1.vecCapacity(); // 15
    cout << endl;
}