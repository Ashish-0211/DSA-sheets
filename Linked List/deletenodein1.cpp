#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Deleted value is :" << value << "\n";
    }
};
void insertAtTail(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (!head)
    {
        head = newNode;
        newNode->next = NULL;
        return;
    }
    Node *current = head;
    while (current->next)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = NULL;
}
void input(Node *&head)
{
    cout << "Enter the number of nodes :"
         << "\n";
    int size;
    cin >> size;
    int data;
    while (size--)
    {
        cin >> data;
        insertAtTail(head, data);
    }
}
void printList(Node *head)
{
    cout << "List is :"
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
Node *getNode(Node *head, int value)
{
    while (head->data != value)
        head = head->next;

    return head;
}
void deleteNodeIn1(Node *&head)
{
    cout << "Enter node you want to delete :"
         << "\n";
    int value;
    cin >> value;
    Node *dNode = getNode(head, value);
    dNode->data = dNode->next->data;
    dNode->next = dNode->next->next;
    return;
}
int main()
{
    Node *head = NULL;
    input(head);
    printList(head);
    deleteNodeIn1(head);
    printList(head);
    return 0;
}