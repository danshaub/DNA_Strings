#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class DNA_String{
    public:
        DNA_String(string file);
        ~DNA_String();
        bool collectData();
        bool file_is_open();
        //void outputToFile();

        
    private:
        void calculateStatistics()
        //bool generate();

        string trimString(string fileName);

        ifstream stream;
        bool fileIsOpen;

        int countStrings = 0; //number of strings of nucleotide characters
        int countNucleotides = 0; //number of nucleotide characters

        //number of each type of nucleotide
        int countA = 0;
        int countC = 0;
        int countT = 0;
        int countG = 0;

        int countBigrams = 0; //total number of nucleotide bigrams

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

        double lengthMean = 0;
        double lengthVariance = 0;
        double lengthStandardDeviation = 0;

        double probabilityA = 0;
        double probabilityC = 0;
        double probabilityG = 0;
        double probabilityT = 0;
};