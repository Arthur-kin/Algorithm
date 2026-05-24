#define LCHILD(r) (1 + ((r) << 1))
#define RCHILD(r) ((1 + (r)) << 1)
#define PARENT(r) (((r) - 1) >> 1)

void HeapifyUp(vector<pair<int, double>> &heap, vector<int> &pos, int r) {
  while (r) {
    int p = PARENT(r);

    if (heap[r].second <= heap[p].second) {
      break;
    }

    swap(heap[r], heap[p]);
    pos[heap[r].first] = r;
    pos[heap[p].first] = p;

    r = p;
  }
}

void HeapifyUnder(vector<pair<int, double>> &heap, vector<int> &pos,
                  int heap_size) {
  int r = 0;

  while (r < heap_size) {
    double ma = heap[r].second;
    int max_ind = r;

    int L = LCHILD(r);
    if (L < heap_size && heap[L].second > ma) {
      ma = heap[L].second;
      max_ind = L;
    }

    int R = RCHILD(r);
    if (R < heap_size && heap[R].second > ma) {
      ma = heap[R].second;
      max_ind = R;
    }

    if (r == max_ind) {
      break;
    }
    swap(heap[r], heap[max_ind]);

    pos[heap[r].first] = r;
    pos[heap[max_ind].first] = max_ind;

    r = max_ind;
  }
}

class Solution {
public:
  double maxProbability(int n, vector<vector<int>> &edges, vector<double> &prob,
                        int s, int t) {
    vector<vector<pair<int, double>>> adj(n, vector<pair<int, double>>());
    for (int i = 0; i < edges.size(); i++) {
      adj[edges[i][0]].push_back({edges[i][1], prob[i]});
      adj[edges[i][1]].push_back({edges[i][0], prob[i]});
    }

    vector<pair<int, double>> heap(n, {0, 0});
    vector<int> pos(n, 0);
    for (int i = 0; i < n; i++) {
      heap[i] = {i, 0};
      pos[i] = i;
    }

    heap[0] = {s, 1};
    pos[s] = 0;
    if (s) {
      heap[s] = {0, 0};
      pos[0] = s;
    }
    int heap_size = n;

    while (heap_size) {
      int cur = heap[0].first;
      double p = heap[0].second;

      if (cur == t || p == 0) {
        return p;
      }

      pos[cur] = -1;
      heap[0] = heap[--heap_size];
      pos[heap[0].first] = 0;

      HeapifyUnder(heap, pos, heap_size);

      for (auto nex : adj[cur]) {
        int nu_v = nex.first;
        double nu_p = p * nex.second;
        int nu_pos = pos[nu_v];

        if (nu_pos >= 0 && heap[nu_pos].second < nu_p) {
          heap[nu_pos].second = nu_p;

          HeapifyUp(heap, pos, nu_pos);
        }
      }
    }

    return 0;
  }
};
