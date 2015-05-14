#include<iostream>
using namespace std;
int main(){
	int T;
	cin>>T;

	long int result[105][105][2];

	result[0][0][0]=0;
	result[0][0][1]=0;

	result[1][0][0]=1;
	result[1][0][1]=1;

	result[1][1][0]=0;
	result[1][1][1]=0;

	for(int i=2;i<105;i++){
		result[i][0][0]=result[i-1][0][0]+result[i-1][0][1];
		result[i][0][1]=result[i-1][0][0];
	}

	for(int i=2;i<105;i++){
		for(int j=1;j<i;j++){
			result[i][j][0]=result[i-1][j][0]+result[i-1][j][1];
			result[i][j][1]=result[i-1][j][0]+result[i-1][j-1][1];
		}
	}

	while(T--){
		int d_no,n,k;
		cin>>d_no;
		cin>>n;
		cin>>k;
		cout<<d_no<<" "<<(result[n][k][0]+result[n][k][1])<<"\n";
	}
}