// Solution to assignment 6
// @author: Mark Freeman

#include<iostream>
using namespace std;

void printGreeting() {
    cout << "Hope you're having a good day!" << endl;
}

void divideNumbers(float x, float y) {
    if(y == 0)
        cout << "Cannot perform division" << endl;
    else {
        cout << x / y << endl;
    }
}

int factorial(int num) {
    if(num < 0)
        return 0;
    else {
        int total = num;
        while(num > 2) { // last in will be 3, so last multiply will be by 2
            num--;
            total *= num;
        }
        return total;
    }
}

//be warned, this may not work on versions of C++
void fibonacci(int N) {

    int arr[N];
    arr[0] = 0;
    arr[1] = 1;

    // easiest to follow approach, but this can also be done on the fly
    for(int i = 2; i < N; i++) { // Nth fibonacci number is at index N - 1
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    // now the array has all of the values, just iterate over and print them
    for(int i = 0; i < N; i++) {
        if(i == N - 1)
            cout << arr[i] << endl;
        else
            cout << arr[i] << ", ";
    }
}

void fibonacci_three_var(int N) {

    if(N > 0) //start the print
        cout << "0";
    if(N > 1) //append the first special case
        cout << ", 1";
    if(N > 2) {
        int left = 0;
        int right = 1;
        int res;
        for(int i = 2; i < N; i++) {
            res = left + right;
            cout << ", " << res;
            left = right;
            right = res;
        }
    }
    cout << endl;
}

int main() {

    cout << "printGreeting(): "; //voids have to get called like this because of operand typing with <<
    printGreeting();

    cout << "divideNumbers(5, 4): ";
    divideNumbers(5, 4);

    cout << "divideNumbers(5, 0): ";
    divideNumbers(5, 0);

    cout << "factorial(10): " << factorial(10) << endl; //returns, does not print, so we must add 'endl'
    cout << "factorial(-1): " << factorial(-1) << endl;

    cout << "fibonacci(10): ";
    fibonacci(10);

    cout << "fibonacci_three_var(10): ";
    fibonacci_three_var(10);
}