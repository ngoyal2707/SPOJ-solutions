#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define BASE 10000
#define POWER 4

typedef struct treenodes{
	int data;
	struct treenodes * left;
	struct treenodes * right;
}treenode;

int currentIndex=0,res_len=0;
/*
Use long long because we are using base 10^4
*/
long long result[MAX];


treenode * createNewNode(int dataValue)
{
	treenode * node = (treenode *)malloc(sizeof(treenode));
	node->data=dataValue;
	node->left=NULL;
	node->right=NULL;
	return node;
}

/*
Only pre order is enough for creating BST.
Check if the next number is smaller then its left child.
IF next number is greater to current but smaller than parent 
then right.
*/

treenode * createBST( int preorder[],int parentValue,int nodeCount)
{
	treenode *root;
	root=createNewNode(preorder[currentIndex]);
	if(currentIndex<nodeCount-1)
	{
		if(preorder[currentIndex+1]<preorder[currentIndex])
		{
			currentIndex++;
			/*
			If going to left child pass current 
			value as parent to left subtree
			*/
			root->left=createBST(preorder,preorder[currentIndex-1],nodeCount);
		}
		if((preorder[currentIndex+1]>preorder[currentIndex])&&(preorder[currentIndex+1]<parentValue))
		{
			currentIndex++;
			/*
			If going to right child, pass current's
			parent's value as parent to right subtree
			*/
			root->right=createBST(preorder,parentValue,nodeCount);
		}
	}
	return root;
}

/*
Long is enough since max value is 29C14,
which is lesser than long limit
*/
long findCombination(int n, int r)
{
	int i;	
	unsigned long long result=1;
	if(r>n-r)
	{
		r=n-r;
	}
	for(i=1;i<=r;i++)
	{
		result*=(n-r+i);
		result=result/i;
	}
	return result;
}

void multiplyResult(long number)
{
	int i;
	long long temp,carry=0;
	for(i=0;i<res_len;i++)
	{
		temp=result[i]*number+carry;
		result[i]=temp%BASE;
		carry=temp/BASE;
	}
	while(carry!=0)
	{
		result[i]=carry%BASE;
		carry=carry/BASE;
		res_len++;
		i++;
	}
}

/*
Very easy, use DP
perm of tree=(perm of left child)*
			(perm of right child)*
			(all combinations of joining of left and right subtree)

Only last value is significant to calculate,
it will be nCr 
where n=total childs in left+right tree
	  r=child in left or right tree(doesnt matter, any one)
*/
int countPermutation(treenode * root)
{
	int leftTreeMemberCount=0,rightTreeMemberCount=0;
	long combinations;
	if(root->left!=NULL)
	{	
		leftTreeMemberCount=countPermutation(root->left);
	}
	if(root->right!=NULL)
	{
		rightTreeMemberCount=countPermutation(root->right);
	}
	combinations=findCombination(leftTreeMemberCount+rightTreeMemberCount,leftTreeMemberCount);
	multiplyResult(combinations);
	return (leftTreeMemberCount+rightTreeMemberCount+1);
}

int main()
{
	int test_cases,i, nodeCount,j,preorder[40];
	char str[10],partial_result[10];
	treenode *root;	
	
	scanf("%d",&test_cases);

	
	sprintf(str,"%%0%dld",POWER);
	for(i=0;i<test_cases;i++)
	{
		scanf("%d",&nodeCount);
		for(j=0;j<nodeCount;j++)
		{	
			scanf("%d",&preorder[j]);
		}
		currentIndex=0;
		/*passing 1000 as parent value of root,  
		  symbolic passing of infinity since max 
		  data value is limited to 30 in question 
		*/
		root=createBST(preorder,1000,nodeCount);

		res_len=1;
		result[0]=1;
		countPermutation(root);

		for(j=res_len-1;j>=0;j--)
		{
			if(j==(res_len-1))
			{
				printf("%ld",result[j]);
			}
			else
			{
				sprintf(partial_result,str,result[j]);
				printf("%s",partial_result);
			}
		}
		printf("\n");
	}
	return 0;
}