#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        cout << "deleted value is :" << value << "\n";
    }
};
void insertAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void insertAtTail(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (!head)
    {
        head = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
        return;
    }
    Node *current = head;
    while (current->next)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    newNode->next = NULL;
}
void input(Node *&head)
{
    cout << "Enter the size of the linked list :"
         << "\n";
    int size;
    cin >> size;
    cout << "Enter values :"
         << "\n";
    int data;
    while (size--)
    {
        cin >> data;
        insertAtTail(head, data);
    }
}
void insertAtPosition(Node *&head, int data)
{
    cout << "Enter the position where you want to insert :"
         << "\n";
    int position;
    cin >> position;
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }
    Node *current = head;
    int count = 1;
    while (count < position)
    {
        current = current->next;
        count++;
    }
    if (!current->next)
    {
        insertAtTail(head, data);
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = current->next;
    current->next->prev = newNode;
    current->next = newNode;
}
void printList(Node *head)
{
    cout << "Linked list is :"
         << "\n";
    Node *current = head;
    while (current)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL"
         << "\n";
}
int main()
{
    Node *head = NULL;
    input(head);
    printList(head);
    insertAtPosition(head, 675);
    printList(head);
    return 0;
}