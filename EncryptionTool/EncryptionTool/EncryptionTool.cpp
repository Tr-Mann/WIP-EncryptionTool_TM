//===========================================================================================================================
// Author: Tristan Mann
// Date: 10/17/2024
// Desc: This is a tool which takes an input message and returns an encrypted version using a variety of encryption methods.
//===========================================================================================================================

#include <iostream>
#include <string>
#include <random>
using namespace std;


int mainMenu();
int encryptionMenu();
int decryptionMenu();
string caesarCipher(string);
void caesarDecrypt(string);
string vignereCipher();
void decryptVignere(string);
int main()
{
    bool isRunning = true;
    int selector;
    while (isRunning)
    {
        selector = mainMenu();

        if (selector == 1)
        {
            //Encryption tool
            selector = encryptionMenu();
            if (selector == 1)
            {
                system("CLS");
                string message;
                cout << "Enter Message to encrypt using Caesar Cipher\n";
                getline(cin, message);
                caesarCipher(message);

            }
            else if (selector == 2)
            {
                vignereCipher();
            }
        }
        else if (selector == 2)
        {
            selector = decryptionMenu();
            if (selector == 1)
            {
                system("CLS");
                string message;
                cout << "Enter Caesar Ciphered message to brute force:\n";
                getline(cin, message);
                caesarDecrypt(message);
            }
            else if (selector == 2)
            {
                system("CLS");
                string message;
                decryptVignere(message);
            }
            
        }
        else
        {
            isRunning = false;
            break;
        }
    }
    
}

//Display main menu and get int for option
int mainMenu()
{
    system("CLS");
    string input;
    int num;
    //Display menu
    cout << "Encryption tool: \n=================\n1. Encrypt\n2. Decrypt\n0. Quit\n";
    //Get oiginal input
    getline(cin, input);
    num = stoi(input);
    //Validate input comparing as string so inputing character doesn't break program only gets marked as invalid
    while (num < 0 && num > 2)
    {
        cout << "Invalid input try again: ";
        getline(cin, input);
    }
    //After validating return the string converted to integer
    return stoi(input);
}

int encryptionMenu()
{
    system("CLS");
    string input;
    cout << "Encryption tool: \n=================\n1. Caesar Cipher\n2. Vignere Cipher\n0. Back\n";

    getline(cin, input);
    while (input != "0" && input != "2" && input != "1")
    {
        cout << "Invalid input try again: ";
        getline(cin, input);
    }
    return stoi(input);
}

string caesarCipher(string msg)
{
    string input;
    string emsg = "";
    srand(time(NULL));
    int random = rand() % (26 - 5) + 5;

    for (int i = 0; i < msg.length(); i++)
    {
        emsg += msg[i] + random;
    }
    cout << emsg;
    cout << "\nType to continue: ";
    getline(cin, input);
    return emsg;
}

int decryptionMenu()
{
    system("CLS");
    string input;
    cout << "Decryption tool: \n=================\n1. Caesar Cipher Brute force\n2. Vignere Cipher Key decryption\n0. Back\n";

    getline(cin, input);
    while (input != "0" && input != "2" && input != "1")
    {
        cout << "Invalid input try again: ";
        getline(cin, input);
    }
    return stoi(input);
}

void caesarDecrypt(string msg)
{
    int shiftVal = 0;
    string input;
    for (shiftVal = 0; shiftVal <= 26; shiftVal++)
    {
        string decrypt = msg;
        for (int i = 0; i < msg.length(); i++)
        {
            decrypt[i] -= shiftVal;
        }
        cout << endl << "=====================================================================================\n" << decrypt 
            << endl << "=====================================================================================\n" << endl;
    
    }
    cout << "\nType to continue: ";
    getline(cin, input);
}

//The Vignere Cipher works by giving a key phrase which is then used to encrypt a message based on a vignere table
string vignereCipher()
{
    string key = "";
    string input;
    string msg = "";
    string usingkey = "";
    int counter = 0;
    cout << "Input message to be encrypted: ";
    getline(cin, msg);

    cout << endl << "Input the key to encrypt the message." << endl;
    getline(cin, key);

    //Make the key wrap to the full length of the message
    if (key.length() > msg.length())
    {
        for (int i = 0; i < msg.length(); i++)
        {
            usingkey += key[i];
        }
    }
    else
    {
        for (int i = 0; i < msg.length(); i++)
        {
            if (counter == key.length())
            {
                counter = 0;
                usingkey += key[counter];
            }
            else
            {
                usingkey += key[counter];
                counter++;
            }
        }
    }

    //We now have the key which will be used to encrypt the message
    
    //Now convert the key to a shift value 
    //Make all letters uppercase
    for (int i = 0; i < usingkey.length(); i++)
    {
       usingkey[i] = toupper(usingkey[i]);
       usingkey[i] -= 65;
    }

    //converting to the int values they will be stored as a string still
    for (int i = 0; i < msg.length(); i++)
    {
        msg[i] += usingkey[i];
        
    }
    //This now stores our encrypted message
    cout << msg << endl;
    cout << "Message Successfully encrypted\nType to continue: ";
    getline(cin, input);
    return msg;

}



void decryptVignere(string msg)
{
    string key;
    string usingkey = "";
    int counter = 0;

    cout << "Input message to be decrypted: ";
    getline(cin, msg);

    cout << endl << "Input the key to decrypt the message." << endl;
    getline(cin, key);
    if (key.length() > msg.length())
    {
        for (int i = 0; i < msg.length(); i++)
        {
            usingkey += key[i];
        }
    }
    else
    {
        for (int i = 0; i < msg.length(); i++)
        {
            if (counter == key.length())
            {
                counter = 0;
                usingkey += key[counter];
            }
            else
            {
                usingkey += key[counter];
                counter++;
            }
        }
    }
    for (int i = 0; i < usingkey.length(); i++)
    {
        usingkey[i] = toupper(usingkey[i]);
        usingkey[i] -= 65;
    }
    for (int i = 0; i < msg.length(); i++)
    {
        msg[i] -= usingkey[i];
    }
    cout << msg << endl;
    cout << endl << "Message successfully decrypted." << endl;
    getline(cin, key);
}