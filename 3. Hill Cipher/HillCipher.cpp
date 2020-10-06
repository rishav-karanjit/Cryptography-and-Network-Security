#include <iostream>
#include <string>

using namespace std;

int a[50];
void Txt_to_num(string str){
	for (int i = 0; i < str.size(); i++){
    	a[i] = str[i]-97;
	}
}

int main(){
	string p;
	int i;
	cout<<"Enter plain text";
	cin>>p;
	
	Txt_to_num(p);

	for(i=0;i<p.size();i++){
		cout<<a[i];
	}
}