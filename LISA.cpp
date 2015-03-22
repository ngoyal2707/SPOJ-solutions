/*
 * LISA.cpp
 *
 *  Created on: Mar 22, 2015
 *      Author: ngoyal
 */

#include<iostream>
#include<cstring>
using namespace std;

long long unsigned int result_max[102][102];
long long unsigned int result_min[102][102];

void solve(char *exp,int len){
	for(int i=0;i<len;i=i+2){
		result_max[i][i]=exp[i]-'0';
		result_min[i][i]=exp[i]-'0';
	}
	for(int exp_len=2;exp_len<len;exp_len=exp_len+2){
		for(int i=0;i<len;i=i+2){
			unsigned long long int max=0,score=0,score1=0;
			unsigned long long int min=9223372036854775806ULL;
			int j=i+exp_len;
			for(int k=i;k<j;k=k+2){
				if(exp[k+1]=='*'){
					score=result_max[i][k]*result_max[k+2][j];
					score1=result_min[i][k]*result_min[k+2][j];
				}else if(exp[k+1]=='+'){
					score=result_max[i][k]+result_max[k+2][j];
					score1=result_min[i][k]+result_min[k+2][j];
				}
				if(score>max) max=score;
				if(score1<min) min=score1;
			}
			result_max[i][j]=max;
			result_min[i][j]=min;
		}
	}
}

int main(){
	int k;
	cin >> k;
	for(int i=0;i<k;i++){
		char exp[102];
		cin>> exp;
		solve(exp,strlen(exp));
		cout << result_max[0][strlen(exp)-1]<<"\t"<< result_min[0][strlen(exp)-1]<<"\n";
	}
}
