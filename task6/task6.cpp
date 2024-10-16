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


void deleteElements(Chain*& lst, int value) {
    Chain* head = lst;
    Chain* prev = NULL;
    bool flag = true;
    while (lst != NULL && flag) {
        prev = lst;
        if (lst->data == 0) {
            flag = false;
        } if (flag && lst->next->data == value) {
            lst->next = lst->next->next;
        }
        else {
            lst = lst->next;
        }
        
    } lst = head;
}

int main() {
    int z = 4;
    Chain* lst = createListFromFile("input.txt");
    deleteElements(lst, z);
    print(lst);
    
}


