#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
 
void* pthread_do(void *arg)
{
	struct timespec ts, ts1;
	int count = 0;
	struct timeval tv1, tv2;
	  
	//ts.tv_nsec = 500000000;    // 1500ms
	ts.tv_nsec = 10; // 5000; // 500000000;    // 1500ms
	//ts.tv_nsec = 2000*1000; // 5000; // 500000000;    // 1500ms
	ts.tv_sec = 0;
	while( 1 )
    {
//		printf("sub pthread %d\n", count);
//		count++;
		gettimeofday(&tv1, NULL);
		printf("tv1.tv_sec=%ld, tv1.tv_usec=%ld\n", tv1.tv_sec, tv1.tv_usec);
		if ( nanosleep(&ts, &ts1) == -1 )
		{
			printf("error!\n");
			exit(1);
		}
		gettimeofday(&tv2, NULL);
		printf("tv2.tv_sec=%ld, tv2.tv_usec=%ld\n", tv2.tv_sec, tv2.tv_usec);
		printf("tv2.tv_usec-tv1.tv_usec=%ld\n", tv2.tv_usec-tv1.tv_usec);
	}
	return NULL;
}
   
int main(void)
{
	pthread_t pthd;
	int count = 0;
	     
	pthd = pthread_create(&pthd, NULL, pthread_do, NULL);
	     
	while ( 1 )
	{
		printf("main pthread %d\n", count);
		count++;
		sleep(1);
	}

	return 0;
}
