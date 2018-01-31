/*
 * Library to use easily a remote controll with arduino
 * Created by Marcio A. Barroso, January 30th 2018
 * Released into the public domain.
 */

#include <arduino.h>
#include <RemoteControl.h>

void RemoteControl::bind(int channel, int pin) {
  Serial.print("Binding channel ");
  Serial.print(channel);
  Serial.print(" on pin ");
  Serial.println(pin);
  data.push_back({channel, pin, 0});
};

std::vector<CHANNEL> RemoteControl::getData() {
  for(int i=0; i<data.size(); i++) {
    data[i].value = convertPulseToPWM(pulseIn(data[i].pin, HIGH, 25000));
  }

  return data;
};

int RemoteControl::convertPulseToPWM(int pulse) {
  int precision = 20;

  if(pulse > 1000) {
    pulse = map(pulse, 1000, 2000, -500, 500);
    pulse = constrain(pulse, -255, 255);
  } else {
    pulse = 0;
  }

  if( abs(pulse) <= precision ) {
    pulse = 0;
  }

  return pulse;
};
