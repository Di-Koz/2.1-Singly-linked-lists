#include <iostream>
#include <string>

using namespace std;

struct node {
    string name;
    node* nextNode;
};

#ifndef FUNC_H
#define FUNC_H
void printList(node* first);
void printList2(node* first);
void defineTypeList(node* first);

node* push_front(node* first, string value);
//void push_front(node* first, string value);
node* push_back(node* first, string value);
void delete_list(node* first);
node* pop_front(node* first);
void pop_back(node* first);
void delete_elem(node* first, string param);
void insert_elem(node* first, string value, string param, int mode);
node* insert_arr(string* arr, int size);
#endif