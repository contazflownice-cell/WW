# Como Compilar / How to Compile

## Método 1: Visual Studio (Recomendado / Recommended)

### Requisitos / Requirements
- Visual Studio 2019 ou mais recente / or newer
- Desktop Development with C++ workload
- Windows 10 SDK

### Passos / Steps

#### Português:
1. Abra o Visual Studio
2. Clique em "Create a new project"
3. Selecione "Dynamic-Link Library (DLL)"
4. Dê um nome ao projeto (exemplo: "WeedMenCheat")
5. Clique em "Create"
6. No Solution Explorer, clique com o botão direito no arquivo .cpp gerado e selecione "Remove"
7. Clique com o botão direito no projeto → "Add" → "Existing Item"
8. Selecione o arquivo `SOURCE_TEMPLATE.cpp`
9. Configure a plataforma:
   - No topo do Visual Studio, selecione "Release"
   - Selecione "x64" (para jogos 64-bit)
10. Vá em "Project" → "Properties"
11. Em "C/C++" → "Code Generation" → "Runtime Library", selecione "Multi-threaded (/MT)"
12. Clique em "Build" → "Build Solution" (ou pressione Ctrl+Shift+B)
13. O DLL será gerado em `x64/Release/WeedMenCheat.dll`

#### English:
1. Open Visual Studio
2. Click "Create a new project"
3. Select "Dynamic-Link Library (DLL)"
4. Name your project (e.g., "WeedMenCheat")
5. Click "Create"
6. In Solution Explorer, right-click the generated .cpp file and select "Remove"
7. Right-click the project → "Add" → "Existing Item"
8. Select the `SOURCE_TEMPLATE.cpp` file
9. Configure the platform:
   - At the top of Visual Studio, select "Release"
   - Select "x64" (for 64-bit games)
10. Go to "Project" → "Properties"
11. Under "C/C++" → "Code Generation" → "Runtime Library", select "Multi-threaded (/MT)"
12. Click "Build" → "Build Solution" (or press Ctrl+Shift+B)
13. The DLL will be generated at `x64/Release/WeedMenCheat.dll`

---

## Método 2: CMake

### Requisitos / Requirements
- CMake 3.15 ou mais recente / or newer
- Visual Studio Build Tools ou MinGW
- Windows SDK

### Passos / Steps

#### Windows (Visual Studio):
```bash
# Criar diretório de build
mkdir build
cd build

# Gerar projeto do Visual Studio
cmake .. -G "Visual Studio 17 2022" -A x64

# Compilar
cmake --build . --config Release

# O DLL estará em build/bin/Release/WeedMenCheat.dll
```

#### Windows (MinGW):
```bash
# Criar diretório de build
mkdir build
cd build

# Gerar Makefiles
cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release

# Compilar
cmake --build .

# O DLL estará em build/bin/WeedMenCheat.dll
```

---

## Método 3: Linha de Comando / Command Line

### Usando cl.exe (Visual Studio Command Prompt)

#### Português:
1. Abra "x64 Native Tools Command Prompt for VS"
2. Navegue até o diretório do projeto
3. Execute:

```cmd
cl.exe /LD /MT /O2 SOURCE_TEMPLATE.cpp /Fe:WeedMenCheat.dll d3d11.lib
```

#### English:
1. Open "x64 Native Tools Command Prompt for VS"
2. Navigate to the project directory
3. Run:

```cmd
cl.exe /LD /MT /O2 SOURCE_TEMPLATE.cpp /Fe:WeedMenCheat.dll d3d11.lib
```

**Opções / Options:**
- `/LD` - Compila como DLL / Compile as DLL
- `/MT` - Usa runtime estático / Use static runtime
- `/O2` - Otimizações de velocidade / Speed optimizations
- `/Fe:` - Nome do arquivo de saída / Output file name

---

## Verificação / Verification

Após compilar, verifique se o DLL foi criado corretamente:

### Windows:
```cmd
dumpbin /headers WeedMenCheat.dll
```

Deve mostrar:
- File Type: DLL
- Machine: x64 (para jogos 64-bit) ou x86 (para jogos 32-bit)

---

## Solução de Problemas / Troubleshooting

### Erro: "d3d11.lib not found"
**Solução:** Instale o Windows SDK através do Visual Studio Installer

### Erro: "Cannot open include file 'd3d11.h'"
**Solução:** Certifique-se que o Windows SDK está instalado

### DLL compilado mas ainda crasha
1. Verifique se o jogo é 64-bit (compile para x64)
2. Verifique se o jogo usa DirectX 11
3. Tente injetar com "Manual Map" no Extreme Injector
4. Injete após o jogo carregar completamente

---

## Próximos Passos / Next Steps

Após compilar o DLL:

1. **Teste primeiro em um jogo simples** - Para garantir que o DLL funciona
2. **Use modo Debug primeiro** - Com console habilitado para ver mensagens
3. **Depois compile em Release** - Para uso final sem console
4. **Configure o Extreme Injector** - Use "Manual Map" como método de injeção

---

## Adicionando Funcionalidades / Adding Features

Para adicionar seu próprio código ao cheat:

1. Edite a função `InitializeCheat()` em `SOURCE_TEMPLATE.cpp`
2. Adicione suas funções de hook, ESP, aimbot, etc.
3. Recompile o DLL

Exemplo:
```cpp
void InitializeCheat()
{
    // Seu código aqui / Your code here
    
    // Exemplo: Hook DirectX
    // SetupD3D11Hooks();
    
    // Exemplo: Criar console de debug
    AllocConsole();
    
    // Seu código customizado / Your custom code
}
```

---

## Recursos Adicionais / Additional Resources

- [DLL Injection Fix Guide](INJECTION_FIX_GUIDE.md) - Guia completo de correção
- [Source Template](SOURCE_TEMPLATE.cpp) - Código fonte comentado
- [Microsoft Docs - DLLs](https://docs.microsoft.com/en-us/cpp/build/dlls-in-visual-cpp)
