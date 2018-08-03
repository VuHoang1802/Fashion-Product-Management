#pragma once
#include "Header.h"
#include <iostream>
#include <conio.h>
#include "console.h"
#include <string>
#include <fstream>
#include <vector>
#include <Windows.h>
using namespace std;
int DemSoLuongTrongDanhSach(string Tep);
// class dăng nhập 
class Login
{
public:
	string TaiKhoan;
	string MatKhau;
	void NhapTaiKhoan();
};
// clas dăng ký kế thừa từ đăng nhập ;
class SignUp: public Login{
public:
	string Usename;
	int Age;
	string UseEmail;
	string MumberUse;
	int CheDo;
	void DKTaiKhoan();
	bool GhiFileVaoTep();
	bool KiemTraDinhDang();
};
//quản lý danh sách tài khoản sau khi dắng ký ;
class SignUpList
{
public:
	vector<SignUp> TK;
	int SoLuongTaiKhoan;
	void DocGhiFile();
	void KiemTraDangNhap();
};

// class thông tin của sản phẩm 
class SanPham{
public:
	string ProductName;
	string MumberProduct;
	string DanhMuc;
	int Gia;
	void NhapSanPham();
	void GhiSanPhamVaoFile();
};
// class quản lý danh sach sản phẩm 0
class  DanhSachSanPham
{
public:
	// tạo mảng vector để quản các sản phẩm ở trên 
	vector<SanPham> DanhSach;
	
	void docGhiTep();// mỗi lần gọi đến hàm là dọc toàn bộ danh sách sản phẩm trong file danh sách sản phẩm vào vetor vừa khai báo ở trên 
	void ghidanhsachvaoFILE(vector<SanPham> DS);// có sự thay đổi đổi thì ghi lại cập nhập thông tin sản phẩm vào trong danh sách 
};
// chức năng của cả hệ thống 
int ChucNangADMIN(string TK, SignUp TTCN);
// biến string TK : vai trò dể phân cấp ( 1, admin , 2 là khách )
//biến SungupTTCN: thông tin cá nhân 
