#include "Sinh_vien.h"



Sinh_vien::Sinh_vien(){}
Sinh_vien::Sinh_vien(string _maSV,string _hoTen){
	this->maSV = _maSV;
	this->hoTen = _hoTen;
};
Sinh_vien::Sinh_vien(string _maSV,string _hoTen,vector<Quyen_sach> _dsDangMuon){
	this->maSV = _maSV;
	this->hoTen = _hoTen;
	this->dsDangMuon = _dsDangMuon;
};

void Sinh_vien::view(){
	cout << "Ma sinh vien: " << maSV << ' ';
	cout << "Ho ten: " << hoTen << endl;
	cout << "Sach dang muon: " << dsDangMuon.size() << endl;

	for (auto i = dsDangMuon.begin(); i != dsDangMuon.end(); i++){
		i->view();
	}
	cout << endl;
};

string Sinh_vien::getMaSV(){
	return this->maSV;
}
string Sinh_vien::getHoTen(){
	return this->hoTen;
}
vector<Quyen_sach>& Sinh_vien::getDsDangMuon(){
	return this->dsDangMuon;

};
void Sinh_vien::setMaSV(string _maSV){ this->maSV = _maSV; }
void Sinh_vien::setHoTen(string _hoTen){ this->hoTen = _hoTen; };
void Sinh_vien::setDsDangMuon(vector<Quyen_sach> ds){ this->dsDangMuon = ds; };



void Sinh_vien::muonSach(Quyen_sach qs){
	this->dsDangMuon.push_back(qs);
};
void Sinh_vien::traSach(Quyen_sach qs){
	int index = 0;
	for (auto i = this->dsDangMuon.begin(); i != dsDangMuon.end(); i++){
		//overloading operator fail.
		//if ((*i) == qs)
		if (i->getMaQuyen()== qs.getMaQuyen()){
			dsDangMuon.erase(dsDangMuon.begin() + index);
			break;
		}
		index++;
	}

};

Sinh_vien::~Sinh_vien(){}
