#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

long long int memo_result[10000][10][10];

long long int solve(long int **G, int x1,int x2,int y,int M,int N){
	long long int result=-1;

	if(y==N-1){
		if(x1==0 && x2==(M-1)){
			// cout<<"asdjskf";
			return (G[y][x1]+G[y][x2]-(x1==x2)*G[y][x1]);
		}
		else 
			return -1;
	}
	if(memo_result[y][x1][x2]!=0)
		return memo_result[y][x1][x2];
	for(int i=-1;i<2;i++){
		for(int j=-1;j<2;j++){
			long long int score=-1;
			int x1New=x1+i; 
			int x2New=x2+j;
			if(x1New>=0 && x1New<M && x2New>=0 && x2New<M)
				score=solve(G,x1New,x2New,y+1,M,N);
			if(score!=-1)
				result=max(result,score);
		}
	}
	if(result!=-1){
		result+=(G[y][x1]+G[y][x2]-(x1==x2)*G[y][x1]);
	}
	// cout<<"x1:"<<x1<<"\tx2:"<<x2<<"\ty:"<<y<<"\tresult:"<<result<<"\n";
	memo_result[y][x1][x2]=result;
	return result;
}
int main(){
	int N,M;
	cin>>N>>M;
	long int **G=new long int* [N];
	memset(memo_result,0,sizeof(memo_result));
	for(int i=0;i<N;i++)
		*(G+i)= new long int[M];
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			// scanf("%ld",&G[i][j]);
			cin>>G[i][j];
		}
	}
	long long int result=solve(G,0,M-1,0,M,N);
	cout<<result<<"\n";
}