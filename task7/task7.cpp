#include <iostream>
#include <fstream>

using namespace std;

struct Chain {
    int data;
    Chain* next = NULL;
};


void print(const Chain* p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

void addElementBegin(Chain*& head, const int value) {
    Chain* newNode = new Chain();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

Chain* createListFromFile(string namefile) {
    ifstream file(namefile);
    int num;

    Chain* head = NULL;
    Chain* current = NULL;
    while (file >> num) {
        Chain* newNode = new Chain();
        newNode->data = num;
        if (head == NULL) head = newNode;
        else current->next = newNode;
        current = newNode;
    } file.close();
    return head;
}


void insertion(Chain*& lst, int x, int z) {
    Chain* head = lst;
    if (lst->data == z) {
        addElementBegin(lst, x);
        head = lst;
        lst = lst->next;
    }
    while (lst->next != NULL) {
        Chain* newNode = new Chain();
        if (lst->next->data == z) {
            newNode->data = x;
            newNode->next = lst->next;
            lst->next = newNode;
            lst = newNode->next;
        }
        else lst = lst->next;
    } lst = head;
}

int main() {
    int z = 4;
    int x = 4;
    Chain* lst = createListFromFile("input.txt");
    insertion(lst, -1, 6);
    print(lst);

}


