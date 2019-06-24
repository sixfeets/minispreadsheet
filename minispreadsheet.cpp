#include<iostream>
using namespace std;

class sheet{
	private:
		int pil;
		int spreadsheet[10][10];
	public:
		void menu();
		void viewsheet();
};

void sheet::menu(){
	cout<<"Menu Spreadsheet V.0.1"<<endl;
	cout<<"1. View Sheet\n2. Print Sheet\n3. Functions"<<endl;
	cout<<"Masukan Pilihan = ";
	cin>>pil;
	if(pil==1){
		viewsheet();
	}
}

void sheet::viewsheet(){
	cout<<" A B C D E F G H I J"<<endl;
	
	for(int i=0;i<10;i++){
		cout<<i+1;
		for(int j=0;j<10;j++){
			spreadsheet[i][j]=0;
			cout<<" "<<spreadsheet[i][j];
		}
		cout<<endl;
	}
}

int main(){
	sheet v;
	
	v.menu();
	
	
	
	return 0;
}
