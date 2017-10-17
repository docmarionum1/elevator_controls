#define UP_BUTTON 5
#define DOWN_BUTTON 8
#define UP_LED 3
#define DOWN_LED 2
#define UP_ARROW 12
#define DOWN_ARROW 11
#define BUZZER_PIN 13

int upButtonState = 0;
int downButtonState = 0;
int upState = -1;
int downState = -1;
int upArrowState = 0;
int downArrowState = 0;
int toneState = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(UP_BUTTON, INPUT);
  pinMode(DOWN_BUTTON, INPUT);
  pinMode(UP_LED, OUTPUT);
  pinMode(DOWN_LED, OUTPUT);
  pinMode(UP_ARROW, OUTPUT);
  pinMode(DOWN_ARROW, OUTPUT);
  Serial.begin(115200);
}


void loop() {

  if (upState == 0) {
    upState = -1;
    upArrowState = 100;
    toneState = 0;
  } else if (upState > 0) {
    upState--;
  }
  
  if (downState == 0) {
    downState = -1;
    downArrowState = 100;
    toneState = 0;
  } else if (downState > 0) {
    downState--;
  }

  upArrowState = max(upArrowState--, 0);
  downArrowState = max(downArrowState--, 0);
  digitalWrite(UP_ARROW, upArrowState > 0);
  digitalWrite(DOWN_ARROW, downArrowState > 0);

  if (toneState == 0) {
    tone(BUZZER_PIN, 660);
  } else if (toneState == 30) {
    tone(BUZZER_PIN, 550);
  } else if (toneState == 60) {
    //tone(BUZZER_PIN, 440);
    noTone(BUZZER_PIN);
  } else if (toneState == 90) {
    noTone(BUZZER_PIN);
  }

  if (toneState < 91) {
    toneState++;
  }
  
 
  upButtonState = digitalRead(UP_BUTTON);
  if (upButtonState == 1 && upState < 0) {
    upState = random(25, 500);
  }
  digitalWrite(UP_LED, upState > 0);

  downButtonState = digitalRead(DOWN_BUTTON);
  if (downButtonState == 1 && downState < 0) {
    downState = random(25, 500);
  }
  digitalWrite(DOWN_LED, downState > 0);
  

  delay(25);
}
