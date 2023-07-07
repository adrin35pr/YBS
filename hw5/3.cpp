#include <iostream>
using namespace std;

struct STUDENT{
    string NAME;
    int GROUP;
    int SES[5];
};



int main(){

    STUDENT STDU1[] = { {"Billy Herrington", 5, {12, 12, 12, 12, 12} }, {"Van Darkholm", 5, {1, 1, 1, 1, 1} }, {"Gordon Freeman", 3, {1, 2, 4, 5, 6}}, {"Cave Johnson", 3, {8, 6, 12, 11, 9} }, {"Vincent Vega", 1, {3, 4, 4, 4, 2 } }, };

    

    for (int i = 0; i < 5; i++) {
        cout << "Name: " << STDU1[i].NAME << endl;
        cout << "Group: " << STDU1[i].GROUP << endl;
        cout << "SES: ";
        for (int j = 0; j < 5; j++) {
            cout << STDU1[i].SES[j] << " ";
        }
        cout << endl << endl;
    }

    // int a = 0;
    // cin >> a;
    // cout << STUD1[a].NAME << endl;
    // cout << STUD1[a].GROUP << end;
    return 0;
}