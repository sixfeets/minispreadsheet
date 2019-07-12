#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<iomanip>
using namespace std;

class spreadsheet{
	private:
		int sheet[10][10];
	public:
		void baca(){
			ifstream data;
			data.open("datasheet.txt");
			cout<<endl;
			for(int i=0;i<10;i++){
				for(int j=0;j<10;j++){
					data>>sheet[i][j];
					cout<<sheet[i][j]<<" ";
				}
				cout<<endl;
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
			cout<<"Berhasil di Print"<<endl;
			file.close();
		}
		int konversi(char x){
			return (int)x-96;
		}
		void function(string x){
			string masukan;
			char kolom;
			int baris;
			int newkol,newkol1;
			if(x.substr(0,4)=="set(" && x[x.size()-1]==')'){
				masukan=x.substr(5,6);
				baris=atoi(masukan.c_str());
				kolom=x[4];
				newkol=konversi(kolom);
				baris-=1;
				newkol-=1;
				if((newkol>=0 and newkol<=9) and (baris>=0 and baris<=9)){
					int value;
					if(x[x.size()-3]==','){
						masukan=x.substr(x.size()-2,x.size());
						value=atoi(masukan.c_str());
					}
					else if(x[x.size()-4]==','){
						masukan=x.substr(x.size()-3,x.size());
						value=atoi(masukan.c_str());
					}
					else if(x[x.size()-5]==','){
						masukan=x.substr(x.size()-4,x.size());
						value=atoi(masukan.c_str());
					}
					else if(x[x.size()-6]==','){
						masukan=x.substr(x.size()-5,x.size());
						value=atoi(masukan.c_str());
						if(value>999 or value<-999){
							value=sheet[baris][newkol];
							cout<<"Input Tidak Valid"<<endl;
						}
					}
					else{
						value=sheet[baris][newkol];
						cout<<"Input Tidak Valid"<<endl;
					}
					sheet[baris][newkol]=value;
					cout<<"["<<newkol<<","<<baris<<"] = "<<sheet[baris][newkol]<<endl;
				}
				else{
					cout<<"Input Tidak Valid"<<endl;
				}
			}
			else if(x.substr(0,4)=="del("){
				masukan=x.substr(5,6);
				baris=atoi(masukan.c_str());
				kolom=x[4];
				newkol=konversi(kolom);
				baris-=1;
				newkol-=1;
				if((newkol>=0 and newkol<=9) and (baris>=0 and baris<=9)){
					sheet[baris][newkol]-=sheet[baris][newkol];
					cout<<"DELETE"<<endl;
				}
			}
			else{
				cout<<"Input Salah"<<endl;
			}
		}
		void menu(){
			kembali:
			system("cls");
			char a;	
			int pil;
			string perintah;
			
			cout<<"MINI SPREADSHEET V.0"<<endl;
			cout<<"1. View Sheet\n2. Print Sheet\n3. Functions"<<endl;
			cout<<"Masukan Pilihan = ";cin>>pil;
			switch(pil){
				case 1:
					baca();
					cout<<endl;
					cout<<"Tekan Y/y untuk kembali = ";cin>>a;
					if(a=='Y' || a=='y'){
						goto kembali;
					}
					else{
						system("cls");
					}
					break;
				case 2:
					tulis();
					cout<<"Tekan Y/y untuk kembali = ";cin>>a;
					if(a=='Y' || a=='y'){
						goto kembali;
					}
					else{
						system("cls");
					}
					break;
				case 3:
					cout<<"Masukan Perintah = ";cin>>perintah;
					function(perintah);
					tulis();
					cout<<"Tekan Y/y untuk kembali = ";cin>>a;
					if(a=='Y' || a=='y'){
						goto kembali;
					}
					else{
						system("cls");
					}
					break;
			}
		}
};

int main(){
	spreadsheet a;
	a.menu();
	
	return 0;
}
