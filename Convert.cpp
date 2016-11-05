/** Temperature converter 1.3
  * @authr: Frédéric Charette 2016
  *
  * Converts from Fahrenheit to Celcius 
  * and vice versa
  *
  */
  
#include <iostream>
#include <string>
using namespace std;

//Declare global variables
double dX;
int iWrongSelect = 0;
string sContinue = "Y";
string sCont;


string fContinue(){
    cout << ">Do you wish to use the converter again? Y|N \n>";
    cin >> sContinue; 
            
    if(sContinue == "y" || sContinue == "Y"){
        return sContinue;
    }
    else if(sContinue == "n" || sContinue =="N"){
        return sContinue;
    }
    else{
        while(iWrongSelect < 6){
            cout << ">This selection is not valid...  (Count " << ++iWrongSelect << " of 5)" << endl;
            cout << ">Make another selection? Y|N \n>";
            cin >> sContinue; 
                if(sContinue == "y" || sContinue == "Y"){
                    iWrongSelect = 0;
                    return sContinue;
                }    
                else if(sContinue == "n" || sContinue == "N"){
                    iWrongSelect = 0;
                    return sContinue;
                }
                else if(iWrongSelect >= 5){
                    return "Err";
                }
                else{
                    //keep looping... 
                }
        }
    }
}

void fToCelcius(float x){
    cout << x  << " Fahrenheit is equal to ";
    cout << (x - 32)* .5556 << "\370 Celcius\n"; 
    
}

void fToFahrenheit(float x){
    cout << x << " Celcius is equal to ";
    cout << x * 1.8 + 32 << "\370 Fahrenheit\n";
}

int main() {
    
    char cSelect;
    
    cout << "This program will convert Fahrenheit to Celcius and vice versa. Please start by making a selection below:\n\n";
    
    do{
        cout << ">Enter  F  to convert to Fahrenheit \t(from Celcius)\n";
        cout << ">Enter  C  to convert to Celcius \t(from Fahrenheit)\n";
        cout << ">Enter  E  to Exit \n";
    
        cin >> cSelect;
        
        switch(cSelect){
        case 'f':
        case 'F':
            cout << ">Please enter the temperature in Celcius\n>";
            cin >> dX;
            if (!cin){
                cout<<">Invalid entry.. A number was expected here...\n";
                cin.clear();
                cin.ignore();
                break;
            }
            fToFahrenheit(dX);
            sContinue = fContinue();
            break;
            
        case 'c':
        case 'C':
            cout << ">Please enter the temperature in Fahrenheit\n>";
            cin >> dX;
            if (!cin){
                cout<<">Invalid entry.. A number was expected here...\n";
                cin.clear();
                cin.ignore();
                break;
                }
            fToCelcius(dX);
            sContinue = fContinue();
            break;
            
        case 'e':
        case 'E':
            cout << ">Exit" << endl;
            cout << ">Thank you for using our temperature converter!";
            return 0;
            break;
            
        default :
            cout << ">Invalid selection, please try again. \n>";
            sContinue = fContinue();
            break;
        }
        }
    while (sContinue == "y" || sContinue == "Y");
    
    if(sContinue == "n" || sContinue == "N"){
        cout << ">Thank you for using our temperature converter!";
        return 0;
    }
    else {
        cout << ">It seems you are having issues with the selection. Please try again later.\n";
        cout << "Program Aborting to prevent further issues...";
        return 1;
    }
}
