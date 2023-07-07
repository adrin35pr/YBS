#include <iostream>
#include <cmath>
using namespace std;

unsigned long sum_squared(const int line) {
    return pow(2, line - 1);
}

int main() {   
    cout << "Which row in Pascal's triangle: " << endl;
    
    int rows;
    cin >> rows;
    
    cout << "Sum: " << sum_squared(rows) << endl;
    
    cout << "Ok " << sum_squared(4) << endl;
    return 0;
}
