/*
 * CHOCOLA.cpp
 *
 *  Created on: Mar 18, 2015
 *      Author: ngoyal
 */

#include<iostream>
#include<algorithm>
#define MAX 1009
using namespace std;

int main(){
	int m,n;
	int x[MAX],y[MAX];
	int T;
	cin >> T;
//	cin>> x[1];
	for(int i=0;i<T;i++){
		cin >> m>> n;
		m--;n--;
		for(int j=0;j<m;j++){
			cin>>x[j];
		}
		for(int j=0;j<n;j++){
			cin>>y[j];
		}
		sort(x,x+m,greater<int>());
		sort(y,y+n,greater<int>());

		int result;
		int rows=1,cols=1;
		int cur_x=0,cur_y=0;
		while(cur_x!=m&&cur_y!=n){
			if(x[cur_x]>y[cur_y]){
				result+=x[cur_x]*cols;
				rows++;
				cur_x++;
			}else{
				result+=y[cur_y]*rows;
				cols++;
				cur_y++;
			}
		}
		while(cur_x!=m){
			result+=x[cur_x]*cols;
			cur_x++;
		}
		while(cur_y!=n){
			result+=y[cur_y]*rows;
			cur_y++;
		}
		cout << result <<"\n";
	}
}

