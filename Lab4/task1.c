#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct{
    int id;
    char message[20];
}data;

void *no_arg(void *arg){
    printf("无参数\n");
    pthread_exit(NULL);
}

void *int_arg(void *arg){
    int val =*((int*)arg);
    printf("参数为整型，内容为%d\n",val);
    pthread_exit(NULL);
}

void *struct_arg(void *arg){
    data val=*((data*)arg);
    printf("参数为结构体，id为%d，内容为%s\n",val.id,val.message);
    pthread_exit(NULL);
}

int main(){
    pthread_t t1,t2,t3;
    int int_val=0;
    data struct_val={1, "Hello world!"};
    pthread_create(&t1,NULL,no_arg,NULL);
    pthread_create(&t2,NULL,int_arg,(void*)&int_val);
    pthread_create(&t3,NULL,struct_arg,(void*)&struct_val);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    printf("所有线程已结束，主线程退出。\n");
    return 0;
}