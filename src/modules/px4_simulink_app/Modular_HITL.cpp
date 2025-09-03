//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Modular_HITL.cpp
//
// Code generated for Simulink model 'Modular_HITL'.
//
// Model version                  : 2.20
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Thu Aug 28 13:20:24 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Modular_HITL.h"
#include "rtwtypes.h"
#include "Modular_HITL_types.h"
#include "Modular_HITL_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

// Named constants for Chart: '<Root>/Chart'
const uint8_T Modular_HITL_IN_AdjustGain = 1U;
const uint8_T Modular_HITL_IN_GainHold = 2U;
const uint8_T Modular_HITL_IN_ResetGain = 3U;

// Block signals (default storage)
B_Modular_HITL_T Modular_HITL_B;

// Block states (default storage)
DW_Modular_HITL_T Modular_HITL_DW;

// Real-time model
RT_MODEL_Modular_HITL_T Modular_HITL_M_ = RT_MODEL_Modular_HITL_T();
RT_MODEL_Modular_HITL_T *const Modular_HITL_M = &Modular_HITL_M_;

// Forward declaration for local functions
static void Modular__PX4Actuators_setupImpl(px4_internal_block_PX4Actuato_T *obj);
static void rate_monotonic_scheduler(void);

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to remember which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void Modular_HITL_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)Modular_HITL_M->StepTask(1));
  eventFlags[2] = ((boolean_T)Modular_HITL_M->StepTask(2));
}

//
//         This function updates active task flag for each subrate
//         and rate transition flags for tasks that exchange data.
//         The function assumes rate-monotonic multitasking scheduler.
//         The function must be called at model base rate so that
//         the generated code self-manages all its subrates and rate
//         transition flags.
//
static void rate_monotonic_scheduler(void)
{
  // To ensure a deterministic data transfer between two rates,
  //  data is transferred at the priority of a fast task and the frequency
  //  of the slow task.  The following flags indicate when the data transfer
  //  happens.  That is, a rate interaction flag is set true when both rates
  //  will run, and false otherwise.


  // tid 0 shares data with slower tid rates: 1, 2
  Modular_HITL_M->Timing.RateInteraction.TID0_1 =
    (Modular_HITL_M->Timing.TaskCounters.TID[1] == 0);
  Modular_HITL_M->Timing.RateInteraction.TID0_2 =
    (Modular_HITL_M->Timing.TaskCounters.TID[2] == 0);

  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (Modular_HITL_M->Timing.TaskCounters.TID[1])++;
  if ((Modular_HITL_M->Timing.TaskCounters.TID[1]) > 3) {// Sample time: [0.004s, 0.0s] 
    Modular_HITL_M->Timing.TaskCounters.TID[1] = 0;
  }

  (Modular_HITL_M->Timing.TaskCounters.TID[2])++;
  if ((Modular_HITL_M->Timing.TaskCounters.TID[2]) > 499) {// Sample time: [0.5s, 0.0s] 
    Modular_HITL_M->Timing.TaskCounters.TID[2] = 0;
  }
}

// System initialize for atomic system:
void PX4WriteParameterBlock_Init(DW_PX4WriteParameterBlock_Mod_T *localDW)
{
  static const char_T ParameterNameStr[16] = "YAW_DAMPER_GAIN";

  // Start for MATLABSystem: '<S14>/PX4 Write Parameter Block'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true,
    -1000.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Modu_PX4WriteParameterBlock(real32_T rtu_0, DW_PX4WriteParameterBlock_Mod_T
  *localDW)
{
  // MATLABSystem: '<S14>/PX4 Write Parameter Block'
  MW_ParamWrite_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE, &rtu_0);
}

// Termination for atomic system:
void PX4WriteParameterBlock_Term(DW_PX4WriteParameterBlock_Mod_T *localDW)
{
  // Terminate for MATLABSystem: '<S14>/PX4 Write Parameter Block'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/PX4 Write Parameter Block'
}

