/*
Name:  Dan Haub
Student ID#:  2315346
Chapman Email:  haub@chapman.edu
Course Number and Section:  CPSC 350-01
Assignment:  1 - DNA Strings
*/

#include <iostream>
#include <fstream>
#include <string>
#include "DNA_String.h"
using namespace std;

int main(int argc, char **argv){
    string fileNameIn = "";

    bool anotherGeneration = false;
    do{
        cout << "Please enter the name of a text file\n:  ";
        cin >> fileNameIn;
        DNA_String dna(fileNameIn);
        while(!dna.inStream_is_open()){
            dna.~DNA_String();
            cout << "Your file name was invalid.\n"
                 << "Please enter the name of a text file\n:  ";
            cin >> fileNameIn;
            DNA_String dna(fileNameIn);
        }
        dna.calculateValues();
        dna.outputToFile();

        cout << endl   
             << "Test another? [y/n]  ";
        char answer;
        cin >> answer;
        
        if(answer == 'y' || answer == 'Y')
            anotherGeneration = true;
        else
            anotherGeneration = false;
        
        cout << endl;
    }while(anotherGeneration);

    return 0;
}