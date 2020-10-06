#include <iostream>
#include <string>

using namespace std;

int a[50];
int a2x2[25][25];
int key[10][10];

//Changed plain txt to number
void Txt_to_num(string str){
	for (int i = 0; i < str.size(); i++){
    	a[i] = str[i]-97;
	}
}

//Converted matrix a to ? * 2 form
void convert_two_mat(int s){
	int r,c;
	for(int i=0;i<s;i++){
		if((i+1)%2)
			r++;
		r=0;
		c=0;
		a2x2[r][c++]=a[i];
		// cout<<a2x2[r][c-1];
	}
	if(c==1){
		a2x2[r][c]=999;
		// cout<<a2x2[r][c];
	}
}
void verify_2x2(int r,int c){
	//Verify key is square matrix or not
	if(r!=c){
		cout<<"Not a square matrix";
		exit(0);
	}
	//Verify determinate is non-zero
	if(key[0][0]*key[1][1]-key[0][1]*key[1][0]==0){
		cout<<"Determinate is 0";
		exit(0);
	}
}

int main(){
	string p;
	int i,j,r,c;
	cout<<"Enter plain text"<<endl;
	cin>>p;
	
	Txt_to_num(p);

	// for(i=0;i<p.size();i++){
	// 	cout<<a[i];
	// }
	convert_two_mat(p.size());

	cout<<"Enter row and column of key matrix";
	cin>>r>>c;

	cout<<"Enter Key:"<<endl;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			cin>>key[r][c];

	verify_2x2(r,c);
}