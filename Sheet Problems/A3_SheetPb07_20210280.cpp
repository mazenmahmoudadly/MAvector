#include <bits/stdc++.h>
using namespace std;

void doWork(ifstream &File, map<string, int> &wordMap);
void printTable(map<string, int> &wordMap);

int main(){
    ifstream File;
    map<string, int> wordMap;

    doWork(File, wordMap);
    printTable(wordMap);


    return 0;
}

void openFile(ifstream& File){
    File.open("file.txt");
}

void doWork(ifstream& File, map<string, int>& wordMap){
    openFile(File);

    string word;
    int size; 
    char ch;

    while (File >> word)
    {
        size = word.size();
        if (size == 1){
            ch = word[0];
            if ((isdigit(ch) || ispunct(ch)) && ch != '-'){
                continue;
            }
        }

        if (ispunct(word[size-1])){
            word = word.substr(0, size-1);
        }

        for (int i = 0; i < word.size(); ++i){
            if (word[i] == '-'){
                continue;
            }
            word[i] = tolower(word[i]);
        }
        wordMap[word]++;
    }

    File.close();
}
void printTable(map<string, int>& wordMap)
{
    cout << setw(15) << "Word" << setw(20) << " Count" << endl;

    for (auto k : wordMap){
        cout << setw(15) <<  k.first << setw(20) << k.second << endl;
    }
}
