void entradas(){

  //Leitura das entradas dos conversores ADC
  //O valor de entrada tem 24 bits de resolução
  
  if (Sensor1.update()) {
    HxADC_In[0] = Sensor1.getData();
  }

  if (Sensor2.update()) {
    HxADC_In[1] = Sensor2.getData();
  }

   sensorTeto = map(HxADC_In[0], 8386500, 8387318, 0, 13);
   sensorLastro = map(HxADC_In[1], 8386500, 8387318, 0, 13);

   int Int_Teto = sensorTeto;
   int Int_Lastro = sensorLastro;
   int Int_set_point_Teto = set_point_Teto;
   int Int_set_point_Lastro = set_point_Lastro;

   AnimTermTeto = map(Int_Teto, 0, Int_set_point_Teto, 0, 62);
   AnimTermLastro = map(Int_Lastro, 0, Int_set_point_Lastro, 0, 62);

  //Leitura das entradas digitais
  //Utilizar o Array Digital_In[0] a Digital_In[3] no software para controle
  Digital_In[0] = !digitalRead(pin_X1);
  Digital_In[1] = !digitalRead(pin_X2);
  Digital_In[2] = !digitalRead(pin_X3);
  
  if (analogRead(pin_X4) > 100){
    Digital_In[3] = 0;
  }else{
    Digital_In[3] = 1;
  }
}
