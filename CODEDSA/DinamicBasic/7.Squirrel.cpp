// Có N nhóm hạt ngũ cốc được đánh số từ 1 tới N mỗi nhóm sẽ có lượng hạt ngũ cốc là A[i] với 1<=i<=N, một con sóc đang ở vị trí nhóm hạt số 1. Nhiệm vụ của nó là tới được nhóm hạt thứ N, chi phí mỗi lần di chuyển từ nhóm hạt x sang nhóm hạt y là abs(A[x] - A[y]), mỗi lần di chuyển con sóc chỉ có thể di chuyển từ nhóm hạt i sang nhóm hạt i + 1 hoặc i + 2. Nhiệm vụ của bạn là tính số lượng ngũ cốc tối thiểu mà con sóc này phải tiêu tốn để có thể đi đến nhóm hạt thứ N
// Input Format
// Dòng 1 N
// Dòng 2 là N số là số hạt ngũ cốc của mỗi nhóm từ 1 tới N
// Constraints
// 1<=N<=10^6
// 1<=A[i]<=10^9
// Output Format
// In ra số lượng ngũ cốc mà sóc đã mất làm chi phí di chuyển
// Sample Input 0
// 9
// 3 7 2 4 8 1 1 5 5 
// Sample Output 0
// 10
// Sample Input 1
// 6
// 3 1 6 1 6 5
// Sample Output 1
// 4
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    int a[n+1];
    for (int i = 1;i<=n;i++) cin >> a[i];
    ll D[n+1];
    D[1] = 0;
    D[2] = abs(a[2] - a[1]);
    for (int i = 3;i<=n;i++){
        D[i] = min(D[i-1]+abs(a[i]-a[i-1]), D[i-2]+abs(a[i]-a[i-2]));
    }
    cout << D[n];
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
