#include<SD.h>
#include<SPI.h>
#include<DS3231.h>

File myFile;
DS3231 rtc(SDA, SCL);

int CSpin = 10;
int trigPin = 7;
int echoPin = 6;

int count;
float pingTravelTime;
float pingTravelDist;
float dist;
float distSum;
float distAvg;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(CSpin, OUTPUT);
  pinMode(trigPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  rtc.begin();

  SD.begin(CSpin);

  if(SD.begin(CSpin))
  {
    Serial.println("SD card ready to use");
  }
  else
  {
    Serial.println("SD card failed");
    return;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  count = 0;
  distSum = 0.0;
  for(int i=0; i<=5; i++)
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(12);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(12);
    digitalWrite(trigPin, LOW);
    pingTravelTime = pulseIn(echoPin, HIGH);
    pingTravelDist = (0.034*pingTravelTime);
    distSum = distSum + (pingTravelDist/2.0);

    delay(12000);
  }

  distAvg = distSum/5.0;  //avg distance(in cm) from the sensor in approx every min

  if(distAvg > 1 && distAvg<15)   //set the distance range according to need
  {
    myFile = SD.open("final.txt", FILE_WRITE);

    if(myFile)
    {
      myFile.print(rtc.getDateStr());
      myFile.print(",");
      myFile.print("1");
      myFile.print(",");
      myFile.println(rtc.getMonthStr());
      myFile.close();

      Serial.print(rtc.getTimeStr());
      Serial.print(",");
      Serial.println("near");

    }

    else
    {
      Serial.println("failed to open the file");
    }

  }

}
