#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct{
    int val;
    long long res;
}data;
void* lowHalf(void* arg){
    data* val=(data*)arg;
    for(int i=1; i<=val->val/2; i++){
        val->res+=i;
    }
    pthread_exit(NULL);
}
void* highHalf(void* arg){
    data* val=(data*)arg;
    for(int i=val->val/2+1;i<=val->val; i++){
        val->res+=i;
    }
    pthread_exit(NULL);
}

int main(){
    int n;long long res=0;
    scanf("%d",&n);
    data l,h;
    l.res=0;h.res=0;l.val=n;h.val=n;
    struct timeval start,end;
    gettimeofday(&start,NULL);
    for(int i=1; i<=n; i++){
        res+=i;
    }
    gettimeofday(&end,NULL);
    double time_use = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("单线程结果：%lld；用时：%lf\n",res, time_use);

    gettimeofday(&start, NULL);
    pthread_t t1,t2;
    pthread_create(&t1,NULL, lowHalf,(void*)&l);
    pthread_create(&t2, NULL, highHalf, (void*)&h);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    res=l.res+h.res;
    gettimeofday(&end,NULL);
    time_use = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("双线程结果：%lld；用时：%lf\n",res, time_use);
    return 0;
}