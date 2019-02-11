#ifndef PDCONTROLLER_H
#define PDCONTROLLER_H

class PDController{
    private:
        
        float error;
        float lastError;

    public:
        PDController(float kP, float kD);
        PDController();
        void setError(float error);
        float getOutput();
        float kP;
        float kD;
        
};
#endif