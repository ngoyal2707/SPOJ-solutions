#include<iostream>
#include<cmath>
using namespace std;

int main(){
	long int t;
	cin>>t;
	while(t--){
		unsigned long long int x,y,z,result,temp,sqrt_temp,denominator_temp;
		cin>>x>>y>>z;
		temp=x*x+y*y+2*y*z;
		sqrt_temp=sqrt((long double)temp);
		if(sqrt_temp*sqrt_temp!=temp){
			cout<<"Not this time."<<"\n";
			continue;
		}
		temp=z*sqrt_temp + z*x;

		denominator_temp=(y+2*z);
		if(temp%denominator_temp==0)
			cout<<temp/denominator_temp<<"\n";
		else
			cout<<"Not this time."<<"\n";	
	}
}