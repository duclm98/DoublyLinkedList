#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
};

struct List
{
    Node* head;
    Node* tail;
};

Node* CreateNode(int val) {
    Node* node = new Node;
    if (node == NULL)
        return NULL;

    node->val = val;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void InitList(List& l) {
    l.head = NULL;
    l.tail = NULL;
}

bool IsEmpty(List l) {
    if (l.head == NULL)
        return true;
    return false;
}

void AddNode(List& l, int val) {
    Node* node = CreateNode(val);
    if (IsEmpty(l)) {
        l.head = node;
        l.tail = node;
    }
    else {
        node->prev = l.tail;
        l.tail->next = node;
        l.tail = node;
    }
}

void PrintList(List l) {
    for (Node* node = l.head; node != NULL; node = node->next) {
        cout << node->val << "\t";
    }
    cout << endl;
}

int main()
{
    List l;
    InitList(l);
    int val;
    bool flag = true;
    while (flag)
    {
        cout << "Nhap vao node: ";
        cin >> val;
        if (val != 0) {
            AddNode(l, val);
        }
        else {
            flag = false;
        }
    }
    PrintList(l);
    return 0;
}