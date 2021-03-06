// BT Example Sketch, Bluetooth Module connected to hardware serial pins

// ----------- BLUETOOTH ------------- 
char buff_name[100];     // Use smaller buffers to safe RAM
char buff_value[100];   // RAM propblems are indicated by random errors with string processing
int pos = 0;
boolean colon = false;

void setup() {    
  Serial.begin(9600);
  sendsetup();
}

void loop() {
  checkserial();  
  delay(20);
  
  /* Example: Send data from Analog 0 pin
  Serial.print("A0:" + String(analogRead(A0)) + "\n");
  */
}

void checkserial() {
  while(Serial.available()) {
     if (!colon) {
       buff_name[pos] = Serial.read();
       if (buff_name[pos] == ':') {
         colon = !colon;
         buff_name[pos] = '\0';
         pos = -1; 
       }
       if (buff_name[pos] == '\n') {
         buff_name[pos] = '\0';
         buff_value[0] = '\0';
         pos = -1;
         receiveline(buff_name,buff_value);
       }
     } else {
       buff_value[pos] = Serial.read();
       if (buff_value[pos] == '\n') {
         colon = !colon;
         buff_value[pos] = '\0';
         pos = -1;
         receiveline(buff_name,buff_value);
       }
     }
     pos++;
  }
}

void receiveline(String name, String value) {
  if (name == "requestsetup") { sendsetup(); return; } 
  if (name == "mirror") {
    Serial.print(value + "\n");
    return;
  }
  
  /* Debugging: Return name and value
  Serial.print("name:" + name + "\n");
  Serial.print("value:" + value + "\n");
  */
  
  /* Example: LED
  if (name == "led") {
    if (value == "true") digitalWrite(ledpin,HIGH);
    if (value == "false") digitalWrite(ledpin,LOW);
  }*/
  
  /* Example: Joystick
  if (name == "joystick") {
    String sx = "";
    String sy = "";
    
    p = 0;
    while (p < value.length() && value.charAt(p) != '|') { sx = sx + value.charAt(p++); }
    p++;
    while (p < value.length()) { sy = sy + value.charAt(p++); }
    
    double x = sx.toFloat();
    double y = sy.toFloat();    
    
    joystick(x,y);
  }
  */
}

// Send information about the events you want to use
void sendsetup() {
    /* Example: Register int between -1 and 1 and set to 0.2
    Serial.print("requestint:steer\n");
    Serial.print("steer:0.2\n");
    Serial.print("setmaxsteer:1\n");
    Serial.print("setminsteer:-1\n");  
    */
}

/* Helper functions:

void log(String s) {
  Serial.print("status:" + s + "\n");  
}

void update(String name, String value) {
  Serial.print(name + ":" + value + "\n"); 
}

void update(String name, int value) {
  Serial.print(name + ":" + String(value) + "\n");
}

*/
