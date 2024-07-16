#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int tu;
	int mau;
} PhanSo;

// a. Nhập các phần tử của mảng. Lưu ý ngoại lệ khi mẫu là 0.
void Nhapphanso(PhanSo* ps, int n) {
	for (int i = 0; i < n; ++i) {
		printf("Nhap phan so thu %d (dang tu/mau): ", i + 1);
		scanf("%d/%d", &ps[i].tu, &ps[i].mau);
		while (ps[i].mau == 0) {
			printf("Mau so phai khac 0 %d (dang tu/mau): ", i + 1);
			scanf("%d/%d", &ps[i].tu, &ps[i].mau);
		}
	}
}

// a. Xuất các phần tử của mảng
void Xuatphanso(PhanSo* ps, int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d/%d ", ps[i].tu, ps[i].mau);
	}
	printf("\n");
}

// b. Xuất các phân số có mẫu > tử
void Maulonhontu(PhanSo* ps, int n) {
	printf("Cac phan so co mau lon hon tu: ");
	for (int i = 0; i < n; ++i) {
		if (ps[i].mau > ps[i].tu) {
			printf("%d/%d ", ps[i].tu, ps[i].mau);
		}
	}
	printf("\n");
}

// c. Đếm số phân số có mẫu và tử chẵn
int Demphanso(PhanSo* ps, int n) {
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (ps[i].tu % 2 == 0 && ps[i].mau % 2 == 0) {
			count++;
		}
	}
	return count;
}

// Hàm tìm ước chung lớn nhất (UCLN)
int Ucln(int a, int b) {
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

// d. Rút gọn phân số
void Rutgonphanso(PhanSo* ps) {
	int gcd = Ucln(ps->tu, ps->mau);
	ps->tu /= gcd;
	ps->mau /= gcd;
}

// e. Tính tích các phần tử của mảng
PhanSo Tichphanso(PhanSo* ps, int n) {
	PhanSo tich;
	tich.tu = 1;
	tich.mau = 1;
	for (int i = 0; i < n; ++i) {
		tich.tu *= ps[i].tu;
		tich.mau *= ps[i].mau;
	}
	// Rút gọn kết quả
	Rutgonphanso(&tich);
	return tich;
}

// f. Tìm phần tử lớn nhất (so sánh giá trị của phân số)
PhanSo Timphansolonnhat(PhanSo* ps, int n) {
	PhanSo max = ps[0];
	for (int i = 1; i < n; ++i) {
		if ((double)ps[i].tu / ps[i].mau >(double)max.tu / max.mau) {
			max = ps[i];
		}
	}
	return max;
}

int main() {
	int n;
	printf("Nhap so luong phan so: ");
	scanf("%d", &n);

	// Khởi tạo mảng phân số
	PhanSo* ps = (PhanSo*)malloc(n * sizeof(PhanSo));

	// Nhập phân số
	Nhapphanso(ps, n);

	// Xuất phân số
	printf("Cac phan so trong mang: ");
	Xuatphanso(ps, n);

	// Xuất các phân số có mẫu > tử
	Maulonhontu(ps, n);

	// Đếm số phân số có mẫu và tử chẵn
	int count = Demphanso(ps, n);
	printf("So phan so co mau va tu chan: %d\n", count);

	// Rút gọn phân số
	for (int i = 0; i < n; ++i) {
		Rutgonphanso(&ps[i]);
	}
	printf("Cac phan so sau khi rut gon: ");
	Xuatphanso(ps, n);

	// Tính tích các phân số
	PhanSo tich = Tichphanso(ps, n);
	printf("Tich cac phan soi: %d/%d\n", tich.tu, tich.mau);

	// Tìm phân số lớn nhất
	PhanSo max = Timphansolonnhat(ps, n);
	printf("Phan so lon nhat: %d/%d\n", max.tu, max.mau);

	// Giải phóng bộ nhớ
	free(ps);

	return 0;
}
