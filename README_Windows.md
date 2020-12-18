Following the practice of [Qt](https://wiki.qt.io/MinGW) and [GTK](https://www.gtk.org/docs/installations/windows/), this project would use [MSYS2/MinGW](https://www.msys2.org/) rather than MSCV on windows.

```shell
# Update the package database and packages with: 
pacman -Sy
# MinGW
pacman -S mingw-w64-x86_64-toolchain
pacman -S mingw-w64-x86_64-qt5
pacman -S mingw-w64-x86_64-qt-creator
```

To use QtCreator properly, you have to link the kits with the a qmake.exe.

Set Cmake  with `-GMinGW Makefiles`


