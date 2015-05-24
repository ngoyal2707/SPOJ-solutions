#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int G,B;
	while(cin>>G>>B && G!=-1 && B!=-1){
		int temp;
		if(G>B){
			temp=G;
			G=B;
			B=temp;
		}
		float temp1=(float)B/(float)(G+1);
		int result=ceil(temp1);
		cout<<result<<"\n";
	}
}