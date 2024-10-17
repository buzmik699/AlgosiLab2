#include <iostream>
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

Chain* initListFromKeyboard() {
    int num; cin >> num;
    Chain* head = NULL;
    Chain* current = NULL;
    while (num != 0) {
        Chain* newNode = new Chain();
        newNode->data = num;
        if (head == NULL) head = newNode;
        else current->next = newNode;
        current = newNode;
        cin >> num;
    } return head;
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

void getLists(const Chain* lst, Chain*& positive, Chain*& negative) {
    while (lst != NULL) {
        if (lst->data >= 0) addElementEnd(positive, lst->data);
        else addElementBegin(negative, lst->data);
        lst = lst->next;
    } 
}





int main() {
    Chain* lst = NULL;
    Chain* pos = NULL;
    Chain* neg = NULL;
    lst = initListFromKeyboard();
    getLists(lst, pos, neg);
    cout << "Positive numbers:\n"; print(pos);
    cout << "__________________\n";
    cout << "Negative numbers:\n"; print(neg);


}

