#include <Arduino.h>
#include <Joystick.h>

Joystick::Joystick(int pinVRX, int pinVRY, int SW)
{
    pinX = pinVRX;
    pinY = pinVRY;
    pinSW = SW;
    offset_x_min;
    offset_x_max;
    offset_y_min;
    offset_y_max;
    offset_x_center;
    offset_y_center;
} 

void Joystick::offsetPosition(int x_min, int x_max, int y_min, int y_max, int x_center, int y_center)
{
    offset_x_min = x_min;
    offset_x_max = x_max;
    offset_y_min = y_min;
    offset_y_max = y_max;
    offset_x_center = x_center;
    offset_y_center = y_center;
}

void Joystick::begin()
{
    if(pinX > 0)
    {
        pinMode(pinX, INPUT);
        Serial.println("# Set pinX: "+String(pinX));
    }
    if(pinY > 0)
    {
        pinMode(pinY, INPUT);
        Serial.println("# Set pinY: "+String(pinY));
    }
    if(pinSW > 0)
    {
        pinMode(pinSW, INPUT);
        Serial.println("# Set pinSW: "+String(pinSW));
    }

}

int Joystick::est_horizontal()
{
    
}

int Joystick::est_vertical()
{

}

void Joystick::handle()
{
    position.x = map((analogRead(pinX)/4), 0, 1024, 0, 10);
    position.y = map((analogRead(pinY)/4), 0, 1024, 0, 10);
}
