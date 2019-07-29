#include "Sach.h"
string IntToString(int value,int digitsCount){
	ostringstream os;
	os << setfill('0') << setw(digitsCount) << value;
	return os.str();
}
Sach::Sach(string _maSach,string _tenSach,string _tacGia,int _copies){
	this->maSach = _maSach;
	this->tenSach = _tenSach;
	this->tacGia = _tacGia;
	this->copies = _copies;
	this->available = _copies;

	for (int i = 0; i < _copies;i++){
		string _maQuyen = _maSach + IntToString(i,4);
		dsQyenSach.push_back(*(new Quyen_sach(_maSach,_maQuyen,true)));
	}
}
Sach::Sach(string _maSach,string _tenSach,string _tacGia){
	this->maSach = _maSach;
	this->tenSach = _tenSach;
	this->tacGia = _tacGia;
}

void Sach::setAvailable(int newAvailable){
	this->available = newAvailable;
}
void Sach::setCopies(int _copies){
	this->copies = _copies;
}
void Sach::setMaSach(string _maSach){
	this->maSach = _maSach;
}
void Sach::setTenSach(string _tenSach){
	this->tenSach = _tenSach;
}
void Sach::setTacGia(string _tacGia){
	this->tacGia = _tacGia;
}
void Sach::setDsQuyenSach(vector<Quyen_sach> dsqs){
	this->dsQyenSach = dsqs;
}

vector<Quyen_sach>& Sach::getDsQuyenSach(){return this->dsQyenSach;}
string Sach::getMaSach(){ return this->maSach; }
string Sach::getTacGia(){ return this->tacGia; }
string Sach::getTenSach(){ return this->tenSach; }
int Sach::getCopies(){ return this->copies; }
int Sach::getAvailable(){ return this->available; }

void Sach::view(){
	cout << setw(10) << left << maSach << setw(30) << left << tenSach << setw(20) << tacGia << setw(5) << left << copies << setw(5) << left << available << endl;
}

Quyen_sach* Sach::getQuyenSachSanSangDauTien(){
	for (auto i = dsQyenSach.begin(); i != dsQyenSach.end(); i++){
		if (i->getStatus()){
			return &(*i);
		}
	}
	return nullptr;
}

Quyen_sach* Sach::getQuyenSachByCode(string _maQuyen){
	for (auto i = dsQyenSach.begin(); i != dsQyenSach.end();i++){
		if (i->getMaQuyen() == _maQuyen){
			return &(*i);
		}
	}
	return nullptr;
}



Sach::Sach()
{
}


Sach::~Sach()
{
}
