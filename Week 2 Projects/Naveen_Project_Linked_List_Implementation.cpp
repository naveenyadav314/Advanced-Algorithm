#include <iostream>
using namespace std;

// followed the node structure from pdf
struct Node {
    int row;      // row index
    int col;      // column index
    int value;    // value
    Node* next;   // point to the next node
};

// new node creation
Node* createNode(int r, int c, int v) {
    Node* newNode = new Node(); 
    newNode->row = r;
    newNode->col = c;
    newNode->value = v;
    newNode->next = nullptr;
    return newNode;
}

void insertNode(Node*& head, int r, int c, int v) {
    Node* newNode = createNode(r, c, v);

    // if list is empty, new node becomes head
    if (head == nullptr) {
        head = newNode;
        return;
    }
    // otherwise, go to the end and attach the new node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display linked list (sparse matrix form)
void displaySparse(Node* head) {
    cout << "\nSparse Matrix Representation:\n";

    cout << "Row:    ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->row << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "Column: ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->col << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "Value:  ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int matrix[50][50]; // fixed size for simplicity

    cout << "Enter the matrix elements (" << rows << " x " << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    Node* head = nullptr;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                insertNode(head, i, j, matrix[i][j]);
            }
        }
    }

    cout << "\nOriginal Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    displaySparse(head);

    return 0;
}
