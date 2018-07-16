#include<stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
	int *p = (int*)0x001;
	int data = 0x001;
	printf("p = %p,p+1=%p \n", (double*)p, (double*)p + 1);
	printf("data = %#x,data+1=%#x\n", data, data + 1);
	printf("int p  = %d,int p +1=%d\n", (int)p, (int)p + 1);

	int arr[10];
	int *pHead = &arr[0];
	int *pEnd = &arr[9];
	int Head = (int)&arr[0];
	int End = (int)&arr[9];
	printf("pEnd = %p, pHead = %p\n", pEnd, pHead);
	printf("pEnd = %d, pHead = %d\n", pEnd ,pHead);
	printf("pEnd - pHead = %d\n", pEnd - pHead);
	printf("&End =%p, &Head = %p\n", &End ,&Head);
	printf("End - Head = %d\n", End - Head);

	getchar();
	return 0;
}
