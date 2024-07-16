
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAXSIZE 100

void nhap_Chuoi(char * &str)
{
	str = (char *)malloc(MAXSIZE*sizeof(char));
	printf("Nhap chuoi:");
	gets(str);
}

void xuat_Chuoi(char *str)
{
	printf("Chuoi vua nhap la:%s",str);
}

void chuyenDoi(char *str)
{
	str[0]-=32;
	for (int i = 1; i < strlen(str); i++)
	{
		if (str[i-1]==' ')
		{
			if (str[i]>=97 && str[i]<=122)
			{
				str[i] -= 32;
			}
		}
	}
}

int main()
{
	char *str;
	nhap_Chuoi(str);
	xuat_Chuoi(str);
	printf("\n---------------------------------\n");
	printf("Chuyen doi ve chu HOA:\n");
	printf("Ket qua:%s", strupr(str));
	printf("\n---------------------------------\n");
	printf("Chuyen Cac Ky Tu Dau Moi Chu Thanh Chu HOA:\n");
	char *p;
	nhap_Chuoi(p);
	chuyenDoi(p);
	xuat_Chuoi(p);
	printf("\n---------------------------------\n");
	getch();
	return 0;
}
