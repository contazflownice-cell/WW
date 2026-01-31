# WW - Game Cheat DLL

## ⚠️ PROBLEMA: CRASH AO INJETAR / PROBLEM: INJECTION CRASH

**Português:**
Se o jogo está crashando quando você injeta o DLL:
- 🚀 **Solução Rápida:** [SOLUCAO_RAPIDA_PT.md](SOLUCAO_RAPIDA_PT.md) (EM PORTUGUÊS!)
- 📖 **Guia Completo:** [INJECTION_FIX_GUIDE.md](INJECTION_FIX_GUIDE.md)

**English:**
If the game is crashing when you inject the DLL:
- 🚀 **Quick Solution:** [SOLUCAO_RAPIDA_PT.md](SOLUCAO_RAPIDA_PT.md) (In Portuguese - use translator)
- 📖 **Complete Guide:** [INJECTION_FIX_GUIDE.md](INJECTION_FIX_GUIDE.md)

---

## Causas Comuns / Common Causes

### 1. DllMain com muito código (Most Common)
O problema mais comum é que o DllMain executa muito código durante `DLL_PROCESS_ATTACH`, causando deadlocks ou crashes.

**Solução:** Recompilar o DLL usando o template fornecido: [SOURCE_TEMPLATE.cpp](SOURCE_TEMPLATE.cpp)

### 2. Incompatibilidade de Arquitetura
- Este DLL é **64-bit (x64)**
- O jogo alvo deve ser também **64-bit**
- Configure o Extreme Injector para injeção 64-bit

### 3. Dependências Faltando
O DLL requer:
- **DirectX 11** (d3d11.dll)
- Certifique-se que o jogo usa DirectX 11

### 4. Anti-Cheat
Alguns jogos têm proteção anti-cheat que detecta DLL injection.

---

## Soluções Rápidas / Quick Solutions

### Método 1: Configurações do Extreme Injector
No Extreme Injector, tente estas configurações:

1. **Injection Method:** Selecione "Manual Map"
2. ✅ Habilite "Scramble DLL Name"
3. ✅ Habilite "Manual Map"
4. ✅ Habilite "Close on inject"

### Método 2: Injetar Após o Jogo Carregar
1. Inicie o jogo primeiro
2. Aguarde até chegar no menu principal
3. Então injete o DLL

### Método 3: Recompilar o DLL (Melhor Solução)
1. Use o código fonte fornecido: [SOURCE_TEMPLATE.cpp](SOURCE_TEMPLATE.cpp)
2. Compile com Visual Studio (x64)
3. Use o novo DLL

---

## Arquivos / Files

- 🚀 `SOLUCAO_RAPIDA_PT.md` - **COMECE AQUI!** Guia rápido em Português / **START HERE!** Quick guide in Portuguese
- `INJECTION_FIX_GUIDE.md` - Guia completo de correção / Complete fix guide
- `SOURCE_TEMPLATE.cpp` - Código fonte correto / Correct source code template
- `COMPILE_GUIDE.md` - Como compilar o DLL / How to compile the DLL
- `WeedMen55Cheat (1).dll` - DLL original (pode ter problemas / may have issues)

---

## Suporte / Support

**COMECE AQUI / START HERE:**
- 🚀 [SOLUCAO_RAPIDA_PT.md](SOLUCAO_RAPIDA_PT.md) - Guia rápido em Português com soluções práticas

**Documentação Completa / Complete Documentation:**
- [INJECTION_FIX_GUIDE.md](INJECTION_FIX_GUIDE.md) - Guia detalhado sobre crashes
- [SOURCE_TEMPLATE.cpp](SOURCE_TEMPLATE.cpp) - Template de código seguro
- [COMPILE_GUIDE.md](COMPILE_GUIDE.md) - Como recompilar o DLL

---

## ⚠️ Aviso Legal / Legal Warning

**Português:**
Este software é fornecido apenas para fins educacionais. O uso de cheats em jogos online pode resultar em banimento permanente. Use por sua conta e risco.

**English:**
This software is provided for educational purposes only. Using cheats in online games may result in permanent bans. Use at your own risk.
