#include "Quyen_sach.h"
Quyen_sach::Quyen_sach (string _maSach,string _maQuyen,bool _isSanSang){
	this->maSach = _maSach;
	this->maQuyen = _maQuyen;
	this->isSanSang = _isSanSang;
};

void Quyen_sach::setMaQuyen (string _maQuyen){
	this->maQuyen = _maQuyen;
}
void Quyen_sach::setMaSach (string _maSach){
	this->maSach = _maSach;
}
void Quyen_sach::setStatus (bool _isSanSang){
	this->isSanSang = _isSanSang;
}

string Quyen_sach::getMaQuyen () const {
	return this->maQuyen;
}
string Quyen_sach::getMaSach () const{
	return this->maSach;
}
bool Quyen_sach::getStatus () const{
	return this->isSanSang;
}
void Quyen_sach::view (){
	string status = (isSanSang)?"san sang"  :"dang duoc muon" ;
	cout << setw (10) << left << maSach << setw (10) << left << maQuyen << setw (20) << left << status << endl;
}

void Quyen_sach::operator=(const Quyen_sach& anotherQuyenSach){
	setMaSach (anotherQuyenSach.getMaSach ());
	setMaQuyen (anotherQuyenSach.getMaQuyen ());
	setStatus (anotherQuyenSach.getStatus ());
}
bool Quyen_sach::operator==(const Quyen_sach& anotherQuyenSach){
	return (maSach == anotherQuyenSach.getMaSach ()) && (maQuyen == anotherQuyenSach.getMaQuyen ()) && (isSanSang == anotherQuyenSach.getStatus ());

}




Quyen_sach::Quyen_sach()
{
}


Quyen_sach::~Quyen_sach()
{
}
