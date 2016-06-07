// InsertionSortList.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <string>

template <typename T>
struct Node
{
    Node(T value): data(value), next(NULL), prev(NULL) {}
    T data;
    Node<T>* next;
    Node<T>* prev;
};

template <typename T>
class LinkedList
{
public:
    LinkedList(): head(NULL), tail(NULL) {}
    ~LinkedList() {}
    void printList();
    void insertNode(T value);
private:
    Node<T>* head;
    Node<T>* tail;
};

template <typename T>
void LinkedList<T>::printList()
{
    Node<T>* temp = head;
    std::cout << "List: ";
    while (temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template <typename T>
void LinkedList<T>::insertNode(T value)
{
    // Check for an empty list and insert a single node as head/tail
    if (head == NULL)
    {
        head = new Node<T>(value);
        tail = head;
        std::cout << "New head node created" << std::endl;
    }
    // List is not empty
    else
    {
        // Search through nodes to find the right insertion location
        Node<T>* temp = head;
        bool locFound = false;
        while ((temp != NULL) && (!locFound))
        {
            if (value > temp->data)
            {
                temp = temp->next;
            }
            else
            {
                locFound = true;
            }
        }
        // Check for new head node
        if (temp == head)
        {
            head = new Node<T>(value);
            head->next = temp;
            temp->prev = head;
            std::cout << "New head node created" << std::endl;
        }
        // Check for new tail node
        else if (temp == NULL)
        {
            temp = new Node<T>(value);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            std::cout << "New tail node created" << std::endl;
        }
        // Insert node as prev node
        else
        {
            Node<T>* newNode = new Node<T>(value);
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;
            newNode->next = temp;
            std::cout << "New node inserted" << std::endl;
        }
    }
}


int _tmain(int argc, _TCHAR* argv[])
{
    LinkedList<double> test;
    test.printList();
    test.insertNode(1.1);
    test.insertNode(5.5);
    test.insertNode(3.3);
    test.printList();
    test.insertNode(0.9);
    test.printList();
    test.insertNode(9.9);
    test.printList();
    test.insertNode(2.2);
    test.insertNode(5.5);
    test.insertNode(5.6);
    test.printList();

    system("PAUSE");
    return 0;
}

