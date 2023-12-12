#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
using namespace std;


int main() {
    int n; cin >> n;
    int a[n];
    for (int &i : a) cin >> i;
    int l = 0;
    int r = 0;
    multiset<int> se;
    int res = -1;
    while (r < n){
        se.insert(a[r]);
        while (se.count(a[r]) >= 2){
            auto it = se.find(a[l]);
            if (it != se.end()) se.erase(it);
            l++;
        }
        res = max(res, r - l + 1);
        r++;
    }
    cout << res;
    return 0;
}
// Bạn được cung cấp một danh sách phát của một đài phát thanh kể từ khi đài đó được thành lập. Danh sách bài hát có tổng cộng n bài hát. Chuỗi các bài hát liên tiếp dài nhất mà mỗi bài hát là duy nhất?

// Input Format

// Dòng đầu tiên chứa một số nguyên n: số lượng bài hát. Dòng tiếp theo có n số nguyên k1, k2,…, kn: số id của mỗi bài hát.

// Constraints

// 1≤n≤2⋅10^5; 1≤ki≤10^9

// Output Format

// In độ dài của chuỗi bài hát dài nhất mà các bài hát này mỗi bài hát chỉ xuất hiện 1 lần.

// Sample Input 0

// 5
// 1 2 3 4 5
// Sample Output 0

// 5
// Sample Input 1

// 5
// 1 1 1 1 1
// Sample Output 1

// 1
// Sample Input 2

// 8
// 1 2 1 3 2 7 4 2
// Sample Output 2

// 5