void controlador()
{
  // setup das variaveis de PID
  ACT[0] = sensorTeto;
  SET[0] = set_point_Teto;
  ACT[1] = sensorLastro;
  SET[1] = set_point_Lastro;
  //Out[0] = Zona[0].Execute(ENABLE[0],ACT[0],SET[0]);
  //Out[1] = Zona[1].Execute(ENABLE[1],ACT[1],SET[1]);


  // Se o botão liga foi pressionado atualiza o status das saídas digitais.
  if (seletor == 1) {
    
    // ..................................................................................................................................................
   
     // ************************************************
     // MODO DE CONTROLE 0 - ON/OFF COM HISTERESE FIXA
     // ************************************************
     if (ModoControle  == 0)
    {   
        
        // ..................................................................................................................................................
        // Calculos de Output para Teto em onnoff
        if (sensorTeto < (set_point_Teto - HistereseTeto) ){ 
          valorTeto = 100; 
        }
        
        if (sensorTeto >= (set_point_Teto - HistereseTeto) ){ 
          valorTeto = 0; 
        }

        // ..................................................................................................................................................
        // Calculos de Output para Lastro onoff
        if (sensorLastro < (set_point_Lastro - HistereseLastro) ){ 
          valorLastro = 100;  
        }
        
        if (sensorLastro >= (set_point_Lastro - HistereseLastro) ){ 
          valorLastro = 0;  
        }
    
    }
    
    // *****************************************
    // MODO DE CONTROLE 01 - PID PURO
    // *****************************************
    
    if (ModoControle  == 1)
    {
      // Calculos de Output para Teto só PID
        if ((sensorTeto < set_point_Teto)&& (Aux_PID_Teto == 1))
        { 
          ENABLE[0] = 1;
          int Out_PID_Teto = Zona[0].Execute(ENABLE[0],ACT[0],SET[0]);
          //valorTeto = map(Out_PID_Teto, 0, 4095, 0, 10);

          valorTeto = set_point_Teto - sensorTeto;

          //Out[0] = Zona[0].Execute(ENABLE[0],ACT[0],SET[0]);
          //valorTeto = Out[0]; 
          Aux_PID_Teto = 0; 
        }
        // Desliga Output Teto  
        if (sensorTeto >= set_point_Teto )
        { 
          valorTeto = 0; 
          ENABLE[0] = 0;
        }
         // -------------------------------------------------------------------------
        // Calculos de Output para Lastro só PID
        if ((sensorLastro < set_point_Lastro)&& (Aux_PID_Lastro == 1))
        { 
          ENABLE[1] = 1;
          int Out_PID_Lastro = Zona[1].Execute(ENABLE[1],ACT[1],SET[1]);
          //valorLastro = map(Out_PID_Lastro, 0, 4095, 0, 10);  
          //valorLastro = Out_PID_Lastro;  

          valorLastro = set_point_Lastro - sensorLastro;

          //Out[1] = Zona[1].Execute(ENABLE[1],ACT[1],SET[1]);
          //valorLastro = Out[1]; 
          Aux_PID_Lastro = 0; 
        }
        // Desliga Output Lastro  
        if (sensorLastro >= set_point_Lastro )
        { 
          valorLastro = 0; 
          ENABLE[1] = 0;
        }
    }  
  }
}
