
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

void THTT(float *a, float *b)
{
	double tong = *a+*b;
	double hieu = *a-*b;
	double tich = (*a)*(*b);
	double thuong = (*a)/(*b);
	printf("Tong:%.2f - Dia chi:%x\n", tong, &tong);
	printf("Hieu:%.2f - Dia chi:%x\n", hieu, &hieu);
	printf("Tich:%.2f - Dia chi:%x\n", tich, &tich);
	printf("Thuong:%.2f - Dia chi:%x\n", thuong, &thuong);
}

int main()
{
	float a = 5.7, b = 4.8;
	float *pa = &a;
	float *pb = &b;
	printf("\nDia chi cua a: %x", pa);
	printf("\nDia chi cua b: %x", pb);
	printf("\n--------------------------------\n");
	THTT(pa,pb);
	getch();
	return 0;
}
