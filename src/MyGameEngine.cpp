#include "MyGameEngine.h"
#include <ctime>
#include <sys/time.h>


void MyGameEngine::idle(){
    struct timeval tp2;
    gettimeofday(&tp2, NULL);
    time2 = tp2.tv_sec * 1000000 + tp2.tv_usec;
    /* We use time1 and time2 to compare how many microseconds ago we last
     used act, if it's greater than 16000 microseconds (0.016 second = 1/60 second)
     we make the environment call act() on all it's  elements */
    if (time2 - time1 > 16000){
    	env->act();
        struct timeval tp1;
        gettimeofday(&tp1, NULL);
        time1 = tp1.tv_sec * 1000000 + tp1.tv_usec;
    }
}
