// Cho dãy số A[] = (a1, a2, .., an) và số tự nhiên K. Hãy đưa ra tất cả các dãy con của dãy số A[] sao cho tổng các phần tử của dãy con đó đúng bằng K. Các phần tử của dãy số A[] được giả thuyết là nguyên dương và không có các phần tử giống nhau. Ví dụ với dãy con A[] = {5, 10, 15, 20, 25}, K = 50 ta có 3 dãy con {5, 10, 15, 20}, {5, 20, 25}, {10, 15, 25}.

// Input Format

// Dòng thứ 1 đưa vào số N là số lượng phần tử của dãy số A[] và số K; Dòng tiếp theo đưa vào N phần tử của dãy số A[].

// Constraints

// 1<=N<=15; 1<=A[i],K<=100;

// Output Format

// Đưa ra tất cả các dãy con của dãy số A[] thỏa mãn yêu cầu bài toán theo thứ tự từ điển, trong đó mỗi dãy con được bao bởi các ký tự [, ]. Nếu không có dãy con nào thỏa mãn yêu cầu bài toán, hãy đưa ra -1.

// Sample Input 0

// 10 26
// 12 11 9 10 6 8 14 7 5 13 
// Sample Output 0

// [5 6 7 8]
// [5 7 14]
// [5 8 13]
// [5 9 12]
// [5 10 11]
// [6 7 13]
// [6 8 12]
// [6 9 11]
// [7 8 11]
// [7 9 10]
// [12 14]
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
int N, K;
int check = 0;
int X[16], a[16];
vector<vector<int>> vt;
void init(){
    cin >> N >> K;
    for (int i = 1;i<=N;i++){
        cin >> a[i];
    }
}
void Try(int i, int start){
    for (int j = start;j<=N;j++){
        if (a[j] <= K){
            X[i] = a[j];
            ll sum = 0;
            for (int k = 1;k<=i;k++) sum+=X[k];
            if (sum == K){
                vector<int> v;
                check = 1;
                for (int k = 1;k<=i;k++){
                    v.push_back(X[k]);
                }
                
                vt.push_back(v);
            }
            Try(i+1, j+1);
        }
    }
}

int main() {
    init();
    Try(1, 1);
    if (!check) cout << -1;
    for (auto &it : vt){
        sort(it.begin(), it.end());
    }
    sort(vt.begin(), vt.end());
    for (auto it : vt){
        cout << "[";
        for (int i = 0;i<it.size();i++){
            if (i == it.size()-1) cout << it[i];
            else cout << it[i] << " ";
        }
        cout << "]";
        cout << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
