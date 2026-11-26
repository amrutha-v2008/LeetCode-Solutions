
class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        bool alice = true;

        while (n >= stones) {
            n -= stones;
            stones--;
            alice = !alice;
        }

        return !alice;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna