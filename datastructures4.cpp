#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i <= heights.size();) {
        int h = (i == heights.size() ? 0 : heights[i]);

        if (st.empty() || h >= heights[st.top()]) {
            st.push(i);
            i++;
        } else {
            int top = st.top();
            st.pop();

            int area = heights[top] * (st.empty() ? i : i - st.top() - 1);
            maxArea = max(maxArea, area);
        }
    }

    return maxArea;
}

int largestRectangleMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();

    if (rows == 0) {
        return 0;
    }

    int cols = matrix[0].size();
    vector<int> heights(cols, 0);
    int maxArea = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                heights[j] = 0;
            } else {
                heights[j]++;
            }
        }

        maxArea = max(maxArea, largestRectangleArea(heights));
    }

    return maxArea;
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter the elements of the matrix (0 or 1): " << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int maxRectangleArea = largestRectangleMatrix(matrix);
    cout << "The area of the largest rectangle in the matrix is: " << maxRectangleArea << endl;

    return 0;
}