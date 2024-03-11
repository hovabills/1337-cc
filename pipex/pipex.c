#include <stdio.h>
//#include <sys/types.h>

int main()
{
	int fds[2];
	pipe(fds);
	fork(NULL);
}
