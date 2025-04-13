# Security-Alert-System-Hardware-


# 🔐 Security Alert System using Arduino

This project is a basic yet powerful **Security Alert System** built using **Arduino Uno**, **PIR Motion Sensor**, **Ultrasonic Sensor**, **Buzzer**, and an **LCD Display**. It is designed to detect intrusions or movement and provide instant feedback both visually (on LCD) and audibly (via buzzer).

## 📌 Features

- 🚨 **Motion Detection** using PIR Sensor
- 📏 **Distance Measurement** using Ultrasonic Sensor (HC-SR04)
- 🔊 **Real-time Alerts** using a Buzzer
- 📺 **LCD Display** shows distance to the object
- 💡 Expandable and suitable for home/college security applications

---

## 🛠️ Components Used

| Component         | Quantity |
|------------------|----------|
| Arduino Uno       | 1        |
| PIR Motion Sensor | 1        |
| Ultrasonic Sensor (HC-SR04) | 1 |
| Piezo Buzzer      | 1        |
| 16x2 LCD Display  | 1        |
| 10k Resistor / Potentiometer | 1 (used for LCD contrast, optional) |
| Breadboard        | 1        |
| Jumper Wires      | As needed |

---

## 📌 Circuit Connections

### Ultrasonic Sensor (HC-SR04)
- **VCC** → 5V
- **GND** → GND
- **TRIG** → Digital Pin 3
- **ECHO** → Digital Pin 4

### PIR Motion Sensor
- **VCC** → 5V
- **GND** → GND
- **OUT** → Digital Pin 2

### Buzzer
- **+ve (long leg)** → Digital Pin 5  
- **-ve (short leg)** → GND

### LCD (16x2)
| LCD Pin | Arduino |
|---------|---------|
| VSS     | GND     |
| VDD     | 5V      |
| V0      | Middle pin of Potentiometer (or GND for low contrast) |
| RS      | Pin 12  |
| RW      | GND     |
| E       | Pin 11  |
| DB4     | Pin 10  |
| DB5     | Pin 9   |
| DB6     | Pin 8   |
| DB7     | Pin 7   |
| A (LED+) | 5V     |
| K (LED-) | GND    |

---

## 🚀 How It Works

1. System remains in **Idle Mode**, monitoring motion using the PIR sensor.
2. If motion is detected, the **ultrasonic sensor** calculates the distance to the object.
3. The **buzzer** is activated.
4. The **LCD** displays the message: `"Intruder Detected!"` and shows the distance in cm.
5. After a few seconds, the system resets and returns to idle.

---

## 💻 Code

The code is provided in the [main.ino](main.ino) file (you can add this name when you upload the code to GitHub). Make sure to have the `LiquidCrystal` library installed. It comes by default with the Arduino IDE.

---

## 🧠 Future Enhancements

- Add a **GSM module** for SMS alerts
- Integrate with **IoT platforms** for remote monitoring
- Add **camera** or **RFID** for verification
- Add **LED indicators** for silent alerts

---

## 👨‍💻 Author

- Devang Gandhi
- Project for College Security/IoT Lab
- GitHub: Dev4057 (https://github.com/Dev4057)



This project is open-source and available under the MIT License.




