//#include "ExtraFuncs.h"
#include <iostream>

using namespace std;

string EVigenere(string plain, string key) {
    int pIdx = 0, kIdx = 0, cIdx = 0;
    string cipher;
    bool lower;

    //scan each char of plain and key
    do {
        //reset key index if at end
        if (key[kIdx] == NULL)
            kIdx = 0;

        //valid char
        if (plain[pIdx] != ' ') {
            //Vigenere Cipher
            cipher += ((plain[pIdx] + key[kIdx]) % 26) + 'A';

            //increment key/cipher indexs
            kIdx++;
            cIdx++;
        }
        else //skip spaces
            cipher += ' ';

        //always increment cipher indx
        pIdx++;
    } while (plain[pIdx] != NULL);
    
    return cipher;
}

void encrypt(){    
    string text, dText, key, cipher;

    cout << "\n********************** ENCRYPT **********************"<<endl<<endl;

    cout << "< Enter a plaintext word >"
        "\n- Must be alphabetical"
        "\n- Can contain spaces" 
        "\n- Case sensitive" << endl << endl;

    //input text
    cin.ignore();
    inputVal(text, true);
    
    cout << "\n< Enter a key word >"
        "\n- Must be alphabetical"
        "\n- Cannot contain spaces" 
        "\n- Case insensitive" << endl << endl;

    //input key
    inputVal(key, false);

    dText = text;
    
    //uppercase text and key
    transform(text.begin(), text.end(), text.begin(), ::toupper);
    transform(key.begin(), key.end(), key.begin(), ::toupper);

    //finalize data format
    cipher = EVigenere(text, key);
    syncCase(dText, cipher);
    printData(dText, key, cipher);
}