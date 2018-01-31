Arduíno RemoteControl
=====================
This is a [Arduino](https://www.arduino.cc/) library to easily connect the board to a remote control.

# Example

```cpp
#include <StandardCplusplus.h>
#include <RemoteControl.h>

// RemoteControl instance
RemoteControl rc;

void setup() {
  Serial.begin(57600);
  Serial.println("Start");

  // binding channel 1 on pin 11
  rc.bind(1,11);

  // binding channel 2 on pin 10
  rc.bind(2,10);
}

void loop() {
  for( int i=0; i<rc.getChannelCount(); i++ ) {
    RemoteControlChannel channel = rc.getChannel(i);
    Serial.print("Channel : ");
    Serial.print(channel.getChannel());
    Serial.print(" - PWM : ");
    Serial.print(channel.getPWM ());
    Serial.print(" - Pulse : ");
    Serial.print(channel.getPulse());
    Serial.print(" - Degrees : ");
    Serial.println(channel.getDegrees(180));
  }

  delay(15);
}

```

If you open the Serial Monitor on Arduino IDE, you will see the read of the data from the remote control
