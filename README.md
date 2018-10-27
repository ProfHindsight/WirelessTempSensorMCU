# WirelessTempSensorMCU
Wireless Temp Sensor node using the STM32F030K6T6TR

# Installation Instructions:
sudo add-apt-repository ppa:team-gcc-arm-embedded/ppa
sudo apt-get update
sudo apt-get install gcc-arm-non-eabi

# Install stlink
sudo apt-get install git build-essential libusb-1.0.0-dev cmake
cd $HOME
git clone https://github.com/texane/stlink
cd stlink
make release
cd build/Release && make install DESTDIR=_install
echo "export PATH=\$PATH:$HOME/stlink/build/Release/_install/usr/local/bin" >> $HOME/.bashrc

# Setup udev rules for USB
https://github.com/texane/stlink
https://github.com/texane/stlink/blob/master/doc/compiling.md

# This should copy the udev rules to the /etc/udev/rules.d directory
cd $HOME/stlink
sudo cp etc/udev/rules.d /etc/udev 
sudo udevadm control --reload-rules
sudo udevadm trigger
