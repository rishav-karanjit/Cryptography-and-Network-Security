#include <bits/stdc++.h>
using namespace std;

char uniqtext[26]; // Global variable

//Step 1
string readPlainText()
{
	ifstream fin;
	string ptext;

	fin.open("plaintext.txt");
	fin >> ptext;
	fin.close();

	return ptext;
}

//Step 2
void addchar(char a[]){
	char x='a';
	for(int i=0;i<26;i++){
		a[i]=x;
		x++;
	}

}

//Step 3
void AddRandNum(int random[]){
	for(int i=0;i<26;i++){
		random[i]=i;
	}
}



int main()
{
	int i;
	char a[52];
	int random[26];

	srand(time(NULL)) ;
	//Step 1
	string plaintext = readPlainText() ;
	cout<<"Plain text = \t" << plaintext << endl;
	//Step 2
	addchar(a);
	//Step 3
	AddRandNum(random);



	//char* keyspace = genKeySpace(plaintext);
	//string key = keyspace[rand()%keyspace.size()];
 
	//cout<<"Unique chars = \t" << uniqtext <<endl;
	//cout<<"Chosen key = \t" << key <<endl;

	//string ciphertext = encrypt(uniqtext , key) ;
	//writecipherText(ciphertext) ; // write ciphertext to file
	//showFrequency(plaintext , ciphertext) ;
}
