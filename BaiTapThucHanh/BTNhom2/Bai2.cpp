#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class TuyenSinh;

class A
{
    float toan, ly, hoa;
public:
    friend class SinhVien;
    friend istream& operator>>(istream& in, TuyenSinh &sv);
    friend ostream& operator<<(ostream& out, TuyenSinh sv);
};
class B
{
    float toan, hoa, sinh;
public:
    friend class SinhVien;
    friend istream& operator>>(istream& in, TuyenSinh &sv);
    friend ostream& operator<<(ostream& out, TuyenSinh sv);
};
class C
{
    float van, su, dia;
public:
    friend class SinhVien;
    friend istream& operator>>(istream& in, TuyenSinh &sv);
    friend ostream& operator<<(ostream& out, TuyenSinh sv);
};
class SinhVien
{
    string sbd;
    string hoTen;
    string diaChi;
    float uutien;
    string khoi;
    float diem;
    A a;
    B b;
    C c;
public:
    friend istream& operator>>(istream& in, TuyenSinh &sv);
    friend ostream& operator<<(ostream& out, TuyenSinh sv);
    friend void trungTuyen(TuyenSinh *a, int n);
    friend void timSinhVien(TuyenSinh *a, int n);
};
class TuyenSinh: public SinhVien//, public A, public B, public C
{
    friend istream& operator>>(istream& in, TuyenSinh &sv);
    friend ostream& operator<<(ostream& out, TuyenSinh sv);
    friend void trungTuyen(TuyenSinh *a, int n);
    friend void timSinhVien(TuyenSinh *a, int n);
};

istream& operator>>(istream& in, TuyenSinh &sv)
{
    cout << "SDB: "; fflush(stdin); getline(in,sv.sbd);
    cout << "HoTen: "; getline(in,sv.hoTen);
    cout << "DiaChi: "; getline(in,sv.diaChi);
    cout << "Uu tien: "; in >> sv.uutien;

    cout << "Sinh vien thi khoi nao(A/B/C) : "; fflush(stdin); getline(in,sv.khoi);
    if(sv.khoi == "A")
    {
        cout << "\tDiem Toan: "; in >> sv.a.toan;
        cout << "\tDiem Ly: "; in >> sv.a.ly;
        cout << "\tDiem Hoa: "; in >> sv.a.hoa;
        sv.diem = sv.a.toan + sv.a.ly + sv.a.hoa + sv.uutien;
    }
    else if(sv.khoi == "B")
    {
        cout << "\tDiem Toan: "; in >> sv.b.toan;
        cout << "\tDiem Hoa: "; in >> sv.b.hoa;
        cout << "\tDiem Sinh: "; in >> sv.b.sinh;
        sv.diem = sv.b.toan + sv.b.hoa + sv.b.sinh + sv.uutien;
    }
    else if(sv.khoi == "C")
    {
        cout << "\tDiem Van: "; in >> sv.c.van;
        cout << "\tDiem Su: "; in >> sv.c.su;
        cout << "\tDiem Dia: "; in >> sv.c.dia;
        sv.diem = sv.c.van + sv.c.su + sv.c.dia + sv.uutien;
    }
    return in;
};
ostream& operator<<(ostream& out, TuyenSinh sv)
{
    out << left << setw(15) << sv.sbd << setw(15) << sv.hoTen << setw(15) << sv.diaChi;
    out << setw(15) << sv.uutien << setw(15) << sv.khoi << setw(15) << sv.diem << endl;
    return out;
};
//trung tuyen
void trungTuyen(TuyenSinh *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i].khoi == "A")
            if(a[i].diem >= 15)
                cout << a[i];
        if(a[i].khoi == "B")
            if(a[i].diem >= 16)
                cout << a[i];
        if(a[i].khoi == "C")
            if(a[i].diem >= 13.5)
                cout << a[i];
    }
};
//tim sinh vien
void timSinhVien(TuyenSinh *a, int n)
{
    string tim;
    cout << "\nNhap SBD can tim : "; fflush(stdin);getline(cin,tim);
    cout << "\n";
    cout << left << setw(15) << "SBD" << setw(15) << "HOTEN" << setw(15) << "DIACHI";
    cout << setw(15) << "UUTIEN" << setw(15) << "KHOI" << setw(15) << "DIEM" << endl;
    for(int i = 0; i < n; i++)
    {
        if(a[i].sbd == tim)
            cout << a[i];
    }
};
int main()
{
    int n;
    cout << "Nhap so sinh vien: "; cin >> n;
    TuyenSinh *a = new TuyenSinh[n];
    cout << "\n\t\t\tNHAP\n";
    for(int i = 0; i < n; i++)
    {
        cout << "\nSinh vien " << i + 1 << endl;
        cin >> a[i];
    }
    cout << "\n\t_______________XUAT________________\n";
    cout << left << setw(15) << "SBD" << setw(15) << "HOTEN" << setw(15) << "DIACHI";
    cout << setw(15) << "UUTIEN" << setw(15) << "KHOI" << setw(15) << "DIEM" << endl;
    for(int i = 0; i < n; i++)
    {

        cout << a[i];
    }
    cout << "\n\t____________Snh vien trung tuyen_____________\n\n";
    cout << left << setw(15) << "SBD" << setw(15) << "HOTEN" << setw(15) << "DIACHI";
    cout << setw(15) << "UUTIEN" << setw(15) << "KHOI" << setw(15) << "DIEM" << endl;
    trungTuyen(a,n);

    timSinhVien(a,n);

    return 0;
}
