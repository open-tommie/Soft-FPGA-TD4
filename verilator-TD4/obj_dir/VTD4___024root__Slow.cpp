// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTD4.h for the primary calling header

#include "VTD4__pch.h"
#include "VTD4__Syms.h"
#include "VTD4___024root.h"

void VTD4___024root___ctor_var_reset(VTD4___024root* vlSelf);

VTD4___024root::VTD4___024root(VTD4__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VTD4___024root___ctor_var_reset(this);
}

void VTD4___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VTD4___024root::~VTD4___024root() {
}
