# Student Result System (C++)

## English

### Overview
A simple console-based **Student Result System** written in **C++**.  
It takes a student's full name and grades for 6 subjects, then prints a final report containing:

- **Average (%)**
- **Failed subjects count** (grade < 50)
- **Final result** (Excellent / Very Good / Good / Pass / Fail)

### Project location
- **Folder**: `studednt resultsystem/`
- **Source file**: `student result system.cpp`

### Requirements
- Windows 10/11
- A C++ compiler:
  - **MinGW g++** (recommended), or
  - **Visual Studio (MSVC)**

### Build & Run (Windows)

#### Option A) MinGW (g++)
Open PowerShell in the repository root and run:

```bat
cd "studednt resultsystem"
g++ -std=c++17 -O2 -Wall "student result system.cpp" -o student_result.exe
.\student_result.exe
```

#### Option B) Visual Studio (MSVC)
Open **Developer Command Prompt for VS** and run:

```bat
cd "studednt resultsystem"
cl /EHsc "student result system.cpp"
"student result system.exe"
```

### How it works (Program flow)
- Enter **Student Full Name**
- Enter **6 subject grades**
- The program calculates the **average** and counts subjects with grade **< 50**
- It prints `FINAL REPORT`

### Example (sample run)

```text
Enter Student Full Name: Ahmed Ali
Enter grade for calculus: 80
Enter grade for Programming: 90
Enter grade for IT fundemntals: 75
Enter grade for arabic: 88
Enter grade for digital Logic: 70
Enter grade for copmputer organizations: 60

---- FINAL REPORT ----
Student Name: Ahmed Ali
Average: 77.1667%
Failed Subjects: 0
Final Result: Good
```

---

## العربية

### نظرة عامة
برنامج كونسول بسيط بلغة **++C** لحساب **نتيجة الطالب**.  
يقوم باستقبال الاسم الكامل ودرجات 6 مواد، ثم يطبع تقريرًا نهائيًا يحتوي على:

- **المعدل (%)**
- **عدد المواد الراسبة** (أقل من 50)
- **التقدير النهائي** (Excellent / Very Good / Good / Pass / Fail)

### مكان المشروع
- **المجلد**: `studednt resultsystem/`
- **ملف الكود**: `student result system.cpp`

### المتطلبات
- Windows 10/11
- مترجم ++C:
  - **MinGW g++** (مفضّل) أو
  - **Visual Studio (MSVC)**

### التجميع والتشغيل (Windows)

#### الطريقة A) باستخدام MinGW (g++)
افتح PowerShell في جذر المستودع ثم نفّذ:

```bat
cd "studednt resultsystem"
g++ -std=c++17 -O2 -Wall "student result system.cpp" -o student_result.exe
.\student_result.exe
```

#### الطريقة B) باستخدام Visual Studio (MSVC)
افتح **Developer Command Prompt for VS** ثم نفّذ:

```bat
cd "studednt resultsystem"
cl /EHsc "student result system.cpp"
"student result system.exe"
```

### آلية العمل
- إدخال **اسم الطالب بالكامل**
- إدخال درجات **6 مواد**
- حساب **المعدل** وعدّ المواد التي درجتها **أقل من 50**
- طباعة تقرير بعنوان `FINAL REPORT`

### مثال تشغيل (مخرجات تجريبية)

```text
Enter Student Full Name: Ahmed Ali
Enter grade for calculus: 80
Enter grade for Programming: 90
Enter grade for IT fundemntals: 75
Enter grade for arabic: 88
Enter grade for digital Logic: 70
Enter grade for copmputer organizations: 60

---- FINAL REPORT ----
Student Name: Ahmed Ali
Average: 77.1667%
Failed Subjects: 0
Final Result: Good
```
