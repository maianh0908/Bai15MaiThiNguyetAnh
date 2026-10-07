#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct KhachHang
{
    int maKH;
    string tenKH;
    string soDienThoai;
    double tongTien;
};

void Nhap(KhachHang a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap khach hang thu " << i + 1 << ":\n";

        cout << "Ma khach hang: ";
        cin >> a[i].maKH;
        cin.ignore();

        cout << "Ten khach hang: ";
        getline(cin, a[i].tenKH);

        cout << "So dien thoai: ";
        getline(cin, a[i].soDienThoai);

        cout << "Tong tien thanh toan: ";
        cin >> a[i].tongTien;
    }
}

void Xuat(KhachHang a[], int n)
{
    cout << "\n";

    cout << left
         << setw(10) << "Ma KH"
         << setw(25) << "Ten khach hang"
         << setw(18) << "So dien thoai"
         << setw(15) << "Tong tien"
         << endl;

    for (int i = 0; i < n; i++)
    {
        cout << left
             << setw(10) << a[i].maKH
             << setw(25) << a[i].tenKH
             << setw(18) << a[i].soDienThoai
             << setw(15) << fixed << setprecision(2) << a[i].tongTien
             << endl;
    }
}

void InsertionSort(KhachHang a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        KhachHang x = a[i];
        int j = i - 1;

        while (j >= 0 && a[j].tongTien > x.tongTien)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = x;
    }
}

void TimKiem(KhachHang a[], int n, double X)
{
    int trai = 0;
    int phai = n - 1;
    int viTri = -1;
    while (trai <= phai)
    {
        int mid = (trai + phai) / 2;

        if (a[mid].tongTien == X)
        {
            viTri = mid;
            break;
        }
        else if (a[mid].tongTien < X)
        {
            trai = mid + 1;
        }
        else
        {
            phai = mid - 1;
        }
    }

    if (viTri == -1)
    {
        cout << "\nKhong tim thay khach hang co tong tien = "
             << fixed << setprecision(2) << X << endl;
        return;
    }

    int dau = viTri;

    while (dau > 0 && a[dau - 1].tongTien == X)
    {
        dau--;
    }

    int cuoi = viTri;

    while (cuoi < n - 1 && a[cuoi + 1].tongTien == X)
    {
        cuoi++;
    }

    cout << "\nCac khach hang co tong tien thanh toan = "
         << fixed << setprecision(2) << X << ":" << endl;

    cout << left
         << setw(10) << "Ma KH"
         << setw(25) << "Ten khach hang"
         << setw(18) << "So dien thoai"
         << setw(15) << "Tong tien"
         << endl;

    for (int i = dau; i <= cuoi; i++)
    {
        cout << left
             << setw(10) << a[i].maKH
             << setw(25) << a[i].tenKH
             << setw(18) << a[i].soDienThoai
             << setw(15) << fixed << setprecision(2) << a[i].tongTien
             << endl;
    }
}

int main()
{
    KhachHang a[100];
    int n;
    double X;

    cout << "Nhap so luong khach hang n = ";
    cin >> n;

    while (n <= 0 || n > 100)
    {
        cout << "Nhap lai n (0<n<=100): ";
        cin >> n;
    }

    Nhap(a, n);

    cout << "\nDANH SACH KHACH HANG VUA NHAP";
    Xuat(a, n);

    InsertionSort(a, n);

    cout << "\nDANH SACH SAU KHI SAP XEP THEO CHIEU TANG DAN";
    Xuat(a, n);

    cout << "\nNhap tong tien X can tim: ";
    cin >> X;

    TimKiem(a, n, X);

    return 0;
}
