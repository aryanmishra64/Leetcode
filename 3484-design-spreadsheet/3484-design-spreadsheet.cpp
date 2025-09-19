class Spreadsheet {
public:
    vector<vector<int>>sheet;
    Spreadsheet(int rows) {
        sheet = vector<vector<int>>(rows, vector<int>(26, 0));

    }
    
      void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;

        sheet[row][col] = value;

    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        sheet[row][col] = 0;
    }
    
    int getValue(string formula) {
    int n = formula.length();
    int ind = -1;

    for (int i = 0; i < n; i++) {
        if (formula[i] == '+') {
            ind = i;
            break;
        }
    }

    string left = formula.substr(1, ind - 1);  // exclude '=' and '+'
    string right = formula.substr(ind + 1);

    int leftval = 0, rightval = 0;

    // left operand
    if (isdigit(left[0])) {
        leftval = stoi(left);
    } else {
        int col = left[0] - 'A';
        int row = stoi(left.substr(1)) - 1;
        leftval = sheet[row][col];
    }

    // right operand
    if (isdigit(right[0])) {
        rightval = stoi(right);
    } else {
        int col = right[0] - 'A';
        int row = stoi(right.substr(1)) - 1;
        rightval = sheet[row][col];
    }

    return leftval + rightval;
}

};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */