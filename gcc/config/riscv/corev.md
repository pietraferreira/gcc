;; Machine description for RISC-V CORE-V operations.
;; Copyright (C) 2023 Free Software Foundation, Inc.

;; This file is part of GCC.

;; GCC is free software; you can redistribute it and/or modify
;; it under the terms of the GNU General Public License as published by
;; the Free Software Foundation; either version 3, or (at your option)
;; any later version.

;; GCC is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.

;; You should have received a copy of the GNU General Public License
;; along with GCC; see the file COPYING3.  If not see
;; <http://www.gnu.org/licenses/>.

(define_c_enum "unspec" [

  ;;CORE-V ALU
  UNSPEC_CV_ALU_CLIP
  UNSPEC_CV_ALU_CLIPR
  UNSPEC_CV_ALU_CLIPU
  UNSPEC_CV_ALU_CLIPUR
  UNSPEC_CV_ALU_ADDN
  UNSPEC_CV_ALU_ADDUN
  UNSPEC_CV_ALU_ADDRN
  UNSPEC_CV_ALU_ADDURN
  UNSPEC_CV_ALU_SUBN
  UNSPEC_CV_ALU_SUBUN
  UNSPEC_CV_ALU_SUBRN
  UNSPEC_CV_ALU_SUBURN
  UNSPEC_CV_ALU_EXTHS
  UNSPEC_CV_ALU_EXTHZ
  UNSPEC_CV_ALU_EXTBS
  UNSPEC_CV_ALU_EXTBZ
])

;; CORE-V ALU builtins
(define_insn "riscv_cv_alu_slet"
  [(set (match_operand:SI 0 "register_operand" "=r")
  (if_then_else (gt:SI (match_operand:SI 1 "register_operand" "r") (match_operand:SI 2 "register_operand" "r")) (const_int 0) (const_int 1)))]
  
  "TARGET_XCVALU && !TARGET_64BIT"
  "cv.slet\t%0, %1, %2" 
  
  [(set_attr "type" "arith")
  (set_attr "mode" "SI")])

(define_insn "riscv_cv_alu_sletu"
  [(set (match_operand:SI 0 "register_operand" "=r")
  (if_then_else (gtu:SI (match_operand:SI 1 "register_operand" "r") (match_operand:SI 2 "register_operand" "r")) (const_int 0) (const_int 1)))]
  
  "TARGET_XCVALU && !TARGET_64BIT"
  "cv.sletu \t%0, %1, %2" 
  
  [(set_attr "type" "arith")
  (set_attr "mode" "SI")])

(define_insn "riscv_cv_alu_min"
  [(set (match_operand:SI 0 "register_operand" "=r")
  (if_then_else (gt:SI (match_operand:SI 1 "register_operand" "r") (match_operand:SI 2 "register_operand" "r")) (match_dup:SI 2) (match_dup:SI 1)))]
  
  "TARGET_XCVALU && !TARGET_64BIT"
  "cv.min\t%0, %1, %2" 
  
  [(set_attr "type" "arith")
  (set_attr "mode" "SI")])

(define_insn "riscv_cv_alu_minu"
  [(set (match_operand:SI 0 "register_operand" "=r")
  (if_then_else (gtu:SI (match_operand:SI 1 "register_operand" "r") (match_operand:SI 2 "register_operand" "r")) (match_dup:SI 2) (match_dup:SI 1)))]
  
  "TARGET_XCVALU && !TARGET_64BIT"
  "cv.minu\t%0, %1, %2" 
  
  [(set_attr "type" "arith")
  (set_attr "mode" "SI")])

(define_insn "riscv_cv_alu_max"
  [(set (match_operand:SI 0 "register_operand" "=r")
  (if_then_else (gt:SI (match_operand:SI 1 "register_operand" "r") (match_operand:SI 2 "register_operand" "r")) (match_dup:SI 1) (match_dup:SI 2)))]
  
  "TARGET_XCVALU && !TARGET_64BIT"
  "cv.max\t%0, %1, %2" 
  
  [(set_attr "type" "arith")
  (set_attr "mode" "SI")])

