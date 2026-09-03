#include "controle.h"
#include "servos.h"
#include "motores.h"

ControllerPtr myController = nullptr;

// ===== CONEXÃO =====

void onConnectedController(ControllerPtr ctl) {

    Serial.println("Controle conectado!");

    myController = ctl;
}

void onDisconnectedController(ControllerPtr ctl) {

    Serial.println("Controle desconectado!");

    if (myController == ctl) {
        myController = nullptr;
    }
}

// ===== INICIALIZAÇÃO =====

void inicializarControle() {

    BP32.setup(
        &onConnectedController,
        &onDisconnectedController
    );

    BP32.forgetBluetoothKeys();
}

// ===== ATUALIZAÇÃO =====

void atualizarControle() {

    BP32.update();

    if (!myController || !myController->isConnected()) {
        pararMotores();
        return;
    }

    // ===== ANALÓGICOS =====

    int rx = myController->axisRX();
    int ry = myController->axisRY();
    int lx = myController->axisX();
    int ly = myController->axisY();

    const int deadzone = 80;

    if (abs(rx) < deadzone) rx = 0;
    if (abs(ry) < deadzone) ry = 0;
    if (abs(lx) < deadzone) lx = 0;
    if (abs(ly) < deadzone) ly = 0;

    // ===== SERVOS =====

    int velX = map(rx, -512, 512, -10, 10);
    int velY = map(ry, -512, 512, -10, 10);

    moverServoSeguro(
        base,
        base.atual + velX
    );

    moverServoSeguro(
        ombro,
        ombro.atual + velY
    );

    // ===== COTOVELO =====

    if (myController->x()) {

        moverServoSeguro(
            cotov,
            cotov.atual + 3
        );
    }

    if (myController->y()) {

        moverServoSeguro(
            cotov,
            cotov.atual - 3
        );
    }

    // ===== GARRA =====

    if (myController->a()) {

        moverServoSeguro(
            garra,
            300
        );
    }

    if (myController->b()) {

        moverServoSeguro(
            garra,
            420
        );
    }

    // ===== ESTEIRA =====

    if (ly > 200) {

        frente();

    } else if (ly < -200) {

        tras();

    } else if (lx > 200) {

        direita();

    } else if (lx < -200) {

        esquerda();

    } else {

        pararMotores();
    }
}