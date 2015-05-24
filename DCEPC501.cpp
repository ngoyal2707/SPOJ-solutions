#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
long long int memo_result[100000];


long long int solve(long int *P,int i,int N){
	long long int result,score1=0,score2=0,score3=0;
	if(i>=N)
		return 0;
	if(memo_result[i]!=-1)
		return memo_result[i];
	if(i<N)
		score1=P[i]+solve(P,i+2,N);
	if(i<N-1)
		score2=P[i]+P[i+1]+solve(P,i+4,N);
	if(i<N-2)
		score3=P[i]+P[i+1]+P[i+2]+solve(P,i+6,N);

	// cout<<"i: "<<i<<"\t"<<score1<<"\t"<<score2<<"\t"<<score3<<"\t"<<"\n";

	result=max(score1,max(score2,score3));
	memo_result[i]=result;
	return result;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		long int N;
		scanf("%ld",&N);
		long int P[N];
		memset(memo_result,-1,sizeof(memo_result));
		for(long int i=0;i<N;i++){
			scanf("%ld",&P[i]);
		}
		long long int result=solve(P,0,N);
		printf("%lld\n",result);
	}	
}