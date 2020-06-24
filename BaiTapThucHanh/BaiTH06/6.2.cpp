#include <bits/stdc++.h>

using namespace std;

class VEHICLE
{
protected:
	string nhanHieu;
	int namsx;
	string hang;
public:
	void NHAP()
	{
		cout<<" - Nhap nhan hieu: ";
		getline(cin,nhanHieu);
		cout<<" - Nhap nam san xuat: ";
		cin>>namsx;
		cout<<" - Nhap hang san xuat: ";
		cin.ignore();
		getline(cin,hang);
	}
	void XUAT()
	{
		cout<<" - Nhan hieu: "<<nhanHieu<<endl;
		cout<<" - Nam san xuat: "<<namsx<<endl;
		cout<<" - Hang san xuat: "<<hang<<endl;
	}
};
class OTO: private VEHICLE
{
	int soChoNgoi;
	double dungtich;
public:
	void NHAP()
	{
		VEHICLE::NHAP();
		cout<<" - Nhap so cho ngoi: ";
		cin>>soChoNgoi;
		cout<<" - Nhap dung tich: ";
		cin>>dungtich;
		cin.ignore();
	}
	void XUAT()
	{
		VEHICLE::XUAT();
		cout<<" - So cho ngoi: "<<soChoNgoi<<endl;
		cout<<" - Dung tich: "<<dungtich<<endl;
	}
};

class MOTO: private VEHICLE
{
	double phankhoi;
public:
	void NHAP()
	{
		VEHICLE::NHAP();
		cout<<" - Nhap phan khoi xe: ";
		cin>>phankhoi;
		cin.ignore();
	}

	void XUAT()
	{
		VEHICLE::XUAT();
		cout<<" - Phan khoi xe: "<<phankhoi<<endl;
	}
};



int main(int argc, char const *argv[])
{
	OTO xe1;
	MOTO xe2;
	cout<<"* Nhap thong tin xe oto: "<<endl;
	xe1.NHAP();
	cout<<"* Nhap thong tin xe moto: "<<endl;
	xe2.NHAP();
	cout<<endl;
	cout<<"* Thong tin xe oto: "<<endl;
	xe1.XUAT();
	cout<<"* Thong tin xe moto: "<<endl;
	xe2.XUAT();
	
	return 0;
}