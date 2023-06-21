class MedianFinder {

    PriorityQueue<Integer> left;
    PriorityQueue<Integer> right;
    double leftMax, rightMin;
    public MedianFinder() {
        left = new PriorityQueue<Integer>(Collections.reverseOrder());
        right = new PriorityQueue<Integer>();
    }
    
    public void addNum(int num) {
        right.add(num);
        if(right.size() > left.size() + 1){
            left.add(right.poll());
        }
        if((left.size() > 0) && (right.peek() < left.peek())){
            right.add(left.poll());
            left.add(right.poll());
        }
    }
    
    public double findMedian() {
        if(left.size() == right.size()){
            return ((left.peek() + 0.0 + right.peek()) / 2);
        }
        return right.peek();
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
