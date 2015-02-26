; Test that functions are aligned to the NaCl bundle alignment.
; We could be smarter and only do this for indirect call targets
; but typically you want to align functions anyway.
; Also, we are currently using hlts for non-executable padding.

; RUN: %p2i --filetype=obj --disassemble -i %s --args -O2 | FileCheck %s

define void @foo() {
  ret void
}
; CHECK-LABEL: foo
; CHECK-NEXT: 0: {{.*}} ret
; CHECK-NEXT: 1: {{.*}} hlt

define void @bar() {
  ret void
}
; CHECK-LABEL: bar
; CHECK-NEXT: 20: {{.*}} ret
