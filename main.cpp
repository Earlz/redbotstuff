#include <Arduino.h>
#include <RedBot.h>
#include <SoftwareSerial.h>
#include <util/delay.h>

RedBotMotor motor;
SoftwareSerial serial(A1,A0);
RedBotAccel accel;


int main(){
    serial.begin(9600);
    motor.drive(255);
    pinMode(13, OUTPUT);
    accel.enableBump();
    int i=0;
    while(1)
    {
      digitalWrite(13, HIGH);
      _delay_ms(100);
      digitalWrite(13, LOW);
      accel.read();
      serial.print(i);
      serial.println();
      serial.print("accel: ");
      
      serial.print(accel.x);
      serial.print(" ");
      serial.print(accel.y);
      serial.print(" ");
      serial.print(accel.z);
      
      serial.println();
      serial.print("distance: ");
      serial.print(analogRead(A3));
      serial.println();
      _delay_ms(100);
      i++;
    }
}


