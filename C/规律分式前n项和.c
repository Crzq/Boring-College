#include <stdio.h>
#include <windows.h>

int main(void) {
	// 1 + 1/3 + 1/5 + ... 前 n 项和
	// n = 23
	double sum = 0;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		sum += 1.0 / (double)(2 * i + 1);
	}
	printf("%f", sum);
	system("pause");
	return 0;
}
