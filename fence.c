#include<stdio.h>
#define MAX 100

typedef struct{
	int x;
	int y;
	int given_position;
}Point;

Point points[MAX];
Point start;
long no_of_sheeps, start_index;

void swap(long a,long b)
{
	Point temp;

	temp.x=points[a].x;
	temp.y=points[a].y;
	temp.given_position=points[a].given_position;

	points[a].x=points[b].x;
	points[a].y=points[b].y;
	points[a].given_position=points[b].given_position;

	points[b].x=temp.x;
	points[b].y=temp.y;
	points[b].given_position=temp.given_position;
}

void read_input()
{
	int i;
	scanf("%ld",&no_of_sheeps);
	for(i=0;i<no_of_sheeps;i++)
	{
		scanf("%d",&points[i].x);
		scanf("%d",&points[i].y);
		points[i].given_position=i+1;
	}
}

void findStartingPoint()
{
	int i;
	start.x=10001;
	start.y=10001;
	for(i=0;i<no_of_sheeps;i++)
	{
		if((points[i].y<start.y)||(points[i].y==start.y)&&(points[i].x<start.x))
		{
			start.x=points[i].x;
			start.y=points[i].y;
			start_index=i;
		}
	}
}

int compare(long first, long second)
{
	int value =(points[first].y-points[start_index].y)*(points[second].x-points[first].x) - 
			   (points[first].x-points[start_index].x)*(points[second].y-points[first].y);

	if(value==0)
	{
		return (points[first].given_position<points[second].given_position)? first:second;
	}
	else if(value < 0)
		return 1;
	else 
		return -1;

}
void mergeSorted(long low, long mid, long high)
{
	Point temp[MAX];
	int comp;
	long l,h,i=0;
	l=low;
	h=mid+1;
	while((l<=mid) || (h < high))
	{
		// returns +ve if first point makes
		// smaller angle to start point
		comp=compare(l, h);
		if(comp>0)
		{
			temp[i].x=points[l].x;
			temp[i].y=points[l].y;
			temp[i].given_position=points[l].given_position;
			l++;
		}
		else
		{
			temp[i].x=points[h].x;
			temp[i].y=points[h].y;
			temp[i].given_position=points[h].given_position;
			h++;
		}
		i++;
	}
	while(l<=mid)
	{
			temp[i].x=points[l].x;
			temp[i].y=points[l].y;
			temp[i].given_position=points[l].given_position;
			l++;
			i++;
	}
	while(h<=high)
	{
			temp[i].x=points[h].x;
			temp[i].y=points[h].y;
			temp[i].given_position=points[h].given_position;
			h++;
			i++;
	}
}

void sortpointsByAngle(long low, long high)
{
	long midPoint;
	if(low < high)
	{
		midPoint=(low+high)/2;
		sortpointsByAngle(low, midPoint);
		sortpointsByAngle(midPoint+1, high);
		mergeSorted(low, midPoint, high);
	}
}


void solveSingleTest()
{
	read_input();
	findStartingPoint();
	swap(start_index,0);
	sortpointsByAngle(1,no_of_sheeps);
}

int main()
{
	int test, i;
	scanf("%d", &test);
	for(i=0;i<test;i++)
	{
		solveSingleTest();
	}

	return 0;
}