const char ADDR[] = {24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54};

void setup() {
  // put your setup code here, to run once:

  for (int n = 0; n < 16; n += 1) {
    pinMode(ADDR[n], INPUT);
  }

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int n = 0; n < 16; n += 1) {
    int bit = digitalRead(ADDR[n]) ? 1 : 0;
    Serial.print(bit);
  }

  Serial.println(1);
}
