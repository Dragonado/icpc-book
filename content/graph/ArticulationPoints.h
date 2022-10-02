/**
 * Author: AshishGup
 * Description: Algorithm to find cut vertices in a graph
 * Time: O(V + E)
 */
#pragma once

const int N = 1e5;
int n, timer;
int tin[N], low[N];
bool vis[N], isArticulation[N];
vector<int> g[N];
void dfs(int u, int par) {
  vis[u] = 1;
  int children = 0;
  tin[u] = low[u] = ++timer;
  for (auto &it : g[u]) {
    if (it == par)
      continue;
    if (vis[it])
      low[u] = min(low[u], tin[it]);
    else {
      dfs(it, u);
      children++;
      low[u] = min(low[u], low[it]);
      if (low[it] >= tin[u] && par != -1)
        isArticulation[u] = 1;
    }
  }
  if (par == -1 && children > 1)
    isArticulation[u] = 1;
}
void articulationPoints() {
  memset(tin, -1, sizeof(tin));
  memset(low, -1, sizeof(low));
  for (int i = 1; i <= n; i++) {
    if (!vis[i])
      dfs(i, -1);
  }
}