/*This sketch Configures the name and baud rate of an HC 06 Bluetooth module */
#include <SoftwareSerial.h>
char message1[10];//need length of chars being read +1 for null character
char message2[9];
SoftwareSerial BLU(10, 11); // RX, TX

void setup() {
  // set baud rate then delay to give user time to open BLU monitor
  Serial.begin(9600);
  Serial.println("A");
  BLU.begin(9600);
  Serial.println("B");
  delay(5000);
  //Send command to set name of HC06 module, with the below command name will change to "forcetronics"
  BLU.print("AT+BAUD4");
  delay(600); //HC06 requires 500 msec for reply
  int8_t count = 0; //declare and intialize count
  while (1) { //loop until OKsetname is read and cleared from buffer
    if (BLU.available()) {
      message1[count] = BLU.read(); //read in char
      count++;
      if (count == 6) break; //after we get all 9 char break out of loop
    }
    delay(10);
  }

  //print out each message to make sure it worked
  Serial.println("");
  Serial.println(message1);
  Serial.println(message2);
}

void loop() {
  //do nothing
  delay(50);
  Serial.println("OK");
}
