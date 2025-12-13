#include <iostream>
#include <vector>

using namespace std;

class LinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node* prev;
        explicit Node(int v) : val(v), next(nullptr), prev(nullptr) { }
    };

    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_back(int val) {
        Node* node = new Node(val);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        size++;
    }

    void push_front(int val) {
        Node* node = new Node(val);
        if (!head) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        size++;
    }

    int pop_back() {
        if (size == 0) return -1;
        int val = tail->val;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        size--;
        return val;
    }

    int pop_front() {
        if (size == 0) return -1;
        int val = head->val;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        size--;
        return val;
    }

    void insert(int p, int val) {
        if (p == 1) { push_front(val); return; }
        if (p > size + 1) return;

        Node* cur = head;
        for (int i = 1; i < p - 1; ++i) cur = cur->next;

        Node* node = new Node(val);
        node->next = cur->next;
        node->prev = cur;
        if (cur->next) cur->next->prev = node;
        cur->next = node;
        if (p == size + 1) tail = node;
        size++;
    }

    int remove(int p) {
        if (p < 1 || p > size) return -1;

        Node* cur = head;
        for (int i = 1; i < p; ++i) cur = cur->next;

        int val = cur->val;
        if (cur->prev) cur->prev->next = cur->next;
        else head = cur->next;
        if (cur->next) cur->next->prev = cur->prev;
        else tail = cur->prev;
        delete cur;
        size--;
        return val;
    }

    [[nodiscard]] int get(int p) const {
        if (p < 1 || p > size) return -1;
        Node* cur = head;
        for (int i = 1; i < p; ++i) cur = cur->next;
        return cur->val;
    }

    [[nodiscard]] int find_min_position(int v) const {
        Node* cur = head;
        int pos = 1;
        int min_pos = -1;
        while (cur) {
            if (cur->val == v && (min_pos == -1 || pos < min_pos)) min_pos = pos;
            cur = cur->next;
            pos++;
        }
        return min_pos;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    LinkedList list;
    vector<long long> answers;

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            char dir; int v;
            cin >> dir >> v;
            if (dir == 'f') list.push_front(v);
            else list.push_back(v);
        } else if (type == 2) {
            char dir;
            cin >> dir;
            int val = (dir == 'f' ? list.pop_front() : list.pop_back());
            answers.push_back(val);
        } else if (type == 3) {
            int p, v;
            cin >> p >> v;
            list.insert(p, v);
        } else if (type == 4) {
            int p;
            cin >> p;
            answers.push_back(list.remove(p));
        } else if (type == 5) {
            int v;
            cin >> v;
            answers.push_back(list.find_min_position(v));
        } else if (type == 6) {
            int p;
            cin >> p;
            answers.push_back(list.get(p));
        }
    }

    for (size_t i = 0; i < answers.size(); ++i) {
        if (i) cout << " ";
        cout << answers[i];
    }
    cout << "\n";

    return 0;
}
