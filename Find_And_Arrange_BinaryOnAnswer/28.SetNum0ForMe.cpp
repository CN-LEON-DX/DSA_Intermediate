// Cho mảng A[] gồm n phần tử. Nhiệm vụ của bạn là hãy sắp đặt lại các phần tử của mảng sao cho các số 0 để ở cuối cùng, các phần tử khác 0 được bảo toàn thứ tự trước sau. Ví dụ với mảng A[] = {1, 2, 0, 0, 0, 3, 6} ta có kết quả A[] = {1, 2, 3, 6, 0, 0, 0}.

// Input Format

// Dòng đầu tiên đưa vào n là số phần tử của mảng A[]; Dòng kế tiếp đưa vào n số A[i] của mảng; Các số được viết cách nhau một vài khoảng trống.

// Constraints

// 1≤ N ≤10^5; 1≤ A[i] ≤10^5.

// Output Format

// In ra kết quả trên một dòng

// Sample Input 0

// 7
// 1 2 0 0 0 3 6
// Sample Output 0

// 1 2 3 6 0 0 0
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> a;
    int cnt = 0;
    while (n--){
        int k; cin >> k;
        if (k!=0) a.push_back(k);
        else cnt++;
    }
    for (int x : a) cout << x << " ";
    while (cnt--) cout << 0 << " ";
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}