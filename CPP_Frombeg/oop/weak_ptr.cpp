#include <iostream>
#include <memory>
using namespace std;

struct Node {
    shared_ptr<Node> next;
    weak_ptr<Node> prev; // weak_ptr to break circular reference
    Node(int val) { cout << "Node " << val << " created\n"; }
    ~Node() { cout << "Node destroyed\n"; }
};

int main() {
    auto node1 = make_shared<Node>(1);
    auto node2 = make_shared<Node>(2);

    node1->next = node2;
    node2->prev = node1; // weak_ptr avoids circular ref

    return 0;
}

