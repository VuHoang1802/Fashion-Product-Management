#include "Header.h"
// sau khi dăng ký , đăng nhập xong ( chọn vai trò 1: admin, 2 là khách) đi đến các chức nắng 
int ChucNangADMIN(string TK, SignUp TTCN){
	while(1)
	{
		DanhSachSanPham DanhSachSP;
		SanPham SP;
		clrscr();
		cout<<"Xin Chao: "<<TK;
		//Các chức năng của ADMIN
		cout<<"\nAn 1: Xem Danh Sach San Pham";
		if (TTCN.CheDo == 1)
		{
			cout<<"\nAn 2: Them San Pham";
			cout<<"\nAn 3: Xoa San Pham";
			cout<<"\nAn 4: Sua Thong tin san pham";
			cout<<"\nAn 5: Sap xep danh sach";
			cout<<"\nAn 6: Xem danh sach tai khoan";
		}
		cout<<"\nAn 7: Xem Thong tin ca nhan";
		cout<<"\nAn 8: Thoat tai khoan";
		char LuaChonCuaAdmin = _getch();
		int vitrixoaSP = -1;
		int VitriCansua = -1;
		SanPham SPthaythe;
		switch (LuaChonCuaAdmin)
		{
		case '1':
			// xem danh sách 
			clrscr();
			DanhSachSP.docGhiTep();
			cout<<"Danh Sach San Pham: Co "<<DanhSachSP.DanhSach.size() - 1<<" San Pham.";
			if (DanhSachSP.DanhSach.size() == 0)
			{
				cout<<"\nDanh Sach Trong";
			}
			else
			{
				TextColor(3);
				gotoXY(1,2);
				cout<<"STT";
				gotoXY(10,2);
				cout<<"ten SP";
				gotoXY(30,2);
				cout<<"ma SP";
				gotoXY(50,2);
				cout<<"Danh muc";
				gotoXY(70,2);
				cout<<"Gia SP";
				TextColor(15);
				for (int i = 0; i < DanhSachSP.DanhSach.size() - 1; i++)
				{
					gotoXY(1,i + 3);
					cout<<i + 1;
					gotoXY(10,i + 3);
					cout<<DanhSachSP.DanhSach[i].ProductName;
					gotoXY(30,i + 3 );
					cout<<DanhSachSP.DanhSach[i].MumberProduct;
					gotoXY(50,i + 3);
					cout<<DanhSachSP.DanhSach[i].DanhMuc;
					gotoXY(70,i + 3);
					cout<<DanhSachSP.DanhSach[i].Gia;
				}
			}
			_getch();
			break;
		case '2':
			// them san pham 
			clrscr();
			DanhSachSP.docGhiTep();
			if(TTCN.CheDo == 1){
				cout<<"\n\nBan Nhap Cac Thong Tin Cua San Pham";
				SP.NhapSanPham();
				SP.GhiSanPhamVaoFile();
				DanhSachSP.DanhSach.push_back(SP);
				_getch();
			}
			else
			{
				cout<<"\nTai khoan cua ban khong duoc cap quyen";
				cout<<"\nNhap phim bat kia de quay tro lai";
				_getch();
			}
			break;
		case '3':

			if (TTCN.CheDo == 1)
			{
				//xóa sản phẩm
				clrscr();
				cout<<"\nAn 1. Xoa het danh sach";
				cout<<"\nAn 2. Xoa thu tu san pham";
				cout<<"\nAn 3. Xoa san pham cuoi cung trong danh sach";
				char luachonXoaSP;
				luachonXoaSP = _getch();
				switch (luachonXoaSP)
				{
				case '1':
					DanhSachSP.docGhiTep();
					DanhSachSP.DanhSach.clear();
					DanhSachSP.ghidanhsachvaoFILE(DanhSachSP.DanhSach);
					break;
				case '2':
					DanhSachSP.docGhiTep();
					do
					{
						cin>>vitrixoaSP;
					} while (vitrixoaSP < 0 || vitrixoaSP > DanhSachSP.DanhSach.size());
					DanhSachSP.DanhSach.erase(DanhSachSP.DanhSach.begin() + vitrixoaSP);
					DanhSachSP.ghidanhsachvaoFILE(DanhSachSP.DanhSach);
					break;
				default:
						break;
				}
			}
			else
			{
				cout<<"\nTai khoan cua ban khong duoc cap quyen";
				cout<<"\nNhap phim bat kia de quay tro lai";
				_getch();
			}
			break;
		case '4':
			//sua thong tin
			clrscr();
			DanhSachSP.docGhiTep();
			cout<<"Nhap vao vi tri san pham can sua: ";
			do
			{
				cin>>VitriCansua;
			} while (VitriCansua < 0 || VitriCansua > DanhSachSP.DanhSach.size());
			SPthaythe.NhapSanPham();
			DanhSachSP.DanhSach.at(VitriCansua) = SPthaythe;
			DanhSachSP.ghidanhsachvaoFILE(DanhSachSP.DanhSach);
			_getch();
			break;
		case '5':
			break;
		case '6':
			break;
		case '7':
			//xem thong tin
			clrscr();
			cout<<"			THONG TIN TAI KHOAN"<<endl;
			cout<<"Ten TK: "<<TTCN.TaiKhoan<<endl;
			cout<<"Ten MK: "<<TTCN.MatKhau<<endl;
			cout<<"Tuoi: "<<TTCN.Age<<endl;
			cout<<"Email: "<<TTCN.UseEmail<<endl;
			cout<<"SDT: "<<TTCN.MumberUse<<endl;
			_getch();
			break;
		case '8':
			return 0;
		default:
			break;
		}
	}
	return 1;
}