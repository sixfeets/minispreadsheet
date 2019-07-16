#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<conio.h>

using namespace std;

class spreadsheet{
	private:
		int sheet[10][10];
	public:
		char konver(int x){
			return (char)x+97;
		}
		void viewsheet(){
			for(char i='A';i<'K';i++){
				cout<<setw(6)<<i;
			}
			cout<<endl;
			for(int i=0;i<10;i++){
				cout<<i+1;
				for(int j=0;j<10;j++){
					cout<<setw(5)<<sheet[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		void baca(){
			ifstream data;
			data.open("datasheet.txt");
			cout<<endl;
			for(int i=0;i<10;i++){
				for(int j=0;j<10;j++){
					data>>sheet[i][j];
				}
			}
			data.close();	
		}
		void tulis(){
			ofstream file;
			file.open("datasheet.txt",ios::in);
			for(int i=0;i<10;i++){
				for(int j=0;j<10;j++){
					file<<sheet[i][j]<<" ";
				}
				file<<endl;
			}
			file.close();
		}
		int konversi(char x){
			return (int)x-96;
		}
		void pencarian(int a[10][10], int kunci){
			for(int i=0;i<10;i++){
				for(int j=0;j<10;j++){
					if(a[i][j]==kunci){
						cout<<"["<<konver(j)<<i+1<<"] "<<"Ketemu"<<endl;
					}				
				}
			}
		}
		void minimumbaris(int a[10][10], char n){
			int baris,kolom;
			int haha;
			haha=konversi(n);
			haha+=95;
			int min=a[haha][0];
			for(int i=0;i<10;i++){
				if(a[haha][i]<=min){
					min=a[haha][i];
					baris=haha;
					kolom=i;
				}
			}
			cout<<"Terkecil = "<<a[baris][kolom]<<endl;
		}
		void minimumkolom(int a[10][10], int n){
			int baris=0,kolom=0;
			n-=1;
			int min=a[0][n];
			for(int i=0;i<10;i++){
				if(a[i][n]<=min){
					min=a[i][n];
					baris=i;
					kolom=n;
				}
			}
			cout<<"Terkecil = "<<a[baris][kolom]<<endl;
					
		}
		void makbaris(int a[10][10], char n){
			int baris,kolom;
			int haha;
			haha=konversi(n);
			haha+=95;
			int min=a[haha][0];
			for(int i=0;i<10;i++){
				if(a[haha][i]>=min){
					min=a[haha][i];
					baris=haha;
					kolom=i;
				}
			}
			cout<<"Terbesar = "<<a[baris][kolom]<<endl;
		}
		void makkolom(int a[10][10], int n){
			int baris=0,kolom=0;
			n-=1;
			int min=a[0][n];
			for(int i=0;i<10;i++){
				if(a[i][n]>=min){
					min=a[i][n];
					baris=i;
					kolom=n;
				}
			}
			cout<<"Terbesar = "<<a[baris][kolom]<<endl;
					
		}
		void tukar (int *a, int *b){
			int temp;
			temp = *a;
			*a = *b;
			*b = temp;
		}
		void cetak_kolom(const int a[10][10], int n){
			for(int i=0;i<10;i++){
				cout<<a[i][n]<<" ";
			}
			cout<<endl;
		}
		void cetak_baris(const int a[10][10],int n){
			for(int i=0;i<10;i++){
				cout<<a[n][i]<<" ";
			}
			cout<<endl;
		}
		void asckolom(int a[10][10], int x){
			cout<<"Not Ascending"<<endl;
			cetak_kolom(a,x);
			cout<<endl;
			
			for(int i=0;i<10-1;i++)
			for(int j=i+1;j<10;j++)
			if(a[i][x]>a[j][x]) tukar(&a[i][x],&a[j][x]);
			
			cout<<"Ascending"<<endl;
			cetak_kolom(a,x);
		}
		void ascbaris(int a[10][10],int x){
			cout<<"Not Ascending"<<endl;
			cetak_baris(a,x);
			cout<<endl;
			
			for(int i=0;i<10-1;i++)
			for(int j=i+1;j<10;j++)
			if(a[x][i]>a[x][j]) tukar(&a[x][i],&a[x][j]);
			
			cout<<"Ascending"<<endl;
			cetak_baris(a,x);
		}
		void deskolom(int a[10][10], int x){
			cout<<"Not Descending"<<endl;
			cetak_kolom(a,x);
			cout<<endl;
			
			for(int i=0;i<10-1;i++)
			for(int j=i+1;j<10;j++)
			if(a[i][x]<a[j][x]) tukar(&a[i][x],&a[j][x]);
			
			cout<<"Descending"<<endl;
			cetak_kolom(a,x);
		}
		void desbaris(int a[10][10],int x){
			cout<<"Not Descending"<<endl;
			cetak_baris(a,x);
			cout<<endl;
			
			for(int i=0;i<10-1;i++)
			for(int j=i+1;j<10;j++)
			if(a[x][i]<a[x][j]) tukar(&a[x][i],&a[x][j]);
			
			cout<<"Descending"<<endl;
			cetak_baris(a,x);
		}
		void ratakolom(int a[10][10],int x){
			int jumlah=0;
			for(int i=0;i<10;i++){
				jumlah+=a[i][x];
			}
			cout<<endl;
			cout<<"Rata-Rata = "<<(float)jumlah/10<<endl;
			cout<<endl;
		}
		void ratabaris(int a[10][10],int x){
			int jumlah=0;
			for(int j=0;j<10;j++){
				jumlah+=a[x][j];
			}
			cout<<endl;
			cout<<"Rata-Rata = "<<(float)jumlah/10<<endl;
			cout<<endl;
		}
		void sumkolom(int a[10][10], int bawal, int bahir, int x,char y){
			int jumlah=0;

			for(int i=bawal;i<=bahir;i++){
				cout<<y<<i+1;
				if(i<bahir) cout<<" + ";
				jumlah+=a[i][x];
			}
			cout<<endl;
			cout<<"Jumlah = "<<jumlah<<endl;
		}
		void sumbaris(int a[10][10], int koal, int koir, int x,char q,char w){
			int jumlah=0;
			
			for(char i=q;i<=w;i++){
				cout<<i<<x+1;
				if(i<w) cout<<" + ";
			}
			
			for(int i=koal;i<=koir;i++){
				jumlah+=a[x][i];
			}
			cout<<endl;
			cout<<"Jumlah = "<<jumlah<<endl;
		}
		void function(string a){
			char kolom;
			int baris=0;
			int kolbar=0;
			string masukan,masukan1;
			
			if(a.substr(0,4)=="set(" && a[a.size()-1]==')'){
				masukan=a.substr(5,6);
				baris=atoi(masukan.c_str());
				kolom=a[4];
				kolbar=konversi(kolom);
				baris-=1;
				kolbar-=1;
				if((kolbar>=0 and kolbar<=9) and (baris>=0 and baris<=9)){
					int value;
					if(a[a.size()-3]==','){
						masukan=a.substr(a.size()-2,a.size());
						value=atoi(masukan.c_str());
					}
					else if(a[a.size()-4]==','){
						masukan=a.substr(a.size()-3,a.size());
						value=atoi(masukan.c_str());
					}
					else if(a[a.size()-5]==','){
						masukan=a.substr(a.size()-4,a.size());
						value=atoi(masukan.c_str());
					}
					else if(a[a.size()-6]==','){
						masukan=a.substr(a.size()-5,a.size());
						value=atoi(masukan.c_str());
					}
					else{
						value=sheet[baris][kolbar];
						cout<<"Input Gagal"<<endl;
						cout<<endl;
					}
					sheet[baris][kolbar]=value;
					cout<<"["<<kolom<<baris+1<<"] = "<<sheet[baris][kolbar]<<endl;
				}
				else{
					cout<<"Input Gagal"<<endl;
				}
			}
			else if(a.substr(0,4)=="del(" && a[a.size()-1]==')'){
				masukan=a.substr(5,6);
				baris=atoi(masukan.c_str());
				kolom=a[4];
				kolbar=konversi(kolom);
				baris-=1;
				kolbar-=1;
				
				if((kolbar>=0 and kolbar<=9) and (baris>=0 and baris<=9)){
					sheet[baris][kolbar]-=sheet[baris][kolbar];
					cout<<"DELETE"<<endl;
				}
				else{
					cout<<"Input Gagal"<<endl;
				}
			}
			else if(a.substr(0,7)=="search(" && a[a.size()-1]==')'){
				int nilai;
				
				if(a[a.size()-2]=='('){
					masukan=a.substr(a.size()-1,a.size());
					nilai=atoi(masukan.c_str());
				}
				else if(a[a.size()-3]=='('){
					masukan=a.substr(a.size()-2,a.size());
					nilai=atoi(masukan.c_str());
				}
				else if(a[a.size()-4]=='('){
					masukan=a.substr(a.size()-3,a.size());
					nilai=atoi(masukan.c_str());
				}
				else if(a[a.size()-5]=='('){
					masukan=a.substr(a.size()-4,a.size());
					nilai=atoi(masukan.c_str());
				}
				else{
					cout<<"Input Gagal"<<endl;
				}
				
				pencarian(sheet,nilai);
			}
			else if(a.substr(0,4)=="min(" && a[a.size()-1]==')'){
				char barkol;
				barkol=a[4];
				
				
				if(a[a.size()-2]=='('){
					masukan=a.substr(a.size()-1,a.size());
					baris=atoi(masukan.c_str());
				}
				else if(a[a.size()-3]=='('){
					masukan=a.substr(a.size()-2,a.size());
					baris=atoi(masukan.c_str());
				}
				else if(a[a.size()-4]=='('){
					masukan=a.substr(a.size()-3,a.size());
					baris=atoi(masukan.c_str());
				}
				else{
					cout<<"Input Gagal"<<endl;
				}
				
				if(barkol=='a' or barkol=='b' or barkol=='c' or barkol=='d' or barkol=='e' or barkol=='f' or barkol=='g' or barkol=='h' or barkol=='i' or barkol=='j'){
					int barkol1;
					barkol1=konversi(barkol);
					minimumkolom(sheet,barkol1);
				}
				else if(baris==1 or baris==2 or baris==3 or baris==4 or baris==5 or baris==6 or baris==7 or baris==8 or baris==9 or baris==10){
					minimumbaris(sheet,baris);
				}
				else{
					cout<<"Input Gagal"<<endl;
				}
			}
			else if(a.substr(0,4)=="max(" && a[a.size()-1]==')'){
				char barkol;
				barkol=a[4];
				
				if(a[a.size()-2]=='('){
					masukan=a.substr(a.size()-1,a.size());
					baris=atoi(masukan.c_str());
				}
				else if(a[a.size()-3]=='('){
					masukan=a.substr(a.size()-2,a.size());
					baris=atoi(masukan.c_str());
				}
				else if(a[a.size()-4]=='('){
					masukan=a.substr(a.size()-3,a.size());
					baris=atoi(masukan.c_str());
				}
				else{
					cout<<"Input Gagal"<<endl;
				}
				
				if(barkol=='a' or barkol=='b' or barkol=='c' or barkol=='d' or barkol=='e' or barkol=='f' or barkol=='g' or barkol=='h' or barkol=='i' or barkol=='j'){
					int barkol1;
					barkol1=konversi(barkol);
					makkolom(sheet,barkol1);
				}
				else if(baris==1 or baris==2 or baris==3 or baris==4 or baris==5 or baris==6 or baris==7 or baris==8 or baris==9 or baris==10){
					makbaris(sheet,baris);
				}
				else{
					cout<<"Input Gagal"<<endl;
				}
			}
			else if(a.substr(0,5)=="sort(" && a[a.size()-1]==')'){
				char kol;
				char asdes;
				int bar;
				kol=a[5];
				asdes=a[a.size()-2];
				
				if(asdes=='1'){
					
					if(a[a.size()-5]=='('){
						masukan=a.substr(a.size()-4,a.size());
						baris=atoi(masukan.c_str());
					}
					else if(a[a.size()-6]=='('){
						masukan=a.substr(a.size()-5,a.size());
						baris=atoi(masukan.c_str());
					}
					else{
						cout<<"Input Gagal"<<endl;
					}
					if(kol=='a' or kol=='b' or kol=='c' or kol=='d' or kol=='e' or kol=='f' or kol=='g' or kol=='h' or kol=='i' or kol=='j'){
						kolbar=konversi(kol);
						kolbar-=1;
						asckolom(sheet,kolbar);
					}
					else if(baris==1 or baris==2 or baris==3 or baris==4 or baris==5 or baris==6 or baris==7 or baris==8 or baris==9 or baris==10){
						bar=baris-1;
						ascbaris(sheet,bar);
					}
					else{
						cout<<"Input Gagal"<<endl;
					}	
				}
				else if(asdes=='0'){
					
					if(a[a.size()-5]=='('){
						masukan=a.substr(a.size()-4,a.size());
						baris=atoi(masukan.c_str());
					}
					else if(a[a.size()-6]=='('){
						masukan=a.substr(a.size()-5,a.size());
						baris=atoi(masukan.c_str());
					}
					else{
						cout<<"Input Gagal"<<endl;
					}
					
					if(kol=='a' or kol=='b' or kol=='c' or kol=='d' or kol=='e' or kol=='f' or kol=='g' or kol=='h' or kol=='i' or kol=='j'){
						kolbar=konversi(kol);
						kolbar-=1;
						deskolom(sheet,kolbar);
					}	
					else if(baris==1 or baris==2 or baris==3 or baris==4 or baris==5 or baris==6 or baris==7 or baris==8 or baris==9 or baris==10){
						bar=baris-1;
						desbaris(sheet,bar);
					}
					else{
						cout<<"Input Gagal"<<endl;
					}
				}
				else{
					cout<<"Input Gagal"<<endl;
				}	
			}
			else if(a.substr(0,5)=="mean(" && a[a.size()-1]==')'){
				char kol;
				kol=a[5];
				
				
				
				if(a[a.size()-3]=='('){
					masukan=a.substr(a.size()-2,a.size());
					baris=atoi(masukan.c_str());
				}
				else if(a[a.size()-4]=='('){
					masukan=a.substr(a.size()-3,a.size());
					baris=atoi(masukan.c_str());
				}
				
				if(kol=='a' or kol=='b' or kol=='c' or kol=='d' or kol=='e' or kol=='f' or kol=='g' or kol=='h' or kol=='i' or kol=='j'){
					int kol1=konversi(kol);
					kol1-=1;
					ratakolom(sheet,kol1);
				}
				else if(baris==1 or baris==2 or baris==3 or baris==4 or baris==5 or baris==6 or baris==7 or baris==8 or baris==9 or baris==10){
					baris-=1;
					ratabaris(sheet,baris);
				}
				else{
					cout<<"Input Gagal"<<endl;
				}
			}
			else if(a.substr(0,4)=="sum(" && a[a.size()-1]==')'){
				char kolomawal;
				char kolomakhir;
				int kowal;
				int kohir;
				int barisawal;
				int barisakhir;
				
				kolomawal=a[4];
				kowal=konversi(kolomawal);
				kowal-=1;//kolom cell awal
				
				masukan=a.substr(5,a.size());
				barisawal=atoi(masukan.c_str());
				
				if(a[6]==','){
					kolomakhir=a[7];
					kohir=konversi(kolomakhir);
				}
				else if(a[7]==','){
					kolomakhir=a[8];
					kohir=konversi(kolomakhir);
				}
				
				kohir-=1;//kolom cell akhir
				
				if(a[9]==')'){
					masukan1=a.substr(8,a.size());
					barisakhir=atoi(masukan1.c_str());
				}
				else if(a[a.size()-1]==')'){
					masukan1=a.substr(a.size()-3,a.size());
					barisakhir=atoi(masukan1.c_str());
				}
				
				if((kolomawal=='a' && kolomakhir=='a') or (kolomawal=='b' && kolomakhir=='b') or (kolomawal=='c' && kolomakhir=='c') or (kolomawal=='d' && kolomakhir=='d') or (kolomawal=='e' && kolomakhir=='e') or (kolomawal=='f' && kolomakhir=='f') or (kolomawal=='g' && kolomakhir=='g') or (kolomawal=='h' && kolomakhir=='h') or (kolomawal=='i' && kolomakhir=='i') or (kolomawal=='j' && kolomakhir=='j')){
					barisawal-=1;//baris cell awal
					barisakhir-=1;//baris cell akhir
					sumkolom(sheet,barisawal,barisakhir,kowal,kolomawal);
				}
				else if((barisawal==1 && barisakhir==1) or (barisawal==2 && barisakhir==2) or (barisawal==3 && barisakhir==3) or (barisawal==4 && barisakhir==4) or (barisawal==5 && barisakhir==5) or (barisawal==6 && barisakhir==6) or (barisawal==7 && barisakhir==7) or (barisawal==8 && barisakhir==8) or (barisawal==9 && barisakhir==9) or (barisawal==10 && barisakhir==10)){
					barisawal-=1;
					sumbaris(sheet,kowal,kohir,barisawal,kolomawal,kolomakhir);
				}
				else{
					cout<<"Input Gagal"<<endl;
				}
			}
			else{
				cout<<"FUNGSI INI TIDAK ADA"<<endl;
			}
		}
		void menu(){
			kembali:
			system("cls");
			int pil;
			string perintah;
			
			cout<<"MINI SPREADSHEET V.0"<<endl;
			cout<<"\n1. View Sheet\n2. Print Sheet\n3. Functions"<<endl;
			baca();
			cout<<"Masukan Pilihan = ";cin>>pil;
			cout<<endl;
			switch(pil){
				case 1:
					viewsheet();
					baca();
					cout<<endl;
					system("pause");
					goto kembali;
					break;
				case 2:
					tulis();
					cout<<"Berhasil di Print"<<endl;
					cout<<endl;
					system("pause");
					goto kembali;
					break;
				case 3:
					cout<<"Masukan Perintah = ";cin>>perintah;
					cout<<endl;
					function(perintah);
					tulis();
					cout<<endl;
					system("pause");
					goto kembali;
					break;
				default:
					cout<<"PILIHAN SALAH"<<endl;
					break;
			}
		}
};

int main(int argc, char *argv[]){
	spreadsheet a;
	a.menu();
	
	return 0;
}
