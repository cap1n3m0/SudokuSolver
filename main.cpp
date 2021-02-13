#include <iostream> 
#include <vector> 
#include <set> 
#include <map> 

using namespace std; 

int main() {
    const int SIZE = 9; 
    vector<int> missingColumns; 
    vector<int> numsToAdd {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    set<int> possColl; 
    map<int, int> possPos; 
    int grid[SIZE][SIZE] = 
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
    for (int SEQ = 0; SEQ < SIZE; SEQ++) {
        cout << "checking " << SEQ << endl; 
        cout << "checking " << SEQ << endl; 
        cout << "checking " << SEQ << endl; 
        for (int i = 0; i < SIZE; i++) {
         int num = grid[SEQ][i]; 
          vector<int> :: iterator f = find(numsToAdd.begin(), numsToAdd.end(), num); 
        if (grid[SEQ][i] != 0) {
            if (f != numsToAdd.end()) {
                numsToAdd.erase(f); 
            }
        } else {
            missingColumns.push_back(i); 
        }
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
          for (int j = 0; j < SIZE; j++) {
            if (j == currCol) {
                for (int row = 0; row < SIZE; row++) {
                    for (int col = 0; col < SIZE; col++) {
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
    }
    return 0; 
}