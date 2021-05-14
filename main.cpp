#include <iostream>
#include "CLinkedList.h"
using namespace std;

CLinkedList cll;

void create_Josephus_circle() {
    int number_of_people, start;
    cout << "\n\tHow many people are in the circle?";
    cin >> number_of_people;
    cout << "\n\tChoose a starting point: ";
    cin >> start;
    if (start > number_of_people) {
        cout << "Out of range";
    }
    else {
        for (int i = start; i <= number_of_people; i++) {
            Node *n1 = new Node();
            n1->setKey(i);
            cll.add_node(n1);
        }
        for (int j = 1; j < start; j++) {
            Node *n1 = new Node();
            n1->setKey(j);
            cll.add_node(n1);
        }


        // cll.display_cll();
    }
}




int main()
{
    int key;

    int ch;

    main:


    cout<<"\n\t Welcome to Josephus problem!";

    cout<<"\n\t[0] Exit\n\t[1] Josephus Problem\n\t[2] Display CLL\n\t[3] Add Node\n\t[4] Delete Node\n\t[5] Third node from a giving one in CLL\n\t[6] Create an CLL for tests";

    cout<<"\n\tEnter your choice: ";

    cin>>ch;

    switch(ch)

    {

        case 0:
        {
            cout << "\n\tAre you sure you want to exit?\n";
            break;
        }
        case 1:
        {
            create_Josephus_circle();
            cout<<"\n\tHow many people are skipped?";
            int k;cin>>k;
            int x=cll.josephus_for_k(k);
            cout<<"\n\tStays alive:"<<x;
            break;
        }
        case 2:
        {
            cll.display_cll();
            break;
        }

        case 3:

        {
            cin >> key;
            Node *n1 = new Node();
            n1->setKey(key);
            cll.add_node(n1);
            break;
        }
        case 4:

        {
            cin >> key;
            cll.delete_node(key);
            break;
        }
        case 5:
        {
            cout<<"\n\tChoose a starting node:";
            cin >> key;
            Node *ptr = cll.nodeExists(key);
            if(ptr == nullptr) {
                cout << "\n\tNode does not exists.";
                break;
            }
            cout<<"\n\tThird element from element -"<<key<<"- is: "<<cll.third_node(key)<<endl;
            break;
        }
        case 6:
        {
            int n;
            cout<<"\n\tHow many nodes do you need?";
            cin>>n;
            for (int i = 1; i <= n; i++) {
                Node *n1 = new Node();
                n1->setKey(i);
                cll.add_node(n1);
            }
            break;
        }


        default:
        {
            cout<<"\n\tInvalid choice";
            break;
        }

    }
    cout<<"\n\t[1] Main Menu\t\t[0] Exit";
    cout<<"\n\tEnter your choice: ";

    cin>>ch;

    switch (ch)

    {

        case 1:
            goto main;

        case 0:
            break;

        default:
            cout<<"Invalid choice";
            break;

    }


    return 0;
}
