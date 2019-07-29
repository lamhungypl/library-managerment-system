#pragma once
#include "Quyen_sach.h"
#include "thu_vien_chung.h"
#include "Sinh_vien.h"

class Ban_ghi_muon{
private:
	string maQuyen;
	string maSV;

	string ngayMuon;
	int limit;

public:
	Ban_ghi_muon();
	Ban_ghi_muon(string _maQuyen,string _maSV,string _ngayMuon,int limit);

	string getMaQuyen();
	string getMaSV();
	string getNgayMuon();

	void setMaQuyen(string);
	void setMaSV(string);
	void setNgayMuon(string);

	void view();

	~Ban_ghi_muon();
};
