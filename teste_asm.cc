#include <iostream>

int finc(volatile int & number) {
    // Implementar incremento atômico (ver pdf)
    register int value = 1;
    asm("lock xadd %%ebx, %%eax;" : "=a" (number) : "a" (number), "b" (value));
}

int main() {
    int number = 3;
    finc(number);
    std::cout << number;
} 