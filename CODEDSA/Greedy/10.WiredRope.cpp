// Cho mảng A[] gồm N số và thực hiện các thao tác theo nguyên tắc dưới đây: 1. Ta chọn một mảng con sao cho phần tử ở giữa của mảng con cũng là phần tử ở giữa của mảng A[] (trong trường hợp N lẻ). 2. Đảo ngược mảng con đã chọn trong mảng A[]. Ta được phép chọn mảng con và phép đảo ngược mảng con bao nhiêu lần tùy ý. Ví dụ với mảng A[] = {1, 6, 3, 4, 5, 2, 7} ta có câu trả lời là YES vì: ta chọn mảng con {3, 4, 5} và đảo ngược để nhận được mảng A[]={1, 6, 5, 4, 3, 2, 7}, chọn tiếp mảng con {6, 5, 4, 3, 2} và đảo ngược ta nhận được mảng A[]={1, 2, 3, 4, 5, 6, 7}. Hãy cho biết ta có thể sắp xếp được mảng A[] bằng cách thực hiện các thao tác kể trên hay không?

// Input Format

// Dòng 1 chứa số nguyên dương N là số lẻ.
// Dòng 2 chứa N số nguyên của mảng A[]

// Constraints

// 1<=N<=10^6; 0<=A[i]<=10^9;

// Output Format

// In ra YES hoặc NO là đáp án của bài toán

// Sample Input 0

// 5
// 1 3 8 7 3 
// Sample Output 0

// NO
// Sample Input 1

// 5
// 1 4 3 2 5
// Sample Output 1

// YES
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#define INT 1000000007
using namespace std;
using ll = long long;
int n; 
int main() {
    priority_queue<ll> pq;
    cin >> n;
    while (n--){
        ll k; cin >> k;
        pq.push(k);
    }
    ll res = 0;
    vector<ll> vt;
    while (pq.size()!=1){
        res += pq.top(); pq.pop();
        res += pq.top(); pq.pop();
        vt.push_back(res);
        pq.push(res);
        res = 0;
    }
    ll result = 0;
    for (ll x : vt){
        result = result % INT + x % INT;
    }
    cout << result%INT;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

