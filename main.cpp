#include <iostream>
#include <fstream> 
#include <vector>
using namespace std; 

bool isValid(string& word, string& contain_alpha, string& not_contain, string& correct_alpha, vector<string>& not_pos);

int main(void){
    ifstream file("words.txt");
    string str;
    getline(file, str);
    //cout<<str<<endl;
    string token, delimiters = "\",";
    vector<string> words;
    string::size_type prev = str.find_first_not_of(delimiters);
    string::size_type pos = str.find_first_of(delimiters, prev);
    while (string::npos != pos || string::npos != prev) {
        words.emplace_back(str.substr(prev, pos-prev));
        prev = str.find_first_not_of(delimiters, pos);
        pos = str.find_first_of(delimiters, prev);
    }
    string contain_alpha="son", correct_alpha="s____", not_contain = "tareiglychud";
    vector<string> not_pos = {"","o","n","n","s"};
    for(string word : words){
        if(isValid(word, contain_alpha, not_contain, correct_alpha, not_pos)){
            cout<<word<<endl;
        }   
    }
}

bool isValid(string& word, string& contain_alpha, string& not_contain, string& correct_alpha, vector<string>& not_pos){
    int cnt = 0;
    for(char c : contain_alpha){
        if(word.find(c) == string::npos){
            return false;
        }
    }

    for(char c : not_contain){
        if(word.find(c) != string::npos){
            return false;
        }
    }

    for(int i=0 ; i<word.size() ; i++){
        if(correct_alpha[i] != '_' && word[i] != correct_alpha[i]) return false;
    }

    for(int i=0 ; i<not_pos.size() ; i++){
        for(char c : not_pos[i]){
            if(word[i] == c) return false;
        }
    }

    return true;
}