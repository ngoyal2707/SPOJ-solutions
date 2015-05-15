#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;
long long int memo_result[55][55];

long long int solve(int N,int diff,int K){
	if(K==0){
		if(diff==0)
			return 1;
		return 0;
	}
	if(memo_result[diff][K]!=-1){
		return memo_result[diff][K];
	}
	long long int result=solve(N,(diff-1+N)%N,K-1)+solve(N,(diff+1)%N,K-1);
	memo_result[diff][K]=result;
	return result;
}
int main(){
	int N,K;
	while(cin>>N && N!=-1 && cin>>K && K!=-1){
		int A,B;
		cin>>A>>B;
		for(int i=0;i<=55;i++){
			for(int j=0;j<=55;j++){
				memo_result[i][j]=-1;
			}
		}
		long long int result=solve(N,(int)abs((double)(A-B)),K);
		cout<<result<<"\n";
	}
}