#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// a. Tìm phần tử lớn nhất của a, xuất ra phần tử lớn nhất và địa chỉ của nó thông qua con trỏ mảng.
void Timphantulonnhat(int* a, int n) {
	int *max = a;
	for (int i = 1; i < n; ++i) {
		if (*(a + i) > *max) {
			max = (a + i);
		}
	}
	printf("Phan tu lon nhat la %d tai dia chi %p\n", *max, (void*)max);
}

// b. Xuất địa chỉ của phần tử chẵn lớn nhất và phần tử lẻ nhỏ nhất, nếu không có thì báo không có phần tử chẵn/lẻ trong mảng.
void Timphantuchanle(int* a, int n) {
	int *chan_max = NULL;
	int *le_min = NULL;

	for (int i = 0; i < n; ++i) {
		if (*(a + i) % 2 == 0) {
			if (chan_max == NULL || *(a + i) > *chan_max) {
				chan_max = (a + i);
			}
		}
		else {
			if (le_min == NULL || *(a + i) < *le_min) {
				le_min = (a + i);
			}
		}
	}

	if (chan_max != NULL) {
		printf("Phan tu chan lon nhat tai dia chi %p\n", (void*)chan_max);
	}
	else {
		printf("Khong co phan tu chan trong mang.\n");
	}

	if (le_min != NULL) {
		printf("Phan tu le nho nhat tai dia chi %p\n", (void*)le_min);
	}
	else {
		printf("Khong co phan tu le trong mang.\n");
	}
}

// c. Xóa phần tử có giá trị 0.
void Xoaphantu(int* a, int* n) {
	int* giatrimoi = a;
	for (int i = 0; i < *n; ++i) {
		if (*(a + i) != 0) {
			*giatrimoi++ = *(a + i);
		}
	}
	*n = giatrimoi - a;
}

// d. Thêm phần tử x vào sau phần tử đầu tiên.
void Themphantu(int* a, int* n, int x) {
	for (int i = *n; i > 1; --i) {
		*(a + i) = *(a + i - 1);
	}
	*(a + 1) = x;
	(*n)++;
}

// e. Tính tổng các phần tử là số chính phương.
bool Sochinhphuong(int n) {
	int canbachai = (int)sqrt((double)n);
	return canbachai * canbachai == n;
}

int Tongsochinhphuong(int* a, int n) {
	int tong = 0;
	for (int i = 0; i < n; ++i) {
		if (Sochinhphuong(*(a + i))) {
			tong += *(a + i);
		}
	}
	return tong;
}

// f. Xuất các số cực đại trong a. Biết rằng số cực đại là số lớn hơn các số quanh nó.
void Xuatcucdai(int* a, int n) {
	if (n == 1) {
		printf("%d\n", *a);
		return;
	}
	for (int i = 0; i < n; ++i) {
		if ((i == 0 && *(a + i) > *(a + i + 1)) ||
			(i == n - 1 && *(a + i) > *(a + i - 1)) ||
			(*(a + i) > *(a + i - 1) && *(a + i) > *(a + i + 1))) {
			printf("%d ", *(a + i));
		}
	}
	printf("\n");
}

int main() {
	int a[100];
	int n, x;

	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);

	printf("Nhap cac phan tu: ");
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	Timphantulonnhat(a, n);
	Timphantuchanle(a, n);

	Xoaphantu(a, &n);
	printf("Mang sau khi xoa phan tu: ");
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");

	printf("Nhap phan tu can them vao sau phan tu dau tien: ");
	scanf("%d", &x);
	Themphantu(a, &n, x);
	printf("Mang sau khi them phan tu: ");
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");

	int tong = Tongsochinhphuong(a, n);
	printf("Tong cac so chinh phuong: %d\n", tong);

	printf("Cac so cuc dai trong mang: ");
	Xuatcucdai(a, n);

	return 0;
}
