 
void hmi_para_Esp32()
{
  if (Serial1.available())
  {   
    for (int i = 0; i <= 9; i++) //5A A5 06 83 55 00 01 00 01 Exemplo de estrutura recebida // alterado
    {
      Buffer[i] = Serial1.read();
        
      switch (Buffer[4])
      {
        case 0x52: // Leitura Setpoint Teto vindo da IHM
        {
          Serial.print("Inteiro Teto: "); 
          byte byteBaixo = Buffer[8];
          byte byteAlto = Buffer[7];
          int inteiroTeto = (byteAlto << 8)| byteBaixo;
          set_point_Teto = inteiroTeto;
          Serial.println(inteiroTeto);
          break;
        }

        case 0x53: // Leitura Setpoint Lastro vindo da IHM
        {
          Serial.print("Inteiro Lastro: "); 
          byte byteBaixo = Buffer[8];
          byte byteAlto = Buffer[7];
          int inteiroLastro = (byteAlto << 8)| byteBaixo;
          set_point_Lastro = inteiroLastro;
          Serial.println(inteiroLastro); 
          break;
        }

        case 0x55: // Leitura botão on/off vindo da IHM
        {
          Serial.print("botao_ON_OFF: "); 
          byte byteBaixo = Buffer[8];
          byte byteAlto = Buffer[7];
          botao_ON_OFF = (byteAlto << 8)| byteBaixo;
          Serial.println(botao_ON_OFF); 

          if (Buffer[8] == 1) // Se o botão está em ON deixa o circuito predisposto a Ligar
          {
            seletor = 1;
          }
          if (Buffer[8] == 0)     // Se o botão está em OFF desliga todas as saídas digitais
          if ((Buffer[8] == 0)||(set_point_Teto == 0)&&(set_point_Lastro == 0))     // Se o botão está em OFF desliga todas as saídas digitais
          {
            seletor = 0;  
            digitalWrite(pin_Y1, LOW); // Relé Teto
            digitalWrite(pin_Y2, LOW); // Relé Lastro   
            digitalWrite(pin_Y3, LOW); // Relé Lampada
            digitalWrite(pin_Y4, LOW); // Relé Vapor (Somente a Solenoide)  
            pinMode(pin_Y5, OUTPUT);   // Coifa
            pinMode(pin_Y6, OUTPUT);   // Beep    
          }
          break;
        }

        case 0x56: // Leitura botão lampada vindo da IHM
        {
          Serial.print("statusLampada: "); 
          byte byteBaixo = Buffer[8];
          byte byteAlto = Buffer[7];
          inteiroStatusLampada = (byteAlto << 8)| byteBaixo;
          StatusLampada = inteiroStatusLampada;
          Serial.println(StatusLampada); 
          break;
        }

        case 0x57: // Leitura botão vapor vindo da IHM
        {
          Serial.print("statusVapor: "); 
          byte byteBaixo = Buffer[8];
          byte byteAlto = Buffer[7];
          int inteiroStatusVapor = (byteAlto << 8)| byteBaixo;
          StatusVapor = inteiroStatusVapor;
          Serial.println(inteiroStatusVapor); 
          break;
        }

        case 0x58: // Leitura Incremento de PID Teto vindo da IHM
        {
          Serial.print("Inteiro PID Teto: "); 
          byte byteBaixo = Buffer[8];
          byte byteAlto = Buffer[7];
          int inteiroPIDTeto = (byteAlto << 8)| byteBaixo;
          incrementoTeto = inteiroPIDTeto;
          Serial.println(inteiroPIDTeto);  
          break;
        }

        case 0x59: // Leitura Incremento de PID Lastro vindo da IHM
        {
          Serial.print("Inteiro PID Lastro: "); 
          byte byteBaixo = Buffer[8];
          byte byteAlto = Buffer[7];
          int inteiroPIDLastro = (byteAlto << 8)| byteBaixo;
          incrementoLastro = inteiroPIDLastro;
          Serial.println(inteiroPIDLastro); 
          break;
        }

        case 0x60: // Leitura Histerese Teto vindo da IHM
        {
          Serial.print("Inteiro Histerese Teto: "); 
          byte byteBaixo = Buffer[8];
          byte byteAlto = Buffer[7];
          int inteiroHistereseTeto = (byteAlto << 8)| byteBaixo;
          HistereseTeto = inteiroHistereseTeto;
          Serial.println(inteiroHistereseTeto);
          break;
        }

        case 0x61: // Leitura Histerese Lastro vindo da IHM
        {
          Serial.print("Inteiro Histerese Lastro: "); 
          byte byteBaixo = Buffer[8];
          byte byteAlto = Buffer[7];
          int inteiroHistereseLastro = (byteAlto << 8)| byteBaixo;
          HistereseLastro = inteiroHistereseLastro;
          Serial.println(inteiroHistereseLastro); 
          break;
        }

        case 0x62: // Leitura Modo de Controle vindo da IHM
        {
          Serial.print("Modo de Controle: "); 
          byte byteBaixo = Buffer[8];
          byte byteAlto = Buffer[7];
          int inteiroModoControle = (byteAlto << 8)| byteBaixo;
          ModoControle = inteiroModoControle;
          Serial.println(inteiroModoControle);
          break;
        }

        case 0x63: // Leitura Tempo de Vapor vindo da IHM
        {
          Serial.print("Tempo Vapor em Segundos: "); 
          byte byteBaixo = Buffer[8];
          byte byteAlto = Buffer[7];
          int inteiroTempoVapor = (byteAlto << 8)| byteBaixo;
          TempoVapor = inteiroTempoVapor;
          Serial.println(inteiroTempoVapor); 
          break;
        }

        case 0x64: // Leitura Minutos programados vindo da IHM
        {
          Serial.print("Minutos Programados: "); 
          byte byteBaixo = Buffer[8];
          byte byteAlto = Buffer[7];
          int inteiroMinProgr = (byteAlto << 8)| byteBaixo;
          min1 = inteiroMinProgr;
          aux1 = min1*60;
          seg1 = 0;
          Serial.println(min1);  

          // Escrevendo na IHM os minutos do cronômetro 0x65
          byte_min_Resp[6] = highByte(min1);
          byte_min_Resp[7] = lowByte(min1);
          Serial1.write(byte_min_Resp, 8);
          break;
        }

        case 0x67: //Leitura Segundos programados vindo da IHM
        {
          Serial.print("Beep Segundos Programados: "); 
          byte byteBaixo = Buffer[8];
          byte byteAlto = Buffer[7];
          int inteiroTempoBeep = (byteAlto << 8)| byteBaixo;
          TempoBeep = inteiroTempoBeep;
          Serial.println(TempoBeep); 
          break;
        }

        case 0x68: // Leitura Segundos Coifa programados vindo da IHM
        {
           Serial.print("Segundos Programados Coifa: "); 
          byte byteBaixo = Buffer[8];
          byte byteAlto = Buffer[7];
          int inteiroTempoCoifa = (byteAlto << 8)| byteBaixo;
          TempoCoifa = inteiroTempoCoifa;
          Serial.println(TempoCoifa);
          break;
        }

        case 0x69: // Leitura Segundos Lampada programados vindo da IHM
        {
          Serial.print("Segundos Programados Lampada: "); 
          byte byteBaixo = Buffer[8];
          byte byteAlto = Buffer[7];
          int inteiroTempoLampada = (byteAlto << 8)| byteBaixo;
          TempoLampada = inteiroTempoLampada;
          Serial.println(TempoLampada); 
          break;
        }

        case 0x70: // Leitura botão play/pause do cronometro
        {
          Serial.print("Botao Play/Pause do Cronometro: "); 
          byte byteBaixo = Buffer[8];
          byte byteAlto = Buffer[7];
          int inteiroBotaoPlay = (byteAlto << 8)| byteBaixo;
          BotaoPlay = inteiroBotaoPlay;
          Serial.println(BotaoPlay); 
          break;
        }

      }  // Fecha Switch Case
    }    // Fecha o Looping For
  }      // Fecha Serial Avaible 
}        // Fecha a função
