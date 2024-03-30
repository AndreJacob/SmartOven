void saidas()
{
  // ****************************** CONTROLE DAS SAÍDAS DIGITAIS FÍSICAS Y1, Y2, Y3, Y4, Y5 E Y6 ******************************************************
 
  // Comando das saídas digitais da Lampada (Independente se o forno esta ligado)
  if (StatusLampada == 1 ){          
      digitalWrite(pin_Y3, 1);  // pin_Y3 - Relé Lampada
  }
  else{
      digitalWrite(pin_Y3, 0);        
  }
  // ..................................................................................................................................................

  
  // Se o botão liga foi pressionado atualiza o status das saídas digitais.
  if (seletor == 1) {
    
    // ****************************** CONTROLE DAS SAÍDAS DIGITAIS FÍSICAS Y1, Y2, Y3, Y4, Y5 E Y6 ******************************************************

    // Comando das saídas digitais do Teto
    if (cont <  valorTeto){  
        digitalWrite(pin_Y1, 1); // pin_Y1 - Relé Teto        
    }
    else{
        digitalWrite(pin_Y1, 0);   
        }
    // ..................................................................................................................................................
    // Comando das saídas digitais do Lastro
    if (cont < valorLastro ){          
        digitalWrite(pin_Y2, 1);  // pin_Y2 - Relé Lastro
    }
    else{
        digitalWrite(pin_Y2, 0);        
        }
   
    // ..................................................................................................................................................
    // Comando das saídas digitais do Vapor (Esse é só da solenoide que controla a agua)
    if (saidaVapor == 1 ){          
        digitalWrite(pin_Y4, 1);  // pin_Y4 - Relé Solenoide Vapor
    }
    else{
        digitalWrite(pin_Y4, 0);        
        }
    // ..................................................................................................................................................
    // Comando das saídas digitais da Coifa
    if (saidaCoifa == 1 ){          
        digitalWrite(pin_Y5, 1);  // pin_Y5 - Relé Coifa
    }
    else{
        digitalWrite(pin_Y5, 0);        
        }
    // ..................................................................................................................................................
    // Comando das saídas digitais do Beep
    if (saidaBeep == 1 ){          
        digitalWrite(pin_Y6, 1);  // pin_Y6 - Relé Beep
    }
    else{
        digitalWrite(pin_Y6, 0);        
        }
    // ....................................................................................................................................................
  
  }
}
