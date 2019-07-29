#pragma once
#include "thu_vien_chung.h"

#include "Sach.h"
#include "Quyen_sach.h"
#include "Ban_ghi_muon.h"
#include "Ban_ghi_tra.h"
#include "Sinh_vien.h"

class Thu_vien{
private:
	vector<Sinh_vien> dsSV;
	vector<Sach> dsSach;
	vector<Ban_ghi_muon> dsDangMuon;
	vector<Ban_ghi_tra> dsDaTra;

public:
	Thu_vien(vector<Sach> _dsSach,vector<Sinh_vien> _dsSV,vector<Ban_ghi_muon> _dsDangMuon,vector<Ban_ghi_tra> _dsDaTra);

	vector<Ban_ghi_muon>& getDsDangMuon();
	vector<Ban_ghi_tra>& getDsDaTra();
	vector<Sach>& getDsSach();
	vector<Sinh_vien>& getDsSV();

	Sinh_vien* getSinhVienByMaSV(string _maSV);

	Sach* getSachByMaSach(string _maSach);
	Sach* getSachByTen(string _tenSach);


	void addSach(Sach newSach);
	void addSinhVien(Sinh_vien newSV);


	void delSach(string _tenSach);
	void delSinhVien(string _maSV);

	void editSach(string _tenSach,string newTitle,string newAuthor);
	void editSinhVien(string _maSV,string newName);

	void viewDsSach();
	void viewDsSinhVien();

	void choMuonSach(string _maSV,string _maSach);
	void choTraSach(string _maSV,string _maQuyenSach,string _maSach);


	void save(string sachPath,string svPath,string banghimuonPath,string banghitraPath);
	void saveDataSach(string sachPath);
	void saveDataSinhVien(string svPath);
	void saveDataMuonSach(string banghimuonPath);
	void saveDataTraSach(string banghitraPath);

	void loadData(string sachPath,string svPath,string banghimuonPath,string banghitraPath);
	void loadDataSach(string sachPath);
	void loadDataSinhVien(string svPath);
	void loadDataMuonSach(string banghimuonPath);
	void loadDataTraSach(string banghitraPath);

	Thu_vien();
	~Thu_vien();
};
