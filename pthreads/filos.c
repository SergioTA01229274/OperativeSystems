#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define NUM_FILOSOFOS	5

pthread_mutex_t tenedores[NUM_FILOSOFOS];

void actividad(){
    sleep(1 + rand()%5);
}

void * vida(void * id){
    long tid;
    tid = (long)id;
    srand(time(NULL) + tid);
    while(1){
        //piensan
        actividad();
        printf("Soy el hilo %ld, y estoy pensando \n", tid);
        if(tid % 2 == 0){
        pthread_mutex_lock(&tenedores[tid]);
        pthread_mutex_lock(&tenedores[(tid + 1) % NUM_FILOSOFOS]);
        //Comer
        actividad();
        printf("Soy el hilo %ld, y voy a comer\n", tid);
        pthread_mutex_unlock(&tenedores[tid]);
        pthread_mutex_unlock(&tenedores[(tid + 1) % NUM_FILOSOFOS]);

        }else{
            pthread_mutex_lock(&tenedores[(tid + 1) % NUM_FILOSOFOS]);
            pthread_mutex_lock(&tenedores[tid]);
            //comer
            actividad();
            printf("Soy el hilo %ld, y voy a comer\n", tid);
            pthread_mutex_unlock(&tenedores[(tid + 1) % NUM_FILOSOFOS]);
            pthread_mutex_unlock(&tenedores[tid]);
        }
    }
}

int main(int argc, char *argv[])
{
   pthread_t threads[NUM_FILOSOFOS];
   int rc;
   long t;
   for(t=0;t<NUM_FILOSOFOS;t++){
     printf("In main: creating thread %ld\n", t);
     rc = pthread_create(&threads[t], NULL, vida, (void *)t);
     if (rc){
       printf("ERROR; return code from pthread_create() is %d\n", rc);
       exit(-1);
       }
     }

   /* Last thing that main() should do */
   pthread_exit(NULL);
}