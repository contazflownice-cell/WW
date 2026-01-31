# SOLUÇÃO RÁPIDA - CRASH AO INJETAR

## 🚨 POR QUE O JOGO CRASHA?

O DLL atual (`WeedMen55Cheat (1).dll`) provavelmente tem problemas no código do **DllMain** que causam crashes quando injetado. Isso é muito comum em DLLs de cheat.

## ✅ COMO CORRIGIR

### Opção 1: Configurar o Extreme Injector (Rápido)

1. Abra o Extreme Injector
2. Selecione o processo do jogo
3. **IMPORTANTE:** Mude o método de injeção:
   - Clique em "Settings" ou "Advanced"
   - Selecione **"Manual Map"** como método de injeção
   - ✅ Habilite "Scramble DLL Name" se disponível
4. Selecione o DLL
5. Injete no jogo

### Opção 2: Injetar No Momento Certo

1. **Inicie o jogo primeiro**
2. **Aguarde até chegar no menu principal** (não injete durante o carregamento)
3. Só então injete o DLL

### Opção 3: Recompilar o DLL (Solução Definitiva)

Se você tem o código fonte ou quer corrigir definitivamente:

1. Use o código fornecido em `SOURCE_TEMPLATE.cpp`
2. Compile usando Visual Studio (veja `COMPILE_GUIDE.md`)
3. Use o novo DLL

## 📋 CHECKLIST DE COMPATIBILIDADE

Antes de injetar, verifique:

- [ ] O jogo é **64-bit**? (Este DLL é 64-bit)
- [ ] O jogo usa **DirectX 11**? (Este DLL precisa de DirectX 11)
- [ ] Você está usando **Extreme Injector** ou similar?
- [ ] O jogo tem **anti-cheat**? (Se sim, pode não funcionar)

### Como Verificar se o Jogo é 64-bit:

**Windows:**
1. Abra o Task Manager (Ctrl+Shift+Esc)
2. Vá para a aba "Details"
3. Encontre o processo do jogo
4. Se tiver "(32 bit)" no nome, o jogo é 32-bit
5. Se não tiver, é 64-bit

### Como Verificar se o Jogo usa DirectX 11:

1. Procure nas configurações do jogo por "DirectX 11" ou "DX11"
2. Ou verifique nos arquivos do jogo se existe `d3d11.dll`
3. Jogos modernos (2015+) geralmente usam DirectX 11 ou 12

## 🔧 TROUBLESHOOTING

### "Nada acontece ao injetar"
- ✅ Tente usar "Manual Map" no Extreme Injector
- ✅ Execute o injector como Administrador
- ✅ Desabilite o antivírus temporariamente

### "O jogo fecha imediatamente"
- ⚠️ Possível anti-cheat detectando o DLL
- ✅ Tente injetar depois do menu carregar
- ✅ Tente usar "Manual Map" com "Scramble DLL Name"

### "Access Denied" ou erro de permissão
- ✅ Execute o Extreme Injector como Administrador
- ✅ Desabilite o antivírus
- ✅ Execute o jogo como Administrador também

### "Failed to inject" ou erro de injeção
- ✅ Verifique se o jogo é 64-bit (use Task Manager)
- ✅ Configure o Extreme Injector para 64-bit
- ✅ Tente um injector diferente (ProcessHacker, Xenos Injector)

## 📚 DOCUMENTAÇÃO COMPLETA

Para mais detalhes, consulte:

- **[INJECTION_FIX_GUIDE.md](INJECTION_FIX_GUIDE.md)** - Guia completo em inglês
- **[SOURCE_TEMPLATE.cpp](SOURCE_TEMPLATE.cpp)** - Código fonte corrigido
- **[COMPILE_GUIDE.md](COMPILE_GUIDE.md)** - Como compilar o DLL

## ⚡ RESUMO

**Problema:** DllMain executa muito código, causando deadlock/crash

**Solução Rápida:** 
1. Use "Manual Map" no Extreme Injector
2. Injete após o menu do jogo carregar

**Solução Definitiva:**
1. Recompile o DLL usando `SOURCE_TEMPLATE.cpp`
2. O template já tem o código correto que não crasha

## 💡 DICA IMPORTANTE

Se você NÃO TEM o código fonte original, a melhor opção é usar as configurações do Extreme Injector (Opção 1) e injetar no momento certo (Opção 2).

Se você TEM o código fonte ou quer criar seu próprio cheat, use o `SOURCE_TEMPLATE.cpp` como base - ele já está configurado corretamente para evitar crashes.

---

## ❓ PRECISA DE MAIS AJUDA?

1. Leia o guia completo: [INJECTION_FIX_GUIDE.md](INJECTION_FIX_GUIDE.md)
2. Veja como compilar: [COMPILE_GUIDE.md](COMPILE_GUIDE.md)
3. Use o código fonte corrigido: [SOURCE_TEMPLATE.cpp](SOURCE_TEMPLATE.cpp)
