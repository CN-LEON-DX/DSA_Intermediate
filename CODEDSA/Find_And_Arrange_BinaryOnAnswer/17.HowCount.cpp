// Cho mảng a gồm n phần tử và số nguyên dương k. Đếm số lượng cặp số ai, aj (i != j) có tổng bằng k.

// Gợi ý : Sắp xếp mảng tăng dần sau đó với mỗi phần tử a[i] trong mảng tìm xem trong đoạn [i + 1, n - 1] có bao nhiêu phần tử có giá trị là k - a[i], bằng cách tìm vị trí đầu tiên và vị trí cuối cùng của phần tử có giá trị là k - a[i] => Số lượng

// Input Format

// Dòng thứ 1 là số lượng phần tử trong mảng và số nguyên dương k; Dòng thứ 2 là n phần tử trong mảng

// Constraints

// 2<=n<=10^6; 1<=k<=10^6; 0<=a[i]<=10^6;

// Output Format

// In ra số lượng cặp số có tổng bằng k

// Sample Input 0

// 4 4
// 2 2 2 2
// Sample Output 0

// 6
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;
int main() {
    int n, k; cin >> n >> k;
    int a[n];
    for (int &x : a) cin >> x;
    sort(a, a+n);
    ll cnt = 0;
    for (int i = 0;i<n;i++){
        int x = lower_bound(a+i+1, a+n, k-a[i])-a;
        int y = upper_bound(a+i+1, a+n, k-a[i])-a;
        cnt+=y-x;
    }
    cout << cnt;
    return 0;
}
