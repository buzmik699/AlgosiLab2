#include <iostream>
#include <fstream>
using namespace std;

struct Chain {
    int data;
    Chain* next = NULL;
};


void print(const Chain* p) {
    while (p != NULL) {
        cout << p->data << endl;
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

void addElementEnd(Chain*& head, const int value) {
    Chain* newNode = new Chain();
    newNode->data = value;
    if (head == NULL) head = newNode;
    else {
        Chain* p = head;
        while (p->next != NULL) p = p->next;
        p->next = newNode;
    }
}


Chain* sumLists(const Chain* first, const Chain* second) {
    
    Chain* lst = NULL;
    while (first != NULL || second != NULL) {
        int value1 = 0;
        int value2 = 0;
        if (first != NULL) {
            value1 = first->data;
            first = first->next;
        } if (second != NULL) {
            value2 = second->data;
            second = second->next;
        }
        addElementEnd(lst, value1 + value2);
        
    } return lst;
}





int main() {
    Chain* a = createListFromFile("input1.txt");
    Chain* b = createListFromFile("input2.txt");
    Chain* c = sumLists(a, b);
    print(c);


}

