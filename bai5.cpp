#include <stdio.h>

int main()
{
	int a, b, c;
	float d;

	printf("Nhap a: ");
	scanf_s("%d", &a);
	printf("Nhap b: ");
	scanf_s("%d", &b);
	printf("Nhap c: ");
	scanf_s("%d", &c);

	d = (float)c / (a - b);
	printf("Ket qua la: %f\n", d);
	return 0;
}