// System initialize for atomic system:
void Modular_HI_SourceBlock_Init(DW_SourceBlock_Modular_HITL_T *localDW)
{
  // Start for MATLABSystem: '<S16>/SourceBlock'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  localDW->obj.orbMetadataObj = ORB_ID(actuator_armed);
  uORB_read_initialize(localDW->obj.orbMetadataObj, &localDW->obj.eventStructObj);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Modular_HITL_SourceBlock(B_SourceBlock_Modular_HITL_T *localB,
  DW_SourceBlock_Modular_HITL_T *localDW)
{
  // MATLABSystem: '<S16>/SourceBlock'
  localB->SourceBlock_o1 = uORB_read_step(localDW->obj.orbMetadataObj,
    &localDW->obj.eventStructObj, &localB->SourceBlock_o2, false, 1.0);
}

// Termination for atomic system:
void Modular_HI_SourceBlock_Term(DW_SourceBlock_Modular_HITL_T *localDW)
{
  // Terminate for MATLABSystem: '<S16>/SourceBlock'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uORB_read_terminate(&localDW->obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S16>/SourceBlock'
}

static void Modular__PX4Actuators_setupImpl(px4_internal_block_PX4Actuato_T *obj)
{
  int32_T n;
  int32_T n_0;
  obj->ValidServoIdx[0] = true;
  obj->ValidServoIdx[1] = true;
  obj->ValidServoIdx[2] = true;
  obj->ValidServoIdx[3] = true;
  obj->ValidServoIdx[4] = true;
  obj->ValidServoIdx[5] = true;
  obj->ValidServoIdx[6] = true;
  n = 0;
  for (int32_T b_k = 0; b_k < 12; b_k++) {
    // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
    if (obj->ValidMotorIdx[b_k]) {
      n++;
    }
  }

  n_0 = 0;
  for (int32_T b_k = 0; b_k < 8; b_k++) {
    // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
    if (obj->ValidServoIdx[b_k]) {
      n_0++;
    }
  }

  // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
  obj->QSize = static_cast<uint8_T>(n + n_0);
  MW_actuators_init(obj->QSize);
}

// Model step function for TID0
void Modular_HITL_step0(void)          // Sample time: [0.001s, 0.0s]
{
  real_T rtb_Divide;
  real_T rtb_Gain10;
  real_T rtb_Gain2;
  real_T rtb_Merge;
  real_T rtb_NormalizeRudderCommand;
  real_T u0;
  int32_T y;
  uint16_T GainMode_prev;
  boolean_T b_varargout_1;
  boolean_T tmp;

  {                                    // Sample time: [0.001s, 0.0s]
    rate_monotonic_scheduler();
  }

  // MATLABSystem: '<S27>/SourceBlock'
  b_varargout_1 = uORB_read_step(Modular_HITL_DW.obj_e.orbMetadataObj,
    &Modular_HITL_DW.obj_e.eventStructObj, &Modular_HITL_B.r, false, 1.0);

  // Outputs for Enabled SubSystem: '<S27>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S28>/Enable'

  // Start for MATLABSystem: '<S27>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S28>/In1'
    Modular_HITL_B.In1 = Modular_HITL_B.r;
  }

  // End of Outputs for SubSystem: '<S27>/Enabled Subsystem'

  // Chart: '<Root>/Chart' incorporates:
  //   Constant: '<S12>/Constant'
  //   DataTypeConversion: '<S11>/Data Type Conversion1'
  //   DataTypeConversion: '<S12>/Data Type Conversion1'
  //   MATLAB Function: '<S11>/MATLAB Function'

  GainMode_prev = Modular_HITL_DW.GainMode_start;
  Modular_HITL_DW.GainMode_start = Modular_HITL_B.In1.values[7];
  if (Modular_HITL_DW.is_active_c3_Modular_HITL == 0) {
    Modular_HITL_DW.is_active_c3_Modular_HITL = 1U;
    Modular_HITL_DW.is_GainAdjustment = Modular_HITL_IN_ResetGain;
    Modu_PX4WriteParameterBlock(static_cast<real32_T>
      (Modular_HITL_P.Constant_Value_m),
      &Modular_HITL_DW.PX4WriteParameterBlock_d);
  } else if (GainMode_prev != Modular_HITL_DW.GainMode_start) {
    if (Modular_HITL_B.In1.values[7] <= 1300) {
      Modular_HITL_DW.is_GainAdjustment = Modular_HITL_IN_ResetGain;
      Modu_PX4WriteParameterBlock(static_cast<real32_T>
        (Modular_HITL_P.Constant_Value_m),
        &Modular_HITL_DW.PX4WriteParameterBlock_d);
    } else if (Modular_HITL_B.In1.values[7] < 1600) {
      Modular_HITL_DW.is_GainAdjustment = Modular_HITL_IN_GainHold;
    } else {
      Modular_HITL_DW.is_GainAdjustment = Modular_HITL_IN_AdjustGain;

      // MATLAB Function: '<S11>/MATLAB Function' incorporates:
      //   DataTypeConversion: '<S8>/Data Type Conversion'

      if (Modular_HITL_B.In1.values[8] <= 2000) {
        y = Modular_HITL_B.In1.values[8];
      } else {
        y = 2000;
      }

      if (y < 1000) {
        y = 1000;
      }

      Modu_PX4WriteParameterBlock(static_cast<real32_T>((2000.0 -
        static_cast<real_T>(y)) / 1000.0 + 0.1),
        &Modular_HITL_DW.PX4WriteParameterBlock);
    }
  } else {
    switch (Modular_HITL_DW.is_GainAdjustment) {
     case Modular_HITL_IN_AdjustGain:
      // MATLAB Function: '<S11>/MATLAB Function' incorporates:
      //   DataTypeConversion: '<S8>/Data Type Conversion'

      if (Modular_HITL_B.In1.values[8] <= 2000) {
        y = Modular_HITL_B.In1.values[8];
      } else {
        y = 2000;
      }

      if (y < 1000) {
        y = 1000;
      }

      Modu_PX4WriteParameterBlock(static_cast<real32_T>((2000.0 -
        static_cast<real_T>(y)) / 1000.0 + 0.1),
        &Modular_HITL_DW.PX4WriteParameterBlock);
      break;

     case Modular_HITL_IN_GainHold:
      break;

     default:
      // case IN_ResetGain:
      Modu_PX4WriteParameterBlock(static_cast<real32_T>
        (Modular_HITL_P.Constant_Value_m),
        &Modular_HITL_DW.PX4WriteParameterBlock_d);
      break;
    }
  }

  // End of Chart: '<Root>/Chart'
  Modular_HITL_SourceBlock(&Modular_HITL_B.SourceBlock_d,
    &Modular_HITL_DW.SourceBlock_d);

  // Outputs for Enabled SubSystem: '<S29>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S32>/Enable'

  if (Modular_HITL_B.SourceBlock_d.SourceBlock_o1) {
    // SignalConversion generated from: '<S32>/In1' incorporates:
    //   MATLABSystem: '<S29>/SourceBlock'

    Modular_HITL_B.In1_j = Modular_HITL_B.SourceBlock_d.SourceBlock_o2;
  }

  // End of Outputs for SubSystem: '<S29>/Enabled Subsystem'

  // Gain: '<S7>/Gain10' incorporates:
  //   Constant: '<S7>/Constant7'
  //   Sum: '<S7>/Sum8'

  rtb_NormalizeRudderCommand = (static_cast<real_T>(Modular_HITL_B.In1.values[1])
    - Modular_HITL_P.Constant7_Value_i) * Modular_HITL_P.Gain10_Gain_h;

  // Gain: '<S6>/Gain10' incorporates:
  //   Constant: '<S6>/Constant7'
  //   Sum: '<S6>/Sum8'

  rtb_Merge = (static_cast<real_T>(Modular_HITL_B.In1.values[2]) -
               Modular_HITL_P.Constant7_Value_j) * Modular_HITL_P.Gain10_Gain_d;

  // Gain: '<S36>/Gain2' incorporates:
  //   Constant: '<S36>/Constant2'
  //   Sum: '<S36>/Sum3'

  rtb_Gain2 = (static_cast<real_T>(Modular_HITL_B.In1.values[5]) -
               Modular_HITL_P.Constant2_Value) * Modular_HITL_P.Gain2_Gain;

  // Gain: '<S37>/Gain10' incorporates:
  //   Constant: '<S37>/Constant7'
  //   Sum: '<S37>/Sum8'

  rtb_Gain10 = (static_cast<real_T>(Modular_HITL_B.In1.values[3]) -
                Modular_HITL_P.Constant7_Value_d) * Modular_HITL_P.Gain10_Gain_p;

  // RateTransition generated from: '<S5>/Product' incorporates:
  //   RateTransition: '<Root>/Rate Transition3'
  //   RateTransition generated from: '<S26>/Divide'

  b_varargout_1 = Modular_HITL_M->Timing.RateInteraction.TID0_2;
  if (b_varargout_1) {
    // RateTransition generated from: '<S5>/Product'
    Modular_HITL_B.TmpRTBAtProductInport1 =
      Modular_HITL_DW.TmpRTBAtProductInport1_Buffer0;
  }

  // End of RateTransition generated from: '<S5>/Product'

  // RateTransition generated from: '<S5>/Sum2' incorporates:
  //   RateTransition: '<Root>/Rate Transition'
  //   RateTransition: '<Root>/Rate Transition2'

  tmp = Modular_HITL_M->Timing.RateInteraction.TID0_1;
  if (tmp) {
    // RateTransition generated from: '<S5>/Sum2'
    Modular_HITL_B.TmpRTBAtSum2Inport2 =
      Modular_HITL_DW.TmpRTBAtSum2Inport2_Buffer0;
  }

  // End of RateTransition generated from: '<S5>/Sum2'

  // RateTransition generated from: '<S26>/Divide'
  if (b_varargout_1) {
    // RateTransition generated from: '<S26>/Divide'
    Modular_HITL_B.TmpRTBAtDivideInport2 =
      Modular_HITL_DW.TmpRTBAtDivideInport2_Buffer0;

    // RateTransition generated from: '<S26>/Divide'
    Modular_HITL_B.TmpRTBAtDivideInport3 =
      Modular_HITL_DW.TmpRTBAtDivideInport3_Buffer0;
  }

  // Product: '<S26>/Divide' incorporates:
  //   Constant: '<S26>/Constant1'
  //   Gain: '<S26>/Gain1'
  //   Sum: '<S26>/Sum1'

  rtb_Divide = (static_cast<real_T>(Modular_HITL_B.In1.values[3]) -
                Modular_HITL_P.Constant1_Value_o) * Modular_HITL_P.Gain1_Gain *
    Modular_HITL_B.TmpRTBAtDivideInport2 / Modular_HITL_B.TmpRTBAtDivideInport3;
  Modular_HITL_SourceBlock(&Modular_HITL_B.SourceBlock,
    &Modular_HITL_DW.SourceBlock);

  // Outputs for Enabled SubSystem: '<S16>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S19>/Enable'

  if (Modular_HITL_B.SourceBlock.SourceBlock_o1) {
    // SignalConversion generated from: '<S19>/In1' incorporates:
    //   MATLABSystem: '<S16>/SourceBlock'

    Modular_HITL_B.In1_c = Modular_HITL_B.SourceBlock.SourceBlock_o2;
  }

  // End of Outputs for SubSystem: '<S16>/Enabled Subsystem'

  // MATLABSystem: '<Root>/PX4 Actuator Write'
  for (y = 0; y < 12; y++) {
    Modular_HITL_B.motorValues[y] = (rtNaNF);
  }

  for (y = 0; y < 8; y++) {
    Modular_HITL_B.servoValues[y] = (rtNaNF);
  }

  // If: '<S31>/If'
  if (Modular_HITL_B.In1_j.armed) {
    // Gain: '<S30>/Gain10' incorporates:
    //   Constant: '<S30>/Constant7'
    //   Sum: '<S30>/Sum8'

    u0 = (static_cast<real_T>(Modular_HITL_B.In1.values[0]) -
          Modular_HITL_P.Constant7_Value) * Modular_HITL_P.Gain10_Gain;

    // Saturate: '<S30>/Saturation'
    if (u0 > Modular_HITL_P.Saturation_UpperSat) {
      // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
      //   DataTypeConversion: '<Root>/Cast To Boolean5'

      Modular_HITL_B.servoValues[0] = static_cast<real32_T>
        (Modular_HITL_P.Saturation_UpperSat);
    } else if (u0 < Modular_HITL_P.Saturation_LowerSat) {
      // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
      //   DataTypeConversion: '<Root>/Cast To Boolean5'

      Modular_HITL_B.servoValues[0] = static_cast<real32_T>
        (Modular_HITL_P.Saturation_LowerSat);
    } else {
      // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
      //   DataTypeConversion: '<Root>/Cast To Boolean5'

      Modular_HITL_B.servoValues[0] = static_cast<real32_T>(u0);
    }

    // End of Saturate: '<S30>/Saturation'
  } else {
    // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
    //   Constant: '<S9>/Constant1'
    //   DataTypeConversion: '<Root>/Cast To Boolean5'

    Modular_HITL_B.servoValues[0] = static_cast<real32_T>
      (Modular_HITL_P.Constant1_Value);
  }

  // End of If: '<S31>/If'

  // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
  //   DataTypeConversion: '<Root>/Cast To Boolean2'
  //   DataTypeConversion: '<Root>/Cast To Boolean3'
  //   DataTypeConversion: '<Root>/Cast To Boolean4'
  //   Gain: '<Root>/Gain9'

  Modular_HITL_B.servoValues[1] = static_cast<real32_T>
    (Modular_HITL_P.Gain9_Gain * rtb_NormalizeRudderCommand);
  Modular_HITL_B.servoValues[2] = static_cast<real32_T>
    (rtb_NormalizeRudderCommand);
  Modular_HITL_B.servoValues[3] = static_cast<real32_T>(rtb_Merge);
  Modular_HITL_B.servoValues[4] = static_cast<real32_T>(rtb_Merge);

  // If: '<S35>/If'
  if (rtb_Gain2 < 0.4) {
    // Outputs for IfAction SubSystem: '<S35>/If Action Subsystem' incorporates:
    //   ActionPort: '<S38>/Action Port'

    // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Boolean1'
    //   SignalConversion generated from: '<S38>/In1'

    Modular_HITL_B.servoValues[5] = static_cast<real32_T>(rtb_Gain10);

    // End of Outputs for SubSystem: '<S35>/If Action Subsystem'
  } else if (rtb_Gain2 > 0.6) {
    // Gain: '<S10>/Normalize Rudder Command' incorporates:
    //   Product: '<S5>/Product'
    //   Sum: '<S5>/Sum2'

    u0 = (rtb_Divide - Modular_HITL_B.TmpRTBAtSum2Inport2) *
      Modular_HITL_B.TmpRTBAtProductInport1 *
      Modular_HITL_P.NormalizeRudderCommand_Gain;

    // Saturate: '<S10>/Saturation'
    if (u0 > Modular_HITL_P.Saturation_UpperSat_d) {
      // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
      //   DataTypeConversion: '<Root>/Cast To Boolean1'

      Modular_HITL_B.servoValues[5] = static_cast<real32_T>
        (Modular_HITL_P.Saturation_UpperSat_d);
    } else if (u0 < Modular_HITL_P.Saturation_LowerSat_g) {
      // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
      //   DataTypeConversion: '<Root>/Cast To Boolean1'

      Modular_HITL_B.servoValues[5] = static_cast<real32_T>
        (Modular_HITL_P.Saturation_LowerSat_g);
    } else {
      // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
      //   DataTypeConversion: '<Root>/Cast To Boolean1'

      Modular_HITL_B.servoValues[5] = static_cast<real32_T>(u0);
    }

    // End of Saturate: '<S10>/Saturation'
  } else {
    // Outputs for IfAction SubSystem: '<S35>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S40>/Action Port'

    // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Boolean1'
    //   SignalConversion generated from: '<S40>/In1'

    Modular_HITL_B.servoValues[5] = static_cast<real32_T>(rtb_Gain10);

    // End of Outputs for SubSystem: '<S35>/If Action Subsystem2'
  }

  // End of If: '<S35>/If'

  // If: '<S17>/If'
  if (Modular_HITL_B.In1_c.armed) {
    // Gain: '<S18>/Gain10' incorporates:
    //   Constant: '<S18>/Constant7'
    //   Sum: '<S18>/Sum8'

    u0 = (static_cast<real_T>(Modular_HITL_B.In1.values[6]) -
          Modular_HITL_P.Constant7_Value_k) * Modular_HITL_P.Gain10_Gain_d3;

    // Saturate: '<S18>/Saturation'
    if (u0 > Modular_HITL_P.Saturation_UpperSat_g) {
      // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
      //   DataTypeConversion: '<Root>/Cast To Boolean7'

      Modular_HITL_B.servoValues[6] = static_cast<real32_T>
        (Modular_HITL_P.Saturation_UpperSat_g);
    } else if (u0 < Modular_HITL_P.Saturation_LowerSat_i) {
      // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
      //   DataTypeConversion: '<Root>/Cast To Boolean7'

      Modular_HITL_B.servoValues[6] = static_cast<real32_T>
        (Modular_HITL_P.Saturation_LowerSat_i);
    } else {
      // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
      //   DataTypeConversion: '<Root>/Cast To Boolean7'

      Modular_HITL_B.servoValues[6] = static_cast<real32_T>(u0);
    }

    // End of Saturate: '<S18>/Saturation'
  } else {
    // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
    //   Constant: '<S2>/Constant2'
    //   DataTypeConversion: '<Root>/Cast To Boolean7'

    Modular_HITL_B.servoValues[6] = static_cast<real32_T>
      (Modular_HITL_P.Constant2_Value_o);
  }

  // End of If: '<S17>/If'

  // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
  //   Constant: '<Root>/Constant'
  //   DataTypeConversion: '<Root>/Cast To Boolean6'

  MW_actuators_set(Modular_HITL_P.Constant_Value_n != 0.0,
                   &Modular_HITL_B.motorValues[0], &Modular_HITL_B.servoValues[0]);

  // RateTransition: '<Root>/Rate Transition'
  if (tmp) {
    // RateTransition: '<Root>/Rate Transition'
    Modular_HITL_B.RateTransition = Modular_HITL_DW.RateTransition_Buffer0;
  }

  // RateTransition: '<Root>/Rate Transition3'
  if (b_varargout_1) {
    // RateTransition: '<Root>/Rate Transition3'
    Modular_HITL_B.RateTransition3 = Modular_HITL_DW.RateTransition3_Buffer0;
  }

  // BusAssignment: '<S4>/Bus Assignment' incorporates:
  //   MATLABSystem: '<S4>/PX4 Timestamp'

  Modular_HITL_B.BusAssignment.timestamp = hrt_absolute_time();

  // RateTransition: '<Root>/Rate Transition2'
  if (tmp) {
    // RateTransition: '<Root>/Rate Transition2'
    Modular_HITL_B.RateTransition2 = Modular_HITL_DW.RateTransition2_Buffer0;
  }

  // BusAssignment: '<S4>/Bus Assignment' incorporates:
  //   DataTypeConversion: '<Root>/Cast To Single1'
  //   DataTypeConversion: '<Root>/Cast To Single2'

  Modular_HITL_B.BusAssignment.yaw_rate = Modular_HITL_B.RateTransition;
  Modular_HITL_B.BusAssignment.yaw_rate_command = static_cast<real32_T>
    (rtb_Divide);
  Modular_HITL_B.BusAssignment.filtered_yaw_rate = static_cast<real32_T>
    (Modular_HITL_B.RateTransition2);
  Modular_HITL_B.BusAssignment.gain = Modular_HITL_B.RateTransition3;

  // MATLABSystem: '<S25>/SinkBlock' incorporates:
  //   BusAssignment: '<S4>/Bus Assignment'

  uORB_write_step(Modular_HITL_DW.obj_a.orbMetadataObj,
                  &Modular_HITL_DW.obj_a.orbAdvertiseObj,
                  &Modular_HITL_B.BusAssignment);
}

