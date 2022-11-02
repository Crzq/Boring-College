#include <stdio.h>

int main(void) {
	int a, b, t;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("a = %d, b = %d\n", a, b);
	t = a; a = b; b = t;
	printf("a = %d, b = %d\n", a, b);

	return 0;
}