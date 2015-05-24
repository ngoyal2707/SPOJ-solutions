#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int memo_result[1000][1000];

int solve(int *a, int i,int K){
	if(K<=0){
		return 0;
	}
	if(i<0){
		return 0;
	}
	if(memo_result[i][K]!=-1)
		return memo_result[i][K];
	int score1=0,score2=0,result=0;
	
	if(K>=a[i]){
		score1=solve(a,i-2,K-a[i]);
		score1=score1+a[i];
	}

	score2=solve(a,i-1,K);
	result=max(score1,score2);
	memo_result[i][K]=result<0?0:result;
	return memo_result[i][K];
}

int main(){
	int T;
	cin>>T;
	int caseNo=1;
	while(T--){
		int N,K;
		scanf("%d%d",&N,&K);
		int a[N];
		memset(memo_result,-1,sizeof(memo_result));
		for(int i=0;i<N;i++){
			scanf("%d",&a[i]);
		}
		int result=solve(a,N-1,K);
		cout<<"Scenario #"<<caseNo<<": "<<result<<"\n";
		caseNo++;
	}
}