
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

void nhap_SoNguyen (int * &a, int &n)
{
	printf("Nhap so phan tu cua mang:");
	scanf("%d", &n);
	a = (int *)malloc(n*sizeof(int));
	for(int i = 0; i < n; i++)
		a[i]= rand()%100;
}

void xuat_SoNguyen(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
	printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %x", i, a[i], a+i);
	}
}

void Xoa_PhanTu(int *a, int &n, int vitri)
{
	if (vitri<0)
	{
		vitri=0;
	}
	else if (vitri>n-1)
	{
		vitri=n-1;
	}
	for (int i = vitri; i < n; i++)
	{
		a[i]=a[i+1];
	}
	n--;
}

void them_PhanTu(int *a, int &n, int giatri, int vitri)
{
	if (vitri<0)
	{
		vitri=0;
	}
	else if (vitri>n-1)
	{
		vitri=n-1;
	}
	for (int i = n; i > vitri; i--)
	{
		a[i]=a[i-1];
	}
	a[vitri]=giatri;
	n++;
}

void Chan_Le(int *a, int n)
{
	int Left = 0;
	int Right = n-1;
	while (Left<Right)
	{
		while (a[Left]%2==0 && Left<Right)
		{
			Left++;
		}

		while (a[Right]%2!=0 && Left<Right)
		{
			Right--;
		}

		if (Left<Right)
		{
			int temp = a[Left];
			a[Left]=a[Right];
			a[Right]=temp;
			Left++;
			Right--;
		}
	}
}


void xuat_SoCucTieu(int *a, int n)
{
	printf("Cac so cuc teu la:\n");
	for (int i = 0; i < n; i++)
	{
		if (a[i] < a[i-1] && a[i] < a[i+1])
		{
			printf("%d ", a[i]);
		}
	}
}

void xet_ChanLe_XenKe(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i]%2==0 && a[i+1]%2!=0 || a[i]%2!=0 && a[i+1]%2==0)
		{
			
		}
		else
		{
			printf("Mang khong xen ke");
			return;
		}
	}
	printf("Mang co xen ke");
}

int main()
{
	int *a, n;
	nhap_SoNguyen(a, n);
	xuat_SoNguyen(a, n);
	printf("\n-------------------------------------------\n");
	printf("Xuat Cac So Cuc Tieu:\n");
	xuat_SoCucTieu(a,n);
	printf("\n-------------------------------------------\n");
	printf("XOA PHAN TU:\n");
	int vt;
	printf("Nhap vi tri phan tu muon xoa:");
	scanf("%d", &vt);
	Xoa_PhanTu(a,n,vt);
	xuat_SoNguyen(a,n);
	printf("\n-------------------------------------------\n");
	printf("THEM PHAN TU:\n");
	int p, k;
	printf("Nhap vi tri muon them:");
	scanf("%d", &k);
	printf("Nhap gia tri:");
	scanf("%d", &p);
	them_PhanTu(a,n,p,k);
	xuat_SoNguyen(a,n);
	printf("\n-------------------------------------------\n");
	printf("CHAN DAU MANG - LE CUOI MANG:\n");
	Chan_Le(a,n);
	xuat_SoNguyen(a,n);
	printf("\n-------------------------------------------\n");
	printf("Kiem tra mang xen ke!!!\n");
	xet_ChanLe_XenKe(a,n);
	getch();
}
