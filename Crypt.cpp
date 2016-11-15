/** Simple encryption program
  * 
  * Copyrights (c) 2016 - Frédéric Charette
  * https://github.com/rain79/CPP_Source
  *
  * I would not use this encryption to safeguard extremely sensitive data, 
  * but it would be ok to prevent users from tampering with simple files...
  */

#include <iostream>
using namespace std;

string SimpleCypher(string sKey, string sCrypto) {

    string sOut = sCrypto;
    
    for(int i = 0; i < sCrypto.size(); i++){
        sOut[i] = sCrypto[i] ^ sKey[i %(sizeof(sKey) + 1)* sizeof(sCrypto)];
    }
    
    return sOut;
}

string GetKey(){

    int iMinKeyLength = 12;
    string sKey;
    
    cout << "Please enter your encryption key:";

    cin >> sKey;
    
    while(sKey.size() < iMinKeyLength){
        cout << "\n\nThe minimum key length is: " << iMinKeyLength << ". Please enter your encryption key:";
        cin >> sKey;
        cout << endl;
    }
    return sKey;
}

int main() {
    
    string sEnc;
    string sDec;
    string sKey;
    sKey = GetKey();
    
    //The below are just examples, change the program to gather user input and encrypt or decrypt text...

    sEnc = SimpleCypher(sKey, "It's simple but it works. Lucky ### 777. Hello!");
    
    cout << "Encrypted: " << sEnc << endl;
    
    sDec = SimpleCypher(sKey, sEnc);
    
    cout << "Decrypted: " << sDec << endl << endl;
    
    sEnc = SimpleCypher(sKey, "Hello, Hello, Hello, Hello <-- The sequence returns different characters and thus is not easily cracked...");
    
    cout << "Encrypted: " << sEnc << endl;
    
    sDec = SimpleCypher(sKey, sEnc);
    
    cout << "Decrypted: " << sDec;
    
    return 0;
}
