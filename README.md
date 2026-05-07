# DungeonGenerator avec CMake

Ce guide explique comment compiler et lancer le projet **DungeonGenerator** sur Windows et Linux.

## Informations utiles du projet

Le projet utilise **CMake** avec les paramètres suivants :

- version minimale de CMake : **3.16** ;
- langage : **C++** ;
- standard C++ requis : **C++23** ;
- cible générée : exécutable **Dungeon** ;
- les fichiers sources sont détectés automatiquement dans `src/*.cpp` ;
- le dossier d'en-têtes est `include/` ;
- avec MSVC, l'option `/W4` est activée ;
- avec GCC/Clang, les options `-Wall -Wextra -Wpedantic` sont activées.

> Le README du dépôt ne contient pas d'instructions d'installation détaillées au moment de la rédaction, donc les commandes ci-dessous sont déduites de la configuration `CMakeLists.txt`.

---

## Prérequis

### Windows

Installer :

1. **Git**
2. **CMake 3.16 ou plus récent**
3. Un compilateur C++ compatible **C++23** :
   - recommandé : **Visual Studio 2022** avec le composant *Desktop development with C++* ;
   - alternative : MinGW-w64 récent, si vous préférez compiler avec `mingw32-make` ou `ninja`.

Vérifier l'installation :

```powershell
git --version
cmake --version
```

Avec Visual Studio, ouvrez de préférence un terminal :

```text
Developer PowerShell for VS 2022
```

ou :

```text
x64 Native Tools Command Prompt for VS 2022
```

---

### Linux

Installer Git, CMake et un compilateur C++ récent.

#### Ubuntu / Debian

```bash
sudo apt update
sudo apt install git cmake g++ build-essential
```

Vérifier l'installation :

```bash
git --version
cmake --version
g++ --version
```

Le compilateur doit supporter **C++23**. Si votre version de `g++` est trop ancienne, installez une version plus récente de GCC ou utilisez Clang.

---

## 1. Cloner le dépôt

```bash
git clone https://github.com/djely2005/DungeonGenerator.git
cd DungeonGenerator
```

---

## 2. Compiler sur Linux

Depuis la racine du projet :

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

L'exécutable sera normalement généré ici :

```bash
./build/Dungeon
```

Pour l'exécuter :

```bash
./build/Dungeon
```

### Compilation en mode Debug

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./build/Dungeon
```

---

## 3. Compiler sur Windows avec Visual Studio

Depuis la racine du projet, dans PowerShell ou dans un terminal développeur Visual Studio :

```powershell
cmake -S . -B build
cmake --build build --config Release
```

L'exécutable sera normalement généré ici :

```powershell
.\build\Release\Dungeon.exe
```

Pour l'exécuter :

```powershell
.\build\Release\Dungeon.exe
```

### Compilation en mode Debug

```powershell
cmake -S . -B build
cmake --build build --config Debug
.\build\Debug\Dungeon.exe
```

---

## 4. Compiler sur Windows avec MinGW ou Ninja

Si vous utilisez MinGW-w64 avec Makefiles :

```powershell
cmake -S . -B build -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build build
.\build\Dungeon.exe
```

Si vous utilisez Ninja :

```powershell
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build
.\build\Dungeon.exe
```

---

## 5. Installation optionnelle

Le `CMakeLists.txt` contient une règle d'installation vers `bin`. Après compilation, vous pouvez installer le programme avec :

### Linux

```bash
cmake --install build --prefix ./install
./install/bin/Dungeon
```

### Windows

```powershell
cmake --install build --config Release --prefix .\install
.\install\bin\Dungeon.exe
```