/*  Compile : gcc pthread_bind_cpu.c -lpthread */

/*
//初始化，设为空
void CPU_ZERO (cpu_set_t *set); 
//将某个cpu加入cpu集中 
void CPU_SET (int cpu, cpu_set_t *set); 
//将某个cpu从cpu集中移出 
void CPU_CLR (int cpu, cpu_set_t *set); 
//判断某个cpu是否已在cpu集中设置了 
int CPU_ISSET (int cpu, const cpu_set_t *set); 
*/


#include <stdio.h>
#include <stdlib.h>
#define __USE_GNU
#include <pthread.h>
#include <unistd.h>


 
int GetCpuCount()
{
    return (int)sysconf(_SC_NPROCESSORS_ONLN);
}
 
void *thread_fun1()
{
    int i=20;
    while(i--)
    {
        printf("i1 = %d\n",i);
    }
 
    return NULL;
}
 
void *thread_fun2()
{
    int i=20;
    while(i--)
    {
        printf("i2 = %d\n",i);
    }
 
    return NULL;
}

/* 使用函数pthread_attr_setaffinity_np  */
int main2()
{
    int cpu_num = 0;
    cpu_num  = GetCpuCount();
    printf("The number of cpu is %d\n", cpu_num);
 
    pthread_t t1;
    pthread_t t2;
    pthread_attr_t attr1;
    pthread_attr_t attr2;
 
    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);
 
    cpu_set_t cpu_info;
    CPU_ZERO(&cpu_info);
    CPU_SET(4, &cpu_info);
    if (0!=pthread_attr_setaffinity_np(&attr1, sizeof(cpu_set_t), &cpu_info))
    {
        printf("set affinity failed");
        return;
    }
 
    CPU_ZERO(&cpu_info);
    CPU_SET(2, &cpu_info);
//    if (0!=pthread_attr_setaffinity_np(&attr2, sizeof(cpu_set_t), &cpu_info))
//    {
//        printf("set affinity failed");
//    }
 
    if (0!=pthread_create(&t1, &attr1, thread_fun, NULL))
    {
        printf("create thread 1 error\n");
        return;
    }
 
    if (0!=pthread_create(&t2, &attr2, thread_fun, NULL))
    {
        printf("create thread 2 error\n");
        return;
    }
 
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}



/* 使用函数pthread_setaffinity_np  */
int main()
{
    int cpu_num = 0;
    cpu_num  = GetCpuCount();
    printf("The number of cpu is %d\n", cpu_num);
 
    pthread_t t1;
    pthread_t t2;
    pthread_attr_t attr1;
    pthread_attr_t attr2;
 
    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);
 
    if (0!=pthread_create(&t1, &attr1, thread_fun1, NULL))
    {
        printf("create thread 1 error\n");
        return;
    }
 
    if (0!=pthread_create(&t2, &attr2, thread_fun2, NULL))
    {
        printf("create thread 2 error\n");
        return;
    }
 
    cpu_set_t cpu_info;
    CPU_ZERO(&cpu_info);
    CPU_SET(0, &cpu_info);
    if (0!=pthread_setaffinity_np(t1, sizeof(cpu_set_t), &cpu_info))
    {
        printf("set affinity failed");
    }
 
    CPU_ZERO(&cpu_info);
    CPU_SET(1, &cpu_info);
    if (0!=pthread_setaffinity_np(t2, sizeof(cpu_set_t), &cpu_info))
    {
        printf("set affinity failed");
    }
 
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}
