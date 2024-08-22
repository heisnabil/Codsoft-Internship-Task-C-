#include <iostream>
using namespace std;

void greet() {
    cout << "\n\nHello! Welcome to your friendly calculator buddy!" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Let's solve some math problems together!" << endl;
}

void showOptions() {
    cout << "\nWhat would you like to do today?" << endl;
    cout << "1. Add two numbers" << endl;
    cout << "2. Subtract one number from another" << endl;
    cout << "3. Multiply two numbers" << endl;
    cout << "4. Divide one number by another" << endl;
    cout << "5. Exit the calculator" << endl;
    cout << "Please enter the number of your choice: ";
}

void Goodbye() {
    cout << "Thanks for Using Calculator" << endl;
}

int main() {
    int choice;
    double num1, num2;

    greet();

    do {
        showOptions();
        cin >> choice;

        if (choice == 5) {
            Goodbye();
            break;
        } else if (choice < 1 || choice > 5) {
            cout << "That's not a valid option. Please try again." << endl;
            continue;
        }

        cout << "Nice! Enter the first number: ";
        cin >> num1;
        cout << "Now, enter the second number: ";
        cin >> num2;

        switch (choice) {
            case 1:
                cout << "Adding gives: " << num1 + num2 << endl;
                break;
            case 2:
                cout << "Subtracting gives: " << num1 - num2 << endl;
                break;
            case 3:
                cout << "Multiplying gives: " << num1 * num2 << endl;
                break;
            case 4:
                if (num2 != 0) {
                    cout << "Dividing gives: " << num1 / num2 << endl;
                } else {
                    cout << "Oops! Division by zero is not allowed." << endl;
                }
                break;
        }

    } while (true);

    return 0;
}
