#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include "DNA_String.h"
using namespace std;

//Constructs object and opens file
DNA_String::DNA_String(string file){
    stream.open(file);
    file_is_open = stream.is_open(); //confirms file has opened. Run this test before calling functions
}

//Destructs object
DNA_String::~DNA_String(){
    cout << "Object deleted\n";
}

//only counts nucleotide letters
//returns true if data collection works
bool DNA_String::collectData(){
    if(!file_is_open){
        return false;
    }

    string line = "";

    while (getline(myfile, line){
        cout << line << endl; //prints each line checked

        line = trimString(line);

        countStrings++; //increments string counter for later calculations
        totalStringLength += line.size(); //adds current line size to total for later calculations
        
        bool isEven = line.size()%2==0; //checks to see if there is an even number of nucleotides
        bool countBigram = true; //flips between on and off to test each pair of nucleotides

        for (int i = 0; i < line.size(); i++){
            //nucleotide counting:
            if(line[i] == 'A')
                countA++;
            if(line[i] == 'C')
                countC++;
            if(line[i] == 'G')
                countG++;
            if(line[i] == 'T')
                countT++;

            //bigraph counting
            if(!isEven&&counBigram&&(i!=line.size()-1)){
                
            }
        }
    }

    return true
}

string DNA_String::trimString(string s)
{
    string newString = "";
    locale loc;

    for (int i = 0; i < s.size(); i++)
    {
        s[i] = toupper(s[i], loc);
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'T' || s[i] == 'G')
        {
            newString += s[i];
        }
    }

    return newString;
}