#define trigPin 9
#define echoPin 10
#define outputDIS 11
#define outputLED 12
int c;
void setup()
{
    Serial.begin(9600);
    pinMode(A1, INPUT);
    pinMode(echoPin, INPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(outputDIS, OUTPUT);
    pinMode(outputLED, OUTPUT);
}
void loop()
{
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration / 2) / 29.1;
    if (distance >= 300 || distance <= 0)
    {
        Serial.println("Out of range");
    }
    else
    {
        Serial.print(distance);
        Serial.println(" cm");
        digitalWrite(outputDIS, HIGH);
        delayMicroseconds(200);
        digitalWrite(outputDIS, LOW);
        delayMicroseconds(50);
    }
    delay(100);
    int c = analogRead(A0);
    if (c < 800)
    {
        digitalWrite(outputLED, LOW);
    }
    else
    {
        digitalWrite(outputLED, HIGH);
    }
}