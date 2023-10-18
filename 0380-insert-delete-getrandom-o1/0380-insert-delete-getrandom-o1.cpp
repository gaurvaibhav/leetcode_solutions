#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class RandomizedSet
{
private:
    vector<int> arr;
    unordered_map<int, int> mp;
public:
    RandomizedSet()
    {
        arr = vector<int>();
        mp = unordered_map<int, int>();
    }
    
    bool insert(int val)
    {
        FASTIO;
        if(mp.find(val) != mp.end()) return false;
        else 
        {
            arr.push_back(val);
            mp[val] = arr.size() - 1;
            return true;
        }
    }
    
    bool remove(int val)
    {
        FASTIO;
        if(mp.find(val) == mp.end())
        {
            return false;
        }
        else 
        {
            arr[mp[val]] = arr.back();
            mp[arr.back()] = mp[val];
            arr.pop_back();
            mp.erase(val);
            return true;
        } 
    }
    
    int getRandom()
    {
        FASTIO;
        return arr[rand() % arr.size()];
    }
};