#include<iostream>
#include<cstring>
#define MODULO 761238923

using namespace std;
int main(){
	int N;
	long long int result[101][101],final_result[101];
	memset(result,0,sizeof(result));
	memset(final_result,0,sizeof(final_result));

	for(int i=0;i<=100;i++){
		result[i][0]=1;
	}
	// result[0][0]=0;
	for(int i=1;i<=100;i++){
		for(int j=1;j<=i;j++){
			for(int k=0;k<=j;k++){
				result[i][j]=(result[i][j]+result[i-1][k])%MODULO;
			}
			// if(i==j)
			// 	cout<<"i: "<<i<<"\t j: "<<j<<"\tresult: "<<result[i][j]<<"\n";
			final_result[i]+=result[i][j];
		}
		// cout<<"i: "<<i<<"\t result: "<<final_result[i]<<"\n";
	}

	while(cin>>N && N){
		cout<<result[N][N]<<"\n";
	}
}