

#include"Thu_vien_chung.h"
#include "Thu_vien.h"
string firstFromNSubstring(string input,int n){
	//return retstring after cut n-end-characters
	int inputSize = input.size();
	return (n > 0 && inputSize > n) ? input.substr(0,inputSize - n) : "";
}
void QuanLyThongTinSach(Thu_vien&);
void QuanLyThongTinSinhVien(Thu_vien&);
void QuanLyThongTinMuonSach(Thu_vien&);
void QuanLyThongTinTraSach(Thu_vien&);
int main(){
	int lua_chon = 0;
	string ql_sach = "1.Quan ly thong tin dau sach\n";
	string ql_sv = "2.Quan ly thong tin sinh vien\n";
	string ql_muon = "3.Quan ly thong tin muon sach\n";
	string ql_tra = "4.Quan ly thong tin tra sach \n";
	string ql_exit = "5.Thoat chuong trinh\n";
	auto prevExceptionMask = cin.exceptions();
	Thu_vien myLib;
	myLib.loadData("sach.txt","sinhvien.txt","banghimuon.txt","banghitra.txt");
	do{
		try{
			lua_chon = 0;
			string luaChonStr = "";
			std::system("CLS");
	
			cout << ql_sach << ql_sv << ql_muon << ql_tra << ql_exit << endl;
			cin.exceptions(istream::failbit);
			cout << "Nhap vap lua chon: ";
			getline(cin,luaChonStr);

			//use string boi vi cpp sida khi ket hop cin voi chuoi , co the bi nham ky tu '\n'
			lua_chon = (luaChonStr == "")?0:stoi(luaChonStr,nullptr);
			//mac dinh stoi dung he co so base 10, neu khong nhap gi ma Enter se bi loi break

			cout << "Ban chon: " << lua_chon << endl;
			std::system("pause");
			switch (lua_chon){
				case 1:
				{
					std::system("CLS");
					QuanLyThongTinSach(myLib);
					myLib.save("sach.txt","sinhvien.txt","banghimuon.txt","banghitra.txt");
					break;
				}
				case 2:
				{
					std::system("CLS");
					QuanLyThongTinSinhVien(myLib);
					myLib.save("sach.txt","sinhvien.txt","banghimuon.txt","banghitra.txt");

					break;
				}
				case 3:
				{
					std::system("CLS");
					QuanLyThongTinMuonSach(myLib);
					myLib.save("sach.txt","sinhvien.txt","banghimuon.txt","banghitra.txt");
					break;
				}
				case 4:
				{
					std::system("CLS");
					QuanLyThongTinTraSach(myLib);
					myLib.save("sach.txt","sinhvien.txt","banghimuon.txt","banghitra.txt");
					break;
				}
				case 5:
				{
					myLib.save("sach.txt","sinhvien.txt","banghimuon.txt","banghitra.txt");
					cout << "Have a nice day.\n";
					std::system("pause");
					return 0;
					break;
				}
				default: { cout << "Have a nice day.\n"; }
			}
		} catch (const ios::failure &){
			cout << "Ban vua nhap khong phai la so!\n";
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			continue;
		}
		cin.exceptions(prevExceptionMask);
	} while (lua_chon != 5);
	return 0;
}
void QuanLyThongTinSach(Thu_vien& tv){
	int chucNangSach = 0;
	string viewDsSach = "1.Xem danh sach Sach trong thu vien\n";
	string searchSach = "2.Tim kiem Sach trong thu vien\n";
	string addSach = "3.Them mot dau sach\n";
	string editSach = "4.Sua mot dau sach\n";
	string returnPrev = "5.Tro ve \n";
	do{
		std::system("CLS");
		chucNangSach = 0;
		string chucNang = "";
		
		cout << "Chuc nang 1" << endl;
		cout << viewDsSach << searchSach << addSach << editSach << returnPrev;
		
		cout << "Ban chon: ";
		getline(cin,chucNang);
		chucNangSach = (chucNang == "")?0:stoi(chucNang,nullptr);
		
		switch (chucNangSach){
			case 1:
			{
				std::system("CLS");
				cout << "Danh sach Dau Sach" << endl;
				tv.viewDsSach();
				system("pause");
				break;
			}
			case 2:
			{
				std::system("CLS");
				string keyWord = "";
				
				cout << "Tim kiem sach" << endl;
				cout << "Nhap vao tu khoa de tim kiem: ";
				getline(cin,keyWord);

				if (keyWord == ""){
					cout << "Hay nhap vao mot tu!" << endl;
				}
				else{
					if (tv.getSachByTen(keyWord)){
						cout << "Tim thay sach: " << endl;
						tv.getSachByTen(keyWord)->view();
					}
					else{
						cout << "Khong tim thay sach." << endl;
					}
				}
				system("pause");

				break;
			}
			case 3:
			{
				std::system("CLS");
				cout << "Them mot dau sach" << endl;
				
				string maSach = "";
				string tenSach = "";
				string tacGia = "";
				int copies = 0;
				int available = 0;

				cout << "Nhap vao ma sach: ";
				getline(cin,maSach);
				if (tv.getSachByMaSach(maSach)){
					cout << "Ma sach nay da co trong thu vien.\n";
					system("pause");

					break;
				}
				else{
					string soLuong = "";
					cout << "Nhap vao ten sach: ";
					getline(cin,tenSach);

					cout << "Nhap vao tac gia: ";
					getline(cin,tacGia);

					cout << "Nhap vao so luong quyen sach: ";
					getline(cin,soLuong);
					
					copies = (soLuong == "")?0:stoi(soLuong,nullptr);
					
					if (maSach =="" || tenSach=="" || tacGia == ""){
						cout << "Thong tin khong hop le.\n";
						system("pause");

						break;
					}
					Sach newSach(maSach,tenSach,tacGia,copies);
					tv.getDsSach().push_back(newSach);
				}
				cout << "Da them sach.\n";
				system("pause");
				break;
			}
			case 4:
			{
				std::system("CLS");
				string keyWord = "";
				
				cout << "Sua thong tin sach" << endl;
				cout << "Nhap vao tu khoa de tim kiem: ";

				getline(cin,keyWord);

				if (keyWord == ""){
					cout << "Hay nhap vao mot tu!" << endl;
				}
				else{
					if (tv.getSachByTen(keyWord)){
						string newTen = "";
						string newTacGia = "";
						Sach* refSach = tv.getSachByTen(keyWord);

						cout << "Tim thay sach: " << endl;
						refSach->view();

						cout << "Ten sach moi: ";
						getline(cin,newTen);
						cout << "Tac gia moi: ";
						getline(cin,newTacGia);


						refSach->setTenSach(newTen);
						refSach->setTacGia(newTacGia);

						cout << "Updated!.\n";
						system("pause");
						break;

					}
					else{
						cout << "Khong tim thay sach." << endl;
						system("pause");
						break;
					}
				}
				system("pause");
				break;
			}
			case 5:
			{
				system("pause");
				break;
			}
			default:
			{
				system("pause");
				break;
			}

		}
	} while (chucNangSach != 5);

};
void QuanLyThongTinSinhVien(Thu_vien& tv){
	int chucNangSV = 0;
	string viewDsSV = "1.Xem danh sach Sinh vien trong thu vien\n";
	string searchSV = "2.Tim kiem Sinh vien trong thu vien\n";
	string addSV = "3.Them mot Sinh vien\n";
	string editSV = "4.Sua thong tin sinh vien\n";
	string returnPrev = "5.Tro ve \n";
	do{
		std::system("CLS");
		chucNangSV = 0;
		string chucNang = "";
		cout << "Chuc nang 2" << endl;
		cout << viewDsSV << searchSV << addSV << editSV << returnPrev;

		cout << "Ban chon: ";
		getline(cin,chucNang);
		chucNangSV = (chucNang == "")?0:stoi(chucNang,nullptr);

		switch (chucNangSV){
			case 1:
			{
				std::system("CLS");
				cout << "Danh sach sinh vien " << endl;
				tv.viewDsSinhVien();
				system("pause");
				break;
			}
			case 2:
			{
				std::system("CLS");
				string keyWord = "";

				cout << "Tim kiem sinh vien" << endl;
				cout << "Nhap vao ma sinh vien: ";

				getline(cin,keyWord);

				if (keyWord == ""){
					cout << "Hay nhap vao!" << endl;
				}
				else{
					if (tv.getSinhVienByMaSV(keyWord)){
						cout << "Tim thay sinh vien: " << endl;
						tv.getSinhVienByMaSV(keyWord)->view();
					}
					else{
						cout << "Khong tim thay." << endl;
					}
				}
				system("pause");

				break;
			}
			case 3:
			{
				std::system("CLS");
				string maSV = "";
				string tenSV = "";

				cout << "Them mot sinh vien" << endl;
				cout << "Nhap vao ma sinh vien: ";

				getline(cin,maSV);
				if (tv.getSinhVienByMaSV(maSV)){
					cout << "Ma nay da co trong thu vien.\n";
					system("pause");

					break;
				}
				else{
					cout << "Nhap vao ten sinh vien: ";
					getline(cin,tenSV);
					if (maSV=="" || tenSV == ""){
						cout << "Thong tin khop hop le.\n";
						system("pause");
						break;
					}

					Sinh_vien newSinhVien(maSV,tenSV);
					tv.getDsSV().push_back(newSinhVien);
				}
				cout << "Da them sinh vien.\n";

				system("pause");
				break;
			}
			case 4:
			{
				std::system("CLS");
				string keyWord = "";

				cout << "Sua thong tin sinh vien" << endl;
				cout << "Nhap vao ma sinh vien: ";

				getline(cin,keyWord);

				if (keyWord == ""){
					cout << "Hay nhap vao!" << endl;
				}
				else{
					if (tv.getSinhVienByMaSV(keyWord)){
						string newTen = "";
						Sinh_vien* refSV = tv.getSinhVienByMaSV(keyWord);

						cout << "Tim thay sinh vien: " << endl;
						refSV->view();

						cout << "Ten moi: ";
						getline(cin,newTen);

						refSV->setHoTen(newTen);

						cout << "Updated!.\n";
					}
					else{
						cout << "Khong tim thay sinh vien." << endl;
					}
				}
				system("pause");

				break;
			}
			case 5:
			{
				system("pause");
				break;
			}
			default:
			{
				system("pause");
				break;
			}
		}
	} while (chucNangSV != 5);
};
void QuanLyThongTinMuonSach(Thu_vien& tv){
	string viewDsBanGhiMuon = "1.Xem danh sach dang muon.\n";
	string addNewRecord = "2.Them mot ban ghi muon.\n";
	string returnPrev = "3.Tro ve \n";
	int chucNangMuonSach = 0;
	do{
		std::system("CLS");

		chucNangMuonSach = 0;
		string chucNang = "";
		cout << "Chuc nang 3" << endl;

		cout << viewDsBanGhiMuon << addNewRecord << returnPrev;
		cout << "Ban chon: ";
		getline(cin,chucNang);
		chucNangMuonSach =(chucNang =="")?0: stoi(chucNang,nullptr);

		switch (chucNangMuonSach){
			case 1:
			{
				std::system("CLS");
				cout << "Danh sach nhung cuon sach dang muon: "<< tv.getDsDangMuon().size() << endl;
				for (auto i = tv.getDsDangMuon().begin(); i != tv.getDsDangMuon().end();i++){
					i->view();
				}
				system("pause");
				break;
			}
			case 2:
			{
				std::system("CLS");
				string maSV = "";
				
				cout << "Them mot ban ghi muon" << endl;
				cout << "Nhap vao ma sinh vien: ";

				getline(cin,maSV);

				if (maSV == ""){
					cout << "Hay nhap vao!" << endl;
				}
				else{
					if (tv.getSinhVienByMaSV(maSV)){
						string keyword = "";
						
						cout << "Tim thay sinh vien: " << endl;
						tv.getSinhVienByMaSV(maSV)->view();

						cout << "Tim kiem sach, nhap vao tu khoa: ";
						getline(cin,keyword);
						if (keyword == ""){
							cout << "Hay nhap vao!";
							break;
						}
						if (tv.getSachByTen(keyword)){
							string temp = "";
							bool    confirm = false     ;
							cout << "Tim thay sach: " << endl;
							tv.getSachByTen(keyword)->view();
							
							if (tv.getSachByTen(keyword)->getAvailable() == 0){
								cout << "Sach hien dang duoc muon het, hay chon cuon khac.\n";
								system("pause");
								break;
							}
							cout << "Xac nhan muon (Y/N): ";
							getline(cin,temp);

							confirm = (temp == "Y") ? true : false;
							if (confirm){
								tv.choMuonSach(maSV,tv.getSachByTen(keyword)->getMaSach());
								cout << "Da them mot ban ghi.\nMuon sach thanh cong.\n";
							}
							else{
								cout << "exiting...\n";
								system("pause");
								break;
							}
						}
						else{
							cout << "Khong tim thay sach." << endl;
							system("pause");
							break;
						}


					}
					else{
						cout << "Khong tim thay." << endl;
						system("pause");
						break;
					}
				}
				system("pause");
				break;
			}
			case 3:
			{
				system("pause");
				break;
			}
			default:
			{
				system("pause");
				break;
			}
		}
	} while (chucNangMuonSach != 3);

};
void QuanLyThongTinTraSach(Thu_vien& tv){
	string viewDsBanGhiTra = "1.Xem danh sach da tra.\n";
	string addBanGhiMoi = "2.Them mot ban ghi tra.\n";
	string returnPrev = "3.Tro ve \n";
	int chucNangTraSach = 0;
	do{
		std::system("CLS");

		chucNangTraSach = 0;
		string chucNang = "";
		cout << "chuc nang 4" << endl;

		cout << viewDsBanGhiTra << addBanGhiMoi << returnPrev;
		cout << "Ban chon: ";
		getline(cin,chucNang);
		chucNangTraSach = (chucNang == "") ? 0 : stoi(chucNang,nullptr);

		switch (chucNangTraSach){
			case 1:
			{
				std::system("CLS");
				cout << "Danh sach nhung cuon sach da tra: " << tv.getDsDaTra().size() << endl;
				for (auto i = tv.getDsDaTra().begin(); i != tv.getDsDaTra().end();i++){
					i->view();
				}
				system("pause");
				break;
			}
			case 2:
			{
				std::system("CLS");
				string maSV = "";

				cout << "Them mot ban ghi tra" << endl;
				cout << "Nhap vao ma sinh vien: ";

				getline(cin,maSV);

				if (maSV == ""){
					cout << "Hay nhap vao!" << endl;
				}
				else{
					if (tv.getSinhVienByMaSV(maSV)){
						string maQuyen = "";

						cout << "Tim thay sinh vien: " << endl;
						tv.getSinhVienByMaSV(maSV)->view();

						cout << "Nhap vao ma quyen sach: ";
						getline(cin,maQuyen);
						
						if (maQuyen == ""){
							cout << "Hay nhap vao!";
							break;
						}
						bool checkTraThanhCong = false;

						for (auto i = tv.getDsDangMuon().begin(); i != tv.getDsDangMuon().end();i++){
							if (i->getMaQuyen() == maQuyen){
								string maSach = firstFromNSubstring(maQuyen,4);
								tv.choTraSach(maSV,maQuyen,maSach);

								checkTraThanhCong = true;
								cout << "Da them mot ban ghi. Tra sach thanh cong.\n";
				
								system("pause");
								break;
							}
						}
						if (checkTraThanhCong == false){
							cout << "Quyen sach khong co trong danh sach dang muon, hay kiem tra lai.\n";

						}
						
						system("pause");
						break;

					}
					else{
						cout << "Khong tim thay, sinh vien khong co trong danh sach." << endl;
						
						system("pause");
						break;
					}
				}
				system("pause");
				break;
			}
			case 3:
			{
				system("pause");
				break;
			}
			default:
			{
				system("pause");
				break;
			}

		}
	} while (chucNangTraSach != 3);
};
