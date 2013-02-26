//code for lcs-lenght
#include <malloc.h>
#include <stdio.h>
#define DIAG 1
#define UP 2
#define LEFT 3
typedef struct _Result{
	int**c;
	int**b;
}Result;
Result lcs_length(char *x,char *y,int m,int n);
void print_lcs(int **b,char *x,int m,int n);
void print_lcs_without_b(int **c,char *x,char *y,int m,int n);
void lcs_length_less_cost(char *x,char *y,int m,int n);
int main()
{
	char x[]={'1','0','0','1','0','1','0','1'};
	char y[]={'0','1','0','1','1','0','1','1','0'};
	Result result;
	lcs_length_less_cost(x,y,sizeof(x),sizeof(y));
	result=lcs_length(x,y,sizeof(x),sizeof(y));
 	printf("the length of lcs is %d\n",result.c[sizeof(x)][sizeof(y)]);	
 	//print_lcs(result.b,x,sizeof(x),sizeof(y));
 	//print_lcs_without_b(result.c,x,y,sizeof(x),sizeof(y));
 	printf("\n");
 	return 0;
}
//x[m],y[n]
Result lcs_length(char *x,char *y,int m,int n)
{
	//init
	Result result;
	result.c=(int **)malloc(sizeof(int *)*(m+1));
	result.b=(int **)malloc(sizeof(int *)*(m+1));
	int i,j;
	for(i=0;i<=m;i++){
		result.c[i]=(int*)malloc(sizeof(int)*(n+1));
		result.b[i]=(int*)malloc(sizeof(int)*(n+1));
	}
	//caculate
	//set c[0][1...n]=0
	for(i=1;i<=n;i++)
		result.c[0][i]=0;
	//set c[1...m][0]=0
	for(i=1;i<=m;i++)
		result.c[i][0]=0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++){
			if(x[i-1]==y[j-1]){
				result.c[i][j]=result.c[i-1][j-1]+1;
				result.b[i][j]=DIAG;
			}else{
				if(result.c[i-1][j]>=result.c[i][j-1]){
					result.c[i][j]=result.c[i-1][j];
					result.b[i][j]=UP;
				}else{
					result.c[i][j]=result.c[i][j-1];
					result.b[i][j]=LEFT;
				}
			}
			//printf("c[%d][%d]=%d\n",i,j,result.c[i][j]);
		}
	return result;
}
// lcs with min(m,n)+o(1) save cost
//assume n is less than m
void lcs_length_less_cost(char *x,char *y,int m,int n)
{
	int *a=(int*)malloc(sizeof(int)*(n+1));
	int i,j;
	for(i=0;i<=n;i++)
		a[i]=0;
	for(i=1;i<=m;i++){
		a[0]=0;//important
		for(j=1;j<=n;j++){
			int c;
			//printf("%c,%c",x[m-1],y[n-1]);
			if(x[i-1]==y[j-1]){
				c=a[j-1]+1;
			}else if(a[0]>=a[j]){
				c=a[0];
			}else{
				c=a[j];
			}
			a[j-1]=a[0];
			a[0]=c;
			//printf("c[%d][%d]=%d\n",i,j,a[0]);
		}
	}
	printf("the lcs length is %d\n",a[0]);
}
//normal version
void print_lcs(int **b,char *x,int m,int n)
{
	if(m==0||n==0)
		return ;
	if(b[m][n]==DIAG){
		print_lcs(b,x,m-1,n-1);
		printf("%c ",x[m-1]);
	}else if(b[m][n]==LEFT){
		print_lcs(b,x,m,n-1);
	}else
		print_lcs(b,x,m-1,n);
}
//printf without b
void print_lcs_without_b(int **c,char *x,char *y,int m,int n)
{
	if(m==0||n==0)
		return ;
	if(x[m]==y[n]){
		print_lcs_without_b(c,x,y,m-1,n-1);
		printf("%c ",x[m-1]);
	}else if(c[m-1][n]>=c[m][n-1]){
		print_lcs_without_b(c,x,y,m-1,n);
	}else
		print_lcs_without_b(c,x,y,m,n-1);
		
}
