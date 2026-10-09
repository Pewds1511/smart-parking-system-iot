# Smart Parking System Using IoT 🚗⚡

An automated, IoT-based real-time parking slot monitoring and management system. This project employs sensor technology and an ESP32 microcontroller to detect vehicle occupancy in individual parking bays and stream live availability data over Wi-Fi to a connected dashboard and local displays.

---

## 📌 Overview

Searching manually for parking spaces causes severe traffic congestion, excessive fuel consumption, and unnecessary delays in urban environments. The **Smart Parking System** automates the tracking of parking spaces by monitoring each slot individually. The real-time occupancy state is processed locally and broadcast to an IoT cloud platform, enabling drivers and facility managers to instantly identify available spaces.

---

## 🚀 Key Features

* **Automated Slot Detection:** Real-time occupancy sensing using IR / Ultrasonic sensors across individual bays.


* **Live Status Telemetry:** Continuous state updates (`AVAILABLE` vs. `OCCUPIED`) sent over Wi-Fi.


* **Dual Display Output:** Slot status visualization via physical hardware indicators (LEDs / LCD / OLED) and cloud-based IoT dashboards.


* **Capacity Tracking:** Dynamic calculation of open slots based on total system capacity ($\text{Available} = \text{Total} - \text{Occupied}$).


* **Modular & Scalable:** Readily expandable to incorporate more bays, automated barriers, and reservation modules.



---

## 🏗️ System Architecture

The project is structured into a multi-layer IoT architecture:

```text
[ Parking Slots (S1 - S4) ]
     │ (IR / Ultrasonic Sensors)
     ▼
[ Sensing Layer ]
     │
     ▼
[ Processing Layer: ESP32 ] ────► [ Local Indicators: LEDs / LCD / Buzzer ]
     │
     │ (Wi-Fi / Internet)
     ▼
[ Communication Layer ]
     │
     ▼
[ Cloud / Data Layer ] (Firebase / ThingSpeak / Blynk / MQTT Broker)
     │
     ▼
[ User Interface ] (Web Dashboard / Mobile App)

```

1. **Sensing Layer:** IR or Ultrasonic sensors installed at individual slots to identify vehicle presence.


2. **Processing Layer:** An ESP32 microcontroller collects sensor signals, executes state logic, and updates status indicators.


3. **Communication Layer:** Integrated Wi-Fi module connects the edge controller to the network infrastructure.


4. **Cloud / Data Layer:** IoT server/database (e.g., Firebase, ThingSpeak, Blynk, or MQTT broker) handles ingestion and storage.


5. **Application / UI Layer:** End-user dashboards and visual displays present live slot availability.



---

## 🛠️ Hardware & Software Stack

### Hardware Components

* **Microcontroller:** ESP32 Development Board (Wi-Fi enabled)


* **Sensors:** IR Sensors / HC-SR04 Ultrasonic Sensors


* **Indicators & Display:** 16x2 LCD (with I2C) or OLED display, Red/Green LEDs, Active Buzzer


* **Prototyping:** Breadboard, Jumper wires, Regulated Power Supply



### Software & Protocols

* **Development Environment:** Arduino IDE


* **Programming Languages:** C / Embedded C++


* **IoT Protocols & Platforms:** Wi-Fi, MQTT / HTTP, Firebase Realtime Database, ThingSpeak, or Blynk



---

## ⚙️ How It Works

1. A vehicle arrives and enters an empty parking slot (e.g., Slot `S1`).


2. The slot sensor detects the vehicle's presence and changes its logic state.


3. The ESP32 processes the signal, updates the local display (e.g., turns the slot LED red), and flags the slot as `OCCUPIED`.


4. The ESP32 transmits the payload over Wi-Fi to the configured IoT platform / cloud database.


5. Remote web dashboards and local digital boards reflect the updated count:
$$\text{Available Slots} = \text{Total Slots} - \text{Occupied Slots}$$



6. When the vehicle exits, the sensor detects an empty bay and resets the state to `AVAILABLE`.



---

## 🔮 Future Enhancements

* **Mobile App & Slot Booking:** Remote pre-booking and parking reservation systems.


* **Automated Access Control:** RFID reader or ANPR (Automatic Number Plate Recognition) for automated boom barrier operation.


* **Digital Payments:** Integrated payment collection via UPI, QR codes, or digital wallets.


* **AI Demand Forecasting:** Predictive parking analytics to optimize city parking capacity during peak intervals.
