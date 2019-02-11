#include "PDController.h"

PDController::PDController(float kP, float kD){
    this->kP = kP;
    this->kD = kD;
}

void PDController::setError(float error){
    this->error = error;
}

float PDController::getOutput(){
    float output = this->kP * error + this->kD * (this->error - this->lastError);
    this->lastError = this->error;
    return output;
}


