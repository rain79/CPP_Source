/** Count Vowels program - Enter some text and the program automatically counts the vowels and returns the total.
  * Copyrights (c) Frédéric Charette - 2016
  * 
  * for some reason; the code does not prompt for text on mobile...
  */
  
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void ProgHeader(){
   cout << "Welcome to the Count Vowel Program. This program will take your input on a text and return the amount of vowels in the text... \n\n";
}

int main() {

    char cTxt;
    int iCountVowels = 0;
    int iCountAs = 0;
    int iCountEs = 0;
    int iCountIs = 0;
    int iCountOs = 0;
    int iCountUs = 0;
    int iCountYs = 0;
    string sTextToCheck;
    
    ProgHeader();
    
    cout << "Please enter the text to count vowels from:";
    
    getline(cin, sTextToCheck);
    cout << endl << endl;
    
    for (int i = 0; i < sTextToCheck.size(); i++){
    
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
    
    cout << "There are " << iCountVowels << " vowels in this text." << endl;
    cout << "There are " << iCountAs << " \"A\"s in this text." << endl;
    cout << "There are " << iCountEs << " \"E\"s in this text." << endl;
    cout << "There are " << iCountIs << " \"I\"s in this text." << endl;
    cout << "There are " << iCountOs << " \"O\"s in this text." << endl;
    cout << "There are " << iCountUs << " \"U\"s in this text." << endl;
    cout << "There are " << iCountYs << " \"Y\"s in this text." << endl;
    
    return 0;
}
