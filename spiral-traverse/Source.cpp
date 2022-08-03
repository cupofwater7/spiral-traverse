#include <vector>
#include <iostream>

using namespace std;

void spiralfall(vector<vector<int>>& array, int startRow, int endRow, int starCol, int endCol, vector<int>& result);
vector<int> spiralTraverse(vector<vector<int>> array);

int main()
{
    vector<vector<int>> input = {
          {1, 2, 3, 4},
          {12, 13, 14, 5},
          {11, 16, 15, 6},
          {10, 9, 8, 7},
    };

    
    vector<int> result = spiralTraverse(input);

    for (int number : result)
    {
        cout << number << " ";
    }

    return 0;
}

void spiralfall(vector<vector<int>>& array, int startRow, int endRow, int starCol, int endCol, vector<int>& result)
{
    if (startRow > endRow || starCol > endCol)return;

    for (int col = starCol; col <= endCol; col++)
    {
        result.push_back(array[startRow][col]);
    }

    for (int row = startRow + 1; row <= endRow; row++)
    {
        result.push_back(array[row][endCol]);
    }

    for (int col = endCol - 1; col >= starCol; col--)
    {
        if (startRow == endRow)
            break;
        result.push_back(array[endRow][col]);
    }

    for (int row = endRow - 1; row >= startRow + 1; row--)
    {

        if (starCol == endCol)
            break;
        result.push_back(array[row][starCol]);
    }

    spiralfall(array, startRow + 1, endRow - 1, starCol + 1, endCol - 1, result);
}

vector<int> spiralTraverse(vector<vector<int>> array) {
    // Write your code here.
    if (array.size() == 0)return{};

    vector<int> result = {};

    spiralfall(array, 0, array.size() - 1, 0, array[0].size() - 1, result);

    return result;

}
