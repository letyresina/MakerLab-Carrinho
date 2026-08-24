# 🤖 Robô Carrinho 2WD

Projeto de desenvolvimento e documentação de um **robô móvel com chassi 2WD**, utilizando uma estrutura em acrílico, dois motores DC e duas rodas motrizes.

## 👥 Integrantes

* **Gabriel Riquetto Reis** — RM 98685
* **Leticia Cristina Gandarez Resina** — RM 98069
* **Sabrina Flores Morais** — RM 550781

---

## 📋 1. Ficha de Requisitos

### 1.1 Estrutura do Chassi

| Característica               | Especificação               |
| ---------------------------- | --------------------------- |
| Tipo                         | Chassi para robô móvel 2WD  |
| Material                     | Acrílico                    |
| Cor                          | Transparente                |
| Comprimento                  | Aproximadamente **22 cm**   |
| Largura                      | Aproximadamente **14,7 cm** |
| Peso                         | Aproximadamente **100 g**   |
| Quantidade de rodas motrizes | 2                           |
| Roda de apoio                | 1 roda boba universal       |
| Chave Liga/Desliga           | Sim                         |

---

### 1.2 Motores

| Característica               | Especificação                                 |
| ---------------------------- | --------------------------------------------- |
| Quantidade                   | **2 motores DC**                              |
| Tipo                         | Motor DC com caixa de redução                 |
| Tensão de operação           | **3 V a 6 V DC**                              |
| Disposição                   | Um motor em cada lateral do chassi            |
| Acoplamento                  | Cada motor é conectado diretamente a uma roda |
| Quantidade de discos encoder | 2                                             |

Os dois motores permitem a movimentação independente das rodas, possibilitando o deslocamento para frente, para trás e a realização de curvas por meio da diferença de acionamento entre os motores.

---

### 1.3 Alimentação

| Característica                 | Especificação                  |
| ------------------------------ | ------------------------------ |
| Suporte de alimentação         | Suporte para **4 pilhas AA**   |
| Quantidade de pilhas           | 4                              |
| Dimensões previstas do suporte | Aproximadamente **62 × 58 mm** |
| Chave de alimentação           | Liga/Desliga                   |
| Alimentação dos motores        | **3 V a 6 V DC**               |

O suporte para pilhas acompanha o kit do chassi e será utilizado como fonte de alimentação para o sistema de movimentação do robô.

---

### 1.4 Placa Controladora

A placa controladora selecionada para o projeto é uma **placa compatível com Arduino Uno R3**, baseada no microcontrolador **ATmega328P**.

| Característica                  | Especificação                         |
| ------------------------------- | ------------------------------------- |
| Placa                           | Arduino Uno R3 compatível             |
| Microcontrolador                | ATmega328P                            |
| Tensão de operação              | 5 V                                   |
| Frequência de clock             | 16 MHz                                |
| Memória Flash                   | 32 KB                                 |
| SRAM                            | 2 KB                                  |
| EEPROM                          | 1 KB                                  |
| Entradas analógicas             | 6                                     |
| Pinos digitais de entrada/saída | 14                                    |
| Pinos PWM                       | 6                                     |
| Dimensões                       | Aproximadamente **68,3 × 53 × 10 mm** |
| Peso                            | Aproximadamente **25 g**              |

A placa será responsável pelo processamento das informações recebidas pelos sensores e pelo envio dos sinais de controle para os motores através da Ponte H.

---

### 1.5 Ponte H

Para o controle dos motores será utilizado o módulo **Ponte H L298N**.

A Ponte H funciona como interface entre o Arduino e os motores DC, permitindo controlar independentemente o sentido de rotação e a velocidade dos dois motores.

| Característica                   | Especificação                       |
| -------------------------------- | ----------------------------------- |
| Modelo                           | L298N                               |
| Chip                             | ST L298N                            |
| Quantidade de motores suportados | 2 motores DC                        |
| Tensão de operação               | 4 V a 35 V                          |
| Tensão lógica                    | 5 V                                 |
| Corrente máxima                  | Até 2 A por canal                   |
| Potência máxima informada        | 25 W                                |
| Dimensões                        | Aproximadamente **43 × 43 × 27 mm** |
| Peso                             | Aproximadamente **30 g**            |

---

### 1.6 Sensor

Para a detecção de obstáculos será utilizado o sensor de distância **VL53L0X ToF (Time-of-Flight)**.

Esse sensor utiliza tecnologia Time-of-Flight para medir a distância entre o robô e objetos à sua frente, enviando as informações ao Arduino através do protocolo I²C.

| Característica        | Especificação                                 |
| --------------------- | --------------------------------------------- |
| Sensor                | VL53L0X                                       |
| Tecnologia            | Time-of-Flight (ToF)                          |
| Função                | Medição de distância e detecção de obstáculos |
| Alcance informado     | Até aproximadamente **2 metros**              |
| Comunicação           | I²C                                           |
| Tensão de alimentação | **3,3 V a 5 V**                               |
| Consumo informado     | Aproximadamente **10 mA**                     |
| Comprimento           | Aproximadamente **25 mm**                     |
| Largura               | Aproximadamente **13 mm**                     |
| Altura                | Aproximadamente **5 mm**                      |
| Posição prevista      | Região frontal do chassi                      |

