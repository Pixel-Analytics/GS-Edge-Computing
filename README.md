# 🚨 OrbitSafe - Sistema Inteligente de Monitoramento de Riscos Ambientais

## 📖 Descrição do Projeto

O **OrbitSafe** é uma plataforma integrada de monitoramento climático e ambiental que combina dados satelitais abertos, provenientes de instituições como NASA, INPE e ESA, com sensores físicos instalados localmente para detectar, calcular e alertar sobre riscos de queimadas e enchentes em tempo real.

A plataforma utiliza informações ambientais, como temperatura, umidade, histórico regional e dados orbitais, para gerar o **Índice de Risco OrbitSafe (IRO)**, um indicador que varia de 0 a 100 e representa o nível de risco de uma determinada região.

Quando o IRO ultrapassa níveis críticos, alertas automáticos podem ser enviados para cidadãos, órgãos da Defesa Civil, produtores rurais e demais responsáveis pela gestão de riscos, permitindo ações preventivas antes que os impactos se agravem.

Como prova de conceito, foi desenvolvido um protótipo utilizando Arduino e sensores físicos, capaz de simular o monitoramento de temperatura, fumaça e nível da água, demonstrando na prática como a coleta local de dados pode complementar as informações obtidas por satélites.

---

## 🎯 Objetivo da Solução

O OrbitSafe tem como objetivo fornecer uma solução inteligente para prevenção de desastres ambientais, integrando dados orbitais e monitoramento local para identificar riscos antes que eles se transformem em emergências.

A solução busca:

- Monitorar indicadores ambientais em tempo real;
- Detectar riscos de queimadas e enchentes;
- Calcular automaticamente o Índice de Risco OrbitSafe (IRO);
- Emitir alertas preventivos para a população e órgãos responsáveis;
- Apoiar a tomada de decisão baseada em dados;
- Reduzir impactos sociais, ambientais e econômicos causados por desastres naturais.

---

## 🔧 Componentes Utilizados

### Hardware

- Arduino Uno R3
- Sensor de Temperatura TMP36
- Sensor de Fumaça MQ-2
- Potenciômetro (simulando sensor de nível da água)
- Display LCD 16x2 I2C
- LED Verde
- LED Amarelo
- LED Vermelho
- Buzzer
- Resistores
- Protoboard
- Jumpers

### Software

- Arduino IDE
- Tinkercad Circuits

### Fontes de Dados (Versão Completa da Plataforma)

- NASA
- INPE
- ESA
- APIs meteorológicas e ambientais

---

## ⚙️ Explicação do Funcionamento

O OrbitSafe foi concebido para funcionar em duas camadas complementares.

### 🛰️ Camada Orbital

Responsável pela coleta de dados provenientes de fontes abertas como NASA, INPE e ESA, incluindo informações meteorológicas, climáticas e ambientais.

Esses dados são utilizados para compor o Índice de Risco OrbitSafe (IRO), que varia de 0 a 100.

### 📡 Camada Local

Representada neste projeto pelo protótipo em Arduino, responsável pela coleta de dados diretamente no ambiente monitorado através de sensores de temperatura, fumaça e nível da água.

A combinação das informações locais e orbitais permite uma avaliação mais precisa dos riscos ambientais.

---

### 🔥 Monitoramento de Queimadas

O sensor TMP36 monitora a temperatura do ambiente.

#### Faixas de operação:

| Temperatura | Status |
|------------|---------|
| Abaixo de -10°C | Emergência (Frio Extremo) |
| -10°C até 50°C | Normal |
| 51°C a 80°C | Atenção |
| Acima de 80°C | Emergência |

Além da temperatura, o sensor MQ-2 é utilizado para detectar a presença de fumaça.

#### Faixas de operação:

| Nível de Fumaça | Status |
|----------------|---------|
| Até 180 | Normal |
| 181 a 250 | Atenção |
| Acima de 250 | Emergência |

Quando níveis elevados de fumaça são detectados, o sistema interpreta a situação como um possível foco de incêndio ou queimada.

---

### 🌊 Monitoramento de Enchentes

O nível da água é simulado através de um potenciômetro.

#### Faixas de operação:

| Nível da Água | Status |
|--------------|---------|
| Até 50% | Normal |
| 51% a 80% | Atenção |
| Acima de 80% | Emergência |

---

### 🚨 Sistema de Alertas

#### 🟢 Status Normal

