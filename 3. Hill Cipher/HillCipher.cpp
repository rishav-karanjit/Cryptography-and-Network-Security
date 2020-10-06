#include <iostream>
#include <string>

using namespace std;

int a[50];
int a2x2[25][25];

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

int main(){
	string p;
	int i;
	cout<<"Enter plain text";
	cin>>p;
	
	Txt_to_num(p);

	// for(i=0;i<p.size();i++){
	// 	cout<<a[i];
	// }
	convert_two_mat(p.size());
}