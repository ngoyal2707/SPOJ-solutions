#include<iostream>
#include<cstring>

using namespace std;
long int memo_result[1000][1000];

long int solve(long int *	list1, int i,int j){

	long int score1,score2;
	
	if(memo_result[i][j]!=-1)
		return memo_result[i][j];

	if(j-i==1)
		return (list1[i]>list1[j]?(list1[i]-list1[j]):(list1[j]-list1[i]));

	if(list1[i+1]>=list1[j])
		score1=list1[i]-list1[i+1]+solve(list1,i+2,j);
	else
		score1=list1[i]-list1[j]+solve(list1,i+1,j-1);

	if(list1[i]>=list1[j-1])
		score2=list1[j]-list1[i]+solve(list1,i+1,j-1);
	else
		score2=list1[j]-list1[j-1]+solve(list1,i,j-2);
	long int result=max(score1,score2);
	memo_result[i][j]=result;
	return result;
}
int main(){
	int N;
	int case_no=1;
	while(cin>>N && N){
		long int list1[1004];
		for(int i=0;i<N;i++){
			cin>>list1[i];
		}
		memset(memo_result,-1,sizeof(memo_result));
		long int result=solve(list1,0,N-1);
		cout<<"In game "<<case_no<<", the greedy strategy might lose by as many as "<<result<<" points."<<"\n";
		case_no++;
	}
}