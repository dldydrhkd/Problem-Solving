class MinStack {
    int idx;
    int[] arr;


    public MinStack() {
        this.idx = -1;
        arr = new int[30001];
    }

    public void push(int val) {
        idx+=1;
        arr[idx]=val;
    }

    public void pop() {
        arr[idx] = 0;
        this.idx-=1;
    }

    public int top() {
        return arr[this.idx];
    }

    public int getMin() {
        int min_val = Integer.MAX_VALUE;
        for(int i=0; i<=idx; i++){
            min_val = Math.min(min_val, arr[i]);
        }
        return min_val;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */