#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;

int ChangeData() //Function to change data if the program was to be looped.
{
    char answer, again;
    cout << "\nData apa yang mau Anda ubah?" << endl;
    cout << "A. Uang Bulanan\nB.Uang Sekarang\nC.Sisa Hari\nD.Tunjukkan data\nE.Keluar dari program\n" << endl;
    cin >> answer;
    if(answer == 'A' || answer == 'a')
    {
        return 1;
    }
    else if (answer == 'B' || answer == 'b')
    {
        return 2;
    }
    else if (answer == 'C' || answer == 'c')
    {
        return 3;
    }
    else if (answer == 'D' || answer == 'd')
    {
        return 4;
    }
    else if (answer == 'E' || answer == 'e')
    {
        cout << "Keluar dari program..." << endl;
        exit(0);
    }
    else
    {
        cout << "\nInput tidak dimengerti." << endl;
        return 0;
    }
}

void ShowData(string temp) //ShowData function which re-reads the file and prints it to screen.
{
    ifstream UserRead("UserData.txt");
    while (getline(UserRead, temp))
    {
        cout << temp << endl;
    }
}

int main()
{
    float pengeluaran_harian, uang_bulanan, uang_sekarang, hari;
    int pos, choice, i = 0;
    string temp, data;

    ifstream UserRead("UserData.txt");

    while (getline(UserRead, temp)) //Reads the file line by line
    {
        cout << temp << endl;
        pos = temp.find(":");
        data = temp.substr(pos + 2);

        switch(i)
        {
        case 0:
            uang_bulanan = stof(data);
            break;
        case 1:
            uang_sekarang = stof(data);
            break;
        case 2:
            hari = stof(data);
            break;
        case 4:
            pengeluaran_harian = stof(data);
            break;
        }
        i++;
    }

    if(i == 0 && !UserRead)
    {
        cout << "Tidak ada data terdeteksi. Membuat data baru.\n\n";
        cout << "Masukkan uang bulanan: ";
        cin >> uang_bulanan;

        cout << "Masukkan uang sekarang: ";
        cin >> uang_sekarang;

        cout << "Masukkan sisa hari: ";
        cin >> hari;
    }

    ofstream UserWrite("UserData.txt");
    //Loop is added here if the program was to be looped.
    choice = ChangeData();
    switch(choice)
    {
    case 1:
        cout << "Masukkan uang bulanan: ";
        cin >> uang_bulanan;
        break;
    case 2:
        cout << "Masukkan uang sekarang: ";
        cin >> uang_sekarang;
        break;
    case 3:
        cout << "Masukkan sisa hari: ";
        cin >> hari;
        break;
    case 4:
        break;
    default:
        cout << "Keluar dari program...";
        exit(0);
    }

    pengeluaran_harian = uang_sekarang/hari;

    UserWrite << fixed << setprecision(0);      //fixed is for normal formatting while precision for decimal points.
    UserWrite << "Uang Bulanan: " << uang_bulanan << endl;
    UserWrite << "Uang Sekarang: " << uang_sekarang << endl;
    UserWrite << "Sisa Hari: " << hari << endl;
    UserWrite << "Uang kamu sudah habis sebanyak: " << abs(uang_sekarang - uang_bulanan) << endl;
    UserWrite << "Batas Pengeluaran Harian: " << pengeluaran_harian << endl;

    ShowData(temp);

    UserRead.close();
    UserWrite.close();
}
