#ifndef JOYSTICK_H
#define JOYSTICK_H
#include <Arduino.h>
#include "./utils/joy_attibute.h"

typedef std::function<void()> onLeft;
typedef std::function<void()> onRight;
typedef std::function<void()> onUp;
typedef std::function<void()> onDown;
typedef std::function<void(boolean state)> onSW;

typedef std::function<void()> onUpLeft;
typedef std::function<void()> onDownLeft;
typedef std::function<void()> onUpRight;
typedef std::function<void()> onDownRight;

struct POSITION{
    int x;
    int y;
};
struct DIRECTION{
    String dir = "None";
    String last_dir = "None";
};
class Joystick
{
    private:
        int pinX;
        int pinY;
        int pinSW;
        int lastStateSW = false;
        int currentStateSW;
        int offset_x_min;
        int offset_x_max;
        int offset_y_min;
        int offset_y_max;
        int offset_x_center;
        int offset_y_center;
        void mapping_Direction(int h, int v);
    public:
        int est_horizontal();
        int est_vertical();
        Joystick(int pinVRX = -1, int pinVRY = -1, int SW = -1);
        void offsetPosition(int x_min, int x_max, int y_min, int y_max, int x_center, int y_center);
        void begin();  

        POSITION position;
        DIRECTION direction;
        void handle();
        void onEvent_Left(onLeft funcEventLeft);
        void onEvent_Right(onRight funcEventRight);
        void onEvent_Up(onUp funcEventUp);
        void onEvent_Down(onDown funcEventDown);
        void onEvent_SW(onSW funcEventSW);

        void onEvent_UpLeft(onUpLeft funcEventUpLeft);
        void onEvent_UpRight(onUpRight funcEventUpRight);
        void onEvent_DownLeft(onDownLeft funcEventDownLeft);
        void onEvent_DonwRight(onDownRight funcEventDownRight);

        void onEvent(onLeft funcEventLeft, onRight funcEventRight, onUp funcEventUp, onDown funcEventDown, onSW funcEventSW = NULL);
    protected:
};
#endif