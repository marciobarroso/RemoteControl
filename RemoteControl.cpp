/*
 * Library to use easily a remote controll with arduino
 * Created by Marcio A. Barroso, January 30th 2018
 * Released into the public domain.
 */

#include <arduino.h>
#include <RemoteControl.h>

/*
 * Constructor
 */
RemoteControlChannel::RemoteControlChannel(int channel, int pin) {
    _number = channel;
    _pin = pin;
};

/*
 * Get the channel number
 */
int RemoteControlChannel::getChannel() {
    return _number;
};

/*
 * Get pin number
 */
int RemoteControlChannel::getPin() {
    return _pin;
};

/*
 * Read the pulse and adjust the maxPulse and minPulse
 */
int RemoteControlChannel::getPulse() {
    int pulse = pulseIn(_pin, HIGH, 25000);
    if( pulse > _maxPulse ) {
        _maxPulse = pulse;
    } else if( pulse < _minPulse ) {
        _minPulse = pulse;
    }
    return pulse;
};

/*
 * Calculate the PWM using the pulse
 */
int RemoteControlChannel::getPWM() {
    int precision = 16;
    int pulse = getPulse();
    int pwm = 0;

    if(pulse > 1000) {
      pwm = map(pulse, _minPulse, _maxPulse, -500, 500);
      pwm = constrain(pwm, -255, 255);
    }

    if( abs(pwm) <= precision ) {
      pwm = 0;
    }

    return pwm;
};

/*
 * Calculate the degrees for servo motors
 */
int RemoteControlChannel::getDegrees(int limit) {
    int precision = 5;
    int precisionUp = (limit/2) + precision;
    int precisionDown = (limit/2) - precision;
    int pulse = getPulse();
    int degrees = 0;

    if(pulse > 1000) {
      degrees = map(pulse, _minPulse, _maxPulse, 0, limit);
    }

    if( degrees >= precisionDown && degrees <= precisionUp ) {
      degrees = limit/2;
    }

    return degrees;
};

/*
 * Bind a channel to a pin
 */
void RemoteControl::bind(int channel, int pin) {
    Serial.print("Binding channel ");
    Serial.print(channel);
    Serial.print(" on pin ");
    Serial.println(pin);
    RemoteControlChannel rcc(channel, pin);
    data.push_back(rcc);
};

/*
 * Get the total of binded channels
 */
int RemoteControl::getChannelCount() {
    return data.size();
}

/*
 * Get the channel by vector index
 */
RemoteControlChannel RemoteControl::getChannel(int channel) {
    return data[channel];
}

/*
 * Get channel vector data
 */
std::vector<RemoteControlChannel> RemoteControl::getData() {
  return data;
};
