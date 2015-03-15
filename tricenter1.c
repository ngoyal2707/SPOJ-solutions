#include<stdio.h>
#include<math.h>
#define EPP 0.00001

int main()
{
	double dist_a,dist_b,dist_c,a,b,c;
	double median_a,median_b,median_c,s,area, r,oh,result;
	int test_cases,i;
	scanf("%d",&test_cases);
	for(i=0;i<test_cases;i++)
	{
		scanf("%lf",&a);
		scanf("%lf",&dist_a);
		scanf("%lf",&dist_b);
		scanf("%lf",&dist_c);
		b=a*dist_a/dist_b;
		c=a*dist_a/dist_c;
		s=(a+b+c)/2;
		area=sqrt(s*(s-a)*(s-b)*(s-c));

		r=(a*b*c)/sqrt((a+b+c)*(b+c-a)*(c+a-b)*(a+b-c));
		oh=9*r*r-(a*a+b*b+c*c);
		if(abs(oh)<EPP)
		{
			oh=0;
		}
		oh=sqrt(oh);
		result=oh*2/3;

		printf("%0.03f\t",area);		
		printf("%0.03f\n",result);
	}

	return 0;
}
