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

void writecipher(char ctxt[]){
	ofstream fout;
	fout.open("ciphertext.txt");
	fout << ctxt;
	fout.close();	
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
	int i=0;
	char alpha[52];
	int random[26];
	char ch;
	srand(time(NULL)) ;
	char ciphertext[200];
	//Step 1
	string plaintext = readPlainText() ;
	cout<<"Plain text = \t" << plaintext << endl;

	//Step 2
	// addchar(alpha);
	//Step 3
	AddRandNum(random);
	keyspaceGen(alpha,random);
	encrypt(ciphertext,plaintext,alpha);
	cout<<"Cipher Text=\t"<<ciphertext<<endl<<endl;

	writecipher(ciphertext);

	cout<<"Cipher text written on ciphertext.txt";
}
