#include <iostream>
#include <fstream>
#include <string>
#include "DNA_String.h"
using namespace std;

int main(int argc, char **argv){
    if(argc < 1){
        cout << "Please provide a file for analysis\n";
        return 0;
    }

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

    ifstream myfile ("test.txt");

    if(myfile.is_open()){

        string line = "";

        while(getline(myfile, line)){
            cout << line << endl;
            bool isEven = 
            for(int i = 0; i < line.size(); i++){

            }
        }

    } else {
        cout << "file could not open\n";
    }

    return 0;
}