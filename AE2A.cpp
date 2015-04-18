/*
 * AE2A.cpp
 *
 *  Created on: Apr 18, 2015
 *      Author: ngoyal
 */

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
double num[571][3421];

int main() {

	int T;
	cin >> T;

	for(int k=1;k<7;k++){
		num[1][k]=1.0/6.0;
	}

	for(int i=2;i<570;i++){
		for(int j=i;j<(6*i+1);j++){
			if(j-i>=0)
				num[i][j]+=num[i-1][j-1];
			if(j-i>=1)
				num[i][j]+=num[i-1][j-2];
			if(j-i>=2)
				num[i][j]+=num[i-1][j-3];
			if(j-i>=3)
				num[i][j]+=num[i-1][j-4];
			if(j-i>=4)
				num[i][j]+=num[i-1][j-5];
			if(j-i>=5)
				num[i][j]+=num[i-1][j-6];

			num[i][j]/=6.0;
		}
	}


	while (T--) {
		long int n, k;
		cin >> n >> k;
		double result;
		if(n>570){
			result=0;
		}else if(n<571 && k>=570*6){
			result=0;
		}else{
			result=num[n][k];
		}

		cout << floor(result*100)<< "\n";
	}
}

