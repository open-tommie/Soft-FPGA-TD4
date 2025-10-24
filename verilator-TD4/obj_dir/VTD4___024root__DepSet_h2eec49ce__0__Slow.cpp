// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTD4.h for the primary calling header

#include "VTD4__pch.h"
#include "VTD4___024root.h"

VL_ATTR_COLD void VTD4___024root___eval_static__TOP(VTD4___024root* vlSelf);

VL_ATTR_COLD void VTD4___024root___eval_static(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___eval_static\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VTD4___024root___eval_static__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__clock__0 = vlSelfRef.clock;
    vlSelfRef.__Vtrigprevexpr___TOP__reset_n__0 = vlSelfRef.reset_n;
    vlSelfRef.__Vtrigprevexpr___TOP__TD4__DOT__pc__0 = 0U;
    vlSelfRef.__Vtrigprevexpr___TOP__alu_data__0 = vlSelfRef.alu_data;
    vlSelfRef.__Vtrigprevexpr___TOP__in_port__0 = vlSelfRef.in_port;
    vlSelfRef.__Vtrigprevexpr___TOP__op__0 = vlSelfRef.op;
    vlSelfRef.__Vtrigprevexpr___TOP__out_port__0 = vlSelfRef.out_port;
    vlSelfRef.__Vtrigprevexpr___TOP__pc_out__0 = vlSelfRef.pc_out;
}

VL_ATTR_COLD void VTD4___024root___eval_static__TOP(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___eval_static__TOP\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.TD4__DOT__pc = 0U;
    vlSelfRef.TD4__DOT__cflag = 1U;
}

VL_ATTR_COLD void VTD4___024root___eval_initial__TOP(VTD4___024root* vlSelf);

