#include <stdio.h>
void declare_array(char a[])
{
	printf("in function declare_array\n");
	printf("&a=%x\n",&a);
	printf("&(a[0])=%x\n",&(a[0]));
	printf("&(a[1])=%x\n",&(a[1]));
}
void declare_point(char*a)
{
	printf("in function declare_point\n");
	printf("&a=%x\n",&a);
	printf("&(a[0])=%x\n",&(a[0]));
	printf("&(a[1])=%x\n",&(a[1]));
	printf("++a=%x\n",++a);
}
int main()
{
	char a[]={'a','b','c','d'};
	printf("out function\n");
	printf("&a=%x\n",&a);
	printf("&(a[0])=%x\n",&(a[0]));
	printf("&(a[1])=%x\n",&(a[1]));
	declare_array(a);
	declare_point(a);
	return 0;
}
