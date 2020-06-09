# Readme

## Setup

```bash
sudo apt-get install freeglut3-dev
# Needed?
sudo apt-get install freeglut3 freeglut3-dev libglew-dev

# for glxinfo command
apt-get install mesa-utils
```


```bash
# Debian
g++ src/demo.cpp -lglut -o demo
# Ubuntu
g++ -lglut -lGL -o demo -c src/demo.cpp
```