// Cho một mảng n số nguyên, nhiệm vụ của bạn là tính số mảng con liên tiếp có nhiều nhất k giá trị khác nhau.

// Input Format

// Dòng nhập đầu tiên có hai số nguyên n và k. Dòng tiếp theo có n số nguyên x1, x2,…, xn: nội dung của mảng.

// Constraints
// 1≤k≤n≤2⋅10^5;
// 1≤xi≤10^9
// Output Format
// In một số nguyên: số mảng con.
// Sample Input 0
// 100 3
// 3 2 3 4 3 3 4 2 3 1 4 4 1 3 4 4 3 1 3 1 4 2 2 3 4 3 2 1 1 1 4 1 1 2 2 1 3 2 4 3 1 3 4 2 1 3 2 2 2 1 4 4 1 4 3 3 3 1 2 1 2 3 1 2 4 3 1 2 4 3 1 4 3 2 1 4 3 4 1 2 3 3 2 2 2 4 4 4 3 2 2 3 4 2 4 2 4 3 1 1
// Sample Output 0
// 641
// Sample Input 1
// 5 2
// 1 2 3 1 1
// Sample Output 1

// 10
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n, k; cin >> n >> k;
    int a[n];
    for (int i = 0;i<n;i++) cin >> a[i];
    unordered_map<int, int> mp;
    int l = 0, r = 0; 
    int cnt = 0;
    ll result = 0;
    while (r < n){
        if (mp[a[r]]==0){
            cnt++;
        }
        mp[a[r]]++;
        while (cnt>k){
            mp[a[l]]--;
            if (mp[a[l]]==0){
                cnt--;
            }
            l++;
        }
        result += r - l + 1;
        r++;
    }
    cout << result << endl;
    return 0;
}