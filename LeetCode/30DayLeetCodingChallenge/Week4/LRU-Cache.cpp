// Problem link : https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3309/
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class LRUCache {
private :
    int capacity;
    unordered_map<int,int> cache ;
    unordered_map<int,int> count_in_queue ;
    queue<int> least_used;
    void add_to_queue(int key) {
        least_used.push(key) ;
        count_in_queue[key]++;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity ;
    }

    int get(int key) {
        auto it = cache.find(key) ;
        if ( it == cache.end()) {
            return -1 ;
        }
        add_to_queue(key);
        return it->second ;
    }

    void put(int key, int value) {

        if ((int) cache.size() < this->capacity) {
            cache[key] = value ;
            add_to_queue(key);
            return ;
        }
        auto it = cache.find(key) ;
        if ( it != cache.end()) {
            it->second = value ; // updating value which is already exists
            add_to_queue(key) ;
            return ;
        }

        while(true) {
            int front_q_val = least_used.front() ;
            least_used.pop();
            if (--count_in_queue[front_q_val] == 0) {
                count_in_queue.erase(front_q_val);
                cache.erase(front_q_val) ;
                break;
            }
        }
        cache[key] = value ;
        add_to_queue(key);
    }
};
