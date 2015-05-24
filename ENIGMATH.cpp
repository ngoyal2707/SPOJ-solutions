#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int main(){
	long int t;
	cin>>t;
	while(t--){
		long long int a,b,temp,temp_a,temp_b;
		cin>>a>>b;

		temp_a=a,temp_b=b;
		if(a>b){
			temp=a;
			a=b;
			b=temp;
		}

		while(b%a!=0){
			temp=b;
			b=a;
			a=temp%a;
		}
		long long int lcm=(temp_a*temp_b)/a;
		// cout<<lcm<<"\n";
		cout<<(temp_b/a)<<" "<<(temp_a/a)<<"\n";
	}
}