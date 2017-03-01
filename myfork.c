#include <stdio.h>
#include <string.h>
#include <unistd.h>

void childProcess()
{
	int count;
	for(count =0;count<10;count++){
		printf("Child Process: %d\n", count);
		sleep(1);
	}
}

void parentProcess()
{
	int count;
	for(count =0;count<20;count++){
		printf("Parent Process: %d\n", count);
		sleep(1);
	}
}

int main()
{
	int childPID;
	printf("Before Calling the Fork: \n");
	
	childPID = fork();
	sleep(12);

	if( childPID == 0 ){
		childProcess();
	}else{
		parentProcess();
	}

	return 0;
}
