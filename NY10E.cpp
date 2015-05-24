#include<iostream>
#include<cstring>

using namespace std;
int main(){
	int P;
	cin>>P;

	long long int result[64][10],final_result[64];
	memset(result,0,sizeof(result));
	final_result[0]=0;
	for(int i=0;i<10;i++){
		result[0][i]=1;
		final_result[0]+=result[0][i];
	}
	for(int i=1;i<64;i++){
		final_result[i]=0;
		for(int j=0;j<10;j++){
			result[i][j]=0;
			for(int k=j;k<10;k++){
				result[i][j]+=result[i-1][k];
			}
			final_result[i]+=result[i][j];
		}
		// cout<<final_result[i]<<"\n";
	}
	while(P--){
		int N,caseN;
		cin>>caseN;
		cin>>N;
		cout<<caseN<<" "<<final_result[N-1]<<"\n";
	}

}