#include<iostream>
#include<cstring>
using namespace std;
int main(){
	long long int result[10][2005],final_result[10][2005];

	memset(result,0,sizeof(result));
	memset(final_result,0,sizeof(final_result));

	// cout<<result[1][0]<<"\n";

	for(int i=1;i<2001;i++){
		result[0][i]=1;
		final_result[0][i]=(i>0?final_result[0][i-1]:0)+result[0][i];
		// cout<<final_result[0][i]<<"\n";
	}


	result[0][0]=0;
	final_result[0][0]=0;
	for(int i=1;i<10;i++){
		for(int j=1;j<2001;j++){
			result[i][j]=0;
			for(int k=0;2*k<=j;k++){
				result[i][j]+=result[i-1][k];
			}
			final_result[i][j]=(j>0?final_result[i][j-1]:0)+result[i][j];
		}
	}

	int d,caseNo=1;
	cin>>d;
	while(d--){
		int i,j;
		cin>>i>>j;
		cout<<"Data set "<<caseNo<<": "<<i<<" "<<j<<" "<<final_result[i-1][j]<<"\n";
		caseNo++;
	}
}