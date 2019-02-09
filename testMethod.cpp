#include <iostream>
#include <fstream>
#include <string>
#include <locale>
using namespace std;

bool collectData();
string trimString(string s);

int main(){

    collectData();
    return 0;
}

bool collectData()
{
    ifstream stream;
    stream.open("test.txt");
    bool file_is_open = stream.is_open();

    int countStrings = 0;
    int countNucleotides = 0;

    int countA = 0;
    int countC = 0;
    int countT = 0;
    int countG = 0;

    int countBigrams = 0;

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

    if (!file_is_open)
    {
        return false;
    }

    string line = "";

    while (getline(stream, line)){
        line = trimString(line); //removes all non-nucleotide characters and converts the line to uppercase

        cout << line << endl; //prints each line checked in the format required

        countStrings++;                  //increments string counter for later calculations
        countNucleotides += line.size(); //adds current line size to total for later calculations

        bool isBigramStart = true; //flips between on and off to test each pair of nucleotides

        for (int i = 0; i < line.size(); i++)
        {
            //nucleotide counting:
            if (line[i] == 'A')
                countA++;
            if (line[i] == 'C')
                countC++;
            if (line[i] == 'G')
                countG++;
            if (line[i] == 'T')
                countT++;

            //bigraph counting
            if (!(i >= line.size() - 1) && isBigramStart)
            {
                countBigrams++; //adds current bigram to the total bigram count

                string bigram = "";
                bigram += line[i];
                bigram += line[i + 1];

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
            else
            {
                isBigramStart = true;
            }
        }
    }

    cout << countStrings << endl
         << countNucleotides << endl
         << countBigrams << endl << endl
         << countA << endl
         << countC << endl
         << countT << endl
         << countG << endl << endl
         << countAA << endl
         << countAC << endl
         << countAT << endl
         << countAG << endl << endl
         << countCA << endl
         << countCC << endl
         << countCT << endl
         << countCG << endl << endl
         << countTA << endl
         << countTC << endl
         << countTT << endl
         << countTG << endl << endl
         << countGA << endl
         << countGC << endl
         << countGT << endl
         << countGG << endl << endl;
         


    return true;
}

string trimString(string s)
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