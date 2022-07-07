#ifndef semaphore_h
#define semaphore_h

#include "cpu.h"
#include "thread.h"
#include "traits.h"
#include "debug.h"

__BEGIN_API

class Semaphore
{
public:
    Semaphore(int v = 1);
    ~Semaphore();

    void p();
    void v();
private:
    // Atomic operations
    int finc(volatile int & number) {return CPU::finc(number)};
    int fdec(volatile int & number) {return CPU::fdec(number)};

    // Thread operations
    void sleep();
    void wakeup(Thread* wakeup_thread);
    void wakeup_all();

private:
    //DECLARAÇÃO DOS ATRIBUTOS DO SEMÁFORO
    volatile int license_num;
    //Queue Queue
};

__END_API

#endif

