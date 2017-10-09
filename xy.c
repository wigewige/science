#include <stdio.h>


int main(void)
{

	float i=-0.96,j=-0.94;
	int x = (1.0 + i) * ((float)100) / 2.0;
	int y = (1.0 - j) * ((float)100) / 2.0;

	printf("i=%f,j=%f,x=%d,y=%d\n",i,j,x,y);


	return 0;
}
