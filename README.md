# C++ Simulation and Visualization

## Quick Start

```
# Build the CMAKE project:
~/cppviz $ mkdir build
~/cppviz $ cd build
~/cppviz/build $ cmake ..
~/cppviz/build $ make

# To use CCLS language server, use CMAKE to create a compile_commands.json:
cmake -H. -BDebug -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=YES
ln -s Debug/compile_commands.json .
```