// Model step function for TID1
void Modular_HITL_step1(void)          // Sample time: [0.004s, 0.0s]
{
  real_T WashoutFilter_tmp;
  real_T rtb_WashoutFilter;
  boolean_T b_varargout_1;

  // MATLABSystem: '<S22>/SourceBlock'
  b_varargout_1 = uORB_read_step(Modular_HITL_DW.obj_g.orbMetadataObj,
    &Modular_HITL_DW.obj_g.eventStructObj, &Modular_HITL_B.r1, false, 1.0);

  // Outputs for Enabled SubSystem: '<S22>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S23>/Enable'

  // Start for MATLABSystem: '<S22>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S23>/In1'
    Modular_HITL_B.In1_k = Modular_HITL_B.r1;
  }

  // End of Outputs for SubSystem: '<S22>/Enabled Subsystem'

  // RateTransition: '<Root>/Rate Transition'
  Modular_HITL_DW.RateTransition_Buffer0 = Modular_HITL_B.In1_k.z;

  // DiscreteTransferFcn: '<S5>/Washout Filter' incorporates:
  //   Gain: '<S5>/Gain6'

  WashoutFilter_tmp = (static_cast<real_T>(Modular_HITL_P.Gain6_Gain) *
                       Modular_HITL_B.In1_k.z -
                       Modular_HITL_P.WashoutFilter_DenCoef[1] *
                       Modular_HITL_DW.WashoutFilter_states) /
    Modular_HITL_P.WashoutFilter_DenCoef[0];
  rtb_WashoutFilter = Modular_HITL_P.WashoutFilter_NumCoef[0] *
    WashoutFilter_tmp + Modular_HITL_P.WashoutFilter_NumCoef[1] *
    Modular_HITL_DW.WashoutFilter_states;

  // RateTransition: '<Root>/Rate Transition2'
  Modular_HITL_DW.RateTransition2_Buffer0 = rtb_WashoutFilter;

  // RateTransition generated from: '<S5>/Sum2'
  Modular_HITL_DW.TmpRTBAtSum2Inport2_Buffer0 = rtb_WashoutFilter;

  // Update for DiscreteTransferFcn: '<S5>/Washout Filter'
  Modular_HITL_DW.WashoutFilter_states = WashoutFilter_tmp;
}

