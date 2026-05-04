@echo off
setlocal

:: ── Auto-detect project root (folder where this .bat lives) ──────────────────
set "ROOT=%~dp0"
set "ROOT=%ROOT:~0,-1%"

echo ============================================================
echo   Student Grading System - Builder
echo   Project: %ROOT%
echo ============================================================
echo.

:: ── Verify g++ is available ──────────────────────────────────────────────────
where g++ >nul 2>&1
IF ERRORLEVEL 1 (
    echo [ERROR] g++ not found! Make sure MinGW/MSYS2 is installed and on PATH.
    echo         e.g. C:\msys64\ucrt64\bin should be in your system PATH.
    echo.
    pause
    exit /b 1
)

:: ── Compile ───────────────────────────────────────────────────────────────────
echo [INFO] Compiling...
echo.

g++ "-I%ROOT%\include" ^
    "%ROOT%\src\Main.cpp" ^
    "%ROOT%\src\Menu.cpp" ^
    "%ROOT%\src\Admin.cpp" ^
    "%ROOT%\src\Public.cpp" ^
    "%ROOT%\src\Results.cpp" ^
    "%ROOT%\src\Student.cpp" ^
    "%ROOT%\src\Teacher.cpp" ^
    "%ROOT%\src\Tools.cpp" ^
    -o "%ROOT%\src\SGS.exe" ^
    -std=c++17 ^
    -Wall

:: ── Result ───────────────────────────────────────────────────────────────────
echo.
IF %ERRORLEVEL% EQU 0 (
    echo ============================================================
    echo   [SUCCESS] Build complete!
    echo   Output: %ROOT%\src\SGS.exe
    echo ============================================================
    echo.
    set /p "RUN=Run the program now? (y/n): "
    IF /I "%RUN%"=="y" (
        echo.
        "%ROOT%\src\SGS.exe"
    )
) ELSE (
    echo ============================================================
    echo   [FAILED] Build failed. See errors above.
    echo ============================================================
)

echo.
pause
endlocal
