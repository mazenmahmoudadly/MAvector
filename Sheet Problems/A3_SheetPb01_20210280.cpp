#include<bits/stdc++.h>
using namespace std;

void loadDict(const string &fileName);
void convertText(const string &Text, string prefix);

int main(){
    string text;
    cout << "Enter text you want to convert: ";
    cin >> text;
    for (int i = 0; i < text.size(); i++){
        text[i] = tolower(text[i]);
    }
    // convertText("ilovemymomanddad", "");
    convertText(text, "");
}

unordered_set<string> dict; 
void loadDict(const string& fileName){
    ifstream File(fileName);
    string token;
    while(File >> token){
        dict.insert(token);
    }
}
void convertText(const string& Text ,string prefix){
    loadDict("dictionary.txt");
    if(Text.empty()){
        cout << prefix << endl;
        return;
    }
    for(int i = 0; i < Text.size(); i++){
        string word = Text.substr(0, i + 1);
        string word2 = Text.substr(i + 1);

        if(dict.find(word) != dict.end()){
       
            convertText(word2, prefix + " " + word);
         
        }
    }
}