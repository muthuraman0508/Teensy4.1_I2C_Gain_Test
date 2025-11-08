#include <Audio.h>
#include <Wire.h>
#include <SD.h>
// #include <USBHost_t36.h>
// USBHost myusb;

#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioPlaySdWav playSdWav1; // xy=158,203
AudioMixer4 mixer1;        // xy=366,200
AudioOutputI2S2 i2s2_1;    // xy=571,201
AudioConnection patchCord1(playSdWav1, 0, mixer1, 0);
AudioConnection patchCord2(mixer1, 0, i2s2_1, 0);
// GUItool: end automatically generated code
#define SDCARD_CS_PIN BUILTIN_SDCARD
void setup()
{
  Serial.begin(115200);
  Serial3.begin(9600);
  delay(400);
  // myusb.begin();
  while (!Serial && millis() < 3000)
    ;
  pinMode(6, OUTPUT);
  digitalWrite(6, HIGH);
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  AudioMemory(8);
  delay(200);
  if (!SD.begin(SDCARD_CS_PIN))
  {
    Serial.println("Unable to access the SD card");
    return;
  }
  delay(200);
  mixer1.gain(0, 1);
  delay(200);
  Serial.println("Setup done");
}
void loop()
{
  playSdWav1.play("buzzer.wav");
  delay(200);
  while (playSdWav1.isPlaying())
    ;
  Serial.println("paly has done");
  delay(2000);
  playSdWav1.play("beep.wav");
  delay(200);
  while (playSdWav1.isPlaying())
    ;
  // Serial.println("paly has done");
  // playSdWav1.play("beep.wav");
  // delay(200);
  // while (playSdWav1.isPlaying())
  //   ;
  // Serial.println("paly has done");
  delay(5000);
}
