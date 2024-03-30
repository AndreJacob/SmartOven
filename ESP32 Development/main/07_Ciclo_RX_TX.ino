// AQUI PRECISO FAZER TESTES COM O TEMPO PARA MELHOR A TAXA DE ESCRITA NA IHM
void ciclo_rx_tx()
{
  // ..................... TEMPORIZADOR (10) - AUXILIA CICLO RX E TX ENTRE IHM E ESP32 ........................................................................
  
  End_Time[10] = millis();
  Elapsed_Time[10] = End_Time[10] - Start_Time[10];
   
  if (Elapsed_Time[10] < 50){  // Nos 50 ms iniciais - Esp32 escreve na IHM
    Esp32_para_hmi(); 
    }
  else
  {
    hmi_para_Esp32(); // A partir 50 ms iniciais - IHM escreve no Esp32
  }

  if (Elapsed_Time[10] >= 1000){ 
    Start_Time[10] = millis(); 
  }

} 