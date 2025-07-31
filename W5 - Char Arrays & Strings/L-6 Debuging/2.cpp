// 2. Debug the code. Integer to Romans. 1 ≤ n ≤ 2000.

#include<iostream>
using namespace std; 

string intToRoman(int num)
{
    string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string hrns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string ths[] = {"", "M", "MM"};

    return ths[num / 1000] + hrns[(num % 1000) % 100] + tens[(num % 100) % 10] + ones[num % 10];
}

// ans 
string intToRoman1(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[] = {"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }

int main() 
{ 
    int num;
    cout << "Enter Number: " << endl; 
    cin >> num;

    string ans = intToRoman(num);
    cout<< "Converted Roman From Integer Is: " << ans << endl;

    return 0; 
}