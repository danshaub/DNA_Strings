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
#include "dna_string.h"
using namespace std;

ofstream NucleotideStringGenerator::out_stream = ofstream("danHaub.out", ios::out | ios::app);

//Constructs object and opens input stream with given file name
NucleotideStringGenerator::NucleotideStringGenerator(string fileName){
    in_stream.open(fileName);
    
    //tests to see if innput stream opened successfully
    in_stream_is_open = in_stream.is_open();
}

//Destructs object and closes input stream
NucleotideStringGenerator::~NucleotideStringGenerator(){
    in_stream.close();
    cout << "Object deleted\n";
}

//returns true if the input stream has been opened
bool NucleotideStringGenerator::InStreamIsOpen(){
    return in_stream.is_open();
}

//closes output stream
void NucleotideStringGenerator::CloseOutputStream(){
    out_stream.close();
}

//returns true if the output stream has been opened
bool NucleotideStringGenerator::OutStreamIsOpen(){
    return out_stream.is_open();
}

//Calls functions for collecting data from the text file
//and for using that data to calculate statistical values
//required for string generation
void NucleotideStringGenerator::CalculateValues(){
    CollectData();
    CalculateStatistics();
}

//prints results and newly generated strings to 
//the static output stream by calling helper functions
void NucleotideStringGenerator::OutputToFile(){
    if(!OutStreamIsOpen()){
        cout << "File output failed\n";
        return;
    }

    OutputStatistics();
    OutputGeneration();

}

//Prints DNA String statistics to the output file
void NucleotideStringGenerator::OutputStatistics(){
    out_stream << "\nStatistics for DNA Strings:\n"
              << "\tTotal number of strings:              " << count_strings << endl
              << "\t\tMean string length:                   " << length_mean << endl
              << "\t\tVariance  of string length:           " << length_variance<< endl
              << "\t\tStandard Deviation of string length:  " << length_standard_deviation << endl << endl << endl


              << "\tTotal number of Nucleotides:          " << countNucleotides << endl
              << "\t\tTotal number of A nucleotides:        " << count_A << endl
              << "\t\t\tProbability of A Nucleotides:         " <<probability_A * 100 << "\%" << endl
              << "\t\tTotal number of C nucleotides:        " << count_C << endl
              << "\t\t\tProbability of C Nucleotides:         " <<probability_C * 100 << "\%" << endl
              << "\t\tTotal number of T nucleotides:        " << count_T << endl
              << "\t\t\tProbability of T Nucleotides:         " <<probability_T * 100 << "\%" << endl
              << "\t\tTotal number of G nucleotides:        " << count_G << endl
              << "\t\t\tProbability of G Nucleotides:         " <<probability_G * 100 << "\%" << endl << endl << endl


              << "\tTotal number of Nucleotide Bigrams:   " << count_bigrams << endl
              << "\t\tTotal number of AA Bigrams:           " << count_AA << endl
              << "\t\t\tProbability of AA Bigrams:            " <<probability_AA * 100 << "\%" << endl
              << "\t\tTotal number of AC Bigrams:           " << count_AC << endl
              << "\t\t\tProbability of AC Bigrams:            " <<probability_AC * 100 << "\%" << endl
              << "\t\tTotal number of AT Bigrams:           " << count_AT << endl
              << "\t\t\tProbability of AT Bigrams:            " <<probability_AT * 100 << "\%" << endl
              << "\t\tTotal number of AG Bigrams:           " << count_AG << endl
              << "\t\t\tProbability of AG Bigrams:            " <<probability_AG * 100 << "\%" << endl << endl

              << "\t\tTotal number of CA Bigrams:           " << count_CA << endl
              << "\t\t\tProbability of CA Bigrams:            " <<probability_CA * 100 << "\%" << endl
              << "\t\tTotal number of CC Bigrams:           " << count_CC << endl
              << "\t\t\tProbability of CC Bigrams:            " <<probability_CC * 100 << "\%" << endl
              << "\t\tTotal number of CT Bigrams:           " << count_CT << endl
              << "\t\t\tProbability of CT Bigrams:            " <<probability_CT * 100 << "\%" << endl
              << "\t\tTotal number of CG Bigrams:           " << count_CG << endl
              << "\t\t\tProbability of CG Bigrams:            " <<probability_CG * 100 << "\%" << endl << endl
 
              << "\t\tTotal number of TA Bigrams:           " << count_TA << endl
              << "\t\t\tProbability of TA Bigrams:            " <<probability_TA * 100 << "\%" << endl
              << "\t\tTotal number of TC Bigrams:           " << count_TC << endl
              << "\t\t\tProbability of TC Bigrams:            " <<probability_TC * 100 << "\%" << endl
              << "\t\tTotal number of TT Bigrams:           " << count_TT << endl
              << "\t\t\tProbability of TT Bigrams:            " <<probability_TT * 100 << "\%" << endl
              << "\t\tTotal number of TG Bigrams:           " << count_TG << endl
              << "\t\t\tProbability of TG Bigrams:            " <<probability_TG * 100 << "\%" << endl << endl

              << "\t\tTotal number of GA Bigrams:           " << count_GA << endl
              << "\t\t\tProbability of GA Bigrams:            " <<probability_GA * 100 << "\%" << endl
              << "\t\tTotal number of GC Bigrams:           " << count_GC << endl
              << "\t\t\tProbability of GC Bigrams:            " <<probability_GC * 100 << "\%" << endl
              << "\t\tTotal number of GT Bigrams:           " << count_GT << endl
              << "\t\t\tProbability of GT Bigrams:            " <<probability_GT * 100 << "\%" << endl
              << "\t\tTotal number of GG Bigrams:           " << count_GG << endl
              << "\t\t\tProbability of GG Bigrams:            " <<probability_GG * 100 << "\%" << endl << endl;
}

