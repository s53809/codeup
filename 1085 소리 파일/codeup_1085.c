#include <stdio.h>
int main() {
	double a, b, c, d, e = 0;
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	e = (a * b * c * d) / 8;
	e = e / (1024 * 1024);
	printf("%.1f MB\n", e);
}