/**
 * Author: AshishGup
 * Description: Given N updates and Q queries. You know that for a particular
 * query: f(query, i) becomes true (and remains true) after the ith update.
 * You want to find the first i such that f(query, i) is true.

 * So for a single query we can binary search on i on the answer and perform
 * updates from 1 to i. The time for this per query is O(logN * cost of N
 updates). This will TLE since we need to do it for Q queries.
 * In parallel binary search can perform binary search for all queries
 parellely.

 * Time: $O(\log N * [T(clear) + Q * T(check) + N *(T(check) + T(apply))]$
 * Usage: Only change the solve(), clear(), apply() and check() functions.
 * Dont change work() or parallel_binary()
 */

#pragma once

const int MAXQ = 1 + 1e5;
const int MAXN = 1 + 1e5;

int lo[MAXQ], mid[MAXQ], hi[MAXQ], ans[MAXQ];
// lo[i] will contain the answer to the ith query.
// if lo[i] = N then answer is impossible

DSUF dsu(MAXN);
vector<int> vec[MAXN];
vector<vi> queries;
vector<vi> edges;

int start = 0;
int N, M, Q;

void clear() { // reset data structures
  dsu = DSUF(N);
}

void apply(int idx) { // Apply ith update
  dsu.merge(edges[idx][1], edges[idx][2]);
}

bool check(int q_idx) { // Check if the condition is satisfied for the q_idx-th
                        // query witht he data structure
  vi query = queries[q_idx];

  if (!dsu.is_connected(query[0], query[1]))
    return false;

  int k = dsu.get_key(query[0]);
  return query[2] <= dsu.uniq[k].size();
}

void work() {
  for (int i = 0; i < M; i++)
    vec[i].clear();
  for (int i = 0; i < Q; i++) {
    if (lo[i] <= hi[i])
      vec[mid[i]].pb(i);
  }

  clear();
  for (int i = 0; i < M; i++) {
    apply(i);
    for (int ind : vec[i]) { // Add appropriate check conditions
      // i = (lo[ind] + hi[ind])/2
      if (check(ind)) {
        hi[ind] = i - 1;
        ans[ind] = edges[i][0];
      } else
        lo[ind] = i + 1;
    }
  }
}

void parallel_binary() {
  for (int i = 0; i < Q; i++) {
    lo[i] = 0;
    hi[i] = M - 1;
  }

  bool changed = true;
  while (changed) {
    changed = false;

    for (int i = 0; i < Q; i++) {
      if (lo[i] <= hi[i]) {
        changed = true;
        mid[i] = (lo[i] + hi[i]) / 2;
      }
    }
    work();
  }
}

void solve() {
  // code starts from here
  cin >> N >> M >> Q;

  input(type, N);

  for (int w, u, v, i = 0; i < M; i++) {
    cin >> u >> v >> w;
    u--;
    v--;
    edges.pb({w, u, v});
  }
  sort(all(edges));

  for (int x, y, k, i = 0; i < Q; i++) {
    cin >> x >> y >> k;
    x--;
    y--;
    ans[i] = -1;
    queries.pb({x, y, k});
  }

  parallel_binary();
  for (int i = 0; i < Q; i++)
    cout << ans[i] << endl;
}