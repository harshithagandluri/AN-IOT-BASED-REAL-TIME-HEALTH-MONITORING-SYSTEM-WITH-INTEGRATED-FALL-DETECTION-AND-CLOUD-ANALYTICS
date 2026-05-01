#include <WiFi.h>
#include <Wire.h>
#include <ThingSpeak.h>
#include <MAX30100_PulseOximeter.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <MPU6050.h>
#include <time.h>

const char* ssid = "jothi";
const char* password = "9704704266";
unsigned long channelID =  3299389;
const char* writeAPIKey = "HD823VXKED2PGAI9";

WiFiClient client;
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

PulseOximeter pox;
MPU6050 mpu;

#define PULSE_SENSOR 34
#define GREEN_LED 25
#define YELLOW_LED 26
#define RED_LED 27
#define BUZZER 14

float maxHeart = 0;
float pulseHeart = 0;
float spo2 = 0;
float confidence = 0;
int fallStatus = 0;
String healthStatus = "Normal"; 
unsigned long lastUpload = 0;
unsigned long lastHealthCheck = 0;
const char* ntpServer = "pool.ntp.org";

void connectWiFi() {
  WiFi.begin(ssid, password);
  int counter = 0;
  while(WiFi.status() != WL_CONNECTED && counter < 20) {
    delay(500);
    counter++;
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  
  Wire.begin(21,22);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  
  connectWiFi();
  configTime(0,0,ntpServer);
  ThingSpeak.begin(client);

  if (!pox.begin()) {
    Serial.println("MAX30100 failed");
  }
  mpu.initialize();
}

void checkFall() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax,&ay,&az);

  float accel = sqrt(pow(ax,2) + pow(ay,2) + pow(az,2))/16384.0;

  if(accel > 2.5) {
    fallStatus = 1;
    digitalWrite(RED_LED,HIGH);
    tone(BUZZER,2000,1000);
    Serial.println("FALL DETECTED!");
  }
  else{
    fallStatus = 0;
    digitalWrite(RED_LED,LOW);
    noTone(BUZZER);
  }
}

void readPulseSensor() {
  int value = analogRead(PULSE_SENSOR);
  pulseHeart = map(value,0,4095,60,120);
}

void updateDisplay(float confidence) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.printf("MAX HR: %.1f\n", maxHeart);
  display.printf("Pulse HR: %.1f\n", pulseHeart);
  display.printf("SpO2: %.1f%%\n", spo2);
  display.printf("Conf: %.1f%%", confidence);
  display.printf("Status: %s\n", healthStatus.c_str());
  display.display();
}

void healthLogic() {

  // Health status logic
  if(spo2 >= 95)
  healthStatus = "Normal";
  else if(spo2 >= 90)
    healthStatus = "Warning";
  else
    healthStatus = "Critical";

  confidence = 100 - abs(maxHeart - pulseHeart);

  if(confidence >= 80) {
    digitalWrite(GREEN_LED,HIGH);
    digitalWrite(YELLOW_LED,LOW);
  } else {
    digitalWrite(GREEN_LED,LOW);
    digitalWrite(YELLOW_LED,HIGH);
  }

  if(spo2 > 0 && spo2 < 92) {
    digitalWrite(RED_LED,HIGH);
    tone(BUZZER,1500, 500);
  } else if (spo2 >= 92) {
    digitalWrite(RED_LED,LOW);
    noTone(BUZZER);
  }

  updateDisplay(confidence);
}

void uploadThingSpeak() {
  ThingSpeak.setField(1,maxHeart);
  ThingSpeak.setField(2,pulseHeart);
  ThingSpeak.setField(3,spo2);
  ThingSpeak.setField(4,confidence);
  ThingSpeak.setField(5,fallStatus);
  ThingSpeak.writeFields(channelID,writeAPIKey);
}

void loop() {
  pox.update();
  
  if(millis() - lastHealthCheck > 1000) {
    maxHeart = pox.getHeartRate();
    spo2 = pox.getSpO2();
    readPulseSensor();
    checkFall();
    healthLogic();
    lastHealthCheck = millis();
  }

  if(millis() - lastUpload > 20000) {
    uploadThingSpeak();
    lastUpload = millis();
  }
}
