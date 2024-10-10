@echo off
setlocal enabledelayedexpansion

for /L %%i in (59,1,97) do (
    set "filename=2.%%i.c"
    echo. > !filename!
)

endlocal
