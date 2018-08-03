#include "Header.h"
// viet nội dung của các hàm trong các class;
int DemSoLuongTrongDanhSach(string Tep){
	fstream GhiFile;//ra vào file
	GhiFile.open(Tep);
	if (GhiFile.fail())
		cout << "Failed to open this file!" <<endl;
	string s;
	int sodong = 0;
	while(getline(GhiFile,s))
	{
		sodong++;
	}
	return sodong;
}
// hàm truy cập trong lớp login;
void Login::NhapTaiKhoan(){
	cout<<"\nTai Khoan: ";
		while (TaiKhoan.length() < 30)
		{
			char c = _getch();
			if(c == 13)
			{
				break;
			}
			TaiKhoan += c;
			cout<<c;
		}
		cout<<"\nMat Khau: ";
		while (MatKhau.length() < 30)
		{
			char c = _getch();
			if(c == 13)
			{
				break;
			}
			MatKhau += c;
			cout<<"*";
		}
}
// hàm dăng ký tài khaorn trong class singup;
void SignUp::DKTaiKhoan(){
		CheDo = 0;
		cout<<"\nTai Khoan: ";
		cin>>TaiKhoan;
		cout<<"\nMat Khau: ";
		while (MatKhau.length() < 30)
		{
			char c = _getch();
			if(c == 13)
			{
				break;
			}
			MatKhau += c;
			cout<<"*";
		}
		cout<<"\nTuoi: ";
		cin>>Age;
		cout<<"\nEmail: ";
		cin>>UseEmail;
		cout<<"\nSo Dien Thoai: ";
		cin>>MumberUse;
		cout<<"\nDang TK(1: admin - 2: Thanh vien) : ";
		cin>>CheDo;
}
bool SignUp::GhiFileVaoTep(){
		fstream FileGhi;
		FileGhi.open("GhiFile.txt",ios::app);
		if (FileGhi.fail()){
			cout << "Failed to open this file!" <<endl;
			return false;
		}
		else{
			FileGhi << TaiKhoan;
			FileGhi<<" ";
			FileGhi << MatKhau;
			FileGhi<<" ";
			FileGhi<<CheDo;
			FileGhi<<" ";
			FileGhi << Usename;
			FileGhi<<" ";
			FileGhi<<Age;
			FileGhi<<" ";
			FileGhi<<UseEmail;
			FileGhi<<" ";
			FileGhi<<MumberUse;
			FileGhi<<"\n";
		}

		FileGhi.close();
		return true;
}
// hàm ktra định dạng trong hàm signup;
bool SignUp::KiemTraDinhDang(){
	return true;
}
// truy cập vào hàm đọc ghi file trong class signuplist
void SignUpList::DocGhiFile(){
	// tạo ra biến DKao dể lưu dữ liệu của từng hàng ở trong file ghifile.txt;
	SignUp DKao;
	fstream DocFile;
	DocFile.open("GhiFile.txt");
	if(DocFile.fail()){
		cout<<"\nFailed to open this file!";
		}
	else{
			
		SoLuongTaiKhoan = DemSoLuongTrongDanhSach("GhiFile.txt");
		int i = 0;
		string s;
		while (!DocFile.eof())
			{
				getline(DocFile,DKao.TaiKhoan,' ');
				getline(DocFile,DKao.MatKhau,' ');
				DocFile>>DKao.CheDo;
				DocFile>>DKao.Age;
				getline(DocFile,s,' ');
				getline(DocFile,DKao.UseEmail,' ');
				getline(DocFile,DKao.MumberUse,'\n');
				TK.push_back(DKao);
				i++;
			}
		}
}
// ham ktra dăng nhập : xem cớ dúng định dang ;
void SignUpList::KiemTraDangNhap(){

}
// hàm băt đầu nhập thông tin sản phẩm trong class NHapsanpham;
void SanPham::NhapSanPham(){
	cout<<"\nNhap Ten San Pham: ";
	fflush(stdin);
	getline(cin, ProductName);
	cout<<"\nNhap Ma San Pham: ";
	fflush(stdin);
	getline(cin, MumberProduct);
	cout<<"\nThuoc Danh Muc: ";
	fflush(stdin);
	getline(cin, DanhMuc);
	cout<<"\nGia: ";
	cin>>Gia;
	cout<<"\n";
}
// hàm chạy sau khi nhập thông tin sản phẩm rồi ghi vào file DanhSachSanPham.txt
void SanPham::GhiSanPhamVaoFile(){
	fstream FileGhi;
	FileGhi.open("DanhSachSanPham.txt", ios::app);
	if (FileGhi.fail())
		cout << "Failed to open this file!" <<endl;
	else{
		FileGhi << ProductName;
		FileGhi<<"#";
		FileGhi << MumberProduct;
		FileGhi<<"#";
		FileGhi << DanhMuc;
		FileGhi<<"#";
		FileGhi<<Gia;
		FileGhi<<"#\n";
	}
	FileGhi.close();
}
// mỗi laand lấy dữ liệu đẻ xử lý thì lại gọi hàm ra đẻ lấy dữ liệu;
void DanhSachSanPham::docGhiTep(){
	SanPham SP;
	fstream DocFile;
	DocFile.open("DanhSachSanPham.txt");
	if(DocFile.fail()){
		cout<<"\nFailed to open this file!";
		}
	else{
		string temp;
		while (!DocFile.eof())
			{
				getline(DocFile,SP.ProductName,'#');
				getline(DocFile,SP.MumberProduct,'#');
				getline(DocFile,SP.DanhMuc,'#');
				DocFile>>SP.Gia;
				getline(DocFile,temp,'\n');
				DanhSach.push_back(SP);
			}
		}
}
// hàm cập nhập thông tin vào file sau khi ( thêm , sửa , xóa )
void DanhSachSanPham::ghidanhsachvaoFILE(vector<SanPham> DS){
	fstream DocFile;
	DocFile.open("DanhSachSanPham.txt", ios::out);
	if(DocFile.fail()){
			cout<<"\nFailed to open this file!";
	}
	else{
		for (int i = 0; i < DS.size(); i++)
		{
			DocFile << DS[i].ProductName;
			DocFile<<"#";
			DocFile << DS[i].MumberProduct;
			DocFile<<"#";
			DocFile << DS[i].DanhMuc;
			DocFile<<"#";
			DocFile<<DS[i].Gia;
			DocFile<<"#\n";
		}
	}
	DocFile.close();
}