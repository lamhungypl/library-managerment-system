#pragma once
#include"Thu_vien_chung.h"
#include"Quyen_sach.h"
class Sach
{
private:
	vector<Quyen_sach> dsQyenSach;
	string maSach;
	string tenSach;
	string tacGia;
	int copies;
	int available;
public:
	Sach(string _maSach,string _tenSach,string _tacGia,int _copies);
	Sach(string _maSach,string _tenSach,string _tacGia);

	vector<Quyen_sach>& getDsQuyenSach();
	string getMaSach();
	string getTenSach();
	string getTacGia();
	int getCopies();
	int getAvailable();

	void setMaSach(string);
	void setTenSach(string);
	void setTacGia(string);
	void setCopies(int);
	void setAvailable(int);
	void setDsQuyenSach(vector<Quyen_sach>);
	
	Quyen_sach* getQuyenSachSanSangDauTien();
	Quyen_sach* getQuyenSachByCode(string _maQuyen);


	void view();

	Sach();
	~Sach();
};

