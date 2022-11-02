#include <stdio.h>

int main(void) {
	char ch1, ch2, ch3;
	ch1 = getchar();
	ch2 = getchar();
	ch3 = getchar();

	/*
	putchar(ch3);
	putchar(ch2);
	putchar(ch1);
	putchar('\n'); */

	printf("ch1 = %c\n", ch1);
	printf("ch2 = %c\n", ch2);
	printf("ch3 = %c\n", ch3);

	return 0;
}