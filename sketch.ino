//Creates a 1mhz carrier which is modulated through OOK with audio recieved via serial
ISR(TIMER2_COMPA_vect) {
  DDRB = (DDRB & ~2) | ((Serial.read() > 127) << 1);
}
void setup() {
  cli();
  TCCR1A = (1 << COM1A0);
  TCCR1B = (1 << WGM12) | (1 << CS11);
  OCR1A = 0;
  TCCR2B = (1 << COM2A0);
  TCCR2B = (1 << WGM21) | (1 << CS21);
  OCR2A = 800;
  TIMSK2 = (1 << OCIE2A);
  sei();
  Serial.begin(115200);
}
void loop() {}
