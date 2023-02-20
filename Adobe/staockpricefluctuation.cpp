class StockPrice {
public:
    unordered_map<int, int> prices;
    multiset<int> ordered;
    int latestTime = -1;
    
    void update(int timestamp, int price) {
        if (prices.count(timestamp)) {
            ordered.erase(ordered.lower_bound(prices[timestamp]));
        }
        prices[timestamp] = price;
        ordered.insert(price);
        latestTime = max(latestTime, timestamp);
    }
    
    int current() {
        return prices[latestTime];
    }
    
    int maximum() {
		return *rbegin(ordered);
    }
    
    int minimum() {return *begin(ordered);}
    
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */