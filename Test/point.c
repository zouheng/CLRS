//test point in c
#include <stdio.h>
int main()
{
	int iArray[2][3] =        {{1,2,3},{4,5,6}};
	int **pArray = NULL;
    pArray = iArray;
    printf("array[0][0] = %d\n", pArray[0][0]);
    printf("array[1][2] = %d\n", pArray[1][2]);
    return 0;
}
