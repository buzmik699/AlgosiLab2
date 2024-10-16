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


void deleteElements(Chain*& first, Chain*& second, int value) {
    Chain* head = first;
    bool flag = false;
    while (first != NULL) {
        if (flag) {
            addElementBegin(second, first->data);
        }
        if (first->data == value) flag = true;
        first = first->next;
    }
    first = head;
    head = first;
    while (true) {
        if (first->data == value) {
            first->next = NULL;
            break;
        }
        first = first->next;
    } first = head;
}


int main() {
    Chain* first = createListFromFile("input.txt");
    Chain* second = NULL;
    deleteElements(first, second, 4);
    print(first);
    cout << "___________\n";
    print(second);
}

