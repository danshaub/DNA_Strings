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

class NucleotideStringGenerator{
    public:
        //Constructs object and opens input stream with given file name
        NucleotideStringGenerator(string fileName);

        //Destructs object and closes input stream
        ~NucleotideStringGenerator();

        //returns true if the input stream has been opened
        bool InStreamIsOpen();

        //closes output stream
        static void CloseOutputStream();

        //returns true if the output stream has been opened
        static bool OutStreamIsOpen();

        //Calls functions for collecting data from the text file
        //and for using that data to calculate statistical values
        //required for string generation
        void CalculateValues();

        //prints results and newly generated strings to 
        //the static output stream by calling helper functions
        void OutputToFile();
        
    private:
        //Prints DNA String statistics to the output file
        void OutputStatistics();

        //Prints 1000 lines of randomly generated DNA strings
        //to the output file that will have the same statistics
        //as the input file's strings        
        void OutputGeneration();

        //Counts number of strings, total string lentgh,
        //number of each nucleotide, number of each bigram
        void CollectData();

        //Calculates mean, variance, and standard deviation of
        //the length of the DNA strings as well as the probability of
        //each nucleotide and bigram using values from CollectData()
        void CalculateStatistics();

        //calculates mean string length
        void CalculateMean();

        //calculates string length variance
        void CalculateVariance();

        //calculates string length standard deviation
        void CalculateStandardDeviation();

        //calculates statistical probablilites of 
        //all nucleotide types
        void CalculateProbabilities();

        //trims string to contain only uppercase nucleotide letters
        //will convert any lowercase nucleotide letters to uppercase
        string PrepareString(string fileName);

        ifstream in_stream;
        bool in_stream_is_open;

        static ofstream out_stream;

        //number of strings of nucleotide characters
        int count_strings = 0;

        //number of nucleotide characters
        int countNucleotides = 0; 

        //number of each type of nucleotide
        int count_A = 0;
        int count_C = 0;
        int count_T = 0;
        int count_G = 0;

        //total number of nucleotide bigrams
        int count_bigrams = 0; 

        //number of each type of nucleotide bigram
        int count_AA = 0;
        int count_AC = 0;
        int count_AT = 0;
        int count_AG = 0;

        int count_CA = 0;
        int count_CC = 0;
        int count_CT = 0;
        int count_CG = 0;

        int count_TA = 0;
        int count_TC = 0;
        int count_TT = 0;
        int count_TG = 0;

        int count_GA = 0;
        int count_GC = 0;
        int count_GT = 0;
        int count_GG = 0;

        //the statistical values of the string lengths
        //stored as doubles but will be used to find
        //rounded values at time of string generation
        double length_mean = 0;
        double length_variance = 0;
        double length_standard_deviation = 0;

        //the statisical probability of each 
        //nucleotide type
        double probability_A = 0;
        double probability_C = 0;
        double probability_T = 0;
        double probability_G = 0;

        //the statistical probability of each
        //nucleotide bigram type
        double probability_AA = 0;
        double probability_AC = 0;
        double probability_AT = 0;
        double probability_AG = 0;

        double probability_CA = 0;
        double probability_CC = 0;
        double probability_CT = 0;
        double probability_CG = 0;

        double probability_TA = 0;
        double probability_TC = 0;
        double probability_TT = 0;
        double probability_TG = 0;

        double probability_GA = 0;
        double probability_GC = 0;
        double probability_GT = 0;
        double probability_GG = 0;
};