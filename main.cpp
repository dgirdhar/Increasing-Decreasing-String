class Solution {
public:
    string sortString(string s) {
        string res = "";
        int arr[26] = {0};
        
        for (int i = 0; i < s.size(); ++i) {
            arr[s[i]-'a']++;    
        }
        
        bool elementFound = false;
        bool isIncreasing = true;
        
        do {
            elementFound = false;
            
            if (isIncreasing) {
                isIncreasing = false;
                
                for (int i = 0; i < 26; ++i) {
                    if (arr[i] > 0) {
                        elementFound = true;
                        res += 'a' + i;
                        arr[i]--;
                    }
                }
            }
            else {
                isIncreasing = true;
                
                for (int i = 25; i >= 0; --i) {
                    if (arr[i] > 0) {
                        elementFound = true;
                        res += 'a' + i;
                        arr[i]--;
                    }
                }                
            }
        } while(elementFound);
        
        return res;
    }
};
