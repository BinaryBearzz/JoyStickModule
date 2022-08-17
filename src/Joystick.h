#ifndef JOYSTICK_H
#define JOYSTICK_H
#include <Arduino.h>
#include "./utils/joy_attibute.h"

struct POSITION{
    int x;
    int y;
};
struct DIRECTION{
    int horizontal;
    int vertical;
};
class Joystick
{
    private:
        int pinX;
        int pinY;
        int pinSW;
        int offset_x_min;
        int offset_x_max;
        int offset_y_min;
        int offset_y_max;
        int offset_x_center;
        int offset_y_center;
        int est_horizontal();
        int est_vertical();
    public:
        Joystick(int pinVRX = -1, int pinVRY = -1, int SW = -1);
        void offsetPosition(int x_min, int x_max, int y_min, int y_max, int x_center, int y_center);
        void begin();  
        POSITION position;
        DIRECTION direction;
        void handle();
    protected:
};
#endif