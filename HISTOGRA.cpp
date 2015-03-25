/*
 * HISTOGRA.cpp
 *
 *  Created on: Mar 24, 2015
 *      Author: ngoyal
 */


#include<iostream>
#include<stack>
#define MAX 100005
using namespace std;

long long int solve(long n,long long *h){
	long long left[n],right[n];
	stack<long long> myStack,myStack2;

	for(int i=0;i<n;i++){
		long long leftMoves=0;
		while(!myStack.empty()&&h[i]<=h[myStack.top()]){
			long long removedIndex=myStack.top();
			myStack.pop();
			leftMoves=leftMoves+1+left[removedIndex];
		}
		left[i]=leftMoves;
		myStack.push(i);
	}

	for(int i=n-1;i>=0;i--){
		long long rightMoves=0;
		while(!myStack2.empty()&&h[i]<=h[myStack2.top()]){
			long long removedIndex=myStack2.top();
			myStack2.pop();
			rightMoves=rightMoves+1+right[removedIndex];
		}
		right[i]=rightMoves;
		myStack2.push(i);
	}

	long long int rectSize[n],maxRect=-1;

	for(int i=0;i<n;i++){
		rectSize[i]=h[i]*(left[i]+right[i]+1);
		if(rectSize[i]>maxRect){
			maxRect=rectSize[i];
		}
	}
	return maxRect;
}

int main(){
	long n;
	cin>>n;
	while(n!=0){
		long long h[MAX];
		for(int i=0;i<n;i++){
			cin>>h[i];
		}
		long long int result=solve(n,h);
		cout<<result<<"\n";
		cin>>n;
	}
}
