@echo off
setlocal enabledelayedexpansion

for /L %%i in (58,1,75) do (
    set "filename=3.%%i.c"
    echo. > !filename!
)

endlocal
