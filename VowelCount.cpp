/** Count Vowels program - Enter some text and the program automatically counts the vowels and returns the total.
  * Copyrights (c) Frédéric Charette - 2016
  * https://github.com/rain79/CPP_Source
  *
  */

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

double iCountVowels = 0;
double iCountAs = 0;
double iCountEs = 0;
double iCountIs = 0;
double iCountOs = 0;
double iCountUs = 0;
double iCountYs = 0;

string ProgMenu(){

    string sSelection;
    char cSelect;

    cout << "Let's begin by making a selection from the following menu: \n";
    cout << "Enter a (F)ile Name (include the full path if the file is not in the same directory).\n";
    cout << "Enter the (T)ext directly in the console.\n";
    cout << "(Q)uit\n\n\n";
    cout << "Please make your selection now:";
    cin >> cSelect;
    cin.ignore();
    cin.clear();
    sSelection = toupper(cSelect);

    if(sSelection == "F" || sSelection == "T" || sSelection =="Q"){
        return sSelection;
    } else {
        ProgMenu();
    }
}

void CountVowels (string sTextToCheck){
    char cTxt;

    for (int i = 0; i < sTextToCheck.size()+1; i++){
    //cout << cTxt << endl;
    cTxt = sTextToCheck[i];
    cTxt = toupper(cTxt);
        switch(cTxt){
            case 'A':
                iCountAs++;
                iCountVowels++;
                break;
            case 'E':
                iCountEs++;
                iCountVowels++;
                break;
            case 'I':
                iCountIs++;
                iCountVowels++;
                break;
            case 'O':
                iCountOs++;
                iCountVowels++;
                break;
            case 'U':
                iCountUs++;
                iCountVowels++;
                break;
            case 'Y':
                iCountYs++;
                iCountVowels++;
                break;
            default :
                //not a vowels
                break;
        }
    }
}

void OpenFile(){
    string sFileName;
    string sReadLine;

    cout << "Please enter the name of the file you wish to work with: ";
    getline(cin, sFileName);
    cout << endl;
    ifstream MyFile(sFileName.c_str());
    if(!MyFile.is_open()){
        cout << "There was an error opening this file. Please try again\n\n";
        cout << "If the file is not in the same path as this application,\n";
        cout << "Be sure to specify the full path.\n"
        OpenFile();
    }
    else {
        while (getline (MyFile, sReadLine) ) {
            CountVowels(sReadLine);
        }
        MyFile.close();
    }
}

int main() {
    string sSelect;
    string sReadLine;

    cout << "Welcome to the Count Vowel Program!\n";
    cout << "This program will take a text and return the amount of vowels in the text... \n\n";

    sSelect = ProgMenu();
    cout << sSelect;
    if (sSelect == "F"){
        OpenFile();
    }
    else if (sSelect == "T"){
        cout << "Please enter the text below. (Press enter to analyze the text...)\n";
        getline(cin, sReadLine);
        CountVowels(sReadLine);
    }
    else if (sSelect == "Q"){
        return 0;
    }
    else {
        cout << "An error has occured... Please try again.";
        return 0;
    }

    cout << "There are " << iCountVowels << " vowels in this text." << endl;
    cout << "There are " << iCountAs << " \"A\"s in this text." << endl;
    cout << "There are " << iCountEs << " \"E\"s in this text." << endl;
    cout << "There are " << iCountIs << " \"I\"s in this text." << endl;
    cout << "There are " << iCountOs << " \"O\"s in this text." << endl;
    cout << "There are " << iCountUs << " \"U\"s in this text." << endl;
    cout << "There are " << iCountYs << " \"Y\"s in this text." << endl;
    
    return 0;
}
