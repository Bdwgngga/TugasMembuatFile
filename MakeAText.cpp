#include <stdio.h>
#include <iostream>
#include <cstring>>
#include <fstream>

using namespace std;

 void createFile() { // Untuk Membuat Fungsi createfile
    char nama[6], npm[8], kelas[5], jurusan[2]; // Mmebuat Variable bertipe data (character)
    string  namaFile; //Membuat Variable bertipe data (string)
    int j ; \\Membuat Variable bertipe data Integer
    char charNama[20];	    //Membuat Variable bertipe data character
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

void menuFile() { // Digunakan untuk membuat menu
    int pilihan;
    cout<<"\nPilihan pengolahan file  "<<endl;
    cout<<"1. Membuat dan input data ke file  "<<endl;
    cout<<"2. Membaca data file  "<<endl;
    cout<<"Masukan pilihan : ";
    cin>>pilihan; //Untuk menyimpan data pilihan yang telah diinput

    if(pilihan==1) {
        createFile(); // Ketika user menginputkan angka 1 maka program akan memanggil fungsi createfile
    }
    if(pilihan==2) {
        readFile();  // Ketika user menginputkan angka 1 maka program akan memanggil fungsi readfile
    }
}

int main() {  //fungsi main yang pertama kali dijalankan ketika program dijalankan
    int ulang;
    do {
        menuFile(); //perulangan do dengan pemanggilan fungsi menufile
        cout<<"\nIngin ulang input data Yes(1) No(0) ";
        cin>>ulang; // Untuk menyimpan data pilihan yang telah diinput
        cout<<endl;
    } while (ulang==1); // Kondisi dimana ketika user memasukkan angka 1 maka program akan selesai dan akan mencetak Terima Kasih.
    cout<<"Terima kasih...";
    cout<<endl;
    return 0;
}
