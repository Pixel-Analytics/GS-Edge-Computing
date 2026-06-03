#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

// ==========================
// LCD
// ==========================

Adafruit_LiquidCrystal lcd(0);

// ==========================
// LEDs
// ==========================

const int LED_VERDE = 8;
const int LED_AMARELO = 9;
const int LED_VERMELHO = 10;

// ==========================
// Buzzer
// ==========================

const int BUZZER = 11;

// ==========================
// Sensores
// ==========================

const int SENSOR_FUMACA = A0;
const int SENSOR_TEMP = A1;
const int SENSOR_NIVEL = A2;

// ==========================
// Controle de Estado
// ==========================

String ultimoStatus = "";

// ==========================
// Bipes de Atenção
// ==========================

void alertaAtencao()
{
  for (int i = 0; i < 3; i++)
  {
    tone(BUZZER, 1000);
    delay(150);

    noTone(BUZZER);
    delay(150);
  }
}

// ==========================
// Tela de Sensores
// ==========================

void mostrarSensores(float temperatura, int nivelAgua, int fumaca)
{
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print((int)temperatura);
  lcd.print("C");

  lcd.setCursor(8, 0);
  lcd.print("A:");
  lcd.print(nivelAgua);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("F:");
  lcd.print(fumaca);

  delay(1500);
}

void setup()
{
  Serial.begin(9600);

  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  lcd.begin(16, 2);
  lcd.setBacklight(1);

  lcd.setCursor(0, 0);
  lcd.print("ORBITSAFE");

  lcd.setCursor(0, 1);
  lcd.print("Inicializando");

  delay(2000);
}

void loop()
{
  // ==========================
  // LEITURA DOS SENSORES
  // ==========================

  int leituraTemp = analogRead(SENSOR_TEMP);
  float tensao = leituraTemp * (5.0 / 1023.0);
  float temperatura = (tensao - 0.5) * 100.0;

  int leituraNivel = analogRead(SENSOR_NIVEL);
  int nivelAgua = map(leituraNivel, 0, 1023, 0, 100);

  int nivelFumaca = analogRead(SENSOR_FUMACA);

  // ==========================
  // SERIAL
  // ==========================

  Serial.println("========================");
  Serial.println("ORBITSAFE");
  Serial.println("========================");

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" C");

  Serial.print("Nivel da Agua: ");
  Serial.print(nivelAgua);
  Serial.println("%");

  Serial.print("Nivel de Fumaca: ");
  Serial.println(nivelFumaca);

  // ==========================
  // TELA DE SENSORES
  // ==========================

  mostrarSensores(
    temperatura,
    nivelAgua,
    nivelFumaca
  );

  // ==========================
  // RESET
  // ==========================

  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERMELHO, LOW);

  // ==========================
  // CLASSIFICAÇÃO
  // ==========================

  bool incendioEmergencia = temperatura > 80;
  bool incendioAtencao = temperatura > 50 && temperatura <= 80;

  bool enchenteEmergencia = nivelAgua > 80;
  bool enchenteAtencao = nivelAgua > 50 && nivelAgua <= 80;

  bool fumacaEmergencia = nivelFumaca > 250;
  bool fumacaAtencao = nivelFumaca > 180 && nivelFumaca <= 250;

  // ==========================
  // EMERGÊNCIA
  // ==========================

  if (incendioEmergencia || enchenteEmergencia || fumacaEmergencia)
  {
    digitalWrite(LED_VERMELHO, HIGH);

    tone(BUZZER, 1500);

    ultimoStatus = "EMERGENCIA";

    Serial.println("STATUS: EMERGENCIA");

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("ORBITSAFE");

    lcd.setCursor(0, 1);

    if (fumacaEmergencia)
    {
      lcd.print("RISCO INCENDIO");
      Serial.println("FUMACA INTENSA");
    }
    else if (incendioEmergencia)
    {
      lcd.print("TEMP CRITICA");
      Serial.println("TEMPERATURA CRITICA");
    }
    else if (enchenteEmergencia)
    {
      lcd.print("RISCO ENCHENTE");
      Serial.println("RISCO DE ENCHENTE");
    }
  }

  // ==========================
  // ATENÇÃO
  // ==========================

  else if (incendioAtencao || enchenteAtencao || fumacaAtencao)
  {
    digitalWrite(LED_AMARELO, HIGH);

    if (ultimoStatus != "ATENCAO")
    {
      alertaAtencao();
      ultimoStatus = "ATENCAO";
    }

    Serial.println("STATUS: ATENCAO");

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("ORBITSAFE");

    lcd.setCursor(0, 1);

    if (fumacaAtencao)
    {
      lcd.print("FUMACA DETECT.");
      Serial.println("FUMACA DETECTADA");
    }
    else if (incendioAtencao)
    {
      lcd.print("TEMP ELEVADA");
      Serial.println("TEMPERATURA ELEVADA");
    }
    else if (enchenteAtencao)
    {
      lcd.print("AGUA ELEVADA");
      Serial.println("NIVEL DE AGUA ELEVADO");
    }
  }

  // ==========================
  // NORMAL
  // ==========================

  else
  {
    digitalWrite(LED_VERDE, HIGH);

    noTone(BUZZER);

    ultimoStatus = "NORMAL";

    Serial.println("STATUS: NORMAL");

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("ORBITSAFE");

    lcd.setCursor(0, 1);
    lcd.print("STATUS NORMAL");
  }

  Serial.println();

  delay(2000);
}