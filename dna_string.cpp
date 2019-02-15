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
#include <locale>
#include <math.h>
#include "DNA_String.h"
using namespace std;

ofstream DNA_String::outStream = ofstream("danHaub.out", ios::out | ios::app);

//Constructs object and opens input stream with given file name
DNA_String::DNA_String(string fileName){
    inStream.open(fileName);
    
    //tests to see if innput stream opened successfully
    inStreamIsOpen = inStream.is_open();
}

//Destructs object and closes input stream
DNA_String::~DNA_String(){
    inStream.close();
    cout << "Object deleted\n";
}

//returns true if the input stream has been opened
bool DNA_String::inStream_is_open(){
    return inStream.is_open();
}

//closes output stream
void DNA_String::closeOutputStream(){
    outStream.close();
}

//returns true if the output stream has been opened
bool DNA_String::outStream_is_open(){
    return outStream.is_open();
}

//Calls functions for collecting data from the text file
//and for using that data to calculate statistical values
//required for string generation
void DNA_String::calculateValues(){
    collectData();
    calculateStatistics();
}

//prints results and newly generated strings to 
//the static output stream by calling helper functions
void DNA_String::outputToFile(){
    if(!outStream_is_open()){
        cout << "File output failed\n";
        return;
    }

    outputStatistics();
    outputGeneration();

}

//Prints DNA String statistics to the output file
void DNA_String::outputStatistics(){
    outStream << "\nStatistics for DNA Strings:\n"
              << "\tTotal number of strings:              " << countStrings << endl
              << "\t\tMean string length:                   " << lengthMean << endl
              << "\t\tVariance  of string length:           " << lengthVariance<< endl
              << "\t\tStandard Deviation of string length:  " << lengthStandardDeviation << endl << endl << endl


              << "\tTotal number of Nucleotides:          " << countNucleotides << endl
              << "\t\tTotal number of A nucleotides:        " << countA << endl
              << "\t\t\tProbability of A Nucleotides:         " <<probabilityA * 100 << "\%" << endl
              << "\t\tTotal number of C nucleotides:        " << countC << endl
              << "\t\t\tProbability of C Nucleotides:         " <<probabilityC * 100 << "\%" << endl
              << "\t\tTotal number of T nucleotides:        " << countT << endl
              << "\t\t\tProbability of T Nucleotides:         " <<probabilityT * 100 << "\%" << endl
              << "\t\tTotal number of G nucleotides:        " << countG << endl
              << "\t\t\tProbability of G Nucleotides:         " <<probabilityG * 100 << "\%" << endl << endl << endl


              << "\tTotal number of Nucleotide Bigrams:   " << countBigrams << endl
              << "\t\tTotal number of AA Bigrams:           " << countAA << endl
              << "\t\t\tProbability of AA Bigrams:            " <<probabilityAA * 100 << "\%" << endl
              << "\t\tTotal number of AC Bigrams:           " << countAC << endl
              << "\t\t\tProbability of AC Bigrams:            " <<probabilityAC * 100 << "\%" << endl
              << "\t\tTotal number of AT Bigrams:           " << countAT << endl
              << "\t\t\tProbability of AT Bigrams:            " <<probabilityAT * 100 << "\%" << endl
              << "\t\tTotal number of AG Bigrams:           " << countAG << endl
              << "\t\t\tProbability of AG Bigrams:            " <<probabilityAG * 100 << "\%" << endl << endl

              << "\t\tTotal number of CA Bigrams:           " << countCA << endl
              << "\t\t\tProbability of CA Bigrams:            " <<probabilityCA * 100 << "\%" << endl
              << "\t\tTotal number of CC Bigrams:           " << countCC << endl
              << "\t\t\tProbability of CC Bigrams:            " <<probabilityCC * 100 << "\%" << endl
              << "\t\tTotal number of CT Bigrams:           " << countCT << endl
              << "\t\t\tProbability of CT Bigrams:            " <<probabilityCT * 100 << "\%" << endl
              << "\t\tTotal number of CG Bigrams:           " << countCG << endl
              << "\t\t\tProbability of CG Bigrams:            " <<probabilityCG * 100 << "\%" << endl << endl
 
              << "\t\tTotal number of TA Bigrams:           " << countTA << endl
              << "\t\t\tProbability of TA Bigrams:            " <<probabilityTA * 100 << "\%" << endl
              << "\t\tTotal number of TC Bigrams:           " << countTC << endl
              << "\t\t\tProbability of TC Bigrams:            " <<probabilityTC * 100 << "\%" << endl
              << "\t\tTotal number of TT Bigrams:           " << countTT << endl
              << "\t\t\tProbability of TT Bigrams:            " <<probabilityTT * 100 << "\%" << endl
              << "\t\tTotal number of TG Bigrams:           " << countTG << endl
              << "\t\t\tProbability of TG Bigrams:            " <<probabilityTG * 100 << "\%" << endl << endl

              << "\t\tTotal number of GA Bigrams:           " << countGA << endl
              << "\t\t\tProbability of GA Bigrams:            " <<probabilityGA * 100 << "\%" << endl
              << "\t\tTotal number of GC Bigrams:           " << countGC << endl
              << "\t\t\tProbability of GC Bigrams:            " <<probabilityGC * 100 << "\%" << endl
              << "\t\tTotal number of GT Bigrams:           " << countGT << endl
              << "\t\t\tProbability of GT Bigrams:            " <<probabilityGT * 100 << "\%" << endl
              << "\t\tTotal number of GG Bigrams:           " << countGG << endl
              << "\t\t\tProbability of GG Bigrams:            " <<probabilityGG * 100 << "\%" << endl << endl;
}

