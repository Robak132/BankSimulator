#ifndef NODE_H
#define NODE_H

#include <string>
#include "Error.h"

using namespace std;

template <typename K, typename V>
class Node {
private:
    K key;
    V value;
    Node<K,V>* next_n;
public:
    Node<K, V>(K _key, V _value) {
        key = _key;
        value = _value;
        next_n = nullptr;
    }

    K GetKey() const {
        return key;
    }
    void SetValue(K _key) {
        key = _key;
    }
    
    V GetValue() const {
        return value;
    }
    void SetValue(V _value) {
        value = _value;
    }

    Node<K, V>* GetNext() {
        return next_n;
    }
    void SetNext(Node* _next) {
        next_n = _next;
    }
};

template <typename K, typename V>
ostream& operator << (ostream& out, const Node<K, V> n) {
    return out << n.GetKey() << "\t" << n.GetValue();
}

template <typename K, typename V>
bool operator == (const Node<K, V>& a, const Node<K, V>& b) {
    return a.GetKey() == b.GetKey() && a.GetValue() == b.GetValue();
}

template <typename K, typename V>
bool operator != (const Node<K, V>& a, const Node<K, V>& b) {
    return !(a == b);
}

#endif