/* 
When doing integer math, sometimes you want a function 
to return two values. Although the better way to 
handle this is with a tuple, we aren't teaching you 
about those yet. So instead I want you to write a 
function that returns one value the normal way, and
uses a non-const reference as a kind of second 
return value.

Write a function named 
"division_with_remainder" that takes two 
ints (a numerator and denominator) and returns 
the results of division. Its third argument is a
non-const reference to int that should be 
modified to hold the remainder of the division.
*/

#include <iostream>
using std::cin; using std::cout;

double division_with_remainder(int numerator, int denominator, 
                               int &rem){
    rem = numerator % denominator;
    return numerator / denominator;
}
