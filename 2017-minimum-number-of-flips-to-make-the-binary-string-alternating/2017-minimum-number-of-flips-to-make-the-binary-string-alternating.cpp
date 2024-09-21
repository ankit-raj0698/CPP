class Solution {
public:
    int minFlips(string s) {

        int k = s.size();
        string a = s + s; // Double the string to handle rotations

        // Create alternating patterns: "010101..." and "101010..."
        string b = "", c = "";
        for (int i = 0; i < a.size(); i++) {
            b += (i % 2 == 0) ? '0' : '1';  // Pattern 1: Starts with '0'
            c += (i % 2 == 0) ? '1' : '0';  // Pattern 2: Starts with '1'
        }

        int left = 0, right = 0, cnt = 0, ans1 = INT_MAX;
        // Check for Pattern 1 i.e string b
        while (right < 2 * k) {
            if (a[right] != b[right])
                cnt++;  // Count mismatch for Pattern 1
            
            if (right - left + 1 > k) {
                if (a[left] != b[left])
                    cnt--;  // Remove left-most mismatch when window moves
                left++;
            }

            if (right - left + 1 == k)
                ans1 = min(ans1, cnt);  // Update minimum flips for Pattern 1

            right++;
        }

        // Reset for Pattern 2 i.e.. string c
        left = 0, right = 0, cnt = 0;
        int ans2 = INT_MAX;
        while (right < 2 * k) {
            if (a[right] != c[right])
                cnt++;  // Count mismatch for Pattern 2
            
            if (right - left + 1 > k) {
                if (a[left] != c[left])
                    cnt--;  // Remove left-most mismatch when window moves
                left++;
            }

            if (right - left + 1 == k)
                ans2 = min(ans2, cnt);  // Update minimum flips for Pattern 2
            right++;
        }

        return min(ans1, ans2);  // Return the minimum flips between the two patterns
    }
};