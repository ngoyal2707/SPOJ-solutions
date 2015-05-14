#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;
long int memo_result[2005][2005];

long int edit_dist(char * str1,char *str2,int i,int j,int K){
	if(i==-1 && j==-1)
		return 0;
	if(i==-1)
		return K*(j+1);
	if(j==-1)
		return K*(i+1); 

	long int result;
	if(memo_result[i][j]!=0)
		result=memo_result[i][j];
	else{
		long int diff=str1[i]-str2[j];
		diff=diff<0?-diff:diff;
		result=min(diff+edit_dist(str1,str2,i-1,j-1,K),K+min(edit_dist(str1,str2,i-1,j,K),edit_dist(str1,str2,i,j-1,K)));
	}
	memo_result[i][j]=result;
	return result;
}

int main(){
	char str1[2005],str2[2005];
	int K;
	cin>>str1;
	cin>>str2;
	cin>>K;
	memset(memo_result,0,sizeof(memo_result));
	long int result=edit_dist(str1,str2,strlen(str1)-1,strlen(str2)-1,K);
	cout<<result;
}