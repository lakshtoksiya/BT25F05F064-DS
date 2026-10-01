#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

Node *head = NULL;

// Insert at beginning
void insertBegin(int data) {
    Node *newNode = new Node;

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
}

// Insert at end
void insertEnd(int data) {
    Node *newNode = new Node;
    Node *temp;

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    newNode->prev = temp;
    temp->next = newNode;
}

// Insert at a given position
void insertMiddle(int data, int position) {
    Node *newNode;
    Node *temp;
    int i;

    // If position is 1, insert at beginning
    if (position == 1) {
        insertBegin(data);
        return;
    }

    newNode = new Node;
    newNode->data = data;

    temp = head;

    // Move to the node before the required position
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position!" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

// Delete from a given position
void deleteNode(int position) {
    Node *temp;
    int i;

    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    temp = head;

    // Delete first node
    if (position == 1) {
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        }

        delete temp;
        return;
    }

    // Move to the node that needs to be deleted
    for (i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position!" << endl;
        return;
    }

    // Connect previous node to next node
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    // Connect next node to previous node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

// Display from beginning to end
void displayForward() {
    Node *temp = head;

    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    cout << "Forward: ";

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Display from end to beginning
void displayBackward() {
    Node *temp = head;

    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    // Go to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    cout << "Backward: ";

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }

    cout << "NULL" << endl;
}

// Main function
int main() {
    int choice, data, position;

    while (1) {

        cout << "\n--- Doubly Linked List Menu ---" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at Middle" << endl;
        cout << "3. Insert at End" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Display Forward" << endl;
        cout << "6. Display Backward" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter data: ";
                cin >> data;

                insertBegin(data);
                break;

            case 2:
                cout << "Enter data: ";
                cin >> data;

                cout << "Enter position: ";
                cin >> position;

                insertMiddle(data, position);
                break;

            case 3:
                cout << "Enter data: ";
                cin >> data;

                insertEnd(data);
                break;

            case 4:
                cout << "Enter position to delete: ";
                cin >> position;

                deleteNode(position);
                break;

            case 5:
                displayForward();
                break;

            case 6:
                displayBackward();
                break;

            case 7:
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
