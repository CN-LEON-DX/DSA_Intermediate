#include <bits/stdc++.h>
using namespace std;

#define TIME cout << "\nTime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s"
#define MAX 100

int n;
int x[MAX], c[MAX], cr1[MAX], cr2[MAX];
int cnt = 0;

// Put by row = i | column = j
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (c[j] == 0 && cr1[i - j + n] == 0 && cr2[i + j - 1] == 0) {
            x[i] = j;        // Place the queen at row i, column j
            c[j] = 1;        // Mark column j as occupied
            cr1[i - j + n] = 1; // Mark the main diagonal as occupied
            cr2[i + j - 1] = 1; 
            
            if (i == n) {
                ++cnt;
                for (int t = 1; t <= n; t++) {
                    cout << "Queen " << t << " is placed in column: " << x[t] << endl;
                }
                cout << endl;
            } else {
                Try(i + 1); // Recur for the next row
            }
            
            // Backtracking
            c[j] = 0;
            cr1[i - j + n] = 0;
            cr2[i + j - 1] = 0;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    cin >> n;
    cout << n << " Queens Problem Solutions:\n";
    Try(1);
    cout << "Total Solutions: " << cnt << endl;
    return 0;
}
