#include <WiFi.h>
#include <esp_now.h>
#include <DW3000.h> // Include your UWB library

#define NODE_ID 0  // Change this for each node: 0, 1, 2, 3

// UWB setup
DW3000 dw; // Replace with your library's initialization if different

// ESP-NOW peer (receiver MAC address)
uint8_t receiverMAC[] = {0x24, 0x6F, 0x28, 0xAB, 0xCD, 0xEF}; // Replace with your receiver ESP32's MAC address

typedef struct {
    int senderID;   // Sender Node ID
    int targetID;   // Target Node ID
    float distance; // Calculated distance
} DistanceData;

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);

    // ESP-NOW Initialization
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }
    esp_now_peer_info_t peerInfo;
    memcpy(peerInfo.peer_addr, receiverMAC, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;
    if (esp_now_add_peer(&peerInfo) != ESP_OK) {
        Serial.println("Failed to add peer");
        return;
    }

    // Initialize UWB module
    if (!dw.begin()) {
        Serial.println("Failed to initialize UWB");
        while (1);
    }
    dw.setup();
    Serial.printf("Node N%d ready\n", NODE_ID);
}

void loop() {
    DistanceData data;
    data.senderID = NODE_ID;

    // Measure distances to other nodes
    for (int targetID = 0; targetID < 4; targetID++) {
        if (targetID == NODE_ID) continue;

        // Perform ToF ranging
        float distance = dw.measureTo(targetID); // Replace with your UWB library's function
        if (distance > 0) {
            data.targetID = targetID;
            data.distance = distance;

            // Send data via ESP-NOW
            esp_err_t result = esp_now_send(receiverMAC, (uint8_t *)&data, sizeof(data));
            if (result == ESP_OK) {
                Serial.printf("Sent: N%d -> N%d: %.2f m\n", NODE_ID, targetID, distance);
            } else {
                Serial.println("Error sending ESP-NOW data");
            }
        }
    }
    delay(1000); // Adjust based on desired measurement frequency
}
