# Semáforo Inteligente com Arduino

Este projeto simula um **sistema de semáforo inteligente**, desenvolvido no **TinkerCad** e programado em **C++ para Arduino**.  
O objetivo foi criar um controle de tráfego que **se adapta dinamicamente** à presença de veículos, **sem usar `delay()`**, garantindo fluidez e precisão no tempo de execução.

---

## Conceito

Diferente de um semáforo comum com tempos fixos, este utiliza **sensores** para detectar veículos e decidir automaticamente qual via deve abrir.  
Além disso, o uso da função `millis()` permite **controle assíncrono do tempo**, evitando travamentos e possibilitando múltiplas tarefas simultâneas — uma prática essencial em sistemas embarcados.

---

## ⚙️ Componentes Utilizados

| Nome | Quantidade | Componente |
|------|-------------|------------|
| U1 | 1 | Arduino Uno R3 |
| D1, D7 | 2 | LED Vermelho |
| D2, D6 | 2 | LED Amarelo |
| D3, D5 | 2 | LED Verde |
| R1–R8 | 8 | Resistor 220 Ω |
| S2, S3 | 2 | Interruptor deslizante |

---

## 💡 Principais Conceitos Aplicados

- **Programação não bloqueante** com `millis()`  
- **Estrutura modular de código**, com funções independentes  
- **Leitura de sensores digitais** (`digitalRead`)  
- **Controle lógico de estados** (máquina de estados simples)  
- **Organização e clareza na lógica sequencial**

---

## 🧩 Estrutura Lógica

O sistema opera em diferentes modos, conforme as condições:

- 🚗 **Carros em ambas as vias:** ciclo padrão de semáforo.  
- 🚙 **Carro em uma única via:** prioridade para a via ocupada.  
- 🌙 **Nenhum carro detectado:** pisca amarelo intermitente.

---

## 🧠 Habilidades Desenvolvidas

Este projeto me ajudou a fortalecer:

- A compreensão de **controle de tempo não linear** em Arduino.  
- A criação de **funções reutilizáveis e limpas**, separando responsabilidades.  
- O raciocínio lógico voltado para **automações inteligentes**.  
- O uso de **boas práticas de codificação modular**.

---

## 📸 Mídia do Projeto

🖼️ *Imagem do circuito e vídeo da execução serão adicionados em breve.*

---

### ✨ Conclusão

Este semáforo inteligente foi uma ótima forma de unir **lógica, eletrônica e programação limpa**.  
Além de funcionar de maneira realista, ele reforça a importância de pensar **de forma assíncrona e modular** — conceitos fundamentais para qualquer desenvolvedor embarcado.

---

> *“Não é só sobre acender LEDs — é sobre pensar como um sistema.”*
