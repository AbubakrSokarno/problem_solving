/**
 * Problem Link :-
 * - https://leetcode.com/problems/min-stack/
 * */
 
class MinStack {
private:
    vector<int> stack_items ;
    vector<int> min_stack ;
    int min_item;
public:
    /** initialize your data structure here. */
    MinStack() {
        stack_items = {} ;
        min_item = INT_MIN ;
    }

    void push(int x) {
        stack_items.push_back(x) ;
        if (!min_stack.empty() && x <= min_stack[min_stack.size() - 1]) {
            min_stack.push_back(x) ;
        }
        else if (min_stack.empty()) {
            min_stack.push_back(x) ;
        }
    }

    void pop() {
        if (! stack_items.empty()) {
            int top_item = stack_items[stack_items.size() - 1];
            if (! min_stack.empty() && top_item == min_stack[min_stack.size() - 1]) {
                min_stack.erase(min_stack.begin() + min_stack.size() - 1);
            }
            stack_items.erase(stack_items.begin() + stack_items.size() - 1);
        }
    }

    int top() {
        if (stack_items.empty())
            return INT_MIN ;
        return stack_items[stack_items.size() - 1];
    }

    int getMin() {
        return min_stack[min_stack.size() - 1];
    }

    void printStacks() {
        cout << "main stack \n" ;
        for(int item : stack_items) {
            cout << item << " " ;
        }
        cout << "\nminimum stack \n" ;
        for(int item : min_stack) {
            cout << item << " " ;
        }
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
