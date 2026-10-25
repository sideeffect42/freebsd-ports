--- Source/JavaScriptCore/assembler/ARM64Assembler.h.orig	2026-07-24 10:02:50.530577200 +0200
+++ Source/JavaScriptCore/assembler/ARM64Assembler.h	2026-10-25 09:50:46.169403000 +0100
@@ -4016,6 +4016,11 @@
     {
         __builtin___clear_cache(reinterpret_cast<char*>(begin), reinterpret_cast<char*>(end));
     }
+#elif OS(FREEBSD) || OS(NETBSD) || OS(OPENBSD)
+    static inline void bsdPageFlush(void *begin, size_t size)
+    {
+        __clear_cache(begin, (reinterpret_cast<char*>(code) + size));
+    }
 #endif
 
     static void cacheFlush(void* code, size_t size)
@@ -4041,6 +4046,8 @@
             linuxPageFlush(current, current + page);
 
         linuxPageFlush(current, end);
+#elif OS(FREEBSD) || OS(NETBSD) || OS(OPENBSD)
+        bsdPageFlush(code, size);
 #elif OS(WINDOWS)
         FlushInstructionCache(GetCurrentProcess(), code, size);
 #else
