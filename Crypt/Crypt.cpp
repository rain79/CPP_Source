/** Simple encryption program
  *
  * Copyrights (c) 2016 - Frédéric Charette
  * https://github.com/rain79/CPP_Source
  *
  * I would not use this encryption to safeguard extremely sensitive data,
  * but it would be ok to prevent users from tampering with simple files...
  */

#include <iostream>
#include <fstream>
using namespace std;

string SimpleCypher(string sKey, string sCrypto) {

	string sOut = sCrypto;

	for (int i = 0; i < sCrypto.size(); i++) {
		sOut[i] = sCrypto[i] ^ sKey[i % (sizeof(sKey) + 1) + (sCrypto.size() % 4)];
	}

	return sOut;
}

string GetKey() {

	int iMinKeyLength = 12;
	string sKey;

    cout << "Welcome to the Cypher Encrypt/Decrypt Program!" << endl;
    cout << "Your encryption key is required to continue." << endl;
    cout << "Please remember that your key is a minimum of " << iMinKeyLength << " characters." <<endl;
	cout << "Please enter your encryption key: ";

	cin >> sKey;

	while (sKey.size() < iMinKeyLength) {
		cout << "\n\nThe minimum key length is: " << iMinKeyLength << " and cannot contain white spaces. Please enter your encryption key:";
		cin >> sKey;
		cout << endl;
	}
	return sKey;
}

/*char cContinue(){
   //Continue or Quit - Or should I do an Invalid Selection and just keep the Continue in a While loop?
}*/

int main() {

    char cSelect;
	string sEnc;
	string sDec;
	string sKey;
	string sMsg;
	sKey = GetKey();
	cout << "First, you need to decide if you wish to (E)ncrypt or (D)ecrypt messages." << endl;
	cout << "Please make your selection now (E|D):";
	cin >> cSelect;
	cin.ignore();

	switch (cSelect) {
	case 'e':
	case 'E':
		cout << "Please enter the message you wish to have encrypted: ";
		getline(cin, sMsg);
		sEnc = SimpleCypher(sKey, sMsg);
		cout << "Encrypted: " << sEnc << endl;
		sDec = SimpleCypher(sKey, sEnc);
		cout << "Decrypted: " << sDec << endl << endl;
        sEnc = SimpleCypher(sKey, "Hello, Hello, Hello, Hello <-- The sequence returns different characters and thus is not easily cracked...");
        cout << "Encrypted: " << sEnc << endl;
        sDec = SimpleCypher(sKey, sEnc);
        cout << "Decrypted: " << sDec;

		break;

	case 'd':
	case 'D':
		cout << "Please enter the message you wish to have decrypted: ";
		cin >> sMsg;
		sDec = SimpleCypher(sKey, sMsg);
		cout << "Decrypted Message: " << sDec << endl;
		break;

	default:
		cout << "Invalid Selection. Please try again." << endl;
		break;
	}

	return 0;
}
