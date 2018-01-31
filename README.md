Arduíno RemoteControl
=====================
This is a [Arduino](https://www.arduino.cc/) library to easily connect the board to a remote control.

# Example

```cpp
#include <StandardCplusplus.h>
#include <vector>
#include <RemoteControl.h>

using namespace std;

// instance of RemoteControl
RemoteControl rc;

void setup() {
  Serial.begin(57600);
  Serial.println("Start");

  // binding the channel 1 to the pin 2 on arduino
  rc.bind(1,2);

  // binding the channel 2 to the pin 3 on arduino
  rc.bind(2,3);
}

void loop() {
  // get the data from all remote control channels
  std::vector<CHANNEL> data = rc.getData();

  // prints the channel's data
  for( int i=0; i<data.size(); i++ ) {
    Serial.print("Channel ");
    Serial.print(data[i].number);
    Serial.print(" : ");
    Serial.println(data[i].value);
  }

  delay(15);
}
```

If you open the Serial Monitor on Arduino IDE, you will see the read of the data from the remote control
