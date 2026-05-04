# Student Grading System (SGS)

A console-based **Student Grading Management System** built in **C++**, designed for university-level academic record management. The system supports multiple user roles — **Teacher**, **Student**, **Admin**, and **Public** — each with tailored functionality for managing student data, marks, results, and re-evaluations.

---

## Table of Contents

- [Features](#features)
- [Project Structure](#project-structure)
- [Architecture](#architecture)
- [Getting Started](#getting-started)
- [How to Compile](#how-to-compile)
- [How to Run](#how-to-run)
- [User Roles & Credentials](#user-roles--credentials)
- [Grading System](#grading-system)
- [Data Files](#data-files)
- [Known Issues / Limitations](#known-issues--limitations)

---

## Features

### Teacher
- **Student Entry** — Add new students (individually or in batch with default branch/section), delete, and modify student records
- **Marks Entry** — Enter marks for an entire section/branch by subject code and semester
- **Edit Marks** — Modify previously entered marks for a specific student and subject
- **Results Viewer** — View results by:
  - Individual student (semester-wise)
  - Particular subject (class-wide)
  - Entire branch/section (with CGPA)
  - Failed students list
- **Re-evaluation Requests** — View, approve, or reject student re-evaluation requests
- **Change Password** — Securely update login credentials

### Student
- **Semester-wise Results** — View detailed marks with SGPA for any semester
- **Subject-wise Results** — Look up marks for a specific subject by code
- **CGPA Display** — Shown on the student homepage
- **Re-evaluation Registration** — Submit a re-evaluation request for a subject
- **Change Password** — Update login password

### Public
- **Help Desk** — View passing conditions and marks breakdown rules
- **Subject Code Finder** — Search for subject codes and credit information by branch and subject name

### Admin
- Login-protected portal *(Work In Progress)*

---

## Project Structure

```
Student_Grading_System/
├── README.md
├── build.bat                       # One-click build script (universal)
├── .gitignore
├── src/                            # C++ source files
│   ├── Main.cpp                    # Entry point
│   ├── Menu.cpp                    # Home page & login routing
│   ├── Teacher.cpp                 # Teacher functionality
│   ├── Student.cpp                 # Student functionality
│   ├── Results.cpp                 # Shared result display logic
│   ├── Admin.cpp                   # Admin portal (WIP)
│   ├── Public.cpp                  # Public helpdesk
│   ├── Tools.cpp                   # Utility & calculation functions
│   └── SGS.exe                     # Compiled Windows executable (after build)
├── include/                        # Header files
│   ├── Academic_members.h          # Teacher, Student, Results, Marks classes
│   ├── Menu.h                      # Menu class
│   ├── Admin.h                     # Admin class
│   ├── Public.h                    # Public class
│   └── Tools.h                     # Base Tools class
└── Files/                          # Flat-file database (plain text)
    ├── Credentials.txt             # User login records
    ├── Student_data.txt            # Student personal information
    ├── Student_marks1.txt          # Student marks per subject per semester
    ├── Subject_data.txt            # Subject catalog (name, code, credits)
    ├── Marks_breakdown.txt         # Grading rules (displayed in Public)
    ├── Passing_Conditions.txt      # Passing criteria (displayed in Public)
    ├── fail.txt                    # Auto-generated failed student records
    └── re_eval.txt                 # Re-evaluation request log
```

---

## Architecture

The system uses an **inheritance-based OOP design** in C++:

```
Tools (base)
├── Results (virtual) ─── showResults() overloads for different views
├── Marks  (virtual)  ─── marks_init(), enter_marks()
│
├── Teacher : Results, Marks  ── Full management access
└── Student : Results         ── Read-only + re-eval

Menu   ── Orchestrates login and routes to the correct role
Public ── Inherits Tools privately for utility access
Admin  ── Standalone (WIP)
```

### Class Responsibilities

| Class | Responsibility |
|---|---|
| `Tools` | Grade/SGPA/CGPA calculation, file lookups (student, subject, branch), color output, sorting |
| `Results` | Overloaded `showResults()` for student-view, teacher-view by subject, by branch |
| `Marks` | Initializing and entering marks for a student-subject pair |
| `Teacher` | Student CRUD, marks editor, result viewer, re-eval manager, password change |
| `Student` | Self-service results, re-eval registration, password change |
| `Menu` | Credential verification, login page routing |
| `Public` | Helpdesk — passing rules, marks breakdown, subject code finder |
| `Admin` | Placeholder (WIP) |

---

## Getting Started

### Prerequisites

- **OS:** Windows (uses `windows.h` for console colors and `system("CLS")`)
- **Compiler:** MinGW g++ (GCC) or MSVC
- **C++ Standard:** C++11 or later

### Clone the Repository

```bash
git clone https://github.com/your-username/Student-Grading-System.git
cd Student-Grading-System
```

---

## How to Compile

### ✅ Option 1 — One-Click Build (Recommended)

Simply **double-click `build.bat`** in the project root, or run it from the terminal:

```bat
.\build.bat
```

The script auto-detects its own location, compiles all sources, and outputs `src\SGS.exe`. It also checks that `g++` is on your PATH before building. After a successful build, it asks if you want to run the program immediately.

> **Prerequisite:** [MSYS2](https://www.msys2.org/) with `ucrt64` toolchain installed and `C:\msys64\ucrt64\bin` added to your system PATH.

---

### Option 2 — Manual g++ Command

```bash
g++ -Iinclude src/Main.cpp src/Menu.cpp src/Teacher.cpp src/Student.cpp src/Results.cpp src/Admin.cpp src/Public.cpp src/Tools.cpp -o src/SGS.exe -std=c++17
```

Run this from the **project root** (`Student_Grading_System/`).

### Option 3 — MSVC (Developer Command Prompt)

```bash
cl src\Main.cpp src\Menu.cpp src\Teacher.cpp src\Student.cpp src\Results.cpp src\Admin.cpp src\Public.cpp src\Tools.cpp /I include /Fe:src\SGS.exe
```

---

## How to Run

```bat
src\SGS.exe
```

Or let `build.bat` launch it for you — after a successful build it will prompt:
```
Run the program now? (y/n):
```

> ⚠️ Always run `SGS.exe` from inside `src\`. The program reads and writes data files using the relative path `../Files/`, so running it from a different directory will cause file-not-found errors.

---

## User Roles & Credentials

At the home screen, select your role:

```
1. Teacher
2. Student
3. Public     (no login required)
4. Admin
5. Exit
```

Credentials are stored in `Files/Credentials.txt` in the format:

```
<login_type>  <login_id>  <password>
```

| `login_type` | Role |
|---|---|
| `1` | Admin |
| `2` | Teacher |
| `3+` | Student (the value serves as their internal serial number) |

### Default Credentials (from `Credentials.txt`)

| Role | Login ID | Password |
|---|---|---|
| Admin | `233018` | `aniket` |
| Teacher | `233019` | `aniket` |
| Student | `233020` | `anshdeep` |
| Student | `233021` | `Anavi` |
| Student | `233022` | `Bhupesh` |

> ⚠️ These are sample/demo credentials. Change passwords after first login using the **Change Password** option.

---

## Grading System

Grades are computed based on percentage marks:

| Marks (%) | Grade | Grade Points |
|---|---|---|
| ≥ 90 | A+ | 10 |
| ≥ 80, < 90 | A | 9 |
| ≥ 70, < 80 | B+ | 8 |
| ≥ 60, < 70 | B | 7 |
| ≥ 50, < 60 | C+ | 6 |
| ≥ 45, < 50 | C | 5 |
| ≥ 40, < 45 | D | 4 |
| < 40 | F | 0 |

### Marks Breakdown

| Component | Weightage |
|---|---|
| Best of Minor 1 / Minor 2 | 30% |
| Internal (Assignments/Attendance/Projects) | 20% |
| Major (End Semester Exam) | 50% |

### Passing Criteria
- Minimum **10 marks** in minor examinations
- Minimum **20% marks** in the major (end semester) examination
- Overall minimum **40%** to avoid an F grade

### Practical Subjects
- Identified by a `_P` suffix in the subject name (e.g., `Physics_P`)
- Graded out of **50 marks** (internally doubled to 100 for grade calculation)

### SGPA & CGPA
- **SGPA** (Semester Grade Point Average) = Σ(Grade Points × Credits) / Σ Credits (only for passed subjects)
- **CGPA** = Running average of SGPA across all semesters

---

## Data Files

All data is persisted in plain text files under `Files/`:

### `Student_data.txt`
```
<serial_no>  <roll_no>  <name>  <branch>  <section>
```

### `Student_marks1.txt`
```
<serial_no>  <semester>  <subject_name>  <minor1>  <minor2>  <internal>  <major>  <total>  <grade>
```

### `Subject_data.txt`
```
<semester>  <branch>  <subject_name>  <subject_code>  <credits>
```

### `Credentials.txt`
```
<login_type>  <roll_no>  <password>
```

### Supported Branches

The sorting and branch-filtering system supports the following branch codes:

`CSE` · `IT` · `ECE` · `EEE` · `ME` · `BIO`

---

## Known Issues / Limitations

- **No database** — All data is stored in plain text files. Concurrent access is not supported. A future version could migrate to SQLite.
- **Single-word branch names** — Branch input is still read as a single token (no spaces), as branch codes like `CSE`, `IT`, `ECE` are always one word by design.
- **Windows-only executable** — The pre-built `SGS.exe` is Windows-only. The source code is now cross-platform (compiles on Linux/macOS with g++), but has not been tested on non-Windows systems.


---

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

---

## License

This project is open-source and available under the [MIT License](LICENSE).

# 🎓 Student Grading System (SGS)

A console-based **Student Grading Management System** built in **C++**, designed for university-level academic record management. The system supports multiple user roles — **Teacher**, **Student**, **Admin**, and **Public** — each with tailored functionality for managing student data, marks, results, and re-evaluations.

---

## 📋 Table of Contents

- [Features](#-features)
- [Project Structure](#-project-structure)
- [Architecture](#-architecture)
- [Getting Started](#-getting-started)
- [How to Compile](#-how-to-compile)
- [How to Run](#-how-to-run)
- [User Roles & Credentials](#-user-roles--credentials)
- [Grading System](#-grading-system)
- [Data Files](#-data-files)
- [Known Issues / Limitations](#-known-issues--limitations)

---
## Features

### 👨‍🏫 Teacher
- **Student Entry** — Add new students (individually or in batch with default branch/section), delete, and modify student records
- **Marks Entry** — Enter marks for an entire section/branch by subject code and semester
- **Edit Marks** — Modify previously entered marks for a specific student and subject
- **Results Viewer** — View results by:
  - Individual student (semester-wise)
  - Particular subject (class-wide)
  - Entire branch/section (with CGPA)
  - Failed students list
- **Re-evaluation Requests** — View, approve, or reject student re-evaluation requests
- **Change Password** — Securely update login credentials

### 🎓 Student
- **Semester-wise Results** — View detailed marks with SGPA for any semester
- **Subject-wise Results** — Look up marks for a specific subject by code
- **CGPA Display** — Shown on the student homepage
- **Re-evaluation Registration** — Submit a re-evaluation request for a subject
- **Change Password** — Update login password

### 🌐 Public
- **Help Desk** — View passing conditions and marks breakdown rules
- **Subject Code Finder** — Search for subject codes and credit information by branch and subject name

### 🔐 Admin
- Login-protected portal *(Work In Progress)*

---

## Project Structure

```
Student-Grading-System/
├── README.md
└── main_dir/
    ├── src/                        # C++ source files
    │   ├── Main.cpp                # Entry point
    │   ├── Menu.cpp                # Home page & login routing
    │   ├── Teacher.cpp             # Teacher functionality
    │   ├── Student.cpp             # Student functionality
    │   ├── Results.cpp             # Shared result display logic
    │   ├── Admin.cpp               # Admin portal (WIP)
    │   ├── Public.cpp              # Public helpdesk
    │   ├── Tools.cpp               # Utility & calculation functions
    │   └── SGS.exe                 # Pre-built Windows executable
    ├── include/                    # Header files
    │   ├── Academic_members.h      # Teacher, Student, Results, Marks classes
    │   ├── Menu.h                  # Menu class
    │   ├── Admin.h                 # Admin class
    │   ├── Public.h                # Public class
    │   └── Tools.h                 # Base Tools class
    └── Files/                      # Flat-file database (plain text)
        ├── Credentials.txt         # User login records
        ├── Student_data.txt        # Student personal information
        ├── Student_marks1.txt      # Student marks per subject per semester
        ├── Subject_data.txt        # Subject catalog (name, code, credits)
        ├── Marks_breakdown.txt     # Grading rules (displayed in Public)
        ├── Passing_Conditions.txt  # Passing criteria (displayed in Public)
        ├── fail.txt                # Auto-generated failed student records
        └── re_eval.txt             # Re-evaluation request log
```

---

## Architecture

The system uses an **inheritance-based OOP design** in C++:

```
Tools (base)
├── Results (virtual) ─── showResults() overloads for different views
├── Marks  (virtual)  ─── marks_init(), enter_marks()
│
├── Teacher : Results, Marks  ── Full management access
└── Student : Results         ── Read-only + re-eval

Menu   ── Orchestrates login and routes to the correct role
Public ── Inherits Tools privately for utility access
Admin  ── Standalone (WIP)
```

### Class Responsibilities

| Class | Responsibility |
|---|---|
| `Tools` | Grade/SGPA/CGPA calculation, file lookups (student, subject, branch), color output, sorting |
| `Results` | Overloaded `showResults()` for student-view, teacher-view by subject, by branch |
| `Marks` | Initializing and entering marks for a student-subject pair |
| `Teacher` | Student CRUD, marks editor, result viewer, re-eval manager, password change |
| `Student` | Self-service results, re-eval registration, password change |
| `Menu` | Credential verification, login page routing |
| `Public` | Helpdesk — passing rules, marks breakdown, subject code finder |
| `Admin` | Placeholder (WIP) |

---

## Getting Started

### Prerequisites

- **OS:** Windows (uses `windows.h` for console colors and `system("CLS")`)
- **Compiler:** MinGW g++ (GCC) or MSVC
- **C++ Standard:** C++11 or later

### Clone the Repository

```bash
git clone https://github.com/your-username/Student-Grading-System.git
cd Student-Grading-System
```

---

## How to Compile

Navigate into the `main_dir/src/` folder and compile all source files together. The executable **must be run from within the `src/` directory** since all file paths are relative (`../Files/`).

**Using g++ (MinGW):**
```bash
cd main_dir/src
g++ Main.cpp Menu.cpp Teacher.cpp Student.cpp Results.cpp Admin.cpp Public.cpp Tools.cpp -o SGS
```

**Using MSVC (Developer Command Prompt):**
```bash
cd main_dir\src
cl Main.cpp Menu.cpp Teacher.cpp Student.cpp Results.cpp Admin.cpp Public.cpp Tools.cpp /Fe:SGS.exe
```

> **Note:** A pre-built `SGS.exe` is included in `main_dir/src/` for Windows users who want to run it directly without compiling.

---

## How to Run

```bash
cd main_dir/src
./SGS        # Linux/Mac-style (if compiled for Windows via MinGW)
SGS.exe      # Windows
```

> ⚠️ Always run the executable from inside `main_dir/src/`. The program reads and writes data files using the relative path `../Files/`, so running it from a different directory will cause file-not-found errors.

---

## User Roles & Credentials

At the home screen, select your role:

```
1. Teacher
2. Student
3. Public     (no login required)
4. Admin
5. Exit
```

Credentials are stored in `main_dir/Files/Credentials.txt` in the format:

```
<login_type>  <login_id>  <password>
```

| `login_type` | Role |
|---|---|
| `1` | Admin |
| `2` | Teacher |
| `3+` | Student (the value serves as their internal serial number) |

### Default Credentials (from `Credentials.txt`)

| Role | Login ID | Password |
|---|---|---|
| Admin | `233018` | `aniket` |
| Teacher | `233019` | `aniket` |
| Student | `233020` | `anshdeep` |
| Student | `233021` | `Anavi` |
| Student | `233022` | `Bhupesh` |

> ⚠️ These are sample/demo credentials. Change passwords after first login using the **Change Password** option.

---

## Grading System

Grades are computed based on percentage marks:

| Marks (%) | Grade | Grade Points |
|---|---|---|
| ≥ 90 | A+ | 10 |
| ≥ 80, < 90 | A | 9 |
| ≥ 70, < 80 | B+ | 8 |
| ≥ 60, < 70 | B | 7 |
| ≥ 50, < 60 | C+ | 6 |
| ≥ 45, < 50 | C | 5 |
| ≥ 40, < 45 | D | 4 |
| < 40 | F | 0 |

### Marks Breakdown

| Component | Weightage |
|---|---|
| Best of Minor 1 / Minor 2 | 30% |
| Internal (Assignments/Attendance/Projects) | 20% |
| Major (End Semester Exam) | 50% |

### Passing Criteria
- Minimum **10 marks** in minor examinations
- Minimum **20% marks** in the major (end semester) examination
- Overall minimum **40%** to avoid an F grade

### Practical Subjects
- Identified by a `_P` suffix in the subject name (e.g., `Physics_P`)
- Graded out of **50 marks** (internally doubled to 100 for grade calculation)

### SGPA & CGPA
- **SGPA** (Semester Grade Point Average) = Σ(Grade Points × Credits) / Σ Credits (only for passed subjects)
- **CGPA** = Running average of SGPA across all semesters

---

## 🗄️ Data Files

All data is persisted in plain text files under `main_dir/Files/`:

### `Student_data.txt`
```
<serial_no>  <roll_no>  <name>  <branch>  <section>
```

### `Student_marks1.txt`
```
<serial_no>  <semester>  <subject_name>  <minor1>  <minor2>  <internal>  <major>  <total>  <grade>
```

### `Subject_data.txt`
```
<semester>  <branch>  <subject_name>  <subject_code>  <credits>
```

### `Credentials.txt`
```
<login_type>  <roll_no>  <password>
```

### Supported Branches

The sorting and branch-filtering system supports the following branch codes:

`CSE` · `IT` · `ECE` · `EEE` · `ME` · `BIO`

---

## ⚠️ Known Issues / Limitations

- **Windows Only** — Uses `<windows.h>` for colored console output and `system("CLS")` for screen clearing. Not portable to Linux/macOS without modification.
- **No database** — All data is stored in plain text files. Concurrent access is not supported.
- **Admin module is incomplete** — The Admin portal currently shows a placeholder "Work In Progress" screen.
- **Single-word names only** — Student names and branch names are read as single tokens (no spaces).
- **No input sanitization** — Entering non-integer values where integers are expected may cause unexpected behavior in some menus.
- **Relative file paths** — The executable must always be run from `main_dir/src/` for file I/O to work correctly.

---

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

---

## License

This project is open-source and available under the [MIT License](LICENSE).

