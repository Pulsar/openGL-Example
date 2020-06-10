# Readme

## Requirements

### System

```bash
sudo apt-get install freeglut3-dev
# Needed?
sudo apt-get install freeglut3 freeglut3-dev libglew-dev

# for glxinfo command
apt-get install mesa-utils
```

### VScode extenssions

1. Save and run
2. C/C++

## Compile

```bash
# Debian
g++ src/demo.cpp -lglut -o demo
# Ubuntu
g++ -lglut -lGL -o demo src/demo.cpp
```
