#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		double S;
		cin>>S;
		//easy derivation
		// formula is 1 - sqrt(2)/3*sqrt(s)
		// can be simplied as 1 - (0.4714..)/sqrt(s)
		double result=1-(0.47140452079)/sqrt(S);
		cout<<result<<"\n";
	}
}