#include<iostream>
#include<cstring>
using namespace std;
long long int memo_result[40][40];
long long int solve(int *braces,int i,int j,int N) {
	long long int result;
	if(i==N && j==0)
		return 1;
	if(i==N)
		return -1;
	if(memo_result[i][j]!=-1)
		return memo_result[i][j];

	if(braces[i]==1){
		long long int temp=solve(braces,i+1,j+1,N);
		result=temp<0?0:temp;

	}else{
		long long int score1,score2;
		score1=(j>0?solve(braces,i+1,j-1,N):0);
		score2=solve(braces,i+1,j+1,N);
		score1=score1<0?0:score1;
		score2=score2<0?0:score2;
		result=score1+score2;
	}
	memo_result[i][j]=result;
	return result;
}

int main(){
	int d;
	cin>>d;
	while(d--){
		int n,k;
		cin>>n>>k;
		int a[k],braces[2*n];
		memset(braces,0,sizeof(braces));
		memset(memo_result,-1,sizeof(memo_result));
		for(int i=0;i<k;i++){
			cin>>a[i];
			braces[a[i]-1]=1;
		}
		long long int result=solve(braces,0,0,2*n);
		cout<<result<<"\n";
	}
}