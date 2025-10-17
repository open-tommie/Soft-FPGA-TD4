// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTD4.h for the primary calling header

#include "VTD4__pch.h"
#include "VTD4__Syms.h"
#include "VTD4___024root.h"

VL_ATTR_COLD void VTD4___024root___eval_initial__TOP(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___eval_initial__TOP\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.TD4__DOT__rom[0U] = 0xb3U;
    vlSelfRef.TD4__DOT__rom[1U] = 0xb6U;
    vlSelfRef.TD4__DOT__rom[2U] = 0xbcU;
    vlSelfRef.TD4__DOT__rom[3U] = 0xb8U;
    vlSelfRef.TD4__DOT__rom[4U] = 0xb8U;
    vlSelfRef.TD4__DOT__rom[5U] = 0xbcU;
    vlSelfRef.TD4__DOT__rom[6U] = 0xb6U;
    vlSelfRef.TD4__DOT__rom[7U] = 0xb3U;
    vlSelfRef.TD4__DOT__rom[8U] = 0xb1U;
    vlSelfRef.TD4__DOT__rom[9U] = 0xf0U;
    vlSelfRef.TD4__DOT__rom[0xaU] = 0U;
    vlSelfRef.TD4__DOT__rom[0xbU] = 0U;
    vlSelfRef.TD4__DOT__rom[0xcU] = 0U;
    vlSelfRef.TD4__DOT__rom[0xdU] = 0U;
    vlSelfRef.TD4__DOT__rom[0xeU] = 0U;
    vlSelfRef.TD4__DOT__rom[0xfU] = 0U;
    vlSymsp->TOP____024unit.__VmonitorNum = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTD4___024root___dump_triggers__stl(VTD4___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VTD4___024root___eval_triggers__stl(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___eval_triggers__stl\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTD4___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
