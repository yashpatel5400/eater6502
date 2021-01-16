const char ADDR[] = {24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54};
const char DATA[] = {31, 33, 35, 37, 39, 41, 43, 45, 47};

#define CLOCK 2

void setup() {
  // put your setup code here, to run once:

  for (int n = 0; n < 16; n += 1) {
    pinMode(ADDR[n], INPUT);
  }

  for (int n = 0; n < 8; n += 1) {
    pinMode(DATA[n], INPUT);
  }

  pinMode(CLOCK, INPUT);

  attachInterrupt(digitalPinToInterrupt(CLOCK), onClock, RISING);

  Serial.begin(9600);
}

void onClock() {
  // put your main code here, to run repeatedly:
  Serial.print("Address: ");
  for (int n = 0; n < 16; n += 1) {
    int bit = digitalRead(ADDR[n]) ? 1 : 0;
    Serial.print(bit);
  }

  Serial.print(" | Data: ");
  for (int n = 0; n < 8; n += 1) {
    int bit = digitalRead(DATA[n]) ? 1 : 0;
    Serial.print(bit);
  }

  Serial.println(1);
}

void loop() {
}
