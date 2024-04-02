//Inclusão da biblioteca .h
//A biblioteca deve incluida logo no início do software
#include "OP_Temp.h"

//Definição do construtor
//O construtor deve ser chamado logo após a inclusão da biblioteca
OP_Temp::OP_Temp(int Valor1){
  this->_Valor1=Valor1;
}

//A função config configura o modo de controle
//No modo On/Off a saída é obrigatorialmente digital (0-1)
//No modo PID a saída pode ser analógica ou digital
void OP_Temp::config(bool MODE, int OUT, int oMAX, int oMIN, unsigned long SAMPLE){
  this->_MODE=MODE;       //Modo de controle 0 = PID; 1 = On/Off
  this->_OUT=OUT;         //Modo da saída de controle 0 = Digital; 1 = Analógico
  this->_oMAX=oMAX;       //Valor máximo para saída do controle (>oMIN & >-10000 & <10000)
  this->_oMIN=oMIN;       //Valor mínimo para saída do controle (<oMAX & >-10000 & <10000)
  this->_SAMPLE=SAMPLE;   //Tempo de atualização dos cálculos de erro
  _Valor1 = 0;
}

//A função ON_OFF configura os parâmetros de funcionamento do controle no modo On/Off
void OP_Temp::ON_OFF(unsigned long tON, unsigned long tOFF, double hTEMP){
  this->_tON=tON;          //Tempo máximo que a saída pode ficar ligada
  this->_tOFF=tOFF;        //Tempo entre acionamentos da saída
  this->_hTEMP=hTEMP;      //Histerese de tolerância do sistema
}

//A função PID configura os parâmetros de funcionamento do controle no modo PID
void OP_Temp::PID(double Kp, double Ki, double Kd, unsigned long tPWM){
  this->_Kp=Kp;         //Ganho proporcional
  this->_Ki=Ki;         //Ganho integral
  this->_Kd=Kd;         //Ganho derivativo
  this->_tPWM=tPWM;     //Período da saída PWM
}

//A função Execute deve ser executada no loop sempre que possível
//para dar dinâmica aos cálculos do controle
int OP_Temp::Execute(bool ENABLE,double ACT, double SET){
  this->_ENABLE=ENABLE;         //GHabilita controle
  this->_ACT=ACT;               //Valor da temperatura atual
  this->_SET=SET;               //Valor do setpoint de temperatura
  if ((_ENABLE == 1) && (_MODE == 0)){
    if (millis() >= (_PID_LastTime + _SAMPLE)){  
      _PID_Error = _SET - _ACT;
      _PID_Ki_Compute += (_Ki * _PID_Error);
      if (_PID_Ki_Compute >= _oMAX){
        _PID_Ki_Compute = _oMAX;
      }else if (_PID_Ki_Compute <= _oMIN){
        _PID_Ki_Compute = _oMIN;
      }
      _PID_Output = (_Kp * _PID_Error) + _PID_Ki_Compute - (_Kd * (_ACT - _PID_LastInput));
      _PID_LastTime = millis();
      _PID_LastInput = _ACT;
      if (_PID_Output >= _oMAX){
        _PID_Output = _oMAX;
      }else if (_PID_Output <= _oMIN){
        _PID_Output = _oMIN;
      }
      if (_OUT == 1){
        _PID_Return = _PID_Output;
      }else if (_OUT == 0){
        _PWM_ON = map(_PID_Output,_oMIN,_oMAX,0,_tPWM);
        if (millis() >= (_TMR_PWM + _tPWM)){
          _TMR_PWM = millis();
        }else if(millis() >= (_TMR_PWM + _PWM_ON)){ 
          _PID_Return = 0;
        }else{
          _PID_Return = 1;
        }
      }
    }
    return _PID_Return;
  }else if ((_ENABLE == 1) && (_MODE == 1)){
    if (_Flag == 1){
      if (millis() < (_TMR_ON_OFF + _tON)){
        _ON_OFF_Return = 1;
      }else if (millis() < (_TMR_ON_OFF + _tON + _tOFF)){
        _ON_OFF_Return = 0;
      }else{
        _TMR_ON_OFF = millis();
      }
    }else{
      _ON_OFF_Return = 0;
      _TMR_ON_OFF = millis();
    }
    if (_ACT < (_SET - _hTEMP)){
      _Flag = 1;
    }else if (_ACT >= _SET){
      _Flag = 0;
    }
    return _ON_OFF_Return;
  }else{
    _PID_Output = 0;
    _PID_LastTime = millis();
    _PID_LastInput = _ACT;
    _PID_Error = 0;
    _PID_Ki_Compute = 0;
    _PID_Return = 0;
    _TMR_PWM = millis();
    _Flag = 0;
    _TMR_ON_OFF =  millis();
    _ON_OFF_Return = 0;
    return _ON_OFF_Return;
  }
}