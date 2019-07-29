#include "Ban_ghi_muon.h"

Ban_ghi_muon::Ban_ghi_muon(){}


Ban_ghi_muon::Ban_ghi_muon(string _maQuyen,string _maSV,string _ngayMuon,int _limit){
	this->maQuyen = _maQuyen;
	this->maSV = _maSV;
	this->ngayMuon = _ngayMuon;
	this->limit = _limit;

};
string Ban_ghi_muon::getMaQuyen(){

	return this->maQuyen;
};
string Ban_ghi_muon::getMaSV(){
	return this->maSV;
};
string Ban_ghi_muon::getNgayMuon(){
	return this->ngayMuon;
};


void Ban_ghi_muon::setMaQuyen(string _maQuyen){
	this->maQuyen = _maQuyen;

}
void Ban_ghi_muon::setMaSV(string _maSV){
	this->maSV = _maSV;

}
void Ban_ghi_muon::setNgayMuon(string _ngayMuon){
	this->ngayMuon = _ngayMuon;

}

void Ban_ghi_muon::view(){
	cout << setw(10) << left << maSV << setw(10) << left << maQuyen << setw(25) << left << ngayMuon << setw(5) << left << limit << endl;
};

Ban_ghi_muon::~Ban_ghi_muon(){}
