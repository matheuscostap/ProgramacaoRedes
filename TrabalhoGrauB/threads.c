#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/*thread function definition*/
int threadCount = 0;
void* threadFunction(void* args)
{
    int numero = threadCount;
    while(1)
    {
        sleep(1);
        printf("Thread %d.\n", numero);
    }
}

int main()
{
    /*creating thread id*/
    pthread_t id;
    int ret;
    int input;

    while(1)
    {
        sleep(1);
        printf("Digite 1 para criar uma thread.\n");
        scanf("%d", &input);

        if(input == 1){
          /*creating thread*/
          ret=pthread_create(&id,NULL,&threadFunction,NULL);
          if(ret==0){
              printf("Thread created successfully.\n");
              threadCount++;
          }else{
              printf("Thread not created.\n");
              return 0; /*return from main*/
          }
        }
    }

    return 0;
}
