#include <iostream>
#include <fstream>
#include <string>
#include "DNA_String.h"
using namespace std;

int main(int argc, char **argv){
    string fileName = "";

    bool anotherGeneration = false;
    do{
        cout << "Please enter the name of a text file\n:  ";
        cin >> fileName;
        DNA_String dna(fileName);
        while(!dna.file_is_open()){
            dna.~DNA_String();
            cout << "Your file name was invalid.\n"
                 << "Please enter the name of a text file\n:  ";
            cin >> fileName;
            DNA_String dna(fileName);
        }
        dna.collectData();

        cout << endl   
             << "Test another? [y/n]  ";
        char answer;
        cin >> answer;
        
        if(answer == 'y' || answer == 'Y')
            anotherGeneration = true;
        else
            anotherGeneration = false;
        
        cout << endl;
        dna.~DNA_String();
    }while(anotherGeneration);

    return 0;
}