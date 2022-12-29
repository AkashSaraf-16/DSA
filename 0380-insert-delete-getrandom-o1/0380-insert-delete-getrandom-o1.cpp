class RandomizedSet {
public:
    unordered_map<int,int> mp; // store val,index in vector
    vector<int> v;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        else{
            v.push_back(val);
            int idx=v.size()-1;
            mp.insert({val,idx});
            return true;
        }
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return false;
        }
        else{
            auto it=mp.find(val);       // get the idx to be removed
            v[it->second]=v.back();
            v.pop_back();
            mp[v[it->second]]=it->second;  // update the map
            mp.erase(val);
            return true;
        }    
    }
    
    int getRandom() {
        int len=mp.size();
        int idx=rand()%len;
        return v[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */