
// Number System
// Is a method to represent numeric values or quantities using different digigts  
// examples

// 1
// Decimal Number system 
// uses 0-9 and its Base is 10 (base is the number of symbols or digits a Number system uses)

// 2
// Binary Number system
// uses base 2
// it uses 1 and 0

// Decimal to Binary Conversion

// A. Division method
// 1. Divide the number by 2
// 2. Store remainder ( That will be a bit in binary number 0 or 1)
// 3. Repeat above steps with the quotient until quotient is less than 2 
// 4. Reverse the bits obtained.

// B. Bitwise Method
// 1. Obtain bit with bitwise AND operation i.e, (N & 1)
// 2. Right Shift N by 1 (N = N >> 1)
// 3. Repeat above steps till N > 0.
// 4. Reverse the bits obtained.

// Binary to decimal conversion

// 1. Multiply each digit with its place value 
// 2. add up all place values 
// 3. sum is the decimal number
// place value example 

// In decimal place value 
// 123 ->
// 1 = 100 = 1 * 10 pow 2
// 2 = 20 = 2 * 10 pow 1
// 3 = 3 = 3 * 10 pow 0      Note 10 pow 0 is always 1 anything to power 0 is always 1
// Adding all give 100 + 20 + 3 = 123

// In binary place value
// 1010 -> 
// 1 = 1 * 2 pow 3
// 0 = 0 * 2 pow 2
// 1 = 1 * 2 pow 1
// 0 = 0 * 2 pow 0
// adding all values 8 + 0 + 2 + 0 = 10
// digit * (base pow i)


