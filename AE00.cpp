#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int N;
	cin>>N;
	long int result=0;
	for(int i=1;i<=sqrt(N);i++)
		result+=(floor(N/i)-i+1);
	cout<<result;
}