@echo off
IF NOT EXIST .\build mkdir .\build

pushd .\build

set compilerFlags=-MT -nologo -GR- -EHa- -Od -Oi -FC -Z7 /D _DEBUG

cl %compilerFlags% ../main.c /Fegng_atlas.exe -link /OPT:REF /SUBSYSTEM:CONSOLE

popd
