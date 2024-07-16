#include <stdio.h>
#include <stdlib.h>

// Hàm chia các phần tử của mảng a cho mảng b và xuất kết quả
void chiaMang(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            printf("Phan tu thu %d cua mang b bang 0, khong the chia!\n", i);
        } else {
            printf("Phan tu thu %d: %d / %d = %.2f\n", i, a[i], b[i], (float)a[i] / b[i]);
        }
    }
}

int main() {
    int n;
    printf("Nhap so luong phan tu cua hai mang: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    int *b = (int *)malloc(n * sizeof(int));

    if (a == NULL || b == NULL) {
        printf("Khong the cap phat bo nho!\n");
        return 1;
    }

    printf("Nhap cac phan tu cua mang a:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    printf("Nhap cac phan tu cua mang b:\n");
    for (int i = 0; i < n; i++) {
        printf("b[%d] = ", i);
        scanf("%d", &b[i]);
    }

    chiaMang(a, b, n);

    // Giải phóng bộ nhớ đã cấp phát
    free(a);
    free(b);

    return 0;
}
