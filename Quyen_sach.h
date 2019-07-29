#pragma once
#include"Thu_vien_chung.h"


class Quyen_sach
{
private:
	string maSach;
	string maQuyen;
	bool isSanSang;
public:
	Quyen_sach ();
	~Quyen_sach();
	Quyen_sach (string _maSach,string _maQuyen,bool _isSanSang);
	
	void setMaSach (string);
	void setMaQuyen (string);
	void setStatus (bool);

	string getMaSach () const;
	string getMaQuyen () const;
	bool getStatus () const;

	void view ();

	void operator=(const Quyen_sach&);
	bool operator==(const Quyen_sach&);

};

