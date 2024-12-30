#include "HomeSpan.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <HTTPClient.h>

// WiFi credentials
const char* ssid = "ISTC_Lab";
const char* password = "ISTC-LAB@CCIT.NDU";

// Server (door control system) details
const char* host = "192.168.38.69";
const uint16_t port = 1621;

// Unlock and lock command packets
uint8_t unlockCommand[] = {
    0x7E, 0x06, 0x01, 0x21, 0x82, 0xFF, 0xA2, 0x45
};

uint8_t lockCommand[] = {
    0x7E, 0x06, 0x01, 0x21, 0x83, 0xFF, 0xA3, 0x47
};

// Make.com Webhook URL
const char* webhook_url = "https://hook.eu2.make.com/ptkkd7g6v72g96xva5kmpvwcd90kd3m5";

WiFiClient client;

struct DoorLock : Service::LockMechanism {
    SpanCharacteristic* lockCurrentState;
    SpanCharacteristic* lockTargetState;

    DoorLock() : Service::LockMechanism() {
        lockCurrentState = new Characteristic::LockCurrentState(1); // 1 = 鎖定
        lockTargetState = new Characteristic::LockTargetState(1); // 1 = 鎖定
    }

    boolean update() override {
        int targetState = lockTargetState->getNewVal();
        
        if (targetState == 0) {  // 0 = 解鎖
            Serial.println("HomeKit: Unlocking the door...");
            sendCommand(unlockCommand, sizeof(unlockCommand));
            lockCurrentState->setVal(0); // 更新當前狀態為解鎖
            sendWebhookNotification("解鎖");
        } else if (targetState == 1) {  // 1 = 鎖定
            Serial.println("HomeKit: Locking the door...");
            sendCommand(lockCommand, sizeof(lockCommand));
            lockCurrentState->setVal(1); // 更新當前狀態為鎖定
            sendWebhookNotification("上鎖");
        }
        
        return true;
    }

    void sendCommand(uint8_t* command, size_t length) {
        if (!client.connect(host, port)) {
            Serial.println("Connection to door system failed.");
            return;
        }
        Serial.println("Connected to door control system");
        Serial.println("Sending command...");
        client.write(command, length);
        delay(100);
        client.stop();
        Serial.println("Command sent and connection closed");
    }

    void sendWebhookNotification(const char* action) {
        HTTPClient http;
        http.begin(webhook_url);  // 設定 Webhook URL

        // 獲取當前時間戳
        unsigned long now = millis() / 1000;
        String payload = "{\"action\":\"" + String(action) + "\", \"time\":\"" + String(now) + "\"}";

        http.addHeader("Content-Type", "application/json");  // 設置請求類型
        int httpResponseCode = http.POST(payload);  // 發送 POST 請求並傳送動作和時間戳

        if (httpResponseCode > 0) {
            Serial.printf("Webhook sent, response code: %d\n", httpResponseCode);
        } else {
            Serial.printf("Error sending webhook: %s\n", http.errorToString(httpResponseCode).c_str());
        }
        http.end();  // 結束 HTTP 連線
    }
};

void setup() {
    Serial.begin(115200);
    delay(10);

    Serial.println();
    Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    homeSpan.begin(Category::Doors, "HomeSpan Door Lock");

    // Create a new Accessory and add DoorLock service
    new SpanAccessory();
    new DoorLock(); // Create DoorLock instance

    new Service::AccessoryInformation();
    new Characteristic::Identify();
}

void loop() {
    homeSpan.poll();
}