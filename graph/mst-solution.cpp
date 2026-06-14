#define LCHILD(r) (1 + ((r) << 1))
#define RCHILD(r) ((1 + (r)) << 1)
#define PARENT(r) (((r) - 1) >> 1)

#define LT(a, b) ((a) >= 0 && ((a) < (b) || (b) < 0))

void HeapifyUp(vector<pair<int, int>> &heap, vector<int> &pos, int r) {
  while (r) {
    int p = PARENT(r);

    if (heap[r].second == heap[p].second ||
        LT(heap[p].second, heap[r].second)) {
      break;
    }

    swap(heap[r], heap[p]);
    pos[heap[r].first] = r;
    pos[heap[p].first] = p;

    r = p;
  }
}

void HeapifyUnder(vector<pair<int, int>> &heap, vector<int> &pos,
                  int heap_size) {
  int r = 0;

  while (r < heap_size) {
    int mi = heap[r].second;
    int min_ind = r;

    int L = LCHILD(r);
    if (L < heap_size && LT(heap[L].second, mi)) {
      mi = heap[L].second;
      min_ind = L;
    }

    int R = RCHILD(r);
    if (R < heap_size && LT(heap[R].second, mi)) {
      mi = heap[R].second;
      min_ind = R;
    }

    if (r == min_ind) {
      break;
    }
    swap(heap[r], heap[min_ind]);

    pos[heap[r].first] = r;
    pos[heap[min_ind].first] = min_ind;

    r = min_ind;
  }
}

class Solution {
public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    int n = points.size();

    vector<int> pos(n, 0);

    vector<pair<int, int>> heap(n, {0, 0});
    for (int i = 0; i < n; i++) {
      heap[i] = {i, -1};
      pos[i] = i;
    }

    heap[0] = {0, 0};
    int heap_size = n;

    int ans = 0;
    while (heap_size) {
      int cur = heap[0].first;
      ans += heap[0].second;

      pos[cur] = -1;
      heap[0] = heap[--heap_size];
      pos[heap[0].first] = 0;

      HeapifyUnder(heap, pos, heap_size);

      for (int nex = 0; nex < n; nex++) {
        if (pos[nex] < 0 || nex == cur) {
          continue;
        }

        int nu_p = abs(points[nex][0] - points[cur][0]) +
                   abs(points[nex][1] - points[cur][1]);
        int nu_pos = pos[nex];

        if (LT(nu_p, heap[nu_pos].second)) {
          heap[nu_pos].second = nu_p;

          HeapifyUp(heap, pos, nu_pos);
        }
      }
    }

    return ans;
  }
};
