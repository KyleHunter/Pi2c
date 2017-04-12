#include "Arduino.h"
#include "pi2c.h"
#include "Wire.h"

int reqVal;
typedef void (*funcPointer)(int);
funcPointer callBackFunc;

void writeCharArray(char cArr[], int strLen) {
  for (int i = 0; i < strLen; ++i)
    Wire.write(int(cArr[i]));
}

void sendFloat(float val, int decimalPlaces)
{
  String str = String(val, decimalPlaces);
  int strLen = str.length() + 1 ;
  char cArr[strLen];
  str.toCharArray(cArr, strLen);
  writeCharArray(cArr, strLen);
}

void sendInt(int val)
{
  String str = String(val);
  int strLen = str.length() + 1 ;
  char cArr[strLen];
  str.toCharArray(cArr, strLen);
  writeCharArray(cArr, strLen);
}

void sendString(String str)
{
  int strLen = str.length() + 1 ;
  char cArr[strLen];
  str.toCharArray(cArr, strLen);
  writeCharArray(cArr, strLen);
}

void receiveData(int byteCount)
{
  while(Wire.available())
    reqVal = Wire.read();
}

void addReqFunc(funcPointer Func)
{
  callBackFunc = Func;
}

void callReqFunc()
{
  callBackFunc(reqVal);
}

void initPi2c(int address)
{
  Wire.begin(address);
  Wire.onReceive(receiveData);
  Wire.onRequest(callReqFunc);
}
