#include<stdio.h>
#include<string.h>
#define MAX 200

long total[MAX],diff[MAX], higherResult[MAX], lowerResult[MAX];
int length_total, length_diff, length_higherResult=0, length_lowerResult=0;

void divideByTwoHigher()
{
	int i,carry=0,temp,temp1;
	for(i=length_higherResult-1;i>=0;i--)
	{
		temp=carry*10+higherResult[i];
		higherResult[i]=temp/2;
		carry=temp%2;
	}
	i=length_higherResult-1;
}

void divideByTwoLower()
{
	int i,carry=0,temp;
	for(i=length_lowerResult-1;i>=0;i--)
	{
		temp=carry*10+lowerResult[i];
		lowerResult[i]=temp/2;
		carry=temp%2;
	}
	i=length_lowerResult-1;


}
void computeHigher()
{
	int i,temp,carry=0;
	length_higherResult=0;
	for(i=0;i<length_diff;i++)
	{
		temp=total[i]+diff[i] + carry;
		higherResult[i]=temp%10;
		carry=temp/10;
		length_higherResult++;
	}
	for(;i<length_total;i++)
	{
		temp=total[i]+carry;
		higherResult[i]=temp%10;
		carry=temp/10;
		length_higherResult++;
	}
	while(carry>0)
	{
		higherResult[i]=carry%10;
		carry=carry/10;
		i++;
		length_higherResult++;
	}
	divideByTwoHigher();
}

void computeLower()
{
	int i,temp,carry=0;
	length_lowerResult=0;
	for(i=0;i<length_diff;i++)
	{
		temp=total[i]-carry-diff[i];
		if(temp<0)
		{
			lowerResult[i]=temp+10;
			carry=1;
		}
		else
		{
			lowerResult[i]=temp;
			carry=0;
		}
		length_lowerResult++;
	}
	for(;i<length_total;i++)
	{
		temp=total[i]-carry;
		if(temp<0)
		{
			lowerResult[i]=temp+10;
			carry=1;
		}
		else
		{		
			lowerResult[i]=temp;
			carry=0;
		}
		length_lowerResult++;
	}
	if(lowerResult[length_lowerResult-1]==0)
	{
		length_lowerResult--;
	}
	/*while(carry>0)
	{
		lowerResult[i]=carry%10;
		carry=carry/10;
		i++;
		length_lowerResult++;
	}*/
	divideByTwoLower();
}
int main()
{
	char totalChar[MAX], diffChar[MAX];
	int i,j;
	for(i=0;i<10;i++)
	{
		scanf("%s",totalChar);
		scanf("%s",diffChar);
		length_total=strlen(totalChar);
		length_diff=strlen(diffChar);
		for(j=0;j<length_total;j++)
		{
			total[j]=totalChar[length_total - 1 -j]-'0';
		}
		for(j=0;j<length_diff;j++)
		{
			diff[j]=diffChar[length_diff - 1 -j]-'0';
		}
		computeHigher();
		
		j=length_higherResult-1;
		while(higherResult[j]==0)
		{
			length_higherResult--;
			j--;
		}

		for(j=length_higherResult-1;j>=0;j--)
		{
			printf("%ld",higherResult[j]);
		}	
		printf("\n");
		computeLower();

		
		j=length_lowerResult-1;
		while(lowerResult[j]==0)
		{
			length_lowerResult--;
			j--;
		}

		for(j=length_lowerResult-1;j>=0;j--)
		{
			printf("%ld",lowerResult[j]);
		}
		printf("\n");
	}
	return 0;
}