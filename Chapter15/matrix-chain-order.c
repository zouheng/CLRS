//code of matrix-chain-order
#include <malloc.h>
#include <limits.h>
#include <stdio.h>
typedef struct _Result
{
	int **m;
	int **s;
	int n;
}Result;
Result matrix_chain_order(int *p,int n);
void print_optimal_parens(int **s,int i,int j);
int main()
{
	int p[]={30,35,15,5,10,20,25};
	//int p[]={5,10,3,12,5,50,6};
	Result r;
	int n=sizeof(p)/sizeof(int)-1;
	r=matrix_chain_order(p,n);
	printf("the result is %d\n",r.m[0][r.n-1]);
	print_optimal_parens(r.s,1,n);
	printf("\n");
}
Result matrix_chain_order(int *p,int n)
{
	printf("n=%d\n",n);
	Result result;
	//Init result struct
	result.m=(int **)malloc(sizeof(int *)*n);
	result.s=(int **)malloc(sizeof(int *)*n);
	result.n=n;
	int i,j,k;
	for(i=1;i<=n;i++){
		result.m[i-1]=(int *)malloc(sizeof(int)*(n-i+1));
		result.s[i-1]=(int *)malloc(sizeof(int)*(n-i+1));
	}
	for(i=1;i<=n;i++){
		result.m[i-1][i-1]=0;
		printf("m[%d][%d]=%d\n",i,i,result.m[i-1][i-1]);
	}
	for(i=2;i<=n;i++){
		for(j=1;j<=n-i+1;j++){
			result.m[j-1][j+i-1-1]=INT_MAX;
			for(k=j;k<=j+i-1-1;k++){
				int count=result.m[j-1][k-1]+result.m[k+1-1][j+i-1-1]+p[j-1]*p[k]*p[j+i-1];
				if(count<=result.m[j-1][j+i-1-1]){
					result.m[j-1][j+i-1-1]=count;
					result.s[j-1][j+i-1-1]=k;
				}	
			}
			printf("m[%d][%d]=%d\n",j,j+i-1,result.m[j-1][j+i-1-1]);
		}
	}
	printf("test1\n");
	return result;
}
void print_optimal_parens(int **s,int i,int j)
{
	if(i==j)
		printf("A%d",i);
	else{
		int k=s[i-1][j-1];
		printf("(");
		print_optimal_parens(s,i,k);
		print_optimal_parens(s,k+1,j);
		printf(")");

	}
}
