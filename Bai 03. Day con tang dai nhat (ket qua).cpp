#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> dp(n, 1);
    vector<int> m(n, -1);

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[j] < a[i] && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
                m[i] = j;  
            }
        }
    }

    int maxLen = 0, endIdx = 0;
    for(int i = 0; i < n; i++){
        if(dp[i] > maxLen){
            maxLen = dp[i];
            endIdx = i;
        }
    }

    vector<int> lis;
    for(int i = endIdx; i != -1; i = m[i])
        lis.push_back(a[i]);
    reverse(lis.begin(), lis.end());

    cout << maxLen << "\n";
    for(int x : lis) cout << x << " ";

    return 0;
}
