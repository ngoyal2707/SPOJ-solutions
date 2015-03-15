#include<stdio.h>
#include<string.h>
#define MAX 1000


long number[MAX], length;
int getLastDigitOfTwoPower()
{
	int lastTwoDigits,count;

	lastTwoDigits=number[0];
	if(length>1)
	{
		lastTwoDigits+=10*number[1];
	}
	if(lastTwoDigits==0)
		return 1;
	count=lastTwoDigits%4;
	switch (count)
	{
	case 0:
		return 6;
	case 1:
		return 2;
	case 2:
		return 4;
	case 3:
		return 8;
	}
}

int getLastDigitOfSmallNumber(int rem)
{
	switch(rem)
	{
	case 0:
		return 1;
	case 1:
		return 1;
	case 2:
		return 2;
	case 3:
		return 6;
	case 4:
		return 4;
	}
}


void number_div_five() 
{
	int i, carry;

	carry = 0;
	for (i = 0; i < length; i++) {
		number[i] = number[i]*2+carry;
		carry = number[i]/10;
		number[i] = number[i]%10;
	}
	if (carry>0) number[length++] = carry;
	length--;
	for (i=0; i<length; i++) number[i] = number[i+1];
}
int ifNumberGreaterThanFive()
{
	if(length==1 && number[0]<5)
		return 1;
	return 0;
}

int getLastDigit()
{
	int rem,  lastDigit=1, counter=1;

	while(ifNumberGreaterThanFive()==0)
	{
		
		rem = number[0]%5;
		number_div_five();	

		lastDigit *= getLastDigitOfTwoPower();
		lastDigit *= getLastDigitOfSmallNumber(rem);
		lastDigit =lastDigit%10;
	}
	lastDigit *= getLastDigitOfSmallNumber(number[0]);

	return lastDigit%10;
}
int main()
{
	char buff[MAX];
	int lastDigit, i;

	while(scanf("%s", &buff) > 0 )
	{
		length = strlen(buff);
		for(i=0;i<length;i++)
		{
			number[length -1 -i]=buff[i] - '0';
		}
		lastDigit = getLastDigit();
		printf("%d\n",lastDigit);
	}
	return 0;

}
