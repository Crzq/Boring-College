#include <stdio.h>
#include <math.h>

int main(void) {
	float a, b, c, x1, x2;
	LOOP: scanf("%f %f %f", &a, &b, &c);
	if ((b * b) < (4 * a * c)) {
		printf("b^2 should greater or equal than 4ac");
		goto LOOP;
	}
	printf("x1 = %f\n", (-b + sqrt(b * b - 4 * a * c)) / (2 * a));
	printf("x1 = %f\n", (-b - sqrt(b * b - 4 * a * c)) / (2 * a));
	return 0;
}