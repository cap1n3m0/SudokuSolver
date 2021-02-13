#include <iostream> 
#include <vector> 
#include <set> 

using namespace std; 

int main() {
    int allNums[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    vector<int> missingColumns; 
    vector<int> numsToAdd;
    set<int> possColl; 
    int* ptr = allNums; 
    copy(ptr, ptr + 9, back_inserter(numsToAdd)); 
    int grid[9][9] = 
    //    0  1  2  3  4  5  6  7  8
        {{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} }; 
    // loop through row 0 of array
    for (int i = 0; i < 9; i++) {
         int num = grid[0][i]; 
          vector<int> :: iterator f = find(numsToAdd.begin(), numsToAdd.end(), num); 
        // if the array element is not 0
        if (grid[0][i] != 0) {
            // find if array elenment is in numsToAdd vector
            // if it is erase it and add the column number to missingColumns
            if (f != numsToAdd.end()) {
                numsToAdd.erase(f); 
            }
        } else {
            missingColumns.push_back(i); 
        }
    }
    // prints out the numbers it needs to add and the columns
    cout << "Values that need to be added: " << endl; 
    for (auto i : numsToAdd) {
        cout << i << endl; 
    }
    cout << "Available columns: " << endl; 
    for (auto i : missingColumns) {
        cout << i << endl; 
    }
    vector<int> :: iterator i = missingColumns.begin(); 
    // loops though values it needs to add to find the right row
    for (int num : numsToAdd) {
        if (possColl.size() > 0) {
            possColl.clear(); 
        }
        copy(missingColumns.begin(), missingColumns.end(), inserter(possColl, possColl.begin())); 
        for (int c = 0; c < missingColumns.size(); c++) {
         int currCol = missingColumns[c]; 
          for (int j = 0; j < 9; j++) {
            if (j == currCol) {
                for (int row = 0; row < 9; row++) {
                    for (int col = 0; col < 9; col++) {
                        if (col == currCol) {
                            if (grid[row][col] == num) {
                                if (find(possColl.begin(), possColl.end(), col) != possColl.end()) {
                                    possColl.erase(col); 
                                }
                            } 
                        } 
                    }
                }
            }
        }
        }
        // found possibler locations. need to filter. 
        for (auto i : possColl) {
            cout << num << " Can go in column " << i << endl; 
        }
    }
    return 0; 
}