int IN1 = 3;
int IN2 = 5;
int IN3 = 6;
int IN4 = 9;

void setup() {
  Serial.begin(9600);  // Serial start with speed 9600
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    int data = Serial.read();  // قراءة البيانات القادمة من البلوتوث
    Serial.println(data);      // طباعة البيانات للتأكد من استقبالها

    switch (data) {
      case 1:  // Forward 
        analogWrite(IN1, 0);
        analogWrite(IN2, 255);
        analogWrite(IN3, 0);
        analogWrite(IN4, 255);
        break;

      case 2:  // Backward 
        analogWrite(IN1, 255);
        analogWrite(IN2, 0);
        analogWrite(IN3, 255);
        analogWrite(IN4, 0);
        break;

      case 3:  // Right 
        analogWrite(IN1, 0);
        analogWrite(IN2, 255);
        analogWrite(IN3, 0);
        analogWrite(IN4, 64);
        break;

      case 4:  // Left 
        analogWrite(IN1, 0);
        analogWrite(IN2, 64);
        analogWrite(IN3, 0);
        analogWrite(IN4, 255);
        break;

      case 5:  // Stop 
        analogWrite(IN1, 0);
        analogWrite(IN2, 0);
        analogWrite(IN3, 0);
        analogWrite(IN4, 0);
        break;

      default:
        // إذا تم استقبال أي رقم غير معروف، توقف عن الحركة
        analogWrite(IN1, 0);
        analogWrite(IN2, 0);
        analogWrite(IN3, 0);
        analogWrite(IN4, 0);
        break;
    }
  }
}