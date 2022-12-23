#include<iostream>
#include<vector>
using namespace std;

void backtrack(int n,vector<string> arr,int i=0){
    if(i==3){
        for(int i=0;i<3;i++){
            cout<<i+1<<"- "<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    arr.push_back("RED");
    backtrack(n,arr, i+1);
    arr.pop_back();

        arr.push_back("YELLOW");
    backtrack(n,arr, i+1);
    arr.pop_back();

        arr.push_back("GREEN");
    backtrack(n,arr, i+1);
    arr.pop_back();
}
int main(){
    vector<string> arr;
    int num;
    cout<<"enter the number of traffic lights: ";
    cin>>num;
backtrack(num,arr,0);
}