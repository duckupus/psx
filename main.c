#include <stdio.h>
#include <unistd.h>
#include "processes.h"

int main() {
	chdir("/proc");
	printf("%lu\n", processAmount());
	return 0;
}
