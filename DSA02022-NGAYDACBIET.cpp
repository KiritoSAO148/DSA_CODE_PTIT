#include <bits/stdc++.h>
using namespace std;

int B[10];

void in(){
	for (int i=1; i<=8; i++){
		cout << B[i];
		if (i==2 || i==4) cout << "/";
	}
	cout << endl;
}

bool check(){
	if (B[1]==0 && B[2]==0) return false;
	if (B[3]==2) return false;
	if (B[3]==0 && B[4]==0) return false;
	if (B[5]==0) return false;
	return true;
}

void Try(int i){
	for (int j=0; j<=1; j++){
		if (j==1) B[i]=2;
		else B[i]=0;
		if (i==8){
			if (check()){
				in();
			}
		}else Try(i+1);
	}
}

int main(){
	Try(1);
}
