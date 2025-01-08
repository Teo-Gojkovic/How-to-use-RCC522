# How to use RCC522 with Arduino

## Required Components

- Arduino Uno, Nano, or Mega
- MFRC522 RFID Module
- Jumper wires
- Breadboard
- x2 LEDs (different colors)
- x2 220Ω resistors

## Wiring

|MFRC522 |Arduino Uno |Arduino Nano |Arduino Mega |
|:------:|:----------:|:-----------:|:-----------:|
|GND     |GND         |GND          |GND          |
|VCC     |3,3V        |3,3V         |3,3V         |
|MOSI    |11          |11           |51           |
|MISO    |12          |12           |50           |
|SCK     |13          |13           |52           |
|SDA     |10          |10           |10           |
|RST     |9           |9            |9            |

![RC522 wiring arduino diagram](/diagrams/arduino_rc522.jpg)

## How to use

After completing the wiring, the first step is to upload the ``simple_read.ino`` sketch to your Arduino board.

Once uploaded, scan your RFID card or tag. The program will display the **UID** (*Unique Identifier*) of the card.

For example, you might see something like this:

```txt
Card UID : 07 0A F5 A6
```

Convert your code into decimal numbers : <br>
>    07 = 7 <br>
>    0A = 10 <br>
>    F5 = 245 <br>
>    A6 = 166 <br>

Open the ``access.ino`` sketch. Replace all occurrences of ``X`` in line 5 with the decimal values of your UID :
```ino
const byte bonUID[4] = {X, X, X, X}; 
```

become

```ino
const byte bonUID[4] = {7, 10, 245, 166}; 
```

## Congratulations !

You’ve successfully set up the RC522 RFID module with your Arduino! Your setup should now recognize your specific RFID card or tag.

## Autor
[![Teo GOJKOVIC](https://img.shields.io/badge/Teo_GOJKOVIC-222e45?style=for-the-badge&logo=github&logoColor=white)](https://github.com/Teo-Gojkovic)