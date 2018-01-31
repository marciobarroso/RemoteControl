/*
 * Library to use easily a remote controll with arduino
 * Created by Marcio A. Barroso, January 30th 2018
 * Released into the public domain.
 */

#include <StandardCplusplus.h>
#include <vector>
#include <Arduino.h>

using namespace std;

#ifndef RemoteControl_h
#define RemoteControl_h

class RemoteControlChannel {

    int _number;
    int _pin;
    int _maxPulse = 1890;
    int _minPulse = 1093;

    public:
        RemoteControlChannel(int channel, int pin);
        int getChannel();
        int getPin();
        int getPulse();
        int getDegrees(int limit);
        int getPWM();

};

class RemoteControl {

    std::vector<RemoteControlChannel> data;

    public:
        void bind(int channel, int pin);
        void bind(int channel, int pin, int minPulse, int maxPulse);
        std::vector<RemoteControlChannel> getData();
        int getChannelCount();
        RemoteControlChannel getChannel(int channel);

};

#endif
