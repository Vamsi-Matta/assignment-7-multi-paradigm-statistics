# assignment-7-multi-paradigm-statistics
Statistical calculations using C, OCaml, and Python to demonstrate procedural, functional, and object-oriented programming paradigms.
# Assignment 7 — Multi-Paradigm Statistics

Repository: `assignment-7-multi-paradigm-statistics`

C (procedural), OCaml (functional), and Python (object-oriented) programs compute mean, median, and mode.

## Windows PowerShell / VS Code
Open the folder containing `statistics.c`, `statistics.ml`, and `statistics.py`.

### Python
```powershell
python --version
python statistics.py
```
Alternative: `py statistics.py`. Enter `8`, then `1 2 2 3 4 4 4 6` on one line.

### C (GCC)
```powershell
gcc --version
gcc -std=c11 -Wall -Wextra statistics.c -o statistics.exe
.\statistics.exe
```
If GCC is missing, install a GCC toolchain (e.g., MSYS2 MinGW-w64). Enter `8`, then `1 2 2 3 4 4 4 6` on one line.

### OCaml
```powershell
ocaml -version
ocaml statistics.ml
```
Install OCaml first. For WSL Ubuntu: `sudo apt update && sudo apt install ocaml`; run `ocaml statistics.ml` in the source folder. Enter `8`, then each number on a new line: `1`, `2`, `2`, `3`, `4`, `4`, `4`, `6`.

Expected for all three:
```
Mean: 3.25
Median: 3.50
Mode(s): 4 (frequency: 3)
```

## Submission
Upload these four source/documentation files to GitHub, paste the real repository link into the Word report, and include screenshots of actual runs in all three languages. Do not upload compiled executables.
