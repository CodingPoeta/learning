#include <emmintrin.h>
#include <x86intrin.h>
#include <stdint.h>
#include <stdio.h> 

//#define uint8_t char
//#define uint64_t long

uint8_t arr[10*4096];

int main(int argc, char const *argv[])
{
	unsigned int junk = 0;
	register uint64_t time1, time2;
	volatile uint8_t *addr;
	int i;

	// init arr
	for (i = 0; i < 10; i++) arr[i*4096] = 1;

	// flush arr from cache
	for (i = 0; i < 10; i++) _mm_clflush(&arr[i*4096]);

	// access some of the array items
	arr[3*4096] = 100;
	arr[7*4096] = 200;

	// printf("%d\n",arr[7*4096]);

	for (i = 0; i < 10; i++)
	{
		addr = &arr[i*4096];
		time1 = __rdtscp(&junk);
		junk = *addr;
		time2 = __rdtscp(&junk) - time1;
		printf("Access time for array[%d*4096]: %d CPU cycles\n",i, (int)time2);
	}
	return 0;
}