//Prints 1000 lines of randomly generated DNA strings
//to the output file that will have the same statistics
//as the input file's strings
void NucleotideStringGenerator::OutputGeneration(){
    out_stream << "String generation:\n\n";
    const double PI = 3.14159265358979323846;

    //calculates ranges for the different nucleotide types.
    //If a random number generated falls within the range
    //of a specific nucleotide, the new character associated
    //with that random number becomes the range's nucleotide
    double rangeA = probability_A;
    double rangeC = probability_A + probability_C;
    double rangeT = probability_A + probability_C + probability_T;
    
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
        int d = int(length_standard_deviation * c + length_mean);

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

        out_stream << line << endl;
    }
}

//Counts number of strings, total string lentgh,
//number of each nucleotide, number of each bigram
void NucleotideStringGenerator::CollectData(){

    //returns false if file has not been opened.
    if (!in_stream_is_open)
    {
        cout << "Data collection failed\n";
        return;
    }

    string line = "";

    //iterates through all lines of text file
    while (getline(in_stream, line)){

        line = PrepareString(line); //removes all non-nucleotide characters and converts the line to uppercase

        //cout << line << endl; //prints each trimmed line checked

        count_strings++; //increments string counter for later calculations
        countNucleotides += line.size(); //adds current line size to total for later calculations
        
        bool isBigramStart = true; //true if current character is the start of a bigram

        //iterates through all characters in the string
        for (int i = 0; i < line.size(); i++){
            //nucleotide counting:
            if(line[i] == 'A')
                count_A++;
            if(line[i] == 'C')
                count_C++;
            if(line[i] == 'G')
                count_G++;
            if(line[i] == 'T')
                count_T++;

            //bigraph counting
            //control statement tests if current character is 
            //not the last character in the string and if it is
            //a beginning character of a bigram
            if(!(i >= line.size()-1) && isBigramStart){
                count_bigrams++; //adds current bigram to the total bigram count
                
                //creates string for the current bigram
                string bigram = "";
                bigram+= line[i];
                bigram+= line[i+1];

                if (!(bigram.compare("AA")))
                    count_AA++;
                if (!(bigram.compare("AC")))
                    count_AC++;
                if (!(bigram.compare("AT")))
                    count_AT++;
                if (!(bigram.compare("AG")))
                    count_AG++;

                if (!(bigram.compare("CA")))
                    count_CA++;
                if (!(bigram.compare("CC")))
                    count_CC++;
                if (!(bigram.compare("CT")))
                    count_CT++;
                if (!(bigram.compare("CG")))
                    count_CG++;

                if (!(bigram.compare("TA")))
                    count_TA++;
                if (!(bigram.compare("TC")))
                    count_TC++;
                if (!(bigram.compare("TT")))
                    count_TT++;
                if (!(bigram.compare("TG")))
                    count_TG++;

                if (!(bigram.compare("GA")))
                    count_GA++;
                if (!(bigram.compare("GC")))
                    count_GC++;
                if (!(bigram.compare("GT")))
                    count_GT++;
                if (!(bigram.compare("GG")))
                    count_GG++;

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
//each nucleotide and bigram using values from CollectData()
void NucleotideStringGenerator::CalculateStatistics(){
    CalculateMean();
    CalculateVariance();
    CalculateStandardDeviation();
    CalculateProbabilities();
}

//calculates mean string length
void NucleotideStringGenerator::CalculateMean(){
    length_mean = double(countNucleotides) / double(count_strings);
}

//calculates string length variance
void NucleotideStringGenerator::CalculateVariance(){
    //resets input stream position to beginning
    in_stream.clear();
    in_stream.seekg(0, in_stream.beg);

    double squareSum = 0;
    string line = "";

    //traverses entire text file and summs 
    //the squares of the differences between
    //the length of the current string and the 
    //mean string length
    while (getline(in_stream, line)){
        line = PrepareString(line);
        cout << line << endl; //prints each trimmed line checked
        squareSum += pow((line.size()-length_mean), 2.0);
    }

    length_variance = squareSum/count_strings;
}

//calculates string length standard deviation
void NucleotideStringGenerator::CalculateStandardDeviation(){
    length_standard_deviation = sqrt(length_variance);
}

//calculates statistical probablilites of 
//all nucleotide types
void NucleotideStringGenerator::CalculateProbabilities(){
    probability_A = double(count_A)/countNucleotides;
    probability_C = double(count_C)/countNucleotides;
    probability_T = double(count_T)/countNucleotides;
    probability_G = double(count_G)/countNucleotides;

    probability_AA = double(count_AA)/count_bigrams;
    probability_AC = double(count_AC)/count_bigrams;
    probability_AT = double(count_AT)/count_bigrams;
    probability_AG = double(count_AG)/count_bigrams;

    probability_CA = double(count_CA)/count_bigrams;
    probability_CC = double(count_CC)/count_bigrams;
    probability_CT = double(count_CT)/count_bigrams;
    probability_CG = double(count_CG)/count_bigrams;

    probability_TA = double(count_TA)/count_bigrams;
    probability_TC = double(count_TC)/count_bigrams;
    probability_TT = double(count_TT)/count_bigrams;
    probability_TG = double(count_TG)/count_bigrams;

    probability_GA = double(count_GA)/count_bigrams;
    probability_GC = double(count_GC)/count_bigrams;
    probability_GT = double(count_GT)/count_bigrams;
    probability_GG = double(count_GG)/count_bigrams;
}

//trims string to contain only uppercase nucleotide letters
//will convert any lowercase nucleotide letters to uppercase
string NucleotideStringGenerator::PrepareString(string s){
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
