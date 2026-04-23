#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <Servo.h>


const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASS";


#define BOT_TOKEN "YOUR_BOT_TOKEN"
#define CHAT_ID "YOUR_CHAT_ID"

WiFiClientSecure client;
UniversalTelegramBot bot(BOT_TOKEN, client);

Servo servo;


String currentOTP = "";
unsigned long otpTime = 0;
const int otpValidity = 30000; 

void setup() {
  Serial.begin(115200);

  servo.attach(2);
  servo.write(0);

  WiFi.begin(ssid, password);

  Serial.print("Connecting WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");

  client.setInsecure();
}

String generateOTP() {
  String otp = "";
  for (int i = 0; i < 4; i++) {
    otp += String(random(0, 10));
  }
  return otp;
}

void loop() {

  int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

  while (numNewMessages) {

    for (int i = 0; i < numNewMessages; i++) {

      String text = bot.messages[i].text;

      Serial.println("Received: " + text);

      if (text == "GET OTP") {

        currentOTP = generateOTP();
        otpTime = millis();

        bot.sendMessage(CHAT_ID, "Your OTP: " + currentOTP, "");

        Serial.println("OTP Generated: " + currentOTP);
      }

      else if (text == currentOTP) {

        if (millis() - otpTime <= otpValidity) {

          servo.write(90);
          bot.sendMessage(CHAT_ID, "Door Unlocked ", "");

          delay(5000);
          servo.write(0);

        } else {
          bot.sendMessage(CHAT_ID, "OTP Expired ", "");
        }
      }

     
      else {
        bot.sendMessage(CHAT_ID, "Unauthorized Access ", "");
      }
    }

    numNewMessages = bot.getUpdates(bot.last_message_received + 1);
  }

  delay(1000);
}
