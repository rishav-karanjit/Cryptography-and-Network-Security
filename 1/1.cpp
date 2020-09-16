#include <bits/stdc++.h>
using namespace std;

char uniqtext[26]; // Global variable

//Plaintext<-file
string readPlainText()
{
	ifstream fin;
	string ptext;

	fin.open("plaintext.txt");
	fin >> ptext;
	fin.close();

	return ptext;
}

//cipertext->file
void writecipher(char ctxt[]){
	ofstream fout;
	fout.open("ciphertext.txt");
	fout << ctxt;
	fout.close();	
}

//random=0-26 used to generate UNIQUE random number
void AddRandNum(int random[]){
	for(int i=0;i<26;i++){
		random[i]=i;
	}
}

//Random Number in range 0-25
int rand26(){
    return(rand() % 26); 
}

// 1.Find Rand Number
// 2.Find Rand Number is Unique
// 3.Change number to ascii value 0->97
void keyspaceGen(char alpha[],int random[]){
	int x,p=0;
	for(int i=0;i<26;i++){
		x=rand26();
		while(random[x]==-1) x=(x+1)%26;
		alpha[p++]=random[x]+97;
		random[x]=-1;
	}
}
// ch->alpha->index->+97->char
//returns index
int searchch(char ch, char alpha[]){
	int i=0;
	while(1){
		if(alpha[i]==ch)
			return i;
		i++;
	}
}

//1.+97->char
void encrypt(char ciphertext[],string plaintext, char alpha[]){
	int i=0;
	char ch;
	while(plaintext[i]){
		ch=plaintext[i];		
		ciphertext[i]= searchch(ch,alpha) + 97;
		i++;
	}
	ciphertext[i]='\0';
}

int main()
{
	int i=0,random[26];
	char alpha[52],ch,ciphertext[200];
	srand(time(NULL)) ;
	
	//Read txt from file
	string plaintext = readPlainText() ;
	cout<<"Plain text = \t" << plaintext << endl;

	//Generated Random Number
	AddRandNum(random);

	//Generated Key
	keyspaceGen(alpha,random);

	//Convert plaintext->cipertext
	encrypt(ciphertext,plaintext,alpha);
	cout<<"Cipher Text=\t"<<ciphertext<<endl<<endl;

	//Cipertext->File
	writecipher(ciphertext);
	cout<<"Cipher text written on ciphertext.txt";
}
