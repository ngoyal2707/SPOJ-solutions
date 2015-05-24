#include<iostream>
#include<cmath>
#include<cstring>
#define MAX 1010
using namespace std;
int main(){
	int result[MAX];
	memset(result,0,sizeof(result));
	for(int i=1;i*i<=1000;i++){
		result[i*i]=1;
	}

	for(int i=2;i<=1000;i++){
		if(result[i]!=1){
			result[i]=2000;
			for(int j=1;j*j<=i;j++){
				result[i]=min(result[i],1+result[i-j*j]);
			}
		}
	}
	long T;
	cin>>T;
	while(T--){
		int A;
		cin>>A;
		cout<<result[A]<<"\n";
	}
}