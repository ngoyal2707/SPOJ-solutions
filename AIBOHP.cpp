/*
 * AIBOHP.cpp
 *
 *  Created on: Mar 21, 2015
 *      Author: ngoyal
 */

#include<iostream>
#include<cstring>
#define MAX 6300

using namespace std;


int main(){
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		char str[MAX];
		cin>>str;
		int length=strlen(str);
		int result[3][MAX];
		int row_ptr=0;
		for(int j=length-1;j>=0;j--){
			for(int k=1;k<(length-j);k++){
				if(str[j]==str[j+k]){
					if(k>1)
						result[row_ptr][k]=result[(row_ptr+2)%3][k-2];
					else
						result[row_ptr][k]=0;
				}
				else{
					result[row_ptr][k]=1+min(result[(row_ptr+2)%3][k-1],result[row_ptr][k-1]);
				}
			}
			row_ptr=(row_ptr+1)%3;
		}
		cout<< result[(row_ptr+2)%3][length-1]<<"\n";
	}
}