> **Observação:** As dimensões do módulo VL53L0X são aproximadas e podem variar de acordo com o fabricante e a placa breakout utilizada.

---

### 1.7 Posição dos Componentes

A distribuição inicial dos principais componentes no chassi será:

| Componente          | Posição                                                         |
| ------------------- | --------------------------------------------------------------- |
| Motor DC esquerdo   | Lateral esquerda do chassi                                      |
| Motor DC direito    | Lateral direita do chassi                                       |
| Rodas motrizes      | Acopladas aos motores nas laterais                              |
| Roda boba universal | Região frontal do chassi                                        |
| Suporte para pilhas | Região central/inferior do chassi                               |
| Chave Liga/Desliga  | Região central do chassi                                        |
| Arduino Uno R3      | Região central/superior do chassi                               |
| Ponte H L298N       | Região central do chassi, próxima aos motores                   |
| Sensor VL53L0X ToF  | Região frontal do chassi, direcionado para a trajetória do robô |

A posição dos componentes poderá ser ajustada durante a montagem para garantir melhor distribuição de peso, organização dos cabos, acesso aos componentes e funcionamento adequado do sistema.

---

### 1.8 Tabela Dimensional dos Componentes

| Componente               | Comprimento |    Largura |                     Altura | Forma de fixação                                               |
| ------------------------ | ----------: | ---------: | -------------------------: | -------------------------------------------------------------- |
| Motor esquerdo           |       70 mm |      22 mm | Conforme componente do kit | Fixação lateral no chassi utilizando suporte e parafusos       |
| Motor direito            |       70 mm |      22 mm | Conforme componente do kit | Fixação lateral no chassi utilizando suporte e parafusos       |
| Arduino Uno R3           | **68,3 mm** |  **53 mm** |                  **10 mm** | Fixação com parafusos e espaçadores                            |
| Ponte H L298N            |   **43 mm** |  **43 mm** |                  **27 mm** | Fixação utilizando os furos do módulo, parafusos e espaçadores |
| Suporte para 4 pilhas AA |   **62 mm** |  **58 mm** |    Conforme suporte do kit | Fixação na região central/inferior do chassi                   |
| Sensor VL53L0X ToF       |  **~25 mm** | **~13 mm** |                  **~5 mm** | Fixação na região frontal do chassi                            |

> **Observação:** Algumas dimensões são aproximadas e poderão ser atualizadas após a medição física dos componentes durante a montagem.

---

### 1.9 Componentes Disponíveis no Kit

| Quantidade | Componente                              |
| ---------: | --------------------------------------- |
|          1 | Chassi em acrílico                      |
|          2 | Motores DC 3 V–6 V com caixa de redução |
|          2 | Rodas de borracha                       |
|          1 | Roda boba universal                     |
|          1 | Chave Liga/Desliga                      |
|          2 | Discos encoder                          |
|          1 | Suporte para 4 pilhas AA                |
|          1 | Kit de parafusos e espaçadores          |

---

### 1.10 Componentes Adicionais do Projeto

Além dos componentes fornecidos no kit do chassi, serão utilizados:

|           Quantidade | Componente                           |
| -------------------: | ------------------------------------ |
|                    1 | Arduino Uno R3 compatível            |
|                    1 | Ponte H L298N                        |
|                    1 | Sensor VL53L0X ToF                   |
| Conforme necessidade | Cabos jumper para conexões elétricas |
|                    4 | Pilhas AA                            |

---

## ✏️ 2. Croqui do Chassi

O croqui apresenta a disposição inicial dos principais componentes do robô, incluindo motores, rodas, roda boba, alimentação e placa controladora.

![Croqui do Chassi](./croqui/Croqui-Chassi.png)

> O croqui representa o planejamento inicial da montagem. A posição da Ponte H e do sensor VL53L0X poderá ser adicionada ou ajustada conforme a montagem física dos componentes.

---

## ⚙️ 3. Arquitetura Inicial

A arquitetura básica do sistema será composta pela leitura do sensor pelo Arduino e pelo controle dos motores através da Ponte H.

```text
Sensor VL53L0X
      │
      │ I²C
      ▼
Arduino Uno R3
      │
      │ Sinais de controle
      ▼
Ponte H L298N
   │       │
   ▼       ▼
Motor    Motor
Esquerdo Direito
   │       │
   ▼       ▼
 Roda     Roda
```

O sensor detectará obstáculos presentes na trajetória do robô. O Arduino processará as informações recebidas e enviará comandos para a Ponte H, responsável por controlar os dois motores DC.

---

## 🔧 4. Desenvolvimento do Projeto

Esta documentação será atualizada durante o desenvolvimento do robô, registrando alterações na estrutura, componentes eletrônicos utilizados, esquema de montagem, programação e testes realizados.

### Status inicial

* [x] Definição do chassi
* [x] Levantamento das dimensões
* [x] Identificação dos motores
* [x] Identificação dos componentes do kit
* [x] Tabela dimensional
* [x] Definição da placa controladora
* [x] Definição da Ponte H
* [x] Definição do sensor
* [x] Elaboração do croqui
* [ ] Montagem do chassi
* [ ] Integração dos componentes eletrônicos
* [ ] Desenvolvimento do software
* [ ] Testes de leitura do sensor
* [ ] Testes de movimentação
* [ ] Testes de detecção e desvio de obstáculos