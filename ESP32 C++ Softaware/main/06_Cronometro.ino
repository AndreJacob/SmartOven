void cronometro()
{
 
  // ..................... TEMPORIZADOR (00) - AUXILIA A CHAMADA DO PID................................................................................
  // Início do calculo de milissegundos para a chamada do pid
  End_Time[0] = millis();
  Elapsed_Time[0] = End_Time[0] - Start_Time[0];

  // Aqui zera o contador de milissegundos do pid    
  if (Elapsed_Time[0] >= 250){ 
    Start_Time[0] = millis(); 
    Aux_PID_Teto = 1; 
    Aux_PID_Lastro = 1;

  }

  
 
  // ..................... TEMPORIZADOR (01) - EMULA O PWM ................................................................................................
  
  // Aqui é criado o "cont" que emula o PWM
  End_Time[1] = millis() / 1000;
  Elapsed_Time[1] = End_Time[1] - Start_Time[1];
  cont = Elapsed_Time[1];
  
  if (cont >= 10){
    Start_Time[1] = millis()/ 1000;
  }
  // ..................... TEMPORIZADOR (02) - AUXILAR PARA A LAMPADA .....................................................................................
  
      /* CRONÔMETRO PARA 	A LAMPADA - A CADA VEZ QUE O BOTÃO LAMPADA FOR PRESSIONADO ELA LIGA POR 
   TEMPO CONFIGURADO E DESLIGA PRESSIONANDO NOVAMENTE OU POR TEMPO */
  /*
  if ((StatusLampada == 1) && (auxLampada == 0)) {
    lampada_start_time = millis(); 
    auxLampada = 1; // Liga a lâmpada
    saidaLampada = 1;
  }

  if (aux1 == 1) {
    segundosLampada = (millis() - lampada_start_time) / 1000; 

    if ((segundosLampada >= TempoLampada) && (auxLampada == 1)) {
      auxLampada = 0; // Desliga a lâmpada
      saidaLampada = 0;

      inteiroStatusLampada = 0;
      StatusLampada = 0;
      //byte_ps_Lampada[6] = highByte(0);
      //byte_ps_Lampada[7] = lowByte(0);
      //Serial1.write(byte_ps_Lampada, 8); // 0x56
    }
  }
  if (StatusLampada == 0) {  
    saidaLampada = 0;
  }
  */
  // ..................... TEMPORIZADOR (03) - AUXILIA CALCULO PARA CONSUMO .............................................................................
  
  // CALCULO DO CONSUMO 
  End_Time[3] = millis() / 1000;
  Elapsed_Time[3] =  End_Time[3] -  Start_Time[3];
  segundo = Elapsed_Time[3];

  if (segundo >= 60){
      minuto = minuto + 1;
      minConsumo = minConsumo + 1;
      Start_Time[3] = millis()/ 1000;
  }

  if (minuto >= 60){
      hora = hora + 1;
      minuto = 0;
  }
  
  custo = ((minConsumo/60)*(0.64*1.2));
  kwh =   ((minConsumo/60) * 1.2);
  
  // ..................... TEMPORIZADOR (04) - AUXILIA CRONOMETRO REGRESSIVO DO FORNO........................................................................
  
  if ((seletor == 1) && (BotaoPlay == 1)){
    
    End_Time[4] = millis();
    Elapsed_Time[4] = End_Time[4] - Start_Time[4]; 
    cont1 = Elapsed_Time[4] ;
    min1 = aux1/60;
    seg1 = aux1 % 60;
  
    if (cont1 >= 1000){
      Start_Time[4] = millis(); 
      aux1 = aux1 - 1;                   
    }

    if (min1 < 0)
    {
      min1 = 0;
    }
    if (seg1 < 0)
    {
      seg1 = 0;
    }
	} 

  // ..................... TEMPORIZADOR (05) - AUXILIA CRONOMETRO PARA O BEEP DO FORNO ........................................................................
  
  if ((min1 == 0) && (seg1 == 1) && (auxBeep == 0)) // Pega o tempo inicial para contagem do Beep
  { 
    Start_Time[5] =  millis() / 1000;
    auxBeep = 1;
  }
  if (auxBeep == 1) // Enquanto Beep ligado conta os segundos
  { 
    End_Time[5] = millis() / 1000;
    Elapsed_Time[5] = End_Time[5] - Start_Time[5];
    segundosBeep = Elapsed_Time[5];
    
    if (segundosBeep < TempoBeep)   // Se o tempo for menor do que o tempo programado liga o beep
    {
      saidaBeep = 1;
    } 
    else                            // Se o tempo for maior ou igual, desliga o beep
    {
      saidaBeep = 0;
      auxBeep = 0;
    } 
  }
  // ..................... TEMPORIZADOR (06) - AUXILIA CRONOMETRO PARA O VAPOR ........................................................................
  // CRONÔMETRO PARA O VAPOR - A CADA VEZ QUE O BOTÃO VAPOR E PRESSIONADO ELE LIGA O TEMPO QUE FOI PROGRAMADO EM IHM CONFIGURAÇÕES

  if ((StatusVaporAnterior != StatusVapor) && (auxVapor == 0)) // Pega o tempo inicial para contagem do vapor
  { 
    StatusVaporAtual = StatusVapor;
    Start_Time[6] =  millis() / 1000;
    auxVapor = 1;
  }
  if (StatusVaporAnterior != StatusVaporAtual) // Enquanto status atual e diferente do anterior conta os segundos
  { 
    End_Time[6] = millis() / 1000;
    Elapsed_Time[6] = End_Time[6] - Start_Time[6];
    segundosVapor = Elapsed_Time[6];
    

    if (segundosVapor < TempoVapor)   // Se o tempo for menor do que o tempo programado liga o vapor
    {
      Serial.println("Ligar Vapor");
      saidaVapor = 1;
    } 
    else                             // Se o tempo for maior ou igual, desliga o vapor e coloca o status anterior igual o atual
    {
      StatusVaporAnterior = StatusVapor;
      saidaVapor = 0;
      auxVapor = 0;
    } 
  }

  // ..................... TEMPORIZADOR (07) - AUXILIA IMPRESSAO NO MONITOR SERIAL PARA ACOMPANHAR OS DADOS................................................
  End_Time[7] = millis();
  Elapsed_Time[7] = End_Time[7] - Start_Time[7];

  // Aqui zera o contador de milissegundos do pid    
  if ((Elapsed_Time[7] >= 2901)&&(enviar == 1))
  { 
    //imprimir();
    enviar = 0; 
    Start_Time[7] = millis(); 
  }
  
  if ((Elapsed_Time[7] <= 2900)&&(enviar == 0)){ 
    enviar = 1; 
  }
 //Serial.println(Elapsed_Time[7]);

  // ..................... TEMPORIZADOR (08) - AUXILIA CRONOMETRO PARA A COIFA DO FORNO ........................................................................
  // Cronômetro para acionamento da COIFA - Aciona toda vez que o forno for ligado ou após a injeção de vapor por tempo programavel (Exemplo 20 seg)

  
  if (((saidaVapor == 1)||(seletor == 1)) && (auxCoifa == 0)) // Pega o tempo inicial para contagem da Coifa
  { 
    Start_Time[8] =  millis() / 1000;
    auxCoifa = 1;
  }

  if ((saidaVapor == 1)||(seletor == 1)) // Enquanto seletor 1 ou Saida VApor = 1 liga a conta o tempo da coifa
  { 
    End_Time[8] = millis() / 1000;
    Elapsed_Time[8] = End_Time[8] - Start_Time[8];
    segundosCoifa = Elapsed_Time[8];

    if(segundosCoifa > 100)  // segurança para nunca estourar a palavra
    {
    	segundosCoifa == 100;
    }
  }
    
  if (segundosCoifa < TempoCoifa)   // Se o tempo for menor do que o tempo programado liga a Coifa
  {
    saidaCoifa = 1;
    //Serial.println("Ligar Coifa");
  } 
  else                      // Se o tempo for maior ou igual, desliga o coifa 
  {
    saidaCoifa = 0;
  } 
    
  if(saidaVapor == 0)       // se o vapor e desligado impede que a coifa ligue novamente
  {
    auxCoifa = 3;
  }

  if((saidaVapor == 1) && (auxCoifa == 3))  // Se o vapor liga novamente predispoe a condição da coifa ligar de novo
  {
    auxCoifa = 0;
  }
 // ..................... TEMPORIZADOR (09) - AUXILIA CRONOMETRO PARA ANIMAÇÕES DO TERMOMETRO DO FORNO ........................................................................

  // Contador para as animações do termometro

  End_Time[9] = millis();
  Elapsed_Time[9] = End_Time[9] - Start_Time[9];
  term = Elapsed_Time[9];
  
  if (term >= 250){
    Anim_01 = Anim_01 + 1;
    Start_Time[9] = millis();

    if (Anim_01 >= 13){
      Anim_01 = 0;
    }
  }
} 

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------
