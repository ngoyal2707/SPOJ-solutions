#include<iostream>
#define MAX 210
using namespace std;

int *** get3DArray(int X,int Y, int Z){
	int ***arr3D = new int**[X];
	for(int i =0; i<X; i++){
	   arr3D[i] = new int*[Y];
	   for(int j =0; j<Y; j++){
		   arr3D[i][j] = new int[Z];
		   for(int k = 0; k<Z;k++){
			  arr3D[i][j][k] = 0;
		   }
	   }
	}
	return arr3D;
}

bool *** get3DArrayBool(int X,int Y, int Z){
	bool ***arr3D = new bool**[X];
	for(int i =0; i<X; i++){
	   arr3D[i] = new bool*[Y];
	   for(int j =0; j<Y; j++){
		   arr3D[i][j] = new bool[Z];
		   for(int k = 0; k<Z;k++){
			  arr3D[i][j][k] = false;
		   }
	   }
	}
	return arr3D;
}

int solve(char a[MAX][MAX], int N){
	bool ***row_pal,***col_pal;
	row_pal=get3DArrayBool(MAX,MAX,MAX);
	col_pal=get3DArrayBool(MAX,MAX,MAX);
//	cout<< "here";
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			row_pal[i][j][0]=true;
			row_pal[i][j][1]=true;
			col_pal[i][j][0]=true;
			col_pal[i][j][1]=true;
		}
	}
	for(int k=2;k<=N;k++){
		for(int i=0;i<N;i++){
			for(int j=k-1;j<N;j++){
				if(a[i][j-k+1]==a[i][j] && row_pal[i][j-1][k-2]){
					row_pal[i][j][k]=true;
				}
			}
		}
	}

	for(int k=2;k<=N;k++){
		for(int i=k-1;i<N;i++){
			for(int j=0;j<N;j++){
					if(a[i-k+1][j]==a[i][j] && col_pal[i-1][j][k-2]){
					col_pal[i][j][k]=true;
				}
			}
		}
	}

	int ***row,***col;
	row=get3DArray(MAX,MAX,MAX);
	col=get3DArray(MAX,MAX,MAX);
	int result=-1;
	for(int i=0;i<N;i++){
//		cout << "lalala";
		for(int j=0;j<N;j++){
			for(int k=1;k<=N;k++){
				if(row_pal[i][j][k])
					row[i][j][k]=i>0?1+row[i-1][j][k]:1;
				if(col_pal[i][j][k])
					col[i][j][k]=j>0?1+col[i][j-1][k]:1;
				if(row[i][j][k] >= k && col[i][j][k] >=k){
					if(k>result){
						result=k;
					}
				}
			}

		}
	}
	return result;
}

int main(){
	int N;
	char a[MAX][MAX];
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> a[i];
	}

	int result=solve(a, N);
	cout << result;
	return 0;
}
