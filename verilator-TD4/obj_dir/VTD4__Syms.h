// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTD4__SYMS_H_
#define VERILATED_VTD4__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VTD4.h"

// INCLUDE MODULE CLASSES
#include "VTD4___024root.h"
#include "VTD4___024unit.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VTD4__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VTD4* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VTD4___024root                 TOP;
    VTD4___024unit                 TOP____024unit;

    // CONSTRUCTORS
    VTD4__Syms(VerilatedContext* contextp, const char* namep, VTD4* modelp);
    ~VTD4__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
