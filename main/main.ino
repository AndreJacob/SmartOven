// SOFTWARE CELMAQ - VERSÃO 1.11 

/*
1) Fazer a chamada de todas as variaveis no mesmo (arquivo.h). ok
2) Diminuir os IFs com switch case ok
3) Acertar o PID fazendo analogico com map
4) Criar uma rotina Controlador ok
5) modo controle somente onoff com histerese ok
6) melhorar tags ok
*/

#include <HX711_ADC.h>
#include <OP_Temp.h> 
#include "Variaveis.h"

//Definição dos pinos do controlador
//Saidas digiais
#define pin_Y1 13  // Teto
#define pin_Y2 12  // Lastro
#define pin_Y3 27  // Lampada
#define pin_Y4 26  // Caldeira
#define pin_Y5 25  // Coifa
#define pin_Y6 33  // Buzer

//Entradas digitais
#define pin_X1 15  
#define pin_X2 14
#define pin_X3 39
#define pin_X4 36

//Entradas de temperatura 
const int pin_DOUT1 = 18;        // Teto
const int pin_SCK1 = 5;
const int pin_DOUT2 = 19;        // Lastro
const int pin_SCK2 = 4;

//Variaveis para controle das entradas e saidas
bool Digital_Out[6];
bool Digital_In[4];
int Analog_In[2];
int Analog_Out[2];
long HxADC_In[2];

//chamada da instância de leitura do conversor ADC
HX711_ADC Sensor1(pin_DOUT1, pin_SCK1);    // Teto
HX711_ADC Sensor2(pin_DOUT2, pin_SCK2);    // Lastro

void setup() {

  //Inicializa comunicações -  No momento ainda não usando a 485
  Serial.begin(115200); // (USB)
  Serial1.begin(115200); // (TTL)
  //Serial2.begin(115200); //(485)

  //Inicializa hardware
  pinMode(pin_X1, INPUT);
  pinMode(pin_X2, INPUT);
  pinMode(pin_X3, INPUT);
  //A leitura do X4 é feita como analógica

  pinMode(pin_Y1, OUTPUT); // Rele Teto
  pinMode(pin_Y2, OUTPUT); // Rele Lastro
  pinMode(pin_Y3, OUTPUT); // Lampada
  pinMode(pin_Y4, OUTPUT); // Caldeira
  pinMode(pin_Y5, OUTPUT); // Coifa
  pinMode(pin_Y6, OUTPUT); // Beep
  
  // Inicia com todas as saídas digitais desligadas
  digitalWrite(pin_Y1, LOW);
  digitalWrite(pin_Y2, LOW);
  digitalWrite(pin_Y3, LOW);
  digitalWrite(pin_Y4, LOW);
  digitalWrite(pin_Y5, LOW);
  digitalWrite(pin_Y6, LOW);

  //Inicialização da biblioteca HX711 - Sensores Termopar
  Sensor1.begin();
  Sensor1.start(2000, false);
  Sensor1.setCalFactor(1);

  Sensor2.begin();
  Sensor2.start(2000, false);
  Sensor2.setCalFactor(1);
  
  // Chama essa rotina que configura variaveis no primeiro ciclo
  primeiro_ciclo(); 
}

void loop() {

  ciclo_rx_tx();
  ciclo_rx_tx();
  entradas();
  ciclo_rx_tx();
  ciclo_rx_tx();
  controlador();
  saidas();
  ciclo_rx_tx();
  ciclo_rx_tx();
  cronometro();
  ciclo_rx_tx();
  ciclo_rx_tx();
  delay(10);

}
