#ifndef DICT_H
#define DICT_H
#include "Node.h"
#include "Error.h"
#include <vector>

using namespace std;

template <typename K, typename V>
class Dict {
private:
    int len;
    Node<K, V>* first;
public:
    Dict<K, V>(K _key, V _value) {
        len = 1;
        first = new Node<K, V>(_key, _value);
    }
    Dict<K, V>() {
        len = 0;
        first = nullptr;
    }
    ~Dict<K, V>() {
        Node<K, V>* head = first;
        Node<K, V>* temp = nullptr;
        while (head != nullptr) {
            temp = head->GetNext();
            delete head;
            head = temp;
        }
}

    int GetSize() const {
        // Zwraca d³ugoœæ s³ownika
        return len;
    }
    Node<K, V>* GetFirst() const {
        // Zwraca wskaŸnik na pierwszy wêze³ s³ownika
        return first;
    }

    void Add(K _key, V _value) {
        // Dodaje wêze³ (klucz i wartoœæ) do s³ownika
        if (first == nullptr) {
            first = new Node<K, V>(_key, _value);
        }
        else {
            Node<K, V>* head = first;
            Node<K, V>* last_head = nullptr;
            while (head != nullptr) {
                if (_key == head->GetKey())
                    throw DuplicatedKey("Duplicated key");
                last_head = head;
                head = head->GetNext();
            }
            head = new Node<K, V>(_key, _value);
            last_head->SetNext(head);
        }
        len++;
    }
    void AddTable(vector<K> _keys, vector<V> _values) {
        if (_keys.size() != _values.size())
            throw invalid_argument("vectors' size different");
        for (int i = 0; i < _keys.size(); i++)
            Add(_keys[i], _values[i]);
    }
    void Delete(K _key, V _value) {
        // Usuwa wêze³ (klucz i wartoœæ) z s³ownika
        Node<K, V>* head = first;
        Node<K, V>* last_head = nullptr;
        while (head != nullptr) {
            if (head->GetKey() == _key && head->GetValue() == _value) {
                if (last_head == nullptr)
                    first = head->GetNext();
                else
                    last_head->SetNext(head->GetNext());
                delete head;
                break;
            }
            last_head = head;
            head = head->GetNext();
        }
        len--;
    }
    void ChangeValue(K _key, V _new_value) {
        // Zmienia wartoœæ okreœlonego wêz³a
        Node<K, V>* head = first;
        while (head != nullptr) {
            if (head->GetKey() == _key) {
                head->SetValue(_new_value);
                break;
            }
            head = head->GetNext();
        }
    }
    
    void Show() {
        // Wyœwietla s³ownik
        Node<K, V>* head = first;
        while (head != nullptr) {
            cout << *head << endl;
            head = head->GetNext();
        }
    }
    V FindValue(K _key) const {
        // Wyszukuje wartoœæ odkreœlonego klucza
        Node<K, V>* head = first;
        while (head != nullptr) {
            if (head->GetKey() == _key)
                return head->GetValue();
            head = head->GetNext();
        }
        throw ValueNotFound("Value not found");
    }
    Node<K, V>* FindNode(Node<K, V> node) {
        // Zwraca wskaŸnik na okreœlony wêze³
        Node<K, V>* head = first;
        while (head != nullptr) {
            if (*head == node)
                return head;
            head = head->GetNext();
        }
        throw ValueNotFound("Node not found");
    }
    
    bool isNode(Node<K, V> node) const {
        // Sprawdza czy w s³owniku znajduje siê wêze³
        Node<K, V>* head = first;
        while (head != nullptr) {
            if (node == *head)
                return 1;
            head = head->GetNext();
        }
        return 0;
    }
    bool isNode(K _key, V _value) const {
        // Sprawdza czy w s³owniku znajduje siê wêze³
        Node<K, V>* head = first;
        while (head != nullptr) {
            if (head->GetKey() == _key && head->GetValue() == _value)
                return 1;
            head = head->GetNext();
        }
        return 0;
    }
};

template <typename K, typename V>
bool operator == (const Dict<K, V> &a, const Dict<K, V> &b) {
    if (a.GetSize() != b.GetSize())
        return 0;

    Node<K, V>*head = a.GetFirst();
    while (head != nullptr) {
        if (!b.isNode(*head))
            return 0;
        head = head->GetNext();
    }
    return 1;
}

template <typename K, typename V>
bool operator != (const Dict<K, V>& a, const Dict<K, V>& b) {
    return !(a == b);
}
#endif