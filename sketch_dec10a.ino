const int pingTrigPin = 12;
const int pingEchoPin = 10;
const int buz=5; 
void setup() {   
  Serial.begin(9600);   
  pinMode(buz, OUTPUT);   
  pinMode(pingTrigPin, OUTPUT);   
  pinMode(pingEchoPin, INPUT);
}   
void loop()   
  {   
  long duration, distanceInCM;      
  digitalWrite(pingTrigPin, LOW);   
  delayMicroseconds(2);   
  digitalWrite(pingTrigPin, HIGH);   
  delayMicroseconds(5);   
  digitalWrite(pingTrigPin, LOW);   
  duration = pulseIn(pingEchoPin, HIGH);   
  distanceInCM = calculateDistance(duration);   
  if(distanceInCM<=100 && distanceInCM>0)   
  {   
    int d= map(distanceInCM, 1, 100, 20, 200);   
    digitalWrite(buz, HIGH);   
    delay(50);   
    digitalWrite(buz, LOW);   
    delay(d);  
  }   
  Serial.print(distanceInCM);    
  Serial.println("cm");
  delay(100);   
  }   
  long calculateDistance(long signalDuration)   
  {   
  return signalDuration / 29 / 2;   
  } 
