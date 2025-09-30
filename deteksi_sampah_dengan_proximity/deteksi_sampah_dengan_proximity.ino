#include <Servo.h>
#include <IRremote.h>

Servo myservo;  // Membuat objek untuk mengendalikan servomotor

const int sensorPin = 8;  // Pin sensor proximity induktif terhubung ke pin digital 2
const int servoPin = 9;   // Pin servomotor terhubung ke pin digital 9

int receiverPin = 11; // Pin yang terhubung ke sensor inframerah
IRrecv irrecv(receiverPin);
decode_results results;

void setup() {
  myservo.attach(servoPin);  // Menghubungkan servomotor ke pin digital 9
  pinMode(sensorPin, INPUT);  // Mengatur pin sensor sebagai input
  Serial.begin(9600);       // Membuka komunikasi serial untuk debugging
  int sensorValue = digitalRead(sensorPin); // Membaca nilai sensor

  irrecv.enableIRIn(); // Mulai menerima sinyal inframerah

}

void loop() {
  int sensorValue = digitalRead(sensorPin); // Membaca nilai sensor
  if (sensorValue == LOW) {
    // Jika sensor mendeteksi logam (sampah anorganik)
    Serial.println("Sampah Anorganik terdeteksi");
    myservo.write(180);  // Menggerakkan servomotor untuk membuka pintu anorganik
    delay(1000);  // Tahan pintu terbuka selama 2 detik
    myservo.write(0);   // Mengembalikan pintu ke posisi awal
    delay(1000);
  } else {
    // Jika sensor tidak mendeteksi logam (sampah organik)
    Serial.println("Sampah Organik terdeteksi");
    myservo.write(90);  // Menggerakkan servomotor untuk membuka pintu anorganik
    delay(500);  // Tahan pintu terbuka selama 2 detik
    myservo.write(0);   // Mengembalikan pintu ke posisi awal
    delay(1000);
  }

  delay(100);  // Jeda sebentar sebelum membaca sensor lagi

  }
