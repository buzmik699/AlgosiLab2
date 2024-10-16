#include <iostream>

using namespace std;

struct Chain {
    int data;
    Chain* next = nullptr;
};


void insertSorted(Chain*& head, int value) {
    Chain* newNode = new Chain();
    newNode->data = value;

    if (head == nullptr || head->data >= value) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Chain* current = head;
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

Chain* insertSortedRecursive(Chain* head, int value) {
    if (head == nullptr || head->data >= value) {
        Chain* newNode = new Chain();
        newNode->data = value;
        newNode->next = head;
        return newNode;
    }
    head->next = insertSortedRecursive(head->next, value);
    return head;
}


void printList(Chain* head) {
    Chain* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


int main() {
    Chain* head = NULL;
    int value;

    cout << "Enter integers (terminate with non-integer input):" << endl;


    while (cin >> value) {
        //insertSorted(head, value);
        head = insertSortedRecursive(head, value);
    }



    cout << "Sorted list:" << std::endl;
    printList(head);

    return 0;
}