(define_insn "riscv_cv_alu_maxu"
  [(set (match_operand:SI 0 "register_operand" "=r")
  (if_then_else (gtu:SI (match_operand:SI 1 "register_operand" "r") (match_operand:SI 2 "register_operand" "r")) (match_dup:SI 1) (match_dup:SI 2)))]
  
  "TARGET_XCVALU && !TARGET_64BIT"
  "cv.maxu\t%0, %1, %2" 
  
  [(set_attr "type" "arith")
  (set_attr "mode" "SI")])

(define_insn "riscv_cv_alu_exths"
  [(set (match_operand:SI 0 "register_operand" "=r")
  (unspec:SI [(match_operand:HI 1 "register_operand" "r")]
    UNSPEC_CV_ALU_EXTHS))]

  "TARGET_XCVALU && !TARGET_64BIT"
  "cv.exths\t%0, %1" 
  
  [(set_attr "type" "arith")
  (set_attr "mode" "SI")])

(define_insn "riscv_cv_alu_exthz"
  [(set (match_operand:SI 0 "register_operand" "=r")
  (unspec:SI [(match_operand:HI 1 "register_operand" "r")]
    UNSPEC_CV_ALU_EXTHZ))]
	
  "TARGET_XCVALU && !TARGET_64BIT"
  "cv.exthz\t%0, %1" 
  
  [(set_attr "type" "arith")
  (set_attr "mode" "SI")])

(define_insn "riscv_cv_alu_extbs"
  [(set (match_operand:SI 0 "register_operand" "=r")
  (unspec:SI [(match_operand:QI 1 "register_operand" "r")]
    UNSPEC_CV_ALU_EXTBS))]

  "TARGET_XCVALU && !TARGET_64BIT"
  "cv.extbs\t%0, %1" 
  
  [(set_attr "type" "arith")
  (set_attr "mode" "SI")])

(define_insn "riscv_cv_alu_extbz"
  [(set (match_operand:SI 0 "register_operand" "=r")
  (unspec:SI [(match_operand:QI 1 "register_operand" "r")]
    UNSPEC_CV_ALU_EXTBZ))] 
  "TARGET_XCVALU && !TARGET_64BIT"
  "cv.extbz\t%0, %1" 
  
  [(set_attr "type" "arith")
  (set_attr "mode" "SI")])

(define_insn "riscv_cv_alu_clip"
  [(set (match_operand:SI 0 "register_operand" "=r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r")
  (unspec:SI [(match_operand:SI 1 "register_operand" "r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r") (match_operand:SI 2 "immediate_register_operand" "PALU31,PALU30,PALU29,PALU28,PALU27,PALU26,PALU25,PALU24,PALU23,PALU22,PALU21,PALU20,PALU19,PALU18,PALU17,PALU16,PALU15,PALU14,PALU13,PALU12,PALU11,PALU10,PALU09,PALU08,PALU07,PALU06,PALU05,PALU04,PALU03,PALU02,PALU01,r")]
    UNSPEC_CV_ALU_CLIP))]
  "TARGET_XCVALU && !TARGET_64BIT"
  "@
  cv.clip\t%0,%1,31
  cv.clip\t%0,%1,30
  cv.clip\t%0,%1,29
  cv.clip\t%0,%1,28
  cv.clip\t%0,%1,27
  cv.clip\t%0,%1,26
  cv.clip\t%0,%1,25
  cv.clip\t%0,%1,24
  cv.clip\t%0,%1,23
  cv.clip\t%0,%1,22
  cv.clip\t%0,%1,21
  cv.clip\t%0,%1,20
  cv.clip\t%0,%1,19
  cv.clip\t%0,%1,18
  cv.clip\t%0,%1,17
  cv.clip\t%0,%1,16
  cv.clip\t%0,%1,15
  cv.clip\t%0,%1,14
  cv.clip\t%0,%1,13
  cv.clip\t%0,%1,12
  cv.clip\t%0,%1,11
  cv.clip\t%0,%1,10
  cv.clip\t%0,%1,9
  cv.clip\t%0,%1,8
  cv.clip\t%0,%1,7
  cv.clip\t%0,%1,6
  cv.clip\t%0,%1,5
  cv.clip\t%0,%1,4
  cv.clip\t%0,%1,3
  cv.clip\t%0,%1,2
  cv.clip\t%0,%1,1
  cv.clipr\t%0,%1,%2"

  [(set_attr "type" "arith")
  (set_attr "mode" "SI")])


