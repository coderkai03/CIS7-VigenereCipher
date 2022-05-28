/* 
 * File:   main.cpp
 * Author: Rian Corcino, Liliana Darch, and Joash Marcos.
 * Team name: STEMMER
 * Created on May 24, 2022, 4:00pm
 * Purpose: Project Encryption/Decryption
 */


//Execution begins here!

//System Libraries
#include<bits/stdc++.h> 
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<cstring>

//Header files
#include "ExtraFuncs.h"
#include "Encrypt.h"
#include "Decrypt.h"

using namespace std;  

//string separater (reference) -> 53 lines
const string border = "\n\n*****************************************************\n\n";

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
   
    //Declare variables here
    int choose;//Choose a problem   
    
    //Initialize variables here
    do{
        //Display the menu
        cout<<endl;
        cout<<"*********** PROJECT ENCRYPTION/DECRYPTION ***********"<<endl<<endl;
        cout<<"Press 1 - Encrypt a message"<<endl;
        cout<<"Press 2 - Decrypt a message"<<endl;
        cout<<"Press 3 - Credits"<<endl;
        cout<<"Press 4 - Exit the program"<<endl;
        cout<<endl;
        
        menuVal(choose, 1, 4);
        
        //Menu
        switch(choose){
            case 1:encrypt();break;
            case 2:decrypt();break;
            case 3:credits();break;
            default:cout<<"Exiting the Menu"<<endl;
        }
    }while(choose>=1 && choose<=3);

    return 0;
}