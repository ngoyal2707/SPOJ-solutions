#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 10010
#define RES_MAX 20020
#define POWER 8
#define KARAT_CUTOFF 4

unsigned long long a[MAX],b[MAX],res[RES_MAX];
int a_len,b_len,a_base_len,b_base_len;
long res_len;

void multiply()
{
	unsigned long long i,j,carry=0,temp,temp_len=0,base;
	res_len=0;
	carry=0;	

	base=(long)pow(10.0,POWER);

	for(i=0;i<a_base_len;i++)
	{
		for(j=0;j<b_base_len;j++)
		{
			res[i+j]+=a[i]*b[j];
		}
	}
	for(i=0;i<(a_base_len+b_base_len);i++)
	{
		temp=res[i]+carry;
		carry=temp/base;
		res[i]=temp%base;
		temp_len++;
		if(res[i]!=0)
		{
			res_len=temp_len;
		}
	}
	if(res_len==0)
	{
		res_len++;
	}
}

int makeEqualLength()
{
	if(a_base_len<b_base_len)
	{
		a_base_len=b_base_len;
	}
	else
	{
		b_base_len=a_base_len;
	}
	return a_base_len;
}

void gradeSchool(unsigned long long *a, unsigned long long *b, unsigned long long *ret, unsigned long long d) {
	int             i, j;

	for(i = 0; i < 2 * d; i++) ret[i] = 0;
	for(i = 0; i < d; i++) {
		for(j = 0; j < d; j++) ret[i + j] += a[i] * b[j];
	}
}

void karatsuba(unsigned long long *a, unsigned long long *b, unsigned long long *ret, int d) {
	int             i;
	unsigned long long             *ar = &a[0]; // low-order half of a
	unsigned long long             *al = &a[d/2]; // high-order half of a
	unsigned long long             *br = &b[0]; // low-order half of b
	unsigned long long             *bl = &b[d/2]; // high-order half of b
	unsigned long long             *asum = &ret[d * 5]; // sum of a's halves
	unsigned long long             *bsum = &ret[d * 5 + d/2]; // sum of b's halves
	unsigned long long             *x1 = &ret[d * 0]; // ar*br's location
	unsigned long long             *x2 = &ret[d * 1]; // al*bl's location
	unsigned long long             *x3 = &ret[d * 2]; // asum*bsum's location

	// when d is small, we're better off just reverting to
	// grade-school multiplication, since it's faster at this point.
	/*  if(d <= KARAT_CUTOFF) {
	gradeSchool(a, b, ret, d);
	return;
	}*/

	if(d <= KARAT_CUTOFF) {
		gradeSchool(a, b, ret, d);
		return;
	}

	// compute asum and bsum
	for(i = 0; i < d / 2; i++) {
		asum[i] = al[i] + ar[i];
		bsum[i] = bl[i] + br[i];
	}

	// do recursive calls (I have to be careful about the order,
	// since the scratch space for the recursion on x1 includes
	// the space used for x2 and x3)
	karatsuba(ar, br, x1, d/2);
	karatsuba(al, bl, x2, d/2);
	karatsuba(asum, bsum, x3, d/2);

	// combine recursive steps
	for(i = 0; i < d; i++) x3[i] = x3[i] - x1[i] - x2[i];
	for(i = 0; i < d; i++) ret[i + d/2] += x3[i];
}

void convertBase()
{
		unsigned long long i,j,carry=0,temp,temp_len=0,base;
	res_len=0;
	carry=0;	

	base=(long)pow(10.0,POWER);
	for(j=0;j<(a_base_len+b_base_len);j++)
	{
		temp=res[j]+carry;
		carry=temp/base;
		res[j]=temp%base;
		temp_len++;
		if(res[j]!=0)
		{
			res_len=temp_len;
		}
	}
	if(res_len==0)
	{
		res_len++;
	}
}

int main()
{
	int test_cases,i,j,k;
	char a_buff[MAX],b_buff[MAX],str[10],partial_result[10];

	unsigned long long carry=0,temp,temp_len=0,base;
	base=(long)pow(10.0,POWER);
	/*	test_cases=1000;
	for(i=0;i<10000;i++)
	{
	a_buff[i]='9';
	b_buff[i]='9';
	}
	a_buff[i]='\0';
	b_buff[i]='\0';
	*/
	scanf("%d",&test_cases);


	sprintf(str,"%%0%dld",POWER);
	for(i=0;i<test_cases;i++)
	{
		scanf("%s",&a_buff);
		scanf("%s",&b_buff);
		a_len=strlen(a_buff);
		b_len=strlen(b_buff);
		memset(res,0,RES_MAX);
		memset(a,0,MAX);
		memset(b,0,MAX);


		a_base_len=0;
		b_base_len=0;
		for(j=0;j<a_len;j=j+POWER)
		{
			for(k=0;k<POWER;k++)
			{
				if((a_len-1-j-k)>=0)
				{
					a[a_base_len]+=(a_buff[a_len-1-j-k]-'0')*pow(10.0,k);
				}
			}
			a_base_len++;
		}
		for(j=0;j<b_len;j=j+POWER)
		{
			for(k=0;k<POWER;k++)
			{
				if((b_len-1-j-k)>=0)
				{
					b[b_base_len]+=(b_buff[b_len-1-j-k]-'0')*pow(10.0,k);
				}
			}
			b_base_len++;
		}
		//karatsuba(a,b,res,(a_base_len>b_base_len?a_base_len:b_base_len));
		multiply();
		convertBase();
		

		for(j=res_len-1;j>=0;j--)
		{
			if(j==(res_len-1))
			{
				printf("%ld",res[j]);
			}
			else
			{
				sprintf(partial_result,str,res[j]);
				printf("%s",partial_result);
			}
		}
		printf("\n");
	}
	return 0;
}