//Prints 1000 lines of randomly generated DNA strings
//to the output file that will have the same statistics
//as the input file's strings
void DNA_String::outputGeneration(){
    outStream << "String generation:\n\n";
    const double PI = 3.14159265358979323846;

    //calculates ranges for the different nucleotide types.
    //If a random number generated falls within the range
    //of a specific nucleotide, the new character associated
    //with that random number becomes the range's nucleotide
    double rangeA = probabilityA;
    double rangeC = probabilityA + probabilityC;
    double rangeT = probabilityA + probabilityC + probabilityT;
    
    for(int i = 1; i <= 1000; i++){
        //generates two random numbers between 0 and 1
        double a = 1 - (double(rand())/(RAND_MAX));
        double b = 1 - (double(rand())/(RAND_MAX));
        
        //uses a and b to generate a random number between
        //-1 and 1 with a gaussian probability centered at 0
        double c = (sqrt(-2 * log(a)) * cos(2 * PI * b));

        //c to generate a random string length d that
        //follows a gaussian curve witht the same standard deviation
        //and mean as the string lengths of the input file
        int d = int(lengthStandardDeviation * c + lengthMean);

        string line = "";

        //uses ranges calculated above to populate
        //the new string of length d
        for(int j = 0; j < d; j++){
            double e = (double(rand())/(RAND_MAX));

            if(e <= rangeA){
                line += "A";
            } else if(e <= rangeC){
                line += "C";
            } else if(e <= rangeT){
                line += "T";
            } else{
                line += "G";
            }
        }

        outStream << line << endl;
    }
}

//Counts number of strings, total string lentgh,
//number of each nucleotide, number of each bigram
void DNA_String::collectData(){

    //returns false if file has not been opened.
    if (!inStreamIsOpen)
    {
        cout << "Data collection failed\n";
        return;
    }

    string line = "";

    //iterates through all lines of text file
    while (getline(inStream, line)){

        line = trimString(line); //removes all non-nucleotide characters and converts the line to uppercase

        //cout << line << endl; //prints each trimmed line checked

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

    return;
}

//Calculates mean, variance, and standard deviation of
//the length of the DNA strings as well as the probability of
//each nucleotide and bigram using values from collectData()
void DNA_String::calculateStatistics(){
    calculateMean();
    calculateVariance();
    calculateStandardDeviation();
    calculateProbabilities();
}

//calculates mean string length
void DNA_String::calculateMean(){
    lengthMean = double(countNucleotides) / double(countStrings);
}

//calculates string length variance
void DNA_String::calculateVariance(){
    //resets input stream position to beginning
    inStream.clear();
    inStream.seekg(0, inStream.beg);

    double squareSum = 0;
    string line = "";

    //traverses entire text file and summs 
    //the squares of the differences between
    //the length of the current string and the 
    //mean string length
    while (getline(inStream, line)){
        line = trimString(line);
        cout << line << endl; //prints each trimmed line checked
        squareSum += pow((line.size()-lengthMean), 2.0);
    }

    lengthVariance = squareSum/countStrings;
}

//calculates string length standard deviation
void DNA_String::calculateStandardDeviation(){
    lengthStandardDeviation = sqrt(lengthVariance);
}

//calculates statistical probablilites of 
//all nucleotide types
void DNA_String::calculateProbabilities(){
    probabilityA = double(countA)/countNucleotides;
    probabilityC = double(countC)/countNucleotides;
    probabilityT = double(countT)/countNucleotides;
    probabilityG = double(countG)/countNucleotides;

    probabilityAA = double(countAA)/countBigrams;
    probabilityAC = double(countAC)/countBigrams;
    probabilityAT = double(countAT)/countBigrams;
    probabilityAG = double(countAG)/countBigrams;

    probabilityCA = double(countCA)/countBigrams;
    probabilityCC = double(countCC)/countBigrams;
    probabilityCT = double(countCT)/countBigrams;
    probabilityCG = double(countCG)/countBigrams;

    probabilityTA = double(countTA)/countBigrams;
    probabilityTC = double(countTC)/countBigrams;
    probabilityTT = double(countTT)/countBigrams;
    probabilityTG = double(countTG)/countBigrams;

    probabilityGA = double(countGA)/countBigrams;
    probabilityGC = double(countGC)/countBigrams;
    probabilityGT = double(countGT)/countBigrams;
    probabilityGG = double(countGG)/countBigrams;
}

//trims string to contain only uppercase nucleotide letters
//will convert any lowercase nucleotide letters to uppercase
string DNA_String::trimString(string s){
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