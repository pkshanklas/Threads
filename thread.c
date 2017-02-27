#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <unistd.h>
using namespace std;

long long sum = 0;

void* function(void *arg)
{
	long long limit = *((long long *)arg);
    long long c =0;
    while(c <= limit){
        sum += c;
        c++;
    }
	sleep(2);
    pthread_exit(0);
}

int main(int argc, char **argv)
{
	if(argc <2){
		std::cout<<"Number Required \n";
		exit(0);
	}
	long long limit = atoll(argv[1]);
    
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid,&attr,function,&limit);
	
    pthread_join(tid, NULL);
	cout<<sum<<endl;
    return 0;
}
