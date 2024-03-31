Files and folders of my Oven project

I used a modified Britânia brand kitchen oven. There are two resistors installed. One at the top described as Teto. Another at the bottom described as Lastro. Each of these resistors works together with a Type J Thermocouple Sensor next to it. So I have 02 sensors, one for the ceiling and another for the ballast where the temperature readings are taken. For 127 V activation I used FOTEK SSR-40 solid state relays. 3-32VDC input and 24-380VAC outputs work very well.

This project was made with ESP32 and OPPLER Hardware OPS012. Communication between the Bettwen Hardware (OPPLER OPS012 with ESP32) and (HMI DWIN DMG80480C070_15WTR) was done via RS232. I would like to have this communication via RS485. I couldn't do RS485 communication. Before arriving at this hardware, I did the project with Arduino and Raspberry Pi. This project is capable of working under any temperature control.



Some videos of the process are on Instagram: https://www.instagram.com/automacao84/

Some ways to find the components

1) Db9 Male Connector With Terminal For Serial Cable Ihm And Clp Rs232 
https://www.google.com/search?q=Conector+Db9+Macho+Com+Borne+P%2F+Cabo+Serial+Ihm+E+Clp +Rs232 and what = CONECOR+DB9+MALE+COM+TERMINAL+P%2F+CABLE+SERIAL+HMI+E+CLP+RS232 & GS_LCRP = EGZJAHJVBWUYBGGGAEEEUYOTIJCAEQUMIMIGAMIGHATHZSA-MAIQUMQUMQUMQUMQUMQUMQUMQUMQUMQUGHZSA-MAIQUMQUMQ UMIGHAIMA-AHBGGE 8

2) Converter Rs232 Ttl Max3232 Serial Db9 Female Arduino Nodemcu
OPS012 Opller - Industrial Shield https://opller.com/pt/produtos/ops012/

3) ESP32 
https://pt.aliexpress.com/w/wholesale-ESP32.html?spm=a2g0o.productlist.search.0

4) Solid State Relays 
https://pt.aliexpress.com/w/wholesale-Rele-De-Estado-S%C3%B3lido-Ssr%2525252d40da-40a-250v-3%2525252d32v.html?spm=a2g0o.home. search.0

5) HMI DWIN DMG80480C070_15WTR 
https://pt.aliexpress.com/w/wholesale-HMI-DWIN-DMG80480C070_15WTR.html?spm=a2g0o.productlist.search.0

6) Source 127VAC/24VAC 
https://pt.aliexpress.com/item/1005005446104614.html?spm=a2g0o.order_list.order_list_main.34.3084caa4dqtV64&gatewayAdapt=glo2bra


I made this other version of the project, with online activation that in the future I want to place the files in another branch. This version has a video on LinkedIn: https://www.linkedin.com/feed/update/urn:li:activity:7071414505255112704/

Some parts of the project you will see in Portuguese.