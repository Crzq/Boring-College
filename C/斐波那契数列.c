#include <stdio.h>

int main(void) {
    // 1 1 2 3 5 8 13 ...
    int f1 = 1, f2 = 1, f3;
	for (int i = 2; i < 30; ++i) {
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
		printf("%d\t", f3);
	}
	return 0;
}
