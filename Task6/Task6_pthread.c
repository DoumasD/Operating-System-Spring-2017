// Demetrios Doumas   Task6    4/28/17
//  Cigarette Smoker's Problem soluion using pThreads libraries 
// Run command gcc Task6_pthread.c -lpthread to complie code
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<signal.h>
#include<pthread.h>

// Create individual functions for each threads
void *AGENT_function(void *ptr);
void *SMOKERONE_function(void *ptr);
void *SMOKERTWO_function(void *ptr);
void *SMOKERTHREE_function(void *ptr);


//Mutex threads to replace semaphores


pthread_mutex_t smoker_match =PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t smoker_tobacco=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t smoker_paper=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t agent=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;






void main()
{

   pthread_t AGENT, SMOKERONE, SMOKERTWO, SMOKERTHREE; //four threads
   int iter1, iter2, iter3, iter4;
 




// Initalize Mutex variables

pthread_mutex_init(&smoker_match,NULL);
pthread_mutex_lock(&smoker_match);

pthread_mutex_init(&smoker_tobacco,NULL);
pthread_mutex_lock(&smoker_tobacco);

pthread_mutex_init(&smoker_paper,NULL);
pthread_mutex_lock(&smoker_paper);

pthread_mutex_init(&agent,NULL);
pthread_mutex_lock(&agent);

pthread_mutex_init(&lock,NULL);// lock==1
pthread_mutex_unlock(&lock);

   // Create threads and check them
   iter1 =pthread_create(&AGENT,NULL, &AGENT_function,NULL);
   if(iter1)
   {
	fprintf(stderr,"Error - pthread_create() return code: %d\n", iter1);
	exit(EXIT_FAILURE);
   }
   iter2 =pthread_create(&SMOKERONE,NULL, &SMOKERONE_function, NULL);
    if(iter2)
   {
	fprintf(stderr,"Error - pthread_create() return code: %d\n", iter2);
	exit(EXIT_FAILURE);
   }
   iter3 =pthread_create(&SMOKERTWO,NULL, &SMOKERTWO_function,NULL);
    if(iter3)
   {
	fprintf(stderr,"Error - pthread_create() return code: %d\n", iter3);
	exit(EXIT_FAILURE);
   } 
   iter4 =pthread_create(&SMOKERTHREE,NULL, &SMOKERTHREE_function,NULL);
     if(iter4)
   {
	fprintf(stderr,"Error - pthread_create() return code: %d\n", iter4);
	exit(EXIT_FAILURE);
   } 


  //wait for other threads before terminating the program
   pthread_join(AGENT, NULL);
   pthread_kill(SMOKERONE,SIGTERM);
   pthread_kill(SMOKERTWO,SIGTERM);
   pthread_kill(SMOKERTHREE, SIGTERM);

   exit(EXIT_SUCCESS);

}



void *AGENT_function(void *ptr)
{
	 time_t t;
	   int randNum;
	   srand((unsigned) time(&t));
	   
	    int c=0;
	    
		    while(c<10) {
		      pthread_mutex_lock(&lock);
		      randNum = (rand()%3) +1; // Pick a random number from 1-3
		      printf("Random number is:%d \n", randNum);
		      if ( randNum == 1 ) {
			 // Put tobacco on table
			 // Put paper on table
			 printf("Agent put tabacco on table. \n");
			 printf("Agent put paper on table. \n");
			 pthread_mutex_unlock( &smoker_match );  // Wake up smoker with match
		       } else if ( randNum == 2 ) {
			 // Put tobacco on table
			// Put match on table
			printf("Agent put tabacco on table. \n");
			printf("Agent put match on table. \n");
			pthread_mutex_unlock( &smoker_paper );  // Wake up smoker with paper
		      } else {
			// Put match on table
			// Put paper on table
			 printf("Agent put match on table. \n");
			 printf("Agent put paper on table. \n");
			pthread_mutex_unlock( &smoker_tobacco ); } // Wake up smoker with tobacco
		      
		      pthread_mutex_unlock(&lock);
		      pthread_mutex_lock(&agent);  //  Agent sleeps
		      c++;
		     }  // end forever loop

}


void *SMOKERONE_function(void *ptr)
{

  int c=0;
  while(c<10) {
       pthread_mutex_lock( &smoker_tobacco );  // Sleep right away
       pthread_mutex_lock( &lock );
       // Pick up match
       // Pick up paper
       printf("Smoker1 picks up match. \n");
       printf("Smoker1 picks up paper. \n");
       printf("Smoker1 smokes. \n");
       sleep(3); //sleep for 3 seconds
        pthread_mutex_unlock( &agent );
       pthread_mutex_unlock( &lock );
       // Smoke (but don't inhale).
	c++;
    }
}
void *SMOKERTWO_function(void *ptr)
{

   int c=0;
   while(c<10) {
       pthread_mutex_lock( &smoker_match );  // Sleep right away
       pthread_mutex_lock( &lock );
       // Pick up tobacc0
       // Pick up paper
       printf("Smoker2 picks up tobacco. \n");
       printf("Smoker2 picks up paper. \n");
       printf("Smoker2 smokes. \n");
       sleep(3); //sleep for 3 seconds
       pthread_mutex_unlock( &agent );
       pthread_mutex_unlock( &lock );
       // Smoke (but don't inhale).
       c++;
 }

}

void *SMOKERTHREE_function(void *ptr)
{
 int c=0;
    while(c<10) { 
       pthread_mutex_lock( &smoker_paper );  // Sleep right away
       pthread_mutex_lock( &lock );
       // Pick up tobacco
       // Pick up match
       printf("Smoker3 picks up tobacco. \n");
       printf("Smoker3 picks up match. \n");
       printf("Smoker3 smokes. \n");
       sleep(3); //sleep for 3 seconds
       pthread_mutex_unlock( &agent );
       pthread_mutex_unlock( &lock );
       // Smoke (but don't inhale).
       c++;
 }
}
