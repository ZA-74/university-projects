# Pharmacy Management System (C++)

## English

### Overview
A clean, menu-driven **Pharmacy Management System** written in **C++**.  
It stores medicine records in memory while the program runs, and persists them using **file handling** in `pharmacy_data.txt`.

### Features
- **Medicine struct** with:
  - **ID**
  - **Name**
  - **Price**
  - **Stock Quantity**
- **Menu-driven interface**
  1. Add Medicine
  2. Search by Name
  3. Update Stock
  4. Display All
  5. Exit
- **File Handling**
  - Automatically **loads** data on startup
  - **Saves** after add/update and again on exit
- **Professional console output**
  - Clear headers, separators, aligned tables
- **Input validation**
  - Safe reading for integers/doubles (prevents crashes on invalid input)

### Project Files
- `pharmacymanagmentsystem.cpp`: main program (all logic + functions)
- `pharmacy_data.txt`: data file created/updated by the program (saved in the working directory)

### Data File Format
Each medicine is stored on a single line using this format:

```
id|name|price|stock
```

Example:

```
1|Paracetamol|12.50|100
2|Amoxicillin|35.00|40
```

### How to Run (Windows)

#### Option A) Visual Studio (MSVC)
Open **Developer Command Prompt for VS**, then inside the project folder:

```bat
cl /EHsc pharmacymanagmentsystem.cpp
pharmacymanagmentsystem.exe
```

#### Option B) MinGW (g++)
Make sure `g++` is installed and available in PATH:

```bat
g++ -std=c++17 -O2 -Wall pharmacymanagmentsystem.cpp -o pharmacymanagmentsystem.exe
pharmacymanagmentsystem.exe
```

### Usage Notes
- **Search and update are by medicine name** (case-insensitive exact match).
- **IDs must be unique**; duplicates are rejected.
- The program writes `pharmacy_data.txt` in the **same folder you run the `.exe` from**.

---

## العربية

### نظرة عامة
مشروع **نظام إدارة صيدلية** بلغة **++C** يعمل بقائمة خيارات (Menu).  
يخزّن بيانات الأدوية أثناء التشغيل داخل الذاكرة، ثم يقوم بالحفظ/التحميل باستخدام **الملفات** في `pharmacy_data.txt`.

### المميزات
- استخدام `struct` لتخزين بيانات الدواء:
  - **الرقم (ID)**
  - **الاسم**
  - **السعر**
  - **كمية المخزون**
- واجهة قائمة (Menu) تحتوي على:
  1. إضافة دواء
  2. البحث بالاسم
  3. تحديث المخزون
  4. عرض جميع الأدوية
  5. خروج
- التعامل مع الملفات (File Handling)
  - تحميل البيانات تلقائيًا عند تشغيل البرنامج
  - حفظ البيانات بعد الإضافة/تحديث المخزون، وكذلك عند الخروج
- مخرجات كونسول منظمة واحترافية
  - عناوين واضحة، فواصل، جدول مرتب ومحاذاة للأعمدة
- التحقق من صحة الإدخال
  - إدخال آمن للأرقام والأسعار لتجنب أخطاء/تعطّل البرنامج

### ملفات المشروع
- `pharmacymanagmentsystem.cpp`: ملف البرنامج الرئيسي (الدوال والمنطق بالكامل)
- `pharmacy_data.txt`: ملف البيانات الذي ينشئه البرنامج ويحدّثه (في مجلد التشغيل)

### صيغة ملف البيانات
يتم تخزين كل دواء في سطر واحد بهذه الصيغة:

```
id|name|price|stock
```

مثال:

```
1|Paracetamol|12.50|100
2|Amoxicillin|35.00|40
```

### طريقة التشغيل (Windows)

#### الطريقة A) Visual Studio (MSVC)
افتح **Developer Command Prompt for VS** ثم داخل مجلد المشروع:

```bat
cl /EHsc pharmacymanagmentsystem.cpp
pharmacymanagmentsystem.exe
```

#### الطريقة B) MinGW (g++)
تأكد أن `g++` مثبت ومضاف إلى PATH:

```bat
g++ -std=c++17 -O2 -Wall pharmacymanagmentsystem.cpp -o pharmacymanagmentsystem.exe
pharmacymanagmentsystem.exe
```

### ملاحظات الاستخدام
- البحث والتحديث يتمان **بالاسم** (مطابقة كاملة بدون حساسية لحروف كبيرة/صغيرة).
- يجب أن يكون **ID فريد** لكل دواء (لن يسمح بالتكرار).
- ملف `pharmacy_data.txt` يتم حفظه في **نفس المجلد الذي تشغّل منه البرنامج**.

