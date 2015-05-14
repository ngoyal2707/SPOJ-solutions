#include<iostream>

using namespace std;

int main(){
	long int d;
	cin>>d;
	while(d--){
		long int s,t,N,M;
		long int *a = new long int[1500001];
		cin>>s>>t>>N>>M;
		a[0]=(s % 100 + 1) * (t % 100 + 1);
		for(int i=1;i<N;i++){
			s = (78901 + 31*s) %  699037;
			t = (23456 + 64*t) % 2097151;
			a[i]=(s % 100 + 1) * (t % 100 + 1);
		}
		long long int lastSum=0,newSum=0;
		long int previousPointer=0;
		long long int result=0;
		long long int final_result=0xFFFFFFFF;
		for(int i=0;i<N;i++){
			newSum=lastSum+a[i];
			if(newSum>M){
				while(newSum>M){
					newSum-=a[i-result];
					result--;
				}
				final_result=min(final_result,result+1);
			}
			result++;
			lastSum=newSum;
		}
		final_result=min(final_result,result);
		cout<<final_result<<"\n";
	}
}