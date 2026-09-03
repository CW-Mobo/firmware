#include "servos.h"
#include "config.h"

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// ===== CONFIGURAÇÃO DOS SERVOS =====

ServoConfig base  = {0, 280, 420, 350};
ServoConfig ombro = {1, 280, 420, 350};
ServoConfig cotov = {2, 280, 420, 350};
ServoConfig garra = {3, 300, 420, 350};

// ===== INICIALIZAÇÃO =====

void inicializarServos() {
    pwm.begin();
    pwm.setPWMFreq(PWM_FREQUENCY);

    pwm.setPWM(base.canal, 0, base.atual);
    pwm.setPWM(ombro.canal, 0, ombro.atual);
    pwm.setPWM(cotov.canal, 0, cotov.atual);
    pwm.setPWM(garra.canal, 0, garra.atual);
}

// ===== MOVIMENTAÇÃO SEGURA =====

void moverServoSeguro(ServoConfig &servo, int alvo) {

    alvo = constrain(alvo, servo.min, servo.max);

    if (abs(alvo - servo.atual) > 2) {

        if (alvo > servo.atual) {
            servo.atual += 2;
        } else {
            servo.atual -= 2;
        }
    }

    pwm.setPWM(servo.canal, 0, servo.atual);
}