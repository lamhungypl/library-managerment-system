#include "Thu_vien.h"
#include <algorithm>
#include <chrono> //curent time
#include<ctime>
std::string getTimeString(){
	std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	std::string s(30,'\0');
	std::strftime(&s[0],s.size(),"%Y-%m-%d %H:%M:%S",std::localtime(&now));
	//project properties -> cpp preprocessor -> _CRT_SECURE_NO_WARNINGS
	return s;
}

string last_n_substring(string input,int n){
	int inputSize = input.size();
	return (n > 0 && inputSize > n) ? input.substr(inputSize - n) : "";
}



string Int2String(int value,int digitsCount){
	ostringstream os;
	os << setfill('0') << setw(digitsCount) << value;
	return os.str();
};

Thu_vien::Thu_vien(){};

Thu_vien::Thu_vien(vector<Sach> _dsSach,vector<Sinh_vien> _dsSV,vector<Ban_ghi_muon> _dsDangMuon,vector<Ban_ghi_tra> _dsDaTra){
	this->dsSach = _dsSach;
	this->dsSV = _dsSV;
	this->dsDangMuon = _dsDangMuon;
	this->dsDaTra = _dsDaTra;
}



vector<Sach>& Thu_vien::getDsSach(){	return this->dsSach;};
vector<Ban_ghi_muon>& Thu_vien::getDsDangMuon(){	return this->dsDangMuon;};
vector<Ban_ghi_tra>& Thu_vien::getDsDaTra(){	return this->dsDaTra;};
vector<Sinh_vien>& Thu_vien::getDsSV(){	return this->dsSV;};

Sinh_vien* Thu_vien::getSinhVienByMaSV(string _maSV){
	for (auto i = dsSV.begin(); i != dsSV.end(); i++){
		if (i->getMaSV() == _maSV){
			return &(*i);
		}
	}
	return nullptr;
};

Sach* Thu_vien::getSachByMaSach(string _maSach){
	for (auto i = dsSach.begin(); i != dsSach.end(); i++){
		if (i->getMaSach() == _maSach){
			return &(*i);
		}
	}
	return nullptr;
};

Sach* Thu_vien::getSachByTen(string keyword){
	for (auto i = this->dsSach.begin(); i != this->dsSach.end(); i++){
		string tensach = i->getTenSach();
		if (tensach.find(keyword) != string::npos){
			//cout << "Tim thay ten sach!" << endl;
			return &(*i);
		}
	}
	return nullptr;
};



void Thu_vien::addSach(Sach newSach){	this->dsSach.push_back(newSach);};

void Thu_vien::addSinhVien(Sinh_vien newSV){ this->dsSV.push_back(newSV); };


void Thu_vien::delSach(string keyword){
	int index = 0;
	for (auto i = this->dsSach.begin(); i != this->dsSach.end(); i++){
		string tensach = i->getTenSach();

		if (tensach.find(keyword) != string::npos){
			cout << "Deleted " << i->getTenSach() << endl;
			this->dsSach.erase(this->dsSach.begin() + index);
			return;
		}
		index++;
	}
	cout << "sach khong ton tai!\n";
};
void Thu_vien::delSinhVien(string _maSV){
	int index = 0;
	for (auto i = this->dsSV.begin(); i != this->dsSV.end();
		i++){
		if (i->getMaSV() == _maSV){
			cout << "Deleted " << i->getMaSV() << ' ' << i->getHoTen();
			this->dsSV.erase(dsSV.begin() + index);
			return;
		}
		index++;
	}
	cout << "khong co sinh vien co ma sinh vien la" << _maSV << "\n";
};

void Thu_vien::editSach(string keyword,string newtensach,string newAuthor){
	for (auto i = this->dsSach.begin(); i != this->dsSach.end(); i++){
		string tensach = i->getTenSach();
		if (tensach.find(keyword) != string::npos){
			i->setTenSach(newtensach);
			i->setTacGia(newAuthor);
			return;
		}
	}
	cout << "Khong tim thay sach!\n";
};
void Thu_vien::editSinhVien(string _maSV,string newName){
	for (auto i = dsSV.begin(); i != dsSV.end(); i++){
		if (i->getMaSV() == _maSV){
			i->setHoTen(newName);
			return;
		}
	}
	cout << "Khong tim thay sinh vien tuong ung\n";
};

void Thu_vien::viewDsSach(){

	cout << setw(10) << left << "Ma sach" << setw(30) << left << "Ten sach" << setw(20) << "Tac gia" << setw(5) << left << "So ban" << setw(5) << left << "Co san" << endl;

	for (auto i = this->dsSach.begin(); i != this->dsSach.end(); i++){
		i->view();
	}
};

void Thu_vien::viewDsSinhVien(){
	cout << "Danh sach sinh vien da dang ky: " << dsSV.size() << endl;
	for (auto i = this->dsSV.begin(); i != this->dsSV.end();
		i++){
		i->view();
	}
};

void Thu_vien::choMuonSach(string _maSV,string _maSach){
	//string day = "Ngay muon";
	string ngayMuon = getTimeString();
	int limit = 10;
	
	Quyen_sach* refQuyen_sach;
	Sach* refSach;

	refSach = this->getSachByMaSach(_maSach);
	refQuyen_sach = refSach->getQuyenSachSanSangDauTien();

	//trang thai thanh "dang muon"
	refQuyen_sach->setStatus(false);
	
	//so luong giam 1
	refSach->setAvailable(refSach->getAvailable() - 1);

	//them ban ghi muon
	Ban_ghi_muon brRecord(refQuyen_sach->getMaQuyen(),_maSV,ngayMuon,limit);
	this->getDsDangMuon().push_back(brRecord);

	//nguoi dung them vao using
	this->getSinhVienByMaSV(_maSV)->muonSach(*refQuyen_sach);

};

void Thu_vien::choTraSach(string _maSV,string _maQuyen,string _maSach){
	string day_borrow = "";
	string day_return = "";
	
	day_return = getTimeString();

	Sinh_vien* refSinh_vien;
	refSinh_vien = this->getSinhVienByMaSV(_maSV);
	
	Sach* refSach;
	refSach = this->getSachByMaSach(_maSach);
	
	Quyen_sach* refQuyen_sach;
	refQuyen_sach = refSach->getQuyenSachByCode(_maQuyen);

	//trang thai thanh "san sang cho muon"
	refQuyen_sach->setStatus(true);
	//so luong tang len 1 quyen
	refSach->setAvailable(refSach->getAvailable() + 1);
	
	//Sinh_vien xoa using Sach
	refSinh_vien->traSach(*refQuyen_sach);

	//xoa ban ghi borrowing
	int index = 0;
	for (auto i = dsDangMuon.begin(); i != dsDangMuon.end(); i++){
		if (i->getMaQuyen() == _maQuyen){
			day_borrow = i->getNgayMuon();
			dsDangMuon.erase(dsDangMuon.begin() + index);
			break;
		}
		index++;
	}
	
	//them ban ghi tra sach
	Ban_ghi_tra rtRecord(_maQuyen,refSinh_vien->getMaSV(),day_borrow,day_return);
	this->getDsDaTra().push_back(rtRecord);

};

void Thu_vien::save(string SachPath,string svPath,string borrowPath,string returnPath){
	this->saveDataSach(SachPath);
	this->saveDataSinhVien(svPath);
	this->saveDataMuonSach(borrowPath);
	this->saveDataTraSach(returnPath);
};
void Thu_vien::loadData(string SachPath,string svPath,string borrowPath,string returnPath){
	this->loadDataSach(SachPath);
	this->loadDataSinhVien(svPath);
	this->loadDataMuonSach(borrowPath);
	this->loadDataTraSach(returnPath);
};


void Thu_vien::loadDataSach(string SachPath){
	string soqs = "";
	int soQuyenSach = 0;
	fstream fileSach;
	fileSach.open(SachPath,ios::in);

	getline(fileSach,soqs);
	soQuyenSach = (soqs == "")?0:stoi(soqs,nullptr);
	for (int i = 0; i < soQuyenSach; i++){
		string maSach = "";
		string tenSach = "";
		string tacGia = "";
		int copies = 0;
		string soBan = "";
		int available = 0;

		getline(fileSach,maSach);
		getline(fileSach,tenSach);
		getline(fileSach,tacGia);
		getline(fileSach,soBan);

		copies = (soBan == "") ? 0 : stoi(soBan,nullptr);

		//fileSach >> copies;
		available = copies;

		Sach dauSach(maSach,tenSach,tacGia);
		dauSach.setCopies(copies);
		dauSach.setAvailable(available);

		for (int j = 0; j < copies; j++){
			bool status = true;
			string temp = "";
			getline(fileSach,temp);

			status = (temp == "1") ? true : false;
			if (!status){
				available = available - 1;
				dauSach.setAvailable(available);
			}
			string maCuonSach = maSach + Int2String(j,4);
			dauSach.getDsQuyenSach().push_back(*(new Quyen_sach(maSach,maCuonSach,status)));

		}

		this->getDsSach().push_back(dauSach);
	}
}
void Thu_vien::loadDataSinhVien(string svPath){
	int soSinhVien = 0;
	string sosv = "";
	fstream fileSV;
	fileSV.open(svPath,ios::in);

	getline(fileSV,sosv);

	soSinhVien = stoi(sosv,nullptr,10);
	for (int i = 0; i < soSinhVien; i++){
		string maSV = "";
		string hoTen = "";
		string soSachMuonStr = "";
		int soSachMuon = 0;


		getline(fileSV,maSV);
		getline(fileSV,hoTen);
		getline(fileSV,soSachMuonStr);

		soSachMuon = (soSachMuonStr == "") ? 0 : stoi(soSachMuonStr,nullptr);
		//fileSV >> soSachMuon;

		Sinh_vien sv(maSV,hoTen);

		for (int j = 0; j< soSachMuon; j++){
			string maSach = "";
			string maQuyen = "";
			getline(fileSV,maSach);
			getline(fileSV,maQuyen);

			Quyen_sach qsachDangMuon = *(this->getSachByMaSach(maSach)->getQuyenSachByCode(maQuyen));

			sv.getDsDangMuon().push_back(qsachDangMuon);
		}

		this->getDsSV().push_back(sv);


	}
}
void Thu_vien::loadDataMuonSach(string borrowPath){
	int soBanGhiMuon = 0;
	string sobgm = "";
	fstream fileMuon;
	fileMuon.open(borrowPath,ios::in);

	getline(fileMuon,sobgm);

	soBanGhiMuon = (sobgm == "")?0:stoi(sobgm,nullptr,10);


	for (int i = 0; i < soBanGhiMuon; i++){
		string maQuyen = "";
		string maSV = "";
		string ngayMuon = "";
		string limitStr = "";
		int limit = 0;

		getline(fileMuon,maQuyen);
		getline(fileMuon,maSV);
		getline(fileMuon,ngayMuon);
		getline(fileMuon,limitStr);

		limit = (limitStr == "") ? 0 : stoi(limitStr,nullptr);
		//fileMuon >> limit;


		Ban_ghi_muon brRecord(maQuyen,maSV,ngayMuon,limit);

		this->getDsDangMuon().push_back(brRecord);

	}
}
void Thu_vien::loadDataTraSach(string returnPath){
	int soBanGhiTra = 0;
	string sobgt = "";
	fstream fileTra;
	fileTra.open(returnPath,ios::in);

	getline(fileTra,sobgt);

	soBanGhiTra = (sobgt=="")?0:stoi(sobgt,nullptr);

	for (int i = 0; i < soBanGhiTra; i++){
		string maQuyen = "";
		string maSV = "";
		string ngayMuon = "";
		string ngayTra = "";
		getline(fileTra,maQuyen);
		getline(fileTra,maSV);
		getline(fileTra,ngayMuon);
		getline(fileTra,ngayTra);


		Ban_ghi_tra rtRecord(maQuyen,maSV,ngayMuon,ngayTra);
		this->getDsDaTra().push_back(rtRecord);
	}
}

void Thu_vien::saveDataSach(string SachPath){
	fstream fileDich;
	fileDich.open(SachPath,ios::out);
	fileDich << this->getDsSach().size() << endl;
	for (unsigned int i = 0; i< this->getDsSach().size(); i++){
		Sach b = this->getDsSach().at(i);
		fileDich << b.getMaSach() << endl;
		fileDich << b.getTenSach() << endl;
		fileDich << b.getTacGia() << endl;
		fileDich << b.getCopies() << endl;
		for (int j = 0; j < b.getCopies(); j++){
			fileDich << b.getDsQuyenSach().at(j).getStatus() << endl;
		}
	}
}
void Thu_vien::saveDataSinhVien(string svPath){
	fstream fileDich;
	fileDich.open(svPath,ios::out);
	fileDich << this->getDsSV().size() << endl;

	for (unsigned int i = 0; i< this->getDsSV().size(); i++){
		Sinh_vien sv = this->getDsSV().at(i);
		fileDich << sv.getMaSV() << "\n" << sv.getHoTen() << "\n";
		fileDich << sv.getDsDangMuon().size() << endl;
		for (unsigned int j = 0; j < sv.getDsDangMuon().size(); j++){

			Quyen_sach qs = sv.getDsDangMuon().at(j);
			fileDich << qs.getMaSach() << endl;
			fileDich << qs.getMaQuyen() << endl;


		}
	}
}

void Thu_vien::saveDataMuonSach(string borrowPath){
	fstream fileDich;
	fileDich.open(borrowPath,ios::out);
	fileDich << this->getDsDangMuon().size() << endl;

	for (unsigned int i = 0; i< this->getDsDangMuon().size(); i++){
		Ban_ghi_muon br = this->getDsDangMuon().at(i);
		fileDich << br.getMaQuyen() << "\n" << br.getMaSV() << "\n" << br.getNgayMuon() << "\n" << 10 << endl;
	}
}
void Thu_vien::saveDataTraSach(string returnPath){
	fstream fileDich;
	fileDich.open(returnPath,ios::out);
	fileDich << this->getDsDaTra().size() << endl;

	for (unsigned int i = 0; i< this->getDsDaTra().size(); i++){
		Ban_ghi_tra rt = this->getDsDaTra().at(i);
		fileDich << rt.getMaQuyen() << "\n" << rt.getMaSV() << "\n" << rt.getNgayMuon() << "\n" << rt.getNgayTra() << endl;
	}
}
Thu_vien::~Thu_vien(){}
