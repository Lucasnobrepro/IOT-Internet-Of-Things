/*
* Includes
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <MQTTClient.h>
 
/*
* Defines
*/
/* Caso desejar utilizar outro broker MQTT, substitua o endereco abaixo */
#define MQTT_ADDRESS   "tcp://10.0.80.231"
/* Substitua este por um ID unico em sua aplicacao */
#define CLIENTID       "ID_server"  
 
/* Substitua aqui os topicos de publish e subscribe por topicos exclusivos de sua aplicacao */
#define MQTT_PUBLISH_TOPIC     "teste/lucas"
#define MQTT_SUBSCRIBE_TOPIC   "teste/lucas   "
 
/*
*  Variaveis globais
*/
MQTTClient client;
 
/*
* Prototipos de funcao
*/
void publish(MQTTClient client, char* topic, char* payload);
int on_message(void *context, char *topicName, int topicLen, MQTTClient_message *message);
 
/*
* Implementacoes
*/
 
/* Funcao: publicacao de mensagens MQTT
 * Parametros: cleinte MQTT, topico MQTT and payload
 * Retorno: nenhum
*/
void publish(MQTTClient client, char* topic, char* payload) {
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
 
    pubmsg.payload = payload;
    pubmsg.payloadlen = strlen(pubmsg.payload);
    pubmsg.qos = 2;
    pubmsg.retained = 0;
    MQTTClient_deliveryToken token;
    MQTTClient_publishMessage(client, topic, &pubmsg, &token);
    MQTTClient_waitForCompletion(client, token, 1000L);
}
 
/* Funcao: callback de mensagens MQTT recebidas e echo para o broker
 * Parametros: contexto, ponteiro para nome do topico da mensagem recebida, tamanho do nome do topico e mensagem recebida
 * Retorno : 1: sucesso (fixo / nao ha checagem de erro neste exemplo)
*/
int on_message(void *context, char *topicName, int topicLen, MQTTClient_message *message) {
    char* payload = message->payload;
 
    /* Mostra a mensagem recebida */
    printf("Mensagem recebida! \n\rTopico: %s Mensagem: %s\n", topicName, payload);
 
    /* Faz echo da mensagem recebida */
    //publish(client, MQTT_PUBLISH_TOPIC, payload);
 
    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}

void msgs(){
  publish(client, MQTT_PUBLISH_TOPIC, "Direcao praca - 5 Km - 30 min");
  sleep(1);
  publish(client, MQTT_PUBLISH_TOPIC, "Direcao praca - 4 Km - 24 min");
  sleep(1);
  publish(client, MQTT_PUBLISH_TOPIC, "Direcao praca - 3 Km - 18 min");
  sleep(1);
  publish(client, MQTT_PUBLISH_TOPIC, "Direcao praca - 2 Km - 12 min");
  sleep(1);
  publish(client, MQTT_PUBLISH_TOPIC, "Direcao praca - 1 Km - 6 min");
  sleep(1);
  publish(client, MQTT_PUBLISH_TOPIC, "Direcao praca - 100 M - 1 min");

  sleep(1);
  publish(client, MQTT_PUBLISH_TOPIC, "Partida");
  sleep(1);

  publish(client, MQTT_PUBLISH_TOPIC, "Direcao UFC - 5 Km - 30 min");
  sleep(1);
  publish(client, MQTT_PUBLISH_TOPIC, "Direcao UFC - 4 Km - 24 min");
  sleep(1);
  publish(client, MQTT_PUBLISH_TOPIC, "Direcao UFC - 3 Km - 18 min");
  sleep(1);
  publish(client, MQTT_PUBLISH_TOPIC, "Direcao UFC - 2 Km - 12 min");
  sleep(1);
  publish(client, MQTT_PUBLISH_TOPIC, "Direcao UFC - 1 Km - 6 min");
  sleep(1);
  publish(client, MQTT_PUBLISH_TOPIC, "Direcao UFC - 100 M - 1 min");
  sleep(1);
}
 
int main(int argc, char *argv[])
{
   int rc;
   MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
 
   /* Inicializacao do MQTT (conexao & subscribe) */
   MQTTClient_create(&client, MQTT_ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
   MQTTClient_setCallbacks(client, NULL, NULL, on_message, NULL);
 
   rc = MQTTClient_connect(client, &conn_opts);
  
  char ms[10000];
  
   if (rc != MQTTCLIENT_SUCCESS)
   {
       printf("\n\rFalha na conexao ao broker MQTT. Erro: %d\n", rc);
       exit(-1);
   }
 
   MQTTClient_subscribe(client, MQTT_SUBSCRIBE_TOPIC, 0);
 
   while(1)
   {
       /*
        * o exemplo opera por "interrupcao" no callback de recepcao de 
        * mensagens MQTT. Portanto, neste laco principal eh preciso fazer
        * nada.
        */

      //printf("Digite mensagem:\n");
      //scanf("%[^\n]%*c", ms);
      //publish(client, MQTT_PUBLISH_TOPIC, ms);
    msgs();
   }
}