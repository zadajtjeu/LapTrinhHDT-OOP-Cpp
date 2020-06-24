#include<iostream>
using namespace std;
long long luongcb_CB;
long long luongcb_GV;

class canbo{
protected:
	char macb[15], madv[15],bh[15];
	int ns;
	float hs;
	long pc_caan;
public:
	void nhap();
	void xuat();
	long long luong_cb();
};
class GV : public canbo{
	int choice;
	long pc_lop;
	long pc_hochai;
public:
	void nhap();
	void xuat();
	long long luong_gv();
};
void canbo:: nhap(){
	cout<<" - Nhap ma can bo (VD: CB1): ";fflush(stdin);gets(macb);
	cout<<" - Nhap ma don vi (VD:DV1): ";fflush(stdin);gets(madv);
	cout<<" - Nhap nam sinh (VD:1985): ";cin>>ns;
	cout<<" - Nhap he so luong (VD:2.6): "; cin>>hs;
	cout<<" - Nhap tien phu cap ca an (VD:200000 VND): "; cin>>pc_caan;
	cout<<" - Nhap bao hiem (VD BICare): ";fflush(stdin);gets(bh);
}
void canbo :: xuat(){
	cout<<" - Ma : "<<macb<<endl;
	cout<<" - Ma don vi :"<<madv<<endl;
	cout<<" - Nam sinh: "<<ns<<endl;
	cout<<" - He so luong :"<<hs<<endl;
	cout<<" - Tien phu cap ca an :"<<pc_caan<<" VND"<<endl;
	cout<<" - Bao hiem :"<<bh<<endl;
}
long long canbo:: luong_cb(){
	long long luong_cb;
	luong_cb=hs*luongcb_CB+pc_caan;
	return luong_cb;
}
void GV:: nhap(){
	canbo::nhap();
	cout<<" - Co phu cap doc hai hay ko:  ";
	cout<<" Co (1) || Khong (0) ? ";cin>>choice;
	cout<<endl;
}
void GV :: xuat(){
	canbo:: xuat();
	pc_lop=0.25*luongcb_GV;
	cout<<" - Tien phu cap lop: "<<pc_lop<<" VND"<<endl;
	if(choice==1){
		pc_hochai=luongcb_GV*0.1;
		cout<<" - Tien pc doc hai: "<<pc_hochai<<" VND";
		cout<<endl;
	}
}
long long GV::luong_gv(){
	pc_lop=0.25*luongcb_GV;
	long long luong_gv;
	luong_gv = (luongcb_GV*hs)+ pc_caan + pc_hochai + pc_lop;
	return luong_gv;
}
int main(){
	canbo cb[100];
	GV g[100];
	int m,n;
	cout<<"* Nhap so can bo: ";cin>>m;
	cout<<"* Nhap so giang vien: ";cin>>n;
	cout<<"** Nhap luong co ban can bo :"; cin>>luongcb_CB;
	cout<<"** Nhap luong co ban giang vien :";cin>>luongcb_GV;

	cout<<endl<<"=========== Nhap Thong Tin ==========="<<endl;
	for(int i=0; i<m;i++){
		cout<<"\n# Nhap thong tin can bo thu "<<i+1<<": "<<endl;
		cb[i].nhap();
	}
	for(int i=0;i<n;i++){
		cout<<"\n## Nhap thong tin giang vien thu "<<i+1<<": "<<endl;
		g[i].nhap();
	}


	cout<<"\n=========== Thong tin can bo va giang vien ===========\n";
	for(int i=0;i<m;i++){
		cout<<endl;
		cb[i].xuat();
		cout<<"=> Luong can bo "<<cb[i].luong_cb()<<" VND";
		cout<<endl;
	}
	for(int i=0;i<n;i++){
		cout<<endl;
		g[i].xuat();
		cout<<"=> Luong giang vien "<<g[i].luong_gv()<<" VND";
		cout<<endl;
	}
	cout<<"\n=========== Danh sach phai dong thue ===========\n";
	for(int i=0;i<m;i++){
		if(cb[i].luong_cb()>5000000){
			cout<<endl;
			cb[i].xuat();
			cout<<"=> Luong "<<cb[i].luong_cb()<<" VND";
			cout<<endl;
		}
	}
	for(int i=0;i<m;i++){
		if(g[i].luong_gv()>5000000){
			cout<<endl;
			g[i].xuat();
			cout<<"=> Luong "<<g[i].luong_gv()<<" VND";
			cout<<endl;
		}
	}
}


/* test case
2
2
1460000
1600000
CB1
DV1
1988
2.6
200000
BI
CB2
DV1
1984
2.9
200000
BI
CB3
DV2
1990
3.3
300000
BIA
1
CB4
DV2
1985
2.9
300000
BIA
0

*/