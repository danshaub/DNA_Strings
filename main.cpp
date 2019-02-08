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