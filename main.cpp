class Solution {
public:
    string sortString(string s) {
        string res = "";
        int arr[26] = {0};
        int min = 26;
        int max = 0;
        int newMin = 0;
        int newMax = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            arr[s[i]-'a']++;    
            if (s[i] - 'a' < min) {
                min = s[i] - 'a';
            }
            if (s[i] - 'a' > max) {
                max = s[i] - 'a';
            }
        }
        
        bool elementFound = false;
        bool isIncreasing = true;
        
        do {
            elementFound = false;
            cout << min << " " << max << endl;
            if (isIncreasing) {
                isIncreasing = false;
                
                for (int i = min; i <= max; ++i) {
                    if (arr[i] > 0) {
                        elementFound = true;
                        res += 'a' + i;
                        arr[i]--;
                        newMax = i;
                    }
                }
                max = newMax;
            }
            else {
                isIncreasing = true;
                
                for (int i = max; i >= min; --i) {
                    if (arr[i] > 0) {
                        elementFound = true;
                        res += 'a' + i;
                        arr[i]--;
                        newMin = i;
                    }
                }
                min = newMin;
            }
        } while(elementFound);
        
        return res;
    }
};
