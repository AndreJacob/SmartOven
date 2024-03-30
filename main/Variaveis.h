
// Criando Buffer e bytes para ler e escrever na IHM
unsigned char Buffer[9];
unsigned char teste[9];
#define Teto_address          0x50
#define Lastro_address        0x51
#define set_Teto_address      0x52
#define set_Lastro_address    0x53
#define ps_onoff_address      0x55
#define ps_Lampada_address    0x56
#define ps_vapor_address      0x57
#define pid_Teto_address      0x58
#define pid_Lastro_address    0x59
#define hist_Teto_address     0x60
#define hist_Lastro_address   0x61
#define modo_Contr_address    0x62
#define time_Vapor_address    0x63
#define min_Progr_address     0x64
#define min_Resp_address      0x65
#define seg_Resp_address      0x66
#define seg_Beep_address      0x67
#define seg_Coifa_address     0x68
#define seg_Lamp_address      0x69
#define play_Botao_address    0x70
#define resp_Seletor_address  0x71
#define resp_Lamp_address     0x72
#define resp_Vapor_address    0x73
#define Term_Teto_address     0x74
#define Term_Lastro_address   0x75
#define String_address        0x76

//int getpage[8];
//byte sendBuffer[] = {CMD_HEAD1, CMD_HEAD2, 0x04, CMD_READ, 0x00 , 0x14, 0x01};
//unsigned char byte_getpage[7] = {0x5A, 0xA5,0x04,0x83, 0x00 , 0x14, 0x01}; 

//Criando o framer de 10 bytes para setar pagina na IHM, copiano na biblioteca DWIN --->  sendBuffer[] = {CMD_HEAD1, CMD_HEAD2, 0x07, CMD_WRITE, 0x00, 0x84, 0x5A, 0x01, 0x00, page}; 
int setpage;
unsigned char byte_setpage[10] = {0x5A, 0xA5, 0x07, 0x82,0x00,0x84, 0x5A, 0x01, 0x00, setpage}; 

// Criando os framers com 8 bytes para ler e escrever na IHM
unsigned char   byteTeto[8] = {0x5A, 0xA5, 0x05, 0x82, Teto_address, 0x00, 0x00, 0x00};                   // 0x50
unsigned char   byteLastro[8] = {0x5A, 0xA5, 0x05, 0x82, Lastro_address , 0x00, 0x00, 0x00};              // 0x51
unsigned char   set_byteTeto[9] = {0x5A, 0xA5, 0x05, 0x82, set_Teto_address, 0x00, 0x00, 0x00, 0x00};     // 0x52
unsigned char   set_byteLastro[8] = {0x5A, 0xA5, 0x05, 0x82, set_Lastro_address , 0x00, 0x00, 0x00};      // 0x53
unsigned char   byte_ps_onoff[8] = {0x5A, 0xA5, 0x05, 0x82, ps_onoff_address, 0x00, 0x00, 0x00};          // 0x55
unsigned char   byte_ps_Lampada[8] = {0x5A, 0xA5, 0x05, 0x82, ps_Lampada_address, 0x00, 0x00, 0x00};      // 0x56
unsigned char   byte_ps_vapor[8] = {0x5A, 0xA5, 0x05, 0x82, ps_vapor_address , 0x00, 0x00, 0x00};         // 0x57
unsigned char   pid_byteTeto[8] = {0x5A, 0xA5, 0x05, 0x82, pid_Teto_address, 0x00, 0x00, 0x00};           // 0x58
unsigned char   pid_byteLastro[8] = {0x5A, 0xA5, 0x05, 0x82, pid_Lastro_address , 0x00, 0x00, 0x00};      // 0x59
unsigned char   byte_hist_Teto[8] = {0x5A, 0xA5, 0x05, 0x82, hist_Teto_address , 0x00, 0x00, 0x00};       // 0x60
unsigned char   byte_hist_Lastro[8] = {0x5A, 0xA5, 0x05, 0x82, hist_Lastro_address , 0x00, 0x00, 0x00};   // 0x61
unsigned char   byte_modo_Contr[8] = {0x5A, 0xA5, 0x05, 0x82, modo_Contr_address , 0x00, 0x00, 0x00};     // 0x62
unsigned char   byte_time_Vapor[8] = {0x5A, 0xA5, 0x05, 0x82, time_Vapor_address  , 0x00, 0x00, 0x00};    // 0x63
unsigned char   byte_min_Progr[8] = {0x5A, 0xA5, 0x05, 0x82, min_Progr_address , 0x00, 0x00, 0x00};       // 0x64
unsigned char   byte_min_Resp[8] = {0x5A, 0xA5, 0x05, 0x82, min_Resp_address , 0x00, 0x00, 0x00};         // 0x65
unsigned char   byte_seg_Resp[8] = {0x5A, 0xA5, 0x05, 0x82, seg_Resp_address , 0x00, 0x00, 0x00};         // 0x66
unsigned char   byte_seg_Beep[8] = {0x5A, 0xA5, 0x05, 0x82, seg_Beep_address  , 0x00, 0x00, 0x00};        // 0x67
unsigned char   byte_seg_Coifa[8] = {0x5A, 0xA5, 0x05, 0x82, seg_Coifa_address  , 0x00, 0x00, 0x00};      // 0x68
unsigned char   byte_seg_Lamp[8] = {0x5A, 0xA5, 0x05, 0x82, seg_Lamp_address  , 0x00, 0x00, 0x00};        // 0x69
unsigned char   byte_play_Botao[8] = {0x5A, 0xA5, 0x05, 0x82, play_Botao_address , 0x00, 0x00, 0x00};     // 0x70
unsigned char   byte_resp_Seletor[8] = {0x5A, 0xA5, 0x05, 0x82, resp_Seletor_address , 0x00, 0x00, 0x00}; // 0x71
unsigned char   byte_resp_Lamp[8] = {0x5A, 0xA5, 0x05, 0x82, resp_Lamp_address , 0x00, 0x00, 0x00};       // 0x72
unsigned char   byte_resp_Vapor[8] = {0x5A, 0xA5, 0x05, 0x82, resp_Vapor_address , 0x00, 0x00, 0x00};     // 0x73
unsigned char   byte_Term_Teto[8] = {0x5A, 0xA5, 0x05, 0x82, Term_Teto_address , 0x00, 0x00, 0x00};       // 0x74
unsigned char   byte_Term_Lastro[8] = {0x5A, 0xA5, 0x05, 0x82, Term_Lastro_address , 0x00, 0x00, 0x00};   // 0x75
unsigned char   byte_String[8] = {0x5A, 0xA5, 0x05, 0x82, String_address , 0x00, 0x00, 0x00};             // 0x76



