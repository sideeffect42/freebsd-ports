--- Source/JavaScriptCore/offlineasm/arm64.rb.orig	2026-07-24 10:02:50.785346700 +0200
+++ Source/JavaScriptCore/offlineasm/arm64.rb	2026-10-25 10:00:31.798647000 +0100
@@ -1458,8 +1458,8 @@
             $asm.puts "ldr #{operands[1].arm64Operand(:quad)}, [#{operands[1].arm64Operand(:quad)}, #{operands[0].asmLabel}@GOTPAGEOFF]"
             $asm.putStr("#endif")
 
-            # On Linux, use ELF GOT relocation specifiers.
-            $asm.putStr("#elif OS(LINUX)")
+            # On Linux, FreeBSD, and OpenBSD, use ELF GOT relocation specifiers.
+            $asm.putStr("#elif OS(LINUX) || OS(FREEBSD) || OS(OPENBSD)")
 
             $asm.puts "adrp #{operands[1].arm64Operand(:quad)}, :got:#{operands[0].asmLabel}"
             $asm.putStr("#if CPU(ADDRESS32)")
