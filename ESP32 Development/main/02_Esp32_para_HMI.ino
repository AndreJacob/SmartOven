 void Esp32_para_hmi() {
  
  // Usar essa Estrutura para setar paginas
  //byte_setpage[9] = 2;
  //Serial1.write(byte_setpage,10);

   // Escrevendo Ligado ou Desligado no botao Vapor 0x71
  //const char teste = "T";
  //byte_String[7] = teste;
  Serial1.write(byte_String, 8);  // 0x76

  // Escrevendo na IHM o sensor Teto 0x50
  int t = sensorTeto;
  byteTeto[6] = highByte(t);  
  byteTeto[7] = lowByte(t);
  Serial1.write(byteTeto, 9);
  
  // Escrevendo na IHM o sensor Lastro 0x51
  int k = sensorLastro;
  byteLastro[6] = highByte(k);  
  byteLastro[7]= lowByte(k);
  Serial1.write(byteLastro, 8);
  
 // int EscreveTeto = set_point_Teto;
  //set_byteTeto[7] = highByte(EscreveTeto);
  //set_byteTeto[8] = lowByte(EscreveTeto);
  //Serial1.write(set_byteTeto,9); 
  
  // Escrevendo na IHM os minutos do cronômetro 0x65
  byte_min_Resp[6] = highByte(min1);
  byte_min_Resp[7] = lowByte(min1);
  Serial1.write(byte_min_Resp, 8);

  // Escrevendo na IHM os segundos do cronômetro 0x66
  byte_seg_Resp[6] = highByte(seg1);
  byte_seg_Resp[7] = lowByte(seg1);
  Serial1.write(byte_seg_Resp, 8);
  
  // Escrevendo Ligado ou Desligado no botao ONOFF 0x71
  byte_resp_Seletor[6] = highByte(seletor);
  byte_resp_Seletor[7] = lowByte(seletor);
  Serial1.write(byte_resp_Seletor, 8);  // 0x71

  // Escrevendo Ligado ou Desligado no botao Lampada 0x71
  byte_resp_Lamp[6] = highByte(StatusLampada);
  byte_resp_Lamp[7] = lowByte(StatusLampada);
  Serial1.write(byte_resp_Lamp, 8);  // 0x72

  // Escrevendo Ligado ou Desligado no botao Vapor 0x71
  byte_resp_Vapor[6] = highByte(saidaVapor);
  byte_resp_Vapor[7] = lowByte(saidaVapor);
  Serial1.write(byte_resp_Vapor, 8);  // 0x73
  
  //******************************************************************************
  if(seletor == 0){
    // Escrevendo Animação Termometro Teto no botao Vapor 0x74
    byte_Term_Teto[6] = highByte(AnimTermTeto);
    byte_Term_Teto[7] = lowByte(AnimTermTeto);
    Serial1.write(byte_Term_Teto, 8);  // 0x74
  }

  if((seletor == 1)&&(sensorTeto < set_point_Teto)){
    // Escrevendo Animação Termometro Teto no botao Vapor 0x74
    byte_Term_Teto[6] = highByte(Anim_01);
    byte_Term_Teto[7] = lowByte(Anim_01);
    Serial1.write(byte_Term_Teto, 8);  // 0x74
  }

    if((seletor == 1)&&(sensorTeto >= set_point_Teto)){
    // Escrevendo Animação Termometro Teto no botao Vapor 0x74
    byte_Term_Teto[6] = highByte(62);
    byte_Term_Teto[7] = lowByte(62);
    Serial1.write(byte_Term_Teto, 8);  // 0x74
  }
   //******************************************************************************

  if(seletor == 0){
   // Escrevendo Animação Termometro LAstro no botao Vapor 0x75
    byte_Term_Lastro[6] = highByte(AnimTermLastro);
    byte_Term_Lastro[7] = lowByte(AnimTermLastro);
    Serial1.write(byte_Term_Lastro, 8);  // 0x75
  }

  if((seletor == 1)&&(sensorLastro < set_point_Lastro)){
    // Escrevendo Animação Termometro LAstro no botao Vapor 0x75
    byte_Term_Lastro[6] = highByte(Anim_01);
    byte_Term_Lastro[7] = lowByte(Anim_01);
    Serial1.write(byte_Term_Lastro, 8);  // 0x75
  }

  if((seletor == 1)&&(sensorLastro >= set_point_Lastro)){
    // Escrevendo Animação Termometro LAstro no botao Vapor 0x75
    byte_Term_Lastro[6] = highByte(62);
    byte_Term_Lastro[7] = lowByte(62);
    Serial1.write(byte_Term_Lastro, 8);  // 0x75
  }
}
