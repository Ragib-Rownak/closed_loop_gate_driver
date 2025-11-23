#define PIN 9
#define POT A0
#define FEED A2
#define R1 10
#define R2 20

  uint16_t potRead = 0;
  int pwmVal = 0;
  float feedVal = 0;
  float Kp = 2.5;           // proportional gain

  float feedCalc(int n){

    float val = (n*5.0)/1023.0;  // converting analog reading to input voltage

    return val;
  } 

  void errorCalc(){

    float desiredVolt = (potRead / 1023.0) * 12.1;  // calculating desired output voltage from the pwm set by pot
    float actualVolt = (feedVal * ((R1 + R2) / (float)R1) ); //typecasted
    float voltDiff = desiredVolt - actualVolt; // calculating the error in voltage
    
    Serial.println();
    Serial.print("PotRead: ");
    Serial.print(potRead);

    Serial.println();

    Serial.print("desired: ");
    Serial.print(desiredVolt);

    Serial.println();

    Serial.print("feed: ");
    Serial.print(feedVal);

    Serial.println();

    Serial.print("actual: ");
    Serial.print(actualVolt);

    Serial.println();

    Serial.print("error: ");
    Serial.print(voltDiff);

    Serial.println();


    pwmVal = pwmVal + Kp * voltDiff;
    pwmVal = constrain(pwmVal, 0, 255);

    Serial.print("pwm: ");Serial.print(pwmVal);
    Serial.println();

    analogWrite(PIN,pwmVal);

  }
  
void setup(){

  pinMode(PIN,OUTPUT);
  //Serial.begin(9600);
  
}

void loop(){

  potRead = analogRead(POT);
 
  // pwmVal = map(potRead,0,1023,0,255);
  // analogWrite(PIN,pwmVal);
  
  feedVal = feedCalc(analogRead(FEED));
  Serial.println();

    Serial.print("feed: ");
    Serial.print(analogRead(FEED));
  
  errorCalc();
  
  //delay(1000);


  
}