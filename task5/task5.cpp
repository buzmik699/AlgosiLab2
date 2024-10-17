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
    Chain* ans = NULL;
    while (first != NULL) {
        if (flag) {
            addElementEnd(ans, first->data);
        }
        if (first->data == value) flag = true;
        first = first->next;
    }
    first = head;
    head = first;
    if (flag) {
        while (true) {
            if (first->data == value) {
                first->next = NULL;
                break;
            }
            first = first->next;
        } first = head;
        while (second != NULL) {
            addElementEnd(ans, second->data);
            second = second->next;
        }
        second = ans;
    }
    
}


int main() {
    Chain* first = createListFromFile("input.txt");
    Chain* second = createListFromFile("input2.txt");
    deleteElements(first, second, 1);
    print(first);
    cout << "___________\n";
    print(second);
}

