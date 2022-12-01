#include <stdio.h>
#include <iostream>
#include <cstring>>
#include <fstream>

using namespace std;

 void createFile() {
    char nama[6], npm[8], kelas[5], jurusan[2];
    string  namaFile;
    int j ;
    char charNama[20];
    FILE *fileTemp;

    namaFile = "biodata.txt";
    strcpy(charNama, namaFile.c_str());

    fileTemp = fopen(charNama, "w");
    fprintf(fileTemp, "====================== BIODATA ======================\n");
    fprintf(fileTemp, "|    Nama    |    NPM    |    KELAS   |   JURUSAN   |");
    
    printf("\nMasukan Banyak Inputan : ");
    cin>>j;

    for (int i=0; i<j; i++) {
        printf("\n========== Masukan data ke-%d ==========", i+1);
        printf("\nMasukan Nama  : ");
        cin>>nama;
        printf("Masukan NPM   : ");
        cin>>npm;
        printf("Masukan Kelas : ");;
        cin>>kelas;
        printf("Masukan Jurusan : ");;
        cin>>jurusan;
        fprintf(fileTemp, "\n|   ""%s", nama );
        fprintf(fileTemp, "   |  ""%s", npm);
        fprintf(fileTemp, " |    ""%s", kelas);
        fprintf(fileTemp, "   |     ""%s", jurusan);
        fprintf(fileTemp, "      |");
    }
    fprintf(fileTemp, "\n=====================================================");
    fclose(fileTemp);

    
}

void readFile(){
	char filesaya{20};
	string line;
	cout<<"Masukan Nama File : ";
	cin>>filesaya;
	ifstream myfile;
	myfile.open("biodata.txt");
	if(myfile.is_open()){
		while (getline(myfile, line)){
			cout<<line<<endl;
		}
	}
	
}

void menuFile() {
    int pilihan;
    cout<<"\nPilihan pengolahan file  "<<endl;
    cout<<"1. Membuat dan input data ke file  "<<endl;
    cout<<"2. Membaca data file  "<<endl;
    cout<<"Masukan pilihan : ";
    cin>>pilihan;

    if(pilihan==1) {
        createFile();
    }
    if(pilihan==2) {
        readFile();
    }
}

int main() {
    int ulang;
    do {
        menuFile();
        cout<<"\nIngin ulang input data Yes(1) No(0) ";
        cin>>ulang;
        cout<<endl;
    } while (ulang==1);
    cout<<"Terima kasih...";
    cout<<endl;
    return 0;
}
