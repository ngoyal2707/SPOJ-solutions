/*
 * THREECOL.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: ngoyal
 */

#include<iostream>
#include<cstring>

#define MAX 10005

using namespace std;
int resultMax[MAX][3];
int resultMin[MAX][3];

int pointer;

typedef struct Treenode{
	struct Treenode * left;
	struct Treenode  * right;
	int data;
}node;

node * getTree(char *str){
	char childCount=str[pointer];
	node *root=new node;
	root->data=pointer;
	pointer++;
	if(childCount=='2'){
		root->left=getTree(str);
		root->right=getTree(str);

	}else if(childCount=='1'){
		root->left=getTree(str);
		root->right=NULL;
	}else{
		root->left=NULL;
		root->right=NULL;
	}
	return root;
}
int solve(node *root,int color){

	if(root==NULL){
		return 0;
	}
	if(resultMax[root->data][color]!=-1){
		return resultMax[root->data][color];
	}

	int score=color==2?1:0;
	if(color==2){
		score+=max(solve(root->left,1)+solve(root->right,0),solve(root->left,0)+solve(root->right,1));
	}else if(color==1){
		score+=max(solve(root->left,0)+solve(root->right,2),solve(root->left,2)+solve(root->right,0));
	}else{
		score+=max(solve(root->left,1)+solve(root->right,2),solve(root->left,2)+solve(root->right,1));
	}
	resultMax[root->data][color]=score;
	return score;
}
int solveMin(node *root,int color){

	if(root==NULL){
		return 0;
	}
	if(resultMin[root->data][color]!=-1){
		return resultMin[root->data][color];
	}

	int score=color==2?1:0;
	if(color==2){
		score+=min(solveMin(root->left,1)+solveMin(root->right,0),solveMin(root->left,0)+solveMin(root->right,1));
	}else if(color==1){
		score+=min(solveMin(root->left,0)+solveMin(root->right,2),solveMin(root->left,2)+solveMin(root->right,0));
	}else{
		score+=min(solveMin(root->left,1)+solveMin(root->right,2),solveMin(root->left,2)+solveMin(root->right,1));
	}
	resultMin[root->data][color]=score;
	return score;
}
//0-Red, 1-Blue, 2-Green
int main(){
	int T;
	cin>>T;
	while(T--){
		char treeStr[MAX];
		cin>>treeStr;
		pointer=0;
		for(int i=0;i<strlen(treeStr);i++){
			resultMax[i][0]=-1;
			resultMax[i][1]=-1;
			resultMax[i][2]=-1;

			resultMin[i][0]=-1;
			resultMin[i][1]=-1;
			resultMin[i][2]=-1;
		}
		node * root=getTree(treeStr);
		int resultMax=max(solve(root,0),max(solve(root,1),solve(root,2)));
		int resultMin=min(solveMin(root,0),min(solveMin(root,1),solveMin(root,2)));
		cout<<resultMax<<" "<<resultMin<<"\n";
	}
}
