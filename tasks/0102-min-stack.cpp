class MinStack {
  private:
    stack<int> values;
    stack<int> minimums;

  public:
    MinStack() {}

    void push(int val) {
        if (values.empty()) {
            minimums.push(val);
        } else {
            minimums.push(min(minimums.top(), val));
        }
        values.push(val);
    }

    void pop() {
        values.pop();
        minimums.pop();
    }

    int top() { return values.top(); }

    int getMin() { return minimums.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */