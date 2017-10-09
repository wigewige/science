#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
 
 void* pthread_do(void *arg)
 {
     struct timespec ts, ts1;
	     int count = 0;
		  
		      ts.tv_nsec = 500000000;    // 1500ms
			      ts.tv_sec = 1;
				      while( 1 )
					      {
						          printf("sub pthread %d\n", count);
								          count++;
										          if ( nanosleep(&ts, &ts1) == -1 )
												          {
														              printf("error!\n");
																	              exit(1);
																				          }
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
