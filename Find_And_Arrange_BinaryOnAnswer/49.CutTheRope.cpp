// Có n sợi dây, bạn cần cắt k đoạn dây có cùng chiều dài từ chúng. Tìm chiều dài tối đa của các mảnh dây bạn có thể nhận được.

// Input Format

// Dòng đầu tiên chứa hai số nguyên n và k. N dòng tiếp theo mỗi dòng ghi một số, chiều dài của sợi dây là a[i].

// Constraints

// (1≤n, k≤10000); (1≤ai≤10^7);

// Output Format

// In ra chiều dài của mảnh dây dài nhất mà bạn có thể cắt với 6 số sau dấu phẩy.

// Sample Input 0

// 4 11
// 802 743 457 539
// Sample Output 0

// 200.5000000
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n, k; cin >> n >> k;
    int a[n];
    for (int &i : a) cin >> i;
    double l = 1, r = *max_element(a, a+n);
    while (r - l > 1e-7){
        double mid = (l + r)/2;
        ll cnt = 0;
        for (int i = 0;i<n;i++){
            cnt += (int)(a[i]/mid);
        }
        if (cnt < k){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << fixed << setprecision(6) << l;
    return 0;
}