# AbilityBrowser (Qt6)

A modern, accessible, and extensible Ability Browser built with Qt6 (C++17).

## Features
- Add, remove, and list abilities (name, description, level)
- Clean MVC architecture (POO)
- RGAA accessibility best practices
- Multilingual ready (tr())
- Ready for CI/CD integration

## Build Instructions

### Prerequisites
- Qt6 (Widgets module)
- CMake >= 3.16
- C++17 compatible compiler (MSVC, GCC, Clang)

### Build (Windows/Linux)
```sh
mkdir build
cd build
cmake .. -DCMAKE_PREFIX_PATH="<Qt6_INSTALL_PATH>"
cmake --build .
```
Replace `<Qt6_INSTALL_PATH>` with your Qt6 installation path (e.g., `C:/Qt/6.5.0/msvc2019_64`).

### Run
- On Windows: `AbilityBrowser.exe`
- On Linux: `./AbilityBrowser`

## Accessibility (RGAA)
- All UI elements have accessible names
- Keyboard navigation supported

## License
MIT 