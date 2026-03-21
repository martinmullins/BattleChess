/* Battle Chess - Decompiled source (preprocessed for Open Watcom 16-bit DOS build) */
#include "ghidra_types.h"
#include "chess_protos.h"

/* Global variables referenced across segments (Ghidra DAT_ symbols) */
static int DAT_6000_10fc;
static undefined2 *DAT_6000_10fa;
static int DAT_1000_e462;
static int DAT_1000_e464;
static undefined2 DAT_1000_e466;
static undefined2 DAT_1000_e468;
static undefined2 DAT_1000_e46a;
static undefined2 DAT_1000_e46c;

/* Stack-relative address stubs (Ghidra _stack_var_ symbols) */
static undefined1 _stack_var_0000;
static undefined1 _stack_var_0002;

/* Additional cross-segment DAT variables */
static undefined2 DAT_243e_051f;
static byte DAT_9000_b1a0;

/* ---- FUN_1000_0021 @ 1000:0021 ---- */

void FUN_1000_0021()

{
  undefined1 uVar1;
  int in_AX;
  int iVar2;
  undefined2 uVar3;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(int *)(in_BX + unaff_SI) = *(int *)(in_BX + unaff_SI) + in_AX;
  while (*(int *)(unaff_BP + -4) != *(int *)(unaff_BP + 4)) {
    iVar2 = FUN_1000_26fe(*(undefined2 *)(*(int *)(unaff_BP + -4) * 2 + *(int *)(unaff_BP + 6)),
                          0x4bb6);
    if (iVar2 == 0) {
      *(undefined1 *)0x11ab = 3;
    }
    iVar2 = FUN_1000_26fe(*(undefined2 *)(*(int *)(unaff_BP + -4) * 2 + *(int *)(unaff_BP + 6)),
                          0x4bbc);
    if (iVar2 == 0) {
      *(undefined1 *)0x5a = 0xff;
    }
    iVar2 = FUN_1000_26fe(*(undefined2 *)(*(int *)(unaff_BP + -4) * 2 + *(int *)(unaff_BP + 6)),
                          0x4bc2);
    if (iVar2 == 0) {
      FUN_1000_dcca();
    }
    *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) + 1;
  }
  *(int *)0x48 = *(int *)0x48 + 1;
  FUN_1000_29b9();
  func_0x00011012(0x1000,*(undefined1 *)0x11ab);
  if ((*(char *)0x11ab == '\0') || (*(char *)0x11ab == '\x03')) {
    *(undefined2 *)0x8d22 = 0xf;
    *(undefined2 *)0x8dde = 0;
    *(undefined2 *)0x9360 = 0xf;
    *(undefined2 *)0x9348 = 1;
  }
  else {
    *(undefined2 *)0x8d22 = 0xe;
    *(undefined2 *)0x8dde = 1;
    *(undefined2 *)0x9360 = 0xf;
    *(undefined2 *)0x9348 = 9;
  }
  FUN_1000_cc46(*(undefined1 *)0x11aa);
  FUN_1000_c9d0();
  FUN_1000_ca56(0);
  iVar4 = (*(uint *)0x11ab & 0xff) * 4;
  uVar5 = (undefined2)((ulong)*(undefined4 *)0x9648 >> 0x10);
  iVar2 = (int)*(undefined4 *)0x9648;
  FUN_1000_cb5b(*(undefined2 *)(iVar2 + iVar4 + 0x20),*(undefined2 *)(iVar2 + iVar4 + 0x22));
  iVar4 = (*(uint *)0x11ab & 0xff) * 4;
  uVar5 = (undefined2)((ulong)*(undefined4 *)0xa8b6 >> 0x10);
  iVar2 = (int)*(undefined4 *)0xa8b6;
  FUN_1000_cb8f(0,0x110d,*(undefined2 *)(iVar2 + iVar4 + 0x20),*(undefined2 *)(iVar2 + iVar4 + 0x22)
               );
  *(int *)0x48 = *(int *)0x48 + 1;
  *(undefined2 *)0xb0b4 = 0x49f0;
  *(undefined2 *)0xb0b6 = 2;
  *(int *)0x48 = *(int *)0x48 + 1;
  FUN_1000_db8a();
  *(int *)0x48 = *(int *)0x48 + 1;
  uVar5 = 0x10e3;
  func_0x00010eb2(0x10e3);
  FUN_1000_2525();
  *(int *)0x48 = *(int *)0x48 + 1;
  FUN_1000_28ae();
  FUN_1000_2b81(3);
  FUN_1000_3e4f();
  do {
    iVar2 = FUN_1000_ea32(unaff_BP + -8,unaff_BP + -6,unaff_BP + -2);
  } while (iVar2 != 0);
  while (iVar2 = FUN_1000_ea32(unaff_BP + -8,unaff_BP + -6,unaff_BP + -2), iVar2 == 0) {
    uVar3 = FUN_1000_ea5b();
    FUN_1000_f2de(uVar3);
  }
  if (*(int *)(unaff_BP + -2) == 0x3b) {
    FUN_1000_ca56(0);
    uVar3 = (undefined2)((ulong)*(undefined4 *)0x9648 >> 0x10);
    iVar2 = (int)*(undefined4 *)0x9648;
    FUN_1000_cb5b(*(undefined2 *)(iVar2 + 0x10),*(undefined2 *)(iVar2 + 0x12));
    FUN_1000_e03a();
    FUN_1000_e197(0,0x1f09,32000,0);
    FUN_1000_2741();
  }
  FUN_1000_2cac();
  if (*(char *)0x5a == '\0') {
    uVar5 = 0x11ef;
    uVar1 = func_0x00011f3e(0x10e3);
    *(undefined1 *)0x5a = uVar1;
    if ((*(char *)0x5b != '\0') && (iVar2 = FUN_1000_1296(0x4bc8,0xc,3), iVar2 != 0x1003)) {
      *(undefined1 *)0x5a = 0;
    }
  }
  else {
    *(undefined1 *)0x5a = 0;
  }
  FUN_1000_7b86();
  *(undefined2 *)0x482 = 0;
  *(undefined2 *)0x988e = 0;
  *(undefined2 *)0x8dda = 0x114a;
  uVar3 = uVar5;
  if (*(char *)0x5a == '\0') {
    uVar3 = 0x11ef;
    FUN_1000_1f0e(uVar5);
  }
  FUN_1000_1d51(0);
  FUN_1000_1ef0(uVar3);
  do {
    FUN_1000_7ba4();
  } while( true );
}



/* ---- FUN_1000_0254 @ 1000:0254 ---- */

uint FUN_1000_0254()

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 unaff_DS;
  char local_34 [2];
  undefined1 local_32;
  undefined1 local_31;
  undefined2 uStack_12;
  undefined2 uStack_10;
  int iStack_e;
  undefined2 uStack_c;
  int iStack_a;
  char *local_8;
  undefined1 *puVar8;
  
  uVar6 = 0x1000;
  FUN_1000_ecaa();
  if (*(char *)0x44 == '\0') {
    if (*(char *)0x95fa == '\0') {
      if ((*(int *)0xeee == 0) || (*(int *)(*(int *)0x9846 * 2 + 0x53c) == 2)) {
        local_8 = (char *)0x2;
        iStack_a = 0x2c1;
        FUN_1000_17f9();
      }
      else if (*(char *)0x8f44 == '\0') {
        local_8 = (char *)0x1;
        iStack_a = 0x2b5;
        FUN_1000_17f9();
      }
      else {
        local_8 = (char *)0x4;
        iStack_a = 0x2a9;
        FUN_1000_17f9();
      }
    }
    else {
      local_8 = (char *)0x3;
      iStack_a = 0x282;
      FUN_1000_17f9();
    }
  }
  else {
    local_8 = (char *)0x1;
    iStack_a = 0x26f;
    FUN_1000_17f9();
  }
  if (((*(char *)0x5a == '\0') && (*(char *)0x8f44 != '\0')) && (*(char *)0x60 == '\0')) {
    local_8 = (char *)0x1000;
    uVar6 = 0x11ef;
    iStack_a = 0x2de;
    FUN_1000_1ef0(0);
    *(char *)0x60 = *(char *)0x60 + '\x01';
  }
  uVar7 = uVar6;
  if (((*(char *)0x5a == '\0') && (*(char *)0x8f44 == '\0')) && (*(char *)0x60 != '\0')) {
    uVar7 = 0x11ef;
    iStack_a = 0x2fc;
    local_8 = (char *)uVar6;
    FUN_1000_1f0e(0);
    *(char *)0x60 = *(char *)0x60 + -1;
  }
  if (((*(int *)0x53c == 2) || (*(int *)0x53e == 2)) &&
     ((*(char *)0x54 == '\0' && ((*(char *)0x55 == '\0' && (*(char *)0x44 == '\0')))))) {
    local_8 = (char *)0x32f;
    iVar2 = FUN_1000_dc91();
    if (iVar2 != 0) {
      local_8 = local_34;
      iStack_a = 0x33a;
      FUN_1000_ddd3();
      if (local_34[0] == -0x5f) {
        local_8 = (undefined1 *)0xb082;
        puVar8 = &local_32;
        for (iVar2 = 0x21; iVar2 != 0; iVar2 = iVar2 + -1) {
          *local_8 = *puVar8;
          local_8 = local_8 + 1;
          puVar8 = puVar8 + 1;
        }
        *(undefined1 *)0x61 = 1;
      }
      else if (local_34[0] == -0x5e) {
        *(undefined1 *)0x817a = local_32;
        *(undefined1 *)0x817b = local_31;
        *(undefined1 *)0x62 = 1;
        local_8 = (char *)0x358;
        FUN_1000_e00f();
      }
      else if (local_34[0] == -0x57) {
        *(undefined1 *)0x63 = local_32;
        local_8 = (char *)0x391;
        FUN_1000_e00f();
      }
    }
  }
  if (((*(int *)0xeee != 0) && (*(int *)(*(int *)0x9846 * 2 + 0x53c) == 2)) &&
     (*(char *)0x62 != '\0')) {
    *(uint *)0xcbcc = (uint)*(byte *)0x817b;
    *(uint *)0xcbca = (uint)*(byte *)0x817a;
    *(undefined1 *)0x62 = 0;
    local_8 = (char *)0x3d6;
    iVar2 = FUN_1000_8ca1();
    if (iVar2 == 0) {
      local_8 = (char *)0x0;
      iStack_a = 0xc;
      uStack_c = 0x4be2;
      iStack_e = 0x3ed;
      FUN_1000_1296();
      local_8 = (char *)0x1b;
      iStack_a = 0x4be2;
      uStack_c = 0x3fa;
      FUN_1000_dbb5();
      local_8 = (char *)0x1;
      iStack_a = 0x4bfe;
      uStack_c = 0x408;
      FUN_1000_dbb5();
    }
    else if (*(char *)0x61 == '\0') {
      *(undefined2 *)0xeee = 0;
      return 6;
    }
  }
  local_8 = (char *)0x423;
  FUN_1000_f2f0();
  local_8 = (char *)0x426;
  piVar3 = (int *)FUN_1000_184d();
  *(undefined2 *)0x9882 = piVar3;
  iVar2 = *piVar3;
  if (iVar2 == 3) {
    if ((*(int *)0xef4 != 0) && (*(int *)0x988e == 0)) {
      if (*(int *)(*(int *)0x57d0 * 0x1c + 0x5f4) != 0) {
        local_8 = (char *)(*(int *)0x57d0 * 0x1c + 0x5e0);
        iStack_a = 0x510;
        FUN_1000_3f49((undefined2*)0);
      }
      local_8 = (char *)(*(int *)0x57d0 * 0x1c + 0x5e0);
      iStack_a = *(int *)0xef4 * 8 + -0x7df2;
      uStack_c = *(undefined2 *)0x9850;
      iStack_e = *(int *)0x935e + 200;
      uStack_10 = *(undefined2 *)0x933a;
      uStack_12 = 0x53b;
      FUN_1000_3f0f(0,0,0,0,0);
    }
    if (*(int *)0x988e == 0) {
      if ((((*(int *)0xeee != 0) && (*(int *)(*(int *)0x9846 * 2 + 0x53c) != 2)) ||
          ((*(int *)0xef2 != 0 && (*(char *)0x54 == '\0')))) && (*(char *)0x55 == '\0')) {
        local_8 = (char *)*(undefined2 *)0x935e;
        iStack_a = *(int *)0x933a;
        uStack_c = 0x58c;
        FUN_1000_0daf();
      }
      if ((*(char *)0x54 == '\0') && (*(char *)0x55 == '\0')) {
        local_8 = (char *)0x5a0;
        uVar1 = FUN_1000_67fb();
        *(undefined1 *)0xda6 = uVar1;
      }
    }
    else {
      local_8 = (char *)*(undefined2 *)0x935e;
      iStack_a = *(int *)0x933a;
      uStack_c = 0x550;
      FUN_1000_512d();
      local_8 = (char *)0x556;
      FUN_1000_5381();
    }
    if ((((*(char *)0x4a != '\0') && (*(char *)0x4b == '\0')) &&
        (*(undefined1 *)0x4b = *(undefined1 *)0x4a, *(int *)0xef0 != 0)) && (*(int *)0x988e == 0)) {
      *(undefined1 *)0x11b4 = 0x18;
      local_8 = (char *)0x5cd;
      FUN_1000_0886();
      if ((*(int *)0xef4 != 0) && (*(int *)(*(int *)0x57d0 * 0x1c + 0x5f4) != 0)) {
        local_8 = (char *)(*(int *)0x57d0 * 0x1c + 0x5e0);
        iStack_a = 0x5ee;
        FUN_1000_3f49((undefined2*)0);
      }
      local_8 = (char *)0x1;
      iStack_a = 0x5f8;
      FUN_1000_17f9();
      local_8 = (char *)0x5fe;
      FUN_1000_4e5d();
      local_8 = (char *)*(undefined2 *)0x935e;
      iStack_a = *(int *)0x933a;
      uStack_c = 0x609;
      FUN_1000_512d();
      *(undefined2 *)0x988e = 1;
      *(undefined1 *)0x44 = 1;
    }
    if (((*(char *)0x4a == '\0') && (*(char *)0x4b != '\0')) &&
       (*(undefined1 *)0x4b = *(undefined1 *)0x4a, *(int *)0x988e != 0)) {
      *(undefined2 *)0x988e = 0;
      *(undefined1 *)0x44 = 0;
      local_8 = (char *)0x640;
      uVar5 = FUN_1000_5035();
      *(undefined1 *)0x11b4 = 0x3f;
      if (uVar5 == 0) {
        return 0;
      }
      local_8 = (char *)0x2;
      iStack_a = 0x652;
      FUN_1000_17f9();
      return uVar5;
    }
    if (*(char *)0x57 != '\0') {
      *(byte *)0x58 = *(byte *)0x58 ^ 0xe;
      local_8 = (char *)(uint)*(byte *)0x58;
      iStack_a = 0x66f;
      FUN_1000_5b18();
      local_8 = (char *)0x7b;
      iStack_a = (uint)*(byte *)0xb0a3 * 0x20 + 0x80;
      uStack_c = 0x79;
      iStack_e = (uint)*(byte *)0xb0a3 * 0x20 + 0x60;
      uStack_12 = 0x699;
      uStack_10 = uVar7;
      FUN_1000_10d3();
    }
  }
  else if (iVar2 == 4) {
    iVar2 = *(int *)(*(int *)0x9882 + 4);
    if (iVar2 == 1) {
      if (*(char *)0x4a == '\0') {
        if (*(int *)0xefc == 0xff) {
          if (*(int *)0xefa == 0xff) {
            return 0x1003;
          }
          if (*(int *)0xef2 != 0) {
            return 0x1002;
          }
          local_8 = (char *)((*(uint *)0xefa & 0x38) << 1 ^ 0x70 | *(uint *)0xefa & 7);
          iStack_a = 0x755;
          FUN_1000_8c26();
          local_8 = (char *)0xc;
          iStack_a = *(undefined2 *)0xefa;
          uStack_c = 0x763;
          FUN_1000_543a();
          *(undefined2 *)0xefc = *(undefined2 *)0xefa;
          *(undefined2 *)0xefa = 0xff;
        }
        else if (*(int *)0xefa == 0xff) {
          if (*(int *)0xefc == *(int *)0xefe) {
            local_8 = (char *)0x724;
            FUN_1000_0886();
          }
        }
        else {
          if (*(char *)0x61 == '\0') {
            *(uint *)0xcbcc = (*(uint *)0xefc & 0x38) << 1 ^ 0x70 | *(uint *)0xefc & 7;
            *(uint *)0xcbca = (*(uint *)0xefa & 0x38) << 1 ^ 0x70 | *(uint *)0xefa & 7;
            local_8 = (char *)0x6fb;
            FUN_1000_0886();
            *(undefined2 *)0xeee = 0;
            local_8 = (char *)0x2;
            iStack_a = 0x708;
            FUN_1000_17f9();
            return 6;
          }
          local_8 = (char *)0x716;
          FUN_1000_0886();
        }
      }
    }
    else if (iVar2 == 2) {
      *(undefined1 *)0x4a = 0;
    }
    else if (iVar2 == 3) {
      if (*(int *)0xef0 != 0) {
        *(undefined1 *)0x4a = 1;
      }
      if (*(char *)0x54 != '\0') {
        return 0x1004;
      }
    }
  }
  else if (iVar2 == 5) {
    iVar2 = *(int *)0x9882;
    *(undefined2 *)0x933a = *(undefined2 *)(iVar2 + 8);
    *(undefined2 *)0x935e = *(undefined2 *)(iVar2 + 10);
    iStack_a = 0x445;
    local_8 = (char *)uVar7;
    func_0x00011f20();
  }
  else {
    if (iVar2 == 6) {
      iVar2 = *(int *)(*(int *)0x9882 + 4);
      *(int *)0x8dcc = iVar2;
      if (((0x1f < iVar2) && (iVar2 < 0x80)) &&
         (((*(char *)0x55 == '\0' && ((*(char *)0x44 == '\0' && (*(char *)0x54 == '\0')))) &&
          ((*(int *)0x53c == 2 || (*(int *)0x53e == 2)))))) {
        local_8 = (char *)*(undefined2 *)0x8dcc;
        iStack_a = 0x486;
        FUN_1000_14c1();
        return 0;
      }
      local_8 = (char *)0x493;
      FUN_1000_0886();
      for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
        iVar4 = iVar2 * 6;
        if (((uint)*(byte *)(iVar4 + 0x108f) == *(uint *)0x8dcc) &&
           (*(char *)(iVar4 + 0x108e) != '\0')) {
          return *(uint *)(iVar4 + 0x108c);
        }
      }
      if ((*(int *)0x8dcc == 0xf3) && (*(char *)0x10ac != '\0')) {
        return 10;
      }
      return *(uint *)0x8dcc | 0x2000;
    }
    if ((iVar2 == 0x3d) && (*(int *)0xef2 != 0)) {
      local_8 = (char *)0x7be;
      FUN_1000_20d5();
    }
  }
  return 0;
}



/* ---- FUN_1000_07f3 @ 1000:07f3 ---- */

void FUN_1000_07f3()

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  undefined2 uVar3;
  
  uVar1 = 0x1000;
  uVar3 = 0x7fb;
  FUN_1000_ecaa();
  if ((*(int *)0x53c == 2) || (*(int *)0x53e == 2)) {
    uVar3 = 0x80c;
    FUN_1000_157c();
  }
  if (4 < *(int *)0x48) {
    uVar3 = 0x1000;
    uVar1 = 0x10d3;
    FUN_1000_0e0d(0x1000);
  }
  uVar2 = uVar1;
  if (1 < *(int *)0x48) {
    uVar2 = 0x10e3;
    func_0x00011066(uVar1,uVar3);
  }
  FUN_1000_0e0d(uVar2);
  FUN_1000_ebfe(10);
  return;
}



/* ---- FUN_1000_083e @ 1000:083e ---- */

undefined2 FUN_1000_083e()

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  if (*(char *)0x61 == '\0') {
    uVar1 = 0;
  }
  else {
    FUN_1000_e00f();
    *(undefined1 *)0x61 = 0;
    FUN_1000_0886();
    uVar1 = 0xb082;
  }
  return uVar1;
}



/* ---- FUN_1000_0865 @ 1000:0865 ---- */

void FUN_1000_0865()

{
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  FUN_1000_3f7f();
  func_0x0000fbf6(0x1000);
  FUN_1000_5e18();
  if (*(char *)0x5a == '\0') {
    FUN_1000_1d51(0);
  }
  return;
}



/* ---- FUN_1000_0886 @ 1000:0886 ---- */

void FUN_1000_0886()

{
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  if (*(int *)0xefc != 0xff) {
    FUN_1000_543a(*(undefined2 *)0xefc,0);
    *(undefined2 *)0xefc = 0xff;
    func_0x0000fce8(0x1000,*(undefined2 *)0x9846);
  }
  FUN_1000_543a(*(undefined2 *)0xefa,0);
  FUN_1000_543a(*(undefined1 *)0x8dd6,0);
  *(undefined2 *)0xefa = 0xff;
  *(undefined1 *)0x8dd6 = 0xff;
  return;
}



/* ---- FUN_1000_08de @ 1000:08de ---- */

void FUN_1000_08de()

{
  int iVar1;
  undefined2 unaff_SI;
  undefined2 unaff_DI;
  undefined2 unaff_DS;
  uint local_12;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int iVar5;
  
  FUN_1000_ecaa();
  uVar3 = CONCAT22(unaff_DI,unaff_SI);
  *(undefined2 *)0xef2 = 1;
  *(undefined2 *)0x8dda = 0x115e;
  if (*(int *)0xef6 == 0) {
    *(undefined2 *)0xef6 = 1;
    FUN_1000_2a1a();
  }
  FUN_1000_1d51(uVar3);
  *(undefined1 *)0x59 = 1;
  *(undefined1 *)0x96b = 0;
  local_12 = 0;
  while (local_12 < 6) {
    *(undefined2 *)0x974 = 0;
    FUN_1000_3f0f(0x10,local_12 * 0x18 + 0x10,0,(uint)*(byte *)(local_12 + 0xf01) * 8 + -0x7df2,
                  0x960);
    *(undefined2 *)0x974 = 0;
    FUN_1000_3f0f(0x130,0xe0b0,1,(uint)*(byte *)0x185d * 8 + -0x7df2,0x960);
    local_12 = 0x98f;
  }
  *(undefined1 *)0x59 = 0;
  FUN_1000_3f49(0x960);
  FUN_1000_3e4f();
  FUN_1000_0865();
  local_12 = 0;
  while ((int)local_12 < 8) {
    *(undefined1 *)(local_12 + -0x6dd0) = 0xff;
    local_12 = local_12 + 1;
  }
  puVar2 = (undefined1 *)CONCAT22(unaff_DS,(undefined1 *)0xa8ba);
  puVar4 = (undefined1 *)CONCAT22(*(undefined2 *)0x923a,(undefined1 *)*(undefined2 *)0x9238);
  for (local_12 = 0; (int)local_12 < 0x1e0; local_12 = local_12 + 1) {
    iVar1 = (int)((ulong)puVar2 >> 0x10);
    if ((undefined1 *)puVar2 == (undefined1 *)0xffff) {
      iVar1 = iVar1 + 0x1000;
    }
    iVar5 = (int)((ulong)puVar4 >> 0x10);
    if ((undefined1 *)puVar4 == (undefined1 *)0xffff) {
      iVar5 = iVar5 + 0x1000;
    }
    *puVar4 = *puVar2;
    puVar2 = (undefined1 *)CONCAT22(iVar1,(undefined1 *)puVar2 + 1);
    puVar4 = (undefined1 *)CONCAT22(iVar5,(undefined1 *)puVar4 + 1);
  }
  do {
    *(undefined1 *)0x44 = 1;
    iVar1 = FUN_1000_0254();
  } while (iVar1 == 0);
  FUN_1000_0d3b();
  return;
}



/* ---- FUN_1000_0a0d @ 1000:0a0d ---- */

void FUN_1000_0a0d()

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  do {
    *(undefined1 *)0x44 = 1;
    iVar1 = FUN_1000_0254();
    *(int *)(unaff_BP + -6) = iVar1;
  } while (iVar1 == 0);
  FUN_1000_0d3b();
  return;
}



/* ---- FUN_1000_0a1f @ 1000:0a1f ---- */

void FUN_1000_0a1f()

{
  byte bVar1;
  int unaff_BP;
  int iVar2;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(uint *)(unaff_BP + -0x12) = (*(uint *)0xefa & 0x38) << 1 ^ 0x70 | *(uint *)0xefa & 7;
  if (*(int *)0xef4 == 0) {
    iVar2 = *(int *)0xefa;
    if (*(char *)(iVar2 + 0x1166) != '\0') {
      bVar1 = *(byte *)(iVar2 + 0x1166);
      *(uint *)0xef4 = bVar1 & 7;
      *(uint *)0x9850 = (uint)(bVar1 >> 6);
      *(uint *)0x57d0 = (uint)*(byte *)(iVar2 + -0x755c);
      *(undefined1 *)(iVar2 + 0x1166) = 0;
      *(undefined1 *)(*(int *)(unaff_BP + -0x12) * 4 + -0x5746) = 0;
    }
  }
  else {
    if (*(char *)(*(int *)0xefa + 0x1166) != '\0') {
      FUN_1000_3f49((uint)*(byte *)(*(int *)0xefa + -0x755c) * 0x1c + 0x5e0);
    }
    if (*(int *)(*(int *)0x57d0 * 0x1c + 0x5f4) != 0) {
      FUN_1000_3f49(*(int *)0x57d0 * 0x1c + 0x5e0);
    }
    FUN_1000_3f0f(*(undefined2 *)(*(int *)0xefa * 2 + *(int *)0xb0c6),
                  *(undefined2 *)((*(int *)0xefa >> 3) * 2 + *(int *)0xb0c8),*(undefined2 *)0x9850,
                  *(int *)0xef4 * 8 + -0x7df2,*(int *)0x57d0 * 0x1c + 0x5e0);
    *(byte *)(*(int *)0xefa + 0x1166) = *(char *)0x9850 << 6 | *(byte *)0xef4;
    *(undefined1 *)(*(int *)0xefa + -0x755c) = *(undefined1 *)0x57d0;
    iVar2 = *(int *)(unaff_BP + -0x12) * 4;
    *(bool *)(iVar2 + -0x5745) = *(int *)0x9850 == 0;
    *(undefined1 *)(iVar2 + -0x5746) = *(undefined1 *)(*(int *)0xef4 + 0x4c);
    *(undefined2 *)0xef4 = 0;
  }
  FUN_1000_0d65();
  return;
}



/* ---- FUN_1000_0b32 @ 1000:0b32 ---- */

void FUN_1000_0b32()

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  if ((*(int *)0xef4 != 0) && (*(int *)(*(int *)0x57d0 * 0x1c + 0x5f4) != 0)) {
    FUN_1000_3f49(*(int *)0x57d0 * 0x1c + 0x5e0);
    *(undefined2 *)0xef4 = 0;
  }
  iVar1 = (*(int *)0x935e + -4) / 0x18;
  *(int *)(unaff_BP + -0x12) = iVar1;
  if ((-1 < iVar1) && (iVar1 < 6)) {
    if ((*(int *)0x933a < 0x19) && (7 < *(int *)0x933a)) {
      *(uint *)0xef4 = (uint)*(byte *)(iVar1 + 0xf01);
      *(undefined2 *)0x9850 = 0;
    }
    else if ((0x127 < *(int *)0x933a) && (*(int *)0x933a < 0x139)) {
      *(uint *)0xef4 = (uint)*(byte *)(*(int *)(unaff_BP + -0x12) + 0xf01);
      *(undefined2 *)0x9850 = 1;
    }
  }
  if (*(int *)0xef4 != 0) {
    *(undefined2 *)(unaff_BP + -0x12) = 0;
    while ((*(int *)(unaff_BP + -0x12) < 0x20 &&
           (*(int *)(*(int *)(unaff_BP + -0x12) * 0x1c + 0x5f4) != 0))) {
      *(int *)(unaff_BP + -0x12) = *(int *)(unaff_BP + -0x12) + 1;
    }
    if (*(int *)(unaff_BP + -0x12) == 0x20) {
      *(undefined2 *)0xef4 = 0;
      FUN_1000_0d6e(0x4c00);
    }
    else {
      *(undefined2 *)0x57d0 = *(undefined2 *)(unaff_BP + -0x12);
      FUN_1000_3f0f(*(undefined2 *)0x933a,*(int *)0x935e + 200,*(undefined2 *)0x9850,
                    *(int *)0xef4 * 8 + -0x7df2,*(int *)0x57d0 * 0x1c + 0x5e0);
    }
  }
  FUN_1000_0d65();
  return;
}



/* ---- FUN_1000_0c28 @ 1000:0c28 ---- */

void FUN_1000_0c28()

{
  int iVar1;
  uint uVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  iVar1 = FUN_1000_1296(0x4c12,0xc,1);
  if (iVar1 == 0x1003) {
    FUN_1000_3f7f();
    *(undefined2 *)(unaff_BP + -0x10) = 0;
    while (*(int *)(unaff_BP + -0x10) < 0x40) {
      *(undefined1 *)(*(int *)(unaff_BP + -0x10) + 0x1166) = 0;
      uVar2 = (*(uint *)(unaff_BP + -0x10) & 0x38) << 1 ^ 0x70 | *(uint *)(unaff_BP + -0x10) & 7;
      *(uint *)(unaff_BP + -0x14) = uVar2;
      *(undefined1 *)(uVar2 * 4 + -0x5746) = 0;
      *(int *)(unaff_BP + -0x10) = *(int *)(unaff_BP + -0x10) + 1;
    }
  }
  FUN_1000_0d65();
  return;
}



/* ---- FUN_1000_0c80 @ 1000:0c80 ---- */

void FUN_1000_0c80()

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  undefined1 *puVar5;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  uVar4 = *(undefined2 *)0x923a;
  *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)0x9238;
  *(undefined2 *)(unaff_BP + -2) = uVar4;
  *(undefined2 *)(unaff_BP + -10) = 0xa8ba;
  *(undefined2 *)(unaff_BP + -8) = unaff_DS;
  *(undefined2 *)(unaff_BP + -0x10) = 0;
  while (*(int *)(unaff_BP + -0x10) < 0x1e0) {
    puVar5 = (undefined1 *)*(undefined4 *)(unaff_BP + -4);
    piVar1 = (int *)(unaff_BP + -4);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    if (iVar2 == -1) {
      *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 0x1000;
    }
    uVar3 = *puVar5;
    puVar5 = (undefined1 *)*(undefined4 *)(unaff_BP + -10);
    piVar1 = (int *)(unaff_BP + -10);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    if (iVar2 == -1) {
      *(int *)(unaff_BP + -8) = *(int *)(unaff_BP + -8) + 0x1000;
    }
    *puVar5 = uVar3;
    *(int *)(unaff_BP + -0x10) = *(int *)(unaff_BP + -0x10) + 1;
  }
  FUN_1000_3f7f();
  *(undefined2 *)0xef4 = 0;
  FUN_1000_0865();
  FUN_1000_0d65();
  return;
}



/* ---- FUN_1000_0cda @ 1000:0cda ---- */

void FUN_1000_0cda()

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  iVar1 = FUN_1000_8e36();
  *(int *)(unaff_BP + -0x18) = iVar1;
  if (iVar1 != 0) {
    *(undefined2 *)0xef4 = 0;
    FUN_1000_0d6e(iVar1);
    thunk_FUN_1000_0d65();
    return;
  }
  *(undefined2 *)0x8dda = 0x114a;
  *(undefined2 *)0xef4 = 0;
  *(undefined2 *)0xef2 = 0;
  *(undefined2 *)0xef6 = *(undefined2 *)(unaff_BP + -0xc);
  *(undefined2 *)0xeee = *(undefined2 *)(unaff_BP + -0xe);
  FUN_1000_2a1a();
  FUN_1000_3e4f();
  FUN_1000_0865();
  FUN_1000_df71();
  if (*(int *)0xeee != 0) {
    func_0x0000fce8(0x1000,*(undefined2 *)0x9846);
  }
  *(undefined1 *)0x44 = 0;
  FUN_1000_0d68();
  return;
}



/* ---- FUN_1000_0d30 @ 1000:0d30 ---- */

void FUN_1000_0d30()

{
  undefined2 unaff_DS;
  
  *(undefined1 *)0x44 = 0;
  FUN_1000_0d68();
  return;
}



/* ---- thunk_FUN_1000_0d65 @ 1000:0d37 ---- */

void thunk_FUN_1000_0d65()

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  do {
    *(undefined1 *)0x44 = 1;
    iVar1 = FUN_1000_0254();
    *(int *)(unaff_BP + -6) = iVar1;
  } while (iVar1 == 0);
  FUN_1000_0d3b();
  return;
}



/* ---- FUN_1000_0d3b @ 1000:0d3b ---- */

void FUN_1000_0d3b()

{
  int in_AX;
  
  if (in_AX == 0x1002) {
    FUN_1000_0a1f();
    return;
  }
  if (in_AX == 0x1003) {
    FUN_1000_0b32();
    return;
  }
  if (in_AX == 0x3000) {
    FUN_1000_0c28();
    return;
  }
  if (in_AX == 0x3002) {
    FUN_1000_0c80();
    return;
  }
  if (in_AX == 0x3003) {
    FUN_1000_0cda();
    return;
  }
  FUN_1000_0d65();
  return;
}



/* ---- FUN_1000_0d53 @ 1000:0d53 ---- */

void FUN_1000_0d53()

{
  int in_AX;
  
  if (in_AX == 0x3002) {
    FUN_1000_0c80();
    return;
  }
  if (in_AX == 0x3003) {
    FUN_1000_0cda();
    return;
  }
  FUN_1000_0d65();
  return;
}



/* ---- FUN_1000_0d65 @ 1000:0d65 ---- */

void FUN_1000_0d65()

{
  int iVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  do {
    *(undefined1 *)0x44 = 1;
    iVar1 = FUN_1000_0254();
    *(int *)(unaff_BP + -6) = iVar1;
  } while (iVar1 == 0);
  FUN_1000_0d3b();
  return;
}



/* ---- FUN_1000_0d68 @ 1000:0d68 ---- */

void FUN_1000_0d68()

{
  return;
}



/* ---- FUN_1000_0d6e @ 1000:0d6e ---- */

void FUN_1000_0d6e(undefined2 param_1)

{
  FUN_1000_ecaa();
  FUN_1000_1296(param_1,0xc,0);
  return;
}



/* ---- FUN_1000_0d8d @ 1000:0d8d ---- */

undefined2 FUN_1000_0d8d(undefined2 param_1)

{
  FUN_1000_ecaa();
  FUN_1000_1296(param_1,0xc,0);
  FUN_1000_07f3();
  return;
}



/* ---- FUN_1000_0daf @ 1000:0daf ---- */

void FUN_1000_0daf()

{
  int param_1 = 0; int param_2 = 0;
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  int *piVar4;
  
  FUN_1000_ecaa();
  iVar2 = 0;
  while ((iVar2 < 9 && (*(int *)(iVar2 * 2 + *(int *)0x8d0c) <= param_2))) {
    iVar2 = iVar2 + 1;
  }
  if (iVar2 < 1) {
    FUN_1000_0f71();
    return;
  }
  if (8 < iVar2) {
    FUN_1000_0f71();
    return;
  }
  iVar3 = 0;
  piVar4 = (int *)((iVar2 + -1) * 0x12 + *(int *)0x8d06);
  while ((iVar3 < 9 && (*piVar4 <= param_1))) {
    iVar3 = iVar3 + 1;
    piVar4 = piVar4 + 1;
  }
  if (0 < iVar3) {
    if (iVar3 < 9) {
      uVar1 = (iVar2 + -1) * 8 | iVar3 - 1U;
      *(uint *)0xefe = uVar1;
      if ((uVar1 == *(uint *)0xefa) || (uVar1 == *(byte *)0x8dd6)) {
        if ((*(char *)0x5a == '\0') || (uVar1 == *(uint *)0xefa)) {
          *(uint *)0x52ce = *(uint *)0x52ce ^ *(uint *)0x52cc;
          FUN_1000_543a(uVar1,*(undefined2 *)0x52ce);
        }
      }
      else {
        FUN_1000_543a(*(undefined2 *)0xefa,0);
        FUN_1000_543a(*(undefined1 *)0x8dd6,0);
        if ((*(int *)0xefa != 0xff) || (*(char *)0x8dd6 != -1)) {
          FUN_1000_543a(*(undefined2 *)0xefc,0xc);
        }
        *(undefined2 *)0xefa = 0xff;
        *(undefined1 *)0x8dd6 = 0xff;
        if ((1 << ((byte)(iVar3 - 1U) & 0x1f) & (uint)*(byte *)(iVar2 + -0x6dd1)) == 0) {
          if (*(char *)0x5a == '\0') {
            if (*(int *)0x8dde == 0) {
              *(undefined2 *)0x52ce = 0xc;
              *(undefined2 *)0x52cc = 3;
            }
            else {
              *(undefined2 *)0x52ce = 10;
              *(undefined2 *)0x52cc = 8;
            }
            *(undefined1 *)0x8dd6 = (char)uVar1;
            FUN_1000_543a(uVar1,*(undefined2 *)0x52ce);
          }
        }
        else {
          if (*(int *)0x8dde == 0) {
            *(undefined2 *)0x52ce = 1;
            *(undefined2 *)0x52cc = 0xe;
          }
          else {
            *(undefined2 *)0x52ce = 9;
            *(undefined2 *)0x52cc = 8;
          }
          FUN_1000_543a(uVar1,*(undefined2 *)0x52ce);
          *(uint *)0xefa = uVar1;
        }
      }
      return;
    }
    FUN_1000_0f2c();
    return;
  }
  FUN_1000_0f2c();
  return;
}



/* ---- FUN_1000_0e0d @ 1000:0e0d ---- */

void FUN_1000_0e0d(int _p1, ...)

{
  uint uVar1;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool in_ZF;
  char in_SF;
  char in_OF;
  
  if (in_ZF || in_OF != in_SF) {
    FUN_1000_0f2c();
    return;
  }
  if (unaff_DI < 9) {
    uVar1 = unaff_SI << 3 | unaff_DI - 1U;
    *(uint *)(unaff_BP + -2) = uVar1;
    *(uint *)0xefe = uVar1;
    if ((*(int *)(unaff_BP + -2) == *(int *)0xefa) ||
       (*(uint *)(unaff_BP + -2) == (uint)*(byte *)0x8dd6)) {
      if ((*(char *)0x5a == '\0') || (*(int *)(unaff_BP + -2) == *(int *)0xefa)) {
        *(uint *)0x52ce = *(uint *)0x52ce ^ *(uint *)0x52cc;
        FUN_1000_543a(*(undefined2 *)(unaff_BP + -2),*(undefined2 *)0x52ce);
      }
    }
    else {
      FUN_1000_543a(*(undefined2 *)0xefa,0);
      FUN_1000_543a(*(undefined1 *)0x8dd6,0);
      if ((*(int *)0xefa != 0xff) || (*(char *)0x8dd6 != -1)) {
        FUN_1000_543a(*(undefined2 *)0xefc,0xc);
      }
      *(undefined2 *)0xefa = 0xff;
      *(undefined1 *)0x8dd6 = 0xff;
      if ((1 << ((byte)(unaff_DI - 1U) & 0x1f) & (uint)*(byte *)(unaff_SI + -0x6dd0)) == 0) {
        if (*(char *)0x5a == '\0') {
          if (*(int *)0x8dde == 0) {
            *(undefined2 *)0x52ce = 0xc;
            *(undefined2 *)0x52cc = 3;
          }
          else {
            *(undefined2 *)0x52ce = 10;
            *(undefined2 *)0x52cc = 8;
          }
          *(undefined1 *)0x8dd6 = *(undefined1 *)(unaff_BP + -2);
          FUN_1000_543a(*(undefined2 *)(unaff_BP + -2),*(undefined2 *)0x52ce);
        }
      }
      else {
        if (*(int *)0x8dde == 0) {
          *(undefined2 *)0x52ce = 1;
          *(undefined2 *)0x52cc = 0xe;
        }
        else {
          *(undefined2 *)0x52ce = 9;
          *(undefined2 *)0x52cc = 8;
        }
        FUN_1000_543a(*(undefined2 *)(unaff_BP + -2),*(undefined2 *)0x52ce);
        *(undefined2 *)0xefa = *(undefined2 *)(unaff_BP + -2);
      }
    }
    return;
  }
  FUN_1000_0f2c();
  return;
}



/* ---- FUN_1000_0f21 @ 1000:0f21 ---- */

void FUN_1000_0f21()

{
  int unaff_BP;
  undefined2 unaff_SS;
  
  FUN_1000_543a(*(undefined2 *)(unaff_BP + -2));
  return;
}



/* ---- FUN_1000_0f2c @ 1000:0f2c ---- */

void FUN_1000_0f2c()

{
  undefined2 unaff_DS;
  
  *(undefined2 *)0xefe = 0xff;
  FUN_1000_1f0e(0x1000);
  FUN_1000_543a(*(undefined2 *)0xefa,0);
  FUN_1000_543a(*(undefined2 *)0xefc,0x1c);
  FUN_1000_543a(*(undefined1 *)0x8dd6,0);
  FUN_1000_1ef0(0x11ef);
  *(undefined2 *)0xefa = 0xff;
  *(undefined1 *)0x8dd6 = 0xff;
  return;
}



/* ---- FUN_1000_0f71 @ 1000:0f71 ---- */

void FUN_1000_0f71()

{
  undefined2 unaff_DS;
  
  *(undefined2 *)0xefe = 0xff;
  FUN_1000_543a(*(undefined2 *)0xefa,0);
  FUN_1000_543a(*(undefined2 *)0xefc,0x1c);
  FUN_1000_543a(*(undefined1 *)0x8dd6,0);
  *(undefined2 *)0xefa = 0xff;
  *(undefined1 *)0x8dd6 = 0xff;
  return;
}



/* ---- FUN_1000_0fb0 @ 1000:0fb0 ---- */

void FUN_1000_0fb0()

{
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  FUN_1000_543a(*(undefined2 *)0xefc,0);
  FUN_1000_543a(*(undefined2 *)0xefa,0);
  *(undefined1 *)0x8d0a = *(undefined1 *)0xefc;
  *(undefined2 *)0xefa = 0xff;
  *(undefined2 *)0xefc = 0xff;
  if ((*(int *)0xef4 != 0) && (*(int *)(*(int *)0x57d0 * 0x1c + 0x5f4) != 0)) {
    FUN_1000_3f49(*(int *)0x57d0 * 0x1c + 0x5e0);
  }
  *(undefined1 *)0x9374 = *(undefined1 *)0xef4;
  *(undefined1 *)0x984e = *(undefined1 *)0xeee;
  *(undefined1 *)0x8fe0 = *(undefined1 *)0xef0;
  *(undefined2 *)0xeee = 0;
  *(undefined2 *)0xef0 = 0;
  *(undefined2 *)0xef4 = 0;
  return;
}



/* ---- FUN_1000_102d @ 1000:102d ---- */

void FUN_1000_102d()

{
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  *(uint *)0xefc = (uint)*(byte *)0x8d0a;
  FUN_1000_543a(*(undefined2 *)0xefc,0x1c);
  *(uint *)0xeee = (uint)*(byte *)0x984e;
  *(uint *)0xef0 = (uint)*(byte *)0x8fe0;
  *(uint *)0xef4 = (uint)*(byte *)0x9374;
  return;
}



/* ---- FUN_1000_1064 @ 1000:1064 ---- */

uint FUN_1000_1064(undefined2 param_1,undefined2 param_2,undefined1 *param_3,int param_4,
                  uint param_5)

{
  undefined2 unaff_DS;
  uint uVar1;
  uint uVar2;
  
  FUN_1000_ecaa();
  *(undefined1 *)0x55 = 1;
  if (param_5 == 0) {
    *param_3 = 0x5f;
    param_3[1] = 0;
  }
  else {
    *param_3 = (undefined1)param_5;
    param_3[1] = 0x5f;
    param_3[2] = 0;
  }
  uVar2 = (uint)(param_5 != 0);
  *(undefined2 *)0x5c8 = param_3;
  *(undefined1 *)0x5c6 = 0xf;
  *(undefined1 *)0x5c7 = *(undefined1 *)0x8dde;
  do {
    FUN_1000_e915(0x5c6,param_1,param_2);
    do {
      param_5 = FUN_1000_0254();
    } while ((param_5 & 0xf000) != 0x2000);
    param_5 = param_5 & 0xfff;
    uVar1 = uVar2;
    if (((0x1f < param_5) && ((int)uVar2 < param_4)) && (param_5 < 0x80)) {
      uVar1 = uVar2 + 1;
      param_3[uVar2] = (undefined1)param_5;
      param_3[uVar1] = 0x5f;
      param_3[uVar2 + 2] = 0;
    }
    uVar2 = uVar1;
    if ((param_5 == 8) && (0 < (int)uVar1)) {
      uVar2 = uVar1 - 1;
      param_3[uVar2] = 0x5f;
      param_3[uVar1] = 0x20;
      param_3[uVar1 + 1] = 0;
    }
  } while (param_5 != 0xd);
  param_3[uVar2] = 0;
  *(undefined1 *)0x55 = 0;
  return uVar2;
}



/* ---- FUN_1000_10d3 @ 1000:10d3 ---- */

undefined2 FUN_1000_10d3()

{
  int iVar1;
  uint uVar2;
  undefined2 in_AX;
  char in_DH;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  uVar2 = CONCAT11((char)((uint)in_AX >> 8),(char)in_AX + in_DH);
  do {
    if (uVar2 == 0x2000) {
      *(byte *)(unaff_BP + 0xd) = *(byte *)(unaff_BP + 0xd) & 0xf;
      if (((0x1f < *(int *)(unaff_BP + 0xc)) && (*(int *)(unaff_BP + -2) < *(int *)(unaff_BP + 10)))
         && (*(int *)(unaff_BP + 0xc) < 0x80)) {
        iVar1 = *(int *)(unaff_BP + -2);
        *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 1;
        *(undefined1 *)(iVar1 + *(int *)(unaff_BP + 8)) = *(undefined1 *)(unaff_BP + 0xc);
        *(undefined1 *)(*(int *)(unaff_BP + -2) + *(int *)(unaff_BP + 8)) = 0x5f;
        *(undefined1 *)(*(int *)(unaff_BP + -2) + *(int *)(unaff_BP + 8) + 1) = 0;
      }
      if ((*(int *)(unaff_BP + 0xc) == 8) && (0 < *(int *)(unaff_BP + -2))) {
        *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + -1;
        *(undefined1 *)(*(int *)(unaff_BP + -2) + *(int *)(unaff_BP + 8)) = 0x5f;
        *(undefined1 *)(*(int *)(unaff_BP + -2) + *(int *)(unaff_BP + 8) + 1) = 0x20;
        *(undefined1 *)(*(int *)(unaff_BP + -2) + *(int *)(unaff_BP + 8) + 2) = 0;
      }
      if (*(int *)(unaff_BP + 0xc) == 0xd) {
        *(undefined1 *)(*(int *)(unaff_BP + -2) + *(int *)(unaff_BP + 8)) = 0;
        *(undefined1 *)0x55 = 0;
        return *(undefined2 *)(unaff_BP + -2);
      }
      FUN_1000_e915(0x5c6);
    }
    uVar2 = FUN_1000_0254();
    *(uint *)(unaff_BP + 0xc) = uVar2;
    uVar2 = uVar2 & 0xf000;
  } while( true );
}



/* ---- FUN_1000_1164 @ 1000:1164 ---- */

undefined4 FUN_1000_1164()

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar6;
  bool bVar7;
  byte local_1a [8];
  undefined2 uStack_12;
  undefined2 uStack_10;
  undefined2 uStack_e;
  byte *pbStack_c;
  undefined2 uStack_a;
  undefined2 local_8;
  uint uVar8;
  int iVar9;
  
  FUN_1000_ecaa();
  local_8 = 0x1177;
  FUN_1000_0fb0();
  do {
    local_8 = *(undefined2 *)0x8dde;
    uStack_a = 0x6f;
    pbStack_c = (byte *)0x13f;
    uStack_e = 0x58;
    uStack_10 = 0;
    uStack_12 = 0x118d;
    FUN_1000_1780(0,0,0,0,0);
    *(undefined2 *)0x5c8 = 0x4c28;
    *(undefined1 *)0x5c6 = *(undefined1 *)0x8d22;
    *(undefined1 *)0x5c7 = *(undefined1 *)0x8dde;
    local_8 = 0x60;
    uStack_a = 8;
    pbStack_c = (byte *)0x5c6;
    uStack_e = 0x11b1;
    FUN_1000_e915();
    local_8 = 0;
    uStack_a = 5;
    pbStack_c = local_1a;
    uStack_e = 0x60;
    uStack_10 = 0xe8;
    uStack_12 = 0x11ca;
    iVar2 = FUN_1000_1064(0,0,0,0,0);
    iVar9 = 0;
    uVar8 = 0;
    if (iVar2 == 0) {
      uVar8 = 0xffff;
      iVar9 = -1;
    }
    else {
      for (iVar5 = 0; iVar5 < iVar2; iVar5 = iVar5 + 1) {
        bVar6 = (int)uVar8 < 0;
        iVar3 = uVar8 << 1;
        bVar7 = CARRY2(uVar8 * 4,uVar8);
        iVar1 = uVar8 * 5;
        uVar4 = uVar8 * 10;
        uVar8 = (local_1a[iVar5] - 0x30) + uVar4;
        iVar9 = ((((iVar9 << 1 | (uint)bVar6) << 1 | (uint)(iVar3 < 0)) + iVar9 + (uint)bVar7) * 2 |
                (uint)(iVar1 < 0)) + (uint)CARRY2(local_1a[iVar5] - 0x30,uVar4);
        if ((local_1a[iVar5] < 0x30) || (0x39 < local_1a[iVar5])) {
          iVar9 = 0;
          uVar8 = 0;
          iVar5 = iVar2;
        }
      }
    }
  } while (((uVar8 == 0 && iVar9 == 0) || (0 < iVar9)) || ((-1 < iVar9 && (10000 < uVar8))));
  local_8 = 0x6f;
  uStack_a = 0x58;
  pbStack_c = (byte *)0x4f;
  uStack_e = 0;
  uStack_10 = 0x1274;
  FUN_1000_58b0();
  local_8 = 0x127a;
  FUN_1000_102d();
  if (iVar9 < 0) {
    iVar9 = 0;
    uVar8 = 0;
  }
  return CONCAT22(iVar9,uVar8);
}



/* ---- FUN_1000_1296 @ 1000:1296 ---- */

undefined2 FUN_1000_1296()

{
  char *param_1 = 0; undefined2 param_2 = 0; int param_3 = 0;
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  undefined2 unaff_DS;
  int iVar6;
  undefined2 uVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  
  FUN_1000_ecaa();
  if (param_3 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 0xc;
  }
  *(undefined1 *)0x54 = 1;
  FUN_1000_0fb0();
  iVar6 = 0;
  pcVar10 = param_1;
  while (*pcVar10 != '\0') {
    iVar6 = iVar6 + 1;
    pcVar10 = pcVar10 + 1;
  }
  if (iVar6 < 0x24) {
    iVar6 = 0x24;
  }
  iVar3 = iVar2 + 0x78;
  FUN_1000_1780(iVar3,0x50,(iVar6 + 1 >> 1) * 8 + 0xa7,iVar3,*(undefined2 *)0x8dde);
  *(undefined2 *)0x5c8 = param_1;
  *(undefined1 *)0x5c6 = *(undefined1 *)0x9360;
  *(undefined1 *)0x5c7 = *(undefined1 *)0x8dde;
  iVar3 = iVar3 + 8;
  FUN_1000_e915(0x5c6,iVar3,0x58);
  *(undefined1 *)0x5c6 = *(undefined1 *)0x8d22;
  if (-1 < param_3) {
    if (param_3 < 2) {
      *(undefined2 *)0x5c8 = 0x4c44;
    }
    else if (param_3 == 2) {
      *(undefined2 *)0x5c8 = 0x4c68;
    }
    else if (param_3 == 3) {
      *(undefined2 *)0x5c8 = 0x4c8e;
    }
  }
  iVar3 = iVar3 + 8;
  uVar9 = 0x5c6;
  uVar8 = 0x1399;
  FUN_1000_e915(0x5c6,iVar3,0x68);
  if (iVar2 != 0) {
    if (param_3 == 1) {
      *(undefined2 *)0x5c8 = 0x4cae;
    }
    else if (param_3 == 2) {
      *(undefined2 *)0x5c8 = 0x4cce;
    }
    else if (param_3 == 3) {
      *(undefined2 *)0x5c8 = 0x4cf0;
    }
    uVar9 = 0x5c6;
    uVar8 = 0x13e3;
    FUN_1000_e915(0x5c6,iVar3 + 8,0x73);
  }
  do {
    iVar6 = FUN_1000_0254();
    if (iVar6 == 0x1003) break;
  } while ((iVar6 != 0x1004) || (iVar2 == 0));
  uVar4 = iVar2 + 0x78;
  cVar5 = '\x02';
  do {
    uVar1 = uVar9 & 1;
    uVar9 = (int)uVar9 >> 1;
    uVar8 = uVar8 >> 1 | (uint)(uVar1 != 0) << 0xf;
    cVar5 = cVar5 + -1;
  } while (cVar5 != '\0');
  uVar9 = 0x50;
  cVar5 = '\x02';
  do {
    uVar1 = uVar4 & 1;
    uVar4 = (int)uVar4 >> 1;
    uVar9 = uVar9 >> 1 | (uint)(uVar1 != 0) << 0xf;
    cVar5 = cVar5 + -1;
  } while (cVar5 != '\0');
  uVar7 = 0x1430;
  FUN_1000_58b0(uVar9,uVar8);
  FUN_1000_102d();
  *(undefined1 *)0x54 = 0;
  return uVar7;
}



/* ---- FUN_1000_1446 @ 1000:1446 ---- */

void FUN_1000_1446()

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  undefined2 **local_6;
  undefined2 local_4;
  
  local_4 = 0x144f;
  FUN_1000_ecaa();
  if ((*(int *)0x53c == 2) || (*(int *)0x53e == 2)) {
    *(undefined2 *)0xeee = 0;
    local_4 = 4;
    local_6 = &local_6;
    FUN_1000_dbb5();
    *(undefined2 *)0x548 = 1;
    local_4 = 0x1484;
    FUN_1000_8aaa();
    while (((*(int *)0x53c == 2 || (*(int *)0x53e == 2)) && (*(char *)0x11a6 == '\0'))) {
      if (*(int *)0x9856 == 0) {
        local_4 = 0x14a3;
        uVar1 = FUN_1000_0254();
        *(undefined2 *)0x9856 = uVar1;
      }
      if (*(int *)0x9856 != 0) {
        local_4 = 0x14b0;
        FUN_1000_872a();
      }
    }
    *(undefined2 *)0x548 = 0;
    *(undefined1 *)0x11a6 = 0;
  }
  return;
}



/* ---- FUN_1000_14c1 @ 1000:14c1 ---- */

void FUN_1000_14c1()

{
  undefined2 param_1 = 0;
  int iVar1;
  undefined2 unaff_DS;
  char local_2a [24];
  undefined2 uStack_12;
  undefined2 uStack_10;
  undefined2 uStack_e;
  char *pcStack_c;
  undefined2 uStack_a;
  char *pcStack_8;
  
  FUN_1000_ecaa();
  pcStack_8 = (char *)0x14d2;
  FUN_1000_0fb0();
  pcStack_8 = (char *)*(undefined2 *)0x8dde;
  uStack_a = 0x70;
  pcStack_c = (char *)0x13f;
  uStack_e = 0x58;
  uStack_10 = 0;
  uStack_12 = 0x14e8;
  FUN_1000_1780(0,0,0,0,0);
  pcStack_8 = (char *)param_1;
  uStack_a = 0x25;
  pcStack_c = local_2a;
  uStack_e = 0x60;
  uStack_10 = 8;
  uStack_12 = 0x14ff;
  iVar1 = FUN_1000_1064(0,0,0,0,0);
  local_2a[iVar1] = '\r';
  pcStack_8 = (char *)0x58;
  uStack_a = 0x4f;
  pcStack_c = (char *)0x0;
  uStack_e = 0x151f;
  FUN_1000_58b0();
  if (1 < iVar1 + 1) {
    if ((((iVar1 + 1 == 4) && (local_2a[0] == '+')) && (local_2a[1] == '+')) && (local_2a[2] == '+')
       ) {
      pcStack_8 = local_2a;
      uStack_a = 0x1549;
      FUN_1000_dbb5();
    }
    else {
      pcStack_8 = local_2a;
      uStack_a = 0x1556;
      FUN_1000_dbb5();
    }
  }
  FUN_1000_102d();
  return;
}



/* ---- FUN_1000_1562 @ 1000:1562 ---- */

void FUN_1000_1562()

{
  FUN_1000_ecaa();
  FUN_1000_dbb5(100,4);
  return;
}



/* ---- FUN_1000_157c @ 1000:157c ---- */

void FUN_1000_157c()

{
  FUN_1000_ecaa();
  FUN_1000_dbb5(0x4d0e,0x18);
  return;
}



/* ---- FUN_1000_1596 @ 1000:1596 ---- */

undefined1 FUN_1000_1596(int param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 unaff_DS;
  bool bVar4;
  
  FUN_1000_ecaa();
  if (*(int *)(param_1 * 2 + 0x53c) == 2) {
    while (*(char *)0x63 == '\0') {
      FUN_1000_0254();
    }
    uVar1 = *(undefined1 *)0x63;
    *(undefined1 *)0x63 = 0;
  }
  else {
    bVar4 = param_1 == 0;
    if (*(int *)0xef6 == 0) {
      uVar2 = 0x136;
    }
    else {
      uVar2 = 300;
    }
    *(undefined1 *)0x96b = 0xfe;
    FUN_1000_1780(0x50,0x3c,0xf0,0x8c,0);
    FUN_1000_3f0f(0x70,uVar2,bVar4,(uint)*(byte *)(*(int *)0x9890 + 0x25) * 8 + -0x7e72,0x960);
    FUN_1000_3e81(0x960);
    *(undefined2 *)0x974 = 0;
    FUN_1000_3f0f(0x90,uVar2,bVar4,(uint)*(byte *)(*(int *)0x9890 + 0x19) * 8 + -0x7e72,0x960);
    FUN_1000_3e81(0x960);
    *(undefined2 *)0x974 = 0;
    FUN_1000_3f0f(0xb0,uVar2,bVar4,(uint)*(byte *)(*(int *)0x9890 + 0x23) * 8 + -0x7e72,0x960);
    FUN_1000_3e81(0x960);
    *(undefined2 *)0x974 = 0;
    FUN_1000_3f0f(0xd0,uVar2,bVar4,(uint)*(byte *)(*(int *)0x9890 + 0x1e) * 8 + -0x7e72,0x960);
    FUN_1000_3e81(0x960);
    *(undefined2 *)0x974 = 0;
    *(undefined1 *)0x96b = 0;
    *(undefined2 *)0x5c8 = 0x4d28;
    *(undefined1 *)0x5c6 = 0xf;
    *(undefined1 *)0x5c7 = 0;
    FUN_1000_e915(0x5c6,0x60,0x7c);
    *(undefined1 *)0x44 = 1;
    *(undefined2 *)0xef0 = 0;
    *(undefined1 *)0x57 = 1;
    *(undefined1 *)0xb0a3 = 0;
    if (*(char *)0x5a == '\0') {
      FUN_1000_22c5(0x61,100);
    }
    do {
      do {
        iVar3 = FUN_1000_0254();
      } while (iVar3 != 0x1003);
    } while ((((*(int *)0x933a < 0x60) || (0xe0 < *(int *)0x933a)) || (*(int *)0x935e < 0x40)) ||
            (0x78 < *(int *)0x935e));
    *(undefined2 *)0xef0 = 1;
    FUN_1000_58b0(0x14,0x3c,0x3c,0x8c);
    *(undefined1 *)0x44 = 0;
    *(undefined1 *)0x57 = 0;
    uVar1 = *(undefined1 *)((*(int *)0x933a + -0x60 >> 5) + 0x6a);
  }
  return uVar1;
}



/* ---- FUN_1000_1780 @ 1000:1780 ---- */

void FUN_1000_1780(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  FUN_1000_ecaa();
  FUN_1000_1f0e(0x1000);
  FUN_1000_5b18(param_5);
  FUN_1000_10d3(0x11ef,param_1,param_2,param_3,param_4);
  FUN_1000_2079(param_1,param_2,param_3,param_4);
  FUN_1000_5b18(0xe);
  for (param_5 = 0; param_5 < 3; param_5 = param_5 + 1) {
    param_4 = param_4 + -1;
    param_3 = param_3 + -1;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
    FUN_1000_2079(param_1,param_2,param_3,param_4);
  }
  FUN_1000_1ef0(0x110d);
  return;
}



/* ---- FUN_1000_17f9 @ 1000:17f9 ---- */

void FUN_1000_17f9()

{
  int param_1 = 0;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  if (param_1 != *(int *)0x46) {
    *(int *)0x46 = param_1;
    FUN_1000_1f0e(0x1000,0xffff);
    FUN_1000_1ef0(0x11ef);
  }
  return;
}



/* ---- FUN_1000_184d @ 1000:184d ---- */

void * FUN_1000_184d()

{
  undefined2 uVar1;
  int iVar2;
  undefined2 ****ppppuVar3;
  undefined2 unaff_DS;
  undefined4 uVar4;
  undefined2 **local_a;
  undefined2 ***local_8;
  undefined2 ***local_6;
  undefined2 ***local_4;
  
  ppppuVar3 = (undefined2 ****)0x1000;
  local_4 = (undefined2 ***)0x1856;
  FUN_1000_ecaa();
  if (*(char *)0x5a == '\0') {
    do {
      local_4 = (undefined2 ***)0x1889;
      uVar4 = FUN_1000_ea5b();
      *(undefined2 *)0x9884 = (int)uVar4;
      *(undefined2 *)0x9886 = (int)((ulong)uVar4 >> 0x10);
      if (*(int *)0x6e == *(int *)0x70) {
        local_4 = &local_4;
        local_6 = &local_6;
        local_8 = &local_8;
        local_a = (undefined2 ***)0x18bc;
        iVar2 = FUN_1000_ea32();
        if (iVar2 == 0) {
          if ((*(int *)0x9886 - *(int *)0xb07c != (uint)(*(uint *)0x9884 < *(uint *)0xb07a)) ||
             (1 < *(uint *)0x9884 - *(uint *)0xb07a)) {
            local_a = (undefined2 ***)0x72;
            uVar1 = *(undefined2 *)0x9886;
            *(undefined2 *)0xb07a = *(undefined2 *)0x9884;
            *(undefined2 *)0xb07c = uVar1;
          }
        }
        else {
          local_4 = (undefined2 ***)(int)(char)local_4;
          local_6 = (undefined2 ***)(int)(char)local_6;
          local_8 = (undefined2 ***)(int)(char)local_8;
          local_a = (undefined2 ***)0x18d5;
          FUN_1000_1917();
        }
      }
      else {
        local_a = (undefined2 **)*(int *)0x6e;
        local_8 = (undefined2 ****)0x18a5;
        local_6 = ppppuVar3;
        local_4 = (undefined2 ***)local_a;
        uVar1 = func_0x0000fd4e();
        *(undefined2 *)0x6e = uVar1;
        ppppuVar3 = (undefined2 ****)0xfbf;
      }
    } while ((undefined2 ***)local_a == (undefined2 ***)0x0);
  }
  else {
    do {
      local_4 = (undefined2 ***)0x1865;
      FUN_1000_2301();
    } while (*(int *)0x6e == *(int *)0x70);
    local_a = (undefined2 **)*(int *)0x6e;
    local_6 = (undefined2 ***)0x1000;
    local_8 = (undefined2 ***)0x187a;
    local_4 = (undefined2 ***)local_a;
    uVar1 = func_0x0000fd4e();
    *(undefined2 *)0x6e = uVar1;
  }
  return (undefined2 ***)local_a;
}



/* ---- FUN_1000_1917 @ 1000:1917 ---- */

int FUN_1000_1917()

{
  byte param_1 = 0; char param_2 = 0; char param_3 = 0;
  undefined2 *puVar1;
  undefined2 *puVar2;
  int *piVar3;
  undefined1 extraout_AH;
  int iVar4;
  undefined2 *puVar5;
  undefined2 uVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  if ((param_1 & 4) == 0) {
    if (*(int *)0x988e == 0) {
      if (*(char *)0x57 == '\0') {
        if (*(char *)0x54 == '\0') {
          if ((param_1 & 8) == 0) {
            if (('`' < param_2) && (param_2 < '{')) {
              param_2 = param_2 + -0x20;
            }
            iVar4 = CONCAT11(extraout_AH,param_2);
            if (*(char *)0x55 == '\0') {
              if ((((*(int *)0xef2 == 0) || (*(char *)0x56 != '\0')) || (*(int *)0xef4 == 0)) ||
                 ((param_3 != 'S' && (param_3 != '\x0e')))) {
                if (((param_2 < 'A') || ('H' < param_2)) && ((param_2 < '1' || ('8' < param_2)))) {
                  if ((param_2 == '\r') || (param_2 == ' ')) {
                    *(undefined2 *)(*(int *)0x70 + 8) = *(undefined2 *)0x933a;
                    *(undefined2 *)(*(int *)0x70 + 10) = *(undefined2 *)0x935e;
                    puVar7 = (undefined2 *)*(undefined2 *)0x70;
                    *puVar7 = 4;
                    puVar7[1] = 0;
                    *(undefined2 *)(*(int *)0x70 + 4) = 1;
                    iVar4 = func_0x0000fd4e(0x1000,*(undefined2 *)0x70);
                    *(int *)0x70 = iVar4;
                  }
                  else if ((param_3 == ';') && (*(int *)0xef0 != 0)) {
                    puVar7 = (undefined2 *)*(undefined2 *)0x70;
                    *puVar7 = 4;
                    puVar7[1] = 0;
                    *(undefined2 *)(*(int *)0x70 + 4) = 3;
                    puVar5 = (undefined2 *)func_0x0000fd4e(0x1000,*(undefined2 *)0x70);
                    *(undefined2 *)0x70 = puVar5;
                    puVar7 = (undefined2 *)0x72;
                    puVar8 = puVar5;
                    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
                      puVar2 = puVar8;
                      puVar8 = puVar8 + 1;
                      puVar1 = puVar7;
                      puVar7 = puVar7 + 1;
                      *puVar2 = *puVar1;
                    }
                    uVar6 = func_0x0000fd4e(0xfbf,puVar5);
                    *(undefined2 *)0x70 = uVar6;
                    FUN_1000_22c5(0x31,8);
                    puVar5 = (undefined2 *)*(undefined2 *)0x70;
                    puVar7 = (undefined2 *)0x72;
                    puVar8 = puVar5;
                    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
                      puVar2 = puVar8;
                      puVar8 = puVar8 + 1;
                      puVar1 = puVar7;
                      puVar7 = puVar7 + 1;
                      *puVar2 = *puVar1;
                    }
                    uVar6 = func_0x0000fd4e(0xfbf,puVar5);
                    *(undefined2 *)0x70 = uVar6;
                    *(undefined2 *)0x484 = 100;
                    iVar4 = FUN_1000_2008(0,1,*(undefined2 *)(*(int *)0x8dda + 2));
                    FUN_1000_22c5(0x55,iVar4 * 8 + 0x31);
                    puVar5 = (undefined2 *)*(undefined2 *)0x70;
                    puVar7 = (undefined2 *)0x72;
                    puVar8 = puVar5;
                    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
                      puVar2 = puVar8;
                      puVar8 = puVar8 + 1;
                      puVar1 = puVar7;
                      puVar7 = puVar7 + 1;
                      *puVar2 = *puVar1;
                    }
                    iVar4 = func_0x0000fd4e(0xfbf,puVar5);
                    *(int *)0x70 = iVar4;
                  }
                  else if (param_3 == '<') {
                    if ((*(int *)0x53c == 2) || (*(int *)0x53e == 2)) {
                      FUN_1000_0886();
                      FUN_1000_14c1(0);
                    }
                  }
                  else if ((param_3 == '=') || (param_3 == '>')) {
                    piVar3 = (int *)*(int *)0x70;
                    *piVar3 = (int)param_3;
                    piVar3[1] = (int)param_3 >> 0xf;
                    iVar4 = func_0x0000fd4e(0x1000,*(undefined2 *)0x70);
                    *(int *)0x70 = iVar4;
                  }
                  else if (*(char *)0x56 == '\0') {
                    iVar4 = func_0x0000fd6a(0x1000,(int)param_3);
                    if ((iVar4 != 0) && (*(char *)0x56 == '\0')) {
                      FUN_1000_1d51(0);
                    }
                  }
                  else {
                    puVar7 = (undefined2 *)*(undefined2 *)0x70;
                    *puVar7 = 7;
                    puVar7[1] = 0;
                    iVar4 = (int)param_3;
                    if (iVar4 == 1) {
                      *(undefined2 *)(*(int *)0x70 + 4) = 0x1b;
                    }
                    else if (iVar4 == 0x48) {
                      *(undefined2 *)(*(int *)0x70 + 4) = 0x80;
                    }
                    else if (iVar4 == 0x4b) {
                      *(undefined2 *)(*(int *)0x70 + 4) = 0x82;
                    }
                    else if (iVar4 == 0x4d) {
                      *(undefined2 *)(*(int *)0x70 + 4) = 0x83;
                    }
                    else if (iVar4 == 0x50) {
                      *(undefined2 *)(*(int *)0x70 + 4) = 0x81;
                    }
                    else {
                      *(undefined2 *)(*(int *)0x70 + 4) = 0;
                    }
                    if (*(int *)(*(int *)0x70 + 4) != 0) {
                      iVar4 = func_0x0000fd4e(0x1000,*(int *)0x70);
                      *(int *)0x70 = iVar4;
                    }
                  }
                }
                else {
                  if ((param_2 < 'A') || ('H' < param_2)) {
                    *(int *)0x88 = -(param_2 + -0x38);
                  }
                  else {
                    *(int *)0x86 = param_2 + -0x41;
                  }
                  FUN_1000_1d51(0);
                }
              }
              else {
                *(undefined2 *)0xefa = 0xff;
                puVar7 = (undefined2 *)*(undefined2 *)0x70;
                *puVar7 = 4;
                puVar7[1] = 0;
                *(undefined2 *)(*(int *)0x70 + 4) = 1;
                iVar4 = func_0x0000fd4e(0x1000,*(undefined2 *)0x70);
                *(int *)0x70 = iVar4;
              }
            }
            else {
              puVar7 = (undefined2 *)*(undefined2 *)0x70;
              *puVar7 = 6;
              puVar7[1] = 0;
              *(int *)(*(int *)0x70 + 4) = (int)param_2;
              iVar4 = 0;
              if (param_2 != 0) {
                iVar4 = func_0x0000fd4e(0x1000,*(undefined2 *)0x70);
                *(int *)0x70 = iVar4;
              }
            }
          }
          else {
            FUN_1000_1c77((int)param_3);
          }
        }
        else {
          FUN_1000_1cfa((int)param_2);
        }
      }
      else {
        FUN_1000_260c((int)param_3);
      }
    }
    else {
      FUN_1000_1da9((int)param_3);
    }
  }
  else {
    iVar4 = 0;
  }
  return iVar4;
}



/* ---- FUN_1000_1c77 @ 1000:1c77 ---- */

void FUN_1000_1c77(int _p1, ...)

{
  char param_1 = (char)_p1;
  undefined2 *puVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  puVar1 = (undefined2 *)*(undefined2 *)0x70;
  *puVar1 = 6;
  puVar1[1] = 0;
  if (param_1 == '\x13') {
    param_1 = 'r';
  }
  else if (param_1 == '\x14') {
    param_1 = 't';
  }
  else if (param_1 == '\x1f') {
    param_1 = 's';
  }
  else if (param_1 == '!') {
    param_1 = 'f';
  }
  else {
    if (param_1 == '$') {
      FUN_1000_1fc2(0x1000);
      return;
    }
    if (param_1 == '2') {
      param_1 = 'm';
    }
  }
  *(int *)(*(int *)0x70 + 4) = param_1 + 0x80;
  uVar2 = func_0x0000fd4e(0x1000,*(undefined2 *)0x70);
  *(undefined2 *)0x70 = uVar2;
  return;
}



/* ---- FUN_1000_1cfa @ 1000:1cfa ---- */

void FUN_1000_1cfa(int param_1)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  if (param_1 == 0xd) {
    param_1 = 1;
  }
  else if (param_1 == 0x1b) {
    param_1 = 3;
  }
  else {
    param_1 = 0;
  }
  puVar1 = (undefined2 *)*(undefined2 *)0x70;
  *puVar1 = 4;
  puVar1[1] = 0;
  *(int *)(*(int *)0x70 + 4) = param_1;
  if (param_1 != 0) {
    uVar2 = func_0x0000fd4e(0x1000,*(undefined2 *)0x70);
    *(undefined2 *)0x70 = uVar2;
  }
  return;
}



/* ---- FUN_1000_1d51 @ 1000:1d51 ---- */

void FUN_1000_1d51(int _p1, ...)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  puVar1 = (undefined2 *)*(undefined2 *)0x70;
  *puVar1 = 5;
  puVar1[1] = 0;
  *(undefined2 *)(*(int *)0x70 + 8) =
       *(undefined2 *)((*(int *)0x88 * 8 + *(int *)0x86) * 2 + *(int *)0xb0c6);
  *(undefined2 *)(*(int *)0x70 + 10) = *(undefined2 *)(*(int *)0x88 * 2 + *(int *)0xb0c8);
  uVar2 = func_0x0000fd4e(0x1000,*(undefined2 *)0x70);
  *(undefined2 *)0x70 = uVar2;
  return;
}



/* ---- FUN_1000_1da9 @ 1000:1da9 ---- */

void FUN_1000_1da9(char param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined2 uVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  if (param_1 == '\x01') {
    FUN_1000_22c5(0,0);
    puVar5 = (undefined2 *)*(undefined2 *)0x70;
    puVar7 = (undefined2 *)0x72;
    puVar8 = puVar5;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      puVar2 = puVar8;
      puVar8 = puVar8 + 1;
      puVar1 = puVar7;
      puVar7 = puVar7 + 1;
      *puVar2 = *puVar1;
    }
    puVar7 = (undefined2 *)func_0x0000fd4e(0x1000,puVar5);
    *(undefined2 *)0x70 = puVar7;
    *puVar7 = 4;
    puVar7[1] = 0;
    *(undefined2 *)(*(int *)0x70 + 4) = 2;
    puVar5 = (undefined2 *)func_0x0000fd4e(0xfbf,*(undefined2 *)0x70);
    *(undefined2 *)0x70 = puVar5;
    puVar7 = (undefined2 *)0x72;
    puVar8 = puVar5;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      puVar2 = puVar8;
      puVar8 = puVar8 + 1;
      puVar1 = puVar7;
      puVar7 = puVar7 + 1;
      *puVar2 = *puVar1;
    }
    uVar6 = func_0x0000fd4e(0xfbf,puVar5);
    *(undefined2 *)0x70 = uVar6;
    FUN_1000_1d51(0);
    puVar5 = (undefined2 *)*(undefined2 *)0x70;
    puVar7 = (undefined2 *)0x72;
    puVar8 = puVar5;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      puVar2 = puVar8;
      puVar8 = puVar8 + 1;
      puVar1 = puVar7;
      puVar7 = puVar7 + 1;
      *puVar2 = *puVar1;
    }
    uVar6 = func_0x0000fd4e(0xfbf,puVar5);
    *(undefined2 *)0x70 = uVar6;
  }
  else if (*(int *)0x47e != 0xff) {
    iVar3 = *(int *)0x480;
    iVar4 = *(int *)0x47e;
    if ((param_1 == '\x1c') || (param_1 == '9')) {
      puVar7 = (undefined2 *)*(undefined2 *)0x70;
      *puVar7 = 4;
      puVar7[1] = 0;
      *(undefined2 *)(*(int *)0x70 + 4) = 2;
      puVar5 = (undefined2 *)func_0x0000fd4e(0x1000,*(undefined2 *)0x70);
      *(undefined2 *)0x70 = puVar5;
      puVar7 = (undefined2 *)0x72;
      puVar8 = puVar5;
      for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
        puVar2 = puVar8;
        puVar8 = puVar8 + 1;
        puVar1 = puVar7;
        puVar7 = puVar7 + 1;
        *puVar2 = *puVar1;
      }
      uVar6 = func_0x0000fd4e(0xfbf,puVar5);
      *(undefined2 *)0x70 = uVar6;
      FUN_1000_1d51(0);
      FUN_1000_2002();
      return;
    }
    if (param_1 == 'H') {
      iVar3 = iVar3 + -1;
    }
    else if (param_1 == 'K') {
      iVar4 = iVar4 + -1;
    }
    else if (param_1 == 'M') {
      iVar4 = iVar4 + 1;
    }
    else if (param_1 == 'P') {
      iVar3 = iVar3 + 1;
    }
    if (*(int *)0x484 <= iVar3) {
      iVar3 = 0;
    }
    if (iVar3 < 0) {
      iVar3 = *(int *)0x484 + -1;
    }
    if (iVar4 < 0) {
      iVar4 = *(int *)0xb0da + -1;
    }
    if (*(int *)0xb0da + -1 < iVar4) {
      iVar4 = 0;
    }
    if (iVar4 == *(int *)0x47e) {
      iVar3 = FUN_1000_2008(iVar3,param_1 == 'P',*(undefined2 *)(*(int *)0x8dda + iVar4 * 4 + 2));
      if (iVar3 != 0xff) {
        FUN_1000_22c5(*(int *)(iVar4 * 2 + 0x53fa) + 0x25,iVar3 * 8 + 0x31,iVar3);
      }
    }
    else {
      FUN_1000_22c5(*(int *)(iVar4 * 2 + 0x53fa) + 1,8);
      puVar7 = (undefined2 *)*(undefined2 *)0x70;
      *puVar7 = 4;
      puVar7[1] = 0;
      *(undefined2 *)(*(int *)0x70 + 4) = 3;
      puVar5 = (undefined2 *)func_0x0000fd4e(0x1000,*(undefined2 *)0x70);
      *(undefined2 *)0x70 = puVar5;
      puVar7 = (undefined2 *)0x72;
      puVar8 = puVar5;
      for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
        puVar2 = puVar8;
        puVar8 = puVar8 + 1;
        puVar1 = puVar7;
        puVar7 = puVar7 + 1;
        *puVar2 = *puVar1;
      }
      uVar6 = func_0x0000fd4e(0xfbf,puVar5);
      *(undefined2 *)0x70 = uVar6;
      iVar3 = FUN_1000_2008(0,1,*(undefined2 *)(*(int *)0x8dda + iVar4 * 4 + 2));
      FUN_1000_22c5(*(int *)(iVar4 * 2 + 0x53fa) + 0x25,iVar3 * 8 + 0x31);
    }
  }
  FUN_1000_2002();
  return;
}



/* ---- FUN_1000_1ef0 @ 1000:1ef0 ---- */

void FUN_1000_1ef0(int _p1, ...)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 *puVar5;
  int unaff_BP;
  undefined2 *puVar6;
  undefined2 *puVar7;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(int *)(unaff_BP + -4) = *(int *)0x484 + -1;
  if (*(int *)(unaff_BP + -2) < 0) {
    iVar3 = *(int *)0xb0da + -1;
  }
  else {
    iVar3 = *(int *)(unaff_BP + -2);
  }
  *(int *)(unaff_BP + -2) = iVar3;
  if (*(int *)0xb0da + -1 < *(int *)(unaff_BP + -2)) {
    uVar4 = 0;
  }
  else {
    uVar4 = *(undefined2 *)(unaff_BP + -2);
  }
  *(undefined2 *)(unaff_BP + -2) = uVar4;
  if (*(int *)(unaff_BP + -2) == *(int *)0x47e) {
    iVar3 = FUN_1000_2008(*(undefined2 *)(unaff_BP + -4),*(char *)(unaff_BP + 4) == 'P',
                          *(undefined2 *)(*(int *)0x8dda + *(int *)(unaff_BP + -2) * 4 + 2));
    *(int *)(unaff_BP + -4) = iVar3;
    if (iVar3 != 0xff) {
      FUN_1000_22c5(*(int *)(*(int *)(unaff_BP + -2) * 2 + 0x53fa) + 0x25,iVar3 * 8 + 0x31);
    }
  }
  else {
    FUN_1000_22c5(*(int *)(*(int *)(unaff_BP + -2) * 2 + 0x53fa) + 1,8);
    puVar6 = (undefined2 *)*(undefined2 *)0x70;
    *puVar6 = 4;
    puVar6[1] = 0;
    *(undefined2 *)(*(int *)0x70 + 4) = 3;
    puVar5 = (undefined2 *)func_0x0000fd4e(0x1000,*(undefined2 *)0x70);
    *(undefined2 *)0x70 = puVar5;
    puVar6 = (undefined2 *)0x72;
    puVar7 = puVar5;
    for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
      puVar2 = puVar7;
      puVar7 = puVar7 + 1;
      puVar1 = puVar6;
      puVar6 = puVar6 + 1;
      *puVar2 = *puVar1;
    }
    uVar4 = func_0x0000fd4e(0xfbf,puVar5);
    *(undefined2 *)0x70 = uVar4;
    iVar3 = FUN_1000_2008(0,1,*(undefined2 *)(*(int *)0x8dda + *(int *)(unaff_BP + -2) * 4 + 2));
    FUN_1000_22c5(*(int *)(*(int *)(unaff_BP + -2) * 2 + 0x53fa) + 0x25,iVar3 * 8 + 0x31);
  }
  FUN_1000_2002();
  return;
}



/* ---- FUN_1000_1f0e @ 1000:1f0e ---- */

void FUN_1000_1f0e(int _p1, ...)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 *puVar5;
  int unaff_BP;
  undefined2 *puVar6;
  undefined2 *puVar7;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  if (*(int *)0xb0da + -1 < *(int *)(unaff_BP + -2)) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined2 *)(unaff_BP + -2);
  }
  *(undefined2 *)(unaff_BP + -2) = uVar3;
  if (*(int *)(unaff_BP + -2) == *(int *)0x47e) {
    iVar4 = FUN_1000_2008(*(undefined2 *)(unaff_BP + -4),*(char *)(unaff_BP + 4) == 'P',
                          *(undefined2 *)(*(int *)0x8dda + *(int *)(unaff_BP + -2) * 4 + 2));
    *(int *)(unaff_BP + -4) = iVar4;
    if (iVar4 != 0xff) {
      FUN_1000_22c5(*(int *)(*(int *)(unaff_BP + -2) * 2 + 0x53fa) + 0x25,iVar4 * 8 + 0x31);
    }
  }
  else {
    FUN_1000_22c5(*(int *)(*(int *)(unaff_BP + -2) * 2 + 0x53fa) + 1,8);
    puVar6 = (undefined2 *)*(undefined2 *)0x70;
    *puVar6 = 4;
    puVar6[1] = 0;
    *(undefined2 *)(*(int *)0x70 + 4) = 3;
    puVar5 = (undefined2 *)func_0x0000fd4e(0x1000,*(undefined2 *)0x70);
    *(undefined2 *)0x70 = puVar5;
    puVar6 = (undefined2 *)0x72;
    puVar7 = puVar5;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      puVar2 = puVar7;
      puVar7 = puVar7 + 1;
      puVar1 = puVar6;
      puVar6 = puVar6 + 1;
      *puVar2 = *puVar1;
    }
    uVar3 = func_0x0000fd4e(0xfbf,puVar5);
    *(undefined2 *)0x70 = uVar3;
    iVar4 = FUN_1000_2008(0,1,*(undefined2 *)(*(int *)0x8dda + *(int *)(unaff_BP + -2) * 4 + 2));
    FUN_1000_22c5(*(int *)(*(int *)(unaff_BP + -2) * 2 + 0x53fa) + 0x25,iVar4 * 8 + 0x31);
  }
  FUN_1000_2002();
  return;
}



/* ---- FUN_1000_1fc2 @ 1000:1fc2 ---- */

void FUN_1000_1fc2(int _p1, ...)

{
  undefined2 in_AX;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(undefined2 *)0x70 = in_AX;
  FUN_1000_2008(0,1);
  FUN_1000_22c5(*(int *)(*(int *)(unaff_BP + -2) * 2 + 0x53fa) + 0x25);
  FUN_1000_2002();
  return;
}



/* ---- FUN_1000_2002 @ 1000:2002 ---- */

void FUN_1000_2002()

{
  return;
}



/* ---- FUN_1000_2008 @ 1000:2008 ---- */

int FUN_1000_2008()

{
  int param_1 = 0; int param_2 = 0; int param_3 = 0;
  undefined2 unaff_DS;
  int iVar1;
  
  FUN_1000_ecaa();
  if (param_2 == 0) {
    param_2 = -1;
  }
  iVar1 = 0;
  while( true ) {
    if (iVar1 == *(int *)0x484) {
      return 0xff;
    }
    if (*(char *)(param_3 + param_1 * 6 + 4) != '\0') break;
    param_1 = param_1 + param_2;
    if (*(int *)0x484 <= param_1) {
      param_1 = 0;
    }
    if (param_1 < 0) {
      param_1 = *(int *)0x484 + -1;
    }
    iVar1 = iVar1 + 1;
  }
  return param_1;
}



/* ---- FUN_1000_2079 @ 1000:2079 ---- */

void FUN_1000_2079(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  FUN_1000_ecaa();
  FUN_1000_10d3(0x1000,param_1,param_2,param_3,param_2);
  FUN_1000_10d3(0x110d,param_3,param_2,param_3,param_4);
  FUN_1000_10d3(0x110d,param_1,param_4,param_3,param_4);
  FUN_1000_10d3(0x110d,param_1,param_2,param_1,param_4);
  return;
}



/* ---- FUN_1000_20d5 @ 1000:20d5 ---- */

void FUN_1000_20d5()

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  undefined2 uVar6;
  int *piVar7;
  undefined2 unaff_DS;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  FUN_1000_ecaa();
  uVar10 = 9;
  *(undefined1 *)0x56 = 1;
  FUN_1000_0886();
  if ((*(int *)0xef4 != 0) && (*(int *)(*(int *)0x57d0 * 0x1c + 0x5f4) != 0)) {
    FUN_1000_3f49(*(int *)0x57d0 * 0x1c + 0x5e0);
  }
  do {
    while( true ) {
      while( true ) {
        iVar9 = 0x2139;
        piVar5 = (int *)FUN_1000_184d();
        iVar8 = *piVar5;
        if (iVar8 != 3) break;
        FUN_1000_578c(uVar10,0x18,0x12);
        uVar10 = uVar10 ^ 9;
      }
      if (iVar8 == 4) break;
      if (iVar8 == 7) {
        if (uVar10 == 0) {
          iVar9 = 0;
          FUN_1000_578c(0,0x18,0x12);
        }
        uVar3 = piVar5[2];
        if (uVar3 == 0x80) {
          if (iVar9 == 7) {
            piVar1 = (int *)0x8a;
            *piVar1 = *piVar1 + -1;
            if (*piVar1 < 0) {
              *(undefined2 *)0x8a = 5;
            }
          }
          else {
            *(int *)0x8a = *(int *)0x8a + -1;
            if (*(int *)0x8a < 6) {
              *(undefined2 *)0x8a = 0xb;
            }
          }
        }
        else if (uVar3 < 0x81) {
          if (uVar3 == 0x1b) {
            FUN_1000_578c(0,0x18,0x12);
            FUN_1000_1d51(0);
            *(undefined2 *)0xefa = 0xff;
            *(undefined1 *)0x56 = 0;
            return;
          }
        }
        else if (uVar3 == 0x81) {
          if (iVar9 == 7) {
            *(int *)0x8a = *(int *)0x8a + 1;
            if (5 < *(int *)0x8a) {
              *(undefined2 *)0x8a = 0;
            }
          }
          else {
            *(int *)0x8a = *(int *)0x8a + 1;
            if (0xb < *(int *)0x8a) {
              *(undefined2 *)0x8a = 6;
            }
          }
        }
        else if ((0x81 < uVar3) && (uVar3 < 0x84)) {
          *(int *)0x8a = (*(int *)0x8a + 6) % 0xc;
        }
      }
    }
  } while (piVar5[2] != 1);
  iVar8 = 0x18;
  FUN_1000_578c(0,0x18,0x12);
  FUN_1000_22c5(iVar8 + 2);
  piVar4 = (int *)*(undefined2 *)0x70;
  piVar7 = piVar4;
  for (iVar8 = 10; iVar8 != 0; iVar8 = iVar8 + -1) {
    piVar2 = piVar7;
    piVar7 = piVar7 + 1;
    piVar1 = piVar5;
    piVar5 = piVar5 + 1;
    *piVar2 = *piVar1;
  }
  uVar6 = func_0x0000fd4e(0x1000,piVar4);
  *(undefined2 *)0x70 = uVar6;
  FUN_1000_1d51(0);
  *(undefined2 *)0xefa = 0xff;
  *(undefined1 *)0x56 = 0;
  return;
}



/* ---- FUN_1000_22c5 @ 1000:22c5 ---- */

void FUN_1000_22c5(undefined2 param_1, ...)

{
  undefined2 param_2 = 0;
  undefined2 *puVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  puVar1 = (undefined2 *)*(undefined2 *)0x70;
  *puVar1 = 5;
  puVar1[1] = 0;
  *(undefined2 *)(*(int *)0x70 + 8) = param_1;
  *(undefined2 *)(*(int *)0x70 + 10) = param_2;
  uVar2 = func_0x0000fd4e(0x1000,*(undefined2 *)0x70);
  *(undefined2 *)0x70 = uVar2;
  return;
}



/* ---- FUN_1000_2301 @ 1000:2301 ---- */

void FUN_1000_2301()

{
  int _stack_var_minus8 = 0; /* stack offset var */
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined2 *puVar6;
  char unaff_DI;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined2 unaff_DS;
  undefined4 uVar9;
  undefined1 *local_a;
  char cVar10;
  uint uVar11;
  
  FUN_1000_ecaa();
  puVar7 = (undefined1 *)0x11ef;
  local_a = (undefined1 *)0x2311;
  func_0x00011fa9();
  if ((*(int *)0x5c != *(int *)0x933a) || (*(int *)0x5e != *(int *)0x935e)) {
    local_a = (undefined1 *)*(undefined2 *)0x5c;
    FUN_1000_22c5(0,0);
  }
  if (*(int *)0x9888 != *(int *)0x8d04) {
    for (uVar11 = 1; uVar11 != 3; uVar11 = uVar11 + 1) {
      puVar8 = puVar7;
      if ((uVar11 & *(uint *)0x8d04) != (uVar11 & *(uint *)0x9888)) {
        puVar6 = (undefined2 *)*(undefined2 *)0x70;
        *puVar6 = 4;
        puVar6[1] = 0;
        *(int *)(*(int *)0x70 + 4) =
             (*(int *)0x8d04 >> ((char)uVar11 - 1U & 0x1f) & 1U) + (uVar11 & 2);
        puVar8 = (undefined1 *)0xfbf;
        local_a = puVar7;
        uVar3 = func_0x0000fd4e();
        *(undefined2 *)0x70 = uVar3;
      }
      puVar7 = puVar8;
    }
    *(undefined2 *)0x9888 = *(undefined2 *)0x8d04;
  }
  uVar9 = FUN_1000_ea5b();
  iVar5 = (int)((ulong)uVar9 >> 0x10);
  uVar11 = (uint)uVar9;
  *(uint *)0x9884 = uVar11;
  *(int *)0x9886 = iVar5;
  if ((iVar5 - *(int *)0xb07c != (uint)(uVar11 < *(uint *)0xb07a)) ||
     (puVar8 = puVar7, 1 < uVar11 - *(uint *)0xb07a)) {
    puVar4 = (undefined2 *)*(undefined2 *)0x70;
    puVar6 = (undefined2 *)0x72;
    for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
      puVar2 = puVar4;
      puVar4 = puVar4 + 1;
      puVar1 = puVar6;
      puVar6 = puVar6 + 1;
      *puVar2 = *puVar1;
    }
    puVar8 = (undefined1 *)0xfbf;
    local_a = puVar7;
    uVar3 = func_0x0000fd4e();
    *(undefined2 *)0x70 = uVar3;
    uVar3 = *(undefined2 *)0x9886;
    *(undefined2 *)0xb07a = *(undefined2 *)0x9884;
    *(undefined2 *)0xb07c = uVar3;
  }
  local_a = &_stack_var_minus8;
  iVar5 = FUN_1000_ea32(&local_a);
  if (iVar5 != 0) {
    puVar6 = (undefined2 *)*(undefined2 *)0x70;
    *puVar6 = 6;
    puVar6[1] = 0;
    if (((uint)local_a & 4) == 0) {
      if (((uint)local_a & 8) == 0) {
  int _stack_var_minus4 = 0; /* stack offset var */
        cVar10 = (char)&_stack_var_minus4;
        local_a = puVar8;
        if (*(char *)0x54 == '\0') {
          if (unaff_DI == '<') {
            *(undefined2 *)(*(int *)0x70 + 4) = 0x20;
            uVar3 = func_0x0000fd4e();
            *(undefined2 *)0x70 = uVar3;
          }
          else {
            if ((cVar10 < 'a') || ('z' < cVar10)) {
              iVar5 = (int)cVar10;
            }
            else {
              iVar5 = cVar10 + -0x20;
            }
            *(int *)(*(int *)0x70 + 4) = iVar5;
            if (iVar5 != 0) {
              uVar3 = func_0x0000fd4e();
              *(undefined2 *)0x70 = uVar3;
            }
          }
        }
        else if (cVar10 == '\r') {
          puVar6 = (undefined2 *)*(undefined2 *)0x70;
          *puVar6 = 4;
          puVar6[1] = 0;
          *(undefined2 *)(*(int *)0x70 + 4) = 1;
          uVar3 = func_0x0000fd4e();
          *(undefined2 *)0x70 = uVar3;
        }
        else if (cVar10 == '\x1b') {
          puVar6 = (undefined2 *)*(undefined2 *)0x70;
          *puVar6 = 4;
          puVar6[1] = 0;
          *(undefined2 *)(*(int *)0x70 + 4) = 3;
          puVar4 = (undefined2 *)func_0x0000fd4e();
          *(undefined2 *)0x70 = puVar4;
          puVar6 = (undefined2 *)0x72;
          for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
            puVar2 = puVar4;
            puVar4 = puVar4 + 1;
            puVar1 = puVar6;
            puVar6 = puVar6 + 1;
            *puVar2 = *puVar1;
          }
          local_a = (undefined1 *)0xfbf;
          puVar6 = (undefined2 *)func_0x0000fd4e();
          *(undefined2 *)0x70 = puVar6;
          *puVar6 = 4;
          puVar6[1] = 0;
          *(undefined2 *)(*(int *)0x70 + 4) = 2;
          local_a = (undefined1 *)0xfbf;
          uVar3 = func_0x0000fd4e();
          *(undefined2 *)0x70 = uVar3;
        }
      }
      else {
        local_a = (undefined1 *)0x251c;
        FUN_1000_1c77(0);
      }
    }
  }
  return;
}



/* ---- FUN_1000_2525 @ 1000:2525 ---- */

void FUN_1000_2525()

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  FUN_1000_ecaa();
  FUN_1000_ca56(0);
  if (*(char *)0x11aa == '\0') {
    iVar5 = 0;
    iVar4 = 0xf;
  }
  else {
    iVar5 = 0xf;
    iVar4 = 0x1f;
  }
  iVar8 = 0;
  uVar6 = 0;
  for (; iVar5 != iVar4; iVar5 = iVar5 + 1) {
    uVar3 = (undefined2)((ulong)*(undefined4 *)0x9848 >> 0x10);
    iVar4 = (int)*(undefined4 *)0x9848;
    uVar7 = *(uint *)(iVar5 * 4 + iVar4);
    uVar1 = *(int *)(iVar5 * 4 + iVar4 + 2) + iVar8 + (uint)CARRY2(uVar7,uVar6);
    if ((uVar1 != 0) && ((1 < uVar1 || (0x1170 < uVar7 + uVar6)))) {
      iVar5 = 0xc;
      FUN_1000_1296(0x4d3a,0xc,0);
      FUN_1000_07f3();
    }
    uVar3 = (undefined2)((ulong)*(undefined4 *)0x8de4 >> 0x10);
    iVar2 = (int)*(undefined4 *)0x8de4;
    iVar4 = *(int *)(iVar5 * 4 + iVar2);
    FUN_1000_cb5b(iVar4,*(undefined2 *)(iVar5 * 4 + iVar2 + 2));
    uVar3 = (undefined2)((ulong)*(undefined4 *)0x9848 >> 0x10);
    iVar5 = (int)*(undefined4 *)0x9848;
    uVar7 = *(uint *)(iVar4 * 4 + iVar5 + 2);
    iVar5 = *(int *)(iVar4 * 4 + iVar5);
    iVar4 = iVar8 * 0x1000 + 0x270c;
    FUN_1000_cb8f(uVar7);
    uVar3 = (undefined2)((ulong)*(undefined4 *)0x9848 >> 0x10);
    iVar2 = (int)*(undefined4 *)0x9848;
    uVar1 = *(uint *)(iVar5 * 4 + iVar2);
    uVar6 = uVar7 + uVar1;
    iVar8 = iVar8 + *(int *)(iVar5 * 4 + iVar2 + 2) + (uint)CARRY2(uVar7,uVar1);
  }
  return;
}



/* ---- FUN_1000_260c @ 1000:260c ---- */

void FUN_1000_260c(int param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 uVar4;
  uint uVar5;
  int iVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  uVar5 = (uint)*(byte *)0xb0a3;
  if (param_1 == 0x1c) {
    puVar7 = (undefined2 *)*(undefined2 *)0x70;
    *puVar7 = 4;
    puVar7[1] = 0;
    *(undefined2 *)(*(int *)0x70 + 4) = 1;
    puVar3 = (undefined2 *)func_0x0000fd4e(0x1000,*(undefined2 *)0x70);
    *(undefined2 *)0x70 = puVar3;
    puVar7 = (undefined2 *)0x72;
    puVar8 = puVar3;
    for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
      puVar2 = puVar8;
      puVar8 = puVar8 + 1;
      puVar1 = puVar7;
      puVar7 = puVar7 + 1;
      *puVar2 = *puVar1;
    }
    uVar4 = func_0x0000fd4e(0xfbf,puVar3);
    *(undefined2 *)0x70 = uVar4;
    FUN_1000_1d51(0);
  }
  else {
    if (param_1 == 0x4b) {
      uVar5 = uVar5 - 1;
    }
    else if (param_1 == 0x4d) {
      uVar5 = uVar5 + 1;
    }
    if ((int)uVar5 < 0) {
      uVar5 = 3;
    }
    if (3 < (int)uVar5) {
      uVar5 = 0;
    }
    if (uVar5 != *(byte *)0xb0a3) {
      FUN_1000_5b18(0);
      FUN_1000_10d3(0x1000,(uint)*(byte *)0xb0a3 * 0x20 + 0x60,0x79,
                    (uint)*(byte *)0xb0a3 * 0x20 + 0x80,0x7b);
      FUN_1000_22c5(uVar5 * 0x20 + 0x61,100);
      *(undefined1 *)0xb0a3 = (char)uVar5;
    }
  }
  return;
}



/* ---- FUN_1000_26fe @ 1000:26fe ---- */

int FUN_1000_26fe()

{
  char *param_1 = 0; char *param_2 = 0;
  int iVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  while( true ) {
    iVar1 = FUN_1000_f1bc((int)*param_2);
    iVar2 = FUN_1000_f1bc((int)*param_1);
    if ((iVar2 != iVar1) || (*param_2 == '\0')) break;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return (int)*param_2;
}



/* ---- FUN_1000_2741 @ 1000:2741 ---- */

void FUN_1000_2741()

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined2 unaff_DS;
  undefined1 local_3a [2];
  char local_38 [38];
  undefined2 uStack_12;
  undefined2 local_10;
  undefined2 uStack_e;
  undefined1 *puStack_c;
  undefined2 *local_a;
  undefined2 **local_8;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  FUN_1000_ecaa();
  *(undefined1 *)0x5c6 = *(undefined1 *)0x8d22;
  *(undefined1 *)0x5c7 = *(undefined1 *)0x8dde;
  *(int *)0x5c8 = (int)local_38;
  local_8 = (undefined2 **)*(undefined2 *)0x8dde;
  local_a = (undefined2 *)0xc7;
  puStack_c = (undefined1 *)0x13f;
  uStack_e = 0;
  local_10 = 0;
  uStack_12 = 0x2771;
  FUN_1000_1780(0,0,0,0,0);
  pcVar7 = (char *)0x1f090000;
  while( true ) {
    pcVar5 = (char *)pcVar7;
    iVar4 = (int)((ulong)pcVar7 >> 0x10);
    if (*pcVar7 == '\0') break;
    if (pcVar5 == (char *)0xffff) {
      iVar4 = iVar4 + 0x1000;
    }
    pcVar6 = (char *)CONCAT22(iVar4,pcVar5 + 1);
    local_a = (undefined2 *)((int)*pcVar7 << 3);
    if (pcVar5 + 1 == (char *)0xffff) {
      iVar4 = iVar4 + 0x1000;
    }
    cVar1 = *pcVar6;
    local_8 = (undefined2 **)local_38;
    pcVar6 = (char *)CONCAT22(iVar4,pcVar5 + 2);
    do {
      iVar4 = (int)((ulong)pcVar6 >> 0x10);
      if ((char *)pcVar6 == (char *)0xffff) {
        iVar4 = iVar4 + 0x1000;
      }
      pcVar7 = (char *)CONCAT22(iVar4,(char *)pcVar6 + 1);
      cVar2 = *pcVar6;
      *(char *)local_8 = cVar2;
      local_8 = (undefined2 **)((int)local_8 + 1);
      pcVar6 = pcVar7;
    } while (cVar2 != '\0');
    puStack_c = (undefined1 *)0x5c6;
    uStack_e = 0x27e4;
    local_8 = (undefined2 **)((int)cVar1 << 3);
    FUN_1000_e915();
  }
  do {
    local_8 = &local_a;
    local_a = &local_10;
    puStack_c = local_3a;
    uStack_e = 0x27f8;
    iVar3 = FUN_1000_ea32();
  } while (iVar3 == 0);
  local_8 = (undefined2 **)*(undefined2 *)0x8dde;
  local_a = (undefined2 *)0xc7;
  puStack_c = (undefined1 *)0x13f;
  uStack_e = 0;
  local_10 = 0;
  uStack_12 = 0x2814;
  FUN_1000_1780(0,0,0,0,0);
  pcVar7 = (char *)CONCAT22(iVar4 + (-(uint)((char *)0xfffe < pcVar5) & 0x1000),pcVar5 + 1);
  while (*pcVar7 != '\0') {
    pcVar5 = (char *)pcVar7;
    iVar4 = (int)((ulong)pcVar7 >> 0x10);
    if (pcVar5 == (char *)0xffff) {
      iVar4 = iVar4 + 0x1000;
    }
    pcVar6 = (char *)CONCAT22(iVar4,pcVar5 + 1);
    local_a = (undefined2 *)((int)*pcVar7 << 3);
    if (pcVar5 + 1 == (char *)0xffff) {
      iVar4 = iVar4 + 0x1000;
    }
    cVar1 = *pcVar6;
    local_8 = (undefined2 **)local_38;
    pcVar6 = (char *)CONCAT22(iVar4,pcVar5 + 2);
    do {
      iVar4 = (int)((ulong)pcVar6 >> 0x10);
      if ((char *)pcVar6 == (char *)0xffff) {
        iVar4 = iVar4 + 0x1000;
      }
      pcVar7 = (char *)CONCAT22(iVar4,(char *)pcVar6 + 1);
      cVar2 = *pcVar6;
      *(char *)local_8 = cVar2;
      local_8 = (undefined2 **)((int)local_8 + 1);
      pcVar6 = pcVar7;
    } while (cVar2 != '\0');
    puStack_c = (undefined1 *)0x5c6;
    uStack_e = 0x2887;
    local_8 = (undefined2 **)((int)cVar1 << 3);
    FUN_1000_e915();
  }
  do {
    local_8 = &local_a;
    local_a = &local_10;
    puStack_c = local_3a;
    uStack_e = 0x289b;
    iVar4 = FUN_1000_ea32();
  } while (iVar4 == 0);
  local_8 = (undefined2 **)0x28a7;
  FUN_1000_3e4f();
  return;
}



/* ---- FUN_1000_28ae @ 1000:28ae ---- */

void FUN_1000_28ae()

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  undefined2 unaff_DS;
  undefined2 local_6;
  
  *(undefined2 *)0x9238 = 0xcc6c;
  *(undefined2 *)0x923a = 0x120d;
  iVar4 = 0;
  do {
    uVar6 = *(undefined2 *)0x923a;
    *(undefined2 *)(iVar4 * 4 + -0x6cb2) = *(undefined2 *)0x9238;
    *(undefined2 *)(iVar4 * 4 + -0x6cb0) = uVar6;
    uVar3 = (uint)*(byte *)(iVar4 + 0x5d2) * 4 + 0xc;
    puVar1 = (uint *)0x9238;
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + uVar3;
    *(int *)0x923a = *(int *)0x923a + (uint)CARRY2(uVar2,uVar3) * 0x1000;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 4);
  local_6 = 0;
  iVar4 = 0;
  do {
    iVar5 = iVar4 * 8;
    *(int *)(iVar4 * 2 + -0x72e6) = iVar5 + -0x67a6;
    *(int *)(iVar5 + -0x67a2) = local_6;
    *(undefined2 *)(iVar5 + -0x67a0) = 0x120d;
    local_6 = local_6 + 0xcb8;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 4);
  local_6 = -0x57ac;
  iVar4 = 0;
  do {
    *(int *)(iVar4 * 2 + -0x4f42) = local_6;
    local_6 = local_6 + 0x18;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 4);
  *(undefined2 *)0xb07e = 0x8478;
  *(undefined2 *)0x936c = 0x9892;
  FUN_1000_ca56(0);
  uVar6 = (undefined2)((ulong)*(undefined4 *)0x9240 >> 0x10);
  iVar4 = (int)*(undefined4 *)0x9240;
  FUN_1000_cb5b(*(undefined2 *)(iVar4 + 8),*(undefined2 *)(iVar4 + 10));
  FUN_1000_cb8f(0x9650);
  FUN_1000_e03a();
  *(undefined2 *)0x9238 = 0;
  *(undefined2 *)0x923a = 0x3823;
  FUN_1000_2d13(0x9650);
  FUN_1000_2c46();
  return;
}



/* ---- FUN_1000_29b9 @ 1000:29b9 ---- */

void FUN_1000_29b9()

{
  undefined2 unaff_DS;
  
  *(undefined2 *)0x9240 = 0x2cee;
  *(undefined2 *)0x9242 = 0x5cc2;
  *(undefined2 *)0x8de4 = 0x2d0e;
  *(undefined2 *)0x8de6 = 0x5cc2;
  *(undefined2 *)0x9648 = 0x2d8a;
  *(undefined2 *)0x964a = 0x5cc2;
  *(undefined2 *)0x817c = 0x2dbe;
  *(undefined2 *)0x817e = 0x5cc2;
  *(undefined2 *)0x987a = 0x2b2e;
  *(undefined2 *)0x987c = 0x5cc2;
  *(undefined2 *)0x9848 = 0x2b4e;
  *(undefined2 *)0x984a = 0x5cc2;
  *(undefined2 *)0xa8b6 = 0x2bca;
  *(undefined2 *)0xa8b8 = 0x5cc2;
  *(undefined2 *)0x8d00 = 0x2bfe;
  *(undefined2 *)0x8d02 = 0x5cc2;
  return;
}



/* ---- FUN_1000_2a1a @ 1000:2a1a ---- */

void FUN_1000_2a1a()

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  FUN_1000_543a(*(undefined2 *)0xefc,0);
  FUN_1000_543a(*(undefined2 *)0xefa,0);
  *(undefined2 *)0xefc = 0xff;
  *(undefined2 *)0xefa = 0xff;
  FUN_1000_3f7f();
  FUN_1000_2c79();
  for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
    *(undefined1 *)(iVar3 + 0xec0) = 0;
  }
  for (iVar3 = 0; iVar3 < 8; iVar3 = iVar3 + 1) {
    *(undefined1 *)(iVar3 + 0xec6) = 0xff;
  }
  if (*(int *)0xef6 == 0) {
    FUN_1000_ca56(0);
    puVar1 = (undefined2 *)*(undefined4 *)0x9240;
    FUN_1000_cb5b(*puVar1,((undefined2 *)puVar1)[1]);
    FUN_1000_cb8f(0x9650);
    FUN_1000_e03a();
    FUN_1000_2d13(0x9650);
    *(undefined2 *)0xb0c8 = 0x3ce;
    *(undefined2 *)0xb0c6 = 0x34e;
    *(undefined2 *)0x8d0c = 0x1e6;
    *(undefined2 *)0x8d06 = 0x1f8;
    *(undefined2 *)0x9890 = 0x166;
    FUN_1000_2b81(0);
    FUN_1000_3652(10);
    FUN_1000_3652(9);
  }
  else {
    FUN_1000_ca56(0);
    if (*(char *)0x11ab == '\0') {
      iVar3 = 3;
    }
    else {
      iVar3 = 2;
    }
    puVar2 = (undefined2 *)(iVar3 * 8 + *(int *)0x9240);
    FUN_1000_cb5b(*puVar2,puVar2[1]);
    FUN_1000_cb8f(0x9650);
    FUN_1000_e03a();
    FUN_1000_2d13(0x9650);
    *(undefined2 *)0xb0c8 = 0x45e;
    *(undefined2 *)0xb0c6 = 0x3de;
    *(undefined2 *)0x8d0c = 0x29a;
    *(undefined2 *)0x8d06 = 0x2ac;
    *(undefined2 *)0x9890 = 0x1a6;
    FUN_1000_2b81(1);
  }
  return;
}



/* ---- FUN_1000_2b81 @ 1000:2b81 ---- */

void FUN_1000_2b81(int param_1)

{
  byte *pbVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  bool bVar4;
  int local_e;
  int local_c;
  byte *local_a;
  byte *local_6;
  
  FUN_1000_ca56(0);
  if ((param_1 == 0) && (*(char *)0x11ab == '\0')) {
    param_1 = 7;
  }
  uVar3 = (undefined2)((ulong)*(undefined4 *)0x9648 >> 0x10);
  iVar2 = (int)*(undefined4 *)0x9648;
  FUN_1000_cb5b(*(undefined2 *)(param_1 * 4 + iVar2),*(undefined2 *)(param_1 * 4 + iVar2 + 2));
  FUN_1000_e03a();
  FUN_1000_e197(*(undefined2 *)0x5ce,*(undefined2 *)0x5d0,32000,0);
  pbVar1 = (byte *)*(uint *)0x5ce;
  local_6 = (byte *)(unsigned short)CONCAT22(*(int *)0x5d0,pbVar1);
  local_a = (byte *)(unsigned short)CONCAT22((uint)((byte *)0xff5f < pbVar1) * 0x1000 + *(int *)0x5d0,pbVar1 + 0xa0)
  ;
  local_e = 0x7c60;
  local_c = 0;
  while (local_e != 0 || local_c != 0) {
    *local_a = *local_a ^ *local_6;
    bVar4 = local_e == 0;
    local_e = local_e + -1;
    local_c = local_c - (uint)bVar4;
    if ((byte *)local_6 == (byte *)0xffff) {
      /* segment update: local_6 hi = GH_HI16(local_6) + 0x1000 */ (void)0;
    }
    local_6 = (byte *)(unsigned short)CONCAT22(GH_HI16(local_6),(byte *)local_6 + 1);
    local_a = (byte *)(unsigned short)CONCAT22(GH_HI16(local_a) + (-(uint)((byte *)0xfffe < (byte *)local_a) & 0x1000),
                               (byte *)local_a + 1);
  }
  FUN_1000_3e4f();
  return;
}



/* ---- FUN_1000_2c46 @ 1000:2c46 ---- */

void FUN_1000_2c46()

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  *(undefined2 *)0x933e = *(undefined2 *)0x936c;
  *(undefined2 *)0xa84e = *(undefined2 *)0xb07e;
  *(undefined2 *)0x8180 = *(undefined2 *)0x96;
  *(undefined2 *)0x8186 = *(undefined2 *)0x94;
  *(undefined2 *)0x936e = *(undefined2 *)0x98;
  *(undefined2 *)0x987e = *(undefined2 *)0x92;
  uVar1 = *(undefined2 *)0x923a;
  *(undefined2 *)0x9368 = *(undefined2 *)0x9238;
  *(undefined2 *)0x936a = uVar1;
  return;
}



/* ---- FUN_1000_2c79 @ 1000:2c79 ---- */

void FUN_1000_2c79()

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  *(undefined2 *)0x936c = *(undefined2 *)0x933e;
  *(undefined2 *)0xb07e = *(undefined2 *)0xa84e;
  *(undefined2 *)0x96 = *(undefined2 *)0x8180;
  *(undefined2 *)0x94 = *(undefined2 *)0x8186;
  *(undefined2 *)0x98 = *(undefined2 *)0x936e;
  *(undefined2 *)0x92 = *(undefined2 *)0x987e;
  uVar1 = *(undefined2 *)0x936a;
  *(undefined2 *)0x9238 = *(undefined2 *)0x9368;
  *(undefined2 *)0x923a = uVar1;
  return;
}



/* ---- FUN_1000_2cac @ 1000:2cac ---- */

void FUN_1000_2cac()

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  *(undefined2 *)0xb0ca = *(undefined2 *)0x936c;
  *(undefined2 *)0xb080 = *(undefined2 *)0xb07e;
  *(undefined2 *)0x95fe = *(undefined2 *)0x96;
  *(undefined2 *)0x8e22 = *(undefined2 *)0x94;
  *(undefined2 *)0xa834 = *(undefined2 *)0x98;
  *(undefined2 *)0x964e = *(undefined2 *)0x92;
  uVar1 = *(undefined2 *)0x923a;
  *(undefined2 *)0x9344 = *(undefined2 *)0x9238;
  *(undefined2 *)0x9346 = uVar1;
  return;
}



/* ---- FUN_1000_2ce0 @ 1000:2ce0 ---- */

void FUN_1000_2ce0()

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  *(undefined2 *)0x936c = *(undefined2 *)0xb0ca;
  *(undefined2 *)0xb07e = *(undefined2 *)0xb080;
  *(undefined2 *)0x96 = *(undefined2 *)0x95fe;
  *(undefined2 *)0x94 = *(undefined2 *)0x8e22;
  *(undefined2 *)0x98 = *(undefined2 *)0xa834;
  *(undefined2 *)0x92 = *(undefined2 *)0x964e;
  uVar1 = *(undefined2 *)0x9346;
  *(undefined2 *)0x9238 = *(undefined2 *)0x9344;
  *(undefined2 *)0x923a = uVar1;
  return;
}



/* ---- FUN_1000_2d13 @ 1000:2d13 ---- */

void FUN_1000_2d13()

{
  int *param_1 = 0;
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  int *local_16;
  byte *local_e;
  byte *local_a;
  
  local_a = (byte *)(unsigned short)CONCAT22(*(undefined2 *)0x923a,(byte *)*(undefined2 *)0x9238);
  iVar2 = *(int *)0x96;
  local_16 = (int *)(*(int *)0x96 * 8 + -0x7e72);
  while (*param_1 != 0 || param_1[1] != 0) {
    iVar3 = param_1[1];
    *local_16 = *param_1;
    local_16[1] = iVar3;
    local_16[2] = (int)(byte *)local_a;
    local_16[3] = GH_HI16(local_a);
    uVar1 = *(byte *)(iVar2 * 8 + -0x7e72) + 1 >> 1;
    FUN_1000_e282((byte *)local_a,GH_HI16(local_a),*(byte *)(iVar2 * 8 + -0x7e71) * uVar1,0,uVar1);
    uVar1 = *(byte *)(iVar2 * 8 + -0x7e72) + 3 >> 1 & 0xfe;
    local_e = (byte *)(unsigned short)CONCAT22((uint)CARRY2(uVar1,(uint)(byte *)local_a) * 0x1000 + GH_HI16(local_a),
                               (byte *)local_a + uVar1);
    for (iVar3 = (*(byte *)(iVar2 * 8 + -0x7e71) - 1) * uVar1; iVar3 != 0; iVar3 = iVar3 + -1) {
      *local_e = *local_e ^ *local_a;
      local_e = (byte *)(unsigned short)CONCAT22(GH_HI16(local_e) +
                                 (-(uint)((byte *)0xfffe < (byte *)local_e) & 0x1000),
                                 (byte *)local_e + 1);
      local_a = (byte *)(unsigned short)CONCAT22(GH_HI16(local_a) +
                                 (-(uint)((byte *)0xfffe < (byte *)local_a) & 0x1000),
                                 (byte *)local_a + 1);
    }
    local_a = local_e;
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 2;
    local_16 = local_16 + 4;
  }
  *(undefined2 *)0x9238 = (byte *)local_a;
  *(int *)0x923a = GH_HI16(local_a);
  *(int *)0x96 = iVar2;
  return;
}



/* ---- FUN_1000_2e34 @ 1000:2e34 ---- */

void FUN_1000_2e34(byte *param_1,int param_2,int param_3)

{
  byte *_local_8 = 0;
  byte *_local_e = 0;
  byte *pbVar1;
  byte bVar2;
  int *piVar3;
  bool bVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  undefined2 *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  char cVar12;
  uint uVar13;
  int iVar14;
  int unaff_DS;
  long lVar15;
  undefined4 uVar16;
  uint local_1e;
  int *local_14;
  byte *local_e;
  byte *local_a;
  byte *local_8;
  
  puVar8 = (undefined2 *)((param_3 + -3) * 8 + *(int *)0x817c);
  FUN_1000_cb5b(*puVar8,puVar8[1]);
  FUN_1000_cb8f(0xaa9c);
  for (iVar10 = 0; iVar10 < 0x100; iVar10 = iVar10 + 1) {
    *(undefined1 *)(iVar10 + -0x765c) = 0;
  }
  for (local_14 = (int *)0xaa9c; (*local_14 != 0 || (local_14[1] != 0)); local_14 = local_14 + 3) {
  }
  pbVar1 = (byte *)(local_14 + 3);
  *(int *)0xb078 = (int)pbVar1;
  _local_8 = (byte *)(unsigned short)CONCAT22(unaff_DS,pbVar1);
  pbVar6 = _local_8;
  iVar10 = unaff_DS;
  if (pbVar1 == (byte *)0xffff) {
    iVar10 = unaff_DS + 0x1000;
  }
  _local_8 = (byte *)(unsigned short)CONCAT22(iVar10,(byte *)((int)local_14 + 7));
  bVar2 = *pbVar6;
  for (uVar11 = 0; pbVar6 = _local_8, (int)uVar11 < (int)(uint)bVar2; uVar11 = uVar11 + 1) {
    bVar4 = false;
    iVar14 = 0;
    _local_e = (byte *)(unsigned short)CONCAT22(unaff_DS,param_1);
    while (*_local_e != 0xff) {
      if (*_local_e == uVar11) {
        bVar4 = true;
        *(undefined1 *)(param_2 + iVar14) = *(undefined1 *)0x92;
      }
      iVar9 = (int)((ulong)_local_e >> 0x10);
      iVar14 = iVar14 + 1;
      _local_e = (byte *)(unsigned short)CONCAT22(iVar9 + (-(uint)((byte *)0xfffe < local_e) & 0x1000),local_e + 1);
    }
    *(undefined1 *)(param_2 + iVar14) = 0xff;
    iVar10 = (int)((ulong)_local_8 >> 0x10);
    if (local_8 == (byte *)0xffff) {
      iVar10 = iVar10 + 0x1000;
    }
    uVar13 = (uint)*pbVar6;
    pbVar1 = local_8 + 2;
    iVar10 = iVar10 + (-(uint)((byte *)0xfffe < local_8 + 1) & 0x1000);
    _local_8 = (byte *)(unsigned short)CONCAT22(iVar10,pbVar1);
    if (bVar4) {
      *(int *)0x92 = *(int *)0x92 + 1;
      for (; pbVar6 = _local_8, uVar13 != 0; uVar13 = uVar13 - 1) {
        iVar10 = (int)((ulong)_local_8 >> 0x10);
        if (local_8 == (byte *)0xffff) {
          iVar10 = iVar10 + 0x1000;
        }
        _local_8 = (byte *)(unsigned short)CONCAT22(iVar10,local_8 + 1);
        *(undefined1 *)(*pbVar6 + 0x89a4) = 1;
      }
    }
    else {
      _local_8 = (byte *)(unsigned short)CONCAT22(iVar10 + (uint)CARRY2((uint)pbVar1,uVar13) * 0x1000,
                                  pbVar1 + uVar13);
    }
  }
  cVar12 = '\0';
  for (iVar10 = 0; iVar10 < 0x100; iVar10 = iVar10 + 1) {
    if (*(char *)(iVar10 + -0x765c) == '\0') {
      *(undefined1 *)(iVar10 + -0x765c) = 0xff;
    }
    else {
      *(char *)(iVar10 + -0x765c) = cVar12;
      cVar12 = cVar12 + '\x01';
    }
  }
  pbVar1 = (byte *)*(int *)0xb078;
  _local_8 = (byte *)(unsigned short)CONCAT22(unaff_DS,pbVar1);
  pbVar6 = _local_8;
  local_14 = (int *)*(undefined2 *)0x936c;
  iVar10 = unaff_DS;
  if (pbVar1 == (byte *)0xffff) {
    iVar10 = unaff_DS + 0x1000;
  }
  _local_8 = (byte *)(unsigned short)CONCAT22(iVar10,pbVar1 + 1);
  bVar2 = *pbVar6;
  for (uVar11 = 0; pbVar6 = _local_8, (int)uVar11 < (int)(uint)bVar2; uVar11 = uVar11 + 1) {
    _local_e = (byte *)(unsigned short)CONCAT22(unaff_DS,param_1);
    while ((*_local_e != 0xff && (*_local_e != uVar11))) {
      iVar9 = (int)((ulong)_local_e >> 0x10);
      _local_e = (byte *)(unsigned short)CONCAT22(iVar9 + (-(uint)((byte *)0xfffe < local_e) & 0x1000),local_e + 1);
    }
    pbVar5 = local_8;
    pbVar1 = local_8 + 1;
    iVar10 = (int)((ulong)_local_8 >> 0x10);
    if (local_8 == (byte *)0xffff) {
      iVar10 = iVar10 + 0x1000;
    }
    _local_8 = (byte *)(unsigned short)CONCAT22(iVar10,pbVar1);
    pbVar7 = _local_8;
    uVar13 = (uint)*pbVar6;
    if (*_local_e == uVar11) {
      puVar8 = (undefined2 *)*(undefined2 *)0xb07e;
      *(int *)0xb07e = *(int *)0xb07e + 2;
      *puVar8 = local_14;
      if ((*_local_8 & 0x80) == 0) {
        if (pbVar1 == (byte *)0xffff) {
          iVar10 = iVar10 + 0x1000;
        }
        _local_8 = (byte *)(unsigned short)CONCAT22(iVar10,pbVar5 + 2);
        iVar14 = (uint)*pbVar7 + *(int *)0x96;
      }
      else {
        if (pbVar1 == (byte *)0xffff) {
          iVar10 = iVar10 + 0x1000;
        }
        _local_8 = (byte *)(unsigned short)CONCAT22(iVar10,pbVar5 + 2);
        iVar14 = (*pbVar7 & 0x7f) + 0x11;
      }
      *local_14 = iVar14;
      piVar3 = local_14;
      for (; pbVar6 = _local_8, local_14 = piVar3 + 1, uVar13 != 0; uVar13 = uVar13 - 1) {
        iVar10 = (int)((ulong)_local_8 >> 0x10);
        if (local_8 == (byte *)0xffff) {
          iVar10 = iVar10 + 0x1000;
        }
        _local_8 = (byte *)(unsigned short)CONCAT22(iVar10,local_8 + 1);
        *local_14 = (uint)*(byte *)(*pbVar6 + 0x89a4) + *(int *)0x98;
        piVar3 = local_14;
      }
      *local_14 = -1;
      local_14 = piVar3 + 2;
    }
    else {
      _local_8 = (byte *)(unsigned short)CONCAT22(iVar10 + (uint)CARRY2((uint)pbVar1,uVar13 + 1) * 0x1000,
                                  pbVar1 + uVar13 + 1);
    }
  }
  *(undefined2 *)0x936c = local_14;
  FUN_1000_e03a();
  bVar4 = false;
  local_1e = 0;
  local_14 = (int *)0xaa9c;
  uVar16 = CONCAT22(*(undefined2 *)0x923a,*(undefined2 *)0x9238);
  local_a = (byte *)(*(int *)0x98 * 8 + -0x43e2);
  iVar14 = 0;
  while( true ) {
    iVar10 = (int)((ulong)uVar16 >> 0x10);
    local_8 = (byte *)uVar16;
    if ((*local_14 == 0) && (local_14[1] == 0)) break;
    *(int *)local_a = *local_14;
    piVar3 = local_14 + 2;
    *(int *)(local_a + 2) = local_14[1];
    if (*(char *)(iVar14 + -0x765c) == -1) {
      if ((*local_a != 0) && (local_a[1] != 0)) {
        bVar4 = true;
      }
    }
    else {
      if ((*local_a != 0) && (local_a[1] != 0)) {
        if (bVar4) {
          lVar15 = FUN_1000_f36e();
          iVar9 = (param_3 + -3) * 8 + *(int *)0x817c;
          FUN_1000_cb5b(lVar15 + CONCAT22(*(undefined2 *)(iVar9 + 6),*(undefined2 *)(iVar9 + 4)) + 8
                       );
          FUN_1000_e394(local_1e & 7);
          bVar4 = false;
        }
        uVar11 = *local_a + 1 >> 1;
        uVar16 = FUN_1000_e282(uVar16,local_a[1] * uVar11,0,uVar11);
      }
      *(byte **)(local_a + 4) = local_8;
      *(int *)(local_a + 6) = iVar10;
      local_a = local_a + 8;
    }
    local_14 = local_14 + 3;
    local_1e = local_1e + *piVar3;
    iVar14 = iVar14 + 1;
  }
  *(int *)0x98 = (int)(local_a + 0x43e2) >> 3;
  *(undefined2 *)0x9238 = local_8;
  *(undefined2 *)0x923a = iVar10;
  return;
}



/* ---- FUN_1000_323a @ 1000:323a ---- */

void FUN_1000_323a(int param_1)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  undefined2 *puVar4;
  uint uVar5;
  undefined2 *puVar6;
  undefined2 uVar7;
  int iVar8;
  uint uVar9;
  undefined2 *puVar10;
  undefined2 *puVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  undefined2 unaff_DS;
  bool bVar17;
  bool bVar18;
  ulong uVar19;
  uint local_26;
  int local_24;
  int *local_22;
  uint local_20;
  int *local_1c;
  int *local_16;
  undefined4 local_14;
  int *local_c;
  undefined4 local_a;
  int local_6;
  int local_4;
  
  *(undefined1 *)(param_1 + 0xec0) = 0;
  iVar12 = param_1 * 0x14;
  puVar4 = (undefined2 *)*(uint *)(iVar12 + 0xda8);
  uVar5 = *(uint *)(iVar12 + 0xdaa);
  local_a = (undefined2 *)CONCAT22(uVar5,puVar4);
  puVar6 = (undefined2 *)*(undefined2 *)(iVar12 + 0xdac);
  uVar7 = *(undefined2 *)(iVar12 + 0xdae);
  local_14 = (undefined2 *)CONCAT22(uVar7,puVar6);
  uVar19 = FUN_1000_f1d6(puVar6,uVar7,puVar4,uVar5);
  bVar17 = (uVar19 & 0x10000) != 0;
  iVar15 = (int)((long)uVar19 >> 0x11);
  uVar9 = (uint)uVar19 >> 1;
  *(undefined2 *)(iVar12 + 0xdaa) = 0;
  *(undefined2 *)(iVar12 + 0xda8) = 0;
  *(undefined2 *)(iVar12 + 0xdae) = 0;
  *(undefined2 *)(iVar12 + 0xdac) = 0;
  bVar18 = false;
  for (local_20 = 0; (!bVar18 && (local_20 < 6)); local_20 = local_20 + 1) {
    iVar12 = local_20 * 0x14;
    if ((uVar5 <= *(uint *)(iVar12 + 0xdaa)) &&
       ((*(uint *)(iVar12 + 0xdaa) != uVar5 || (puVar4 < (undefined2 *)*(uint *)(iVar12 + 0xda8)))))
    {
      puVar1 = (uint *)(iVar12 + 0xda8);
      uVar3 = *puVar1;
      *puVar1 = *puVar1 + uVar9 * -2;
      *(int *)(iVar12 + 0xdaa) =
           *(int *)(iVar12 + 0xdaa) +
           ((uint)CARRY2(uVar3,uVar9 * -2) - ((iVar15 << 1 | (uint)bVar17) + (uint)(uVar9 != 0))) *
           0x1000;
      puVar1 = (uint *)(iVar12 + 0xdac);
      uVar3 = *puVar1;
      *puVar1 = *puVar1 + uVar9 * -2;
      *(int *)(iVar12 + 0xdae) =
           *(int *)(iVar12 + 0xdae) +
           ((uint)CARRY2(uVar3,uVar9 * -2) - ((iVar15 << 1 | (uint)bVar17) + (uint)(uVar9 != 0))) *
           0x1000;
    }
    bVar18 = 0xfffe < local_20;
  }
  uVar19 = FUN_1000_f1d6(*(undefined2 *)0x9238,*(undefined2 *)0x923a,puVar6,uVar7);
  local_26 = (uint)uVar19 >> 1 | (uint)((uVar19 & 0x10000) != 0) << 0xf;
  local_24 = (int)((long)uVar19 >> 0x11);
  while( true ) {
    puVar11 = local_a;
    puVar10 = local_14;
    bVar18 = local_26 == 0;
    if (local_24 == 0 && local_26 == 0) break;
    if ((undefined2 *)0xfffd < (undefined2 *)local_14) {
      /* segment update: local_14 hi = GH_HI16(local_14) + 0x1000 */ (void)0;
    }
    local_14 = (undefined2 *)CONCAT22(GH_HI16(local_14),(undefined2 *)local_14 + 1);
    if ((undefined2 *)0xfffd < (undefined2 *)local_a) {
      /* segment update: local_a hi = GH_HI16(local_a) + 0x1000 */ (void)0;
    }
    local_a = (undefined2 *)CONCAT22(GH_HI16(local_a),(undefined2 *)local_a + 1);
    *puVar11 = *puVar10;
    local_26 = local_26 - 1;
    local_24 = local_24 - (uint)bVar18;
  }
  *(undefined2 *)0x9238 = (undefined2 *)local_a;
  *(int *)0x923a = GH_HI16(local_a);
  iVar12 = param_1 * 0x14;
  local_c = (int *)*(uint *)(iVar12 + 0xdb0);
  local_16 = (int *)*(int *)(iVar12 + 0xdb2);
  iVar13 = (int)local_16 - (int)local_c >> 1;
  *(undefined2 *)(iVar12 + 0xdb0) = 0;
  *(undefined2 *)(iVar12 + 0xdb2) = 0;
  iVar14 = *(int *)(iVar12 + 0xdb8) - *(int *)(iVar12 + 0xdb6);
  local_1c = (int *)*(int *)(iVar12 + 0xdb4);
  iVar12 = *local_16 - (int)local_1c >> 1;
  bVar18 = false;
  for (local_20 = 0; (!bVar18 && (local_20 < 6)); local_20 = local_20 + 1) {
    iVar8 = local_20 * 0x14;
    if (local_c < (int *)*(uint *)(iVar8 + 0xdb0)) {
      *(int *)(iVar8 + 0xdb0) = *(int *)(iVar8 + 0xdb0) + iVar13 * -2;
      *(int *)(iVar8 + 0xdb2) = *(int *)(iVar8 + 0xdb2) + iVar13 * -2;
      *(int *)(iVar8 + 0xdb6) = *(int *)(iVar8 + 0xdb6) - iVar14;
      *(int *)(iVar8 + 0xdb8) = *(int *)(iVar8 + 0xdb8) - iVar14;
      *(int *)(iVar8 + 0xdb4) = *(int *)(iVar8 + 0xdb4) + iVar12 * -2;
    }
    bVar18 = 0xfffe < local_20;
  }
  *(int *)0x92 = *(int *)0x92 - iVar13;
  local_26 = *(int *)0xb07e - (int)local_16 >> 1;
  local_24 = *(int *)0xb07e - (int)local_16 >> 0xf;
  while( true ) {
    bVar18 = local_26 == 0;
    if (local_24 == 0 && local_26 == 0) break;
    local_22 = (int *)*local_16;
    iVar13 = *local_22;
    piVar16 = local_1c;
    while( true ) {
      local_1c = piVar16 + 1;
      local_22 = local_22 + 1;
      *piVar16 = iVar13;
      if (*local_22 == -1) break;
      iVar13 = *local_22 - iVar14;
      piVar16 = local_1c;
    }
    *local_1c = *local_22;
    *local_c = *local_16 + iVar12 * -2;
    local_26 = local_26 + -1;
    local_24 = local_24 - (uint)bVar18;
    local_1c = piVar16 + 2;
    local_16 = local_16 + 1;
    local_c = local_c + 1;
  }
  *(uint *)0xb07e = (uint)local_c;
  *(int *)0x936c = (int)local_1c;
  bVar18 = false;
  for (local_20 = *(uint *)(param_1 * 0x14 + 0xdb8); (!bVar18 && (local_20 < *(uint *)0x98));
      local_20 = local_20 + 1) {
    puVar1 = (uint *)(local_20 * 8 + -0x43de);
    uVar5 = *puVar1;
    *puVar1 = *puVar1 + uVar9 * -2;
    piVar2 = (int *)(local_20 * 8 + -0x43dc);
    *piVar2 = *piVar2 + ((uint)CARRY2(uVar5,uVar9 * -2) -
                        ((iVar15 << 1 | (uint)bVar17) + (uint)(uVar9 != 0))) * 0x1000;
    bVar18 = 0xfffe < local_20;
  }
  local_22 = (int *)(*(int *)(param_1 * 0x14 + 0xdb8) * 8 + -0x43e2);
  iVar12 = (*(int *)0x98 * 8 - (int)local_22) + -0x43e2;
  local_1c = (undefined2 *)(*(int *)(param_1 * 0x14 + 0xdb6) * 8 + -0x43e2);
  local_6 = iVar12 >> 1;
  local_4 = iVar12 >> 0xf;
  while( true ) {
    bVar18 = local_6 == 0;
    if (local_4 == 0 && local_6 == 0) break;
    *local_1c = *local_22;
    local_22 = local_22 + 1;
    local_1c = local_1c + 1;
    local_6 = local_6 + -1;
    local_4 = local_4 - (uint)bVar18;
  }
  *(int *)0x98 = *(int *)0x98 -
                 (*(int *)(param_1 * 0x14 + 0xdb8) - *(int *)(param_1 * 0x14 + 0xdb6));
  return;
}



/* ---- FUN_1000_35a0 @ 1000:35a0 ---- */

void FUN_1000_35a0(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  undefined2 unaff_DS;
  
  *(undefined1 *)(param_1 + 0xec0) = 1;
  iVar2 = param_1 * 0x14;
  *(undefined2 *)(iVar2 + 0xdb4) = *(undefined2 *)0x936c;
  *(undefined2 *)(iVar2 + 0xdb0) = *(undefined2 *)0xb07e;
  *(undefined2 *)(iVar2 + 0xdb6) = *(undefined2 *)0x98;
  uVar1 = *(undefined2 *)0x923a;
  *(undefined2 *)(iVar2 + 0xda8) = *(undefined2 *)0x9238;
  *(undefined2 *)(iVar2 + 0xdaa) = uVar1;
  FUN_1000_ca56(1);
  for (uVar3 = 0; uVar3 < *(byte *)(param_1 + 0xb8); uVar3 = uVar3 + 1) {
    *(undefined1 *)(uVar3 + 0x9650) = (char)uVar3;
  }
  *(undefined1 *)(uVar3 + 0x9650) = 0xff;
  FUN_1000_2e34(0x9650,uVar3 + 0x9652,param_1 + 3);
  param_1 = param_1 * 0x14;
  *(undefined2 *)(param_1 + 0xdb2) = *(undefined2 *)0xb07e;
  *(undefined2 *)(param_1 + 0xdb8) = *(undefined2 *)0x98;
  uVar1 = *(undefined2 *)0x923a;
  *(undefined2 *)(param_1 + 0xdac) = *(undefined2 *)0x9238;
  *(undefined2 *)(param_1 + 0xdae) = uVar1;
  return;
}



/* ---- FUN_1000_3652 @ 1000:3652 ---- */

void FUN_1000_3652(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  undefined2 unaff_DS;
  undefined4 uVar7;
  
  *(undefined1 *)(param_1 + 0xece) = 1;
  uVar6 = *(undefined2 *)0x923a;
  *(undefined2 *)(param_1 * 10 + 0xe20) = *(undefined2 *)0x9238;
  *(undefined2 *)(param_1 * 10 + 0xe22) = uVar6;
  uVar6 = (undefined2)((ulong)*(undefined4 *)0x8de4 >> 0x10);
  iVar5 = (int)*(undefined4 *)0x8de4;
  uVar2 = *(uint *)((uint)*(byte *)0x11aa * 0x3c + iVar5);
  iVar4 = ((uint)*(byte *)0x11aa * 0xf + param_1) * 4;
  uVar3 = *(uint *)(iVar4 + iVar5);
  FUN_1000_e449(uVar3 - uVar2,
                ((*(int *)(iVar4 + iVar5 + 2) - *(int *)((uint)*(byte *)0x11aa * 0x3c + iVar5 + 2))
                - (uint)(uVar3 < uVar2)) * 0x1000 + 0x270c);
  FUN_1000_e03a();
  uVar7 = FUN_1000_e197(*(undefined2 *)0x9238,*(undefined2 *)0x923a,11000,0);
  uVar3 = (uint)uVar7 + 1 & 0xfffe;
  puVar1 = (uint *)0x9238;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + uVar3;
  *(int *)0x923a =
       *(int *)0x923a +
       ((int)((ulong)uVar7 >> 0x10) + (uint)(0xfffe < (uint)uVar7) + (uint)CARRY2(uVar2,uVar3)) *
       0x1000;
  uVar6 = *(undefined2 *)0x923a;
  *(undefined2 *)(param_1 * 10 + 0xe24) = *(undefined2 *)0x9238;
  *(undefined2 *)(param_1 * 10 + 0xe26) = uVar6;
  FUN_1000_e45c();
  return;
}



/* ---- FUN_1000_3713 @ 1000:3713 ---- */

void FUN_1000_3713()

{
  uint uVar1;
  int iVar2;
  int unaff_DI;
  undefined2 unaff_DS;
  bool bVar3;
  undefined4 uVar4;
  int local_18;
  uint local_16;
  uint local_14;
  int local_10;
  uint local_e;
  uint local_c;
  uint local_a;
  int local_8;
  byte *local_6;
  
  uVar4 = FUN_1000_f1d6(*(undefined2 *)0x9238,*(undefined2 *)0x923a,0,0x3823);
  local_16 = *(uint *)0xb0b4 - (uint)uVar4;
  local_14 = (*(int *)0xb0b6 - (int)((ulong)uVar4 >> 0x10)) - (uint)(*(uint *)0xb0b4 < (uint)uVar4);
  local_a = 0;
  local_c = 0;
  iVar2 = 0;
  do {
    if ((*(char *)(iVar2 + 0xec6) != -1) && (*(char *)(iVar2 + 0xec0) == '\0')) {
      uVar1 = *(uint *)(iVar2 * 4 + 0xbe);
      bVar3 = CARRY2(local_c,uVar1);
      local_c = local_c + uVar1;
      local_a = local_a + *(int *)(iVar2 * 4 + 0xc0) + (uint)bVar3;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 6);
  if (*(char *)0xecc != -1) {
    local_8 = *(byte *)0xecc - 1;
    unaff_DI = *(byte *)0xecd - 1;
    *(undefined2 *)0xb0ce = *(undefined2 *)(local_8 * 0xc + unaff_DI * 2 + -0x7392);
    *(undefined2 *)0xb0d0 = *(undefined2 *)(local_8 * 2 + unaff_DI * 0xc + -0x734a);
    iVar2 = local_8 * 0x18 + unaff_DI * 4;
    uVar1 = *(uint *)(iVar2 + 0xd6);
    bVar3 = CARRY2(local_c,uVar1);
    local_c = local_c + uVar1;
    local_a = local_a + *(int *)(iVar2 + 0xd8) + (uint)bVar3;
    for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
      *(undefined1 *)(iVar2 + 0xede) = 0;
    }
    for (local_6 = (byte *)*(undefined2 *)(local_8 * 0xc + unaff_DI * 2 + -0x7392); *local_6 != 0xff
        ; local_6 = local_6 + 1) {
      if ((*local_6 & 0x80) != 0) {
        *(undefined1 *)((*local_6 & 0xf) + 0xede) = 1;
        local_6 = local_6 + 1;
      }
    }
    for (local_6 = (byte *)*(undefined2 *)(local_8 * 2 + unaff_DI * 0xc + -0x734a); *local_6 != 0xff
        ; local_6 = local_6 + 1) {
      if ((*local_6 & 0x80) != 0) {
        *(undefined1 *)((*local_6 & 0xf) + 0xede) = 1;
        local_6 = local_6 + 1;
      }
    }
  }
  local_e = 0;
  while ((local_14 <= local_a && ((local_14 < local_a || (local_16 < local_c))))) {
    local_18 = 0x7fff;
    iVar2 = 0;
    do {
      if ((*(char *)(iVar2 + 0xec6) == -1) && (*(char *)(iVar2 + 0xec0) != '\0')) {
        local_18 = *(int *)(iVar2 * 0x14 + 0xdba);
        local_10 = iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 6);
    if (local_18 == 0x7fff) {
      if ((*(char *)0xecc == -1) || (*(int *)0xef8 != 0)) {
        FUN_1000_0d8d(0x4d48);
      }
      else {
        iVar2 = (uint)*(byte *)0xecd * 4 + (uint)*(byte *)0xecc * 0x18;
        uVar1 = *(uint *)(iVar2 + 0xba);
        bVar3 = local_c < uVar1;
        local_c = local_c - uVar1;
        local_a = (local_a - *(int *)(iVar2 + 0xbc)) - (uint)bVar3;
        local_e = (uint)*(byte *)0xecc;
      }
    }
    else {
      FUN_1000_323a(local_10);
    }
    uVar4 = FUN_1000_f1d6(*(undefined2 *)0x9238,*(undefined2 *)0x923a,0,0x3823);
    local_14 = (*(int *)0xb0b6 - (int)((ulong)uVar4 >> 0x10)) -
               (uint)(*(uint *)0xb0b4 < (uint)uVar4);
    local_16 = *(uint *)0xb0b4 - (uint)uVar4;
  }
  iVar2 = 0;
  do {
    if ((*(char *)(iVar2 + 0xec6) != -1) && (*(char *)(iVar2 + 0xec0) == '\0')) {
      FUN_1000_35a0(iVar2);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 6);
  *(uint *)0xef8 = local_e;
  if ((*(char *)0xecc != -1) && (local_e == 0)) {
    FUN_1000_2cac();
    FUN_1000_2e34(*(undefined2 *)(local_8 * 0xc + unaff_DI * 2 + -0x70ba),0x103e,local_8 * 2 + 9);
    iVar2 = local_8 * 0x10 + *(int *)0x817c;
    FUN_1000_cb5b(*(undefined2 *)(iVar2 + 0x38),*(undefined2 *)(iVar2 + 0x3a));
    FUN_1000_cb8f(0x9650);
    FUN_1000_e03a();
    FUN_1000_2d13(0x9650);
    FUN_1000_2e34(*(undefined2 *)(local_8 * 2 + unaff_DI * 0xc + -0x7072),0x1052,unaff_DI * 2 + 0x15
                 );
    iVar2 = unaff_DI * 0x10 + *(int *)0x817c;
    FUN_1000_cb5b(*(undefined2 *)(iVar2 + 0x98),*(undefined2 *)(iVar2 + 0x9a));
    FUN_1000_cb8f(0x9650);
    FUN_1000_e03a();
    FUN_1000_2d13(0x9650);
    for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {
      *(undefined1 *)(iVar2 + 0xece) = 0;
    }
    *(undefined1 *)0xed8 = 1;
    *(undefined1 *)0xed7 = 1;
    iVar2 = 0;
    do {
      if ((*(char *)(iVar2 + 0xede) != '\0') && (*(char *)(iVar2 + 0xece) == '\0')) {
        FUN_1000_3652(iVar2);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x10);
  }
  FUN_1000_f1d6(*(undefined2 *)0x9238,*(undefined2 *)0x923a,0,0x3823);
  return;
}



/* ---- FUN_1000_3a99 @ 1000:3a99 ---- */

void FUN_1000_3a99(undefined2 param_1)

{
  undefined2 unaff_DS;
  
  if (*(int *)0x8e != 0) {
    *(int *)0x8e = *(int *)0x8e + -1;
    *(undefined2 *)(*(int *)0x8e * 2 + -0x72e6) = param_1;
    return;
  }
  FUN_1000_0d8d(0x4d61);
  return;
}



/* ---- FUN_1000_3ac2 @ 1000:3ac2 ---- */

undefined2 FUN_1000_3ac2()

{
  int iVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  
  if (*(int *)0x8e < 4) {
    iVar1 = *(int *)0x8e;
    *(int *)0x8e = *(int *)0x8e + 1;
    return *(undefined2 *)(iVar1 * 2 + -0x72e6);
  }
  uVar2 = FUN_1000_0d8d(0x4d6b);
  return uVar2;
}



/* ---- FUN_1000_3ae3 @ 1000:3ae3 ---- */

void FUN_1000_3ae3(undefined2 param_1)

{
  undefined2 unaff_DS;
  
  if (*(int *)0x90 != 0) {
    *(int *)0x90 = *(int *)0x90 + -1;
    *(undefined2 *)(*(int *)0x90 * 2 + -0x4f42) = param_1;
    return;
  }
  FUN_1000_0d8d(0x4d75);
  return;
}



/* ---- FUN_1000_3b0c @ 1000:3b0c ---- */

undefined2 FUN_1000_3b0c()

{
  int iVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  
  if (*(int *)0x90 < 4) {
    iVar1 = *(int *)0x90;
    *(int *)0x90 = *(int *)0x90 + 1;
    return *(undefined2 *)(iVar1 * 2 + -0x4f42);
  }
  uVar2 = FUN_1000_0d8d(0x4d7f);
  return uVar2;
}



/* ---- FUN_1000_3b2e @ 1000:3b2e ---- */

void FUN_1000_3b2e()

{
  FUN_1000_ecaa();
  return;
}



/* ---- FUN_1000_3b3a @ 1000:3b3a ---- */

void FUN_1000_3b3a(byte *param_1,int param_2, ...)

{
  byte *param_3 = 0;
  byte bVar1;
  uint uVar2;
  int iVar4;
  undefined2 uVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined2 unaff_DS;
  undefined2 local_12;
  byte *pbVar11;
  uint uVar3;
  
  FUN_1000_ecaa();
  param_2 = param_2 * 8;
  bVar1 = *(byte *)(param_2 + -0x43e2);
  if ((bVar1 == 0) || (*(char *)(param_2 + -0x43e1) == '\0')) {
    *param_3 = *param_1;
    param_3[1] = param_1[1];
    param_3[2] = param_1[2];
    param_3[3] = param_1[3];
  }
  else {
    if (*(char *)(param_2 + -0x43e0) < (char)param_1[2]) {
      uVar10 = ((int)(char)param_1[2] - (int)*(char *)(param_2 + -0x43e0)) + (uint)bVar1;
      cVar6 = (char)uVar10;
      *param_3 = (*param_1 - cVar6 & ~-(*param_1 < uVar10)) + cVar6;
      param_3[2] = param_1[2];
    }
    else {
      uVar10 = ((int)*(char *)(param_2 + -0x43e0) - (int)(char)param_1[2]) + (uint)*param_1;
      bVar1 = *(byte *)(param_2 + -0x43e2);
      cVar6 = (char)uVar10;
      *param_3 = (bVar1 - cVar6 & ~-(bVar1 < uVar10)) + cVar6;
      param_3[2] = *(byte *)(param_2 + -0x43e0);
    }
    if (*(char *)(param_2 + -0x43df) < (char)param_1[3]) {
      uVar10 = ((int)(char)param_1[3] - (int)*(char *)(param_2 + -0x43df)) +
               (uint)*(byte *)(param_2 + -0x43e1);
      param_3[1] = (byte)((param_1[1] - uVar10 & ~-(uint)(param_1[1] < uVar10)) + uVar10);
      param_3[3] = param_1[3];
    }
    else {
      uVar10 = ((int)*(char *)(param_2 + -0x43df) - (int)(char)param_1[3]) + (uint)param_1[1];
      param_3[1] = (byte)((*(byte *)(param_2 + -0x43e1) - uVar10 &
                          ~-(uint)(*(byte *)(param_2 + -0x43e1) < uVar10)) + uVar10);
      param_3[3] = *(byte *)(param_2 + -0x43df);
    }
  }
  pbVar11 = *(byte **)(param_3 + 4);
  FUN_1000_5a4f(pbVar11,*(undefined2 *)(param_3 + 6),(*param_3 + 3 >> 1) * (uint)param_3[1],0);
  uVar7 = (int)(char)param_3[2] - (int)(char)param_1[2];
  uVar10 = (*param_3 + 3 >> 1 & 0xfe) * ((int)(char)param_3[3] - (int)(char)param_1[3]) +
           (CONCAT11((char)((int)uVar7 >> 9),(char)((int)uVar7 >> 1)) & 0xfffe);
  uVar2 = *(uint *)(param_3 + 4);
  uVar3 = *(uint *)(param_3 + 4);
  iVar4 = *(int *)(param_3 + 6);
  *(uint *)0x492a = (uint)param_1[1];
  *(uint *)0x4928 = (*param_1 + 3 >> 1 & 0xfe) + 2 >> 1;
  *(uint *)0x4924 = uVar7 & 3;
  *(undefined2 *)0x4930 = 0xffff;
  *(undefined2 *)0x4932 = 0;
  *(undefined2 *)0x492c = 0xfffe;
  *(int *)0x492e = ((*param_3 + 3 >> 1 & 0xfe) - (*param_1 + 3 >> 1 & 0xfe)) + -2;
  uVar5 = *(undefined2 *)(param_1 + 6);
  *(undefined2 *)0x4938 = *(undefined2 *)(param_1 + 4);
  *(undefined2 *)0x493a = uVar5;
  *(int *)0x4934 = uVar10 + uVar3;
  *(int *)0x4936 = (((int)uVar10 >> 0xf) + (uint)CARRY2(uVar10,uVar2)) * 0x1000 + iVar4;
  *(undefined2 *)0x4926 = 0;
  FUN_1000_e57a();
  if ((*pbVar11 != 0) && (pbVar11[1] != 0)) {
    uVar7 = (int)(char)param_3[2] - (int)(char)pbVar11[2];
    uVar3 = (*param_3 + 3 >> 1 & 0xfe) * ((int)(char)param_3[3] - (int)(char)pbVar11[3]);
    uVar9 = CONCAT11((char)((int)uVar7 >> 9),(char)((int)uVar7 >> 1)) & 0xfffe;
    uVar8 = uVar3 + uVar9;
    uVar10 = *(uint *)(param_3 + 4);
    uVar2 = *(uint *)(param_3 + 4);
    iVar4 = *(int *)(param_3 + 6);
    *(uint *)0x492a = (uint)pbVar11[1];
    *(uint *)0x4928 = (*pbVar11 + 3 >> 1 & 0xfe) + 2 >> 1;
    *(uint *)0x4924 = uVar7 & 3;
    *(undefined2 *)0x4926 = 2;
    *(undefined2 *)0x4930 = 0xffff;
    *(undefined2 *)0x4932 = 0;
    *(undefined2 *)0x492c = 0xfffe;
    *(int *)0x492e = ((*param_3 + 3 >> 1 & 0xfe) - (*pbVar11 + 3 >> 1 & 0xfe)) + -2;
    uVar5 = *(undefined2 *)(pbVar11 + 6);
    *(undefined2 *)0x4938 = *(undefined2 *)(pbVar11 + 4);
    *(undefined2 *)0x493a = uVar5;
    *(int *)0x4934 = uVar8 + uVar2;
    *(int *)0x4936 = ((uint)CARRY2(uVar3,uVar9) + (uint)CARRY2(uVar8,uVar10)) * 0x1000 + iVar4;
    *(undefined2 *)0x4942 = local_12;
    FUN_1000_e57a();
  }
  return;
}



/* ---- FUN_1000_3e4f @ 1000:3e4f ---- */

void FUN_1000_3e4f()

{
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  FUN_1000_1f0e(0x1000);
  func_0x000110d0(0x11ef,0,0,0xa0,200,*(undefined2 *)0x5ce,*(undefined2 *)0x5d0);
  FUN_1000_1ef0(0x110d);
  return;
}



/* ---- FUN_1000_3e81 @ 1000:3e81 ---- */

void FUN_1000_3e81(int param_1)

{
  int *piVar1;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  piVar1 = (int *)0xda4;
  while (*piVar1 != 0) {
    if (*piVar1 == param_1) {
      *piVar1 = *(int *)(param_1 + 0x1a);
    }
    else {
      piVar1 = (int *)(*piVar1 + 0x1a);
    }
  }
  return;
}



/* ---- FUN_1000_3eb1 @ 1000:3eb1 ---- */

void FUN_1000_3eb1(int param_1,int param_2)

{
  undefined2 unaff_DS;
  int *piVar1;
  
  FUN_1000_ecaa();
  piVar1 = (int *)0xda4;
  while (*piVar1 != param_2) {
    if (*piVar1 == 0) {
      *(undefined2 *)(param_2 + 0x1a) = 0;
      *piVar1 = param_2;
    }
    else if (*(int *)(*piVar1 + 2) < param_1) {
      piVar1 = (int *)(*piVar1 + 0x1a);
    }
    else {
      *(int *)(param_2 + 0x1a) = *piVar1;
      *piVar1 = param_2;
    }
  }
  return;
}



/* ---- FUN_1000_3f0f @ 1000:3f0f ---- */

void FUN_1000_3f0f(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
             undefined2 param_5, ...)

{
  FUN_1000_ecaa();
  FUN_1000_3e81(param_5);
  FUN_1000_3eb1(param_2,param_5);
  FUN_1000_3f9e(param_1,param_2,param_3,param_4,param_5);
  return;
}



/* ---- FUN_1000_3f49 @ 1000:3f49 ---- */

void FUN_1000_3f49()

{
  undefined2 *param_1 = 0;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  FUN_1000_3e81(param_1);
  FUN_1000_3f9e(*param_1,param_1[1],*(undefined1 *)(param_1 + 5),param_1[10],param_1);
  param_1[10] = 0;
  *(undefined1 *)((int)param_1 + 0xb) = 0;
  return;
}



/* ---- FUN_1000_3f7f @ 1000:3f7f ---- */

void FUN_1000_3f7f()

{
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  while (*(int *)0xda4 != 0) {
    FUN_1000_3f49(*(undefined2 *)0xda4);
  }
  return;
}



/* ---- FUN_1000_3f9e @ 1000:3f9e ---- */

void FUN_1000_3f9e()

{
  int param_1 = 0; int param_2 = 0; int param_3 = 0; byte *param_4 = 0; int *param_5 = 0;
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  for (; 199 < param_2; param_2 = param_2 + -200) {
  }
  *(int *)0x922e = -((char)param_4[2] - param_1) >> 2;
  *(uint *)0x9364 = (((*param_4 + 3 & 0xfc) - (int)(char)param_4[2]) + param_1) - 1 >> 2;
  *(int *)0x9378 = -((char)param_4[3] - param_2);
  *(int *)0x8d08 = (param_2 - ((int)(char)param_4[3] - (uint)param_4[1])) + -1;
  param_5[6] = -((char)param_4[2] - param_1);
  param_5[7] = (*param_4 + 3 & 0xfc) + param_5[6] + -1;
  param_5[8] = *(int *)0x9378;
  param_5[9] = *(int *)0x8d08;
  pbVar1 = (byte *)param_5[10];
  if (pbVar1 == (byte *)0x0) {
    param_5[4] = 0;
  }
  else {
    if (param_5[4] != 0) {
      FUN_1000_3a99(param_5[10]);
    }
    iVar2 = *param_5 - (int)(char)pbVar1[2] >> 2;
    if (iVar2 < *(int *)0x922e) {
      *(int *)0x922e = iVar2;
    }
    uVar3 = (((*pbVar1 + 3 & 0xfc) - (int)(char)pbVar1[2]) + *param_5) - 1 >> 2;
    if (*(int *)0x9364 < (int)uVar3) {
      *(uint *)0x9364 = uVar3;
    }
    if (param_5[1] - (int)(char)pbVar1[3] < *(int *)0x9378) {
      *(int *)0x9378 = param_5[1] - (int)(char)pbVar1[3];
    }
    iVar2 = (param_5[1] - (int)(char)pbVar1[3]) + (uint)pbVar1[1] + -1;
    if (*(int *)0x8d08 < iVar2) {
      *(int *)0x8d08 = iVar2;
    }
  }
  if (*(int *)0x922e < 0) {
    *(undefined2 *)0x922e = 0;
  }
  if (0x4f < *(int *)0x9364) {
    *(undefined2 *)0x9364 = 0x4f;
  }
  if (*(int *)0x9378 < 0) {
    *(undefined2 *)0x9378 = 0;
  }
  if (199 < *(int *)0x8d08) {
    *(undefined2 *)0x8d08 = 199;
  }
  *param_5 = param_1;
  param_5[1] = param_2;
  param_5[2] = param_1;
  param_5[3] = param_2;
  *(char *)(param_5 + 5) = '\x01' - (param_3 == 0);
  param_5[10] = (int)param_4;
  if ((((-1 < *(int *)0x9364) && (*(int *)0x922e < 0x50)) && (*(int *)0x9378 < 200)) &&
     (-1 < *(int *)0x8d08)) {
    if (*(char *)((int)param_5 + 0xb) == -2) {
      FUN_1000_41a8(1);
      *(undefined2 *)0xa850 = param_5;
    }
    else {
      FUN_1000_41a8(0);
    }
    FUN_1000_42a0();
  }
  return;
}



/* ---- FUN_1000_41a8 @ 1000:41a8 ---- */

void FUN_1000_41a8(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  *(int *)0xb0ba = *(int *)0x922e << 2;
  iVar2 = *(int *)0x9364 * 4 + 3;
  *(int *)0x9644 = iVar2;
  *(int *)0xb0d8 = (iVar2 - *(int *)0xb0ba) + 1;
  *(int *)0x9372 = (*(int *)0x9364 - *(int *)0x922e) * 2 + 2;
  *(int *)0x8dd4 = (*(int *)0x8d08 - *(int *)0x9378) + 1;
  if (*(int *)0x9372 * *(int *)0x8dd4 < 0xcb1) {
    uVar3 = *(int *)0x9378 * 0xa0 + *(int *)0x922e * 2;
    uVar1 = *(uint *)0x5ce;
    iVar2 = (((int)uVar3 >> 0xf) + (uint)CARRY2(uVar3,*(uint *)0x5ce)) * 0x1000 + *(int *)0x5d0;
    *(undefined2 *)0x4930 = 0xffff;
    *(undefined2 *)0x4932 = 0xffff;
    *(int *)0x492c = 0xa0 - *(int *)0x9372;
    *(undefined2 *)0x492e = 0;
    *(int *)0x4938 = uVar3 + uVar1;
    *(int *)0x493a = iVar2;
    *(undefined2 *)0x4934 = 0x3f90;
    *(undefined2 *)0x4936 = 0x120d;
    *(undefined2 *)0x492a = *(undefined2 *)0x8dd4;
    *(int *)0x4928 = *(int *)0x9372 >> 1;
    *(undefined2 *)0x4924 = 0;
    *(undefined2 *)0x4926 = 0;
    if (param_1 == 0) {
      FUN_1000_e57a();
    }
    else {
      FUN_1000_5a4f(0x3f90,0x120d,*(int *)0x8dd4 * *(int *)0x9372,0,iVar2);
    }
  }
  else {
    FUN_1000_0d8d(0x4d8a);
  }
  return;
}



/* ---- FUN_1000_42a0 @ 1000:42a0 ---- */

void FUN_1000_42a0()

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined2 unaff_DS;
  int local_2e;
  undefined2 local_2a;
  uint local_26;
  int local_24;
  uint local_22;
  undefined2 local_20;
  int local_1a;
  
  FUN_1000_ecaa();
  for (iVar7 = *(int *)0xda4; iVar7 != 0; iVar7 = *(int *)(iVar7 + 0x1a)) {
    if ((((*(int *)(iVar7 + 0xc) <= *(int *)0x9644) && (*(int *)0xb0ba <= *(int *)(iVar7 + 0xe))) &&
        (*(int *)(iVar7 + 0x10) <= *(int *)0x8d08)) &&
       ((*(int *)0x9378 <= *(int *)(iVar7 + 0x12) &&
        ((*(int *)0xa850 == 0 || (*(int *)0xa850 == iVar7)))))) {
      if (*(char *)(iVar7 + 10) != '\0') {
        FUN_1000_4575(*(undefined2 *)(iVar7 + 0x14));
      }
      local_1a = *(int *)(iVar7 + 0xc) - *(int *)0xb0ba;
      if (local_1a < 0) {
        uVar2 = -local_1a;
        local_1a = 0;
        local_20 = *(undefined2 *)((uVar2 & 3) * 2 + 0x46e);
      }
      else {
        uVar2 = 0;
        local_20 = 0xffff;
      }
      uVar3 = *(int *)0x9644 - *(int *)(iVar7 + 0xe);
      if ((int)uVar3 < 0) {
        local_26 = -uVar3;
        local_2a = *(undefined2 *)((local_26 & 3) * 2 + 0x476);
      }
      else {
        local_26 = 0;
        if ((uVar3 & 3) == 0) {
          local_2a = 0xffff;
        }
        else {
          local_2a = 0;
        }
      }
      iVar4 = (((*(byte *)*(undefined2 *)(iVar7 + 0x14) + 3 & 0xfc) - local_26) - uVar2) + 3;
      uVar3 = CONCAT11((char)(iVar4 >> 9),(char)(iVar4 >> 1)) & 0xfffe;
      if ((*(byte *)(iVar7 + 0xc) & 3) != 0) {
        if (local_26 == 0) {
          uVar3 = uVar3 + 2;
        }
        else if (uVar2 != 0) {
          uVar3 = uVar3 + 2;
        }
      }
      iVar4 = *(int *)(iVar7 + 0x10) - *(int *)0x9378;
      if (iVar4 < 0) {
        local_2e = -iVar4;
        iVar4 = 0;
        if (*(int *)0x8d08 < *(int *)(iVar7 + 0x12)) {
          iVar5 = *(int *)0x8d08 - *(int *)0x9378;
        }
        else {
          iVar5 = *(int *)(iVar7 + 0x12) - *(int *)0x9378;
        }
      }
      else {
        local_2e = 0;
        if (*(int *)0x8d08 < *(int *)(iVar7 + 0x12)) {
          iVar5 = *(int *)0x8d08 - *(int *)(iVar7 + 0x10);
        }
        else {
          iVar5 = *(int *)(iVar7 + 0x12) - *(int *)(iVar7 + 0x10);
        }
      }
      local_24 = iVar5 + 1;
      uVar6 = (iVar5 + local_2e) * (*(byte *)*(undefined2 *)(iVar7 + 0x14) + 3 >> 1 & 0xfe) +
              (CONCAT11((char)((int)uVar2 >> 9),(char)((int)uVar2 >> 1)) & 0xfffe);
      local_22 = (local_24 + iVar4 + -1) * *(int *)0x9372 +
                 (CONCAT11((char)(local_1a >> 9),(char)(local_1a >> 1)) & 0xfffe);
      if ((uVar2 & 3) != 0) {
        local_22 = local_22 - 2;
      }
      *(undefined2 *)0x4930 = local_20;
      *(undefined2 *)0x4932 = local_2a;
      *(int *)0x492c = -((*(byte *)*(undefined2 *)(iVar7 + 0x14) + 3 >> 1 & 0xfe) + uVar3);
      *(int *)0x492e = -(uVar3 + *(int *)0x9372);
      if (*(char *)(iVar7 + 10) == '\0') {
        puVar1 = (uint *)(*(int *)(iVar7 + 0x14) + 4);
        uVar2 = *puVar1;
        iVar4 = *(int *)(*(int *)(iVar7 + 0x14) + 6);
        *(int *)0x4938 = uVar6 + *puVar1;
        *(int *)0x493a = (((int)uVar6 >> 0xf) + (uint)CARRY2(uVar6,uVar2)) * 0x1000 + iVar4;
      }
      else {
        *(int *)0x4938 = uVar6 + 0x32e0;
        *(undefined2 *)0x493a = 0x120d;
      }
      *(int *)0x4934 = local_22 + 0x3f90;
      *(int *)0x4936 = (((int)local_22 >> 0xf) + (uint)(0xc06f < local_22)) * 0x1000 + 0x120d;
      *(int *)0x492a = local_24;
      *(int *)0x4928 = (int)uVar3 >> 1;
      *(uint *)0x4924 = *(uint *)(iVar7 + 0xc) & 3;
      *(undefined2 *)0x4926 = 1;
      FUN_1000_e57a();
    }
  }
  *(undefined2 *)0xa850 = 0;
  if (*(char *)0x59 == '\0') {
    FUN_1000_1f0e(0x1000);
    func_0x000110d0(0x11ef,0x241a,*(undefined2 *)0x9378,*(undefined2 *)0x9372,*(undefined2 *)0x8dd4,
                    0x3f90);
    FUN_1000_1ef0(0x110d);
  }
  else {
    FUN_1000_5cb5(0x7f20,*(undefined2 *)0x9378,*(undefined2 *)0x9372,*(undefined2 *)0x8dd4,0x3f90,
                  0x120d);
  }
  return;
}



/* ---- FUN_1000_4575 @ 1000:4575 ---- */

void FUN_1000_4575()

{
  byte *param_1 = 0;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  FUN_1000_e8cb(*(undefined2 *)(param_1 + 4),*(undefined2 *)(param_1 + 6),*param_1 + 3 >> 1 & 0xfffe
                ,param_1[1]);
  return;
}



/* ---- FUN_1000_45a2 @ 1000:45a2 ---- */

void FUN_1000_45a2(int param_1,int param_2,int param_3,int param_4)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  iVar2 = param_3 * 8;
  param_4 = param_4 * 0x1c;
  *(undefined1 *)(param_4 + 0x5ea) = 0;
  *(int *)(param_4 + 0x5e0) = param_1;
  *(int *)(param_4 + 0x5e2) = param_2;
  *(int *)(param_4 + 0x5ec) = -(*(char *)(iVar2 + -0x7e70) - param_1);
  *(int *)(param_4 + 0x5ee) =
       (*(byte *)(iVar2 + -0x7e72) + 3 & 0xfc) + *(int *)(param_4 + 0x5ec) + -1;
  *(int *)(param_4 + 0x5f0) = -(*(char *)(iVar2 + -0x7e6f) - param_2);
  *(int *)(param_4 + 0x5f2) =
       (param_2 - ((int)*(char *)(iVar2 + -0x7e6f) - (uint)*(byte *)(iVar2 + -0x7e71))) + -1;
  uVar1 = *(undefined2 *)(param_3 * 4 + -0x7516);
  *(undefined2 *)(param_4 + 0x5f6) = *(undefined2 *)(param_3 * 4 + -0x7518);
  *(undefined2 *)(param_4 + 0x5f8) = uVar1;
  *(undefined1 *)(param_4 + 0x5eb) = 0xff;
  *(undefined2 *)(param_4 + 0x5f4) = (byte *)(iVar2 + -0x7e72);
  FUN_1000_3eb1(param_2 + 200,(int *)(param_4 + 0x5e0));
  return;
}



/* ---- FUN_1000_466b @ 1000:466b ---- */

void FUN_1000_466b(int param_1)

{
  undefined2 *puVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 unaff_DS;
  int local_18;
  undefined2 *puVar6;
  int *piVar7;
  char *pcVar8;
  
  FUN_1000_ecaa();
  FUN_1000_1f0e(0x1000);
  *(undefined1 *)0x5c7 = 9;
  *(undefined2 *)0x8ddc = 0x19;
  puVar6 = (undefined2 *)*(undefined2 *)(param_1 * 4 + *(int *)0x8dda + 2);
  *(int *)0x8dd8 = *(int *)(param_1 * 2 + 0x53fa) + -0x20;
  *(undefined2 *)0x8dd2 = 0;
  while( true ) {
    puVar1 = puVar6 + 3;
    if ((char *)*puVar6 == (char *)0x0) break;
    local_18 = 0;
    pcVar8 = (char *)*puVar6;
    while (*pcVar8 != '\0') {
      local_18 = local_18 + 1;
      pcVar8 = pcVar8 + 1;
    }
    puVar6 = puVar1;
    if (*(int *)0x8dd2 < local_18) {
      *(int *)0x8dd2 = local_18;
    }
  }
  iVar3 = (*(int *)0x8dd2 >> 1) + -1;
  *(int *)0x8dd2 = iVar3;
  if (0xe0 < iVar3 * 0x10 + *(int *)0x8dd8) {
    *(int *)0x8dd8 = iVar3 * -0x10 + 0xe0;
  }
  FUN_1000_45a2(*(undefined2 *)0x8dd8,*(undefined2 *)0x8ddc,0xf,0x20);
  FUN_1000_45a2(*(undefined2 *)0x8dd8,*(undefined2 *)0x8ddc,0x10,0x21);
  for (iVar3 = 0; iVar3 < *(int *)0x8dd2; iVar3 = iVar3 + 1) {
    FUN_1000_45a2(iVar3 * 0x10 + *(int *)0x8dd8 + 0x30,*(undefined2 *)0x8ddc,4,iVar3 + 0x22);
  }
  if (*(int *)0x2eb3 < 0xbb9) {
    FUN_1000_45a2(*(int *)0x8dd8 + 0x20,*(int *)0x8ddc + 0x17,8,0x2c);
    FUN_1000_45a2(*(int *)0x8dd2 * 0x10 + *(int *)0x8dd8 + 0x30,*(int *)0x8ddc + 0x17,10,0x2d);
    FUN_1000_45a2(*(int *)0x8dd8 + 0x10,*(int *)0x8ddc + 0x17,7,0x39);
    for (iVar3 = 0; iVar3 < *(int *)0x8dd2; iVar3 = iVar3 + 1) {
      FUN_1000_45a2(iVar3 * 0x10 + *(int *)0x8dd8 + 0x30,*(int *)0x8ddc + 0x17,9,iVar3 + 0x2e);
    }
    FUN_1000_45a2(*(int *)0x8dd8 + 0x10,*(int *)0x8ddc + 0x17,5,0x38);
    for (iVar3 = 0; iVar3 < *(int *)0x8dd2; iVar3 = iVar3 + 1) {
      FUN_1000_45a2(iVar3 * 0x10 + *(int *)0x8dd8 + 0x30,*(int *)0x8ddc + 0x17,6,iVar3 + 0x3a);
    }
  }
  FUN_1000_45a2(*(undefined2 *)0x8dd8,*(undefined2 *)0x8ddc,0,0x44);
  FUN_1000_45a2(*(int *)0x8dd2 * 0x10 + *(int *)0x8dd8 + 0x20,*(undefined2 *)0x8ddc,2,0x45);
  FUN_1000_3f0f(*(undefined2 *)0x8dd8,*(int *)0x8ddc + 200,0,0x818e,0xd50);
  FUN_1000_3f0f(*(int *)0x8dd2 * 0x10 + *(int *)0x8dd8 + 0x20,*(int *)0x8ddc + 200,0,0x819e,0xd6c);
  piVar7 = (int *)0x820e;
  FUN_1000_3f0f(*(int *)0x8dd2 * 0x10 + *(int *)0x8dd8 + 0x20,*(int *)0x8ddc + 200,0,0x820e,0x97c);
  if (*(int *)0x2eb3 < 0xbb9) {
    FUN_1000_3f0f(*(int *)0x8dd2 * 0x10 + *(int *)0x8dd8 + 0x30,*(int *)0x8ddc + 0xdf,0,0x81c6,0xc1c
                 );
    piVar7 = (int *)0x7;
    FUN_1000_45a2(*(int *)0x8dd8 + 0x10,*(int *)0x8ddc + 0x17,7,0x39);
  }
  *(undefined2 *)0x484 = 0;
  local_18 = 0;
  while (iVar3 = *piVar7, iVar3 != 0) {
    FUN_1000_5381();
    *(int *)0x8ddc = *(int *)0x8ddc + 8;
    *(int *)0x484 = *(int *)0x484 + 1;
    if (*(int *)0x2eb3 < 0xbb9) {
      FUN_1000_45a2(*(int *)0x8dd8 + 0x10,*(int *)0x8ddc + 0x17,5,0x38);
      for (iVar5 = 0; iVar5 < *(int *)0x8dd2; iVar5 = iVar5 + 1) {
        iVar4 = iVar5 * 0x1c;
        *(int *)(iVar4 + 0xc3a) = *(int *)0x8ddc + 0x17;
        *(int *)(iVar4 + 0xc48) = (*(int *)0x8ddc - (int)*(char *)0x81c1) + 0x17;
        *(int *)(iVar4 + 0xc4a) =
             (*(int *)0x8ddc - (int)*(char *)0x81c1) + (uint)*(byte *)0x81bf + 0x16;
      }
      iVar5 = *(int *)0x8ddc + 0xdf;
      FUN_1000_3f0f(*(int *)0x8dd2 * 0x10 + *(int *)0x8dd8 + 0x30,iVar5,0,0x81c6,0xc1c);
      *(int *)0x5c8 = iVar3;
      if (*(int *)0x8dde == 0) {
        if (*(char *)(iVar5 + 4) == '\0') {
          uVar2 = 0;
        }
        else {
          uVar2 = 0xf;
        }
        *(undefined1 *)0x5c6 = uVar2;
      }
      else {
        if (*(char *)(iVar5 + 4) == '\0') {
          uVar2 = 8;
        }
        else {
          uVar2 = 0xe;
        }
        *(undefined1 *)0x5c6 = uVar2;
      }
      FUN_1000_e915(0x5c6,*(int *)0x8dd8 + 0x24,*(int *)0x8ddc + 0xf);
      for (iVar3 = 0; iVar3 < *(int *)0x8dd2; iVar3 = iVar3 + 1) {
        iVar5 = iVar3 * 0x1c;
        *(int *)(iVar5 + 0xaea) = *(int *)0x8ddc + 0x17;
        *(int *)(iVar5 + 0xaf8) = (*(int *)0x8ddc - (int)*(char *)0x81d9) + 0x17;
        *(int *)(iVar5 + 0xafa) =
             (*(int *)0x8ddc - (int)*(char *)0x81d9) + (uint)*(byte *)0x81d7 + 0x16;
      }
      FUN_1000_45a2(*(int *)0x8dd2 * 0x10 + *(int *)0x8dd8 + 0x30,*(int *)0x8ddc + 0x17,10,0x2d);
      FUN_1000_45a2(*(int *)0x8dd8 + 0x20,*(int *)0x8ddc + 0x17,8,0x2c);
      iVar3 = *(int *)0x8dd8 + 0x10;
      FUN_1000_45a2(iVar3,*(int *)0x8ddc + 0x17,7,0x39);
    }
    else {
      FUN_1000_45a2(*(int *)0x8dd2 * 0x10 + *(int *)0x8dd8 + 0x30,*(int *)0x8ddc + 0xf,10,0x2d);
      FUN_1000_45a2(*(int *)0x8dd8 + 0x20,*(int *)0x8ddc + 0xf,8,0x2c);
      FUN_1000_3f0f(*(int *)0x8dd8 + 0x20,*(int *)0x8ddc + 0xd7,0,0x81ce,0xab0);
      iVar3 = *(int *)0x8ddc + 0xd7;
      FUN_1000_3f0f(*(int *)0x8dd2 * 0x10 + *(int *)0x8dd8 + 0x30,iVar3,0,0x81de,0xacc);
      FUN_1000_527e(local_18,0);
      local_18 = local_18 + 1;
    }
    piVar7 = (int *)(iVar3 + 6);
  }
  if (3000 < *(int *)0x2eb3) {
    FUN_1000_45a2(*(int *)0x8dd8 + 0x10,*(int *)0x8ddc + 0x17,5,0x38);
    FUN_1000_45a2(*(int *)0x8dd8 + 0x10,*(int *)0x8ddc + 0x17,7,0x39);
    for (iVar3 = 0; iVar3 < *(int *)0x8dd2; iVar3 = iVar3 + 1) {
      FUN_1000_45a2(iVar3 * 0x10 + *(int *)0x8dd8 + 0x30,*(int *)0x8ddc + 0x17,6,iVar3 + 0x3a);
    }
    FUN_1000_3f0f(*(int *)0x8dd2 * 0x10 + *(int *)0x8dd8 + 0x30,*(int *)0x8ddc + 0xdf,0,0x81c6,0xc1c
                 );
  }
  iVar3 = 0xab0;
  for (iVar5 = 0; iVar5 < *(int *)0x8dd2 + 2; iVar5 = iVar5 + 1) {
    FUN_1000_3e81(iVar3);
    *(undefined2 *)(iVar3 + 0x14) = 0;
    iVar3 = iVar3 + 0x1c;
  }
  FUN_1000_1ef0(0x11ef);
  return;
}



/* ---- FUN_1000_4c74 @ 1000:4c74 ---- */

void FUN_1000_4c74()

{
  int iVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  FUN_1000_1f0e(0x1000);
  if (*(int *)0x2eb3 < 0xbb9) {
    while (0x19 < *(int *)0x8ddc) {
      FUN_1000_5381();
      *(int *)0x8ddc = *(int *)0x8ddc + -8;
      FUN_1000_45a2(*(int *)0x8dd8 + 0x10,*(int *)0x8ddc + 0x17,5,0x38);
      for (iVar1 = 0; iVar1 < *(int *)0x8dd2; iVar1 = iVar1 + 1) {
        FUN_1000_45a2(iVar1 * 0x10 + *(int *)0x8dd8 + 0x30,*(int *)0x8ddc + 0x17,6,iVar1 + 0x3a);
      }
      FUN_1000_3f0f(*(int *)0x8dd2 * 0x10 + *(int *)0x8dd8 + 0x30,*(int *)0x8ddc + 0xdf,0,0x81c6,
                    0xc1c);
      FUN_1000_45a2(*(int *)0x8dd8 + 0x10,*(int *)0x8ddc + 0x17,7,0x39);
    }
    FUN_1000_45a2(*(undefined2 *)0x8dd8,*(undefined2 *)0x8ddc,0x10,0x21);
  }
  iVar1 = 0xc00;
  for (iVar2 = 0; iVar2 < *(int *)0x8dd2 + 2; iVar2 = iVar2 + 1) {
    FUN_1000_3e81(iVar1);
    *(undefined2 *)(iVar1 + 0x14) = 0;
    iVar1 = iVar1 + 0x1c;
  }
  iVar1 = 0x960;
  for (iVar2 = 0; iVar2 < *(int *)0x8dd2 + 2; iVar2 = iVar2 + 1) {
    FUN_1000_3e81(iVar1);
    *(undefined2 *)(iVar1 + 0x14) = 0;
    iVar1 = iVar1 + 0x1c;
  }
  FUN_1000_3f49(0xd50);
  FUN_1000_3f49(0xd6c);
  if (*(int *)0x2eb3 < 0xbb9) {
    *(undefined2 *)0x990 = 0x820e;
    *(undefined2 *)0xc30 = 0x81c6;
    FUN_1000_3f0f(*(int *)0x8dd2 * 0x10 + *(int *)0x8dd8 + 0x20,*(int *)0x8ddc + 200,0,0x820e,0x97c)
    ;
    FUN_1000_3f0f(*(int *)0x8dd2 * 0x10 + *(int *)0x8dd8 + 0x30,*(int *)0x8ddc + 0xdf,0,0x81c6,0xc1c
                 );
    FUN_1000_3f49(0x97c);
    FUN_1000_3f49(0xc1c);
  }
  else {
    FUN_1000_58b0(*(int *)0xd5c >> 2,*(int *)0xd7a >> 2,*(undefined2 *)0xd7e,*(undefined2 *)0xc2e);
  }
  *(undefined2 *)0x480 = 0xff;
  FUN_1000_1ef0(0x11ef);
  return;
}



/* ---- FUN_1000_4e5d @ 1000:4e5d ---- */

void FUN_1000_4e5d()

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined2 unaff_DS;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  
  FUN_1000_ecaa();
  FUN_1000_1f0e(0x1000);
  piVar4 = (int *)*(undefined2 *)0x8dda;
  iVar8 = 0x960;
  *(undefined1 *)0x96b = 0xff;
  uVar2 = *(undefined2 *)0x8b16;
  *(undefined2 *)0x976 = *(undefined2 *)0x8b14;
  *(undefined2 *)0x978 = uVar2;
  *(undefined2 *)0x974 = 0;
  iVar6 = 0;
  FUN_1000_3f0f(0,200,0,0x81e6,0x960);
  FUN_1000_3e81(iVar8);
  *(undefined2 *)(iVar8 + 0x14) = 0;
  *(undefined1 *)(iVar8 + 0xb) = 0;
  iVar5 = 0x30;
  while( true ) {
    piVar1 = piVar4;
    piVar4 = piVar4 + 2;
    if ((char *)*piVar1 == (char *)0x0) break;
    iVar7 = 0;
    pcVar10 = (char *)*piVar1;
    while (*pcVar10 != '\0') {
      iVar7 = iVar7 + 1;
      pcVar10 = pcVar10 + 1;
    }
    iVar3 = iVar7 + 1 >> 1;
    iVar7 = iVar6 + 1;
    *(int *)(iVar6 * 2 + 0x53fa) = iVar5;
    iVar9 = iVar8;
    for (iVar6 = 0; iVar8 = iVar9 + 0x1c, iVar6 < iVar3; iVar6 = iVar6 + 1) {
      *(undefined1 *)(iVar9 + 0x27) = 0xff;
      uVar2 = *(undefined2 *)0x8b1e;
      *(undefined2 *)(iVar9 + 0x32) = *(undefined2 *)0x8b1c;
      *(undefined2 *)(iVar9 + 0x34) = uVar2;
      iVar7 = 0;
      iVar6 = 200;
      FUN_1000_3f0f(iVar5,200,0,0x81f6,iVar8);
      iVar3 = 0x4f4e;
      FUN_1000_3e81(iVar8);
      *(undefined2 *)(iVar8 + 0x14) = 0;
      *(undefined1 *)(iVar8 + 0xb) = 0;
      iVar5 = iVar5 + 0x10;
      iVar9 = iVar8;
    }
    iVar6 = 0x4f74;
    FUN_1000_50af(iVar7 + -1,0);
    if (*piVar4 == 0) {
      *(int *)(iVar6 * 2 + 0x53fa) = iVar5;
      *(undefined1 *)(iVar8 + 0xb) = 0xff;
      uVar2 = *(undefined2 *)0x8b22;
      *(undefined2 *)(iVar8 + 0x16) = *(undefined2 *)0x8b20;
      *(undefined2 *)(iVar8 + 0x18) = uVar2;
      iVar6 = 0;
      FUN_1000_3f0f(iVar5,200,0,0x81fe,iVar8);
      FUN_1000_3e81(iVar8);
      *(undefined2 *)(iVar8 + 0x14) = 0;
      *(undefined1 *)(iVar8 + 0xb) = 0;
      iVar5 = iVar5 + 0x18;
    }
    else {
      *(undefined1 *)(iVar8 + 0xb) = 0xff;
      uVar2 = *(undefined2 *)0x8b1a;
      *(undefined2 *)(iVar8 + 0x16) = *(undefined2 *)0x8b18;
      *(undefined2 *)(iVar8 + 0x18) = uVar2;
      iVar6 = 0;
      FUN_1000_3f0f(iVar5,200,0,0x81ee,iVar8);
      FUN_1000_3e81(iVar8);
      *(undefined2 *)(iVar8 + 0x14) = 0;
      *(undefined1 *)(iVar8 + 0xb) = 0;
      iVar5 = iVar5 + 0x10;
    }
  }
  *(int *)0xb0da = iVar6 + -1;
  FUN_1000_1ef0(0x11ef);
  return;
}



/* ---- FUN_1000_5035 @ 1000:5035 ---- */

undefined2 FUN_1000_5035()

{
  undefined2 unaff_DS;
  undefined2 uVar1;
  
  FUN_1000_ecaa();
  FUN_1000_1f0e(0x1000);
  if (*(int *)0x47e != 0xff) {
    FUN_1000_4c74();
  }
  *(undefined2 *)0x47e = 0xff;
  uVar1 = 0x4f;
  FUN_1000_58b0(0,0x4f,0,0x17);
  FUN_1000_1ef0(0x11ef);
  return uVar1;
}



/* ---- FUN_1000_50af @ 1000:50af ---- */

void FUN_1000_50af(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  FUN_1000_1f0e(0x1000);
  *(undefined2 *)0x5cc = *(undefined2 *)(param_1 * 4 + *(int *)0x8dda);
  if (*(int *)0x8dde == 0) {
    if (*(char *)0x11ab == '\x03') {
      if (param_2 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 0xf;
      }
      *(undefined1 *)0x5ca = uVar1;
    }
    else {
      if (param_2 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 0xc;
      }
      *(undefined1 *)0x5ca = uVar1;
    }
  }
  else {
    if (param_2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 9;
    }
    *(undefined1 *)0x5ca = uVar1;
  }
  FUN_1000_e915(0x5ca,*(undefined2 *)(param_1 * 2 + 0x53fa),8);
  FUN_1000_1ef0(0x11ef);
  return;
}



/* ---- FUN_1000_512d @ 1000:512d ---- */

void FUN_1000_512d()

{
  int param_1 = 0; int param_2 = 0;
  int iVar1;
  undefined2 unaff_DS;
  int iVar2;
  
  FUN_1000_ecaa();
  FUN_1000_1f0e(0x1000);
  if (param_2 < 0x10) {
    iVar2 = 0;
    while ((iVar2 < 5 && (*(int *)(iVar2 * 2 + 0x53fa) < param_1))) {
      iVar2 = iVar2 + 1;
    }
    if ((0 < iVar2) && (iVar2 <= *(int *)0xb0da)) {
      iVar2 = iVar2 + -1;
      if (iVar2 != *(int *)0x47e) {
        if (*(int *)0x47e != 0xff) {
          FUN_1000_4c74();
          FUN_1000_50af(*(undefined2 *)0x47e,0);
          *(undefined2 *)0x47e = 0xff;
        }
        FUN_1000_50af(iVar2,1);
        *(int *)0x47e = iVar2;
        FUN_1000_466b(iVar2);
      }
    }
  }
  if (*(int *)0x47e != 0xff) {
    if (((param_1 < *(int *)0x8dd8 + 0x24) ||
        (*(int *)0x8dd2 * 0x10 + *(int *)0x8dd8 + 0x34 <= param_1)) || (param_2 < 0x30)) {
      if (*(int *)0x480 != 0xff) {
        FUN_1000_527e(*(undefined2 *)0x480,0);
        *(undefined2 *)0x480 = 0xff;
      }
    }
    else {
      iVar2 = 0;
      for (iVar1 = 0x30; (iVar1 < *(int *)0x8ddc + 0x1f && (iVar1 <= param_2)); iVar1 = iVar1 + 8) {
        iVar2 = iVar2 + 1;
      }
      if (iVar1 < *(int *)0x8ddc + 0x1f) {
        iVar2 = iVar2 + -1;
        if (iVar2 != *(int *)0x480) {
          if (*(int *)0x480 != 0xff) {
            FUN_1000_527e(*(undefined2 *)0x480,0);
          }
          FUN_1000_527e(iVar2,1);
          *(int *)0x480 = iVar2;
        }
      }
      else if (*(int *)0x480 != 0xff) {
        FUN_1000_527e(*(undefined2 *)0x480,0);
        *(undefined2 *)0x480 = 0xff;
      }
    }
  }
  FUN_1000_1ef0(0x11ef);
  return;
}



/* ---- FUN_1000_527e @ 1000:527e ---- */

void FUN_1000_527e(int param_1,int param_2)

{
  int iVar1;
  undefined1 uVar2;
  undefined2 unaff_DS;
  char local_1c [3];
  char acStack_19 [11];
  undefined2 uStack_e;
  undefined2 uStack_c;
  int iStack_a;
  int local_8;
  char *pcVar3;
  char *pcVar4;
  
  FUN_1000_ecaa();
  iVar1 = *(int *)0x8dd2;
  pcVar4 = local_1c;
  for (pcVar3 = (char *)*(undefined2 *)
                         (*(int *)(*(int *)0x47e * 4 + *(int *)0x8dda + 2) + param_1 * 6);
      *pcVar3 != '\0'; pcVar3 = pcVar3 + 1) {
    *pcVar4 = *pcVar3;
    pcVar4 = pcVar4 + 1;
  }
  for (; pcVar4 != acStack_19 + iVar1 * 2; pcVar4 = pcVar4 + 1) {
    *pcVar4 = ' ';
  }
  *pcVar4 = '\0';
  *(int *)0x5c8 = (int)local_1c;
  if (*(char *)(*(int *)(*(int *)0x47e * 4 + *(int *)0x8dda + 2) + param_1 * 6 + 4) == '\0') {
    *(undefined1 *)0x5c7 = 9;
    if (*(int *)0x8dde == 0) {
      *(undefined1 *)0x5c6 = 0;
    }
    else {
      *(undefined1 *)0x5c6 = 8;
    }
  }
  else if (*(int *)0x8dde == 0) {
    if (param_2 == 0) {
      uVar2 = 9;
    }
    else {
      uVar2 = 0;
    }
    *(undefined1 *)0x5c7 = uVar2;
    *(undefined1 *)0x5c6 = 0xf;
  }
  else {
    if (param_2 == 0) {
      uVar2 = 9;
    }
    else {
      uVar2 = 1;
    }
    *(undefined1 *)0x5c7 = uVar2;
    *(undefined1 *)0x5c6 = 0xe;
  }
  local_8 = param_1 * 8 + 0x30;
  iStack_a = *(int *)0x8dd8 + 0x24;
  uStack_c = 0x5c6;
  uStack_e = 0x5378;
  FUN_1000_e915();
  return;
}



/* ---- FUN_1000_5381 @ 1000:5381 ---- */

void FUN_1000_5381()

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  if (*(int *)0x47e != 0xff) {
    iVar3 = *(int *)0x482;
    *(uint *)0x482 = (uint)(iVar3 == 0);
    iVar3 = (uint)(iVar3 == 0) * 4;
    uVar2 = *(undefined2 *)(iVar3 + -0x7516);
    *(undefined2 *)0xd66 = *(undefined2 *)(iVar3 + -0x7518);
    *(undefined2 *)0xd68 = uVar2;
    FUN_1000_3f0f(*(undefined2 *)0xd50,*(int *)0xd52 + 200,*(undefined1 *)0xd5a,
                  *(int *)0x482 * 8 + -0x7e72,0xd50);
    uVar2 = *(undefined2 *)(*(int *)0x482 * 4 + -0x750e);
    *(undefined2 *)0xd82 = *(undefined2 *)(*(int *)0x482 * 4 + -0x7510);
    *(undefined2 *)0xd84 = uVar2;
    FUN_1000_3f0f(*(undefined2 *)0xd6c,*(int *)0xd6e + 200,*(undefined1 *)0xd76,
                  *(int *)0x482 * 8 + -0x7e62,0xd6c);
    cVar1 = *(char *)0x933c;
    *(char *)0x933c = *(char *)0x933c + '\x01';
    if (cVar1 != '\0') {
      *(undefined1 *)0x933c = 0;
    }
  }
  return;
}



/* ---- FUN_1000_543a @ 1000:543a ---- */

void FUN_1000_543a()

{
  uint param_1 = 0; uint param_2 = 0;
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  if (param_1 < 0x40) {
    iVar9 = (param_1 >> 3) * 0x12 + *(int *)0x8d06;
    iVar2 = (param_1 & 7) * 2;
    iVar10 = *(int *)(iVar2 + iVar9) + -1;
    iVar1 = *(int *)(iVar2 + iVar9 + 2);
    iVar3 = *(int *)(iVar2 + iVar9 + 0x12) + -1;
    iVar2 = *(int *)(iVar2 + iVar9 + 0x12 + 2);
    piVar4 = (int *)((param_1 >> 3) * 2 + *(int *)0x8d0c);
    iVar9 = *piVar4;
    iVar5 = piVar4[1] + 1;
    iVar6 = iVar3;
    if (iVar10 < iVar3) {
      iVar6 = iVar10;
    }
    *(int *)0x922e = iVar6 >> 2;
    iVar6 = iVar1;
    if (iVar1 < iVar2) {
      iVar6 = iVar2;
    }
    *(int *)0x9364 = iVar6 >> 2;
    *(int *)0x9378 = iVar9;
    *(int *)0x8d08 = iVar5;
    if (*(int *)0x922e < 0) {
      *(undefined2 *)0x922e = 0;
    }
    if (0x4f < *(int *)0x9364) {
      *(undefined2 *)0x9364 = 0x4f;
    }
    if (*(int *)0x9378 < 0) {
      *(undefined2 *)0x9378 = 0;
    }
    if (199 < *(int *)0x8d08) {
      *(undefined2 *)0x8d08 = 199;
    }
    FUN_1000_41a8(0);
    if (param_2 != 0) {
      FUN_1000_5b18(param_2);
      iVar10 = iVar10 - *(int *)0xb0ba;
      iVar6 = *(int *)0xb0ba;
      iVar1 = iVar1 - iVar6;
      iVar3 = iVar3 - iVar6;
      iVar2 = iVar2 - iVar6;
      FUN_1000_5b3d(iVar10,0);
      FUN_1000_5b55(iVar1,0);
      FUN_1000_5b55(iVar2,iVar5 - iVar9);
      FUN_1000_5b55(iVar3,iVar5 - iVar9);
      FUN_1000_5b55(iVar10,0);
      FUN_1000_5b3d(iVar10 + 1,1);
      FUN_1000_5b55(iVar1 + -1,1);
      FUN_1000_5b55(iVar1 + -1,0);
      FUN_1000_5b55(iVar2 + -1,iVar5 - iVar9);
      FUN_1000_5b55(iVar2 + -1,(iVar5 - iVar9) + -1);
      FUN_1000_5b55(iVar3 + 1,(iVar5 - iVar9) + -1);
      FUN_1000_5b55(iVar3 + 1,iVar5 - iVar9);
      FUN_1000_5b55(iVar10 + 1,0);
      if (((param_2 != 0) && (param_2 < 0x1c)) && (*(int *)0xefc != 0xff)) {
        FUN_1000_5b18(0x1c);
        uVar7 = (param_1 & 0x38) << 1 | param_1 & 7;
        uVar8 = (*(uint *)0xefc & 0x38) << 1 | *(uint *)0xefc & 7;
        if ((uVar7 - 1 == uVar8) || (uVar7 - 0x11 == uVar8)) {
          FUN_1000_5b3d(0,0);
          FUN_1000_5b55(iVar10,0);
          FUN_1000_5b3d(0,1);
          FUN_1000_5b55(iVar10,1);
        }
        if ((uVar7 - 1 == uVar8) || (uVar7 + 0xf == uVar8)) {
          FUN_1000_5b3d(0,(iVar5 - iVar9) + -1);
          FUN_1000_5b55(iVar3,(iVar5 - iVar9) + -1);
          FUN_1000_5b3d(0,iVar5 - iVar9);
          FUN_1000_5b55(iVar3,iVar5 - iVar9);
        }
        if ((uVar7 + 1 == uVar8) || (uVar7 - 0xf == uVar8)) {
          FUN_1000_5b3d(*(int *)0xb0d8 + -1,0);
          FUN_1000_5b55(iVar1,0);
          FUN_1000_5b3d(*(int *)0xb0d8 + -1,1);
          FUN_1000_5b55(iVar1,1);
        }
        if ((uVar7 + 1 == uVar8) || (uVar7 + 0x11 == uVar8)) {
          FUN_1000_5b3d(*(int *)0xb0d8 + -1,(iVar5 - iVar9) + -1);
          FUN_1000_5b55(iVar2,(iVar5 - iVar9) + -1);
          FUN_1000_5b3d(*(int *)0xb0d8 + -1,iVar5 - iVar9);
          FUN_1000_5b55(iVar2,iVar5 - iVar9);
        }
      }
    }
    FUN_1000_42a0();
  }
  return;
}



/* ---- FUN_1000_578c @ 1000:578c ---- */

void FUN_1000_578c()

{
  int param_1 = 0; int param_2 = 0; int param_3 = 0; int param_4 = 0; int param_5 = 0;
  int iVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  iVar1 = param_1 + param_3 + -1;
  iVar2 = param_2 + param_4 + -1;
  *(int *)0x922e = param_1 >> 2;
  *(int *)0x9364 = iVar1 >> 2;
  *(int *)0x9378 = param_2;
  *(int *)0x8d08 = iVar2;
  if (*(int *)0x922e < 0) {
    *(undefined2 *)0x922e = 0;
  }
  if (0x4f < *(int *)0x9364) {
    *(undefined2 *)0x9364 = 0x4f;
  }
  if (*(int *)0x9378 < 0) {
    *(undefined2 *)0x9378 = 0;
  }
  if (199 < *(int *)0x8d08) {
    *(undefined2 *)0x8d08 = 199;
  }
  FUN_1000_41a8(0);
  if (param_5 != 0) {
    FUN_1000_5b18(param_5);
    param_1 = param_1 - *(int *)0xb0ba;
    iVar1 = iVar1 - *(int *)0xb0ba;
    FUN_1000_5b3d(param_1,0);
    FUN_1000_5b55(iVar1,0);
    FUN_1000_5b55(iVar1,iVar2 - param_2);
    FUN_1000_5b55(param_1,iVar2 - param_2);
    FUN_1000_5b55(param_1,0);
    FUN_1000_5b3d(param_1 + 1,1);
    FUN_1000_5b55(iVar1 + -1,1);
    FUN_1000_5b55(iVar1 + -1,(iVar2 - param_2) + -1);
    FUN_1000_5b55(param_1 + 1,(iVar2 - param_2) + -1);
    FUN_1000_5b55(param_1 + 1,1);
  }
  FUN_1000_42a0();
  return;
}



/* ---- FUN_1000_58b0 @ 1000:58b0 ---- */

void FUN_1000_58b0()

{
  int param_1 = 0; int param_2 = 0; int param_3 = 0; int param_4 = 0;
  int iVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  *(int *)0x922e = param_1;
  *(int *)0x9364 = param_2;
  iVar1 = (param_2 - param_1) * 2 + 2;
  while (((param_4 - param_3) + 1) * iVar1 != 0) {
    *(int *)0x9378 = param_3;
    iVar2 = param_3 + (int)(0x32c / (long)iVar1) + -1;
    *(int *)0x8d08 = iVar2;
    if (param_4 < iVar2) {
      *(int *)0x8d08 = param_4;
    }
    FUN_1000_41a8(0);
    FUN_1000_42a0();
    param_3 = *(int *)0x8d08 + 1;
  }
  return;
}



/* ---- FUN_1000_5934 @ 1000:5934 ---- */

void FUN_1000_5934(undefined2 *param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  uint uVar6;
  undefined2 unaff_DS;
  undefined2 uVar7;
  uint *puVar8;
  
  FUN_1000_ecaa();
  for (uVar6 = 0; uVar6 < 0xf; uVar6 = uVar6 + 1) {
    uVar3 = FUN_1000_f2f0();
    puVar4 = (undefined2 *)(uVar6 * 2 + 0x486);
    uVar7 = *puVar4;
    puVar5 = (undefined2 *)((uVar3 % (0xf - uVar6) + uVar6 + 1) * 2 + 0x486);
    *puVar4 = *puVar5;
    *puVar5 = uVar7;
  }
  uVar7 = param_1[4];
  param_1[4] = 0;
  bVar1 = ((byte *)param_1[10])[1];
  bVar2 = *(byte *)param_1[10];
  for (uVar6 = 0; uVar6 < 0x10; uVar6 = uVar6 + 1) {
    puVar8 = (uint *)CONCAT22(*(undefined2 *)(param_1[10] + 6),
                              (uint *)*(undefined2 *)(param_1[10] + 4));
    for (uVar3 = 0; uVar3 < (bVar2 + 3 >> 2) * (uint)bVar1; uVar3 = uVar3 + 1) {
      *puVar8 = *puVar8 & *(uint *)((uVar3 + uVar6 & 0xf) * 2 + 0x486);
      puVar8 = (uint *)CONCAT22((int)((ulong)puVar8 >> 0x10) +
                                (-(uint)((uint *)0xfffd < (uint *)puVar8) & 0x1000),
                                (uint *)puVar8 + 1);
    }
    uVar7 = param_1[10];
    FUN_1000_3f0f(*param_1,param_1[1],*(undefined1 *)(param_1 + 5),uVar7,param_1);
  }
  *(undefined1 *)((int)param_1 + 0xb) = 0;
  param_1[4] = uVar7;
  FUN_1000_3f49(param_1);
  return;
}



/* ---- FUN_1000_5a2b @ 1000:5a2b ---- */

void FUN_1000_5a2b()

{
  FUN_1000_ecaa();
  return;
}



/* ---- FUN_1000_5a37 @ 1000:5a37 ---- */

void FUN_1000_5a37()

{
  FUN_1000_ecaa();
  return;
}



/* ---- FUN_1000_5a43 @ 1000:5a43 ---- */

void FUN_1000_5a43()

{
  FUN_1000_ecaa();
  return;
}



/* ---- FUN_1000_5a4f @ 1000:5a4f ---- */

void FUN_1000_5a4f()

{
  undefined1 * param_1 = 0; int param_2 = 0; undefined1 param_3 = 0;
  undefined1 *puVar1;
  
  FUN_1000_ecaa();
  for (; puVar1 = param_1, param_2 != 0; param_2 = param_2 + -1) {
    if ((undefined1 *)param_1 == (undefined1 *)0xffff) {
      /* segment update: param_1 hi = GH_HI16(param_1) + 0x1000 */ (void)0;
    }
    param_1 = (undefined1 *)CONCAT22(GH_HI16(param_1),(undefined1 *)param_1 + 1);
    *puVar1 = param_3;
  }
  return;
}



/* ---- FUN_1000_5a7c @ 1000:5a7c ---- */

void FUN_1000_5a7c(uint param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  uVar2 = param_2 * *(int *)0x9372 + (int)param_1 / 2;
  if ((int)uVar2 < 0xcb1) {
    if ((param_1 & 1) == 0) {
      bVar1 = 0xf0;
    }
    else {
      bVar1 = 0xf;
    }
    *(byte *)(uVar2 + 0x3f90) = *(byte *)(uVar2 + 0x3f90) & ~bVar1 | bVar1 & *(byte *)0x8172;
  }
  return;
}



/* ---- FUN_1000_5b00 @ 1000:5b00 ---- */

void FUN_1000_5b00(int param_1)

{
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  *(undefined2 *)0x4a6 = *(undefined2 *)(param_1 * 2 + 0x4a8);
  return;
}



/* ---- FUN_1000_5b18 @ 1000:5b18 ---- */

void FUN_1000_5b18()

{
  byte param_1 = 0;
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  uVar1 = *(undefined2 *)0x4d94;
  *(byte *)0xc = param_1 & 0xf;
  *(byte *)0x8172 = (param_1 & 0xf) << 4 | *(byte *)0xc;
  return;
}



/* ---- FUN_1000_5b3d @ 1000:5b3d ---- */

void FUN_1000_5b3d(undefined2 param_1,undefined2 param_2)

{
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  *(undefined2 *)0x8d26 = param_1;
  *(undefined2 *)0x8d2a = param_2;
  return;
}



/* ---- FUN_1000_5b55 @ 1000:5b55 ---- */

void FUN_1000_5b55(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined2 unaff_DS;
  undefined2 local_10;
  undefined2 local_c;
  
  FUN_1000_ecaa();
  local_c = FUN_1000_8fb5(param_1 - *(int *)0x8d26);
  local_10 = FUN_1000_8fb5(param_2 - *(int *)0x8d2a);
  FUN_1000_5c8b(param_1 - *(int *)0x8d26);
  iVar1 = FUN_1000_5c8b(param_2 - *(int *)0x8d2a);
  if (local_10 < local_c) {
    iVar2 = local_10 * 2 - local_c;
    (*(code *)*(undefined2 *)0x4a6)(*(undefined2 *)0x8d26,*(undefined2 *)0x8d2a);
    while (local_c != 0) {
      *(int *)0x8d26 = *(int *)0x8d26 + 0x5bd1;
      if (-1 < iVar2) {
        *(int *)0x8d2a = *(int *)0x8d2a + iVar1;
      }
      iVar2 = *(int *)0x8d2a;
      (*(code *)*(undefined2 *)0x4a6)(*(undefined2 *)0x8d26);
      local_c = local_c + -1;
    }
  }
  else {
    iVar2 = local_c * 2 - local_10;
    (*(code *)*(undefined2 *)0x4a6)(*(undefined2 *)0x8d26,*(undefined2 *)0x8d2a);
    while (local_10 != 0) {
      *(int *)0x8d2a = *(int *)0x8d2a + iVar1;
      if (-1 < iVar2) {
        *(int *)0x8d26 = *(int *)0x8d26 + 0x5c3a;
      }
      iVar2 = *(int *)0x8d2a;
      (*(code *)*(undefined2 *)0x4a6)(*(undefined2 *)0x8d26);
      local_10 = local_10 + -1;
    }
  }
  *(int *)0x8d26 = param_1;
  *(int *)0x8d2a = param_2;
  return;
}



/* ---- FUN_1000_5c8b @ 1000:5c8b ---- */

undefined2 FUN_1000_5c8b(int param_1)

{
  undefined2 uVar1;
  
  FUN_1000_ecaa();
  if (param_1 < 1) {
    if (param_1 < 0) {
      uVar1 = 0xffff;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* ---- FUN_1000_5cb5 @ 1000:5cb5 ---- */

void FUN_1000_5cb5()

{
  int param_1 = 0; int param_2 = 0; int param_3 = 0; int param_4 = 0; undefined1 *param_5 = 0;
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined2 unaff_DS;
  undefined4 local_a;
  int local_6;
  
  FUN_1000_ecaa();
  uVar3 = param_2 * 0xa0 + param_1;
  local_a = (undefined1 *)
            CONCAT22(*(int *)0x5d0 +
                     (((int)uVar3 >> 0xf) + (uint)CARRY2(*(uint *)0x5ce,uVar3)) * 0x1000,
                     (undefined1 *)(*(uint *)0x5ce + uVar3));
  uVar3 = 0xa0 - param_3;
  while (param_4 != 0) {
    local_6 = param_3;
    while (puVar2 = local_a, puVar1 = param_5, local_6 != 0) {
      if ((undefined1 *)param_5 == (undefined1 *)0xffff) {
        /* segment update: param_5 hi = GH_HI16(param_5) + 0x1000 */ (void)0;
      }
      param_5 = (undefined1 *)CONCAT22(GH_HI16(param_5),(undefined1 *)param_5 + 1);
      if ((undefined1 *)local_a == (undefined1 *)0xffff) {
        /* segment update: local_a hi = GH_HI16(local_a) + 0x1000 */ (void)0;
      }
      local_a = (undefined1 *)CONCAT22(GH_HI16(local_a),(undefined1 *)local_a + 1);
      *puVar2 = *puVar1;
      local_6 = local_6 + -1;
    }
    local_a = (undefined1 *)
              CONCAT22(GH_HI16(local_a) +
                       (((int)uVar3 >> 0xf) + (uint)CARRY2((uint)(undefined1 *)local_a,uVar3)) *
                       0x1000,(undefined1 *)local_a + uVar3);
    param_4 = param_4 + -1;
  }
  return;
}



/* ---- FUN_1000_5d48 @ 1000:5d48 ---- */

void FUN_1000_5d48()

{
  bool bVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  bVar1 = false;
  do {
    iVar2 = FUN_1000_184d(*(undefined2 *)(*(int *)0x53f0 + 10));
    *(int *)0x9882 = iVar2;
    if (*(int *)(iVar2 + 4) == 1) {
      bVar1 = true;
    }
  } while (!bVar1);
  return;
}



/* ---- FUN_1000_5d7a @ 1000:5d7a ---- */

void FUN_1000_5d7a()

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  bVar2 = false;
  do {
    iVar3 = FUN_1000_184d(*(undefined2 *)(*(int *)0x53f0 + 10));
    *(int *)0x9882 = iVar3;
    if (*(int *)(iVar3 + 4) == 1) {
      FUN_1000_07f3();
    }
    piVar1 = (int *)*(int *)0x9882;
    if ((*piVar1 == 5) && (piVar1[1] == 0)) {
      *(int *)0x933a = piVar1[4];
      *(int *)0x935e = piVar1[5];
      bVar2 = true;
    }
  } while (!bVar2);
  return;
}



/* ---- FUN_1000_5dca @ 1000:5dca ---- */

char * FUN_1000_5dca(int param_1,int param_2,char *param_3)

{
  char cVar1;
  char *pcVar2;
  undefined2 unaff_DS;
  undefined4 uVar3;
  
  if (param_1 == 0 && param_2 == 0) {
    *param_3 = '0';
  }
  else {
    uVar3 = FUN_1000_f39c(param_1,param_2,10,0);
    pcVar2 = (char *)FUN_1000_5dca(uVar3, 0, param_3);
    cVar1 = FUN_1000_f402(param_1,param_2,10,0);
    param_3 = pcVar2 + 1;
    *pcVar2 = cVar1 + '0';
  }
  return param_3;
}



/* ---- FUN_1000_5e18 @ 1000:5e18 ---- */

void FUN_1000_5e18()

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 unaff_DS;
  byte *pbVar6;
  
  FUN_1000_ecaa();
  pbVar6 = (byte *)0x1166;
  iVar3 = 0;
  for (iVar5 = 0; iVar5 < 0x40; iVar5 = iVar5 + 1) {
    iVar4 = iVar3;
    if (*pbVar6 != 0) {
      *(undefined1 *)(iVar3 * 0x1c + 0x5eb) = (char)iVar5;
      *(undefined1 *)(iVar5 + -0x755c) = (char)iVar3;
      iVar4 = iVar3 + 1;
      puVar1 = (undefined2 *)((uint)*(byte *)((*pbVar6 & 0x3f) + *(int *)0x9890) * 8 + -0x7e72);
      puVar2 = (undefined2 *)(*pbVar6 & 0x40);
      FUN_1000_3f0f(*puVar1,*puVar2,puVar2,puVar1,iVar3 * 0x1c + 0x5e0);
    }
    pbVar6 = pbVar6 + 1;
    iVar3 = iVar4;
  }
  return;
}



/* ---- FUN_1000_5ebc @ 1000:5ebc ---- */

void FUN_1000_5ebc(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6, ...)

{
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  param_3 = param_3 - param_1;
  param_4 = param_4 - param_2;
  if (param_3 < 0) {
    *(int *)0x9362 =
         ((param_3 % param_5) * param_6 - param_5 / 2) / param_5 + (param_3 / param_5) * param_6 +
         param_1;
  }
  else {
    *(int *)0x9362 =
         ((param_3 % param_5) * param_6 + param_5 / 2) / param_5 + (param_3 / param_5) * param_6 +
         param_1;
  }
  if (param_4 < 0) {
    *(int *)0x9376 =
         ((param_4 % param_5) * param_6 - param_5 / 2) / param_5 + (param_4 / param_5) * param_6 +
         param_2;
  }
  else {
    *(int *)0x9376 =
         ((param_4 % param_5) * param_6 + param_5 / 2) / param_5 + (param_4 / param_5) * param_6 +
         param_2;
  }
  return;
}



/* ---- FUN_1000_5fbd @ 1000:5fbd ---- */

undefined1 FUN_1000_5fbd(byte param_1, ...)

{
  char param_2 = 0; byte param_3 = 0; byte param_4 = 0; undefined1 param_5 = 0;
  int iVar1;
  byte *pbVar2;
  undefined2 unaff_DS;
  byte bVar3;
  
  FUN_1000_ecaa();
  if (param_2 == '\x05') {
    if (param_4 == 0) {
      *(byte *)0xecc = *(byte *)(param_3 + 0x1166) & 7;
    }
    else {
      *(byte *)0xecd = *(byte *)(param_3 + 0x1166) & 7;
    }
  }
  else if (param_2 != '\b') {
    *(undefined1 *)((*(byte *)(param_3 + 0x1166) & 7) + 0xec5) = 1;
  }
  *(byte *)0x4bc = *(char *)0x4bc + 1U & 0x1f;
  pbVar2 = (byte *)((uint)param_1 * 8 + 0x52f2);
  bVar3 = *pbVar2;
  if (bVar3 == 0xff) {
    *pbVar2 = *(byte *)0x4bc;
  }
  else {
    for (; bVar3 != 0xff; bVar3 = *(byte *)((uint)bVar3 * 8 + 0x52f3)) {
      param_1 = bVar3;
    }
    *(undefined1 *)((uint)param_1 * 8 + 0x52f3) = *(undefined1 *)0x4bc;
  }
  iVar1 = (uint)*(byte *)0x4bc * 8;
  *(char *)(iVar1 + 0x52f0) = param_2;
  *(byte *)(iVar1 + 0x52f4) = param_3;
  *(byte *)(iVar1 + 0x52f5) = param_4;
  *(undefined1 *)(iVar1 + 0x52f6) = param_5;
  *(undefined1 *)(iVar1 + 0x52f1) = 2;
  *(undefined1 *)(iVar1 + 0x52f2) = 0xff;
  *(undefined1 *)(iVar1 + 0x52f3) = 0xff;
  if ((param_2 == '\x03') && (param_3 != param_4)) {
    if (*(int *)0xef6 == 0) {
      FUN_1000_3713();
    }
    FUN_1000_60bb();
  }
  return *(undefined1 *)0x4bc;
}



/* ---- FUN_1000_60bb @ 1000:60bb ---- */

void FUN_1000_60bb()

{
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  FUN_1000_6167(*(undefined1 *)0x984f);
  return;
}



/* ---- FUN_1000_60d3 @ 1000:60d3 ---- */

undefined1 FUN_1000_60d3(char param_1, ...)

{
  byte param_2 = 0; char param_3 = 0; undefined1 param_4 = 0;
  char cVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  cVar1 = *(char *)0x4bc;
  *(byte *)0x4bc = cVar1 + 1U & 0x1f;
  iVar2 = ((byte)(cVar1 + 1U) & 0x1f) * 8;
  *(char *)(iVar2 + 0x52f0) = param_1;
  *(byte *)(iVar2 + 0x52f4) = param_2;
  *(char *)(iVar2 + 0x52f5) = param_3;
  *(undefined1 *)(iVar2 + 0x52f6) = param_4;
  *(undefined1 *)(iVar2 + 0x52f2) = 0xff;
  *(undefined1 *)(iVar2 + 0x52f3) = 0xff;
  *(undefined1 *)0x984f = *(undefined1 *)0x4bc;
  if (param_1 == '\x05') {
    if (param_3 == '\0') {
      *(byte *)0xecc = *(byte *)(param_2 + 0x1166) & 7;
    }
    else {
      *(byte *)0xecd = *(byte *)(param_2 + 0x1166) & 7;
    }
  }
  else if (param_1 != '\b') {
    *(undefined1 *)((*(byte *)(param_2 + 0x1166) & 7) + 0xec5) = 1;
  }
  return *(undefined1 *)0x984f;
}



/* ---- FUN_1000_6167 @ 1000:6167 ---- */

uint FUN_1000_6167(byte param_1)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  undefined2 *puVar7;
  uint uVar8;
  undefined2 uVar9;
  uint uVar10;
  int iVar11;
  byte *pbVar12;
  undefined2 unaff_DS;
  int local_14;
  
  FUN_1000_ecaa();
  iVar11 = (uint)param_1 * 8;
  pbVar12 = (byte *)(iVar11 + 0x52f0);
  bVar1 = *(byte *)(iVar11 + 0x52f4);
  bVar6 = *(byte *)(iVar11 + 0x52f5);
  bVar2 = *(byte *)(iVar11 + 0x52f6);
  *(undefined1 *)(iVar11 + 0x52f1) = 1;
  puVar7 = (undefined2 *)FUN_1000_3b0c();
  *(byte *)((int)puVar7 + 9) = param_1;
  puVar7[3] = (uint)*(byte *)(bVar1 + 0x8aa4) * 0x1c + 0x5e0;
  *puVar7 = 0;
  *(byte *)(puVar7 + 4) = *pbVar12;
  *(undefined1 *)(puVar7 + 1) = 0;
  bVar5 = *(byte *)(bVar1 + 0x1166);
  bVar4 = bVar5 & 7;
  uVar8 = (bVar5 & 0x38) >> 3;
  bVar5 = (byte)uVar8;
  if (*(int *)0xef6 == 0) {
    uVar10 = *pbVar12 - 1;
    switch(uVar10) {
    case 0:
      puVar7[6] = *(int *)((uint)bVar4 * 0x14 + 0xd9c) + 0x7b88 >> 1;
      if (((bVar4 == 1) || (bVar4 == 3)) || (bVar4 == 6)) {
        bVar5 = bVar5 >> 1;
      }
      puVar7[6] = puVar7[6] + (uint)bVar5;
      puVar7[2] = *(undefined2 *)(uVar8 * 2 + (uint)bVar4 * 0x30 + -0x720c);
      *(undefined1 *)(puVar7 + 7) = *(undefined1 *)(puVar7[3] + 0xb);
      *(byte *)(puVar7[3] + 0xb) = bVar6;
      *(byte *)((int)puVar7 + 0xf) = bVar6;
      *(undefined1 *)(puVar7 + 8) = 0;
      FUN_1000_6796(puVar7);
      break;
    case 1:
      *(byte *)(puVar7 + 7) = *(byte *)(bVar1 + 0x1166) >> 3 & 7;
      *(byte *)((int)puVar7 + 0xf) = bVar6;
      *(byte *)(puVar7 + 8) = bVar4;
      puVar7[6] = 0;
      *(byte *)(bVar1 + 0x1166) = *(byte *)(bVar1 + 0x1166) & 0x47 | bVar6 << 3;
      FUN_1000_6796(puVar7);
      break;
    case 2:
      puVar7[6] = (uint)bVar6;
      puVar7[7] = 0xff;
      if (bVar1 != bVar6) {
        if (*(char *)0x4e0 != '\0') {
          *(undefined1 *)0x4e0 = 0;
          puVar7[7] = (uint)*(byte *)(bVar6 + 0x8aa4);
        }
        uVar8 = (uint)bVar1;
        *(undefined1 *)(bVar6 + 0x1166) = *(undefined1 *)(uVar8 + 0x1166);
        *(undefined1 *)(uVar8 + 0x1166) = 0;
        *(undefined1 *)(bVar6 + 0x8aa4) = *(undefined1 *)(uVar8 + 0x8aa4);
        local_14 = 0;
        while (local_14 < 8) {
          *(undefined1 *)(local_14 + 0xec6) = 0xff;
          local_14 = local_14 + 1;
        }
      }
      FUN_1000_6796(puVar7);
      break;
    case 3:
      puVar7[6] = *(int *)((uint)bVar4 * 0x14 + 0xd9c) + 0x7b88 >> 1;
      if (((bVar4 == 1) || (bVar4 == 3)) || (bVar4 == 6)) {
        puVar7[6] = puVar7[6] + (uint)(bVar5 >> 1);
      }
      else {
        puVar7[6] = puVar7[6] + uVar8;
      }
      puVar7[2] = *(undefined2 *)(uVar8 * 2 + (uint)bVar4 * 0x30 + -0x720c);
      *(undefined1 *)(puVar7 + 10) = *(undefined1 *)((uint)bVar6 * 2 + 0x4c0);
      *(undefined1 *)((int)puVar7 + 0x15) = *(undefined1 *)((uint)bVar6 * 2 + 0x4d0);
      *(undefined1 *)(puVar7 + 9) = 0;
      FUN_1000_6796(puVar7);
      break;
    case 4:
      if (bVar6 == 0) {
        uVar9 = 0x103e;
      }
      else {
        uVar9 = 0x1052;
      }
      puVar7[6] = uVar9;
      *(byte *)(puVar7 + 7) = bVar6;
      *(char *)0x4e0 = *(char *)0x4e0 + '\x01';
      if ((*(char *)0x4e0 == '\x02') && (*(int *)0xef8 != 0)) {
        *(undefined2 *)0xef8 = 1;
        *(undefined1 *)(*(byte *)0xecc + 0xec5) = 0xff;
        *(undefined1 *)(*(byte *)0xecd + 0xec5) = 0xff;
        FUN_1000_3713();
      }
      puVar7[2] = *(undefined2 *)((uint)bVar6 * 2 + -0x4f32);
      FUN_1000_6796(puVar7);
      break;
    case 5:
      puVar7[6] = (*(int *)((uint)bVar4 * 0x14 + 0xd9c) + 0x7b88 >> 1) + (uint)bVar6 + 0xe;
      if (bVar6 < 2) {
        *(byte *)(bVar1 + 0x1166) = *(byte *)(bVar1 + 0x1166) & 0x47 | bVar6 << 5;
      }
      else {
        if (*(int *)puVar7[3] < 0xa1) {
          bVar6 = 0x18;
        }
        else {
          bVar6 = 0x38;
        }
        *(byte *)(bVar1 + 0x1166) = bVar6 | *(byte *)(bVar1 + 0x1166) & 0x47;
      }
      FUN_1000_6796(puVar7);
      break;
    case 6:
      puVar7[6] = *(int *)((uint)bVar4 * 0x14 + 0xd9c) + 0x7b88 >> 1;
      *(byte *)(puVar7[3] + 0xb) = bVar6;
      *(undefined1 *)((int)puVar7 + 0x13) = 0;
      if (((bVar4 == 1) || (bVar4 == 3)) || (bVar4 == 6)) {
        puVar7[6] = puVar7[6] + (uint)(bVar5 >> 1);
      }
      else {
        puVar7[6] = puVar7[6] + uVar8;
      }
      puVar7[2] = *(undefined2 *)(uVar8 * 2 + (uint)bVar4 * 0x30 + -0x720c);
      if (bVar2 == 1) {
        puVar7[10] = *(int *)((uint)bVar6 * 2 + *(int *)0xb0c6) + 9;
        puVar7[0xb] = *(int *)((uint)(bVar6 >> 3) * 2 + *(int *)0xb0c8) + -5;
        if ((3 < bVar5) && (bVar5 < 7)) {
          *(undefined1 *)((int)puVar7 + 0x13) = 1;
        }
      }
      else if (bVar2 == 0) {
        puVar7[10] = *(int *)((uint)bVar6 * 2 + *(int *)0xb0c6) + -9;
        puVar7[0xb] = *(int *)((uint)(bVar6 >> 3) * 2 + *(int *)0xb0c8) + 5;
      }
      else {
        puVar7[10] = *(undefined2 *)((uint)bVar6 * 2 + *(int *)0xb0c6);
        puVar7[0xb] = *(undefined2 *)((uint)(bVar6 >> 3) * 2 + *(int *)0xb0c8);
      }
      *(undefined1 *)(puVar7 + 9) = 0;
      FUN_1000_6796(puVar7);
      break;
    case 7:
      puVar7[6] = *(int *)((uint)bVar4 * 0x14 + 0xd9c) + 0x7b88 >> 1;
      if (((bVar4 == 1) || (bVar4 == 3)) || (bVar4 == 6)) {
        puVar7[6] = puVar7[6] + (uint)(bVar5 >> 1);
      }
      else {
        puVar7[6] = puVar7[6] + uVar8;
      }
      *(undefined1 *)(puVar7 + 10) = *(undefined1 *)((uint)bVar6 * 2 + 0x4c0);
      *(undefined1 *)((int)puVar7 + 0x15) = *(undefined1 *)((uint)bVar6 * 2 + 0x4d0);
      *(undefined1 *)(puVar7 + 9) = 0;
      FUN_1000_6796(puVar7);
    }
    if (*(char *)(iVar11 + 0x52f3) == -1) {
      return uVar10;
    }
    uVar8 = FUN_1000_6167(*(undefined1 *)(iVar11 + 0x52f3));
    return uVar8;
  }
  bVar3 = false;
  uVar8 = *pbVar12 - 1;
  switch(*pbVar12 - 1) {
  case 2:
    puVar7[6] = (uint)bVar6;
    puVar7[7] = 0xff;
    if (bVar1 != bVar6) {
      if (*(char *)0x4e0 != '\0') {
        *(char *)0x9602 = *(char *)0x9602 + *(char *)0x4e0 * '\x04';
        *(undefined1 *)0x4e0 = 0;
        FUN_1000_3f49((uint)*(byte *)(bVar6 + 0x8aa4) * 0x1c + 0x5e0);
      }
      uVar8 = (uint)bVar1;
      *(undefined1 *)(bVar6 + 0x1166) = *(undefined1 *)(uVar8 + 0x1166);
      *(undefined1 *)(uVar8 + 0x1166) = 0;
      *(undefined1 *)(bVar6 + 0x8aa4) = *(undefined1 *)(uVar8 + 0x8aa4);
    }
    FUN_1000_6796(puVar7);
    break;
  case 4:
    *(undefined1 *)0x4e0 = 1;
  case 1:
  case 3:
  case 5:
    bVar3 = true;
    uVar8 = (uint)bVar1;
    break;
  case 6:
    if ((bVar1 == bVar6) || (bVar2 < 2)) {
      bVar3 = true;
      uVar8 = (uint)bVar6;
      break;
    }
    *(undefined1 *)(puVar7 + 4) = 1;
  case 0:
    puVar7[6] = bVar4 + 0x10;
    *(undefined1 *)(puVar7 + 7) = *(undefined1 *)(puVar7[3] + 0xb);
    *(byte *)(puVar7[3] + 0xb) = bVar6;
    *(byte *)((int)puVar7 + 0xf) = bVar6;
    *(undefined1 *)(puVar7 + 8) = 0;
    FUN_1000_6796(puVar7);
    break;
  case 7:
    puVar7[6] = bVar4 + 0x10;
    *(undefined1 *)(puVar7 + 10) = *(undefined1 *)((uint)bVar6 * 2 + 0x4c0);
    *(undefined1 *)((int)puVar7 + 0x15) = *(undefined1 *)((uint)bVar6 * 2 + 0x4d0);
    *(undefined1 *)(puVar7 + 9) = 0;
    FUN_1000_6796(puVar7);
  }
  if (*(char *)(iVar11 + 0x52f3) != -1) {
    uVar8 = FUN_1000_6167(*(undefined1 *)(iVar11 + 0x52f3));
  }
  if (bVar3) {
    *(undefined1 *)((uint)*(byte *)((int)puVar7 + 9) * 8 + 0x52f1) = 0;
    bVar1 = *(byte *)((int)puVar7 + 9);
    FUN_1000_3ae3(puVar7);
    bVar1 = *(byte *)((uint)bVar1 * 8 + 0x52f2);
    uVar8 = (uint)bVar1;
    if (bVar1 != 0xff) {
      uVar8 = FUN_1000_6167(bVar1);
    }
  }
  return uVar8;
}



/* ---- FUN_1000_6796 @ 1000:6796 ---- */

void FUN_1000_6796()

{
  int param_1 = 0;
  int iVar1;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  iVar1 = *(int *)0x4be;
  if (iVar1 == 0) {
    *(int *)0x4be = param_1;
  }
  else {
    for (; *(int *)(iVar1 + 10) != 0; iVar1 = *(int *)(iVar1 + 10)) {
    }
    *(int *)(iVar1 + 10) = param_1;
  }
  *(undefined2 *)(param_1 + 10) = 0;
  return;
}



/* ---- FUN_1000_67cb @ 1000:67cb ---- */

void FUN_1000_67cb(int param_1)

{
  int *piVar1;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  for (piVar1 = (int *)0x4be; *piVar1 != param_1; piVar1 = (int *)(*piVar1 + 10)) {
  }
  *piVar1 = *(int *)(param_1 + 10);
  FUN_1000_3ae3(param_1);
  return;
}



/* ---- FUN_1000_67fb @ 1000:67fb ---- */

undefined2 FUN_1000_67fb()

{
  char cVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  undefined2 unaff_DS;
  uint uVar5;
  
  FUN_1000_ecaa();
  iVar4 = 0;
  uVar3 = *(uint *)0x4be;
  if (uVar3 == 0) {
    uVar2 = 1;
  }
  else {
    for (; uVar3 != 0; uVar3 = *(uint *)(uVar3 + 10)) {
      switch(*(undefined1 *)(uVar3 + 8)) {
      case 1:
        iVar4 = FUN_1000_68ea(uVar3);
        break;
      case 2:
        iVar4 = FUN_1000_730c(uVar3);
        break;
      case 3:
        iVar4 = FUN_1000_758c(uVar3);
        break;
      case 4:
        iVar4 = FUN_1000_6ab1(uVar3);
        break;
      case 5:
        iVar4 = FUN_1000_75f6(uVar3);
        break;
      case 6:
        iVar4 = FUN_1000_724d(uVar3);
        break;
      case 7:
        iVar4 = FUN_1000_70ef(uVar3);
        break;
      case 8:
        iVar4 = FUN_1000_6bf9(uVar3);
      }
      if (iVar4 != 0) {
        *(undefined1 *)((uint)*(byte *)(uVar3 + 9) * 8 + 0x52f1) = 0;
        uVar5 = uVar3;
        FUN_1000_67cb(0);
        cVar1 = *(char *)((uVar5 & 0xff) * 8 + 0x52f2);
        if (cVar1 != -1) {
          FUN_1000_6167(cVar1);
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* ---- FUN_1000_68ea @ 1000:68ea ---- */

undefined2 FUN_1000_68ea()

{
  int *param_1 = 0;
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 unaff_DS;
  char cVar7;
  int *piVar8;
  undefined2 *puVar9;
  
  FUN_1000_ecaa();
  iVar5 = FUN_1000_772d(param_1);
  if (iVar5 != 0) {
    puVar9 = (undefined2 *)*param_1;
    iVar5 = param_1[3];
    iVar6 = param_1[6];
    if ((char)param_1[8] == '\0') {
      piVar8 = (int *)*(undefined2 *)(iVar6 * 2 + -0x7b88);
      if (*(int *)0xef6 == 0) {
        cVar7 = '\0';
        for (; *piVar8 != -1; piVar8 = piVar8 + 1) {
          cVar7 = cVar7 + '\x01';
        }
        *(char *)(param_1 + 8) = cVar7;
        piVar8 = (int *)*(undefined2 *)(iVar6 * 2 + -0x7b88);
      }
      else {
        *(undefined1 *)(param_1 + 8) = 8;
      }
      *(undefined1 *)((int)param_1 + 0x11) = 1;
      if (*(int *)0xef6 == 0) {
        iVar6 = *piVar8;
      }
      iVar6 = iVar6 * 8 + -0x7e72;
      *(undefined2 *)0x9362 = *(undefined2 *)((uint)*(byte *)(param_1 + 7) * 2 + *(int *)0xb0c6);
      *(undefined2 *)0x9376 =
           *(undefined2 *)((uint)(*(byte *)(param_1 + 7) >> 3) * 2 + *(int *)0xb0c8);
      FUN_1000_3f0f(*(undefined2 *)0x9362,*(undefined2 *)0x9376,*(undefined1 *)(iVar5 + 10),iVar6,
                    iVar5);
      *(undefined2 *)(iVar5 + 8) = 0;
    }
    else {
      if (*(byte *)(param_1 + 8) <= *(byte *)((int)param_1 + 0x11)) {
        *(undefined2 *)(iVar5 + 4) =
             *(undefined2 *)((uint)*(byte *)((int)param_1 + 0xf) * 2 + *(int *)0xb0c6);
        *(undefined2 *)(iVar5 + 6) =
             *(undefined2 *)((uint)(*(byte *)((int)param_1 + 0xf) >> 3) * 2 + *(int *)0xb0c8);
        return 1;
      }
      iVar4 = *(int *)(iVar5 + 0x14);
      iVar6 = iVar4;
      if (*(int *)0xef6 == 0) {
        iVar6 = FUN_1000_3ac2();
        FUN_1000_3b3a(iVar4,*puVar9,iVar6);
      }
      bVar1 = *(byte *)(param_1 + 7);
      bVar2 = *(byte *)((int)param_1 + 0xf);
      uVar3 = *(undefined1 *)((int)param_1 + 0x11);
      *(char *)((int)param_1 + 0x11) = *(char *)((int)param_1 + 0x11) + '\x01';
      iVar4 = *(int *)((uint)(bVar1 >> 3) * 2 + *(int *)0xb0c8);
      FUN_1000_5ebc(*(undefined2 *)(iVar4 * 2 + *(int *)0xb0c6),iVar4,
                    *(undefined2 *)((uint)bVar2 * 2 + *(int *)0xb0c6),
                    *(undefined2 *)((uint)(bVar2 >> 3) * 2 + *(int *)0xb0c8),(char)param_1[8],uVar3)
      ;
      FUN_1000_3f0f(*(undefined2 *)0x9362,*(undefined2 *)0x9376,*(undefined1 *)(iVar5 + 10),iVar6,
                    iVar5);
      *(uint *)(iVar5 + 8) = (uint)(*(int *)0xef6 == 0);
    }
    *param_1 = iVar6;
  }
  return 0;
}



/* ---- FUN_1000_6ab1 @ 1000:6ab1 ---- */

undefined2 FUN_1000_6ab1()

{
  int *param_1 = 0;
  undefined1 uVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 unaff_DS;
  uint uVar5;
  int *piVar6;
  undefined2 *puVar7;
  
  FUN_1000_ecaa();
  iVar2 = FUN_1000_772d(param_1);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    puVar7 = (undefined2 *)*param_1;
    iVar2 = param_1[3];
    iVar4 = param_1[6];
    if (puVar7 == (undefined2 *)0x0) {
      piVar6 = (int *)*(undefined2 *)(iVar4 * 2 + -0x7b88);
      param_1[7] = *(int *)(iVar2 + 4);
      param_1[8] = *(int *)(iVar2 + 6);
      uVar5 = 0;
      for (; *piVar6 != -1; piVar6 = piVar6 + 1) {
        uVar5 = uVar5 + 1;
      }
      *(char *)(param_1 + 9) = (char)(uVar5 >> 1);
      *(undefined1 *)((int)param_1 + 0x13) = 1;
      iVar4 = *(int *)*(undefined2 *)(iVar4 * 2 + -0x7b88) * 8 + -0x7e72;
      FUN_1000_3f0f(*(undefined2 *)(iVar2 + 4),*(undefined2 *)(iVar2 + 6),
                    *(undefined1 *)(iVar2 + 10),iVar4,iVar2,iVar4);
      *(undefined2 *)(iVar2 + 8) = 0;
    }
    else {
      uVar3 = *(undefined2 *)(iVar2 + 0x14);
      iVar4 = FUN_1000_3ac2(uVar3);
      FUN_1000_3b3a(uVar3,*puVar7,iVar4);
      uVar1 = *(undefined1 *)((int)param_1 + 0x13);
      *(char *)((int)param_1 + 0x13) = *(char *)((int)param_1 + 0x13) + '\x01';
      FUN_1000_5ebc(param_1[7],param_1[8],(int)(char)param_1[10] + param_1[7],
                    (int)*(char *)((int)param_1 + 0x15) + param_1[8],(char)param_1[9],uVar1);
      FUN_1000_3f0f(*(undefined2 *)0x9362,*(undefined2 *)0x9376,*(undefined1 *)(iVar2 + 10),iVar4,
                    iVar2,iVar4);
      *(undefined2 *)(iVar2 + 8) = 1;
    }
    if (*(byte *)(param_1 + 9) + 1 == (uint)*(byte *)((int)param_1 + 0x13)) {
      *(int *)(iVar2 + 4) = (int)(char)param_1[10] + param_1[7];
      *(int *)(iVar2 + 6) = (int)*(char *)((int)param_1 + 0x15) + param_1[8];
      uVar3 = 1;
    }
    else {
      *param_1 = iVar4;
      uVar3 = 0;
    }
  }
  return uVar3;
}



/* ---- FUN_1000_6bf9 @ 1000:6bf9 ---- */

undefined2 FUN_1000_6bf9(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  if (*(char *)(param_1 + 2) == '\0') {
    *(undefined1 *)(param_1 + 2) = 0;
    iVar2 = *(int *)(param_1 + 6);
    if (*(char *)(param_1 + 0x12) == '\0') {
      *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(iVar2 + 4);
      *(undefined2 *)(param_1 + 0x10) = *(undefined2 *)(iVar2 + 6);
      *(undefined1 *)(param_1 + 0x12) = 6;
      *(undefined1 *)(param_1 + 0x13) = 0;
    }
    uVar3 = *(undefined2 *)(iVar2 + 0x14);
    uVar1 = *(undefined1 *)(param_1 + 0x13);
    *(char *)(param_1 + 0x13) = *(char *)(param_1 + 0x13) + '\x01';
    FUN_1000_5ebc(*(undefined2 *)(param_1 + 0xe),*(undefined2 *)(param_1 + 0x10),
                  (int)*(char *)(param_1 + 0x14) + *(int *)(param_1 + 0xe),
                  (int)*(char *)(param_1 + 0x15) + *(int *)(param_1 + 0x10),
                  *(undefined1 *)(param_1 + 0x12),uVar1,uVar3);
    FUN_1000_3f0f(*(undefined2 *)0x9362,*(undefined2 *)0x9376,*(undefined1 *)(iVar2 + 10),uVar3,
                  iVar2);
    *(undefined2 *)(iVar2 + 8) = 0;
    if (*(byte *)(param_1 + 0x12) + 1 == (uint)*(byte *)(param_1 + 0x13)) {
      *(int *)(iVar2 + 4) = (int)*(char *)(param_1 + 0x14) + *(int *)(param_1 + 0xe);
      *(int *)(iVar2 + 6) = (int)*(char *)(param_1 + 0x15) + *(int *)(param_1 + 0x10);
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    *(char *)(param_1 + 2) = *(char *)(param_1 + 2) + -1;
    uVar3 = 0;
  }
  return uVar3;
}



/* ---- FUN_1000_70ef @ 1000:70ef ---- */

undefined2 FUN_1000_70ef()

{
  int *param_1 = 0;
  undefined1 uVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 unaff_DS;
  uint uVar5;
  int *piVar6;
  undefined2 *puVar7;
  
  FUN_1000_ecaa();
  iVar2 = FUN_1000_772d(param_1);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    puVar7 = (undefined2 *)*param_1;
    iVar2 = param_1[3];
    iVar4 = param_1[6];
    if (puVar7 == (undefined2 *)0x0) {
      piVar6 = (int *)*(undefined2 *)(iVar4 * 2 + -0x7b88);
      param_1[7] = *(int *)(iVar2 + 4);
      param_1[8] = *(int *)(iVar2 + 6);
      uVar5 = 0;
      for (; *piVar6 != -1; piVar6 = piVar6 + 1) {
        uVar5 = uVar5 + 1;
      }
      if (*(char *)((int)param_1 + 0x13) == '\0') {
        uVar1 = (undefined1)(uVar5 >> 1);
      }
      else {
        uVar1 = (undefined1)uVar5;
      }
      *(undefined1 *)(param_1 + 9) = uVar1;
      *(undefined1 *)((int)param_1 + 0x13) = 0;
      iVar4 = *(int *)*(undefined2 *)(iVar4 * 2 + -0x7b88) * 8 + -0x7e72;
      uVar1 = *(undefined1 *)((int)param_1 + 0x13);
      *(char *)((int)param_1 + 0x13) = *(char *)((int)param_1 + 0x13) + '\x01';
      FUN_1000_5ebc(param_1[7],param_1[8],param_1[10],param_1[0xb],(char)param_1[9],uVar1);
      FUN_1000_3f0f(*(undefined2 *)0x9362,*(undefined2 *)0x9376,*(undefined1 *)(iVar2 + 10),iVar4,
                    iVar2);
      *(undefined2 *)(iVar2 + 8) = 0;
    }
    else {
      uVar3 = *(undefined2 *)(iVar2 + 0x14);
      iVar4 = FUN_1000_3ac2(uVar3);
      FUN_1000_3b3a(uVar3,*puVar7,iVar4);
      uVar1 = *(undefined1 *)((int)param_1 + 0x13);
      *(char *)((int)param_1 + 0x13) = *(char *)((int)param_1 + 0x13) + '\x01';
      FUN_1000_5ebc(param_1[7],param_1[8],param_1[10],param_1[0xb],(char)param_1[9],uVar1);
      FUN_1000_3f0f(*(undefined2 *)0x9362,*(undefined2 *)0x9376,*(undefined1 *)(iVar2 + 10),iVar4,
                    iVar2,iVar4);
      *(undefined2 *)(iVar2 + 8) = 1;
    }
    if (*(char *)((int)param_1 + 0x13) == (char)param_1[9]) {
      *(int *)(iVar2 + 4) = param_1[10];
      *(int *)(iVar2 + 6) = param_1[0xb];
      uVar3 = 1;
    }
    else {
      *param_1 = iVar4;
      uVar3 = 0;
    }
  }
  return uVar3;
}



/* ---- FUN_1000_724d @ 1000:724d ---- */

undefined2 FUN_1000_724d()

{
  int *param_1 = 0;
  undefined2 *puVar1;
  undefined2 uVar2;
  int *piVar3;
  undefined2 unaff_DS;
  undefined2 *puVar4;
  
  FUN_1000_ecaa();
  if ((char)param_1[1] == '\0') {
    *(undefined1 *)(param_1 + 1) = 0;
    puVar4 = (undefined2 *)*param_1;
    puVar1 = (undefined2 *)param_1[3];
    if (puVar4 == (undefined2 *)0x0) {
      piVar3 = (int *)(*(int *)*(undefined2 *)(param_1[6] * 2 + -0x7b88) * 8 + -0x7e72);
      FUN_1000_3f0f(puVar1[2],puVar1[3],*(undefined1 *)(puVar1 + 5),piVar3,puVar1,piVar3);
      puVar1[4] = 0;
    }
    else {
      uVar2 = puVar1[10];
      piVar3 = (int *)FUN_1000_3ac2(uVar2);
      FUN_1000_3b3a(uVar2,*puVar4,piVar3);
      FUN_1000_3f0f(*puVar1,puVar1[1],*(undefined1 *)(puVar1 + 5),piVar3,puVar1,piVar3);
      puVar1[4] = 1;
    }
    if (*piVar3 == -1) {
      uVar2 = 1;
    }
    else {
      *param_1 = (int)piVar3;
      uVar2 = 0;
    }
  }
  else {
    *(char *)(param_1 + 1) = (char)param_1[1] + -1;
    uVar2 = 0;
  }
  return uVar2;
}



/* ---- FUN_1000_730c @ 1000:730c ---- */

undefined2 FUN_1000_730c()

{
  int *param_1 = 0;
  byte bVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  undefined2 uVar6;
  undefined2 unaff_DS;
  undefined1 uVar7;
  undefined2 *puVar8;
  int *piVar9;
  
  FUN_1000_ecaa();
  if ((param_1[6] != 0) && (iVar4 = FUN_1000_772d(param_1), iVar4 == 0)) {
    return 0;
  }
  puVar8 = (undefined2 *)*param_1;
  piVar3 = (int *)param_1[3];
  bVar1 = *(byte *)(param_1 + 7);
  uVar5 = (uint)bVar1;
  bVar2 = *(byte *)(param_1 + 8);
  if (puVar8 == (undefined2 *)0x0) {
    if (param_1[6] == 0) {
      if (*(byte *)((int)param_1 + 0xf) == uVar5) {
        return 1;
      }
      if ((*(char *)((int)param_1 + 0xf) - bVar1 & 4) == 0) {
        iVar4 = 1;
      }
      else {
        iVar4 = -1;
      }
      param_1[6] = iVar4;
      if (iVar4 < 1) {
        uVar5 = uVar5 + 0x10;
      }
      else {
        uVar5 = uVar5 + 8;
      }
      if (((bVar2 == 3) || (bVar2 == 6)) || (bVar2 == 1)) {
        param_1[6] = param_1[6] << 1;
        piVar9 = (int *)*(undefined2 *)(*(int *)((uint)bVar2 * 0x14 + 0xd9c) + (uVar5 & 0xfffe));
      }
      else {
        piVar9 = (int *)*(undefined2 *)(*(int *)((uint)bVar2 * 0x14 + 0xd9c) + uVar5 * 2);
      }
      uVar5 = *piVar9 * 8 + 0x818e;
      piVar9 = (int *)piVar3[3];
      iVar4 = piVar3[2];
      FUN_1000_3f0f(iVar4,piVar9,(char)piVar3[5],uVar5,piVar3,uVar5);
      piVar3[4] = 0;
    }
    else {
      if (((char)param_1[6] + bVar1 & 7) == *(byte *)((int)param_1 + 0xf)) {
        return 1;
      }
      uVar5 = param_1[6] + uVar5 & 7;
      if (param_1[6] < 1) {
        uVar5 = uVar5 + 0x10;
      }
      else {
        uVar5 = uVar5 + 8;
      }
      if (((bVar2 == 3) || (bVar2 == 6)) || (bVar2 == 1)) {
        uVar5 = uVar5 >> 1;
      }
      if (((bVar2 == 2) || (bVar2 == 5)) || (bVar2 == 1)) {
        puVar8 = (undefined2 *)(*(int *)(*(int *)((uint)bVar2 * 0x14 + 0xd9c) + uVar5 * 2) + 4);
        iVar4 = piVar3[10];
        uVar5 = FUN_1000_3ac2(iVar4);
        FUN_1000_3b3a(iVar4,*puVar8,uVar5);
        piVar9 = (int *)piVar3[3];
        iVar4 = piVar3[2];
        FUN_1000_3f0f(iVar4,piVar9,(char)piVar3[5],uVar5,piVar3,uVar5);
        piVar3[4] = 1;
      }
      else {
        uVar5 = *(int *)*(undefined2 *)(*(int *)((uint)bVar2 * 0x14 + 0xd9c) + uVar5 * 2) * 8 +
                0x818e;
        piVar9 = (int *)piVar3[1];
        iVar4 = *piVar3;
        FUN_1000_3f0f(iVar4,piVar9,(char)piVar3[5],uVar5,piVar3,uVar5);
        piVar3[4] = 0;
      }
    }
    param_1[2] = *(int *)(((uint)(-1 < param_1[6]) + iVar4 * 2) * 2 + (uVar5 & 0xff) * 0x30 +
                         -0x71fc);
    *(undefined1 *)(param_1 + 1) = 0;
    FUN_1000_772d(param_1);
    uVar7 = (undefined1)iVar4;
  }
  else {
    iVar4 = piVar3[10];
    uVar6 = FUN_1000_3ac2(iVar4);
    FUN_1000_3b3a(iVar4,*puVar8,uVar6,iVar4,uVar6);
    piVar9 = (int *)piVar3[1];
    iVar4 = *piVar3;
    FUN_1000_3f0f(iVar4,piVar9,(char)piVar3[5],uVar6,piVar3,uVar6);
    uVar7 = (undefined1)iVar4;
    piVar3[4] = 1;
  }
  if (*piVar9 == -1) {
    piVar9 = (int *)0x0;
  }
  *param_1 = (int)piVar9;
  *(undefined1 *)(param_1 + 7) = uVar7;
  return 0;
}



/* ---- FUN_1000_758c @ 1000:758c ---- */

undefined2 FUN_1000_758c(int param_1)

{
  int iVar1;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  iVar1 = *(int *)(param_1 + 6);
  FUN_1000_3f0f(*(undefined2 *)(iVar1 + 4),*(undefined2 *)(iVar1 + 6),*(undefined1 *)(iVar1 + 10),
                (uint)*(byte *)((*(byte *)(*(int *)(param_1 + 0xc) + 0x1166) & 0x3f) +
                               *(int *)0x9890) * 8 + -0x7e72,*(undefined2 *)(param_1 + 6));
  if (*(int *)(param_1 + 0xe) != 0xff) {
    FUN_1000_5934(*(int *)(param_1 + 0xe) * 0x1c + 0x5e0);
  }
  *(undefined2 *)(*(int *)(param_1 + 6) + 8) = 0;
  return 1;
}



/* ---- FUN_1000_75f6 @ 1000:75f6 ---- */

undefined2 FUN_1000_75f6()

{
  int *param_1 = 0;
  undefined2 *puVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 unaff_DS;
  undefined2 *puVar4;
  int *piVar5;
  byte *pbVar6;
  
  FUN_1000_ecaa();
  if (*(char *)0x4e0 == '\x01') {
    uVar2 = 0;
  }
  else if ((char)param_1[1] == -1) {
    if (*(char *)0x4e0 == '\x04') {
      if (((char)param_1[7] != '\0') &&
         (*(char *)0x9602 = *(char *)0x9602 + *(char *)0x4e0, *(int *)0xef6 == 0)) {
        FUN_1000_2ce0();
        *(undefined1 *)(*(byte *)0xecd + 0xec5) = 1;
        *(undefined1 *)0xecd = 0xff;
        *(undefined1 *)0xecc = 0xff;
        FUN_1000_3713();
      }
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    iVar3 = FUN_1000_772d(param_1);
    if (iVar3 == 0) {
      uVar2 = 0;
    }
    else {
      puVar4 = (undefined2 *)*param_1;
      puVar1 = (undefined2 *)param_1[3];
      pbVar6 = (byte *)param_1[6];
      if (puVar4 == (undefined2 *)0x0) {
        if (*pbVar6 == 0xff) {
          *(undefined1 *)(param_1 + 1) = 0xff;
          *(char *)0x4e0 = *(char *)0x4e0 + '\x01';
          return 0;
        }
        piVar5 = (int *)(uint)*(byte *)(puVar1 + 5);
        FUN_1000_3f0f(*puVar1,puVar1[1],piVar5,
                      *(int *)*(undefined2 *)((uint)*pbVar6 * 2 + -0x7b88) * 8 + -0x7e72,puVar1);
        puVar1[4] = 0;
        pbVar6 = pbVar6 + 1;
      }
      else {
        uVar2 = FUN_1000_3ac2();
        FUN_1000_3b3a(uVar2,*puVar4,uVar2,uVar2);
        piVar5 = (int *)(uint)*(byte *)(puVar1 + 5);
        FUN_1000_3f0f(*puVar1,puVar1[1],piVar5,uVar2,puVar1);
        puVar1[4] = 1;
      }
      if (*piVar5 == -1) {
        piVar5 = (int *)0x0;
      }
      *param_1 = (int)piVar5;
      param_1[6] = (int)pbVar6;
      uVar2 = 0;
    }
  }
  return uVar2;
}



/* ---- FUN_1000_772d @ 1000:772d ---- */

undefined2 FUN_1000_772d()

{
  int param_1 = 0;
  byte bVar1;
  undefined1 *puVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  if (*(char *)(param_1 + 2) == '\0') {
    if (*(int *)0xef6 == 0) {
      while ((bVar1 = *(byte *)*(undefined2 *)(param_1 + 4), 0x7f < bVar1 && (bVar1 != 0xff))) {
        FUN_1000_c83a(bVar1 & 0xf,*(undefined1 *)(*(int *)(param_1 + 6) + 10),
                      *(byte *)(*(int *)(param_1 + 4) + 1) - 0x40);
        *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 2;
      }
      if (*(char *)*(undefined2 *)(param_1 + 4) == -1) {
        *(undefined1 *)(param_1 + 2) = 0;
      }
      else {
        puVar2 = (undefined1 *)*(undefined2 *)(param_1 + 4);
        *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
        *(undefined1 *)(param_1 + 2) = *puVar2;
      }
    }
    else {
      *(undefined1 *)(param_1 + 2) = 0;
    }
    uVar3 = 1;
  }
  else {
    *(char *)(param_1 + 2) = *(char *)(param_1 + 2) + -1;
    uVar3 = 0;
  }
  return uVar3;
}



/* ---- FUN_1000_77af @ 1000:77af ---- */

void FUN_1000_77af(uint *param_1)

{
  byte bVar1;
  uint uVar2;
  undefined2 unaff_DS;
  uint local_14;
  uint local_12;
  undefined2 local_10;
  uint local_e;
  uint local_c;
  uint local_a;
  uint *puStack_8;
  
  FUN_1000_ecaa();
  if ((param_1[2] != 0) && ((byte)param_1[3] == 1)) {
    local_14 = *param_1;
    local_12 = param_1[1];
    local_10 = 0;
    local_e = (uint)(byte)param_1[3];
    puStack_8 = &local_14;
    local_a = 0x77ea;
    FUN_1000_77af(0);
    if ((*param_1 & 7) == 6) {
      local_14 = (uint)((byte)*param_1 & 0xf0 | 5);
      local_12 = (uint)((byte)param_1[1] & 0xf0 | 7);
    }
    else {
      local_14 = (uint)((byte)*param_1 & 0xf0 | 3);
      local_12 = param_1[1] & 0xf0;
    }
    local_e = 3;
    local_10 = 0;
    param_1 = &local_14;
  }
  local_c = CONCAT11((*(unsigned char *)((char *)&local_c + 1)),(byte)((int)param_1[1] >> 1) & 0x38 ^ 0x38 | (byte)param_1[1] & 7
                    );
  uVar2 = (uint)(byte)((byte)((int)*param_1 >> 1) & 0x38 ^ 0x38 | (byte)*param_1 & 7);
  if (*(char *)(uVar2 + 0x1166) != '\0') {
    puStack_8 = (uint *)((uint)*(byte *)(uVar2 + 0x8aa4) * 0x1c + 0x5e0);
    local_a = 0x786e;
    FUN_1000_3f49((undefined2*)0);
  }
  puStack_8 = (uint *)((uint)*(byte *)((local_c & 0xff) + 0x8aa4) * 0x1c + 0x5e0);
  local_a = 0x7883;
  FUN_1000_3f49((undefined2*)0);
  puStack_8 = (uint *)(local_a & 0xff);
  local_a = (uint)*(byte *)((local_c & 0xff) + 0x8aa4);
  local_c = *(byte *)((local_c & 0xff) + 0x1166) & 0x40;
  local_e = (uint)*(byte *)((byte)param_1[3] + 0xf00);
  local_10 = 0x78ad;
  FUN_1000_7aa7();
  *(undefined1 *)((local_c & 0xff) + 0x1166) = 0;
  if ((param_1[2] != 0) && ((byte)param_1[3] == 6)) {
    bVar1 = (byte)local_c & 0x38 | (byte)local_a & 7;
    local_c = CONCAT11((*(unsigned char *)((char *)&local_c + 1)),bVar1);
    puStack_8 = (uint *)((uint)*(byte *)(bVar1 + 0x8aa4) * 0x1c + 0x5e0);
    local_a = 0x78e4;
    FUN_1000_3f49((undefined2*)0);
    *(undefined1 *)((local_c & 0xff) + 0x1166) = 0;
  }
  return;
}



/* ---- FUN_1000_78f6 @ 1000:78f6 ---- */

void FUN_1000_78f6(uint *param_1)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  undefined2 unaff_DS;
  uint local_16;
  uint local_14;
  undefined2 local_12;
  undefined2 local_10;
  uint local_e;
  uint local_c;
  uint uStack_a;
  uint *local_8;
  
  FUN_1000_ecaa();
  bVar2 = 0;
  local_c = CONCAT11((*(unsigned char *)((char *)&local_c + 1)),(byte)((int)param_1[1] >> 1) & 0x38 ^ 0x38 | (byte)param_1[1] & 7
                    );
  bVar1 = (byte)((int)*param_1 >> 1) & 0x38 ^ 0x38 | (byte)*param_1 & 7;
  local_e = CONCAT11((*(unsigned char *)((char *)&local_e + 1)),bVar1);
  local_8 = (uint *)((uint)*(byte *)(bVar1 + 0x8aa4) * 0x1c + 0x5e0);
  uStack_a = 0x793f;
  FUN_1000_3f49((undefined2*)0);
  if (((param_1[2] != 0) && ((byte)param_1[3] != 6)) && ((byte)param_1[3] != 1)) {
    pbVar3 = (byte *)((local_e & 0xff) + 0x1166);
    *pbVar3 = *pbVar3 & 0x78 | 4;
  }
  local_8 = (uint *)(local_c & 0xff);
  uStack_a = (uint)*(byte *)((local_e & 0xff) + 0x8aa4);
  local_c = local_c & 0xff;
  local_e = *(byte *)((local_e & 0xff) + 0x1166) & 7;
  local_10 = 0x798f;
  FUN_1000_7aa7();
  *(undefined1 *)((local_e & 0xff) + 0x1166) = 0;
  if ((param_1[2] != 0) && ((byte)param_1[3] == 6)) {
    bVar2 = 4;
    local_e = CONCAT11((*(unsigned char *)((char *)&local_e + 1)),(byte)local_e & 7 | (byte)local_c & 0x38);
  }
  if (*(byte *)((int)param_1 + 7) != 0) {
    bVar2 = *(byte *)(*(byte *)((int)param_1 + 7) + 0xf00);
  }
  if (bVar2 != 0) {
    bVar1 = 0;
    while ((bVar1 < 0x20 && (*(int *)((uint)bVar1 * 0x1c + 0x5f4) != 0))) {
      bVar1 = bVar1 + 1;
    }
    local_8 = (uint *)(local_e & 0xff);
    uStack_a = (uint)bVar1;
    local_c = local_e & 0xff ^ 0x40;
    local_e = (uint)bVar2;
    local_10 = 0x7a09;
    FUN_1000_7aa7();
  }
  if ((param_1[2] != 0) && ((byte)param_1[3] == 1)) {
    local_10 = CONCAT11((*(unsigned char *)((char *)&local_10 + 1)),3);
    local_12 = 0;
    if ((*param_1 & 7) == 6) {
      local_16 = (uint)((byte)*param_1 & 0xf0 | 7);
      bVar2 = (byte)*param_1 & 0xf0 | 5;
    }
    else {
      local_16 = *param_1 & 0xf0;
      bVar2 = (byte)*param_1 & 0xf0 | 3;
    }
    local_14 = (uint)bVar2;
    local_8 = &local_16;
    uStack_a = 0x7a58;
    FUN_1000_77af(0);
  }
  return;
}



/* ---- FUN_1000_7a61 @ 1000:7a61 ---- */

void FUN_1000_7a61(uint param_1,int param_2)

{
  uint uVar1;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  uVar1 = (uint)((byte)((int)param_1 >> 1) & 0x38 ^ 0x38) | param_1 & 7;
  FUN_1000_7aa7(*(undefined1 *)(param_2 + 0xf00),*(byte *)(uVar1 + 0x1166) & 0x40,
                *(undefined1 *)(uVar1 + 0x8aa4),uVar1);
  return;
}



/* ---- FUN_1000_7aa7 @ 1000:7aa7 ---- */

void FUN_1000_7aa7()

{
  uint param_1 = 0; int param_2 = 0; int param_3 = 0; int param_4 = 0;
  int iVar1;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  if (param_1 == 6) {
    if (((byte)param_4 & 7) < 4) {
      iVar1 = 3;
    }
    else {
      iVar1 = 7;
    }
  }
  else if (param_1 == 1) {
    if (((byte)param_4 & 7) < 4) {
      if (param_2 == 0) {
        iVar1 = 3;
      }
      else {
        iVar1 = 1;
      }
    }
    else if (param_2 == 0) {
      iVar1 = 5;
    }
    else {
      iVar1 = 7;
    }
  }
  else if (param_2 == 0) {
    iVar1 = 4;
  }
  else {
    iVar1 = 0;
  }
  *(byte *)(param_4 + 0x1166) = (char)iVar1 << 3 | (byte)param_2 | (byte)param_1;
  *(undefined1 *)(param_4 + -0x755c) = (undefined1)param_3;
  *(byte *)(param_3 * 0x1c + 0x5eb) = (byte)param_4;
  FUN_1000_3f0f(*(undefined2 *)(param_4 * 2 + *(int *)0xb0c6),
                *(undefined2 *)((param_4 >> 3) * 2 + *(int *)0xb0c8),param_2,
                (uint)*(byte *)((iVar1 << 3 | param_1) + *(int *)0x9890) * 8 + -0x7e72,
                param_3 * 0x1c + 0x5e0);
  return;
}



/* ---- FUN_1000_7b86 @ 1000:7b86 ---- */

void FUN_1000_7b86()

{
  undefined2 unaff_DS;
  
  FUN_1000_8a96(0x85a4,0x400,0);
  FUN_1000_7bc2();
  FUN_1000_7c99();
  *(undefined2 *)0x9856 = 0;
  return;
}



/* ---- FUN_1000_7ba4 @ 1000:7ba4 ---- */

void FUN_1000_7ba4()

{
  int iVar1;
  undefined2 unaff_DS;
  
  iVar1 = *(int *)0x57cc;
  if (iVar1 == 0) {
    FUN_1000_7ddb();
    return;
  }
  if (iVar1 != 1) {
    if (iVar1 != 2) {
      return;
    }
    FUN_1000_801a();
    return;
  }
  FUN_1000_7e6b();
  return;
}



/* ---- FUN_1000_7bc2 @ 1000:7bc2 ---- */

void FUN_1000_7bc2()

{
  undefined2 unaff_DS;
  
  FUN_1000_9840();
  *(undefined2 *)0x53e = 1;
  *(undefined2 *)0x8176 = 1;
  FUN_1000_2a1a();
  FUN_1000_3e4f();
  FUN_1000_6cb4();
  FUN_1000_82a5();
  if (*(int *)0xef6 == 0) {
    FUN_1000_35a0(3);
    FUN_1000_35a0(2);
  }
  return;
}



/* ---- FUN_1000_7bf9 @ 1000:7bf9 ---- */

void FUN_1000_7bf9()

{
  int iVar1;
  int iVar2;
  undefined2 unaff_DS;
  undefined2 local_4;
  
  for (local_4 = *(int *)0x9880; -0x69 < local_4; local_4 = local_4 + -1) {
    iVar1 = (local_4 - *(int *)0x9880) * 8;
    iVar2 = local_4 * 8;
    *(undefined2 *)(iVar1 + -0x7724) = *(undefined2 *)(iVar2 + -0x771c);
    *(undefined2 *)(iVar1 + -0x7722) = *(undefined2 *)(iVar2 + -0x771a);
    *(undefined2 *)(iVar1 + -0x7720) = *(undefined2 *)(iVar2 + -0x7718);
    *(undefined2 *)(iVar1 + -0x771e) = *(undefined2 *)(iVar2 + -0x7716);
  }
  *(undefined2 *)0x9880 = 0xffff;
  *(undefined2 *)0x85a4 = *(undefined2 *)0x4e2;
  *(undefined2 *)0x85a6 = *(undefined2 *)0x4e4;
  *(undefined2 *)0x85a8 = *(undefined2 *)0x4e6;
  *(undefined2 *)0x85aa = *(undefined2 *)0x4e8;
  *(undefined2 *)0x88e4 = *(undefined2 *)0x4e2;
  *(undefined2 *)0x88e6 = *(undefined2 *)0x4e4;
  *(undefined2 *)0x88e8 = *(undefined2 *)0x4e6;
  *(undefined2 *)0x88ea = *(undefined2 *)0x4e8;
  return;
}



/* ---- FUN_1000_7c52 @ 1000:7c52 ---- */

void FUN_1000_7c52()

{
  int iVar1;
  undefined2 unaff_DS;
  undefined2 local_4;
  
  *(int *)0x9880 = *(int *)0x9880 + -1;
  for (local_4 = -0x68; local_4 <= *(int *)0x9880; local_4 = local_4 + 1) {
    iVar1 = local_4 * 8;
    *(undefined2 *)(iVar1 + -0x771c) = *(undefined2 *)(iVar1 + -0x7714);
    *(undefined2 *)(iVar1 + -0x771a) = *(undefined2 *)(iVar1 + -0x7712);
    *(undefined2 *)(iVar1 + -0x7718) = *(undefined2 *)(iVar1 + -0x7710);
    *(undefined2 *)(iVar1 + -0x7716) = *(undefined2 *)(iVar1 + -0x770e);
  }
  *(undefined2 *)0x85a4 = *(undefined2 *)0x4e2;
  *(undefined2 *)0x85a6 = *(undefined2 *)0x4e4;
  *(undefined2 *)0x85a8 = *(undefined2 *)0x4e6;
  *(undefined2 *)0x85aa = *(undefined2 *)0x4e8;
  return;
}



/* ---- FUN_1000_7c99 @ 1000:7c99 ---- */

void FUN_1000_7c99()

{
  int iVar1;
  undefined2 unaff_DS;
  
  *(undefined2 *)0x9844 = 0;
  *(undefined2 *)0x8fde = 0;
  *(undefined2 *)0x9646 = 0x17;
  FUN_1000_7d26();
  FUN_1000_7da8();
  if (*(char *)0x0 == '\0') {
    *(undefined2 *)0x8fde = 0;
  }
  else {
    *(undefined2 *)0x8fde = 200;
  }
  *(undefined2 *)0x8fda = 0;
  *(undefined2 *)0x8fdc = 0;
  *(undefined2 *)0x8fd6 = 0;
  *(undefined2 *)0x8fd8 = 0;
  *(undefined1 *)0x88e3 = 1;
  *(undefined2 *)0x57c8 = 0;
  *(undefined2 *)0x984c = 0;
  FUN_1000_8a96(0xb0dc,0xb40,0);
  iVar1 = *(int *)(*(int *)0x9846 * 2 + 0x53c);
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      *(undefined2 *)0x57cc = 2;
      goto LAB_1000_7d1c;
    }
    if (iVar1 != 2) goto LAB_1000_7d1c;
  }
  *(undefined2 *)0x57cc = 0;
LAB_1000_7d1c:
  *(undefined2 *)0x934a = 0;
  FUN_1000_0865();
  return;
}



/* ---- FUN_1000_7d26 @ 1000:7d26 ---- */

void FUN_1000_7d26()

{
  undefined2 unaff_DS;
  undefined2 local_4;
  
  FUN_1000_946f();
  local_4 = 0;
  do {
    FUN_1000_7dbf(*(undefined2 *)(local_4 * 2 + 0x52a),0,local_4);
    FUN_1000_7dbf(6,0,local_4 + 0x10);
    FUN_1000_7dbf(6,1,local_4 + 0x60);
    FUN_1000_7dbf(*(undefined2 *)(local_4 * 2 + 0x52a),1,local_4 + 0x70);
    local_4 = local_4 + 1;
  } while (local_4 < 8);
  FUN_1000_950d();
  *(undefined2 *)0x9846 = 0;
  *(undefined2 *)0xa836 = 1;
  return;
}



/* ---- FUN_1000_7da8 @ 1000:7da8 ---- */

void FUN_1000_7da8()

{
  undefined2 unaff_DS;
  
  *(undefined2 *)0x9880 = 0xffff;
  *(undefined2 *)0x88dc = *(undefined2 *)0x4e2;
  *(undefined2 *)0x88de = *(undefined2 *)0x4e4;
  *(undefined2 *)0x88e0 = *(undefined2 *)0x4e6;
  *(undefined2 *)0x88e2 = *(undefined2 *)0x4e8;
  return;
}



/* ---- FUN_1000_7dbf @ 1000:7dbf ---- */

void FUN_1000_7dbf(undefined1 param_1,undefined1 param_2,int param_3)

{
  undefined2 unaff_DS;
  
  *(undefined1 *)(param_3 * 4 + -0x5746) = param_1;
  *(undefined1 *)(param_3 * 4 + -0x5745) = param_2;
  return;
}



/* ---- FUN_1000_7ddb @ 1000:7ddb ---- */

void FUN_1000_7ddb()

{
  undefined1 uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  
  *(undefined2 *)0xcbd2 = 0;
  *(undefined2 *)0x934c = 0;
  iVar2 = FUN_1000_8fca();
  if (iVar2 == 0) {
    FUN_1000_900a();
  }
  else {
    uVar1 = FUN_1000_9a50(*(undefined2 *)0xa836,*(undefined1 *)(*(int *)0x9846 * 0x20 + -0x69fc));
    *(undefined1 *)0x8f44 = uVar1;
    *(undefined2 *)0xeee = 1;
    func_0x0000fce8(0x1000,*(undefined2 *)0x9846);
    do {
      FUN_1000_8aaa();
      if (*(int *)0x9856 == 0) {
        uVar3 = FUN_1000_0254();
        *(undefined2 *)0x9856 = uVar3;
      }
      if (*(int *)0x9856 != 0) {
        FUN_1000_872a();
      }
      iVar2 = FUN_1000_083e();
      if (iVar2 != 0) {
        FUN_1000_8d73(iVar2,iVar2);
        return;
      }
    } while (*(int *)0x9856 == 0);
    *(undefined2 *)0xeee = 0;
    *(undefined2 *)0x57cc = 1;
  }
  return;
}



/* ---- FUN_1000_7e6b @ 1000:7e6b ---- */

void FUN_1000_7e6b()

{
  undefined1 uVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  *(undefined2 *)0x57cc = 0;
  switch(*(undefined1 *)0x9856) {
  case 1:
    iVar2 = FUN_1000_1296(0x4da8,0xc,1);
    if (iVar2 == 0x1003) {
      FUN_1000_7c99();
      FUN_1000_df71();
    }
    break;
  case 2:
    if (*(int *)(*(int *)0x9846 * 2 + 0x53c) == 1) {
      *(undefined2 *)0x57cc = 2;
    }
    break;
  case 4:
    iVar2 = *(int *)0x9880 * 8;
    if (*(char *)(iVar2 + -0x7716) != '\0') {
      FUN_1000_86a1(*(undefined2 *)(iVar2 + -0x771c),*(undefined2 *)(iVar2 + -0x771a),
                    *(undefined2 *)(iVar2 + -0x7718),*(undefined2 *)(iVar2 + -0x7716));
      FUN_1000_78f6(*(int *)0x9880 * 8 + -0x7714);
    }
    break;
  case 5:
    iVar2 = *(int *)0x9880 * 8;
    if ((*(char *)(iVar2 + -0x770e) != '\0') && (*(int *)0x9880 < -1)) {
      FUN_1000_866d(*(undefined2 *)(iVar2 + -0x7714),*(undefined2 *)(iVar2 + -0x7712),
                    *(undefined2 *)(iVar2 + -0x7710),*(undefined2 *)(iVar2 + -0x770e));
      FUN_1000_77af(*(int *)0x9880 * 8 + -0x771c);
    }
    break;
  case 6:
    FUN_1000_8ca1();
    FUN_1000_7bf9();
    FUN_1000_8632();
    FUN_1000_7c52();
    *(undefined2 *)0x88ec = *(undefined2 *)0x4e2;
    *(undefined2 *)0x88ee = *(undefined2 *)0x4e4;
    *(undefined2 *)0x88f0 = *(undefined2 *)0x4e6;
    *(undefined2 *)0x88f2 = *(undefined2 *)0x4e8;
    *(undefined2 *)0x9856 = 0;
    iVar2 = FUN_1000_9371();
    if (iVar2 == 0) {
      iVar2 = FUN_1000_bb0e(*(undefined2 *)0x88dc,*(undefined2 *)0x88de,*(undefined2 *)0x88e0,
                            *(undefined2 *)0x88e2,0);
      if (iVar2 != 0) {
        *(int *)0x9856 = iVar2;
      }
    }
    else {
      uVar1 = FUN_1000_1596(*(undefined2 *)0xa836);
      *(undefined1 *)0x88e2 = uVar1;
      FUN_1000_93d6();
    }
    if (*(int *)(*(int *)0x9846 * 2 + 0x53c) == 1) {
      *(undefined2 *)0x57cc = 2;
      goto LAB_1000_8011;
    }
    goto LAB_1000_7fc0;
  case 0xb:
    FUN_1000_893c();
    break;
  case 0xe:
    FUN_1000_cc72();
    break;
  case 0xf:
    FUN_1000_ced4();
    break;
  case 0x12:
    FUN_1000_08de();
    FUN_1000_7da8();
    *(undefined2 *)0x9856 = 0;
    if (*(int *)(*(int *)0x9846 * 2 + 0x53c) == 1) {
      *(undefined2 *)0x9856 = 2;
      goto LAB_1000_8011;
    }
LAB_1000_7fc0:
    iVar2 = FUN_1000_8fca();
    if (iVar2 == 0) {
      FUN_1000_900a();
    }
    goto LAB_1000_8011;
  }
  *(undefined2 *)0x9856 = 0;
LAB_1000_8011:
  FUN_1000_8aaa();
  return;
}



/* ---- FUN_1000_801a @ 1000:801a ---- */

void FUN_1000_801a()

{
  int iVar1;
  undefined2 unaff_DS;
  
  *(undefined2 *)0x934a = 0;
  do {
    *(undefined2 *)0xeee = 0;
    iVar1 = *(int *)0x934a;
    if (iVar1 == 0) {
      FUN_1000_8061();
    }
    else if (iVar1 == 1) {
      FUN_1000_810c();
    }
    else if (iVar1 == 2) {
      FUN_1000_82a4();
    }
  } while ((*(int *)0x57cc == 2) && (*(int *)(*(int *)0x9846 * 2 + 0x53c) == 1));
  *(undefined2 *)0x57cc = 0;
  return;
}



/* ---- FUN_1000_8061 @ 1000:8061 ---- */

void FUN_1000_8061()

{
  undefined2 unaff_DS;
  undefined2 uVar1;
  
  FUN_1000_85c5();
  FUN_1000_8a64();
  FUN_1000_7bf9();
  if (*(int *)0x53a != 0) {
    FUN_1000_8384();
  }
  *(undefined2 *)0x9880 = 0;
  *(undefined2 *)0xeee = 0;
  if (*(int *)0x53a == 0) {
    *(undefined2 *)0x9844 = 0;
    uVar1 = 2;
  }
  else {
    if (0 < *(int *)0xb0d2) {
      *(undefined1 *)0x95fa = 1;
      FUN_1000_17f9(3);
      *(undefined2 *)0x9844 = 1;
      FUN_1000_82db();
      *(undefined1 *)0x95fa = 0;
      if (*(int *)0x53c == *(int *)0x53e) {
        if (*(int *)0x9856 == 0) {
          uVar1 = FUN_1000_0254();
          *(undefined2 *)0x9856 = uVar1;
        }
        if (*(int *)0x9856 != 0) {
          FUN_1000_872a();
        }
      }
      goto LAB_1000_80f5;
    }
    *(undefined2 *)0x9844 = 0;
    uVar1 = *(undefined2 *)0x9646;
  }
  FUN_1000_a528(uVar1);
LAB_1000_80f5:
  *(undefined2 *)0x9880 = 0xffff;
  *(undefined2 *)0x934a = 1;
  FUN_1000_85fd(*(undefined2 *)0x57c8);
  return;
}



/* ---- FUN_1000_810c @ 1000:810c ---- */

void FUN_1000_810c()

{
  undefined2 uVar1;
  int iVar2;
  undefined2 unaff_DS;
  undefined2 uVar3;
  
  *(undefined2 *)0x88e4 = *(undefined2 *)0x8bae;
  *(undefined2 *)0x88e6 = *(undefined2 *)0x8bb0;
  *(undefined2 *)0x88e8 = *(undefined2 *)0x8bb2;
  *(undefined2 *)0x88ea = *(undefined2 *)0x8bb4;
  *(undefined2 *)0x927a = *(undefined2 *)0x4e2;
  *(undefined2 *)0x927c = *(undefined2 *)0x4e4;
  *(undefined2 *)0x927e = *(undefined2 *)0x4e6;
  *(undefined2 *)0x9280 = *(undefined2 *)0x4e8;
  *(undefined2 *)0x88ec = *(undefined2 *)0x4e2;
  *(undefined2 *)0x88ee = *(undefined2 *)0x4e4;
  *(undefined2 *)0x88f0 = *(undefined2 *)0x4e6;
  *(undefined2 *)0x88f2 = *(undefined2 *)0x4e8;
  if (*(char *)0x88ea == '\0') {
    *(undefined2 *)0x927a = *(undefined2 *)0x4e2;
    *(undefined2 *)0x927c = *(undefined2 *)0x4e4;
    *(undefined2 *)0x927e = *(undefined2 *)0x4e6;
    *(undefined2 *)0x9280 = *(undefined2 *)0x4e8;
    if (*(int *)0x53c == *(int *)0x53e) {
      FUN_1000_900a();
      *(undefined2 *)0x934a = 0;
      return;
    }
    if (*(char *)0x88e2 == '\0') {
      FUN_1000_7c99();
      *(undefined2 *)0x57cc = 0;
      return;
    }
  }
  else {
    iVar2 = *(int *)0x9880 * 8;
    FUN_1000_861b(*(undefined2 *)(iVar2 + -0x7714),*(undefined2 *)(iVar2 + -0x7712),
                  *(undefined2 *)(iVar2 + -0x7710),*(undefined2 *)(iVar2 + -0x770e));
    FUN_1000_7c52();
    if (*(int *)0x53c == *(int *)0x53e) {
      if ((((0x77 < *(int *)0x984c) || (FUN_1000_9bfd(), 99 < iVar2)) ||
          (iVar2 = FUN_1000_9c34(0), 2 < iVar2)) || (*(int *)0x8de0 < -0x87f)) {
        if (*(int *)0x9846 == 0) {
          FUN_1000_1296(0x4dc0,0xc,0);
          FUN_1000_df71();
          uVar3 = 0xd;
          uVar1 = 0x4dcd;
        }
        else {
          FUN_1000_1296(0x4ddb,0xc,0);
          FUN_1000_df71();
          uVar3 = 0xc;
          uVar1 = 0x4de7;
        }
        FUN_1000_dbb5(uVar1,uVar3);
        FUN_1000_1446();
        FUN_1000_7c99();
        return;
      }
      *(undefined2 *)0x934a = 0;
      iVar2 = FUN_1000_9371();
      if (iVar2 != 0) {
        FUN_1000_93d6();
        return;
      }
      iVar2 = FUN_1000_bb0e(*(undefined2 *)0x88e4,*(undefined2 *)0x88e6,*(undefined2 *)0x88e8,
                            *(undefined2 *)0x88ea,0);
      if (iVar2 == 0) {
        return;
      }
      *(int *)0x9856 = iVar2;
      return;
    }
    *(undefined2 *)0x934a = 2;
    iVar2 = FUN_1000_9371();
    if (iVar2 == 0) {
      iVar2 = FUN_1000_bb0e(*(undefined2 *)0x88e4,*(undefined2 *)0x88e6,*(undefined2 *)0x88e8,
                            *(undefined2 *)0x88ea,0);
      if (iVar2 != 0) {
        *(int *)0x9856 = iVar2;
      }
    }
    else {
      FUN_1000_93d6();
    }
    iVar2 = FUN_1000_8fca();
    if (iVar2 != 0) {
      return;
    }
  }
  FUN_1000_900a();
  return;
}



/* ---- FUN_1000_82a4 @ 1000:82a4 ---- */

void FUN_1000_82a4()

{
  return;
}



/* ---- FUN_1000_82a5 @ 1000:82a5 ---- */

void FUN_1000_82a5()

{
  int iVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  
  FUN_1000_ca56(0);
  uVar2 = (undefined2)((ulong)*(undefined4 *)0x9648 >> 0x10);
  iVar1 = (int)*(undefined4 *)0x9648;
  FUN_1000_cb5b(*(undefined2 *)(iVar1 + 8),*(undefined2 *)(iVar1 + 10));
  uVar2 = (undefined2)((ulong)*(undefined4 *)0xa8b6 >> 0x10);
  iVar1 = (int)*(undefined4 *)0xa8b6;
  FUN_1000_cb8f(0,0x1f09,*(undefined2 *)(iVar1 + 8),*(undefined2 *)(iVar1 + 10));
  return;
}



/* ---- FUN_1000_82db @ 1000:82db ---- */

void FUN_1000_82db()

{
  byte bVar1;
  undefined2 unaff_DS;
  int local_a;
  int local_8;
  int local_4;
  
  FUN_1000_1ef0(0x1000);
  bVar1 = FUN_1000_f2f0();
  for (local_4 = 0; *(char *)(local_4 + 0x540) <= (char)(bVar1 & 0xf); local_4 = local_4 + 1) {
  }
  for (local_a = 1; local_a <= local_4; local_a = local_a + 1) {
    FUN_1000_8515(1);
  }
  *(uint *)0x8cfe = *(byte *)*(undefined2 *)0xb0d2 & 0x3f;
  FUN_1000_a348();
  for (local_8 = 0; local_8 <= *(int *)0x8cfe; local_8 = local_8 + 1) {
    FUN_1000_a4d4();
  }
  *(undefined2 *)0x8bae = *(undefined2 *)0x8d12;
  *(undefined2 *)0x8bb0 = *(undefined2 *)0x8d14;
  *(undefined2 *)0x8bb2 = *(undefined2 *)0x8d16;
  *(undefined2 *)0x8bb4 = *(undefined2 *)0x8d18;
  *(undefined2 *)0x8bb6 = *(undefined2 *)0x4e2;
  *(undefined2 *)0x8bb8 = *(undefined2 *)0x4e4;
  *(undefined2 *)0x8bba = *(undefined2 *)0x4e6;
  *(undefined2 *)0x8bbc = *(undefined2 *)0x4e8;
  *(undefined2 *)0x8de0 = 0;
  *(undefined2 *)0x8de8 = 0;
  *(undefined2 *)0x9854 = 0;
  FUN_1000_1f0e(0x11ef);
  return;
}



/* ---- FUN_1000_8384 @ 1000:8384 ---- */

void FUN_1000_8384()

{
  int iVar1;
  undefined2 unaff_DS;
  
  *(undefined1 *)0x95fa = 1;
  FUN_1000_17f9(3);
  FUN_1000_7bf9();
  *(undefined2 *)0xb0d2 = 0;
  if (*(int *)0x984c < *(int *)0x8fde) {
    *(undefined2 *)0x9366 = *(undefined2 *)0x9880;
    while (iVar1 = *(int *)0x9880 * 8, *(char *)(iVar1 + -0x7716) != '\0') {
      FUN_1000_86a1(*(undefined2 *)(iVar1 + -0x771c),*(undefined2 *)(iVar1 + -0x771a),
                    *(undefined2 *)(iVar1 + -0x7718),*(undefined2 *)(iVar1 + -0x7716));
    }
    *(undefined2 *)0xb0cc = 0;
    if (*(char *)(*(int *)0x9880 * 8 + -0x7715) == '\x01') {
      *(int *)0x9880 = *(int *)0x9880 + 1;
      FUN_1000_843f();
      *(int *)0x9880 = *(int *)0x9880 + -1;
    }
    while (*(int *)0x9880 < *(int *)0x9366) {
      iVar1 = *(int *)0x9880 * 8;
      FUN_1000_866d(*(undefined2 *)(iVar1 + -0x7714),*(undefined2 *)(iVar1 + -0x7712),
                    *(undefined2 *)(iVar1 + -0x7710),*(undefined2 *)(iVar1 + -0x770e));
    }
    if (*(int *)0xb0cc == 0) {
      *(undefined2 *)0x8fde = *(undefined2 *)0x984c;
      *(undefined2 *)0xb0d2 = 0;
    }
    else {
      *(undefined2 *)0x8fde = 200;
    }
  }
  *(undefined1 *)0x95fa = 0;
  return;
}



/* ---- FUN_1000_843f @ 1000:843f ---- */

void FUN_1000_843f()

{
  int iVar1;
  byte *pbVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  
  *(int *)0xb0d2 = *(int *)0xb0d2 + 1;
  if (*(int *)0x9366 < *(int *)0x9880) {
    *(undefined2 *)0xb0cc = 1;
    return;
  }
  *(undefined2 *)0x8cfe = 0xffff;
  FUN_1000_a348();
  do {
    *(int *)0x8cfe = *(int *)0x8cfe + 1;
    FUN_1000_a4d4();
    if (*(char *)0x8d18 == '\0') break;
    iVar1 = FUN_1000_9448(0x8d12,*(int *)0x9880 * 8 + -0x771c);
  } while (iVar1 == 0);
  if (*(char *)0x8d18 != '\0') {
    while( true ) {
      pbVar2 = (byte *)*(undefined2 *)0xb0d2;
      uVar3 = *(undefined2 *)0x4da6;
      if ((*pbVar2 & 0x3f) == *(uint *)0x8cfe) break;
      pbVar2 = (byte *)*(undefined2 *)0xb0d2;
      uVar3 = *(undefined2 *)0x4da6;
      if (0x7f < *pbVar2) break;
      FUN_1000_8515(0);
    }
    if ((*pbVar2 & 0x7f) == *(int *)0x8cfe + 0x40U) {
      iVar1 = *(int *)0x9880 * 8;
      FUN_1000_866d(*(undefined2 *)(iVar1 + -0x771c),*(undefined2 *)(iVar1 + -0x771a),
                    *(undefined2 *)(iVar1 + -0x7718),*(undefined2 *)(iVar1 + -0x7716));
      FUN_1000_843f();
      iVar1 = *(int *)0x9880 * 8;
      FUN_1000_86a1(*(undefined2 *)(iVar1 + -0x7724),*(undefined2 *)(iVar1 + -0x7722),
                    *(undefined2 *)(iVar1 + -0x7720),*(undefined2 *)(iVar1 + -0x771e));
    }
  }
  return;
}



/* ---- FUN_1000_8515 @ 1000:8515 ---- */

void FUN_1000_8515(byte param_1)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  int local_4;
  
  if (*(byte *)*(undefined2 *)0xb0d2 < 0x80) {
    local_4 = 0;
    do {
      uVar1 = *(undefined2 *)0x4da6;
      if ((*(byte *)*(undefined2 *)0xb0d2 & 0x40) != 0) {
        local_4 = local_4 + 1;
      }
      if (0x7f < *(byte *)*(undefined2 *)0xb0d2) {
        local_4 = local_4 + -1;
      }
      *(int *)0xb0d2 = *(int *)0xb0d2 + 1;
    } while (local_4 != 0);
    if ((param_1 & *(char *)*(undefined2 *)0xb0d2 == '?') == 0) {
      return;
    }
  }
  thunk_FUN_1000_857c();
  return;
}



/* ---- thunk_FUN_1000_857c @ 1000:8577 ---- */

void thunk_FUN_1000_857c()

{
  undefined2 unaff_DS;
  
  while ((*(byte *)(*(int *)0xb0d2 + -1) & 0x40) == 0) {
    FUN_1000_858d();
  }
  return;
}



/* ---- FUN_1000_857c @ 1000:857c ---- */

void FUN_1000_857c()

{
  undefined2 unaff_DS;
  
  while ((*(byte *)(*(int *)0xb0d2 + -1) & 0x40) == 0) {
    FUN_1000_858d();
  }
  return;
}



/* ---- FUN_1000_858d @ 1000:858d ---- */

void FUN_1000_858d()

{
  undefined2 unaff_DS;
  undefined2 local_4;
  
  local_4 = 0;
  do {
    *(int *)0xb0d2 = *(int *)0xb0d2 + -1;
    if (0x7f < *(byte *)*(undefined2 *)0xb0d2) {
      local_4 = local_4 + 1;
    }
    if ((*(byte *)*(undefined2 *)0xb0d2 & 0x40) != 0) {
      local_4 = local_4 + -1;
    }
  } while (local_4 != 0);
  return;
}



/* ---- FUN_1000_85c4 @ 1000:85c4 ---- */

void FUN_1000_85c4()

{
  return;
}



/* ---- FUN_1000_85c5 @ 1000:85c5 ---- */

void FUN_1000_85c5()

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  undefined4 uVar2;
  
  FUN_1000_f204(0);
  uVar1 = (undefined2)((ulong)uVar2 >> 0x10);
  *(undefined2 *)0xcbbe = (int)uVar2;
  *(undefined2 *)0xcbc0 = uVar1;
  *(undefined2 *)0xcbc2 = (int)uVar2;
  *(undefined2 *)0xcbc4 = uVar1;
  return;
}



/* ---- FUN_1000_85dd @ 1000:85dd ---- */

void FUN_1000_85dd()

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined2 unaff_DS;
  undefined4 uVar5;
  
  FUN_1000_f204(0);
  iVar4 = (int)((ulong)uVar5 >> 0x10);
  uVar3 = (uint)uVar5;
  *(uint *)0xcbc2 = uVar3;
  *(int *)0xcbc4 = iVar4;
  uVar1 = *(uint *)0xcbbe;
  iVar2 = *(int *)0xcbc0;
  *(int *)0xcbc6 = uVar3 - *(uint *)0xcbbe;
  *(int *)0xcbc8 = (iVar4 - iVar2) - (uint)(uVar3 < uVar1);
  return;
}



/* ---- FUN_1000_85fd @ 1000:85fd ---- */

void FUN_1000_85fd(int param_1)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined2 unaff_DS;
  
  FUN_1000_85dd();
  uVar4 = *(uint *)0xcbc6;
  iVar5 = *(int *)0xcbc8;
  puVar1 = (uint *)(param_1 * 4 + -0x702a);
  uVar3 = *puVar1;
  *puVar1 = *puVar1 + uVar4;
  piVar2 = (int *)(param_1 * 4 + -0x7028);
  *piVar2 = *piVar2 + iVar5 + (uint)CARRY2(uVar3,uVar4);
  return;
}



/* ---- FUN_1000_861b @ 1000:861b ---- */

void FUN_1000_861b(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  FUN_1000_866d(param_1,param_2,param_3,param_4);
  return;
}



/* ---- FUN_1000_8632 @ 1000:8632 ---- */

void FUN_1000_8632()

{
  int iVar1;
  undefined2 unaff_DS;
  
  iVar1 = *(int *)0x9880 * 8;
  *(undefined2 *)(iVar1 + -0x7714) = *(undefined2 *)0xcbca;
  *(undefined2 *)(iVar1 + -0x7712) = *(undefined2 *)0xcbcc;
  *(undefined2 *)(iVar1 + -0x7710) = *(undefined2 *)0xcbce;
  *(undefined2 *)(iVar1 + -0x770e) = *(undefined2 *)0xcbd0;
  *(undefined2 *)0xb0ac = *(undefined2 *)0xcbca;
  *(undefined2 *)0xb0ae = *(undefined2 *)0xcbcc;
  *(undefined2 *)0xb0b0 = *(undefined2 *)0xcbce;
  *(undefined2 *)0xb0b2 = *(undefined2 *)0xcbd0;
  FUN_1000_861b(*(undefined2 *)(iVar1 + -0x7714),*(undefined2 *)(iVar1 + -0x7712),
                *(undefined2 *)(iVar1 + -0x7710),*(undefined2 *)(iVar1 + -0x770e));
  return;
}



/* ---- FUN_1000_866d @ 1000:866d ---- */

void FUN_1000_866d(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  undefined2 unaff_DS;
  
  *(int *)0x9880 = *(int *)0x9880 + 1;
  *(int *)0x984c = *(int *)0x984c + 1;
  FUN_1000_9749(param_1,param_2,param_3,param_4,0);
  *(undefined2 *)0x57c8 = *(undefined2 *)0xa836;
  *(undefined2 *)0xa836 = *(undefined2 *)0x9846;
  *(undefined2 *)0x9846 = *(undefined2 *)0x57c8;
  return;
}



/* ---- FUN_1000_86a1 @ 1000:86a1 ---- */

void FUN_1000_86a1(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  undefined2 unaff_DS;
  
  *(undefined2 *)0x57c8 = *(undefined2 *)0xa836;
  *(undefined2 *)0xa836 = *(undefined2 *)0x9846;
  *(undefined2 *)0x9846 = *(undefined2 *)0x57c8;
  FUN_1000_9749(param_1,param_2,param_3,param_4,1);
  *(int *)0x984c = *(int *)0x984c + -1;
  *(int *)0x9880 = *(int *)0x9880 + -1;
  return;
}



/* ---- FUN_1000_86d6 @ 1000:86d6 ---- */

undefined2 FUN_1000_86d6(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  FUN_1000_9749(param_1,param_2,param_3,param_4,0);
  uVar1 = FUN_1000_9a50(*(undefined2 *)0xa836,*(undefined1 *)(*(int *)0x9846 * 0x20 + -0x69fc));
  FUN_1000_9749(param_1,param_2,param_3,param_4,1);
  return uVar1;
}



/* ---- FUN_1000_872a @ 1000:872a ---- */

void FUN_1000_872a()

{
  int iVar1;
  undefined2 unaff_DS;
  
  if ((*(uint *)0x9856 & 0xf000) != 0) {
    *(undefined2 *)0x9856 = 0;
    return;
  }
  switch(*(undefined1 *)0x9856) {
  case 3:
    FUN_1000_89df();
    break;
  default:
    goto switchD_1000_874c_caseD_4;
  case 7:
    FUN_1000_8835();
    break;
  case 8:
    *(undefined2 *)0x8176 = 1;
    break;
  case 9:
    *(undefined2 *)0x8176 = 0;
    break;
  case 10:
    *(byte *)0x8176 = *(byte *)0x8176 ^ 1;
    break;
  case 0xc:
    if ((*(int *)0x53c == 2) && (*(int *)0x9856 == 0x20c)) {
      FUN_1000_157c();
    }
    iVar1 = *(int *)0x9856;
    *(int *)0x53c = iVar1 >> 8;
    if (iVar1 >> 8 == 2) {
      FUN_1000_1562();
    }
    if (*(int *)0x9846 == 0) {
      iVar1 = *(int *)0x53c;
LAB_1000_8805:
      if (iVar1 == 1) {
        *(undefined2 *)0x9856 = 2;
        goto switchD_1000_874c_caseD_4;
      }
    }
    break;
  case 0xd:
    if ((*(int *)0x53e == 2) && (*(int *)0x9856 == 0x20d)) {
      FUN_1000_157c();
    }
    iVar1 = *(int *)0x9856;
    *(int *)0x53e = iVar1 >> 8;
    if (iVar1 >> 8 == 2) {
      FUN_1000_1562();
    }
    if (*(int *)0x9846 == 1) {
      iVar1 = *(int *)0x53e;
      goto LAB_1000_8805;
    }
    break;
  case 0x10:
    if (*(int *)0xef6 == 0) {
      *(undefined2 *)0xef6 = 1;
LAB_1000_876f:
      FUN_1000_2a1a();
      FUN_1000_3e4f();
      FUN_1000_0865();
    }
    break;
  case 0x11:
    if (*(int *)0xef6 != 0) {
      *(undefined2 *)0xef6 = 0;
      goto LAB_1000_876f;
    }
  }
  *(undefined2 *)0x9856 = 0;
switchD_1000_874c_caseD_4:
  FUN_1000_8aaa();
  return;
}



/* ---- FUN_1000_8834 @ 1000:8834 ---- */

void FUN_1000_8834()

{
  return;
}



/* ---- FUN_1000_8835 @ 1000:8835 ---- */

void FUN_1000_8835()

{
  int iVar1;
  
  iVar1 = FUN_1000_1296(0x4df4,0xc,1);
  if (iVar1 == 0x1003) {
    FUN_1000_07f3(0);
  }
  return;
}



/* ---- FUN_1000_8856 @ 1000:8856 ---- */

int FUN_1000_8856(char param_1,char param_2)

{
  char cVar1;
  undefined2 local_4;
  
  cVar1 = FUN_1000_f1bc((int)param_1);
  if (((('`' < cVar1) && (cVar1 < 'i')) && ('0' < param_2)) && (param_2 < '9')) {
    local_4 = param_2 * 0x10 + (int)cVar1 + -0x371;
  }
  return local_4;
}



/* ---- FUN_1000_889c @ 1000:889c ---- */

void FUN_1000_889c(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined2 unaff_DS;
  int local_6;
  
  if ((char)param_1[3] != '\0') {
    uVar1 = (int)(uint)((byte)param_1[1] & 0x70 ^ 0x70) >> 1 | param_1[1] & 7;
    uVar2 = (int)(uint)((byte)*param_1 & 0x70 ^ 0x70) >> 1 | *param_1 & 7;
    local_6 = 0;
    do {
      FUN_1000_543a(uVar1,local_6 % 6 + 2);
      FUN_1000_941b(2,0);
      FUN_1000_543a(uVar2,local_6 % 6 + 2);
      local_6 = local_6 + 1;
    } while (local_6 != 0x14);
    FUN_1000_543a(uVar1,0);
    FUN_1000_543a(uVar2,0);
  }
  return;
}



/* ---- FUN_1000_893c @ 1000:893c ---- */

void FUN_1000_893c()

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  
  uVar1 = *(undefined2 *)0xef0;
  uVar2 = *(undefined2 *)0xeee;
  *(undefined2 *)0xeee = 0;
  *(undefined2 *)0xef0 = 0;
  FUN_1000_7bf9();
  if (*(int *)0x53a != 0) {
    FUN_1000_8384();
    *(undefined2 *)0x9880 = 0;
    if (0 < *(int *)0xb0d2) {
      FUN_1000_82db();
      goto LAB_1000_8993;
    }
  }
  *(undefined2 *)0xcbd2 = 1;
  *(undefined2 *)0x934c = 0;
  *(undefined2 *)0x9880 = 0;
  FUN_1000_a528(2);
LAB_1000_8993:
  *(undefined2 *)0x9880 = 0xffff;
  *(undefined2 *)0x927a = *(undefined2 *)0x8bae;
  *(undefined2 *)0x927c = *(undefined2 *)0x8bb0;
  *(undefined2 *)0x927e = *(undefined2 *)0x8bb2;
  *(undefined2 *)0x9280 = *(undefined2 *)0x8bb4;
  *(undefined2 *)0x9282 = *(undefined2 *)0x4e2;
  *(undefined2 *)0x9284 = *(undefined2 *)0x4e4;
  *(undefined2 *)0x9286 = *(undefined2 *)0x4e6;
  *(undefined2 *)0x9288 = *(undefined2 *)0x4e8;
  *(int *)0x964c = -*(int *)0x8de0;
  FUN_1000_889c(0x927a);
  *(undefined2 *)0x927a = *(undefined2 *)0x4e2;
  *(undefined2 *)0x927c = *(undefined2 *)0x4e4;
  *(undefined2 *)0x927e = *(undefined2 *)0x4e6;
  *(undefined2 *)0x9280 = *(undefined2 *)0x4e8;
  *(undefined2 *)0xef0 = uVar1;
  *(undefined2 *)0xeee = uVar2;
  return;
}



/* ---- FUN_1000_89df @ 1000:89df ---- */

void FUN_1000_89df()

{
  undefined2 uVar1;
  int iVar2;
  undefined2 unaff_DS;
  undefined4 uVar3;
  long lVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  
  uVar1 = *(undefined2 *)0x53a;
  iVar2 = *(int *)0x9856;
  *(int *)0x53a = iVar2 >> 8;
  if (iVar2 >> 8 == 0) {
    *(undefined2 *)0x53f2 = 6;
    *(undefined2 *)0x53f4 = 0;
  }
  else if (*(int *)0x53a == 10) {
    uVar6 = 0;
    uVar5 = 0x3c;
    uVar3 = FUN_1000_1164(0x3c,0);
    lVar4 = FUN_1000_f32e(uVar3,uVar5,uVar6);
    *(undefined2 *)0x818a = (int)lVar4;
    *(undefined2 *)0x818c = (int)((ulong)lVar4 >> 0x10);
    if (lVar4 == 0) {
      *(undefined2 *)0x53a = uVar1;
    }
    else {
      uVar1 = *(undefined2 *)0x818c;
      *(undefined2 *)0x53f2 = (int)lVar4;
      *(undefined2 *)0x53f4 = uVar1;
    }
  }
  else {
    iVar2 = 5 << (*(char *)0x53a - 1U & 0x1f);
    *(int *)0x53f2 = iVar2;
    *(int *)0x53f4 = iVar2 >> 0xf;
    *(undefined2 *)0x8fda = 0;
    *(undefined2 *)0x8fdc = 0;
    *(undefined2 *)0x8fd6 = 0;
    *(undefined2 *)0x8fd8 = 0;
  }
  return;
}



/* ---- FUN_1000_8a64 @ 1000:8a64 ---- */

void FUN_1000_8a64()

{
  uint uVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  *(undefined2 *)0xcbd2 = 1;
  *(undefined2 *)0x934c = 0;
  uVar1 = *(uint *)0x53f2;
  iVar2 = *(int *)0x53f4;
  *(uint *)0x818a = uVar1;
  *(int *)0x818c = iVar2;
  if ((iVar2 < 1) && ((iVar2 < 0 || (uVar1 < 3)))) {
    *(undefined2 *)0x818a = 3;
    *(undefined2 *)0x818c = 0;
  }
  return;
}



/* ---- FUN_1000_8a96 @ 1000:8a96 ---- */

void FUN_1000_8a96(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  FUN_1000_f2b0(param_1,param_3,param_2);
  return;
}



/* ---- FUN_1000_8aaa @ 1000:8aaa ---- */

void FUN_1000_8aaa()

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined2 unaff_DS;
  
  iVar3 = 0;
  while (piVar5 = (int *)*(undefined2 *)(iVar3 * 4 + *(int *)0x8dda + 2), piVar5 != (int *)0x0) {
    for (; *piVar5 != 0; piVar5 = piVar5 + 3) {
      *(undefined1 *)*piVar5 = 0x20;
      *(undefined1 *)(piVar5 + 2) = 0;
    }
    iVar3 = iVar3 + 1;
  }
  *(undefined1 *)0x1082 = 1;
  *(undefined1 *)0x10ac = 1;
  *(undefined1 *)0x10b2 = 1;
  iVar4 = 4;
  iVar3 = 0x10c0;
  do {
    *(undefined1 *)(iVar3 + 4) = 1;
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + 6;
  } while (iVar4 != 10);
  iVar4 = 0;
  iVar3 = 0x10ea;
  do {
    *(undefined1 *)(iVar3 + 4) = 1;
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + 6;
  } while (iVar4 != 0xb);
  if (*(int *)0x548 == 0) {
    if (*(char *)0x9852 == '\0') {
      if (*(char *)0x95fa == '\0') {
        iVar4 = 0;
        iVar3 = 0x1066;
        do {
          *(undefined1 *)(iVar3 + 4) = 1;
          iVar4 = iVar4 + 1;
          iVar3 = iVar3 + 6;
        } while (iVar4 != 4);
        *(char *)0x1094 = '\x01' - (*(char *)(*(int *)0x9880 * 8 + -0x7716) == '\0');
        if ((*(char *)(*(int *)0x9880 * 8 + -0x770e) == '\0') || (-2 < *(int *)0x9880)) {
          uVar1 = 0;
        }
        else {
          uVar1 = 1;
        }
        *(undefined1 *)0x109a = uVar1;
        *(undefined1 *)0x10a0 = 1;
        *(undefined1 *)0x10b8 = 1;
        *(undefined1 *)0x10be = 1;
      }
      else {
        *(undefined1 *)0x108e = 1;
      }
    }
  }
  else {
    *(undefined1 *)0x10a0 = 0;
  }
  if ((*(int *)0x53c == 2) || (*(int *)0x53e == 2)) {
    *(undefined1 *)0x1094 = 0;
    *(undefined1 *)0x109a = 0;
  }
  *(bool *)0x10e2 = *(int *)0x53c != 2;
  *(bool *)0x10d0 = *(int *)0x53e != 2;
  if (*(int *)0x8176 == 0) {
    puVar2 = (undefined1 *)*(undefined2 *)0x10ae;
  }
  else {
    puVar2 = (undefined1 *)*(undefined2 *)0x10a8;
  }
  *puVar2 = 0x2b;
  if (*(int *)0xef6 == 0) {
    puVar2 = (undefined1 *)*(undefined2 *)0x10b4;
  }
  else {
    puVar2 = (undefined1 *)*(undefined2 *)0x10ba;
  }
  *puVar2 = 0x2b;
  *(undefined1 *)*(undefined2 *)(*(int *)0x53a * 6 + 0x10ea) = 0x2b;
  *(undefined1 *)*(undefined2 *)(*(int *)0x53c * 6 + 0x10c0) = 0x2b;
  *(undefined1 *)*(undefined2 *)(*(int *)0x53e * 6 + 0x10d2) = 0x2b;
  return;
}



/* ---- FUN_1000_8c26 @ 1000:8c26 ---- */

void FUN_1000_8c26()

{
  int param_1 = 0;
  byte *pbVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  FUN_1000_8a96(0x9230,8,0);
  *(int *)0x9880 = *(int *)0x9880 + 1;
  *(undefined2 *)0xcbca = *(undefined2 *)0x4e2;
  *(undefined2 *)0xcbcc = *(undefined2 *)0x4e4;
  *(undefined2 *)0xcbce = *(undefined2 *)0x4e6;
  *(undefined2 *)0xcbd0 = *(undefined2 *)0x4e8;
  FUN_1000_a348();
  do {
    FUN_1000_a4d4();
    if ((*(char *)0x8d18 != '\0') && (param_1 == *(int *)0x8d14)) {
      iVar2 = FUN_1000_86d6(*(undefined2 *)0x8d12,*(int *)0x8d14,*(undefined2 *)0x8d16,
                            *(undefined2 *)0x8d18);
      if (iVar2 == 0) {
        pbVar1 = (byte *)((*(int *)0x8d12 >> 4 ^ 7U) + 0x9230);
        *pbVar1 = *pbVar1 | '\x01' << (*(byte *)0x8d12 & 7);
      }
    }
  } while (*(char *)0x8d18 != '\0');
  *(int *)0x9880 = *(int *)0x9880 + -1;
  return;
}



/* ---- FUN_1000_8ca1 @ 1000:8ca1 ---- */

undefined1 FUN_1000_8ca1()

{
  int iVar1;
  undefined2 unaff_DS;
  
  *(undefined1 *)0xcbd0 = 0;
  *(int *)0x9880 = *(int *)0x9880 + 1;
  FUN_1000_a348();
  while( true ) {
    FUN_1000_a4d4();
    if ((*(int *)0x8d12 == *(int *)0xcbca) && (*(int *)0x8d14 == *(int *)0xcbcc)) break;
    if (*(char *)0x8d18 == '\0') {
LAB_1000_8cd9:
      iVar1 = *(int *)0x9880 * 8;
      *(undefined2 *)(iVar1 + -0x771c) = *(undefined2 *)0x4e2;
      *(undefined2 *)(iVar1 + -0x771a) = *(undefined2 *)0x4e4;
      *(undefined2 *)(iVar1 + -0x7718) = *(undefined2 *)0x4e6;
      *(undefined2 *)(iVar1 + -0x7716) = *(undefined2 *)0x4e8;
      *(int *)0x9880 = *(int *)0x9880 + -1;
      return *(undefined1 *)0xcbd0;
    }
  }
  *(undefined2 *)0xcbca = *(undefined2 *)0x8d12;
  *(undefined2 *)0xcbcc = *(undefined2 *)0x8d14;
  *(undefined2 *)0xcbce = *(undefined2 *)0x8d16;
  *(undefined2 *)0xcbd0 = *(undefined2 *)0x8d18;
  goto LAB_1000_8cd9;
}



/* ---- FUN_1000_8cfa @ 1000:8cfa ---- */

void FUN_1000_8cfa()

{
  byte *param_1 = 0;
  int iVar1;
  undefined2 unaff_DS;
  int local_6;
  int local_4;
  
  *param_1 = *(undefined1 *)0x9846;
  param_1 = param_1 + 1;
  for (local_4 = 0; local_4 != 0x80; local_4 = local_4 + 0x10) {
    for (local_6 = 0; local_6 != 8; local_6 = local_6 + 2) {
      iVar1 = (local_4 + local_6) * 4;
      *param_1 = (*(char *)(iVar1 + -0x5745) << 3 | *(byte *)(iVar1 + -0x5746)) << 4;
      iVar1 = (local_4 + local_6) * 4;
      *param_1 = *param_1 | *(char *)(iVar1 + -0x5741) << 3 | *(byte *)(iVar1 + -0x5742);
      param_1 = param_1 + 1;
    }
  }
  return;
}



/* ---- FUN_1000_8d73 @ 1000:8d73 ---- */

void FUN_1000_8d73()

{
  byte * param_1 = 0;
  byte bVar1;
  undefined2 unaff_DS;
  int local_6;
  int local_4;
  
  FUN_1000_946f();
  bVar1 = *param_1;
  *(uint *)0x9846 = (uint)bVar1;
  *(uint *)0xa836 = bVar1 ^ 1;
  param_1 = param_1 + 1;
  for (local_4 = 0; local_4 != 0x80; local_4 = local_4 + 0x10) {
    for (local_6 = 0; local_6 != 8; local_6 = local_6 + 2) {
      FUN_1000_7dbf((*param_1 & 0x70) >> 4,*param_1 >> 7,local_4 + local_6);
      FUN_1000_7dbf(*param_1 & 7,(*param_1 & 8) >> 3,local_4 + local_6 + 1);
      param_1 = param_1 + 1;
    }
  }
  FUN_1000_7da8();
  FUN_1000_950d();
  FUN_1000_3e4f();
  FUN_1000_0865();
  if (*(int *)(*(int *)0x9846 * 2 + 0x53c) == 1) {
    *(undefined2 *)0x57cc = 2;
  }
  else {
    *(undefined2 *)0x57cc = 0;
  }
  return;
}



/* ---- FUN_1000_8e36 @ 1000:8e36 ---- */

undefined2 FUN_1000_8e36()

{
  undefined2 uVar1;
  int iVar2;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int local_12 [4];
  uint local_a;
  int local_8 [2];
  char *local_4;
  
  FUN_1000_950d();
  FUN_1000_8a96(local_8,4,0);
  FUN_1000_8a96(local_12,4,0);
  local_a = 0;
  do {
    if ((local_a & 0x88) == 0) {
      local_4 = (char *)(local_a * 4 + -0x5746);
      if ((*local_4 != '\0') &&
         (local_12[*(uint *)(local_a * 4 + -0x5745) & 0xff] =
               local_12[*(uint *)(local_a * 4 + -0x5745) & 0xff] + 1, *local_4 == '\x01')) {
        local_8[*(uint *)(local_4 + 1) & 0xff] = local_8[*(uint *)(local_4 + 1) & 0xff] + 1;
      }
    }
    local_a = local_a + 1;
  } while ((int)local_a < 0x78);
  if (local_12[0] < 0x11) {
    if (local_12[1] < 0x11) {
      if (local_8[0] < 2) {
        if (local_8[1] < 2) {
          if (local_8[0] < 1) {
            uVar1 = 0x4e66;
          }
          else if (local_8[1] < 1) {
            uVar1 = 0x4e78;
          }
          else {
            local_a = (uint)*(byte *)0x9604;
            local_12[3] = (int)*(byte *)0x9624;
            for (local_12[2] = 0; local_12[2] != 8; local_12[2] = local_12[2] + 1) {
              if (*(int *)(local_12[2] * 2 + 0x4ea) + local_a == local_12[3]) {
                return 0x4e8b;
              }
            }
            for (local_12[2] = 0; local_12[2] != 7; local_12[2] = local_12[2] + 1) {
              if ((*(char *)(local_12[2] * 4 + -0x5746) == '\x06') ||
                 (*(char *)(local_12[2] * 4 + -0x5586) == '\x06')) {
                return 0x4e9f;
              }
            }
            FUN_1000_8f88();
            iVar2 = FUN_1000_9a50(*(undefined2 *)0x9846,
                                  *(undefined1 *)(*(int *)0xa836 * 0x20 + -0x69fc));
            if (iVar2 == 0) {
              uVar1 = 0;
            }
            else if (*(int *)0x9846 == 0) {
              uVar1 = 0x4eb4;
            }
            else {
              uVar1 = 0x4ec6;
            }
          }
        }
        else {
          uVar1 = 0x4e4d;
        }
      }
      else {
        uVar1 = 0x4e35;
      }
    }
    else {
      uVar1 = 0x4e1b;
    }
  }
  else {
    uVar1 = 0x4e02;
  }
  return uVar1;
}



/* ---- FUN_1000_8f88 @ 1000:8f88 ---- */

void FUN_1000_8f88()

{
  undefined2 unaff_DS;
  
  FUN_1000_7da8();
  FUN_1000_950d();
  *(undefined2 *)0x8fde = 0;
  return;
}



/* ---- FUN_1000_8f95 @ 1000:8f95 ---- */

int FUN_1000_8f95(int param_1,int param_2, ...)

{
  if (param_2 < param_1) {
    param_1 = param_2;
  }
  return param_1;
}



/* ---- FUN_1000_8fa5 @ 1000:8fa5 ---- */

int FUN_1000_8fa5(int param_1,int param_2)

{
  if (param_1 < param_2) {
    param_1 = param_2;
  }
  return param_1;
}



/* ---- FUN_1000_8fb5 @ 1000:8fb5 ---- */

int FUN_1000_8fb5(int param_1)

{
  if (0 < param_1) {
    return param_1;
  }
  return -param_1;
}



/* ---- FUN_1000_8fca @ 1000:8fca ---- */

undefined2 FUN_1000_8fca()

{
  char cVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  *(int *)0x9880 = *(int *)0x9880 + 1;
  FUN_1000_a348();
  *(int *)0x9880 = *(int *)0x9880 + -1;
  FUN_1000_a4d4();
  cVar1 = *(char *)0x8d18;
  while( true ) {
    if (cVar1 == '\0') {
      return 0;
    }
    iVar2 = FUN_1000_86d6(*(undefined2 *)0x8d12,*(undefined2 *)0x8d14,*(undefined2 *)0x8d16,
                          *(undefined2 *)0x8d18);
    if (iVar2 == 0) break;
    FUN_1000_a4d4();
    cVar1 = *(char *)0x8d18;
  }
  return 1;
}



/* ---- FUN_1000_900a @ 1000:900a ---- */

void FUN_1000_900a()

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  
  if (((*(int *)0x53c == 0) && (*(int *)0x53e != 2)) ||
     ((*(int *)0x53e == 0 && (*(int *)0x53c != 2)))) {
    iVar1 = 1;
  }
  else {
    iVar1 = 0;
  }
  iVar2 = FUN_1000_9a50(*(undefined2 *)0xa836,*(undefined1 *)(*(int *)0x9846 * 0x20 + -0x69fc));
  if (iVar2 == 0) {
    uVar4 = 0x4ef3;
  }
  else {
    FUN_1000_91dc();
    *(undefined2 *)0x57c8 = *(undefined2 *)0x9846;
    *(undefined2 *)0x9846 = *(undefined2 *)0xa836;
    *(undefined2 *)0xa836 = *(undefined2 *)0x57c8;
    if ((*(char *)0xcbd0 != '\0') &&
       (iVar3 = FUN_1000_bb0e(*(undefined2 *)0xcbca,*(undefined2 *)0xcbcc,*(undefined2 *)0xcbce,
                              *(undefined2 *)0xcbd0,1), iVar3 != 0)) {
      *(int *)0x9856 = iVar3;
    }
    uVar4 = 0x4ed7;
  }
  iVar1 = FUN_1000_1296(uVar4,0xc,iVar1 << 1);
  FUN_1000_1446();
  if (((*(int *)0x53c == 2) || (*(int *)0x53e == 2)) || (iVar1 == 0x1003)) {
    FUN_1000_7c99();
  }
  else {
    if (iVar2 == 0) {
      *(undefined2 *)0x57c8 = *(undefined2 *)0xa836;
      *(undefined2 *)0xa836 = *(undefined2 *)0x9846;
      *(undefined2 *)0x9846 = *(undefined2 *)0x57c8;
    }
    else {
      iVar1 = *(int *)0xcbca;
      *(undefined1 *)(iVar1 * 4 + -0x5746) = *(undefined1 *)0xcbd1;
      *(undefined1 *)(iVar1 * 4 + -0x5745) = *(undefined1 *)0xa836;
      iVar1 = *(int *)0xcbcc;
      *(undefined1 *)(iVar1 * 4 + -0x5746) = *(undefined1 *)0xcbd0;
      *(undefined1 *)(iVar1 * 4 + -0x5745) = *(undefined1 *)0x9846;
      FUN_1000_78f6(0xcbca);
    }
    iVar1 = *(int *)0x9880 * 8;
    *(undefined2 *)0xcbca = *(undefined2 *)(iVar1 + -0x771c);
    *(undefined2 *)0xcbcc = *(undefined2 *)(iVar1 + -0x771a);
    *(undefined2 *)0xcbce = *(undefined2 *)(iVar1 + -0x7718);
    *(undefined2 *)0xcbd0 = *(undefined2 *)(iVar1 + -0x7716);
    iVar1 = *(int *)0xcbca;
    *(undefined1 *)(iVar1 * 4 + -0x5746) = *(undefined1 *)0xcbd1;
    *(undefined1 *)(iVar1 * 4 + -0x5745) = *(undefined1 *)0xa836;
    iVar1 = *(int *)0xcbcc;
    *(undefined1 *)(iVar1 * 4 + -0x5746) = *(undefined1 *)0xcbd0;
    *(undefined1 *)(iVar1 * 4 + -0x5745) = *(undefined1 *)0x9846;
    FUN_1000_78f6(*(int *)0x9880 * 8 + -0x771c);
    iVar1 = *(int *)0x9880 * 8;
    *(undefined2 *)(iVar1 + -0x771c) = *(undefined2 *)0x4e2;
    *(undefined2 *)(iVar1 + -0x771a) = *(undefined2 *)0x4e4;
    *(undefined2 *)(iVar1 + -0x7718) = *(undefined2 *)0x4e6;
    *(undefined2 *)(iVar1 + -0x7716) = *(undefined2 *)0x4e8;
    *(undefined2 *)(iVar1 + -0x7714) = *(undefined2 *)0x4e2;
    *(undefined2 *)(iVar1 + -0x7712) = *(undefined2 *)0x4e4;
    *(undefined2 *)(iVar1 + -0x7710) = *(undefined2 *)0x4e6;
    *(undefined2 *)(iVar1 + -0x770e) = *(undefined2 *)0x4e8;
    *(int *)0x9880 = *(int *)0x9880 + -1;
    FUN_1000_7bf9();
    FUN_1000_950d();
    *(undefined2 *)0x57cc = 0;
  }
  return;
}



/* ---- FUN_1000_91dc @ 1000:91dc ---- */

void FUN_1000_91dc()

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  int local_6;
  char cStack_3;
  
  *(undefined2 *)0xcbca = *(undefined2 *)0x88dc;
  *(undefined2 *)0xcbcc = *(undefined2 *)0x88de;
  *(undefined2 *)0xcbce = *(undefined2 *)0x88e0;
  *(undefined2 *)0xcbd0 = *(undefined2 *)0x88e2;
  *(undefined2 *)0xcbcc = *(undefined2 *)0xcbca;
  uVar1 = (uint)*(byte *)(*(int *)0x9846 * 0x20 + -0x69fc);
  *(uint *)0xcbca = uVar1;
  *(undefined2 *)0xcbce = 0;
  *(undefined1 *)0xcbd1 = 1;
  if (*(char *)0x88e2 != '\0') {
    iVar2 = FUN_1000_98f9(*(undefined1 *)0x88e2,*(undefined2 *)0xa836,*(undefined2 *)0x88dc,uVar1);
    if (iVar2 != 0) {
      return;
    }
    local_6 = 1;
    iVar2 = *(int *)(*(int *)0xa836 * 2 + -0x7232);
    for (; local_6 <= iVar2; local_6 = local_6 + 1) {
      uVar1 = *(uint *)(*(int *)0xa836 * 0x20 + local_6 * 2 + -0x69fc);
      cStack_3 = (char)(uVar1 >> 8);
      if ((cStack_3 != '\0') &&
         (iVar3 = FUN_1000_98f9(cStack_3,*(undefined2 *)0xa836,uVar1 & 0xff,*(undefined2 *)0xcbca),
         iVar3 != 0)) {
        *(char *)0xcbd0 = cStack_3;
        *(uint *)0xcbcc = uVar1 & 0xff;
        return;
      }
    }
  }
  *(undefined2 *)0xcbca = *(undefined2 *)0x4e2;
  *(undefined2 *)0xcbcc = *(undefined2 *)0x4e4;
  *(undefined2 *)0xcbce = *(undefined2 *)0x4e6;
  *(undefined2 *)0xcbd0 = *(undefined2 *)0x4e8;
  return;
}



/* ---- FUN_1000_92ab @ 1000:92ab ---- */

void FUN_1000_92ab(int param_1,byte param_2)

{
  byte bVar1;
  byte *pbVar2;
  undefined2 unaff_DS;
  
  pbVar2 = (byte *)(param_1 + (uint)param_2 * 2);
  *(int *)0x9856 = (uint)*pbVar2 << 8;
  FUN_1000_89df();
  *(undefined2 *)0x9856 = 0;
  bVar1 = pbVar2[1];
  *(uint *)0x53e = bVar1 & 3;
  *(uint *)0x53c = bVar1 >> 2 & 3;
  *(uint *)0x8176 = (uint)((bVar1 & 0x40) != 0);
  *(uint *)0x8188 = (uint)((bVar1 & 0x20) != 0);
  *(uint *)0xef6 = (uint)((bVar1 & 0x10) != 0);
  return;
}



/* ---- FUN_1000_931c @ 1000:931c ---- */

void FUN_1000_931c(int param_1,byte param_2)

{
  undefined1 *puVar1;
  undefined2 unaff_DS;
  
  puVar1 = (undefined1 *)(param_1 + (uint)param_2 * 2);
  *puVar1 = *(undefined1 *)0x53a;
  puVar1[1] = *(byte *)0x53e & 3 | (*(byte *)0x53c & 3) << 2 |
              *(char *)0x8176 * '@' + *(char *)0x8188 * ' ' + *(char *)0xef6 * '\x10';
  return;
}



/* ---- FUN_1000_9371 @ 1000:9371 ---- */

undefined2 FUN_1000_9371()

{
  int iVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  
  *(undefined2 *)0xcbca = *(undefined2 *)0x88dc;
  *(undefined2 *)0xcbcc = *(undefined2 *)0x88de;
  *(undefined2 *)0xcbce = *(undefined2 *)0x88e0;
  *(undefined2 *)0xcbd0 = *(undefined2 *)0x88e2;
  if (((*(int *)0xcbce == 0) || (*(char *)0xcbd0 == '\x01')) || (*(char *)0xcbd0 == '\x06')) {
    uVar2 = 0;
  }
  else {
    *(undefined1 *)0xcbd0 = 6;
    *(undefined2 *)0xcbce = 0;
    iVar1 = FUN_1000_bb0e(*(undefined2 *)0xcbca,*(undefined2 *)0xcbcc,*(undefined2 *)0xcbce,
                          *(undefined2 *)0xcbd0,1);
    if (iVar1 != 0) {
      *(int *)0x9856 = iVar1;
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* ---- FUN_1000_93d6 @ 1000:93d6 ---- */

void FUN_1000_93d6()

{
  undefined2 unaff_DS;
  
  if (*(int *)(*(int *)0x9846 * 2 + 0x53c) == 2) {
    FUN_1000_dfac(0x88dc);
    FUN_1000_dfe3(*(undefined1 *)0x88e2);
  }
  FUN_1000_7a61(*(undefined2 *)0x88dc,*(undefined1 *)0x88e2);
  FUN_1000_96f9(*(undefined1 *)0x88e2,*(undefined2 *)0x88dc);
  return;
}



/* ---- FUN_1000_941a @ 1000:941a ---- */

void FUN_1000_941a()

{
  return;
}



/* ---- FUN_1000_941b @ 1000:941b ---- */

void FUN_1000_941b(undefined2 param_1,undefined2 param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined4 uVar5;
  
  lVar4 = FUN_1000_ea5b();
  do {
    uVar5 = FUN_1000_ea5b();
    iVar2 = (int)((ulong)uVar5 >> 0x10);
    lVar1 = lVar4 + CONCAT22(param_2,param_1);
    iVar3 = (int)((ulong)lVar1 >> 0x10);
    if (iVar3 < iVar2) {
      return;
    }
  } while ((iVar2 < iVar3) || ((uint)uVar5 < (uint)lVar1));
  return;
}



/* ---- FUN_1000_9448 @ 1000:9448 ---- */

bool FUN_1000_9448(undefined2 param_1,undefined2 param_2)

{
  int iVar1;
  
  FUN_1000_ecaa();
  iVar1 = FUN_1000_f25c(param_1,param_2,8);
  return iVar1 == 0;
}



/* ---- FUN_1000_946f @ 1000:946f ---- */

void FUN_1000_946f()

{
  FUN_1000_ecaa();
  FUN_1000_8a96(0xa8ba,0x1e0,0);
  return;
}



/* ---- FUN_1000_948c @ 1000:948c ---- */

void FUN_1000_948c()

{
  undefined2 unaff_DS;
  int iVar1;
  int iVar2;
  
  FUN_1000_ecaa();
  for (iVar2 = 0; iVar2 < 0x78; iVar2 = iVar2 + 1) {
    *(undefined2 *)(iVar2 * 4 + -0x5744) = 0x10;
  }
  for (iVar2 = 0; iVar2 < 2; iVar2 = iVar2 + 1) {
    for (iVar1 = 0; iVar1 < 0x10; iVar1 = iVar1 + 1) {
      *(undefined1 *)(iVar1 * 2 + iVar2 * 0x20 + -0x69fb) = 0;
    }
  }
  *(undefined2 *)0x8dce = 0xffff;
  *(undefined2 *)0x8dd0 = 0xffff;
  FUN_1000_f284(0xb0a6,0x8dce,4);
  return;
}



/* ---- FUN_1000_950d @ 1000:950d ---- */

void FUN_1000_950d()

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined2 unaff_DS;
  uint local_8;
  uint uVar5;
  
  FUN_1000_ecaa();
  FUN_1000_948c();
  for (local_8 = 1; (int)local_8 < 7; local_8 = local_8 + 1) {
    if (local_8 == 6) {
      local_8 = 4;
      FUN_1000_f284(0xb0a6,0x8dce);
    }
    uVar5 = 0;
    do {
      if (*(byte *)(uVar5 * 4 + -0x5746) == local_8) {
        uVar2 = (uint)*(byte *)(uVar5 * 4 + -0x5745);
        piVar3 = (int *)(uVar2 * 2 + -0x7232);
        piVar1 = piVar3;
        *piVar1 = *piVar1 + 1;
        iVar4 = *piVar3 * 2 + uVar2 * 0x20;
        *(undefined1 *)(iVar4 + -0x69fb) = (undefined1)local_8;
        *(undefined1 *)(iVar4 + -0x69fc) = (char)uVar5;
        *(undefined2 *)(uVar5 * 4 + -0x5744) =
             *(undefined2 *)((uint)*(byte *)(uVar5 * 4 + -0x5745) * 2 + -0x7232);
      }
      uVar5 = uVar5 ^ 0x77;
      if ((uVar5 & 4) == 0) {
        if ((int)uVar5 < 0x70) {
          uVar5 = uVar5 + 0x10;
        }
        else {
          uVar5 = uVar5 + 0x11 & 0x73;
        }
      }
    } while (uVar5 != 0);
  }
  return;
}



/* ---- FUN_1000_95df @ 1000:95df ---- */

void FUN_1000_95df(int param_1,int *param_2,int *param_3)

{
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  if (((byte)param_1 & 7) < 4) {
    *param_2 = param_1 + 1;
    *param_3 = param_1 + -2;
  }
  else {
    *param_2 = param_1 + -1;
    *param_3 = param_1 + 1;
  }
  return;
}



/* ---- FUN_1000_961c @ 1000:961c ---- */

void FUN_1000_961c(int param_1,int param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  iVar4 = param_1 * 4;
  uVar1 = *(undefined2 *)(iVar4 + -0x5746);
  uVar2 = *(undefined2 *)(iVar4 + -0x5744);
  param_2 = param_2 * 4;
  uVar3 = *(undefined2 *)(param_2 + -0x5744);
  *(undefined2 *)(iVar4 + -0x5746) = *(undefined2 *)(param_2 + -0x5746);
  *(undefined2 *)(iVar4 + -0x5744) = uVar3;
  *(undefined2 *)(param_2 + -0x5746) = uVar1;
  *(undefined2 *)(param_2 + -0x5744) = uVar2;
  *(undefined1 *)((uint)*(byte *)(iVar4 + -0x5745) * 0x20 + *(int *)(iVar4 + -0x5744) * 2 + -0x69fc)
       = (undefined1)param_1;
  return;
}



/* ---- FUN_1000_967c @ 1000:967c ---- */

void FUN_1000_967c(int param_1)

{
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  param_1 = param_1 * 4;
  *(undefined1 *)(param_1 + -0x5746) = 0;
  *(undefined1 *)
   (*(int *)(param_1 + -0x5744) * 2 + (*(uint *)(param_1 + -0x5745) & 0xff) * 0x20 + -0x69fb) = 0;
  return;
}



/* ---- FUN_1000_96af @ 1000:96af ---- */

void FUN_1000_96af(undefined1 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  iVar2 = param_3 * 4;
  iVar1 = *(int *)(iVar2 + -0x5744) * 2 + param_2 * 0x20;
  *(undefined1 *)(iVar2 + -0x5746) = param_1;
  *(undefined1 *)(iVar2 + -0x5745) = (undefined1)param_2;
  *(undefined1 *)(iVar1 + -0x69fb) = param_1;
  *(undefined1 *)(iVar1 + -0x69fc) = (undefined1)param_3;
  return;
}



/* ---- FUN_1000_96f9 @ 1000:96f9 ---- */

void FUN_1000_96f9(undefined1 param_1,int param_2)

{
  byte bVar1;
  int *piVar2;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  param_2 = param_2 * 4;
  *(undefined1 *)(param_2 + -0x5746) = param_1;
  bVar1 = *(byte *)(param_2 + -0x5745);
  *(undefined1 *)(*(int *)(param_2 + -0x5744) * 2 + (uint)bVar1 * 0x20 + -0x69fb) = param_1;
  piVar2 = (int *)((uint)bVar1 * 2 + -0x4f5a);
  if (*piVar2 < *(int *)(param_2 + -0x5744)) {
    *piVar2 = *(int *)(param_2 + -0x5744);
  }
  return;
}



/* ---- FUN_1000_9749 @ 1000:9749 ---- */

void FUN_1000_9749(uint param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  undefined2 unaff_DS;
  undefined2 local_a;
  uint local_8;
  undefined2 *puStack_6;
  uint *local_4;
  
  local_4 = (uint *)0x9752;
  FUN_1000_ecaa();
  if (param_5 == 0) {
    if ((*(unsigned char *)((char *)&param_4 + 1)) != 0) {
      local_4 = (uint *)param_1;
      puStack_6 = (undefined2 *)0x978b;
      FUN_1000_967c(0);
    }
    local_4 = (uint *)param_2;
    puStack_6 = (undefined2 *)param_1;
    local_8 = 0x9797;
    FUN_1000_961c(0,0);
  }
  else {
    local_4 = (uint *)param_1;
    puStack_6 = (undefined2 *)param_2;
    local_8 = 0x9761;
    FUN_1000_961c(0,0);
    if ((*(unsigned char *)((char *)&param_4 + 1)) != 0) {
      local_4 = (uint *)param_1;
      puStack_6 = (undefined2 *)*(undefined2 *)0xa836;
      local_8 = (uint)(*(unsigned char *)((char *)&param_4 + 1));
      local_a = 0x977a;
      FUN_1000_96af(0,0,0);
    }
  }
  if (param_3 != 0) {
    if ((char)param_4 == '\x01') {
      local_4 = &local_8;
      puStack_6 = &local_a;
      local_8 = param_1;
      local_a = 0x1000;
      FUN_1000_95df(0,0,0);
      if (param_5 == 0) {
        local_4 = (uint *)local_8;
        puStack_6 = (undefined2 *)local_a;
        local_8 = 0x97d8;
        FUN_1000_961c(0,0);
      }
      else {
        local_4 = (uint *)local_a;
        puStack_6 = (undefined2 *)local_8;
        local_8 = 0x97ca;
        FUN_1000_961c(0,0);
      }
    }
    else if ((char)param_4 == '\x06') {
      local_4 = (uint *)((param_1 & 7) + (param_2 & 0x70));
      if (param_5 == 0) {
        puStack_6 = (undefined2 *)0x9812;
        FUN_1000_967c(0);
      }
      else {
        puStack_6 = (undefined2 *)*(undefined2 *)0xa836;
        local_8 = 6;
        local_a = 0x9807;
        FUN_1000_96af(0,0,0);
      }
    }
    else if (param_5 == 0) {
      local_4 = (uint *)param_1;
      puStack_6 = (undefined2 *)(param_4 & 0xff);
      local_8 = 0x9838;
      FUN_1000_96f9(0,0);
    }
    else {
      local_4 = (uint *)param_2;
      puStack_6 = (undefined2 *)0x6;
      local_8 = 0x9827;
      FUN_1000_96f9(0,0);
    }
  }
  return;
}



/* ---- FUN_1000_9840 @ 1000:9840 ---- */

void FUN_1000_9840()

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined2 unaff_DS;
  int iVar4;
  int iVar5;
  
  FUN_1000_ecaa();
  FUN_1000_8a96(0x5404,0x3bc,0);
  for (iVar4 = 7; -1 < iVar4; iVar4 = iVar4 + -1) {
    for (iVar5 = 1; iVar5 < 8; iVar5 = iVar5 + 1) {
      iVar2 = *(int *)(iVar4 * 2 + 0x4ea) * iVar5 * 4;
      piVar3 = (int *)(iVar2 + 0x55e0);
      if (iVar4 < 4) {
        *piVar3 = *(int *)0x510 + *(int *)0x512;
      }
      else {
        *piVar3 = *(int *)0x510 + *(int *)0x514;
      }
      *(undefined2 *)(iVar2 + 0x55e2) = *(undefined2 *)(iVar4 * 2 + 0x4ea);
    }
    iVar5 = iVar4 * 2;
    piVar1 = (int *)(*(int *)(iVar5 + 0x4ea) * 4 + 0x55e0);
    *piVar1 = *piVar1 + *(int *)0x50e;
    iVar2 = *(int *)(iVar5 + 0x4fa) * 4;
    *(undefined2 *)(iVar2 + 0x55e0) = *(undefined2 *)0x516;
    *(undefined2 *)(iVar2 + 0x55e2) = *(undefined2 *)(iVar5 + 0x4fa);
  }
  return;
}



/* ---- FUN_1000_98f9 @ 1000:98f9 ---- */

bool FUN_1000_98f9(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined2 unaff_DS;
  bool bVar2;
  
  FUN_1000_ecaa();
  if (param_1 == 6) {
    iVar1 = FUN_1000_8fb5((param_4 - *(int *)(param_2 * 2 + 0x50a)) - param_3);
    bVar2 = iVar1 == 1;
  }
  else {
    iVar1 = (param_4 - param_3) * 4;
    if ((*(uint *)(param_1 * 2 + 0x50c) & *(uint *)(iVar1 + 0x55e0)) == 0) {
      bVar2 = false;
    }
    else if (param_1 == 1 || param_1 == 5) {
      bVar2 = true;
    }
    else {
      do {
        param_3 = param_3 + *(int *)(iVar1 + 0x55e2);
        if (param_3 == param_4) break;
      } while (*(char *)(param_3 * 4 + -0x5746) == '\0');
      bVar2 = param_3 == param_4;
    }
  }
  return bVar2;
}



/* ---- FUN_1000_99be @ 1000:99be ---- */

undefined2 FUN_1000_99be(uint param_1,int param_2)

{
  uint uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  param_2 = param_2 - *(int *)(param_1 * 2 + 0x50a);
  uVar1 = param_2 - 1;
  iVar3 = uVar1 * 4;
  if (((uVar1 & 0x88) == 0) &&
     (*(char *)(iVar3 + -0x5746) == '\x06' && *(byte *)(iVar3 + -0x5745) == param_1)) {
    uVar2 = 1;
  }
  else if (((param_2 + 1U & 0x88) == 0) &&
          (*(char *)(iVar3 + -0x573e) == '\x06' && *(byte *)(iVar3 + -0x573d) == param_1)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* ---- FUN_1000_9a50 @ 1000:9a50 ---- */

undefined2 FUN_1000_9a50(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined1 *puVar4;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  iVar1 = FUN_1000_99be(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 * 2 + -0x4f5a);
    puVar4 = (undefined1 *)(iVar1 * 2 + param_1 * 0x20 + -0x69fc);
    for (; -1 < iVar1; iVar1 = iVar1 + -1) {
      if ((puVar4[1] != '\0') &&
         (iVar1 = param_2, iVar2 = FUN_1000_98f9(puVar4[1],param_1,*puVar4,0), iVar2 != 0)) {
        return 1;
      }
      puVar4 = puVar4 + -2;
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



/* ---- FUN_1000_9ad5 @ 1000:9ad5 ---- */

void FUN_1000_9ad5(undefined2 param_1,byte *param_2)

{
  int iVar1;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  *(undefined2 *)0x52d0 = param_1;
  param_2[0] = 0;
  param_2[1] = 0;
  iVar1 = FUN_1000_9b46(5);
  if (iVar1 != 0) {
    iVar1 = FUN_1000_9b46(3);
    if (iVar1 != 0) {
      param_2[0] = 1;
      param_2[1] = 0;
    }
    iVar1 = FUN_1000_9b46(10);
    if (iVar1 != 0) {
      *param_2 = *param_2 | 2;
    }
  }
  return;
}



/* ---- FUN_1000_9b46 @ 1000:9b46 ---- */

undefined2 FUN_1000_9b46()

{
  int param_1 = 0; uint param_2 = 0;
  int iVar1;
  int iVar2;
  undefined2 unaff_DS;
  undefined2 local_8;
  
  FUN_1000_ecaa();
  local_8 = 0;
  if ((*(byte *)(param_1 * 4 + -0x5746) == param_2) &&
     ((uint)*(byte *)(param_1 * 4 + -0x5745) == *(uint *)0x52d0)) {
    iVar1 = *(int *)0x9880 + -1;
    for (iVar2 = iVar1 * 8 + -0x771c; *(char *)(iVar2 + 6) != '\0'; iVar2 = iVar2 + -8) {
      if (*(int *)(iVar1 * 8 + -0x771c) == param_1) {
        return 0;
      }
      iVar1 = iVar1 + -1;
    }
    local_8 = 1;
  }
  return local_8;
}



/* ---- FUN_1000_9bbc @ 1000:9bbc ---- */

bool FUN_1000_9bbc(int param_1)

{
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  return ((*(char *)(param_1 + 6) != '\0' && *(char *)(param_1 + 6) != '\x06') &&
         *(char *)(param_1 + 7) == '\0') && *(int *)(param_1 + 4) == 0;
}



/* ---- FUN_1000_9bfd @ 1000:9bfd ---- */

void FUN_1000_9bfd()

{
  int iVar1;
  undefined2 unaff_DS;
  undefined2 local_6;
  
  FUN_1000_ecaa();
  local_6 = 0;
  while( true ) {
    iVar1 = FUN_1000_9bbc((*(int *)0x9880 - local_6) * 8 + -0x771c);
    if (iVar1 == 0) break;
    local_6 = -0x63e3;
  }
  return;
}



/* ---- FUN_1000_9c34 @ 1000:9c34 ---- */

int FUN_1000_9c34(int param_1)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  undefined2 unaff_DS;
  int local_14;
  int local_12;
  int local_10;
  int local_e;
  int local_c;
  int local_a;
  int local_8;
  int iVar4;
  
  FUN_1000_ecaa();
  local_10 = 1;
  local_e = *(int *)0x9880 + -3;
  local_12 = *(int *)0x9880 + 1;
  for (local_14 = local_12; bVar2 = FUN_1000_9bbc(local_14 * 8 + -0x7724),
      (bVar2 & (local_e < local_14 || param_1 == 0)) != 0; local_14 = local_14 + -1) {
  }
  local_a = local_12;
  iVar4 = 1;
  if (local_e < local_14) {
    return 1;
  }
  do {
    iVar1 = local_a + -1;
    iVar3 = *(int *)(iVar1 * 8 + -0x771c);
    for (local_c = local_a + 1; local_a = iVar1, local_c < local_12; local_c = local_c + 2) {
      if (*(int *)(local_c * 8 + -0x771a) == iVar3) goto LAB_1000_9d78;
    }
    local_8 = *(int *)(iVar1 * 8 + -0x771a);
    do {
      local_c = iVar1;
      if (local_c + -2 < local_14) {
        return iVar4;
      }
      iVar1 = local_c + -2;
      if (*(int *)(iVar1 * 8 + -0x771c) == local_8) {
        local_8 = *(int *)(iVar1 * 8 + -0x771a);
      }
    } while (local_8 != iVar3 || local_e + 1 < iVar1);
    if (iVar1 < local_e) {
      iVar3 = FUN_1000_a514(local_12 - iVar1);
      local_e = iVar1;
      if (iVar3 != 0) {
        if (iVar1 == local_14) {
          return iVar4;
        }
        local_e = local_c + -3;
      }
      local_a = local_12;
    }
LAB_1000_9d78:
    if (local_a <= local_e) {
      local_10 = local_10 + 1;
      if (local_e + -2 < local_14) {
        return local_10;
      }
      local_12 = local_e;
      local_a = local_e;
      local_e = local_e + -2;
      iVar4 = local_10;
    }
  } while( true );
}



/* ---- FUN_1000_9db3 @ 1000:9db3 ---- */

uint FUN_1000_9db3(int param_1,uint param_2,uint param_3,undefined2 param_4)

{
  int iVar1;
  int iVar2;
  undefined2 unaff_DS;
  uint local_a;
  uint *local_8;
  uint uVar3;
  
  FUN_1000_ecaa();
  uVar3 = 0;
  if ((param_3 & (char)param_4 == '\x01') == 0) {
    if ((param_3 & (char)param_4 == '\x06') == 0) {
      if (param_3 != 0) {
        (*(unsigned char *)((char *)&param_4 + 0)) = '\x06';
      }
      if (((*(char *)(param_2 * 4 + -0x5746) == (char)param_4) &&
          ((uint)*(byte *)(param_2 * 4 + -0x5745) == *(uint *)0x9846)) &&
         ((*(char *)(param_1 * 4 + -0x5746) == (*(unsigned char *)((char *)&param_4 + 1)) &&
          ((uint)*(byte *)(param_1 * 4 + -0x5745) == *(uint *)0xa836 || (*(unsigned char *)((char *)&param_4 + 1)) == '\0')))) {
        if ((char)param_4 == '\x06') {
          local_8 = (uint *)(param_1 - param_2);
          local_a = 0x9f81;
          iVar2 = FUN_1000_8fb5(0);
          if (iVar2 < 0x20) {
            uVar3 = 1;
          }
          else {
            uVar3 = (uint)(*(char *)(((int)(param_1 + param_2) / 2) * 4 + -0x5746) == '\0');
          }
        }
        else {
          local_8 = (uint *)param_1;
          local_a = param_2;
          uVar3 = FUN_1000_98f9((char)param_4,*(undefined2 *)0x9846,0,0);
        }
      }
    }
    else {
      iVar2 = *(int *)0x9880 * 8;
      if (*(char *)(iVar2 + -0x771e) == '\x06') {
        local_8 = (uint *)(*(int *)(iVar2 + -0x7724) - *(int *)(iVar2 + -0x7722));
        local_a = 0x9eb5;
        iVar2 = FUN_1000_8fb5(0);
        if ((0x1f < iVar2) &&
           (*(char *)(param_2 * 4 + -0x5746) == '\x06' &&
            (uint)*(byte *)(param_2 * 4 + -0x5745) == *(uint *)0x9846)) {
          uVar3 = (uint)((*(int *)(*(int *)0x9880 * 8 + -0x7724) +
                         *(int *)(*(int *)0x9880 * 8 + -0x7722)) / 2 == param_1);
        }
      }
    }
  }
  else {
    local_8 = &local_a;
    local_a = *(uint *)0x9846;
    FUN_1000_9ad5(0,0);
    if ((local_a & 1 << ((int)param_2 < param_1)) != 0) {
      iVar2 = (int)(param_1 + param_2) / 2;
      if (((*(char *)(param_1 * 4 + -0x5746) == '\0') && (*(char *)(iVar2 * 4 + -0x5746) == '\0'))
         && ((int)param_2 < param_1 || *(char *)(param_1 * 4 + -0x574a) == '\0')) {
        local_8 = (uint *)param_2;
        local_a = *(uint *)0xa836;
        iVar1 = FUN_1000_9a50(0,0);
        if (iVar1 == 0) {
          local_8 = (uint *)param_1;
          local_a = *(uint *)0xa836;
          iVar1 = FUN_1000_9a50(0,0);
          if (iVar1 == 0) {
            local_a = *(uint *)0xa836;
            local_8 = (uint *)iVar2;
            iVar2 = FUN_1000_9a50(0,0);
            if (iVar2 == 0) {
              uVar3 = 1;
            }
          }
        }
      }
    }
  }
  return uVar3;
}



/* ---- FUN_1000_9fdf @ 1000:9fdf ---- */

void FUN_1000_9fdf()

{
  int iVar1;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  if (*(int *)0x845e < 0x50) {
    iVar1 = *(int *)0x845e;
    *(int *)0x845e = *(int *)0x845e + 1;
    iVar1 = iVar1 * 8;
    *(undefined2 *)(iVar1 + -0x6c86) = *(undefined2 *)0x8d12;
    *(undefined2 *)(iVar1 + -0x6c84) = *(undefined2 *)0x8d14;
    *(undefined2 *)(iVar1 + -0x6c82) = *(undefined2 *)0x8d16;
    *(undefined2 *)(iVar1 + -0x6c80) = *(undefined2 *)0x8d18;
  }
  return;
}



/* ---- FUN_1000_a011 @ 1000:a011 ---- */

void FUN_1000_a011()

{
  undefined2 unaff_DS;
  undefined2 local_4;
  
  FUN_1000_ecaa();
  *(undefined2 *)0x8d16 = 1;
  local_4 = 2;
  while (local_4 < 6) {
    *(undefined1 *)0x8d18 = (undefined1)local_4;
    FUN_1000_9fdf();
    local_4 = -0x5fc6;
  }
  *(undefined2 *)0x8d16 = 0;
  return;
}



/* ---- FUN_1000_a045 @ 1000:a045 ---- */

void FUN_1000_a045()

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined2 unaff_DS;
  int local_8;
  
  FUN_1000_ecaa();
  *(undefined2 *)0x8d16 = 0;
  *(undefined1 *)0x8d19 = *(undefined1 *)(*(int *)0x8d12 * 4 + -0x5746);
  *(undefined1 *)0x8d18 = 6;
  uVar1 = *(int *)0x8d12 - *(int *)(*(int *)0x9846 * 2 + 0x50a);
  for (uVar2 = uVar1 - 1; (int)uVar2 <= (int)(uVar1 + 1); uVar2 = uVar2 + 1) {
    if (((uVar2 != uVar1) && ((uVar2 & 0x88) == 0)) &&
       (*(char *)(uVar2 * 4 + -0x5746) == '\x06' &&
        (uint)*(byte *)(uVar2 * 4 + -0x5745) == *(uint *)0x9846)) {
      *(uint *)0x8d14 = uVar2;
      if (*(int *)0x8d12 < 8 || 0x6f < *(int *)0x8d12) {
        FUN_1000_a011();
      }
      else {
        FUN_1000_9fdf();
      }
    }
  }
  for (local_8 = *(int *)(*(int *)0x9846 * 2 + -0x4f5a); -1 < local_8; local_8 = local_8 + -1) {
    iVar3 = local_8 * 2 + *(int *)0x9846 * 0x20;
    if (*(char *)(iVar3 + -0x69fb) != '\x06' && *(char *)(iVar3 + -0x69fb) != '\0') {
      local_8 = *(int *)0x8d12;
      iVar3 = FUN_1000_98f9(*(undefined1 *)(iVar3 + -0x69fb),*(undefined2 *)0x9846,
                            *(undefined1 *)(iVar3 + -0x69fc),0);
      if (iVar3 != 0) {
        iVar3 = local_8 * 2 + *(int *)0x9846 * 0x20;
        *(uint *)0x8d14 = (uint)*(byte *)(iVar3 + -0x69fc);
        *(undefined1 *)0x8d18 = *(undefined1 *)(iVar3 + -0x69fb);
        local_8 = -0x5e87;
        FUN_1000_9fdf();
      }
    }
  }
  return;
}



/* ---- FUN_1000_a181 @ 1000:a181 ---- */

uint FUN_1000_a181()

{
  int iVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined2 unaff_DS;
  int local_c;
  uint local_a;
  int local_8;
  uint local_6;
  
  FUN_1000_ecaa();
  *(undefined2 *)0x8d16 = 0;
  uVar4 = *(int *)0x8d14 * 4;
  bVar2 = *(byte *)(uVar4 + 0xa8ba);
  *(byte *)0x8d18 = bVar2;
  *(undefined1 *)0x8d19 = 0;
  local_6 = bVar2 - 1;
  switch(local_6) {
  case 0:
    for (local_c = 7; local_6 = uVar4, -1 < local_c; local_c = local_c + -1) {
      uVar4 = *(int *)(local_c * 2 + 0x4ea) + *(int *)0x8d14;
      if (((uVar4 & 0x88) == 0) && (*(char *)(uVar4 * 4 + -0x5746) == '\0')) {
        *(uint *)0x8d12 = uVar4;
        FUN_1000_9fdf();
      }
    }
    break;
  case 1:
  case 2:
  case 3:
    local_8 = 7;
    local_6 = 0;
    if (*(char *)0x8d18 == '\x03') {
      local_8 = 3;
    }
    if (*(char *)0x8d18 == '\x04') {
      local_6 = 4;
    }
    for (local_c = local_8; (int)local_6 <= local_c; local_c = local_c + -1) {
      iVar1 = *(int *)(local_c * 2 + 0x4ea);
      iVar3 = *(int *)0x8d14;
      while ((local_a = iVar1 + iVar3, (local_a & 0x88) == 0 &&
             (*(char *)(local_a * 4 + -0x5746) == '\0'))) {
        *(uint *)0x8d12 = local_a;
        local_6 = 0xa28d;
        FUN_1000_9fdf();
        iVar3 = *(int *)0x8d12;
      }
    }
    break;
  case 4:
    for (local_c = 7; local_6 = uVar4, -1 < local_c; local_c = local_c + -1) {
      uVar4 = *(int *)(local_c * 2 + 0x4fa) + *(int *)0x8d14;
      if (((uVar4 & 0x88) == 0) && (*(char *)(uVar4 * 4 + -0x5746) == '\0')) {
        *(uint *)0x8d12 = uVar4;
        FUN_1000_9fdf();
      }
    }
    break;
  case 5:
    local_6 = *(int *)(*(int *)0x9846 * 2 + 0x50a) + *(int *)0x8d14;
    *(uint *)0x8d12 = local_6;
    if (*(char *)(local_6 * 4 + -0x5746) == '\0') {
      if (*(int *)0x8d12 < 8 || 0x6f < (int)local_6) {
        FUN_1000_a011();
      }
      else {
        FUN_1000_9fdf();
        local_6 = 0;
        if (*(int *)0x8d14 < 0x18 || 0x5f < *(int *)0x8d14) {
          iVar1 = *(int *)0x8d12;
          iVar3 = *(int *)0x8d14;
          *(int *)0x8d12 = *(int *)0x8d12 + (iVar1 - iVar3);
          local_6 = iVar1 - iVar3;
          if (*(char *)(*(int *)0x8d12 * 4 + -0x5746) == '\0') {
            FUN_1000_9fdf();
          }
        }
      }
    }
  }
  return local_6;
}



/* ---- FUN_1000_a348 @ 1000:a348 ---- */

void FUN_1000_a348()

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined2 unaff_DS;
  int iVar5;
  
  FUN_1000_ecaa();
  *(undefined2 *)0x845e = 0;
  *(undefined2 *)0xa852 = 0;
  for (iVar5 = 1; iVar5 <= *(int *)(*(int *)0xa836 * 2 + -0x7232); iVar5 = iVar5 + 1) {
    iVar4 = iVar5 * 2 + *(int *)0xa836 * 0x20;
    if (*(char *)(iVar4 + -0x69fb) != '\0') {
      *(uint *)0x8d12 = (uint)*(byte *)(iVar4 + -0x69fc);
      iVar5 = -0x5c64;
      FUN_1000_a045();
    }
  }
  *(undefined2 *)0x8d16 = 1;
  *(undefined1 *)0x8d18 = 1;
  *(undefined1 *)0x8d19 = 0;
  for (iVar5 = 1; -1 < iVar5; iVar5 = iVar5 + -1) {
    iVar5 = iVar5 * 4 + *(int *)0x9846 * 8;
    *(undefined2 *)0x8d12 = *(undefined2 *)(iVar5 + 0x51a);
    uVar1 = *(undefined2 *)(iVar5 + 0x51c);
    *(undefined2 *)0x8d14 = uVar1;
    iVar5 = *(int *)0x8d16;
    iVar4 = FUN_1000_9db3(*(undefined2 *)0x8d12,uVar1,iVar5,*(undefined2 *)0x8d18);
    if (iVar4 != 0) {
      FUN_1000_9fdf();
    }
  }
  for (iVar5 = *(int *)(*(int *)0x9846 * 2 + -0x7232); -1 < iVar5; iVar5 = iVar5 + -1) {
    iVar4 = iVar5 * 2 + *(int *)0x9846 * 0x20;
    if (*(char *)(iVar4 + -0x69fb) != '\0') {
      *(uint *)0x8d14 = (uint)*(byte *)(iVar4 + -0x69fc);
      iVar5 = -0x5bcf;
      FUN_1000_a181();
    }
  }
  iVar5 = *(int *)0x9880 * 8;
  if ((*(char *)(iVar5 + -0x771e) == '\x06') &&
     (iVar5 = FUN_1000_8fb5(*(int *)(iVar5 + -0x7724) - *(int *)(iVar5 + -0x7722)), 0x1f < iVar5)) {
    *(undefined2 *)0x8d16 = 1;
    *(undefined1 *)0x8d18 = 6;
    *(undefined1 *)0x8d19 = 0;
    iVar5 = *(int *)0x9880 * 8;
    *(int *)0x8d12 = (*(int *)(iVar5 + -0x7724) + *(int *)(iVar5 + -0x7722)) / 2;
    for (uVar3 = *(int *)(iVar5 + -0x7724) - 1; uVar2 = *(uint *)(*(int *)0x9880 * 8 + -0x7724),
        (int)uVar3 <= (int)(uVar2 + 1); uVar3 = uVar3 + 1) {
      if ((uVar3 != uVar2) && ((uVar3 & 0x88) == 0)) {
        *(uint *)0x8d14 = uVar3;
        iVar5 = FUN_1000_9db3(*(undefined2 *)0x8d12,uVar3,*(undefined2 *)0x8d16,
                              *(undefined2 *)0x8d18);
        if (iVar5 != 0) {
          FUN_1000_9fdf();
        }
      }
    }
  }
  return;
}



/* ---- FUN_1000_a4d4 @ 1000:a4d4 ---- */

void FUN_1000_a4d4()

{
  int iVar1;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  if (*(int *)0xa852 < *(int *)0x845e) {
    iVar1 = *(int *)0xa852;
    *(int *)0xa852 = *(int *)0xa852 + 1;
    iVar1 = iVar1 * 8;
    *(undefined2 *)0x8d12 = *(undefined2 *)(iVar1 + -0x6c86);
    *(undefined2 *)0x8d14 = *(undefined2 *)(iVar1 + -0x6c84);
    *(undefined2 *)0x8d16 = *(undefined2 *)(iVar1 + -0x6c82);
    *(undefined2 *)0x8d18 = *(undefined2 *)(iVar1 + -0x6c80);
  }
  else {
    *(undefined2 *)0x8d12 = *(undefined2 *)0x4e2;
    *(undefined2 *)0x8d14 = *(undefined2 *)0x4e4;
    *(undefined2 *)0x8d16 = *(undefined2 *)0x4e6;
    *(undefined2 *)0x8d18 = *(undefined2 *)0x4e8;
  }
  return;
}



/* ---- FUN_1000_a514 @ 1000:a514 ---- */

uint FUN_1000_a514(uint param_1)

{
  FUN_1000_ecaa();
  return param_1 & 1;
}



/* ---- FUN_1000_a528 @ 1000:a528 ---- */

void FUN_1000_a528(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  undefined2 uVar5;
  
  FUN_1000_ecaa();
  FUN_1000_1ef0(0x1000);
  *(undefined1 *)0x8de2 = *(undefined1 *)0x9846;
  *(undefined1 *)0x95fa = 1;
  FUN_1000_17f9(3);
  FUN_1000_85c4();
  FUN_1000_85c5();
  *(undefined2 *)0x9340 = 0;
  FUN_1000_a6d2();
  func_0x0000fe59(0x11ef);
  FUN_1000_85dd();
  uVar4 = *(undefined2 *)0xcbc6;
  uVar5 = *(undefined2 *)0xcbc8;
  iVar3 = *(int *)0x922c;
  *(int *)0x57c4 = -iVar3;
  *(int *)0x57c6 = -iVar3;
  *(undefined2 *)0x8de8 = 0;
  *(undefined2 *)0x8bae = *(undefined2 *)0x4e2;
  *(undefined2 *)0x8bb0 = *(undefined2 *)0x4e4;
  *(undefined2 *)0x8bb2 = *(undefined2 *)0x4e6;
  *(undefined2 *)0x8bb4 = *(undefined2 *)0x4e8;
  *(undefined2 *)0x8de0 = *(undefined2 *)0x922c;
  *(undefined2 *)0x8b2c = 0x7fff;
  do {
    if (*(int *)0x8de8 < 2) {
      *(undefined2 *)0x53f6 = *(undefined2 *)0x8de0;
    }
    uVar1 = FUN_1000_8f95(*(undefined2 *)0x8b2c,*(int *)0x8de0 + -0x80,uVar4,uVar5);
    *(undefined2 *)0x8b2c = uVar1;
    if ((*(int *)0xa838 == 5) && (*(undefined2 *)0x8b2c = 0x6000, 0 < *(int *)0x8de8)) {
      *(int *)0x8de8 = *(int *)0x8de8 + 1;
    }
    *(int *)0x8de8 = *(int *)0x8de8 + 1;
    iVar2 = FUN_1000_a799(*(undefined2 *)0x8b2c,0x7f00);
    iVar3 = *(int *)0x8b2c;
    if ((((iVar2 <= iVar3) && (*(int *)0x9340 == 0)) && (*(int *)0xa838 != 5)) &&
       (0 < *(int *)0x9854)) {
      *(int *)0x8de0 = iVar3;
      FUN_1000_a799(0x8100,iVar3 + -8);
      *(undefined2 *)0x9854 = 2;
    }
  } while (((*(int *)0x9340 == 0) && (*(int *)0x8de8 < param_1)) &&
          ((1 < *(int *)0x9854 &&
           ((iVar3 = FUN_1000_8fb5(*(undefined2 *)0x8de0), iVar3 < 0x7080 &&
            (iVar3 = FUN_1000_a68b(), iVar3 == 0))))));
  FUN_1000_8aaa();
  while ((*(int *)0xcbd2 == 0 && (*(int *)0x9340 == 0))) {
    if (*(int *)0x9856 == 0) {
      uVar4 = FUN_1000_0254();
      *(undefined2 *)0x9856 = uVar4;
    }
    if (*(int *)0x9856 != 0) {
      FUN_1000_baaf();
    }
  }
  FUN_1000_85dd();
  *(undefined1 *)0x95fa = 0;
  FUN_1000_1f0e(0xfdf);
  return;
}



/* ---- FUN_1000_a68b @ 1000:a68b ---- */

undefined2 FUN_1000_a68b()

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  if (*(int *)0xcbd2 == 0) {
    uVar1 = 0;
  }
  else {
    FUN_1000_85dd();
    if ((*(int *)0x818c < *(int *)0xcbc8) ||
       (((*(int *)0x818c <= *(int *)0xcbc8 && (*(uint *)0x818a <= *(uint *)0xcbc6)) ||
        (*(int *)((uint)*(byte *)0x8de2 * 2 + 0x53c) != 1)))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* ---- FUN_1000_a6d2 @ 1000:a6d2 ---- */

void FUN_1000_a6d2()

{
  int unaff_DS;
  undefined2 local_a;
  int iVar1;
  int iVar2;
  
  FUN_1000_ecaa();
  for (iVar1 = 0; iVar1 < 0x18; iVar1 = iVar1 + 1) {
    for (iVar2 = 0; iVar2 < 2; iVar2 = iVar2 + 1) {
      iVar1 = iVar2 * 8 + iVar1 * 0x10;
      *(undefined2 *)(iVar1 + -0x6f54) = *(undefined2 *)0x4e2;
      *(undefined2 *)(iVar1 + -0x6f52) = *(undefined2 *)0x4e4;
      *(undefined2 *)(iVar1 + -0x6f50) = *(undefined2 *)0x4e6;
      *(undefined2 *)(iVar1 + -0x6f4e) = *(undefined2 *)0x4e8;
      iVar1 = unaff_DS;
    }
  }
  *(undefined2 *)0x9244 = 0;
  *(undefined2 *)0x8dea = 0xffff;
  *(undefined2 *)0x8dec = 0xffff;
  for (local_a = 0; (int)local_a < 2; local_a = local_a + 1) {
    for (iVar1 = *(int *)(local_a * 2 + 0x5c0); iVar1 <= *(int *)(local_a * 2 + 0x5c0) + 7;
        iVar1 = iVar1 + 1) {
      if ((*(char *)(iVar1 * 4 + -0x5746) == '\x06') && (*(byte *)(iVar1 * 4 + -0x5745) == local_a))
      {
        if (local_a == *(uint *)0x9846) {
          *(int *)0x8dea = iVar1;
        }
        else {
          *(int *)0x8dec = iVar1;
        }
      }
    }
  }
  return;
}



/* ---- FUN_1000_a799 @ 1000:a799 ---- */

undefined2 FUN_1000_a799(undefined2 param_1,undefined2 param_2)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  *(uint *)0x57c2 = (uint)(*(char *)0x8bb4 != '\0');
  *(undefined2 *)0x9854 = 0;
  FUN_1000_a7e9(param_1,param_2,*(undefined2 *)0x8de8,*(undefined2 *)0x57c2,
                        *(undefined2 *)0x57c4,*(undefined2 *)0x57c6,0x8bae);
  if (*(int *)0x9854 == 0) {
    *(undefined2 *)0x8de0 = uVar1;
  }
  return uVar1;
}



/* ---- FUN_1000_a7e9 @ 1000:a7e9 ---- */

void FUN_1000_a7e9(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  FUN_1000_f284(*(int *)0x5c4 + 0xde,*(undefined2 *)0x5c4,0xde);
  *(int *)0x5c4 = *(int *)0x5c4 + 0xde;
  if (*(int *)0x5c4 == -0x7e8e) {
    FUN_1000_07f3(10);
  }
  piVar1 = (int *)*(int *)0x5c4;
  *piVar1 = param_1;
  piVar1[1] = param_2;
  piVar1[2] = param_3;
  piVar1[3] = param_4;
  piVar1[4] = param_5;
  piVar1[5] = param_6;
  piVar1[6] = param_7;
  piVar1[7] = (uint)(*(int *)(*(int *)0x9880 * 2 + -0x6dbc) == 0 && piVar1[2] < 1);
  if (piVar1[7] == 0) {
    piVar1[8] = *(int *)0x9880 * 0x80 + -32000;
  }
  else {
    piVar1[8] = -piVar1[5];
    if ((*piVar1 < piVar1[8]) && (*piVar1 = piVar1[8], piVar1[1] <= piVar1[8])) goto LAB_1000_a92c;
  }
  FUN_1000_a943();
  if (*(int *)0x9340 == 0) {
    if ((piVar1[8] == *(int *)0x9880 * 0x80 + -32000) &&
       (iVar2 = FUN_1000_9a50(*(undefined2 *)0xa836,*(undefined1 *)(*(int *)0x9846 * 0x20 + -0x69fc)
                             ), iVar2 == 0)) {
      piVar1[8] = 0;
    }
    else {
      iVar2 = piVar1[6];
      iVar3 = *(int *)0x9880 * 8;
      FUN_1000_ae11(*(undefined2 *)(iVar2 + iVar3),*(undefined2 *)(iVar2 + iVar3 + 2),
                    *(undefined2 *)(iVar2 + iVar3 + 4),*(undefined2 *)(iVar2 + iVar3 + 6));
    }
  }
LAB_1000_a92c:
  *(int *)0x5c4 = *(int *)0x5c4 + -0xde;
  return;
}



/* ---- FUN_1000_a943 @ 1000:a943 ---- */

void FUN_1000_a943()

{
  undefined2 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  iVar4 = *(int *)0x9880 * 8;
  if (*(char *)(*(int *)(*(int *)0x5c4 + 0xc) + iVar4 + 6) != '\0') {
    puVar1 = (undefined2 *)(*(int *)(*(int *)0x5c4 + 0xc) + iVar4);
    *(undefined2 *)(iVar4 + -0x771c) = *puVar1;
    *(undefined2 *)(iVar4 + -0x771a) = puVar1[1];
    *(undefined2 *)(iVar4 + -0x7718) = puVar1[2];
    *(undefined2 *)(iVar4 + -0x7716) = puVar1[3];
    *(undefined2 *)(*(int *)0x5c4 + 0x1c) = 0;
    iVar4 = FUN_1000_ab58();
    if (iVar4 != 0) {
      return;
    }
  }
  iVar4 = *(int *)0x9880 * 8;
  if ((*(char *)(iVar4 + -0x771e) != '\0') && (*(char *)(iVar4 + -0x771e) != '\x01')) {
    *(undefined2 *)(*(int *)0x5c4 + 0x1c) = 1;
    iVar2 = FUN_1000_b44a(*(uint *)(iVar4 + -0x7724));
    if (iVar2 != 0) {
      return;
    }
  }
  *(undefined2 *)(*(int *)0x5c4 + 0x1c) = 2;
  if (*(int *)(*(int *)0x5c4 + 0xe) == 0) {
    for (iVar2 = 0; iVar2 < 2; iVar2 = iVar2 + 1) {
      iVar5 = *(int *)0x9880 * 8;
      iVar2 = *(int *)0x9880 * 0x10 + iVar2 * 8;
      *(undefined2 *)(iVar5 + -0x771c) = *(undefined2 *)(iVar2 + -0x6f54);
      *(undefined2 *)(iVar5 + -0x771a) = *(undefined2 *)(iVar2 + -0x6f52);
      *(undefined2 *)(iVar5 + -0x7718) = *(undefined2 *)(iVar2 + -0x6f50);
      *(undefined2 *)(iVar5 + -0x7716) = *(undefined2 *)(iVar2 + -0x6f4e);
      iVar2 = iVar5;
      if (*(char *)(iVar5 + -0x7716) != '\0') {
        iVar2 = *(int *)(iVar5 + -0x7716);
        iVar5 = FUN_1000_9db3(*(undefined2 *)(iVar5 + -0x771c),*(undefined2 *)(iVar5 + -0x771a),
                              *(undefined2 *)(iVar5 + -0x7718),0);
        if (iVar5 != 0) {
          iVar2 = -0x55d1;
          iVar5 = FUN_1000_ab58();
          if (iVar5 != 0) {
            return;
          }
        }
      }
    }
  }
  *(undefined2 *)(*(int *)0x5c4 + 0x1c) = 3;
  iVar2 = 1;
  while( true ) {
    if (*(int *)(*(int *)0xa836 * 2 + -0x7232) < iVar2) {
      if (((*(int *)(*(int *)0x5c4 + 0xe) == 0) ||
          (iVar4 = *(int *)(*(int *)0x9880 * 2 + -0x7216), iVar4 < 0)) ||
         ((*(char *)(iVar4 * 4 + -0x5746) != '\x06' ||
           (uint)*(byte *)(iVar4 * 4 + -0x5745) != *(uint *)0x9846 ||
          (iVar4 = FUN_1000_b5ea(iVar4), iVar4 == 0)))) {
        if (*(int *)(*(int *)0x5c4 + 0xe) == 0) {
          iVar4 = FUN_1000_b860();
          if (iVar4 != 0) {
            return;
          }
          for (iVar4 = *(int *)(*(int *)0x9846 * 2 + -0x7232); -1 < iVar4; iVar4 = iVar4 + -1) {
            iVar2 = iVar4 * 2 + *(int *)0x9846 * 0x20;
            if ((*(char *)(iVar2 + -0x69fb) != '\0') &&
               (iVar2 = FUN_1000_b5ea(*(undefined1 *)(iVar2 + -0x69fc)), iVar2 != 0)) {
              return;
            }
          }
        }
        FUN_1000_b8f4();
      }
      return;
    }
    iVar5 = iVar2 * 2 + *(int *)0xa836 * 0x20;
    if (((*(char *)(iVar5 + -0x69fb) != '\0') &&
        (uVar3 = (uint)*(byte *)(iVar5 + -0x69fc),
        *(uint *)(iVar4 + -0x7724) != uVar3 || *(char *)(iVar4 + -0x771e) == '\0')) &&
       (iVar5 = FUN_1000_b44a(uVar3), iVar5 != 0)) break;
    iVar2 = iVar2 + 1;
  }
  return;
}



/* ---- FUN_1000_ab58 @ 1000:ab58 ---- */

undefined2 FUN_1000_ab58()

{
  int *piVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  piVar1 = (int *)*(int *)0x5c4;
  iVar2 = FUN_1000_aeba();
  if (iVar2 == 0) {
    if (*(int *)0x9880 < 0x17) {
      iVar2 = *(int *)0x9880;
      piVar1[iVar2 * 4 + 0x13] = *(int *)0x4e2;
      piVar1[iVar2 * 4 + 0x14] = *(int *)0x4e4;
      piVar1[iVar2 * 4 + 0x15] = *(int *)0x4e6;
      piVar1[iVar2 * 4 + 0x16] = *(int *)0x4e8;
      if (piVar1[0xe] == 0) {
        FUN_1000_f284(piVar1 + 0xf,piVar1[6],0xc0);
      }
    }
    piVar1[10] = 0;
    piVar1[0xd] = 0;
    if (piVar1[3] != 0) {
      if (piVar1[0xe] == 0) {
        piVar1[10] = (uint)(*(char *)(*(int *)0x9880 * 8 + piVar1[6] + 0xe) != '\0');
      }
      else {
        piVar1[0xd] = (uint)(*piVar1 <= piVar1[8]);
      }
    }
    while (iVar2 = FUN_1000_af87(), iVar2 == 0) {
      if ((((*(int *)0xa838 != 5) || (0 < piVar1[9] || *(int *)(*(int *)0x9880 * 2 + -0x6dba) != 0))
          && (iVar2 = FUN_1000_b2ae(), iVar2 == 0)) && (*(int *)0x9880 < 0x17)) {
        uVar3 = *(undefined2 *)0x9846;
        *(undefined2 *)0x9846 = *(undefined2 *)0xa836;
        *(undefined2 *)0xa836 = uVar3;
        *(int *)0x9880 = *(int *)0x9880 + 1;
        if (piVar1[0xd] == 0) {
          FUN_1000_a7e9(-piVar1[1],-*piVar1,piVar1[9],piVar1[10],piVar1[0xb],piVar1[0xc],
                                piVar1 + 0xf);
          piVar1[0xc] = -iVar2;
        }
        else {
          FUN_1000_a7e9(-*piVar1 + -1,-*piVar1,piVar1[9],piVar1[10],piVar1[0xb],piVar1[0xc],
                                piVar1 + 0xf);
          piVar1[0xc] = -iVar2;
        }
        *(int *)0x9880 = *(int *)0x9880 + -1;
        uVar3 = *(undefined2 *)0xa836;
        *(undefined2 *)0xa836 = *(undefined2 *)0x9846;
        *(undefined2 *)0x9846 = uVar3;
      }
      iVar2 = *(int *)0x9880 * 8;
      FUN_1000_9749(*(undefined2 *)(iVar2 + -0x771c),*(undefined2 *)(iVar2 + -0x771a),
                    *(undefined2 *)(iVar2 + -0x7718),*(undefined2 *)(iVar2 + -0x7716),1);
      if (*(int *)0x9340 != 0) {
        return 1;
      }
      iVar2 = -0x530d;
      FUN_1000_8aaa();
      if (*(int *)0x9856 == 0) {
        iVar2 = -0x5303;
        uVar3 = FUN_1000_0254();
        *(undefined2 *)0x9856 = uVar3;
      }
      if (*(int *)0x988e != 0) {
        while (*(int *)0x988e != 0) {
          iVar2 = -0x52ef;
          iVar4 = FUN_1000_0254();
          if (iVar4 != 0) {
            *(int *)0x9856 = iVar4;
          }
        }
      }
      if (*(int *)0x9856 == 0) {
        iVar2 = -0x52d9;
        uVar3 = FUN_1000_0254();
        *(undefined2 *)0x9856 = uVar3;
      }
      if (*(int *)0x9856 != 0) {
        iVar2 = -0x52cc;
        FUN_1000_baaf();
      }
      if ((((*(int *)0x9340 == 0) && (*(int *)0xcbd2 != 0)) &&
          ((*(int *)0x9880 == 0 || (iVar2 == 0)))) &&
         (FUN_1000_85dd(), *(int *)0x8b2c < *(int *)0x8de0)) {
        uVar3 = FUN_1000_a68b();
        *(undefined2 *)0x9340 = uVar3;
      }
      if ((*(int *)0xcbd2 != 0) && (*(int *)0x8de8 < 2)) {
        *(undefined2 *)0x9340 = 0;
      }
      iVar2 = FUN_1000_8fa5(piVar1[8],piVar1[0xc]);
      piVar1[8] = iVar2;
      iVar2 = FUN_1000_9448(piVar1[6] + *(int *)0x9880 * 8,*(int *)0x9880 * 8 + -0x771c);
      if (iVar2 != 0) {
        FUN_1000_b383();
      }
      if (piVar1[8] <= *piVar1) {
LAB_1000_ae03:
        return *(undefined2 *)0x9340;
      }
      FUN_1000_b383();
      if (piVar1[1] <= piVar1[8]) {
        return 1;
      }
      if (((1 < piVar1[2]) && (piVar1[3] != 0)) && (piVar1[0xd] == 0)) {
        iVar2 = FUN_1000_8f95(piVar1[8] + 4,piVar1[1] + -1);
        piVar1[8] = iVar2;
      }
      *piVar1 = piVar1[8];
      if ((piVar1[0xd] & (uint)(*(int *)0x9340 == 0)) == 0) goto LAB_1000_ae03;
      piVar1[0xd] = 0;
    }
  }
  return 0;
}



/* ---- FUN_1000_ae11 @ 1000:ae11 ---- */

void FUN_1000_ae11(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  int iVar1;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  if (((char)param_4 != '\0') &&
     ((*(char *)(*(int *)0x9880 * 8 + -0x771e) == '\0' ||
      (*(int *)(*(int *)0x9880 * 8 + -0x7724) != param_1)))) {
    if ((*(char *)(*(int *)0x9880 * 0x10 + -0x6f4e) == '\0') ||
       (iVar1 = FUN_1000_9448(&param_1,*(int *)0x9880 * 0x10 + -0x6f4c), iVar1 != 0)) {
      iVar1 = *(int *)0x9880 * 0x10;
      *(undefined2 *)(iVar1 + -0x6f4c) = *(undefined2 *)(iVar1 + -0x6f54);
      *(undefined2 *)(iVar1 + -0x6f4a) = *(undefined2 *)(iVar1 + -0x6f52);
      *(undefined2 *)(iVar1 + -0x6f48) = *(undefined2 *)(iVar1 + -0x6f50);
      *(undefined2 *)(iVar1 + -0x6f46) = *(undefined2 *)(iVar1 + -0x6f4e);
      *(int *)(iVar1 + -0x6f54) = param_1;
      *(undefined2 *)(iVar1 + -0x6f52) = param_2;
      *(undefined2 *)(iVar1 + -0x6f50) = param_3;
      *(undefined2 *)(iVar1 + -0x6f4e) = param_4;
    }
    else {
      iVar1 = FUN_1000_9448(&param_1,*(int *)0x9880 * 0x10 + -0x6f54);
      if (iVar1 == 0) {
        iVar1 = *(int *)0x9880 * 0x10;
        *(int *)(iVar1 + -0x6f4c) = param_1;
        *(undefined2 *)(iVar1 + -0x6f4a) = param_2;
        *(undefined2 *)(iVar1 + -0x6f48) = param_3;
        *(undefined2 *)(iVar1 + -0x6f46) = param_4;
      }
    }
  }
  return;
}



/* ---- FUN_1000_aeba @ 1000:aeba ---- */

undefined2 FUN_1000_aeba()

{
  int iVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  if (*(int *)(*(int *)0x5c4 + 0x1c) != 0) {
    iVar1 = FUN_1000_9448(*(int *)0x9880 * 8 + -0x771c,
                          *(int *)(*(int *)0x5c4 + 0xc) + *(int *)0x9880 * 8);
    if (iVar1 != 0) {
      return 1;
    }
    if ((*(int *)(*(int *)0x5c4 + 0xe) == 0) && (*(int *)(*(int *)0x5c4 + 0x1c) != 2)) {
      for (iVar1 = 0; iVar1 < 2; iVar1 = iVar1 + 1) {
        iVar1 = iVar1 * 8 + *(int *)0x9880 * 0x10 + -0x6f54;
        iVar2 = FUN_1000_9448(*(int *)0x9880 * 8 + -0x771c, 0);
        if (iVar2 != 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}



/* ---- FUN_1000_af55 @ 1000:af55 ---- */

undefined2 FUN_1000_af55(int param_1)

{
  int *piVar1;
  undefined2 unaff_DS;
  undefined2 local_4;
  
  FUN_1000_ecaa();
  local_4 = 0;
  piVar1 = (int *)*(int *)0x5c4;
  if (param_1 <= *piVar1) {
    local_4 = 1;
    if (piVar1[8] < param_1) {
      piVar1[8] = param_1;
    }
  }
  return local_4;
}



/* ---- FUN_1000_af87 @ 1000:af87 ---- */

undefined2 FUN_1000_af87()

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  iVar3 = *(int *)0x5c4;
  *(int *)(iVar3 + 0x12) = *(int *)(iVar3 + 4) + -1;
  if (*(int *)0xa838 == 5) {
    iVar4 = *(int *)0x9880 * 8;
    FUN_1000_9749(*(undefined2 *)(iVar4 + -0x771c),*(undefined2 *)(iVar4 + -0x771a),
                  *(undefined2 *)(iVar4 + -0x7718),*(undefined2 *)(iVar4 + -0x7716),0);
    iVar4 = FUN_1000_9a50(*(undefined2 *)0xa836,*(undefined1 *)(*(int *)0x9846 * 0x20 + -0x69fc));
    if (iVar4 == 0) {
      if (*(int *)0x9880 == 0) {
        *(int *)0x9854 = *(int *)0x9854 + 1;
      }
      iVar4 = *(int *)0x9880;
      *(undefined2 *)(iVar4 * 2 + -0x6dba) = 0;
      *(undefined2 *)(iVar4 * 2 + -0x7212) = 0xffff;
      *(undefined2 *)(iVar3 + 0x16) = 0;
      *(undefined2 *)(iVar3 + 0x18) = 0;
      if (0 < *(int *)(iVar3 + 0x12)) {
        return 0;
      }
      if (*(int *)(iVar3 + 0x12) == 0) {
        uVar1 = FUN_1000_9a50(*(undefined2 *)0x9846,*(undefined1 *)(*(int *)0xa836 * 0x20 + -0x69fc)
                             );
        *(undefined2 *)(*(int *)0x9880 * 2 + -0x6dba) = uVar1;
      }
      if (*(int *)(*(int *)0x9880 * 2 + -0x6dba) != 0) {
        return 0;
      }
      iVar3 = FUN_1000_af55(*(undefined2 *)(iVar3 + 0x16));
      if (iVar3 == 0) {
        return 0;
      }
    }
  }
  else {
    if (((*(int *)0x8de8 < 2) && ((*(uint *)(iVar3 + 0xe) & (uint)(1 < *(int *)0x9880)) != 0)) &&
       (iVar4 = *(int *)0x9880 * 8,
       (*(int *)(iVar4 + -0x772c) != *(int *)(iVar4 + -0x771a) &&
       *(byte *)(iVar4 + -0x7716) <= *(byte *)(iVar4 + -0x7715)) && *(int *)(iVar3 + 0x1c) != 1)) {
      return 1;
    }
    iVar4 = *(int *)0x9880 * 8;
    iVar4 = func_0x00010b15(0x1000,*(undefined2 *)(iVar4 + -0x771c),*(undefined2 *)(iVar4 + -0x771a)
                            ,*(undefined2 *)(iVar4 + -0x7718),*(undefined2 *)(iVar4 + -0x7716));
    *(int *)(iVar3 + 0x16) = iVar4 - *(int *)(iVar3 + 8);
    uVar1 = FUN_1000_98f9(*(undefined1 *)(*(int *)0x9880 * 8 + -0x7716),*(undefined2 *)0x9846,
                          *(undefined2 *)(*(int *)0x9880 * 8 + -0x771c),
                          *(undefined1 *)(*(int *)0xa836 * 0x20 + -0x69fc));
    *(undefined2 *)(*(int *)0x9880 * 2 + -0x6dba) = uVar1;
    if (*(int *)(*(int *)0x9880 * 2 + -0x6dba) != 0) {
      *(undefined2 *)(iVar3 + 0x12) = *(undefined2 *)(iVar3 + 4);
    }
    iVar5 = *(int *)0x9880 * 2;
    *(undefined2 *)(iVar5 + -0x7212) = *(undefined2 *)(iVar5 + -0x7216);
    iVar4 = *(int *)0x9880 * 8;
    if ((*(char *)(iVar4 + -0x7716) == '\x06') &&
       (*(int *)(iVar4 + -0x771c) < 0x18 || 0x5f < *(int *)(iVar4 + -0x771c))) {
      *(undefined2 *)(iVar5 + -0x7212) = *(undefined2 *)(iVar4 + -0x771c);
      *(undefined2 *)(iVar3 + 0x12) = *(undefined2 *)(iVar3 + 4);
    }
    if (((*(int *)(*(int *)0x9880 * 2 + -0x6dba) == 0 && *(int *)(iVar3 + 0x12) < 1) &&
         0 < *(int *)0x9880) && (iVar4 = FUN_1000_af55(*(undefined2 *)(iVar3 + 0x16)), iVar4 != 0))
    {
      return 1;
    }
    iVar4 = *(int *)0x9880 * 8;
    FUN_1000_9749(*(undefined2 *)(iVar4 + -0x771c),*(undefined2 *)(iVar4 + -0x771a),
                  *(undefined2 *)(iVar4 + -0x7718),*(undefined2 *)(iVar4 + -0x7716),0);
    iVar4 = FUN_1000_9a50(*(undefined2 *)0xa836,*(undefined1 *)(*(int *)0x9846 * 0x20 + -0x69fc));
    if (iVar4 == 0) {
      piVar6 = (int *)(*(int *)0x9880 * 2 + -0x7212);
      if ((-1 < *piVar6) &&
         ((uint)*(byte *)(*piVar6 * 4 + -0x5745) != *(uint *)0x9846 ||
          *(char *)(*piVar6 * 4 + -0x5746) != '\x06')) {
        *piVar6 = -1;
      }
      if (*(int *)0x9880 == 0) {
        *(int *)0x9854 = *(int *)0x9854 + 1;
      }
      if (*(int *)0x9880 == 0) {
        uVar2 = FUN_1000_f2f0();
        *(int *)(iVar3 + 0x16) = *(int *)(iVar3 + 0x16) + (uVar2 & 7);
      }
      *(undefined2 *)(iVar3 + 0x18) = *(undefined2 *)(iVar3 + 0x16);
      return 0;
    }
  }
  iVar3 = *(int *)0x9880 * 8;
  FUN_1000_9749(*(undefined2 *)(iVar3 + -0x771c),*(undefined2 *)(iVar3 + -0x771a),
                *(undefined2 *)(iVar3 + -0x7718),*(undefined2 *)(iVar3 + -0x7716),1);
  return 1;
}



/* ---- FUN_1000_b2ae @ 1000:b2ae ---- */

undefined2 FUN_1000_b2ae()

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined2 unaff_DS;
  int local_6;
  undefined2 local_4;
  
  FUN_1000_ecaa();
  if (*(int *)0x9880 == 1) {
    FUN_1000_9bfd();
    iVar1 = FUN_1000_9c34(0);
    if (2 < iVar1) {
      *(undefined2 *)(*(int *)0x5c4 + 0x18) = 0;
      return 1;
    }
    local_6 = 0;
    if (iVar2 < 0x60) {
      if (iVar1 < 2) {
        if (0x13 < iVar2) {
          local_6 = 1;
        }
      }
      else {
        local_6 = 2;
      }
    }
    else {
      local_6 = 3;
    }
    uVar3 = (int)*(uint *)0x53f6 >> 0xf;
    *(int *)(*(int *)0x5c4 + 0x16) =
         *(int *)(*(int *)0x5c4 + 0x16) +
         (((int)((*(uint *)0x53f6 ^ uVar3) - uVar3) >> 2 ^ uVar3) - uVar3) * local_6;
    uVar3 = (int)*(uint *)0x53f6 >> 0xf;
    *(int *)(*(int *)0x5c4 + 0x18) =
         *(int *)(*(int *)0x5c4 + 0x18) +
         (((int)((*(uint *)0x53f6 ^ uVar3) - uVar3) >> 2 ^ uVar3) - uVar3) * local_6;
  }
  local_4 = 0;
  if (2 < *(int *)0x9880) {
    local_4 = 1;
    iVar2 = FUN_1000_9c34(0);
    if (1 < iVar2) {
      *(undefined2 *)(*(int *)0x5c4 + 0x18) = 0;
      local_4 = 1;
    }
  }
  return local_4;
}



/* ---- FUN_1000_b383 @ 1000:b383 ---- */

void FUN_1000_b383()

{
  undefined2 *puVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  FUN_1000_f284(*(undefined2 *)(*(int *)0x5c4 + 0xc),*(int *)0x5c4 + 0x1e,0xc0);
  iVar2 = *(int *)0x9880 * 8;
  puVar1 = (undefined2 *)(*(int *)(*(int *)0x5c4 + 0xc) + iVar2);
  *puVar1 = *(undefined2 *)(iVar2 + -0x771c);
  puVar1[1] = *(undefined2 *)(iVar2 + -0x771a);
  puVar1[2] = *(undefined2 *)(iVar2 + -0x7718);
  puVar1[3] = *(undefined2 *)(iVar2 + -0x7716);
  if (*(int *)0x9880 == 0) {
    iVar2 = *(int *)0x5c4;
    *(undefined2 *)0x8de0 = *(undefined2 *)(iVar2 + 0x10);
    if (*(int *)0xa838 == 5) {
      *(undefined2 *)(iVar2 + 0x10) = *(undefined2 *)0x8b2c;
    }
  }
  return;
}



/* ---- FUN_1000_b3e6 @ 1000:b3e6 ---- */

undefined2 FUN_1000_b3e6()

{
  int iVar1;
  undefined2 unaff_DS;
  int local_6;
  
  FUN_1000_ecaa();
  *(undefined2 *)(*(int *)0x9880 * 8 + -0x7718) = 1;
  local_6 = 2;
  while( true ) {
    if (5 < local_6) {
      *(undefined2 *)(*(int *)0x9880 * 8 + -0x7718) = 0;
      return 0;
    }
    *(undefined1 *)(*(int *)0x9880 * 8 + -0x7716) = (undefined1)local_6;
    iVar1 = FUN_1000_ab58();
    if (iVar1 != 0) break;
    local_6 = local_6 + 1;
  }
  return 0xb424;
}



/* ---- FUN_1000_b44a @ 1000:b44a ---- */

undefined2 FUN_1000_b44a(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  iVar3 = *(int *)0x9880 * 8;
  *(undefined1 *)(iVar3 + -0x7715) = *(undefined1 *)(param_1 * 4 + -0x5746);
  *(undefined2 *)(iVar3 + -0x7718) = 0;
  *(int *)(iVar3 + -0x771c) = param_1;
  *(undefined1 *)(iVar3 + -0x7716) = 6;
  uVar1 = *(int *)(iVar3 + -0x771c) - *(int *)(*(int *)0x9846 * 2 + 0x50a);
  for (uVar2 = uVar1 - 1; (int)uVar2 <= (int)(uVar1 + 1); uVar2 = uVar2 + 1) {
    if (((uVar2 != uVar1) && ((uVar2 & 0x88) == 0)) &&
       (*(char *)(uVar2 * 4 + -0x5746) == '\x06' &&
        (uint)*(byte *)(uVar2 * 4 + -0x5745) == *(uint *)0x9846)) {
      iVar3 = *(int *)0x9880 * 8;
      *(uint *)(iVar3 + -0x771a) = uVar2;
      if (*(int *)(iVar3 + -0x771c) < 8 || 0x6f < *(int *)(iVar3 + -0x771c)) {
        uVar2 = 0xb521;
        iVar3 = FUN_1000_b3e6();
        if (iVar3 != 0) {
          return 1;
        }
      }
      else {
        uVar2 = 0xb530;
        iVar3 = FUN_1000_ab58();
        if (iVar3 != 0) {
          return 1;
        }
      }
    }
  }
  iVar3 = *(int *)(*(int *)0x9846 * 2 + -0x4f5a);
  do {
    if (iVar3 < 0) {
      return 0;
    }
    iVar4 = iVar3 * 2 + *(int *)0x9846 * 0x20;
    if (*(char *)(iVar4 + -0x69fb) != '\x06' && *(char *)(iVar4 + -0x69fb) != '\0') {
      iVar3 = *(int *)0x9846;
      iVar4 = FUN_1000_98f9(*(undefined1 *)(iVar4 + -0x69fb),iVar3,*(undefined1 *)(iVar4 + -0x69fc),
                            param_1);
      if (iVar4 != 0) {
        iVar5 = iVar3 * 2 + *(int *)0x9846 * 0x20;
        iVar4 = *(int *)0x9880;
        *(uint *)(iVar4 * 8 + -0x771a) = (uint)*(byte *)(iVar5 + -0x69fc);
        *(undefined1 *)(iVar4 * 8 + -0x7716) = *(undefined1 *)(iVar5 + -0x69fb);
        iVar4 = FUN_1000_ab58();
        if (iVar4 != 0) {
          return 1;
        }
      }
    }
    iVar3 = iVar3 + -1;
  } while( true );
}



/* ---- FUN_1000_b5ea @ 1000:b5ea ---- */

undefined2 FUN_1000_b5ea(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  int local_e;
  uint local_c;
  int local_a;
  int local_8;
  
  FUN_1000_ecaa();
  iVar2 = *(int *)0x9880 * 8;
  *(undefined2 *)(iVar2 + -0x7718) = 0;
  *(int *)(iVar2 + -0x771a) = param_1;
  *(undefined1 *)(iVar2 + -0x7716) = *(undefined1 *)(param_1 * 4 + -0x5746);
  *(undefined1 *)(iVar2 + -0x7715) = 0;
  switch(*(undefined1 *)(iVar2 + -0x7716)) {
  case 1:
    for (local_e = 7; -1 < local_e; local_e = local_e + -1) {
      uVar1 = *(int *)(local_e * 2 + 0x4ea) + *(int *)(*(int *)0x9880 * 8 + -0x771a);
      if (((uVar1 & 0x88) == 0) && (*(char *)(uVar1 * 4 + -0x5746) == '\0')) {
        *(uint *)(*(int *)0x9880 * 8 + -0x771c) = uVar1;
        iVar2 = FUN_1000_ab58();
        if (iVar2 != 0) {
          return 1;
        }
      }
    }
    break;
  case 2:
  case 3:
  case 4:
    local_a = 7;
    local_8 = 0;
    if (*(char *)(*(int *)0x9880 * 8 + -0x7716) == '\x03') {
      local_a = 3;
    }
    if (*(char *)(*(int *)0x9880 * 8 + -0x7716) == '\x04') {
      local_8 = 4;
    }
    for (local_e = local_a; local_8 <= local_e; local_e = local_e + -1) {
      iVar2 = *(int *)(local_e * 2 + 0x4ea);
      iVar3 = *(int *)(*(int *)0x9880 * 8 + -0x771a);
      while ((local_c = iVar3 + iVar2, (local_c & 0x88) == 0 &&
             (*(char *)(local_c * 4 + -0x5746) == '\0'))) {
        *(uint *)(*(int *)0x9880 * 8 + -0x771c) = local_c;
        local_8 = -0x48a8;
        iVar3 = FUN_1000_ab58();
        if (iVar3 != 0) {
          return 1;
        }
        iVar3 = *(int *)(*(int *)0x9880 * 8 + -0x771c);
      }
    }
    break;
  case 5:
    for (local_e = 7; -1 < local_e; local_e = local_e + -1) {
      uVar1 = *(int *)(local_e * 2 + 0x4fa) + *(int *)(*(int *)0x9880 * 8 + -0x771a);
      if (((uVar1 & 0x88) == 0) && (*(char *)(uVar1 * 4 + -0x5746) == '\0')) {
        *(uint *)(*(int *)0x9880 * 8 + -0x771c) = uVar1;
        iVar2 = FUN_1000_ab58();
        if (iVar2 != 0) {
          return 1;
        }
      }
    }
    break;
  case 6:
    iVar3 = *(int *)0x9880 * 8;
    iVar2 = *(int *)(*(int *)0x9846 * 2 + 0x50a) + *(int *)(iVar3 + -0x771a);
    *(int *)(iVar3 + -0x771c) = iVar2;
    if (*(char *)(iVar2 * 4 + -0x5746) == '\0') {
      if (*(int *)(iVar3 + -0x771c) < 8 || 0x6f < iVar2) {
        iVar2 = FUN_1000_b3e6();
        if (iVar2 != 0) {
          return 1;
        }
      }
      else {
        iVar2 = FUN_1000_ab58();
        if (iVar2 != 0) {
          return 1;
        }
        iVar2 = *(int *)0x9880 * 8;
        if (((*(int *)(iVar2 + -0x771a) < 0x18 || 0x5f < *(int *)(iVar2 + -0x771a)) &&
            (*(int *)(iVar2 + -0x771c) =
                  *(int *)(iVar2 + -0x771c) +
                  (*(int *)(iVar2 + -0x771c) - *(int *)(iVar2 + -0x771a)),
            *(char *)(*(int *)(iVar2 + -0x771c) * 4 + -0x5746) == '\0')) &&
           (iVar2 = FUN_1000_ab58(), iVar2 != 0)) {
          return 1;
        }
      }
    }
  }
  return 0;
}



/* ---- FUN_1000_b860 @ 1000:b860 ---- */

undefined2 FUN_1000_b860()

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  iVar2 = *(int *)0x9880 * 8;
  *(undefined2 *)(iVar2 + -0x7718) = 1;
  *(undefined1 *)(iVar2 + -0x7716) = 1;
  *(undefined1 *)(iVar2 + -0x7715) = 0;
  iVar2 = 1;
  while( true ) {
    if (iVar2 < 0) {
      return 0;
    }
    iVar3 = *(int *)0x9880 * 8;
    iVar4 = iVar2 * 4 + *(int *)0x9846 * 8;
    *(undefined2 *)(iVar3 + -0x771c) = *(undefined2 *)(iVar4 + 0x51a);
    uVar1 = *(undefined2 *)(iVar4 + 0x51c);
    *(undefined2 *)(iVar3 + -0x771a) = uVar1;
    iVar3 = FUN_1000_9db3(*(undefined2 *)(iVar3 + -0x771c),uVar1,*(undefined2 *)(iVar3 + -0x7718),
                          *(undefined2 *)(iVar3 + -0x7716));
    if ((iVar3 != 0) && (iVar3 = FUN_1000_ab58(), iVar3 != 0)) break;
    iVar2 = iVar2 + -1;
  }
  return 1;
}



/* ---- FUN_1000_b8f4 @ 1000:b8f4 ---- */

undefined2 FUN_1000_b8f4()

{
  uint uVar1;
  int iVar2;
  undefined2 unaff_DS;
  uint uVar3;
  
  FUN_1000_ecaa();
  iVar2 = *(int *)0x9880 * 8;
  if ((*(char *)(iVar2 + -0x771e) == '\x06') &&
     (iVar2 = FUN_1000_8fb5(*(int *)(iVar2 + -0x7724) - *(int *)(iVar2 + -0x7722)), 0x1f < iVar2)) {
    iVar2 = *(int *)0x9880 * 8;
    *(undefined2 *)(iVar2 + -0x7718) = 1;
    *(undefined1 *)(iVar2 + -0x7716) = 6;
    *(undefined1 *)(iVar2 + -0x7715) = 0;
    *(int *)(iVar2 + -0x771c) = (*(int *)(iVar2 + -0x7724) + *(int *)(iVar2 + -0x7722)) / 2;
    uVar1 = *(int *)(iVar2 + -0x7724) - 1;
    while (iVar2 = *(int *)0x9880 * 8, (int)uVar1 <= *(int *)(iVar2 + -0x7724) + 1) {
      uVar3 = uVar1;
      if ((*(uint *)(iVar2 + -0x7724) != uVar1) && ((uVar1 & 0x88) == 0)) {
        *(uint *)(iVar2 + -0x771a) = uVar1;
        uVar3 = *(uint *)(iVar2 + -0x7716);
        iVar2 = FUN_1000_9db3(*(undefined2 *)(iVar2 + -0x771c),uVar1,
                              *(undefined2 *)(iVar2 + -0x7718),0);
        if (iVar2 != 0) {
          uVar3 = 0xb9a1;
          iVar2 = FUN_1000_ab58();
          if (iVar2 != 0) {
            return 1;
          }
        }
      }
      uVar1 = uVar3 + 1;
    }
  }
  return 0;
}



/* ---- FUN_1000_b9ba @ 1000:b9ba ---- */

void FUN_1000_b9ba()

{
  undefined2 uVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  *(undefined2 *)0x8184 = *(undefined2 *)0x9880;
  while (0 < *(int *)0x9880) {
    *(int *)0x9880 = *(int *)0x9880 + -1;
    uVar1 = *(undefined2 *)0xa836;
    *(undefined2 *)0xa836 = *(undefined2 *)0x9846;
    *(undefined2 *)0x9846 = uVar1;
    iVar2 = *(int *)0x9880 * 8;
    FUN_1000_9749(*(undefined2 *)(iVar2 + -0x771c),*(undefined2 *)(iVar2 + -0x771a),
                  *(undefined2 *)(iVar2 + -0x7718),*(undefined2 *)(iVar2 + -0x7716),1);
  }
  *(int *)0x9880 = *(int *)0x9880 + -1;
  if (*(int *)0x934c != 0) {
    iVar2 = *(int *)0x9880 * 8;
    FUN_1000_86a1(*(undefined2 *)(iVar2 + -0x771c),*(undefined2 *)(iVar2 + -0x771a),
                  *(undefined2 *)(iVar2 + -0x7718),*(undefined2 *)(iVar2 + -0x7716));
  }
  return;
}



/* ---- FUN_1000_ba37 @ 1000:ba37 ---- */

void FUN_1000_ba37()

{
  undefined2 uVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  if (*(int *)0x934c != 0) {
    iVar2 = *(int *)0x9880 * 8;
    FUN_1000_866d(*(undefined2 *)(iVar2 + -0x7714),*(undefined2 *)(iVar2 + -0x7712),
                  *(undefined2 *)(iVar2 + -0x7710),*(undefined2 *)(iVar2 + -0x770e));
  }
  *(int *)0x9880 = *(int *)0x9880 + 1;
  while (*(int *)0x9880 < *(int *)0x8184) {
    iVar2 = *(int *)0x9880 * 8;
    FUN_1000_9749(*(undefined2 *)(iVar2 + -0x771c),*(undefined2 *)(iVar2 + -0x771a),
                  *(undefined2 *)(iVar2 + -0x7718),*(undefined2 *)(iVar2 + -0x7716),0);
    uVar1 = *(undefined2 *)0x9846;
    *(undefined2 *)0x9846 = *(undefined2 *)0xa836;
    *(undefined2 *)0xa836 = uVar1;
    *(int *)0x9880 = *(int *)0x9880 + 1;
  }
  return;
}



/* ---- FUN_1000_baaf @ 1000:baaf ---- */

void FUN_1000_baaf()

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  FUN_1000_b9ba();
  FUN_1000_8834();
  FUN_1000_872a();
  uVar1 = FUN_1000_a68b();
  *(undefined2 *)0x9340 = uVar1;
  if (*(int *)0x9856 != 0) {
    if (*(int *)0xcbd2 == 0) {
      FUN_1000_1296(0x4f0a,0xc,0);
    }
    else {
      if (*(int *)0x9856 == 2) {
        *(undefined2 *)0x9340 = 1;
      }
      *(undefined2 *)0x9856 = 0;
    }
  }
  FUN_1000_ba37();
  return;
}



/* ---- FUN_1000_bb01 @ 1000:bb01 ---- */

void FUN_1000_bb01()

{
  FUN_1000_ecaa();
  return;
}



/* ---- FUN_1000_bb0e @ 1000:bb0e ---- */

uint FUN_1000_bb0e(uint param_1,uint param_2,int param_3,undefined2 param_4,int param_5)

{
  byte bVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined2 unaff_DS;
  byte local_2a;
  int local_18;
  undefined1 local_16;
  undefined1 local_14;
  char cVar6;
  char cVar7;
  uint uVar8;
  byte bVar9;
  byte bVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  undefined2 uVar14;
  
  FUN_1000_ecaa();
  *(undefined1 *)0x9852 = 1;
  if (*(int *)(*(int *)0x9846 * 2 + 0x53c) == 2) {
    if ((*(char *)0x11b3 == '\0') && (param_5 == 0)) {
      FUN_1000_dfac(&param_1);
    }
    else {
      *(undefined1 *)0x11b3 = 0;
    }
  }
  cVar7 = '\x01';
  if (param_3 != 0) {
    if (*(int *)(*(int *)0x9846 * 2 + 0x53c) == 2) {
      *(undefined1 *)0x11b3 = 1;
    }
    if ((char)param_4 == '\x06') {
      uVar3 = param_2 & 0x70 | param_1 & 7;
      cVar7 = -0x48;
      FUN_1000_bb0e(uVar3,param_2,0,0x606,0);
      *(undefined1 *)0x9852 = 1;
      param_3 = 0;
      (*(unsigned char *)((char *)&param_4 + 1)) = '\0';
      param_2 = uVar3;
    }
    else {
      cVar7 = '\n';
      FUN_1000_bb0e(param_1,param_2,0,(char)param_4,0);
      *(undefined1 *)0x9852 = 1;
      bVar1 = (byte)param_1;
      if ((bVar1 & 7) == 6) {
        bVar1 = bVar1 & 0xf0 | 5;
        param_2 = (uint)((byte)param_2 & 0xf0 | 7);
      }
      else {
        bVar1 = bVar1 & 0xf0 | 3;
        param_2 = param_2 & 0xf0;
      }
      param_1 = (uint)bVar1;
      (*(unsigned char *)((char *)&param_4 + 0)) = '\x03';
      (*(unsigned char *)((char *)&param_4 + 1)) = '\0';
    }
  }
  uVar3 = (uint)((byte)((int)param_2 >> 1) & 0x38 ^ 0x38) | param_2 & 7;
  param_1 = (uint)((byte)((int)param_1 >> 1) & 0x38 ^ 0x38) | param_1 & 7;
  (*(unsigned char *)((char *)&param_2 + 0)) = (byte)uVar3;
  bVar1 = (byte)param_2;
  if ((byte)param_2 == (byte)param_1) {
    uVar3 = 0;
  }
  else {
    if ((*(unsigned char *)((char *)&param_4 + 1)) == '\0') {
      local_18 = 200;
    }
    else {
      local_18 = 0;
      bVar10 = (byte)param_2;
      while (bVar10 != (byte)param_1) {
        if ((bVar10 & 0x38) < ((byte)param_1 & 0x38)) {
          bVar10 = bVar10 + 8;
        }
        else if (((byte)param_1 & 0x38) < (bVar10 & 0x38)) {
          bVar10 = bVar10 - 8;
        }
        if ((bVar10 & 7) < ((byte)param_1 & 7)) {
          bVar10 = bVar10 + 1;
        }
        else if (((byte)param_1 & 7) < (bVar10 & 7)) {
          bVar10 = bVar10 - 1;
        }
        local_18 = local_18 + 1;
      }
    }
    iVar13 = 0;
    uVar5 = param_1;
    uVar11 = uVar3;
    uVar8 = uVar3;
    if ((char)param_4 == '\x03') {
      iVar13 = 1;
      uVar5 = uVar3;
      param_2 = uVar3;
      if (((byte)param_2 & 0x38) < ((byte)param_1 & 0x38)) {
        uVar11 = 1;
        local_14 = FUN_1000_60d3(6,0,0,0);
        uVar8 = param_2;
      }
      else if ((((byte)param_2 & 0x38) == ((byte)param_1 & 0x38)) &&
              ((*(byte *)(uVar3 + 0x1166) & 0x40) == 0)) {
        uVar11 = 1;
        local_14 = FUN_1000_60d3(6,0,0,0);
        uVar8 = param_2;
      }
      else {
        uVar11 = 0;
        local_14 = FUN_1000_60d3(6,0,0,0);
        uVar8 = param_2;
      }
    }
    param_2 = uVar8;
    bVar9 = (byte)uVar5;
    bVar10 = (byte)uVar11;
    if ((char)param_4 == '\x05') {
      local_18 = local_18 + -1;
      if ((bVar1 & 0x38) < (bVar9 & 0x38)) {
        if ((bVar1 + 8 & 0x38) < (bVar9 & 0x38)) {
          if ((bVar1 & 7) < (bVar9 & 7)) {
            local_2a = 2;
          }
          else {
            local_2a = 6;
          }
        }
        else {
          local_2a = 4;
        }
      }
      else if ((bVar9 & 0x38) < (bVar1 - 8 & 0x38)) {
        if ((bVar1 & 7) < (bVar9 & 7)) {
          local_2a = 2;
        }
        else {
          local_2a = 6;
        }
      }
      else {
        local_2a = 0;
      }
      uVar5 = (uint)local_2a;
      uVar2 = FUN_1000_60d3(2,uVar3,0,0);
      bVar10 = (byte)uVar5;
      if (*(char *)((uVar5 & 0xff) + 0x1166) != '\0') {
        bVar10 = local_2a;
        FUN_1000_5fbd(uVar2,8,uVar5 & 0xff,0,0);
      }
      uVar5 = uVar3;
      local_14 = FUN_1000_5fbd(uVar2,1,0,0,0);
      bVar9 = (byte)uVar5;
      iVar13 = 1;
    }
    if ((bVar10 & 0x38) < (bVar9 & 0x38)) {
      if ((bVar10 & 7) < (bVar9 & 7)) {
        local_2a = 3;
      }
      else if ((bVar9 & 7) < (bVar10 & 7)) {
        local_2a = 5;
      }
      else {
        local_2a = 4;
      }
    }
    else if ((bVar9 & 0x38) < (bVar10 & 0x38)) {
      if ((bVar10 & 7) < (bVar9 & 7)) {
        local_2a = 1;
      }
      else if ((bVar9 & 7) < (bVar10 & 7)) {
        local_2a = 7;
      }
      else {
        local_2a = 0;
      }
    }
    else if ((bVar10 & 7) < (bVar9 & 7)) {
      local_2a = 2;
    }
    else if ((bVar9 & 7) < (bVar10 & 7)) {
      local_2a = 6;
    }
    if ((char)param_4 == '\x06') {
      if (local_2a == 2) {
        local_2a = 1;
      }
      else if (local_2a == 6) {
        local_2a = 7;
      }
    }
    uVar5 = uVar3;
    if (iVar13 == 0) {
      uVar11 = (uint)local_2a;
      uVar8 = 2;
      local_14 = FUN_1000_60d3(0,0,0,0);
    }
    else {
      uVar11 = (uint)local_2a;
      uVar8 = 2;
      local_14 = FUN_1000_5fbd(local_14,0,0,0,0);
    }
    uVar14 = 1;
    if (local_18 < 2) {
      uVar8 = uVar5 & 0xff;
      cVar7 = *(char *)((*(byte *)(uVar8 + 0x1166) & 7) + 0x11ac);
      if (local_2a == 1) {
        if (cVar7 == '\x04') {
          local_14 = FUN_1000_5fbd(local_14,2,uVar8,5);
          uVar8 = uVar8 & 0xff;
          uVar2 = FUN_1000_5fbd(local_14,4,uVar8,6);
          uVar8 = uVar8 & 0xff;
          local_16 = FUN_1000_5fbd(uVar2,2,uVar8,3);
        }
        else {
          if (cVar7 == '\x03') {
            uVar5 = uVar5 & 0xff;
            local_14 = FUN_1000_5fbd(local_14,6,uVar5,1);
          }
          uVar5 = uVar5 & 0xff;
          local_14 = FUN_1000_5fbd(local_14,2,uVar5,6);
          uVar5 = uVar5 & 0xff;
          uVar2 = FUN_1000_5fbd(local_14,4,uVar5,6);
          uVar8 = uVar5 & 0xff;
          local_16 = FUN_1000_5fbd(uVar2,2,uVar8,4);
        }
        uVar8 = uVar8 & 0xff;
        cVar6 = '\a';
        cVar7 = -0x51;
        local_16 = FUN_1000_5fbd(local_16,7,uVar8,uVar8,0);
      }
      else {
        if (cVar7 == '\x03') {
          uVar5 = uVar5 & 0xff;
          local_14 = FUN_1000_5fbd(local_14,6,uVar5,1);
        }
        else if (cVar7 == '\x05') {
          uVar5 = uVar5 & 0xff;
          local_14 = FUN_1000_5fbd(local_14,2,uVar5,4);
        }
        else {
          uVar5 = uVar5 & 0xff;
          local_14 = FUN_1000_5fbd(local_14,2,uVar5,5);
        }
        uVar8 = uVar5 & 0xff;
        cVar6 = '\a';
        cVar7 = '8';
        local_16 = FUN_1000_5fbd(local_14,7,uVar8,uVar8,0);
      }
      if ((cVar6 == '\x03') || (cVar6 == '\x05')) {
        uVar8 = uVar8 & 0xff;
        local_16 = FUN_1000_5fbd(local_16,2,uVar8,0);
      }
      else {
        uVar8 = uVar8 & 0xff;
        local_16 = FUN_1000_5fbd(local_16,2,uVar8,1);
      }
      uVar8 = uVar8 & 0xff;
      uVar2 = FUN_1000_5fbd(local_16,3,uVar8,uVar8);
      uVar11 = 0;
      uVar5 = uVar8 & 0xff;
      uVar8 = 5;
      FUN_1000_5fbd(uVar2);
      local_18 = 200;
    }
    while( true ) {
      bVar1 = (byte)uVar5;
      bVar10 = (byte)uVar11;
      if (bVar10 == bVar1) break;
      uVar12 = uVar11 & 0xff;
      if ((bVar10 & 0x38) < (bVar1 & 0x38)) {
        uVar11 = (uint)(byte)(bVar10 + 8);
      }
      else if ((bVar1 & 0x38) < (bVar10 & 0x38)) {
        uVar11 = (uint)(byte)(bVar10 - 8);
      }
      bVar10 = (byte)uVar11;
      if ((bVar10 & 7) < (bVar1 & 7)) {
        uVar11 = (uint)(byte)(bVar10 + 1);
      }
      else if ((bVar1 & 7) < (bVar10 & 7)) {
        uVar11 = (uint)(byte)(bVar10 - 1);
      }
      if ((char)param_4 == '\x05') {
        uVar4 = uVar11 & 0xff;
        if ((*(char *)(uVar4 + 0x1166) != '\0') && ((byte)uVar11 != bVar1)) {
          uVar11 = uVar8 & 0xff;
          uVar8 = 8;
          FUN_1000_5fbd(local_14);
          uVar5 = uVar4;
        }
        uVar4 = uVar12 & 0xff;
        if (*(char *)(uVar4 + 0x1166) != '\0') {
          uVar11 = (uVar8 & 0xff) + 4 & 7;
          uVar8 = 8;
          FUN_1000_5fbd(local_14);
          uVar5 = uVar4;
        }
      }
      if ((((*(char *)((uVar11 & 0xff) + 0x1166) == '\0') || ((char)uVar11 != (char)uVar5)) ||
          (local_2a < 4)) || (6 < local_2a)) {
        uVar11 = uVar11 & 0xff;
        uVar8 = 1;
        uVar5 = uVar3;
        local_14 = FUN_1000_5fbd(local_14);
      }
      else {
        cVar7 = '\0';
      }
      local_18 = local_18 + -1;
      if (local_18 < 2) {
        uVar8 = uVar5 & 0xff;
        cVar7 = *(char *)((*(byte *)(uVar8 + 0x1166) & 7) + 0x11ac);
        if (local_2a == 1) {
          if (cVar7 == '\x04') {
            local_14 = FUN_1000_5fbd(local_14,2,uVar8,5,uVar12,uVar14);
            uVar8 = uVar8 & 0xff;
            uVar2 = FUN_1000_5fbd(local_14,4,uVar8,6);
            uVar8 = uVar8 & 0xff;
            local_16 = FUN_1000_5fbd(uVar2,2,uVar8,3);
          }
          else {
            if (cVar7 == '\x03') {
              uVar5 = uVar5 & 0xff;
              local_14 = FUN_1000_5fbd(local_14,6,uVar5,1,uVar12,uVar14);
            }
            uVar5 = uVar5 & 0xff;
            local_14 = FUN_1000_5fbd(local_14,2,uVar5,6,uVar12,uVar14);
            uVar5 = uVar5 & 0xff;
            uVar2 = FUN_1000_5fbd(local_14,4,uVar5,6);
            uVar8 = uVar5 & 0xff;
            local_16 = FUN_1000_5fbd(uVar2,2,uVar8,4);
          }
          uVar8 = uVar8 & 0xff;
          cVar6 = '\a';
          cVar7 = -0x2a;
          local_16 = FUN_1000_5fbd(local_16,7,uVar8,uVar8,0);
        }
        else {
          if (cVar7 == '\x03') {
            uVar5 = uVar5 & 0xff;
            local_14 = FUN_1000_5fbd(local_14,6,uVar5,1,uVar12,uVar14);
          }
          else if (cVar7 == '\x05') {
            uVar5 = uVar5 & 0xff;
            local_14 = FUN_1000_5fbd(local_14,2,uVar5,4,uVar12,uVar14);
          }
          else {
            uVar5 = uVar5 & 0xff;
            local_14 = FUN_1000_5fbd(local_14,2,uVar5,5,uVar12,uVar14);
          }
          uVar8 = uVar5 & 0xff;
          cVar6 = '\a';
          cVar7 = '_';
          local_16 = FUN_1000_5fbd(local_14,7,uVar8,uVar8,0);
        }
        if ((cVar6 == '\x03') || (cVar6 == '\x05')) {
          uVar8 = uVar8 & 0xff;
          local_16 = FUN_1000_5fbd(local_16,2,uVar8,0);
        }
        else {
          uVar8 = uVar8 & 0xff;
          local_16 = FUN_1000_5fbd(local_16,2,uVar8,1);
        }
        uVar8 = uVar8 & 0xff;
        uVar2 = FUN_1000_5fbd(local_16,3,uVar8,uVar8);
        uVar11 = 0;
        uVar5 = uVar8 & 0xff;
        uVar8 = 5;
        FUN_1000_5fbd(uVar2);
        local_18 = 200;
      }
    }
    if ((*(unsigned char *)((char *)&param_4 + 1)) != '\0') {
      if (cVar7 != '\0') {
        if (((char)param_4 == '\x03') || ((char)param_4 == '\x05')) {
          uVar5 = uVar3;
          local_14 = FUN_1000_5fbd(local_14,2,uVar3,0);
        }
        else {
          uVar5 = uVar3;
          local_14 = FUN_1000_5fbd(local_14,2,uVar3,1);
        }
      }
      cVar7 = '\a';
      uVar2 = FUN_1000_5fbd(local_14,7,uVar3,uVar5 & 0xff,1);
      if ((cVar7 == '\x03') || (cVar7 == '\x05')) {
        local_14 = FUN_1000_5fbd(uVar2,2,uVar3,4);
        local_2a = 4;
      }
      else {
        local_14 = FUN_1000_5fbd(uVar2,2,uVar3,5);
      }
      uVar2 = FUN_1000_5fbd(local_14,3,uVar3,uVar3);
      uVar5 = uVar3;
      uVar2 = FUN_1000_5fbd(uVar2,5,uVar3,1);
      local_14 = FUN_1000_5fbd(uVar2,7,uVar3,uVar5 & 0xff,2);
    }
    uVar5 = uVar3;
    if ((char)param_4 == '\x03') {
      if ((local_2a == 2) || (local_2a == 6)) {
        if ((*(byte *)(uVar3 + 0x1166) & 0x40) == 0) {
          uVar2 = FUN_1000_5fbd(local_14,2,uVar3,4);
          local_14 = FUN_1000_5fbd(uVar2,6,uVar3,3);
        }
        else {
          uVar2 = FUN_1000_5fbd(local_14,2,uVar3,0);
          local_14 = FUN_1000_5fbd(uVar2,6,uVar3,2);
        }
      }
      else if (local_2a == 0) {
        local_14 = FUN_1000_5fbd(local_14,6,uVar3,2);
      }
      else {
        local_14 = FUN_1000_5fbd(local_14,6,uVar3,3);
      }
    }
    else if ((char)param_4 == '\x04') {
      if ((local_2a == 0) || (3 < local_2a)) {
        if ((*(byte *)(uVar3 + 0x1166) & 0x40) == 0) {
          local_14 = FUN_1000_5fbd(local_14,2,uVar3,5);
        }
        else {
          local_14 = FUN_1000_5fbd(local_14,2,uVar3,7);
        }
      }
      else if ((*(byte *)(uVar3 + 0x1166) & 0x40) == 0) {
        local_14 = FUN_1000_5fbd(local_14,2,uVar3,3);
      }
      else {
        local_14 = FUN_1000_5fbd(local_14,2,uVar3,1);
      }
    }
    else if ((*(byte *)(uVar3 + 0x1166) & 0x40) == 0) {
      local_14 = FUN_1000_5fbd(local_14,2,uVar3,4);
    }
    else {
      local_14 = FUN_1000_5fbd(local_14,2,uVar3,0);
    }
    FUN_1000_5fbd(local_14,3,uVar3,uVar5 & 0xff);
    uVar3 = 0;
    FUN_1000_8aaa(1);
    *(undefined1 *)0xda6 = 0;
    while (*(char *)0xda6 == '\0') {
      uVar5 = FUN_1000_0254();
      if ((uVar5 != 0) && ((uVar5 & 0xf000) == 0)) {
        uVar3 = uVar5;
      }
    }
    *(undefined1 *)0x9852 = 0;
  }
  return uVar3;
}



/* ---- FUN_1000_c83a @ 1000:c83a ---- */

void FUN_1000_c83a(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  if (*(char *)0x11aa == '\0') {
    FUN_1000_c868(param_1,param_2,param_3);
  }
  else {
    FUN_1000_c924(param_1,param_2,param_3);
  }
  return;
}



/* ---- FUN_1000_c868 @ 1000:c868 ---- */

void FUN_1000_c868()

{
  int param_1 = 0;
  uint *puVar1;
  uint uVar2;
  undefined2 unaff_DS;
  undefined4 uVar3;
  undefined2 uVar4;
  uint local_6;
  int local_4;
  
  local_4 = 0xc871;
  FUN_1000_ecaa();
  if (*(int *)0x8176 != 0) {
    uVar2 = *(uint *)(param_1 * 10 + 0xe20);
    local_6 = *(uint *)(uVar2 + 2);
    local_4 = (int)local_6 >> 0xf;
    FUN_1000_f37a(&local_6);
    local_4 = 0;
    local_6 = 0x118;
    FUN_1000_f362();
    uVar4 = (undefined2)uVar3;
    FUN_1000_f32e(uVar3);
    puVar1 = (uint *)(param_1 * 10 + 0xe20);
    local_6 = *puVar1 + 4;
    local_4 = (uint)(0xfffb < *puVar1) * 0x1000 + *(int *)(param_1 * 10 + 0xe22);
    func_0x00010e30(0x1000,local_6,local_4,uVar4);
  }
  return;
}



/* ---- FUN_1000_c924 @ 1000:c924 ---- */

void FUN_1000_c924()

{
  int param_1 = 0;
  uint *puVar1;
  int iVar2;
  undefined2 unaff_DS;
  undefined4 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  uint local_6;
  
  FUN_1000_ecaa();
  if (*(int *)0x8176 != 0) {
    iVar2 = param_1 * 10;
    local_6 = *(uint *)(iVar2 + 0xe22);
    FUN_1000_f1d6(*(undefined2 *)(iVar2 + 0xe24),*(undefined2 *)(iVar2 + 0xe26),
                  *(undefined2 *)(iVar2 + 0xe20));
    local_6 = *(int *)*(undefined4 *)(iVar2 + 0xe20) >> 0xf;
    FUN_1000_f37a(&local_6,*(int *)*(undefined4 *)(iVar2 + 0xe20));
    local_6 = 0;
    uVar5 = 0x118;
    FUN_1000_f362(0x118);
    uVar4 = (undefined2)((ulong)uVar3 >> 0x10);
    uVar3 = FUN_1000_f32e(uVar3,uVar5);
    iVar2 = (int)((ulong)uVar3 >> 0x10) + 0x3b9a + (uint)CARRY2(local_6,(uint)uVar3);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    puVar1 = (uint *)(param_1 * 10 + 0xe20);
    local_6 = (uint)(0xfffd < *puVar1) * 0x1000 + *(int *)(param_1 * 10 + 0xe22);
    FUN_1000_0f21(0x1000,local_6,iVar2,uVar4,*puVar1 + 2);
  }
  return;
}



/* ---- FUN_1000_c9d0 @ 1000:c9d0 ---- */

void FUN_1000_c9d0()

{
  byte bVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  iVar2 = FUN_1000_ed5a(0x50be,0x8000);
  *(int *)0x11b6 = iVar2;
  if (iVar2 == -1) {
    FUN_1000_1296(0x50c7,0xc,0);
    FUN_1000_07f3(0);
  }
  FUN_1000_ecc0(*(undefined2 *)0x11b6);
  iVar2 = FUN_1000_ed5a(0x50e3,0x8000);
  *(int *)0x11b6 = iVar2;
  if (iVar2 == -1) {
    *(undefined2 *)0x57ce = 1;
    FUN_1000_f316();
    *(int *)0x988a = (bVar1 >> 6) + 1;
  }
  else {
    *(undefined2 *)0x57ce = 0;
    *(undefined2 *)0x988a = 1;
    FUN_1000_ecc0(*(undefined2 *)0x11b6);
  }
  *(undefined2 *)0x11b6 = 0xffff;
  return;
}



/* ---- FUN_1000_ca56 @ 1000:ca56 ---- */

void FUN_1000_ca56(int param_1)

{
  int iVar1;
  undefined2 unaff_DS;
  bool bVar2;
  char local_2c [2];
  byte local_2a [9];
  char local_21;
  undefined2 uStack_a;
  undefined2 uStack_8;
  byte *pbStack_6;
  byte *pbStack_4;
  
  pbStack_4 = (byte *)0xca5f;
  FUN_1000_ecaa();
  pbStack_4 = (byte *)local_2c;
  pbStack_6 = (byte *)0xca66;
  FUN_1000_f31a();
  local_2a[0] = local_2c[0] + 0x40;
  local_2a[1] = 0x3a;
  local_2a[2] = 0;
  bVar2 = param_1 != 0;
  if (bVar2) {
    pbStack_4 = (byte *)0x50f5;
    pbStack_6 = local_2a;
    uStack_8 = 0xca9e;
    FUN_1000_f102();
  }
  else {
    pbStack_4 = (byte *)0x50ec;
    pbStack_6 = local_2a;
    uStack_8 = 0xca8a;
    FUN_1000_f102();
  }
  if (bVar2 != (bool)*(char *)0x11b8) {
    if (*(int *)0x11b6 != -1) {
      pbStack_4 = (byte *)*(undefined2 *)0x11b6;
      pbStack_6 = (byte *)0xcabe;
      FUN_1000_ecc0();
    }
    if ((char)local_2a[0] < 'C') {
      while( true ) {
        pbStack_4 = local_2a;
        pbStack_6 = (byte *)0xcb35;
        iVar1 = FUN_1000_cc0f();
        if (iVar1 != 0) break;
        local_2a[0] = local_2a[0] ^ 3;
        pbStack_4 = local_2a;
        pbStack_6 = (byte *)0xcb02;
        iVar1 = FUN_1000_cc0f();
        if (iVar1 != 0) break;
        if (local_21 == '1') {
          uStack_8 = 0x5116;
        }
        else {
          uStack_8 = 0x5131;
        }
        pbStack_4 = (byte *)0x0;
        pbStack_6 = (byte *)0xc;
        uStack_a = 0xcb1d;
        FUN_1000_1296();
      }
    }
    else {
      pbStack_4 = (byte *)0x8000;
      pbStack_6 = local_2a;
      uStack_8 = 0xcad2;
      iVar1 = FUN_1000_ed5a();
      *(int *)0x11b6 = iVar1;
      if (iVar1 == -1) {
        pbStack_4 = (byte *)0x0;
        pbStack_6 = (byte *)0xc;
        uStack_8 = 0x50fe;
        uStack_a = 0xcae9;
        FUN_1000_1296();
        pbStack_4 = (byte *)0x0;
        pbStack_6 = (byte *)0xcaf2;
        FUN_1000_07f3();
      }
    }
    *(bool *)0x11b8 = bVar2;
  }
  pbStack_4 = (byte *)0x0;
  pbStack_6 = (byte *)0x0;
  uStack_8 = 0xcb49;
  FUN_1000_cb5b();
  return;
}



/* ---- FUN_1000_cb50 @ 1000:cb50 ---- */

void FUN_1000_cb50()

{
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  *(undefined1 *)0x11b8 = 0xff;
  return;
}



/* ---- FUN_1000_cb5b @ 1000:cb5b ---- */

void FUN_1000_cb5b()

{
  undefined2 param_1 = 0; undefined2 param_2 = 0;
  undefined2 unaff_DS;
  long lVar1;
  
  FUN_1000_ecaa();
  FUN_1000_ece0(*(undefined2 *)0x11b6,param_1,param_2,0);
  if (lVar1 == -1) {
    FUN_1000_941a(0x514e);
    FUN_1000_07f3();
  }
  return;
}



/* ---- FUN_1000_cb8f @ 1000:cb8f ---- */

void FUN_1000_cb8f()

{
  undefined1 *param_1 = 0; uint param_2 = 0; int param_3 = 0;
  undefined1 *puVar1;
  uint uVar2;
  undefined2 unaff_DS;
  uint local_208;
  undefined1 local_204 [504];
  undefined2 uStack_c;
  undefined2 uStack_a;
  undefined1 *puStack_8;
  uint uStack_6;
  undefined1 *puVar3;
  
  FUN_1000_ecaa();
  for (; param_2 != 0 || param_3 != 0; param_2 = param_2 - uVar2) {
    uVar2 = param_2;
    if ((-1 < param_3) && ((0 < param_3 || (0x200 < param_2)))) {
      uVar2 = 0x200;
    }
    puStack_8 = local_204;
    uStack_a = *(undefined2 *)0x11b6;
    uStack_c = 0xcbc8;
    uStack_6 = uVar2;
    FUN_1000_eefe();
    puVar3 = local_204;
    for (local_208 = 0; puVar1 = param_1, local_208 != uVar2; local_208 = local_208 + 1) {
      if ((undefined1 *)param_1 == (undefined1 *)0xffff) {
        /* segment update: param_1 hi = GH_HI16(param_1) + 0x1000 */ (void)0;
      }
      param_1 = (undefined1 *)CONCAT22(GH_HI16(param_1),(undefined1 *)param_1 + 1);
      *puVar1 = *puVar3;
      puVar3 = puVar3 + 1;
    }
    param_3 = (param_3 - ((int)uVar2 >> 0xf)) - (uint)(param_2 < uVar2);
  }
  return;
}



/* ---- FUN_1000_cc0f @ 1000:cc0f ---- */

undefined2 FUN_1000_cc0f()

{
  char * param_1 = 0;
  int iVar1;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  iVar1 = func_0x00011084(0x1000,(int)*param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_1000_ed5a(param_1,0x8000);
    *(int *)0x11b6 = iVar1;
    if (iVar1 != -1) {
      return 1;
    }
  }
  return 0;
}



/* ---- FUN_1000_cc46 @ 1000:cc46 ---- */

void FUN_1000_cc46(int param_1)

{
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  if (param_1 == 0) {
    *(undefined2 *)0x53f8 = 0x11ba;
    *(undefined2 *)0x8ae4 = 0x1c62;
  }
  else {
    *(undefined2 *)0x53f8 = 0x2010;
    *(undefined2 *)0x8ae4 = 0x2a98;
  }
  return;
}



/* ---- FUN_1000_cc72 @ 1000:cc72 ---- */

void FUN_1000_cc72()

{
  int iVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  uint local_294;
  undefined1 local_292 [512];
  uint local_92;
  int local_90;
  uint local_8e;
  uint local_8c;
  int *local_8a;
  uint local_88;
  int local_86;
  undefined1 local_84 [15];
  byte abStack_75 [113];
  undefined1 *local_4;
  
  local_8e = 0;
  local_294 = 0xffff;
  local_90 = 0;
  local_92 = 0;
  *(undefined1 *)0x2b28 = *(undefined1 *)0x9360;
  *(undefined1 *)0x2b29 = *(undefined1 *)0x8dde;
  iVar1 = FUN_1000_d59d(local_292);
  if (iVar1 == 0) {
    FUN_1000_1296(0x515c,0xc,0);
  }
  else {
    local_4 = local_292;
    FUN_1000_17f9(1);
    FUN_1000_1f0e(0x1000);
    FUN_1000_d2cc();
    FUN_1000_d2dd(local_4,local_84);
    FUN_1000_d365(local_84,0x516c);
    FUN_1000_d66c(local_8e,local_84);
    FUN_1000_1ef0(0x11ef);
LAB_1000_cd09:
    local_8a = (int *)FUN_1000_d766();
    if ((*local_8a == 7) && (local_8a[1] == 0)) {
      if (local_8a[2] == 0x80) {
        local_8e = FUN_1000_db65(local_84,local_8e);
      }
      else {
        if (local_8a[2] != 0x81) goto LAB_1000_cd09;
        local_8e = FUN_1000_db3d(local_84,local_8e);
      }
      FUN_1000_d66c(local_8e,local_84);
      goto LAB_1000_cd09;
    }
    if ((*local_8a != 6) || (local_8a[1] != 0)) {
      if (*local_8a == 4) {
        if (local_8a[2] == 1) {
          local_88 = FUN_1000_ea5b();
          local_86 = (int)local_88 >> 0xf;
          local_8c = FUN_1000_d840(*(undefined2 *)0x933a,*(undefined2 *)0x935e,0);
          if ((int)local_8c < 8) {
            if (abStack_75[local_8c * 0x10] != 0xff) {
              local_8e = local_8c;
              FUN_1000_d66c(local_8c,local_84);
            }
          }
          else if ((local_8c == 8) && (iVar1 = FUN_1000_d92e(8,0), iVar1 != 0)) goto LAB_1000_cec2;
          if (local_8c == local_8e) {
            if (((local_86 - local_90 == (uint)(local_88 < local_92)) && (local_88 - local_92 < 10))
               && (local_294 == local_8e)) goto LAB_1000_cd80;
            local_92 = local_88;
            local_90 = local_86;
            local_294 = local_8e;
          }
        }
      }
      else if (*local_8a == 5) {
        *(int *)0x933a = local_8a[4];
        *(int *)0x935e = local_8a[5];
        func_0x00011f20(0x11ef);
      }
      goto LAB_1000_cd09;
    }
    iVar1 = local_8a[2];
    if (iVar1 == 0xd) goto LAB_1000_cd80;
    if (iVar1 == 0x1b) {
LAB_1000_cec2:
      FUN_1000_1f0e(0x11ef);
      FUN_1000_d90e();
      goto LAB_1000_ceca;
    }
    if (iVar1 != 0x20) goto LAB_1000_cd09;
LAB_1000_cd80:
    FUN_1000_1f0e(0x11ef);
    FUN_1000_d90e();
    local_8e = (uint)abStack_75[local_8e * 0x10];
    FUN_1000_8d73(local_4 + local_8e * 0x30 + 0x1f);
    FUN_1000_df71();
    local_8c = *(uint *)0xef6;
    FUN_1000_92ab(local_4,local_8e);
    if (local_8c != *(uint *)0xef6) {
      FUN_1000_2a1a();
      FUN_1000_3e4f();
      FUN_1000_0865();
    }
LAB_1000_ceca:
    FUN_1000_1ef0(0x11ef);
  }
  return;
}



/* ---- FUN_1000_ced4 @ 1000:ced4 ---- */

void FUN_1000_ced4()

{
  char *pcVar1;
  int iVar2;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_2aa [512];
  int local_aa;
  uint local_a8;
  int local_a6;
  uint local_a4;
  int local_a2;
  int local_a0;
  char local_9e [16];
  int *local_8e;
  uint local_8c;
  int local_8a;
  undefined1 local_88 [15];
  byte abStack_79 [113];
  int local_8;
  uint local_6;
  undefined1 *local_4;
  
  local_a2 = 0;
  local_aa = 1;
  local_a4 = -1;
  local_a6 = 0;
  local_a8 = 0;
  *(undefined1 *)0x2b28 = *(undefined1 *)0x9360;
  *(undefined1 *)0x2b29 = *(undefined1 *)0x8dde;
  FUN_1000_d59d(local_2aa);
  local_4 = local_2aa;
  FUN_1000_17f9(1);
  FUN_1000_1f0e(0x1000);
  FUN_1000_d2cc();
  FUN_1000_d2dd(local_4,local_88);
  FUN_1000_d365(local_88,0x5171);
  local_8 = FUN_1000_d8b6(local_9e,local_88 + local_a2 * 0x10);
  FUN_1000_1ef0(0x11ef);
LAB_1000_cf65:
  do {
    do {
      while( true ) {
        while( true ) {
          local_8e = (int *)FUN_1000_d766();
          if (local_a2 != -1) {
            FUN_1000_5b3d(0x40,local_a2 * 10 + 0x44);
          }
          iVar2 = *local_8e;
          if (iVar2 != 3) break;
          if (((local_a2 != -1) && (local_aa != 0)) && ((local_6 & 4) != 0)) {
            if (local_9e[local_8] == '_') {
              local_9e[local_8] = ' ';
            }
            else {
              local_9e[local_8] = '_';
            }
            FUN_1000_d551(local_9e,0xe);
          }
          local_6 = local_6 + 1;
        }
        if (iVar2 == 4) break;
        if (iVar2 == 5) {
          *(int *)0x933a = local_8e[4];
          *(int *)0x935e = local_8e[5];
          func_0x00011f20(0x11ef);
        }
        else if (iVar2 == 6) {
          if (local_8e[2] == 0x1b) {
LAB_1000_d2c4:
            FUN_1000_d90e();
            return;
          }
          if (local_a2 != -1) {
            if (local_8e[2] == 8) {
              pcVar1 = local_9e + local_8;
              local_8 = local_8 + -1;
              *pcVar1 = ' ';
              if (local_8 < 0) {
                local_8 = 0;
              }
            }
            else if (local_8e[2] == 0xd) {
              if (local_8 != 0) goto LAB_1000_d090;
            }
            else {
              iVar2 = FUN_1000_d8f6(local_8e[2]);
              if (iVar2 != 0) {
                pcVar1 = local_9e + local_8;
                local_8 = local_8 + 1;
                *pcVar1 = (char)local_8e[2];
                if (0xe < local_8) {
                  local_8 = 0xe;
                }
              }
            }
            FUN_1000_d551(local_9e,0xe);
          }
        }
        else if (((iVar2 == 7) && (0x7f < (uint)local_8e[2])) && ((uint)local_8e[2] < 0x82)) {
          FUN_1000_d8b6(local_9e,local_88 + local_a2 * 0x10);
          FUN_1000_d551(local_9e,0xe);
          if (local_8e[2] == 0x80) {
            local_a2 = local_a2 + -1;
          }
          else {
            local_a2 = local_a2 + 1;
          }
          if (7 < local_a2) {
            local_a2 = 0;
          }
          if (local_a2 < 0) {
            local_a2 = 7;
          }
          local_8 = FUN_1000_d8b6(local_9e,local_88 + local_a2 * 0x10);
          local_aa = 1;
        }
      }
    } while (local_8e[2] != 1);
    local_8c = FUN_1000_ea5b();
    local_8a = (int)local_8c >> 0xf;
    local_a0 = FUN_1000_d840(*(undefined2 *)0x933a,*(undefined2 *)0x935e,1);
    if (local_a0 < 8) {
      FUN_1000_d8b6(local_9e,local_88 + local_a2 * 0x10);
      FUN_1000_d551(local_9e,0xe);
      local_a2 = local_a0;
      local_8 = FUN_1000_d8b6(local_9e,local_88 + local_a0 * 0x10);
      local_aa = 1;
LAB_1000_d269:
      if (((local_8a - local_a6 != (uint)(local_8c < local_a8)) || (9 < local_8c - local_a8)) ||
         (local_a2 != local_a4)) {
        local_a8 = local_8c;
        local_a6 = local_8a;
        local_a4 = local_a2;
        goto LAB_1000_cf65;
      }
    }
    else {
      if (local_a0 == 8) {
        iVar2 = FUN_1000_d92e(8,1);
        if (iVar2 != 0) goto LAB_1000_d2c4;
        goto LAB_1000_d269;
      }
      if (((local_a0 != 9) || (local_8 == 0)) || (iVar2 = FUN_1000_d92e(9,1), iVar2 == 0))
      goto LAB_1000_d269;
LAB_1000_d090:
      local_9e[local_8] = '\0';
      FUN_1000_f142(local_88 + local_a2 * 0x10,local_9e);
    }
    if (local_8 != 0) {
      local_a4 = (uint)abStack_79[local_a2 * 0x10];
      if (local_a4 == 0xff) {
        local_a4 = *(uint *)0x52d4;
      }
      FUN_1000_f142(local_4 + local_a4 * 0x30 + 0x10,local_88 + local_a2 * 0x10);
      FUN_1000_8cfa(local_4 + local_a4 * 0x30 + 0x1f);
      FUN_1000_931c(local_4,local_a4);
      FUN_1000_d90e();
      FUN_1000_d601(local_4);
      return;
    }
  } while( true );
}



/* ---- FUN_1000_d2cc @ 1000:d2cc ---- */

void FUN_1000_d2cc()

{
  undefined2 unaff_DS;
  
  FUN_1000_5b00(1);
  *(undefined2 *)0x52d2 = 0xffff;
  return;
}



/* ---- FUN_1000_d2dd @ 1000:d2dd ---- */

void FUN_1000_d2dd()

{
  int param_1 = 0; undefined1 * param_2 = 0;
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 unaff_DS;
  undefined1 *local_4;
  
  FUN_1000_8a96(param_2,0x80,0);
  local_4 = param_2;
  iVar2 = 0;
  do {
    *local_4 = 0;
    local_4[0xf] = 0xff;
    iVar2 = iVar2 + 1;
    local_4 = local_4 + 0x10;
  } while (iVar2 != 8);
  iVar2 = 0;
  for (iVar3 = 0; iVar3 != 8; iVar3 = iVar3 + 1) {
    pcVar1 = (char *)(param_1 + iVar3 * 0x30 + 0x10);
    iVar4 = iVar2;
    if (*pcVar1 != '\0') {
      FUN_1000_f142(param_2 + iVar2 * 0x10,pcVar1);
      iVar4 = iVar2 + 1;
      param_2[iVar2 * 0x10 + 0xf] = (char)iVar3;
    }
    iVar2 = iVar4;
  }
  *(int *)0x52d4 = iVar2;
  return;
}



/* ---- FUN_1000_d365 @ 1000:d365 ---- */

void FUN_1000_d365()

{
  int param_1 = 0; undefined2 param_2 = 0;
  undefined2 uVar1;
  undefined2 unaff_DS;
  int iVar2;
  
  uVar1 = FUN_1000_f174(param_2,0x5176);
  FUN_1000_d440(uVar1);
  FUN_1000_d474(uVar1);
  FUN_1000_d4db(uVar1);
  FUN_1000_5b18(*(undefined2 *)0x9360);
  iVar2 = 0;
  do {
    FUN_1000_5b3d(0x40,iVar2 * 10 + 0x44);
    uVar1 = FUN_1000_f1a0(iVar2 * 0x10 + param_1);
    FUN_1000_d551(iVar2 * 0x10 + param_1,uVar1);
    iVar2 = iVar2 + 1;
  } while (iVar2 != 8);
  iVar2 = FUN_1000_f1a0(param_2);
  if (9 < iVar2) {
    iVar2 = 9;
  }
  FUN_1000_5b3d(-(iVar2 * 4 + -0xe2),0x54);
  FUN_1000_d551(0x517b,iVar2);
  FUN_1000_5b3d(-(iVar2 * 4 + -0xe2),0x4e);
  FUN_1000_d551(param_2,iVar2);
  return;
}



/* ---- FUN_1000_d440 @ 1000:d440 ---- */

void FUN_1000_d440()

{
  undefined2 unaff_DS;
  
  FUN_1000_5b18(*(undefined2 *)0x8dde);
  FUN_1000_d528(0,0,0xd0,0x59);
  FUN_1000_1780(0x33,0x33,0x10b,0x94,*(undefined2 *)0x8dde);
  return;
}



/* ---- FUN_1000_d474 @ 1000:d474 ---- */

void FUN_1000_d474(int param_1)

{
  undefined2 unaff_DS;
  
  FUN_1000_5b18(*(undefined2 *)0x8d22);
  FUN_1000_2079(0x3a,0x3a,0xbd,0x8d);
  FUN_1000_2079(0x3b,0x3b,0xbc,0x8c);
  FUN_1000_2079(200,0x81,0xfd,0x8d);
  if (param_1 != 0) {
    FUN_1000_2079(200,0x6d,0xfd,0x79);
  }
  return;
}



/* ---- FUN_1000_d4db @ 1000:d4db ---- */

void FUN_1000_d4db(int param_1)

{
  undefined2 unaff_DS;
  
  FUN_1000_5b18(*(undefined2 *)0x9360);
  FUN_1000_5b3d(0xd3,0x76);
  if (param_1 != 0) {
    FUN_1000_d551(0x5185,4);
  }
  FUN_1000_5b3d(0xcc,0x8a);
  FUN_1000_d551(0x518a,6);
  return;
}



/* ---- FUN_1000_d528 @ 1000:d528 ---- */

void FUN_1000_d528(int param_1,int param_2,int param_3,int param_4)

{
  FUN_1000_10d3(0x1000,param_1 + 0x37,param_2 + 0x37,param_3 + 0x37,param_4 + 0x37);
  return;
}



/* ---- FUN_1000_d551 @ 1000:d551 ---- */

void FUN_1000_d551()

{
  int param_1 = 0; int param_2 = 0;
  undefined2 unaff_DS;
  undefined1 local_4;
  
  if (param_2 != 0) {
    local_4 = *(undefined1 *)(param_2 + param_1);
    *(undefined1 *)(param_2 + param_1) = 0;
  }
  *(int *)0x2b2a = param_1;
  FUN_1000_e915(0x2b28,*(undefined2 *)0x8d26,*(int *)0x8d2a + -6);
  if (param_2 != 0) {
    *(undefined1 *)(param_2 + param_1) = local_4;
  }
  return;
}



/* ---- FUN_1000_d59d @ 1000:d59d ---- */

bool FUN_1000_d59d()

{
  undefined2 param_1 = 0;
  int iVar1;
  undefined1 local_22 [32];
  
  FUN_1000_d65a(local_22);
  FUN_1000_cb50();
  FUN_1000_ca56(1);
  iVar1 = FUN_1000_ed5a(local_22,0);
  if (iVar1 != -1) {
    FUN_1000_eefe(iVar1,param_1,0x200);
    FUN_1000_ecc0(iVar1);
  }
  else {
    FUN_1000_8a96(param_1,0x200,0);
  }
  return iVar1 != -1;
}



/* ---- FUN_1000_d601 @ 1000:d601 ---- */

bool FUN_1000_d601()

{
  undefined2 param_1 = 0;
  int iVar1;
  undefined1 local_22 [32];
  
  FUN_1000_d65a(local_22);
  FUN_1000_cb50();
  FUN_1000_ca56(1);
  iVar1 = FUN_1000_ed5a(local_22,0x101,0x180);
  if (iVar1 != -1) {
    FUN_1000_efda(iVar1,param_1,0x200);
    FUN_1000_ecc0(iVar1);
  }
  return iVar1 != -1;
}



/* ---- FUN_1000_d65a @ 1000:d65a ---- */

void FUN_1000_d65a()

{
  undefined2 param_1 = 0;
  FUN_1000_f142(param_1,0x5191);
  return;
}



/* ---- FUN_1000_d66c @ 1000:d66c ---- */

void FUN_1000_d66c()

{
  int param_1 = 0; int param_2 = 0;
  undefined2 unaff_DS;
  char local_16 [16];
  char *local_6;
  char *local_4;
  
  if (param_1 != *(int *)0x52d2) {
    if (*(int *)0x52d2 != -1) {
      FUN_1000_8a96(local_16,0xf,0x20);
      local_6 = local_16;
      local_4 = (char *)(param_2 + *(int *)0x52d2 * 0x10);
      while (*local_4 != '\0') {
        *local_6 = *local_4;
        local_6 = local_6 + 1;
        local_4 = local_4 + 1;
      }
      *(undefined1 *)0x2b29 = *(undefined1 *)0x8dde;
      FUN_1000_5b3d(0x40,*(int *)0x52d2 * 10 + 0x44);
      FUN_1000_d551(local_16,0xf);
    }
    FUN_1000_8a96(local_16,0xf,0x20);
    local_6 = local_16;
    local_4 = (char *)(param_1 * 0x10 + param_2);
    while (*local_4 != '\0') {
      *local_6 = *local_4;
      local_6 = local_6 + 1;
      local_4 = local_4 + 1;
    }
    *(undefined1 *)0x2b29 = *(undefined1 *)0x9348;
    FUN_1000_5b3d(0x40,param_1 * 10 + 0x44);
    FUN_1000_d551(local_16,0xf);
    *(undefined1 *)0x2b29 = *(undefined1 *)0x8dde;
    *(int *)0x52d2 = param_1;
  }
  return;
}



/* ---- FUN_1000_d766 @ 1000:d766 ---- */

undefined2 FUN_1000_d766()

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  undefined2 unaff_DS;
  undefined1 local_8 [2];
  byte local_6 [2];
  char local_4 [2];
  
  if (*(char *)0x5a == '\0') {
    do {
      do {
        uVar6 = FUN_1000_ea5b();
        *(uint *)0x9884 = uVar6;
        *(int *)0x9886 = (int)uVar6 >> 0xf;
        if ((((int)uVar6 >> 0xf) - *(int *)0xb07c != (uint)(uVar6 < *(uint *)0xb07a)) ||
           (1 < uVar6 - *(uint *)0xb07a)) {
          *(undefined2 *)0x52d6 = 3;
          *(undefined2 *)0x52d8 = 0;
          uVar4 = *(undefined2 *)0x9886;
          *(undefined2 *)0xb07a = *(undefined2 *)0x9884;
          *(undefined2 *)0xb07c = uVar4;
          return 0x52d6;
        }
        iVar5 = FUN_1000_ea32(local_8,local_6,local_4);
      } while (iVar5 == 0);
      *(undefined2 *)0x52d6 = 7;
      *(undefined2 *)0x52d8 = 0;
      if (local_4[0] == 'H') {
        *(undefined2 *)0x52da = 0x80;
        return 0x52d6;
      }
      if (local_4[0] == 'P') {
        *(undefined2 *)0x52da = 0x81;
        return 0x52d6;
      }
    } while (local_6[0] == 0);
    *(undefined2 *)0x52d6 = 6;
    *(undefined2 *)0x52d8 = 0;
    *(uint *)0x52da = (uint)local_6[0];
  }
  else {
    while (*(int *)0x6e == *(int *)0x70) {
      FUN_1000_2301();
    }
    puVar1 = (undefined2 *)*(undefined2 *)0x6e;
    puVar8 = (undefined2 *)0x52d6;
    puVar7 = puVar1;
    for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
      puVar3 = puVar8;
      puVar8 = puVar8 + 1;
      puVar2 = puVar7;
      puVar7 = puVar7 + 1;
      *puVar3 = *puVar2;
    }
    uVar4 = func_0x0000fd4e(0x1000,puVar1);
    *(undefined2 *)0x6e = uVar4;
  }
  return 0x52d6;
}



/* ---- FUN_1000_d840 @ 1000:d840 ---- */

int FUN_1000_d840(int param_1,int param_2,int param_3)

{
  if ((((0x3c < param_1) && (param_1 < 0xbb)) && (0x3c < param_2)) && (param_2 < 0x8b)) {
    return (param_2 + -0x3c) / 10;
  }
  if (((200 < param_1) && (param_1 < 0xfd)) && ((0x81 < param_2 && (param_2 < 0x8d)))) {
    return 8;
  }
  if (((param_3 != 0) && (200 < param_1)) &&
     ((param_1 < 0xfd && ((0x6d < param_2 && (param_2 < 0x79)))))) {
    return 9;
  }
  return 0xff;
}



/* ---- FUN_1000_d8b6 @ 1000:d8b6 ---- */

int FUN_1000_d8b6()

{
  int param_1 = 0; undefined2 param_2 = 0;
  int iVar1;
  undefined2 unaff_DS;
  
  FUN_1000_8a96(param_1,0xf,0x20);
  FUN_1000_f142(param_1,param_2);
  iVar1 = FUN_1000_f1a0(param_1);
  *(undefined1 *)(iVar1 + param_1) = 0x20;
  return iVar1;
}



/* ---- FUN_1000_d8f6 @ 1000:d8f6 ---- */

undefined2 FUN_1000_d8f6(int param_1)

{
  if ((0x1f < param_1) && (param_1 < 0x7f)) {
    return 1;
  }
  return 0;
}



/* ---- FUN_1000_d90e @ 1000:d90e ---- */

void FUN_1000_d90e()

{
  FUN_1000_5b00(0);
  FUN_1000_58b0(0xc,0x42,0x33,0x94);
  return;
}



/* ---- FUN_1000_d92e @ 1000:d92e ---- */

bool FUN_1000_d92e(int param_1,undefined2 param_2)

{
  undefined2 uVar1;
  int *piVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 unaff_DS;
  
  uVar5 = 0x1000;
  do {
    uVar1 = 1;
    uVar4 = uVar5;
    while( true ) {
      FUN_1000_d9c6(param_1,uVar1);
      do {
        piVar2 = (int *)FUN_1000_d766();
        if (((*piVar2 == 4) && (piVar2[1] == 0)) && (piVar2[2] == 0)) {
          FUN_1000_d9c6(param_1,0);
          iVar3 = FUN_1000_d840(*(undefined2 *)0x933a,*(undefined2 *)0x935e,param_2);
          return iVar3 == param_1;
        }
      } while ((*piVar2 != 5) || (piVar2[1] != 0));
      *(int *)0x933a = piVar2[4];
      *(int *)0x935e = piVar2[5];
      uVar5 = 0x11ef;
      func_0x00011f20(uVar4);
      iVar3 = FUN_1000_d840(*(undefined2 *)0x933a,*(undefined2 *)0x935e,param_2);
      if (iVar3 == param_1) break;
      uVar1 = 0;
      uVar4 = uVar5;
    }
  } while( true );
}



/* ---- FUN_1000_d9c6 @ 1000:d9c6 ---- */

void FUN_1000_d9c6(int param_1,int param_2)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  undefined2 uVar2;
  
  if (param_2 == 0) {
    if (*(int *)0x2b2c != -1) {
      FUN_1000_5b18(*(undefined2 *)0x8dde);
      FUN_1000_1f0e(0x1000);
      if (param_1 == 8) {
        FUN_1000_d528(0x91,0x4a,0xc6,0x56);
        FUN_1000_5b3d(0xcc,0x8a);
        FUN_1000_d551(0x51a7,6);
        FUN_1000_5b18(*(undefined2 *)0x8d22);
        uVar2 = 0x8d;
        uVar1 = 0x81;
      }
      else {
        FUN_1000_d528(0x91,0x36,0xc6,0x42);
        FUN_1000_5b3d(0xd3,0x76);
        FUN_1000_d551(0x51ae,4);
        FUN_1000_5b18(*(undefined2 *)0x8d22);
        uVar2 = 0x79;
        uVar1 = 0x6d;
      }
      FUN_1000_2079(200,uVar1,0xfd,uVar2);
      FUN_1000_1ef0(0x11ef);
      *(undefined2 *)0x2b2c = 0xffff;
    }
  }
  else if (param_1 != *(int *)0x2b2c) {
    FUN_1000_5b18(*(undefined2 *)0x9360);
    *(undefined1 *)0x2b28 = *(undefined1 *)0x8dde;
    *(undefined1 *)0x2b29 = *(undefined1 *)0x9360;
    FUN_1000_1f0e(0x1000);
    if (param_1 == 8) {
      FUN_1000_d528(0x91,0x4a,0xc6,0x56);
      FUN_1000_5b3d(0xcc,0x8a);
      uVar2 = 6;
      uVar1 = 0x519b;
    }
    else {
      FUN_1000_d528(0x91,0x36,0xc6,0x42);
      FUN_1000_5b3d(0xd3,0x76);
      uVar2 = 4;
      uVar1 = 0x51a2;
    }
    FUN_1000_d551(uVar1,uVar2);
    *(int *)0x2b2c = param_1;
    FUN_1000_1ef0(0x11ef);
    *(undefined1 *)0x2b28 = *(undefined1 *)0x9360;
    *(undefined1 *)0x2b29 = *(undefined1 *)0x8dde;
    return;
  }
  return;
}



/* ---- FUN_1000_db3d @ 1000:db3d ---- */

int FUN_1000_db3d()

{
  int param_1 = 0; int param_2 = 0;
  undefined2 unaff_DS;
  
  do {
    param_2 = param_2 + 1;
    if (7 < param_2) {
      param_2 = 0;
    }
  } while (*(char *)(param_1 + param_2 * 0x10 + 0xf) == -1);
  return param_2;
}



/* ---- FUN_1000_db65 @ 1000:db65 ---- */

int FUN_1000_db65()

{
  int param_1 = 0; int param_2 = 0;
  undefined2 unaff_DS;
  
  do {
    param_2 = param_2 + -1;
    if (param_2 < 0) {
      param_2 = 7;
    }
  } while (*(char *)(param_1 + param_2 * 0x10 + 0xf) == -1);
  return param_2;
}



/* ---- FUN_1000_db8a @ 1000:db8a ---- */

void FUN_1000_db8a()

{
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  *(undefined2 *)0x9342 = 0x8b2e;
  *(undefined2 *)0x8ae6 = 0x8b2e;
  FUN_1000_0e0d(0x1000);
  FUN_1000_0d30(0x10d3,0x43);
  FUN_1000_0d53(0x10d3);
  return;
}



/* ---- FUN_1000_dbb5 @ 1000:dbb5 ---- */

void FUN_1000_dbb5()

{
  undefined1 *param_1 = 0; int param_2 = 0;
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  uVar1 = 0x1000;
  while (param_2 != 0) {
    func_0x00010de6(uVar1,*param_1);
    param_1 = param_1 + 1;
    param_2 = param_2 + -1;
    uVar1 = 0x10d3;
  }
  return;
}



/* ---- FUN_1000_dbe3 @ 1000:dbe3 ---- */

/* WARNING: Removing unreachable block (ram,0x0001dc37) */
/* WARNING: Removing unreachable block (ram,0x0001dc4b) */

undefined2 FUN_1000_dbe3()

{
  undefined1 *param_1 = 0; int param_2 = 0;
  undefined1 *puVar1;
  ulong uVar2;
  int iVar3;
  undefined2 unaff_DS;
  ulong uVar4;
  
  FUN_1000_ecaa();
  do {
    iVar3 = param_2 + -1;
    if (param_2 == 0) {
      return 0;
    }
    FUN_1000_f204(0);
    uVar2 = uVar4 + 8;
    do {
      if (*(int *)0x8ae6 != *(int *)0x9342) break;
      FUN_1000_f204(0);
    } while (uVar4 < uVar2);
    if (uVar2 <= uVar4) {
      return 0xffff;
    }
    puVar1 = (undefined1 *)*(undefined2 *)0x8ae6;
    *(int *)0x8ae6 = *(int *)0x8ae6 + 1;
    *param_1 = *puVar1;
    param_1 = param_1 + 1;
    param_2 = iVar3;
    if (*(int *)0x8ae6 == -0x7452) {
      *(undefined2 *)0x8ae6 = 0x8b2e;
    }
  } while( true );
}



/* ---- FUN_1000_dc7f @ 1000:dc7f ---- */

void FUN_1000_dc7f()

{
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  *(undefined2 *)0x8ae6 = *(undefined2 *)0x9342;
  return;
}



/* ---- FUN_1000_dc91 @ 1000:dc91 ---- */

int FUN_1000_dc91()

{
  uint uVar1;
  undefined2 unaff_DS;
  undefined2 local_6;
  
  FUN_1000_ecaa();
  uVar1 = *(uint *)0x9342;
  if (uVar1 < *(uint *)0x8ae6) {
    local_6 = (uVar1 - *(int *)0x8ae6) + 0x80;
  }
  else {
    local_6 = uVar1 - *(int *)0x8ae6;
  }
  return local_6;
}



/* ---- FUN_1000_dcca @ 1000:dcca ---- */

void FUN_1000_dcca()

{
  undefined2 unaff_DS;
  
  FUN_1000_ecaa();
  *(undefined2 *)0x2ebe = 0x2f8;
  *(undefined2 *)0x2ebc = 3;
  return;
}



/* ---- FUN_1000_dce2 @ 1000:dce2 ---- */

void FUN_1000_dce2()

{
  char *param_1 = 0;
  int iVar1;
  char *pcVar2;
  undefined2 unaff_DS;
  undefined2 local_14;
  undefined2 local_12;
  char *local_10;
  uint local_e;
  undefined2 uStack_c;
  char **ppcStack_a;
  char *local_8;
  char *pcVar3;
  int iVar4;
  
  FUN_1000_ecaa();
  local_8 = (char *)0x3020;
  local_e = 0;
  local_10 = (char *)((byte)param_1[1] - 2 & 0x7f);
  pcVar3 = param_1;
  for (pcVar2 = local_10; pcVar2 != (char *)0x0; pcVar2 = pcVar2 + -1) {
    *(char *)((int)&local_8 + local_e) = *(char *)((int)&local_8 + local_e) + *pcVar3;
    local_e = local_e ^ 1;
    pcVar3 = pcVar3 + 1;
  }
  ppcStack_a = (char **)param_1;
  uStack_c = 0xdd34;
  local_8 = local_10;
  FUN_1000_dbb5();
  local_8 = (char *)0x2;
  ppcStack_a = &local_8;
  uStack_c = 0xdd42;
  FUN_1000_dbb5();
  iVar4 = 0;
  do {
    local_8 = param_1;
    ppcStack_a = (char **)0xdd4e;
    iVar1 = FUN_1000_ddd3();
    if (iVar1 == -1) {
      local_14 = 0x4a6;
      local_12 = 0x34c6;
      local_8 = (char *)0x4;
      ppcStack_a = (char **)&local_14;
      uStack_c = 0xdd69;
      FUN_1000_dbb5();
      *param_1 = '\0';
    }
    else if (*param_1 == -0x5c) {
      local_8 = local_10;
      ppcStack_a = (char **)param_1;
      uStack_c = 0xdd7d;
      FUN_1000_dbb5();
      local_8 = (char *)0x2;
      ppcStack_a = &local_8;
      uStack_c = 0xdd8b;
      FUN_1000_dbb5();
    }
    else if (*param_1 != -0x5b) {
      local_8 = (char *)0x0;
      ppcStack_a = (char **)0xc;
      uStack_c = 0x51b4;
      local_e = 0xdda3;
      FUN_1000_1296();
      return;
    }
    iVar4 = iVar4 + 1;
  } while ((*param_1 != -0x5b) && (iVar4 < 5));
  if (4 < iVar4) {
    local_8 = (char *)0x0;
    ppcStack_a = (char **)0xc;
    uStack_c = 0x51da;
    local_e = 0xddca;
    FUN_1000_1296();
  }
  return;
}



/* ---- FUN_1000_ddd3 @ 1000:ddd3 ---- */

undefined2 FUN_1000_ddd3()

{
  byte *param_1 = 0;
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  undefined2 unaff_DS;
  undefined2 local_12;
  undefined2 local_10;
  uint local_e;
  byte *local_c;
  byte *local_a;
  int local_8;
  byte _stack_var_fffa[2];
  
  FUN_1000_ecaa();
  do {
    local_8 = 1;
    local_a = param_1;
    local_c = (byte *)0xddee;
    iVar2 = FUN_1000_dbe3();
    if (iVar2 == 0) {
      if ((*param_1 & 0xf0) == 0xa0) {
        local_8 = 1;
        local_a = param_1 + 1;
        local_c = (byte *)0xde0e;
        iVar2 = FUN_1000_dbe3();
        if (iVar2 == 0) {
          local_e = param_1[1] & 0x7f;
          if (local_e < 0x28) {
            local_8 = local_e - 2;
            local_a = param_1 + 2;
            local_c = (byte *)0xde36;
            iVar2 = FUN_1000_dbe3();
            if (iVar2 == 0) {
              local_c = (byte *)0x0;
              pbVar3 = param_1;
              for (local_a = (byte *)(local_e - 2); local_a != (byte *)0x0;
                  local_a = (byte *)((int)local_a + -1)) {
                pbVar1 = pbVar3;
                pbVar3 = pbVar3 + 1;
                _stack_var_fffa[(int)local_c] = _stack_var_fffa[(int)local_c] + *pbVar1;
                local_c = (byte *)((uint)local_c ^ 1);
              }
              if ((*pbVar3 == 0x20) && (pbVar3[1] == 0x30)) {
                if (*param_1 == 0xa6) {
                  if (*(char *)0x2ec0 == '\0') {
                    local_12 = 0x4a5;
                    local_10 = 0x34c5;
                  }
                  else {
                    local_12 = 0x4a4;
                    local_10 = 0x34c4;
                  }
                  local_8 = 4;
                  local_a = (byte *)&local_12;
                  local_c = (byte *)0xdeb6;
                  FUN_1000_dbb5();
                }
                else {
                  if (*param_1 != 0xaa) {
                    return 0;
                  }
                  *(undefined1 *)0x11a6 = 1;
                }
                local_8 = -0x212f;
                iVar2 = FUN_1000_dc91();
                if (iVar2 != 0) {
                  local_8 = 1;
                }
              }
              else {
                local_8 = -0x2121;
                FUN_1000_dc7f();
                *(undefined1 *)0x2ec0 = 1;
              }
            }
          }
          else {
            local_8 = 0xdee9;
            FUN_1000_dc7f();
            local_8 = 1;
          }
        }
      }
      else if (*param_1 < 0x80) {
        pbVar3 = param_1;
        if (*param_1 != 10) {
          while (*pbVar3 != 0xd) {
            if (0x1f < *pbVar3) {
              pbVar3 = pbVar3 + 1;
            }
            local_8 = 1;
            local_c = (byte *)0xdf0f;
            local_a = pbVar3;
            iVar2 = FUN_1000_dbe3();
            if (iVar2 == -1) {
              *pbVar3 = 0xd;
            }
          }
          *pbVar3 = 0;
          if ((*param_1 != 0) &&
             ((((*param_1 != 0x41 || (param_1[1] != 0x54)) || (param_1[2] != 0x45)) ||
              (param_1[3] != 0)))) {
            local_8 = 0;
            local_a = (byte *)0xc;
            local_c = param_1;
            local_e = 0xdf44;
            FUN_1000_1296();
          }
        }
        local_8 = -0x20b6;
        iVar2 = FUN_1000_dc91();
        if (iVar2 != 0) {
          local_8 = 1;
        }
      }
      else {
        local_8 = -0x20a8;
        FUN_1000_dc7f();
        *(undefined1 *)0x2ec0 = 1;
      }
    }
  } while (local_8 != 0);
  return 0xffff;
}



/* ---- FUN_1000_df71 @ 1000:df71 ---- */

void FUN_1000_df71()

{
  undefined2 unaff_DS;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 auStack_2a [34];
  undefined2 uStack_8;
  undefined1 *puStack_6;
  
  FUN_1000_ecaa();
  if ((*(int *)0x53c == 2) || (*(int *)0x53e == 2)) {
    local_2c = 0xa1;
    local_2b = 0x25;
    puStack_6 = auStack_2a;
    uStack_8 = 0xdf9a;
    FUN_1000_8cfa();
    puStack_6 = &local_2c;
    uStack_8 = 0xdfa4;
    FUN_1000_dce2();
  }
  return;
}



/* ---- FUN_1000_dfac @ 1000:dfac ---- */

void FUN_1000_dfac()

{
  undefined1 * param_1 = 0;
  undefined2 unaff_DS;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined2 uStack_8;
  undefined1 *puStack_6;
  
  FUN_1000_ecaa();
  local_2c = 0xa2;
  local_2b = 6;
  local_2a = *param_1;
  local_29 = param_1[2];
  puStack_6 = &local_2c;
  uStack_8 = 0xdfdb;
  FUN_1000_dce2();
  return;
}



/* ---- FUN_1000_dfe3 @ 1000:dfe3 ---- */

void FUN_1000_dfe3(undefined1 param_1)

{
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined2 uStack_8;
  undefined1 *puStack_6;
  
  FUN_1000_ecaa();
  local_2c = 0xa9;
  local_2b = 5;
  local_2a = param_1;
  puStack_6 = &local_2c;
  uStack_8 = 0xe007;
  FUN_1000_dce2();
  return;
}



/* ---- FUN_1000_e00f @ 1000:e00f ---- */

void FUN_1000_e00f()

{
  undefined2 unaff_DS;
  undefined2 **local_6;
  undefined2 local_4;
  
  local_4 = 0xe018;
  FUN_1000_ecaa();
  local_4 = 4;
  local_6 = &local_6;
  FUN_1000_dbb5();
  *(undefined1 *)0x2ec0 = 0;
  return;
}



/* ---- FUN_1000_e03a @ 1000:e03a ---- */

void FUN_1000_e03a()

{
  undefined2 *puVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined2 *unaff_SI;
  undefined2 *puVar5;
  undefined2 unaff_DS;
  
  FUN_1000_e3ea();
  *(undefined2 *)0x30c8 = *unaff_SI;
  *(undefined2 *)0x30ca = unaff_SI[1];
  puVar5 = (undefined2 *)0x30cc;
  for (iVar4 = 0x200; iVar4 != 0; iVar4 = iVar4 + -1) {
    puVar1 = puVar5;
    puVar5 = puVar5 + 1;
    *puVar1 = 0;
  }
  uVar3 = 0x10;
  FUN_1000_e077();
  *(int *)0x30c6 = (int)(unaff_SI + 5);
  *(undefined2 *)0x30c2 = uVar2;
  *(undefined1 *)0x30c4 = uVar3;
  FUN_1000_e0d8();
  return;
}



/* ---- FUN_1000_e077 @ 1000:e077 ---- */

void FUN_1000_e077()

{
  undefined2 extraout_DX;
  int in_BX;
  int unaff_DI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  FUN_1000_e0b6();
  if (!(bool)in_CF) {
    FUN_1000_e077();
    FUN_1000_e0b6();
    FUN_1000_e077();
    return;
  }
  FUN_1000_e0a8();
  *(undefined2 *)(unaff_DI * 4 + 0x30cc) = extraout_DX;
  *(int *)(unaff_DI * 4 + 0x30ce) = in_BX;
  if (0x10 < in_BX) {
    FUN_1000_e410();
  }
  return;
}



/* ---- FUN_1000_e0a8 @ 1000:e0a8 ---- */

void FUN_1000_e0a8()

{
  char cVar1;
  
  cVar1 = '\b';
  do {
    FUN_1000_e0b6();
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return;
}



/* ---- FUN_1000_e0b6 @ 1000:e0b6 ---- */

int FUN_1000_e0b6()

{
  int in_AX;
  char in_CL;
  undefined2 *unaff_SI;
  undefined2 unaff_DS;
  
  if (in_CL != '\0') {
    return in_AX << 1;
  }
  if (unaff_SI != (undefined2 *)0x30c2) {
    return CONCAT11((char)*unaff_SI,(char)((uint)*unaff_SI >> 8)) << 1;
  }
  FUN_1000_e3ea();
  return CONCAT11((char)*(undefined2 *)0x30c2,(char)((uint)*(undefined2 *)0x30c2 >> 8)) << 1;
}



/* ---- FUN_1000_e0d8 @ 1000:e0d8 ---- */

void FUN_1000_e0d8()

{
  byte *pbVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  char cVar6;
  byte bVar7;
  byte *pbVar8;
  undefined1 *puVar9;
  byte *pbVar10;
  undefined2 *puVar11;
  undefined2 unaff_DS;
  
  pbVar8 = (byte *)0x30cc;
  puVar9 = (undefined1 *)0x38cc;
  cVar5 = '\0';
LAB_1000_e0e5:
  do {
    bVar7 = pbVar8[2];
    if (bVar7 != 0) {
      if ('\b' < (char)bVar7) {
        bVar7 = (byte)((uint)(*(int *)pbVar8 << (0x10 - bVar7 & 0x1f)) >> 8);
        *(byte *)0x44d5 = bVar7;
        iVar3 = (uint)bVar7 * 4;
        *(undefined2 *)(iVar3 + 0x34cc) = 0;
        *(undefined2 *)(iVar3 + 0x34ce) = puVar9;
        pbVar10 = pbVar8;
        cVar6 = cVar5;
        do {
          bVar7 = pbVar10[2];
          if (('\b' < (char)bVar7) &&
             (iVar3 = *(int *)pbVar10 << (0x10 - bVar7 & 0x1f),
             (char)((uint)iVar3 >> 8) == *(char *)0x44d5)) {
            puVar9[1] = (char)iVar3;
            puVar9[2] = cVar6;
            puVar9[3] = bVar7 - 8;
            *puVar9 = *(undefined1 *)((byte)(bVar7 - 8) + 0x44cc);
            (pbVar10 + 2)[0] = 0;
            (pbVar10 + 2)[1] = 0;
            puVar9 = puVar9 + 4;
          }
          pbVar10 = pbVar10 + 4;
          cVar6 = cVar6 + '\x01';
        } while (cVar6 != '\0');
        goto LAB_1000_e0e5;
      }
      iVar3 = (uint)*pbVar8 << (-bVar7 + 10 & 0x1f);
      pbVar10 = (byte *)(iVar3 + 0x34cc);
      *pbVar10 = bVar7;
      *(char *)(iVar3 + 0x34cd) = cVar5;
      *(undefined2 *)(iVar3 + 0x34ce) = 0;
      iVar4 = (1 << (-bVar7 + 8 & 0x1f)) + -1;
      if (iVar4 != 0) {
        puVar11 = (undefined2 *)(iVar3 + 0x34d0);
        for (iVar4 = iVar4 * 2; iVar4 != 0; iVar4 = iVar4 + -1) {
          puVar2 = puVar11;
          puVar11 = puVar11 + 1;
          pbVar1 = pbVar10;
          pbVar10 = pbVar10 + 2;
          *puVar2 = *(undefined2 *)pbVar1;
        }
      }
    }
    pbVar8 = pbVar8 + 4;
    cVar5 = cVar5 + '\x01';
    if (cVar5 == '\0') {
      return;
    }
  } while( true );
}



/* ---- FUN_1000_e197 @ 1000:e197 ---- */

undefined2 FUN_1000_e197()

{
  char *param_1 = 0; uint param_2 = 0; int param_3 = 0;
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  undefined1 *puVar4;
  char *pcVar5;
  undefined2 uVar6;
  undefined1 uVar7;
  char cVar8;
  byte bVar9;
  uint in_CX;
  char cVar10;
  byte bVar11;
  byte extraout_DL;
  uint extraout_DX;
  uint uVar12;
  uint extraout_DX_00;
  int iVar13;
  undefined2 *puVar14;
  undefined1 *puVar15;
  char *pcVar16;
  int iVar17;
  undefined2 unaff_DS;
  undefined4 uVar18;
  
  uVar12 = 0;
  if (param_3 != 0) {
    FUN_1000_e410();
    uVar12 = (uint)((ulong)uVar18 >> 0x10);
    param_2 = (uint)uVar18;
  }
  if ((*(uint *)0x30c8 < param_2) && (*(uint *)0x30ca <= uVar12)) {
    param_2 = *(uint *)0x30c8;
    uVar12 = *(uint *)0x30ca;
  }
  puVar1 = (uint *)0x30ca;
  uVar3 = *puVar1;
  *puVar1 = *puVar1 - uVar12;
  *(int *)0x30c8 = (*(int *)0x30c8 - param_2) - (uint)(uVar3 < uVar12);
  *(uint *)0x44d8 = param_2;
  *(uint *)0x44d6 = param_2;
  iVar17 = (int)((ulong)param_1 >> 0x10);
  pcVar16 = (char *)param_1;
  puVar15 = (undefined1 *)*(undefined2 *)0x30c6;
  FUN_1000_e3ba();
  uVar12 = extraout_DX;
  do {
    iVar13 = (uVar12 >> 8) * 4;
    bVar11 = (byte)*(undefined2 *)(iVar13 + 0x34cc);
    cVar8 = (char)((uint)*(undefined2 *)(iVar13 + 0x34cc) >> 8);
    cVar10 = (char)(in_CX >> 8);
    if (bVar11 == 0) {
      cVar8 = (char)uVar12;
      bVar9 = cVar10 - 8;
      bVar11 = cVar8 << (bVar9 & 0xf) | (byte)(CONCAT11(cVar8,cVar8) >> 0x10 - (bVar9 & 0xf));
      puVar4 = puVar15;
      puVar15 = puVar15 + 1;
      uVar7 = *puVar4;
      if (puVar15 == (undefined1 *)0x30c2) {
        uVar7 = FUN_1000_e3ea();
        bVar11 = extraout_DL;
      }
      uVar12 = CONCAT11(uVar7,bVar11) >> (bVar9 & 0xf) |
               CONCAT11(uVar7,bVar11) << 0x10 - (bVar9 & 0xf);
      puVar14 = (undefined2 *)*(undefined2 *)(iVar13 + 0x34ce);
      while ((byte)((byte)*puVar14 & (byte)(uVar12 >> 8)) != (byte)((uint)*puVar14 >> 8)) {
        puVar14 = puVar14 + 2;
      }
      uVar6 = puVar14[1];
      pcVar5 = pcVar16;
      pcVar16 = pcVar16 + 1;
      cVar8 = (char)uVar6;
      *pcVar5 = cVar8;
      *(char *)0x44df = *(char *)0x44df + cVar8;
      if (pcVar16 == (char *)0x0) {
        iVar17 = iVar17 + 0x1000;
        pcVar16 = (char *)0x0;
      }
      bVar11 = (byte)((uint)uVar6 >> 8);
      bVar9 = bVar11 & 0xf;
      uVar12 = uVar12 << bVar9 | uVar12 >> 0x10 - bVar9;
      bVar11 = cVar10 - bVar11;
    }
    else {
      pcVar5 = pcVar16;
      pcVar16 = pcVar16 + 1;
      *pcVar5 = cVar8;
      *(char *)0x44df = *(char *)0x44df + cVar8;
      if (pcVar16 == (char *)0x0) {
        iVar17 = iVar17 + 0x1000;
        pcVar16 = (char *)0x0;
      }
      uVar12 = uVar12 << (bVar11 & 0xf) | uVar12 >> 0x10 - (bVar11 & 0xf);
      bVar11 = cVar10 - bVar11;
    }
    in_CX = (uint)bVar11 << 8;
    if ((char)bVar11 < '\b') {
      puVar4 = puVar15;
      puVar15 = puVar15 + 1;
      uVar12 = CONCAT11(*puVar4,(byte)(uVar12 << (bVar11 & 0xf)) |
                                (byte)(uVar12 >> 0x10 - (bVar11 & 0xf)));
      uVar12 = uVar12 >> (bVar11 & 0xf) | uVar12 << 0x10 - (bVar11 & 0xf);
      in_CX = (uint)(byte)(bVar11 + 8) << 8;
      if (puVar15 == (undefined1 *)0x30c2) {
        FUN_1000_e3ea();
        uVar12 = extraout_DX_00;
      }
    }
    piVar2 = (int *)0x44d6;
    *piVar2 = *piVar2 + -1;
  } while (*piVar2 != 0);
  *(int *)0x30c6 = (int)puVar15;
  *(uint *)0x30c2 = uVar12;
  *(uint *)0x30c4 = in_CX >> 8;
  return *(undefined2 *)0x44d8;
}



/* ---- FUN_1000_e282 @ 1000:e282 ---- */

char * FUN_1000_e282()

{
  char * param_1 = 0; uint param_2 = 0; int param_3 = 0; uint param_4 = 0;
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  undefined1 *puVar4;
  char *pcVar5;
  undefined2 uVar6;
  undefined1 uVar7;
  char cVar8;
  byte bVar9;
  uint in_CX;
  char cVar10;
  byte bVar11;
  byte extraout_DL;
  uint extraout_DX;
  uint uVar12;
  uint extraout_DX_00;
  int iVar13;
  undefined2 *puVar14;
  undefined1 *puVar15;
  char *pcVar16;
  int iVar17;
  undefined2 unaff_DS;
  undefined4 uVar18;
  
  uVar12 = 0;
  if (param_3 != 0) {
    FUN_1000_e410();
    uVar12 = (uint)((ulong)uVar18 >> 0x10);
    param_2 = (uint)uVar18;
  }
  if ((*(uint *)0x30c8 < param_2) && (*(uint *)0x30ca <= uVar12)) {
    param_2 = *(uint *)0x30c8;
    uVar12 = *(uint *)0x30ca;
  }
  puVar1 = (uint *)0x30ca;
  uVar3 = *puVar1;
  *puVar1 = *puVar1 - uVar12;
  *(int *)0x30c8 = (*(int *)0x30c8 - param_2) - (uint)(uVar3 < uVar12);
  *(uint *)0x44d8 = param_2;
  *(uint *)0x44d6 = param_2;
  iVar17 = (int)((ulong)param_1 >> 0x10);
  pcVar16 = (char *)param_1;
  puVar15 = (undefined1 *)*(undefined2 *)0x30c6;
  *(uint *)0x44d8 = param_4;
  FUN_1000_e3ba();
  uVar12 = extraout_DX;
  do {
    iVar13 = (uVar12 >> 8) * 4;
    bVar11 = (byte)*(undefined2 *)(iVar13 + 0x34cc);
    cVar8 = (char)((uint)*(undefined2 *)(iVar13 + 0x34cc) >> 8);
    cVar10 = (char)(in_CX >> 8);
    if (bVar11 == 0) {
      cVar8 = (char)uVar12;
      bVar9 = cVar10 - 8;
      bVar11 = cVar8 << (bVar9 & 0xf) | (byte)(CONCAT11(cVar8,cVar8) >> 0x10 - (bVar9 & 0xf));
      puVar4 = puVar15;
      puVar15 = puVar15 + 1;
      uVar7 = *puVar4;
      if (puVar15 == (undefined1 *)0x30c2) {
        uVar7 = FUN_1000_e3ea();
        bVar11 = extraout_DL;
      }
      uVar12 = CONCAT11(uVar7,bVar11) >> (bVar9 & 0xf) |
               CONCAT11(uVar7,bVar11) << 0x10 - (bVar9 & 0xf);
      puVar14 = (undefined2 *)*(undefined2 *)(iVar13 + 0x34ce);
      while ((byte)((byte)*puVar14 & (byte)(uVar12 >> 8)) != (byte)((uint)*puVar14 >> 8)) {
        puVar14 = puVar14 + 2;
      }
      uVar6 = puVar14[1];
      pcVar5 = pcVar16;
      pcVar16 = pcVar16 + 1;
      cVar8 = (char)uVar6;
      *pcVar5 = cVar8;
      *(char *)0x44df = *(char *)0x44df + cVar8;
      if (pcVar16 == (char *)0x0) {
        iVar17 = iVar17 + 0x1000;
        pcVar16 = (char *)0x0;
      }
      bVar11 = (byte)((uint)uVar6 >> 8);
      bVar9 = bVar11 & 0xf;
      uVar12 = uVar12 << bVar9 | uVar12 >> 0x10 - bVar9;
      bVar11 = cVar10 - bVar11;
    }
    else {
      pcVar5 = pcVar16;
      pcVar16 = pcVar16 + 1;
      *pcVar5 = cVar8;
      *(char *)0x44df = *(char *)0x44df + cVar8;
      if (pcVar16 == (char *)0x0) {
        iVar17 = iVar17 + 0x1000;
        pcVar16 = (char *)0x0;
      }
      uVar12 = uVar12 << (bVar11 & 0xf) | uVar12 >> 0x10 - (bVar11 & 0xf);
      bVar11 = cVar10 - bVar11;
    }
    in_CX = (uint)bVar11 << 8;
    if ((char)bVar11 < '\b') {
      puVar4 = puVar15;
      puVar15 = puVar15 + 1;
      uVar12 = CONCAT11(*puVar4,(byte)(uVar12 << (bVar11 & 0xf)) |
                                (byte)(uVar12 >> 0x10 - (bVar11 & 0xf)));
      uVar12 = uVar12 >> (bVar11 & 0xf) | uVar12 << 0x10 - (bVar11 & 0xf);
      in_CX = (uint)(byte)(bVar11 + 8) << 8;
      if (puVar15 == (undefined1 *)0x30c2) {
        FUN_1000_e3ea();
        uVar12 = extraout_DX_00;
      }
    }
    param_4 = param_4 - 1;
    if (param_4 == 0) {
      *pcVar16 = '\0';
      param_4 = *(uint *)0x44d8;
      if (((param_4 & 1) != 0) && (pcVar16 = pcVar16 + (param_4 & 1), pcVar16 == (char *)0x0)) {
        iVar17 = iVar17 + 0x1000;
        pcVar16 = (char *)0x0;
      }
    }
    piVar2 = (int *)0x44d6;
    *piVar2 = *piVar2 + -1;
  } while (*piVar2 != 0);
  *(int *)0x30c6 = (int)puVar15;
  *(uint *)0x30c2 = uVar12;
  *(uint *)0x30c4 = in_CX >> 8;
  return (char *)CONCAT22(iVar17,pcVar16);
}



/* ---- FUN_1000_e394 @ 1000:e394 ---- */

void FUN_1000_e394(int param_1)

{
  byte bVar1;
  uint uVar2;
  code *extraout_DX;
  undefined2 *unaff_SI;
  undefined2 unaff_DS;
  
  FUN_1000_e3ea();
  uVar2 = CONCAT11((char)*unaff_SI,(char)((uint)*unaff_SI >> 8));
  bVar1 = (byte)param_1 & 0xf;
  *(uint *)0x30c2 = uVar2 << bVar1 | uVar2 >> 0x10 - bVar1;
  *(int *)0x30c4 = -(param_1 + -0x10);
  *(int *)0x30c6 = (int)(unaff_SI + 1);
  *(undefined1 *)0x44df = 0;
                    /* WARNING: Could not recover jumptable at 0x0001e3b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*extraout_DX)();
  return;
}



/* ---- FUN_1000_e3ba @ 1000:e3ba ---- */

void FUN_1000_e3ba()

{
  int iVar1;
  undefined2 unaff_DS;
  
  if ((char)*(undefined2 *)0x30c4 < '\t') {
    iVar1 = *(int *)0x30c6;
    if (iVar1 == 0x30c2) {
      FUN_1000_e3ea();
    }
    if (iVar1 == 0x30c1) {
      FUN_1000_e3ea();
    }
  }
  return;
}



/* ---- FUN_1000_e3ea @ 1000:e3ea ---- */

undefined4 FUN_1000_e3ea()

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  int iVar3;
  undefined2 in_DX;
  undefined2 *puVar4;
  undefined2 unaff_DS;
  
  if (*(char *)0x44de == '\0') {
    FUN_1000_cb8f(0x2ec2);
    return CONCAT22(in_DX,in_AX);
  }
  DAT_6000_10fc = (*(uint *)0x44da >> 4) + *(int *)0x44dc;
  DAT_6000_10fa = (undefined2 *)(*(uint *)0x44da & 0xf);
  puVar4 = (undefined2 *)0x2ec2;
  for (iVar3 = 0x100; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = puVar4;
    puVar4 = puVar4 + 1;
    puVar1 = DAT_6000_10fa;
    DAT_6000_10fa = DAT_6000_10fa + 1;
    *puVar2 = *puVar1;
  }
  return CONCAT22(in_DX,in_AX);
}



/* ---- FUN_1000_e410 @ 1000:e410 ---- */

void FUN_1000_e410()

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



/* ---- FUN_1000_e449 @ 1000:e449 ---- */

void FUN_1000_e449(undefined2 param_1,undefined2 param_2)

{
  undefined2 unaff_DS;
  code *in_stack_00000000;
  
  *(undefined2 *)0x44da = param_1;
  *(undefined2 *)0x44dc = param_2;
  *(undefined1 *)0x44de = 1;
                    /* WARNING: Could not recover jumptable at 0x0001e45a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*in_stack_00000000)();
  return;
}



/* ---- FUN_1000_e45c @ 1000:e45c ---- */

void FUN_1000_e45c()

{
  undefined2 unaff_DS;
  
  *(undefined1 *)0x44de = 0;
  return;
}



/* ---- FUN_1000_e57a @ 1000:e57a ---- */

void FUN_1000_e57a()

{
  int iVar1;
  undefined2 unaff_DS;
  
  iVar1 = *(int *)0x4928;
  if ((iVar1 != 0) && (DAT_1000_e462 = iVar1, *(int *)0x492a != 0)) {
    DAT_1000_e466 = *(undefined2 *)0x492c;
    DAT_1000_e468 = *(undefined2 *)0x492e;
    DAT_1000_e46a = *(undefined2 *)0x4930;
    DAT_1000_e46c = *(undefined2 *)0x4932;
                    /* WARNING: Could not recover jumptable at 0x0001e5f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    DAT_1000_e464 = *(int *)0x492a;
    (*(code *)*(undefined2 *)((*(uint *)0x4924 & 1 | *(int *)0x4926 << 1) * 2 + -0x1a92))();
    return;
  }
  return;
}



/* ---- FUN_1000_e8cb @ 1000:e8cb ---- */

void FUN_1000_e8cb()

{
  undefined4 param_1 = 0; int param_2 = 0; int param_3 = 0;
  byte *pbVar1;
  undefined1 *puVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  
  puVar6 = (undefined1 *)0x32e0;
  uVar3 = (uint)(param_2 * param_3) >> 1;
  iVar4 = ((uint)param_1 >> 4) + (int)((ulong)param_1 >> 0x10) + -0x800;
  pbVar5 = (byte *)(((uint)param_1 & 0xf) + 0x8000);
  do {
    pbVar1 = pbVar5 + 1;
    puVar2 = puVar6 + 1;
    *puVar6 = *(undefined1 *)(ulong)(*pbVar5 + 0xe7cb);
    pbVar5 = pbVar5 + 2;
    puVar6 = puVar6 + 2;
    *puVar2 = *(undefined1 *)(ulong)(*pbVar1 + 0xe7cb);
    uVar3 = uVar3 - 1;
  } while (uVar3 != 0);
  return;
}



/* ---- FUN_1000_e915 @ 1000:e915 ---- */

void FUN_1000_e915()

{
  uint param_1 = 0; undefined2 param_2 = 0;
  char *pcVar1;
  undefined2 *puVar2;
  uint uVar3;
  undefined2 uVar4;
  byte bVar5;
  int iVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte bVar11;
  uint *puVar10;
  char *pcVar12;
  undefined2 *puVar13;
  undefined2 uVar14;
  undefined2 unaff_DS;
  int *in_stack_00000000;
  
  FUN_1000_1f0e(0x1000);
  *(uint *)0x4520 = param_1 >> 1;
  *(undefined2 *)0x4522 = param_2;
  iVar6 = *in_stack_00000000;
  bVar8 = (byte)((uint)iVar6 >> 8);
  bVar11 = (byte)((uint)(iVar6 << 4) >> 8);
  bVar5 = bVar8 | bVar11;
  *(undefined2 *)0x44e0 = CONCAT11(bVar5,bVar5);
  bVar7 = (byte)iVar6;
  *(undefined2 *)0x44e2 = CONCAT11(bVar7 | bVar11,bVar5);
  bVar9 = (byte)(iVar6 << 4);
  *(undefined2 *)0x44e4 = CONCAT11(bVar8 | bVar9,bVar5);
  *(undefined2 *)0x44e6 = CONCAT11(bVar7 | bVar9,bVar5);
  bVar5 = bVar7 | bVar11;
  *(undefined2 *)0x44e8 = CONCAT11(bVar8 | bVar11,bVar5);
  *(undefined2 *)0x44ea = CONCAT11(bVar7 | bVar11,bVar5);
  *(undefined2 *)0x44ec = CONCAT11(bVar8 | bVar9,bVar5);
  *(undefined2 *)0x44ee = CONCAT11(bVar7 | bVar9,bVar5);
  bVar5 = bVar8 | bVar9;
  *(undefined2 *)0x44f0 = CONCAT11(bVar8 | bVar11,bVar5);
  *(undefined2 *)0x44f2 = CONCAT11(bVar7 | bVar11,bVar5);
  *(undefined2 *)0x44f4 = CONCAT11(bVar8 | bVar9,bVar5);
  *(undefined2 *)0x44f6 = CONCAT11(bVar7 | bVar9,bVar5);
  bVar5 = bVar7 | bVar9;
  *(undefined2 *)0x44f8 = CONCAT11(bVar8 | bVar11,bVar5);
  *(undefined2 *)0x44fa = CONCAT11(bVar7 | bVar11,bVar5);
  *(undefined2 *)0x44fc = CONCAT11(bVar8 | bVar9,bVar5);
  *(undefined2 *)0x44fe = CONCAT11(bVar7 | bVar9,bVar5);
  pcVar12 = (char *)in_stack_00000000[1];
  uVar14 = 0x11ef;
  while( true ) {
    pcVar1 = pcVar12;
    pcVar12 = pcVar12 + 1;
    if (*pcVar1 == '\0') break;
    puVar10 = (uint *)((uint)(byte)(*pcVar1 - 0x20) * 8 + 0x4524);
    puVar13 = (undefined2 *)0x4500;
    iVar6 = 4;
    do {
      uVar3 = *puVar10;
      puVar10 = puVar10 + 1;
      *puVar13 = *(undefined2 *)((uVar3 >> 3 & 0x1e) + 0x44e0);
      puVar13[1] = *(undefined2 *)((uVar3 & 0xf) * 2 + 0x44e0);
      bVar5 = (byte)(uVar3 >> 8);
      puVar2 = puVar13 + 3;
      puVar13[2] = *(undefined2 *)((bVar5 >> 3 & 0x1e) + 0x44e0);
      puVar13 = puVar13 + 4;
      *puVar2 = *(undefined2 *)((bVar5 & 0xf) * 2 + 0x44e0);
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    uVar4 = *(undefined2 *)0x4522;
    iVar6 = *(int *)0x4520;
    *(int *)0x4520 = iVar6 + 4;
    func_0x000110d0(uVar14,iVar6,uVar4,4,8,0x4500);
    uVar14 = 0x110d;
  }
  FUN_1000_1ef0(uVar14);
  return;
}



/* ---- FUN_1000_ea32 @ 1000:ea32 ---- */

bool FUN_1000_ea32()

{
  undefined1 *param_1 = 0; undefined1 *param_2 = 0; undefined1 *param_3 = 0;
  code *pcVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  undefined1 in_ZF;
  
  pcVar1 = (code *)swi(0x16);
  (*pcVar1)();
  if (!(bool)in_ZF) {
    pcVar1 = (code *)swi(0x16);
    uVar3 = (*pcVar1)();
    *param_2 = (char)uVar3;
    *param_3 = (char)((uint)uVar3 >> 8);
    pcVar1 = (code *)swi(0x16);
    uVar2 = (*pcVar1)();
    *param_1 = uVar2;
  }
  return !(bool)in_ZF;
}



/* ---- FUN_1000_ea5b @ 1000:ea5b ---- */

undefined4 FUN_1000_ea5b()

{
  code *pcVar1;
  undefined2 in_CX;
  undefined2 extraout_DX;
  
  pcVar1 = (code *)swi(0x1a);
  (*pcVar1)();
  return CONCAT22(in_CX,extraout_DX);
}



/* ---- FUN_1000_ea64 @ 1000:ea64 ---- */

void FUN_1000_ea64()

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)();
  return;
}



/* ---- FUN_1000_eb2a @ 1000:eb2a ---- */

void FUN_1000_eb2a()

{
  uint *puVar1;
  char *pcVar2;
  char *pcVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  char extraout_DH;
  uint extraout_DX;
  undefined2 in_BX;
  int iVar7;
  int unaff_BP;
  int unaff_SI;
  char *pcVar8;
  int unaff_DI;
  char *pcVar9;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar10;
  
  FUN_1000_f470();
  FUN_1000_f6d7();
  (*(code *)*(undefined2 *)0x495c)(0xff);
  *(char *)(unaff_SI + -0x32d0) = *(char *)(unaff_SI + -0x32d0) + extraout_DH;
  puVar1 = (uint *)(unaff_BP + unaff_DI + 0x49d1);
  *puVar1 = *puVar1 & (uint)&_stack_var_0000;
  pcVar4 = (code *)swi(0x21);
  (*pcVar4)();
  *(undefined2 *)0x49bd = in_BX;
  *(undefined2 *)0x49bf = unaff_ES;
  pcVar4 = (code *)swi(0x21);
  (*pcVar4)();
  if (*(int *)0x4bac != 0) {
    bVar10 = false;
    (*(code *)*(undefined2 *)0x4baa)();
    if (bVar10) {
      FUN_1000_f490();
      return;
    }
    (*(code *)*(undefined2 *)0x4baa)();
  }
  iVar7 = *(int *)0x2c;
  if (iVar7 != 0) {
    pcVar9 = (char *)0x0;
    do {
      if (*pcVar9 == '\0') break;
      iVar6 = 0xc;
      pcVar8 = (char *)0x49b0;
      bVar10 = false;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        pcVar3 = pcVar9;
        pcVar9 = pcVar9 + 1;
        pcVar2 = pcVar8;
        pcVar8 = pcVar8 + 1;
        bVar10 = *pcVar2 == *pcVar3;
      } while (bVar10);
      if (bVar10) {
        pcVar8 = (char *)0x49d8;
        iVar6 = (int)*pcVar9;
        do {
          pcVar9 = pcVar9 + 1;
          cVar5 = '\0';
          if (*pcVar9 != -1) {
            cVar5 = *pcVar9;
          }
          pcVar2 = pcVar8;
          pcVar8 = pcVar8 + 1;
          *pcVar2 = cVar5;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        break;
      }
      iVar6 = 0x7fff;
      bVar10 = true;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        pcVar2 = pcVar9;
        pcVar9 = pcVar9 + 1;
        bVar10 = *pcVar2 == '\0';
      } while (!bVar10);
    } while (bVar10);
  }
  iVar7 = 4;
  do {
    bVar10 = false;
    *(byte *)(iVar7 + 0x49d8) = *(byte *)(iVar7 + 0x49d8) & 0xbf;
    pcVar4 = (code *)swi(0x21);
    (*pcVar4)();
    if ((!bVar10) && ((extraout_DX & 0x80) != 0)) {
      *(byte *)(iVar7 + 0x49d8) = *(byte *)(iVar7 + 0x49d8) | 0x40;
    }
    iVar7 = iVar7 + -1;
  } while (-1 < iVar7);
  FUN_1000_ec96();
  FUN_1000_ec87();
  return;
}



/* ---- FUN_1000_ebfe @ 1000:ebfe ---- */

void FUN_1000_ebfe()

{
  undefined2 param_1 = 0; undefined2 param_2 = 0;
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  FUN_1000_ec87();
  FUN_1000_ec87();
  FUN_1000_ec87();
  FUN_1000_ec96();
  FUN_1000_f496();
  iVar2 = 0xf;
  iVar3 = 5;
  do {
    if ((*(byte *)(iVar3 + 0x49d8) & 1) != 0) {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)();
    }
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_1000_ec5a();
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  if (*(int *)0x4bac != 0) {
    (*(code *)*(undefined2 *)0x4baa)();
  }
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  if (*(char *)0x49fa != '\0') {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
  }
  return;
}



/* ---- FUN_1000_ec5a @ 1000:ec5a ---- */

void FUN_1000_ec5a()

{
  undefined2 param_1 = 0;
  code *pcVar1;
  undefined2 unaff_DS;
  
  if (*(int *)0x4bac != 0) {
    (*(code *)*(undefined2 *)0x4baa)(0x1000);
  }
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  if (*(char *)0x49fa != '\0') {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
  }
  return;
}



/* ---- FUN_1000_ec87 @ 1000:ec87 ---- */

void FUN_1000_ec87()

{
  int *unaff_SI;
  int *unaff_DI;
  undefined2 unaff_DS;
  
  while (unaff_SI < unaff_DI) {
    unaff_DI = unaff_DI + -1;
    if ((code *)*unaff_DI != (code *)0x0) {
      (*(code *)*unaff_DI)();
    }
  }
  return;
}



/* ---- FUN_1000_ec96 @ 1000:ec96 ---- */

void FUN_1000_ec96()

{
  int *piVar1;
  int *unaff_SI;
  int *unaff_DI;
  int *piVar2;
  undefined2 unaff_DS;
  
  while (unaff_SI < unaff_DI) {
    piVar2 = unaff_DI + -2;
    piVar1 = unaff_DI + -1;
    unaff_DI = piVar2;
    if (*piVar2 != 0 || *piVar1 != 0) {
      (*(code *)*piVar2)(0x1000);
    }
  }
  return;
}



/* ---- FUN_1000_ecaa @ 1000:ecaa ---- */

void FUN_1000_ecaa()

{
  undefined1 *in_AX;
  undefined2 unaff_DS;
  code *in_stack_00000000;
  
  if ((in_AX <= &_stack_var_0002) && ((undefined1 *)*(uint *)0x4a00 <= &_stack_var_0002 + -(int)in_AX)) {
                    /* WARNING: Could not recover jumptable at 0x0001ecb9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*in_stack_00000000)();
    return;
  }
  FUN_1000_eb2a();
  return;
}



/* ---- FUN_1000_ecc0 @ 1000:ecc0 ---- */

void FUN_1000_ecc0()

{
  uint param_1 = 0;
  code *pcVar1;
  undefined2 unaff_DS;
  bool bVar2;
  
  bVar2 = param_1 < *(uint *)0x49d6;
  if (bVar2) {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    if (!bVar2) {
      *(undefined1 *)(param_1 + 0x49d8) = 0;
    }
  }
  FUN_1000_f700();
  return;
}



/* ---- FUN_1000_ece0 @ 1000:ece0 ---- */

void FUN_1000_ece0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  undefined2 unaff_DS;
  bool bVar5;
  undefined4 uVar6;
  
  if (*(uint *)0x49d6 <= param_1) goto LAB_1000_ed57;
  bVar5 = false;
  if ((param_3 & 0x8000) != 0) {
    if (param_4 == 0) goto LAB_1000_ed57;
    bVar5 = false;
    pcVar2 = (code *)swi(0x21);
    uVar6 = (*pcVar2)();
    uVar3 = (uint)((ulong)uVar6 >> 0x10);
    if (bVar5) goto LAB_1000_ed57;
    if ((param_4 & 2) == 0) {
      uVar1 = (uint)CARRY2((uint)uVar6,param_2);
      bVar5 = CARRY2(uVar3,param_3) || CARRY2(uVar3 + param_3,uVar1);
      if ((int)(uVar3 + param_3 + uVar1) < 0) goto LAB_1000_ed57;
    }
    else {
      pcVar2 = (code *)swi(0x21);
      uVar6 = (*pcVar2)(uVar3);
      uVar4 = (uint)((ulong)uVar6 >> 0x10);
      uVar3 = (uint)CARRY2((uint)uVar6,param_2);
      uVar1 = uVar4 + param_3;
      bVar5 = CARRY2(uVar4,param_3) || CARRY2(uVar1,uVar3);
      if ((int)(uVar1 + uVar3) < 0) {
        pcVar2 = (code *)swi(0x21);
        (*pcVar2)();
        goto LAB_1000_ed57;
      }
    }
  }
  pcVar2 = (code *)swi(0x21);
  (*pcVar2)();
  if (!bVar5) {
    *(byte *)(param_1 + 0x49d8) = *(byte *)(param_1 + 0x49d8) & 0xfd;
  }
LAB_1000_ed57:
  FUN_1000_f713();
  return;
}



/* ---- FUN_1000_ed5a @ 1000:ed5a ---- */

/* WARNING: Removing unreachable block (ram,0x0001ee52) */

uint FUN_1000_ed5a()

{
  undefined2 param_1 = 0; uint param_2 = 0; uint param_3 = 0;
  code *pcVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  byte bVar6;
  uint extraout_DX;
  undefined2 unaff_DS;
  bool bVar7;
  undefined1 uVar8;
  bool bVar9;
  byte local_6;
  char local_4;
  char local_3;
  undefined2 _local_4;
  
  uVar2 = _local_4;
  local_4 = '\0';
  local_6 = 0;
  if (((param_2 & 0x8000) == 0) && (((param_2 & 0x4000) != 0 || ((*(byte *)0x4b21 & 0x80) == 0)))) {
    local_6 = 0x80;
  }
  bVar7 = false;
  pcVar1 = (code *)swi(0x21);
  uVar5 = param_2;
  uVar3 = (*pcVar1)();
  if (bVar7) {
    if ((uVar3 != 2) || ((uVar5 & 0x100) == 0)) goto LAB_1000_ed9e;
    bVar7 = false;
    local_4 = 'I';
    FUN_1000_eeed();
    uVar8 = 0;
    uVar5 = 0;
LAB_1000_ee5c:
    pcVar1 = (code *)swi(0x21);
    uVar3 = (*pcVar1)();
    if ((bool)uVar8) {
LAB_1000_ee65:
      FUN_1000_f713();
      return uVar5;
    }
    if ((local_4 != '\0') || ((param_2 & 2) == 0)) {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)();
      bVar9 = false;
      pcVar1 = (code *)swi(0x21);
      uVar3 = (*pcVar1)();
      if (bVar9) goto LAB_1000_ee65;
      if ((!bVar7) && ((param_3 & 1) != 0)) {
        bVar7 = false;
        uVar5 = (uint)(byte)((byte)uVar5 | 1);
        pcVar1 = (code *)swi(0x21);
        (*pcVar1)();
        if (bVar7) goto LAB_1000_ee65;
      }
    }
  }
  else {
    if ((uVar5 & 0x500) == 0x500) {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)();
      goto LAB_1000_ed9e;
    }
    bVar7 = true;
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    if ((extraout_DX & 0x80) != 0) {
      local_6 = local_6 | 0x40;
    }
    if ((local_6 & 0x40) == 0) {
      if ((param_2 & 0x200) == 0) {
        if (((local_6 & 0x80) != 0) && ((param_2 & 2) != 0)) {
          pcVar1 = (code *)swi(0x21);
          (*pcVar1)();
          pcVar1 = (code *)swi(0x21);
          iVar4 = (*pcVar1)();
          if ((iVar4 != 0) && (local_3 = SUB21(uVar2,1), local_3 == '\x1a')) {
            pcVar1 = (code *)swi(0x21);
            (*pcVar1)();
            pcVar1 = (code *)swi(0x21);
            (*pcVar1)();
          }
          uVar5 = 0;
          pcVar1 = (code *)swi(0x21);
          (*pcVar1)();
        }
      }
      else {
        uVar8 = 0;
        if ((param_2 & 3) == 0) {
          pcVar1 = (code *)swi(0x21);
          (*pcVar1)();
          pcVar1 = (code *)swi(0x21);
          (*pcVar1)();
          goto LAB_1000_ee5c;
        }
        uVar5 = 0;
        pcVar1 = (code *)swi(0x21);
        (*pcVar1)();
      }
    }
  }
  if ((local_6 & 0x40) == 0) {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    bVar6 = 0;
    if ((uVar5 & 1) != 0) {
      bVar6 = 0x10;
    }
    if ((param_2 & 8) != 0) {
      bVar6 = bVar6 | 0x20;
    }
  }
  else {
    bVar6 = 0;
  }
  if (uVar3 < *(uint *)0x49d6) {
    *(byte *)(uVar3 + 0x49d8) = bVar6 | local_6 | 1;
    return uVar3;
  }
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
LAB_1000_ed9e:
  FUN_1000_f713();
  return uVar5;
}



/* ---- FUN_1000_eeed @ 1000:eeed ---- */

void FUN_1000_eeed()

{
  return;
}



/* ---- FUN_1000_eefe @ 1000:eefe ---- */

/* WARNING: Removing unreachable block (ram,0x0001efd7) */
/* WARNING: Removing unreachable block (ram,0x0001efcc) */

void FUN_1000_eefe()

{
  uint param_1 = 0;
  char *pcVar1;
  char cVar2;
  code *pcVar3;
  undefined2 uVar4;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 uVar7;
  int iVar5;
  undefined1 extraout_AH_01;
  int iVar8;
  uint extraout_DX;
  char *pcVar9;
  char *pcVar10;
  undefined2 unaff_DS;
  bool bVar11;
  undefined4 uVar12;
  char cVar6;
  
  if (*(uint *)0x49d6 <= param_1) {
LAB_1000_ef6d:
    FUN_1000_f713();
    return;
  }
  bVar11 = false;
  if ((*(byte *)(param_1 + 0x49d8) & 2) != 0) {
    FUN_1000_f713();
    return;
  }
  pcVar3 = (code *)swi(0x21);
  uVar12 = (*pcVar3)();
  pcVar10 = (char *)((ulong)uVar12 >> 0x10);
  if (((bVar11) || ((*(byte *)(param_1 + 0x49d8) & 0x80) == 0)) ||
     (*(byte *)(param_1 + 0x49d8) = *(byte *)(param_1 + 0x49d8) & 0xfb, (int)uVar12 == 0))
  goto LAB_1000_ef6d;
  uVar4 = 0xd00;
  if (*pcVar10 == '\n') {
    *(byte *)(param_1 + 0x49d8) = *(byte *)(param_1 + 0x49d8) | 4;
  }
LAB_1000_ef52:
  pcVar9 = (char *)((ulong)uVar12 >> 0x10);
  iVar8 = (int)uVar12;
  pcVar1 = pcVar9 + 1;
  cVar2 = *pcVar9;
  cVar6 = (char)((uint)uVar4 >> 8);
  uVar4 = CONCAT11(cVar6,cVar2);
  if (cVar2 == cVar6) {
    if (iVar8 != 1) {
      if (*pcVar1 != '\n') goto LAB_1000_ef62;
      goto LAB_1000_ef65;
    }
    bVar11 = false;
    if ((*(byte *)(param_1 + 0x49d8) & 0x40) == 0) {
      pcVar3 = (code *)swi(0x21);
      iVar5 = (*pcVar3)();
      if (!bVar11) {
        uVar7 = 0;
        if (iVar5 != 0) {
          pcVar3 = (code *)swi(0x21);
          (*pcVar3)();
          iVar8 = 1;
          uVar7 = extraout_AH_01;
        }
        uVar4 = CONCAT11(uVar7,0xd);
        goto LAB_1000_ef62;
      }
      goto LAB_1000_ef6d;
    }
    pcVar3 = (code *)swi(0x21);
    (*pcVar3)();
    bVar11 = false;
    uVar7 = extraout_AH;
    if ((extraout_DX & 0x20) == 0) {
      pcVar3 = (code *)swi(0x21);
      (*pcVar3)();
      uVar7 = extraout_AH_00;
      if (bVar11) goto LAB_1000_ef6d;
    }
    uVar4 = CONCAT11(uVar7,10);
  }
  else if (cVar2 == '\x1a') {
    *(byte *)(param_1 + 0x49d8) = *(byte *)(param_1 + 0x49d8) | 2;
    goto LAB_1000_ef6d;
  }
LAB_1000_ef62:
  *pcVar10 = (char)uVar4;
  pcVar10 = pcVar10 + 1;
LAB_1000_ef65:
  uVar12 = CONCAT22(pcVar1,iVar8 + -1);
  if (iVar8 + -1 == 0) goto LAB_1000_ef6d;
  goto LAB_1000_ef52;
}



/* ---- FUN_1000_efda @ 1000:efda ---- */

/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000_efda()

{
  uint param_1 = 0; char * param_2 = 0; int param_3 = 0;
  char *pcVar1;
  code *pcVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  undefined2 uVar8;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar9;
  undefined2 uStack_10;
  char _stack_var_fff2;
  
  if (param_1 < *(uint *)0x49d6) {
    if ((*(byte *)(param_1 + 0x49d8) & 0x20) != 0) {
      bVar9 = false;
      pcVar2 = (code *)swi(0x21);
      (*pcVar2)();
      if (bVar9) goto LAB_1000_efed;
    }
    if ((*(byte *)(param_1 + 0x49d8) & 0x80) != 0) {
      bVar9 = true;
      iVar5 = param_3;
      pcVar6 = param_2;
      if (param_3 == 0) {
        FUN_1000_f0c0();
        return;
      }
      do {
        if (iVar5 == 0) break;
        bVar9 = *pcVar6 == '\n';
        iVar5 = iVar5 + -1;
        pcVar6 = pcVar6 + 1;
      } while (!bVar9);
      if (bVar9) {
        uStack_10 = 0xf02e;
        FUN_1000_f754();
        if (uVar4 < 0xa9) {
          FUN_1000_eb2a();
          return;
        }
        pcVar6 = &_stack_var_fff2;
        iVar5 = 0x200;
        if (uVar4 < 0x228) {
          iVar5 = 0x80;
        }
        iVar5 = -iVar5;
        pcVar7 = &_stack_var_fff2 + iVar5;
        *(undefined2 *)((int)&uStack_10 + iVar5) = unaff_SS;
        uVar8 = *(undefined2 *)((int)&uStack_10 + iVar5);
        do {
          pcVar1 = param_2;
          param_2 = param_2 + 1;
          cVar3 = *pcVar1;
          if (cVar3 == '\n') {
            cVar3 = '\r';
            if (pcVar7 == pcVar6) {
              *(undefined2 *)((int)&uStack_10 + iVar5) = 0xf068;
              cVar3 = FUN_1000_f080();
            }
            pcVar1 = pcVar7;
            pcVar7 = pcVar7 + 1;
            *pcVar1 = cVar3;
            cVar3 = '\n';
          }
          if (pcVar7 == pcVar6) {
            *(undefined2 *)((int)&uStack_10 + iVar5) = 0xf073;
            cVar3 = FUN_1000_f080();
          }
          pcVar1 = pcVar7;
          pcVar7 = pcVar7 + 1;
          *pcVar1 = cVar3;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
        *(undefined2 *)((int)&uStack_10 + iVar5) = 0xf05d;
        FUN_1000_f080();
        FUN_1000_f0c0();
        return;
      }
    }
    FUN_1000_f0ce();
    return;
  }
LAB_1000_efed:
  FUN_1000_f713();
  return;
}



/* ---- FUN_1000_f080 @ 1000:f080 ---- */

/* WARNING: Unable to track spacebase fully for stack */

undefined2 FUN_1000_f080()

{
  code *pcVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 uVar3;
  uint in_DX;
  int unaff_BP;
  uint unaff_DI;
  undefined2 unaff_SS;
  bool bVar4;
  
  bVar4 = unaff_DI < in_DX;
  if (unaff_DI != in_DX) {
    pcVar1 = (code *)swi(0x21);
    iVar2 = (*pcVar1)();
    if ((bVar4) || (*(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + iVar2, iVar2 == 0)) {
      FUN_1000_f713();
      return uVar3;
    }
  }
  return in_AX;
}



/* ---- FUN_1000_f0c0 @ 1000:f0c0 ---- */

/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_1000_f0c0()

{
  FUN_1000_f713();
  return;
}



/* ---- FUN_1000_f0ce @ 1000:f0ce ---- */

void FUN_1000_f0ce()

{
  code *pcVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  
  if (*(int *)(unaff_BP + 8) != 0) {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    FUN_1000_f713();
    return;
  }
  FUN_1000_f713();
  return;
}



/* ---- FUN_1000_f102 @ 1000:f102 ---- */

char * FUN_1000_f102()

{
  char * param_1 = 0; char * param_2 = 0;
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined2 unaff_DS;
  
  iVar3 = -1;
  pcVar6 = param_1;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar1 = pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (*pcVar1 != '\0');
  uVar4 = 0xffff;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar1 = param_2;
    param_2 = param_2 + 1;
  } while (*pcVar1 != '\0');
  uVar4 = ~uVar4;
  param_2 = param_2 + -uVar4;
  pcVar7 = pcVar6 + -1;
  if (((uint)param_2 & 1) != 0) {
    pcVar1 = param_2;
    param_2 = param_2 + 1;
    pcVar6[-1] = *pcVar1;
    uVar4 = uVar4 - 1;
    pcVar7 = pcVar6;
  }
  for (uVar5 = uVar4 >> 1; uVar5 != 0; uVar5 = uVar5 - 1) {
    pcVar2 = pcVar7;
    pcVar7 = pcVar7 + 2;
    pcVar1 = param_2;
    param_2 = param_2 + 2;
    *(undefined2 *)pcVar2 = *(undefined2 *)pcVar1;
  }
  for (uVar4 = (uint)((uVar4 & 1) != 0); uVar4 != 0; uVar4 = uVar4 - 1) {
    pcVar2 = pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar1 = param_2;
    param_2 = param_2 + 1;
    *pcVar2 = *pcVar1;
  }
  return param_1;
}



/* ---- FUN_1000_f142 @ 1000:f142 ---- */

void FUN_1000_f142()

{
  char * param_1 = 0; char * param_2 = 0;
  char *pcVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  undefined2 unaff_DS;
  
  uVar3 = 0xffff;
  pcVar5 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar1 = pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (*pcVar1 != '\0');
  uVar3 = ~uVar3;
  if (((uint)param_1 & 1) != 0) {
    pcVar2 = param_1;
    param_1 = param_1 + 1;
    pcVar1 = param_2;
    param_2 = param_2 + 1;
    *pcVar2 = *pcVar1;
    uVar3 = uVar3 - 1;
  }
  for (uVar4 = uVar3 >> 1; uVar4 != 0; uVar4 = uVar4 - 1) {
    pcVar2 = param_1;
    param_1 = param_1 + 2;
    pcVar1 = param_2;
    param_2 = param_2 + 2;
    *(undefined2 *)pcVar2 = *(undefined2 *)pcVar1;
  }
  for (uVar3 = (uint)((uVar3 & 1) != 0); uVar3 != 0; uVar3 = uVar3 - 1) {
    pcVar2 = param_1;
    param_1 = param_1 + 1;
    pcVar1 = param_2;
    param_2 = param_2 + 1;
    *pcVar2 = *pcVar1;
  }
  return;
}



/* ---- FUN_1000_f174 @ 1000:f174 ---- */

int FUN_1000_f174()

{
  byte * param_1 = 0; char * param_2 = 0;
  byte *pbVar1;
  char *pcVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  byte *pbVar7;
  undefined2 unaff_DS;
  bool bVar8;
  bool bVar9;
  
  iVar4 = 0;
  uVar5 = 0xffff;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar2 = param_2;
    param_2 = param_2 + 1;
  } while (*pcVar2 != '\0');
  pcVar6 = (char *)~uVar5;
  bVar8 = param_2 < pcVar6;
  pbVar7 = (byte *)(param_2 + -(int)pcVar6);
  bVar9 = pbVar7 == (byte *)0x0;
  do {
    if (pcVar6 == (char *)0x0) break;
    pcVar6 = pcVar6 + -1;
    pbVar3 = pbVar7;
    pbVar7 = pbVar7 + 1;
    pbVar1 = param_1;
    param_1 = param_1 + 1;
    bVar8 = *pbVar1 < *pbVar3;
    bVar9 = *pbVar1 == *pbVar3;
  } while (bVar9);
  if (!bVar9) {
    iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
  }
  return iVar4;
}



/* ---- FUN_1000_f1a0 @ 1000:f1a0 ---- */

int FUN_1000_f1a0()

{
  char * param_1 = 0;
  char *pcVar1;
  uint uVar2;
  undefined2 unaff_DS;
  
  uVar2 = 0xffff;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar1 = param_1;
    param_1 = param_1 + 1;
  } while (*pcVar1 != '\0');
  return ~uVar2 - 1;
}



/* ---- FUN_1000_f1bc @ 1000:f1bc ---- */

int FUN_1000_f1bc(int param_1)

{
  undefined2 unaff_DS;
  
  if ((*(byte *)(param_1 + 0x4a1f) & 1) != 0) {
    return param_1 + 0x20;
  }
  return param_1;
}



/* ---- FUN_1000_f1d6 @ 1000:f1d6 ---- */

undefined4 FUN_1000_f1d6()

{
  uint param_1 = 0; uint param_2 = 0; uint param_3 = 0; uint param_4 = 0;
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 - param_4;
  uVar2 = uVar1 * 0x10 + param_1;
  return CONCAT22((((((uint)(param_2 < param_4) * -2 + (uint)CARRY2(uVar1,uVar1)) * 2 +
                    (uint)CARRY2(uVar1 * 2,uVar1 * 2)) * 2 + (uint)CARRY2(uVar1 * 4,uVar1 * 4)) * 2
                   + (uint)CARRY2(uVar1 * 8,uVar1 * 8) + (uint)CARRY2(uVar1 * 0x10,param_1)) -
                  (uint)(uVar2 < param_3),uVar2 - param_3);
}



/* ---- FUN_1000_f204 @ 1000:f204 ---- */

void FUN_1000_f204()

{
  code *pcVar1;
  undefined2 *puVar2;
  uint in_CX;
  uint uVar3;
  uint extraout_DX;
  byte extraout_DH;
  uint extraout_DX_00;
  uint uVar4;
  uint uVar5;
  undefined2 unaff_DS;
  undefined4 uVar6;
  uint uVar7;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  uVar5 = extraout_DX;
  (*pcVar1)();
  puVar2 = (undefined2 *)(uint)extraout_DH;
  uVar7 = in_CX >> 8;
  pcVar1 = (code *)swi(0x21);
  uVar3 = in_CX;
  (*pcVar1)(uVar7);
  uVar4 = extraout_DX_00;
  if ((uVar5 != extraout_DX_00) && (uVar4 = extraout_DX_00, (char)in_CX == '\x17')) {
    uVar3 = uVar7;
    uVar4 = uVar5;
  }
  uVar6 = FUN_1000_f766(uVar3 - 0x7bc,uVar4 >> 8);
  if (puVar2 != (undefined2 *)0x0) {
    puVar2[1] = (int)((ulong)uVar6 >> 0x10);
    *puVar2 = (int)uVar6;
  }
  return;
}



/* ---- FUN_1000_f25c @ 1000:f25c ---- */

int FUN_1000_f25c()

{
  byte * param_1 = 0; byte * param_2 = 0; int param_3 = 0;
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  undefined2 unaff_DS;
  bool bVar4;
  bool bVar5;
  
  bVar4 = false;
  iVar3 = 0;
  bVar5 = true;
  if (param_3 != 0) {
    do {
      if (param_3 == 0) break;
      param_3 = param_3 + -1;
      pbVar2 = param_2;
      param_2 = param_2 + 1;
      pbVar1 = param_1;
      param_1 = param_1 + 1;
      bVar4 = *pbVar1 < *pbVar2;
      bVar5 = *pbVar1 == *pbVar2;
    } while (bVar5);
    if (!bVar5) {
      iVar3 = (1 - (uint)bVar4) - (uint)(bVar4 != 0);
    }
  }
  return iVar3;
}



/* ---- FUN_1000_f284 @ 1000:f284 ---- */

void FUN_1000_f284()

{
  undefined2 * param_1 = 0; undefined2 * param_2 = 0; uint param_3 = 0;
  undefined2 *puVar1;
  undefined2 *puVar2;
  uint uVar3;
  undefined2 unaff_DS;
  
  if (param_3 != 0) {
    if (((uint)param_1 & 1) != 0) {
      puVar2 = param_1;
      param_1 = (undefined2 *)((int)param_1 + 1);
      puVar1 = param_2;
      param_2 = (undefined2 *)((int)param_2 + 1);
      *(undefined1 *)puVar2 = *(undefined1 *)puVar1;
      param_3 = param_3 - 1;
    }
    for (uVar3 = param_3 >> 1; uVar3 != 0; uVar3 = uVar3 - 1) {
      puVar2 = param_1;
      param_1 = param_1 + 1;
      puVar1 = param_2;
      param_2 = param_2 + 1;
      *puVar2 = *puVar1;
    }
    for (uVar3 = (uint)((param_3 & 1) != 0); uVar3 != 0; uVar3 = uVar3 - 1) {
      puVar2 = param_1;
      param_1 = (undefined2 *)((int)param_1 + 1);
      puVar1 = param_2;
      param_2 = (undefined2 *)((int)param_2 + 1);
      *(undefined1 *)puVar2 = *(undefined1 *)puVar1;
    }
  }
  return;
}



/* ---- FUN_1000_f2b0 @ 1000:f2b0 ---- */

undefined2 * FUN_1000_f2b0()

{
  undefined2 * param_1 = 0; undefined1 param_2 = 0; uint param_3 = 0;
  undefined2 *puVar1;
  uint uVar2;
  undefined2 *puVar3;
  undefined2 unaff_DS;
  
  if (param_3 != 0) {
    puVar3 = param_1;
    if (((uint)param_1 & 1) != 0) {
      puVar3 = (undefined2 *)((int)param_1 + 1);
      *(undefined1 *)param_1 = param_2;
      param_3 = param_3 - 1;
    }
    for (uVar2 = param_3 >> 1; uVar2 != 0; uVar2 = uVar2 - 1) {
      puVar1 = puVar3;
      puVar3 = puVar3 + 1;
      *puVar1 = CONCAT11(param_2,param_2);
    }
    for (uVar2 = (uint)((param_3 & 1) != 0); uVar2 != 0; uVar2 = uVar2 - 1) {
      puVar1 = puVar3;
      puVar3 = (undefined2 *)((int)puVar3 + 1);
      *(undefined1 *)puVar1 = param_2;
    }
  }
  return param_1;
}



/* ---- FUN_1000_f2de @ 1000:f2de ---- */

void FUN_1000_f2de(undefined2 param_1)

{
  undefined2 unaff_DS;
  
  *(undefined2 *)0x4a02 = param_1;
  *(undefined2 *)0x4a04 = 0;
  return;
}



/* ---- FUN_1000_f2f0 @ 1000:f2f0 ---- */

uint FUN_1000_f2f0()

{
  uint uVar1;
  undefined2 unaff_DS;
  long lVar2;
  
  lVar2 = FUN_1000_f32e(*(undefined2 *)0x4a02,*(undefined2 *)0x4a04,0x43fd,3);
  uVar1 = (uint)((ulong)(lVar2 + 0x269ec3) >> 0x10);
  *(undefined2 *)0x4a02 = (int)(lVar2 + 0x269ec3);
  *(uint *)0x4a04 = uVar1;
  return uVar1 & 0x7fff;
}



/* ---- FUN_1000_f316 @ 1000:f316 ---- */

void FUN_1000_f316()

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x11);
  (*pcVar1)();
  return;
}



/* ---- FUN_1000_f31a @ 1000:f31a ---- */

undefined2 FUN_1000_f31a()

{
  uint * param_1 = 0;
  code *pcVar1;
  char cVar2;
  undefined2 unaff_DS;
  
  pcVar1 = (code *)swi(0x21);
  cVar2 = (*pcVar1)();
  *param_1 = (uint)(byte)(cVar2 + 1);
  return 0;
}



/* ---- FUN_1000_f32e @ 1000:f32e ---- */

long FUN_1000_f32e()

{
  uint param_1 = 0; int param_2 = 0; uint param_3 = 0; int param_4 = 0;
  if (param_4 == 0 && param_2 == 0) {
    return (ulong)param_1 * (ulong)param_3;
  }
  return CONCAT22((int)((ulong)param_1 * (ulong)param_3 >> 0x10) +
                  param_2 * param_3 + param_1 * param_4,(int)((ulong)param_1 * (ulong)param_3));
}



/* ---- FUN_1000_f362 @ 1000:f362 ---- */

void FUN_1000_f362()

{
  uint in_CX;
  uint uVar1;
  
  for (uVar1 = in_CX & 0xff; uVar1 != 0; uVar1 = uVar1 - 1) {
  }
  return;
}



/* ---- FUN_1000_f36e @ 1000:f36e ---- */

long FUN_1000_f36e()

{
  uint in_CX;
  uint uVar1;
  
  for (uVar1 = in_CX & 0xff; uVar1 != 0; uVar1 = uVar1 - 1) {
  }
  return;
}



/* ---- FUN_1000_f37a @ 1000:f37a ---- */

void FUN_1000_f37a()

{
  undefined2 * param_1 = 0; undefined2 param_2 = 0; undefined2 param_3 = 0;
  undefined2 unaff_DS;
  undefined4 uVar1;
  
  uVar1 = FUN_1000_f87c(*param_1,param_1[1],param_2,param_3);
  param_1[1] = (int)((ulong)uVar1 >> 0x10);
  *param_1 = (int)uVar1;
  return;
}



/* ---- FUN_1000_f39c @ 1000:f39c ---- */

/* WARNING: Removing unreachable block (ram,0x0001f3ed) */

undefined4 FUN_1000_f39c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulong uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ulong uVar6;
  
  uVar1 = CONCAT22(param_2,param_1);
  uVar2 = param_4;
  uVar5 = param_3;
  if (param_4 == 0) {
    uVar2 = param_2 / param_3;
    iVar3 = (int)(((ulong)param_2 % (ulong)param_3 << 0x10 | (ulong)param_1) / (ulong)param_3);
  }
  else {
    do {
      uVar4 = uVar2 >> 1;
      uVar5 = uVar5 >> 1 | (uint)((uVar2 & 1) != 0) << 0xf;
      uVar2 = param_2 & 1;
      param_2 = param_2 >> 1;
      param_1 = param_1 >> 1 | (uint)(uVar2 != 0) << 0xf;
      uVar2 = uVar4;
    } while (uVar4 != 0);
    iVar3 = (int)(CONCAT22(param_2,param_1) / (ulong)uVar5);
    uVar6 = FUN_1000_f32e(param_3,param_4,iVar3,0);
    if (uVar1 < uVar6) {
      iVar3 = iVar3 + -1;
    }
    uVar2 = 0;
  }
  return CONCAT22(uVar2,iVar3);
}



/* ---- FUN_1000_f402 @ 1000:f402 ---- */

/* WARNING: Removing unreachable block (ram,0x0001f450) */

undefined4 FUN_1000_f402(uint param_1,uint param_2,uint param_3,uint param_4)

{
  long lVar1;
  ulong uVar2;
  uint uVar3;
  int iVar5;
  int iVar6;
  uint uVar7;
  ulong uVar8;
  uint uVar4;
  
  uVar2 = CONCAT22(param_2,param_1);
  uVar4 = param_4;
  uVar7 = param_3;
  if (param_4 == 0) {
    iVar5 = (int)(((ulong)param_2 % (ulong)param_3 << 0x10 | (ulong)param_1) % (ulong)param_3);
    iVar6 = 0;
  }
  else {
    do {
      uVar3 = uVar4 >> 1;
      uVar7 = uVar7 >> 1 | (uint)((uVar4 & 1) != 0) << 0xf;
      uVar4 = param_2 & 1;
      param_2 = param_2 >> 1;
      param_1 = param_1 >> 1 | (uint)(uVar4 != 0) << 0xf;
      uVar4 = uVar3;
    } while (uVar3 != 0);
    uVar8 = FUN_1000_f32e(param_3,param_4,(int)(CONCAT22(param_2,param_1) / (ulong)uVar7),0);
    if (uVar2 < uVar8) {
      uVar8 = uVar8 - CONCAT22(param_4,param_3);
    }
    lVar1 = uVar8 - uVar2;
    iVar6 = (int)lVar1;
    iVar5 = -iVar6;
    iVar6 = -(uint)(iVar6 != 0) - (int)((ulong)lVar1 >> 0x10);
  }
  return CONCAT22(iVar6,iVar5);
}



/* ---- FUN_1000_f470 @ 1000:f470 ---- */

void FUN_1000_f470()

{
  undefined2 unaff_DS;
  
  FUN_1000_f6d7(0xfc);
  if (*(int *)0x4a06 != 0) {
    (*(code *)*(undefined2 *)0x4a06)();
  }
  FUN_1000_f6d7(0xff);
  return;
}



/* ---- FUN_1000_f490 @ 1000:f490 ---- */

void FUN_1000_f490()

{
  FUN_1000_eb2a();
  return;
}



/* ---- FUN_1000_f496 @ 1000:f496 ---- */

uint FUN_1000_f496()

{
  byte *pbVar1;
  byte bVar3;
  uint uVar2;
  int iVar4;
  byte *pbVar5;
  undefined2 unaff_DS;
  
  pbVar5 = (byte *)0x0;
  iVar4 = 0x42;
  bVar3 = 0;
  do {
    pbVar1 = pbVar5;
    pbVar5 = pbVar5 + 1;
    bVar3 = bVar3 ^ *pbVar1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  uVar2 = CONCAT11(bVar3,*pbVar1) ^ 0x5500;
  if (bVar3 != 0x55) {
    FUN_1000_f470();
    FUN_1000_f6d7(1);
    uVar2 = 1;
  }
  return uVar2;
}



/* ---- FUN_1000_f6ac @ 1000:f6ac ---- */

int * FUN_1000_f6ac(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined2 unaff_DS;
  
  piVar3 = (int *)0x51fa;
  do {
    piVar1 = piVar3;
    piVar3 = piVar3 + 1;
    piVar4 = piVar3;
    if ((*piVar1 == param_1) || (piVar4 = (int *)0x0, *piVar1 == -1)) {
      return piVar4;
    }
    iVar2 = -1;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      piVar1 = piVar3;
      piVar3 = (int *)((int)piVar3 + 1);
    } while ((char)*piVar1 != '\0');
  } while( true );
}



/* ---- FUN_1000_f6d7 @ 1000:f6d7 ---- */

void FUN_1000_f6d7()

{
  undefined2 param_1 = 0;
  char *pcVar1;
  code *pcVar2;
  char *pcVar3;
  int iVar4;
  undefined2 unaff_ES;
  
  pcVar3 = (char *)FUN_1000_f6ac(param_1);
  if (pcVar3 != (char *)0x0) {
    iVar4 = -1;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar1 = pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (*pcVar1 != '\0');
    pcVar2 = (code *)swi(0x21);
    (*pcVar2)();
  }
  return;
}



/* ---- FUN_1000_f700 @ 1000:f700 ---- */

long FUN_1000_f700()

{
  uint in_DX;
  bool in_CF;
  
  if (!in_CF) {
    return (ulong)in_DX << 0x10;
  }
  FUN_1000_f726();
  return -1;
}



/* ---- FUN_1000_f713 @ 1000:f713 ---- */

void FUN_1000_f713()

{
  bool in_CF;
  
  if (in_CF) {
    FUN_1000_f726();
  }
  return;
}



/* ---- FUN_1000_f726 @ 1000:f726 ---- */

void FUN_1000_f726()

{
  byte bVar1;
  char cVar2;
  uint in_AX;
  undefined2 unaff_DS;
  
  bVar1 = (byte)in_AX;
  *(byte *)0x49d4 = bVar1;
  cVar2 = (char)(in_AX >> 8);
  if (cVar2 != '\0') goto LAB_1000_f74b;
  if (*(byte *)0x49d1 < 3) {
LAB_1000_f741:
    if (0x13 < bVar1) {
LAB_1000_f745:
      in_AX = 0x13;
    }
  }
  else {
    if (0x21 < bVar1) goto LAB_1000_f745;
    if (bVar1 < 0x20) goto LAB_1000_f741;
    in_AX = 5;
  }
  cVar2 = *(char *)(ulong)((in_AX & 0xff) + 0x4a0a);
LAB_1000_f74b:
  *(int *)0x49c9 = (int)cVar2;
  return;
}



/* ---- FUN_1000_f754 @ 1000:f754 ---- */

void FUN_1000_f754()

{
  code *in_stack_00000000;
  
                    /* WARNING: Could not recover jumptable at 0x0001f760. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*in_stack_00000000)();
  return;
}



/* ---- FUN_1000_f766 @ 1000:f766 ---- */

long FUN_1000_f766()

{
  int param_1 = 0; int param_2 = 0; int param_3 = 0; int param_4 = 0; int param_5 = 0; uint param_6 = 0;
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined2 unaff_DS;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  undefined1 local_14 [4];
  int local_10;
  int local_c;
  int local_a;
  int local_6;
  
  uVar3 = (int)(param_1 + 3U) >> 0xf;
  iVar1 = ((int)((param_1 + 3U ^ uVar3) - uVar3) >> 2 ^ uVar3) - uVar3;
  lVar4 = FUN_1000_f32e(iVar1,iVar1 >> 0xf,0x5180,1);
  local_6 = *(int *)(param_2 * 2 + 0x4b3a);
  if ((param_1 % 4 == 0) && (2 < param_2)) {
    local_6 = local_6 + 1;
  }
  lVar5 = FUN_1000_f32e(param_5,param_5 >> 0xf,0x3c,0);
  lVar6 = FUN_1000_f32e(param_4,param_4 >> 0xf,0xe10,0);
  iVar1 = param_3 + param_1 * 0x16d + local_6;
  lVar7 = FUN_1000_f32e(iVar1,iVar1 >> 0xf,0x5180,1);
  lVar5 = lVar5 + lVar6 + lVar7;
  uVar3 = (uint)lVar5;
  uVar2 = uVar3 + param_6;
  local_6 = param_3 + local_6;
  FUN_1000_f962();
  lVar4 = lVar4 + CONCAT22((int)((ulong)lVar5 >> 0x10) + ((int)param_6 >> 0xf) +
                           (uint)CARRY2(uVar3,param_6) + 0x12ce + (uint)(0x59ff < uVar2),
                           uVar2 + 0xa600) + CONCAT22(*(undefined2 *)0x4b64,*(undefined2 *)0x4b62);
  local_a = param_1 + 0x50;
  local_c = param_2 + -1;
  local_10 = param_4;
  if (*(int *)0x4b66 != 0) {
    iVar1 = FUN_1000_fa12(local_14);
    if (iVar1 != 0) {
      lVar4 = CONCAT22((int)((ulong)lVar4 >> 0x10) - (uint)((uint)lVar4 < 0xe10),(uint)lVar4 - 0xe10
                      );
    }
  }
  return lVar4;
}



/* ---- FUN_1000_f87c @ 1000:f87c ---- */

/* WARNING: Removing unreachable block (ram,0x0001f8ff) */

undefined4 FUN_1000_f87c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulong uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar6;
  bool bVar7;
  ulong uVar8;
  uint uVar5;
  
  uVar6 = 0;
  if ((int)param_2 < 0) {
    uVar6 = 0xffff;
    bVar7 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(uint)bVar7 - param_2;
  }
  uVar1 = CONCAT22(param_2,param_1);
  if ((int)param_4 < 0) {
    uVar6 = ~uVar6;
    bVar7 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(uint)bVar7 - param_4;
  }
  uVar2 = param_3;
  uVar5 = param_4;
  if (param_4 == 0) {
    uVar2 = param_2 / param_3;
    iVar3 = (int)(((ulong)param_2 % (ulong)param_3 << 0x10 | (ulong)param_1) / (ulong)param_3);
  }
  else {
    do {
      uVar4 = uVar5 >> 1;
      uVar2 = uVar2 >> 1 | (uint)((uVar5 & 1) != 0) << 0xf;
      uVar5 = param_2 & 1;
      param_2 = param_2 >> 1;
      param_1 = param_1 >> 1 | (uint)(uVar5 != 0) << 0xf;
      uVar5 = uVar4;
    } while (uVar4 != 0);
    iVar3 = (int)(CONCAT22(param_2,param_1) / (ulong)uVar2);
    uVar8 = FUN_1000_f32e(param_3,param_4,iVar3,0);
    if (uVar1 < uVar8) {
      iVar3 = iVar3 + -1;
    }
    uVar2 = 0;
  }
  if (uVar6 != 0) {
    bVar7 = iVar3 != 0;
    iVar3 = -iVar3;
    uVar2 = -(uint)bVar7 - uVar2;
  }
  return CONCAT22(uVar2,iVar3);
}



/* ---- FUN_1000_f962 @ 1000:f962 ---- */

void FUN_1000_f962()

{
  char *pcVar1;
  int iVar2;
  undefined2 unaff_DS;
  undefined4 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  
  pcVar1 = (char *)FUN_1000_fb12(0x4b56);
  if ((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) {
    FUN_1000_fae6(*(undefined2 *)0x4b68,pcVar1,3);
    uVar5 = 0;
    uVar4 = 0xe10;
    pcVar1 = pcVar1 + 3;
    uVar3 = thunk_FUN_1000_fba2(pcVar1,0xe10,0);
    uVar3 = FUN_1000_f32e(uVar3,uVar4,uVar5,0);
    *(undefined2 *)0x4b62 = (int)uVar3;
    *(undefined2 *)0x4b64 = (int)((ulong)uVar3 >> 0x10);
    iVar2 = 0;
    while (pcVar1[iVar2] != '\0') {
      if ((((*(byte *)(pcVar1[iVar2] + 0x4a1f) & 4) == 0) && (pcVar1[iVar2] != '-')) ||
         (iVar2 = iVar2 + 1, 2 < iVar2)) break;
    }
    if (pcVar1[iVar2] == '\0') {
      *(undefined1 *)*(undefined2 *)0x4b6a = 0;
    }
    else {
      FUN_1000_fae6(*(undefined2 *)0x4b6a,pcVar1 + iVar2,3);
    }
    *(uint *)0x4b66 = (uint)(*(char *)*(undefined2 *)0x4b6a != '\0');
  }
  return;
}



/* ---- FUN_1000_fa12 @ 1000:fa12 ---- */

undefined2 FUN_1000_fa12()

{
  int param_1 = 0;
  uint uVar1;
  uint uVar2;
  undefined2 unaff_DS;
  int local_8;
  
  if (*(int *)(param_1 + 8) < 3) {
    return 0;
  }
  if (9 < *(int *)(param_1 + 8)) {
    return 0;
  }
  if ((3 < *(int *)(param_1 + 8)) && (*(int *)(param_1 + 8) < 9)) {
    return 1;
  }
  uVar2 = *(int *)(param_1 + 10) + 0x76c;
  if (((int)uVar2 < 0x7c3) || (*(int *)(param_1 + 8) != 3)) {
    local_8 = *(int *)(*(int *)(param_1 + 8) * 2 + 0x4b3e);
  }
  else {
    local_8 = *(int *)(*(int *)(param_1 + 8) * 2 + 0x4b3c) + 7;
  }
  if ((uVar2 & 3) == 0) {
    local_8 = local_8 + 1;
  }
  uVar2 = *(int *)(param_1 + 10) - 0x45;
  uVar1 = (int)uVar2 >> 0xf;
  local_8 = local_8 - (int)((((int)((uVar2 ^ uVar1) - uVar1) >> 2 ^ uVar1) - uVar1) + local_8 +
                            (*(int *)(param_1 + 10) + -0x46) * 0x16d + 4) % 7;
  if (*(int *)(param_1 + 8) == 3) {
    if (local_8 < *(int *)(param_1 + 0xe)) {
      return 1;
    }
    if ((*(int *)(param_1 + 0xe) == local_8) && (1 < *(int *)(param_1 + 4))) {
      return 1;
    }
  }
  else {
    if (*(int *)(param_1 + 0xe) < local_8) {
      return 1;
    }
    if ((*(int *)(param_1 + 0xe) == local_8) && (*(int *)(param_1 + 4) < 1)) {
      return 1;
    }
  }
  return 0;
}



/* ---- FUN_1000_fae6 @ 1000:fae6 ---- */

char * FUN_1000_fae6()

{
  char * param_1 = 0; char * param_2 = 0; int param_3 = 0;
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  undefined2 unaff_DS;
  
  pcVar3 = param_1;
  if (param_3 != 0) {
    do {
      pcVar1 = param_2;
      param_2 = param_2 + 1;
      if (*pcVar1 == '\0') break;
      pcVar2 = pcVar3;
      pcVar3 = pcVar3 + 1;
      *pcVar2 = *pcVar1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
    for (; param_3 != 0; param_3 = param_3 + -1) {
      pcVar1 = pcVar3;
      pcVar3 = pcVar3 + 1;
      *pcVar1 = '\0';
    }
  }
  return param_1;
}



/* ---- thunk_FUN_1000_fba2 @ 1000:fb0e ---- */

undefined4 thunk_FUN_1000_fba2()

{
  byte * param_1 = 0;
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined2 unaff_DS;
  bool bVar10;
  
  iVar5 = 0;
  iVar7 = 0;
  do {
    do {
      pbVar1 = param_1;
      param_1 = param_1 + 1;
      bVar2 = *pbVar1;
    } while (bVar2 == 0x20);
  } while (bVar2 == 9);
  if ((bVar2 != 0x2d) && (bVar4 = bVar2, bVar2 != 0x2b)) goto LAB_1000_fbc2;
  while( true ) {
    pbVar1 = param_1;
    param_1 = param_1 + 1;
    bVar4 = *pbVar1;
LAB_1000_fbc2:
    if ((0x39 < bVar4) || (bVar4 < 0x30)) break;
    uVar8 = iVar7 * 2;
    uVar6 = iVar5 << 1 | (uint)(iVar7 < 0);
    iVar5 = iVar7 << 2;
    uVar9 = iVar7 * 8;
    uVar3 = iVar7 * 10;
    iVar7 = uVar3 + (byte)(bVar4 - 0x30);
    iVar5 = ((uVar6 << 1 | (uint)((int)uVar8 < 0)) << 1 | (uint)(iVar5 < 0)) + uVar6 +
            (uint)CARRY2(uVar9,uVar8) + (uint)CARRY2(uVar3,(uint)(byte)(bVar4 - 0x30));
  }
  if (bVar2 == 0x2d) {
    bVar10 = iVar7 != 0;
    iVar7 = -iVar7;
    iVar5 = -(iVar5 + (uint)bVar10);
  }
  return CONCAT22(iVar5,iVar7);
}



/* ---- FUN_1000_fb12 @ 1000:fb12 ---- */

int FUN_1000_fb12(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined2 unaff_DS;
  
  piVar3 = (int *)*(int *)0x49f0;
  if ((piVar3 != (int *)0x0) && (param_1 != 0)) {
    iVar1 = FUN_1000_f1a0(param_1);
    for (; *piVar3 != 0; piVar3 = piVar3 + 1) {
      if (*(char *)(*piVar3 + iVar1) == '=') {
        iVar2 = FUN_1000_fb68(*piVar3,param_1,iVar1);
        if (iVar2 == 0) {
          return *piVar3 + iVar1 + 1;
        }
      }
    }
  }
  return 0;
}



/* ---- FUN_1000_fb68 @ 1000:fb68 ---- */

uint FUN_1000_fb68()

{
  char * param_1 = 0; char * param_2 = 0; int param_3 = 0;
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  undefined2 unaff_DS;
  
  uVar4 = 0;
  iVar3 = param_3;
  pcVar5 = param_1;
  if (param_3 != 0) {
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar1 = pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar1 != '\0');
    param_3 = param_3 - iVar3;
    do {
      if (param_3 == 0) break;
      param_3 = param_3 + -1;
      pcVar2 = param_1;
      param_1 = param_1 + 1;
      pcVar1 = param_2;
      param_2 = param_2 + 1;
    } while (*pcVar1 == *pcVar2);
    uVar4 = 0;
    if ((byte)param_2[-1] <= (byte)param_1[-1]) {
      if (param_2[-1] == param_1[-1]) {
        return 0;
      }
      uVar4 = 0xfffe;
    }
    uVar4 = ~uVar4;
  }
  return uVar4;
}



/* ---- FUN_1000_fba2 @ 1000:fba2 ---- */

undefined4 FUN_1000_fba2(byte *param_1)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined2 unaff_DS;
  bool bVar10;
  volatile unsigned long _ret;

  iVar5 = 0;
  iVar7 = 0;
  do {
    do {
      pbVar1 = param_1;
      param_1 = param_1 + 1;
      bVar2 = *pbVar1;
    } while (bVar2 == 0x20);
  } while (bVar2 == 9);
  if ((bVar2 != 0x2d) && (bVar4 = bVar2, bVar2 != 0x2b)) goto LAB_1000_fbc2;
  while( true ) {
    pbVar1 = param_1;
    param_1 = param_1 + 1;
    bVar4 = *pbVar1;
LAB_1000_fbc2:
    if ((0x39 < bVar4) || (bVar4 < 0x30)) break;
    uVar8 = iVar7 * 2;
    uVar6 = iVar5 << 1 | (uint)(iVar7 < 0);
    iVar5 = iVar7 << 2;
    uVar9 = iVar7 * 8;
    uVar3 = iVar7 * 10;
    iVar7 = uVar3 + (byte)(bVar4 - 0x30);
    iVar5 = ((uVar6 << 1 | (uint)((int)uVar8 < 0)) << 1 | (uint)(iVar5 < 0)) + uVar6 +
            (uint)CARRY2(uVar9,uVar8) + (uint)CARRY2(uVar3,(uint)(byte)(bVar4 - 0x30));
  }
  if (bVar2 == 0x2d) {
    bVar10 = iVar7 != 0;
    iVar7 = -iVar7;
    iVar5 = -(iVar5 + (uint)bVar10);
  }
  _ret = ((unsigned long)(unsigned short)iVar5 << 16) | (unsigned short)iVar7;
  return _ret;
}



/* ---- FUN_1000_fbf6 @ 1000:fbf6 ---- */
#pragma on(optimize)
#pragma off(optimize)
void FUN_1000_fbf6()

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte p_flag;
  byte p_type;
  undefined1 local_8;

  for (uVar3 = 0; (int)uVar3 < 0x40; uVar3 = uVar3 + 1) {
    uVar2 = (uVar3 & 0x38) << 1 ^ 0x70 | uVar3 & 7;
    p_type = *(byte *)((uint)(uVar2 * 4) - 0x5746u);
    bVar1 = *(byte *)((uint)p_type + 0xf00u);
    p_flag = *(byte *)((uint)(uVar2 * 4) - 0x5745u);
    if (bVar1 == 6) {
      if ((uVar3 & 7) < 4) {
        local_8 = '\x03';
      }
      else {
        local_8 = '\a';
      }
    }
    else if (bVar1 == 1) {
      if ((uVar3 & 7) < 4) {
        if (p_flag == 0) {
          local_8 = '\x01';
        }
        else {
          local_8 = '\x03';
        }
      }
      else if (p_flag == 0) {
        local_8 = '\a';
      }
      else {
        local_8 = '\x05';
      }
    }
    else if (p_flag == 0) {
      local_8 = '\0';
    }
    else {
      local_8 = '\x04';
    }
    if (bVar1 == 0) {
      bVar1 = 0;
    }
    else {
      bVar1 = (byte)(((p_flag == 0) ? 0x40 : 0) | ((int)local_8 << 3) | (int)bVar1);
    }
    *(byte *)(uVar3 + 0x1166u) = bVar1;
  }
  return;
}



#pragma on(optimize)
/* ---- FUN_1000_fce8 @ 1000:fce8 ---- */

void FUN_1000_fce8(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  
  for (iVar2 = 0; iVar2 < 8; iVar2 = iVar2 + 1) {
    *(undefined1 *)(iVar2 + -0x6dd0) = 0;
    for (iVar3 = 0; iVar3 < 8; iVar3 = iVar3 + 1) {
      bVar1 = *(byte *)(iVar2 * 8 + iVar3 + 0x1166);
      if ((bVar1 & 7) != 0) {
        if ((bVar1 & 0x40) == 0) {
          if (param_1 != 0) {
            *(byte *)(iVar2 + -0x6dd0) = *(byte *)(iVar2 + -0x6dd0) | '\x01' << ((byte)iVar3 & 0x1f)
            ;
          }
        }
        else if (param_1 == 0) {
          *(byte *)(iVar2 + -0x6dd0) = *(byte *)(iVar2 + -0x6dd0) | '\x01' << ((byte)iVar3 & 0x1f);
        }
      }
    }
  }
  return;
}



/* ---- FUN_1000_fd4e @ 1000:fd4e ---- */

int FUN_1000_fd4e(int param_1)

{
  param_1 = param_1 + 0x14;
  if (param_1 == -0x7234) {
    param_1 = -0x72d4;
  }
  return param_1;
}



/* ---- FUN_1000_fd6a @ 1000:fd6a ---- */

undefined2 FUN_1000_fd6a(char param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  
  if (param_1 == 'H') {
    if (*(int *)0x88 < 1) {
      iVar1 = 7;
    }
    else {
      iVar1 = *(int *)0x88 + -1;
    }
    *(int *)0x88 = iVar1;
    uVar2 = 1;
  }
  else if (param_1 == 'K') {
    if (*(int *)0x86 < 1) {
      iVar1 = 7;
    }
    else {
      iVar1 = *(int *)0x86 + -1;
    }
    *(int *)0x86 = iVar1;
    uVar2 = 1;
  }
  else if (param_1 == 'M') {
    if (*(int *)0x86 < 7) {
      iVar1 = *(int *)0x86 + 1;
    }
    else {
      iVar1 = 0;
    }
    *(int *)0x86 = iVar1;
    uVar2 = 1;
  }
  else if (param_1 == 'P') {
    if (*(int *)0x88 < 7) {
      iVar1 = *(int *)0x88 + 1;
    }
    else {
      iVar1 = 0;
    }
    *(int *)0x88 = iVar1;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* ---- FUN_1000_fdf2 @ 1000:fdf2 ---- */

int FUN_1000_fdf2(int param_1)

{
  if (param_1 < 0) {
    param_1 = -param_1;
  }
  return param_1;
}



/* ---- FUN_1000_fe0c @ 1000:fe0c ---- */

int FUN_1000_fe0c(int param_1,int param_2)

{
  if (param_2 <= param_1) {
    param_2 = param_1;
  }
  return param_2;
}



/* ---- FUN_1000_fe2b @ 1000:fe2b ---- */

int FUN_1000_fe2b(int param_1,int param_2)

{
  if (param_1 <= param_2) {
    param_2 = param_1;
  }
  return param_2;
}



/* ---- FUN_1000_fe4a @ 1000:fe4a ---- */

uint FUN_1000_fe4a(uint param_1)

{
  return param_1 & 1;
}



/* ---- FUN_1000_fe59 @ 1000:fe59 ---- */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0001ff92) */
/* WARNING: Removing unreachable block (ram,0x00010024) */
/* WARNING: Removing unreachable block (ram,0x00010029) */
/* WARNING: Removing unreachable block (ram,0x00010031) */
/* WARNING: Removing unreachable block (ram,0x00010049) */
/* WARNING: Removing unreachable block (ram,0x0001004e) */
/* WARNING: Removing unreachable block (ram,0x00010066) */
/* WARNING: Removing unreachable block (ram,0x0001006b) */
/* WARNING: Removing unreachable block (ram,0x00010083) */
/* WARNING: Removing unreachable block (ram,0x00010026) */
/* WARNING: Removing unreachable block (ram,0x00010088) */
/* WARNING: Removing unreachable block (ram,0x000100a4) */
/* WARNING: Removing unreachable block (ram,0x000100ab) */
/* WARNING: Removing unreachable block (ram,0x000100c5) */
/* WARNING: Removing unreachable block (ram,0x000100dd) */
/* WARNING: Removing unreachable block (ram,0x00010170) */
/* WARNING: Removing unreachable block (ram,0x00010188) */
/* WARNING: Removing unreachable block (ram,0x000101aa) */
/* WARNING: Removing unreachable block (ram,0x000101b0) */
/* WARNING: Removing unreachable block (ram,0x000101e5) */
/* WARNING: Removing unreachable block (ram,0x0001021c) */
/* WARNING: Removing unreachable block (ram,0x000101ef) */
/* WARNING: Removing unreachable block (ram,0x000101fe) */
/* WARNING: Removing unreachable block (ram,0x00010215) */
/* WARNING: Removing unreachable block (ram,0x0001021a) */
/* WARNING: Removing unreachable block (ram,0x00010221) */
/* WARNING: Removing unreachable block (ram,0x0001023d) */
/* WARNING: Removing unreachable block (ram,0x00010242) */
/* WARNING: Removing unreachable block (ram,0x0001024a) */
/* WARNING: Removing unreachable block (ram,0x0001019e) */
/* WARNING: Removing unreachable block (ram,0x00010186) */

void FUN_1000_fe59()

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int aiStack_1f8 [242];
  int local_14;
  uint local_8;
  int local_6;
  
  *(undefined2 *)0xb0d6 = 0;
  *(undefined2 *)0xb0a4 = 0;
  *(undefined2 *)0x57c0 = 0;
  *(undefined2 *)0x8d28 = 0;
  for (local_8 = 0; (int)local_8 < 0x78; local_8 = local_8 + 1) {
    if ((((local_8 & 0x88) == 0) && (bVar1 = *(byte *)(local_8 * 4 + -0x5746), bVar1 != 0)) &&
       (bVar1 != 1)) {
      local_14 = *(int *)((uint)bVar1 * 2 + 0x54c);
      *(int *)0xb0a4 = *(int *)0xb0a4 + local_14;
      if (bVar1 == 6) {
        *(int *)0x57c0 = *(int *)0x57c0 + *(int *)0x558;
      }
      if (*(char *)(local_8 * 4 + -0x5745) == '\0') {
        local_14 = -local_14;
      }
      *(int *)0x8d28 = *(int *)0x8d28 - local_14;
    }
  }
  uVar3 = FUN_1000_fe0c(0,*(int *)0xb0a4 + -0x2000);
  uVar7 = (int)uVar3 >> 0xf;
  *(int *)0x8182 = ((int)((uVar3 ^ uVar7) - uVar7) >> 8 ^ uVar7) - uVar7;
  iVar4 = FUN_1000_fdf2(*(undefined2 *)0x8d28);
  iVar6 = *(int *)0x552;
  iVar2 = *(int *)0x554;
  iVar5 = FUN_1000_fdf2(*(undefined2 *)0x8d28);
  *(uint *)0xb0d6 =
       (uint)((*(int *)0xb0a4 - iVar5) / 2 <= *(int *)0x554 * 2 && iVar6 - iVar2 <= iVar4);
  local_8 = 0;
  iVar6 = FUN_1000_fe0c(0,-((*(int *)0x55a + *(int *)0x55a) * 3 + -8));
  for (local_6 = 0; local_6 < 2; local_6 = local_6 + 1) {
    aiStack_1f8[local_8 + local_6 * 0x78] = (*(int *)0x59e * (*(int *)0x8182 + 8) * 3 >> 5) + iVar6;
    local_8 = local_8 ^ 0x70;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ---- FUN_2000_094c @ 2000:094c ---- */

int FUN_2000_094c(int param_1)

{
  int iVar1;
  undefined2 local_6;
  
  local_6 = 0;
  for (; param_1 != 0; param_1 = param_1 >> 1) {
    FUN_243e_ba6a(0x1000,param_1);
    if (iVar1 != 0) {
      local_6 = local_6 + 1;
    }
  }
  return local_6;
}



/* ---- FUN_2000_097c @ 2000:097c ---- */

void FUN_2000_097c(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined2 unaff_DS;
  
  iVar1 = param_1 * 8 + param_2 * 4;
  uVar2 = *(uint *)(iVar1 + -0x7014);
  uVar2 = ~(uVar2 << 1 | (int)uVar2 >> 1) & uVar2;
  FUN_2000_094c(*(undefined2 *)(iVar1 + -0x7012));
  FUN_2000_094c(uVar2);
  FUN_2000_094c(*(uint *)(iVar1 + -0x7012) & uVar2);
  return;
}



/* ---- FUN_2000_09f9 @ 2000:09f9 ---- */

void FUN_2000_09f9()

{
  return;
}



/* ---- FUN_2000_0a2c @ 2000:0a2c ---- */

void FUN_2000_0a2c(int param_1,int param_2)

{
  int iVar1;
  undefined2 unaff_DS;
  
  *(uint *)0x8d24 = ~*(uint *)(param_2 * 2 + 0x5ae);
  iVar1 = param_1 * 4 + *(int *)0x9880 * 8;
  *(uint *)(iVar1 + -0x7014) =
       *(uint *)(iVar1 + -0x7014) & *(uint *)0x8d24 | *(uint *)(iVar1 + -0x7012);
  *(uint *)(iVar1 + -0x7012) = *(uint *)(iVar1 + -0x7012) & *(uint *)0x8d24;
  FUN_2000_097c(*(int *)0x9880 + -1,param_1);
  FUN_2000_097c(*(undefined2 *)0x9880,param_1);
  return;
}



/* ---- FUN_2000_0a93 @ 2000:0a93 ---- */

void FUN_2000_0a93(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  *(undefined2 *)0x8d24 = *(undefined2 *)(param_2 * 2 + 0x5ae);
  uVar1 = ~*(uint *)(param_3 * 2 + 0x5ae);
  iVar2 = param_1 * 4 + *(int *)0x9880 * 8;
  *(uint *)(iVar2 + -0x7012) =
       *(uint *)(iVar2 + -0x7012) | *(uint *)(iVar2 + -0x7014) & *(uint *)0x8d24;
  *(uint *)(iVar2 + -0x7014) =
       *(uint *)(iVar2 + -0x7014) & uVar1 | *(uint *)(iVar2 + -0x7012) | *(uint *)0x8d24;
  *(uint *)(iVar2 + -0x7012) = *(uint *)(iVar2 + -0x7012) & uVar1;
  FUN_2000_097c(*(int *)0x9880 + -1,param_1);
  FUN_2000_097c(*(undefined2 *)0x9880,param_1);
  return;
}



/* ---- FUN_2000_0b15 @ 2000:0b15 ---- */

void FUN_2000_0b15(uint param_1,uint param_2,uint param_3,undefined2 param_4)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_DS;
  undefined2 local_a;
  undefined2 local_8;
  int local_6;
  undefined2 local_4;
  
  uVar5 = 0x1000;
  local_4 = 6;
  *(undefined2 *)0x5be = 0;
  if (param_3 != 0) {
    if ((char)param_4 == '\x01') {
      uVar5 = 0;
      func_0x000095df(0x1000,param_1,&local_a,&local_8);
      FUN_2000_09f9(3,*(undefined2 *)0x9846,local_8);
      FUN_2000_09f9(3,*(undefined2 *)0x9846,local_a);
      *(int *)0x5be = iVar1 - iVar4;
      if ((int)param_2 < (int)param_1) {
        *(int *)0x5be = *(int *)0x5be + *(int *)0x59c;
      }
      else {
        *(int *)0x5be = *(int *)0x5be + *(int *)0x59a;
      }
    }
    else if ((char)param_4 == '\x06') {
      local_6 = param_1 - *(int *)(*(int *)0x9846 * 2 + 0x50a);
      FUN_2000_09f9(6,*(undefined2 *)0xa836,local_6);
      *(undefined2 *)0x5be = uVar2;
    }
    else {
      FUN_2000_0a2c(*(undefined2 *)0x9846,param_2 & 7);
      FUN_2000_09f9(6,*(undefined2 *)0x9846,param_2);
      FUN_2000_09f9((char)param_4,*(undefined2 *)0x9846,param_2);
      *(int *)0x5be = (iVar3 - iVar1) + iVar4;
    }
  }
  if ((*(unsigned char *)((char *)&param_4 + 1)) != '\0') {
    FUN_2000_09f9((*(unsigned char *)((char *)&param_4 + 1)),*(undefined2 *)0xa836,param_1);
    *(int *)0x5be = *(int *)0x5be + iVar4;
    FUN_243e_ba12(uVar5,*(undefined2 *)0x8de0);
    if (((0xff < iVar4) && ((*(unsigned char *)((char *)&param_4 + 1)) != '\x06')) &&
       ((*(int *)0x57c8 == *(int *)0xa836) == -1 < *(int *)0x8de0)) {
      *(int *)0x5be = *(int *)0x5be + -0x10;
    }
  }
  iVar4 = *(int *)0x9880 * 8;
  uVar5 = *(undefined2 *)(iVar4 + -0x701a);
  *(undefined2 *)(iVar4 + -0x7014) = *(undefined2 *)(iVar4 + -0x701c);
  *(undefined2 *)(iVar4 + -0x7012) = uVar5;
  uVar5 = *(undefined2 *)(iVar4 + -0x7016);
  *(undefined2 *)(iVar4 + -0x7010) = *(undefined2 *)(iVar4 + -0x7018);
  *(undefined2 *)(iVar4 + -0x700e) = uVar5;
  if (((uint)((char)param_4 == '\x06') & ((*(unsigned char *)((char *)&param_4 + 1)) != '\0' | param_3)) != 0) {
    FUN_2000_0a93(*(undefined2 *)0x9846,param_1 & 7,param_2 & 7);
    *(int *)0x5be = *(int *)0x5be + iVar4;
  }
  if (((char)param_4 == '\x06' & param_3) != 0 || (*(unsigned char *)((char *)&param_4 + 1)) == '\x06') {
    FUN_2000_0a2c(*(undefined2 *)0xa836,param_1 & 7);
    *(int *)0x5be = *(int *)0x5be - iVar4;
  }
  FUN_2000_09f9((char)param_4,*(undefined2 *)0x9846,param_2);
  FUN_2000_09f9((char)param_4,*(undefined2 *)0x9846,param_1);
  return;
}



/* ---- FUN_2000_0d30 @ 2000:0d30 ---- */

undefined1 FUN_2000_0d30()

{
  code *pcVar1;
  undefined1 uVar2;
  undefined2 unaff_DS;
  
  pcVar1 = (code *)swi(0x14);
  (*pcVar1)();
  uVar2 = in(CONCAT11((char)((uint)*(undefined2 *)0x2ebe >> 8),0xf8));
  return uVar2;
}



/* ---- FUN_2000_0eb2 @ 2000:0eb2 ---- */

void FUN_2000_0eb2()

{
  code *pcVar1;
  long lVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  int iVar5;
  undefined2 in_BX;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  
  *(undefined1 *)0x2eae = 0xff;
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  *(undefined2 *)0x2eaf = in_BX;
  *(undefined2 *)0x2eb1 = unaff_ES;
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  iVar5 = 0;
  do {
  } while (*(char *)0x2eae != '\0');
  do {
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  out(0x43,0);
  uVar3 = in(0x40);
  uVar4 = in(0x40);
  lVar2 = (ulong)(uint)-CONCAT11(uVar4,uVar3) * 0x346;
  iVar5 = (int)((ulong)lVar2 >> 0x10);
  if ((int)lVar2 < 0) {
    iVar5 = iVar5 + 1;
  }
  *(int *)0x2eb3 = (uint)*(byte *)0x2eae * 0x346 + iVar5;
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  return;
}



/* ---- FUN_2000_0f21 @ 2000:0f21 ---- */

undefined2 FUN_2000_0f21(undefined2 param_1,undefined2 param_2,int param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  iVar5 = (int)(CONCAT22(param_2,param_1) / (ulong)*(uint *)0x2eb3);
  iVar6 = iVar5 + -2;
  if (iVar6 == 0 || iVar5 < 2) {
    iVar6 = 1;
  }
  iVar5 = ((uint)param_4 >> 4) + (int)((ulong)param_4 >> 0x10) + -0x800;
  pcVar8 = (char *)(((uint)param_4 & 0xf) + 0x8000);
  uVar2 = in(0x21);
  *(undefined1 *)0x2eb9 = uVar2;
  out(0x21,0xe7);
  bVar3 = in(0x61);
  bVar3 = bVar3 & 0xfd;
  do {
    bVar3 = bVar3 ^ 2;
    out(0x61,bVar3);
    pcVar1 = pcVar8;
    pcVar8 = pcVar8 + 1;
    cVar4 = *pcVar1;
    iVar7 = iVar6;
    do {
      do {
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      cVar4 = cVar4 + -1;
      iVar7 = iVar6;
    } while (cVar4 != '\0');
    param_3 = param_3 + -1;
  } while (param_3 != 0);
  out(0x21,*(undefined1 *)0x2eb9);
  return CONCAT11((char)((uint)iVar5 >> 8),*(undefined1 *)0x2eb9);
}



/* ---- entry @ 243e:0001 ---- */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: This function may have set the stack pointer */

void entry(void)

{
  char *pcVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  char cVar4;
  char extraout_AH;
  int in_BX;
  int unaff_BP;
  undefined2 *unaff_SI;
  undefined2 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  DAT_243e_051f = 0x43e4;
  FUN_243e_0024();
  if (SBORROW2(unaff_BP,1)) {
    puVar3 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    puVar2 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    *puVar3 = *puVar2;
  }
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + cVar4;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + extraout_AH;
  pcVar1 = (char *)((int)unaff_DI + unaff_BP + 0x55);
  *pcVar1 = *pcVar1 + cVar4;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ---- FUN_243e_0024 @ 243e:0024 ---- */

void FUN_243e_0024()

{
  undefined2 param_1 = 0; uint param_2 = 0;
  undefined1 *puVar1;
  int *piVar2;
  char *pcVar3;
  undefined1 *puVar4;
  int *piVar5;
  undefined2 uVar6;
  code *pcVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint extraout_DX;
  int *piVar11;
  undefined1 *puVar12;
  undefined4 *puVar13;
  char *pcVar14;
  int *piVar15;
  undefined1 *puVar16;
  undefined2 unaff_ES;
  bool bVar17;
  int *in_stack_00000000;
  undefined2 in_stack_0000000c;
  uint in_stack_00000014;
  
  *(undefined1 *)(in_stack_00000000 + 0x198) = 0;
  uVar6 = *(undefined2 *)0x2c;
  iVar9 = 0x1000;
  pcVar14 = (char *)0x0;
code_r0x0002442e:
  do {
    if (iVar9 != 0) {
      iVar9 = iVar9 + -1;
      pcVar3 = pcVar14;
      pcVar14 = pcVar14 + 1;
      if (*pcVar3 != '\0') goto code_r0x0002442e;
    }
  } while (*pcVar14 != '\0');
  *(undefined2 *)((int)in_stack_00000000 + 0x331) = pcVar14 + 3;
  pcVar7 = (code *)swi(0x21);
  (*pcVar7)();
  pcVar7 = (code *)swi(0x21);
  (*pcVar7)();
  pcVar7 = (code *)swi(0x21);
  (*pcVar7)();
  pcVar7 = (code *)swi(0x21);
  (*pcVar7)();
  if (*(uint *)((int)in_stack_00000000 + 0x35f) < extraout_DX) {
LAB_243e_009d:
    *(undefined1 *)(in_stack_00000000 + 0x198) = 1;
  }
  else {
    if (extraout_DX != *(uint *)((int)in_stack_00000000 + 0x35f)) goto LAB_243e_01c0;
    if (param_2 != *(uint *)((int)in_stack_00000000 + 0x35d)) {
      if (param_2 < *(uint *)((int)in_stack_00000000 + 0x35d)) goto LAB_243e_01c0;
      goto LAB_243e_009d;
    }
  }
  iVar9 = 0x10;
  *(undefined2 *)((int)in_stack_00000000 + 0x333) = uVar6;
  piVar11 = (int *)((int)in_stack_00000000 + 0x335);
  bVar17 = in_stack_00000000 == (int *)0x0;
  piVar15 = in_stack_00000000;
  do {
    if (iVar9 == 0) break;
    iVar9 = iVar9 + -1;
    piVar5 = piVar15;
    piVar15 = piVar15 + 1;
    piVar2 = piVar11;
    piVar11 = piVar11 + 1;
    bVar17 = *piVar2 == *piVar5;
  } while (bVar17);
  if (bVar17) {
    if ((char)in_stack_00000000[0x198] != '\x01') goto LAB_243e_01c0;
    FUN_243e_0230();
    pcVar7 = (code *)swi(0x21);
    (*pcVar7)();
    pcVar7 = (code *)swi(0x21);
    (*pcVar7)();
    pcVar7 = (code *)swi(0x21);
    (*pcVar7)();
    pcVar7 = (code *)swi(0x21);
    (*pcVar7)();
  }
  else {
    FUN_243e_0230();
    iVar9 = 0x2000 - *(int *)((int)in_stack_00000000 + 0x37b);
    do {
      piVar15 = (int *)0x6;
      piVar11 = (int *)((int)in_stack_00000000 + 0x355);
      if (iVar9 + 1 == -0x6000) goto LAB_243e_01c0;
      iVar10 = 4;
      bVar17 = false;
      do {
        if (iVar10 == 0) break;
        iVar10 = iVar10 + -1;
        piVar5 = piVar15;
        piVar15 = piVar15 + 1;
        piVar2 = piVar11;
        piVar11 = piVar11 + 1;
        bVar17 = *piVar2 == *piVar5;
      } while (bVar17);
      iVar9 = iVar9 + 1;
    } while (!bVar17);
    pcVar7 = (code *)swi(0x21);
    (*pcVar7)();
    pcVar7 = (code *)swi(0x21);
    (*pcVar7)();
    iVar9 = 0x25;
    piVar11 = in_stack_00000000 + 0x198;
    do {
      *(undefined1 *)piVar11 = 0;
      piVar11 = (int *)((int)piVar11 + 1);
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    pcVar7 = (code *)swi(0x21);
    (*pcVar7)();
    pcVar7 = (code *)swi(0x21);
    (*pcVar7)();
    for (iVar9 = (*(int *)((int)in_stack_00000000 + 0x35f) -
                 (uint)(*(uint *)((int)in_stack_00000000 + 0x35d) < in_stack_00000014)) * 2;
        iVar9 != 0; iVar9 = iVar9 + -1) {
      pcVar7 = (code *)swi(0x21);
      (*pcVar7)();
    }
    pcVar7 = (code *)swi(0x21);
    (*pcVar7)();
    pcVar7 = (code *)swi(0x21);
    (*pcVar7)();
  }
  pcVar7 = (code *)swi(0x21);
  (*pcVar7)();
  pcVar7 = (code *)swi(0x21);
  (*pcVar7)();
  pcVar7 = (code *)swi(0x21);
  (*pcVar7)();
LAB_243e_01c0:
  iVar9 = 0x2000 - *(int *)((int)in_stack_00000000 + 0x37b);
  puVar12 = (undefined1 *)((int)in_stack_00000000 + 0x363);
  puVar16 = (undefined1 *)0x0;
  for (iVar10 = 0xe; iVar10 != 0; iVar10 = iVar10 + -1) {
    puVar4 = puVar16;
    puVar16 = puVar16 + 1;
    puVar1 = puVar12;
    puVar12 = puVar12 + 1;
    *puVar4 = *puVar1;
  }
  if (*(int *)((int)in_stack_00000000 + 0x381) != 0) {
    iVar8 = 0x2000 - *(int *)((int)in_stack_00000000 + 0x381);
    iVar10 = *(int *)0x6;
    if (iVar10 != 0) {
      puVar13 = (undefined4 *)*(undefined2 *)0x18;
      do {
        *(int *)((int)puVar13 + 2) = *(int *)((int)puVar13 + 2) + iVar9;
        *(int *)*puVar13 = *(int *)*puVar13 + iVar9;
        puVar13 = puVar13 + 1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
  }
  *(int *)((int)in_stack_00000000 + 0x373) = *(int *)((int)in_stack_00000000 + 0x373) + iVar9;
                    /* WARNING: Could not recover jumptable at 0x0002460b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(ulong)*(uint *)((int)in_stack_00000000 + 0x371))();
  return;
}



/* ---- FUN_243e_0230 @ 243e:0230 ---- */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00024751) overlaps instruction at (ram,0x00024750)
    */
/* WARNING: Removing unreachable block (ram,0x000246ce) */
/* WARNING: Removing unreachable block (ram,0x00024688) */
/* WARNING: Removing unreachable block (ram,0x000246e9) */
/* WARNING: Removing unreachable block (ram,0x000246ec) */
/* WARNING: Removing unreachable block (ram,0x000246d3) */
/* WARNING: Removing unreachable block (ram,0x000246e0) */
/* WARNING: Removing unreachable block (ram,0x0002466b) */
/* WARNING: Removing unreachable block (ram,0x000246e2) */
/* WARNING: Removing unreachable block (ram,0x000246e3) */
/* WARNING: Removing unreachable block (ram,0x0002467d) */
/* WARNING: Removing unreachable block (ram,0x00024682) */
/* WARNING: Removing unreachable block (ram,0x00024684) */
/* WARNING: Removing unreachable block (ram,0x00024686) */
/* WARNING: Removing unreachable block (ram,0x000246eb) */
/* WARNING: Removing unreachable block (ram,0x000246ee) */
/* WARNING: Removing unreachable block (ram,0x000246f7) */
/* WARNING: Removing unreachable block (ram,0x000246fa) */
/* WARNING: Removing unreachable block (ram,0x00024606) */
/* WARNING: Removing unreachable block (ram,0x0002460d) */
/* WARNING: Removing unreachable block (ram,0x00024614) */
/* WARNING: Removing unreachable block (ram,0x000246fb) */
/* WARNING: Removing unreachable block (ram,0x00024724) */

void FUN_243e_0230()
{
  uint param_1 = 0;
  undefined2 param_2 = 0;
  undefined2 param_3 = 0;
  undefined2 param_4 = 0;
  undefined2 param_5 = 0;
  undefined2 param_6 = 0;
  undefined2 param_7 = 0;
  byte *pbVar1;
  undefined1 *puVar2;
  uint *puVar3;
  undefined1 *puVar4;
  undefined1 uVar5;
  uint uVar6;
  long lVar7;
  code *pcVar8;
  byte bVar9;
  byte bVar10;
  char cVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  byte bVar15;
  char cVar16;
  int iVar17;
  int in_BX;
  uint uVar18;
  undefined4 in_EBP;
  undefined1 *puVar19;
  undefined4 *puVar20;
  undefined1 *unaff_SI;
  uint *puVar21;
  undefined1 *puVar22;
  int *unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_GS;
  bool bVar23;
  bool bVar24;
  undefined4 uVar25;
  undefined2 in_stack_00000000;
  undefined2 uStack_e;
  undefined1 *puStack_c;
  undefined1 *puStack_a;
  int iStack_8;
  uint uStack_4;
  uint in_stack_0000fffe;
  
  do {
    pcVar8 = (code *)swi(0x21);
    (*pcVar8)();
    pcVar8 = (code *)swi(0x21);
    param_3 = (*pcVar8)();
    pcVar8 = (code *)swi(0x21);
    (*pcVar8)();
    pcVar8 = (code *)swi(0x21);
    (*pcVar8)();
    uVar18 = (uint)in_EBP;
    bVar9 = (byte)in_stack_00000000;
    if ((bVar9 == 0x77) || (bVar9 == 0x57)) {
      return;
    }
    if ((bVar9 == 0x66) || (bVar9 == 0x46)) {
      param_1 = 0x2000 - *(int *)(uVar18 + 0x47e);
      puVar19 = (undefined1 *)(uVar18 + 0x466);
      puVar22 = (undefined1 *)0x0;
      for (iVar17 = 0xe; iVar17 != 0; iVar17 = iVar17 + -1) {
        puVar4 = puVar22;
        puVar22 = puVar22 + 1;
        puVar2 = puVar19;
        puVar19 = puVar19 + 1;
        *puVar4 = *puVar2;
      }
      if (*(int *)(uVar18 + 0x484) != 0) {
        iVar12 = 0x2000 - *(int *)(uVar18 + 0x484);
        iVar17 = *(int *)0x6;
        if (iVar17 != 0) {
          puVar20 = (undefined4 *)*(undefined2 *)0x18;
          do {
            *(int *)((int)puVar20 + 2) = *(int *)((int)puVar20 + 2) + param_1;
            *(int *)*puVar20 = *(int *)*puVar20 + param_1;
            puVar20 = puVar20 + 1;
            iVar17 = iVar17 + -1;
          } while (iVar17 != 0);
        }
      }
      *(int *)(uVar18 + 0x476) = *(int *)(uVar18 + 0x476) + param_1;
                    /* WARNING: Could not recover jumptable at 0x0002460b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(ulong)*(uint *)(uVar18 + 0x474))();
      return;
    }
  } while ((bVar9 != 0x62) && (bVar9 != 0x42));
  pcVar8 = (code *)swi(0x21);
  uVar25 = (*pcVar8)();
  uVar14 = (uint)((ulong)uVar25 >> 0x10);
  uVar13 = (uint)uVar25;
  puVar21 = (uint *)(unaff_SI + 1);
  out(*unaff_SI,uVar14);
  if (in_BX == -1) {
    uStack_4 = 0;
    in_stack_0000fffe = uVar14;
code_r0x00024743:
    *(int *)(uStack_4 + (int)puVar21) = *(int *)(uStack_4 + (int)puVar21) + uVar13;
    bVar9 = (byte)uVar13;
    *(byte *)(uStack_4 + (int)puVar21) = *(byte *)(uStack_4 + (int)puVar21) & bVar9;
    *(char *)(uStack_4 + (int)puVar21) = *(char *)(uStack_4 + (int)puVar21) + bVar9;
    *(char *)(uStack_4 + (int)puVar21) = *(char *)(uStack_4 + (int)puVar21) + bVar9;
    *(char *)(uStack_4 + (int)puVar21) = *(char *)(uStack_4 + (int)puVar21) + bVar9;
    *(char *)(uStack_4 + (int)puVar21) = *(char *)(uStack_4 + (int)puVar21) + bVar9;
code_r0x0002474f:
    bVar10 = (byte)uVar13;
    *(char *)(uStack_4 + (int)puVar21) = *(char *)(uStack_4 + (int)puVar21) + bVar10;
    *(char *)(uStack_4 + (int)puVar21) = *(char *)(uStack_4 + (int)puVar21) + bVar10;
    pbVar1 = (byte *)(uStack_4 + (int)puVar21);
    bVar9 = *pbVar1;
    *pbVar1 = *pbVar1 + bVar10;
    bVar15 = bVar10 + *(byte *)(uStack_4 + (int)puVar21);
    cVar11 = bVar15 + CARRY1(bVar9,bVar10);
    uVar14 = (uint)(CARRY1(bVar10,*(byte *)(uStack_4 + (int)puVar21)) ||
                   CARRY1(bVar15,CARRY1(bVar9,bVar10)));
    bVar24 = CARRY2(in_stack_0000fffe,*puVar21);
    uVar6 = in_stack_0000fffe + *puVar21;
    in_stack_0000fffe = uVar6 + uVar14;
    iVar17 = CONCAT11(((char)(uVar13 >> 8) - *(char *)((int)puVar21 + (uVar18 - 0x80))) -
                      (bVar24 || CARRY2(uVar6,uVar14)),cVar11);
    *(char *)(uStack_4 + (int)unaff_DI) = *(char *)(uStack_4 + (int)unaff_DI) + cVar11;
  }
  else {
    unaff_DI = (int *)(puStack_c + 1);
    uVar5 = in(in_stack_0000fffe);
    *puStack_c = uVar5;
    pbVar1 = puStack_a + uStack_4 + 0x6f;
    *pbVar1 = *pbVar1 & (byte)in_stack_0000fffe;
    lVar7 = (long)*(int *)(iStack_8 + 0x74) * 0x4120;
    uVar18 = (uint)lVar7;
    bVar23 = (int)uVar18 != lVar7;
    puVar21 = (uint *)(puStack_a + 1);
    out(*puStack_a,in_stack_0000fffe);
    bVar24 = true;
    uVar13 = param_1;
    if (*pbVar1 == 0) {
LAB_243e_02ed:
      if (!bVar24) {
        uVar5 = in(in_stack_0000fffe);
        *(undefined1 *)unaff_DI = uVar5;
        unaff_DI = (int *)(puStack_c + 3);
        uVar5 = in(in_stack_0000fffe);
        puStack_c[2] = uVar5;
        if (!bVar23) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        goto code_r0x00024743;
      }
      *(char *)(uStack_4 + (int)puVar21) = *(char *)(uStack_4 + (int)puVar21) + (char)uVar13;
      *(char *)(uStack_4 + (int)puVar21) = *(char *)(uStack_4 + (int)puVar21) + (char)uVar13;
      pbVar1 = (byte *)(uVar18 + (int)puVar21);
      bVar9 = *pbVar1;
      bVar15 = (byte)(uVar13 >> 8);
      *pbVar1 = *pbVar1 + bVar15;
      *unaff_DI = (*unaff_DI - (int)puVar21) - (uint)CARRY1(bVar9,bVar15);
      uVar14 = uStack_4;
    }
    else {
      uVar13 = param_1 + 0x96aa;
      if (param_1 < 0x6956) goto code_r0x0002474f;
      bVar10 = (byte)((uint)in_stack_00000000 >> 8);
      bVar15 = (byte)(uVar13 >> 8);
      if (uVar13 == 0) {
        DAT_9000_b1a0 = DAT_9000_b1a0 & bVar10;
        if ((long)(int)&param_1 == (long)*(int *)(uStack_4 + (int)puVar21) * 0x7577) {
          *(undefined1 *)(uStack_4 + 0x65) = 0;
          *(undefined1 *)(uStack_4 + (int)unaff_DI) = 0;
          *(byte *)(uVar18 + (int)puVar21) = *(byte *)(uVar18 + (int)puVar21) & bVar9;
          puStack_c[0x6a] = puStack_c[0x6a] & 0x69;
          puVar3 = puVar21;
          puVar21 = (uint *)(puStack_a + 2);
          out((char)*puVar3,in_stack_0000fffe);
          *(byte *)(uVar18 + (int)puVar21) = *(byte *)(uVar18 + (int)puVar21) & bVar9;
          uVar13 = 0x7f5b;
          pbVar1 = (byte *)(uStack_4 + 0x69);
          bVar23 = false;
          *pbVar1 = *pbVar1 & (byte)in_stack_0000fffe;
          bVar24 = *pbVar1 == 0;
          uVar18 = param_1;
          goto LAB_243e_02ed;
        }
      }
      else {
        *(byte *)(uStack_4 + (int)puVar21) = *(byte *)(uStack_4 + (int)puVar21) & bVar15;
        *(byte *)(uStack_4 + (int)puVar21) = *(byte *)(uStack_4 + (int)puVar21) & bVar15;
      }
      *(byte *)(uVar18 + (int)puVar21) = *(byte *)(uVar18 + (int)puVar21) & bVar9;
      puVar21 = (uint *)(puStack_a + 2);
      *(byte *)(uStack_4 + 0x20) = *(byte *)(uStack_4 + 0x20) & bVar10;
      in_stack_0000fffe = in_stack_0000fffe + 1;
      puStack_a[0x74] = puStack_a[0x74] & (bVar15 | 0x2c);
      puVar3 = (uint *)((int)unaff_DI + uVar18 + 0x6b);
      *puVar3 = *puVar3 & 0x6e65;
      *(undefined1 *)(uStack_4 + (int)puVar21) = *(undefined1 *)(uStack_4 + (int)puVar21);
      *(undefined1 *)(uStack_4 + (int)puVar21) = *(undefined1 *)(uStack_4 + (int)puVar21);
      *(undefined1 *)(uStack_4 + (int)puVar21) = *(undefined1 *)(uStack_4 + (int)puVar21);
      uVar13 = uStack_4;
      uVar14 = (uint)(bVar15 | 0x2c) << 8;
    }
    cVar11 = (char)uVar14;
    *(char *)(uVar13 + (int)puVar21) = *(char *)(uVar13 + (int)puVar21) + cVar11;
    *(char *)(uVar13 + (int)puVar21) = *(char *)(uVar13 + (int)puVar21) + cVar11;
    *(char *)(uVar13 + (int)puVar21) = *(char *)(uVar13 + (int)puVar21) + cVar11;
    *(char *)(uVar13 + (int)puVar21) = *(char *)(uVar13 + (int)puVar21) + cVar11;
    *(char *)(uVar13 + (int)puVar21) = *(char *)(uVar13 + (int)puVar21) + cVar11;
    *(char *)(uVar13 + (int)puVar21) = *(char *)(uVar13 + (int)puVar21) + cVar11;
    *(char *)(uVar13 + (int)puVar21) = *(char *)(uVar13 + (int)puVar21) + cVar11;
    *(char *)(uVar13 + (int)puVar21) = *(char *)(uVar13 + (int)puVar21) + cVar11;
    *(char *)(uVar13 + (int)puVar21) = *(char *)(uVar13 + (int)puVar21) + cVar11;
    *(char *)(uVar13 + (int)puVar21) = *(char *)(uVar13 + (int)puVar21) + cVar11;
    *(char *)(uVar13 + (int)puVar21) = *(char *)(uVar13 + (int)puVar21) + cVar11;
    *(char *)(uVar13 + (int)puVar21) = *(char *)(uVar13 + (int)puVar21) + cVar11;
    *(char *)(uVar13 + (int)puVar21) = *(char *)(uVar13 + (int)puVar21) + cVar11;
    *(char *)(uVar13 + (int)puVar21) = *(char *)(uVar13 + (int)puVar21) + cVar11;
    *(char *)(uVar13 + (int)puVar21) = *(char *)(uVar13 + (int)puVar21) + cVar11;
    uStack_4 = CONCAT11((char)(uVar13 >> 8),(byte)uVar13 & *(byte *)(uVar13 + (int)unaff_DI));
    pbVar1 = (byte *)((int)unaff_DI + uStack_4 + 0x49);
    *pbVar1 = *pbVar1 ^ 1;
    cVar16 = (char)((uVar14 ^ 0x5993) >> 8);
    *(char *)(uStack_4 + (int)puVar21) = *(char *)(uStack_4 + (int)puVar21) + cVar16;
    cVar11 = (char)(uVar14 ^ 0x5993);
    *(char *)(uStack_4 + (int)puVar21) = *(char *)(uStack_4 + (int)puVar21) + cVar11;
    *(char *)(uStack_4 + (int)puVar21) = *(char *)(uStack_4 + (int)puVar21) + cVar11;
    *(char *)(uStack_4 + (int)puVar21) = *(char *)(uStack_4 + (int)puVar21) + cVar11;
    *(char *)(uStack_4 + (int)puVar21) = *(char *)(uStack_4 + (int)puVar21) + cVar11;
    *(char *)(uStack_4 + (int)puVar21) = *(char *)(uStack_4 + (int)puVar21) + cVar11;
    *(char *)(uStack_4 + (int)puVar21) = *(char *)(uStack_4 + (int)puVar21) + cVar11;
    *(char *)(uStack_4 + (int)puVar21) = *(char *)(uStack_4 + (int)puVar21) + cVar11;
    bVar15 = (byte)in_stack_0000fffe;
    *(char *)(uVar18 + (int)puVar21) = *(char *)(uVar18 + (int)puVar21) + bVar15;
    pbVar1 = (byte *)(uVar18 + (int)unaff_DI);
    bVar9 = *pbVar1;
    *pbVar1 = *pbVar1 + bVar15;
    iVar17 = CONCAT11(cVar16,cVar11 + '\x1a' + CARRY1(bVar9,bVar15));
  }
  *(char *)0xd714 = *(char *)0xd714 + (char)(uStack_4 >> 8);
  *(int *)(uStack_4 + (int)puVar21) = *(int *)(uStack_4 + (int)puVar21) + iVar17;
  *(char *)(uStack_4 + (int)puVar21) = *(char *)(uStack_4 + (int)puVar21) + (char)iVar17;
  puVar3 = (uint *)((int)unaff_DI + uVar18 + 0x201);
  uVar18 = *puVar3;
  *puVar3 = (uint)(&_stack_var_0000 + *puVar3);
  if (CARRY2(uVar18,(uint)&_stack_var_0000)) {
    out(*puVar21,in_stack_0000fffe);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ---- FUN_243e_ba12 @ 243e:ba12 ---- */

/* WARNING: Control flow encountered bad instruction data */

void FUN_243e_ba12()

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ---- FUN_243e_ba6a @ 243e:ba6a ---- */

/* WARNING: Control flow encountered bad instruction data */

void FUN_243e_ba6a()

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* ---- Unresolved stubs for Ghidra func_0x* and FUN_ cross-references ---- */

/* FUN_1000_6cb4 - implemented in src/fun_6cb4.asm (not decompiled by Ghidra) */
int func_0x00011012() { return 0; }
/* func_0x00010eb2: overlay dispatch to FUN_2000_0eb2 (1000:0eb2 -> 2000:0eb2)
 * Called with 1 arg (segment ID); FUN_2000_0eb2 takes no args. */
int func_0x00010eb2() { FUN_2000_0eb2(); return 0; }
int func_0x00011f3e() { return 0; }
int func_0x00011f20() { return 0; }
int func_0x00011066() { return 0; }
/* func_0x* stubs: forward to actual named implementations where known.
 * The first argument (often 0x1000) is a segment ID for the overlay manager;
 * our single-segment build ignores it. */
int func_0x0000fbf6() { FUN_1000_fbf6(); return 0; }
int func_0x0000fce8() { FUN_1000_fce8(0); return 0; }
int func_0x0000fd4e() { return FUN_1000_fd4e(0); }
int func_0x0000fd6a() { return (int)FUN_1000_fd6a(0); }
int func_0x00011fa9() { return 0; }   /* overlay stub - no decompiled body */
int func_0x000110d0() { return 0; }   /* overlay stub */
int func_0x0000fe59() { FUN_1000_fe59(); return 0; }
/* func_0x00010b15: overlay dispatch to FUN_2000_0b15 (1000:0b15 -> 2000:0b15)
 * Called as (seg_id, p1, p2, p3, p4); skip seg_id, forward p1..p4. */
int func_0x00010b15(uint _seg, uint p1, uint p2, uint p3, undefined2 p4) {
    FUN_2000_0b15(p1, p2, p3, p4); return 0;
}
int func_0x00010de6(undefined2 a, undefined1 b) { return 0; }  /* overlay stub @ 1000:0de6 */
int func_0x00010e30() { return 0; }   /* overlay stub */
int func_0x00011084() { return 0; }   /* overlay stub */
int func_0x000095df() { FUN_1000_95df(0,0,0); return 0; }

