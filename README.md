# C++ Numerics and Visualization

Mixing in standard Python numerics with C++ bindings and C++ visualizations for efficiency.

## Dependencies
- [pybind11](https://pybind11.readthedocs.io/en/stable/)
- [Eigen3](https://eigen.tuxfamily.org/index.php?title=Main_Page)
- [Matplot++](https://github.com/alandefreitas/matplotplusplus)

For system-wide accessibility on Mac, some of these packages can be downloaded with brew and included with CMAKE:
```
brew install pybind11 matplot++
```

## Quick Start

```
# Build the CMAKE project:
~/cppviz $ mkdir build
~/cppviz $ cd build
~/cppviz/build $ cmake ..
~/cppviz/build $ make

# To use CCLS language server (n/vim), use CMAKE to create a compile_commands.json:
cmake -H. -BDebug -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=YES
ln -s Debug/compile_commands.json .
```
