/*
 * MIXTURES.cpp
 *
 *  Created on: Apr 16, 2015
 *      Author: ngoyal
 */

#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

long int result[101][101];
long int smoke[101][101];
long int solve(long int i,long int j,long int *a){
	if(result[i][j]!=-1){
		return result[i][j];
	}
	if(i==j)
		return a[i];

	long int min =100000001;
	long int minValue=0;

	for(long int k=i;k<j;k++){
		long int score1=solve(i,k,a);
		long int score2=solve(k+1,j,a);
		long int score=smoke[i][k]+smoke[k+1][j]+score1*score2;
		if(score<min){
			min=score;
			minValue=(score1+score2)%100;
		}
	}
	result[i][j]=minValue;
	smoke[i][j]=min;
	return result[i][j];
}
int main(){
	long int N;
	while(scanf("%ld",&N)!=EOF){
		long int a[100];
		for(long int i=0;i<N;i++){
			cin>>a[i];
		}
		memset(result,-1,sizeof(result));
		solve(0,N-1,a);
		long int result=smoke[0][N-1];
		cout<<result<<"\n";
	}
}

