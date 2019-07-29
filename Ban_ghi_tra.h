#pragma once
#include "Quyen_sach.h"
#include "Ban_ghi_muon.h"
#include "Sinh_vien.h"

class Ban_ghi_tra{
private:
	string maQuyen;
	string maSV;
	string ngayMuon;
	string ngayTra;

public:
	Ban_ghi_tra();
	Ban_ghi_tra(string _maQuyen,string _maSV,string _ngayMuon,string _ngayTra);

	string getMaSV();
	string getMaQuyen();
	string getNgayMuon();
	string getNgayTra();

	void setNgayMuon(string);
	void setNgayTra(string);
	void setMaQuyen(string);
	void setMaSV(string);

	void view();

	~Ban_ghi_tra();
};
