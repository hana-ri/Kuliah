#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

string delimit,
       strInput;

int posisi = 0,
    jmlhKata = 0,
    i,
    C,
    sizeArray;

int jumlahKata(string strInput);

void inputKeArray(string dataInformasi[], string strInput);

void permutasi(string dataInformasi[], string delmit, int sizeArray);

void simpan(string dataInformasi[], string delimit, int sizeArray);\

void baca(string strInput);

void log(string dataInformasi[], int sizeArray);

int main()
{
    {
        cout << R"(        
         _   __     _                             _       ____ 
        | | / /    | |                           | |     / ___|
        | |/ /  ___| | ___  _ __ ___  _ __   ___ | | __ / /___ 
        |    \ / _ \ |/ _ \| '_ ` _ \| '_ \ / _ \| |/ / | ___ \
        | |\  \  __/ | (_) | | | | | | |_) | (_) |   <  | \_/ |
        \_| \_/\___|_|\___/|_| |_| |_| .__/ \___/|_|\_\ \_____/
                                     | |                       
                                     |_|                
        )" << '\n';
    }
    cout << "=================== M e n u ===================\n1. Generate List\n2. Simpan Informasi\n3. Tampilkan isi file\n4. Hapus File\n===============================================" << endl;
    cout << "Pilih menu: "; cin >> C;
    switch (C)
    {
    case 1:
            // strInput = "a b c";
            cin.ignore();
            cout << "Masukan informasi: "; getline(cin, strInput);
            delimit = " ";
            {      
                sizeArray = jumlahKata(strInput);
                string dataInformasi[sizeArray];
                inputKeArray(dataInformasi, strInput);
                permutasi(dataInformasi, delimit,sizeArray);
            }
        break;
    case 2:
            cin.ignore();
            cout << "masukan informasi yang ingin disimpan.\npisahkan setiap informasi dengan tanda ;\ncontoh: rendi tekom;fikri tekom; rizal tekom\nMasukan informasi: "; getline(cin, strInput);
            delimit = ";";
            {
                sizeArray = jumlahKata(strInput);
                string dataInformasi[sizeArray];
                inputKeArray(dataInformasi, strInput);;
                simpan(dataInformasi, delimit, sizeArray);
            }
        break;
    case 3:
            cin.ignore();
            cout << "List File\n- Ouput.txt\n- Info.txt\nKetikan Input: ";cin>>strInput;
            baca(strInput);
        break;
    case 4:
            cout << "\n=============== Menghapus File ================\n1. Ouput.txt\n2. Info.txt\n===============================================\nPilih Input:";
            cin >> i;
            if(i == 1) {
                cout << "Apakah anda yakin ingin menghapus file tersebut (y=konfirmasi)\nKetik Input: ";
                cin >> strInput;
                if(strInput == "y"){
                system("del Output.txt");
                } else {
                    break;
                }
            } else if(i == 2) {
                cout << "Apakah anda yakin ingin menghapus file tersebut (y=konfirmasi)\nKetik Input: ";
                cin >> strInput;
                if(strInput == "y"){
                system("del Info.txt");
                } else {
                    break;
                }
            } else {
                cout << "Maaf Menu yang dipilih tidak tersedia";
            }
        break;
    default:
        cout << "Menu yang kamu pilih tidak tersedia!";        
        break;
    }
    return 0;
}

/* 
    [fungsi jumlahKata()]
    fungsi untuk menghitung jumlah kata yang diterima dari strInput
    lalu string akan di olah sedemikian rupa dalam while, hingga bisa
    menghitung jumlah kata yang nantinya jumlah/nilai tersebut di return.
    untuk menentukan ukuran dari array data.
*/
int jumlahKata(string strInput)
{
    while (true){
        posisi = strInput.find(delimit, posisi + 1);
        jmlhKata++;
        if(posisi < 0) {
            break;
        }
    }
    // cout << "\nJumlah Kata yang dihasilkan dari fungsi jumlahKata: " << jmlhKata << endl;
    return jmlhKata;
}

/*
    [fungsi inputKeArray()]
    fungsi ini akan memecah string lalu memasukannya ke dalam array
    contoh: aku kenapa kamu-> {"aku", "kenapa", "kamu"}
*/
void inputKeArray(string dataInformasi[], string strInput)
{
    string tempX;
    i = 0;
    // memecah string lalu memasukannya kedalam array
    while(true){
        // cout << "\nString : " << strInput;
        posisi =  strInput.find(delimit);
        tempX = strInput.substr(0, posisi);
        dataInformasi[i] = tempX;
        // cout << endl << "Kata: " << tempX << "\ndimasukan kedalam array dataInformasi[" << i << "]" << "='" << tempX << "';" << endl;
        i++;
        strInput.erase(0, posisi + delimit.length());
        if(posisi < 0) {
            break;
        }
    }
}

/*
    [fungsi permutasi()]
    fungsi ini akan melakukan permutasi dengan bantuan fungsi
    dari library algorithm next_permutation()
*/
void permutasi(string dataInformasi[], string delimit, int sizeArray)
{
    cout << "\nData yang diolah menggunakan permutasi: ";
    log(dataInformasi, sizeArray);
    cout << endl;
    
    // mengurutkan Array
    sort(dataInformasi, dataInformasi+sizeArray);
    do {
        log(dataInformasi, sizeArray);
        simpan(dataInformasi, delimit, sizeArray);
    } while(next_permutation(dataInformasi, dataInformasi+ sizeArray));
}

/*
    [Fungsi simpan()]
    fungsi ini akan memasukan nilai yang dihasilkan 
    dan menuliskannya dalam format namafile.txt
*/ 
void simpan(string dataInformasi[], string delimit, int sizeArray)
{
    ofstream fileKu;

    if(delimit == " ") {
        fileKu.open("Output.txt", ios::app);
    } else {
        fileKu.open("Info.txt", ios::app);
    }

    if(fileKu.is_open() && delimit == " ") {
        for(i = 0; i < sizeArray; i++) {
            fileKu << dataInformasi[i];
        }
        fileKu << endl;
    } else if(fileKu.is_open() && delimit == ";") {
        for(i = 0; i < sizeArray; i++) {
            fileKu << dataInformasi[i]<<endl;
        }
        fileKu << endl;
        cout << "Data telah disimpan\n";
    }else {
        cout << "File tidak dapat dibuka :(";
    }
    fileKu.close();
}
/*
    [fungsi baca()]
    untuk membaca isi didalam file
*/
void baca(string strInput)
{
    string text;
    ifstream fileKu(strInput);

    while (getline(fileKu, text))
    {
        cout << text << endl;
    }
    
}

/*
    [Fungsi log()]
    untuk menampilkan data dari array 1d
*/
void log(string dataInformasi[], int sizeArray)
{
    for(i = 0; i < sizeArray; i++) {
        cout << dataInformasi[i];
    }
    cout << endl;
}