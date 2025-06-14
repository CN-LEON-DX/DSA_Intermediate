// Một nhà máy có n máy có thể được sử dụng để tạo ra sản phẩm. Mục tiêu của bạn là tạo ra tổng số sản phẩm. Đối với mỗi máy, bạn biết số giây nó cần để tạo ra một sản phẩm. Các máy có thể hoạt động đồng thời và bạn có thể tự do quyết định lịch trình của chúng. Thời gian ngắn nhất cần thiết để làm ra t sản phẩm là bao nhiêu? (Gợi ý : Binary search on answer)

// Input Format

// Dòng nhập đầu tiên có hai số nguyên n và t: số lượng máy móc và sản phẩm. Dòng tiếp theo ghi n số nguyên k1, k2,…, kn: thời gian cần thiết để tạo ra một sản phẩm sử dụng mỗi máy.

// Constraints

// 1≤n≤2⋅10^5; 1≤t≤10^9; 1≤ki≤10^9;

// Output Format

// In một số nguyên: thời gian tối thiểu cần thiết để tạo ra t sản phẩm.

// Sample Input 0

// 3 7
// 3 2 5
// Sample Output 0

// 8
// Explanation 0

// Giải thích test : Trong 8s, máy 1 làm được 2 sản phẩm, máy 2 làm được 4, máy 3 làm được 1 sản phẩm.
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

bool check(ll a[], ll n, ll mid, ll k){
    ll res = 0;
    for (ll i = 0; i < n; i++){
        res += mid/a[i];
        if(res >= k) return true;
    }
    return false;
}

int main() {
    ll n, k; cin >> n >> k;
    ll a[n];
    for (ll &i : a) cin >> i;
    ll res = -1;
    ll l = 0;
    ll r = *max_element(a, a+n) * k;
    while (l <= r){
        ll mid = l + (r - l) / 2;
        if (check(a, n, mid, k)){
            res = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    cout << res;
    return 0;
}