- LED Verde aceso
- Buzzer desligado
- LCD exibindo status normal

#### 🟡 Status de Atenção

- LED Amarelo aceso
- Buzzer realiza 3 bipes rápidos
- LCD exibe mensagens de alerta correspondentes ao sensor responsável

#### 🔴 Status de Emergência

- LED Vermelho aceso
- Buzzer permanece ativo continuamente
- LCD exibe o tipo de risco identificado (queimada, fumaça intensa, enchente ou frio extremo)

---

## 📊 Índice de Risco OrbitSafe (IRO)

O Índice de Risco OrbitSafe (IRO) é um indicador que varia de 0 a 100 e representa a probabilidade de ocorrência de eventos ambientais críticos em determinada região.

O cálculo considera fatores como:

- Temperatura ambiente;
- Umidade do ar;
- Histórico climático regional;
- Presença de fumaça;
- Nível da água;
- Dados orbitais e meteorológicos.

### Classificação do IRO

| IRO | Nível |
|------|--------|
| 0 – 30 | Baixo |
| 31 – 60 | Moderado |
| 61 – 80 | Alto |
| 81 – 100 | Crítico |

Quando o índice atinge níveis elevados, o sistema pode gerar alertas preventivos para cidadãos, agricultores e órgãos da Defesa Civil.

---

## 🔌 Estrutura do Circuito

### Sensor de Temperatura TMP36

| TMP36 | Arduino |
|--------|----------|
| VCC | 5V |
| OUT | A1 |
| GND | GND |

### Sensor de Fumaça MQ-2

| MQ-2 | Arduino |
|-------|----------|
| AOUT | A0 |
| VCC | 5V |
| GND | GND |

### Sensor de Nível da Água (Potenciômetro)

| Potenciômetro | Arduino |
|---------------|----------|
| Terminal Esquerdo | GND |
| Terminal Central | A2 |
| Terminal Direito | 5V |

### LEDs e Buzzer

| Componente | Pino |
|------------|------|
| LED Verde | 8 |
| LED Amarelo | 9 |
| LED Vermelho | 10 |
| Buzzer | 11 |

### Display LCD I2C

| LCD | Arduino |
|------|----------|
| SDA | A4 |
| SCL | A5 |
| VCC | 5V |
| GND | GND |

---

## ▶️ Instruções de Execução

### Simulação no Tinkercad

1. Acesse o circuito:

https://www.tinkercad.com/things/g3TYtt12eJY-magnificent-migelo-hango?sharecode=vR8i0kqLzCggmxpKCbgx_QOKjVCRaO0SfaeoFGTqaZY

2. Clique em **Start Simulation**.

3. Utilize os sensores para simular situações de risco:
   - Ajuste o TMP36 para aumentar ou reduzir a temperatura;
   - Ajuste o potenciômetro para simular o aumento do nível da água;
   - Ajuste o sensor MQ-2 para simular a presença de fumaça.

4. Observe as respostas do sistema através:
   - LEDs de status;
   - Buzzer;
   - Display LCD;
   - Monitor Serial.

---

## 🌐 Simulação do Circuito

Circuito disponível no Tinkercad:

https://www.tinkercad.com/things/g3TYtt12eJY-magnificent-migelo-hango?sharecode=vR8i0kqLzCggmxpKCbgx_QOKjVCRaO0SfaeoFGTqaZY

---

## 🔗 Repositório do Projeto

GitHub:

https://github.com/Pixel-Analytics/GS-Edge-Computing

---

## 🧠 Aplicação de Edge Computing

O OrbitSafe aplica conceitos de Edge Computing ao realizar parte do processamento diretamente nos dispositivos de monitoramento instalados em campo.

No protótipo desenvolvido, o Arduino analisa localmente os dados dos sensores e toma decisões imediatas sobre situações de risco, sem depender de servidores externos.

Essa abordagem reduz a latência, aumenta a confiabilidade do sistema e permite respostas mais rápidas em cenários críticos.

Em uma implementação completa, o processamento local atuaria em conjunto com dados satelitais provenientes de plataformas como NASA, INPE e ESA para compor o Índice de Risco OrbitSafe (IRO).

---

## 👥 Integrantes do Grupo

- Renan Carlos Silva Bonanno - RM573043
- Murillo Dourado Vieira - RM571912
- Gabriel Do Santos Perine Tardelli - RM569751
- André Peixoto Cano - RM570429
- Leonardo Yuiti Hidifira - RM569519

