#include <iostream>
#include <iomanip>
#include <cstdlib> 
using namespace std;

// function to print a number with "fieldspace" space and "precision" decimal digits

void print_real (float number, int fieldspace, int precision){
    cout << fixed << showpoint << setw(fieldspace) << setprecision(precision);
    cout << number << "\n";
}

/* template function "update_scale" with two reference variables 
 * 'm(1/2)' and default variable 'm3'. */

template <typename T>
void update_scale (T& m1, T& m2, T m3 = 10){
    
    // storing originally referenced variables
    T temp1, temp2;
    temp1 = m1; temp2 = m2;

    m1 = (temp1 + temp2) * m3;
    m2 = (temp1 - temp2) * m3;
    return ;
}

int main(void){
float a, b;
cout << "Please input two real numbers: ";
cin >> a >> b;	

// print both inputs
print_real(a, 7, 3);
print_real(b, 7, 3);

// third parameter isn't necessary since it defaults to 10
update_scale(a, b);

// print after "update_scale"
cout << "Updated values: \n";
print_real(a, 7, 3);
print_real(b, 7, 3);
}
