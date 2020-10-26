#include <iostream>
#include <string>

using namespace std;

int a[50];
int a2x2[25][3];
int key[3][3];
int r,c;

void print_mat(int a[][3],int p, int q){
	for(int i=0;i<p;i++){
		for(int j=0;j<q;j++)
			cout<<a[i][j]<<"\t";
		cout<<endl;
	}
}

//Changed plain txt to number
void Txt_to_num(string str,int row){
	int itr=0;
	for (int i = 0; i < str.size(); i++){
    	a[i] = str[i]-97;
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<r;j++){
			if(itr == str.size()){
				a2x2[i][j] = 9999;
				// cout<<a2x2[i][j];
			}
			else{
				a2x2[i][j] = a[itr++];
				// cout<<a2x2[i][j];
			}
		}
	}
}

string num_to_txt(int a2x2[25][3],int n){
	string res="";
	for(int i=0;i<25;i++){
		for(int j=0;j<r;j++){
			res.push_back(a2x2[i][j]+97);
			n--;
			if(n==0){
				return res;
			}
		}
	}
	return res;
}

int findDet(int mat[3][3],int n)
{
	int det;
	if(n == 2)
	{
		det = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0] ;
	}
	else if (n == 3)
	{
		det = mat[0][0]*( mat[1][1]* mat[2][2] - mat[1][2] * mat[2][1])  - mat[0][1] * ( mat[1][0] * mat[2][2] - mat[2][0] *mat[1][2] ) + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
	}
	else det = 0 ; // invalid input
	cout<<"Det = "<<det<<endl;
	cout<<"Det = "<<det%26<<endl;
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
	int cofactor[3][3];
	if(order==2){
		cofactor[0][0] = key[1][1];
		cofactor[0][1] = -key[1][0];
		cofactor[1][0] = -key[0][1];
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
	cout<<"The cofactor is"<<endl;
	print_mat(cofactor,order,order);
	//transpose
	for (int i = 0; i < order; ++i)
      	for (int j = 0; j < order; ++j) {
        	adjoint[j][i] = cofactor[i][j];	
      	}
}

void multiply(int P[][3],int k[3][3],int n) 
{
	int zero,one;
	if(r==2){
		for(int i=0;i<n/2;i++){
			zero = P[i][0] * k[0][0] + P[i][1] * k[0][1];

			P[i][1] = P[i][0] * k[1][0] + P[i][1] * k[1][1];
			P[i][0] = zero;

			P[i][0] = P[i][0] % 26;
			P[i][1] = P[i][1] % 26;	
			for(int q=0;q<2;q++)
				while(P[i][q]<0)
					P[i][q]+=26;
		}
	}
	else{
		for(int i=0;i<n/2;i++){
			zero = P[i][0] * k[0][0] + P[i][1] * k[0][1] +P[i][2] * k[0][2];
			one = P[i][0] * k[1][0] + P[i][1] * k[1][1] +P[i][2] * k[1][2];
			P[i][2] = P[i][0] * k[2][0] + P[i][1] * k[2][1] +P[i][2] * k[2][2];
			
			P[i][0] = zero;
			P[i][1] = one;
			for(int q=0;q<3;q++)
				while(P[i][q]<0)
					P[i][q]+=26;
			P[i][0] = P[i][0] % 26;
			P[i][1] = P[i][1] % 26;	
			P[i][2] = P[i][2] % 26;
		}		
	}
}

void encryption(int a2x2[][3],int key[3][3],int n){
	multiply(a2x2,key,n);
	cout<<"Encrypted text:"<<num_to_txt(a2x2,n)<<endl;
}

void decryption(int a2x2[][3],int keyin[3][3], int n){
	multiply(a2x2,keyin,n);
	cout<<"Decrypted text:"<<num_to_txt(a2x2,n)<<endl;
}

int main(){
	int i,j,inverse;
	string p;
	cout<<"Enter plain text"<<endl;
	cin>>p;

	cout<<"Enter row and column of key matrix";
	cin>>r>>c;
	
	// int P[25][3];
	int n = p.length();
	int l = p.length();
	if(n%2 && r==2)
		n++;

	if(r==3)
		while(n%3)
			n++;
	int row = (p.length())/r;
	Txt_to_num(p,row);

	cout<<"Enter Key:"<<endl;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			cin>>key[i][j];

	verify_2x2(r,c);

	encryption(a2x2,key,l);

	//Decryption

	inverse=FindInverse(findDet(key,r));

	cout<<"The inverse is "<<inverse<<endl;
	int adjoint[3][3];
	find_adjoint(adjoint,r);

	printf("The Adjoint Matrix is:\n");
	print_mat(adjoint,r,r);

	for(i=0;i<r;i++)
		for(j=0;j<r;j++){
			adjoint[i][j] = (adjoint[i][j] * inverse) % 26;
		}

	cout<<"K^-1="<<endl;
	print_mat(adjoint,r,r);

	decryption(a2x2,adjoint,l);
}