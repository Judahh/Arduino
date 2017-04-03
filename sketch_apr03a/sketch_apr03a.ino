#include <QueueArray.h>
#include <math.h>

QueueArray <bool> queueBitsFound;
int bitPosition=-1;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("START");
  queueBitsFound.enqueue(0);
  queueBitsFound.enqueue(0);
  queueBitsFound.enqueue(1);
  queueBitsFound.enqueue(1);
  queueBitsFound.enqueue(0);
  queueBitsFound.enqueue(0);
  queueBitsFound.enqueue(0);
  queueBitsFound.enqueue(0);
  queueBitsFound.enqueue(0);
  queueBitsFound.enqueue(0);
  queueBitsFound.enqueue(1);
  queueBitsFound.enqueue(0);
  queueBitsFound.enqueue(1);
  queueBitsFound.enqueue(1);
  queueBitsFound.enqueue(1);
  queueBitsFound.enqueue(0);
  queueBitsFound.enqueue(0);
  queueBitsFound.enqueue(0);
  queueBitsFound.enqueue(0);
  queueBitsFound.enqueue(0);
  queueBitsFound.enqueue(0);
  queueBitsFound.enqueue(0);
}

void checkBits() {
  while (queueBitsFound.count()>0) {
    bool newBit=queueBitsFound.dequeue();
    if(bitPosition==-1){
      if(newBit){
        Serial.println("P++");
        bitPosition++;
      }
    }else{
      if(bitPosition<8){
        Serial.print((int)newBit);
        bitPosition++;
      }else{
        bitPosition=-1;
      }
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  checkBits();
}
