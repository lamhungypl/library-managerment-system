#include "Ban_ghi_tra.h"

Ban_ghi_tra::Ban_ghi_tra(){}

Ban_ghi_tra::Ban_ghi_tra(string _maQuyen,string _maSV,string _ngayMuon,string _ngayTra){
	this->maQuyen = _maQuyen;
	this->maSV = _maSV;
	this->ngayMuon = _ngayMuon;
	this->ngayTra = _ngayTra;
};
string Ban_ghi_tra::getMaSV(){	return this->maSV;};
string Ban_ghi_tra::getMaQuyen(){	return this->maQuyen;};
string Ban_ghi_tra::getNgayTra(){	return this->ngayTra;}
string Ban_ghi_tra::getNgayMuon(){	return this->ngayMuon;}


void Ban_ghi_tra::setNgayTra(string d){	this->ngayTra = d;};
void Ban_ghi_tra::setNgayMuon(string d){	this->ngayMuon = d;};
void Ban_ghi_tra::setMaQuyen(string mq){ this->maQuyen = mq; }
void Ban_ghi_tra::setMaSV(string mssv){ this->maSV = mssv; }

void Ban_ghi_tra::view(){
	cout << setw(10) << left << maSV << setw(10) << left << maQuyen << setw(25) << left << ngayMuon << setw(25) << left << ngayTra << endl;
};



Ban_ghi_tra::~Ban_ghi_tra(){}
