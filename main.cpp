#include<bits/stdc++.h>

#define MAX 8
using namespace std;

int A[MAX][MAX] = { 0 };//Khởi tạo mảng giá trị 0
int X[8] = { -2,-2,-1,-1, 1, 1, 2, 2};
int Y[8] = { -1, 1,-2, 2,-2, 2,-1, 1};
int dem = 0;//Số bước đi
int n;

void xuat() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout<<A[i][j]<<" ";
        cout << endl;
    }
    cout << endl;
}

void diChuyen(int x, int y) {
    ++dem;//Tăng giá trị bước đi
    A[x][y] = dem;//Đánh dấu đã đi
    for (int i = 0; i < 8; i++)    {
        //Kiểm tra xem mã đã đi hết bàn cờ chưa
        if (dem == n * n) {
            cout << "Cac buoc di la: \n";
            xuat();
            exit(0);//kết thúc chương trình
        }
        //Nếu chưa đi hết bàn cờ thì tạo bước đi mới
        int u = x + X[i];//tạo một vị trí x mới
        int v = y + Y[i];//tạo một vịi trí y mới
        //Nếu hợp lẹ thì tiến hành di chuyển
        if (u >= 0 && u < n&&v >= 0 && v < n&& A[u][v] == 0)
            diChuyen(u, v);
    }
    //Nếu không tìm được bước đi thì ta phải trả lại các giá trị ban đầu
    --dem;
    A[x][y] = 0;
}
int main() {

    cin >> n;
    int a, b;

    cin>>a;

    cin >> b;
    diChuyen(a, b);

    cout << "-1";
}