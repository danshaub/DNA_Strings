#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include "DNA_String.h"
using namespace std;

//Constructs object and opens file
DNA_String::DNA_String(string fileName){
    stream.open(fileName);
    fileIsOpen = stream.is_open(); //confirms file has opened. Run this test before calling functions
}

//Destructs object
DNA_String::~DNA_String(){
    stream.close();
    cout << "Object deleted\n";
}

//returns true if the file stream has been opened
bool DNA_String::file_is_open(){
    return fileIsOpen;
}

//Counts number of strings, total string lentgh,
//number of each nucleotide, number of each bigram,
//and calls function to calculate statistics
//returns true if data collection succedes
//returns false if file has not been opened.
bool DNA_String::collectData(){

    //returns false if file has not been opened.
    if(!fileIsOpen){
        return false;
    }

    string line = "";

    //iterates through all lines of text file
    while (getline(stream, line)){

        line = trimString(line); //removes all non-nucleotide characters and converts the line to uppercase

        cout << line << endl; //prints each trimmed line checked

        countStrings++; //increments string counter for later calculations
        countNucleotides += line.size(); //adds current line size to total for later calculations
        
        bool isBigramStart = true; //true if current character is the start of a bigram

        //iterates through all characters in the string
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
            //control statement tests if current character is 
            //not the last character in the string and if it is
            //a beginning character of a bigram
            if(!(i >= line.size()-1) && isBigramStart){
                countBigrams++; //adds current bigram to the total bigram count
                
                //creates string for the current bigram
                string bigram = "";
                bigram+= line[i];
                bigram+= line[i+1];

                if (!(bigram.compare("AA")))
                    countAA++;
                if (!(bigram.compare("AC")))
                    countAC++;
                if (!(bigram.compare("AT")))
                    countAT++;
                if (!(bigram.compare("AG")))
                    countAG++;

                if (!(bigram.compare("CA")))
                    countCA++;
                if (!(bigram.compare("CC")))
                    countCC++;
                if (!(bigram.compare("CT")))
                    countCT++;
                if (!(bigram.compare("CG")))
                    countCG++;

                if (!(bigram.compare("TA")))
                    countTA++;
                if (!(bigram.compare("TC")))
                    countTC++;
                if (!(bigram.compare("TT")))
                    countTT++;
                if (!(bigram.compare("TG")))
                    countTG++;

                if (!(bigram.compare("GA")))
                    countGA++;
                if (!(bigram.compare("GC")))
                    countGC++;
                if (!(bigram.compare("GT")))
                    countGT++;
                if (!(bigram.compare("GG")))
                    countGG++;

                isBigramStart = false;
            }
            else{
                isBigramStart = true;
            }
        }
    }

    calculateStatistics();

    return true;
}

//Calculates mean, variance, and standard deviation of
//the length of the DNA strings as well as the probability of
//each nucleotide and bigram
void DNA_String::calculateStatistics(){
    lengthMean = double(countNucleotides)/double(countStrings);
    
}

    //trims string to contain only uppercase nucleotide letters
    //will convert any lowercase nucleotide letters to uppercase
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