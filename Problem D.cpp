#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
private:
    vector<int> heap;
    int sz;

    void sift_up(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (heap[i] < heap[p]) {
                swap(heap[i], heap[p]);
                i = p;
            } else {
                break;
            }
        }
    }

    void sift_down(int i) {
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            if (left < sz && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < sz && heap[right] < heap[smallest]) {
                smallest = right;
            }
            if (smallest == i) {
                break;
            }
            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

public:
    PriorityQueue() : sz(0) {
        heap.reserve(2000010);
    }

    void push(int val) {
        if (sz == heap.size()) {
            heap.push_back(val);
        } else {
            heap[sz] = val;
        }
        sz++;
        sift_up(sz - 1);
    }

    void pop() {
        if (sz == 0) {
            return;
        }
        sz--;
        if (sz > 0) {
            heap[0] = heap[sz];
            sift_down(0);
        }
    }

    int min() const {
        if (sz == 0) {
            return -1;
        }
        return heap[0];
    }

    bool empty() const {
        return sz == 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    PriorityQueue pq;
    vector<int> answers;
    answers.reserve(q);

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int v;
            cin >> v;
            pq.push(v);
        } else {
            pq.pop();
        }
        answers.push_back(pq.min());
    }

    for (int i = 0; i < q; ++i) {
        if (i > 0) cout << " ";
        cout << answers[i];
    }
    cout << "\n";

    return 0;
}