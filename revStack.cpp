#include <bits/stdc++.h>
#include "myTempStack.h"
using namespace std;

void insertAtBottom(Stack<int> &chk, int chkEl)
{
    if (chk.empty())
    {
        chk.push(chkEl);
        return;
    }
    int topElement = chk.Top();
    chk.pop();
    insertAtBottom(chk, chkEl);

    chk.push(topElement);
}

void revSt(Stack<int> &chk)
{
    if (chk.empty())
    {
        return;
    }
    int topEl = chk.Top();
    chk.pop();
    revSt(chk);

    insertAtBottom(chk, topEl);
}

int main()
{
    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    revSt(st);
    while (!st.empty())
    {
        cout << st.pop() << " ";
    }
}