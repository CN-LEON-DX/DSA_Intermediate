// Cho N công việc. Mỗi công việc được biểu diễn như một bộ 3 số nguyên dương , trong đó JobId là mã của việc, Deadline là thời gian kết thúc của việc, Profit là lợi nhuận đem lại nếu hoàn thành việc đó đúng thời gian. Thời gian để hoàn toàn mỗi công việc là 1 đơn vị thời gian. Hãy cho biết lợi nhuận lớn nhất có thể thực hiện các việc với giả thiết mỗi việc được thực hiện đơn lẻ.

// Gợi ý : B1. Sắp xếp công việc theo lợi nhuận giảm dần

// B2. Đối với mỗi công việc => Lựa chọn mốc thời gian bắt đầu để thực hiện công việc, ví dụ nếu deadline là X thì mốc thời gian hợp lệ sẽ là 0,1...X-1, và lựa chọn mốc thời gian lớn nhất còn trống để thực hiện công việc này, sau đó đánh dấu mốc thời gian này đã được sử dụng.

// struct job{
//     int id, deadline, profit;
// };
// Input Format

// Dòng thứ 1 chứa số nguyên dương N; N dòng tiếp theo mô tả id, deadline, profit của N công việc

// Constraints

// 1<=N<=10^5; 1<=JobID<=N; 1<=Deadline<=N; 1<=Profit<=1000;

// Output Format

// In ra lợi nhuận lớn nhất

// Sample Input 0

// 4
// 1 4 20
// 2 1 10
// 3 1 40
// 4 1 30
// Sample Output 0

// 60
#include<bits/stdc++.h>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

int findMaxProfit(Job arr[], int n) {
    sort(arr, arr+n, comparison);

    int result[n];
    bool slot[n];

    for (int i=0; i<n; i++)
        slot[i] = false;

    for (int i=0; i<n; i++) {
        for (int j=min(n, arr[i].deadline)-1; j>=0; j--) {
            if (slot[j]==false) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    int maxProfit = 0;
    for (int i=0; i<n; i++)
        if (slot[i])
            maxProfit += arr[result[i]].profit;
    return maxProfit;
}

int main() {
    int n;
    cin >> n;
    Job arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;
    }
    cout << findMaxProfit(arr, n);
    return 0;
}