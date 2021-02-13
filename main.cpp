#include <iostream> 
#include <vector> 

using namespace std; 

int main() {
    int allNums[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    vector<int> missingColumns {}; 
    vector<int> numsToAdd {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    int grid[9][9] = 
        {{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} }; 
    // loop through array
    for (int i = 0; i < 9; i++) {
        // if the array element is not 0
        if (grid[0][i] != 0) {
            int num = grid[0][i]; 
            // find if array elenment is in numsToAdd vector
            vector<int> :: iterator f = find(numsToAdd.begin(), numsToAdd.end(), num); 
            // if it is erase it and add the column number to missingColumns
            if (f != numsToAdd.end()) {
                numsToAdd.erase(f); 
                missingColumns.push_back(i); 
            }
        }
    }
    // prints out the numbers it needs to add
    for (int i : numsToAdd) {
        cout << i << endl;
    }
    cout << "Columns" << endl;
    cout << "Columns" << endl;
    cout << "Columns" << endl;
    // prints out the missing column numbers
    for (int i : missingColumns) {
        cout << i << endl;
    }
    cout << "Columns" << endl;
    cout << "Columns" << endl;
    cout << "Columns" << endl;
    // finds the location by looking at column
    return 0; 
}