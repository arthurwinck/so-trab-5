#include "semaphore.h"
#include "thread.h"

__BEGIN_API    

void Semaphore::p() {
    //begin_atomic();
    if (fdec(license_num) < 1) {
        sleep();
    //} else {
        //end_atomic();
    }

    //begin_atomic();
    /// if(fdec(_value) < 1) {
        //sleep
    //} else {
        //end_atomic();
    //}


}

// post
void Semaphore::v() {
    //being_atomic();
    if(finc(license_num) < 0) {
        wakeup(); //implicit end_atomic;
    //else {
        //end_atomic();
    }
    
    /* 
    being_atomic();
    if(finc(_value)) < 0) {
        wakeup(); //implicit end_atomic;
    else
        end_atomic();
    }
    
    */

}

void Semaphore::sleep() {
    Thread::sleep(&this->_wait);
}

void Semaphore::wakeup() {
    Thread::wakeup(&this->_wait);
}

void Semaphore::wakeup_all() {
    Thread::wakeup_all(&this->_wait);
}

Semaphore::Semaphore(int v){
    license_num = v;
}

Semaphore::~Semaphore() {
    Thread::wakeup_all(&this->_wait);
}


// void Thread::reschedule() {
//     yield();
// }
__END_API