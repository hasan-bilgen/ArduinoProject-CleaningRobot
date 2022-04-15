#include <SparkFun_TB6612.h>

long timet, dist;
#define AIN1        6
#define AIN2        5
#define PWMA        10
#define BIN1        7
#define BIN2        8
#define PWMB        9
#define STBY        4

#define BI_LED_RED  11
#define BI_LED_GRN  A3
#define DIR_LED_LFT 12
#define DIR_LED_RHT 13

#define US_ECHO A4
#define US_TRIG A5

#define SENSOR_1     2
#define SENSOR_2     3

#define AUX_OUTPUT A2
#define LDR A1
#define BATT_VOLTAGE A0

const int offsetA = 1;
const int offsetB = 1;
bool togi = false;

Motor leftmotor = Motor(AIN2, AIN1, PWMA, offsetA, STBY);
Motor rightmotor = Motor(BIN1, BIN2, PWMB, offsetB, STBY);


void toggleDir()
{
  if (togi)
  {
    digitalWrite(DIR_LED_LFT, HIGH);
    digitalWrite(DIR_LED_RHT, LOW);
  }
  else
  {
    digitalWrite(DIR_LED_LFT, LOW);
    digitalWrite(DIR_LED_RHT, HIGH);
  }
  togi = !togi;
}

void setup() {

  pinMode(US_ECHO, INPUT);
  pinMode(US_TRIG, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  

}

void loop() {

digitalWrite(US_TRIG, LOW);
delayMicroseconds(5);
digitalWrite(US_TRIG, HIGH);
delayMicroseconds(10);
digitalWrite(US_TRIG, LOW);

timet = pulseIn(US_ECHO, HIGH);
dist = timet / 29.1 / 2;

if (digitalRead(SENSOR_1)||digitalRead(SENSOR_2) == HIGH){
  forward(leftmotor, rightmotor, LOW);
  back(leftmotor, rightmotor, HIGH);
  back(leftmotor, rightmotor);
  delay(500);
  back(leftmotor, rightmotor, LOW);
  back(leftmotor, rightmotor);
  righ();
  delay(100);

  }

if(dist < 15){
  //back();
  forward(leftmotor, rightmotor, LOW);
  back(leftmotor, rightmotor, HIGH);
  back(leftmotor, rightmotor);
  delay(500);
  back(leftmotor, rightmotor, LOW);
  back(leftmotor, rightmotor);
  
  righ();
  //right(leftmotor, rightmotor, HIGH);
  delay(100);
  //right(leftmotor, rightmotor, LOW);
}
else{
  forwar();
  //forward(leftmotor, rightmotor, HIGH);
  //forward(leftmotor, rightmotor);
}

}



void bac(){
  digitalWrite(AIN2, LOW);
  digitalWrite(AIN1, HIGH);
  digitalWrite(PWMA, 150);

  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  digitalWrite(PWMB, 150);
}

void forwar(){
  digitalWrite(AIN2, HIGH);
  digitalWrite(AIN1, LOW);
  digitalWrite(PWMA, 240);

  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  digitalWrite(PWMB, 240);
}

void righ(){
  digitalWrite(AIN2, LOW);
  digitalWrite(AIN1, HIGH);
  digitalWrite(PWMA, 240);

  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  digitalWrite(PWMB, 150);
}

void lef(){
  digitalWrite(AIN2, HIGH);
  digitalWrite(AIN1, LOW);
  digitalWrite(PWMA, 150);

  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  digitalWrite(PWMB, 240);
}
