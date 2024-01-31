// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       Disparo_de_un_triac_dimmer_variador_de_potencia_AC.ino
    Created:	29/08/2023 10:03:35
    Author:     AUTO-LUISMI\LUIS M ECHEVARRIA
*/


#include <TimerOne.h>
volatile int i = 0;
volatile bool cruce = 0;
#define SalidaTriac 9
#define Detector 7
#define PotPin A3
unsigned short time_to_interrupt = 100;//tiempo en que se produciran las interuciones 
unsigned short Pot;
int dimmer;
// The setup() function runs once each time the micro-controller starts

void setup()
{
    pinMode(SalidaTriac, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(Detector), Detencion, RISING);
    Timer1.initialize(time_to_interrupt);
    Timer1.attachInterrupt(Dimer);

}

void Detencion()
{
    cruce = true;
    i = 0;
    digitalWrite(SalidaTriac, LOW);
}

void Dimer()
{
    if (cruce==true)
    {
        if (i >= dimmer)
        {
            digitalWrite(SalidaTriac, HIGH);
        }
        else
        {
            i++;
        }
    }
}

// Add the main program code into the continuous loop() function
void loop()
{
    Pot = analogRead(PotPin);
    dimmer = map(Pot, 0, 1023, 0, 83);//con la funcion map convierto de 1023 0 83

}
