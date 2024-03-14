#ifndef FACTORIAL_H
#define FACTORIAL_H

unsigned int Factorial(unsigned int number) {
    return number > 1 ? Factorial(number-1)*number : 1;
}

#endif  // FACTORIAL_H