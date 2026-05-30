# Smart Soil Monitoring System using ESP8266 (IoT Dashboard)

A real-time IoT-based soil moisture monitoring system built with ESP8266 NodeMCU and a soil moisture sensor. The system hosts a live web dashboard that displays soil moisture level, percentage, and status (Dry/Wet) over Wi-Fi.

---

##  Project Overview

This project converts the ESP8266 into a **live web server** that displays real-time soil moisture data on a mobile-friendly dashboard. Users can access the system from any device connected to the same Wi-Fi network.

The dashboard includes:
- Soil moisture percentage
- Visual progress bar
- Animated status indicator
- Dark mode UI
- Real-time auto refresh

---

##  Hardware Used

- ESP8266 NodeMCU
- Soil Moisture Sensor (Analog Output)
- Jumper Wires
- Breadboard (Optional/if needed)

---

##  Features

-  Web-based IoT dashboard
-  Real-time soil moisture percentage
-  Dry / Wet soil detection
-  Dark mode modern UI
-  Mobile responsive design
-  Auto-refresh every 1 second
-  Wi-Fi based access (local network)

---

##  How It Works

1. ESP8266 connects to Wi-Fi
2. Reads analog soil moisture value from A0 pin
3. Converts value into percentage (0–100%)
4. Hosts a web server
5. Displays live dashboard on browser

---

##  Wiring Diagram

| Soil Sensor | ESP8266 |
|-------------|----------|
| VCC         | 3.3V(5v)    |
| GND         | GND      |
| AO          | A0       |

---

##  Installation & Setup

1. Install ESP8266 board in Arduino IDE
2. Select board: NodeMCU 1.0 (ESP-12E Module)
3. Install required libraries:
   - ESP8266WiFi
   - ESP8266WebServer
4. Upload the code
5. Open Serial Monitor (115200 baud)
6. Copy IP address
7. Open IP in browser

---

##  Future Improvements

- Firebase cloud integration
- Mobile app control
- Automatic irrigation system
- AI-based watering prediction
- Remote internet access

---

##  Author

Developed by: *MANSUR ISAH*  
Project Type: IoT / Embedded Systems
