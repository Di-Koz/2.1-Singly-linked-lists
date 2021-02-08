#include <iostream>
#include <string>
using namespace std;

struct node {
    string name;
    node *nextNode;
};

void printList(node *first) {
    for (first; first != nullptr; first = first -> nextNode) {
        cout << first -> name << " ";
    }
}

void printList2(node *first) {
    if (first == nullptr) {
        return;
    }
    cout << first -> name << " ";
    printList2(first -> nextNode);
}

void defineTypeList(node* first) {
    node* copyFirst = first;
    while ((first -> nextNode != nullptr) && (first -> nextNode != copyFirst)) {
        first = first -> nextNode;
    }

    if (first -> nextNode == nullptr) {
        cout << "acyclic";
    }
    if (first->nextNode == copyFirst) {
        cout << "cyclick";
    }
}

void push_front(node *first, node *elem) {
    elem -> nextNode = first;
}

void push_back(node *first, node *elem) {
    while (first -> nextNode != nullptr) {
        first = first -> nextNode;
    }
    
    first -> nextNode = elem;
    elem -> nextNode = nullptr;
}

void delete_list(node *first) {
    while (first != nullptr) {
        delete first;
        first = first -> nextNode;
    }
}

void pop_front(node *first) {
    delete first;
}

void pop_back(node *first) {
    while (first -> nextNode -> nextNode != nullptr) {
        first = first -> nextNode;
    }

    delete first -> nextNode;
    first -> nextNode = nullptr;
}

void delete_elem(node *first, string param) {
    while (first -> nextNode -> name != param) {
        first = first -> nextNode;
    }
    
    node *deleteElem = first -> nextNode;
    first -> nextNode = deleteElem -> nextNode;
    delete deleteElem;
}

void insert_elem(node *first, node *elem, string param, int mode) {
    if (mode == 1) {
        while (first -> name != param) {
            first = first -> nextNode;
        }
    } else if (mode == 0) {
        while (first -> nextNode -> name != param) {
            first = first -> nextNode;
        }
    }
    
    elem -> nextNode = first -> nextNode;
    first -> nextNode = elem;
}

void insert_arr(node *first, string *arr, int size) {
    for (int i = 0; i < size; ++i) {
        first -> name = arr[i];
    
        if (i != size - 1) {
            node* nextElem = new node;
            first -> nextNode = nextElem;
            first = nextElem;
        }
        else {
            first -> nextNode = nullptr;
        }
    }
}

int main() {
    //начальный список
    node *cur = new node;
    cur -> name = "Novosibirsk";
    node *cur2 = new node;
    cur2 -> name = "Munchen";
    cur -> nextNode = cur2;
    node *cur3 = new node;
    cur3 -> name = "Orenburg";
    cur2 -> nextNode = cur3;
    node *cur4 = new node;
    cur4 -> name = "Paris";
    cur3 -> nextNode = cur4;
    cur4 -> nextNode = nullptr;
    printList(cur);
    cout << endl;
    printList2(cur);
    cout << endl;
    defineTypeList(cur);
    cout << endl;
    //1
    //node *newElem = new node;
    //newElem -> name = "Tomsk";
    //push_front(cur, newElem);
    //printList(newElem);
    //2
    //node *newElem = new node;
    //newElem -> name = "Kostroma";
    //push_back(cur, newElem);
    //printList2(cur);
    //3
    //delete_list(cur);
    //printList(cur);
    //4
    //pop_front(cur);
    //printList(cur2);
    //5
    //pop_back(cur);
    //printList(cur);
    //6
    //delete_elem(cur, "Orenburg");
    //printList2(cur);
    //7
    //node *newElem = new node;
    //newElem -> name = "Moscow";
    //insert_elem(cur, newElem, "Munchen", 0);
    //insert_elem(cur, newElem, "Munchen", 1);
    //printList(cur);
    //8
    //const int N = 5;
    //string mas[N] = {"Ural", "Petersburg", "Omsk", "Volgograd", "Rostov"};
    //
    //node *first = new node;
    //insert_arr(first, mas, N);
    //printList(first);
    
    
    
    
}