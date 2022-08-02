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
        this->next = nullptr;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != nullptr)
        {
            delete next;
            this->next = nullptr;
        }
        cout << "Deleted value is :" << value << "\n";
    }
};
void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        newNode->next = nullptr;
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
Node *middleOfList(Node *head)
{
    if (!head)
        return nullptr;
    Node *slow = head;
    Node *fast = head;
    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main()
{
    Node *head = nullptr;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    print(head);
    Node *middle = middleOfList(head);
    cout << middle->data << "\n";
    return 0;
}