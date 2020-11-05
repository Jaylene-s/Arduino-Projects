int trig = 7; //ultrasonic trig pin
int echo = 8; //ultrasonic echo pin
byte fan = 6; //mini fan connected to pin 6 arduino uno

long duration;
float distance;

void setup() {
Serial.begin(9600);
pinMode(trig, OUTPUT); //trigpin will send out the ultrsound
pinMode(echo, INPUT); //echopin will turn on based on the infromation recieved
pinMode(fan, OUTPUT); //echopin triggers the fan to turn on
}

void loop() {
digitalWrite(trig, LOW);
delayMicroseconds(3);     //a short LOW pulse beforehand to ensure a clean HIGH pulse
digitalWrite(trig, HIGH); //send a 10 microsecond high pulse
delayMicroseconds(10);
digitalWrite(trig, LOW); 

duration = pulseIn(echo, HIGH); //when the ultrasound is emitted the module makes the echopin high
distance = duration/58; //based on ultrasonic datasheet

if(distance < 40){
digitalWrite(fan, HIGH); //turn on the fan if it is within range
}else{
digitalWrite(fan, LOW); //otherwise turn off
}
Serial.println (distance); 
}
