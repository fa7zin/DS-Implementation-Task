#include <iostream>
#include <vector>

using namespace std;

class HashTable {
private:
    struct Node {
        int key;
        int value;
        Node* next;
        Node(int k, int v) : key(k), value(v), next(nullptr) {}
    };

    vector<Node*> table;
    int size;
    int capacity;

    unsigned int hash(int key) const {
        unsigned int h = (unsigned int)key;
        h ^= h >> 16;
        h *= 0x85ebca6b;
        h ^= h >> 13;
        h *= 0xc2b2ae35;
        h ^= h >> 16;
        return h;
    }

    void resize() {
        int old_capacity = capacity;
        vector<Node*> old_table = table;

        capacity *= 2;
        table.assign(capacity, nullptr);
        size = 0;

        for (int i = 0; i < old_capacity; ++i) {
            Node* cur = old_table[i];
            while (cur) {
                Node* next = cur->next;
                unsigned int idx = hash(cur->key) % capacity;
                cur->next = table[idx];
                table[idx] = cur;
                cur = next;
                size++;
            }
        }
    }

public:
    HashTable() : size(0), capacity(16384) {
        table.assign(capacity, nullptr);
    }

    ~HashTable() {
        for (int i = 0; i < capacity; ++i) {
            Node* cur = table[i];
            while (cur) {
                Node* temp = cur;
                cur = cur->next;
                delete temp;
            }
        }
    }

    int put(int key, int value) {
        if (size >= capacity) {
            resize();
        }

        unsigned int idx = hash(key) % capacity;

        Node* cur = table[idx];
        while (cur) {
            if (cur->key == key) {
                int old = cur->value;
                cur->value = value;
                return old;
            }
            cur = cur->next;
        }

        Node* node = new Node(key, value);
        node->next = table[idx];
        table[idx] = node;
        size++;
        return -1;
    }

    int remove(int key) {
        unsigned int idx = hash(key) % capacity;

        Node* cur = table[idx];
        Node* prev = nullptr;

        while (cur) {
            if (cur->key == key) {
                int val = cur->value;
                if (prev) prev->next = cur->next;
                else table[idx] = cur->next;
                delete cur;
                size--;
                return val;
            }
            prev = cur;
            cur = cur->next;
        }
        return -1;
    }

    int get(int key) const {
        unsigned int idx = hash(key) % capacity;

        Node* cur = table[idx];
        while (cur) {
            if (cur->key == key) return cur->value;
            cur = cur->next;
        }
        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    HashTable dict;
    vector<long long> answers;

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int k, v;
            cin >> k >> v;
            answers.push_back(dict.put(k, v));
        }
        else if (type == 2) {
            int k;
            cin >> k;
            answers.push_back(dict.remove(k));
        }
        else if (type == 3) {
            int k;
            cin >> k;
            answers.push_back(dict.get(k));
        }
    }

    for (size_t i = 0; i < answers.size(); ++i) {
        if (i > 0) cout << " ";
        cout << answers[i];
    }
    cout << "\n";

    return 0;
}