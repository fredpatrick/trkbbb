#ifndef TRK_INPUTSENSOR_HH
#define TRK_INPUTSENSOR_HH

#include <sys/time.h>
#include <pthread.h>
#include "GPIO.h"

namespace trk {

class InputSensor
{
    public:
        InputSensor();
        ~InputSensor();

        virtual void    event(int ierr, InputGPIO* gpio) = 0;
        virtual int     value() = 0;
        virtual int     count() = 0;
        virtual double  timeofday() = 0;
    protected:
        static pthread_mutex_t write_event_;
};

}

#endif
