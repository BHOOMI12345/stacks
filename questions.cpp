#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Q2 DELETE THE MIDDLE ELEMENT OF THE STACK
void solve(stack<int> st, int count, int n)
{
    if (count == n / 2)
    {
        st.pop();
        return;
    }

    int num = st.top();
    st.pop();

    solve(st, count + 1, n);

    st.push(num);
}
void deletionOfMiddleElement(stack<int> st, int size)
{
    int count = 0;
    solve(st, count, size);
}

// Q3 VALID PARENTHESIS
bool valideParenthesis(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }

        else
        {
            if (!st.empty())
            {
                char top = st.top();
                if ((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{'))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    return st.empty();
}

// Q4 INSERTION AT THE BOTTOM OF THE STACK

void solve(stack<int> st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }

    int num = st.top();
    st.pop();

    solve(st, x);
}
stack<int> pushAtBottom(stack<int> &s, int x)
{
    solve(s, x);
    return s;
}

// Q5 REVERSE THE STACK USING RECURSION

void recursion(stack<int> st)
{
    int num = st.top();
    st.pop();

    recursion(st);

    pushAtBottom(st, num);
}

// Q6 SORT STACK
void sortedInsert(stack<int> st, int num)
{
    if (st.empty() || (!st.empty() && st.top() < num))
    {
        st.push(num);
        return;
    }

    int n = st.top();
    st.pop();

    sortedInsert(st, n);

    st.push(n);
}

void sort(stack<int> st)
{
    if (st.empty())
    {
        return;
    }

    int num = st.top();
    st.pop();

    sort(st);

    sortedInsert(st, num);
}

// Q7 FIND REDUNDANT BRACKETS

bool redundantBrackets(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '*' || ch == '+' || ch == '/' || ch == '-')
        {
            st.push(ch);
        }

        else
        {
            if (ch == ')')
            {
                bool isRedundant = true;
                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '*' || top == '+' || top == '/' || top == '-')
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }

                if (isRedundant == true)
                {
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}

// Q8 FIND THE MINIMUM COST

int findMinCost(string &s)
{

    stack<char> st;
    if (s.length() % 2 == 1)
    {
        return -1;
    }

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '{')
        {
            st.push(ch);
        }

        else
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }

            else
            {
                st.push(ch);
            }
        }

        int a = 0, b = 0;
        while (!st.empty())
        {
            if (st.top() == '{')
            {
                b++;
            }
            else
            {
                a++;
            }

            st.pop();
        }
        int ans = (a + 1) / 2 + (b + 1) / 2;
        return ans;
    }
}



// Q9 LARGEST RECTANGLE IN HISTOGRAM

vector<int> nextSmallerElement(vector<int> next, int n)
{
    stack<int> st;
    st.push(-1);

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = next[i];
        while (st.top() != -1 && next[st.top()] >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);

    }

    return ans;
}

vector<int> previousSmallerElement(vector<int>  prev, int n)
{
    stack<int> st;
    st.push(-1);

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = prev[i];
        while (st.top() != -1 && prev[st.top()] >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);

    }

    return ans;
}

int rectangle(vector<int> &heights)
{
    int n = heights.size();

    vector<int> next(n);

    next = nextSmallerElement(next, n);

    vector<int> prev(n);

    prev = previousSmallerElement(prev, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];

        if (next[i] == -1)
        {
            next[i] = n;
        }

        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }

    return area;
}


//Q10 CELEBRITY PROBLEM

bool knows(vector<vector<int>> arr,int a,int b,int n)
{
    if(arr[a][b]==1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int celebrity(vector<vector<int>> arr,int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    while (st.size()>1)
    {
        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();

        if(knows(arr,a,b,n))
        {
            st.push(b);
        }
        else
        {
            st.push(a);
        }
    }

    int ans = st.top();

    int zeroCount = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[ans][i] == 0)
        {
            zeroCount++;
        }
    }

    if(zeroCount!=n)
    {
        return -1;
    }

    int oneCount = 0;

    for (int i = 0; i < n; i++)
    {
        if(arr[i][ans] ==1)
        {
            oneCount++;
        }
    }

    if(oneCount!=n-1)
    {
        return -1;
    }

    return ans;
    
    
    
    
}



// Q1 REVERSE THE STRING USING STACK
int main()
{

    string str = "bhoomica";

    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        st.push(str[i]);
    }

    string ans = "";

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    cout << ans << endl;
}