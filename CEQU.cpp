#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

int main(){
	long int t,caseNo=1;
	cin>>t;
	while(t--){
		long long int a,b,c,temp,temp_a,temp_b;
		scanf("%lld%lld%lld",&a,&b,&c);

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
		// long long int lcm=(temp_a*temp_b)/a;
		// cout<<lcm<<"\n";
		if(c%a==0)
			printf("Case %ld: Yes\n",caseNo);
		else
			printf("Case %ld: No\n",caseNo);
		caseNo++;
	}
}