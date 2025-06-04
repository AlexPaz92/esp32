#include <Arduino.h>
#include <LedControl.h>

const int DIN_PIN = 23;   // Ajusta a tu conexion
const int CS_PIN  = 5;    // Ajusta a tu conexion
const int CLK_PIN = 18;   // Ajusta a tu conexion

LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, 1);

void setup() {
    lc.shutdown(0, false);
    lc.setIntensity(0, 8);    // brillo medio
    lc.clearDisplay(0);

    randomSeed(analogRead(0));
}

void loop() {
    // cambia la intensidad para dar un efecto "psicodelico"
    for (int intensity = 0; intensity < 16; intensity++) {
        lc.setIntensity(0, intensity);
        mostrarPatronAleatorio();
        delay(50);
    }
    for (int intensity = 15; intensity >= 0; intensity--) {
        lc.setIntensity(0, intensity);
        mostrarPatronAleatorio();
        delay(50);
    }
}

void mostrarPatronAleatorio() {
    for (int row = 0; row < 8; row++) {
        byte valor = random(256); // numero aleatorio de 0 a 255
        lc.setRow(0, row, valor);
    }
}

