#include <stdio.h>
void test(int **a)
{
}
void test1(int (*a)[5])
{

}
void test2(int *a[5])
{

}
void test3(int a[5][5])
{

}
int main()
{
	int a[2][3][5];
	int (*r)[5]=a[0];
	int *t=a[0][0];
	printf("r=%x\n",r);
	printf("++r=%x\n",++r);
	printf("t=%x\n",t);
	printf("++t=%x\n",++t);
	int b[2][5];
	int *c[5];
	test(c);
	test1(b);
	//test3(b);
	int d[2][6];
	test3(d);
}