// Model step function for TID2
void Modular_HITL_step2(void)          // Sample time: [0.5s, 0.0s]
{
  real32_T rtb_ReadParameter1_o1;
  real32_T rtb_ReadParameter_o1;
  boolean_T b_varargout_2;

  // MATLABSystem: '<Root>/Read Parameter'
  b_varargout_2 = MW_ParamRead_Step(Modular_HITL_DW.obj_d0.MW_PARAMHANDLE,
    MW_SINGLE, &rtb_ReadParameter_o1);
  if (b_varargout_2) {
    rtb_ReadParameter_o1 = 0.0F;
  }

  // End of MATLABSystem: '<Root>/Read Parameter'

  // RateTransition: '<Root>/Rate Transition3'
  Modular_HITL_DW.RateTransition3_Buffer0 = rtb_ReadParameter_o1;

  // RateTransition generated from: '<S26>/Divide'
  Modular_HITL_DW.TmpRTBAtDivideInport3_Buffer0 = rtb_ReadParameter_o1;

  // RateTransition generated from: '<S5>/Product'
  Modular_HITL_DW.TmpRTBAtProductInport1_Buffer0 = rtb_ReadParameter_o1;

  // MATLABSystem: '<S26>/Read Parameter1'
  b_varargout_2 = MW_ParamRead_Step(Modular_HITL_DW.obj_k.MW_PARAMHANDLE,
    MW_SINGLE, &rtb_ReadParameter1_o1);
  if (b_varargout_2) {
    rtb_ReadParameter1_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S26>/Read Parameter1'

  // RateTransition generated from: '<S26>/Divide'
  Modular_HITL_DW.TmpRTBAtDivideInport2_Buffer0 = rtb_ReadParameter1_o1;
}

// Use this function only if you need to maintain compatibility with an existing static main program.
void Modular_HITL_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Modular_HITL_step0();
    break;

   case 1 :
    Modular_HITL_step1();
    break;

   case 2 :
    Modular_HITL_step2();
    break;

   default :
    // do nothing
    break;
  }
}

