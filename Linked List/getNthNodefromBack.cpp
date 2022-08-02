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
    cout << "Enter the size of the linked list :"
         << "\n";
    int size;
    cin >> size;
    cout << "Enter the value :"
         << "\n";
    int data;
    while (size--)
    {
        cin >> data;
        insertAtTail(head, data);
    }
}
void printList(Node *head)
{
    Node *current = head;
    cout << "Linked list is :"
         << "\n";
    while (current)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL"
         << "\n";
}
void getNthNodelast(Node *head)
{
    cout << "Enetr the nth node :"
         << "\n";
    int nth;
    cin >> nth;
    Node *fast = head;
    Node *slow = head;
    for (int i = 1; i < nth; i++)
    {
        fast = fast->next;
        if (!fast)
            return;
    }
    while (fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    cout << "Nth node from the last :"
         << "\n";
    cout << slow->data << "\n";
}
int main()
{
    Node *head = NULL;
    input(head);
    printList(head);
    getNthNodelast(head);
    return 0;
}