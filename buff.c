#include "minitalk.h"
#include <stdio.h>
int main(void)
{
	if ((7 & 0x80) == 0)
		printf("ascii");
	if ((191 & 0xC0) != 0 && (191 & 0x20) == 0)
		printf(" 2 bytes");
	if ((221 & 0xE0) != 0 && (191 & 0x10) == 0)
		printf(" 3 bytes");
	if ((230 & 0xF0) != 0 && (191 & 0x8) == 0)
		printf(" 4 bytes");
	return 0;
}
