#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX

void setup() {
//  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
//
//
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  

  
//
//  mySerial.print("AT");
//  waitForResponse();
//
//    mySerial.print("AT+UUID?");
//  waitForResponse();
//
//    mySerial.print("AT+CHAR?");
//  waitForResponse();
//
//      mySerial.print("AT+CHAR?");
//  waitForResponse();
//  

//   Serial.println("AT+RENEW");
 mySerial.print("AT+RENEW");
  waitForResponse();



//  Serial.println("AT+UUID?");
//  mySerial.print("AT+UUID?");
//  waitForResponse();
//
//  Serial.println("AT+PASS1234");
//  mySerial.print("AT+PASS1234");
//  waitForResponse();
//
//  Serial.println("AT+NAMEHM-10");
//  mySerial.print("AT+NAMEHM-10");
//  waitForResponse();

}
String msg, msgReceived;
char c;
void loop() {
  // put your main code here, to run repeatedly:


  char c;
  if (Serial.available()) {
    
    msg = Serial.readString();
    mySerial.print(msg);
    
    Serial.print("\nHM10 disse:\n");
    Serial.println(msg);
  }

 while (mySerial.available()) {
    delay(10);                                        //small delay to allow input buffer to fill

    c = mySerial.read();                              //gets one byte from serial buffer
    if (c == '~') {
      break;
    }                                                 //breaks out of capture loop to print readstring
    msgReceived += c;
  }                                                   //makes the string readString 

  if (msgReceived.length() >0) {
    Serial.print("\nAndroid disse:" + msgReceived);   //prints string to serial port out
    msgReceived="";                                   //clears variable for new input
  }
}

void waitForResponse() {
  delay(1000);
  while (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  Serial.write("\n");
}
