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
using namespace std;

class DNA_String{
    public:
        //Constructs object and opens input stream with given file name
        DNA_String(string fileName);

        //Destructs object and closes input stream
        ~DNA_String();

        //returns true if the input stream has been opened
        bool inStream_is_open();

        //closes output stream
        static void closeOutputStream();

        //returns true if the output stream has been opened
        static bool outStream_is_open();

        //Calls functions for collecting data from the text file
        //and for using that data to calculate statistical values
        //required for string generation
        void calculateValues();

        //prints results and newly generated strings to 
        //the static output stream by calling helper functions
        void outputToFile();
        
    private:
        //Prints DNA String statistics to the output file
        void outputStatistics();

        //Prints 1000 lines of randomly generated DNA strings
        //to the output file that will have the same statistics
        //as the input file's strings        
        void outputGeneration();

        //Counts number of strings, total string lentgh,
        //number of each nucleotide, number of each bigram
        void collectData();

        //Calculates mean, variance, and standard deviation of
        //the length of the DNA strings as well as the probability of
        //each nucleotide and bigram using values from collectData()
        void calculateStatistics();

        //calculates mean string length
        void calculateMean();

        //calculates string length variance
        void calculateVariance();

        //calculates string length standard deviation
        void calculateStandardDeviation();

        //calculates statistical probablilites of 
        //all nucleotide types
        void calculateProbabilities();

        //trims string to contain only uppercase nucleotide letters
        //will convert any lowercase nucleotide letters to uppercase
        string trimString(string fileName);

        ifstream inStream;
        bool inStreamIsOpen;

        static ofstream outStream;

        //number of strings of nucleotide characters
        int countStrings = 0;

        //number of nucleotide characters
        int countNucleotides = 0; 

        //number of each type of nucleotide
        int countA = 0;
        int countC = 0;
        int countT = 0;
        int countG = 0;

        //total number of nucleotide bigrams
        int countBigrams = 0; 

        //number of each type of nucleotide bigram
        int countAA = 0;
        int countAC = 0;
        int countAT = 0;
        int countAG = 0;

        int countCA = 0;
        int countCC = 0;
        int countCT = 0;
        int countCG = 0;

        int countTA = 0;
        int countTC = 0;
        int countTT = 0;
        int countTG = 0;

        int countGA = 0;
        int countGC = 0;
        int countGT = 0;
        int countGG = 0;

        //the statistical values of the string lengths
        //stored as doubles but will be used to find
        //rounded values at time of string generation
        double lengthMean = 0;
        double lengthVariance = 0;
        double lengthStandardDeviation = 0;

        //the statisical probability of each 
        //nucleotide type
        double probabilityA = 0;
        double probabilityC = 0;
        double probabilityT = 0;
        double probabilityG = 0;

        //the statistical probability of each
        //nucleotide bigram type
        double probabilityAA = 0;
        double probabilityAC = 0;
        double probabilityAT = 0;
        double probabilityAG = 0;

        double probabilityCA = 0;
        double probabilityCC = 0;
        double probabilityCT = 0;
        double probabilityCG = 0;

        double probabilityTA = 0;
        double probabilityTC = 0;
        double probabilityTT = 0;
        double probabilityTG = 0;

        double probabilityGA = 0;
        double probabilityGC = 0;
        double probabilityGT = 0;
        double probabilityGG = 0;
};