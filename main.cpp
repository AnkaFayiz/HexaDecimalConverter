#include <iostream>
#include <string.h>

using namespace std;

void banner(){
    cout << "\n       Menu        " <<endl; 
    cout << "1. Hex -> Decimal " <<endl;
    cout << "2. Decimal -> Hex " << endl;
    cout << "3. Exit!" <<endl;
}

void hexToDecimal(){
    char number[20];
    int base = 1, temp = 0;
    cout << "Enter the Hexa Number : ";cin.ignore(); cin.getline(number, 20);

    int len = strlen(number);

    for(int i = len - 1; i >= 0; i--){
        if(number[i] >='0' && number[i] <= '9'){
            temp += (number[i] - 48) * base;
            base = base * 16;
        }
        else if(number[i] >= 'A' && number[i] <= 'F'){
            temp += (number[i] - 55) * base;
            base = base * 16;
        }
    }
    cout << "Result : " << temp << endl;
}

void decimalToHex(){
    int num, i = 0, temp; 
    char hexa[50];

    cout << "Enter the Decimal number : "; cin >> num; 
    int n = num;

    while(n != 0){
        temp = n % 16;

        if(temp < 10){
            hexa[i] = temp + 48;
            i++;
        }
        else{
            hexa[i] = temp + 55;
            i++;
        }
        n = n / 16;
    }

    cout << "Result : ";
    for(int j = i - 1; j >= 0; j--){
        cout << hexa[j];
    }
    cout << "\n";
}

int main(){
    char ch;

    while(true){
        banner();
        cout << "Choose between 1-3 : "; cin >> ch;
        
        switch(ch){
            case '1': hexToDecimal();
                      break;
            case '2': decimalToHex();
                        break;
            default:  cout << "Thank you for using our service\n";
                      exit(0); 
                      break;
        }
    }
    
    return 0;
}
