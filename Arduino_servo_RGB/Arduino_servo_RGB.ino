/*
  по нажатию на кнопку, сервопривод начитается вращаться на 90 градусов и трехцветный
  светодиод начинает гореть красным цветом. При повторном нажатии, светодиод
  загорается синим цветом и сервопривод вращается в обратном направлении на 90
  градусов. При бездействии светодиод горит зеленым цветом и сервопривод
  находится в состоянии покоя.
*/

#include <Servo.h>


// на пине 7 подключена кнопка
#define BUTTON 7
// RGB светодиод
#define RED 11
#define GREEN 12
#define BLUE 13

// pin сервы
#define PIN_SERVO 10

// объект meservo для управления сервочкой
Servo myservo;

// переенная которая указывает двигаться ли серве и в какую сторону
byte direction = 1;
//direction = 1; servo = 0* led = red
//direction = 2; servo = 180* led = blue

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON, INPUT_PULLUP); // под кнопку ногу сделали входом
  pinMode(RED, OUTPUT); // выход светодиода
  pinMode(GREEN, OUTPUT); // выход светодиода
  pinMode(BLUE, OUTPUT); // выход светодиода

  myservo.attach(PIN_SERVO); // подключили серву

}//setup

void loop() {
  // put your main code here, to run repeatedly:
  //myservo.write(pos);

  // если кнопка нажата
  if (digitalRead(BUTTON) == 0) {
    delay(50); // задержка 50 мс для подавения дребезга
    if (digitalRead(BUTTON) == 0) {
      // потушим зеленый 
      digitalWrite(GREEN, 0);
      // проверяем куда вращаться
      if (direction == 1) { 
        myservo.write(0); // повернем серво относительно середины на 90* т.е. вернем в исходную для сервы позицию
        digitalWrite(RED, 1); // зажечь красный
        // при следующем нажатии направление будет в другую сторону
        direction = 2;
        // ничего не делать пока кнопка удерживается
        while (digitalRead(BUTTON) == 0) {
          delay(50);
        }//while 
      }//if dir = 1
      // если вращаться в другую сторону
      else if(direction == 2){
        myservo.write(180); // повернем серво относительно середины на 90* т.е. вернем в исходную для сервы позицию
        digitalWrite(BLUE, 1); // зажечь красный
        // при следующем нажатии направление будет в другую сторону
        direction = 1;
        // ничего не делать пока кнопка удерживается
        while (digitalRead(BUTTON) == 0) {
          delay(50);
        }//while 
      } //if dir = 2
    }//digRead(BUTTON)
  }////digRead(BUTTON)

// когда кнопки не нажаты
// светодиоды в исходное состояние
// серву в среднюю позицию
digitalWrite(RED, 0);
digitalWrite(BLUE, 0);
digitalWrite(GREEN, 1);
myservo.write(90);



}//loop
