#include <stdio.h>
#include <iostream>
#include <cstring>>
#include <fstream>

using namespace std;

 void createFile() { // Untuk Membuat Fungsi createfile
    char nama[6], npm[8], kelas[5], jurusan[2]; // Mmebuat Variable bertipe data (character)
    string  namaFile; //Membuat Variable bertipe data (string)
    int j ; //Membuat Variable bertipe data Integer
    char charNama[20];	    //Membuat Variable bertipe data character
    FILE *fileTemp; //berfungsi agar file menyimpan semua inputan.

    namaFile = "biodata.txt"; //Memberikan nama file dan ekstensi file yang dibuat yaitu biodata.txt
    strcpy(charNama, namaFile.c_str());//Berfungsi untuk menkonversikan variable namafile dari bertipe string menjadi char

    fileTemp = fopen(charNama, "w"); // digunakan untuk membuka file sesuai nama yang di inputkan user yang tersimpan pada variable charNama
	 
    fprintf(fileTemp, "====================== BIODATA ======================\n");
    fprintf(fileTemp, "|    Nama    |    NPM    |    KELAS   |   JURUSAN   |");
	 //Sebagai Headers file
    
    printf("\nMasukan Banyak Inputan : ");
    cin>>j; //Meminta banyak data yang akan disimpan pada file lalu menyimpan pada variable j
    for (int i=0; i<j; i++) { //Sebagai perulangan agar dapat memasukan data sebanyak yang akan input pada file
        printf("\n========== Masukan data ke-%d ==========", i+1); //Headers
        printf("\nMasukan Nama  : ");
        cin>>nama;//Meminta inputan nama dan menyimpan pada variable nama
        printf("Masukan NPM   : ");
        cin>>npm;//Meminta inputan nama dan menyimpan pada variable npm
        printf("Masukan Kelas : ");;
        cin>>kelas;//Meminta inputan nama dan menyimpan pada variable kelas
        printf("Masukan Jurusan : ");;
        cin>>jurusan;//Meminta inputan nama dan menyimpan pada variable jurusan
        fprintf(fileTemp, "\n|   ""%s", nama ); // Untuk memasukan nilai yang tersimpan pada variable nama ke dalam file 
        fprintf(fileTemp, "   |  ""%s", npm);	// Untuk memasukan nilai yang tersimpan pada variable npm ke dalam file 
        fprintf(fileTemp, " |    ""%s", kelas);    // Untuk memasukan nilai yang tersimpan pada variable kelas ke dalam file 
        fprintf(fileTemp, "   |     ""%s", jurusan); // Untuk memasukan nilai yang tersimpan pada variable jurusan ke dalam file 
        fprintf(fileTemp, "      |");
    }
    fprintf(fileTemp, "\n====================================================="); // Sebagai Footers file
    fclose(fileTemp); // Untuk Menutup File

    
}

void readFile(){
	string line;
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
