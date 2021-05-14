#ifndef ADS_JOSEPHUS_CLINKEDLIST_H
#define ADS_JOSEPHUS_CLINKEDLIST_H
class Node
{
private:
    int key;
    Node * next;
public:
    Node();
    explicit Node(int k);
    int getKey();
    Node * getNext();
    void setNext(Node * p);
    void setKey(int n);
};

class CLinkedList {
private:
    Node * head;
    int size;

public:
    CLinkedList();
    Node * nodeExists(int k);
    void add_node(Node * new_node);
    void display_cll();
    void delete_node(int k);
   // int josephus();
    int josephus_for_k(int k);
    int third_node(int k);


};


#endif //ADS_JOSEPHUS_CLINKEDLIST_H
