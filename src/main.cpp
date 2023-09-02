#include <Arduino.h>
#include "Player.h"

Player players[5];
int numPlayers = 0;

void setup()
{
  Serial.begin(9600);

  Serial.println("Number of players: ");
  while (numPlayers < 2 || numPlayers > 5)
  {
    if (Serial.available() > 0)
    {
      numPlayers = Serial.parseInt();
    }
  }

  Serial.println("Starting game with " + String(numPlayers) + " players!");
}

void loop()
{
}