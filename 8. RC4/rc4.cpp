#include <bits/stdc++.h>
using namespace std;

int main()
{
    int S[256], T[256], keyStream[256];
    string ptString, keyString, dtString = "";
    int pt[256], ct[256], dt[256];

    cout << "Enter message : "; cin >> ptString;
    cout << "Enter key     : "; cin >> keyString;
    int n = ptString.length();

    cout << "\nPlain text \t: " ;
    for(int i=0; i<n; i++)
    {
        pt[i] = ptString[i]; // converting char to its ASCII value
        cout << pt[i] << " ";
    }

    // Initialization
    for(int i=0; i<256; i++)
    {
        S[i] = i;
        T[i] = (int)keyString[i%keyString.length()]; // fill T with ASCII value of key T[256]=[keykeykeykey...]
    }

    // Initial permutation
    int j=0;
    for(int i=0; i<256; i++)
    {
        j = (j + S[i] + T[i]) % 256;
        swap(S[i], S[j]);
    }

    // Stream Generation
    cout << "\nKey Stream \t: ";
    j=0;
    for(int i=0; i<n; i++) // generate keystream of same length as plaintext
    {
        j = (j + S[i]) % 256;
        swap(S[i], S[j]);
        int t = (S[i] + S[j]) % 256;
        keyStream[i] = S[t];
        cout << keyStream[i] << " ";
    }

    // Encryption
    cout << "\nCipher Text \t: ";
    for(int i=0; i<n; i++)
    {
        ct[i] = pt[i] ^ keyStream[i]; // xor
        cout << ct[i] << " ";
    }

    // Decryption
    cout << "\nDecrypted text \t: " ;
    for(int i=0; i<n; i++)
    {
        dt[i] = ct[i] ^ keyStream[i];
        cout << dt[i] << " ";
        dtString += (char)dt[i]; // change ASCII value to char
    }
    cout << "\nDecrypted text \t: " << dtString << endl;
}