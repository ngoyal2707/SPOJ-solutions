/*
 * MBALL.cpp
 *
 *  Created on: Mar 28, 2015
 *      Author: ngoyal
 */

#include<iostream>
#include<cstring>
#include<ctime>


using namespace std;
#define MAX 100004

long long unsigned int result[MAX][5];


long long unsigned int solve_bottomUP(long int S, int m, int score_types[5]){
	for(int i=0;i<5;i++)
		result[0][i]=1;

	for(long int i=1;i<=S;i++){
		for(int j=0;j<5;j++){
			result[i][j]=0;
			if(j-1>=0)
				result[i][j]+=result[i][j-1];
			if(i-score_types[j]>=0)
				result[i][j]+=result[i-score_types[j]][j];
		}
	}
	return result[S][m];
}
int main(){
	short int N;
	cin>> N;
	int score_types[5]={2,3,6,7,8};
	solve_bottomUP(100001,4,score_types);
	while(N--){
		long int S;
		cin >> S;
		cout << result[S][4]<<"\n";

	}
}

