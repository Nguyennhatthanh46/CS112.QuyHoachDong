/*
Người giao cơm
Lưu Ngô là một cậu sinh viên nhận giao cơm cho quán ăn nọ, công việc của cậu là mỗi ngày giao cơm đến n căn hộ khác nhau (mỗi căn hộ đánh số từ 1…n), đảm bảo rằng các căn hộ liên thông với nhau (luôn có đường đi từ căn hộ này đến n-1 căn hộ khác). Lo sợ sẽ hết xăng trên đường nên Lưu Ngô cần biết q khoảng cách từ căn hộ này đến căn hộ kia để đi cho phù hợp với lượng xăng còn lại trong bình. Thật tiếc vì cậu ấy không thể ước lượng được tất cả khoảng cách này, giúp cậu ta nhé:
Input:
Dòng đầu tiên chứa 2 số nguyên n và q: Số lượng căn hộ và số lượng khoảng cách Lưu Ngô muốn biết. Các căn hộ đánh số từ 1,2…n
n-1 dòng tiếp theo cho biết tồn tại đường đi giữa 2 căn hộ. Mỗi dòng chứa hai số nguyên a và b, thể hiện có đường đi giữa căn hộ a đến căn hộ b
Cuối cùng có q dòng mô tả các truy vấn khoảng cách: Mỗi dòng chứa số nguyên a và b: Khoảng cách ngắn nhất giữa căn hộ a đến căn hộ b là bao nhiêu, biết rằng khoảng cách giữa 2 căn hộ là số con đường cần phải đi qua?
Output
In q số nguyên, câu trả lời của mỗi truy vấn
Constraints
1 <= n,q <= 2.10^5
1 <= a,b <= n

Example:
5 3
1 2
1 3
3 4
3 5
1 3
2 5
1 4

output
1
3
2
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int LOG = 18;

vector<int> adj[MAXN];
int depth[MAXN];
int parent[MAXN][LOG];

void dfs(int u, int par, int d){
    depth[u] = d;
    parent[u][0] = par;
    for(int v : adj[u])
        if(v != par)
            dfs(v, u, d + 1);
}

void buildLCA(int n){
    for(int k = 1; k < LOG; k++)
        for(int v = 1; v <= n; v++)
            parent[v][k] = parent[parent[v][k-1]][k-1];
}

int lca(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];
    for(int k = 0; k < LOG; k++)
        if((diff >> k) & 1)
            u = parent[u][k];

    if(u == v) return u;

    for(int k = LOG-1; k >= 0; k--)
        if(parent[u][k] != parent[v][k]){
            u = parent[u][k];
            v = parent[v][k];
        }

    return parent[u][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, 0);
    buildLCA(n);

    while(q--){
        int a, b;
        cin >> a >> b;
        int l = lca(a, b);
        cout << depth[a] + depth[b] - 2 * depth[l] << "\n";
    }

    return 0;
}
