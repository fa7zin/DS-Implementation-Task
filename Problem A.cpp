#include <iostream>
#include <vector>

using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

    void resize() {
        capacity = max(2, capacity * 2);
        int* new_arr = new int[capacity];
        for (int i = 0; i < size; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
    }

public:
    DynamicArray() {
        capacity = 2;
        size = 0;
        arr = new int[capacity];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void push_back(int val) {
        if (size == capacity) resize();
        arr[size++] = val;
    }

    int pop_back() {
        if (size == 0) return -1;
        return arr[--size];
    }

    void insert(int pos, int val) {
        if (size == capacity) resize();
        for (int i = size; i >= pos; i--) {
            arr[i] = arr[i-1];
        }
        arr[pos-1] = val;
        size++;
    }

    int remove(int pos) {
        if (pos < 1 || pos > size) return -1;
        int val = arr[pos-1];
        for (int i = pos-1; i < size-1; i++) {
            arr[i] = arr[i+1];
        }
        size--;
        return val;
    }

    [[nodiscard]] int get(int pos) const {
        if (pos < 1 || pos > size) return -1;
        return arr[pos-1];
    }

    [[nodiscard]] int getSize() const {
        return size;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    DynamicArray da;
    vector<long long> answers;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int v;
            cin >> v;
            da.push_back(v);
        } else if (type == 2) {
            answers.push_back(da.pop_back());
        } else if (type == 3) {
            int p, v;
            cin >> p >> v;
            da.insert(p, v);
        } else if (type == 4) {
            int p;
            cin >> p;
            answers.push_back(da.remove(p));
        } else if (type == 5) {
            int v;
            cin >> v;
            int min_pos = -1;
            for (int pos = 1; pos <= da.getSize(); pos++) {
                if (da.get(pos) == v) {
                    min_pos = pos;
                    break;
                }
            }
            answers.push_back(min_pos);
        } else if (type == 6) {
            int p;
            cin >> p;
            answers.push_back(da.get(p));
        }
    }

    for (size_t i = 0; i < answers.size(); i++) {
        if (i > 0) cout << " ";
        cout << answers[i];
    }

    cout << "\n";

    return 0;
}
