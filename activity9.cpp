#include <iostream>
using namespace std;

class Mahasiswa {
    private :
        static int totalMahasiswa;
    public :
        string nama;
        string status;
        int usia;

        Mahasiswa(string pNama, int pUsia) {
            nama = pNama;
            usia = pUsia;
            status = "Mahasiswa Baru";
            ++totalMahasiswa;
            cout << nama << " Dibuat" << "Status" << status << endl;
            cout << endl;
        }

        ~Mahasiswa() {
            cout << nama << " Dihancurkan" << endl;
            --totalMahasiswa;
            cout << endl;
        }

        static int getTotalMahasiswa() {
            return totalMahasiswa;
        }

        static void setTotalMahasiswa(int a){
            totalMahasiswa = a;
        }
};

int Mahasiswa::totalMahasiswa = 0;

int main() {

    cout << "Total Mahasiswa adalah " << Mahasiswa::getTotalMahasiswa() << endl;

    Mahasiswa mhs1("Maman", 40);
    Mahasiswa mhs2("Agus", 34);

    Mahasiswa::setTotalMahasiswa(10);

    cout << "Total Mahasiswa adalah " << Mahasiswa::getTotalMahasiswa() << endl;
    {
        Mahasiswa mhs3("Budi", 19);
        Mahasiswa mhs4("Caca", 21);
        cout << "Total Mahasiswa adalah " << Mahasiswa::getTotalMahasiswa() << endl;
    }

    cout << "Total Mahasiswa adalah " << Mahasiswa::getTotalMahasiswa() << endl;

}

// konsep dari static adalah satu variabel bisa memvariasi semua object
// construktor konsepnya adalah dia memberikan nilai awal , bisa berubah ditengah jalan memiliki parameter 
// syarat destruktor adalah tanda ~ , tidak bisa mempunyai parameter karena disimpannya didalam memory
