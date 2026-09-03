#ifndef SERVOS_H
#define SERVOS_H

#include <Adafruit_PWMServoDriver.h>

struct ServoConfig {
    int canal;
    int min;
    int max;
    int atual;
};

extern Adafruit_PWMServoDriver pwm;

extern ServoConfig base;
extern ServoConfig ombro;
extern ServoConfig cotov;
extern ServoConfig garra;

void inicializarServos();

void moverServoSeguro(ServoConfig &servo, int alvo);

#endif