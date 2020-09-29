#include <stdio.h>
#include <math.h>
const double PI = 3.1415926;
int Evklid(int a, int b)
{
	if (b > a)
	{
		int c = a;
		a = b;
		b = c;
	}
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
double norm(int z, int n)
{
	double angle;
	if (z > 0)
	{
		angle = atan(n / z) * 180 / PI;
	}
	else if (n > 0)
	{
		angle = 180 + atan(n / z) * 180 / PI;
	}
	else
	{
		angle = atan(n / z) * 180 / PI - 180;
	}
	if (angle < 0)
	{
		angle = angle + 360;
	}
	return angle;
}
int main()
{
	int z, n, up, down, g, k, i = 1, t, down1, up1, g1;
	double angle_pi, q = 0, angle;
	printf("Enter a and b:\n");
	scanf_s("%d%d", &z, &n);
	q = sqrt(z * z + n * n);
	if (z == 0 || n == 0)
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
		t = 0;
	}
	else
	{
		angle = norm(z, n);
		up = 1000000;
		angle_pi = 180 / angle;
		down = round(angle_pi * up);
		k = Evklid(up, down);
		up = up / k;
		down = down / k;
		printf("%lf(cos PI %d/%d + i sin PI %d/%d)\n", q, up, down, up, down);
		printf("%lf\n", (double)up / down);
		t = 1;
	}
	if (t == 1)
	{
		if (n > 0)
		{
			printf("%lf - i %lf\n", z / (q * q), n / (q * q));
		}
		else
		{
			printf("%lf + i %lf\n", z / (q * q), fabs(n / (q * q)));
		}
		printf("enter the degree of the number:\n");
		scanf_s("%d", &g);
		k = Evklid(down, g);
		down1 = down / k;
		g = g / k;
		printf("%lf(cos PI %d/%d + i sin PI %d/%d)\n", powl(q, g), up * g, down1, up * g, down1);
		printf("%lf\n", ((double)up * g) / down1);
		printf("Enter the degree of the root:\n");
		scanf_s("%d", &g);
		int p = g;
		g = g;
		for (i = 0; i < p; i++)
		{
			up1 = (up + 2 * down * i);
			k = Evklid(up1, g);
			up1 = up1 / k;
			g1 = g / k;
			printf("%lf(cos PI %d/%d + i sin PI %d/%d)\n", powl(q, 1 / (double)g), up1, down * g1, up1, down * g1);
			printf("%lf \n", (double)up1 / (down * g1));
		}
	}
	if(t==0)
	{
		int p = 1;
		printf("enter the degree of the number:\n");
		scanf_s("%d", &g);
		if (g % 2 == 0)
			p == -1;
		printf("%lf", p*(pow(q, g)));
		if(n!=0 && p==1)
			printf("i");
		printf("\n");
		printf("Enter the degree of the root:\n");
		scanf_s("%d", &g);
		printf("%lf", p * (pow(q, 1/(double)g)));
		if (n != 0)
			printf("pow(i,1/%d",g);
	}
	return 0;
}