#include <Servo.h>
#define LED1 2
#define LED2 3
#define LED3 4
char dato;
String cadena;
String d1, d2, d3, d4, d5, d6;
Servo servo1, servo2, servo3;
bool led1, led2, led3;
byte s1, s2, s3;
byte p1, p2, p3, p4, p5, p6;
void setup() {
  Serial.begin(9600);  // put your setup code here, to run once:
  pinMode(LED1, 1);
  pinMode(LED2, 1);
  pinMode(LED3, 1);
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
}

void loop() {
  if (Serial.available() > 0) {
    dato = Serial.read();
    cadena = cadena + dato;
    if (dato == '*') {
      p1 = cadena.indexOf('|');
      p2 = cadena.indexOf('|', p1 + 1);
      p3 = cadena.indexOf('|', p2 + 1);
      p4 = cadena.indexOf('|', p3 + 1);
      p5 = cadena.indexOf('|', p4 + 1);
      p6 = cadena.indexOf('|', p5 + 1);
      d1 = cadena.substring(0, p1);
      d2 = cadena.substring(p1 + 1, p2);
      d3 = cadena.substring(p2 + 1, p3);
      d4 = cadena.substring(p3 + 1, p4);
      d5 = cadena.substring(p4 + 1, p5);
      d6 = cadena.substring(p5 + 1, p6);
      s1 = d1.toInt();
      s2 = d2.toInt();
      s3 = d3.toInt();
      led1 = d4.toInt();
      led2 = d5.toInt();
      led3 = d6.toInt();
      servo1.write(s1);
      servo2.write(s2);
      servo3.write(s3);
      digitalWrite(LED1, led1);
      digitalWrite(LED2, led2);
      digitalWrite(LED3, led3);
      cadena = "";
    }
  }
}