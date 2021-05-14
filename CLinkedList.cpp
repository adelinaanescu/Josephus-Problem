#include "CLinkedList.h"
#include<iostream>
using namespace std;

Node::Node()
{
    key = 0;
    next = nullptr;
}

Node::Node(int k)
{
    key = k;
}

int Node::getKey ()
{
    return key;
}

Node * Node::getNext()
{
    return next;
}

void Node::setNext(Node * p)
{
    next = p;
}

void Node::setKey(int n)
{
    key = n;
}
CLinkedList::CLinkedList()
{
    head = nullptr;
    size = 0;
}
Node * CLinkedList::nodeExists(int k)
{

    Node * temp = nullptr;
    Node * ptr = head;

    if (ptr == nullptr)
    {
        return temp;
    }
    else
    {
        do
        {
            if (ptr -> getKey() == k)
            {
                temp = ptr;
            }
            ptr = ptr -> getNext();

        }
        while (ptr != head);

        return temp;
    }

}

void CLinkedList::add_node(Node * new_node)
{
    if (nodeExists(new_node -> getKey()) != nullptr)
    {
        cout << "\n\tNode alreday exists. Try again!"<<endl;
    }
    else
    {
        if (head == nullptr)
        {
            head = new_node;
            new_node -> setNext(head);
        }
        else
        {
            Node * ptr = head;
            while (ptr -> getNext() != head)
            {
                ptr = ptr -> getNext();
            }
            ptr -> setNext(new_node);
            new_node -> setNext(head);
        }
        size++;
    }

}
void CLinkedList::display_cll()
{
    if (head == nullptr)
    {
        cout << "\n\tThe Circular Linked List is empty.";
    }
    else
    {
        Node * temp = head;
        cout<<"\n\t";
        do
        {

            cout << "[" << temp -> getKey() << "]->";
            temp = temp -> getNext();
        }
        while (temp != head);

    }
cout<<endl;
}

void CLinkedList::delete_node(int k)
{
    Node * ptr = nodeExists(k);
    if(ptr == nullptr)
        cout<<"\n\tNode does not exists.";
    else {
        if (ptr == head) {
            if (head->getNext() == nullptr) {
                head = nullptr;
                cout << "Empty CLList";
            } else {
                Node *ptr1 = head;
                while (ptr1->getNext() != head) {
                    ptr1 = ptr1->getNext();
                }
                ptr1->setNext(head->getNext());
                head = head->getNext();
            }


        } else {
            Node *temp = nullptr;
            Node *prevptr = head;
            Node *currentptr = head ->getNext();
            while (currentptr != nullptr) {
                if (currentptr ->getKey() == k) {
                    temp = currentptr;
                    currentptr = nullptr;
                } else {
                    prevptr = prevptr ->getNext();
                    currentptr = currentptr ->getNext();
                }
            }

            prevptr ->setNext(temp->getNext()) ;

        }
    }
}


//int CLinkedList::josephus() {
//    display_cll();
//    Node *current= head;
//    Node *del= head->getNext();
//    while(head->getNext()!=head)
//    {
//        if(del == head)
//        {
//            head=head->getNext();
//        }
//        cout<<"\n\tWe kill "<<del->getKey()<<"th person :  ";
//        delete_node(del->getKey());
//        current=current->getNext();
//        del=current->getNext();
//
//        display_cll();
//
//
//    }
//    return head->getKey();
//}
int CLinkedList::josephus_for_k(int k) {
    display_cll();
    Node *current= head;
    Node *del= head->getNext();
    while(head->getNext()!=head)
    {
        for(int i = 1; i < k; i++)
        {
            current = current->getNext();
            del = del->getNext();
        }
        if(del == head)
        {
            head=head->getNext();
        }
        cout<<"\n\tWe kill "<<del->getKey()<<"th person :  ";
        delete_node(del->getKey());
        current=current->getNext();
        del=current->getNext();

        display_cll();


    }
    return head->getKey();
}
int CLinkedList::third_node(int k){

    Node *current=head;
    for(int i=1;i<k+3;i++)
        current=current->getNext();
    return current->getKey();
}


