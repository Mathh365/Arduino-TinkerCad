# 🎨 Controle RGB com Arduino  

Um projeto interativo criado para explorar **controle de cores RGB** usando **Arduino UNO**, **botões**, e **potenciômetros**.  
O objetivo é permitir a seleção de cores básicas (R, G, B, Y, P, C) e o ajuste fino de intensidade de cada cor via potenciômetros.

---

## ⚙️ Componentes Utilizados  

- 🟦 1x Arduino UNO  
- 🔴 1x LED RGB (cátodo comum)  
- 🎚️ 3x Potenciômetros (para ajustar R, G e B)  
- 🔘 6x Botões (para selecionar cores predefinidas: R, G, B, Y, P, C)  
- 🪫 Resistores (220Ω e 10kΩ)  
- 🔌 Jumpers macho-macho  

---

## 🔩 Circuito  

Visualização do circuito montado no **Tinkercad**:  

![Circuito RGB](circuito.png)

---

## 💡 Funcionamento  

Cada botão aciona uma combinação de cores:  
| Cor | Componentes Ativos |
|------|--------------------|
| 🔴 Vermelho | R |
| 🟢 Verde | G |
| 🔵 Azul | B |
| 🟡 Amarelo | R + G |
| 🟣 Magenta | R + B |
| 🔵 Ciano | G + B |

Os potenciômetros permitem ajustar manualmente a intensidade de cada canal RGB em tempo real.

---

## 🧠 Lógica do Código  

O programa foi desenvolvido em **C++ para Arduino**, e sua estrutura inclui:  
- **Leitura analógica** dos potenciômetros (A0, A1, A2)  
- **Leitura digital** dos botões (com `digitalRead()`)  
- **Controle PWM** das cores com `analogWrite()`  
- **Função de debounce** para evitar leituras falsas nos botões  

📄 Código completo: [`codigo.ino`](codigo.ino)

---

## 🚀 Como Testar  

1. Abra o código no **Arduino IDE**.  
2. Conecte o Arduino UNO via USB.  
3. Faça o upload do código.  
4. Experimente pressionar os botões e girar os potenciômetros!  

---

## 🎯 Objetivo  

Este projeto foi desenvolvido com fins **educacionais**, explorando o funcionamento prático de:  
- Entradas analógicas e digitais  
- Controle PWM  
- Mistura de cores RGB  
- Organização modular de código Arduino  

---

## 🧩 Aprendizados  

- Diferença entre entrada analógica e digital  
- Controle de brilho via PWM  
- Uso de resistores e debounce em botões  
- Implementação de lógica condicional e leitura em tempo real  

---

## 🏁 Resultado  

O projeto final permite brincar com **mistura de cores em tempo real**, aprendendo na prática conceitos fundamentais de eletrônica e programação embarcada.  

> “Aprender é transformar curiosidade em criação.” ✨  

---

## 📷 Créditos  

Projeto criado e desenvolvido por **Mir4aii**  
Feito com ❤️ e café ☕  
