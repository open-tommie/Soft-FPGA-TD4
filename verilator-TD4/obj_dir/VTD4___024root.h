// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTD4.h for the primary calling header

#ifndef VERILATED_VTD4___024ROOT_H_
#define VERILATED_VTD4___024ROOT_H_  // guard

#include "verilated.h"
class VTD4___024unit;


class VTD4__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTD4___024root final : public VerilatedModule {
  public:
    // CELLS
    VTD4___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    VL_IN8(clock,0,0);
    VL_IN8(reset_n,0,0);
    VL_IN8(in_port,3,0);
    VL_OUT8(pc_out,3,0);
    VL_OUT8(op,7,0);
    VL_OUT8(out_port,3,0);
    VL_OUT8(alu_data,3,0);
    CData/*3:0*/ TD4__DOT__reg_a;
    CData/*3:0*/ TD4__DOT__reg_b;
    CData/*3:0*/ TD4__DOT__reg_out;
    CData/*3:0*/ TD4__DOT__pc;
    CData/*0:0*/ TD4__DOT__cflag;
    CData/*1:0*/ TD4__DOT__alu_sel;
    CData/*1:0*/ TD4__DOT__load_sel;
    CData/*3:0*/ TD4__DOT__im;
    CData/*3:0*/ TD4__DOT__alu_in;
    CData/*3:0*/ TD4__DOT__next_pc;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clock__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__reset_n__0;
    CData/*3:0*/ __Vtrigprevexpr___TOP__TD4__DOT__pc__0;
    CData/*3:0*/ __Vtrigprevexpr___TOP__alu_data__0;
    CData/*3:0*/ __Vtrigprevexpr___TOP__in_port__0;
    CData/*7:0*/ __Vtrigprevexpr___TOP__op__0;
    CData/*3:0*/ __Vtrigprevexpr___TOP__out_port__0;
    CData/*3:0*/ __Vtrigprevexpr___TOP__pc_out__0;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 16> TD4__DOT__rom;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<9> __VactTriggered;
    VlTriggerVec<9> __VnbaTriggered;

    // INTERNAL VARIABLES
    VTD4__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTD4___024root(VTD4__Syms* symsp, const char* v__name);
    ~VTD4___024root();
    VL_UNCOPYABLE(VTD4___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
