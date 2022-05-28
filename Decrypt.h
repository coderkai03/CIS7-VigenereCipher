//#include "ExtraFuncs.h"
#include <iostream>

using namespace std;

string DVigenere(string cipher, string key) {
    int pIdx = 0, kIdx = 0, cIdx = 0;
    string plain;
    bool lower;

    //scan each char of cipher and key
    do {
        //reset key index if at end
        if (key[kIdx] == NULL)
            kIdx = 0;

        //valid char
        if (cipher[pIdx] != ' ') {
            //Reverse Vigenere Cipher
            plain += (((cipher[cIdx] - key[kIdx]) + 26) % 26) + 'A';

            //increment key/plain indexs
            kIdx++;
            pIdx++;
        }
        else //skip spaces
            plain += ' ';

        //always increment cipher indx
        cIdx++;
    } while (cipher[pIdx] != NULL);

    return plain;
}

void decrypt(){    
    string text, key, cipher, dCipher;

    cout << "\n********************** DECRYPT **********************"<<endl<<endl;

    cout << "< Enter an encrypted word >"
        "\n- Must be alphabetical"
        "\n- Can contain spaces" 
        "\n- Case sensitive" << endl << endl;

    //input cipher
    cin.ignore();
    inputVal(cipher, true);
    
    cout << "\n< Enter a key word >"
        "\n- Must be alphabetical"
        "\n- Cannot contain spaces" 
        "\n- Case insensitive" << endl << endl;

    //input key
    inputVal(key, false);

    dCipher = cipher;
    
    //uppercase cipher and key
    transform(cipher.begin(), cipher.end(), cipher.begin(), ::toupper);
    transform(key.begin(), key.end(), key.begin(), ::toupper);

    //finalize data format
    text = DVigenere(cipher, key);
    syncCase(dCipher, text);
    printData(text, key, dCipher);
}

//Test en/decrypts
//CGOXCTWTAKIWPKM
//cgoxctwtakiwpkm