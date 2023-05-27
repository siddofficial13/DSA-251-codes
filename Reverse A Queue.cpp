#include <bits/stdc++.h> 
queue<int> reverseQueue(queue<int> q)
{
    // Using a Stack.
    stack<int> stack;
    while(!q.empty()){
        stack.push(q.front());
        q.pop();
    }
    while(!stack.empty()){
        q.push(stack.top());
        stack.pop();
    }
    return q;
}
