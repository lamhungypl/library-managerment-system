#pragma once
#include"Thu_vien_chung.h"
#include "Quyen_sach.h"

class Sinh_vien
{
private:
	string maSV;
	string hoTen;
	vector<Quyen_sach> dsDangMuon;

public:
	Sinh_vien(string _maSV,string _hoTen);
	Sinh_vien(string _maSV,string _hoTen,vector<Quyen_sach> _dsDangMuon);

	string getMaSV();
	string getHoTen();
	vector<Quyen_sach>& getDsDangMuon();

	void setMaSV(string);
	void setHoTen(string);
	void setDsDangMuon(vector<Quyen_sach>);

	void muonSach(Quyen_sach qsach);
	void traSach(Quyen_sach qsach);
	void view();

	Sinh_vien();
	~Sinh_vien();
};

