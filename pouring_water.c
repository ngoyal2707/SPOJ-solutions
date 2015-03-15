#include<stdio.h>


int main()
{
	int test_cases=0,i,a,b,c;
	scanf("%d",&test_cases);
	for(i=0;i<test_cases;i++){
		scanf("%ld",&a);
		scanf("%ld",&b);
		scanf("%ld",&c);
		if( c == 0){
			printf("0\n");
		}
		if(c == a || c == b){
			printf("1\n");
		} else if( (c == (a-b)) || (c == (b-a))){
			printf("2\n");
		} else {
			printf("-1\n");
		}
	}
	return 0;
}