class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            bool alive = true;

            while (!st.empty() && asteroids[i] < 0 && st.top() > 0) {

                if (abs(asteroids[i]) > st.top()) {
                    st.pop();
                }
                else if (abs(asteroids[i]) == st.top()) {
                    st.pop();
                    alive = false;
                    break;
                }
                else {
                    alive = false;
                    break;
                }
            }

            if (alive) {
                st.push(asteroids[i]);
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};