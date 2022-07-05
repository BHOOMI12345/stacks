#include<iostream>
#include<stack>

using namespace std;

class Stcack{
    public:
    int top1;
    int top2;
    int *arr;
    int size;

    Stack(int size)
    {
        this->size = size;
        int *arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int ele)
    {
        if(top2-top1>1)
        {
            top1++;
            arr[top1] = ele;
        }
        else
        {
            return ;
        }
    }

    void push2(int ele)
    {
        if(top2-top1 > 1)
        {
            top2--;
            arr[top2] = ele;
        }
        else
        {
            return;
        }
    }

    int pop1()
    {
        if(top1>=0)
        {
            int y1 = arr[top1];
            top1--;
            return y1;
        }
        else
        {
            return -1;
        }
    }

    int pop2()
    {
        if(top2 < size)
        {
            int y2 = arr[top2];
            top2++;
            return y2;
        }

        else 
        {
            return -1;
        }
    }

};