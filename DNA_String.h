#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class DNA_String{
    public:
        DNA_String(string file);
        ~DNA_String();
        
    private:
        void countNucleotides();
        bool calculateStringStats() 
        bool generate();

        int countStrings = 0;

        int countA = 0;
        int countC = 0;
        int countT = 0;
        int countG = 0;

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
}