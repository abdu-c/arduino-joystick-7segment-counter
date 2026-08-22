// [TR] Arduino Uno & XY Joystick ile 7-Segment Display Sayıcı Projesi
// [EN] Arduino Uno & XY Joystick 7-Segment Display Counter Project

// Pin Tanımları
const int pinA = 2;
const int pinB = 3;
const int pinC = 4;
const int pinD = 5;
const int pinE = 6;
const int pinF = 7;
const int pinG = 8;


const int butonPin = 9;  // Joystick Butonu (Sıfırlama)

int sayac = 0; // Başlangıç değeri

// 7-Segment Segment Kontrol Fonksiyonu (Ortak Anot: 0 = YANAR, 1 = SÖNER)
void segmentleriSur(int a, int b, int c, int d, int e, int f, int g) {
  digitalWrite(pinA, a);
  digitalWrite(pinB, b);
  digitalWrite(pinC, c);
  digitalWrite(pinD, d);
  digitalWrite(pinE, e);
  digitalWrite(pinF, f);
  digitalWrite(pinG, g);
}

// Rakam Seçici
void rakamGoster(int sayi) {
  switch (sayi) {
    case 0: segmentleriSur(0, 0, 0, 0, 0, 0, 1); break;
    case 1: segmentleriSur(1, 0, 0, 1, 1, 1, 1); break;
    case 2: segmentleriSur(0, 0, 1, 0, 0, 1, 0); break;
    case 3: segmentleriSur(0, 0, 0, 0, 1, 1, 0); break;
    case 4: segmentleriSur(1, 0, 0, 1, 1, 0, 0); break;
    case 5: segmentleriSur(0, 1, 0, 0, 1, 0, 0); break;
    case 6: segmentleriSur(0, 1, 0, 0, 0, 0, 0); break;
    case 7: segmentleriSur(0, 0, 0, 1, 1, 1, 1); break;
    case 8: segmentleriSur(0, 0, 0, 0, 0, 0, 0); break;
    case 9: segmentleriSur(0, 0, 0, 0, 1, 0, 0); break;
  }
}

void setup() {
  for (int pin = 2; pin <= 8; pin++) {
    pinMode(pin, OUTPUT);
  }
  pinMode(butonPin, INPUT_PULLUP);
  rakamGoster(sayac);
}

void loop() {
  int joyDeger = analogRead(A0);

  // reset button
  if (digitalRead(butonPin) == LOW) {
    sayac = 0;
    rakamGoster(sayac);
    delay(250);
  }

  // Joystick Yukarı -> Artır
  if (joyDeger < 300) {
    if (sayac < 9) {
      sayac++;
      rakamGoster(sayac);
    }
    delay(300);
  }
  // Joystick Aşağı -> Azalt
  else if (joyDeger > 700) {
    if (sayac > 0) {
      sayac--;
      rakamGoster(sayac);
    }
    delay(300);
  }
}
