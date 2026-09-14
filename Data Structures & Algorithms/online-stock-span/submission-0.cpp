class StockSpanner {
public:
    StockSpanner() = default;
    
    int next(int price) {
        int span = 1;
        while (!stk_.empty() && stk_.top().first <= price)
        {
            span += stk_.top().second;
            stk_.pop();
        }

        stk_.push({price, span});
        return span;
    }
private:
    std::stack<std::pair<int, int>> stk_;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */