#include "semaphore.h"

__BEGIN_API

// Como precisamos controlar as threads que chamam o semáforo
// precisamos de uma forma de conseguir saber quem realizou a chamada
// pro semáforo


// wait
void Semaphore::p() {
    // Checar se o num de licenças é > 0, se sim decrementar com
    // fdec e continuar execução (retornar (?))
    // Se não dar sleep na thread
    if (license_num > 0) {
        fdec(license_num);
    } else {
        sleep();
    }
}

// post
void Semaphore::v() {
    // Checar se existe threads na lista de threads esperando
    // Se sim dar wake na primeira thread da fila
    // Se não incrementar o num de licenças com finc
}

int Semaphore::finc(volatile int & number) {
    // Implementar incremento atômico (ver pdf)
}

int Semaphore::fdec(volatile int & number) {
    // Implementar decremento atômico (ver pdf)
}

void Semaphore::sleep() {
    // Implementar thread sleep
    // Trocar status da thread para waiting e colocar thread na 
    // fila de threads esperando
}

void Semaphore::wakeup() {
    // Implementar thread wakeup
    // "Acordar" a thread, resumir sua execução
}

void Semaphore::wakeup_all() {
    //Implementar thread wakeup_all
    // Acordar todas as threads
}

__END_API