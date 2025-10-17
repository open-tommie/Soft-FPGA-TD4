#!/bin/bash
# Verilatorを使ってVerilogコードをC++に変換
#
# MSYS2環境での使用を想定
#
# 実行方法: ./do-verilator.sh

verilator --no-timing --cc TD4.v --exe main.cpp --top-module TD4 --threads 1 --threads-dpi none -o VTD4_sim

#