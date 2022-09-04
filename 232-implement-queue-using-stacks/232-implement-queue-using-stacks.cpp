class MyQueue {
public:
    stack<int> q;
    int size;
    
    MyQueue() {
        size = 0;   
    }
    
    void push(int x) {
        stack<int> temp;
        if(q.empty()){
            q.push(x);
            return;
        }
        
        while(q.size() != 0){
            temp.push(q.top());
            q.pop();
        }
        
        temp.push(x);
        while(temp.size() != 0){
            q.push(temp.top());
            temp.pop();
        }
        size++;
    }
    
    int pop() {
        size--;
        int val = q.top();
        q.pop();
        return val;
        
    }
    
    int peek() {
        return q.top(); 
    }
    
    bool empty() {
        return q.empty() ;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */