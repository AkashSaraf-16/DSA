#define mis map<int,string>
class TimeMap {
public:
    unordered_map<string,mis> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end())
            return "";
        // upper_bound: it returns the iterator just greater than the value provided
        auto upper_it=mp[key].upper_bound(timestamp);
        if(upper_it==mp[key].begin())   // this means we are searching for timestamp which is smallest hence returning ""
            return "";
        return prev(upper_it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */