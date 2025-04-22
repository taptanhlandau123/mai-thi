#include <iostream>
#include <string>

using namespace std;
//C  = 7*P -b mod 26
//	a=7, b nh?p t? b�n ph�m
//	P = 15(C-b) mod 26

// H�m t�nh ??c chung l?n nh?t (GCD) c?a 2 s? a v�  b?
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// H�m t�m ph?n ngh?ch ??o a trong Z26
int nghichdao(int a) {
    for (int x = 1; x < 26; x++) {
        if ((a * x) % 26 == 1)
            return x;
    }
    return -1; // kh�ng t�m th?y ph?n t? ngh?ch ??o
}

// H�m m� h�a chu?i
string mahoa(string chuoi, int a, int b) {
    string mahoachuoi = "";
    for (int i = 0; i < chuoi.length(); i++) {
    	char ch = chuoi[i];
        if (isalpha(ch)) {
            // chuy?n ??i k� t? th�nh s? nguy�n trong kho?ng 0-25 (a-z)
            int P = tolower(ch) - 'a';

            // �p d?ng c�ng th?c m� h�a C = (a * P + b) mod 26
            int C = (a * P - b + 26) % 26;

            // Chuy?n ??i s? nguy�n th�nh k� t? v� th�m v�o chu?i m� h�a
            mahoachuoi += (C + 'a');
        } else {
            // Gi? nguy�n k� t? kh�ng ph?i ch? c�i
            mahoachuoi += ch;
        }
    }
    return mahoachuoi;
}

// H�m gi?i m� chu?i
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
            // chuy?n ??i k� t? th�nh s? nguy�n trong kho?ng 0-25 (a-z)
            int C = tolower(ch) - 'a';

            // �p d?ng c�ng th?c gi?i m�  P = ((C - b) * aInverse) mod 26
            int P = ((C + b) * aInverse) % 26;

            // chuy?n ??i s? nguy�n th�nh k� t? v� th�m v�o chu?i gi?i m�
            giaimachuoi += (P + 'a');
        } else {
            // Gi? nguy�n k� t? kh�ng ph?i ch? c�i
            giaimachuoi += ch;
        }
    }
    return giaimachuoi;
}

int main() {
    // Nh?p chu?i t? b�n ph�m
    string chuoi;
    cout << "Nhap chuoi: ";
    getline(cin, chuoi);

    // Nh?p s? nguy�n a v� b
    int a=7, b;
//    cout << "Nhap so nguyen a: ";
//    cin >> a;
    cout << "Nhap so nguyen b: ";
    cin >> b;

    // Ki?m tra t�nh h?p l? c?a a v� b
    if (gcd(a, 26) != 1) {
        cout << "Gia tri cua a khong hop le. Vui long chon gia tri khac." << endl;
        return 0;
    }

    // M� h�a chu?i v� hi?n th? k?t qu?
    string mahoachuoi = mahoa(chuoi, a, b);
    cout << "Chuoi sau khi ma hoa: " << mahoachuoi << endl;

    // Gi?i m� chu?i v� hi?n th? k?t qu?
    string giaimachuoi = giaima(mahoachuoi, a, b);
    cout << "Chuoi sau khi giai ma: " << giaimachuoi << endl;

    return 0;
}

