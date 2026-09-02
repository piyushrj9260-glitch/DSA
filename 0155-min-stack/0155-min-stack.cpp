class MinStack {
    stack<long long> st;
    long long minEle;

public:
    MinStack() {
        minEle = LLONG_MAX;
    }

    void push(int value) {

        if(st.empty()) {
            st.push(value);
            minEle = value;
        }
        else {
            if(value >= minEle) {
                st.push(value);
            }
            else {
                st.push(2LL * value - minEle);
                minEle = value;
            }
        }
    }

    void pop() {

        if(st.empty())
            return;

        long long topVal = st.top();
        st.pop();

        if(topVal < minEle) {
            minEle = 2 * minEle - topVal;
        }
    }

    int top() {

        long long topVal = st.top();

        if(topVal < minEle)
            return (int)minEle;

        return (int)topVal;
    }

    int getMin() {
        return (int)minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */