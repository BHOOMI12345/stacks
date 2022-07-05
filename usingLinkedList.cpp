#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node * next;

    Node (int d)
    {
        data = d;
        next = NULL;
    }
};

class Stacks{
    Node * top;
    Stacks()
    {
        top = NULL;
    }

    void push(int data)
    {
        Node * temp = new Node (data);
        if(top==NULL)
        {
            top = temp;
            return;
        }

        temp->next = top;
        top = temp;
        

    }

    void pop()
    {
        if(top==NULL)
        {
            cout<<"Stack is empty"<<endl;
            return ;
        }

        Node * temp = top;
        top = top->next;
        delete(temp);
    }
};