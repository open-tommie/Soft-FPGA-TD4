// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTD4.h for the primary calling header

#include "VTD4__pch.h"
#include "VTD4__Syms.h"
#include "VTD4___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VTD4___024root___dump_triggers__ico(VTD4___024root* vlSelf);
#endif  // VL_DEBUG

void VTD4___024root___eval_triggers__ico(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___eval_triggers__ico\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTD4___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTD4___024root___dump_triggers__act(VTD4___024root* vlSelf);
#endif  // VL_DEBUG

void VTD4___024root___eval_triggers__act(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___eval_triggers__act\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.clock) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clock__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.reset_n)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__reset_n__0)));
    vlSelfRef.__VactTriggered.setBit(2U, ((IData)(vlSelfRef.TD4__DOT__pc) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__TD4__DOT__pc__0)));
    vlSelfRef.__VactTriggered.setBit(3U, ((IData)(vlSelfRef.alu_data) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__alu_data__0)));
    vlSelfRef.__VactTriggered.setBit(4U, ((IData)(vlSelfRef.clock) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clock__0)));
    vlSelfRef.__VactTriggered.setBit(5U, ((IData)(vlSelfRef.in_port) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__in_port__0)));
    vlSelfRef.__VactTriggered.setBit(6U, ((IData)(vlSelfRef.op) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__op__0)));
    vlSelfRef.__VactTriggered.setBit(7U, ((IData)(vlSelfRef.out_port) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__out_port__0)));
    vlSelfRef.__VactTriggered.setBit(8U, ((IData)(vlSelfRef.pc_out) 
                                          != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__pc_out__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__clock__0 = vlSelfRef.clock;
    vlSelfRef.__Vtrigprevexpr___TOP__reset_n__0 = vlSelfRef.reset_n;
    vlSelfRef.__Vtrigprevexpr___TOP__TD4__DOT__pc__0 
        = vlSelfRef.TD4__DOT__pc;
    vlSelfRef.__Vtrigprevexpr___TOP__alu_data__0 = vlSelfRef.alu_data;
    vlSelfRef.__Vtrigprevexpr___TOP__in_port__0 = vlSelfRef.in_port;
    vlSelfRef.__Vtrigprevexpr___TOP__op__0 = vlSelfRef.op;
    vlSelfRef.__Vtrigprevexpr___TOP__out_port__0 = vlSelfRef.out_port;
    vlSelfRef.__Vtrigprevexpr___TOP__pc_out__0 = vlSelfRef.pc_out;
    if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VactDidInit)))))) {
        vlSelfRef.__VactDidInit = 1U;
        vlSelfRef.__VactTriggered.setBit(2U, 1U);
        vlSelfRef.__VactTriggered.setBit(3U, 1U);
        vlSelfRef.__VactTriggered.setBit(4U, 1U);
        vlSelfRef.__VactTriggered.setBit(5U, 1U);
        vlSelfRef.__VactTriggered.setBit(6U, 1U);
        vlSelfRef.__VactTriggered.setBit(7U, 1U);
        vlSelfRef.__VactTriggered.setBit(8U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTD4___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void VTD4___024root___nba_sequent__TOP__1(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___nba_sequent__TOP__1\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((((~ (IData)(vlSymsp->TOP____024unit.__VmonitorOff)) 
                      & (1U == vlSymsp->TOP____024unit.__VmonitorNum))))) {
        VL_WRITEF_NX("monitor: time=%03t, clock=%b, pc=%02xH %bB, rom[pc]=%02xH %bB, in_port=%02xH, pc_out=%02xH %b, op=%02x %b, out_port=%02xH %b, alu_data=%02xH %b\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,1,(IData)(vlSelfRef.clock),
                     4,vlSelfRef.TD4__DOT__pc,4,(IData)(vlSelfRef.TD4__DOT__pc),
                     8,vlSelfRef.TD4__DOT__rom[vlSelfRef.TD4__DOT__pc],
                     8,vlSelfRef.TD4__DOT__rom[vlSelfRef.TD4__DOT__pc],
                     4,vlSelfRef.in_port,4,(IData)(vlSelfRef.pc_out),
                     4,vlSelfRef.pc_out,8,(IData)(vlSelfRef.op),
                     8,vlSelfRef.op,4,(IData)(vlSelfRef.out_port),
                     4,vlSelfRef.out_port,4,(IData)(vlSelfRef.alu_data),
                     4,vlSelfRef.alu_data);
    }
}
