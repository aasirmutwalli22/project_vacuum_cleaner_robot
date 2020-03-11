int motor11           = 10;
int motor12           = 11;
int motor21           = 12;
int motor22           = 13;

int triggerPin        = 9;
int echoPinRight      = 5;
int echoPinFront      = 6;
int echoPinLeft       = 7;

int proximityPinRight = 3;
int proximityPinLeft  = 2;

int relayPin          = 8;

void setup() {
  pinMode(motor11,            OUTPUT);
  pinMode(motor12,            OUTPUT);
  pinMode(motor21,            OUTPUT);
  pinMode(motor22,            OUTPUT);

  pinMode(triggerPin,         OUTPUT);
  pinMode(echoPinRight,       INPUT);
  pinMode(echoPinFront,       INPUT);
  pinMode(echoPinLeft,        INPUT);

  pinMode(proximityPinRight,  INPUT);
  pinMode(proximityPinLeft,   INPUT);

  pinMode(relayPin,           OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if      (!digitalRead(proximityPinRight) && !digitalRead(proximityPinLeft) && getFrontDistance <= 10) takeLeftTurn();
  else if (!digitalRead(proximityPinRight) || !digitalRead(proximityPinLeft) || getFrontDistance <= 10) stopRobot();
  else straight();
}

void takeLeftTurn() {
  left();
  delay(8000);
  stopRobot();
  straight();
  delay(8000);
  stopRobot();
  left();
  delay(8000);
  stopRobot();
}
void takeRightTurn() {
  right();
  delay(8000);
  stopRobot();
  straight();
  delay(8000);
  stopRobot();
  right();
  delay(8000);
  stopRobot();
}


float getFrontDistance() {
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  long duration = pulseIn(echoPinFront, HIGH);
  return duration * 0.034 / 2;
}
float getRightDistance() {
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  long duration = pulseIn(echoPinRight, HIGH);
  return duration * 0.034 / 2;
}
float getLeftDistance() {
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  long duration = pulseIn(echoPinLeft, HIGH);
  return duration * 0.034 / 2;
}

void turnOnRelay() {
  digitalWrite(relayPin, HIGH);
}
void turnOffRelay() {
  digitalWrite(relayPin, LOW);
}


void straight() {
  digitalWrite(motor11, HIGH);
  digitalWrite(motor12, LOW);
  digitalWrite(motor21, LOW);
  digitalWrite(motor22, HIGH);
}
void back() {
  digitalWrite(motor11, LOW);
  digitalWrite(motor12, HIGH);
  digitalWrite(motor21, HIGH);
  digitalWrite(motor22, LOW);
}
void left() {
  digitalWrite(motor11, HIGH);
  digitalWrite(motor12, LOW);
  digitalWrite(motor21, HIGH);
  digitalWrite(motor22, LOW);
}
void right() {
  digitalWrite(motor11, LOW);
  digitalWrite(motor12, HIGH);
  digitalWrite(motor21, LOW);
  digitalWrite(motor22, HIGH);
}
void stopRobot() {
  digitalWrite(motor11, LOW);
  digitalWrite(motor12, LOW);
  digitalWrite(motor21, LOW);
  digitalWrite(motor22, LOW);
}
