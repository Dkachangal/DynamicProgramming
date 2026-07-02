#include<iostream>
#include<vector>
using namespace std;


int trib(int n) {
    // RECURSIVE APPROACH
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    return (trib(n-1) + trib(n-2) + trib(n-3));
} 

// MEMORISATIO
int tribM(int n) {
    vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for (int i=3; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];

}

int tribDPTabu(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    int curr = 0;
    int prev3 = 0;
    int prev2 = 1;
    int prev1 = 1;

    for (int i=3; i<=n; i++) {
        curr = prev3 + prev2 + prev1;
        prev3 = prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}
// Tabulation

int main() {
    int n = 1;
    cout << tribDPTabu(n);

    return 0;
}