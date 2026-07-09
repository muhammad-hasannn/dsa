#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> a){
    vector<int> ans;

    int m = a.size();
    int n = a[0].size();

    int right = n-1;
    int bottom = m-1;
    int left = 0;
    int up = 0;

    while(up <= bottom && right >= left){
        // left ---> right
        for(int i = left; i <= right; i++){
        //           ^from where we are starting  

            ans.push_back(a[up][i]);
            //                        ^on which line we are moving
        }
        up++; // becuase we have moved in this line

        // up ---> bottom
        for(int i = up; i <= bottom; i++){
            ans.push_back(a[i][right]);
        }
        right--;

        // right ---> left
        if(up <= bottom){
            for(int i = right; i >= left; i--){
                ans.push_back(a[bottom][i]);
            }
            bottom--;
        }

        // bottom ---> up
        if(left <= right){
            for(int i = bottom; i >= up; i--){
                ans.push_back(a[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {
        {1,  2, 3, 4},
        {5,  6, 7, 8},
        {9, 10,11,12},
        {13,14,15,16}
    };

    vector<int> result = spiralOrder(matrix);

    cout << "Spiral Order: ";

    for(int i = 0; i < result.size(); i++) cout << result[i] << " ";
    cout << "\n";
}