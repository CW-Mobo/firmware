#include <Arduino.h>
#include <Wire.h>

#include "config.h"
#include "servos.h"
#include "motores.h"
#include "controle.h"

void setup() {

    Serial.begin(115200);

    // ===== I2C =====

    Wire.begin(SDA_PIN, SCL_PIN);

    // ===== COMPONENTES =====

    inicializarServos();
    inicializarMotores();
    inicializarControle();

    Serial.println("Sistema pronto!");
}

void loop() {

    atualizarControle();

    delay(20);
}