// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTD4.h for the primary calling header

#ifndef VERILATED_VTD4___024UNIT_H_
#define VERILATED_VTD4___024UNIT_H_  // guard

#include "verilated.h"


class VTD4__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTD4___024unit final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __VmonitorOff;
    QData/*63:0*/ __VmonitorNum;

    // INTERNAL VARIABLES
    VTD4__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTD4___024unit(VTD4__Syms* symsp, const char* v__name);
    ~VTD4___024unit();
    VL_UNCOPYABLE(VTD4___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
