#include<iostream>
#include<stack>

using namespace std;

class Stack{
    public:

    int top;
    int *arr;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if(size-top >1 )
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout<<"Stack OverFlow"<<endl;
        }
    }

    void pop()
    {
        if(top >=0)
        {
            top--;
        }
        else
        {
            cout<<"Stack UnderFlow"<<endl;
        }
    }

    int peek()
    {
        if(top>=0)
        {
            return arr[top];
        }
        else
        {
            cout<<"Stack Empty"<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


int main()
{
    Stack st(5);

    st.push(50);
    st.push(44);
    st.push(87);
    st.push(56);
    st.push(68);
    st.push(70);

    cout<<  st.peek()<<endl;
    st.pop();
    cout<<  st.peek()<<endl;
    st.pop();
    cout<<  st.peek()<<endl;
    st.pop();
    cout<<  st.peek()<<endl;
    st.pop();
    cout<<  st.peek()<<endl;
    st.pop();
    cout<<  st.peek()<<endl;
    st.pop();

    if(st.isEmpty())
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        cout<<"Stack is empty"<<endl;
    }

    
}