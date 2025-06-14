#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int n, m, s;
vector<int> a[1001];
bool visited[1001];
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        cout << v << ' ';
        for (int x : a[v]){
            if (!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}
int main() {
    cin >> n >> m >> s;
    memset(visited, false, sizeof(visited));
    for (int i = 1;i<= m;i++){
        int x, y; cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i<= n;i++){
        sort(a[i].begin(), a[i].end());
    }
    bfs(s);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh. Hãy thực hiện in ra danh sách các đỉnh được duyệt theo thuật toán BFS(s).

Input Format

Dòng đầu tiên là 2 số n và m và s, tương ứng với số lượng đỉnh, cạnh của đồ thị và đỉnh bắt đầu duyệt. Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Constraints

1<=s<=n<=1000; 1<=m<=n*(n-1)/2;

Output Format

In ra các đỉnh được duyệt theo thuật toán BFS(s). Chú ý trong quá trình mở rộng các đỉnh của thuật toán BFS luôn lựa chọn duyệt các đỉnh có thứ tự nhỏ hơn trước.

Sample Input 0

5 7 5
4 1
5 3
4 3
5 1
3 2
4 2
2 1
Sample Output 0

5 1 3 2 4 