// CRIANDO VARIÁVEIS GERAIS PARA O SISTEMA
                               
bool seletor = 0, Aux_PID_Teto = 0, Aux_PID_Lastro = 0, enviar = 1;                                                                         
int cont, segundo, minuto, hora, inteiroTeto = 0, inteiroLastro = 0, inteiroPIDTeto = 0;
unsigned long Elapsed_Time[20];
unsigned long End_Time[20];
unsigned long Start_Time[20] = {0};


int inteiroPIDLastro, botao_ON_OFF, valorTeto = 0, valorLastro = 0, tetoSetLesIncr = 0, lastroSetLesIncr, segundosVapor, StatusVaporAtual = 0, PAG =  10, AnimTermTeto, AnimTermLastro;
int cont1 = 0, seg1, min1 , end_time1, aux1, HistereseTeto,HistereseLastro, ModoControle, TempoVapor, StatusVapor, StatusLampada, StatusVaporAnterior = 0, auxVapor = 0, auxLampada = 0,term,  Anim_01;
int saidaCoifa = 0, saidaVapor = 0, auxCoifa = 0, segundosCoifa, segundosLampada, TempoCoifa = 20, saidaBeep = 0, auxBeep = 0, segundosBeep, TempoBeep = 10, TempoLampada, BotaoPlay, saidaLampada, inteiroStatusLampada;                              
float minConsumo, kwh, custo;                                              
double OutputTeto, OutputLastro, sensorTeto, sensorLastro, incrementoTeto = 0, incrementoLastro = 0, set_point_Teto = 0, set_point_Lastro = 0;      
  
// Criando ás variaveis do PID
const int N_Zonas = 2;
int Modo[2], Out[2], oMAX[2], oMIN[2], SAMPLE[2], Kp[2], Ki[2], Kd[2], tPWM[2], ENABLE[2], ACT[2], SET[2];

// Cria a instância do PID com o determinado numero de zonas (nesse caso 2)
OP_Temp Zona[N_Zonas](2);

