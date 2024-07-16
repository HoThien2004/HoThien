#include<stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

void nhapM1C_SoNguyen (int * &a, int &n)
{
	printf("Nhap so phan tu cua mang:");
	scanf("%d", &n);
	a = (int *)malloc(n*sizeof(int));
	for(int i = 0; i < n; i++)
		a[i]= rand()%100;
}

void xuatM1C_SoNguyen(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
	printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %x", i, a[i], a+i);
	}
}

void timMAX(int *a, int n)
{
	int *p;
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i]>=temp)
		{
			temp=a[i];
			p=&a[i];
		}
	}
	printf("Phan tu lon nhat la:%d - Dia chi cua no:%x\n", temp, p);
}

void timChan_Max(int *a, int n)
{
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i]%2==0)
		{
			if (a[i]>=temp)
			{
				temp=a[i];
			}
		}
	}
	printf("Chan Max la:%d\n", temp);
}

void timLe_Max(int *a, int n)
{
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i]%2!=0)
		{
			if (a[i]>temp)
			{
				temp=a[i];
			}
		}
	}
	printf("Le Max la:%d\n", temp);
}

void Xoa_PhanTu(int *a, int &n, int giatri)
{
	for (int i = 0; i < n; i++)
	{
		if (giatri==a[i])
		{
			for (int j = i; j < n; j++)
			{
				a[j] = a[j+1];
			}
			n--;
		}
	}
}

void them_PhanTu(int *a, int &n, int x)
{
	
	for (int i = n; i > 0; i--)
	{
		a[i]=a[i-1];
	}
	a[1]=x;
	n++;
}

int kiemTra_SoChinhPhuong(double a)
{
	int can = sqrt(a);
	if (can*can == a)
	{
		return 1;
	}
	return 0;
}

int sum_SCP(int *a, int n)
{
	int tong=0;
	for (int i = 0; i < n; i++)
	{
		if (kiemTra_SoChinhPhuong(a[i])==1)
		{
			tong+=a[i];
		}
	}
	return tong;
}

void xuat_SoCucDai(int *a, int n)
{
	printf("Cac so cuc dai la:\n");
	for (int i = 0; i < n; i++)
	{
		if (a[i] > a[i-1] && a[i] > a[i+1])
		{
			printf("%d ", a[i]);
		}
	}
}

int main()
{
	int *a, n;
	nhapM1C_SoNguyen(a, n);
	xuatM1C_SoNguyen(a, n);
	printf("\n-------------------------------------------\n");
	printf("Tim phan tu lon nhat\n");
	timMAX(a,n);
	printf("\n-------------------------------------------\n");
	printf("Tim phan tu CHAN lon nhat\n");
	timChan_Max(a,n);
	printf("\n-------------------------------------------\n");
	printf("Tim phan tu LE lon nhat\n");
	timLe_Max(a,n);
	printf("\n-------------------------------------------\n");
	printf("XOA PHAN TU co gia tri 0\n");
	Xoa_PhanTu(a,n,0);
	xuatM1C_SoNguyen(a,n);
	printf("\n-------------------------------------------\n");
	printf("\nThem Phan Tu x vao sau phan tu dau tien\n");
	int x;
	printf("Nhap gia tri x:");
	scanf("%d", &x);
	them_PhanTu(a,n,x);
	xuatM1C_SoNguyen(a,n);
	printf("\n-------------------------------------------\n");
	printf("Tong cac So CHINH PHUONG\n");
	printf("Ket Qua:%d", sum_SCP(a,n));
	printf("\n-------------------------------------------\n");
	printf("Xuat cac So CUC DAI\n");
	xuat_SoCucDai(a,n);
	getch();
}