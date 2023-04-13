#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

Node* GetNewNode(int x)
{
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void InsertAtHead(Node** head, int x)
{
    Node* newNode = GetNewNode(x);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    } 
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void InsertAtPos(Node** head, int x, int pos)
{
    Node* newNode = GetNewNode(x);
    if (pos == 1)
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    } 
    Node* newNode2 = *head;
    for (int i = 0; i < pos - 2; i++)
    {
        newNode2 = newNode2->next;
    }
    newNode->next = newNode2->next;
    newNode->prev = newNode2;
    newNode2->next = newNode;
}

void DeleteAtPos(Node** head, int pos)
{
    Node* newNode = *head;
    if (pos == 1)
    {
        *head = newNode->next;
        return;
    }
    for (int i = 0; i < pos-2; i++)
    {
        newNode = newNode->next;
    }
    Node* newNode2 = newNode->next;
    newNode->next = newNode2->next;
    newNode2->prev = newNode;
    free(newNode2);
}

void Reverse(Node** head)
{
    Node* newNode = *head;
    while (newNode != NULL)
    {   
        auto* temp = newNode->next;
        newNode->next = newNode->prev;
        newNode->prev = temp;
        if (newNode->prev != NULL) newNode = newNode->prev;
        else break;
    }
    *head = newNode;
}

void Print(Node* head)
{
    Node* temp = head;
    cout << "Forward: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void RecursionPrint(Node* head) // same with singly linked list
{
    cout << head->data << " ";
    if (head->next != NULL) RecursionPrint(head->next);
    else
    {
        cout << endl;
        return;
    }
}

void ReversePrint(Node* head)
{
    Node* temp = head;
    cout << "Reverse: ";
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    Node* head = NULL;
    InsertAtHead(&head, 3);
    InsertAtHead(&head, 4);
    InsertAtHead(&head, 5);
    InsertAtHead(&head, 7);
    Print(head);
    ReversePrint(head);
    InsertAtPos(&head, 15, 4);
    Print(head);
    DeleteAtPos(&head,4);
    Print(head);
    Reverse(&head);
    RecursionPrint(head);
    return 0;
}