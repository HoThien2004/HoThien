#include <stdio.h>
#include <conio.h>>
typedef struct {
    int tu;
    int mau;
} PhanSo;

// Hàm tính giá trị của phân số
float giaTriPhanSo(PhanSo ps) {
    return (float)ps.tu / ps.mau;
}

// Hàm tìm phân số lớn nhất
PhanSo timPhanSoLonNhat(PhanSo arr[], int n) {
    PhanSo max = arr[0];
    for (int i = 1; i < n; i++) {
        if (giaTriPhanSo(arr[i]) > giaTriPhanSo(max)) {
            max = arr[i];
        }
    }
    return max;
}

// Hàm tìm phân số nhỏ nhất
PhanSo timPhanSoNhoNhat(PhanSo arr[], int n) {
    PhanSo min = arr[0];
    for (int i = 1; i < n; i++) {
        if (giaTriPhanSo(arr[i]) < giaTriPhanSo(min)) {
            min = arr[i];
        }
    }
    return min;
}

// Hàm xóa phần tử tại vị trí k
void xoaPhanTu(PhanSo arr[], int *n, int k) {
    if (k < 0 || k >= *n) {
        printf("Vi tri k khong hop le!\n");
        return;
    }
    for (int i = k; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

// Hàm thêm phần tử x tại vị trí k
void themPhanTu(PhanSo arr[], int *n, PhanSo x, int k) {
    if (k < 0 || k > *n) {
        printf("Vi tri k khong hop le!\n");
        return;
    }
    for (int i = *n; i > k; i--) {
        arr[i] = arr[i - 1];
    }
    arr[k] = x;
    (*n)++;
}

// Hàm in mảng phân số
void inMangPhanSo(PhanSo arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d/%d ", arr[i].tu, arr[i].mau);
    }
    printf("\n");
}

int main() {
    PhanSo arr[100];
    int n;

    printf("Nhap so luong phan so: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap phan so thu %d (tu mau): ", i + 1);
        scanf("%d %d", &arr[i].tu, &arr[i].mau);
    }

    printf("Mang phan so ban dau: ");
    inMangPhanSo(arr, n);

    PhanSo max = timPhanSoLonNhat(arr, n);
    printf("Phan so lon nhat: %d/%d\n", max.tu, max.mau);

    PhanSo min = timPhanSoNhoNhat(arr, n);
    printf("Phan so nho nhat: %d/%d\n", min.tu, min.mau);

    int k;
    printf("Nhap vi tri can xoa: ");
    scanf("%d", &k);
    xoaPhanTu(arr, &n, k);
    printf("Mang phan so sau khi xoa: ");
    inMangPhanSo(arr, n);

    PhanSo x;
    printf("Nhap phan so can them (tu mau): ");
    scanf("%d %d", &x.tu, &x.mau);
    printf("Nhap vi tri can them: ");
    scanf("%d", &k);
    themPhanTu(arr, &n, x, k);
    printf("Mang phan so sau khi them: ");
    inMangPhanSo(arr, n);

    return 0;
}
