#!/bin/bash
# Verilatorを使ってVerilogコードをC++に変換
#
# counter.v: Verilogコード
# main.cpp: C++のテストベンチコード
# 実行方法: ./do-verilator.sh

#verilator --cc counter.v --exe main.cpp --top-module counter --threads 0 -o Vcounter_sim
verilator --no-timing --cc TD4.v --exe main.cpp --top-module TD4 --threads 1 --threads-dpi none -o VTD4_sim
#verilator --cc counter.v --exe main.cpp --top-module counter --no-threads -o Vcounter_sim

#    Vcounter.h、Vcounter.cpp、Vcounter__Trace.cpp などが生成されます。
