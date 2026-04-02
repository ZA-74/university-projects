# لعبة تخمين الرقم (Number Guessing)

برنامج بسيط بلغة **C++** يطلب من المستخدم تخمين رقم عشوائي بين **1** و **100**، مع تلميحات *Too low* / *Too high* حتى الإجابة الصحيحة، وعدّ محاولات التخمين.

## الملف

- `NumberGuessing.cpp` — الكود المصدري

## المتطلبات

- مترجم يدعم **C++11** أو أحدث (مثل MinGW `g++` أو MSVC).

## الترجمة والتشغيل (ويندوز)

**g++:**

```bash
g++ -std=c++11 -o NumberGuessing.exe NumberGuessing.cpp
NumberGuessing.exe
```

**MSVC:**

```bash
cl /EHsc NumberGuessing.cpp
NumberGuessing.exe
```

## طريقة اللعب

1. شغّل البرنامج؛ تظهر رسالة *Guess a number from 1 to 100*.
2. أدخل رقماً في كل محاولة.
3. *Too low* = الرقم السري أكبر؛ *Too high* = الرقم السري أصغر.
4. عند النجاح تظهر *Correct! Tries: …* مع عدد المحاولات.

## الفكرة البرمجية

يستخدم البرنامج حلقة **`do-while`**: تنفيذ الإدخال والمقارنة مرة على الأقل، ثم التكرار حتى `guess == secret`. التوليد العشوائي بـ `rand()` مع `srand(time(...))`.
