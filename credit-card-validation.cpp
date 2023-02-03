#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;
int getDigit(const int number);
int sumOddDigits(const string cardNumber);
int sumEvenDigits(const string cardNumber);
int main(){
    string cardNumber;
    char yON;
    int result = 0;
    do{
    cout << "Enter a credit card number: ";
    cin >> cardNumber;
    result = sumEvenDigits(cardNumber) + sumOddDigits(cardNumber);
    if(result % 10 == 0){
        cout << cardNumber << " is valid\n";
    }
    else{
        cout << cardNumber << " is not valid\n";
    }
    cout << "Do you want To quit Type Y or y to quit or N or n to continue? ";
    cin >> yON;
    }while(yON == 'N' || yON == 'n');
    return 0;
}
int getDigit(const int number){
    return number % 10 + (number / 10 % 10);
}
int sumOddDigits(const string cardNumber){
    int sum = 0;
    for(int i = cardNumber.size() - 1; i >= 0; i-=2){
        sum += cardNumber[i] - '0';
    }
    return sum;
}
int sumEvenDigits(const string cardNumber){
    int sum = 0;
    for(int i = cardNumber.size() - 2; i >= 0; i-=2){
        sum += getDigit((cardNumber[i] - '0') * 2);
    }
    return sum;
}
