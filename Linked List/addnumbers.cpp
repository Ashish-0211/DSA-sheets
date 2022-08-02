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
        cout << "deleted node value is :" << value << "\n";
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
void print(Node *head)
{
    Node *current = head;
    cout << "List is :"
         << "\n";
    while (current)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL"
         << "\n";
}
Node *reverse(Node *&node)
{
    Node *current = node;
    Node *prev = NULL;
    Node *next = NULL;
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
Node *add(Node *head1, Node *head2)
{
    Node *dummy = new Node();
    Node *temp = dummy;
    int carry = 0;
    while (head1 || head2 || carry)
    {
        int sum = 0;
        if (head1)
        {
            sum += head1->data;
            head1 = head1->next;
        }
        if (head2)
        {
            sum += head2->data;
            head2 = head2->next;
        }
        sum += carry;
        carry = sum / 10;
        Node *node = new Node(sum % 10);
        temp->next = node;
        temp = temp->next;
    }
    dummy->next = reverse(dummy->next);
    return dummy->next;
}
int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    input(head1);
    input(head2);
    print(head1);
    print(head2);
    Node *result = NULL;
    result = add(head1, head2);
    print(result);
    return 0;
}