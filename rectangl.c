#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#define MAX 250001
#define BASE 10

typedef struct Points
{
	long x;
	long y;
}Points;

void sortForY(Points points[MAX],Points y_sorted[MAX],long N)
{
	long i, max, exp = 1,j;
	long bucket[BASE] = { 0 };

	max=points[0].y;
	for (i = 1; i < N; i++)
	{
		if (abs(points[i].y) > max)
			max = abs(points[i].y);
	}

	while (max / exp > 0)
	{
		for(i=0;i<BASE;i++)
			bucket[i]=0;
		for (i = 0; i < N; i++)
			bucket[(abs(points[i].y) / exp) % BASE]++;

		for (i = 1; i < BASE; i++)
			bucket[i] += bucket[i - 1]; 

		for (i = N - 1; i >= 0; i--)
		{
			y_sorted[--bucket[abs(points[i].y / exp) % BASE]].x = points[i].x;
			y_sorted[bucket[abs(points[i].y / exp) % BASE]].y = points[i].y;
		}
		for (i = 0; i < N; i++)
		{
			points[i].x = y_sorted[i].x;
			points[i].y = y_sorted[i].y;
		}
		exp *= BASE;
	}
	j=0;
	for (i = N-1; i >=0; i--)
	{
		if(points[i].y<0)
		{
			y_sorted[j].x = points[i].x;
			y_sorted[j++].y = points[i].y;
		}
	}
	for(i=0;i<N;i++)
	{
		if(points[i].y>=0)
		{
			y_sorted[j].x = points[i].x;
			y_sorted[j++].y = points[i].y;
		}
	}
}

void sortForX(Points points[MAX],Points x_sorted[MAX],long N)
{
	long i, max, exp = 1,j;
	long bucket[BASE] = { 0 };

	max=points[0].x;
	for (i = 1; i < N; i++)
	{
		if (abs(points[i].x) > max)
			max = abs(points[i].x);
	}

	while (max / exp > 0)
	{
		for(i=0;i<BASE;i++)
			bucket[i]=0;
		for (i = 0; i < N; i++)
			bucket[abs(points[i].x / exp) % BASE]++;

		for (i = 1; i < BASE; i++)
			bucket[i] += bucket[i - 1]; 

		for (i = N - 1; i >= 0; i--)
		{
			x_sorted[--bucket[abs(points[i].x / exp) % BASE]].x = points[i].x;
			x_sorted[bucket[abs(points[i].x / exp) % BASE]].y = points[i].y;
		}
		for (i = 0; i < N; i++)
		{
			points[i].x = x_sorted[i].x;
			points[i].y = x_sorted[i].y;
		}
		exp *= BASE;
	}
	j=0;
	for (i = N-1; i >=0; i--)
	{
		if(points[i].x<0)
		{
			x_sorted[j].x = points[i].x;
			x_sorted[j++].y = points[i].y;
		}
	}
	for(i=0;i<N;i++)
	{
		if(points[i].x>=0)
		{
			x_sorted[j].x = points[i].x;
			x_sorted[j++].y = points[i].y;
		}
	}
}
long searchForStartingIndexInX(Points points[MAX],long N,long x)
{
	long high,mid,low;
	low=0;
	high=N-1;
	mid=(low+high)/2;
	while(high>low)
	{
		if(points[mid].x<x)
			low=mid+1;
		else
			high=mid-1;
		mid=(low+high)/2;
	}
	if(points[high].x==x)
		high--;
	return high;
}

long searchForEndingIndexInX(Points points[MAX],long N,long x)
{
	long high,mid,low;
	low=0;
	high=N-1;
	mid=(low+high)/2;
	while(high>low)
	{
		if(points[mid].x>x)
			high=mid-1;
		else
			low=mid+1;
		mid=(low+high)/2;
	}
	if(points[high].x==x)
		high++;
	return high;
}

long searchForStartingIndexInY(Points points[MAX],long N,long y)
{
	long high,mid,low;
	low=0;
	high=N-1;
	mid=(low+high)/2;
	while(high>low)
	{
		if(points[mid].y<y)
			low=mid+1;
		else
			high=mid-1;
		mid=(low+high)/2;
	}
	if(points[high].y==y)
		high--;
	return high;
}

long searchForEndingIndexInY(Points points[MAX],long N,long y)
{
	long high,mid,low;
	low=0;
	high=N-1;
	mid=(low+high)/2;
	while(high>low)
	{
		if(points[mid].y>y)
			high=mid-1;
		else
			low=mid+1;
		mid=(low+high)/2;
	}
	if(points[high].y==y)
		high++;
	return high;
}

int main()
{
	long N,i,j,k;
	long long int rectangleCount=0;
	Points *points=(Points *)calloc(1,MAX*sizeof(Points));
	Points *x_sorted=(Points *)calloc(1,MAX*sizeof(Points));
	Points *y_sorted=(Points *)calloc(1,MAX*sizeof(Points));

	Points *temp_x=(Points *)calloc(1,MAX*sizeof(Points));
	Points *temp_y=(Points *)calloc(1,MAX*sizeof(Points));
	Points current;
	long tempx_count,tempy_count;
	long start_index_x,start_index_y;
	long end_index_x,end_index_y;
	long index;
	scanf("%ld",&N);
	/*srand(time(NULL));
	N=100;*/
	for(i=0;i<N;i++)
	{
		scanf("%ld",&points[i].x);
		scanf("%ld",&points[i].y);
		/*points[i].x=rand()-16000;
		points[i].y=rand()-16000;*/
	}

	sortForX(points,x_sorted,N);
	sortForY(points,y_sorted,N);

	for(i=0;i<N;i++)
	{
		current=x_sorted[i];
		start_index_x=i;
		end_index_x=i;
		while(x_sorted[end_index_x].x==current.x)
		{
			end_index_x++;
		}

		start_index_y=searchForStartingIndexInY(y_sorted,N,current.y);
		end_index_y=searchForEndingIndexInY(y_sorted,N,current.y);
		for(j=start_index_x+1;j<end_index_x;j++)
		{
			for(k=start_index_y+1;k<end_index_y;k++)
			{
				if(y_sorted[k].x>current.x)
				{
					index=searchForStartingIndexInX(x_sorted,N,y_sorted[k].x);
					index++;
					while(x_sorted[index].x==y_sorted[k].x)
					{
						if(x_sorted[index].y==x_sorted[j].y)
						{
							rectangleCount++;
						/*	printf("\n\n%ld\t%ld",current.x,current.y);
							printf("\t%ld\t%ld",x_sorted[j].x,x_sorted[j].y);							
							printf("\t%ld\t%ld",y_sorted[k].x,y_sorted[k].y);							
							printf("\t%ld\t%ld",x_sorted[index].x,x_sorted[index].y);*/
						}	
						index++;
					}
				}
			}
		}
	}
	printf("%lld\n",rectangleCount);
	return 0;
}