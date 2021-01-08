/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: keypad_template.c
 *
 * Code generated for Simulink model 'keypad_template'.
 *
 * Model version                  : 1.74
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Fri Dec 18 18:24:08 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "keypad_template.h"
#include "keypad_template_private.h"
#include "keypad_template_dt.h"

/* Block signals (default storage) */
B_keypad_template_T keypad_template_B;

/* Block states (default storage) */
DW_keypad_template_T keypad_template_DW;

/* Real-time model */
RT_MODEL_keypad_template_T keypad_template_M_;
RT_MODEL_keypad_template_T *const keypad_template_M = &keypad_template_M_;

/* Model step function */
void keypad_template_step(void)
{
  /* S-Function (keypad_sfcn): '<Root>/S-Function Builder' */
  keypad_sfcn_Outputs_wrapper( &keypad_template_B.SFunctionBuilder );

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  keypad_template_B.DataTypeConversion = keypad_template_B.SFunctionBuilder;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(0, (real_T)keypad_template_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(keypad_template_M)!=-1) &&
        !((rtmGetTFinal(keypad_template_M)-keypad_template_M->Timing.taskTime0) >
          keypad_template_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(keypad_template_M, "Simulation finished");
    }

    if (rtmGetStopRequested(keypad_template_M)) {
      rtmSetErrorStatus(keypad_template_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  keypad_template_M->Timing.taskTime0 =
    (++keypad_template_M->Timing.clockTick0) *
    keypad_template_M->Timing.stepSize0;
}

/* Model initialize function */
void keypad_template_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)keypad_template_M, 0,
                sizeof(RT_MODEL_keypad_template_T));
  rtmSetTFinal(keypad_template_M, -1);
  keypad_template_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  keypad_template_M->Sizes.checksums[0] = (3884138128U);
  keypad_template_M->Sizes.checksums[1] = (60119671U);
  keypad_template_M->Sizes.checksums[2] = (169910371U);
  keypad_template_M->Sizes.checksums[3] = (1504231656U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    keypad_template_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(keypad_template_M->extModeInfo,
      &keypad_template_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(keypad_template_M->extModeInfo,
                        keypad_template_M->Sizes.checksums);
    rteiSetTPtr(keypad_template_M->extModeInfo, rtmGetTPtr(keypad_template_M));
  }

  /* block I/O */
  (void) memset(((void *) &keypad_template_B), 0,
                sizeof(B_keypad_template_T));

  /* states (dwork) */
  (void) memset((void *)&keypad_template_DW, 0,
                sizeof(DW_keypad_template_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    keypad_template_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;
  }
}

/* Model terminate function */
void keypad_template_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
