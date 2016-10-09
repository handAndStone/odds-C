/*
	setitimer() 不支持在同一进程中同时使用多次以支持多个定时器。
	linux有关定时器（setitimer）的叙述是这样的：  
	linux系统给每个进程提供了3个定时器，每个定时器在各自不同的域里面计数。当任何一个timer计数到结束了，系统就发送一个信号（signal）给该进程，同时计数器重置.
	一共支持以下3中计数器形式：  
  　ITIMER_REAL   在real time中计数器减1，然后等计数往比后发送SIGALRM信号。  
  　ITIMER_VIRTUAL   当进程在执行的过程中计数，然后当计数完毕后发送SIGVTALRM信号给该进程。  
  　ITIMER_PROF   在该进程被执行和系统在代表该进程执行的时间都进行计数.


功能描述：
获取或设定间歇计时器的值。系统为进程提供三种类型的计时器，每一类以不同的时间域递减其值。当计时器超时，信号被发送到进程，之后计时器重启动。

用法：
int getitimer(int which, struct itimerval *value);
int setitimer(int which, const struct itimerval *value, struct itimerval *ovalue);
 
参数：
which：间歇计时器类型，有三种选择
ITIMER_REAL //数值为0，计时器的值实时递减，发送的信号是SIGALRM。
ITIMER_VIRTUAL //数值为1，进程执行时递减计时器的值，发送的信号是SIGVTALRM。
ITIMER_PROF //数值为2，进程和系统执行时都递减计时器的值，发送的信号是SIGPROF。
value，ovalue：时间参数，原型如下
struct itimerval
{
                struct timeval it_interval;
                struct timeval it_value;   
 };
struct timeval
{
                long tv_sec;               
                long tv_usec;              
};
getitimer()用计时器的当前值填写value指向的结构体。
setitimer()将value指向的结构体设为计时器的当前值，如果ovalue不是NULL，将返回计时器原有值。

返回说明：
成功执行时，返回0。失败返回-1，errno被设为以下的某个值
EFAULT：value或ovalue是不有效的指针
EINVAL：其值不是ITIMER_REAL，ITIMER_VIRTUAL 或 ITIMER_PROF之一
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/time.h>
#include <errno.h>

void PrintMsg(int Num)
{
    printf("%s\n", "Hello World");

    return;
}

int main(int argc, char* argv[])
{
    signal(SIGALRM, PrintMsg);

    struct itimerval tick;
    tick.it_value.tv_sec = 10;  //十秒钟后将启动定时器
    tick.it_value.tv_usec = 0;
    tick.it_interval.tv_sec  =1; //定时器启动后，每隔1秒将执行相应的函数
    tick.it_interval.tv_usec = 0;

    //setitimer将触发SIGALRM信号
    int ret = setitimer(ITIMER_REAL, &tick, NULL);

    if ( ret != 0)
    {
        printf("Set timer error. %s \n", strerror(errno) );

        return -1;
    }

    printf("Wait!\n");

    getchar();

    return 0;
}
