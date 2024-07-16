#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
	char hoTen[50];
	char gioiTinh[10];
	int ngay;
	int thang;
	int nam;
} NguoiLaoDong;

void nem_loi(int maLoi) {
	switch (maLoi) {
	case 101:
		printf("Lỗi 101: Tuổi không thuộc trong tuổi lao động.\n");
		break;
	default:
		printf("Lỗi: %d\n", maLoi);
	}
	exit(maLoi);
}

void kiem_tra_gioi_tinh(char* gioiTinh) {
	if (strcmp(gioiTinh, "nam") != 0 && strcmp(gioiTinh, "nữ") != 0) {
		printf("errcode\n");
		exit(1);
	}
}

int tinh_nam_nghi_huu(NguoiLaoDong nld, int namHienTai) {
	int tuoi = namHienTai - nld.nam;

	if ((strcmp(nld.gioiTinh, "nam") == 0 && (tuoi < 18 || tuoi > 62)) ||
		(strcmp(nld.gioiTinh, "nu") == 0 && (tuoi < 18 || tuoi > 60))) {
		nem_loi(101);
	}

	int namNghiHuu;
	if (strcmp(nld.gioiTinh, "nam") == 0) {
		namNghiHuu = nld.nam + 62;
	}
	else {
		namNghiHuu = nld.nam + 60;
	}

	return namNghiHuu;
}

int main() {
	NguoiLaoDong nld;
	int namHienTai = 2021;

	printf("Nhap ho ten: ");
	fgets(nld.hoTen, 50, stdin);
	nld.hoTen[strcspn(nld.hoTen, "\n")] = 0; 

	printf("Nhap gioi tinh (nam/nu): ");
	fgets(nld.gioiTinh, 10, stdin);
	nld.gioiTinh[strcspn(nld.gioiTinh, "\n")] = 0; 
	kiem_tra_gioi_tinh(nld.gioiTinh);

	printf("Nhap ngay thang nam sinh(dd/mm/yyyy): ");
	scanf("%d/%d/%d", &nld.ngay, &nld.thang, &nld.nam);

	int namNghiHuu = tinh_nam_nghi_huu(nld, namHienTai);

	printf("Thoi gian %s duoc nghi huu la ngay thang: %02d/%d\n", nld.hoTen, nld.thang, namNghiHuu);

	return 0;
}
