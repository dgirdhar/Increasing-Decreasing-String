class Solution {
public:
    string sortString(string s) {
        string res = "";
        int arr[26] = {0};
        int min = 26;
        int max = 0;
        int newMin = 0;
        int newMax = 0;
        int size = s.size();
        int newSize = 0;
        
        for (int i = 0; i < size; ++i) {
            arr[s[i]-'a']++;    
            if (s[i] - 'a' < min) {
                min = s[i] - 'a';
            }
            if (s[i] - 'a' > max) {
                max = s[i] - 'a';
            }
        }
        
        do {
            if (size == newSize) {
                break;
            }
                
            for (int i = min; i <= max; ++i) {
                if (arr[i]-- > 0) {
                    res += 'a' + i;
                    newMax = i;
                    newSize++;
                }
            }
            max = newMax;
            if (size == newSize) {
                break;
            }
            
            for (int i = max; i >= min; --i) {
                if (arr[i]-- > 0) {
                    res += 'a' + i;
                    newMin = i;
                    newSize++;
                }
            }            
            min = newMin;
        } while(true);
        
        return res;
    }
};
