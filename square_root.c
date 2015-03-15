/*
Nice Problem, Using digit by digit method 
to solve given on wikipedia with decimal 
base 10. Newton Raphson and binary search 
method might give TLE since the number is 
very very large
Got AC 0.22 sec

ngoyal
naman.goyal21@gmail.com
*/


#include<stdio.h>
#include<string.h>

#define MAX_INPUT 805

int number[MAX_INPUT], num_len=0;
int result[MAX_INPUT], res_len=0;

int compare(int temp_divisor[],int temp_div_len, int remainder[],  int rem_len)
{
	int i;
	int compare_result;
	while(remainder[rem_len-1]==0)
		rem_len--;
	if(temp_div_len<rem_len)
	{
		return 1;
	}
	else if(temp_div_len>rem_len)
	{
		return 0;
	}
	else
	{
		for(i=rem_len-1;i>=0;i--)
		{
			if(temp_divisor[i]<remainder[i])
			{
				return 1; 
			}
			else if (temp_divisor[i]>remainder[i])
			{
				return 0;
			}
		}
	}
	return 1;
}

int find_x(int divisor[], int div_len, int remainder[],int rem_len)
{
	int previos_x;
	int i,j;
	int last_digit,carry,temp;
	int temp_divisor[MAX_INPUT],temp_div_len=0;
	int result;
	/*
	try all possibilities from 0 to 9 for next digit.
	this can be done in better way by somehow predicting
	but this will do for now.
	*/
	for(i=0;i<=9;i++)
	{
		temp_div_len=0;
		temp_divisor[temp_div_len++]=i*i%10;
		carry=i*i/10;

		for(j=0;j<div_len;j++)
		{
			temp=divisor[j]*i+carry;
			temp_divisor[temp_div_len++]=temp%10;
			carry=temp/10;
		}
		while(carry!=0)
		{
			temp_divisor[temp_div_len++]=carry%10;
			carry=carry/10;
		}

		/*
		returns 1 if divisor<=remainder
		returns 0 otherwise
		*/
		if(i!=0)
		{
			result=compare(temp_divisor,temp_div_len, remainder, rem_len);
		}
		else
			result=1;
		if(!result)
		{
			break;
		}
	}
	return --i;
}

void findRoot()
{
	int i,j;
	int remainder[MAX_INPUT], rem_len=0;
	int divisor[MAX_INPUT], div_len=0;
	int x=0;
	int carry=0,temp;
	int carry1,carry2,temp1,temp2;
	int isTrailingZero=1,trailingZeroCount;

	memset(divisor,0,MAX_INPUT);
	for(i=num_len-1;i>=0;i=i-2)
	{
		/*
		multiply earlier remainder with 100 and 
		new pair of numbers.
		Also removing tariling zeros from 
		previos calculation
		*/
		isTrailingZero=1;
		trailingZeroCount=0;
		for(j=rem_len-1;j>=0;j--)
		{
			if((isTrailingZero)&&(remainder[j]==0))
			{
				trailingZeroCount++;
			}
			else
			{			
				remainder[j+2]=remainder[j];
				isTrailingZero=0;
			}
		}
		remainder[1]=number[i];
		remainder[0]=number[i-1];
		rem_len+=2;
		rem_len-=trailingZeroCount;

		/*
		Add previos value of x(newly founded digit of sqr root)
		to the divisor.
		*/
		carry=0;
		for(j=0;j<div_len;j++)
		{
			if(j==0)
			{
				temp=divisor[j]+x;
			}
			else
			{
				if(carry==0)
					break;
				temp=divisor[j]+carry;
			}
			divisor[j]=temp%10;
			carry=temp/10;
		}
		while(carry!=0)
		{
			divisor[j]=carry%10;
			carry=carry/10;
			j++;
			div_len++;
		}

		/*
		This method is the key method. It finds 
		out the next digit of sqr root.
		*/
		x=find_x(divisor,div_len,remainder,rem_len);
		result[res_len++]=x;
		
		/*
		Append this digit to current divisor.
		*/
		for(j=div_len-1;j>=0;j--)
		{
			divisor[j+1]=divisor[j];
		}
		divisor[0]=x;
		div_len++;


		/*
		Find out the new remainder by
		remainder=remainder-(divisor)*x
		*/
		carry1=0;
		carry2=0;
		for(j=0;j<rem_len;j++)
		{
			if(j<div_len)
			{
				temp1=divisor[j]*x+carry1;
				carry1=temp1/10;
			}
			else
			{
				temp1=carry1;
				carry1=carry1/10;
			}

			temp2=remainder[j]-carry2 -temp1%10;
			if(temp2<0)
			{
				remainder[j]=temp2+10;
				carry2=1;
			}
			else
			{
				remainder[j]=temp2;
				carry2=0;
			}
		}
	}
}

int main()
{
	short test_cases=0,i;
	int j;
	char num_char[MAX_INPUT];

	scanf("%hu",&test_cases);
	for(i=0;i<test_cases;i++)
	{
		scanf("%s",&num_char);
		num_len=strlen(num_char);
		res_len=0;
		memset(number,0,MAX_INPUT);

		for(j=0;j<num_len;j++)
		{
			number[num_len-1-j]=num_char[j]-'0';
		}
		/*
		convert to even digits since we are 
		gonna pair two digits from the right
		*/
		if(num_len%2 !=0)
		{
			num_len++;
		}
		findRoot();
		for(j=0;j<res_len;j++)
		{
			printf("%d",result[j]);
		}
		printf("\n");
	}
	return 0;
}