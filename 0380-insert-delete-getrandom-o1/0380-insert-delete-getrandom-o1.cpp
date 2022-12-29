class RandomizedSet {
public:
    unordered_set<int> st;
    vector<int> v;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(st.find(val)!=st.end()){
            return false;
        }
        else{
            st.insert(val);
            v.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(st.find(val)==st.end()){
            return false;
        }
        else{
            st.erase(st.find(val));
            vector<int> temp(st.begin(),st.end());
            v=temp;
            return true;
        }    
    }
    
    int getRandom() {
        int len=st.size();
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