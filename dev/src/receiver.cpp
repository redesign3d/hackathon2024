#include <WiFi.h>
#include <esp_now.h>

typedef struct {
    int senderID;   // Sender Node ID
    int targetID;   // Target Node ID
    float distance; // Calculated distance
} DistanceData;

// Callback for received ESP-NOW messages
void onDataReceive(const uint8_t *mac, const uint8_t *incomingData, int len) {
    DistanceData data;
    memcpy(&data, incomingData, sizeof(data));
    Serial.printf("Received from N%d: Distance to N%d = %.2f m\n", data.senderID, data.targetID, data.distance);

    // Send data to Teleplot
    sendToTeleplot(data.senderID, data.targetID, data.distance);
}

void sendToTeleplot(int senderID, int targetID, float distance) {
    // Teleplot expects data in the format: "variable_name value"
    char variableName[20];
    snprintf(variableName, sizeof(variableName), "N%d_to_N%d", senderID, targetID);
    Serial.printf("%s %.2f\n", variableName, distance);
}

void setup() {
    Serial.begin(115200); // Teleplot listens on this port
    WiFi.mode(WIFI_STA);

    // Initialize ESP-NOW
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }
    esp_now_register_recv_cb(onDataReceive);

    Serial.println("Receiver ready and connected to Teleplot");
}

void loop() {
    // Continuously listen for ESP-NOW messages
}