// Model initialize function
void Modular_HITL_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    static const char_T ParameterNameStr[16] = "YAW_DAMPER_GAIN";
    static const char_T ParameterNameStr_0[13] = "YAW_RATE_MAX";
    int32_T i;

    // Start for RateTransition generated from: '<S5>/Product'
    Modular_HITL_B.TmpRTBAtProductInport1 =
      Modular_HITL_P.TmpRTBAtProductInport1_InitialC;

    // Start for RateTransition generated from: '<S5>/Sum2'
    Modular_HITL_B.TmpRTBAtSum2Inport2 =
      Modular_HITL_P.TmpRTBAtSum2Inport2_InitialCond;

    // Start for RateTransition generated from: '<S26>/Divide'
    Modular_HITL_B.TmpRTBAtDivideInport2 =
      Modular_HITL_P.TmpRTBAtDivideInport2_InitialCo;

    // Start for RateTransition generated from: '<S26>/Divide'
    Modular_HITL_B.TmpRTBAtDivideInport3 =
      Modular_HITL_P.TmpRTBAtDivideInport3_InitialCo;

    // Start for RateTransition: '<Root>/Rate Transition'
    Modular_HITL_B.RateTransition =
      Modular_HITL_P.RateTransition_InitialCondition;

    // Start for RateTransition: '<Root>/Rate Transition3'
    Modular_HITL_B.RateTransition3 =
      Modular_HITL_P.RateTransition3_InitialConditio;

    // Start for RateTransition: '<Root>/Rate Transition2'
    Modular_HITL_B.RateTransition2 =
      Modular_HITL_P.RateTransition2_InitialConditio;

    // InitializeConditions for RateTransition generated from: '<S5>/Product'
    Modular_HITL_DW.TmpRTBAtProductInport1_Buffer0 =
      Modular_HITL_P.TmpRTBAtProductInport1_InitialC;

    // InitializeConditions for RateTransition generated from: '<S5>/Sum2'
    Modular_HITL_DW.TmpRTBAtSum2Inport2_Buffer0 =
      Modular_HITL_P.TmpRTBAtSum2Inport2_InitialCond;

    // InitializeConditions for RateTransition generated from: '<S26>/Divide'
    Modular_HITL_DW.TmpRTBAtDivideInport2_Buffer0 =
      Modular_HITL_P.TmpRTBAtDivideInport2_InitialCo;

    // InitializeConditions for RateTransition generated from: '<S26>/Divide'
    Modular_HITL_DW.TmpRTBAtDivideInport3_Buffer0 =
      Modular_HITL_P.TmpRTBAtDivideInport3_InitialCo;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition'
    Modular_HITL_DW.RateTransition_Buffer0 =
      Modular_HITL_P.RateTransition_InitialCondition;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition3'
    Modular_HITL_DW.RateTransition3_Buffer0 =
      Modular_HITL_P.RateTransition3_InitialConditio;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition2'
    Modular_HITL_DW.RateTransition2_Buffer0 =
      Modular_HITL_P.RateTransition2_InitialConditio;

    // InitializeConditions for DiscreteTransferFcn: '<S5>/Washout Filter'
    Modular_HITL_DW.WashoutFilter_states =
      Modular_HITL_P.WashoutFilter_InitialStates;

    // SystemInitialize for IfAction SubSystem: '<S1>/GainAdjustment.AdjustGain' 
    // SystemInitialize for Chart: '<Root>/Chart'
    PX4WriteParameterBlock_Init(&Modular_HITL_DW.PX4WriteParameterBlock);

    // End of SystemInitialize for SubSystem: '<S1>/GainAdjustment.AdjustGain'

    // SystemInitialize for IfAction SubSystem: '<S1>/GainAdjustment.ResetGain'
    PX4WriteParameterBlock_Init(&Modular_HITL_DW.PX4WriteParameterBlock_d);

    // End of SystemInitialize for SubSystem: '<S1>/GainAdjustment.ResetGain'

    // SystemInitialize for Enabled SubSystem: '<S16>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S19>/In1' incorporates:
    //   Outport: '<S19>/Out1'

    Modular_HITL_B.In1_c = Modular_HITL_P.Out1_Y0_b;

    // End of SystemInitialize for SubSystem: '<S16>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S22>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S23>/In1' incorporates:
    //   Outport: '<S23>/Out1'

    Modular_HITL_B.In1_k = Modular_HITL_P.Out1_Y0_m;

    // End of SystemInitialize for SubSystem: '<S22>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S27>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S28>/In1' incorporates:
    //   Outport: '<S28>/Out1'

    Modular_HITL_B.In1 = Modular_HITL_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S27>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S29>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S32>/In1' incorporates:
    //   Outport: '<S32>/Out1'

    Modular_HITL_B.In1_j = Modular_HITL_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S29>/Enabled Subsystem'

    // Start for MATLABSystem: '<S27>/SourceBlock'
    Modular_HITL_DW.obj_e.matlabCodegenIsDeleted = false;
    Modular_HITL_DW.obj_e.isSetupComplete = false;
    Modular_HITL_DW.obj_e.isInitialized = 1;
    Modular_HITL_DW.obj_e.orbMetadataObj = ORB_ID(input_rc);
    uORB_read_initialize(Modular_HITL_DW.obj_e.orbMetadataObj,
                         &Modular_HITL_DW.obj_e.eventStructObj);
    Modular_HITL_DW.obj_e.isSetupComplete = true;
    Modular_HI_SourceBlock_Init(&Modular_HITL_DW.SourceBlock_d);
    Modular_HI_SourceBlock_Init(&Modular_HITL_DW.SourceBlock);

    // Start for MATLABSystem: '<Root>/PX4 Actuator Write'
    for (i = 0; i < 12; i++) {
      Modular_HITL_DW.obj.ValidMotorIdx[i] = false;
    }

    for (i = 0; i < 8; i++) {
      Modular_HITL_DW.obj.ValidServoIdx[i] = false;
    }

    Modular_HITL_DW.obj.matlabCodegenIsDeleted = false;
    Modular_HITL_DW.obj.isSetupComplete = false;
    Modular_HITL_DW.obj.isInitialized = 1;
    Modular__PX4Actuators_setupImpl(&Modular_HITL_DW.obj);
    Modular_HITL_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/PX4 Actuator Write'

    // Start for MATLABSystem: '<S4>/PX4 Timestamp'
    Modular_HITL_DW.obj_d.matlabCodegenIsDeleted = false;
    Modular_HITL_DW.obj_d.isInitialized = 1;
    Modular_HITL_DW.obj_d.isSetupComplete = true;

    // Start for MATLABSystem: '<S25>/SinkBlock' incorporates:
    //   BusAssignment: '<S4>/Bus Assignment'

    Modular_HITL_DW.obj_a.matlabCodegenIsDeleted = false;
    Modular_HITL_DW.obj_a.isSetupComplete = false;
    Modular_HITL_DW.obj_a.isInitialized = 1;
    Modular_HITL_DW.obj_a.orbMetadataObj = ORB_ID(yaw_damper_info);
    uORB_write_initialize(Modular_HITL_DW.obj_a.orbMetadataObj,
                          &Modular_HITL_DW.obj_a.orbAdvertiseObj,
                          &Modular_HITL_B.BusAssignment, 1);
    Modular_HITL_DW.obj_a.isSetupComplete = true;

    // Start for MATLABSystem: '<S22>/SourceBlock'
    Modular_HITL_DW.obj_g.matlabCodegenIsDeleted = false;
    Modular_HITL_DW.obj_g.isSetupComplete = false;
    Modular_HITL_DW.obj_g.isInitialized = 1;
    Modular_HITL_DW.obj_g.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(Modular_HITL_DW.obj_g.orbMetadataObj,
                         &Modular_HITL_DW.obj_g.eventStructObj);
    Modular_HITL_DW.obj_g.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Read Parameter'
    Modular_HITL_DW.obj_d0.matlabCodegenIsDeleted = false;
    Modular_HITL_DW.obj_d0.isInitialized = 1;
    Modular_HITL_DW.obj_d0.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0],
      true, 500.0);
    Modular_HITL_DW.obj_d0.isSetupComplete = true;

    // Start for MATLABSystem: '<S26>/Read Parameter1'
    Modular_HITL_DW.obj_k.matlabCodegenIsDeleted = false;
    Modular_HITL_DW.obj_k.isInitialized = 1;
    Modular_HITL_DW.obj_k.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_0[0],
      true, 500.0);
    Modular_HITL_DW.obj_k.isSetupComplete = true;
  }
}

