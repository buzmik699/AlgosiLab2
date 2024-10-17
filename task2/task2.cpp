#include <iostream>
#include <string>

using namespace std;

struct Chain {
    int data;
    Chain* next = NULL;
};


void insertSorted(Chain*& head, int value) {
    Chain* newNode = new Chain();
    newNode->data = value;

    if (head == NULL || head->data >= value) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Chain* current = head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

Chain* insertSortedRecursive(Chain* head, int value) {
    if (head == NULL || head->data >= value) {
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
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void addList(Chain*& list, Chain*& head) {
    while (head != NULL) {
        insertSorted(list, head->data);
        head = head->next;
    }
}


int main() {
    Chain* main_list = NULL;
    Chain* lst1 = NULL;
    Chain* lst2 = NULL;
    int value1;


    cout << "Enter integers for list1 (terminate with non-integer input):" << endl;
    while (cin >> value1) {
        insertSorted(lst1, value1);
    }

    
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter integers for list2 (terminate with non-integer input):" << endl;
    while (cin >> value1) {
        insertSorted(lst2, value1);
    }
    addList(main_list, lst1);
    addList(main_list, lst2);

    
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Sorted list:" << endl;
    printList(main_list);

    return 0;
}
