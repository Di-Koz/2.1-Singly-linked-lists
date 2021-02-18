#include <iostream>
#include <string>
#include "func.h"
using namespace std;

int main() {
    //начальный список
    node *cur = new node;
    cur = nullptr;
    for (int i = 0; i < 5; ++i) {
       cur = push_back(cur, "num" + to_string(i + 1));
    }
    printList(cur);
    cout << endl;

    //cur = push_front(cur, "num0");
    //push_front(cur, "num0");
    //cur = push_back(cur, "num0");
    //delete_list(cur);
    //cur = pop_front(cur);
    //pop_back(cur);
    //delete_elem(cur, "num1");
    //insert_elem(cur, "num0", "num1", 0);
    //insert_elem(cur, "num0", "num3", 1);
    string mas[5] = {"num56", "num3", "num78", "num12", "num13"};
    cur = insert_arr(mas, 5);
    printList2(cur); 
}


