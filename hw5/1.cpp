#include <iostream>

int opposite_number(const int n, const int number) {
    int opposite = (number + n/2) % n;
    return opposite;
}

int main() {
    int n, number;
    std::cout << "Numbers on circle: ";
    std::cin >> n;
    std::cout << "Number which needs to oposite: ";
    std::cin >> number;

    int opposite = opposite_number(n, number);
    std::cout << "Oposite number: " << opposite << std::endl;

    return 0;
}
