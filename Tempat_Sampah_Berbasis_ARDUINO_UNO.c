#include <Servo.h>

// ==== KONSTANTA ====
const float SOUND_SPEED = 0.034;

// ==== PIN ====
const int trig1 = 9;
const int echo1 = 8;
const int trig2 = 6;
const int echo2 = 7;
const int servoPin  = 10;
const int buzzerPin = 11;

// ==== OBJEK ====
Servo servo1;

// ==== VARIABEL ====
float jarak1_cm = 0;
float jarak2_cm = 0;
bool tutupTerbuka = false;
bool statusPenuh  = false;

// ==== FUNGSI ====
float bacaJarakCM(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long durasi = pulseIn(echoPin, HIGH, 30000);
  if (durasi == 0) return 0;

  return (durasi * SOUND_SPEED) / 2.0;
}

void buzzerBeep3() {
  for (byte i = 0; i < 3; i++) {
    tone(buzzerPin, 1000);
    delay(200);
    noTone(buzzerPin);
    delay(200);
  }
}

// ==== SETUP ====
void setup() {
  Serial.begin(9600);

  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(buzzerPin, OUTPUT);

  servo1.attach(servoPin);
  servo1.write(0); // tutup
}

// ==== LOOP ====
void loop() {
  jarak1_cm = bacaJarakCM(trig1, echo1);
  jarak2_cm = bacaJarakCM(trig2, echo2);

  Serial.print("Sensor1: ");
  Serial.print(jarak1_cm);
  Serial.print(" cm | Sensor2: ");
  Serial.print(jarak2_cm);
  Serial.println(" cm");

  // ==== BUKA TUTUP ====
  if (jarak1_cm > 0 && jarak1_cm <= 5 && !tutupTerbuka) {
    servo1.write(90); // buka
    tutupTerbuka = true;
    delay(3000);
    servo1.write(0);  // tutup
    tutupTerbuka = false;
  }

  // ==== STATUS PENUH ====
  if (jarak2_cm > 0 && jarak2_cm <= 4) {
    if (!statusPenuh) {
      Serial.println("Status: PENUH");
      buzzerBeep3();
      statusPenuh = true;
    }
  } else {
    statusPenuh = false;
    noTone(buzzerPin);
    Serial.println("Status: KOSONG");
  }

  Serial.println("----------------------");
  delay(1000);
}