(define_insn "riscv_cv_alu_clipu"
  [(set (match_operand:SI 0 "register_operand" "=r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r")
  (unspec:SI [(match_operand:SI 1 "register_operand" "r,r,r,r,r,r,,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r,r") (match_operand:SI 2 "immediate_register_operand" "PALU31,PALU30,PALU29,PALU28,PALU27,PALU26,PALU25,PALU24,PALU23,PALU22,PALU21,PALU20,PALU19,PALU18,PALU17,PALU16,PALU15,PALU14,PALU13,PALU12,PALU11,PALU10,PALU09,PALU08,PALU07,PALU06,PALU05,PALU04,PALU03,PALU02,PALU01,r")]
    UNSPEC_CV_ALU_CLIPU))]
  "TARGET_XCVALU && !TARGET_64BIT"
  "@
  cv.clipu\t%0,%1,31
  cv.clipu\t%0,%1,30
  cv.clipu\t%0,%1,29
  cv.clipu\t%0,%1,28
  cv.clipu\t%0,%1,27
  cv.clipu\t%0,%1,26
  cv.clipu\t%0,%1,25
  cv.clipu\t%0,%1,24
  cv.clipu\t%0,%1,23
  cv.clipu\t%0,%1,22
  cv.clipu\t%0,%1,21
  cv.clipu\t%0,%1,20
  cv.clipu\t%0,%1,19
  cv.clipu\t%0,%1,18
  cv.clipu\t%0,%1,17
  cv.clipu\t%0,%1,16
  cv.clipu\t%0,%1,15
  cv.clipu\t%0,%1,14
  cv.clipu\t%0,%1,13
  cv.clipu\t%0,%1,12
  cv.clipu\t%0,%1,11
  cv.clipu\t%0,%1,10
  cv.clipu\t%0,%1,9
  cv.clipu\t%0,%1,8
  cv.clipu\t%0,%1,7
  cv.clipu\t%0,%1,6
  cv.clipu\t%0,%1,5
  cv.clipu\t%0,%1,4
  cv.clipu\t%0,%1,3
  cv.clipu\t%0,%1,2
  cv.clipu\t%0,%1,1
  cv.clipur\t%0,%1,%2"

  [(set_attr "type" "arith")
  (set_attr "mode" "SI")])

(define_insn "riscv_cv_alu_addN"
  [(set (match_operand:SI 0 "register_operand" "=r,r")
  (unspec:SI [(match_operand:SI 1 "register_operand" "r,0")
                      (match_operand:SI 2 "register_operand" "r,r")
                      (match_operand:QI 3 "csr_operand" "K,r")]
    UNSPEC_CV_ALU_ADDN))]
  "TARGET_XCVALU && !TARGET_64BIT"
  "@
  cv.addN\t%0,%1,%2,%3
  cv.addNr\t%0,%2,%3"

  [(set_attr "type" "arith")
  (set_attr "mode" "SI")])

