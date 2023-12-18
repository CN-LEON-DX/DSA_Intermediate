// Cô bé Anna đi mua sắm cùng mẹ và cô băn khoăn không biết làm thế nào để cải thiện chất lượng dịch vụ.

// Có n người trong hàng đợi. Đối với mỗi người, chúng tôi biết thời gian cần thiết t để phục vụ anh ta. Một người sẽ thất vọng nếu thời gian anh ta chờ đợi nhiều hơn thời gian cần thiết để phục vụ anh ta. Thời gian một người chờ là tổng thời gian tất cả những người đứng trong hàng đợi trước mặt anh ta được phục vụ. Anna nghĩ rằng nếu chúng ta hoán đổi một số người trong hàng đợi, thì chúng ta có thể giảm số người thất vọng.

// Giúp Anna tìm ra con số tối đa mà những người không thất vọng có thể đạt được bằng cách hoán đổi những người trong hàng đợi.

// Input Format

// Dòng đầu tiên chứa số N là số người trong hàng đợi; Dòng thứ 2 chứa N số là thời gian cần phục vụ của N người

// Constraints

// 1<=N<=10^5; 1<=t<=10^9;

// Output Format

// In ra đáp án của bài toán

// Sample Input 0

// 7
// 4 3 17 4 5 14 20 
// Sample Output 0

// 3
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    vector<long long> t(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    long long wait_time = 0;
    int ok = 0;
    for (int i = 0; i < N; i++) {
        if (wait_time <= t[i]) {
            ok++;
            wait_time += t[i];
        }
    }
    cout << ok;
    return 0;
}