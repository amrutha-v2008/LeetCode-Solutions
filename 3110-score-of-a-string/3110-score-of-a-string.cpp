class Solution {
public:
    int scoreOfString(string s) {
      int score=0;
      for(int i=0;i<s.length()-1;++i){
        score+=abs(s[i]-s[i+1]);
      }  
      return score;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna