#include<stdio.h>

long countTrailingZero(long num);

int main(){
	int zeros,num, no_input,i;
	scanf("%ld",&no_input);

	for(i =0;i<no_input;i++){
		scanf("%ld",&num);
		zeros = countTrailingZero(num);
		printf("%ld\n",zeros);
	}
	return 0;
}

long countTrailingZero(long num){
	long zeros = 0, dividend=0;
	dividend = num;
	do {
		dividend = dividend/5;
		zeros += dividend;
	}while(dividend != 0);
	return zeros;
}