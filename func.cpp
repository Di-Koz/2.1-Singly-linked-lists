#include <iostream>
#include <string>
#include "func.h"
using namespace std;

void printList(node* first) {
    for (first; first != nullptr; first = first->nextNode) {
        cout << first->name << " ";
    }
}

void printList2(node* first) {
    if (first == nullptr) {
        return;
    }
    cout << first->name << " ";
    printList2(first->nextNode);
}

void defineTypeList(node* first) {
    node* copyFirst = first;
    while ((first->nextNode != nullptr) && (first->nextNode != copyFirst)) {
        first = first->nextNode;
    }

    if (first->nextNode == nullptr) {
        cout << "acyclic";
    }
    if (first->nextNode == copyFirst) {
        cout << "cyclick";
    }
}

node* push_front(node* first, string value) {
    node* elem = new node;
    elem->name = value;

    elem->nextNode = first;
    return elem;
}

//void push_front(node* first, string value) {
//    node* elem = new node;
//    elem->name = value;
//
//    elem->nextNode = first;
//    first = elem;
//}

node* push_back(node* first, string value) {
    node* elem = new node;
    elem->name = value;

    if (first == nullptr) {
        first = elem;
        first->nextNode = nullptr;

        return first;
    }
    else {
        node* copyFirst = first;

        while (first->nextNode != nullptr) {
            first = first->nextNode;
        }

        first->nextNode = elem;
        elem->nextNode = nullptr;

        return copyFirst;
    }
}

void delete_list(node* first) {
    node* temp = first;

    while (first != nullptr) {
        temp = first;
        first = first->nextNode;
        delete temp;
        temp = nullptr;
    }

    delete first;
    first = nullptr;
}

node* pop_front(node* first) {
    if (first == nullptr) {
        return 0;
    }
    else {
        node* newFirst = first->nextNode;

        first = nullptr;
        delete first;

        return newFirst;
    }
}

void pop_back(node* first) {
    if (first == nullptr) {
        return;
    }
    else {
        while (first->nextNode->nextNode != nullptr) {
            first = first->nextNode;
        }

        first->nextNode = nullptr;
        delete first->nextNode;
    }
}

void delete_elem(node* first, string param) {
    if (first == nullptr) {
        return;
    }
    else {
        if (first->name == param) {
            *first = *pop_front(first);
        }
        else {
            while ((first->nextNode != nullptr) && (first->nextNode->name != param)) {
                first = first->nextNode;
            }

            if (first->nextNode == nullptr) {
                return;
            }

            node* deleteElem = first->nextNode;
            first->nextNode = deleteElem->nextNode;

            deleteElem = nullptr;
            delete deleteElem;
        }
    }
}

void insert_elem(node* first, string value, string param, int mode) {
    if (first == nullptr) {
        return;
    }
    else {
        node* elem = new node;
        elem->name = value;

        if (mode == 1) {
            node* copyFirst = first;

            while ((first->nextNode != nullptr) && (first->name != param)) {
                first = first->nextNode;
            }

            if ((first->name == param) && (first->nextNode == nullptr)) {
                first = push_back(copyFirst, value);
            }
            else {
                if (first->nextNode == nullptr) {
                    return;
                }

                elem->nextNode = first->nextNode;
                first->nextNode = elem;
            }
        }
        else if (mode == 0) {
            if (first->name == param) {
                first = push_front(first, value);
            }
            else {
                while ((first->nextNode != nullptr) && (first->nextNode->name != param)) {
                    first = first->nextNode;
                }

                if (first->nextNode == nullptr) {
                    return;
                }

                elem->nextNode = first->nextNode;
                first->nextNode = elem;
            }
        }
    }
}

node* insert_arr(string* arr, int size) {
    if ((arr->size() == 0) || (size == 0)) {
        return 0;
    }
    else {
        node* first = new node;
        node* copyFirst = first;

        for (int i = 0; i < size; ++i) {
            first->name = arr[i];

            if (i != size - 1) {
                node* nextElem = new node;
                first->nextNode = nextElem;
                first = nextElem;
            }
            else {
                first->nextNode = nullptr;
            }
        }
        return copyFirst;
    }
}


