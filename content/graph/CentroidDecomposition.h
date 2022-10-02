/**
 * Author: Chaithanya Shyam D
 * Description: The answer is some function on the paths on the tree. We
 * calculate this value for all paths passing through the centroid in $O(N)$ or
 * $O(\log N)$ time. We then remove the centroid and then recurse on the
 * remaning subtrees. This is Divide and Conquer on trees.
 *
 * Only change getAnswer() and dfs2() function
 *
 * Time: The recurrence is T(N) = O(K) + 2*T(N/2)
 * Where O(K) is the time complexity in calculating the answer for all paths
 * going through the centroid. It is usually $O(N)$ or $O(N \log N)$, where N =
 * number of nodes in the subtree
 */
#pragma once

class tree_dc { // tree divide and conquer
private:
  vector<vi> adj;
  vector<bool> rem;
  vi subtree_cnt;
  int N;

  void dfs(int root, int par = 0) {
    assert(rem[root] == false);
    subtree_cnt[root] = 1;

    for (int ne : adj[root]) {
      if (ne == par || rem[ne])
        continue;
      dfs(ne, root);

      subtree_cnt[root] += subtree_cnt[ne];
    }
  }

  void reRoot(int old_root, int new_root) {
    int t1 = subtree_cnt[old_root];
    int t2 = subtree_cnt[new_root];

    subtree_cnt[old_root] -= t2;
    subtree_cnt[new_root] += (t1 - t2);
  }

  int getCentroid(int root) {
    assert(rem[root] == false); // its not removed

    int centroid = root;

    for (int ne : adj[root]) {
      if (rem[ne])
        continue;
      if (subtree_cnt[ne] <= subtree_cnt[root] / 2)
        continue;

      reRoot(root, ne);
      centroid = getCentroid(ne);
      break;
    }

    return centroid;
  }

  void removeCentroid(int centroid) { rem[centroid] = true; }

public:
  tree_dc(int N = 0) {
    this->N = N;

    adj.resize(N + 1);
    subtree_cnt.assign(N + 1, 0);
    rem.assign(N + 1, false);
  }

  void init(int N) {
    this->N = N;

    adj.resize(N + 1);
    subtree_cnt.assign(N + 1, 0);
    rem.assign(N + 1, false);
  }

  void add_edge(int u,
                int v) { // 1 based indexing, adding weight to edges can be done
    assert(u > 0 && v > 0 && u <= N && v <= N && u != v);
    adj[u].pb(v);
    adj[v].pb(u);
  }

  void build() {
    dfs(1); // 1-based indexing. initial root doesnt matter so it can be
            // anything
  }

  // modify below code for your problem
  void dfs2(int root, int par, int depth, vi &v) {
    assert(rem[root] == false);

    depth++;
    v.pb(depth);

    for (int ne : adj[root]) {
      if (rem[ne] || ne == par)
        continue;

      dfs2(ne, root, depth, v);
    }
  }

  // modify below code for your problem
  int getAnswer(int temp_root) {
    int centroid = getCentroid(temp_root); // O(N)
    int ans = 0;

    // merging step
    // capture all answers that involve the centroid in O(N) or O(NlogN) where N
    // = subtree_cnt[centroid] add your code here
    for (int ne : adj[centroid]) {
      if (rem[ne])
        continue;

      vi v;
      dfs2(ne, centroid, 0, v); // usually a 2nd dfs is done to capture answers
    }

    // Conquering step, done need to change below step
    removeCentroid(centroid);
    for (int ne : adj[centroid]) {
      if (rem[ne])
        continue;
      ans += getAnswer(ne);
      // if(ans >= MOD) ans -= MOD; if needed
    }

    return ans;
  }
};

void solve() {
  // code starts from here
  int N;
  cin >> N;

  tree_dc tree(N);
  for (int i = 1; i <= N - 1; i++) {
    int u, v;
    cin >> u >> v; // 1 based indexing
    tree.add_edge(u, v);
  }

  tree.build();

  // cout << tree.getAnswer(1) << endl;
}