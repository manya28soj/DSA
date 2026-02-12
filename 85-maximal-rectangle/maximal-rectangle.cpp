class Solution {
public:

    // Function to find Previous Smaller Element
    vector<int> prevSmallerElement(vector<int>& arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            while(s.top() != -1 && arr[s.top()] >= arr[i]){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    // Function to find Next Smaller Element
    vector<int> nextSmallerElement(vector<int>& arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--){
            while(s.top() != -1 && arr[s.top()] >= arr[i]){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    // Largest Rectangle in Histogram (LC 84 logic)
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next = nextSmallerElement(heights, n);
        vector<int> prev = prevSmallerElement(heights, n);

        int area = 0;

        for(int i = 0; i < n; i++){
            int height = heights[i];

            if(next[i] == -1){
                next[i] = n;
            }

            int width = next[i] - prev[i] - 1;
            int newArea = height * width;

            area = max(area, newArea);
        }

        return area;
    }

    // Main function for LC 85
    int maximalRectangle(vector<vector<char>>& matrix) {

        if(matrix.size() == 0) return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m, 0);
        int maxArea = 0;

        for(int i = 0; i < n; i++){

            // Build histogram for current row
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    heights[j] += 1;
                }
                else{
                    heights[j] = 0;
                }
            }

            // Apply histogram logic
            int area = largestRectangleArea(heights);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
