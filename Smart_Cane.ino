const int trig1 = 9;
const int echo1 = 8;
const int trig2 = 7;
const int echo2 = 6;
const int buzz = 5;
const int vib = 4;

long duration1;
long duration2;
int distance1;
int distance2;

void setup()
{
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(buzz, OUTPUT);
  pinMode(vib, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig1,LOW);

  duration1 = pulseIn(echo1, HIGH);
  distance1 = duration1 * 0.0342 / 2;

  digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig2,LOW);
  
  duration2 = pulseIn(echo2, HIGH);
  distance2 = duration2 * 0.0342 / 2;

  if (distance1<=50 && distance2<=50)
  {
    digitalWrite(buzz, HIGH);
    digitalWrite(vib,HIGH);
    delayMicroseconds(20);
    digitalWrite(buzz, LOW);
    digitalWrite(vib,LOW);
  }

  else if (distance1>=50 && distance2<=50)
  {
    digitalWrite(buzz, HIGH);
    digitalWrite(vib,HIGH);
    delayMicroseconds(20);
    digitalWrite(buzz, LOW);
    digitalWrite(vib,LOW);
  }
  else if (distance1<=50 && distance2>=50)
  {
    digitalWrite(buzz, HIGH);
    digitalWrite(vib,HIGH);
    delayMicroseconds(10);
    digitalWrite(buzz, LOW);
    digitalWrite(vib,LOW);
  }
  else
  {
    digitalWrite(buzz, LOW);
    digitalWrite(vib, LOW);
  }
  Serial.println(distance1);
  Serial.print("Distance1: ");
  
  Serial.print("Distance2: ");
  Serial.println(distance2);

}
