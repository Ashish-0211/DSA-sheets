#include <iostream>
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
        cout << "deleted value is :" << value << "\n";
    }
};
void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        newNode->next = NULL;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
}
void print(Node *head)
{
    if (!head)
        return;
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL"
         << "\n";
}
Node *removeDuplicate(Node *&head)
{
    if (!head)
        return nullptr;
    Node *current = head;
    while (current)
    {
        while (current->next and current->data == current->next->data)
        {
            current->next = current->next->next;
        }
        current = current->next;
    }
    return head;
}
int main()
{
    Node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 2);
    insertAtTail(head, 2);
    insertAtTail(head, 2);
    print(head);
    Node *gg = removeDuplicate(head);
    print(head);
    return 0;
}