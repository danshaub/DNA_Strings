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
        DNA_String(string fileName);
        ~DNA_String();
        bool inStream_is_open();
        static void closeOutputStream();
        static bool outStream_is_open();
        void calculateValues();
        void outputToFile();
        
    private:
        void outputStatistics();
        void outputGeneration();
        void collectData();
        void calculateStatistics();
        void calculateMean();
        void calculateVariance();
        void calculateStandardDeviation();
        void calculateProbabilities();

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