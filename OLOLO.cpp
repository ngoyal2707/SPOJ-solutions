/*
 * OLOLO.cpp
 *
 *  Created on: Apr 16, 2015
 *      Author: ngoyal
 */

#include<stdio.h>
int main(){
	long int N,a;
	scanf("%ld",&N);
	long int result=0;
	while(N--){
		scanf("%ld",&a);
		result=result^a;
	}
	printf("%ld",result);
}
