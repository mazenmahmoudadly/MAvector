#include <bits/stdc++.h>

using namespace std;
template <class T>
class Stack{
private:
    T *arr;
    int size = 0;
    int capacity = 0;

public:
    Stack(int size){
        arr = new T[size];
        capacity = size;
    }

    ~Stack(){
        delete[] arr;
        arr = nullptr;
    }

    void puch_back(T element){
        if (size == capacity){
            cout << "Stack is full" << endl;
        }
        else{
            arr[size] = element;
            size++;
        }
    }

    void pop_back(){
        if (size == 0){
            cout << "Stack is empty" << endl;
        }
        else{
            size--;
        }
    }
    void print(){
        if (size == 0){
            cout << "Stack is empty" << endl;
        }
        else{
            for (int i = 0; i < size; ++i){
                cout << arr[i];
                if (i != size - 1){
                    cout << ", ";
                }
            }
            cout << endl;
        }
    }

    void manageStack(){
        char option;
        T element;
        while (true){
            cout << "1- Push\n" << "2- Pop\n" << "3- Print\n" << "4- Exit\n";
            cout << "choose: ";
            cin >> option;
            if (option == '1'){
                cout << "Enter the element that you want to push it: ";
                cin >> element;
                puch_back(element);
            }
            else if (option == '2'){
                pop_back();
            }
            else if (option == '3'){
                print();
            }
            else if (option == '4'){
                break;
            }
            else{
                cout << "Invalid option" << endl;
            }
        }
    }
};

int main(){
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;
    Stack<int> s(size);
    s.manageStack();
}