(define_insn "riscv_cv_alu_adduN"
  [(set (match_operand:SI 0 "register_operand" "=r,r")
  (unspec:SI [(match_operand:SI 1 "register_operand" "r,0")
					(match_operand:SI 2 "register_operand" "r,r")
					(match_operand:QI 3 "csr_operand" "K,r")]
    UNSPEC_CV_ALU_ADDUN))]
  "TARGET_XCVALU && !TARGET_64BIT"
  "@
  cv.adduN\t%0,%1,%2,%3
  cv.adduNr\t%0,%2,%3"

  [(set_attr "type" "arith")
  (set_attr "mode" "SI")])

  (define_insn "riscv_cv_alu_addRN"
  [(set (match_operand:SI 0 "register_operand" "=r,r")
  (unspec:SI [(match_operand:SI 1 "register_operand" "r,0")
  (match_operand:SI 2 "register_operand" "r,r") 
  (match_operand:QI 3 "csr_operand" "K,r")]
    UNSPEC_CV_ALU_ADDRN))]
  "TARGET_XCVALU && !TARGET_64BIT"
  "@
  cv.addRN\t%0,%1,%2,%3
  cv.addRNr\t%0,%2,%3"

  [(set_attr "type" "arith")
  (set_attr "mode" "SI")])

  (define_insn "riscv_cv_alu_adduRN"
  [(set (match_operand:SI 0 "register_operand" "=r,r")
  (unspec:SI [(match_operand:SI 1 "register_operand" "r,0")
  (match_operand:SI 2 "register_operand" "r,r") 
  (match_operand:QI 3 "csr_operand" "K,r")]
    UNSPEC_CV_ALU_ADDURN))]
  "TARGET_XCVALU && !TARGET_64BIT"
  "@
  cv.adduRN\t%0,%1,%2,%3
  cv.adduRNr\t%0,%2,%3"

  [(set_attr "type" "arith")
  (set_attr "mode" "SI")])

  (define_insn "riscv_cv_alu_subN"
  [(set (match_operand:SI 0 "register_operand" "=r,r")
  (unspec:SI [(match_operand:SI 1 "register_operand" "r,0")
  (match_operand:SI 2 "register_operand" "r,r") 
  (match_operand:QI 3 "csr_operand" "K,r")]
    UNSPEC_CV_ALU_SUBN))]
  "TARGET_XCVALU && !TARGET_64BIT"
  "@
  cv.subN\t%0,%1,%2,%3
  cv.subNr\t%0,%2,%3"

  [(set_attr "type" "arith")
  (set_attr "mode" "SI")])

  (define_insn "riscv_cv_alu_subuN"
  [(set (match_operand:SI 0 "register_operand" "=r,r")
  (unspec:SI [(match_operand:SI 1 "register_operand" "r,0")
  (match_operand:SI 2 "register_operand" "r,r")
  (match_operand:QI 3 "csr_operand" "K,r")]
    UNSPEC_CV_ALU_SUBUN))]
  "TARGET_XCVALU && !TARGET_64BIT"
  "@
  cv.subuN\t%0,%1,%2,%3
  cv.subuNr\t%0,%2,%3"

  [(set_attr "type" "arith")
  (set_attr "mode" "SI")])

  (define_insn "riscv_cv_alu_subRN"
  [(set (match_operand:SI 0 "register_operand" "=r,r")
  (unspec:SI [(match_operand:SI 1 "register_operand" "r,0")
  (match_operand:SI 2 "register_operand" "r,r") 
  (match_operand:QI 3 "csr_operand" "K,r")]
    UNSPEC_CV_ALU_SUBRN))]
  "TARGET_XCVALU && !TARGET_64BIT"
  "@
  cv.subRN\t%0,%1,%2,%3
  cv.subRNr\t%0,%2,%3"

  [(set_attr "type" "arith")
  (set_attr "mode" "SI")])

  (define_insn "riscv_cv_alu_subuRN"
  [(set (match_operand:SI 0 "register_operand" "=r,r")
  (unspec:SI [(match_operand:SI 1 "register_operand" "r,0")
  (match_operand:SI 2 "register_operand" "r,r") 
  (match_operand:QI 3 "csr_operand" "K,r")]
    UNSPEC_CV_ALU_SUBURN))]
  "TARGET_XCVALU && !TARGET_64BIT"
  "@
  cv.subuRN\t%0,%1,%2,%3
  cv.subuRNr\t%0,%2,%3"

  [(set_attr "type" "arith")
  (set_attr "mode" "SI")])
