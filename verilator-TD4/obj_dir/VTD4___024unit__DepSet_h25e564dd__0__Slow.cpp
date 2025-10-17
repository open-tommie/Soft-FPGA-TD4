// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTD4.h for the primary calling header

#include "VTD4__pch.h"
#include "VTD4___024unit.h"

VL_ATTR_COLD void VTD4___024unit___ctor_var_reset(VTD4___024unit* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+  VTD4___024unit___ctor_var_reset\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->__VmonitorNum = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 9173067072191078724ull);
    vlSelf->__VmonitorOff = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9011783253012809090ull);
}
