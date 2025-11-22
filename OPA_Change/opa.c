
#include "opa.h"

static const DL_OPA_Config gOPA_1Config0 = {
    .pselChannel    = DL_OPA_PSEL_IN0_POS,
    .nselChannel    = DL_OPA_NSEL_RTAP,
    .mselChannel    = DL_OPA_MSEL_GND,
    .gain           = DL_OPA_GAIN_N1_P2,
    .outputPinState = DL_OPA_OUTPUT_PIN_ENABLED,
    .choppingMode   = DL_OPA_CHOPPING_MODE_DISABLE,
};

static const DL_OPA_Config gOPA_1Config1 = {
    .pselChannel    = DL_OPA_PSEL_IN0_POS,
    .nselChannel    = DL_OPA_NSEL_RTOP,
    .mselChannel    = DL_OPA_MSEL_OPEN,
    .gain           = DL_OPA_GAIN_N1_P2,
    .outputPinState = DL_OPA_OUTPUT_PIN_ENABLED,
    .choppingMode   = DL_OPA_CHOPPING_MODE_DISABLE,
};



// void OPA_0_init(uint8_t mode)
// {
//     DL_OPA_disable(OPA_0_INST);

//     if(mode==0){
//         DL_OPA_init(OPA_0_INST, (DL_OPA_Config *) &gOPA_0Config0);
//     }else{
//         DL_OPA_init(OPA_0_INST, (DL_OPA_Config *) &gOPA_0Config1);
//     }
//     DL_OPA_enableRailToRailInput(OPA_0_INST);
//     DL_OPA_setGainBandwidth(OPA_0_INST, DL_OPA_GBW_HIGH);

//     DL_OPA_enable(OPA_0_INST);
// }

void OPA_1_init(uint8_t mode)
{
    DL_OPA_disable(OPA_1_INST);

    if(mode==0){
        DL_OPA_init(OPA_1_INST, (DL_OPA_Config *) &gOPA_1Config0);
    }else {
        DL_OPA_init(OPA_1_INST, (DL_OPA_Config *) &gOPA_1Config1);
    }
    DL_OPA_enableRailToRailInput(OPA_1_INST);
    DL_OPA_setGainBandwidth(OPA_1_INST, DL_OPA_GBW_HIGH);

    DL_OPA_enable(OPA_1_INST);
}
