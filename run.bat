@echo [Running] %1...
@echo off

:start
if %1==buildenv goto buildenv
if %1==emulat goto emulat
goto error_param

:exit 
@echo [Exiting] %1...
exit

:error_param
echo What do you want todo?
echo       Run Docker Buildenv:  run.bat buildenv
echo       Run QEMU Emulator:                   run.bat emulate
echo {OS programming\run}!
goto exit

:error_param2
echo Please define the os-name in arg[2]
goto exit

:buildenv
echo running Buildenv for %2.

docker run --rm -it -v "%cd%:/root/env" %2-buildenv
goto exit

:emulat
echo Running QEMU...
qemu-system-x86_64 -cdrom dist/x86_64/kernel.iso -L "C:\Program Files\qemu"
goto exit
