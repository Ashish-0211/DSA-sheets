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
        cout << "Deleted value is  :" << value << "\n";
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
    int data;
    cout << "Enter values :"
         << "\n";
    while (size--)
    {
        cin >> data;
        insertAtTail(head, data);
    }
}
void printList(Node *head)
{
    cout << "Linked List is :"
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
Node *rotateListNaive(Node *&head, int k)
{
    if (!head or !head->next)
        return head;
    for (int i = 0; i < k; i++)
    {
        Node *temp = head;
        while (temp->next->next)
            temp = temp->next;

        Node *end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}
Node *rotateListOptimise(Node *&head, int k)
{
    if (!head or !head or k == 0)
        return head;
    Node *current = head;
    int length = 0;
    while (current->next)
    {
        length++;
        current = current->next;
    }
    current->next = head;
    k = k % length;
    int end = length - k;
    while (end--)
        current = current->next;
    head = current->next;
    current->next = NULL;
    return head;
}
int main()
{
    Node *head = NULL;
    input(head);
    printList(head);
    cout << "Rotate the list by :"
         << "\n";
    int k = 0;
    cin >> k;
    Node *nHead = NULL;
    nHead = rotateListNaive(head, k);
    printList(nHead);
    Node *kHead = NULL;
    kHead = rotateListOptimise(head, k);
    printList(kHead);
    return 0;
}