// Demetrios Doumas   Task6    4/28/17
//  Cigarette Smoker's Problem soluion using semaphore
// http://www.cs.umd.edu/~hollings/cs412/s96/synch/smokers.html pusedo code 

#include"sem.h"
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<signal.h>

#define PERMS 0666 //0666 - To grant read and write permissions

int main()
{

int Agent, Smoker1, Smoker2, Smoker3;  /// Four processes
int pid_childOne, pid_childTwo,pid_childThree,pid_childFour;//wait status
int lock, smoker_paper, smoker_tobacco, smoker_match, agent; // binary semaphore 
int status1, status2,status3,status4;
pid_t pidSmoker1, pidSmoker2, pidSmoker3, pidAgent;


// Create semaphores


 if((lock=semget(IPC_PRIVATE,1,PERMS | IPC_CREAT)) == -1)
 {
   printf("\n can't create lock semaphore");
   exit(1);
 }

if((smoker_paper=semget(IPC_PRIVATE,1,PERMS | IPC_CREAT)) == -1)
 {
   printf("\n can't create smoker_paper semaphore");
   exit(1);
 }


if((smoker_tobacco=semget(IPC_PRIVATE,1,PERMS | IPC_CREAT)) == -1)
 {
   printf("\n can't create smoker_tobacco semaphore");
   exit(1);
 }

if((smoker_match=semget(IPC_PRIVATE,1,PERMS | IPC_CREAT)) == -1)
 {
   printf("\n can't create smoker_match semaphore");
   exit(1);
 }

if((agent=semget(IPC_PRIVATE,1,PERMS | IPC_CREAT)) == -1)
 {
   printf("\n can't create agent semaphore");
   exit(1);
 }




// Initialize Semaphores
sem_create(smoker_match,0);
sem_create(smoker_tobacco,0);
sem_create(smoker_paper,0);
sem_create(agent,0);
sem_create(lock,1);


 





 Smoker1=fork();
 pidSmoker1 = getpid();
 
 if(Smoker1==0)
 {
 
  int c=0;
  while(c<10) {
       P( smoker_tobacco );  // Sleep right away
       P( lock );
       // Pick up match
       // Pick up paper
       printf("Smoker1 picks up match. \n");
       printf("Smoker1 picks up paper. \n");
       printf("Smoker1 smokes. \n");
       sleep(3); //sleep for 3 seconds
       V( agent );
       V( lock );
       // Smoke (but don't inhale).
	c++;
    }
 }
 Smoker2=fork();
 pidSmoker2 = getpid(); 

if(Smoker2==0)
 {
  
   int c=0;
   while(c<10) {
       P( smoker_match );  // Sleep right away
       P( lock );
       // Pick up tobacc0
       // Pick up paper
       printf("Smoker2 picks up tobacco. \n");
       printf("Smoker2 picks up paper. \n");
       printf("Smoker2 smokes. \n");
       sleep(3); //sleep for 3 seconds
       V( agent );
       V( lock );
       // Smoke (but don't inhale).
       c++;
 }
}



 Smoker3=fork();
 //pidSmoker3 = getpid(); 
if(Smoker3==0)
 {
    
    int c=0;
    while(c<10) { 
       P( smoker_paper );  // Sleep right away
       P( lock );
       // Pick up tobacco
       // Pick up match
       printf("Smoker3 picks up tobacco. \n");
       printf("Smoker3 picks up match. \n");
       printf("Smoker3 smokes. \n");
       sleep(3); //sleep for 3 seconds
       V( agent );
       V( lock );
       // Smoke (but don't inhale).
       c++;
 	}
}


////////////////////////////////////The agent

   time_t t;
   int randNum;
   srand((unsigned) time(&t));
   
    int c=0;
    
	    while(c<10) {
	     P( lock );
	      randNum = (rand()%3) +1; // Pick a random number from 1-3
	      printf("Random number is:%d \n", randNum);
	      if ( randNum == 1 ) {
		 // Put tobacco on table
		 // Put paper on table
		 printf("Agent put tabacco on table. \n");
		 printf("Agent put paper on table. \n");
		 V( smoker_match );  // Wake up smoker with match
	       } else if ( randNum == 2 ) {
		 // Put tobacco on table
		// Put match on table
		printf("Agent put tabacco on table. \n");
		printf("Agent put match on table. \n");
		V( smoker_paper );  // Wake up smoker with paper
	      } else {
		// Put match on table
		// Put paper on table
		 printf("Agent put match on table. \n");
		 printf("Agent put paper on table. \n");
		V( smoker_tobacco ); } // Wake up smoker with tobacco
	      V( lock );
	      P( agent );  //  Agent sleeps
	      c++;
	
	     }  // end forever loop

	kill(Smoker1, SIGKILL);
	kill(Smoker2, SIGKILL);
	kill(Smoker3, SIGKILL);
        printf("All processs exited:\n");

return 0;
}
