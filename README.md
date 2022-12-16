# JoyStickModule
  this library make for using joystick module  5pin  such as gnd, 5v, vrX, vrY, sw
  test working on ESP32 only if use other board suggest offset value in function Joystick::handle()
      adjust range analogread from 0, 4096 to 0, 1024 or 0, 2048 up to you(board support)  position.x = map((aPinX), 0, 4096, -6, 6);
                                                                            position.y = map((aPinY), 0, 4096, -6, 6);

![Pinout](https://github.com/BinaryBearzz/JoyStickModule/blob/main/Images/JoyDIR.png?=250x250)
