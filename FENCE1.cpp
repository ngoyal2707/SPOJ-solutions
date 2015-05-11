#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	int L;
	cin>>L;
	while(L){
		double result;
		result = (L*L)/(2*3.1415926);
		cout << std::fixed;
		cout<<std::setprecision(2);
		cout<<(int(result*100+0.5))/100.0<<"\n";
		cin>>L;
	}
}