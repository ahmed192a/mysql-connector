# Mysql Connector Example

## Pre-requisites

you need to install vcpkg as c++ package manager using the following command

```sh
git clone https//github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
```

you will find all dependencies in the `vcpkg.json` file
which will be installed while building the project

sudo chmod -R 777 /opt/vcpkg/

sudo chmod -R 777 /root/.cache/vcpkg/

## installing vcpgk

```sh
wget -O vcpkg.tar.gz https://github.com/microsoft/vcpkg/archive/master.tar.gz
sudo mkdir /opt/vcpkg
sudo tar xf vcpkg.tar.gz --strip-components=1 -C /opt/vcpkg
sudo /opt/vcpkg/bootstrap-vcpkg.sh
sudo ln -s /opt/vcpkg/vcpkg /usr/local/bin/vcpkg
vcpkg version
rm -rf vcpkg.tar.gz

# to remove vcpkg
sudo rm -rf /opt/vcpkg
sudo rm -rf /usr/local/bin/vcpkg
sudo rm -rf /root/.cache/vcpkg
sudo rm -rf /root/.vcpkg
rm -rf ~/.vcpkg
```

## give permission to current user

```sh
sudo chmod -R 777 /opt/vcpkg
sudo chmod -R 777 /root/.cache/vcpkg
```

### In Debug mode

open the terminal in the root directory of the project and run the following command

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release 
cmake --build build --config Release
./build/Release/myapp
```

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug
./build/Debug/myapp
```
