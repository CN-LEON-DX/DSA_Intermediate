// Có N nhóm học sinh, mỗi nhóm học sinh có từ 1 tới 4 người. Các nhóm học sinh này dự định sẽ đi thăm quan vườn bách thú bằng những chiếc xe taxi, mỗi xe taxi trở được tối đa 4 người. Hãy tìm số lượng taxi tối thiểu để có thể trở hết N nhóm học sinh này, biết rằng những học sinh ở cùng 1 nhóm sẽ đi cùng 1 taxi

// Input Format

// Dòng đầu tiên chứa số nguyên dương N là số nhóm học sinh; Dòng thứ 2 gồm N số là số lượng của các nhóm học sinh

// Constraints

// 1<=N<=10000; Số lượng học sinh của mỗi nhóm là 1 số dương không quá 4

// Output Format

// In ra số lượng xe taxi tối thiểu cần dùng

// Sample Input 0
// 6
// 2 1 3 1 2 2 
// Sample Output 0
// 3
// Buoc lam 
// 1. Sap xep cac nhom hoc sinh theo thu tu tang dan
// 2. Duyet tu dau den cuoi mang, neu so luong hoc sinh cua nhom hien tai + so luong hoc sinh cua nhom tiep theo <= 4 thi gop 2 nhom lai
// 3. Neu khong thi tang so luong taxi len 1
// 4. In ra so luong taxi
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int d[5] = {0};
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        d[x]++;
    }

    int taxi = d[4] + d[3] + d[2] / 2;
    d[1] -= d[3];
    if (d[2] % 2 == 1) {
        taxi++;
        d[1] -= 2;
    }
    if (d[1] > 0) {
        taxi += (d[1] + 3) / 4;
    }

    cout << taxi << endl;

    return 0;
}
