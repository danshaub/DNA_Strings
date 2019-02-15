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
#include "dna_string.h"
using namespace std;

int main(int argc, char **argv){
    string fileNameIn = "";

    bool argUsed = false; //tests if commandline arg file name has been used

    bool anotherGeneration = false; //tests if user has decided to generate more strings

    do{
        //uses arg file name only once
        if(argc > 1 && !argUsed){
            fileNameIn = argv[1];
            argUsed = true;
        }
        //otherwise uses a cin value for the file name
        else{
            cout << "Please enter the name of a text file\n:  ";
            cin >> fileNameIn;
        }

        NucleotideStringGenerator dna(fileNameIn); //tries to create NucleotideStringGenerator object with file name

        //if the file name is invalid, the object is deleted and
        //another file name is asked for
        while(!dna.InStreamIsOpen()){
            dna.~NucleotideStringGenerator();
            cout << "Your file name was invalid.\n"
                 << "Please enter the name of a text file\n:  ";
            cin >> fileNameIn;
            NucleotideStringGenerator dna(fileNameIn);
        }


        dna.CalculateValues();
        dna.OutputToFile();

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

    NucleotideStringGenerator::CloseOutputStream();
    return 0;
}