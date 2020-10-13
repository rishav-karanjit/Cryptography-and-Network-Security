#include <iostream>
#include <string>

using namespace std;

int a[50];
int a2x2[25][25];
int key[3][3];
int r,c;

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

int findDet(int a[3][3],int n)
{
	int det;
	if(n == 2)
	{
		det = a[0][0] * a[1][1] - a[0][1] * a[1][0] ;
	}
	else if (n == 3)
	{
		det = a[0][0]*( a[1][1]* a[2][2] - a[1][2] * a[2][1])  - a[0][1] * ( a[1][0] * a[2][2] - a[2][0] * a[1][2] ) + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
	}

	else det = 0 ; // invalid input
	
	return(det % 26);
}

void verify_2x2(int r,int c){
	//Verify key is square matrix or not
	if(r!=c){
		cout<<"Not a square matrix";
		exit(0);
	}
	//Verify determinate is non-zero
	if(findDet(key,r)==0){
		cout<<"Determinate is 0";
		exit(0);
	}
}

int FindInverse(int r2,int r1=26){
	int x = r1;
	int q,r,t1=0,t2=1,t;
	while(r2!=0){
		q = r1 / r2;
		r = r1 - q * r2;
		t = t1 - q * t2;

		r1 = r2;
		r2 = r;

		t1 = t2;
		t2 = t;
	}
	if(r1 != 1){
		cout<<"Inverse does not exit. Reason: gcd != 1";
		exit(0);
	}
	else{
		if(t1<0){
			t1 += x; 
		}
		return t1;
	}
}

void SelectTempMat(int temp[3][3],int r,int c){
	int i,j,x=0,y=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(r==i || c==j)
				continue;
			temp[x][y] = key[i][j];
			y++;
			if(y==2){
				y=0;
				x++;
			}
		}
	}
}

void find_adjoint(int adjoint[3][3], int order){
	int cofactor[order][order];
	if(order==2){
		cofactor[0][0] = key[1][1];
		cofactor[0][1] = key[1][0];
		cofactor[1][0] = key[0][1];
		cofactor[1][1] = key[0][0];
	}
	else{
		int i,j,r=0,c=0,temp[3][3];
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				SelectTempMat(temp,i,j);
				cofactor[i][j] = findDet(temp,2);
				if(i%2){
					if(j%2==0){
						cofactor[i][j] = -cofactor[i][j];
					}
				}
				else
					if(j%2)
						cofactor[i][j] = -cofactor[i][j];
			}
		}

	}

	//transpose
	for (int i = 0; i < order; ++i)
      	for (int j = 0; j < order; ++j) {
        	adjoint[j][i] = cofactor[i][j];
      	}
}
int main(){
	string p;
	int i,j,inverse;
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
			cin>>key[i][j];

	verify_2x2(r,c);
	inverse=FindInverse(findDet(key,r));

	int adjoint[3][3];
	find_adjoint(adjoint,r);


}