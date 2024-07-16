
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 100


struct PhanSo
{
	int tu, mau;
};

void nhap_PhanSo(PhanSo a[], int &n)
{
	printf("Nhap so luong phan tu:");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("---Nhap phan so thu %d---\n", i);
		printf("Nhap tu so:"); scanf("%d", &a[i].tu);
		printf("Nhap mau so:"); scanf("%d", &a[i].mau);
		while (a[i].mau==0)
		{
			printf("Mau so phai khac 0!!! Vui long nhap lai!!!\n");
			printf("Nhap tu so:"); scanf("%d", &a[i].tu);
			printf("Nhap mau so:"); scanf("%d", &a[i].mau);
		}
		if (a[i].mau<0)
		{
			a[i].mau = -a[i].mau;
			a[i].tu = -a[i].tu;
		}
	}
}

void xuat_PhanSo(PhanSo a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i].tu==0)
		{
			printf("Phan so thu %d: 0", i);
		}
		else if (a[i].mau==1)
		{
			printf("Phan so thu %d: %d", i, a[i].tu);
		}
		else if (a[i].mau<0)
		{
			printf("Phan so thu %d: -%d/%d", i, a[i].tu, a[i].mau);
		}
		else printf("Phan so thu %d: %d/%d\n", i, a[i].tu, a[i].mau);
	}
}

void xuat_Mau_LonHon_Tu(PhanSo a[], int n)
{
	printf("Cac phan so co mau > tu:\n");
	for (int i = 0; i < n; i++)
	{
		if (a[i].mau > a[i].tu)
		{		
			printf("%d/%d ", a[i].tu, a[i].mau);
		}
	}
	printf("\n");
}

int dem_PS_Chan(PhanSo a[], int n)
{
	bool flag = false;
	int dem=0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].tu%2==0 && a[i].mau%2==0)
		{
			dem++;
			flag = true;
		}
	}
	if (flag==false)
	{
		return 0;
	}
	else return dem;
}

int ULCN(int a, int b)
{
	int temp=a;
	if (a<0)
	{
		temp=-a;
	}
	while (temp!=b)
	{
		if (temp>b)
		{
			temp = temp-b;
		} 
		else b = b-temp;
	}
	return temp;
}

void toiGian_PS(PhanSo a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int temp = ULCN(a[i].tu, a[i].mau);
		a[i].tu /= temp;
		a[i].mau /= temp;
	}
}

void timMAX(PhanSo a[], int n)
{
	float max = 0;
	int t1, t2;
	for (int i = 0; i < n; i++)
	{
		float h = float(a[i].tu) / float(a[i].mau);
		if (h>=max)
		{
			max=h;
			t1=a[i].tu;
			t2=a[i].mau;
		}
	}
	printf("Phan so lon nhat la: %d/%d", t1, t2);
}

float tich_CacPS(PhanSo a[], int n)
{
	float tongTu = 1;
	float tongMau = 1;
	for (int i = 0; i < n; i++)
	{
		tongTu *= a[i].tu;
		tongMau *= a[i].mau;
	}
	return tongTu/tongMau;
}
int main()
{
	PhanSo a[MAXSIZE];
	int n;
	nhap_PhanSo(a,n);
	printf("----------------------------------------------\n");
	xuat_PhanSo(a,n);
	printf("----------------------------------------------\n");
	xuat_Mau_LonHon_Tu(a,n);
	printf("----------------------------------------------\n");
	printf("So luong phan so co tu va mau chan la:\n");
	if (dem_PS_Chan(a,n)==0)
	{
		printf("khong co so nao phu hop dieu kien tren\n");
	}
	else printf("%d ", dem_PS_Chan(a,n));
	printf("\n----------------------------------------------\n");
	printf("Cac phan so sau khi toi gian:\n");
	toiGian_PS(a,n);
	xuat_PhanSo(a,n);
	printf("----------------------------------------------\n");
	printf("Tich Cac Phan So La:%.2f\n", tich_CacPS(a,n));
	printf("----------------------------------------------\n");
	timMAX(a,n);
	getch();
	return 0;
}
