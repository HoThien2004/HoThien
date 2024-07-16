#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAXSIZE 100

void nhapDuLieu(char a[], char b[], int &c, int &d, int &e)
{
	printf("Nhap ho ten:");
	gets(a);
	printf("Nhap gioi tinh:");
	gets(b);
	printf("Nhap ngay-thang-nam:");
	scanf("%d %d %d", &c, &d, &e);
}

void xuatDuLieu(char a[], char b[], int &c, int &d, int &e)
{
	printf("Ho Ten:%s\n", a);
	printf("Gioi Tinh:%s\n", b);
	printf("Sinh Ngay: %d-%d-%d\n", c, d, e);
}

int xetTuoiLaoDong(int year)
{
	if (2024-year >= 18)
	{
		if (2024-year < 60 || 2024-year < 62)
		{
			return 0;
		}
	}
	return 1;
}

void tinhTuoiHuu(char a[], char b[], int day, int month, int year)
{
	int x, k;
	if (strcmp(b,"Nam")==1 || strcmp(b,"Nu")==1)
	{
		printf("Loi gioi tinh khong phu hop!!!");
		return;
	}

	if (xetTuoiLaoDong(year)==1)
	{
		printf("Khong du 18 hoac da qua tuoi nghi huu!!!");
		return;
	}
	else
	{	
		if (strcmp(b,"Nam")==0)
		{
			x = 62 - (2024-year);
		}
		else
		{
			x = 60 - (2024-year);
		}
		k = 2024 + x;
	}
	printf("Ho Ten: %d - Gioi Tinh:%d\n", a, b);
	printf("Ngay Sinh:%d-%d-%d", day,month,year);
	printf("Hien tai da %d Tuoi", 2024-year);
	printf("Se duoc nghi huu vao thang %d-%d", month, k);
}

int main()
{
	char hoTen[MAXSIZE];
	char gioiTinh[MAXSIZE];
	int day, month, year;
	nhapDuLieu(hoTen,gioiTinh,day,month,year);
	xuatDuLieu(hoTen,gioiTinh,day,month,year);
	tinhTuoiHuu(hoTen,gioiTinh,day,month,year);
	getch();
	return 0;
}