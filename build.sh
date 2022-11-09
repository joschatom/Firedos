# /bin/sh

clear;
neofetch --logo 0
echo "Plase wait..."
ping localhost -c 10 >> /dev/null
clear

echo "Cleaning alredy existing Object Files..."
ping localhost -c 2 >> /dev/null
make clean # Calls the 'CLEAN' role using make!
echo "All Object File cleaned up!"
make build-x86_64 # Calls 'BUILD<x86_64>' to compile the Files.
echo ""
echo Done.