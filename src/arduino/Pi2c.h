#include "Arduino.h"

typedef void (*funcPointer)(int);

extern void initPi2c(int address);
extern void addReqFunc(funcPointer Func);
extern void sendFloat(float val, int decimalPlaces);
extern void sendInt(int val);
extern void sendString(String val);
