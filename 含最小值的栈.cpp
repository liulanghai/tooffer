#include "common.h"
class Solution {
public:
    stack<int> stack1;
    stack<int> minstack;
    void push(int value) {
        stack1.push(value);
        if(minstack.empty()){
            minstack.push(value);
        }else
        {
            int tmp = minstack.top();
            if(tmp<value){
                minstack.push(tmp);
            }else{
                 minstack.push(value);
            }
        }
    }
    void pop() {
        stack1.pop();
        minstack.pop();
    }
    int top() {
        return stack1.top();
    }
    int min() {
        return minstack.top();
    }
};