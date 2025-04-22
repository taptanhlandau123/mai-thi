#include <iostream>
#include <string>

using namespace std;
//C  = 7*P -b mod 26
//	a=7, b nh?p t? bàn phím
//	P = 15(C-b) mod 26

// Hàm tính ??c chung l?n nh?t (GCD) c?a 2 s? a và  b?
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Hàm tìm ph?n ngh?ch ??o a trong Z26
int nghichdao(int a) {
    for (int x = 1; x < 26; x++) {
        if ((a * x) % 26 == 1)
            return x;
    }
    return -1; // không tìm th?y ph?n t? ngh?ch ??o
}

// Hàm mã hóa chu?i
string mahoa(string chuoi, int a, int b) {
    string mahoachuoi = "";
    for (int i = 0; i < chuoi.length(); i++) {
    	char ch = chuoi[i];
        if (isalpha(ch)) {
            // chuy?n ??i kí t? thành s? nguyên trong kho?ng 0-25 (a-z)
            int P = tolower(ch) - 'a';

            // Áp d?ng công th?c mã hóa C = (a * P + b) mod 26
            int C = (a * P - b + 26) % 26;

            // Chuy?n ??i s? nguyên thành kí t? và thêm vào chu?i mã hóa
            mahoachuoi += (C + 'a');
        } else {
            // Gi? nguyên kí t? không ph?i ch? cái
            mahoachuoi += ch;
        }
    }
    return mahoachuoi;
}

// Hàm gi?i mã chu?i
string giaima(string mahoachuoi, int a, int b) {
    string giaimachuoi = "";
    int aInverse = nghichdao(a);
    if (aInverse == -1) {
        cout << "Khong ton tai phan tu nghich dao cua a trong Z26." << endl;
        return giaimachuoi;
    }
for (int i = 0; i < mahoachuoi.length(); i++) {
    	char ch = mahoachuoi[i];
        if (isalpha(ch)) {
            // chuy?n ??i kí t? thành s? nguyên trong kho?ng 0-25 (a-z)
            int C = tolower(ch) - 'a';

            // Áp d?ng công th?c gi?i mã  P = ((C - b) * aInverse) mod 26
            int P = ((C + b) * aInverse) % 26;

            // chuy?n ??i s? nguyên thành kí t? và thêm vào chu?i gi?i mã
            giaimachuoi += (P + 'a');
        } else {
            // Gi? nguyên kí t? không ph?i ch? cái
            giaimachuoi += ch;
        }
    }
    return giaimachuoi;
}

int main() {
    // Nh?p chu?i t? bàn phím
    string chuoi;
    cout << "Nhap chuoi: ";
    getline(cin, chuoi);

    // Nh?p s? nguyên a và b
    int a=7, b;
//    cout << "Nhap so nguyen a: ";
//    cin >> a;
    cout << "Nhap so nguyen b: ";
    cin >> b;

    // Ki?m tra tính h?p l? c?a a và b
    if (gcd(a, 26) != 1) {
        cout << "Gia tri cua a khong hop le. Vui long chon gia tri khac." << endl;
        return 0;
    }

    // Mã hóa chu?i và hi?n th? k?t qu?
    string mahoachuoi = mahoa(chuoi, a, b);
    cout << "Chuoi sau khi ma hoa: " << mahoachuoi << endl;

    // Gi?i mã chu?i và hi?n th? k?t qu?
    string giaimachuoi = giaima(mahoachuoi, a, b);
    cout << "Chuoi sau khi giai ma: " << giaimachuoi << endl;

    return 0;
}

