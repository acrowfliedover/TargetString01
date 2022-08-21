// TargetString01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

//given length n, calculate the number of strings using only 0 and 1 of given length
//that satisfies all 0s have a 1 on the left of it.
//in other words, it can't have a leading 0, it can't have two consectutive 0s.
//in a sense, for any number n with f(n) many such strings, f(n+1)=f(n ending in 0)+2* f(n ending in 1)
int TargetString01(int n);
double FastPower(double base, int power);
bool CheckIfInteger(std::string test);
int ConvertToInteger(std::string str);
int main()
{
    std::string str;
    std::cin >> str;
    std::cout << ConvertToInteger(str) << "\n";
   // int a[2][2] = { {1,1},{1,0} };
}

//an really easy way to do Fib
int TargetString01(int n) {
    int a = 0;
    int b = 1;
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            a += b;
        }
        else {
            b += a;
        }
    }
    return a + b;
}

double FastPower(double base, int power) {
    double result = 1;
    double newbase = base;
    int newpower = power;
    for (int i = 2; i / 2 < power; i *= 2) {
        if (newpower % i != 0) {
            result *= newbase;
            newpower -= i / 2;
        }
        newbase *= newbase;
    }
    return result;
}

//integers contain only "-" or number digits;
//if start with zero, nothing falls behind
//can only start with -, and only follows by a non zero number
//leading digit can't be zero
bool CheckIfInteger(std::string test) {
    if (test[0] != '-' && (test[0] < '0' || test[0]>'9')) {
        return false;
    }
    else if(test[0]=='-' && (test.length()==1||test[1]=='0')) {
       return false;
    }
    else if (test[0] == '0' && test.length() > 1) {
        return false;    for (int i = 1; i < test.length(); i++) {
            if (test[i] < '0' || test[i]>'9') {
                return false;
            }
        }
    }
    return true;
}

int ConvertToInteger(std::string str) {
    if (str == "") {
        return NULL;
    }
    if (!CheckIfInteger(str)){
        throw std::invalid_argument("not an integer");
    }
    bool neg = (str[0] == '-');
    const int minq = INT_MIN / 10;
    const int minr = INT_MIN % 10;
    int res = 0;
    int cur = 0;
    for (int i = neg ? 1 : 0; i < str.length(); i++) {
        cur = '0' - str[i];
        if ((res < minq) || res == minq && cur < minr) {
            throw std::out_of_range("out of range");
        }
        res = res * 10 + cur;
    }
    if (!neg && res == INT_MIN) {
        throw std::out_of_range("out of range");
    }
    return neg ? res : -res;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
