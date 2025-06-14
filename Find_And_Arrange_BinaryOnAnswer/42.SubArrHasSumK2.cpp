// Cho một mảng gồm n số nguyên, nhiệm vụ của bạn là đếm số mảng con (dãy con các phần tử liên tiếp) có tổng bằng x.

// Input Format

// Dòng đầu tiên có hai số nguyên n và x: kích thước của mảng và tổng mục tiêu x. Dòng tiếp theo có n số nguyên a1, a2,…, an: các phần tử trong mảng

// Constraints

// 1≤n≤2⋅10^5; -10^9≤x, ai≤10^9

// Output Format

// In một số nguyên: số lượng mảng con cần thiết.

// Sample Input 0

// 5 7
// 2 4 1 2 7
// Sample Output 0

// 3
// Bài này có một đăc điểm khác bài 41 là mảng có thể có số âm, 
// 
// nên ta không thể dùng 2 con trỏ l, r như bài 41 được.
//  Ta sẽ dùng 2 con trỏ l, r nhưng sẽ có một điều kiện
// mới là sum(l, r) >= k thì mới tăng lên, nếu không thì 
// ta sẽ tăng r lên. Điều này đảm bảo rằng mảng con 
// sum(l, r) luôn có tổng >= k.
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int n, k; cin >> n >> k;
    int l = 0;
    int a[n]; for(int &x : a) cin >> x;
    ll sum = 0;
    ll cnt = 0;
    for (int r = 0;r<n;r++){
        sum+=a[r];
        while (sum > k && l<n){
            if (a[l]==0 && sum==k){
                cnt++;
                l++;
            }
            if (a[l]<0) sum+=a[l];
            
            else sum-=a[l];
            l++;
        }
        if (sum==k) cnt++;
    }
    cout << cnt << endl;
    return 0;
} 