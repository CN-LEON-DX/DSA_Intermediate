#include <bits/stdc++.h>
using namespace std;

// Run Time 
#define TIME cout << "\nTime: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s"

// Debug
void __print(int x) {cerr << x;}
// Other debug functions omitted for brevity...

typedef pair<int,int> ii;
const int MOD = 1e9+7;

int n;
int x[100][100];
vector<pair<ii, char>> step = {{{1, 0}, 'D'}, {{0, 1}, 'R'}};
vector<string> vt;
string temp = "";

void Try(int i, int j) {
    // Check if we reached the destination
    if (i == n && j == n) {
        vt.push_back(temp);
        return;
    }

    for (auto t : step) {
        int new_i = i + t.first.first;
        int new_j = j + t.first.second;

        // Check bounds and if the cell is walkable
        if (new_i <= n && new_j <= n && x[new_i][new_j] == 1) {
            x[new_i][new_j] = 0; // Mark as visited
            temp += t.second; // Add move to path
            Try(new_i, new_j); // Recursive call
            x[new_i][new_j] = 1; // Unmark to backtrack
            temp.pop_back(); // Remove last move
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> x[i][j];
        }
    }

    // Ensure start and end points are valid
    if (x[1][1] == 1 && x[n][n] == 1) {
        Try(1, 1);
    }

    for (auto it : vt) {
        cout << it << endl;
    }

    return 0;
}
