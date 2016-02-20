#include "Timer.h"

#define RED1      7
#define GREEN1    8
#define GREEN2    12
#define RPI       9

#define STATE_WORKING    0
#define STATE_FAIL       1

volatile int state;
Timer t;

void setup() {
  pinMode(RED1, OUTPUT);
  pinMode(GREEN1, OUTPUT);
  pinMode(RPI, OUTPUT);
  pinMode(GREEN2, OUTPUT);

  t.after(5000, doAfter);

  state = STATE_WORKING;
}

void loop() {
  t.update();
  // Blinking green LED if working
  if(state == STATE_WORKING) {
    digitalWrite(RPI, LOW);
    digitalWrite(GREEN1, HIGH);
    delay(500);
    digitalWrite(GREEN1, LOW);
    delay(500);
  } else if(state == STATE_FAIL) {
    digitalWrite(GREEN1, LOW);
    digitalWrite(RED1, HIGH);
    digitalWrite(GREEN2, HIGH);
    digitalWrite(RPI, HIGH);
  }
}

void doAfter() {
  state = STATE_FAIL;
}
