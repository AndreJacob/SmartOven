void imprimir()
{
 // Utilizando essa parte pra imprimir variaveis a cada 5 segundos
    Serial.println("");
    //Serial.print("incrementoTeto: ");
    //Serial.println(incrementoTeto); 
    Serial.print("set_point_Teto: ");
    Serial.println(set_point_Teto); 
    Serial.print("sensorTeto: ");
    Serial.println(sensorTeto); 
    Serial.print("valorTeto: ");
    Serial.println(valorTeto); 
    //Serial.print("Out1 PID Teto: ");
    //Serial.println(Out[0]);
    Serial.print("Histerese Teto: ");
    Serial.println(HistereseTeto); 

    Serial.println(" ----------------------------");

    Serial.println("");
    //Serial.print("incrementoLastro: ");
    //Serial.println(incrementoLastro); 
    Serial.print("set_point_Lastro: ");
    Serial.println(set_point_Lastro); 
    Serial.print("sensorLastro: ");
    Serial.println(sensorLastro); 
    Serial.print("valorLastro: ");
    Serial.println(valorLastro); 
    //Serial.print("Out1 PID Lastro: ");
    //Serial.println(Out[1]);
    Serial.print("Histerese Lastro: ");
    Serial.println(HistereseLastro); 
    Serial.println("");

    Serial.println(" ----------------------------");
    Serial.print("Modo de Controle: ");
    Serial.println(ModoControle); 
    Serial.print("Tempo de Vapor: ");
    Serial.println(TempoVapor); 
    Serial.print("Status da Lampada: ");
    Serial.println(StatusLampada);
    Serial.print("Status do Vapor: ");
    Serial.println(StatusVapor); 

    //Serial.print("Segundos Lampada: ");
    //Serial.print(segundosLampada); 
    //Serial.print(" Tempo Lampada: ");
    //Serial.print(TempoLampada);
    //Serial.print(" Status Lampada ");
    //Serial.print(StatusLampada);
    //Serial.print(" auxLampada ");
    //Serial.println(auxLampada);

    //Serial.println(" ----------------------------");

    //Serial.print("Anim Teto 0 ate 62:  ");
    //Serial.print(AnimTermTeto);
    //Serial.print(" Anim Lastro 0 ate 62: ");
    //Serial.print(AnimTermLastro);

    Serial.println(" ----------------------------");
}