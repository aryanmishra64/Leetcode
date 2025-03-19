#include <vector>
#include <string>
#include <cctype>

using namespace std;

class Spreadsheet {
private:
    vector<vector<int>> mat;
    int numRows;
    
    bool isCellReference(const string& str) {
        return isalpha(str[0]) && isdigit(str[1]);
    }
    
    int getCellValue(const string& cell) {
        char colChar = cell[0];
        int col = colChar - 'A';
        int row = stoi(cell.substr(1)) - 1;
        return mat[row][col];
    }
    
public:
    Spreadsheet(int rows) : numRows(rows), mat(rows, vector<int>(26, 0)) {}
    
    void setCell(string cell, int value) {
        char colChar = cell[0];
        int col = colChar - 'A';
        int row = stoi(cell.substr(1)) - 1;
        mat[row][col] = value;
    }
    
    void resetCell(string cell) {
        char colChar = cell[0];
        int col = colChar - 'A';
        int row = stoi(cell.substr(1)) - 1;
        mat[row][col] = 0;
    }
    
    int getValue(string formula) {
        formula = formula.substr(1); // Remove '='
        size_t plusPos = formula.find('+');
        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);
        
        int leftValue = isCellReference(left) ? getCellValue(left) : stoi(left);
        int rightValue = isCellReference(right) ? getCellValue(right) : stoi(right);
        
        return leftValue + rightValue;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */