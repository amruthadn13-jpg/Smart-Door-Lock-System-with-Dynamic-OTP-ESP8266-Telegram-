# 🔐 Smart Door Lock System with Dynamic OTP (ESP8266 + Telegram)

## 📌 Overview

This project is an **IoT-based Smart Door Lock System** built using **ESP8266**, **Servo Motor**, and a **Telegram Bot**, enhanced with **dynamic OTP generation and expiry**.

Unlike basic systems, this implementation generates a **new OTP each time** and validates it within a limited time, improving security significantly.

---

## ⚙️ Features

* Remote control using Telegram Bot
* Dynamic OTP generation
* Time-based OTP expiry (30 seconds)
* Secure access control
* Servo motor door locking mechanism
* Real-time feedback via Telegram

---

## 🧠 Project Description

This system integrates **embedded hardware**, **network communication**, and **security logic** to create a smart and secure door access system.

---

### 🔹 WiFi Connectivity

The ESP8266 connects to a WiFi network and enables communication with the Telegram servers, allowing remote control of the system.

---

### 🔹 Telegram Bot Communication

* The device continuously listens for messages from a Telegram bot
* Users interact with the system by sending commands
* The bot processes messages and responds in real time

---

### 🔹 Dynamic OTP Generation

* When the user sends `"GET OTP"`:

  * A random 4-digit OTP is generated
  * The OTP is sent to the user via Telegram
  * A timestamp is stored for validation

This ensures that every login attempt uses a **new OTP**.

---

### 🔹 OTP Verification with Expiry

* When a user sends the OTP:

  * The system checks if it matches the generated OTP
  * It also verifies if the OTP is within the **valid time (30 seconds)**

* If valid:

  * Access is granted

* If expired:

  * Access is denied

---

### 🔹 Servo Motor Control

* The servo motor acts as a door lock
* Default position: **Locked (0°)**
* On successful authentication:

  * Rotates to **90° (Unlock)**
  * After a delay → returns to **0° (Lock)**

---

### 🔹 Security Handling

* Only valid OTP within time limit is accepted
* Any incorrect or unauthorized message is rejected
* Prevents reuse of old OTPs

---

## 🔄 Working Flow

1. ESP8266 connects to WiFi
2. User sends **"GET OTP"** via Telegram
3. System generates and sends a random OTP
4. User sends the received OTP
5. System verifies:

   * OTP correctness
   * OTP validity time
6. If valid:

   * Door unlocks
   * Confirmation message sent
7. If invalid/expired:

   * Access denied message sent

---

## 🔐 Security Highlights

* Dynamic OTP generation
* Time-based OTP expiration
* No fixed password usage
* Protection against replay attacks

---

## 🧠 Learning Outcomes

* IoT system design using ESP8266
* Integration with Telegram Bot API
* Random OTP generation logic
* Time-based validation using millis()
* Servo motor control
* Secure remote access implementation

---

## 🚀 Future Enhancements

* Mobile app integration
* Multi-user authentication
* Biometric or RFID support
* Cloud database logging
* Camera-based monitoring system

---

## 👩‍💻 Author

**Amrutha D N**
