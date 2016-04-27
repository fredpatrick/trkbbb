#ifndef TRK_SWITCHSENSOR_HH
#define TRK_SWITCHSENSOR_HH

#include "InputSensor.h"
#include "GPIO.h"
#include "GPIOConfig.h"

namespace trk {

class Switch;

class SwitchSensor : public InputSensor
{
    public:
        SwitchSensor( int sw_num,  const SW_DIRECTION& sw_direc, int sensor_fd);
        ~SwitchSensor();

        void event (int ierr, InputGPIO* gpio);
        int     value();
        int     count();
        timeval timeofday();

    private:
        SW_DIRECTION    sw_direc_;
        int             sw_num_;
        int             sensor_fd_;

        int             value_;
        int             count_;
        timeval         time_of_day_;
};

}

#endif
