// Trong một liên hoan phim, n bộ phim sẽ được chiếu. Bạn biết thời gian bắt đầu và kết thúc của mỗi bộ phim. Số lượng phim tối đa bạn có thể xem toàn bộ là bao nhiêu? Biết rằng nếu thời gian kết thúc của bộ phim trước bằng hoặc nhỏ hơn thời gian bắt đầu của bộ phim sau thì bạn có thể xem cả 2 phim này.

// Input Format

// Dòng nhập đầu tiên có số nguyên n: số lượng phim. Sau đó, có n dòng mô tả các bộ phim. Mỗi dòng có hai số nguyên a và b: thời gian bắt đầu và kết thúc của một bộ phim.

// Constraints

// 1≤ n, m ≤2.10^5; 1≤ a, b ≤10^9

// Output Format

// In một số nguyên: số lượng phim tối đa.

// Sample Input 0

// 3
// 3 5
// 4 9
// 5 8
// Sample Output 0

// 2
// Explanation 0

// Giải thích test : Bạn có thể xem 2 bộ phim (3,5) và (5,8)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> vt(n);
    for (int i = 0; i < n; i++) {
        cin >> vt[i].first >> vt[i].second;
    }
    // Ta chỉ cần sort theo thời gian kết thúc của bộ phim
    sort(vt.begin(), vt.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    int end = vt[0].second, cnt = 1;
    for (int i = 1; i < n; i++) {
        if (vt[i].first >= end) {
            cnt++;
            end = vt[i].second;
        }
    }
    cout << cnt;
    return 0;
}