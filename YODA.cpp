#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;
long int primes[6000],primeCount=0;

long long int solve_fact(long long int numerator,long long int denom_fact_list[27],long long int denom_fact_count){
	
	long int num_facts[6000];
	long int denom_facts[6000];
	memset(num_facts,0,sizeof(num_facts));
	memset(denom_facts,0,sizeof(denom_facts));

	long int biggest_factor=0;
	for(int i=0;primes[i]<=numerator;i++){
		long int curr_prime=primes[i];
		long int temp_prime=curr_prime;
		// cout<<curr_prime<<"\n";
		while(curr_prime<=numerator){
			num_facts[temp_prime]+=numerator/curr_prime;
			curr_prime*=temp_prime;
			biggest_factor=primes[i];
		}
	}

	for(int k=0;k<denom_fact_count;k++){
		long int denominator=denom_fact_list[k];
		for(int i=0;primes[i]<=denominator;i++){
			long int curr_prime=primes[i];
			long int temp_prime=curr_prime;
			while(curr_prime<=numerator){
				denom_facts[temp_prime]+=denominator/curr_prime;
				curr_prime*=temp_prime;
			}
		}
	}
	// cout<<numerator<<"\n";
	long long int result=1;
	for(int i=2;i<=biggest_factor;i++){
		result*=pow(i,num_facts[i]-denom_facts[i]);
	}

	return result;
}

int main(){
	char input_str[50000];

	int dummy[50000],i=2;
	memset(dummy,0,sizeof(dummy));
	while(i<50000){
		if(dummy[i]==0){
			primes[primeCount]=i;
			for(int j=0;j*i<50000;j++){
				dummy[j*i]=1;
			}
			primeCount++;
		}
		i++;
	}


	while(cin.getline(input_str,50000)){
		long int counts[27]; 
		memset(counts,0,sizeof(counts));
		
		for(int i=0;i<strlen(input_str);i++){
			if(input_str[i]>=97 && input_str[i]<=122)
				counts[(input_str[i]-97)]++;
			else if(input_str[i]>=65 && input_str[i]<=90)
				counts[(input_str[i]-65)]++;

		}
		int oddCount=0;
		long long int result=0;
		for(int i=0;i<27;i++){
			if(counts[i]%2!=0)
				oddCount++;
		}
		if(oddCount>1)
			result=0;
		else{
			long long int num_fact=0, denom_fact_list[27], denom_fact_count=0;
			memset(denom_fact_list,0,sizeof(denom_fact_list));
			for(int i=0;i<27;i++){
				if(counts[i]%2!=0){
					counts[i]--;
				}
				if(counts[i]==0)
					continue;
				denom_fact_list[denom_fact_count++]=counts[i]/2;
				num_fact+=counts[i]/2;
			}
			result=solve_fact(num_fact,denom_fact_list,denom_fact_count);
		
		}
		cout<<result<<"\n";
	} 
}
