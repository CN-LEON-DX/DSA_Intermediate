// Tại sân bay, mọi người đang làm thủ tục để check in. Có tất cả N vị khách. Vị khách thứ i tới làm thủ tục tại thời điểm T[i] và cần D[i] thời gian để check in xong. Các bạn hãy xác định xem thời điểm nào tất cả các vị khách làm xong thủ tục để lên máy bay?

// Input Format

// Dòng đầu tiên là số nguyên dương N; N dòng tiếp theo, mỗi dòng gồm 2 số nguyên cho biết thời điểm đến của vị khách thứ i và thời gian vị khách này làm xong thủ tục check in. Các giá trị này không vượt quá 10^6.

// Constraints

// 1<=N<=10^5; 1<=T[i], D[i]<=10^6

// Output Format

// In ra đáp án tìm được.

// Sample Input 0

// 3
// 2 1
// 8 3
// 5 7
// Sample Output 0

// 15
// Explanation 0

// Người thứ 1 đến lúc 2h và làm thủ tục hết 1h => 3h xong Người thứ 2 đến lúc 5h và làm thủ tục hết 7h => 12h xong Người thứ 3 đến lúc 8h nhưng người thứ 2 12h mới làm xong nên bắt đầu làm từ 12h => 15h xong

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int n; cin >> n; 
    vector<pair<int, int>> vt;
    while (n--){
        int x, y; cin >> x >> y;
        vt.push_back({x, y});
    }
    sort(vt.begin(), vt.end());
    int temp = vt[0].second;
    ll cnt = vt[0].first + vt[0].second;
    for (int i = 1;i<vt.size();i++){
        if (cnt < vt[i].first){
            cnt = vt[i].first + vt[i].second;
        }else{
            cnt += vt[i].second;
        }
    }
    cout << cnt << endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}