#include <stdio.h>
#include <math.h>
#include <iostream>
int Evklid(int a, int b)
{
	int k = 1;
	while (a != 0 && b != 0)
	{
		while (a % 2 == 0 && b % 2 == 0)
		{
			a = a / 2;
			b = b / 2;
			k = k * 2;
		}
		while (a % 2 == 0)
			a = a / 2;
		while (b % 2 == 0)
			b = b / 2;
		if (a >= b)
			a = a - b;
		else
			b = b - a;
	}
	return b * k;
}
int main(void) {
	setlocale(LC_ALL, "\0");
	const double PI = 3.1415926;
	int z, n,up,down,g,k,i=1;
	double angle_pi, q=0,angle;
	scanf_s("%d%d", &z, &n);
	q = sqrt(z * z + n * n);
	if (z == 0 || n==0)
	{
		if (n == 0)
		{
			printf("%lf\n", q);
		}
		else
		if (z == 0)
		{
			printf("%lfi\n", q);
		}
	}
	else
	{
		if (z > 0)
		{
			angle = atan(n / z)*180/PI;
		}
		else if (n > 0)
		{
			angle = 180 + atan(n / z)*180/PI;
		}
		else
		{
			angle = atan(n / z)*180/PI - 180;
		}
		if (angle < 0)
		{
			angle = angle + 360;
		}
		up = 1000000;
		angle_pi = 180 / angle;
		down = round(angle_pi * up);
		k = Evklid(up, down);
		up = up / k;
		down = down / k;
		printf("%lf(cos PI %d/%d + i sin PI %d/%d)\n", q, up, down, up, down);
		if (n < 0)
		{
			i = -1;
		}
		if (i == 1)
		{
			printf("%lf - i %lf\n", z / q, n / q);
		}
		else
		{
			printf("%lf + i %lf\n", z / q, n / q);
		}
		printf("¬ведите степень, в которую желаете возвести комлексное число:\n");
		scanf_s("%d", &g);
		k = Evklid(down, g);
		down = down / k;
		g = g / k;
		printf("%lf(cos PI %d/%d + i sin PI %d/%d)\n", powl(q, g), up * g, down, up * g, down);
		printf("¬ведите степень корн€:\n");
		scanf_s("%d", &g);
		up = up * 1000000;
		g = g * 1000000;
		k = Evklid(up, g);
		up = up / k;
		g = g / k;
		printf("%lf(cos PI %d/%d + i sin PI %d/%d)\n", powl(q, 1 / (double)g), up, down * g, up, down * g);
		if (g % 2 == 0)
		{
			printf("-%lf(cos PI %d/%d + i sin PI %d/%d)\n", powl(q, 1 / (double)g), up, down * g, up, down * g);
		}
	}
	return 0;
}