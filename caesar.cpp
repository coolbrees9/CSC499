/*  Colin O'Neal
 *  Caesar Cipher
 *  CSC 499
 *  5/4/2018      */

#include <cstdlib>
#include <math.h>
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

void encrypt(string code, int key);
void decrypt(string code, int key);
int main(int argc, char* argv[])
{
      string code, action;
      int key;
      printf("Input a code/phrase: ");
      getline(cin, code);  //gets the user's code input
      printf("Do you want to encrypt or decrypt the code? (e or d): ");
      cin >> action;
      if(action == "e" || action == "E")  //User input is e
      {
            printf("Enter an integer to increment the code: ");
            cin >> key;
            encrypt(code, key);
      }
      else if(action == "d" || action == "D")  //User input is d
      {
            printf("Enter an integer to decrement the code: ");
            cin >> key;
            decrypt(code, key);
      }
      else  //User input is invalid
            printf("Invalid");
}
//Method to encrypt the user's code
void encrypt(string code, int key)
{
      string temp;
      for(int i = 0; i < code.length(); i++)
      {
            //Alphabetic character
            if(isalpha(code[i]))
            {
                  //Uppercase letter
                  if(isupper(code[i]))
                  {
                        temp += char(int(code[i] + key - 65) % 26 + 65);
                  }
                  //Lowercase letter
                  else
                  {
                        temp += char(int(code[i] + key - 97) % 26 + 97);
                  }
            }
            //Check for spaces
            else if(int(code[i]) == 32)
            {
                  temp += " ";
            }
      }
      cout << "Original code: " << code << endl;
      cout << "Encrypted code: " << temp << endl;
}
//Method to decrypt the user's code
void decrypt(string code, int key)
{
      string temp;
      for(int i = 0; i < code.length(); i++)
      {
            //Alphabetic character
            if(isalpha(code[i]))
            {
                  //Uppercase letter
                  if(isupper(code[i]))
                  {
                        temp += char(int(code[i] - key - 65) % 26 + 65);
                  }
                  //Lowercase letter
                  else
                  {
                        temp += char(int(code[i] - key - 97) % 26 + 97);
                  }
            }
            //Check for spaces
            else if(int(code[i]) == 32)
            {
                  temp += " ";
            }
      }
      cout << "Original code: " << code << endl;
      cout << "Decrypted code: " << temp << endl;
}
