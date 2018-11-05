## Install Instructions:
sudo apt-get install libboost-dev libtool-bin git gcc-arm-none-eabi libnewlib-arm-none-eabi ssh
git clone http://github.com/szczys/stm32f0-discovery-basic-template
wget -qO - https://download.sublimetext.com/sublimehq-pub.gpg | sudo apt-key add -
echo "deb https://download.sublimetext.com/ apt/stable/" | sudo tee /etc/apt/sources.list.d/sublime-text.list
sudo apt-get updatesu
sudo apt-get install sublime-text
sudo apt-install cmake build-essential libusb-1.0
cd ~/Documents
git clone https://github.com/texane/stlink
cd stlink
make release
make debug
cd build/Release;make install DESTDIR=$HOME
cd ../..
cp etc/udev/rules.d /etc/udev/
sudo udevadm control --reload-rules
sudo udevadm trigger
cd ~/Documents/stm32f0-discover-basic-template
chmod +x program-board.sh