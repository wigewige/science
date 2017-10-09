#include <stdio.h>


int main(void)
{
	int sample=8000;
	int value=1;

	printf("value=%d,sample=%d\n",value,sample);
	value=htonl(sample);
	//value=htons(sample);

	printf("value=%d,sample=%d\n",value,sample);






}
