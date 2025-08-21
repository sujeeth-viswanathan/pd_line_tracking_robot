/************************************************************
 * PD Line Tracking Robot - OSOYOO V2.1 Platform
 * Developed by: [Your Name]
 * Description: Line following robot using IR sensors + PD control
 ************************************************************/

#include <Arduino.h>

// ==== Sensor Pin Definitions ====
#define LFSensor_0 A0  // Leftmost
#define LFSensor_1 A1
#define LFSensor_2 A2  // Center
#define LFSensor_3 A3
#define LFSensor_4 A4  // Rightmost

// ==== Motor Pin Definitions ====
#define speedPinR 9    // Right motor PWM
#define RightMotorDirPin1 12
#define RightMotorDirPin2 11
#define speedPinL 6    // Left motor PWM
#define LeftMotorDirPin1 7
#define LeftMotorDirPin2 8

// ==== Speed Settings ====
#define BASE_SPEED 150
#define FAST_SPEED 180
#define MID_SPEED 140
#define SLOW_SPEED 130

// ==== Sensor Pattern Constants ====
const String STRAIGHT = "00100";
const String FAR_LEFT = "10000";
const String LEFT = "01100";
const String FAR_RIGHT = "00001";
const String RIGHT = "00110";
const String STOP_LINE = "11111";

// ==== PD Controller Gains ====
const float Kp = 25.0;
const float Kd = 15.0;
int lastError = 0;

// ==== Setup ====
void setup() {
  // Motor pins
  pinMode(RightMotorDirPin1, OUTPUT);
  pinMode(RightMotorDirPin2, OUTPUT);
  pinMode(speedPinR, OUTPUT);
  pinMode(LeftMotorDirPin1, OUTPUT);
  pinMode(LeftMotorDirPin2, OUTPUT);
  pinMode(speedPinL, OUTPUT);

  // Stop motors at boot
  stopMotors();

  // Serial for debugging
  Serial.begin(9600);
}

// ==== Loop ====
void loop() {
  pdLineTracking();
}

// ==== Read Sensor Pattern ====
String readSensorPattern() {
  char sensor[6];
  for (int i = 0; i < 5; i++) {
    int pin = LFSensor_0 + i;
    sensor[i] = digitalRead(pin) == LOW ? '1' : '0'; // Assuming active-low sensors
  }
  sensor[5] = '\0';
  return String(sensor);
}

// ==== Compute Line Error from Sensor ====
int computeError(String pattern) {
  int weights[5] = {-200, -100, 0, 100, 200};
  int error = 0;
  for (int i = 0; i < 5; i++) {
    if (pattern[i] == '1') {
      error += weights[i];
    }
  }
  return error;
}

// ==== PD Controller Logic ====
void pdLineTracking() {
  String sensorPattern = readSensorPattern();
  Serial.println(sensorPattern);

  if (sensorPattern == "00000") {
    stopMotors();
    return;
  }

  int error = computeError(sensorPattern);
  int correction = Kp * error + Kd * (error - lastError);
  lastError = error;

  int leftSpeed = constrain(BASE_SPEED + correction, 0, 255);
  int rightSpeed = constrain(BASE_SPEED - correction, 0, 255);

  setMotorSpeed(leftSpeed, rightSpeed);
  moveForward();
}

// ==== Motor Control Functions ====
void setMotorSpeed(int left, int right) {
  analogWrite(speedPinL, left);
  analogWrite(speedPinR, right);
}

void moveForward() {
  digitalWrite(RightMotorDirPin1, HIGH);
  digitalWrite(RightMotorDirPin2, LOW);
  digitalWrite(LeftMotorDirPin1, HIGH);
  digitalWrite(LeftMotorDirPin2, LOW);
}

void stopMotors() {
  digitalWrite(RightMotorDirPin1, LOW);
  digitalWrite(RightMotorDirPin2, LOW);
  digitalWrite(LeftMotorDirPin1, LOW);
  digitalWrite(LeftMotorDirPin2, LOW);
}

