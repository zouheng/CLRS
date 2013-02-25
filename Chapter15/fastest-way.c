//code for 15.1
//assume  exist 2 working line
#include <malloc.h>
#include <stdio.h>
typedef struct _Result
{
	int **f;
	int **l;
	int fn;
	int ln;
	int n;
}Result;
Result fastest_way(int **a,int**t,int e[],int x[],int n);
void print_stations(int **l,int ln,int n);
int main()
{
	int a1[]={7,9,3,4,8,4};
    int a2[]={8,5,6,4,5,7};	
	int *a[2];
	a[0]=&a1[0];
	a[1]=&a2[0];
	int t1[]={2,3,1,3,4};
	int t2[]={2,1,2,2,1};
	int *t[2];
	t[0]=&t1[0];
	t[1]=&t2[0];
	int e[]={2,4};
	int x[]={3,2};
	Result result;
	result=fastest_way(a,t,e,x,6);
	printf("the result is %d\n",result.fn);
	printf("the result ln is %d\n",result.ln);
	print_stations(result.l,result.ln,6);
}
Result fastest_way(int **a,int**t,int* e,int* x,int n)
{
	Result result;
	//init 
	result.n=n;
	result.f=(int **)malloc(sizeof(int*)*2);
	int i;
	for(i=0;i<2;i++){
		result.f[i]=(int*)malloc(sizeof(int)*n);
	}
	result.l=(int **)malloc(sizeof(int*)*2);
	for(i=0;i<2;i++){
		result.l[i]=(int*)malloc(sizeof(int)*n);
	}
	//first
	result.f[0][0]=a[0][0]+e[0];
	result.f[1][0]=a[1][0]+e[1];
	printf("f[0][0]=%d\n",result.f[0][0]);
	printf("f[1][0]=%d\n",result.f[1][0]);
	//caculate f[1][2...n],f[2][2...n]
	for(i=1;i<=n-1;i++){
		if(result.f[0][i-1]<=result.f[1][i-1]+t[1][i-1]){
			result.f[0][i]=result.f[0][i-1]+a[0][i];
			result.l[0][i]=0;
		}else{
			result.f[0][i]=result.f[1][i-1]+t[1][i-1]+a[0][i];
			result.l[0][i]=1;
		}
		printf("f[0][%d]=%d\n",i,result.f[0][i]);
		printf("l[0][%d]=%d\n",i,result.l[0][i]);
		if(result.f[1][i-1]<=result.f[0][i-1]+t[0][i-1]){
			result.f[1][i]=result.f[1][i-1]+a[1][i];
			result.l[1][i]=1;
		}else{
			result.f[1][i]=result.f[0][i-1]+t[0][i-1]+a[1][i];
			result.l[1][i]=0;
		}
		printf("f[1][%d]=%d\n",i,result.f[1][i]);
		printf("l[1][%d]=%d\n",i,result.l[1][i]);
	}
	if(result.f[0][n-1]+x[0]<=result.f[1][n-1]+x[1]){
		result.fn=result.f[0][n-1]+x[0];
		result.ln=0;
	}
	else{
		result.fn=result.f[1][n-1]+x[1];
		result.ln=1;
	}
	printf("fn=%d\n",result.fn);
	return result;
}
//normal version
/*
void print_stations(int **l,int ln,int n)
{
	int i;
	int line=ln;
	printf("line %d,station %i\n",line+1,n);
	for(i=n;i>=2;--i){
		line=l[line][i-1];
		printf("line %d,station %i\n",line+1,i-1);
	}
}*/
//printf in asce order
void print_stations(int **l,int ln,int n)
{
	if(n<=0)
		return;
	print_stations(l,l[ln][n-1],n-1);
	printf("line %d,station %d\n",ln+1,n);
}

