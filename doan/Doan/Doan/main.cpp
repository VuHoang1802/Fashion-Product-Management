#include "Header.h"
using namespace std;
int main(){
	//PlaySound(TEXT("test.wma"), NULL, SND_FILENAME);
	while(1){
		clrscr();
		cout<<"       Chao Mung ban toi he thong cua hang online cua hang Fahsion Idea";
		cout<<"\n1.  Dang Nhap.";
		cout<<"\n2.  Dang ki (Neu ban chu co TK).";
		cout<<"\n3.  Thoat";
		SignUpList DanhSachTK;
		char LuaChon;
		LuaChon = _getch();
		Login DangNhap;
		SignUp DangKiTK;
		int k = -1;
		int TTTaiKhoan = -1;
		switch (LuaChon)
		{
		case '1':			
			clrscr();
			DangNhap.NhapTaiKhoan();
			//Kiểm tra tk có đúng ko
			DanhSachTK.DocGhiFile();
			for (int i = 0; i < DanhSachTK.TK.size(); i++) // duyet các kí tự trong 2 thuộc tính tài khoản và mật khẩu
			{
				if(DangNhap.TaiKhoan == DanhSachTK.TK[i].TaiKhoan && DangNhap.MatKhau == DanhSachTK.TK[i].MatKhau) //kiêm tra tai khoan mat khau
				{
					k = DanhSachTK.TK[i].CheDo;
					TTTaiKhoan = i;
				}
			}
			//nếu đúng
			if(k != -1){
				cout<<"Ten TK: "<<DanhSachTK.TK[TTTaiKhoan].TaiKhoan<<endl;
				cout<<"Ten MK: "<<DanhSachTK.TK[TTTaiKhoan].MatKhau<<endl;
				cout<<"Tuoi: "<<DanhSachTK.TK[TTTaiKhoan].Age<<endl;
				cout<<"Email: "<<DanhSachTK.TK[TTTaiKhoan].UseEmail<<endl;
				cout<<"SDT: "<<DanhSachTK.TK[TTTaiKhoan].MumberUse<<endl;
				ChucNangADMIN(DangNhap.TaiKhoan, DanhSachTK.TK[TTTaiKhoan]);
				_getch();
			}
			else
			{
				cout<< "\n\nBan dang nhap khong thanh cong";
				_getch();
			}
			break;
		case '2':
			bool KT, KTDinhDang;
			do
			{
				clrscr();
				DangKiTK.DKTaiKhoan();
				KT = DangKiTK.GhiFileVaoTep();
				KTDinhDang = DangKiTK.KiemTraDinhDang();
			} while (KT != true || KTDinhDang != true);
			cout<<"\n BAN DANG DANG KI THANH CONG";
			cout<<"\n An ENTER de THOAT bang DANG KI";
			_getch();
			break;
		case '3':
			return 0;
		}
	}
	_getch();
	return 0;
}