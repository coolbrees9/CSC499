/*  Colin O'Neal
 *  RSA Algorithm
 *  CSC 499
 *  5/4/2018      */

//This program will run the RSA Encryption Algorithm
//based on what the user inputs as the message and the 
//two public keys
#include <cstdlib>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

long int prime(long int num);
long int gcd(long int x, long int y);
void encrypt(long int e[], long int en[100], long int temp[100], long int m[], char msg[], long int n);
void decrypt(long int d[], long int en[100], long int temp[100], long int m[], long int n);
int main()
{
      int i, j, k;
      long int n, p, q, r, prflag, e[100], d[100], m[100], en[100], temp[100];
      //Array to hold the input message
      char msg[100];      
      //Message to be encrypted
      printf("Input a message: \n");
      fflush(stdin);
      cin.getline(msg, 100);
      
      printf("Input first and second prime numbers greater than 7, must be different numbers(Use a space to seperate them): \n");
      cin >> p >> q;
      //Check if both numbers inputted are prime and are different
      prflag = prime(p);
      if(prflag == 0 || p < 7)
      {
            cout << "Not a prime number or is less than 7\n";
            exit(1);
      }
      prflag = prime(q);
      if(prflag == 0 || p == q || q < 7)
      {
            cout << "Not a prime number and must be different numbers or is less than 7\n";
            exit(1);
      }
      //Sets m equal to msg and goes until end of msg
      for(i = 0; msg[i] != '\0'; i++)
            m[i] = msg[i];
      n = p * q;
      r = (p - 1) * (q - 1);
      k = 0;
      for(i = 2; i < r; i++)
      {
            if(r % i == 0)
                  continue;
            prflag = prime(i);
            if(prflag == 1 && i != p && i != q)
            {
                  e[k] = i;
                  prflag = gcd(e[k], r);
                  if(prflag > 0)
                  {
                        d[k] = prflag;
                        k++;
                  }
                  if(k == 99)
                        break;
            }
      }
      encrypt(e, en, temp, m, msg, n);
      decrypt(d, en, temp, m, n);
      return 0;
}

//Checks if number is prime
long int prime(long int num)
{
      long int i, j;
      j = sqrt(num);
      for(i = 2; i <= j; i++)
      {
            if(num % i == 0)
                  return 0;
      }
      return 1;
}
//Returns greatest common divisor of x and y
long int gcd(long int x, long int y)
{
      long int temp = 1;
      while(1)
      {
          temp = temp + y;
          if(temp % x == 0)
              return(temp / x);
      }
}
//Method to encrypt the message
void encrypt(long int e[], long int en[100], long int temp[100], long int m[], char msg[], long int n)
{
      long int pt, ct, i, j, k, length;
      long int key = e[0];
      i = 0;
      length = strlen(msg);
      while (i != length)
      {
          pt = m[i];
          pt = pt - 96;
          k = 1;
          for(j = 0; j < key; j++)
          {
              k = k * pt;
              k = k % n;
          }
          temp[i] = k;
          ct = k + 96;
          en[i] = ct;
          i++;
      }
      en[i] = -1;
      cout << "Here is the encrypted message: " << endl;
      for(i = 0; en[i] != -1; i++)
          printf("%c", en[i]);
      cout << endl;
}
//Method to decrypt the encrypted message
void decrypt(long int d[], long int en[100], long int temp[100], long int m[], long int n)
{
      long int pt, ct, i, j, k;
      long int key = d[0];
      i = 0;
      while(en[i] != -1)
      {
          ct = temp[i];
          k = 1;
          for(j = 0; j < key; j++)
          {
              k = (k * ct) % n;
          }
          pt = k + 96;
          m[i] = pt;
          i++;
      }
      m[i] = -1;
      cout << "Here is the Original message: " << endl;
      for(i = 0; m[i] != -1; i++)
          printf("%c", m[i]);
      cout << endl;
}
