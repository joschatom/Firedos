@echo off
@echo "Bulding Docker Env..."


docker build . -t %1-buildenv


@rem $buildenv >> .\dockerctr.log
@echo on