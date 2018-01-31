/*
 * Library to use easily a remote controll with arduino
 * Created by Marcio A. Barroso, January 30th 2018
 * Released into the public domain.
 */

#include <StandardCplusplus.h>
#include <vector>

using namespace std;

#ifndef RemoteControl_h
#define RemoteControl_h

struct CHANNEL {
  int number;
  int pin;
  int value;
};

class RemoteControl {

  std::vector<CHANNEL> data;

  public:
    void bind(int channel, int pin);
    std::vector<CHANNEL> getData();

  private:
    int convertPulseToPWM(int pulse);
};

#endif
