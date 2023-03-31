# CSCI 240
# Data Structures and Algorithms
## Lab Exam 1
### 2022-09-20

## The ADT
A bit bucket is an ordered collection of bits that allows the client to set, unset, retrieve a bit, and clear all bits with a single instruction. Think of it as an array of bits.
??If this is an array of bits, where and when do I populate it?? Oh no wait, if you pass in a number, it will be represented as bits right? so if I just use bitwise operators with the bitMask array I created, it should work on that number.

Note: for the remainder of this document:
    Set: meand to set a bit's value to 1
    Unset: means to set a bit's value to 0

BitBucket ADT: 
- Set: Takes as input the position of a bit in the bucket and sets it
- Unset: takes as input the position of a bit in the bucket and unsets it
- At: takes as input a bucket position and returns true if set or false otherwise.
- Clear: unsets all bits in the bucket

## Implementation notes
The actual data is stored in an array of bytes (unsigned chars). This array should be dynamically allocated at instantiation but it does not resize. Once instantiated, the bucket's size never changes.

You should use bitwise operators to set, unset, and retrieve the value of the requested bit. 
??Am I supposed to 

### Bitwise shift operations will perform multiplication and division. 
- A left shift will multiply a value. ("<<" operator)
- A right shift will divide a value   (">>" operator)
For example, assume a variable called "val" is an integer type. If you shift the value left by n bits you will multiply it by $2^n$. If you shift it right by 2 bits you will divide it by $2^n$.

The "~" operator compliments a value (flips the bits.)

You can return a specific bit in a byte by shifting a single bit into the proper position then performing a bitwise AND ("&"). 
Example: return val & (1 << 3); // shift the least significan bit (LSB) of the value 1 to the left by 3 places then AND that with val. this will return the $4^{th}$ LSB of val.

You can set a bit in a certain position of val by using a bitwise OR. Assume the variable "pos" holds the position of the bit to be set. val = val | (1 << pos); will set the bit at position pos.

So, how does one unset a bit? This is where the bitwise compliment and bitwise AND operator come into play.
the following statement will unset a bit at position pos in the variable val: val = val & ~(1 << pos);. The part of the expression to the right of the AND operator sets all bits except the bit at position pos. AND'ing this with val will unset a bit in the same position. 

The value 1 shifted to a certain position then used in the method shown above is called a "mask".

As you can see, using these bitwise operators negates the need of expensive operations like multiplication, division, and modulo.

It also provides for efficient use of memory. there is not built-in way to address a single bit in memory. We can implement a way though. 

## Requirements
- You must write the BitBucket class using two files, a header file for declaration (provided), and a cpp file for definition. 
- Write a test program call test_bit_bucket.cpp and should function as demonstrated in class.
- Do not modify the bit_bucket.h file that I provided. If you do, your code will not compile or run when I test it.

## Grading Rubric
Code quality:   15%
Correctness:    30% (program functions correctly)
Optimality:     20% 
Test program:   15%

If your program doesn't compile then I cannot grade it so you will receive a zero.

