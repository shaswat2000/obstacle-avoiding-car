int RF=6; 
int RB=7;
int LF=9;
int LB=8;
int trigpin= 10;
int echopin=11;
int pwml= 5;
int pwmr= 3;
int f=0;
void setup() {
  // put your setup code here, to run once:
pinMode(LF, OUTPUT);
pinMode(LB, OUTPUT);
pinMode(RF, OUTPUT);
pinMode(RB, OUTPUT);
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
pinMode(pwml, OUTPUT);
pinMode(pwmr, OUTPUT);
Serial.begin(9600);
analogWrite(pwml, 70);
analogWrite(pwmr, 83);
digitalWrite(RF, LOW);digitalWrite(RB, LOW);digitalWrite(LF, LOW);digitalWrite(RF, LOW);
}

void loop() {
  f=0;
  // put your main code here, to run repeatedly:
float duration, cms;
digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin, LOW);
delayMicroseconds(2);
duration= pulseIn(echopin, HIGH);
cms=340*duration/20000;
Serial.println(cms);
delay(50 );
if(cms>20)
{
 digitalWrite(RF, HIGH);
 digitalWrite(LF, HIGH);  
 Serial.println("f");
}
else
{
    digitalWrite(RF, LOW);
    digitalWrite(LF, LOW); 
    digitalWrite(RB, HIGH);
    digitalWrite(LB, HIGH); 
    delay(300);
    digitalWrite(RB, LOW);
    digitalWrite(LB, LOW);
    delay(1000);  //here,./
  
   while(f==0)
  {
     digitalWrite(trigpin, HIGH);
     delayMicroseconds(10);
     digitalWrite(trigpin, LOW);
     delayMicroseconds(2);
     duration= pulseIn(echopin, HIGH);
     cms=340*duration/20000;
     Serial.println(cms);
     digitalWrite(LB, HIGH);
     digitalWrite(RF, HIGH);
     digitalWrite(LF, LOW);
     digitalWrite(RB, LOW);
     delay(100);
     digitalWrite(LB, LOW);
     digitalWrite(RF, LOW);
     if(cms>20)
     {
      f=1;
     }
     delay(200);   
    }  
}


}
