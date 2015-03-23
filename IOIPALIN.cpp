/*
 * IOIPALIN.cpp
 *
 *  Created on: Mar 23, 2015
 *      Author: ngoyal
 */

#include<iostream>
#include<cstring>
#define MAX 6300

using namespace std;


int main(){
	char str[MAX];
	int length;
	cin>>length;
	cin>>str;
	int result[3][MAX];
	int row_ptr=0;
	int prev;
	for(int j=length-1;j>=0;j--){
		for(int k=1;k<(length-j);k++){
			prev=(row_ptr+2)%3;
			if(str[j]==str[j+k]){
				if(k>1)
					result[row_ptr][k]=result[prev][k-2];
				else
					result[row_ptr][k]=0;
			}
			else{
				result[row_ptr][k]=1+min(result[prev][k-1],result[row_ptr][k-1]);
			}
		}
		row_ptr=(row_ptr+1)%3;
	}
	cout<< result[(row_ptr+2)%3][length-1]<<"\n";
}

