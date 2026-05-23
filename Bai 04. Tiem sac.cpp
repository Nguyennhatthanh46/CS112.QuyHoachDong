/*
Tiệm sách
Bạn đang ở trong một cửa hàng sách bán n cuốn sách khác nhau. Bạn biết giá và số trang của mỗi cuốn sách.

Bạn đã quyết định rằng tổng giá mua của bạn tối đa là x. Số lượng trang tối đa bạn có thể mua là bao nhiêu? 
Bạn có thể mua mỗi cuốn nhiều nhất một lần.

Input:
Dòng đầu tiên là hai số nguyên n và x lần lượt là số lượng sách và số tiền tối đa mà bạn chi.

Dòng thứ hai là dãy n số nguyên h1, h2, ..., hn, là giá trị của mỗi cuốn sách.

Dòng thứ ba là dãy n số nguyên s1, s2, ..., sn, là số lượng trang của mỗi cuốn sách.

Output
Một số nguyên là số lượng trang sách tối đa có thể mua được
Điều kiện
1 <= n <= 1000
1 <= x <= 10^5
1 <= hi, si <= 1000

Example:
Input
4 10
4 8 5 3
5 12 8 1

Output
13
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> h(n), s(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++) cin >> s[i];

    vector<int> dp(x + 1, 0);  

    for(int i = 0; i < n; i++)
        for(int j = x; j >= h[i]; j--)  
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);

    cout << dp[x] << "\n";
    return 0;
}
