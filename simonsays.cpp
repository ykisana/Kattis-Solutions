#include <iostream>
#include <sstream>
#include <string>


using namespace std;
int main(){
    int lines;
    string sentence;
    string command;
    getline(cin, sentence);
    lines = stoi(sentence);


    for(int i = 0; i < lines; i++){
        getline(cin, sentence);

        command = sentence.substr(0,10);
        if(command == "Simon says"){
            sentence=sentence.substr(sentence.find_first_of(" \t")+1);
            sentence=sentence.substr(sentence.find_first_of(" \t")+1);
            cout << sentence << '\n';
        }
    }

}
