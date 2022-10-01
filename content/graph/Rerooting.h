/**
 * Author: Chaithanya Shyam D
 * Description: We can use re-rooting technique when the dp value of a node only
 * depends on the dp value of its children and it can be calculated in
 * $O(\text{adj[node].size()})$ time per node
 * Usage: The below code solve the problem: For every node, find the sum of
 * distances to every other node. Dont change dfs2() function.
 * Time: $O(N)$
 */
#pragma once

vector<vi> adj;
int N;
vi ans, dp, sz;

void dfs(int src, int par) {
  for (int ne : adj[src]) {
    if (ne == par)
      continue;
    dfs(ne, src);

    sz[src] += 1 + sz[ne];
    dp[src] += 1 + sz[ne] + dp[ne];
  }
}

// reroot a -> b
void reroot(int a, int b) {
  dp[a] -= (1 + sz[b] + dp[b]);
  sz[a] -= (sz[b] + 1);

  dp[b] += 1 + sz[a] + dp[a];
  sz[b] += sz[a] + 1;
}

void dfs2(int src, int par) {
  ans[src] = dp[src];

  for (int ne : adj[src]) {
    if (ne == par)
      continue;

    reroot(src, ne); // re-root from src to ne
    dfs2(ne, src);
    reroot(ne, src); // re-root from ne to src
  }
}

void solve() {
  cin >> N;
  adj.resize(N);

  for (int u, v, i = 0; i < N - 1; i++) {
    cin >> u >> v;
    u--;
    v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  ans.assign(N, 0);
  dp.assign(N, 0);
  sz.assign(N, 0);

  dfs(0, 0);
  dfs2(0, 0);

  for (int i : ans)
    cout << i << " ";
  cout << endl;
}