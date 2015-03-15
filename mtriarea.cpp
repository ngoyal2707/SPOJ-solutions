#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#define MAX 50001
#define INF 10001
#define NEG_INF -1
using namespace std;

struct Point
{
	int x;
	int y;
};

bool onSegment(Point p1, Point p2, Point p3);
Point p0;

Point nextToTop(stack<Point> &S)
{
	Point p = S.top();
	S.pop();
	Point res = S.top();
	S.push(p);
	return res;
}

void swap(Point &p1, Point &p2)
{
	Point temp = p1;
	p1 = p2;
	p2 = temp;
}

int dist(Point p1, Point p2)
{
	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
		(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;  // colinear
	return (val > 0)? 1: 2; // clock or counterclock wise
}

int compare(const void *vp1, const void *vp2)
{
	Point *p1 = (Point *)vp1;
	Point *p2 = (Point *)vp2;

	int o = orientation(p0, *p1, *p2);
	if (o == 0)
		return (dist(p0, *p2) >= dist(p0, *p1))? -1 : 1;

	return (o == 2)? -1: 1;
}

void convexHull(Point points[], int n,stack<Point> &S)
{
	int ymin = points[0].y, min = 0;
	for (int i = 1; i < n; i++)
	{
		int y = points[i].y;

		if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
			ymin = points[i].y, min = i;
	}

	swap(points[0], points[min]);

	p0 = points[0];

	if(n>1)
		qsort(&points[1], n-1, sizeof(Point), compare);



	S.push(points[0]);
	if(n>2)
	{
		int i=0;
		while((!orientation(points[i],points[i+1],points[i+2]))&&(i<n-2))
		{
			i++;
		}
		if(i<(n-2))
		{
			S.push(points[++i]);
			S.push(points[++i]);
			for (; i < n; i++)
			{
				while (orientation(nextToTop(S), S.top(), points[i]) != 2)
					S.pop();
				S.push(points[i]);
			}
		}
		else
		{
			S.push(points[i+1]);
		}
	}
	else if(n==2)
	{
		S.push(points[1]);
	}

}
int area(Point p1, Point p2, Point p3)
{
	int area;
	area=(p1.x*p2.y-p1.x*p3.y-p2.x*p1.y+p2.x*p3.y+p3.x*p1.y-p3.x*p2.y);
	return area;
}
int main()
{
	int n,convexHullPointCount;
	int A,B,C,bA,bB,bC;
	Point points[MAX],hull[MAX];
	stack<Point> s;
	while(1)
	{
		scanf("%d",&n);
		if(n==-1)
			break;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&points[i].x);
			scanf("%d",&points[i].y);
		}
		convexHullPointCount=0;
		convexHull(points,n,s);
		while(!s.empty())
		{
			Point p=s.top();
			s.pop();
			hull[convexHullPointCount++]=p;
		}
		A=0;B=1;C=2;
		bA=A;bB=B;bC=C;
		while(1)
		{
			while(1)
			{
				while(area(hull[A],hull[B],hull[C])<=area(hull[A],hull[B],hull[(C+1)%convexHullPointCount]))
				{
					C=(C+1)%convexHullPointCount;
				}
				if(area(hull[A],hull[B],hull[C])<=area(hull[A],hull[(B+1)%convexHullPointCount],hull[C]))
				{
					B=(B+1)%convexHullPointCount;
					continue;
				}
				else 
					break;
			}
			if(area(hull[A],hull[B],hull[C])>area(hull[bA],hull[bB],hull[bC]))
			{
				bA=A;bB=B;bC=C;
			}
			A=(A+1)%convexHullPointCount;
			if(A==B) 
				B=(B+1)%convexHullPointCount;
			if(B==C)
				C=(C+1)%convexHullPointCount;
			if(A==0)
				break;
		}
		int minArea=area(hull[bA],hull[bB],hull[bC]);
		printf("%d",minArea/2);
		if(minArea%2==0)
			printf(".00\n");
		else
			printf(".50\n");
	}
	return 0;
}