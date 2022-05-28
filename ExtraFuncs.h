#include <iomanip>
#include <iostream>

using namespace std;

void credits(){
    cout<<"\n******************** END CREDITS ********************"<<endl<<endl;
    cout<<"The Program Encryption/Decryption was created by: "<<endl; 
    cout<<"Rian Corcino, Liliana Darch, and Joash Marcos."<<endl;
    cout<<"Course CIS 7 "<<endl;
    cout<<"Spring 2022"<<endl;
    cout<<"Professor Dr. Kasey Nguyen"<<endl;
}

void printData(string plain, string key, string cipher) {
    const int sw1 = 20;
    cout << "\n******************** CIPHER DATA ********************" << endl << endl;
    cout << setw(sw1) << left << "Plaintext: " << plain << endl;
    cout << setw(sw1) << left << "Key: " << key << endl;
    cout << setw(sw1) << left << "Cipher: " << cipher << endl;
}

void syncCase(string plain, string &cipher) {
    int i = 0;
    
    do {
        if (islower(plain[i]))
            cipher[i] = tolower(cipher[i]);
        
        i++;
    } while (plain[i] != NULL);
}

void menuVal(int &input, int min, int max) {
    bool invalid;
    
    do {
        //menu input
        cout << "Input: ";
        cin >> input;

        //input validity
        invalid = input < min || input > max;

        if (invalid) {
            cout << "Invalid input. Please try again." << endl << endl;
        }
    } while (invalid);
}

void inputVal(string &input, bool plain) {
    bool invalid = true;
    int i = 0;

    //cin.ignore();
    do {
        //Input a plain/cipher text
        cout << "Input: ";
        getline(cin, input);
        
        do { //check each char
            if (plain) {
                if (!(isalpha(input[i]) || input[i] == ' ')) { //valid plain char
                    cout << "Invalid input. Please try again." << endl << endl;
                    break;
                }
            }
            else {
                if (!isalpha(input[i])) { //valid cipher char
                    cout << "Invalid input. Please try again." << endl << endl;
                    break;
                }
            }

            i++; //increment through string
            
            //end of string
            if (input[i] == NULL) {
                invalid = false;
            }            
        } while(input[i] != NULL);
        i = 0; //reset i
    } while(invalid);
}