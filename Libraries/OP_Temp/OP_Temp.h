/*
Arquivo             OP_Temp.h
Versão              V1.0
Data                20/04/2023
Autor               Alberto Degrecci / Leonardo Giannine
Contato             www.opller.com

Descrição:
  Esse biblioteca foi desenvolvida para controle de temperatura em diversas aplicações.
  Possui dois métodos de controle:
  PID - Para sistemas com respostas mais dinâmicas e hardware que aceite PWM
  On/Off - Para sistemas com respostas lentas e hardware com baixa dinâmica
*/

//Definição da chamada da biblioteca
#ifndef OP_Temp_H_INCLUDED
#define OP_Temp_H_INCLUDED

//Inclusão das bibliotecas necessárias ao controle
#include <Arduino.h>

//Criação da classe / construtor / Funções / Variáveis
class OP_Temp{
  public:
    OP_Temp(int Valor1);
    void config(bool MODE, int OUT, int oMAX, int oMIN, unsigned long SAMPLE);
    void ON_OFF(unsigned long tON, unsigned long tOFF, double hTEMP);
    void PID(double Kp, double Ki, double Kd, unsigned long tPWM);
    int Execute(bool ENABLE,double ACT, double SET);
  private:
    int _Valor1;
    bool _MODE;
    int _OUT;
    int _oMAX;
    int _oMIN;
    unsigned long _SAMPLE;
    unsigned long _tON;
    unsigned long _tOFF;
    double _hTEMP;
    double _Kp;
    double _Ki;
    double _Kd;
    unsigned long _tPWM;
    bool _ENABLE;
    double _ACT;
    double _SET;
    //Vaiáveis dedicadas ao PID
    double _PID_Error;
    unsigned long _PID_LastTime;
    double _PID_Ki_Compute;
    double _PID_Output;
    double _PID_LastInput;
    int _PID_Return;
    long _PWM_ON;
    unsigned long _TMR_PWM;
    //Variáveis dedicadas ao On/Off
    int _ON_OFF_Return;
    unsigned long _TMR_ON_OFF;
    bool _Flag;
};

#endif //OPX001_IO_H_INCLUDED