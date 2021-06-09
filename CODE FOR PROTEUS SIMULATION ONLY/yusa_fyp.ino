#include <Boards.h>
#include <Firmata.h>
#include <FirmataConstants.h>
#include <FirmataDefines.h>
#include <FirmataMarshaller.h>
#include <FirmataParser.h>

#include<SoftwareSerial.h>

SoftwareSerial SIM900A(2, 3);//10tx green orange luar,11rx purple yellow dalam
int Sensor_7 = 0;
int Sensor_8 = 0;
int sensorbaby = 0;

void setup() 
{                
 pinMode(4, INPUT);
  pinMode(9, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  
  Serial.begin(9600);
  SIM900A.begin(9600);
    delay(100);
    SIM900A.println("AT+CMGF=1");
    delay(100);
    SIM900A.println("AT+CMGS=\"+60174539140\"\r");//parent number
    //SIM900A.println("AT+CMGS=\"+60174539140\"\r");//parent second number
    delay(100);
    SIM900A.println("Initialize");//message that gsm module will sent
    Serial.println("Initialized");
    delay(100);
    SIM900A.println((char)26);// ASCII code of CTRL+Z
    delay(100);
    Serial.println ("Message has been sent to yusafypproteus");
}

void loop()
{
  digitalRead(4);

  digitalRead(9);

  digitalRead(5);

  digitalRead(6);

  digitalRead(10);

  sensorbaby = digitalRead(11);
  Sensor_7 = digitalRead(7);
  Sensor_8 = digitalRead(8);
   //------------------------------------------------------------------
  if (Sensor_7 == 0 && Sensor_8 == 0) {
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    //delay(100); // Wait for 1000 millisecond(s)
    if (sensorbaby == 1) {
      //delay(100); // Wait for 1000 millisecond(s)
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      Serial.println ("Sending Message to yusaikmal");
    SIM900A.println("AT+CMGF=1");
   // delay(100);
    SIM900A.println("AT+CMGS=\"+601139938774\"\r");//parent number
    //delay(1000);
    SIM900A.println("Attention! Your child is inside the car!!!");//message that gsm module will sent
    Serial.println("Attention! Your child is inside the car!!!");
    //delay(100);
    SIM900A.println((char)26);// ASCII code of CTRL+Z
   // delay(1000);
    Serial.println ("Message has been sent to yusa ikmal");
    } else {
      //delay(1000); // Wait for 1000 millisecond(s)
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      Serial.println("standbymode // User left the car");
    }
  }
  if (Sensor_7 == 1 && Sensor_8 == 1) {
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    //delay(1000); // Wait for 1000 millisecond(s)
    //Serial.println("Two parent seat occupied");
    //delay(1000); // Wait for 1000 millisecond(s)
    if (sensorbaby == 1) {
      //delay(1000); // Wait for 1000 millisecond(s)
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      Serial.println("Baby + 2 Parent Seat Occcupied");
    } else {
      //delay(1000); // Wait for 1000 millisecond(s)
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      Serial.println("Two Parent seat Occupied");
    }
  }
  if (Sensor_7 == 0 && Sensor_8 == 1 || Sensor_7 == 1 && Sensor_8 == 0) {
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    //delay(1000); // Wait for 1000 millisecond(s)
    Serial.println("One parent seat occupied");
     //delay(1000); // Wait for 1000 millisecond(s)
    if (sensorbaby == 1) {
      //delay(1000); // Wait for 1000 millisecond(s)
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      Serial.println("Baby + 1 Parent Seat Occcupied");
    } else {
      //delay(1000); // Wait for 1000 millisecond(s)
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      Serial.println("One Parent seat Occupied");
  }
  }  
}