// Model terminate function
void Modular_HITL_terminate(void)
{
  int32_T i;
  real32_T servoValues[8];

  // Terminate for MATLABSystem: '<S27>/SourceBlock'
  if (!Modular_HITL_DW.obj_e.matlabCodegenIsDeleted) {
    Modular_HITL_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Modular_HITL_DW.obj_e.isInitialized == 1) &&
        Modular_HITL_DW.obj_e.isSetupComplete) {
      uORB_read_terminate(&Modular_HITL_DW.obj_e.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S27>/SourceBlock'

  // Terminate for IfAction SubSystem: '<S1>/GainAdjustment.AdjustGain'
  // Terminate for Chart: '<Root>/Chart'
  PX4WriteParameterBlock_Term(&Modular_HITL_DW.PX4WriteParameterBlock);

  // End of Terminate for SubSystem: '<S1>/GainAdjustment.AdjustGain'

  // Terminate for IfAction SubSystem: '<S1>/GainAdjustment.ResetGain'
  PX4WriteParameterBlock_Term(&Modular_HITL_DW.PX4WriteParameterBlock_d);

  // End of Terminate for SubSystem: '<S1>/GainAdjustment.ResetGain'
  Modular_HI_SourceBlock_Term(&Modular_HITL_DW.SourceBlock_d);
  Modular_HI_SourceBlock_Term(&Modular_HITL_DW.SourceBlock);

  // Terminate for MATLABSystem: '<Root>/PX4 Actuator Write'
  if (!Modular_HITL_DW.obj.matlabCodegenIsDeleted) {
    Modular_HITL_DW.obj.matlabCodegenIsDeleted = true;
    if ((Modular_HITL_DW.obj.isInitialized == 1) &&
        Modular_HITL_DW.obj.isSetupComplete) {
      for (i = 0; i < 12; i++) {
        Modular_HITL_B.motorValues_m[i] = (rtNaNF);
      }

      for (i = 0; i < 8; i++) {
        servoValues[i] = (rtNaNF);
      }

      for (i = 0; i < 12; i++) {
        if (Modular_HITL_DW.obj.ValidMotorIdx[i]) {
          Modular_HITL_B.motorValues_m[i] = 0.0F;
        }
      }

      for (i = 0; i < 8; i++) {
        if (Modular_HITL_DW.obj.ValidServoIdx[i]) {
          servoValues[i] = 0.0F;
        }
      }

      MW_actuators_set(false, &Modular_HITL_B.motorValues_m[0], &servoValues[0]);
      MW_actuators_terminate();
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 Actuator Write'

  // Terminate for MATLABSystem: '<S4>/PX4 Timestamp'
  if (!Modular_HITL_DW.obj_d.matlabCodegenIsDeleted) {
    Modular_HITL_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/PX4 Timestamp'

  // Terminate for MATLABSystem: '<S25>/SinkBlock'
  if (!Modular_HITL_DW.obj_a.matlabCodegenIsDeleted) {
    Modular_HITL_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Modular_HITL_DW.obj_a.isInitialized == 1) &&
        Modular_HITL_DW.obj_a.isSetupComplete) {
      uORB_write_terminate(&Modular_HITL_DW.obj_a.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S25>/SinkBlock'

  // Terminate for MATLABSystem: '<S22>/SourceBlock'
  if (!Modular_HITL_DW.obj_g.matlabCodegenIsDeleted) {
    Modular_HITL_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((Modular_HITL_DW.obj_g.isInitialized == 1) &&
        Modular_HITL_DW.obj_g.isSetupComplete) {
      uORB_read_terminate(&Modular_HITL_DW.obj_g.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S22>/SourceBlock'

  // Terminate for MATLABSystem: '<Root>/Read Parameter'
  if (!Modular_HITL_DW.obj_d0.matlabCodegenIsDeleted) {
    Modular_HITL_DW.obj_d0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Read Parameter'

  // Terminate for MATLABSystem: '<S26>/Read Parameter1'
  if (!Modular_HITL_DW.obj_k.matlabCodegenIsDeleted) {
    Modular_HITL_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S26>/Read Parameter1'
}

uint16_T &RT_MODEL_Modular_HITL_T::TaskCounter(int32_T idx)
{
  return (Timing.TaskCounters.TID[(idx)]);
}

boolean_T RT_MODEL_Modular_HITL_T::StepTask(int32_T idx) const
{
  return (Timing.TaskCounters.TID[(idx)] == 0);
}

const char_T* RT_MODEL_Modular_HITL_T::getErrorStatus() const
{
  return (errorStatus);
}

void RT_MODEL_Modular_HITL_T::setErrorStatus(const char_T* const volatile
  aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
