#(ESP32 Firmware Code)

/**
 * ESP32-WROOM-32 Project Firmware
 * Features: 
 * - MPU6050 motion sensing (I2C)
 * - Wi-Fi connectivity
 * - UART debugging via CH340G
 * - Power monitoring and management
 * - Automatic programming circuit via DTR/RTS
 */

#include <Wire.h>
#include <WiFi.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

// Define Pins
#define BATTERY_PIN 34    // ADC pin to monitor LiPo battery voltage
#define TX_PIN 1          // UART TX pin
#define RX_PIN 3          // UART RX pin

// Wi-Fi Credentials (Update as needed)
const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

// MPU6050 Sensor
Adafruit_MPU6050 mpu;

// Battery voltage monitoring
float readBatteryVoltage() {
    float voltage = analogRead(BATTERY_PIN) * (3.3 / 4095.0) * 2.0; // Adjust divider ratio
    return voltage;
}

void setup() {
    Serial.begin(115200);
    Wire.begin(); // Initialize I2C for MPU6050

    // Initialize MPU6050 Sensor
    if (!mpu.begin()) {
        Serial.println("MPU6050 not found! Check wiring.");
        while (1);
    }
    Serial.println("MPU6050 initialized!");

    // Initialize Wi-Fi
    WiFi.begin(ssid, password);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(1000);
    }
    Serial.println("\nWi-Fi connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}

void loop() {
    // Read MPU6050 data
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    Serial.print("Accel X: "); Serial.print(a.acceleration.x);
    Serial.print(" Y: "); Serial.print(a.acceleration.y);
    Serial.print(" Z: "); Serial.println(a.acceleration.z);

    // Read Battery Voltage
    float batteryVoltage = readBatteryVoltage();
    Serial.print("Battery Voltage: ");
    Serial.print(batteryVoltage);
    Serial.println("V");

    delay(2000);  // Delay for readability
}
