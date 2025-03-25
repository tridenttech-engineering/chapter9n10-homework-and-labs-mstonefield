//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <your name> on <current date>

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function prototypes
double getPayment(int, double, int);
double getTotal(double, int);

int main()
{
    int carPrice = 0;
    int rebate = 0;
    double creditRate = 0.0;
    double dealerRate = 0.0;
    int term = 0;
    double creditPayment = 0.0;
    double dealerPayment = 0.0;

    cout << "Car price (after any trade-in): ";
    cin >> carPrice;
    cout << "Rebate: ";
    cin >> rebate;
    cout << "Credit union rate: ";
    cin >> creditRate;
    cout << "Dealer rate: ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;

    int months = term * 12;

    // Calculate and round monthly payments
    creditPayment = getPayment(carPrice - rebate, creditRate / 12, months);
    dealerPayment = getPayment(carPrice, dealerRate / 12, months);

    // Calculate total payments based on rounded monthly payments
    double totalCredit = getTotal(creditPayment, months);
    double totalDealer = getTotal(dealerPayment, months);

    // Display results
    cout << fixed << setprecision(2);
    cout << "Credit union payment: $" << creditPayment << endl;
    cout << "Total credit union payment: $" << totalCredit << endl;
    cout << "Dealer payment: $" << dealerPayment << endl;
    cout << "Total dealer payment: $" << totalDealer << endl;

    return 0;
}

// Function to calculate monthly payment
double getPayment(int prin, double monthRate, int months)
{
    double denominator = 1 - pow(monthRate + 1, -months);

    if (denominator == 0)
        return -1;

    return prin * monthRate / denominator;
}

// Function to calculate total based on properly rounded monthly payment
double getTotal(double monthPay, int months)
{
    double total = 0.0;
    double roundedPay = static_cast<int>((monthPay + 0.005) * 100) / 100.0;
    total = roundedPay * months;
    return total;
}