// Cho mảng A[] gồm N số nguyên dương phân biệt và số X. Nhiệm vụ của bạn là tìm phép tổ hợp các số trong mảng A[] có tổng bằng X. Các số trong mảng A[] có thể được sử dụng nhiều lần. Mỗi tổ hợp các số của mảng A[] được in ra theo thứ tự không giảm các số. Ví dụ với A[] = {2, 4, 6, 8}, X = 8 ta có các tổ hợp các số như sau: {2, 2, 2, 2}, {2, 2, 4}, {2, 6}, {4, 4}, {8}.

// Input Format

// Dòng thứ nhất là hai số N và X; dòng tiếp theo đưa vào N số của mmảng A[]; các số được viết cách nhau một vài khoảng trống

// Constraints

// 1<=N<=20; 1<=X,A[i]<=100;

// Output Format

// In ra số tổ hợp thỏa mãn sau đó in ra các tổ hợp thỏa mãn trên từng dòng. Xem output để rõ hơn cách in. Trong trường hợp không có tổ hợp thỏa mãn thì in ra -1.

// Sample Input 0

// 3 10
// 4 2 3 
// Sample Output 0

// 5
// {2 2 2 2 2}
// {2 2 2 4}
// {2 2 3 3}
// {2 4 4}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x;
vector<int> a, res;
vector<vector<int>> result;

void print() {
    for (auto &v : result) {
        cout << "{";
        for (int i = 0; i < v.size(); i++) {
            if (i==v.size()-1) cout << v[i];
            else cout << v[i] << " ";
        }
        cout << "}" << endl;
    }
}

void Try(int i, int sum) {
    if (sum == x) {
        result.push_back(res);
        return;
    }
    for (int j = i; j < n; j++) {
        if (sum + a[j] <= x) {
            res.push_back(a[j]);
            Try(j, sum + a[j]);
            res.pop_back();
        }
    }
}

int main() {
    cin >> n >> x;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    Try(0, 0);
    if (result.empty()) {
        cout << -1 << endl;
    } else {
        cout << result.size() << endl;
        print();
    }
    return 0;
}
// {3 3 4}