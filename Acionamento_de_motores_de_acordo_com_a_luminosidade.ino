//Projeto de acionamento de motores de acordo com a luminosidade controlada através de Potenciometros. 


#include <LiquidCrystal.h> //Inclusao da biblioteca do LCD

//Definindo pinos dos periféricos de saída
#define K1 33 
#define K2 34
#define K3 35


LiquidCrystal lcd (8, 9, 4, 5, 6, 7); //Mapeamento/pinagem do LCD

//Variáveis de 16 bits que admite somente valores positivos
unsigned int red;
unsigned int green;
unsigned int blue;

//Loading/priorizando a leitura  das funções principais 
void ControlRele();
void setLCDNomes();
void startColors();

//Função de presentação de nomes no LCD
void setLCDNomes()
{
  lcd.setCursor(0, 0);
  lcd.print("Gabriel.");

  lcd.setCursor(9, 0);
  lcd.print("Bruno");
}

//Funçaõ de controle de luminosidade do LED VM com seu respectivo valor em %
void setLCDColorsRed()
{
  analogWrite (44, red);
  red = map(red, 0, 255 , 0 , 100);
  lcd.setCursor(0, 1);
  lcd.print("R=");
  lcd.print(red);
}

//Funçaõ de controle de luminosidade do LED VD com seu respectivo valor em %
void setLCDColorsGreen()
{
  analogWrite (45, green);
  green = map(green, 0, 255 , 0 , 100);
  lcd.setCursor(5, 1);
  lcd.print("G=");
  lcd.print(green);
}

//Funçaõ de controle de luminosidade do LED AZ com seu respectivo valor em %
void setLCDColorsBlue()
{
  analogWrite (46, blue);
  blue = map(blue, 0, 255 , 0 , 100);
  lcd.setCursor(10, 1);
  lcd.print("B=");
  lcd.print(blue);
}

//Mapeando os valores analógicos de entrada de 10 bits para 8 bits
void startColors()
{
  red = analogRead(A8);
  red = map(red, 0, 1023, 0, 255);

  green = analogRead(A9);
  green = map(green, 0, 1023, 0, 255);

  blue = analogRead(A10);
  blue = map(blue, 0, 1023, 0, 255);
}

//Função de acionamento dos relés de acordo com a luminosidade
void ControlRele()
{
  if (red >= 80)
  {
     digitalWrite(K1,0);  
  }

   if (red<20)
   {
    digitalWrite(K1,1);
   } 
}


//Função de inicialização do sistema
void setup() {
  lcd.begin(2, 16);
  setLCDNomes();
}

//Função de loop/repetição
void loop()
{
  startColors();
  setLCDColorsRed();
  setLCDColorsGreen();
  setLCDColorsBlue();
  ControlRele();
}
