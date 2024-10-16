#include <iostream>
#include <string>

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
    Chain* head = nullptr;
    int value1;

    cout << "Enter integers for list1 (terminate with non-integer input):" << endl;
    while (cin >> value1) {
        insertSorted(head, value1);
    }

    // Сбросить состояние cin после некорректного ввода
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter integers for list2 (terminate with non-integer input):" << endl;
    while (cin >> value1) {
        insertSorted(head, value1);
    }

    // Сбросить состояние cin после некорректного ввода
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Sorted list:" << endl;
    printList(head);

    return 0;
}
