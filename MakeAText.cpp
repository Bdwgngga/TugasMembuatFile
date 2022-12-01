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
	string line; // Membuat variable line bertipe data string
	ifstream myfile; //Menggunakan Ifstream untuk membuka file
	myfile.open("biodata.txt"); //Untuk membuka file
	if(myfile.is_open()){ //Digunakan untuk statment jika myfile terbuka maka akan meneksekusi program dibawah
		while (getline(myfile, line)){ //Digunakan untuk looping baris dalam file dnegan mengambil semua baris yang ada di file lalu disimpan ke dalam variable line
			cout<<line<<endl; //Digunakan untuk mencetak baris yang disimpan dalam variable line
		}
	}
	
}

void menuFile() { // Digunakan untuk membuat menu
    int pilihan; // variabel dengan tipe data integer
    cout<<"\nPilihan pengolahan file  "<<endl; // menampilkan judul menu
    cout<<"1. Membuat dan input data ke file  "<<endl; // menampilkan pilihan menu
    cout<<"2. Membaca data file  "<<endl; // menampilkan pilihan menu
    cout<<"Masukan pilihan : "; // untuk meminta data atau inputan
    cin>>pilihan; //Untuk menyimpan data pilihan yang telah diinput

    if(pilihan==1) {
        createFile(); // Ketika user menginputkan angka 1 maka program akan memanggil fungsi createfile
    }
    if(pilihan==2) {
        readFile();  // Ketika user menginputkan angka 1 maka program akan memanggil fungsi readfile
    }
}

int main() {  //fungsi main yang pertama kali dijalankan ketika program dijalankan
    int ulang; // variabel dengan tipe data integer
    do { // prulangan do
        menuFile(); //perulangan do dengan pemanggilan fungsi menufile
        cout<<"\nIngin Kembali ke Menu ? Yes(1) No(0) ";
        cin>>ulang; // Untuk menyimpan data pilihan yang telah diinput
        cout<<endl;
    } while (ulang==1); // Kondisi dimana ketika user memasukkan angka 0 maka program akan selesai dan akan mencetak Terima Kasih.
    cout<<"Terima kasih..."; // menampilkan terima kasih
    cout<<endl;
    return 0;
}
