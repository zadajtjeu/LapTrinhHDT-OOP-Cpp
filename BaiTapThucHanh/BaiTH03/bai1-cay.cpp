#include <bits/stdc++.h>

using namespace std;

class CAY
{
protected:
	double chieuCao, doTuoi, chuViTan;
public:
	virtual void nhap()
	{
		cout<<"Nhap thong tin cay"<<endl;
		cout<<"Nhap chieu cao cay: ";
		cin>>chieuCao;
		cout<<"Nhap do tuoi: ";
		cin>>doTuoi;
		cout<<"Nhap chu vi tan: ";
		cin>>chuViTan;
		cout<<endl;
	}

	virtual void xuat()
	{
		cout<<"Thong tin Cay "<<endl; 
		cout<<"Chieu cao cay: "<<chieuCao<<endl;
		cout<<"Do tuoi cay: "<<doTuoi<<endl;
		cout<<"Chu vi tan: "<<chuViTan<<endl;
		cout<<endl;
	}
};

class CayCanh : public CAY
{
private:
	long long gia;
	string chungLoai;
public:
	void nhap()
	{
		cout<<"Nhap thong tin cay canh"<<endl;
		cout<<"Nhap chieu cao cay: ";
		cin>>chieuCao;
		cout<<"Nhap do tuoi cay: ";
		cin>>doTuoi;
		cout<<"Nhap chu vi tan: ";
		cin>>chuViTan;
		cout<<"Nhap gia thanh: ";
		cin>>gia;
		cout<<"Nhap vao chung loai: ";
		cin.ignore();
		getline(cin,chungLoai);
		cout<<endl;
	}
	void xuat()
	{
		cout<<"Thong tin Cay Canh "<<endl; 
		cout<<"Chieu cao cay: "<<chieuCao<<endl;
		cout<<"Do tuoi cay: "<<doTuoi<<endl;
		cout<<"Chu vi tan: "<<chuViTan<<endl;
		cout<<"Gia thanh: "<<gia<<endl;
		cout<<"Chung loai: "<<chungLoai<<endl;
		cout<<endl;
	}
	
};

int main(int argc, char const *argv[])
{
	CAY a, *p;
	CayCanh b;

	p = &a;
	p->nhap(); // nhap lop CAY
	p = &b;
	p->nhap(); // nhap lop CayCanh

	p = &a;
	p->xuat(); // xuat lop CAY
	p = &b;
	p->xuat(); // xuat lop CayCanh

	return 0;
}