VL_ATTR_COLD void VTD4___024root___eval_initial(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___eval_initial\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VTD4___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void VTD4___024root___eval_final(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___eval_final\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTD4___024root___dump_triggers__stl(VTD4___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VTD4___024root___eval_phase__stl(VTD4___024root* vlSelf);

VL_ATTR_COLD void VTD4___024root___eval_settle(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___eval_settle\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            VTD4___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("TD4.v", 9, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VTD4___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTD4___024root___dump_triggers__stl(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___dump_triggers__stl\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTD4___024root___stl_sequent__TOP__0(VTD4___024root* vlSelf);

VL_ATTR_COLD void VTD4___024root___eval_stl(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___eval_stl\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VTD4___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void VTD4___024root___stl_sequent__TOP__0(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___stl_sequent__TOP__0\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.out_port = vlSelfRef.TD4__DOT__reg_out;
    vlSelfRef.pc_out = vlSelfRef.TD4__DOT__pc;
    vlSelfRef.op = vlSelfRef.TD4__DOT__rom[vlSelfRef.TD4__DOT__pc];
    vlSelfRef.TD4__DOT__im = (0xfU & vlSelfRef.TD4__DOT__rom
                              [vlSelfRef.TD4__DOT__pc]);
    vlSelfRef.TD4__DOT__load_sel = (3U & (vlSelfRef.TD4__DOT__rom
                                          [vlSelfRef.TD4__DOT__pc] 
                                          >> 6U));
    vlSelfRef.TD4__DOT__alu_sel = ((3U == (IData)(vlSelfRef.TD4__DOT__load_sel))
                                    ? 3U : (3U & (vlSelfRef.TD4__DOT__rom
                                                  [vlSelfRef.TD4__DOT__pc] 
                                                  >> 4U)));
    vlSelfRef.TD4__DOT__alu_in = ((0U == (IData)(vlSelfRef.TD4__DOT__alu_sel))
                                   ? (IData)(vlSelfRef.TD4__DOT__reg_a)
                                   : ((1U == (IData)(vlSelfRef.TD4__DOT__alu_sel))
                                       ? (IData)(vlSelfRef.TD4__DOT__reg_b)
                                       : ((2U == (IData)(vlSelfRef.TD4__DOT__alu_sel))
                                           ? (IData)(vlSelfRef.in_port)
                                           : 0U)));
    vlSelfRef.alu_data = (0xfU & ((IData)(vlSelfRef.TD4__DOT__alu_in) 
                                  + (IData)(vlSelfRef.TD4__DOT__im)));
    vlSelfRef.TD4__DOT__next_pc = (0xfU & (((3U == (IData)(vlSelfRef.TD4__DOT__load_sel)) 
                                            & ((vlSelfRef.TD4__DOT__rom
                                                [vlSelfRef.TD4__DOT__pc] 
                                                >> 4U) 
                                               | (IData)(vlSelfRef.TD4__DOT__cflag)))
                                            ? (IData)(vlSelfRef.alu_data)
                                            : ((IData)(1U) 
                                               + (IData)(vlSelfRef.TD4__DOT__pc))));
}

VL_ATTR_COLD void VTD4___024root___eval_triggers__stl(VTD4___024root* vlSelf);

VL_ATTR_COLD bool VTD4___024root___eval_phase__stl(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___eval_phase__stl\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VTD4___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        VTD4___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTD4___024root___dump_triggers__ico(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___dump_triggers__ico\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VTD4___024root___dump_triggers__act(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___dump_triggers__act\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clock)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge reset_n)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @( TD4.pc)\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @( alu_data)\n");
    }
    if ((0x10ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @( clock)\n");
    }
    if ((0x20ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @( in_port)\n");
    }
    if ((0x40ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 6 is active: @( op)\n");
    }
    if ((0x80ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 7 is active: @( out_port)\n");
    }
    if ((0x100ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 8 is active: @( pc_out)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VTD4___024root___dump_triggers__nba(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___dump_triggers__nba\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clock)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge reset_n)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @( TD4.pc)\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @( alu_data)\n");
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @( clock)\n");
    }
    if ((0x20ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @( in_port)\n");
    }
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 6 is active: @( op)\n");
    }
    if ((0x80ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 7 is active: @( out_port)\n");
    }
    if ((0x100ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 8 is active: @( pc_out)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTD4___024root___ctor_var_reset(VTD4___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTD4___024root___ctor_var_reset\n"); );
    VTD4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clock = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5452235342940299466ull);
    vlSelf->reset_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14129604614540204776ull);
    vlSelf->in_port = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13757102152313978848ull);
    vlSelf->pc_out = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4379395961601650806ull);
    vlSelf->op = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3630531923276091163ull);
    vlSelf->out_port = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14082562809818315590ull);
    vlSelf->alu_data = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14578465531364390362ull);
    vlSelf->TD4__DOT__reg_a = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5334183407208277687ull);
    vlSelf->TD4__DOT__reg_b = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6986839260762812606ull);
    vlSelf->TD4__DOT__reg_out = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12694129959777793359ull);
    vlSelf->TD4__DOT__pc = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17879370140953207570ull);
    vlSelf->TD4__DOT__cflag = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5896350294259003891ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->TD4__DOT__rom[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14108967976894027539ull);
    }
    vlSelf->TD4__DOT__alu_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16999026452724883536ull);
    vlSelf->TD4__DOT__load_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15184404071616404868ull);
    vlSelf->TD4__DOT__im = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6360516191144242940ull);
    vlSelf->TD4__DOT__alu_in = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14752872427280325084ull);
    vlSelf->TD4__DOT__next_pc = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17253731895648379276ull);
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13272892335938733197ull);
    vlSelf->__Vtrigprevexpr___TOP__reset_n__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13318404360585350920ull);
    vlSelf->__Vtrigprevexpr___TOP__TD4__DOT__pc__0 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4681179123285911019ull);
    vlSelf->__Vtrigprevexpr___TOP__alu_data__0 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14643684688691474059ull);
    vlSelf->__Vtrigprevexpr___TOP__in_port__0 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 848867331792178647ull);
    vlSelf->__Vtrigprevexpr___TOP__op__0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2789152853020238382ull);
    vlSelf->__Vtrigprevexpr___TOP__out_port__0 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12925706689802917036ull);
    vlSelf->__Vtrigprevexpr___TOP__pc_out__0 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9088151162618904628ull);
    vlSelf->__VactDidInit = 0;
}
