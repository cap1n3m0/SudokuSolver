#include <iostream> 
#include <vector> 
#include <set> 

using namespace std; 

void columnOK() {

}

void nextColumn() {

}

int main() {
    int allNums[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    vector<int> missingColumns; 
    vector<int> numsToAdd;
    set<int> noColumn; 
    int* ptr = allNums; 
    copy(ptr, ptr + 9, back_inserter(numsToAdd)); 
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
    // loops though values it needs to add to find the right row
    for (int num : numsToAdd) {
        if (noColumn.size() > 0) {
            noColumn.clear(); 
        }
        for (int c = 0; c < missingColumns.size(); c++) {
         // loops through the missing columns
         int currCol = missingColumns[c]; 
         // sets the current column as the missing column we are checking
          for (int j = 0; j < 9; j++) {
            if (j == currCol) { // if the grid column is equal to the current column
                // loop through all the elements in this column
                for (int row = 0; row < 9; row++) {
                    for (int col = 0; col < 9; col++) {
                        if (col == currCol) {
                            // finds if num is in the column we are checking
                            if (grid[row][col] == num) {
                                noColumn.insert(col); 
                                cout << num << " is found in " << row << ", " << col << endl;  
                                // needs to check if num is in the row of each of these missing columns
                                // if num is in this row, we can't put num there so we need to check the next row
                                // if all of the rows have num, we need to check the next column
                                // once a spot has been found we need to replace the grid position with num and move onto the next number
                            }  
                        }
                    }
                }
            }
        }
        }
        for (auto i : noColumn) {
            cout << num << " cannot go in column " << i << endl; 
        }
    }
    return 0; 
}