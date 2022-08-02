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
    cout << "Enter the number of nodes you want to enter :"
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
Node *intersectionList(Node *head1, Node *head2)
{
    Node *current1 = head1;
    Node *current2 = head2;
    while (current2)
    {
        Node *temp = current1;
        while (temp)
        {
            if (temp == current2)
                return current2;
            temp = temp->next;
        }
        current2 = current2->next;
    }
    return NULL;
}
Node *intersectionHash(Node *head1, Node *head2)
{
    unordered_set<Node *> st;
    Node *current1 = head1;
    while (current1)
    {
        st.insert(current1);
        current1 = current1->next;
    }
    Node *current2 = head2;
    while (current2)
    {
        if (st.count(current2))
            return current2;
        current2 = current2->next;
    }
    return NULL;
}
int getDifference(Node *head1, Node *head2)
{
    int len1 = 0;
    int len2 = 0;
    Node *current1 = head1;
    Node *current2 = head2;
    while (current1)
    {
        len1++;
        current1 = current1->next;
    }
    while (current2)
    {
        len2++;
        current2 = current2->next;
    }
    return (len1 - len2);
}
Node *intersectionDifference(Node *head1, Node *head2)
{
    int difference = getDifference(head1, head2);
    if (difference < 0)
        while (difference++ != 0)
            head2 = head2->next;
    else if (difference > 0)
        while (difference-- != 0)
            head1 = head1->next;
    while (head1)
    {
        if (head1 == head2)
            return head1;
        head2 = head2->next;
        head1 = head1->next;
    }
    return head1;
}
int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    input(head1);
    input(head2);
    printList(head1);
    printList(head2);
    Node *intersection = intersectionList(head1, head2);
    Node *intersectionH = intersectionHash(head1, head2);
    Node *intersectionDiff = intersectionDifference(head1, head2);
    printList(intersection);
    return 0;
}