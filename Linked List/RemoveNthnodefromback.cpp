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
void insertedAtTail(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (!head)
    {
        head = newNode;
        newNode->next = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
}
void input(Node *&head, int size)
{
    int data;
    while (size--)
    {
        cin >> data;
        insertedAtTail(head, data);
    }
}
void printLinkedList(Node *head)
{
    cout << "Linked List is :"
         << "\n";
    Node *current = head;
    while (current)
    {
        cout << current->data << "->"
             << " ";
        current = current->next;
    }
    cout << "NULL"
         << "\n";
}
void deleteNthNode(Node *&head)
{
    cout << "Enter the nth to be delete from back :"
         << "\n";
    int location;
    cin >> location;
    Node *start = new Node();
    start->next = head;
    Node *slow = start;
    Node *fast = start;
    for (int i = 0; i < location; i++)
        fast = fast->next;

    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    head = start->next;
}
int main()
{
    Node *head = NULL;
    cout << "Enter the number of nodes in the linked list :"
         << "\n";
    int size;
    cin >> size;
    input(head, size);
    printLinkedList(head);
    deleteNthNode(head);
    printLinkedList(head);
    return 0;
}