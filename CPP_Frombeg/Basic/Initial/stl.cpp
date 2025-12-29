#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm> // for sort, reverse
using namespace std;

int main() {
    // 1?? Vector
    vector<int> v = {3, 1, 4};
    v.push_back(2);
    cout << "Vector elements: ";
    for(int x : v) cout << x << " ";
    cout << endl;
    sort(v.begin(), v.end()); // sort vector
    cout << "Sorted vector: ";
    for(int x : v) cout << x << " ";
    cout << endl;

    // 2?? List
    list<int> l = {10, 20, 30};
    l.push_front(5); // insert at beginning
    cout << "List elements: ";
    for(int x : l) cout << x << " ";
    cout << endl;

    // 3?? Deque
    deque<int> d = {1,2,3};
    d.push_front(0);
    d.push_back(4);
    cout << "Deque elements: ";
    for(int x : d) cout << x << " ";
    cout << endl;

    // 4?? Set
    set<int> s = {5, 3, 1, 3};
    s.insert(4);
    cout << "Set elements (sorted & unique): ";
    for(int x : s) cout << x << " ";
    cout << endl;

    // 5?? Map
    map<string,int> m;
    m["Alice"] = 25;
    m["Bob"] = 30;
    cout << "Map elements: ";
    for(auto &p : m) cout << p.first << "-" << p.second << " ";
    cout << endl;

    // 6?? Unordered Map
    unordered_map<string,int> um;
    um["apple"]=10; um["banana"]=5;
    cout << "Unordered map: ";
    for(auto &p : um) cout << p.first << "-" << p.second << " ";
    cout << endl;

    // 7?? Stack
    stack<int> st;
    st.push(1); st.push(2); st.push(3);
    cout << "Stack top: " << st.top() << endl;
    st.pop();
    cout << "Stack top after pop: " << st.top() << endl;

    // 8?? Queue
    queue<int> q;
    q.push(1); q.push(2); q.push(3);
    cout << "Queue front: " << q.front() << endl;
    q.pop();
    cout << "Queue front after pop: " << q.front() << endl;

    // 9?? Priority Queue
    priority_queue<int> pq;
    pq.push(10); pq.push(5); pq.push(20);
    cout << "Priority queue top (max element): " << pq.top() << endl;

    return 0;
}


