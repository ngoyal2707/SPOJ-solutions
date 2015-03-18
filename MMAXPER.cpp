/*
 * MMAXPER.cpp
 *
 *  Created on: Mar 17, 2015
 *      Author: ngoyal
 */

#include<iostream>
#define MAX 1005

using namespace std;
int abs(int n){
	return n>0?n:-n;
}

void solve(int n, int *a,int *b,int result[MAX][2]){
	if (result[n][0]!=-1 && result[n][1]!=-1){
//		return max(result[n][0],result[n][1]);
		return;
	}
	if(n==0){
		result[0][0]=a[0];
		result[0][1]=b[0];
	}else{
	solve(n-1,a,b,result);
	result[n][0]=a[n]+max(result[n-1][0]+ abs(b[n]-b[n-1]),result[n-1][1]+abs(b[n]-a[n-1]));
	result[n][1]=b[n]+max(result[n-1][0]+ abs(a[n]-b[n-1]),result[n-1][1]+abs(a[n]-a[n-1]));
	}
//	cout<< result[n][0]<<"\t";
//	cout<< result[n][1]<<"\n";

}

int main(){
	int n,a[MAX],b[MAX],result[MAX][2];
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i]>>b[i];
		result[i][0]=-1;
		result[i][1]=-1;
	}

	solve(n-1,a,b,result);
	int res=max(result[n-1][0],result[n-1][1]);
	cout << res;
	return 0;
}
