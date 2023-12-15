// Cho một tập gồm N phần tử được đánh số từ 1 đến N. Nhiệm vụ của bạn là liệt kê tất cả các tập con khác rỗng của N theo thứ tự từ điển tăng dần.

// Input Format

// Dòng duy nhất chứa số nguyên dương N.

// Constraints

// 1<=N<=9;

// Output Format

// In ra các tập con của N theo thứ tự từ điển tăng dần.

// Sample Input 0

// 4
// Sample Output 0

// 1 
// 1 2 
// 1 2 3 
// 1 2 3 4 
// 1 2 4 
// 1 3 
// 1 3 4 
// 1 4 
// 2 
// 2 3 
// 2 3 4 
// 2 4 
// 3 
// 3 4 
// 4 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main() {
    cin >> n;
    vector<string> vt;
    for (int i = 0;i<(1<<n);i++){
        string temp = "";
        for (int j = 0;j<n;j++){
            if ((i & (1<<j)) !=0){
                temp += to_string(j+1) + " ";
            }
        }
        vt.push_back(temp);
    }
    // Dong nay quan trong
    sort(vt.begin(), vt.end());
    for (int i = 1;i<vt.size();i++) cout << vt[i] << endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
