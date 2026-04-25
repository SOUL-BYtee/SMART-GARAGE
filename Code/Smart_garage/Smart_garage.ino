#include <Servo.h>

// تعريف السيرفو
Servo servo1;
Servo servo2;

// Pins of ultrasonic
const int trigPin = 5;
const int echoPin = 6;

long duration;
int distance;

void setup() {
  servo1.attach(2);
  servo2.attach(3);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  servo1.write(90);   // start mode
  servo2.write(80);   // start mode
  Serial.begin(9600);
}

void loop() {

  // إرسال نبضة التريجر
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // قراءة الإيكو
  duration = pulseIn(echoPin, HIGH);

  // حساب المسافة
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // الشرط: لو في جسم قريب
  if (distance <= 20) { // أقل من 20 سم
    servo1.write(0);   // لف
    servo2.write(180);
      delay(4000);

  } else {
    servo1.write(90);   // رجوع للوضع الطبيعي
    servo2.write(80);
  }

  delay(200);
}
