#ifndef PDCONTROLLER_H
#define PDCONTROLLER_H

class PDController{
    private:    
        float error;
        float lastError;
        float kP;
        float kD;
    public:
        PDController(float kP, float kD);
        PDController();
        void setkP(float kP);
        void setkD(float kD);
        void setError(float error);
        float getOutput();
       
};
#endif