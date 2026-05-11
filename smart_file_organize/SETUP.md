# شرح التثبيت والتشغيل
# Installation & Setup Guide

## الخطوة 1: المتطلبات الأساسية
## Step 1: Requirements

### تحميل Node.js (إذا لم يكن مثبتاً)
### Download Node.js (if not installed)
- اذهب إلى: https://nodejs.org
- اختر LTS version
- ثبته على جهازك

---

## الخطوة 2: التثبيت الأول
## Step 2: First Installation

### على Windows:
```bash
npm install
```

### على Mac/Linux:
```bash
npm install
chmod +x start.sh
```

---

## الخطوة 3: التشغيل
## Step 3: Running

### على Windows:
1. انقر مرتين على ملف `start.bat`
   - أو استخدم Terminal:
   ```bash
   npm start
   ```

### على Mac/Linux:
```bash
./start.sh
```
أو
```bash
npm start
```

---

## الخطوة 4: الوصول للتطبيق
## Step 4: Access the Application

بعد التشغيل، افتح المتصفح وذهب إلى:
### Open your browser and go to:
```
http://localhost:3000
```

---

## خيارات الوصول من أجهزة أخرى
## Options for Remote Access from Other Devices

### الخيار 1: شبكة محلية (نفس الشبكة)
### Option 1: Local Network (Same WiFi)

1. جد IP address جهازك:
   - Windows: `ipconfig` (ابحث عن IPv4)
   - Mac/Linux: `ifconfig` أو `hostname -I`

2. من جهاز آخر على نفس الشبكة:
   ```
   http://<your-ip>:3000
   ```
   مثال: `http://192.168.1.100:3000`

**ملاحظة**: تأكد أن الـ firewall يسمح بالوصول

---

### الخيار 2: استخدام ngrok (للوصول من أي مكان)
### Option 2: Use ngrok (Remote Access)

1. حمل ngrok من: https://ngrok.com/download

2. ثبته واستخرج الملف

3. افتح Terminal في مجلد ngrok:
   ```bash
   ngrok http 3000
   ```

4. ستحصل على رابط عام مثل:
   ```
   https://abc123xyz.ngrok.io
   ```

5. شارك هذا الرابط - أي شخص يمكنه الوصول!

**ملاحظة**: الرابط يتغير كل مرة تشغل ngrok. للحصول على رابط ثابت، استخدم حساب مدفوع.

---

### الخيار 3: نشر على السحابة
### Option 3: Deploy to Cloud

استخدم:
- **Heroku** (مجاني)
- **Railway.app** (موصى به)
- **Render.com**
- **Replit**
- **Azure** أو **AWS**

---

## استكشاف الأخطاء
## Troubleshooting

### مشكلة: "npm command not found"
- تأكد من تثبيت Node.js بشكل صحيح
- أعد تشغيل Terminal بعد التثبيت

### مشكلة: Port 3000 مستخدم
- غير PORT في `server.js` إلى 3001 مثلاً
- أو أغلق البرنامج الذي يستخدم 3000

### مشكلة: لا يمكن الوصول من جهاز آخر
- تأكد أن الخادم يعمل بدون أخطاء
- تحقق من firewall
- جرب إضافة رابط IP بدلاً من localhost

---

## ملاحظات مهمة
## Important Notes

- التطبيق حالياً يعتمد على ملف `.exe` لـ Windows فقط
- للعمل على جميع الأنظمة تحتاج لبناء نسخ منفصلة:
  - Windows: `smartfileorganize.exe`
  - Mac: `smartfileorganize` (binary)
  - Linux: `smartfileorganize` (binary)

---

## للمزيد من الأسئلة
## Questions?

- تحقق من الأخطاء في Terminal
- اطلب مساعدة من أصدقائك البرمجيين
