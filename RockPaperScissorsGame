/** Console Rock Paper Scissors game (v.: 3.2)
  * @authr: Frédéric Charette (c) 2016
  * https://github.com/rain79/CPP_Source
  *
  * Play Rock/Paper/Scissors on the console - 1 or 2 players
  * 1 Player games play against computer (Random outcome)
  */
  
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int GetNoOfPlayers(){
    int iNoOfPlayer;
    
    //Program Header
    cout << "Welcome to Console \"Rock Paper Scissors\"!";    
    cout << "\nHow many people are playing?\n";
    cout << "\tSelect (1|2):" << endl;
    cin >> iNoOfPlayer;
    while (!cin){
        cout << "Invalid Entry; \nPlease enter a number:";
        cin.clear();
        cin.ignore();
        cin >> iNoOfPlayer;
        cout << endl;
        if(!cin){
           //Still not a number 
        }
        else{
            break;
        }
    }
    if (iNoOfPlayer <= 1){
        return iNoOfPlayer;
    } else {
        return 2;
    }
}

bool PlayAgain(){
    string sPlayAgain = "x";
    char cYesNo;
    
    while (sPlayAgain != "Y" || "N"){
        cout << "Do you want to keep playing?\n";
        cout << "Select (Y|N):";
        cin >> cYesNo;
        cout << endl;
        sPlayAgain = toupper(cYesNo);
        
        if(sPlayAgain == "Y"){
            return true;
            break;
        }else if(sPlayAgain == "N"){
            cout << "Thank you for playing. Hopefully we will see you again soon!\n";
            return false;
            break;
        }else{
             cout << "Invalid Selection...\n";
        }
    }
}
string ValidateSelection(string sGetSel, int iPlayerID){
    char cSelection;
    while (sGetSel != "P" || "R" || "S") {
       if (sGetSel == "P"){
           break;
       }else if (sGetSel == "R"){
           break;  
       }else if (sGetSel == "S"){
           break;
       }else { 
           cout << "Player " << iPlayerID << ":\n\tYour selection " << sGetSel << " is not valid" << endl;
           cout << "Please make another selection:";
           cin >> cSelection;
           cout << endl;
           sGetSel = toupper(cSelection);
        }
    }
    return sGetSel;
}

string CompSelect(){
    int iRandomize;
    iRandomize = rand();
    srand(iRandomize);
    iRandomize = rand() % 3;
    iRandomize++;
    if (iRandomize == 1){
        return "R"; 
    }else if(iRandomize == 2){
        return "P";
    }else if(iRandomize == 3){
        return "S";
    }else{
        return "E"; 
    } 
}

void getwinner(string sPl1, string sPl2){

    //Declare function variable
    string P="Paper";
    string R="Rock";
    string S="Scissors";

    // Check the different options and determine winner...
    if (sPl1 == "P"){
        cout << "Player 1 acquires " << P;
        if (sPl2 == "R"){
            cout << "\nPlayer 2 acquires " << R << "\nPlayer 1 wins!";
        }
        else if(sPl2 == "S"){
            cout << "\nPlayer 2 acquires " << S << "\nPlayer 2 wins!";
        }
        else if(sPl2 == "P"){
        cout << "\nPlayer 2 acquires " << P << "\nIt's a tie!";
        }
    } else if (sPl1 == "R"){
        cout << "Player 1 acquires " << R;
        if (sPl2 == "P"){
            cout << "\nPlayer 2 acquires " << P << "\nPlayer 2 wins!";
        }
        else if (sPl2 == "S"){
            cout << "\nPlayer 2 acquires " << S << "\nPlayer 1 wins!";
        }
        else if (sPl2 == "R"){
            cout << "\nPlayer 2 acquires " << R << "\nIt's a tie!";
        }
    } else if (sPl1 == "S"){
        cout << "Player 1 acquires " << S;
        if (sPl2 == "P"){
            cout << "\nPlayer 2 acquires " << P << "\nPlayer 1 wins!";
        }
        else if (sPl2 == "R"){
            cout << "\nPlayer 2 acquires " << R << "\nPlayer 2 wins!";
        }
        else if (sPl2 == "S"){
            cout << "\nPlayer 2 acquires " << S << "\nIt's a tie!";
        }
    } else {
        cout << "OMG! A flow of lava has destroyed the game!?! \nActually, something went wrong. Please try again...";
    }
    cout << endl;    
}

int main() {

    //Declare program variable
    bool bKeepPlaying;
    char cP1;
    char cP2;
    int iNoOfPlayers;
    int iRandomize;
    string sPSel1; //Player 1 Selection
    string sPSel2; //Player 2 Selection
    
    do{
        iNoOfPlayers = GetNoOfPlayers();
        if (iNoOfPlayers < 1){
             cout << "When no one plays; no one wins...";
             return 1;
        }
        
        cout << "Type R for Rock\nType P for Paper\nType S for Scissors\n";
        
        //Player 1 selection
        cout << "Player 1 Choose your Weapon\n";
        cin >> cP1;
        sPSel1 = toupper(cP1);
        sPSel1 = ValidateSelection(sPSel1, 1);
        
        if (iNoOfPlayers >= 2) {
            //Player 2 Selection
            cout << "Player 2 Choose your Weapon\n";
            cin >> cP2;
            sPSel2 = toupper(cP2);
            sPSel2 = ValidateSelection(sPSel2, 2);
        }else{
         cout << "Computer will be playing as Player 2!\n";
        
    
         sPSel2 = CompSelect();   
        }
        
        cout << "=-= Let the game begin =-=" << endl;
        getwinner(sPSel1, sPSel2);
        
        bKeepPlaying = PlayAgain();
        if (bKeepPlaying == false){
            break;
            }
                
    } while (bKeepPlaying = true);
    
    
    return 0;
    
}
