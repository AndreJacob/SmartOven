void primeiro_ciclo(){

  // Configuração das variaveis do PID
 // [0] para Teto
  Modo[0] = 0;     //Modo de controle 0 = PID; 1 = On/Off
  Out[0] = 1;      //Modo da saída de controle 0 = Digital; 1 = Analógico
  oMAX[0] = 4095; //Valor máximo para saída do controle (>oMIN & >-10000 & <10000)
  oMIN[0] = 0;     //Valor mínimo para saída do controle (<oMAX & >-10000 & <10000)
  SAMPLE[0] = 100; //Tempo de atualização dos cálculos de erro
  Kp[0] = 2;
  Ki[0] = 1;
  Kd[0] = 0,2;
  tPWM[0] = 10000; //Período da saída PWM
  Zona[0].config(Modo[0],Out[0],oMAX[0],oMIN[0],SAMPLE[0]);
  Zona[0].PID(Kp[0],Ki[0],Kd[0],tPWM[0]);
  
  // [1] para Lastro
  Modo[1] = 0;
  Out[1] = 1;
  oMAX[1] = 4095;
  oMIN[1] = 0;
  SAMPLE[1] = 100;
  Kp[1] = 2;
  Ki[1] = 1;
  Kd[1] = 0,2;
  tPWM[1] = 10000;
  Zona[1].config(Modo[1],Out[1],oMAX[1],oMIN[1],SAMPLE[1]);
  Zona[1].PID(Kp[1],Ki[1],Kd[1],tPWM[1]);
  
  // Controle para iniciar IHM com tudo zerado e desligado as saídas digitais
  int l = 0;
  
  byteTeto[6] = highByte(0);
  byteTeto[7] = lowByte(0);
  Serial1.write(byteTeto, 8);        // 0x50
  sensorTeto = 0;

  byteLastro[6] = highByte(0);
  byteLastro[7]= lowByte(0);
  Serial1.write(byteLastro, 8);      // 0x51   
  sensorLastro = 0;

  set_byteTeto[6] = highByte(180);
  set_byteTeto[7] = lowByte(180);
  Serial1.write(set_byteTeto,9);    // 0x52 alterado
  set_point_Teto = 180;

  set_byteLastro[6] = highByte(150);
  set_byteLastro[7] = lowByte(150);
  Serial1.write(set_byteLastro, 8);  // 0x53
  set_point_Lastro = 150;

  byte_ps_onoff[6] = highByte(0);
  byte_ps_onoff[7] = lowByte(0);
  Serial1.write(byte_ps_onoff, 8);   // 0x55
  botao_ON_OFF = 0;

  byte_ps_Lampada[6] = highByte(0);
  byte_ps_Lampada[7] = lowByte(0);
  Serial1.write(byte_ps_Lampada, 8); // 0x56
  StatusLampada = 0;

  byte_ps_vapor[6] = highByte(0);
  byte_ps_vapor[7] = lowByte(0);
  Serial1.write(byte_ps_vapor, 8);   // 0x57

  pid_byteTeto[6] = highByte(20);
  pid_byteTeto[7] = lowByte(20);
  Serial1.write(pid_byteTeto, 8);    // 0x58
  incrementoTeto = 20;

  
  pid_byteLastro[6] = highByte(20);
  pid_byteLastro[7] = lowByte(20);
  Serial1.write(pid_byteLastro, 8);  // 0x59
  incrementoLastro = 20;

  byte_hist_Teto[6] = highByte(20);
  byte_hist_Teto[7] = lowByte(20);
  Serial1.write(byte_hist_Teto, 8);  // 0x60
  HistereseTeto = 20;

  byte_hist_Lastro[6] = highByte(20);
  byte_hist_Lastro[7] = lowByte(20);
  Serial1.write(byte_hist_Lastro, 8);  // 0x61
  HistereseLastro = 20;

  byte_modo_Contr[6] = highByte(1);
  byte_modo_Contr[7] = lowByte(1);
  Serial1.write(byte_modo_Contr, 8);  // 0x62
  ModoControle = 1;

  byte_time_Vapor[6] = highByte(3);
  byte_time_Vapor[7] = lowByte(3);
  Serial1.write(byte_time_Vapor, 8);  // 0x63
  TempoVapor = 3;

  byte_min_Progr[6] = highByte(59);
  byte_min_Progr[7] = lowByte(59);
  Serial1.write(byte_min_Progr, 8);    // 0x64
  min1 = 59;
  aux1 = min1*60;
  

  byte_min_Resp[6] = highByte(59);
  byte_min_Resp[7] = lowByte(59);
  Serial1.write(byte_min_Resp, 8);    // 0x65
  min1 = 59;

  byte_seg_Resp[6] = highByte(0);
  byte_seg_Resp[7] = lowByte(0);
  Serial1.write(byte_seg_Resp, 8);   // 0x66
  seg1 = 0;

  byte_seg_Beep[6] = highByte(5);
  byte_seg_Beep[7] = lowByte(5);
  Serial1.write(byte_seg_Beep, 8);   // 0x67
  TempoBeep = 5;

  byte_seg_Coifa[6] = highByte(15);
  byte_seg_Coifa[7] = lowByte(15);
  Serial1.write(byte_seg_Coifa, 8);   // 0x68
  TempoCoifa = 15;

  byte_seg_Lamp[6] = highByte(20);
  byte_seg_Lamp[7] = lowByte(20);
  Serial1.write(byte_seg_Lamp, 8);   // 0x69
  TempoLampada = 20;

  byte_play_Botao[6] = highByte(0);
  byte_play_Botao[7] = lowByte(0);
  Serial1.write(byte_play_Botao, 8);  // 0x70
  BotaoPlay = 0;

  byte_resp_Seletor[6] = highByte(seletor);
  byte_resp_Seletor[7] = lowByte(seletor);
  Serial1.write(byte_resp_Seletor, 8);  // 0x71

  byte_resp_Lamp[6] = highByte(StatusLampada);
  byte_resp_Lamp[7] = lowByte(StatusLampada);
  Serial1.write(byte_resp_Lamp, 8);  // 0x72

  byte_resp_Vapor[6] = highByte(saidaVapor);
  byte_resp_Vapor[7] = lowByte(saidaVapor);
  Serial1.write(byte_resp_Vapor, 8);  // 0x73
  
  seletor = 0;  

  //aux1 = (min1 * 60) + seg1; // auxiliar para a contagem regressiva
  seg1 = 0;

}