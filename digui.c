#include "stdio.h"

void f(int n)
{
	if(!n)
		return;
	
	printf("%d",n&0x1);
	n=n>>1;
	f(n);
}

void msb_f(int n)
{
	int i;
	/*
	for(i=0;i<32;i++)
	{
		printf("%d",n>>31&0x1);
		n=n<<1;
	}
	*/

	for(i=31;i>=0;i--)
	{
		printf("%d",n>>i&0x1);
	}
	return;
}



int main()
{
	printf("hello world.\n");

	int n=4;
	printf("lsb_f: 0b");
	f(n);
	printf("\n");
	printf("end\n");


	n=4;
	printf("n: %d\n",n);
	printf("msb_f: 0b");
	msb_f(n);
	printf("\n");
	printf("end\n");

	//n=-4;
	n=n<<1;
	printf("n: %d\n",n);
	printf("msb_f: 0b");
	msb_f(n);
	printf("\n");
	printf("end\n");


	//n=-4;
	n=n>>1;
	printf("n: %d\n",n);
	printf("msb_f: 0b");
	msb_f(n);
	printf("\n");
	printf("end\n");



	n=-1;
	printf("n: %d\n",n);
	printf("msb_f: 0b");
	msb_f(n);
	printf("\n");
	printf("end\n");


	//n=-2;
	n=n<<2;
	printf("n: %d\n",n);
	printf("msb_f: 0b");
	msb_f(n);
	printf("\n");
	printf("end\n");



	//n=-4;
	n=n<<1;
	printf("n: %d\n",n);
	printf("msb_f: 0b");
	msb_f(n);
	printf("\n");
	printf("end\n");


	//n=-4;
	n=n>>4;
	printf("n: %d\n",n);
	printf("msb_f: 0b");
	msb_f(n);
	printf("\n");
	printf("end\n");



#if 0
	n=-4;
	printf("0b");
	//f(n);
	printf("\n");
	printf("end\n");
	
	n=0xffff;
	printf("0b");
	f(n);
	printf("\n");
	printf("end\n");

	n=0xffffffff;
	printf("0b");
	f(n);
	printf("\n");
	printf("end\n");


	n=0x5AA5A55A;
	printf("0b");
	f(n);
	printf("\n");
	printf("end\n");
#endif

	return 0;
}
