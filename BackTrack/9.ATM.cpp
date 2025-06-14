// Một máy ATM hiện có n (n ≤ 30) tờ tiền có giá trị t[1], t[2], …, t[n]. Hãy tìm cách trả ít tờ nhất với số tiền đúng bằng S (các tờ tiền có giá trị bất kỳ và có thể bằng nhau, mỗi tờ tiền chỉ được dùng một lần).

// Input Format

// Dòng 1 gồm 2 số nguyên n và S (S ≤ 10^9). Dòng thứ hai chứa n số nguyên t[1], t[2], …, t[n] (t[i] ≤ 10^9)

// Constraints

// 1<=N<=30; 1<=S<=10^9; 1<=t[i]<=10^9;

// Output Format

// In ra số tờ tiền ít nhất phải trả, nếu không thể tìm được ra kết quả thì in -1.

// Sample Input 0

// 6 30
// 10 4 10 5 8 8 
// Sample Output 0
// 4

// So cach giai bai nay la dung quy hoach dong. Ta co cong thuc: F[i][j] = min(F[i-1][j], F[i][j-t[i]] + 1)
// Ngoai ra ta con co the giai bang phuong phap quay lui nhu sau:
// - Buoc 1: Sap xep mang t[] theo thu tu giam dan
// - Buoc 2: Goi ham Try(i, j) de tim so to tien it nhat de tra cho so tien j voi cac to tien tu t[i] den t[n]
// - Buoc 3: Neu co the tra duoc thi in ra ket qua, nguoc lai in ra -1
#include <iostream>
#include <algorithm>
using namespace std;

int n, s;
int a[31];
int res = 1e9;

void Try(int i, int sum, int cnt){
    if(sum == s) {
        res = min(res, cnt);
        return;
    }
    if(i > n || sum > s) return;
    Try(i+1, sum+a[i], cnt+1);
    Try(i+1, sum, cnt);
}

int main() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1, greater<int>());
    Try(1, 0, 0);
    if(res == 1e9) res = -1;
    cout << res;
    return 0;
}
