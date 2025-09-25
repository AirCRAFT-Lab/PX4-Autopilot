//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Hummingbird_Flight_Controller_Lower_Memory.cpp
//
// Code generated for Simulink model 'Hummingbird_Flight_Controller_Lower_Memory'.
//
// Model version                  : 2.189
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Thu Sep 25 09:50:43 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Hummingbird_Flight_Controller_Lower_Memory.h"
#include "Hummingbird_Flight_Controller_Lower_Memory_types.h"
#include "rtwtypes.h"
#include <uORB/topics/attitude_command.h>
#include <uORB/topics/rate_command.h>
#include <uORB/topics/rate_command_error.h>
#include "Hummingbird_Flight_Controller_Lower_Memory_private.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>
#include "rt_defines.h"
#include <float.h>

// Named constants for Chart: '<Root>/Chart'
const uint8_T Hummingbir_IN_Set_mission_start = 6U;
const uint8_T Hummingbird_Fli_IN_FW_Stabilize = 2U;
const uint8_T Hummingbird_Flig_IN_MR_Attitude = 3U;
const uint8_T Hummingbird_Flight_C_IN_FW_Nav1 = 1U;
const uint8_T Hummingbird_Flight_C_IN_MR_Vel1 = 5U;
const uint8_T Hummingbird_Flight_Co_IN_MR_Nav = 4U;
const uint8_T Hummingbird__IN_NO_ACTIVE_CHILD = 0U;

// Named constants for Chart: '<S1458>/Chart'
const uint8_T Hummingbird_Flight_Con_IN_Mixed = 3U;
const uint8_T Hummingbird_Flight_Contro_IN_FW = 1U;
const uint8_T Hummingbird_Flight_Contro_IN_MR = 2U;

// Named constants for Chart: '<Root>/Chart1'
const uint8_T Hummingbird_Fligh_IN_Controlled = 1U;
const uint8_T Hummingbird_Flight_Con_IN_Start = 3U;
const uint8_T Hummingbird_Flight_IN_FW_Manual = 2U;

// Block signals (default storage)
B_Hummingbird_Flight_Controll_T Hummingbird_Flight_Controller_B;

// Block states (default storage)
DW_Hummingbird_Flight_Control_T Hummingbird_Flight_Controlle_DW;

// Real-time model
RT_MODEL_Hummingbird_Flight_C_T Hummingbird_Flight_Controlle_M_ =
  RT_MODEL_Hummingbird_Flight_C_T();
RT_MODEL_Hummingbird_Flight_C_T *const Hummingbird_Flight_Controlle_M =
  &Hummingbird_Flight_Controlle_M_;

// Forward declaration for local functions
static real_T Hummingbird_Fligh_rt_atan2d_snf(real_T u0, real_T u1);
static real32_T Hummingbird_Fligh_rt_atan2f_snf(real32_T u0, real32_T u1);
static real_T Hummingbird_Flight__rt_remd_snf(real_T u0, real_T u1);
static void Hummingbird_Flight_Control_cosd(real_T *x);
static void Hummingbird_Flight_Control_sind(real_T *x);
static void Hummingbird_Flight_Con_lla2ecef(const real_T llaPos[3], real_T
  ecefPos[3]);
static void Hummingbird_Flight_Cont_lla2ned(const real_T lla[3], const real_T
  lla0[3], real_T xyzNED[3]);
static real_T Hummingbird_Flight_Control_norm(const real_T x[3]);
static real_T Hummingbird_Flight_Con_xzlangeM(const real_T x[9]);
static void Hummingbird_Flight_Cont_xzlascl(real_T cfrom, real_T cto, int32_T m,
  int32_T n, real_T A[9], int32_T iA0, int32_T lda);
static real_T Hummingbird_Flight_Contro_xnrm2(int32_T n, const real_T x[9],
  int32_T ix0);
static real_T Hummingbird_Flight_Contro_xdotc(int32_T n, const real_T x[9],
  int32_T ix0, const real_T y[9], int32_T iy0);
static void Hummingbird_Flight_Contro_xaxpy(int32_T n, real_T a, int32_T ix0,
  real_T y[9], int32_T iy0);
static real_T Hummingbird_Flight_Cont_xnrm2_b(int32_T n, const real_T x[3],
  int32_T ix0);
static void Hummingbird_Flight_Cont_xaxpy_l(int32_T n, real_T a, const real_T x
  [9], int32_T ix0, real_T y[3], int32_T iy0);
static void Hummingbird_Flight_Con_xaxpy_lx(int32_T n, real_T a, const real_T x
  [3], int32_T ix0, real_T y[9], int32_T iy0);
static void Hummingbird_Flight_Co_xzlascl_o(real_T cfrom, real_T cto, int32_T m,
  int32_T n, real_T A[3], int32_T iA0, int32_T lda);
static void Hummingbird_Flight_Contro_xrotg(real_T *a, real_T *b, real_T *c,
  real_T *s);
static void Hummingbird_Flight_Controll_svd(const real_T A[9], real_T U[3]);
static void Hummingbird_Flight_Co_lla2ned_f(const real_T lla[3], const real_T
  lla0[3], real_T xyzNED[3]);
static real_T Hummingbird_Flight_Contr_norm_j(const real_T x[2]);
static void exit_internal_Flight_controller(void);
static void Hummingb_PX4Actuators_setupImpl(px4_internal_block_PX4Actuato_T *obj);
static void rate_monotonic_scheduler(void);

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to remember which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void Hummingbird_Flight_Controller_Lower_Memory_SetEventsForThisBaseStep
  (boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)Hummingbird_Flight_Controlle_M->StepTask(1));
  eventFlags[2] = ((boolean_T)Hummingbird_Flight_Controlle_M->StepTask(2));
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
  Hummingbird_Flight_Controlle_M->Timing.RateInteraction.TID0_1 =
    (Hummingbird_Flight_Controlle_M->Timing.TaskCounters.TID[1] == 0);
  Hummingbird_Flight_Controlle_M->Timing.RateInteraction.TID0_2 =
    (Hummingbird_Flight_Controlle_M->Timing.TaskCounters.TID[2] == 0);

  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (Hummingbird_Flight_Controlle_M->Timing.TaskCounters.TID[1])++;
  if ((Hummingbird_Flight_Controlle_M->Timing.TaskCounters.TID[1]) > 3) {// Sample time: [0.004s, 0.0s] 
    Hummingbird_Flight_Controlle_M->Timing.TaskCounters.TID[1] = 0;
  }

  (Hummingbird_Flight_Controlle_M->Timing.TaskCounters.TID[2])++;
  if ((Hummingbird_Flight_Controlle_M->Timing.TaskCounters.TID[2]) > 499) {// Sample time: [0.5s, 0.0s] 
    Hummingbird_Flight_Controlle_M->Timing.TaskCounters.TID[2] = 0;
  }
}

//
// System initialize for atomic system:
//
//
//
//
//
//
//
//
//
//
//    ...
//
void Hummingbi_PX4Timestamp_Init(DW_PX4Timestamp_Hummingbird_F_T *localDW)
{
  // Start for MATLABSystem: '<S17>/PX4 Timestamp'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

//
// Output and update for atomic system:
//
//
//
//
//
//
//
//
//
//
//    ...
//
void Hummingbird_Fl_PX4Timestamp(B_PX4Timestamp_Hummingbird_Fl_T *localB)
{
  // MATLABSystem: '<S17>/PX4 Timestamp'
  localB->PX4Timestamp = hrt_absolute_time();
}

//
// Termination for atomic system:
//
//
//
//
//
//
//
//
//
//
//    ...
//
void Hummingbi_PX4Timestamp_Term(DW_PX4Timestamp_Hummingbird_F_T *localDW)
{
  // Terminate for MATLABSystem: '<S17>/PX4 Timestamp'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S17>/PX4 Timestamp'
}

// System initialize for atomic system:
void Humming_ReadParameter3_Init(DW_ReadParameter3_Hummingbird_T *localDW)
{
  static const char_T ParameterNameStr[9] = "B_I_GAIN";

  // Start for MATLABSystem: '<S27>/Read Parameter3'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummingbird__ReadParameter3(B_ReadParameter3_Hummingbird__T *localB,
  DW_ReadParameter3_Hummingbird_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S27>/Read Parameter3'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter3_o1);
  if (b_varargout_2) {
    localB->ReadParameter3_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S27>/Read Parameter3'
}

// Termination for atomic system:
void Humming_ReadParameter3_Term(DW_ReadParameter3_Hummingbird_T *localDW)
{
  // Terminate for MATLABSystem: '<S27>/Read Parameter3'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S27>/Read Parameter3'
}

//
// Output and update for atomic system:
//    '<S12>/MATLAB Function'
//    '<S367>/MATLAB Function'
//
void Hummingbird__MATLABFunction(const xyz_bus *rtu_euler_angles, const real_T
  rtu_world_rates[2], real_T rtu_world_rates_h, real_T rty_body_rates[3],
  B_MATLABFunction_Hummingbird__T *localB)
{
  real_T rtu_world_rates_0[3];
  real_T rty_body_rates_0;
  real_T rty_body_rates_1;
  real_T rty_body_rates_2;
  localB->dv[0] = 1.0;
  localB->dv[3] = 0.0;
  localB->dv[6] = -sin(rtu_euler_angles->Y);
  localB->dv[1] = 0.0;
  localB->dv[4] = cos(rtu_euler_angles->X);
  localB->dv[7] = cos(rtu_euler_angles->Y) * sin(rtu_euler_angles->X);
  localB->dv[2] = 0.0;
  localB->dv[5] = -sin(rtu_euler_angles->X);
  localB->dv[8] = cos(rtu_euler_angles->Y) * cos(rtu_euler_angles->X);

  // SignalConversion generated from: '<S190>/ SFunction '
  rtu_world_rates_0[0] = rtu_world_rates[0];
  rtu_world_rates_0[1] = rtu_world_rates[1];
  rtu_world_rates_0[2] = rtu_world_rates_h;
  rty_body_rates[0] = 0.0;
  rty_body_rates[1] = 0.0;
  rty_body_rates[2] = 0.0;
  rty_body_rates_0 = rty_body_rates[0];
  rty_body_rates_1 = rty_body_rates[1];
  rty_body_rates_2 = rty_body_rates[2];
  for (int32_T i = 0; i < 3; i++) {
    real_T tmp;
    tmp = rtu_world_rates_0[i];
    rty_body_rates_0 += localB->dv[3 * i] * tmp;
    rty_body_rates_1 += localB->dv[3 * i + 1] * tmp;
    rty_body_rates_2 += localB->dv[3 * i + 2] * tmp;
  }

  rty_body_rates[2] = rty_body_rates_2;
  rty_body_rates[1] = rty_body_rates_1;
  rty_body_rates[0] = rty_body_rates_0;
}

// System initialize for atomic system:
void Hummingbird__SinkBlock_Init(const px4_Bus_attitude_command *rtu_0,
  DW_SinkBlock_Hummingbird_Flig_T *localDW)
{
  // Start for MATLABSystem: '<S362>/SinkBlock'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  localDW->obj.orbMetadataObj = ORB_ID(attitude_command);
  uORB_write_initialize(localDW->obj.orbMetadataObj,
                        &localDW->obj.orbAdvertiseObj, rtu_0, 1);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummingbird_Fligh_SinkBlock(const px4_Bus_attitude_command *rtu_0,
  DW_SinkBlock_Hummingbird_Flig_T *localDW)
{
  // MATLABSystem: '<S362>/SinkBlock'
  uORB_write_step(localDW->obj.orbMetadataObj, &localDW->obj.orbAdvertiseObj,
                  rtu_0);
}

// Termination for atomic system:
void Hummingbird__SinkBlock_Term(DW_SinkBlock_Hummingbird_Flig_T *localDW)
{
  // Terminate for MATLABSystem: '<S362>/SinkBlock'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uORB_write_terminate(&localDW->obj.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S362>/SinkBlock'
}

// System initialize for atomic system:
void Hummingbir_SinkBlock_b_Init(const px4_Bus_rate_command *rtu_0,
  DW_SinkBlock_Hummingbird_Fl_h_T *localDW)
{
  // Start for MATLABSystem: '<S364>/SinkBlock'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  localDW->obj.orbMetadataObj = ORB_ID(rate_command);
  uORB_write_initialize(localDW->obj.orbMetadataObj,
                        &localDW->obj.orbAdvertiseObj, rtu_0, 1);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummingbird_Fli_SinkBlock_h(const px4_Bus_rate_command *rtu_0,
  DW_SinkBlock_Hummingbird_Fl_h_T *localDW)
{
  // MATLABSystem: '<S364>/SinkBlock'
  uORB_write_step(localDW->obj.orbMetadataObj, &localDW->obj.orbAdvertiseObj,
                  rtu_0);
}

// Termination for atomic system:
void Hummingbir_SinkBlock_i_Term(DW_SinkBlock_Hummingbird_Fl_h_T *localDW)
{
  // Terminate for MATLABSystem: '<S364>/SinkBlock'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uORB_write_terminate(&localDW->obj.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S364>/SinkBlock'
}

// System initialize for atomic system:
void Hummingbir_SinkBlock_a_Init(const px4_Bus_rate_command_error *rtu_0,
  DW_SinkBlock_Hummingbird_Fl_a_T *localDW)
{
  // Start for MATLABSystem: '<S366>/SinkBlock'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  localDW->obj.orbMetadataObj = ORB_ID(rate_command_error);
  uORB_write_initialize(localDW->obj.orbMetadataObj,
                        &localDW->obj.orbAdvertiseObj, rtu_0, 1);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummingbird_Fli_SinkBlock_j(const px4_Bus_rate_command_error *rtu_0,
  DW_SinkBlock_Hummingbird_Fl_a_T *localDW)
{
  // MATLABSystem: '<S366>/SinkBlock'
  uORB_write_step(localDW->obj.orbMetadataObj, &localDW->obj.orbAdvertiseObj,
                  rtu_0);
}

// Termination for atomic system:
void Hummingbir_SinkBlock_f_Term(DW_SinkBlock_Hummingbird_Fl_a_T *localDW)
{
  // Terminate for MATLABSystem: '<S366>/SinkBlock'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uORB_write_terminate(&localDW->obj.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S366>/SinkBlock'
}

// System initialize for atomic system:
void Hummingb_ReadParameter_Init(DW_ReadParameter_Hummingbird__T *localDW)
{
  static const char_T ParameterNameStr[16] = "FW_PITCH_P_GAIN";

  // Start for MATLABSystem: '<S197>/Read Parameter'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummingbird_F_ReadParameter(B_ReadParameter_Hummingbird_F_T *localB,
  DW_ReadParameter_Hummingbird__T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S197>/Read Parameter'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter_o1);
  if (b_varargout_2) {
    localB->ReadParameter_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S197>/Read Parameter'
}

// Termination for atomic system:
void Hummingb_ReadParameter_Term(DW_ReadParameter_Hummingbird__T *localDW)
{
  // Terminate for MATLABSystem: '<S197>/Read Parameter'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S197>/Read Parameter'
}

// System initialize for atomic system:
void Humming_ReadParameter1_Init(DW_ReadParameter1_Hummingbird_T *localDW)
{
  static const char_T ParameterNameStr[15] = "FW_ROLL_P_GAIN";

  // Start for MATLABSystem: '<S197>/Read Parameter1'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummingbird__ReadParameter1(B_ReadParameter1_Hummingbird__T *localB,
  DW_ReadParameter1_Hummingbird_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S197>/Read Parameter1'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter1_o1);
  if (b_varargout_2) {
    localB->ReadParameter1_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S197>/Read Parameter1'
}

// Termination for atomic system:
void Humming_ReadParameter1_Term(DW_ReadParameter1_Hummingbird_T *localDW)
{
  // Terminate for MATLABSystem: '<S197>/Read Parameter1'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S197>/Read Parameter1'
}

// System initialize for atomic system:
void Hummin_ReadParameter_c_Init(DW_ReadParameter_Hummingbir_d_T *localDW)
{
  static const char_T ParameterNameStr[16] = "FW_PITCH_D_GAIN";

  // Start for MATLABSystem: '<S201>/Read Parameter'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummingbird_ReadParameter_b(B_ReadParameter_Hummingbird_j_T *localB,
  DW_ReadParameter_Hummingbir_d_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S201>/Read Parameter'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter_o1);
  if (b_varargout_2) {
    localB->ReadParameter_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S201>/Read Parameter'
}

// Termination for atomic system:
void Hummin_ReadParameter_o_Term(DW_ReadParameter_Hummingbir_d_T *localDW)
{
  // Terminate for MATLABSystem: '<S201>/Read Parameter'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S201>/Read Parameter'
}

// System initialize for atomic system:
void Hummi_ReadParameter1_l_Init(DW_ReadParameter1_Hummingbi_d_T *localDW)
{
  static const char_T ParameterNameStr[15] = "FW_ROLL_D_GAIN";

  // Start for MATLABSystem: '<S201>/Read Parameter1'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummingbir_ReadParameter1_b(B_ReadParameter1_Hummingbir_j_T *localB,
  DW_ReadParameter1_Hummingbi_d_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S201>/Read Parameter1'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter1_o1);
  if (b_varargout_2) {
    localB->ReadParameter1_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S201>/Read Parameter1'
}

// Termination for atomic system:
void Hummi_ReadParameter1_c_Term(DW_ReadParameter1_Hummingbi_d_T *localDW)
{
  // Terminate for MATLABSystem: '<S201>/Read Parameter1'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S201>/Read Parameter1'
}

// System initialize for atomic system:
void Hummin_ReadParameter_l_Init(DW_ReadParameter_Hummingbi_d5_T *localDW)
{
  static const char_T ParameterNameStr[17] = "FW_PITCH_RP_GAIN";

  // Start for MATLABSystem: '<S202>/Read Parameter'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummingbir_ReadParameter_b3(B_ReadParameter_Hummingbir_jt_T *localB,
  DW_ReadParameter_Hummingbi_d5_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S202>/Read Parameter'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter_o1);
  if (b_varargout_2) {
    localB->ReadParameter_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S202>/Read Parameter'
}

// Termination for atomic system:
void Hummin_ReadParameter_c_Term(DW_ReadParameter_Hummingbi_d5_T *localDW)
{
  // Terminate for MATLABSystem: '<S202>/Read Parameter'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S202>/Read Parameter'
}

// System initialize for atomic system:
void Hummi_ReadParameter1_c_Init(DW_ReadParameter1_Hummingb_d5_T *localDW)
{
  static const char_T ParameterNameStr[17] = "FW_ROLL_R_P_GAIN";

  // Start for MATLABSystem: '<S202>/Read Parameter1'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummingbi_ReadParameter1_b3(B_ReadParameter1_Hummingbi_jt_T *localB,
  DW_ReadParameter1_Hummingb_d5_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S202>/Read Parameter1'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter1_o1);
  if (b_varargout_2) {
    localB->ReadParameter1_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S202>/Read Parameter1'
}

// Termination for atomic system:
void Hummi_ReadParameter1_g_Term(DW_ReadParameter1_Hummingb_d5_T *localDW)
{
  // Terminate for MATLABSystem: '<S202>/Read Parameter1'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S202>/Read Parameter1'
}

// System initialize for atomic system:
void Humming_ReadParameter2_Init(DW_ReadParameter2_Hummingbird_T *localDW)
{
  static const char_T ParameterNameStr[16] = "FW_YAW_R_P_GAIN";

  // Start for MATLABSystem: '<S202>/Read Parameter2'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummingbird__ReadParameter2(B_ReadParameter2_Hummingbird__T *localB,
  DW_ReadParameter2_Hummingbird_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S202>/Read Parameter2'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter2_o1);
  if (b_varargout_2) {
    localB->ReadParameter2_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S202>/Read Parameter2'
}

// Termination for atomic system:
void Humming_ReadParameter2_Term(DW_ReadParameter2_Hummingbird_T *localDW)
{
  // Terminate for MATLABSystem: '<S202>/Read Parameter2'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S202>/Read Parameter2'
}

// System initialize for atomic system:
void Hummi_ReadParameter2_h_Init(DW_ReadParameter2_Hummingbi_d_T *localDW)
{
  static const char_T ParameterNameStr[17] = "FW_PITCH_RD_GAIN";

  // Start for MATLABSystem: '<S203>/Read Parameter2'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummingbir_ReadParameter2_b(B_ReadParameter2_Hummingbir_j_T *localB,
  DW_ReadParameter2_Hummingbi_d_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S203>/Read Parameter2'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter2_o1);
  if (b_varargout_2) {
    localB->ReadParameter2_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S203>/Read Parameter2'
}

// Termination for atomic system:
void Hummi_ReadParameter2_b_Term(DW_ReadParameter2_Hummingbi_d_T *localDW)
{
  // Terminate for MATLABSystem: '<S203>/Read Parameter2'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S203>/Read Parameter2'
}

// System initialize for atomic system:
void Hummi_ReadParameter3_c_Init(DW_ReadParameter3_Hummingbi_d_T *localDW)
{
  static const char_T ParameterNameStr[17] = "FW_ROLL_R_D_GAIN";

  // Start for MATLABSystem: '<S203>/Read Parameter3'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummingbir_ReadParameter3_b(B_ReadParameter3_Hummingbir_j_T *localB,
  DW_ReadParameter3_Hummingbi_d_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S203>/Read Parameter3'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter3_o1);
  if (b_varargout_2) {
    localB->ReadParameter3_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S203>/Read Parameter3'
}

// Termination for atomic system:
void Hummi_ReadParameter3_a_Term(DW_ReadParameter3_Hummingbi_d_T *localDW)
{
  // Terminate for MATLABSystem: '<S203>/Read Parameter3'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S203>/Read Parameter3'
}

// System initialize for atomic system:
void Humming_ReadParameter4_Init(DW_ReadParameter4_Hummingbird_T *localDW)
{
  static const char_T ParameterNameStr[16] = "FW_YAW_R_D_GAIN";

  // Start for MATLABSystem: '<S203>/Read Parameter4'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummingbird__ReadParameter4(B_ReadParameter4_Hummingbird__T *localB,
  DW_ReadParameter4_Hummingbird_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S203>/Read Parameter4'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter4_o1);
  if (b_varargout_2) {
    localB->ReadParameter4_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S203>/Read Parameter4'
}

// Termination for atomic system:
void Humming_ReadParameter4_Term(DW_ReadParameter4_Hummingbird_T *localDW)
{
  // Terminate for MATLABSystem: '<S203>/Read Parameter4'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S203>/Read Parameter4'
}

// System initialize for atomic system:
void Hummin_ReadParameter_j_Init(DW_ReadParameter_Hummingb_d53_T *localDW)
{
  static const char_T ParameterNameStr[13] = "FW_DM_P_GAIN";

  // Start for MATLABSystem: '<S204>/Read Parameter'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummingbi_ReadParameter_b3r(B_ReadParameter_Hummingbi_jtu_T *localB,
  DW_ReadParameter_Hummingb_d53_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S204>/Read Parameter'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter_o1);
  if (b_varargout_2) {
    localB->ReadParameter_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S204>/Read Parameter'
}

// Termination for atomic system:
void Hummin_ReadParameter_g_Term(DW_ReadParameter_Hummingb_d53_T *localDW)
{
  // Terminate for MATLABSystem: '<S204>/Read Parameter'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S204>/Read Parameter'
}

// System initialize for atomic system:
void Hummi_ReadParameter1_i_Init(DW_ReadParameter1_Humming_d53_T *localDW)
{
  static const char_T ParameterNameStr[13] = "FW_DL_P_GAIN";

  // Start for MATLABSystem: '<S204>/Read Parameter1'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummingb_ReadParameter1_b3r(B_ReadParameter1_Hummingb_jtu_T *localB,
  DW_ReadParameter1_Humming_d53_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S204>/Read Parameter1'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter1_o1);
  if (b_varargout_2) {
    localB->ReadParameter1_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S204>/Read Parameter1'
}

// Termination for atomic system:
void Hummi_ReadParameter1_h_Term(DW_ReadParameter1_Humming_d53_T *localDW)
{
  // Terminate for MATLABSystem: '<S204>/Read Parameter1'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S204>/Read Parameter1'
}

// System initialize for atomic system:
void Hummi_ReadParameter2_e_Init(DW_ReadParameter2_Hummingb_d5_T *localDW)
{
  static const char_T ParameterNameStr[13] = "FW_DN_P_GAIN";

  // Start for MATLABSystem: '<S204>/Read Parameter2'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummingbi_ReadParameter2_b3(B_ReadParameter2_Hummingbi_jt_T *localB,
  DW_ReadParameter2_Hummingb_d5_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S204>/Read Parameter2'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter2_o1);
  if (b_varargout_2) {
    localB->ReadParameter2_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S204>/Read Parameter2'
}

// Termination for atomic system:
void Hummi_ReadParameter2_l_Term(DW_ReadParameter2_Hummingb_d5_T *localDW)
{
  // Terminate for MATLABSystem: '<S204>/Read Parameter2'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S204>/Read Parameter2'
}

// System initialize for atomic system:
void Hummin_ReadParameter_a_Init(DW_ReadParameter_Humming_d533_T *localDW)
{
  static const char_T ParameterNameStr[13] = "MR_CR_P_GAIN";

  // Start for MATLABSystem: '<S545>/Read Parameter'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummingb_ReadParameter_b3rg(B_ReadParameter_Hummingb_jtur_T *localB,
  DW_ReadParameter_Humming_d533_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S545>/Read Parameter'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter_o1);
  if (b_varargout_2) {
    localB->ReadParameter_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S545>/Read Parameter'
}

// Termination for atomic system:
void Hummin_ReadParameter_m_Term(DW_ReadParameter_Humming_d533_T *localDW)
{
  // Terminate for MATLABSystem: '<S545>/Read Parameter'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S545>/Read Parameter'
}

// System initialize for atomic system:
void Hummi_ReadParameter1_k_Init(DW_ReadParameter1_Hummin_d533_T *localDW)
{
  static const char_T ParameterNameStr[13] = "MR_CR_D_GAIN";

  // Start for MATLABSystem: '<S545>/Read Parameter1'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Humming_ReadParameter1_b3rg(B_ReadParameter1_Humming_jtur_T *localB,
  DW_ReadParameter1_Hummin_d533_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S545>/Read Parameter1'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter1_o1);
  if (b_varargout_2) {
    localB->ReadParameter1_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S545>/Read Parameter1'
}

// Termination for atomic system:
void Hummi_ReadParameter1_f_Term(DW_ReadParameter1_Hummin_d533_T *localDW)
{
  // Terminate for MATLABSystem: '<S545>/Read Parameter1'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S545>/Read Parameter1'
}

// System initialize for atomic system:
void Hummi_ReadParameter_cb_Init(DW_ReadParameter_Hummin_d533c_T *localDW)
{
  static const char_T ParameterNameStr[13] = "PITCH_P_GAIN";

  // Start for MATLABSystem: '<S607>/Read Parameter'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Humming_ReadParameter_b3rga(B_ReadParameter_Humming_jturd_T *localB,
  DW_ReadParameter_Hummin_d533c_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S607>/Read Parameter'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter_o1);
  if (b_varargout_2) {
    localB->ReadParameter_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S607>/Read Parameter'
}

// Termination for atomic system:
void Hummin_ReadParameter_l_Term(DW_ReadParameter_Hummin_d533c_T *localDW)
{
  // Terminate for MATLABSystem: '<S607>/Read Parameter'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S607>/Read Parameter'
}

// System initialize for atomic system:
void Hummi_ReadParameter1_b_Init(DW_ReadParameter1_Hummi_d533c_T *localDW)
{
  static const char_T ParameterNameStr[12] = "ROLL_P_GAIN";

  // Start for MATLABSystem: '<S607>/Read Parameter1'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummin_ReadParameter1_b3rga(B_ReadParameter1_Hummin_jturd_T *localB,
  DW_ReadParameter1_Hummi_d533c_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S607>/Read Parameter1'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter1_o1);
  if (b_varargout_2) {
    localB->ReadParameter1_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S607>/Read Parameter1'
}

// Termination for atomic system:
void Hummi_ReadParameter1_n_Term(DW_ReadParameter1_Hummi_d533c_T *localDW)
{
  // Terminate for MATLABSystem: '<S607>/Read Parameter1'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S607>/Read Parameter1'
}

// System initialize for atomic system:
void Hummi_ReadParameter2_c_Init(DW_ReadParameter2_Humming_d53_T *localDW)
{
  static const char_T ParameterNameStr[11] = "YAW_P_GAIN";

  // Start for MATLABSystem: '<S607>/Read Parameter2'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummingb_ReadParameter2_b3r(B_ReadParameter2_Hummingb_jtu_T *localB,
  DW_ReadParameter2_Humming_d53_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S607>/Read Parameter2'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter2_o1);
  if (b_varargout_2) {
    localB->ReadParameter2_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S607>/Read Parameter2'
}

// Termination for atomic system:
void Hummi_ReadParameter2_a_Term(DW_ReadParameter2_Humming_d53_T *localDW)
{
  // Terminate for MATLABSystem: '<S607>/Read Parameter2'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S607>/Read Parameter2'
}

// System initialize for atomic system:
void Hummin_ReadParameter_g_Init(DW_ReadParameter_Hummi_d533co_T *localDW)
{
  static const char_T ParameterNameStr[13] = "PITCH_D_GAIN";

  // Start for MATLABSystem: '<S608>/Read Parameter'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummin_ReadParameter_b3rgae(B_ReadParameter_Hummin_jturdt_T *localB,
  DW_ReadParameter_Hummi_d533co_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S608>/Read Parameter'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter_o1);
  if (b_varargout_2) {
    localB->ReadParameter_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S608>/Read Parameter'
}

// Termination for atomic system:
void Hummin_ReadParameter_k_Term(DW_ReadParameter_Hummi_d533co_T *localDW)
{
  // Terminate for MATLABSystem: '<S608>/Read Parameter'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S608>/Read Parameter'
}

// System initialize for atomic system:
void Hummi_ReadParameter1_o_Init(DW_ReadParameter1_Humm_d533co_T *localDW)
{
  static const char_T ParameterNameStr[12] = "ROLL_D_GAIN";

  // Start for MATLABSystem: '<S608>/Read Parameter1'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummi_ReadParameter1_b3rgae(B_ReadParameter1_Hummi_jturdt_T *localB,
  DW_ReadParameter1_Humm_d533co_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S608>/Read Parameter1'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter1_o1);
  if (b_varargout_2) {
    localB->ReadParameter1_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S608>/Read Parameter1'
}

// Termination for atomic system:
void Humm_ReadParameter1_gu_Term(DW_ReadParameter1_Humm_d533co_T *localDW)
{
  // Terminate for MATLABSystem: '<S608>/Read Parameter1'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S608>/Read Parameter1'
}

// System initialize for atomic system:
void Humm_ReadParameter2_cs_Init(DW_ReadParameter2_Hummin_d533_T *localDW)
{
  static const char_T ParameterNameStr[11] = "YAW_D_GAIN";

  // Start for MATLABSystem: '<S608>/Read Parameter2'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Humming_ReadParameter2_b3rg(B_ReadParameter2_Humming_jtur_T *localB,
  DW_ReadParameter2_Hummin_d533_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S608>/Read Parameter2'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter2_o1);
  if (b_varargout_2) {
    localB->ReadParameter2_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S608>/Read Parameter2'
}

// Termination for atomic system:
void Hummi_ReadParameter2_h_Term(DW_ReadParameter2_Hummin_d533_T *localDW)
{
  // Terminate for MATLABSystem: '<S608>/Read Parameter2'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S608>/Read Parameter2'
}

// System initialize for atomic system:
void Hummin_ReadParameter_h_Init(DW_ReadParameter_Humm_d533cok_T *localDW)
{
  static const char_T ParameterNameStr[15] = "PITCH_R_P_GAIN";

  // Start for MATLABSystem: '<S609>/Read Parameter'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummi_ReadParameter_b3rgaen(B_ReadParameter_Hummi_jturdtk_T *localB,
  DW_ReadParameter_Humm_d533cok_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S609>/Read Parameter'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter_o1);
  if (b_varargout_2) {
    localB->ReadParameter_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S609>/Read Parameter'
}

// Termination for atomic system:
void Hummin_ReadParameter_e_Term(DW_ReadParameter_Humm_d533cok_T *localDW)
{
  // Terminate for MATLABSystem: '<S609>/Read Parameter'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S609>/Read Parameter'
}

// System initialize for atomic system:
void Humm_ReadParameter1_kn_Init(DW_ReadParameter1_Hum_d533cok_T *localDW)
{
  static const char_T ParameterNameStr[14] = "ROLL_R_P_GAIN";

  // Start for MATLABSystem: '<S609>/Read Parameter1'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Humm_ReadParameter1_b3rgaen(B_ReadParameter1_Humm_jturdtk_T *localB,
  DW_ReadParameter1_Hum_d533cok_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S609>/Read Parameter1'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter1_o1);
  if (b_varargout_2) {
    localB->ReadParameter1_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S609>/Read Parameter1'
}

// Termination for atomic system:
void Humm_ReadParameter1_n2_Term(DW_ReadParameter1_Hum_d533cok_T *localDW)
{
  // Terminate for MATLABSystem: '<S609>/Read Parameter1'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S609>/Read Parameter1'
}

// System initialize for atomic system:
void Hummi_ReadParameter2_o_Init(DW_ReadParameter2_Hummi_d533c_T *localDW)
{
  static const char_T ParameterNameStr[13] = "YAW_R_P_GAIN";

  // Start for MATLABSystem: '<S609>/Read Parameter2'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummin_ReadParameter2_b3rga(B_ReadParameter2_Hummin_jturd_T *localB,
  DW_ReadParameter2_Hummi_d533c_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S609>/Read Parameter2'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter2_o1);
  if (b_varargout_2) {
    localB->ReadParameter2_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S609>/Read Parameter2'
}

// Termination for atomic system:
void Hummi_ReadParameter2_o_Term(DW_ReadParameter2_Hummi_d533c_T *localDW)
{
  // Terminate for MATLABSystem: '<S609>/Read Parameter2'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S609>/Read Parameter2'
}

// System initialize for atomic system:
void Hummi_ReadParameter_cl_Init(DW_ReadParameter_Hum_d533cok2_T *localDW)
{
  static const char_T ParameterNameStr[17] = "MR_DM_PITCH_GAIN";

  // Start for MATLABSystem: '<S610>/Read Parameter'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Humm_ReadParameter_b3rgaenb(B_ReadParameter_Humm_jturdtkq_T *localB,
  DW_ReadParameter_Hum_d533cok2_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S610>/Read Parameter'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter_o1);
  if (b_varargout_2) {
    localB->ReadParameter_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S610>/Read Parameter'
}

// Termination for atomic system:
void Hummi_ReadParameter_ms_Term(DW_ReadParameter_Hum_d533cok2_T *localDW)
{
  // Terminate for MATLABSystem: '<S610>/Read Parameter'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S610>/Read Parameter'
}

// System initialize for atomic system:
void Humm_ReadParameter1_l5_Init(DW_ReadParameter1_Hu_d533cok2_T *localDW)
{
  static const char_T ParameterNameStr[16] = "MR_DM_ROLL_GAIN";

  // Start for MATLABSystem: '<S610>/Read Parameter1'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hum_ReadParameter1_b3rgaenb(B_ReadParameter1_Hum_jturdtkq_T *localB,
  DW_ReadParameter1_Hu_d533cok2_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S610>/Read Parameter1'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter1_o1);
  if (b_varargout_2) {
    localB->ReadParameter1_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S610>/Read Parameter1'
}

// Termination for atomic system:
void Hummi_ReadParameter1_k_Term(DW_ReadParameter1_Hu_d533cok2_T *localDW)
{
  // Terminate for MATLABSystem: '<S610>/Read Parameter1'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S610>/Read Parameter1'
}

// System initialize for atomic system:
void Humm_ReadParameter2_ow_Init(DW_ReadParameter2_Humm_d533co_T *localDW)
{
  static const char_T ParameterNameStr[15] = "MR_DM_YAW_GAIN";

  // Start for MATLABSystem: '<S610>/Read Parameter2'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 200.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void Hummi_ReadParameter2_b3rgae(B_ReadParameter2_Hummi_jturdt_T *localB,
  DW_ReadParameter2_Humm_d533co_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S610>/Read Parameter2'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter2_o1);
  if (b_varargout_2) {
    localB->ReadParameter2_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S610>/Read Parameter2'
}

// Termination for atomic system:
void Hummi_ReadParameter2_j_Term(DW_ReadParameter2_Humm_d533co_T *localDW)
{
  // Terminate for MATLABSystem: '<S610>/Read Parameter2'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S610>/Read Parameter2'
}

//
// Output and update for atomic system:
//    '<S9>/MATLAB Function2'
//    '<S10>/MATLAB Function2'
//
void Hummingbird_MATLABFunction2(real_T rtu_psi, real_T rtu_psi_c, real_T
  *rty_psi_c_unwrapped)
{
  if (fabs(rtu_psi - rtu_psi_c) < 3.1415926535897931) {
    *rty_psi_c_unwrapped = rtu_psi_c;
  } else if (rtu_psi > 0.0) {
    *rty_psi_c_unwrapped = rtu_psi_c + 6.2831853071795862;
  } else {
    *rty_psi_c_unwrapped = rtu_psi_c - 6.2831853071795862;
  }
}

static real_T Hummingbird_Fligh_rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      Hummingbird_Flight_Controller_B.i2 = 1;
    } else {
      Hummingbird_Flight_Controller_B.i2 = -1;
    }

    if (u1 > 0.0) {
      Hummingbird_Flight_Controller_B.i3 = 1;
    } else {
      Hummingbird_Flight_Controller_B.i3 = -1;
    }

    y = atan2(static_cast<real_T>(Hummingbird_Flight_Controller_B.i2),
              static_cast<real_T>(Hummingbird_Flight_Controller_B.i3));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static real32_T Hummingbird_Fligh_rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    if (u0 > 0.0F) {
      Hummingbird_Flight_Controller_B.i7 = 1;
    } else {
      Hummingbird_Flight_Controller_B.i7 = -1;
    }

    if (u1 > 0.0F) {
      Hummingbird_Flight_Controller_B.i8 = 1;
    } else {
      Hummingbird_Flight_Controller_B.i8 = -1;
    }

    y = static_cast<real32_T>(atan2(static_cast<real_T>(static_cast<real32_T>
      (Hummingbird_Flight_Controller_B.i7)), static_cast<real_T>
      (static_cast<real32_T>(Hummingbird_Flight_Controller_B.i8))));
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = static_cast<real32_T>(atan2(static_cast<real_T>(u0), static_cast<real_T>
      (u1)));
  }

  return y;
}

static real_T Hummingbird_Flight__rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      Hummingbird_Flight_Controller_B.q = ceil(u1);
    } else {
      Hummingbird_Flight_Controller_B.q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != Hummingbird_Flight_Controller_B.q)) {
      Hummingbird_Flight_Controller_B.q = fabs(u0 / u1);
      if (!(fabs(Hummingbird_Flight_Controller_B.q - floor
                 (Hummingbird_Flight_Controller_B.q + 0.5)) > DBL_EPSILON *
            Hummingbird_Flight_Controller_B.q)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S13>/MATLAB Function2'
static void Hummingbird_Flight_Control_cosd(real_T *x)
{
  int8_T n;
  if (rtIsInf(*x) || rtIsNaN(*x)) {
    *x = (rtNaN);
  } else {
    Hummingbird_Flight_Controller_B.b_x_j = Hummingbird_Flight__rt_remd_snf(*x,
      360.0);
    Hummingbird_Flight_Controller_B.absx_j = fabs
      (Hummingbird_Flight_Controller_B.b_x_j);
    if (Hummingbird_Flight_Controller_B.absx_j > 180.0) {
      if (Hummingbird_Flight_Controller_B.b_x_j > 0.0) {
        Hummingbird_Flight_Controller_B.b_x_j -= 360.0;
      } else {
        Hummingbird_Flight_Controller_B.b_x_j += 360.0;
      }

      Hummingbird_Flight_Controller_B.absx_j = fabs
        (Hummingbird_Flight_Controller_B.b_x_j);
    }

    if (Hummingbird_Flight_Controller_B.absx_j <= 45.0) {
      Hummingbird_Flight_Controller_B.b_x_j *= 0.017453292519943295;
      n = 0;
    } else if (Hummingbird_Flight_Controller_B.absx_j <= 135.0) {
      if (Hummingbird_Flight_Controller_B.b_x_j > 0.0) {
        Hummingbird_Flight_Controller_B.b_x_j =
          (Hummingbird_Flight_Controller_B.b_x_j - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        Hummingbird_Flight_Controller_B.b_x_j =
          (Hummingbird_Flight_Controller_B.b_x_j + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (Hummingbird_Flight_Controller_B.b_x_j > 0.0) {
      Hummingbird_Flight_Controller_B.b_x_j =
        (Hummingbird_Flight_Controller_B.b_x_j - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      Hummingbird_Flight_Controller_B.b_x_j =
        (Hummingbird_Flight_Controller_B.b_x_j + 180.0) * 0.017453292519943295;
      n = -2;
    }

    switch (n) {
     case 0:
      *x = cos(Hummingbird_Flight_Controller_B.b_x_j);
      break;

     case 1:
      *x = -sin(Hummingbird_Flight_Controller_B.b_x_j);
      break;

     case -1:
      *x = sin(Hummingbird_Flight_Controller_B.b_x_j);
      break;

     default:
      *x = -cos(Hummingbird_Flight_Controller_B.b_x_j);
      break;
    }
  }
}

// Function for MATLAB Function: '<S13>/MATLAB Function2'
static void Hummingbird_Flight_Control_sind(real_T *x)
{
  int8_T n;
  if (rtIsInf(*x) || rtIsNaN(*x)) {
    *x = (rtNaN);
  } else {
    Hummingbird_Flight_Controller_B.b_x = Hummingbird_Flight__rt_remd_snf(*x,
      360.0);
    Hummingbird_Flight_Controller_B.absx_n = fabs
      (Hummingbird_Flight_Controller_B.b_x);
    if (Hummingbird_Flight_Controller_B.absx_n > 180.0) {
      if (Hummingbird_Flight_Controller_B.b_x > 0.0) {
        Hummingbird_Flight_Controller_B.b_x -= 360.0;
      } else {
        Hummingbird_Flight_Controller_B.b_x += 360.0;
      }

      Hummingbird_Flight_Controller_B.absx_n = fabs
        (Hummingbird_Flight_Controller_B.b_x);
    }

    if (Hummingbird_Flight_Controller_B.absx_n <= 45.0) {
      Hummingbird_Flight_Controller_B.b_x *= 0.017453292519943295;
      n = 0;
    } else if (Hummingbird_Flight_Controller_B.absx_n <= 135.0) {
      if (Hummingbird_Flight_Controller_B.b_x > 0.0) {
        Hummingbird_Flight_Controller_B.b_x =
          (Hummingbird_Flight_Controller_B.b_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        Hummingbird_Flight_Controller_B.b_x =
          (Hummingbird_Flight_Controller_B.b_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (Hummingbird_Flight_Controller_B.b_x > 0.0) {
      Hummingbird_Flight_Controller_B.b_x = (Hummingbird_Flight_Controller_B.b_x
        - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      Hummingbird_Flight_Controller_B.b_x = (Hummingbird_Flight_Controller_B.b_x
        + 180.0) * 0.017453292519943295;
      n = -2;
    }

    switch (n) {
     case 0:
      *x = sin(Hummingbird_Flight_Controller_B.b_x);
      break;

     case 1:
      *x = cos(Hummingbird_Flight_Controller_B.b_x);
      break;

     case -1:
      *x = -cos(Hummingbird_Flight_Controller_B.b_x);
      break;

     default:
      *x = -sin(Hummingbird_Flight_Controller_B.b_x);
      break;
    }
  }
}

// Function for MATLAB Function: '<S13>/MATLAB Function2'
static void Hummingbird_Flight_Con_lla2ecef(const real_T llaPos[3], real_T
  ecefPos[3])
{
  Hummingbird_Flight_Controller_B.sinphi_m = llaPos[0];
  Hummingbird_Flight_Control_sind(&Hummingbird_Flight_Controller_B.sinphi_m);
  Hummingbird_Flight_Controller_B.N = 6.378137E+6 / sqrt(1.0 -
    Hummingbird_Flight_Controller_B.sinphi_m *
    Hummingbird_Flight_Controller_B.sinphi_m * 0.0066943799901413165);
  Hummingbird_Flight_Controller_B.b = llaPos[0];
  Hummingbird_Flight_Control_cosd(&Hummingbird_Flight_Controller_B.b);
  Hummingbird_Flight_Controller_B.b *= Hummingbird_Flight_Controller_B.N +
    llaPos[2];
  Hummingbird_Flight_Controller_B.c = llaPos[1];
  Hummingbird_Flight_Control_cosd(&Hummingbird_Flight_Controller_B.c);
  Hummingbird_Flight_Controller_B.d = llaPos[1];
  Hummingbird_Flight_Control_sind(&Hummingbird_Flight_Controller_B.d);
  ecefPos[0] = Hummingbird_Flight_Controller_B.b *
    Hummingbird_Flight_Controller_B.c;
  ecefPos[1] = Hummingbird_Flight_Controller_B.b *
    Hummingbird_Flight_Controller_B.d;
  ecefPos[2] = (Hummingbird_Flight_Controller_B.N * 0.99330562000985867 +
                llaPos[2]) * Hummingbird_Flight_Controller_B.sinphi_m;
}

// Function for MATLAB Function: '<S13>/MATLAB Function2'
static void Hummingbird_Flight_Cont_lla2ned(const real_T lla[3], const real_T
  lla0[3], real_T xyzNED[3])
{
  Hummingbird_Flight_Controller_B.cosphi = lla0[0];
  Hummingbird_Flight_Control_cosd(&Hummingbird_Flight_Controller_B.cosphi);
  Hummingbird_Flight_Controller_B.sinphi = lla0[0];
  Hummingbird_Flight_Control_sind(&Hummingbird_Flight_Controller_B.sinphi);
  Hummingbird_Flight_Controller_B.coslambda = lla0[1];
  Hummingbird_Flight_Control_cosd(&Hummingbird_Flight_Controller_B.coslambda);
  Hummingbird_Flight_Controller_B.sinlambda = lla0[1];
  Hummingbird_Flight_Control_sind(&Hummingbird_Flight_Controller_B.sinlambda);
  Hummingbird_Flight_Con_lla2ecef(lla, Hummingbird_Flight_Controller_B.dv1);
  Hummingbird_Flight_Con_lla2ecef(lla0, Hummingbird_Flight_Controller_B.dv2);
  Hummingbird_Flight_Controller_B.ecefPosWithENUOrigin_idx_0 =
    Hummingbird_Flight_Controller_B.dv1[0] -
    Hummingbird_Flight_Controller_B.dv2[0];
  Hummingbird_Flight_Controller_B.ecefPosWithENUOrigin_idx_1 =
    Hummingbird_Flight_Controller_B.dv1[1] -
    Hummingbird_Flight_Controller_B.dv2[1];
  Hummingbird_Flight_Controller_B.ecefPosWithENUOrigin_idx_2 =
    Hummingbird_Flight_Controller_B.dv1[2] -
    Hummingbird_Flight_Controller_B.dv2[2];
  Hummingbird_Flight_Controller_B.tmp =
    Hummingbird_Flight_Controller_B.coslambda *
    Hummingbird_Flight_Controller_B.ecefPosWithENUOrigin_idx_0 +
    Hummingbird_Flight_Controller_B.sinlambda *
    Hummingbird_Flight_Controller_B.ecefPosWithENUOrigin_idx_1;
  xyzNED[0] = -Hummingbird_Flight_Controller_B.sinphi *
    Hummingbird_Flight_Controller_B.tmp + Hummingbird_Flight_Controller_B.cosphi
    * Hummingbird_Flight_Controller_B.ecefPosWithENUOrigin_idx_2;
  xyzNED[1] = -Hummingbird_Flight_Controller_B.sinlambda *
    Hummingbird_Flight_Controller_B.ecefPosWithENUOrigin_idx_0 +
    Hummingbird_Flight_Controller_B.coslambda *
    Hummingbird_Flight_Controller_B.ecefPosWithENUOrigin_idx_1;
  xyzNED[2] = -(Hummingbird_Flight_Controller_B.cosphi *
                Hummingbird_Flight_Controller_B.tmp +
                Hummingbird_Flight_Controller_B.sinphi *
                Hummingbird_Flight_Controller_B.ecefPosWithENUOrigin_idx_2);
}

// Function for MATLAB Function: '<S13>/MATLAB Function1'
static real_T Hummingbird_Flight_Control_norm(const real_T x[3])
{
  real_T y;
  Hummingbird_Flight_Controller_B.scale_j = 3.3121686421112381E-170;
  Hummingbird_Flight_Controller_B.absxk_f = fabs(x[0]);
  if (Hummingbird_Flight_Controller_B.absxk_f > 3.3121686421112381E-170) {
    y = 1.0;
    Hummingbird_Flight_Controller_B.scale_j =
      Hummingbird_Flight_Controller_B.absxk_f;
  } else {
    Hummingbird_Flight_Controller_B.t_a =
      Hummingbird_Flight_Controller_B.absxk_f / 3.3121686421112381E-170;
    y = Hummingbird_Flight_Controller_B.t_a *
      Hummingbird_Flight_Controller_B.t_a;
  }

  Hummingbird_Flight_Controller_B.absxk_f = fabs(x[1]);
  if (Hummingbird_Flight_Controller_B.absxk_f >
      Hummingbird_Flight_Controller_B.scale_j) {
    Hummingbird_Flight_Controller_B.t_a =
      Hummingbird_Flight_Controller_B.scale_j /
      Hummingbird_Flight_Controller_B.absxk_f;
    y = y * Hummingbird_Flight_Controller_B.t_a *
      Hummingbird_Flight_Controller_B.t_a + 1.0;
    Hummingbird_Flight_Controller_B.scale_j =
      Hummingbird_Flight_Controller_B.absxk_f;
  } else {
    Hummingbird_Flight_Controller_B.t_a =
      Hummingbird_Flight_Controller_B.absxk_f /
      Hummingbird_Flight_Controller_B.scale_j;
    y += Hummingbird_Flight_Controller_B.t_a *
      Hummingbird_Flight_Controller_B.t_a;
  }

  Hummingbird_Flight_Controller_B.absxk_f = fabs(x[2]);
  if (Hummingbird_Flight_Controller_B.absxk_f >
      Hummingbird_Flight_Controller_B.scale_j) {
    Hummingbird_Flight_Controller_B.t_a =
      Hummingbird_Flight_Controller_B.scale_j /
      Hummingbird_Flight_Controller_B.absxk_f;
    y = y * Hummingbird_Flight_Controller_B.t_a *
      Hummingbird_Flight_Controller_B.t_a + 1.0;
    Hummingbird_Flight_Controller_B.scale_j =
      Hummingbird_Flight_Controller_B.absxk_f;
  } else {
    Hummingbird_Flight_Controller_B.t_a =
      Hummingbird_Flight_Controller_B.absxk_f /
      Hummingbird_Flight_Controller_B.scale_j;
    y += Hummingbird_Flight_Controller_B.t_a *
      Hummingbird_Flight_Controller_B.t_a;
  }

  return Hummingbird_Flight_Controller_B.scale_j * sqrt(y);
}

// Function for MATLAB Function: '<S13>/MATLAB Function1'
static real_T Hummingbird_Flight_Con_xzlangeM(const real_T x[9])
{
  real_T y;
  boolean_T exitg1;
  y = 0.0;
  Hummingbird_Flight_Controller_B.k_ct = 0;
  exitg1 = false;
  while ((!exitg1) && (Hummingbird_Flight_Controller_B.k_ct < 9)) {
    Hummingbird_Flight_Controller_B.absxk_o = fabs
      (x[Hummingbird_Flight_Controller_B.k_ct]);
    if (rtIsNaN(Hummingbird_Flight_Controller_B.absxk_o)) {
      y = (rtNaN);
      exitg1 = true;
    } else {
      if (Hummingbird_Flight_Controller_B.absxk_o > y) {
        y = Hummingbird_Flight_Controller_B.absxk_o;
      }

      Hummingbird_Flight_Controller_B.k_ct++;
    }
  }

  return y;
}

// Function for MATLAB Function: '<S13>/MATLAB Function1'
static void Hummingbird_Flight_Cont_xzlascl(real_T cfrom, real_T cto, int32_T m,
  int32_T n, real_T A[9], int32_T iA0, int32_T lda)
{
  boolean_T notdone;
  Hummingbird_Flight_Controller_B.cfromc_d = cfrom;
  Hummingbird_Flight_Controller_B.ctoc_g = cto;
  notdone = true;
  while (notdone) {
    Hummingbird_Flight_Controller_B.cfrom1_l =
      Hummingbird_Flight_Controller_B.cfromc_d * 2.0041683600089728E-292;
    Hummingbird_Flight_Controller_B.cto1_d =
      Hummingbird_Flight_Controller_B.ctoc_g / 4.9896007738368E+291;
    if ((fabs(Hummingbird_Flight_Controller_B.cfrom1_l) > fabs
         (Hummingbird_Flight_Controller_B.ctoc_g)) &&
        (Hummingbird_Flight_Controller_B.ctoc_g != 0.0)) {
      Hummingbird_Flight_Controller_B.mul_d = 2.0041683600089728E-292;
      Hummingbird_Flight_Controller_B.cfromc_d =
        Hummingbird_Flight_Controller_B.cfrom1_l;
    } else if (fabs(Hummingbird_Flight_Controller_B.cto1_d) > fabs
               (Hummingbird_Flight_Controller_B.cfromc_d)) {
      Hummingbird_Flight_Controller_B.mul_d = 4.9896007738368E+291;
      Hummingbird_Flight_Controller_B.ctoc_g =
        Hummingbird_Flight_Controller_B.cto1_d;
    } else {
      Hummingbird_Flight_Controller_B.mul_d =
        Hummingbird_Flight_Controller_B.ctoc_g /
        Hummingbird_Flight_Controller_B.cfromc_d;
      notdone = false;
    }

    for (Hummingbird_Flight_Controller_B.j_m = 0;
         Hummingbird_Flight_Controller_B.j_m < n;
         Hummingbird_Flight_Controller_B.j_m++) {
      Hummingbird_Flight_Controller_B.offset_c =
        (Hummingbird_Flight_Controller_B.j_m * lda + iA0) - 2;
      for (Hummingbird_Flight_Controller_B.b_i_m = 0;
           Hummingbird_Flight_Controller_B.b_i_m < m;
           Hummingbird_Flight_Controller_B.b_i_m++) {
        Hummingbird_Flight_Controller_B.i1 =
          (Hummingbird_Flight_Controller_B.b_i_m +
           Hummingbird_Flight_Controller_B.offset_c) + 1;
        A[Hummingbird_Flight_Controller_B.i1] *=
          Hummingbird_Flight_Controller_B.mul_d;
      }
    }
  }
}

// Function for MATLAB Function: '<S13>/MATLAB Function1'
static real_T Hummingbird_Flight_Contro_xnrm2(int32_T n, const real_T x[9],
  int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      Hummingbird_Flight_Controller_B.scale_l = 3.3121686421112381E-170;
      Hummingbird_Flight_Controller_B.kend_h = ix0 + n;
      for (Hummingbird_Flight_Controller_B.k_c = ix0;
           Hummingbird_Flight_Controller_B.k_c <
           Hummingbird_Flight_Controller_B.kend_h;
           Hummingbird_Flight_Controller_B.k_c++) {
        Hummingbird_Flight_Controller_B.absxk_h = fabs
          (x[Hummingbird_Flight_Controller_B.k_c - 1]);
        if (Hummingbird_Flight_Controller_B.absxk_h >
            Hummingbird_Flight_Controller_B.scale_l) {
          Hummingbird_Flight_Controller_B.t_bn =
            Hummingbird_Flight_Controller_B.scale_l /
            Hummingbird_Flight_Controller_B.absxk_h;
          y = y * Hummingbird_Flight_Controller_B.t_bn *
            Hummingbird_Flight_Controller_B.t_bn + 1.0;
          Hummingbird_Flight_Controller_B.scale_l =
            Hummingbird_Flight_Controller_B.absxk_h;
        } else {
          Hummingbird_Flight_Controller_B.t_bn =
            Hummingbird_Flight_Controller_B.absxk_h /
            Hummingbird_Flight_Controller_B.scale_l;
          y += Hummingbird_Flight_Controller_B.t_bn *
            Hummingbird_Flight_Controller_B.t_bn;
        }
      }

      y = Hummingbird_Flight_Controller_B.scale_l * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S13>/MATLAB Function1'
static real_T Hummingbird_Flight_Contro_xdotc(int32_T n, const real_T x[9],
  int32_T ix0, const real_T y[9], int32_T iy0)
{
  real_T d;
  d = 0.0;
  if (n >= 1) {
    for (Hummingbird_Flight_Controller_B.k_e = 0;
         Hummingbird_Flight_Controller_B.k_e < n;
         Hummingbird_Flight_Controller_B.k_e++) {
      d += x[(ix0 + Hummingbird_Flight_Controller_B.k_e) - 1] * y[(iy0 +
        Hummingbird_Flight_Controller_B.k_e) - 1];
    }
  }

  return d;
}

// Function for MATLAB Function: '<S13>/MATLAB Function1'
static void Hummingbird_Flight_Contro_xaxpy(int32_T n, real_T a, int32_T ix0,
  real_T y[9], int32_T iy0)
{
  if ((n >= 1) && (!(a == 0.0))) {
    for (Hummingbird_Flight_Controller_B.k_a = 0;
         Hummingbird_Flight_Controller_B.k_a < n;
         Hummingbird_Flight_Controller_B.k_a++) {
      Hummingbird_Flight_Controller_B.i6 = (iy0 +
        Hummingbird_Flight_Controller_B.k_a) - 1;
      y[Hummingbird_Flight_Controller_B.i6] += y[(ix0 +
        Hummingbird_Flight_Controller_B.k_a) - 1] * a;
    }
  }
}

// Function for MATLAB Function: '<S13>/MATLAB Function1'
static real_T Hummingbird_Flight_Cont_xnrm2_b(int32_T n, const real_T x[3],
  int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      Hummingbird_Flight_Controller_B.scale_b = 3.3121686421112381E-170;
      Hummingbird_Flight_Controller_B.kend = ix0 + n;
      for (Hummingbird_Flight_Controller_B.k_j = ix0;
           Hummingbird_Flight_Controller_B.k_j <
           Hummingbird_Flight_Controller_B.kend;
           Hummingbird_Flight_Controller_B.k_j++) {
        Hummingbird_Flight_Controller_B.absxk_n = fabs
          (x[Hummingbird_Flight_Controller_B.k_j - 1]);
        if (Hummingbird_Flight_Controller_B.absxk_n >
            Hummingbird_Flight_Controller_B.scale_b) {
          Hummingbird_Flight_Controller_B.t_b =
            Hummingbird_Flight_Controller_B.scale_b /
            Hummingbird_Flight_Controller_B.absxk_n;
          y = y * Hummingbird_Flight_Controller_B.t_b *
            Hummingbird_Flight_Controller_B.t_b + 1.0;
          Hummingbird_Flight_Controller_B.scale_b =
            Hummingbird_Flight_Controller_B.absxk_n;
        } else {
          Hummingbird_Flight_Controller_B.t_b =
            Hummingbird_Flight_Controller_B.absxk_n /
            Hummingbird_Flight_Controller_B.scale_b;
          y += Hummingbird_Flight_Controller_B.t_b *
            Hummingbird_Flight_Controller_B.t_b;
        }
      }

      y = Hummingbird_Flight_Controller_B.scale_b * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S13>/MATLAB Function1'
static void Hummingbird_Flight_Cont_xaxpy_l(int32_T n, real_T a, const real_T x
  [9], int32_T ix0, real_T y[3], int32_T iy0)
{
  if ((n >= 1) && (!(a == 0.0))) {
    for (Hummingbird_Flight_Controller_B.k_p5 = 0;
         Hummingbird_Flight_Controller_B.k_p5 < n;
         Hummingbird_Flight_Controller_B.k_p5++) {
      Hummingbird_Flight_Controller_B.i5 = (iy0 +
        Hummingbird_Flight_Controller_B.k_p5) - 1;
      y[Hummingbird_Flight_Controller_B.i5] += x[(ix0 +
        Hummingbird_Flight_Controller_B.k_p5) - 1] * a;
    }
  }
}

// Function for MATLAB Function: '<S13>/MATLAB Function1'
static void Hummingbird_Flight_Con_xaxpy_lx(int32_T n, real_T a, const real_T x
  [3], int32_T ix0, real_T y[9], int32_T iy0)
{
  if ((n >= 1) && (!(a == 0.0))) {
    for (Hummingbird_Flight_Controller_B.k_p = 0;
         Hummingbird_Flight_Controller_B.k_p < n;
         Hummingbird_Flight_Controller_B.k_p++) {
      Hummingbird_Flight_Controller_B.i4 = (iy0 +
        Hummingbird_Flight_Controller_B.k_p) - 1;
      y[Hummingbird_Flight_Controller_B.i4] += x[(ix0 +
        Hummingbird_Flight_Controller_B.k_p) - 1] * a;
    }
  }
}

// Function for MATLAB Function: '<S13>/MATLAB Function1'
static void Hummingbird_Flight_Co_xzlascl_o(real_T cfrom, real_T cto, int32_T m,
  int32_T n, real_T A[3], int32_T iA0, int32_T lda)
{
  boolean_T notdone;
  Hummingbird_Flight_Controller_B.cfromc = cfrom;
  Hummingbird_Flight_Controller_B.ctoc = cto;
  notdone = true;
  while (notdone) {
    Hummingbird_Flight_Controller_B.cfrom1 =
      Hummingbird_Flight_Controller_B.cfromc * 2.0041683600089728E-292;
    Hummingbird_Flight_Controller_B.cto1 = Hummingbird_Flight_Controller_B.ctoc /
      4.9896007738368E+291;
    if ((fabs(Hummingbird_Flight_Controller_B.cfrom1) > fabs
         (Hummingbird_Flight_Controller_B.ctoc)) &&
        (Hummingbird_Flight_Controller_B.ctoc != 0.0)) {
      Hummingbird_Flight_Controller_B.mul = 2.0041683600089728E-292;
      Hummingbird_Flight_Controller_B.cfromc =
        Hummingbird_Flight_Controller_B.cfrom1;
    } else if (fabs(Hummingbird_Flight_Controller_B.cto1) > fabs
               (Hummingbird_Flight_Controller_B.cfromc)) {
      Hummingbird_Flight_Controller_B.mul = 4.9896007738368E+291;
      Hummingbird_Flight_Controller_B.ctoc =
        Hummingbird_Flight_Controller_B.cto1;
    } else {
      Hummingbird_Flight_Controller_B.mul = Hummingbird_Flight_Controller_B.ctoc
        / Hummingbird_Flight_Controller_B.cfromc;
      notdone = false;
    }

    for (Hummingbird_Flight_Controller_B.j = 0;
         Hummingbird_Flight_Controller_B.j < n;
         Hummingbird_Flight_Controller_B.j++) {
      Hummingbird_Flight_Controller_B.offset =
        (Hummingbird_Flight_Controller_B.j * lda + iA0) - 2;
      for (Hummingbird_Flight_Controller_B.b_i = 0;
           Hummingbird_Flight_Controller_B.b_i < m;
           Hummingbird_Flight_Controller_B.b_i++) {
        Hummingbird_Flight_Controller_B.i_m =
          (Hummingbird_Flight_Controller_B.b_i +
           Hummingbird_Flight_Controller_B.offset) + 1;
        A[Hummingbird_Flight_Controller_B.i_m] *=
          Hummingbird_Flight_Controller_B.mul;
      }
    }
  }
}

// Function for MATLAB Function: '<S13>/MATLAB Function1'
static void Hummingbird_Flight_Contro_xrotg(real_T *a, real_T *b, real_T *c,
  real_T *s)
{
  Hummingbird_Flight_Controller_B.roe = *b;
  Hummingbird_Flight_Controller_B.absa = fabs(*a);
  Hummingbird_Flight_Controller_B.absb = fabs(*b);
  if (Hummingbird_Flight_Controller_B.absa >
      Hummingbird_Flight_Controller_B.absb) {
    Hummingbird_Flight_Controller_B.roe = *a;
  }

  Hummingbird_Flight_Controller_B.scale_o = Hummingbird_Flight_Controller_B.absa
    + Hummingbird_Flight_Controller_B.absb;
  if (Hummingbird_Flight_Controller_B.scale_o == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *a = 0.0;
    *b = 0.0;
  } else {
    Hummingbird_Flight_Controller_B.ads = Hummingbird_Flight_Controller_B.absa /
      Hummingbird_Flight_Controller_B.scale_o;
    Hummingbird_Flight_Controller_B.bds = Hummingbird_Flight_Controller_B.absb /
      Hummingbird_Flight_Controller_B.scale_o;
    Hummingbird_Flight_Controller_B.scale_o *= sqrt
      (Hummingbird_Flight_Controller_B.ads * Hummingbird_Flight_Controller_B.ads
       + Hummingbird_Flight_Controller_B.bds *
       Hummingbird_Flight_Controller_B.bds);
    if (Hummingbird_Flight_Controller_B.roe < 0.0) {
      Hummingbird_Flight_Controller_B.scale_o =
        -Hummingbird_Flight_Controller_B.scale_o;
    }

    *c = *a / Hummingbird_Flight_Controller_B.scale_o;
    *s = *b / Hummingbird_Flight_Controller_B.scale_o;
    if (Hummingbird_Flight_Controller_B.absa >
        Hummingbird_Flight_Controller_B.absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }

    *a = Hummingbird_Flight_Controller_B.scale_o;
  }
}

// Function for MATLAB Function: '<S13>/MATLAB Function1'
static void Hummingbird_Flight_Controll_svd(const real_T A[9], real_T U[3])
{
  boolean_T apply_transform;
  boolean_T doscale;
  boolean_T exitg1;
  memcpy(&Hummingbird_Flight_Controller_B.b_A[0], &A[0], 9U * sizeof(real_T));
  Hummingbird_Flight_Controller_B.s[0] = 0.0;
  Hummingbird_Flight_Controller_B.e[0] = 0.0;
  Hummingbird_Flight_Controller_B.work[0] = 0.0;
  Hummingbird_Flight_Controller_B.s[1] = 0.0;
  Hummingbird_Flight_Controller_B.e[1] = 0.0;
  Hummingbird_Flight_Controller_B.work[1] = 0.0;
  Hummingbird_Flight_Controller_B.s[2] = 0.0;
  Hummingbird_Flight_Controller_B.e[2] = 0.0;
  Hummingbird_Flight_Controller_B.work[2] = 0.0;
  doscale = false;
  Hummingbird_Flight_Controller_B.anrm = Hummingbird_Flight_Con_xzlangeM(A);
  Hummingbird_Flight_Controller_B.cscale = Hummingbird_Flight_Controller_B.anrm;
  if ((Hummingbird_Flight_Controller_B.anrm > 0.0) &&
      (Hummingbird_Flight_Controller_B.anrm < 6.7178761075670888E-139)) {
    doscale = true;
    Hummingbird_Flight_Controller_B.cscale = 6.7178761075670888E-139;
    Hummingbird_Flight_Cont_xzlascl(Hummingbird_Flight_Controller_B.anrm,
      Hummingbird_Flight_Controller_B.cscale, 3, 3,
      Hummingbird_Flight_Controller_B.b_A, 1, 3);
  } else if (Hummingbird_Flight_Controller_B.anrm > 1.4885657073574029E+138) {
    doscale = true;
    Hummingbird_Flight_Controller_B.cscale = 1.4885657073574029E+138;
    Hummingbird_Flight_Cont_xzlascl(Hummingbird_Flight_Controller_B.anrm,
      Hummingbird_Flight_Controller_B.cscale, 3, 3,
      Hummingbird_Flight_Controller_B.b_A, 1, 3);
  }

  for (Hummingbird_Flight_Controller_B.m = 0; Hummingbird_Flight_Controller_B.m <
       2; Hummingbird_Flight_Controller_B.m++) {
    Hummingbird_Flight_Controller_B.qp1 = Hummingbird_Flight_Controller_B.m + 2;
    Hummingbird_Flight_Controller_B.qq_tmp = 3 *
      Hummingbird_Flight_Controller_B.m + Hummingbird_Flight_Controller_B.m;
    Hummingbird_Flight_Controller_B.qq = Hummingbird_Flight_Controller_B.qq_tmp
      + 1;
    apply_transform = false;
    Hummingbird_Flight_Controller_B.nrm = Hummingbird_Flight_Contro_xnrm2(3 -
      Hummingbird_Flight_Controller_B.m, Hummingbird_Flight_Controller_B.b_A,
      Hummingbird_Flight_Controller_B.qq_tmp + 1);
    if (Hummingbird_Flight_Controller_B.nrm > 0.0) {
      apply_transform = true;
      if (Hummingbird_Flight_Controller_B.b_A[Hummingbird_Flight_Controller_B.qq_tmp]
          < 0.0) {
        Hummingbird_Flight_Controller_B.nrm =
          -Hummingbird_Flight_Controller_B.nrm;
      }

      Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.m] =
        Hummingbird_Flight_Controller_B.nrm;
      if (fabs(Hummingbird_Flight_Controller_B.nrm) >= 1.0020841800044864E-292)
      {
        Hummingbird_Flight_Controller_B.nrm = 1.0 /
          Hummingbird_Flight_Controller_B.nrm;
        Hummingbird_Flight_Controller_B.qjj =
          (Hummingbird_Flight_Controller_B.qq_tmp -
           Hummingbird_Flight_Controller_B.m) + 3;
        for (Hummingbird_Flight_Controller_B.e_k =
             Hummingbird_Flight_Controller_B.qq;
             Hummingbird_Flight_Controller_B.e_k <=
             Hummingbird_Flight_Controller_B.qjj;
             Hummingbird_Flight_Controller_B.e_k++) {
          Hummingbird_Flight_Controller_B.b_A[Hummingbird_Flight_Controller_B.e_k
            - 1] *= Hummingbird_Flight_Controller_B.nrm;
        }
      } else {
        Hummingbird_Flight_Controller_B.qjj =
          (Hummingbird_Flight_Controller_B.qq_tmp -
           Hummingbird_Flight_Controller_B.m) + 3;
        for (Hummingbird_Flight_Controller_B.e_k =
             Hummingbird_Flight_Controller_B.qq;
             Hummingbird_Flight_Controller_B.e_k <=
             Hummingbird_Flight_Controller_B.qjj;
             Hummingbird_Flight_Controller_B.e_k++) {
          Hummingbird_Flight_Controller_B.b_A[Hummingbird_Flight_Controller_B.e_k
            - 1] /=
            Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.m];
        }
      }

      Hummingbird_Flight_Controller_B.b_A[Hummingbird_Flight_Controller_B.qq_tmp]
        ++;
      Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.m] =
        -Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.m];
    } else {
      Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.m] = 0.0;
    }

    for (Hummingbird_Flight_Controller_B.qq =
         Hummingbird_Flight_Controller_B.qp1; Hummingbird_Flight_Controller_B.qq
         < 4; Hummingbird_Flight_Controller_B.qq++) {
      Hummingbird_Flight_Controller_B.qjj = (Hummingbird_Flight_Controller_B.qq
        - 1) * 3 + Hummingbird_Flight_Controller_B.m;
      if (apply_transform) {
        Hummingbird_Flight_Contro_xaxpy(3 - Hummingbird_Flight_Controller_B.m,
          -(Hummingbird_Flight_Contro_xdotc(3 -
          Hummingbird_Flight_Controller_B.m, Hummingbird_Flight_Controller_B.b_A,
          Hummingbird_Flight_Controller_B.qq_tmp + 1,
          Hummingbird_Flight_Controller_B.b_A,
          Hummingbird_Flight_Controller_B.qjj + 1) /
            Hummingbird_Flight_Controller_B.b_A[Hummingbird_Flight_Controller_B.qq_tmp]),
          Hummingbird_Flight_Controller_B.qq_tmp + 1,
          Hummingbird_Flight_Controller_B.b_A,
          Hummingbird_Flight_Controller_B.qjj + 1);
      }

      Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.qq - 1] =
        Hummingbird_Flight_Controller_B.b_A[Hummingbird_Flight_Controller_B.qjj];
    }

    if (Hummingbird_Flight_Controller_B.m <= 0) {
      Hummingbird_Flight_Controller_B.nrm = Hummingbird_Flight_Cont_xnrm2_b(2,
        Hummingbird_Flight_Controller_B.e, 2);
      if (Hummingbird_Flight_Controller_B.nrm == 0.0) {
        Hummingbird_Flight_Controller_B.e[0] = 0.0;
      } else {
        if (Hummingbird_Flight_Controller_B.e[1] < 0.0) {
          Hummingbird_Flight_Controller_B.e[0] =
            -Hummingbird_Flight_Controller_B.nrm;
        } else {
          Hummingbird_Flight_Controller_B.e[0] =
            Hummingbird_Flight_Controller_B.nrm;
        }

        Hummingbird_Flight_Controller_B.nrm = Hummingbird_Flight_Controller_B.e
          [0];
        if (fabs(Hummingbird_Flight_Controller_B.e[0]) >=
            1.0020841800044864E-292) {
          Hummingbird_Flight_Controller_B.nrm = 1.0 /
            Hummingbird_Flight_Controller_B.e[0];
          for (Hummingbird_Flight_Controller_B.qq_tmp =
               Hummingbird_Flight_Controller_B.qp1;
               Hummingbird_Flight_Controller_B.qq_tmp < 4;
               Hummingbird_Flight_Controller_B.qq_tmp++) {
            Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.qq_tmp
              - 1] *= Hummingbird_Flight_Controller_B.nrm;
          }
        } else {
          for (Hummingbird_Flight_Controller_B.qq_tmp =
               Hummingbird_Flight_Controller_B.qp1;
               Hummingbird_Flight_Controller_B.qq_tmp < 4;
               Hummingbird_Flight_Controller_B.qq_tmp++) {
            Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.qq_tmp
              - 1] /= Hummingbird_Flight_Controller_B.nrm;
          }
        }

        Hummingbird_Flight_Controller_B.e[1]++;
        Hummingbird_Flight_Controller_B.e[0] =
          -Hummingbird_Flight_Controller_B.e[0];
        for (Hummingbird_Flight_Controller_B.qq_tmp =
             Hummingbird_Flight_Controller_B.qp1;
             Hummingbird_Flight_Controller_B.qq_tmp < 4;
             Hummingbird_Flight_Controller_B.qq_tmp++) {
          Hummingbird_Flight_Controller_B.work[Hummingbird_Flight_Controller_B.qq_tmp
            - 1] = 0.0;
        }

        for (Hummingbird_Flight_Controller_B.qq_tmp =
             Hummingbird_Flight_Controller_B.qp1;
             Hummingbird_Flight_Controller_B.qq_tmp < 4;
             Hummingbird_Flight_Controller_B.qq_tmp++) {
          Hummingbird_Flight_Cont_xaxpy_l(2,
            Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.qq_tmp
            - 1], Hummingbird_Flight_Controller_B.b_A, 3 *
            (Hummingbird_Flight_Controller_B.qq_tmp - 1) + 2,
            Hummingbird_Flight_Controller_B.work, 2);
        }

        for (Hummingbird_Flight_Controller_B.qq_tmp =
             Hummingbird_Flight_Controller_B.qp1;
             Hummingbird_Flight_Controller_B.qq_tmp < 4;
             Hummingbird_Flight_Controller_B.qq_tmp++) {
          Hummingbird_Flight_Con_xaxpy_lx(2,
            -Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.qq_tmp
            - 1] / Hummingbird_Flight_Controller_B.e[1],
            Hummingbird_Flight_Controller_B.work, 2,
            Hummingbird_Flight_Controller_B.b_A, 3 *
            (Hummingbird_Flight_Controller_B.qq_tmp - 1) + 2);
        }
      }
    }
  }

  Hummingbird_Flight_Controller_B.m = 1;
  Hummingbird_Flight_Controller_B.s[2] = Hummingbird_Flight_Controller_B.b_A[8];
  Hummingbird_Flight_Controller_B.e[1] = Hummingbird_Flight_Controller_B.b_A[7];
  Hummingbird_Flight_Controller_B.e[2] = 0.0;
  Hummingbird_Flight_Controller_B.qp1 = 0;
  Hummingbird_Flight_Controller_B.ztest0 = Hummingbird_Flight_Controller_B.s[0];
  if (Hummingbird_Flight_Controller_B.s[0] != 0.0) {
    Hummingbird_Flight_Controller_B.rt = fabs(Hummingbird_Flight_Controller_B.s
      [0]);
    Hummingbird_Flight_Controller_B.r_g = Hummingbird_Flight_Controller_B.s[0] /
      Hummingbird_Flight_Controller_B.rt;
    Hummingbird_Flight_Controller_B.ztest0 = Hummingbird_Flight_Controller_B.rt;
    Hummingbird_Flight_Controller_B.s[0] = Hummingbird_Flight_Controller_B.rt;
    Hummingbird_Flight_Controller_B.e[0] /= Hummingbird_Flight_Controller_B.r_g;
  }

  if (Hummingbird_Flight_Controller_B.e[0] != 0.0) {
    Hummingbird_Flight_Controller_B.rt = fabs(Hummingbird_Flight_Controller_B.e
      [0]);
    Hummingbird_Flight_Controller_B.r_g = Hummingbird_Flight_Controller_B.rt /
      Hummingbird_Flight_Controller_B.e[0];
    Hummingbird_Flight_Controller_B.e[0] = Hummingbird_Flight_Controller_B.rt;
    Hummingbird_Flight_Controller_B.s[1] *= Hummingbird_Flight_Controller_B.r_g;
  }

  if ((Hummingbird_Flight_Controller_B.ztest0 >=
       Hummingbird_Flight_Controller_B.e[0]) || rtIsNaN
      (Hummingbird_Flight_Controller_B.e[0])) {
    Hummingbird_Flight_Controller_B.nrm = Hummingbird_Flight_Controller_B.ztest0;
  } else {
    Hummingbird_Flight_Controller_B.nrm = Hummingbird_Flight_Controller_B.e[0];
  }

  Hummingbird_Flight_Controller_B.ztest0 = Hummingbird_Flight_Controller_B.s[1];
  if (Hummingbird_Flight_Controller_B.s[1] != 0.0) {
    Hummingbird_Flight_Controller_B.rt = fabs(Hummingbird_Flight_Controller_B.s
      [1]);
    Hummingbird_Flight_Controller_B.r_g = Hummingbird_Flight_Controller_B.s[1] /
      Hummingbird_Flight_Controller_B.rt;
    Hummingbird_Flight_Controller_B.ztest0 = Hummingbird_Flight_Controller_B.rt;
    Hummingbird_Flight_Controller_B.s[1] = Hummingbird_Flight_Controller_B.rt;
    Hummingbird_Flight_Controller_B.e[1] = Hummingbird_Flight_Controller_B.b_A[7]
      / Hummingbird_Flight_Controller_B.r_g;
  }

  if (Hummingbird_Flight_Controller_B.e[1] != 0.0) {
    Hummingbird_Flight_Controller_B.rt = fabs(Hummingbird_Flight_Controller_B.e
      [1]);
    Hummingbird_Flight_Controller_B.r_g = Hummingbird_Flight_Controller_B.rt /
      Hummingbird_Flight_Controller_B.e[1];
    Hummingbird_Flight_Controller_B.e[1] = Hummingbird_Flight_Controller_B.rt;
    Hummingbird_Flight_Controller_B.s[2] = Hummingbird_Flight_Controller_B.b_A[8]
      * Hummingbird_Flight_Controller_B.r_g;
  }

  if ((!(Hummingbird_Flight_Controller_B.ztest0 >=
         Hummingbird_Flight_Controller_B.e[1])) && (!rtIsNaN
       (Hummingbird_Flight_Controller_B.e[1]))) {
    Hummingbird_Flight_Controller_B.ztest0 = Hummingbird_Flight_Controller_B.e[1];
  }

  if ((!(Hummingbird_Flight_Controller_B.nrm >=
         Hummingbird_Flight_Controller_B.ztest0)) && (!rtIsNaN
       (Hummingbird_Flight_Controller_B.ztest0))) {
    Hummingbird_Flight_Controller_B.nrm = Hummingbird_Flight_Controller_B.ztest0;
  }

  Hummingbird_Flight_Controller_B.ztest0 = Hummingbird_Flight_Controller_B.s[2];
  if (Hummingbird_Flight_Controller_B.s[2] != 0.0) {
    Hummingbird_Flight_Controller_B.rt = fabs(Hummingbird_Flight_Controller_B.s
      [2]);
    Hummingbird_Flight_Controller_B.ztest0 = Hummingbird_Flight_Controller_B.rt;
    Hummingbird_Flight_Controller_B.s[2] = Hummingbird_Flight_Controller_B.rt;
  }

  if (!(Hummingbird_Flight_Controller_B.ztest0 >= 0.0)) {
    Hummingbird_Flight_Controller_B.ztest0 = 0.0;
  }

  if (!(Hummingbird_Flight_Controller_B.nrm >=
        Hummingbird_Flight_Controller_B.ztest0)) {
    Hummingbird_Flight_Controller_B.nrm = Hummingbird_Flight_Controller_B.ztest0;
  }

  while ((Hummingbird_Flight_Controller_B.m + 2 > 0) &&
         (Hummingbird_Flight_Controller_B.qp1 < 75)) {
    Hummingbird_Flight_Controller_B.qq_tmp = Hummingbird_Flight_Controller_B.m +
      1;
    exitg1 = false;
    while (!(exitg1 || (Hummingbird_Flight_Controller_B.qq_tmp == 0))) {
      Hummingbird_Flight_Controller_B.ztest0 = fabs
        (Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.qq_tmp
         - 1]);
      if (Hummingbird_Flight_Controller_B.ztest0 <= (fabs
           (Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qq_tmp
            - 1]) + fabs
           (Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qq_tmp]))
          * 2.2204460492503131E-16) {
        Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.qq_tmp
          - 1] = 0.0;
        exitg1 = true;
      } else if ((Hummingbird_Flight_Controller_B.ztest0 <=
                  1.0020841800044864E-292) ||
                 ((Hummingbird_Flight_Controller_B.qp1 > 20) &&
                  (Hummingbird_Flight_Controller_B.ztest0 <=
                   2.2204460492503131E-16 * Hummingbird_Flight_Controller_B.nrm)))
      {
        Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.qq_tmp
          - 1] = 0.0;
        exitg1 = true;
      } else {
        Hummingbird_Flight_Controller_B.qq_tmp--;
      }
    }

    if (Hummingbird_Flight_Controller_B.m + 1 ==
        Hummingbird_Flight_Controller_B.qq_tmp) {
      Hummingbird_Flight_Controller_B.qjj = 4;
    } else {
      Hummingbird_Flight_Controller_B.qq = Hummingbird_Flight_Controller_B.m + 2;
      Hummingbird_Flight_Controller_B.qjj = Hummingbird_Flight_Controller_B.m +
        2;
      exitg1 = false;
      while ((!exitg1) && (Hummingbird_Flight_Controller_B.qjj >=
                           Hummingbird_Flight_Controller_B.qq_tmp)) {
        Hummingbird_Flight_Controller_B.qq = Hummingbird_Flight_Controller_B.qjj;
        if (Hummingbird_Flight_Controller_B.qjj ==
            Hummingbird_Flight_Controller_B.qq_tmp) {
          exitg1 = true;
        } else {
          Hummingbird_Flight_Controller_B.ztest0 = 0.0;
          if (Hummingbird_Flight_Controller_B.qjj <
              Hummingbird_Flight_Controller_B.m + 2) {
            Hummingbird_Flight_Controller_B.ztest0 = fabs
              (Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.qjj
               - 1]);
          }

          if (Hummingbird_Flight_Controller_B.qjj >
              Hummingbird_Flight_Controller_B.qq_tmp + 1) {
            Hummingbird_Flight_Controller_B.ztest0 += fabs
              (Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.qjj
               - 2]);
          }

          Hummingbird_Flight_Controller_B.rt = fabs
            (Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qjj
             - 1]);
          if ((Hummingbird_Flight_Controller_B.rt <= 2.2204460492503131E-16 *
               Hummingbird_Flight_Controller_B.ztest0) ||
              (Hummingbird_Flight_Controller_B.rt <= 1.0020841800044864E-292)) {
            Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qjj
              - 1] = 0.0;
            exitg1 = true;
          } else {
            Hummingbird_Flight_Controller_B.qjj--;
          }
        }
      }

      if (Hummingbird_Flight_Controller_B.qq ==
          Hummingbird_Flight_Controller_B.qq_tmp) {
        Hummingbird_Flight_Controller_B.qjj = 3;
      } else if (Hummingbird_Flight_Controller_B.m + 2 ==
                 Hummingbird_Flight_Controller_B.qq) {
        Hummingbird_Flight_Controller_B.qjj = 1;
      } else {
        Hummingbird_Flight_Controller_B.qjj = 2;
        Hummingbird_Flight_Controller_B.qq_tmp =
          Hummingbird_Flight_Controller_B.qq;
      }
    }

    switch (Hummingbird_Flight_Controller_B.qjj) {
     case 1:
      Hummingbird_Flight_Controller_B.ztest0 =
        Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.m];
      Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.m] = 0.0;
      for (Hummingbird_Flight_Controller_B.qq =
           Hummingbird_Flight_Controller_B.m + 1;
           Hummingbird_Flight_Controller_B.qq >=
           Hummingbird_Flight_Controller_B.qq_tmp + 1;
           Hummingbird_Flight_Controller_B.qq--) {
        Hummingbird_Flight_Contro_xrotg
          (&Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qq
           - 1], &Hummingbird_Flight_Controller_B.ztest0,
           &Hummingbird_Flight_Controller_B.rt,
           &Hummingbird_Flight_Controller_B.r_g);
        if (Hummingbird_Flight_Controller_B.qq >
            Hummingbird_Flight_Controller_B.qq_tmp + 1) {
          Hummingbird_Flight_Controller_B.ztest0 =
            -Hummingbird_Flight_Controller_B.r_g *
            Hummingbird_Flight_Controller_B.e[0];
          Hummingbird_Flight_Controller_B.e[0] *=
            Hummingbird_Flight_Controller_B.rt;
        }
      }
      break;

     case 2:
      Hummingbird_Flight_Controller_B.ztest0 =
        Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.qq_tmp
        - 1];
      Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.qq_tmp -
        1] = 0.0;
      for (Hummingbird_Flight_Controller_B.qq =
           Hummingbird_Flight_Controller_B.qq_tmp + 1;
           Hummingbird_Flight_Controller_B.qq <=
           Hummingbird_Flight_Controller_B.m + 2;
           Hummingbird_Flight_Controller_B.qq++) {
        Hummingbird_Flight_Contro_xrotg
          (&Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qq
           - 1], &Hummingbird_Flight_Controller_B.ztest0,
           &Hummingbird_Flight_Controller_B.rt,
           &Hummingbird_Flight_Controller_B.r_g);
        Hummingbird_Flight_Controller_B.smm1 =
          Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.qq -
          1];
        Hummingbird_Flight_Controller_B.ztest0 =
          -Hummingbird_Flight_Controller_B.r_g *
          Hummingbird_Flight_Controller_B.smm1;
        Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.qq - 1]
          = Hummingbird_Flight_Controller_B.smm1 *
          Hummingbird_Flight_Controller_B.rt;
      }
      break;

     case 3:
      Hummingbird_Flight_Controller_B.ztest0 =
        Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.m + 1];
      Hummingbird_Flight_Controller_B.rt = fabs
        (Hummingbird_Flight_Controller_B.ztest0);
      Hummingbird_Flight_Controller_B.r_g = fabs
        (Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.m]);
      if ((Hummingbird_Flight_Controller_B.rt >=
           Hummingbird_Flight_Controller_B.r_g) || rtIsNaN
          (Hummingbird_Flight_Controller_B.r_g)) {
        Hummingbird_Flight_Controller_B.r_g = Hummingbird_Flight_Controller_B.rt;
      }

      Hummingbird_Flight_Controller_B.rt = fabs
        (Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.m]);
      if ((Hummingbird_Flight_Controller_B.r_g >=
           Hummingbird_Flight_Controller_B.rt) || rtIsNaN
          (Hummingbird_Flight_Controller_B.rt)) {
        Hummingbird_Flight_Controller_B.rt = Hummingbird_Flight_Controller_B.r_g;
      }

      Hummingbird_Flight_Controller_B.r_g = fabs
        (Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qq_tmp]);
      if ((Hummingbird_Flight_Controller_B.rt >=
           Hummingbird_Flight_Controller_B.r_g) || rtIsNaN
          (Hummingbird_Flight_Controller_B.r_g)) {
        Hummingbird_Flight_Controller_B.r_g = Hummingbird_Flight_Controller_B.rt;
      }

      Hummingbird_Flight_Controller_B.rt = fabs
        (Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.qq_tmp]);
      if ((Hummingbird_Flight_Controller_B.r_g >=
           Hummingbird_Flight_Controller_B.rt) || rtIsNaN
          (Hummingbird_Flight_Controller_B.rt)) {
        Hummingbird_Flight_Controller_B.rt = Hummingbird_Flight_Controller_B.r_g;
      }

      Hummingbird_Flight_Controller_B.ztest0 /=
        Hummingbird_Flight_Controller_B.rt;
      Hummingbird_Flight_Controller_B.smm1 =
        Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.m] /
        Hummingbird_Flight_Controller_B.rt;
      Hummingbird_Flight_Controller_B.emm1 =
        Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.m] /
        Hummingbird_Flight_Controller_B.rt;
      Hummingbird_Flight_Controller_B.r_g =
        Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qq_tmp]
        / Hummingbird_Flight_Controller_B.rt;
      Hummingbird_Flight_Controller_B.smm1 =
        ((Hummingbird_Flight_Controller_B.smm1 +
          Hummingbird_Flight_Controller_B.ztest0) *
         (Hummingbird_Flight_Controller_B.smm1 -
          Hummingbird_Flight_Controller_B.ztest0) +
         Hummingbird_Flight_Controller_B.emm1 *
         Hummingbird_Flight_Controller_B.emm1) / 2.0;
      Hummingbird_Flight_Controller_B.emm1 *=
        Hummingbird_Flight_Controller_B.ztest0;
      Hummingbird_Flight_Controller_B.emm1 *=
        Hummingbird_Flight_Controller_B.emm1;
      if ((Hummingbird_Flight_Controller_B.smm1 != 0.0) ||
          (Hummingbird_Flight_Controller_B.emm1 != 0.0)) {
        Hummingbird_Flight_Controller_B.shift = sqrt
          (Hummingbird_Flight_Controller_B.smm1 *
           Hummingbird_Flight_Controller_B.smm1 +
           Hummingbird_Flight_Controller_B.emm1);
        if (Hummingbird_Flight_Controller_B.smm1 < 0.0) {
          Hummingbird_Flight_Controller_B.shift =
            -Hummingbird_Flight_Controller_B.shift;
        }

        Hummingbird_Flight_Controller_B.shift =
          Hummingbird_Flight_Controller_B.emm1 /
          (Hummingbird_Flight_Controller_B.smm1 +
           Hummingbird_Flight_Controller_B.shift);
      } else {
        Hummingbird_Flight_Controller_B.shift = 0.0;
      }

      Hummingbird_Flight_Controller_B.ztest0 =
        (Hummingbird_Flight_Controller_B.r_g +
         Hummingbird_Flight_Controller_B.ztest0) *
        (Hummingbird_Flight_Controller_B.r_g -
         Hummingbird_Flight_Controller_B.ztest0) +
        Hummingbird_Flight_Controller_B.shift;
      Hummingbird_Flight_Controller_B.rt =
        Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.qq_tmp]
        / Hummingbird_Flight_Controller_B.rt *
        Hummingbird_Flight_Controller_B.r_g;
      for (Hummingbird_Flight_Controller_B.qq =
           Hummingbird_Flight_Controller_B.qq_tmp + 1;
           Hummingbird_Flight_Controller_B.qq <=
           Hummingbird_Flight_Controller_B.m + 1;
           Hummingbird_Flight_Controller_B.qq++) {
        Hummingbird_Flight_Contro_xrotg(&Hummingbird_Flight_Controller_B.ztest0,
          &Hummingbird_Flight_Controller_B.rt,
          &Hummingbird_Flight_Controller_B.r_g,
          &Hummingbird_Flight_Controller_B.smm1);
        if (Hummingbird_Flight_Controller_B.qq >
            Hummingbird_Flight_Controller_B.qq_tmp + 1) {
          Hummingbird_Flight_Controller_B.e[0] =
            Hummingbird_Flight_Controller_B.ztest0;
        }

        Hummingbird_Flight_Controller_B.rt =
          Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.qq -
          1];
        Hummingbird_Flight_Controller_B.emm1 =
          Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qq -
          1];
        Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.qq - 1]
          = Hummingbird_Flight_Controller_B.rt *
          Hummingbird_Flight_Controller_B.r_g -
          Hummingbird_Flight_Controller_B.emm1 *
          Hummingbird_Flight_Controller_B.smm1;
        Hummingbird_Flight_Controller_B.ztest0 =
          Hummingbird_Flight_Controller_B.smm1 *
          Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qq];
        Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qq] *=
          Hummingbird_Flight_Controller_B.r_g;
        Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qq - 1]
          = Hummingbird_Flight_Controller_B.emm1 *
          Hummingbird_Flight_Controller_B.r_g +
          Hummingbird_Flight_Controller_B.rt *
          Hummingbird_Flight_Controller_B.smm1;
        Hummingbird_Flight_Contro_xrotg
          (&Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qq
           - 1], &Hummingbird_Flight_Controller_B.ztest0,
           &Hummingbird_Flight_Controller_B.r_g,
           &Hummingbird_Flight_Controller_B.smm1);
        Hummingbird_Flight_Controller_B.rt =
          Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.qq -
          1];
        Hummingbird_Flight_Controller_B.ztest0 =
          Hummingbird_Flight_Controller_B.rt *
          Hummingbird_Flight_Controller_B.r_g +
          Hummingbird_Flight_Controller_B.smm1 *
          Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qq];
        Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qq] =
          Hummingbird_Flight_Controller_B.rt *
          -Hummingbird_Flight_Controller_B.smm1 +
          Hummingbird_Flight_Controller_B.r_g *
          Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qq];
        Hummingbird_Flight_Controller_B.rt =
          Hummingbird_Flight_Controller_B.smm1 *
          Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.qq];
        Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.qq] *=
          Hummingbird_Flight_Controller_B.r_g;
      }

      Hummingbird_Flight_Controller_B.e[Hummingbird_Flight_Controller_B.m] =
        Hummingbird_Flight_Controller_B.ztest0;
      Hummingbird_Flight_Controller_B.qp1++;
      break;

     default:
      if (Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qq_tmp]
          < 0.0) {
        Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qq_tmp]
          =
          -Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qq_tmp];
      }

      Hummingbird_Flight_Controller_B.qp1 =
        Hummingbird_Flight_Controller_B.qq_tmp + 1;
      while ((Hummingbird_Flight_Controller_B.qq_tmp + 1 < 3) &&
             (Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qq_tmp]
              <
              Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qp1]))
      {
        Hummingbird_Flight_Controller_B.rt =
          Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qq_tmp];
        Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qq_tmp]
          =
          Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qp1];
        Hummingbird_Flight_Controller_B.s[Hummingbird_Flight_Controller_B.qp1] =
          Hummingbird_Flight_Controller_B.rt;
        Hummingbird_Flight_Controller_B.qq_tmp =
          Hummingbird_Flight_Controller_B.qp1;
        Hummingbird_Flight_Controller_B.qp1++;
      }

      Hummingbird_Flight_Controller_B.qp1 = 0;
      Hummingbird_Flight_Controller_B.m--;
      break;
    }
  }

  U[0] = Hummingbird_Flight_Controller_B.s[0];
  U[1] = Hummingbird_Flight_Controller_B.s[1];
  U[2] = Hummingbird_Flight_Controller_B.s[2];
  if (doscale) {
    Hummingbird_Flight_Co_xzlascl_o(Hummingbird_Flight_Controller_B.cscale,
      Hummingbird_Flight_Controller_B.anrm, 3, 1, U, 1, 3);
  }
}

// Function for MATLAB Function: '<S14>/MATLAB Function1'
static void Hummingbird_Flight_Co_lla2ned_f(const real_T lla[3], const real_T
  lla0[3], real_T xyzNED[3])
{
  int8_T n;
  boolean_T exitg1;
  boolean_T latp2;
  Hummingbird_Flight_Controller_B.dLat = lla[0] - lla0[0];
  Hummingbird_Flight_Controller_B.dLon = lla[1] - lla0[1];
  Hummingbird_Flight_Controller_B.flat = fabs
    (Hummingbird_Flight_Controller_B.dLat);
  if (Hummingbird_Flight_Controller_B.flat > 180.0) {
    if (rtIsNaN(Hummingbird_Flight_Controller_B.dLat + 180.0)) {
      Hummingbird_Flight_Controller_B.flat = (rtNaN);
    } else if (rtIsInf(Hummingbird_Flight_Controller_B.dLat + 180.0)) {
      Hummingbird_Flight_Controller_B.flat = (rtNaN);
    } else {
      Hummingbird_Flight_Controller_B.flat = fmod
        (Hummingbird_Flight_Controller_B.dLat + 180.0, 360.0);
      if (Hummingbird_Flight_Controller_B.flat == 0.0) {
        Hummingbird_Flight_Controller_B.flat = 0.0;
      } else if (Hummingbird_Flight_Controller_B.flat < 0.0) {
        Hummingbird_Flight_Controller_B.flat += 360.0;
      }
    }

    Hummingbird_Flight_Controller_B.dLat = Hummingbird_Flight_Controller_B.dLat *
      0.0 + (Hummingbird_Flight_Controller_B.flat - 180.0);
    Hummingbird_Flight_Controller_B.flat = fabs
      (Hummingbird_Flight_Controller_B.dLat);
  }

  if (Hummingbird_Flight_Controller_B.flat > 90.0) {
    Hummingbird_Flight_Controller_B.flat = fabs
      (Hummingbird_Flight_Controller_B.dLat);
    latp2 = (Hummingbird_Flight_Controller_B.flat > 90.0);
    Hummingbird_Flight_Controller_B.dLon += 180.0;
    Hummingbird_Flight_Controller_B.absx_l =
      Hummingbird_Flight_Controller_B.dLat * static_cast<real_T>(latp2);
    if (rtIsNaN(Hummingbird_Flight_Controller_B.absx_l)) {
      Hummingbird_Flight_Controller_B.absx_l = (rtNaN);
    } else if (Hummingbird_Flight_Controller_B.absx_l < 0.0) {
      Hummingbird_Flight_Controller_B.absx_l = -1.0;
    } else {
      Hummingbird_Flight_Controller_B.absx_l =
        (Hummingbird_Flight_Controller_B.absx_l > 0.0);
    }

    Hummingbird_Flight_Controller_B.dLat = (90.0 -
      (Hummingbird_Flight_Controller_B.flat * static_cast<real_T>(latp2) - 90.0))
      * Hummingbird_Flight_Controller_B.absx_l * static_cast<real_T>(latp2) +
      Hummingbird_Flight_Controller_B.dLat * static_cast<real_T>(!latp2);
  }

  if ((Hummingbird_Flight_Controller_B.dLon > 180.0) ||
      (Hummingbird_Flight_Controller_B.dLon < -180.0)) {
    Hummingbird_Flight_Controller_B.flat = Hummingbird_Flight__rt_remd_snf
      (Hummingbird_Flight_Controller_B.dLon, 360.0);
    Hummingbird_Flight_Controller_B.absx_l =
      Hummingbird_Flight_Controller_B.flat / 180.0;
    if (Hummingbird_Flight_Controller_B.absx_l < 0.0) {
      Hummingbird_Flight_Controller_B.absx_l = ceil
        (Hummingbird_Flight_Controller_B.absx_l);
    } else {
      Hummingbird_Flight_Controller_B.absx_l = floor
        (Hummingbird_Flight_Controller_B.absx_l);
    }

    Hummingbird_Flight_Controller_B.dLon = (Hummingbird_Flight_Controller_B.flat
      - 360.0 * Hummingbird_Flight_Controller_B.absx_l) +
      Hummingbird_Flight_Controller_B.dLon * 0.0;
  }

  Hummingbird_Flight_Controller_B.flat = lla0[0];
  Hummingbird_Flight_Control_sind(&Hummingbird_Flight_Controller_B.flat);
  Hummingbird_Flight_Controller_B.flat = 6.378137E+6 / sqrt(1.0 -
    0.0066943799901413165 * Hummingbird_Flight_Controller_B.flat *
    Hummingbird_Flight_Controller_B.flat);
  Hummingbird_Flight_Controller_B.absx_l = lla0[0];
  Hummingbird_Flight_Control_sind(&Hummingbird_Flight_Controller_B.absx_l);
  Hummingbird_Flight_Controller_B.g = lla0[0];
  Hummingbird_Flight_Control_sind(&Hummingbird_Flight_Controller_B.g);
  xyzNED[0] = Hummingbird_Flight_Controller_B.dLat /
    (Hummingbird_Fligh_rt_atan2d_snf(1.0, 0.99330562000985867 / (1.0 -
       0.0066943799901413165 * Hummingbird_Flight_Controller_B.absx_l *
       Hummingbird_Flight_Controller_B.g) * Hummingbird_Flight_Controller_B.flat)
     * 57.295779513082323);
  if (rtIsInf(lla0[0]) || rtIsNaN(lla0[0])) {
    Hummingbird_Flight_Controller_B.dLat = (rtNaN);
  } else {
    Hummingbird_Flight_Controller_B.dLat = Hummingbird_Flight__rt_remd_snf(lla0
      [0], 360.0);
    Hummingbird_Flight_Controller_B.absx_l = fabs
      (Hummingbird_Flight_Controller_B.dLat);
    if (Hummingbird_Flight_Controller_B.absx_l > 180.0) {
      if (Hummingbird_Flight_Controller_B.dLat > 0.0) {
        Hummingbird_Flight_Controller_B.dLat -= 360.0;
      } else {
        Hummingbird_Flight_Controller_B.dLat += 360.0;
      }

      Hummingbird_Flight_Controller_B.absx_l = fabs
        (Hummingbird_Flight_Controller_B.dLat);
    }

    if (Hummingbird_Flight_Controller_B.absx_l <= 45.0) {
      Hummingbird_Flight_Controller_B.dLat *= 0.017453292519943295;
      n = 0;
    } else if (Hummingbird_Flight_Controller_B.absx_l <= 135.0) {
      if (Hummingbird_Flight_Controller_B.dLat > 0.0) {
        Hummingbird_Flight_Controller_B.dLat =
          (Hummingbird_Flight_Controller_B.dLat - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        Hummingbird_Flight_Controller_B.dLat =
          (Hummingbird_Flight_Controller_B.dLat + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (Hummingbird_Flight_Controller_B.dLat > 0.0) {
      Hummingbird_Flight_Controller_B.dLat =
        (Hummingbird_Flight_Controller_B.dLat - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      Hummingbird_Flight_Controller_B.dLat =
        (Hummingbird_Flight_Controller_B.dLat + 180.0) * 0.017453292519943295;
      n = -2;
    }

    switch (n) {
     case 0:
      Hummingbird_Flight_Controller_B.dLat = cos
        (Hummingbird_Flight_Controller_B.dLat);
      break;

     case 1:
      Hummingbird_Flight_Controller_B.dLat = -sin
        (Hummingbird_Flight_Controller_B.dLat);
      break;

     case -1:
      Hummingbird_Flight_Controller_B.dLat = sin
        (Hummingbird_Flight_Controller_B.dLat);
      break;

     default:
      Hummingbird_Flight_Controller_B.dLat = -cos
        (Hummingbird_Flight_Controller_B.dLat);
      break;
    }
  }

  xyzNED[1] = Hummingbird_Flight_Controller_B.dLon /
    (Hummingbird_Fligh_rt_atan2d_snf(1.0, Hummingbird_Flight_Controller_B.flat *
      Hummingbird_Flight_Controller_B.dLat) * 57.295779513082323);
  xyzNED[2] = -lla[2] + lla0[2];
  Hummingbird_Flight_Controller_B.c_x[0] = rtIsNaN(xyzNED[0]);
  Hummingbird_Flight_Controller_B.c_x[1] = rtIsNaN(xyzNED[1]);
  Hummingbird_Flight_Controller_B.c_x[2] = rtIsNaN(xyzNED[2]);
  latp2 = false;
  Hummingbird_Flight_Controller_B.k = 0;
  exitg1 = false;
  while ((!exitg1) && (Hummingbird_Flight_Controller_B.k < 3)) {
    if (Hummingbird_Flight_Controller_B.c_x[Hummingbird_Flight_Controller_B.k])
    {
      latp2 = true;
      exitg1 = true;
    } else {
      Hummingbird_Flight_Controller_B.k++;
    }
  }

  Hummingbird_Flight_Controller_B.dLon = 0.0 / static_cast<real_T>(!latp2);
  xyzNED[0] += Hummingbird_Flight_Controller_B.dLon;
  xyzNED[1] += Hummingbird_Flight_Controller_B.dLon;
  xyzNED[2] += Hummingbird_Flight_Controller_B.dLon;
}

// Function for MATLAB Function: '<S780>/MATLAB Function'
static real_T Hummingbird_Flight_Contr_norm_j(const real_T x[2])
{
  real_T y;
  Hummingbird_Flight_Controller_B.scale_d = 3.3121686421112381E-170;
  Hummingbird_Flight_Controller_B.absxk_e = fabs(x[0]);
  if (Hummingbird_Flight_Controller_B.absxk_e > 3.3121686421112381E-170) {
    y = 1.0;
    Hummingbird_Flight_Controller_B.scale_d =
      Hummingbird_Flight_Controller_B.absxk_e;
  } else {
    Hummingbird_Flight_Controller_B.t_bj =
      Hummingbird_Flight_Controller_B.absxk_e / 3.3121686421112381E-170;
    y = Hummingbird_Flight_Controller_B.t_bj *
      Hummingbird_Flight_Controller_B.t_bj;
  }

  Hummingbird_Flight_Controller_B.absxk_e = fabs(x[1]);
  if (Hummingbird_Flight_Controller_B.absxk_e >
      Hummingbird_Flight_Controller_B.scale_d) {
    Hummingbird_Flight_Controller_B.t_bj =
      Hummingbird_Flight_Controller_B.scale_d /
      Hummingbird_Flight_Controller_B.absxk_e;
    y = y * Hummingbird_Flight_Controller_B.t_bj *
      Hummingbird_Flight_Controller_B.t_bj + 1.0;
    Hummingbird_Flight_Controller_B.scale_d =
      Hummingbird_Flight_Controller_B.absxk_e;
  } else {
    Hummingbird_Flight_Controller_B.t_bj =
      Hummingbird_Flight_Controller_B.absxk_e /
      Hummingbird_Flight_Controller_B.scale_d;
    y += Hummingbird_Flight_Controller_B.t_bj *
      Hummingbird_Flight_Controller_B.t_bj;
  }

  return Hummingbird_Flight_Controller_B.scale_d * sqrt(y);
}

// Function for Chart: '<Root>/Chart'
static void exit_internal_Flight_controller(void)
{
  Hummingbird_Flight_Controlle_DW.is_Flight_controller =
    Hummingbird__IN_NO_ACTIVE_CHILD;
}

static void Hummingb_PX4Actuators_setupImpl(px4_internal_block_PX4Actuato_T *obj)
{
  int32_T n;
  int32_T n_0;
  obj->ValidMotorIdx[0] = true;
  obj->ValidMotorIdx[1] = true;
  obj->ValidMotorIdx[2] = true;
  obj->ValidMotorIdx[3] = true;
  obj->ValidMotorIdx[4] = true;
  obj->ValidMotorIdx[5] = true;
  obj->ValidMotorIdx[6] = true;
  obj->ValidMotorIdx[7] = true;
  obj->ValidServoIdx[0] = true;
  obj->ValidServoIdx[1] = true;
  obj->ValidServoIdx[2] = true;
  obj->ValidServoIdx[3] = true;
  obj->ValidServoIdx[4] = true;
  obj->ValidServoIdx[5] = true;
  obj->ValidServoIdx[6] = true;
  obj->ValidServoIdx[7] = true;
  n = 0;
  for (int32_T b_k = 0; b_k < 12; b_k++) {
    // Start for MATLABSystem: '<Root>/PX4 Actuator Write1'
    if (obj->ValidMotorIdx[b_k]) {
      n++;
    }
  }

  n_0 = 0;
  for (int32_T b_k = 0; b_k < 8; b_k++) {
    // Start for MATLABSystem: '<Root>/PX4 Actuator Write1'
    if (obj->ValidServoIdx[b_k]) {
      n_0++;
    }
  }

  // Start for MATLABSystem: '<Root>/PX4 Actuator Write1'
  obj->QSize = static_cast<uint8_T>(n + n_0);
  MW_actuators_init(obj->QSize);
}

// Model step function for TID0
void Hummingbird_Flight_Controller_Lower_Memory_step0(void) // Sample time: [0.001s, 0.0s] 
{
  boolean_T b_varargout_1;
  static const real_T b_a[9] = { 0.0073818933374696725, 0.0,
    -0.00050005792718292737, 0.0, -0.006204756255817, 0.0, 0.000432458171345293,
    0.0, -0.0026697396905476403 };

  {                                    // Sample time: [0.001s, 0.0s]
    rate_monotonic_scheduler();
  }

  // MATLABSystem: '<S1502>/SourceBlock'
  b_varargout_1 = uORB_read_step
    (Hummingbird_Flight_Controlle_DW.obj_o.orbMetadataObj,
     &Hummingbird_Flight_Controlle_DW.obj_o.eventStructObj,
     &Hummingbird_Flight_Controller_B.r1, false, 1.0);

  // Outputs for Enabled SubSystem: '<S1502>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S1566>/Enable'

  // Start for MATLABSystem: '<S1502>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S1566>/In1'
    Hummingbird_Flight_Controller_B.In1_j = Hummingbird_Flight_Controller_B.r1;
  }

  // End of Outputs for SubSystem: '<S1502>/Enabled Subsystem'

  // DataTypeConversion: '<S5>/Cast To Double2' incorporates:
  //   Gain: '<S5>/Convert to ft2'

  Hummingbird_Flight_Controller_B.CastToDouble25 =
    Hummingbird_Flight_Controller_P.Converttoft2_Gain *
    Hummingbird_Flight_Controller_B.In1_j.y;

  // BusCreator: '<S5>/Bus Creator3' incorporates:
  //   Gain: '<S5>/Convert to ft1'
  //   Gain: '<S5>/Convert to ft3'

  Hummingbird_Flight_Controller_B.b_t =
    Hummingbird_Flight_Controller_P.Converttoft1_Gain *
    Hummingbird_Flight_Controller_B.In1_j.x;
  Hummingbird_Flight_Controller_B.r_c =
    Hummingbird_Flight_Controller_P.Converttoft3_Gain *
    Hummingbird_Flight_Controller_B.In1_j.z;

  // Gain: '<S5>/Convert To ft//s' incorporates:
  //   DataTypeConversion: '<S5>/Data Type Conversion1'

  Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 =
    Hummingbird_Flight_Controller_P.ConvertTofts_Gain *
    Hummingbird_Flight_Controller_B.In1_j.vx;
  Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
    Hummingbird_Flight_Controller_P.ConvertTofts_Gain *
    Hummingbird_Flight_Controller_B.In1_j.vy;
  Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 =
    Hummingbird_Flight_Controller_P.ConvertTofts_Gain *
    Hummingbird_Flight_Controller_B.In1_j.vz;

  // MATLAB Function: '<S5>/MATLAB Function1'
  Hummingbird_Flight_Controller_B.course = Hummingbird_Fligh_rt_atan2d_snf
    (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1,
     Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0);

  // MATLABSystem: '<S1500>/SourceBlock'
  b_varargout_1 = uORB_read_step
    (Hummingbird_Flight_Controlle_DW.obj_k.orbMetadataObj,
     &Hummingbird_Flight_Controlle_DW.obj_k.eventStructObj,
     &Hummingbird_Flight_Controller_B.r5, false, 1.0);

  // Outputs for Enabled SubSystem: '<S1500>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S1564>/Enable'

  // Start for MATLABSystem: '<S1500>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S1564>/In1'
    Hummingbird_Flight_Controller_B.In1_l = Hummingbird_Flight_Controller_B.r5;
  }

  // End of Outputs for SubSystem: '<S1500>/Enabled Subsystem'

  // MATLABSystem: '<S5>/Coordinate Transformation Conversion1' incorporates:
  //   Math: '<S5>/Transpose2'

  Hummingbird_Flight_Controller_B.a_n = 1.0F / static_cast<real32_T>(sqrt(
    static_cast<real_T>(((Hummingbird_Flight_Controller_B.In1_l.q[0] *
    Hummingbird_Flight_Controller_B.In1_l.q[0] +
    Hummingbird_Flight_Controller_B.In1_l.q[1] *
    Hummingbird_Flight_Controller_B.In1_l.q[1]) +
    Hummingbird_Flight_Controller_B.In1_l.q[2] *
    Hummingbird_Flight_Controller_B.In1_l.q[2]) +
                        Hummingbird_Flight_Controller_B.In1_l.q[3] *
                        Hummingbird_Flight_Controller_B.In1_l.q[3])));
  Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0 =
    Hummingbird_Flight_Controller_B.In1_l.q[0] *
    Hummingbird_Flight_Controller_B.a_n;
  Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1 =
    Hummingbird_Flight_Controller_B.In1_l.q[1] *
    Hummingbird_Flight_Controller_B.a_n;
  Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2 =
    Hummingbird_Flight_Controller_B.In1_l.q[2] *
    Hummingbird_Flight_Controller_B.a_n;
  Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3 =
    Hummingbird_Flight_Controller_B.In1_l.q[3] *
    Hummingbird_Flight_Controller_B.a_n;
  Hummingbird_Flight_Controller_B.a_n =
    Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1 *
    Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3 * 2.0F -
    Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0 *
    Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2 * 2.0F;
  if (Hummingbird_Flight_Controller_B.a_n > 1.0F) {
    Hummingbird_Flight_Controller_B.a_n = 1.0F;
  }

  Hummingbird_Flight_Controller_B.ParamStep_i =
    Hummingbird_Flight_Controller_B.a_n;
  if (Hummingbird_Flight_Controller_B.a_n < -1.0F) {
    Hummingbird_Flight_Controller_B.ParamStep_i = -1.0F;
  }

  if ((Hummingbird_Flight_Controller_B.ParamStep_i < 0.0F) && (static_cast<
       real32_T>(fabs(static_cast<real_T>
                      (Hummingbird_Flight_Controller_B.ParamStep_i + 1.0F))) <
       1.1920929E-6F)) {
    Hummingbird_Flight_Controller_B.a_n = -2.0F *
      Hummingbird_Fligh_rt_atan2f_snf
      (Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1,
       Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0);
    Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0 = 0.0F;
    Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1 = 1.57079637F;
  } else if ((Hummingbird_Flight_Controller_B.ParamStep_i > 0.0F) && (
              static_cast<real32_T>(fabs(static_cast<real_T>
                (Hummingbird_Flight_Controller_B.ParamStep_i - 1.0F))) <
              1.1920929E-6F)) {
    Hummingbird_Flight_Controller_B.a_n = 2.0F * Hummingbird_Fligh_rt_atan2f_snf
      (Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1,
       Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0);
    Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0 = 0.0F;
    Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1 = -1.57079637F;
  } else {
    Hummingbird_Flight_Controller_B.ParamStep =
      Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0 *
      Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0 * 2.0F - 1.0F;
    Hummingbird_Flight_Controller_B.a_n = Hummingbird_Fligh_rt_atan2f_snf
      (Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0 *
       Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3 * 2.0F +
       Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1 *
       Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2 * 2.0F,
       Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1 *
       Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1 * 2.0F +
       Hummingbird_Flight_Controller_B.ParamStep);
    Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0 =
      Hummingbird_Fligh_rt_atan2f_snf
      (Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0 *
       Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1 * 2.0F +
       Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2 *
       Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3 * 2.0F,
       Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3 *
       Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3 * 2.0F +
       Hummingbird_Flight_Controller_B.ParamStep);
    Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1 =
      -static_cast<real32_T>(asin(static_cast<real_T>
      (Hummingbird_Flight_Controller_B.ParamStep_i)));
  }

  // MATLABSystem: '<S1501>/SourceBlock'
  b_varargout_1 = uORB_read_step
    (Hummingbird_Flight_Controlle_DW.obj_a.orbMetadataObj,
     &Hummingbird_Flight_Controlle_DW.obj_a.eventStructObj,
     &Hummingbird_Flight_Controller_B.r8, false, 1.0);

  // Outputs for Enabled SubSystem: '<S1501>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S1565>/Enable'

  // Start for MATLABSystem: '<S1501>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S1565>/In1'
    Hummingbird_Flight_Controller_B.In1_f = Hummingbird_Flight_Controller_B.r8;
  }

  // End of Outputs for SubSystem: '<S1501>/Enabled Subsystem'

  // Gain: '<S1543>/Filter Coefficient' incorporates:
  //   DataTypeConversion: '<S5>/Cast To Double7'
  //   DiscreteIntegrator: '<S1535>/Filter'
  //   Gain: '<S1533>/Derivative Gain'
  //   Sum: '<S1535>/SumD'

  Hummingbird_Flight_Controller_B.rtb_FilterCoefficient_g2 =
    (Hummingbird_Flight_Controller_P.PIDController_D *
     Hummingbird_Flight_Controller_B.In1_f.gyro_rad[0] -
     Hummingbird_Flight_Controlle_DW.Filter_DSTATE[0]) *
    Hummingbird_Flight_Controller_P.PIDController_N;
  Hummingbird_Flight_Controller_B.rtb_FilterCoefficient_idx_0 =
    Hummingbird_Flight_Controller_B.rtb_FilterCoefficient_g2;

  // Sum: '<S1549>/Sum' incorporates:
  //   DataTypeConversion: '<S5>/Cast To Double7'
  //   Gain: '<S1543>/Filter Coefficient'
  //   Gain: '<S1545>/Proportional Gain'

  Hummingbird_Flight_Controller_B.Sum_e[0] =
    Hummingbird_Flight_Controller_P.PIDController_P *
    Hummingbird_Flight_Controller_B.In1_f.gyro_rad[0] +
    Hummingbird_Flight_Controller_B.rtb_FilterCoefficient_g2;

  // Gain: '<S1543>/Filter Coefficient' incorporates:
  //   DataTypeConversion: '<S5>/Cast To Double7'
  //   DiscreteIntegrator: '<S1535>/Filter'
  //   Gain: '<S1533>/Derivative Gain'
  //   Sum: '<S1535>/SumD'

  Hummingbird_Flight_Controller_B.rtb_FilterCoefficient_g2 =
    (Hummingbird_Flight_Controller_P.PIDController_D *
     Hummingbird_Flight_Controller_B.In1_f.gyro_rad[1] -
     Hummingbird_Flight_Controlle_DW.Filter_DSTATE[1]) *
    Hummingbird_Flight_Controller_P.PIDController_N;
  Hummingbird_Flight_Controller_B.rtb_FilterCoefficient_idx_1 =
    Hummingbird_Flight_Controller_B.rtb_FilterCoefficient_g2;

  // Sum: '<S1549>/Sum' incorporates:
  //   DataTypeConversion: '<S5>/Cast To Double7'
  //   Gain: '<S1543>/Filter Coefficient'
  //   Gain: '<S1545>/Proportional Gain'

  Hummingbird_Flight_Controller_B.Sum_e[1] =
    Hummingbird_Flight_Controller_P.PIDController_P *
    Hummingbird_Flight_Controller_B.In1_f.gyro_rad[1] +
    Hummingbird_Flight_Controller_B.rtb_FilterCoefficient_g2;

  // Gain: '<S1543>/Filter Coefficient' incorporates:
  //   DataTypeConversion: '<S5>/Cast To Double7'
  //   DiscreteIntegrator: '<S1535>/Filter'
  //   Gain: '<S1533>/Derivative Gain'
  //   Sum: '<S1535>/SumD'

  Hummingbird_Flight_Controller_B.rtb_FilterCoefficient_g2 =
    (Hummingbird_Flight_Controller_P.PIDController_D *
     Hummingbird_Flight_Controller_B.In1_f.gyro_rad[2] -
     Hummingbird_Flight_Controlle_DW.Filter_DSTATE[2]) *
    Hummingbird_Flight_Controller_P.PIDController_N;

  // Sum: '<S1549>/Sum' incorporates:
  //   DataTypeConversion: '<S5>/Cast To Double7'
  //   Gain: '<S1543>/Filter Coefficient'
  //   Gain: '<S1545>/Proportional Gain'

  Hummingbird_Flight_Controller_B.Sum_e[2] =
    Hummingbird_Flight_Controller_P.PIDController_P *
    Hummingbird_Flight_Controller_B.In1_f.gyro_rad[2] +
    Hummingbird_Flight_Controller_B.rtb_FilterCoefficient_g2;

  // MATLABSystem: '<S1487>/SourceBlock'
  b_varargout_1 = uORB_read_step
    (Hummingbird_Flight_Controlle_DW.obj_m.orbMetadataObj,
     &Hummingbird_Flight_Controlle_DW.obj_m.eventStructObj,
     &Hummingbird_Flight_Controller_B.r9, false, 1.0);

  // Outputs for Enabled SubSystem: '<S1487>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S1560>/Enable'

  // Start for MATLABSystem: '<S1487>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S1560>/In1'
    Hummingbird_Flight_Controller_B.In1_p = Hummingbird_Flight_Controller_B.r9;
  }

  // End of Outputs for SubSystem: '<S1487>/Enabled Subsystem'

  // DataTypeConversion: '<S5>/Cast To Double8' incorporates:
  //   Gain: '<S5>/Convert To ft//s1'

  Hummingbird_Flight_Controller_B.CastToDouble8 =
    Hummingbird_Flight_Controller_P.ConvertTofts1_Gain *
    Hummingbird_Flight_Controller_B.In1_p.true_airspeed_m_s;

  // RateTransition generated from: '<S5>/Rate Transition'
  if (Hummingbird_Flight_Controlle_M->Timing.RateInteraction.TID0_1) {
    // RateTransition generated from: '<S5>/Rate Transition'
    Hummingbird_Flight_Controller_B.X =
      Hummingbird_Flight_Controlle_DW.RateTransition_1_Buffer0;

    // RateTransition generated from: '<S5>/Rate Transition'
    Hummingbird_Flight_Controller_B.Y =
      Hummingbird_Flight_Controlle_DW.RateTransition_2_Buffer0;

    // RateTransition generated from: '<S5>/Rate Transition'
    Hummingbird_Flight_Controller_B.Z =
      Hummingbird_Flight_Controlle_DW.RateTransition_3_Buffer0;
  }

  // End of RateTransition generated from: '<S5>/Rate Transition'

  // MATLABSystem: '<S1485>/SourceBlock'
  b_varargout_1 = uORB_read_step
    (Hummingbird_Flight_Controlle_DW.obj_h.orbMetadataObj,
     &Hummingbird_Flight_Controlle_DW.obj_h.eventStructObj,
     &Hummingbird_Flight_Controller_B.r10, false, 1.0);

  // Outputs for Enabled SubSystem: '<S1485>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S1558>/Enable'

  // Start for MATLABSystem: '<S1485>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S1558>/In1'
    Hummingbird_Flight_Controller_B.In1_fv = Hummingbird_Flight_Controller_B.r10;
  }

  // End of Outputs for SubSystem: '<S1485>/Enabled Subsystem'

  // MATLABSystem: '<S1503>/SourceBlock'
  b_varargout_1 = uORB_read_step
    (Hummingbird_Flight_Controlle_DW.obj_i.orbMetadataObj,
     &Hummingbird_Flight_Controlle_DW.obj_i.eventStructObj,
     &Hummingbird_Flight_Controller_B.r3, false, 1.0);

  // Outputs for Enabled SubSystem: '<S1503>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S1567>/Enable'

  // Start for MATLABSystem: '<S1503>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S1567>/In1'
    Hummingbird_Flight_Controller_B.In1_a = Hummingbird_Flight_Controller_B.r3;
  }

  // End of Outputs for SubSystem: '<S1503>/Enabled Subsystem'

  // Gain: '<S5>/Gain13' incorporates:
  //   DataTypeConversion: '<S5>/Cast To Double20'

  Hummingbird_Flight_Controller_B.CastToDouble25_f =
    Hummingbird_Flight_Controller_P.Gain13_Gain_a *
    Hummingbird_Flight_Controller_B.In1_a.alt;

  // BusCreator generated from: '<Root>/Chart' incorporates:
  //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
  //
  Hummingbird_Flight_Controller_B.BusConversion_InsertedFor_Chart.X =
    Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0;
  Hummingbird_Flight_Controller_B.BusConversion_InsertedFor_Chart.Y =
    Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1;
  Hummingbird_Flight_Controller_B.BusConversion_InsertedFor_Chart.Z =
    Hummingbird_Flight_Controller_B.a_n;

  // MATLABSystem: '<S1486>/SourceBlock'
  b_varargout_1 = uORB_read_step
    (Hummingbird_Flight_Controlle_DW.obj_p.orbMetadataObj,
     &Hummingbird_Flight_Controlle_DW.obj_p.eventStructObj,
     &Hummingbird_Flight_Controller_B.r2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S1486>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S1559>/Enable'

  // Start for MATLABSystem: '<S1486>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S1559>/In1'
    Hummingbird_Flight_Controller_B.In1_d = Hummingbird_Flight_Controller_B.r2;
  }

  // End of Outputs for SubSystem: '<S1486>/Enabled Subsystem'

  // RateTransition generated from: '<S1493>/Sum' incorporates:
  //   RateTransition generated from: '<S1491>/Sum'
  //   RateTransition generated from: '<S1492>/Sum'
  //   RateTransition generated from: '<S1493>/Divide'
  //   RateTransition generated from: '<S1494>/Sum'
  //   RateTransition generated from: '<S1495>/Sum'
  //   RateTransition generated from: '<S1496>/Sum'
  //   RateTransition generated from: '<S1497>/Sum'
  //   RateTransition generated from: '<S1498>/Sum'
  //   RateTransition generated from: '<S1499>/Sum'

  b_varargout_1 = Hummingbird_Flight_Controlle_M->Timing.RateInteraction.TID0_2;
  if (b_varargout_1) {
    // RateTransition generated from: '<S1493>/Sum'
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2 =
      Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buffer0;

    // RateTransition generated from: '<S1493>/Divide'
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2 =
      Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_Buffer0;
  }

  // End of RateTransition generated from: '<S1493>/Sum'

  // DataTypeConversion: '<S5>/Cast To single2' incorporates:
  //   Constant: '<S1493>/Constant'
  //   Gain: '<S1493>/Gain'
  //   Product: '<S1493>/Divide'
  //   Sum: '<S1493>/Sum'
  //   Sum: '<S1493>/Sum2'

  Hummingbird_Flight_Controller_B.scale = floor((static_cast<real32_T>
    (Hummingbird_Flight_Controller_B.In1_d.values[2]) -
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2) /
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2 *
    Hummingbird_Flight_Controller_P.Gain_Gain_gt +
    Hummingbird_Flight_Controller_P.Constant_Value_kf);
  if (rtIsNaN(Hummingbird_Flight_Controller_B.scale) || rtIsInf
      (Hummingbird_Flight_Controller_B.scale)) {
    Hummingbird_Flight_Controller_B.scale = 0.0;
  } else {
    Hummingbird_Flight_Controller_B.scale = fmod
      (Hummingbird_Flight_Controller_B.scale, 65536.0);
  }

  Hummingbird_Flight_Controller_B.BusCreator.Throttle = static_cast<uint16_T>
    (Hummingbird_Flight_Controller_B.scale < 0.0 ? static_cast<int32_T>(
      static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-Hummingbird_Flight_Controller_B.scale)))) : static_cast<int32_T>(
      static_cast<uint16_T>(Hummingbird_Flight_Controller_B.scale)));

  // End of DataTypeConversion: '<S5>/Cast To single2'

  // RateTransition generated from: '<S1491>/Sum' incorporates:
  //   RateTransition generated from: '<S1491>/Divide'

  if (b_varargout_1) {
    // RateTransition generated from: '<S1491>/Sum'
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_m =
      Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buffer0_o;

    // RateTransition generated from: '<S1491>/Divide'
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_p =
      Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_Buffer0_l;
  }

  // DataTypeConversion: '<S5>/Cast To single' incorporates:
  //   Constant: '<S1491>/Constant'
  //   Gain: '<S1491>/Gain'
  //   Product: '<S1491>/Divide'
  //   Sum: '<S1491>/Sum'
  //   Sum: '<S1491>/Sum2'

  Hummingbird_Flight_Controller_B.scale = floor((static_cast<real32_T>
    (Hummingbird_Flight_Controller_B.In1_d.values[0]) -
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_m) /
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_p *
    Hummingbird_Flight_Controller_P.Gain_Gain_f +
    Hummingbird_Flight_Controller_P.Constant_Value_ho);
  if (rtIsNaN(Hummingbird_Flight_Controller_B.scale) || rtIsInf
      (Hummingbird_Flight_Controller_B.scale)) {
    Hummingbird_Flight_Controller_B.scale = 0.0;
  } else {
    Hummingbird_Flight_Controller_B.scale = fmod
      (Hummingbird_Flight_Controller_B.scale, 65536.0);
  }

  Hummingbird_Flight_Controller_B.BusCreator.Roll = static_cast<uint16_T>
    (Hummingbird_Flight_Controller_B.scale < 0.0 ? static_cast<int32_T>(
      static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-Hummingbird_Flight_Controller_B.scale)))) : static_cast<int32_T>(
      static_cast<uint16_T>(Hummingbird_Flight_Controller_B.scale)));

  // End of DataTypeConversion: '<S5>/Cast To single'

  // RateTransition generated from: '<S1492>/Sum' incorporates:
  //   RateTransition generated from: '<S1492>/Divide'

  if (b_varargout_1) {
    // RateTransition generated from: '<S1492>/Sum'
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_mb =
      Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buffer0_os;

    // RateTransition generated from: '<S1492>/Divide'
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_py =
      Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_Buffer_lz;
  }

  // DataTypeConversion: '<S5>/Cast To single1' incorporates:
  //   Constant: '<S1492>/Constant'
  //   Gain: '<S1492>/Gain'
  //   Product: '<S1492>/Divide'
  //   Sum: '<S1492>/Sum'
  //   Sum: '<S1492>/Sum2'

  Hummingbird_Flight_Controller_B.scale = floor((static_cast<real32_T>
    (Hummingbird_Flight_Controller_B.In1_d.values[1]) -
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_mb) /
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_py *
    Hummingbird_Flight_Controller_P.Gain_Gain_gl +
    Hummingbird_Flight_Controller_P.Constant_Value_iv);
  if (rtIsNaN(Hummingbird_Flight_Controller_B.scale) || rtIsInf
      (Hummingbird_Flight_Controller_B.scale)) {
    Hummingbird_Flight_Controller_B.scale = 0.0;
  } else {
    Hummingbird_Flight_Controller_B.scale = fmod
      (Hummingbird_Flight_Controller_B.scale, 65536.0);
  }

  Hummingbird_Flight_Controller_B.BusCreator.Pitch = static_cast<uint16_T>
    (Hummingbird_Flight_Controller_B.scale < 0.0 ? static_cast<int32_T>(
      static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-Hummingbird_Flight_Controller_B.scale)))) : static_cast<int32_T>(
      static_cast<uint16_T>(Hummingbird_Flight_Controller_B.scale)));

  // End of DataTypeConversion: '<S5>/Cast To single1'

  // RateTransition generated from: '<S1494>/Sum' incorporates:
  //   RateTransition generated from: '<S1494>/Divide'

  if (b_varargout_1) {
    // RateTransition generated from: '<S1494>/Sum'
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_mbd =
      Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buffer0_osg;

    // RateTransition generated from: '<S1494>/Divide'
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_pyt =
      Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_Buffe_lzh;
  }

  // DataTypeConversion: '<S5>/Cast To single3' incorporates:
  //   Constant: '<S1494>/Constant'
  //   Gain: '<S1494>/Gain'
  //   Product: '<S1494>/Divide'
  //   Sum: '<S1494>/Sum'
  //   Sum: '<S1494>/Sum2'

  Hummingbird_Flight_Controller_B.scale = floor((static_cast<real32_T>
    (Hummingbird_Flight_Controller_B.In1_d.values[3]) -
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_mbd) /
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_pyt *
    Hummingbird_Flight_Controller_P.Gain_Gain_nm +
    Hummingbird_Flight_Controller_P.Constant_Value_ibq);
  if (rtIsNaN(Hummingbird_Flight_Controller_B.scale) || rtIsInf
      (Hummingbird_Flight_Controller_B.scale)) {
    Hummingbird_Flight_Controller_B.scale = 0.0;
  } else {
    Hummingbird_Flight_Controller_B.scale = fmod
      (Hummingbird_Flight_Controller_B.scale, 65536.0);
  }

  Hummingbird_Flight_Controller_B.BusCreator.Yaw = static_cast<uint16_T>
    (Hummingbird_Flight_Controller_B.scale < 0.0 ? static_cast<int32_T>(
      static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-Hummingbird_Flight_Controller_B.scale)))) : static_cast<int32_T>(
      static_cast<uint16_T>(Hummingbird_Flight_Controller_B.scale)));

  // End of DataTypeConversion: '<S5>/Cast To single3'

  // RateTransition generated from: '<S1495>/Sum' incorporates:
  //   RateTransition generated from: '<S1495>/Divide'

  if (b_varargout_1) {
    // RateTransition generated from: '<S1495>/Sum'
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_mbdz =
      Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buffer0_osgb;

    // RateTransition generated from: '<S1495>/Divide'
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_pyts =
      Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_Buff_lzhx;
  }

  // DataTypeConversion: '<S5>/Cast To single4' incorporates:
  //   Constant: '<S1495>/Constant'
  //   Gain: '<S1495>/Gain'
  //   Product: '<S1495>/Divide'
  //   Sum: '<S1495>/Sum'
  //   Sum: '<S1495>/Sum2'

  Hummingbird_Flight_Controller_B.scale = floor((static_cast<real32_T>
    (Hummingbird_Flight_Controller_B.In1_d.values[4]) -
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_mbdz) /
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_pyts *
    Hummingbird_Flight_Controller_P.Gain_Gain_dx +
    Hummingbird_Flight_Controller_P.Constant_Value_pj);
  if (rtIsNaN(Hummingbird_Flight_Controller_B.scale) || rtIsInf
      (Hummingbird_Flight_Controller_B.scale)) {
    Hummingbird_Flight_Controller_B.scale = 0.0;
  } else {
    Hummingbird_Flight_Controller_B.scale = fmod
      (Hummingbird_Flight_Controller_B.scale, 65536.0);
  }

  Hummingbird_Flight_Controller_B.BusCreator.Arm_Switch = static_cast<uint16_T>
    (Hummingbird_Flight_Controller_B.scale < 0.0 ? static_cast<int32_T>(
      static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-Hummingbird_Flight_Controller_B.scale)))) : static_cast<int32_T>(
      static_cast<uint16_T>(Hummingbird_Flight_Controller_B.scale)));

  // End of DataTypeConversion: '<S5>/Cast To single4'

  // RateTransition generated from: '<S1496>/Sum' incorporates:
  //   RateTransition generated from: '<S1496>/Divide'

  if (b_varargout_1) {
    // RateTransition generated from: '<S1496>/Sum'
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_mbdzh =
      Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buffer_osgbz;

    // RateTransition generated from: '<S1496>/Divide'
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_pytsl =
      Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_Buf_lzhxe;
  }

  // DataTypeConversion: '<S5>/Cast To single5' incorporates:
  //   Constant: '<S1496>/Constant'
  //   Gain: '<S1496>/Gain'
  //   Product: '<S1496>/Divide'
  //   Sum: '<S1496>/Sum'
  //   Sum: '<S1496>/Sum2'

  Hummingbird_Flight_Controller_B.scale = floor((static_cast<real32_T>
    (Hummingbird_Flight_Controller_B.In1_d.values[5]) -
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_mbdzh) /
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_pytsl *
    Hummingbird_Flight_Controller_P.Gain_Gain_f1 +
    Hummingbird_Flight_Controller_P.Constant_Value_le);
  if (rtIsNaN(Hummingbird_Flight_Controller_B.scale) || rtIsInf
      (Hummingbird_Flight_Controller_B.scale)) {
    Hummingbird_Flight_Controller_B.scale = 0.0;
  } else {
    Hummingbird_Flight_Controller_B.scale = fmod
      (Hummingbird_Flight_Controller_B.scale, 65536.0);
  }

  Hummingbird_Flight_Controller_B.BusCreator.Flight_Mode = static_cast<uint16_T>
    (Hummingbird_Flight_Controller_B.scale < 0.0 ? static_cast<int32_T>(
      static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-Hummingbird_Flight_Controller_B.scale)))) : static_cast<int32_T>(
      static_cast<uint16_T>(Hummingbird_Flight_Controller_B.scale)));

  // End of DataTypeConversion: '<S5>/Cast To single5'

  // RateTransition generated from: '<S1497>/Sum' incorporates:
  //   RateTransition generated from: '<S1497>/Divide'

  if (b_varargout_1) {
    // RateTransition generated from: '<S1497>/Sum'
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_mbdzha =
      Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buffe_osgbzt;

    // RateTransition generated from: '<S1497>/Divide'
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_pytslg =
      Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_Bu_lzhxel;
  }

  // DataTypeConversion: '<S5>/Cast To single6' incorporates:
  //   Constant: '<S1497>/Constant'
  //   Gain: '<S1497>/Gain'
  //   Product: '<S1497>/Divide'
  //   Sum: '<S1497>/Sum'
  //   Sum: '<S1497>/Sum2'

  Hummingbird_Flight_Controller_B.scale = floor((static_cast<real32_T>
    (Hummingbird_Flight_Controller_B.In1_d.values[6]) -
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_mbdzha) /
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_pytslg *
    Hummingbird_Flight_Controller_P.Gain_Gain_a +
    Hummingbird_Flight_Controller_P.Constant_Value_fo);
  if (rtIsNaN(Hummingbird_Flight_Controller_B.scale) || rtIsInf
      (Hummingbird_Flight_Controller_B.scale)) {
    Hummingbird_Flight_Controller_B.scale = 0.0;
  } else {
    Hummingbird_Flight_Controller_B.scale = fmod
      (Hummingbird_Flight_Controller_B.scale, 65536.0);
  }

  Hummingbird_Flight_Controller_B.BusCreator.channel_7 = static_cast<uint16_T>
    (Hummingbird_Flight_Controller_B.scale < 0.0 ? static_cast<int32_T>(
      static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-Hummingbird_Flight_Controller_B.scale)))) : static_cast<int32_T>(
      static_cast<uint16_T>(Hummingbird_Flight_Controller_B.scale)));

  // End of DataTypeConversion: '<S5>/Cast To single6'

  // RateTransition generated from: '<S1498>/Sum' incorporates:
  //   RateTransition generated from: '<S1498>/Divide'

  if (b_varargout_1) {
    // RateTransition generated from: '<S1498>/Sum'
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_mbdzhaq =
      Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buff_osgbztg;

    // RateTransition generated from: '<S1498>/Divide'
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_pytslgw =
      Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_B_lzhxel2;
  }

  // DataTypeConversion: '<S5>/Cast To single7' incorporates:
  //   Constant: '<S1498>/Constant'
  //   Gain: '<S1498>/Gain'
  //   Product: '<S1498>/Divide'
  //   Sum: '<S1498>/Sum'
  //   Sum: '<S1498>/Sum2'

  Hummingbird_Flight_Controller_B.scale = floor((static_cast<real32_T>
    (Hummingbird_Flight_Controller_B.In1_d.values[7]) -
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_mbdzhaq) /
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_pytslgw *
    Hummingbird_Flight_Controller_P.Gain_Gain_n2 +
    Hummingbird_Flight_Controller_P.Constant_Value_hf);
  if (rtIsNaN(Hummingbird_Flight_Controller_B.scale) || rtIsInf
      (Hummingbird_Flight_Controller_B.scale)) {
    Hummingbird_Flight_Controller_B.scale = 0.0;
  } else {
    Hummingbird_Flight_Controller_B.scale = fmod
      (Hummingbird_Flight_Controller_B.scale, 65536.0);
  }

  Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode = static_cast<uint16_T>
    (Hummingbird_Flight_Controller_B.scale < 0.0 ? static_cast<int32_T>(
      static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-Hummingbird_Flight_Controller_B.scale)))) : static_cast<int32_T>(
      static_cast<uint16_T>(Hummingbird_Flight_Controller_B.scale)));

  // End of DataTypeConversion: '<S5>/Cast To single7'

  // RateTransition generated from: '<S1499>/Sum' incorporates:
  //   RateTransition generated from: '<S1499>/Divide'

  if (b_varargout_1) {
    // RateTransition generated from: '<S1499>/Sum'
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_mbdzhaqa =
      Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buf_osgbztgq;

    // RateTransition generated from: '<S1499>/Divide'
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_pytslgwp =
      Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2__lzhxel2b;
  }

  // DataTypeConversion: '<S5>/Cast To single8' incorporates:
  //   Constant: '<S1499>/Constant'
  //   Gain: '<S1499>/Gain'
  //   Product: '<S1499>/Divide'
  //   Sum: '<S1499>/Sum'
  //   Sum: '<S1499>/Sum2'

  Hummingbird_Flight_Controller_B.scale = floor((static_cast<real32_T>
    (Hummingbird_Flight_Controller_B.In1_d.values[8]) -
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_mbdzhaqa) /
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_pytslgwp *
    Hummingbird_Flight_Controller_P.Gain_Gain_gn +
    Hummingbird_Flight_Controller_P.Constant_Value_is);
  if (rtIsNaN(Hummingbird_Flight_Controller_B.scale) || rtIsInf
      (Hummingbird_Flight_Controller_B.scale)) {
    Hummingbird_Flight_Controller_B.scale = 0.0;
  } else {
    Hummingbird_Flight_Controller_B.scale = fmod
      (Hummingbird_Flight_Controller_B.scale, 65536.0);
  }

  Hummingbird_Flight_Controller_B.BusCreator.channel_9 = static_cast<uint16_T>
    (Hummingbird_Flight_Controller_B.scale < 0.0 ? static_cast<int32_T>(
      static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-Hummingbird_Flight_Controller_B.scale)))) : static_cast<int32_T>(
      static_cast<uint16_T>(Hummingbird_Flight_Controller_B.scale)));

  // End of DataTypeConversion: '<S5>/Cast To single8'

  // BusCreator: '<S5>/Bus Creator'
  Hummingbird_Flight_Controller_B.BusCreator.channel_10 =
    Hummingbird_Flight_Controller_B.In1_d.values[9];
  Hummingbird_Flight_Controller_B.BusCreator.channel_11 =
    Hummingbird_Flight_Controller_B.In1_d.values[10];
  Hummingbird_Flight_Controller_B.BusCreator.channel_12 =
    Hummingbird_Flight_Controller_B.In1_d.values[11];
  Hummingbird_Flight_Controller_B.BusCreator.channel_13 =
    Hummingbird_Flight_Controller_B.In1_d.values[12];
  Hummingbird_Flight_Controller_B.BusCreator.channel_14 =
    Hummingbird_Flight_Controller_B.In1_d.values[13];
  Hummingbird_Flight_Controller_B.BusCreator.channel_15 =
    Hummingbird_Flight_Controller_B.In1_d.values[14];
  Hummingbird_Flight_Controller_B.BusCreator.channel_16 =
    Hummingbird_Flight_Controller_B.In1_d.values[15];
  Hummingbird_Flight_Controller_B.BusCreator.channel_17 =
    Hummingbird_Flight_Controller_B.In1_d.values[16];
  Hummingbird_Flight_Controller_B.BusCreator.channel_18 =
    Hummingbird_Flight_Controller_B.In1_d.values[17];

  // MATLABSystem: '<S1488>/SourceBlock'
  b_varargout_1 = uORB_read_step
    (Hummingbird_Flight_Controlle_DW.obj_az.orbMetadataObj,
     &Hummingbird_Flight_Controlle_DW.obj_az.eventStructObj,
     &Hummingbird_Flight_Controller_B.r, false, 1.0);

  // Outputs for Enabled SubSystem: '<S1488>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S1561>/Enable'

  // Start for MATLABSystem: '<S1488>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S1561>/In1'
    Hummingbird_Flight_Controller_B.In1 = Hummingbird_Flight_Controller_B.r;
  }

  // End of Outputs for SubSystem: '<S1488>/Enabled Subsystem'

  // Gain: '<S5>/Gain1' incorporates:
  //   DataTypeConversion: '<S5>/Cast To Double14'

  Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.airspeed =
    Hummingbird_Flight_Controller_P.Gain1_Gain_bw *
    Hummingbird_Flight_Controller_B.In1.next.acceptance_radius;

  // Gain: '<S5>/Gain2' incorporates:
  //   DataTypeConversion: '<S5>/Cast To Double15'

  Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.acceptance_radius
    = Hummingbird_Flight_Controller_P.Gain2_Gain_ci *
    Hummingbird_Flight_Controller_B.In1.next.cruising_speed;

  // BusCreator: '<S5>/Bus Creator17' incorporates:
  //   BusCreator: '<S5>/Bus Creator11'
  //   DataTypeConversion: '<S5>/Cast To Double13'
  //   Gain: '<S5>/Gain'

  Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lat =
    Hummingbird_Flight_Controller_B.In1.next.lat;
  Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lon =
    Hummingbird_Flight_Controller_B.In1.next.lon;
  Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.altitude
    = Hummingbird_Flight_Controller_P.Gain_Gain_g *
    Hummingbird_Flight_Controller_B.In1.next.alt;

  // Gain: '<S5>/Gain4' incorporates:
  //   DataTypeConversion: '<S5>/Cast To Double17'

  Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.airspeed =
    Hummingbird_Flight_Controller_P.Gain4_Gain_a *
    Hummingbird_Flight_Controller_B.In1.current.acceptance_radius;

  // Gain: '<S5>/Gain5' incorporates:
  //   DataTypeConversion: '<S5>/Cast To Double18'

  Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.acceptance_radius
    = Hummingbird_Flight_Controller_P.Gain5_Gain_i *
    Hummingbird_Flight_Controller_B.In1.current.cruising_speed;

  // BusCreator: '<S5>/Bus Creator16' incorporates:
  //   BusCreator: '<S5>/Bus Creator12'
  //   DataTypeConversion: '<S5>/Cast To Double16'
  //   Gain: '<S5>/Gain3'

  Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lat =
    Hummingbird_Flight_Controller_B.In1.current.lat;
  Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lon =
    Hummingbird_Flight_Controller_B.In1.current.lon;
  Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.altitude
    = Hummingbird_Flight_Controller_P.Gain3_Gain_c *
    Hummingbird_Flight_Controller_B.In1.current.alt;

  // Gain: '<S5>/Gain7' incorporates:
  //   DataTypeConversion: '<S5>/Cast To Double21'

  Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.next.airspeed =
    Hummingbird_Flight_Controller_P.Gain7_Gain_a *
    Hummingbird_Flight_Controller_B.In1.previous.acceptance_radius;

  // Gain: '<S5>/Gain8' incorporates:
  //   DataTypeConversion: '<S5>/Cast To Double22'

  Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.next.acceptance_radius =
    Hummingbird_Flight_Controller_P.Gain8_Gain_h *
    Hummingbird_Flight_Controller_B.In1.previous.cruising_speed;

  // BusCreator: '<S5>/Bus Creator15' incorporates:
  //   BusCreator: '<S5>/Bus Creator13'
  //   DataTypeConversion: '<S5>/Cast To Double19'
  //   Gain: '<S5>/Gain6'

  Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.next.gps_pos.lat =
    Hummingbird_Flight_Controller_B.In1.previous.lat;
  Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.next.gps_pos.lon =
    Hummingbird_Flight_Controller_B.In1.previous.lon;
  Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.next.gps_pos.altitude =
    Hummingbird_Flight_Controller_P.Gain6_Gain_i *
    Hummingbird_Flight_Controller_B.In1.previous.alt;

  // MATLABSystem: '<S1489>/SourceBlock'
  b_varargout_1 = uORB_read_step
    (Hummingbird_Flight_Controlle_DW.obj_g.orbMetadataObj,
     &Hummingbird_Flight_Controlle_DW.obj_g.eventStructObj,
     &Hummingbird_Flight_Controller_B.r7, false, 1.0);

  // Outputs for Enabled SubSystem: '<S1489>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S1562>/Enable'

  // Start for MATLABSystem: '<S1489>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S1562>/In1'
    Hummingbird_Flight_Controller_B.In1_i4 = Hummingbird_Flight_Controller_B.r7;
  }

  // End of Outputs for SubSystem: '<S1489>/Enabled Subsystem'

  // Gain: '<S5>/Gain9' incorporates:
  //   DataTypeConversion: '<S5>/Cast To Double23'

  Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.X =
    Hummingbird_Flight_Controller_P.Gain9_Gain_e *
    Hummingbird_Flight_Controller_B.In1_i4.x;

  // Gain: '<S5>/Gain10' incorporates:
  //   DataTypeConversion: '<S5>/Cast To Double24'

  Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.Y =
    Hummingbird_Flight_Controller_P.Gain10_Gain_d *
    Hummingbird_Flight_Controller_B.In1_i4.y;

  // Gain: '<S5>/Gain11' incorporates:
  //   DataTypeConversion: '<S5>/Cast To Double25'

  Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.Z =
    Hummingbird_Flight_Controller_P.Gain11_Gain_d *
    Hummingbird_Flight_Controller_B.In1_i4.z;

  // BusCreator: '<S5>/Bus Creator14' incorporates:
  //   BusCreator: '<S5>/Bus Creator19'
  //   DataTypeConversion: '<S5>/Cast To Double12'
  //   Gain: '<S5>/Gain12'

  Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lat =
    Hummingbird_Flight_Controller_B.In1_i4.lat;
  Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lon =
    Hummingbird_Flight_Controller_B.In1_i4.lon;
  Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.altitude =
    Hummingbird_Flight_Controller_P.Gain12_Gain_d *
    Hummingbird_Flight_Controller_B.In1_i4.alt;

  // Chart: '<Root>/Chart' incorporates:
  //   BusCreator: '<S5>/Bus Creator9'

  Hummingbird_Flight_Controller_B.RC_Flight_Mode_prev_g =
    Hummingbird_Flight_Controlle_DW.RC_Flight_Mode_start_m;
  Hummingbird_Flight_Controlle_DW.RC_Flight_Mode_start_m =
    Hummingbird_Flight_Controller_B.BusCreator.Flight_Mode;
  Hummingbird_Flight_Controller_B.RC_VTOL_Mode_prev_i =
    Hummingbird_Flight_Controlle_DW.RC_VTOL_Mode_start_l;
  Hummingbird_Flight_Controlle_DW.RC_VTOL_Mode_start_l =
    Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode;
  if (Hummingbird_Flight_Controlle_DW.is_active_c3_Hummingbird_Flight == 0) {
    Hummingbird_Flight_Controlle_DW.RC_Flight_Mode_start_m =
      Hummingbird_Flight_Controller_B.BusCreator.Flight_Mode;
    Hummingbird_Flight_Controlle_DW.RC_VTOL_Mode_start_l =
      Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode;
    Hummingbird_Flight_Controlle_DW.is_active_c3_Hummingbird_Flight = 1U;
    if (Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode < 1200) {
      if (Hummingbird_Flight_Controller_B.BusCreator.Flight_Mode > 1800) {
        Hummingbird_Flight_Controlle_DW.is_Flight_controller =
          Hummingbir_IN_Set_mission_start;
        Hummingbird_Flight_Controlle_DW.mission_start[0] =
          Hummingbird_Flight_Controller_B.In1_a.lat;
        Hummingbird_Flight_Controlle_DW.mission_start[1] =
          Hummingbird_Flight_Controller_B.In1_a.lon;
        Hummingbird_Flight_Controlle_DW.mission_start[2] =
          Hummingbird_Flight_Controller_B.CastToDouble25_f;
      } else {
        Hummingbird_Flight_Controlle_DW.is_Flight_controller =
          Hummingbird_Fli_IN_FW_Stabilize;

        // Merge: '<S1>/ Merge ' incorporates:
        //   Constant: '<S7>/Constant10'
        //   SignalConversion generated from: '<S7>/dtFW'

        Hummingbird_Flight_Controller_B.dtFW =
          Hummingbird_Flight_Controller_P.Constant10_Value;

        // Gain: '<S1168>/Gain5' incorporates:
        //   Constant: '<S7>/Constant11'
        //   Merge: '<S1>/ Merge 1'
        //   SignalConversion generated from: '<S7>/dtMR'

        Hummingbird_Flight_Controller_B.dtMR =
          Hummingbird_Flight_Controller_P.Constant11_Value_b;
        Hummingbird_Fl_PX4Timestamp
          (&Hummingbird_Flight_Controller_B.PX4Timestamp_l);

        // Gain: '<S376>/Gain10' incorporates:
        //   Constant: '<S376>/Constant7'
        //   Sum: '<S376>/Sum8'

        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Roll)
           - Hummingbird_Flight_Controller_P.Constant7_Value_l) *
          Hummingbird_Flight_Controller_P.Gain10_Gain_e;

        // Saturate: '<S376>/Saturation'
        if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_k) {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_k;
        } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                   Hummingbird_Flight_Controller_P.Saturation_LowerSat_i) {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
            Hummingbird_Flight_Controller_P.Saturation_LowerSat_i;
        }

        // Gain: '<S367>/Gain1' incorporates:
        //   Saturate: '<S376>/Saturation'

        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
          Hummingbird_Flight_Controller_P.Gain1_Gain_j *
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;

        // Gain: '<S377>/Gain10' incorporates:
        //   Constant: '<S377>/Constant7'
        //   Sum: '<S377>/Sum8'

        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Pitch)
           - Hummingbird_Flight_Controller_P.Constant7_Value_m) *
          Hummingbird_Flight_Controller_P.Gain10_Gain_j;

        // Saturate: '<S377>/Saturation'
        if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_n) {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_n;
        } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                   Hummingbird_Flight_Controller_P.Saturation_LowerSat_l) {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
            Hummingbird_Flight_Controller_P.Saturation_LowerSat_l;
        }

        // Gain: '<S367>/Gain2' incorporates:
        //   Saturate: '<S377>/Saturation'

        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          Hummingbird_Flight_Controller_P.Gain2_Gain_l *
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;

        // Gain: '<S378>/Gain10' incorporates:
        //   Constant: '<S378>/Constant7'
        //   Sum: '<S378>/Sum8'

        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Yaw) -
           Hummingbird_Flight_Controller_P.Constant7_Value_ne) *
          Hummingbird_Flight_Controller_P.Gain10_Gain_m;

        // Saturate: '<S378>/Saturation'
        if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_j) {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_j;
        } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                   Hummingbird_Flight_Controller_P.Saturation_LowerSat_ly) {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
            Hummingbird_Flight_Controller_P.Saturation_LowerSat_ly;
        }

        // Gain: '<S367>/Gain3' incorporates:
        //   Saturate: '<S378>/Saturation'

        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 *=
          Hummingbird_Flight_Controller_P.Gain3_Gain_j;

        // Sum: '<S367>/Sum' incorporates:
        //   BusCreator generated from: '<Root>/Chart'
        //   Gain: '<S367>/Gain4'
        //   Product: '<S367>/Divide'
        //   Trigonometry: '<S367>/Trigonometric Function1'
        //   Trigonometry: '<S367>/Trigonometric Function3'

        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_P.Gain4_Gain_n * tan
          (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0) * cos
          (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1) /
          Hummingbird_Flight_Controller_B.CastToDouble8 +
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;

        // BusAssignment: '<S372>/Bus Assignment' incorporates:
        //   Constant: '<S367>/Constant2'
        //   DataTypeConversion: '<S367>/Cast To Single7'
        //   DataTypeConversion: '<S367>/Cast To Single8'
        //   DataTypeConversion: '<S367>/Cast To Single9'
        //   MATLABSystem: '<S372>/PX4 Timestamp'

        Hummingbird_Flight_Controller_B.BusAssignment_nb.timestamp =
          Hummingbird_Flight_Controller_B.PX4Timestamp_l.PX4Timestamp;
        Hummingbird_Flight_Controller_B.BusAssignment_nb.roll =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);
        Hummingbird_Flight_Controller_B.BusAssignment_nb.pitch =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
        Hummingbird_Flight_Controller_B.BusAssignment_nb.yaw_rate =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1);
        Hummingbird_Flight_Controller_B.BusAssignment_nb._padding0[0] =
          Hummingbird_Flight_Controller_P.Constant2_Value_j[0];
        Hummingbird_Flight_Controller_B.BusAssignment_nb._padding0[1] =
          Hummingbird_Flight_Controller_P.Constant2_Value_j[1];
        Hummingbird_Flight_Controller_B.BusAssignment_nb._padding0[2] =
          Hummingbird_Flight_Controller_P.Constant2_Value_j[2];
        Hummingbird_Flight_Controller_B.BusAssignment_nb._padding0[3] =
          Hummingbird_Flight_Controller_P.Constant2_Value_j[3];
        Hummingbird_Fligh_SinkBlock
          (&Hummingbird_Flight_Controller_B.BusAssignment_nb,
           &Hummingbird_Flight_Controlle_DW.SinkBlock_l);
        Hummingbird_Fl_PX4Timestamp
          (&Hummingbird_Flight_Controller_B.PX4Timestamp_p5);

        // Sum: '<S367>/Sum5' incorporates:
        //   DataTypeConversion: '<S5>/Cast To Double3'
        //   DataTypeConversion: '<S5>/Cast To Double4'
        //   DataTypeConversion: '<S5>/Cast To Double5'
        //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
        //
        Hummingbird_Flight_Controller_B.prev_waypoint[0] =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 -
          Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0;
        Hummingbird_Flight_Controller_B.prev_waypoint[1] =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
          Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1;
        Hummingbird_Flight_Controller_B.prev_waypoint[2] =
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 -
          Hummingbird_Flight_Controller_B.a_n;
        Hummingbird__ReadParameter1
          (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb,
           &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb);
        Hummingbird_F_ReadParameter
          (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb,
           &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb);
        Hummingbir_ReadParameter1_b
          (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3,
           &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3);
        Hummingbird_ReadParameter_b
          (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3,
           &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3);

        // Product: '<S472>/NProd Out' incorporates:
        //   Constant: '<S367>/Constant1'
        //   Constant: '<S379>/Constant'
        //   DiscreteIntegrator: '<S464>/Filter'
        //   Product: '<S462>/DProd Out'
        //   Sum: '<S464>/SumD'

        Hummingbird_Flight_Controller_B.Filter_os[0] =
          (Hummingbird_Flight_Controller_B.prev_waypoint[0] *
           Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3.ReadParameter1_o1
           - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_d[0]) *
          Hummingbird_Flight_Controller_P.Constant1_Value_c;
        Hummingbird_Flight_Controller_B.Filter_os[1] =
          (Hummingbird_Flight_Controller_B.prev_waypoint[1] *
           Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3.ReadParameter_o1
           - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_d[1]) *
          Hummingbird_Flight_Controller_P.Constant1_Value_c;
        Hummingbird_Flight_Controller_B.Filter_os[2] =
          (Hummingbird_Flight_Controller_B.prev_waypoint[2] *
           Hummingbird_Flight_Controller_P.Constant_Value_bs -
           Hummingbird_Flight_Controlle_DW.Filter_DSTATE_d[2]) *
          Hummingbird_Flight_Controller_P.Constant1_Value_c;

        // Sum: '<S478>/Sum' incorporates:
        //   Constant: '<S375>/Constant'
        //   Product: '<S474>/PProd Out'

        Hummingbird_Flight_Controller_B.DProdOut_n[0] =
          Hummingbird_Flight_Controller_B.prev_waypoint[0] *
          Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb.ReadParameter1_o1
          + Hummingbird_Flight_Controller_B.Filter_os[0];
        Hummingbird_Flight_Controller_B.DProdOut_n[1] =
          Hummingbird_Flight_Controller_B.prev_waypoint[1] *
          Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb.ReadParameter_o1
          + Hummingbird_Flight_Controller_B.Filter_os[1];
        Hummingbird_Flight_Controller_B.DProdOut_n[2] =
          Hummingbird_Flight_Controller_B.prev_waypoint[2] *
          Hummingbird_Flight_Controller_P.Constant_Value_lw +
          Hummingbird_Flight_Controller_B.Filter_os[2];

        // MATLAB Function: '<S367>/MATLAB Function'
        Hummingbird__MATLABFunction
          (&Hummingbird_Flight_Controller_B.BusConversion_InsertedFor_Chart,
           &Hummingbird_Flight_Controller_B.DProdOut_n[0],
           Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1,
           Hummingbird_Flight_Controller_B.prev_waypoint,
           &Hummingbird_Flight_Controller_B.sf_MATLABFunction_b);

        // BusAssignment: '<S373>/Bus Assignment' incorporates:
        //   Constant: '<S367>/Constant3'
        //   DataTypeConversion: '<S367>/Cast To Single1'
        //   DataTypeConversion: '<S367>/Cast To Single2'
        //   DataTypeConversion: '<S367>/Cast To Single6'
        //   MATLABSystem: '<S373>/PX4 Timestamp'

        Hummingbird_Flight_Controller_B.BusAssignment_j1.timestamp =
          Hummingbird_Flight_Controller_B.PX4Timestamp_p5.PX4Timestamp;
        Hummingbird_Flight_Controller_B.BusAssignment_j1.roll_rate =
          static_cast<real32_T>(Hummingbird_Flight_Controller_B.prev_waypoint[0]);
        Hummingbird_Flight_Controller_B.BusAssignment_j1.pitch_rate =
          static_cast<real32_T>(Hummingbird_Flight_Controller_B.prev_waypoint[1]);
        Hummingbird_Flight_Controller_B.BusAssignment_j1.yaw_rate = static_cast<
          real32_T>(Hummingbird_Flight_Controller_B.prev_waypoint[2]);
        Hummingbird_Flight_Controller_B.BusAssignment_j1._padding0[0] =
          Hummingbird_Flight_Controller_P.Constant3_Value_c[0];
        Hummingbird_Flight_Controller_B.BusAssignment_j1._padding0[1] =
          Hummingbird_Flight_Controller_P.Constant3_Value_c[1];
        Hummingbird_Flight_Controller_B.BusAssignment_j1._padding0[2] =
          Hummingbird_Flight_Controller_P.Constant3_Value_c[2];
        Hummingbird_Flight_Controller_B.BusAssignment_j1._padding0[3] =
          Hummingbird_Flight_Controller_P.Constant3_Value_c[3];
        Hummingbird_Fli_SinkBlock_h
          (&Hummingbird_Flight_Controller_B.BusAssignment_j1,
           &Hummingbird_Flight_Controlle_DW.SinkBlock_c);
        Hummingbird_Fl_PX4Timestamp
          (&Hummingbird_Flight_Controller_B.PX4Timestamp_ct);

        // Sum: '<S367>/Sum4' incorporates:
        //   DataTypeConversion: '<S5>/Cast To Double7'

        Hummingbird_Flight_Controller_B.DProdOut_n[0] =
          Hummingbird_Flight_Controller_B.prev_waypoint[0] -
          Hummingbird_Flight_Controller_B.In1_f.gyro_rad[0];
        Hummingbird_Flight_Controller_B.DProdOut_n[1] =
          Hummingbird_Flight_Controller_B.prev_waypoint[1] -
          Hummingbird_Flight_Controller_B.In1_f.gyro_rad[1];
        Hummingbird_Flight_Controller_B.DProdOut_n[2] =
          Hummingbird_Flight_Controller_B.prev_waypoint[2] -
          Hummingbird_Flight_Controller_B.In1_f.gyro_rad[2];
        Hummingbi_ReadParameter1_b3
          (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3a,
           &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3a);
        Hummingbir_ReadParameter_b3
          (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3a,
           &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3a);
        Hummingbird__ReadParameter2
          (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgae,
           &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgae);
        Hummingbir_ReadParameter3_b
          (&Hummingbird_Flight_Controller_B.ReadParameter3_b3,
           &Hummingbird_Flight_Controlle_DW.ReadParameter3_b3);
        Hummingbir_ReadParameter2_b
          (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaen,
           &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaen);
        Hummingbird__ReadParameter4
          (&Hummingbird_Flight_Controller_B.ReadParameter4_b,
           &Hummingbird_Flight_Controlle_DW.ReadParameter4_b);

        // Product: '<S420>/NProd Out' incorporates:
        //   Constant: '<S367>/Constant4'
        //   DiscreteIntegrator: '<S412>/Filter'
        //   Product: '<S410>/DProd Out'
        //   Sum: '<S412>/SumD'

        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          (Hummingbird_Flight_Controller_B.DProdOut_n[0] *
           Hummingbird_Flight_Controller_B.ReadParameter3_b3.ReadParameter3_o1 -
           Hummingbird_Flight_Controlle_DW.Filter_DSTATE_p[0]) *
          Hummingbird_Flight_Controller_P.Constant4_Value_p;
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          (Hummingbird_Flight_Controller_B.DProdOut_n[1] *
           Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaen.ReadParameter2_o1
           - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_p[1]) *
          Hummingbird_Flight_Controller_P.Constant4_Value_p;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
          (Hummingbird_Flight_Controller_B.DProdOut_n[2] *
           Hummingbird_Flight_Controller_B.ReadParameter4_b.ReadParameter4_o1 -
           Hummingbird_Flight_Controlle_DW.Filter_DSTATE_p[2]) *
          Hummingbird_Flight_Controller_P.Constant4_Value_p;

        // Sum: '<S426>/Sum' incorporates:
        //   Product: '<S422>/PProd Out'

        Hummingbird_Flight_Controller_B.prev_waypoint[0] =
          Hummingbird_Flight_Controller_B.DProdOut_n[0] *
          Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3a.ReadParameter1_o1
          + Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1;
        Hummingbird_Flight_Controller_B.prev_waypoint[1] =
          Hummingbird_Flight_Controller_B.DProdOut_n[1] *
          Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3a.ReadParameter_o1
          + Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;
        Hummingbird_Flight_Controller_B.prev_waypoint[2] =
          Hummingbird_Flight_Controller_B.DProdOut_n[2] *
          Hummingbird_Flight_Controller_B.ReadParameter2_b3rgae.ReadParameter2_o1
          + Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;

        // BusAssignment: '<S374>/Bus Assignment' incorporates:
        //   Constant: '<S367>/Constant'
        //   DataTypeConversion: '<S367>/Cast To Single3'
        //   DataTypeConversion: '<S367>/Cast To Single4'
        //   DataTypeConversion: '<S367>/Cast To Single5'
        //   MATLABSystem: '<S374>/PX4 Timestamp'

        Hummingbird_Flight_Controller_B.BusAssignment_ia.timestamp =
          Hummingbird_Flight_Controller_B.PX4Timestamp_ct.PX4Timestamp;
        Hummingbird_Flight_Controller_B.BusAssignment_ia.roll_rate_error =
          static_cast<real32_T>(Hummingbird_Flight_Controller_B.prev_waypoint[0]);
        Hummingbird_Flight_Controller_B.BusAssignment_ia.pitch_rate_error =
          static_cast<real32_T>(Hummingbird_Flight_Controller_B.prev_waypoint[1]);
        Hummingbird_Flight_Controller_B.BusAssignment_ia.yaw_rate_error =
          static_cast<real32_T>(Hummingbird_Flight_Controller_B.prev_waypoint[2]);
        Hummingbird_Flight_Controller_B.BusAssignment_ia._padding0[0] =
          Hummingbird_Flight_Controller_P.Constant_Value_c4[0];
        Hummingbird_Flight_Controller_B.BusAssignment_ia._padding0[1] =
          Hummingbird_Flight_Controller_P.Constant_Value_c4[1];
        Hummingbird_Flight_Controller_B.BusAssignment_ia._padding0[2] =
          Hummingbird_Flight_Controller_P.Constant_Value_c4[2];
        Hummingbird_Flight_Controller_B.BusAssignment_ia._padding0[3] =
          Hummingbird_Flight_Controller_P.Constant_Value_c4[3];
        Hummingbird_Fli_SinkBlock_j
          (&Hummingbird_Flight_Controller_B.BusAssignment_ia,
           &Hummingbird_Flight_Controlle_DW.SinkBlock_cp);

        // Sum: '<S367>/Sum3'
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_B.prev_waypoint[0];
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
          Hummingbird_Flight_Controller_B.prev_waypoint[1];
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 =
          Hummingbird_Flight_Controller_B.prev_waypoint[2];
        Hummingb_ReadParameter1_b3r
          (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ay,
           &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ay);
        Hummingbi_ReadParameter_b3r
          (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ay,
           &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ay);
        Hummingbi_ReadParameter2_b3
          (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb,
           &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb);

        // Merge: '<S1>/ Merge 2' incorporates:
        //   BusCreator: '<S5>/Bus Creator6'
        //   Product: '<S526>/PProd Out'
        //   Sum: '<S367>/Sum3'

        Hummingbird_Flight_Controller_B.dM[0] =
          (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 -
           Hummingbird_Flight_Controller_B.Sum_e[0]) *
          Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ay.ReadParameter1_o1;
        Hummingbird_Flight_Controller_B.dM[1] =
          (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 -
           Hummingbird_Flight_Controller_B.Sum_e[1]) *
          Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ay.ReadParameter_o1;
        Hummingbird_Flight_Controller_B.dM[2] =
          (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 -
           Hummingbird_Flight_Controller_B.Sum_e[2]) *
          Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb.ReadParameter2_o1;

        // Update for DiscreteIntegrator: '<S464>/Filter'
        Hummingbird_Flight_Controlle_DW.Filter_DSTATE_d[0] +=
          Hummingbird_Flight_Controller_P.Filter_gainval_n *
          Hummingbird_Flight_Controller_B.Filter_os[0];

        // Update for DiscreteIntegrator: '<S412>/Filter'
        Hummingbird_Flight_Controlle_DW.Filter_DSTATE_p[0] +=
          Hummingbird_Flight_Controller_P.Filter_gainval_bd *
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1;

        // Update for DiscreteIntegrator: '<S464>/Filter'
        Hummingbird_Flight_Controlle_DW.Filter_DSTATE_d[1] +=
          Hummingbird_Flight_Controller_P.Filter_gainval_n *
          Hummingbird_Flight_Controller_B.Filter_os[1];

        // Update for DiscreteIntegrator: '<S412>/Filter'
        Hummingbird_Flight_Controlle_DW.Filter_DSTATE_p[1] +=
          Hummingbird_Flight_Controller_P.Filter_gainval_bd *
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;

        // Update for DiscreteIntegrator: '<S464>/Filter'
        Hummingbird_Flight_Controlle_DW.Filter_DSTATE_d[2] +=
          Hummingbird_Flight_Controller_P.Filter_gainval_n *
          Hummingbird_Flight_Controller_B.Filter_os[2];

        // Update for DiscreteIntegrator: '<S412>/Filter'
        Hummingbird_Flight_Controlle_DW.Filter_DSTATE_p[2] +=
          Hummingbird_Flight_Controller_P.Filter_gainval_bd *
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;
      }
    } else if (Hummingbird_Flight_Controller_B.BusCreator.Flight_Mode > 1800) {
      Hummingbird_Flight_Controlle_DW.is_Flight_controller =
        Hummingbird_Flight_Co_IN_MR_Nav;

      // Merge: '<S1>/ Merge ' incorporates:
      //   Constant: '<S9>/Constant10'
      //   SignalConversion generated from: '<S9>/dtFW'

      Hummingbird_Flight_Controller_B.dtFW =
        Hummingbird_Flight_Controller_P.Constant10_Value_b;

      // MATLAB Function: '<S780>/MATLAB Function2'
      if (rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lat)
          || rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lon))
      {
        Hummingbird_Flight_Controller_B.prev_lat[0] =
          Hummingbird_Flight_Controlle_DW.mission_start[0];
        Hummingbird_Flight_Controller_B.prev_lat[1] =
          Hummingbird_Flight_Controlle_DW.mission_start[1];
        Hummingbird_Flight_Controller_B.prev_lat[2] =
          Hummingbird_Flight_Controlle_DW.mission_start[2];
      } else {
        Hummingbird_Flight_Controller_B.prev_lat[0] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lat;
        Hummingbird_Flight_Controller_B.prev_lat[1] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lon;
        Hummingbird_Flight_Controller_B.prev_lat[2] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.altitude;
      }

      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[0] =
        Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lat;
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[1] =
        Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lon;
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[2] =
        Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.altitude;
      Hummingbird_Flight_Cont_lla2ned(Hummingbird_Flight_Controller_B.prev_lat,
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c,
        Hummingbird_Flight_Controller_B.current_lat);
      if (rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lat))
      {
        Hummingbird_Flight_Controller_B.DProdOut_n[0] = 0.0;
        Hummingbird_Flight_Controller_B.DProdOut_n[1] = 0.0;
        Hummingbird_Flight_Controller_B.DProdOut_n[2] = 0.0;
      } else if (rtIsNaN
                 (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lon))
      {
        Hummingbird_Flight_Controller_B.DProdOut_n[0] = 0.0;
        Hummingbird_Flight_Controller_B.DProdOut_n[1] = 0.0;
        Hummingbird_Flight_Controller_B.DProdOut_n[2] = 0.0;
      } else {
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[0] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lat;
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[1] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lon;
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[2] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.altitude;
        Hummingbird_Flight_Controller_B.prev_lat[0] =
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lat;
        Hummingbird_Flight_Controller_B.prev_lat[1] =
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lon;
        Hummingbird_Flight_Controller_B.prev_lat[2] =
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.altitude;
        Hummingbird_Flight_Cont_lla2ned
          (Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c,
           Hummingbird_Flight_Controller_B.prev_lat,
           Hummingbird_Flight_Controller_B.dv);
        Hummingbird_Flight_Controller_B.DProdOut_n[0] = 3.28084 *
          Hummingbird_Flight_Controller_B.dv[0] +
          Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.X;
        Hummingbird_Flight_Controller_B.DProdOut_n[1] = 3.28084 *
          Hummingbird_Flight_Controller_B.dv[1] +
          Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.Y;
        Hummingbird_Flight_Controller_B.DProdOut_n[2] = 3.28084 *
          Hummingbird_Flight_Controller_B.dv[2] +
          Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.Z;
      }

      // Sum: '<S777>/Sum20' incorporates:
      //   BusCreator: '<S5>/Bus Creator9'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        Hummingbird_Flight_Controller_B.DProdOut_n[2] -
        Hummingbird_Flight_Controller_B.CastToDouble25_f;

      // Gain: '<S872>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S864>/Filter'
      //   Gain: '<S862>/Derivative Gain'
      //   Sum: '<S864>/SumD'

      Hummingbird_Flight_Controller_B.Esp_dot =
        (Hummingbird_Flight_Controller_P.PIDController5_D *
         Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_fu) *
        Hummingbird_Flight_Controller_P.PIDController5_N;

      // Sum: '<S878>/Sum' incorporates:
      //   DiscreteIntegrator: '<S869>/Integrator'
      //   Gain: '<S874>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (Hummingbird_Flight_Controller_P.PIDController5_P *
         Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_n) +
        Hummingbird_Flight_Controller_B.Esp_dot;

      // Saturate: '<S876>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.PIDController5_UpperSaturationL) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.PIDController5_UpperSaturationL;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.PIDController5_LowerSaturationL)
      {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.PIDController5_LowerSaturationL;
      }

      // Sum: '<S777>/Sum21' incorporates:
      //   BusCreator: '<S5>/Bus Creator4'
      //   Saturate: '<S876>/Saturation'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2;

      // Gain: '<S820>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S812>/Filter'
      //   Gain: '<S810>/Derivative Gain'
      //   Sum: '<S812>/SumD'

      Hummingbird_Flight_Controller_B.V =
        (Hummingbird_Flight_Controller_P.PIDController3_D *
         Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_l) *
        Hummingbird_Flight_Controller_P.PIDController3_N;

      // Gain: '<S1168>/Gain5' incorporates:
      //   DiscreteIntegrator: '<S817>/Integrator'
      //   Gain: '<S777>/Gain5'
      //   Gain: '<S822>/Proportional Gain'
      //   Merge: '<S1>/ Merge 1'
      //   Sum: '<S826>/Sum'

      Hummingbird_Flight_Controller_B.dtMR =
        ((Hummingbird_Flight_Controller_P.PIDController3_P *
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 +
          Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_j) +
         Hummingbird_Flight_Controller_B.V) * -Hummingbird_Flight_Controller_P.m;

      // Gain: '<S814>/Integral Gain'
      Hummingbird_Flight_Controller_B.IntegralGain_k =
        Hummingbird_Flight_Controller_P.PIDController3_I *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;

      // Gain: '<S866>/Integral Gain'
      Hummingbird_Flight_Controller_B.CastToDouble25_f =
        Hummingbird_Flight_Controller_P.PIDController5_I *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1;

      // MATLAB Function: '<S9>/MATLAB Function2' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double3'
      //   MATLAB Function: '<S780>/MATLAB Function2'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //
      Hummingbird_MATLABFunction2(static_cast<real_T>
        (Hummingbird_Flight_Controller_B.a_n), Hummingbird_Fligh_rt_atan2d_snf
        (Hummingbird_Flight_Controller_B.DProdOut_n[1] - (3.28084 *
        Hummingbird_Flight_Controller_B.current_lat[1] +
        Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.Y),
         Hummingbird_Flight_Controller_B.DProdOut_n[0] - (3.28084 *
        Hummingbird_Flight_Controller_B.current_lat[0] +
        Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.X)),
        &Hummingbird_Flight_Controller_B.course);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_pb);

      // Sum: '<S780>/Sum14' incorporates:
      //   BusCreator: '<S5>/Bus Creator9'

      Hummingbird_Flight_Controller_B.Filter_os[0] =
        Hummingbird_Flight_Controller_B.DProdOut_n[0] -
        Hummingbird_Flight_Controller_B.In1_a.lat;
      Hummingbird_Flight_Controller_B.Filter_os[1] =
        Hummingbird_Flight_Controller_B.DProdOut_n[1] -
        Hummingbird_Flight_Controller_B.In1_a.lon;
      Hummingbird_Flight_Controller_B.Filter_os[2] =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1;

      // Gain: '<S1101>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1093>/Filter'
      //   Gain: '<S1091>/Derivative Gain'
      //   Sum: '<S1093>/SumD'

      Hummingbird_Flight_Controller_B.scale =
        (Hummingbird_Flight_Controller_P.PIDController8_D[0] *
         Hummingbird_Flight_Controller_B.Filter_os[0] -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_b[0]) *
        Hummingbird_Flight_Controller_P.PIDController8_N;
      Hummingbird_Flight_Controller_B.DProdOut_n[0] =
        Hummingbird_Flight_Controller_B.scale;

      // Sum: '<S1107>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1098>/Integrator'
      //   Gain: '<S1091>/Derivative Gain'
      //   Gain: '<S1103>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        (Hummingbird_Flight_Controller_P.PIDController8_P[0] *
         Hummingbird_Flight_Controller_B.Filter_os[0] +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[0]) +
        Hummingbird_Flight_Controller_B.scale;

      // Gain: '<S1101>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1093>/Filter'
      //   Gain: '<S1091>/Derivative Gain'
      //   Sum: '<S1093>/SumD'

      Hummingbird_Flight_Controller_B.scale =
        (Hummingbird_Flight_Controller_P.PIDController8_D[1] *
         Hummingbird_Flight_Controller_B.Filter_os[1] -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_b[1]) *
        Hummingbird_Flight_Controller_P.PIDController8_N;
      Hummingbird_Flight_Controller_B.DProdOut_n[1] =
        Hummingbird_Flight_Controller_B.scale;

      // Sum: '<S1107>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1098>/Integrator'
      //   Gain: '<S1091>/Derivative Gain'
      //   Gain: '<S1103>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
        (Hummingbird_Flight_Controller_P.PIDController8_P[1] *
         Hummingbird_Flight_Controller_B.Filter_os[1] +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[1]) +
        Hummingbird_Flight_Controller_B.scale;

      // Gain: '<S1101>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1093>/Filter'
      //   Gain: '<S1091>/Derivative Gain'
      //   Sum: '<S1093>/SumD'
      //   Sum: '<S780>/Sum14'

      Hummingbird_Flight_Controller_B.scale =
        (Hummingbird_Flight_Controller_P.PIDController8_D[2] *
         Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_b[2]) *
        Hummingbird_Flight_Controller_P.PIDController8_N;

      // Sum: '<S1107>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1098>/Integrator'
      //   Gain: '<S1103>/Proportional Gain'
      //   Sum: '<S780>/Sum14'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        (Hummingbird_Flight_Controller_P.PIDController8_P[2] *
         Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[2]) +
        Hummingbird_Flight_Controller_B.scale;

      // MATLAB Function: '<S780>/MATLAB Function'
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_p[0] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_p[1] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1;
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        Hummingbird_Flight_Contr_norm_j
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_p);
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 > 30.0) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 /
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 * 30.0;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 /
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 * 30.0;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 /
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 * 30.0;
      }

      // Sum: '<S780>/Sum1' incorporates:
      //   BusCreator: '<S5>/Bus Creator4'

      Hummingbird_Flight_Controller_B.prev_waypoint[0] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;
      Hummingbird_Flight_Controller_B.prev_waypoint[1] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      Hummingbird_Flight_Controller_B.prev_waypoint[2] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2;

      // Gain: '<S1153>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1145>/Filter'
      //   Gain: '<S1143>/Derivative Gain'
      //   Sum: '<S1145>/SumD'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 =
        (Hummingbird_Flight_Controller_P.PIDController9_D[0] *
         Hummingbird_Flight_Controller_B.prev_waypoint[0] -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_e[0]) *
        Hummingbird_Flight_Controller_P.PIDController9_N;
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;

      // Sum: '<S1159>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1150>/Integrator'
      //   Gain: '<S1143>/Derivative Gain'
      //   Gain: '<S1155>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (Hummingbird_Flight_Controller_P.PIDController9_P[0] *
         Hummingbird_Flight_Controller_B.prev_waypoint[0] +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[0]) +
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;

      // Saturate: '<S1157>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturationL) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturationL;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerSaturationL)
      {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.PIDController9_LowerSaturationL;
      }

      // Gain: '<S1153>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1145>/Filter'
      //   Gain: '<S1143>/Derivative Gain'
      //   Sum: '<S1145>/SumD'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 =
        (Hummingbird_Flight_Controller_P.PIDController9_D[1] *
         Hummingbird_Flight_Controller_B.prev_waypoint[1] -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_e[1]) *
        Hummingbird_Flight_Controller_P.PIDController9_N;
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;

      // Sum: '<S1159>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1150>/Integrator'
      //   Gain: '<S1143>/Derivative Gain'
      //   Gain: '<S1155>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        (Hummingbird_Flight_Controller_P.PIDController9_P[1] *
         Hummingbird_Flight_Controller_B.prev_waypoint[1] +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[1]) +
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;

      // Saturate: '<S1157>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturationL) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturationL;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerSaturationL)
      {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_P.PIDController9_LowerSaturationL;
      }

      // Gain: '<S1153>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1145>/Filter'
      //   Gain: '<S1143>/Derivative Gain'
      //   Sum: '<S1145>/SumD'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 =
        (Hummingbird_Flight_Controller_P.PIDController9_D[2] *
         Hummingbird_Flight_Controller_B.prev_waypoint[2] -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_e[2]) *
        Hummingbird_Flight_Controller_P.PIDController9_N;

      // Sum: '<S1159>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1150>/Integrator'
      //   Gain: '<S1143>/Derivative Gain'
      //   Gain: '<S1155>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
        (Hummingbird_Flight_Controller_P.PIDController9_P[2] *
         Hummingbird_Flight_Controller_B.prev_waypoint[2] +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[2]) +
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;

      // Saturate: '<S1157>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturationL) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturationL;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerSaturationL)
      {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
          Hummingbird_Flight_Controller_P.PIDController9_LowerSaturationL;
      }

      // MATLAB Function: '<S780>/MATLAB Function1' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double3'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 = cos
        (static_cast<real_T>(Hummingbird_Flight_Controller_B.a_n));
      Hummingbird_Flight_Controller_B.t = sin(static_cast<real_T>
        (Hummingbird_Flight_Controller_B.a_n));
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 = asin
        ((-Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 *
          Hummingbird_Flight_Controller_B.t +
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 *
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1) / sqrt
         ((Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 *
           Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 +
           Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 *
           Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1) +
          (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 - 32.174) *
          (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 - 32.174)));

      // Saturate: '<S780>/Saturation1'
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 >
          Hummingbird_Flight_Controller_P.Saturation1_UpperSat_i) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_P.Saturation1_UpperSat_i;
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 <
                 Hummingbird_Flight_Controller_P.Saturation1_LowerSat_l) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_P.Saturation1_LowerSat_l;
      }

      // MATLAB Function: '<S780>/MATLAB Function1'
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 = atan
        ((-Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 *
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 -
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 *
          Hummingbird_Flight_Controller_B.t) / fabs
         (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 - 32.174));

      // Saturate: '<S780>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_p) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_p;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_l5) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_l5;
      }

      // BusAssignment: '<S890>/Bus Assignment' incorporates:
      //   Constant: '<S779>/Constant5'
      //   DataTypeConversion: '<S779>/Cast To Single16'
      //   DataTypeConversion: '<S779>/Cast To Single17'
      //   DataTypeConversion: '<S779>/Cast To Single18'
      //   MATLABSystem: '<S890>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_ov.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_pb.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_ov.roll =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment_ov.pitch = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_ov.yaw_rate = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.course);
      Hummingbird_Flight_Controller_B.BusAssignment_ov._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant5_Value_d[0];
      Hummingbird_Flight_Controller_B.BusAssignment_ov._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant5_Value_d[1];
      Hummingbird_Flight_Controller_B.BusAssignment_ov._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant5_Value_d[2];
      Hummingbird_Flight_Controller_B.BusAssignment_ov._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant5_Value_d[3];
      Hummingbird_Fligh_SinkBlock
        (&Hummingbird_Flight_Controller_B.BusAssignment_ov,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_ir);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_a);

      // Sum: '<S779>/Sum6' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double3'
      //   DataTypeConversion: '<S5>/Cast To Double4'
      //   DataTypeConversion: '<S5>/Cast To Double5'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0;
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1;
      Hummingbird_Flight_Controller_B.course -=
        Hummingbird_Flight_Controller_B.a_n;
      Hummin_ReadParameter1_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter1_o,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_o);
      Humming_ReadParameter_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter_o,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_o);
      Hummingb_ReadParameter2_b3r
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu5,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ayu5);
      Hummi_ReadParameter1_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter1_l,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_l);
      Hummin_ReadParameter_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter_l,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_l);
      Humming_ReadParameter2_b3rg
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu5d,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ayu5d);

      // Product: '<S1038>/NProd Out' incorporates:
      //   Constant: '<S779>/Constant4'
      //   DiscreteIntegrator: '<S1030>/Filter'
      //   Product: '<S1028>/DProd Out'
      //   Sum: '<S1030>/SumD'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 *
         Hummingbird_Flight_Controller_B.ReadParameter1_l.ReadParameter1_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_k[0]) *
        Hummingbird_Flight_Controller_P.Constant4_Value_e;
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 *
         Hummingbird_Flight_Controller_B.ReadParameter_l.ReadParameter_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_k[1]) *
        Hummingbird_Flight_Controller_P.Constant4_Value_e;
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
        (Hummingbird_Flight_Controller_B.course *
         Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu5d.ReadParameter2_o1
         - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_k[2]) *
        Hummingbird_Flight_Controller_P.Constant4_Value_e;

      // Sum: '<S1044>/Sum' incorporates:
      //   Product: '<S1040>/PProd Out'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 *
        Hummingbird_Flight_Controller_B.ReadParameter1_o.ReadParameter1_o1 +
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 *
        Hummingbird_Flight_Controller_B.ReadParameter_o.ReadParameter_o1 +
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1;
      Hummingbird_Flight_Controller_B.course =
        Hummingbird_Flight_Controller_B.course *
        Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu5.ReadParameter2_o1
        + Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2;

      // BusAssignment: '<S891>/Bus Assignment' incorporates:
      //   Constant: '<S779>/Constant6'
      //   DataTypeConversion: '<S779>/Cast To Single10'
      //   DataTypeConversion: '<S779>/Cast To Single11'
      //   DataTypeConversion: '<S779>/Cast To Single15'
      //   MATLABSystem: '<S891>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_mv.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_a.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_mv.roll_rate = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_mv.pitch_rate = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment_mv.yaw_rate =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.course);
      Hummingbird_Flight_Controller_B.BusAssignment_mv._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant6_Value[0];
      Hummingbird_Flight_Controller_B.BusAssignment_mv._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant6_Value[1];
      Hummingbird_Flight_Controller_B.BusAssignment_mv._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant6_Value[2];
      Hummingbird_Flight_Controller_B.BusAssignment_mv._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant6_Value[3];
      Hummingbird_Fli_SinkBlock_h
        (&Hummingbird_Flight_Controller_B.BusAssignment_mv,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_fv);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_ac);

      // Sum: '<S779>/Sum2' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double7'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 -=
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[0];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 -=
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[1];
      Hummingbird_Flight_Controller_B.course -=
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[2];

      // BusAssignment: '<S892>/Bus Assignment' incorporates:
      //   Constant: '<S779>/Constant1'
      //   DataTypeConversion: '<S779>/Cast To Single12'
      //   DataTypeConversion: '<S779>/Cast To Single13'
      //   DataTypeConversion: '<S779>/Cast To Single14'
      //   MATLABSystem: '<S892>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_f.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_ac.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_f.roll_rate_error =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_f.pitch_rate_error =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment_f.yaw_rate_error =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.course);
      Hummingbird_Flight_Controller_B.BusAssignment_f._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant1_Value_f[0];
      Hummingbird_Flight_Controller_B.BusAssignment_f._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant1_Value_f[1];
      Hummingbird_Flight_Controller_B.BusAssignment_f._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant1_Value_f[2];
      Hummingbird_Flight_Controller_B.BusAssignment_f._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant1_Value_f[3];
      Hummingbird_Fli_SinkBlock_j
        (&Hummingbird_Flight_Controller_B.BusAssignment_f,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_fw);
      Humm_ReadParameter1_b3rgaen
        (&Hummingbird_Flight_Controller_B.ReadParameter1_px,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_px);
      Hummi_ReadParameter_b3rgaen
        (&Hummingbird_Flight_Controller_B.ReadParameter_px,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_px);
      Hummin_ReadParameter2_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu5da,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ayu5da);
      Hum_ReadParameter1_b3rgaenb
        (&Hummingbird_Flight_Controller_B.ReadParameter1_i,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_i);
      Humm_ReadParameter_b3rgaenb
        (&Hummingbird_Flight_Controller_B.ReadParameter_i,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_i);
      Hummi_ReadParameter2_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter2_j,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_j);

      // Merge: '<S1>/ Merge 2' incorporates:
      //   BusCreator: '<S5>/Bus Creator6'
      //   Product: '<S936>/PProd Out'
      //   Product: '<S988>/PProd Out'
      //   Sum: '<S779>/Sum1'

      Hummingbird_Flight_Controller_B.dM[0] =
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 *
         Hummingbird_Flight_Controller_B.ReadParameter1_px.ReadParameter1_o1 -
         Hummingbird_Flight_Controller_B.Sum_e[0]) *
        Hummingbird_Flight_Controller_B.ReadParameter1_i.ReadParameter1_o1;
      Hummingbird_Flight_Controller_B.dM[1] =
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 *
         Hummingbird_Flight_Controller_B.ReadParameter_px.ReadParameter_o1 -
         Hummingbird_Flight_Controller_B.Sum_e[1]) *
        Hummingbird_Flight_Controller_B.ReadParameter_i.ReadParameter_o1;
      Hummingbird_Flight_Controller_B.dM[2] =
        (Hummingbird_Flight_Controller_B.course *
         Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu5da.ReadParameter2_o1
         - Hummingbird_Flight_Controller_B.Sum_e[2]) *
        Hummingbird_Flight_Controller_B.ReadParameter2_j.ReadParameter2_o1;

      // Update for DiscreteIntegrator: '<S869>/Integrator'
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_n +=
        Hummingbird_Flight_Controller_P.Integrator_gainval_n *
        Hummingbird_Flight_Controller_B.CastToDouble25_f;

      // Update for DiscreteIntegrator: '<S864>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_fu +=
        Hummingbird_Flight_Controller_P.Filter_gainval_k *
        Hummingbird_Flight_Controller_B.Esp_dot;

      // Update for DiscreteIntegrator: '<S817>/Integrator'
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_j +=
        Hummingbird_Flight_Controller_P.Integrator_gainval_m *
        Hummingbird_Flight_Controller_B.IntegralGain_k;

      // Update for DiscreteIntegrator: '<S812>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_l +=
        Hummingbird_Flight_Controller_P.Filter_gainval_i *
        Hummingbird_Flight_Controller_B.V;

      // Update for DiscreteIntegrator: '<S1098>/Integrator' incorporates:
      //   Gain: '<S1095>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_P.PIDController8_I *
        Hummingbird_Flight_Controller_B.Filter_os[0] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_b +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[0];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[0] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController8_UpperIntegratorS) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[0] =
          Hummingbird_Flight_Controller_P.PIDController8_UpperIntegratorS;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController8_LowerIntegratorS)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[0] =
          Hummingbird_Flight_Controller_P.PIDController8_LowerIntegratorS;
      }

      // Update for DiscreteIntegrator: '<S1093>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_b[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_e *
        Hummingbird_Flight_Controller_B.DProdOut_n[0];

      // Update for DiscreteIntegrator: '<S1150>/Integrator' incorporates:
      //   Gain: '<S1147>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_P.PIDController9_I[0] *
        Hummingbird_Flight_Controller_B.prev_waypoint[0] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_m2 +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[0];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[0] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegratorS) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[0] =
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegratorS;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerIntegratorS)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[0] =
          Hummingbird_Flight_Controller_P.PIDController9_LowerIntegratorS;
      }

      // Update for DiscreteIntegrator: '<S1145>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_e[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_l *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;

      // Update for DiscreteIntegrator: '<S1030>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_k[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_io *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;

      // Update for DiscreteIntegrator: '<S1098>/Integrator' incorporates:
      //   Gain: '<S1095>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_P.PIDController8_I *
        Hummingbird_Flight_Controller_B.Filter_os[1] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_b +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[1];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[1] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController8_UpperIntegratorS) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[1] =
          Hummingbird_Flight_Controller_P.PIDController8_UpperIntegratorS;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController8_LowerIntegratorS)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[1] =
          Hummingbird_Flight_Controller_P.PIDController8_LowerIntegratorS;
      }

      // Update for DiscreteIntegrator: '<S1093>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_b[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_e *
        Hummingbird_Flight_Controller_B.DProdOut_n[1];

      // Update for DiscreteIntegrator: '<S1150>/Integrator' incorporates:
      //   Gain: '<S1147>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_P.PIDController9_I[1] *
        Hummingbird_Flight_Controller_B.prev_waypoint[1] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_m2 +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[1];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[1] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegratorS) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[1] =
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegratorS;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerIntegratorS)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[1] =
          Hummingbird_Flight_Controller_P.PIDController9_LowerIntegratorS;
      }

      // Update for DiscreteIntegrator: '<S1145>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_e[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_l *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1;

      // Update for DiscreteIntegrator: '<S1030>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_k[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_io *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1;

      // Update for DiscreteIntegrator: '<S1098>/Integrator' incorporates:
      //   Gain: '<S1095>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_P.PIDController8_I *
        Hummingbird_Flight_Controller_B.Filter_os[2] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_b +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[2];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[2] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController8_UpperIntegratorS) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[2] =
          Hummingbird_Flight_Controller_P.PIDController8_UpperIntegratorS;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController8_LowerIntegratorS)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[2] =
          Hummingbird_Flight_Controller_P.PIDController8_LowerIntegratorS;
      }

      // Update for DiscreteIntegrator: '<S1093>/Filter' incorporates:
      //   Gain: '<S1101>/Filter Coefficient'

      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_b[2] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_e *
        Hummingbird_Flight_Controller_B.scale;

      // Update for DiscreteIntegrator: '<S1150>/Integrator' incorporates:
      //   Gain: '<S1147>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_P.PIDController9_I[2] *
        Hummingbird_Flight_Controller_B.prev_waypoint[2] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_m2 +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[2];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[2] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegratorS) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[2] =
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegratorS;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerIntegratorS)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[2] =
          Hummingbird_Flight_Controller_P.PIDController9_LowerIntegratorS;
      }

      // Update for DiscreteIntegrator: '<S1145>/Filter' incorporates:
      //   Gain: '<S1153>/Filter Coefficient'

      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_e[2] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_l *
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;

      // Update for DiscreteIntegrator: '<S1030>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_k[2] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_io *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2;
    } else if (Hummingbird_Flight_Controller_B.BusCreator.Flight_Mode > 1200) {
      Hummingbird_Flight_Controlle_DW.is_Flight_controller =
        Hummingbird_Flight_C_IN_MR_Vel1;

      // Merge: '<S1>/ Merge ' incorporates:
      //   Constant: '<S10>/Constant14'
      //   SignalConversion generated from: '<S10>/dtFW'

      Hummingbird_Flight_Controller_B.dtFW =
        Hummingbird_Flight_Controller_P.Constant14_Value_p;
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_d);

      // Sum: '<S1168>/Sum21' incorporates:
      //   BusCreator: '<S5>/Bus Creator4'
      //   Constant: '<S1402>/Constant'
      //   Gain: '<S1402>/Gain'
      //   Sum: '<S1402>/Sum'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
        (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Throttle)
         - Hummingbird_Flight_Controller_P.Constant_Value_f5) *
        Hummingbird_Flight_Controller_P.Gain_Gain_n -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2;
      Hummingb_ReadParameter_b3rg
        (&Hummingbird_Flight_Controller_B.ReadParameter_ld,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_ld);
      Humming_ReadParameter1_b3rg
        (&Hummingbird_Flight_Controller_B.ReadParameter1_ld,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_ld);

      // Product: '<S1211>/NProd Out' incorporates:
      //   Constant: '<S1168>/Constant'
      //   DiscreteIntegrator: '<S1203>/Filter'
      //   Product: '<S1201>/DProd Out'
      //   Sum: '<S1203>/SumD'

      Hummingbird_Flight_Controller_B.V =
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 *
         Hummingbird_Flight_Controller_B.ReadParameter1_ld.ReadParameter1_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_f) *
        Hummingbird_Flight_Controller_P.Constant_Value_p5;

      // Gain: '<S1168>/Gain5' incorporates:
      //   Product: '<S1213>/PProd Out'
      //   Sum: '<S1217>/Sum'

      Hummingbird_Flight_Controller_B.dtMR =
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 *
         Hummingbird_Flight_Controller_B.ReadParameter_ld.ReadParameter_o1 +
         Hummingbird_Flight_Controller_B.V) * -Hummingbird_Flight_Controller_P.m;

      // BusAssignment: '<S1171>/Bus Assignment' incorporates:
      //   Constant: '<S10>/Constant'
      //   Constant: '<S10>/Constant2'
      //   Constant: '<S10>/Constant7'
      //   Constant: '<S10>/Constant9'
      //   DataTypeConversion: '<S10>/Cast To Single'
      //   MATLABSystem: '<S1171>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_n.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_d.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_n.x =
        Hummingbird_Flight_Controller_P.Constant_Value_jh;
      Hummingbird_Flight_Controller_B.BusAssignment_n.y =
        Hummingbird_Flight_Controller_P.Constant2_Value_p;
      Hummingbird_Flight_Controller_B.BusAssignment_n.z = static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.dtMR);
      for (Hummingbird_Flight_Controller_B.i = 0;
           Hummingbird_Flight_Controller_B.i < 10;
           Hummingbird_Flight_Controller_B.i++) {
        Hummingbird_Flight_Controller_B.BusAssignment_n.name[Hummingbird_Flight_Controller_B.i]
          =
          Hummingbird_Flight_Controller_P.Constant7_Value_g[Hummingbird_Flight_Controller_B.i];
      }

      Hummingbird_Flight_Controller_B.BusAssignment_n._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant9_Value_c[0];
      Hummingbird_Flight_Controller_B.BusAssignment_n._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant9_Value_c[1];

      // MATLABSystem: '<S1399>/SinkBlock' incorporates:
      //   BusAssignment: '<S1171>/Bus Assignment'

      uORB_write_step(Hummingbird_Flight_Controlle_DW.obj_hh.orbMetadataObj,
                      &Hummingbird_Flight_Controlle_DW.obj_hh.orbAdvertiseObj,
                      &Hummingbird_Flight_Controller_B.BusAssignment_n);

      // MATLAB Function: '<S10>/MATLAB Function2' incorporates:
      //   Constant: '<S1405>/Constant'
      //   DataTypeConversion: '<S5>/Cast To Double3'
      //   Gain: '<S1172>/Gain'
      //   Gain: '<S1405>/Gain'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //   Sum: '<S1405>/Sum'
      //
      Hummingbird_MATLABFunction2(static_cast<real_T>
        (Hummingbird_Flight_Controller_B.a_n),
        Hummingbird_Flight_Controller_P.Gain_Gain_j2 *
        (Hummingbird_Flight_Controller_P.Gain_Gain_j * (static_cast<real_T>
        (Hummingbird_Flight_Controller_B.BusCreator.Yaw) -
        Hummingbird_Flight_Controller_P.Constant_Value_lu)),
        &Hummingbird_Flight_Controller_B.Esp_dot);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_g);

      // Sum: '<S1172>/Sum1' incorporates:
      //   BusCreator: '<S5>/Bus Creator4'
      //   Constant: '<S1403>/Constant'
      //   Constant: '<S1404>/Constant'
      //   Gain: '<S1172>/Gain1'
      //   Gain: '<S1172>/Gain2'
      //   Gain: '<S1403>/Gain'
      //   Gain: '<S1404>/Gain'
      //   Sum: '<S1403>/Sum'
      //   Sum: '<S1404>/Sum'

      Hummingbird_Flight_Controller_B.Filter_os[0] = (static_cast<real_T>
        (Hummingbird_Flight_Controller_B.BusCreator.Pitch) -
        Hummingbird_Flight_Controller_P.Constant_Value_mb) *
        Hummingbird_Flight_Controller_P.Gain_Gain_e *
        Hummingbird_Flight_Controller_P.Gain2_Gain_j -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;
      Hummingbird_Flight_Controller_B.Filter_os[1] = (static_cast<real_T>
        (Hummingbird_Flight_Controller_B.BusCreator.Roll) -
        Hummingbird_Flight_Controller_P.Constant_Value_mbi) *
        Hummingbird_Flight_Controller_P.Gain_Gain_d *
        Hummingbird_Flight_Controller_P.Gain1_Gain_b -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;

      // Gain: '<S1443>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1435>/Filter'
      //   Gain: '<S1433>/Derivative Gain'
      //   Sum: '<S1435>/SumD'

      Hummingbird_Flight_Controller_B.scale =
        (Hummingbird_Flight_Controller_P.PIDController9_D_d[0] *
         Hummingbird_Flight_Controller_B.Filter_os[0] -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_h[0]) *
        Hummingbird_Flight_Controller_P.PIDController9_N_j;
      Hummingbird_Flight_Controller_B.DProdOut_n[0] =
        Hummingbird_Flight_Controller_B.scale;

      // Sum: '<S1449>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1440>/Integrator'
      //   Gain: '<S1433>/Derivative Gain'
      //   Gain: '<S1445>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (Hummingbird_Flight_Controller_P.PIDController9_P_b[0] *
         Hummingbird_Flight_Controller_B.Filter_os[0] +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[0]) +
        Hummingbird_Flight_Controller_B.scale;

      // Saturate: '<S1447>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturatio_o) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturatio_o;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerSaturatio_a)
      {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.PIDController9_LowerSaturatio_a;
      }

      // Gain: '<S1443>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1435>/Filter'
      //   Gain: '<S1433>/Derivative Gain'
      //   Sum: '<S1435>/SumD'

      Hummingbird_Flight_Controller_B.scale =
        (Hummingbird_Flight_Controller_P.PIDController9_D_d[1] *
         Hummingbird_Flight_Controller_B.Filter_os[1] -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_h[1]) *
        Hummingbird_Flight_Controller_P.PIDController9_N_j;
      Hummingbird_Flight_Controller_B.DProdOut_n[1] =
        Hummingbird_Flight_Controller_B.scale;

      // Sum: '<S1449>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1440>/Integrator'
      //   Gain: '<S1433>/Derivative Gain'
      //   Gain: '<S1445>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        (Hummingbird_Flight_Controller_P.PIDController9_P_b[1] *
         Hummingbird_Flight_Controller_B.Filter_os[1] +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[1]) +
        Hummingbird_Flight_Controller_B.scale;

      // Saturate: '<S1447>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturatio_o) {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturatio_o;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerSaturatio_a)
      {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          Hummingbird_Flight_Controller_P.PIDController9_LowerSaturatio_a;
      }

      // Gain: '<S1443>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1435>/Filter'
      //   Gain: '<S1433>/Derivative Gain'
      //   Sum: '<S1172>/Sum1'
      //   Sum: '<S1435>/SumD'

      Hummingbird_Flight_Controller_B.scale =
        (Hummingbird_Flight_Controller_P.PIDController9_D_d[2] *
         Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_h[2]) *
        Hummingbird_Flight_Controller_P.PIDController9_N_j;

      // Sum: '<S1449>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1440>/Integrator'
      //   Gain: '<S1445>/Proportional Gain'
      //   Sum: '<S1172>/Sum1'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
        (Hummingbird_Flight_Controller_P.PIDController9_P_b[2] *
         Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[2]) +
        Hummingbird_Flight_Controller_B.scale;

      // Saturate: '<S1447>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturatio_o) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturatio_o;
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerSaturatio_a)
      {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          Hummingbird_Flight_Controller_P.PIDController9_LowerSaturatio_a;
      }

      // MATLAB Function: '<S1172>/MATLAB Function1' incorporates:
      //   Saturate: '<S1447>/Saturation'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 = asin
        ((-Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 * 0.0 +
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1) / sqrt
         ((Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 *
           Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 +
           Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 *
           Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1) +
          (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 - 32.174)
          * (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
             32.174)));

      // Saturate: '<S1172>/Saturation1'
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation1_UpperSat_a) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation1_UpperSat_a;
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation1_LowerSat_a) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation1_LowerSat_a;
      }

      // MATLAB Function: '<S1172>/MATLAB Function1' incorporates:
      //   Saturate: '<S1447>/Saturation'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 = atan
        ((-Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 -
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 * 0.0) / fabs
         (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 - 32.174));

      // Saturate: '<S1172>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_h) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_h;
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_a) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_a;
      }

      // BusAssignment: '<S1229>/Bus Assignment' incorporates:
      //   Constant: '<S1170>/Constant5'
      //   DataTypeConversion: '<S1170>/Cast To Single16'
      //   DataTypeConversion: '<S1170>/Cast To Single17'
      //   DataTypeConversion: '<S1170>/Cast To Single18'
      //   MATLABSystem: '<S1229>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_ip.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_g.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_ip.roll = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_ip.pitch =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_ip.yaw_rate =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.Esp_dot);
      Hummingbird_Flight_Controller_B.BusAssignment_ip._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant5_Value_l[0];
      Hummingbird_Flight_Controller_B.BusAssignment_ip._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant5_Value_l[1];
      Hummingbird_Flight_Controller_B.BusAssignment_ip._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant5_Value_l[2];
      Hummingbird_Flight_Controller_B.BusAssignment_ip._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant5_Value_l[3];
      Hummingbird_Fligh_SinkBlock
        (&Hummingbird_Flight_Controller_B.BusAssignment_ip,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_hd);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_j);

      // Sum: '<S1170>/Sum6' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double4'
      //   DataTypeConversion: '<S5>/Cast To Double5'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0;
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1;
      Hummin_ReadParameter1_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter1_k,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_k);
      Humming_ReadParameter_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter_k,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_k);
      Hummingb_ReadParameter2_b3r
        (&Hummingbird_Flight_Controller_B.ReadParameter2_o,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_o);
      Hummi_ReadParameter1_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter1_lu,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_lu);
      Hummin_ReadParameter_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter_lu,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_lu);
      Humming_ReadParameter2_b3rg
        (&Hummingbird_Flight_Controller_B.ReadParameter2_l,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_l);

      // Product: '<S1377>/NProd Out' incorporates:
      //   Constant: '<S1170>/Constant4'
      //   DiscreteIntegrator: '<S1369>/Filter'
      //   Product: '<S1367>/DProd Out'
      //   Sum: '<S1369>/SumD'

      Hummingbird_Flight_Controller_B.prev_waypoint[0] =
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 *
         Hummingbird_Flight_Controller_B.ReadParameter1_lu.ReadParameter1_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_c[0]) *
        Hummingbird_Flight_Controller_P.Constant4_Value_ey;
      Hummingbird_Flight_Controller_B.prev_waypoint[1] =
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 *
         Hummingbird_Flight_Controller_B.ReadParameter_lu.ReadParameter_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_c[1]) *
        Hummingbird_Flight_Controller_P.Constant4_Value_ey;

      // Sum: '<S1383>/Sum' incorporates:
      //   Product: '<S1379>/PProd Out'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 *
        Hummingbird_Flight_Controller_B.ReadParameter1_k.ReadParameter1_o1 +
        Hummingbird_Flight_Controller_B.prev_waypoint[0];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 *
        Hummingbird_Flight_Controller_B.ReadParameter_k.ReadParameter_o1 +
        Hummingbird_Flight_Controller_B.prev_waypoint[1];

      // BusAssignment: '<S1230>/Bus Assignment' incorporates:
      //   Constant: '<S1170>/Constant6'
      //   DataTypeConversion: '<S1170>/Cast To Single10'
      //   DataTypeConversion: '<S1170>/Cast To Single11'
      //   DataTypeConversion: '<S1170>/Cast To Single15'
      //   MATLABSystem: '<S1230>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_j.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_j.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_j.roll_rate =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_j.pitch_rate = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_j.yaw_rate =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.Esp_dot);
      Hummingbird_Flight_Controller_B.BusAssignment_j._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant6_Value_k[0];
      Hummingbird_Flight_Controller_B.BusAssignment_j._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant6_Value_k[1];
      Hummingbird_Flight_Controller_B.BusAssignment_j._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant6_Value_k[2];
      Hummingbird_Flight_Controller_B.BusAssignment_j._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant6_Value_k[3];
      Hummingbird_Fli_SinkBlock_h
        (&Hummingbird_Flight_Controller_B.BusAssignment_j,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_o);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_k);

      // Sum: '<S1170>/Sum2' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double7'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 -=
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[0];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -=
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[1];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        Hummingbird_Flight_Controller_B.Esp_dot -
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[2];

      // BusAssignment: '<S1231>/Bus Assignment' incorporates:
      //   Constant: '<S1170>/Constant1'
      //   DataTypeConversion: '<S1170>/Cast To Single12'
      //   DataTypeConversion: '<S1170>/Cast To Single13'
      //   DataTypeConversion: '<S1170>/Cast To Single14'
      //   MATLABSystem: '<S1231>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_i.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_k.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_i.roll_rate_error =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_i.pitch_rate_error =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_i.yaw_rate_error =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment_i._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant1_Value_fj[0];
      Hummingbird_Flight_Controller_B.BusAssignment_i._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant1_Value_fj[1];
      Hummingbird_Flight_Controller_B.BusAssignment_i._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant1_Value_fj[2];
      Hummingbird_Flight_Controller_B.BusAssignment_i._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant1_Value_fj[3];
      Hummingbird_Fli_SinkBlock_j
        (&Hummingbird_Flight_Controller_B.BusAssignment_i,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_jf);
      Humm_ReadParameter1_b3rgaen
        (&Hummingbird_Flight_Controller_B.ReadParameter1_m,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_m);
      Hummi_ReadParameter_b3rgaen
        (&Hummingbird_Flight_Controller_B.ReadParameter_m,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_m);
      Hummin_ReadParameter2_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter2_p,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_p);
      Hum_ReadParameter1_b3rgaenb
        (&Hummingbird_Flight_Controller_B.ReadParameter1_kh,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_kh);
      Humm_ReadParameter_b3rgaenb
        (&Hummingbird_Flight_Controller_B.ReadParameter_kh,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_kh);
      Hummi_ReadParameter2_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter2_i,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_i);

      // Merge: '<S1>/ Merge 2' incorporates:
      //   BusCreator: '<S5>/Bus Creator6'
      //   Product: '<S1275>/PProd Out'
      //   Product: '<S1327>/PProd Out'
      //   Sum: '<S1170>/Sum1'

      Hummingbird_Flight_Controller_B.dM[0] =
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 *
         Hummingbird_Flight_Controller_B.ReadParameter1_m.ReadParameter1_o1 -
         Hummingbird_Flight_Controller_B.Sum_e[0]) *
        Hummingbird_Flight_Controller_B.ReadParameter1_kh.ReadParameter1_o1;
      Hummingbird_Flight_Controller_B.dM[1] =
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 *
         Hummingbird_Flight_Controller_B.ReadParameter_m.ReadParameter_o1 -
         Hummingbird_Flight_Controller_B.Sum_e[1]) *
        Hummingbird_Flight_Controller_B.ReadParameter_kh.ReadParameter_o1;
      Hummingbird_Flight_Controller_B.dM[2] =
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 *
         Hummingbird_Flight_Controller_B.ReadParameter2_p.ReadParameter2_o1 -
         Hummingbird_Flight_Controller_B.Sum_e[2]) *
        Hummingbird_Flight_Controller_B.ReadParameter2_i.ReadParameter2_o1;

      // Update for DiscreteIntegrator: '<S1203>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_f +=
        Hummingbird_Flight_Controller_P.Filter_gainval_pt *
        Hummingbird_Flight_Controller_B.V;

      // Update for DiscreteIntegrator: '<S1440>/Integrator' incorporates:
      //   Gain: '<S1437>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        Hummingbird_Flight_Controller_P.PIDController9_I_i[0] *
        Hummingbird_Flight_Controller_B.Filter_os[0] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_ma +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[0];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[0] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegrato_e) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[0] =
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegrato_e;
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerIntegrato_p)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[0] =
          Hummingbird_Flight_Controller_P.PIDController9_LowerIntegrato_p;
      }

      // Update for DiscreteIntegrator: '<S1435>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_h[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_kc *
        Hummingbird_Flight_Controller_B.DProdOut_n[0];

      // Update for DiscreteIntegrator: '<S1369>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_c[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_o *
        Hummingbird_Flight_Controller_B.prev_waypoint[0];

      // Update for DiscreteIntegrator: '<S1440>/Integrator' incorporates:
      //   Gain: '<S1437>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        Hummingbird_Flight_Controller_P.PIDController9_I_i[1] *
        Hummingbird_Flight_Controller_B.Filter_os[1] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_ma +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[1];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[1] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegrato_e) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[1] =
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegrato_e;
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerIntegrato_p)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[1] =
          Hummingbird_Flight_Controller_P.PIDController9_LowerIntegrato_p;
      }

      // Update for DiscreteIntegrator: '<S1435>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_h[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_kc *
        Hummingbird_Flight_Controller_B.DProdOut_n[1];

      // Update for DiscreteIntegrator: '<S1369>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_c[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_o *
        Hummingbird_Flight_Controller_B.prev_waypoint[1];

      // Update for DiscreteIntegrator: '<S1440>/Integrator' incorporates:
      //   Gain: '<S1437>/Integral Gain'
      //   Sum: '<S1172>/Sum1'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        Hummingbird_Flight_Controller_P.PIDController9_I_i[2] *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 *
        Hummingbird_Flight_Controller_P.Integrator_gainval_ma +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[2];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[2] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegrato_e) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[2] =
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegrato_e;
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerIntegrato_p)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[2] =
          Hummingbird_Flight_Controller_P.PIDController9_LowerIntegrato_p;
      }

      // Update for DiscreteIntegrator: '<S1435>/Filter' incorporates:
      //   Gain: '<S1443>/Filter Coefficient'

      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_h[2] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_kc *
        Hummingbird_Flight_Controller_B.scale;

      // Update for DiscreteIntegrator: '<S1369>/Filter' incorporates:
      //   Constant: '<S1170>/Constant4'
      //   DataTypeConversion: '<S5>/Cast To Double3'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //   Product: '<S1367>/DProd Out'
      //   Product: '<S1377>/NProd Out'
      //   Sum: '<S1170>/Sum6'
      //   Sum: '<S1369>/SumD'
      //
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_c[2] +=
        ((Hummingbird_Flight_Controller_B.Esp_dot -
          Hummingbird_Flight_Controller_B.a_n) *
         Hummingbird_Flight_Controller_B.ReadParameter2_l.ReadParameter2_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_c[2]) *
        Hummingbird_Flight_Controller_P.Constant4_Value_ey *
        Hummingbird_Flight_Controller_P.Filter_gainval_o;
    } else {
      Hummingbird_Flight_Controlle_DW.is_Flight_controller =
        Hummingbird_Flig_IN_MR_Attitude;

      // Merge: '<S1>/ Merge ' incorporates:
      //   Constant: '<S8>/Constant14'
      //   SignalConversion generated from: '<S8>/dtFW'

      Hummingbird_Flight_Controller_B.dtFW =
        Hummingbird_Flight_Controller_P.Constant14_Value;

      // Sum: '<S545>/Sum21' incorporates:
      //   BusCreator: '<S5>/Bus Creator4'
      //   Constant: '<S773>/Constant'
      //   Gain: '<S773>/Gain'
      //   Sum: '<S773>/Sum'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 = (
        static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Throttle)
        - Hummingbird_Flight_Controller_P.Constant_Value_ct) *
        Hummingbird_Flight_Controller_P.Gain_Gain -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2;
      Hummingb_ReadParameter_b3rg
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ayu);
      Humming_ReadParameter1_b3rg
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ayu);

      // Product: '<S586>/NProd Out' incorporates:
      //   Constant: '<S545>/Constant'
      //   DiscreteIntegrator: '<S578>/Filter'
      //   Product: '<S576>/DProd Out'
      //   Sum: '<S578>/SumD'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 *
         Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu.ReadParameter1_o1
         - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_j) *
        Hummingbird_Flight_Controller_P.Constant_Value_fn;

      // Gain: '<S1168>/Gain5' incorporates:
      //   Gain: '<S545>/Gain5'
      //   Merge: '<S1>/ Merge 1'
      //   Product: '<S588>/PProd Out'
      //   Sum: '<S592>/Sum'

      Hummingbird_Flight_Controller_B.dtMR =
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 *
         Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu.ReadParameter_o1
         + Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0) *
        -Hummingbird_Flight_Controller_P.m;
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_m);

      // Gain: '<S547>/Gain1' incorporates:
      //   Constant: '<S774>/Constant'
      //   Gain: '<S774>/Gain'
      //   Sum: '<S774>/Sum'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Roll) -
         Hummingbird_Flight_Controller_P.Constant_Value_ag) *
        Hummingbird_Flight_Controller_P.Gain_Gain_m *
        Hummingbird_Flight_Controller_P.Gain1_Gain_h;

      // Saturate: '<S547>/Saturation1'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation1_UpperSat) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation1_UpperSat;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation1_LowerSat) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation1_LowerSat;
      }

      // Gain: '<S547>/Gain2' incorporates:
      //   Constant: '<S775>/Constant'
      //   Gain: '<S775>/Gain'
      //   Sum: '<S775>/Sum'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Pitch) -
         Hummingbird_Flight_Controller_P.Constant_Value_oq) *
        Hummingbird_Flight_Controller_P.Gain_Gain_i *
        Hummingbird_Flight_Controller_P.Gain2_Gain_c;

      // Saturate: '<S547>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_l) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_l;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_f) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_f;
      }

      // Gain: '<S547>/Gain' incorporates:
      //   Constant: '<S776>/Constant'
      //   Gain: '<S776>/Gain'
      //   Sum: '<S776>/Sum'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 = (
        static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Yaw) -
        Hummingbird_Flight_Controller_P.Constant_Value_l4) *
        Hummingbird_Flight_Controller_P.Gain_Gain_o *
        Hummingbird_Flight_Controller_P.Gain_Gain_ii;

      // BusAssignment: '<S604>/Bus Assignment' incorporates:
      //   Constant: '<S546>/Constant2'
      //   DataTypeConversion: '<S546>/Cast To Single7'
      //   DataTypeConversion: '<S546>/Cast To Single8'
      //   DataTypeConversion: '<S546>/Cast To Single9'
      //   MATLABSystem: '<S604>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_d.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_m.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_d.roll =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_d.pitch =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_d.yaw_rate =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_d._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant2_Value_b[0];
      Hummingbird_Flight_Controller_B.BusAssignment_d._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant2_Value_b[1];
      Hummingbird_Flight_Controller_B.BusAssignment_d._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant2_Value_b[2];
      Hummingbird_Flight_Controller_B.BusAssignment_d._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant2_Value_b[3];
      Hummingbird_Fligh_SinkBlock
        (&Hummingbird_Flight_Controller_B.BusAssignment_d,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_lp);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_ef);

      // Sum: '<S546>/Sum5' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double4'
      //   DataTypeConversion: '<S5>/Cast To Double5'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //
      Hummingbird_Flight_Controller_B.prev_waypoint[0] =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0;
      Hummingbird_Flight_Controller_B.prev_waypoint[1] =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1;
      Hummin_ReadParameter1_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu5,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ayu5);
      Humming_ReadParameter_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu5,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ayu5);
      Hummingb_ReadParameter2_b3r
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3);
      Hummi_ReadParameter1_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu5d,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ayu5d);
      Hummin_ReadParameter_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu5d,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ayu5d);
      Humming_ReadParameter2_b3rg
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3a,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3a);

      // Product: '<S700>/NProd Out' incorporates:
      //   Constant: '<S546>/Constant1'
      //   DiscreteIntegrator: '<S692>/Filter'
      //   Product: '<S690>/DProd Out'
      //   Sum: '<S692>/SumD'

      Hummingbird_Flight_Controller_B.Filter_os[0] =
        (Hummingbird_Flight_Controller_B.prev_waypoint[0] *
         Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu5d.ReadParameter1_o1
         - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_bl[0]) *
        Hummingbird_Flight_Controller_P.Constant1_Value_d;
      Hummingbird_Flight_Controller_B.Filter_os[1] =
        (Hummingbird_Flight_Controller_B.prev_waypoint[1] *
         Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu5d.ReadParameter_o1
         - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_bl[1]) *
        Hummingbird_Flight_Controller_P.Constant1_Value_d;

      // Sum: '<S706>/Sum' incorporates:
      //   Product: '<S702>/PProd Out'

      Hummingbird_Flight_Controller_B.DProdOut_n[0] =
        Hummingbird_Flight_Controller_B.prev_waypoint[0] *
        Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu5.ReadParameter1_o1
        + Hummingbird_Flight_Controller_B.Filter_os[0];
      Hummingbird_Flight_Controller_B.DProdOut_n[1] =
        Hummingbird_Flight_Controller_B.prev_waypoint[1] *
        Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu5.ReadParameter_o1
        + Hummingbird_Flight_Controller_B.Filter_os[1];

      // BusAssignment: '<S605>/Bus Assignment' incorporates:
      //   Constant: '<S546>/Constant3'
      //   DataTypeConversion: '<S546>/Cast To Single1'
      //   DataTypeConversion: '<S546>/Cast To Single2'
      //   DataTypeConversion: '<S546>/Cast To Single6'
      //   MATLABSystem: '<S605>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_kl.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_ef.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_kl.roll_rate =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[0]);
      Hummingbird_Flight_Controller_B.BusAssignment_kl.pitch_rate =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[1]);
      Hummingbird_Flight_Controller_B.BusAssignment_kl.yaw_rate = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_kl._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant3_Value_i[0];
      Hummingbird_Flight_Controller_B.BusAssignment_kl._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant3_Value_i[1];
      Hummingbird_Flight_Controller_B.BusAssignment_kl._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant3_Value_i[2];
      Hummingbird_Flight_Controller_B.BusAssignment_kl._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant3_Value_i[3];
      Hummingbird_Fli_SinkBlock_h
        (&Hummingbird_Flight_Controller_B.BusAssignment_kl,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_d);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_cf);

      // Sum: '<S546>/Sum4' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double7'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        Hummingbird_Flight_Controller_B.DProdOut_n[0];
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        Hummingbird_Flight_Controller_B.DProdOut_n[1];
      Hummingbird_Flight_Controller_B.DProdOut_n[0] =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 -
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[0];
      Hummingbird_Flight_Controller_B.DProdOut_n[1] =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 -
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[1];
      Hummingbird_Flight_Controller_B.DProdOut_n[2] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[2];

      // BusAssignment: '<S606>/Bus Assignment' incorporates:
      //   Constant: '<S546>/Constant'
      //   DataTypeConversion: '<S546>/Cast To Single3'
      //   DataTypeConversion: '<S546>/Cast To Single4'
      //   DataTypeConversion: '<S546>/Cast To Single5'
      //   MATLABSystem: '<S606>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_ox.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_cf.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_ox.roll_rate_error =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[0]);
      Hummingbird_Flight_Controller_B.BusAssignment_ox.pitch_rate_error =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[1]);
      Hummingbird_Flight_Controller_B.BusAssignment_ox.yaw_rate_error =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[2]);
      Hummingbird_Flight_Controller_B.BusAssignment_ox._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant_Value_pq[0];
      Hummingbird_Flight_Controller_B.BusAssignment_ox._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant_Value_pq[1];
      Hummingbird_Flight_Controller_B.BusAssignment_ox._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant_Value_pq[2];
      Hummingbird_Flight_Controller_B.BusAssignment_ox._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant_Value_pq[3];
      Hummingbird_Fli_SinkBlock_j
        (&Hummingbird_Flight_Controller_B.BusAssignment_ox,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_a);
      Humm_ReadParameter1_b3rgaen
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu5da,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ayu5da);
      Hummi_ReadParameter_b3rgaen
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu5da,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ayu5da);
      Hummin_ReadParameter2_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ay,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ay);
      Hum_ReadParameter1_b3rgaenb
        (&Hummingbird_Flight_Controller_B.ReadParameter1_j,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_j);
      Humm_ReadParameter_b3rgaenb
        (&Hummingbird_Flight_Controller_B.ReadParameter_j,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_j);
      Hummi_ReadParameter2_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ayu);

      // Merge: '<S1>/ Merge 2' incorporates:
      //   BusCreator: '<S5>/Bus Creator6'
      //   Product: '<S650>/PProd Out'
      //   Product: '<S754>/PProd Out'
      //   Sum: '<S546>/Sum3'

      Hummingbird_Flight_Controller_B.dM[0] =
        (Hummingbird_Flight_Controller_B.DProdOut_n[0] *
         Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu5da.ReadParameter1_o1
         - Hummingbird_Flight_Controller_B.Sum_e[0]) *
        Hummingbird_Flight_Controller_B.ReadParameter1_j.ReadParameter1_o1;
      Hummingbird_Flight_Controller_B.dM[1] =
        (Hummingbird_Flight_Controller_B.DProdOut_n[1] *
         Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu5da.ReadParameter_o1
         - Hummingbird_Flight_Controller_B.Sum_e[1]) *
        Hummingbird_Flight_Controller_B.ReadParameter_j.ReadParameter_o1;
      Hummingbird_Flight_Controller_B.dM[2] =
        (Hummingbird_Flight_Controller_B.DProdOut_n[2] *
         Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ay.ReadParameter2_o1
         - Hummingbird_Flight_Controller_B.Sum_e[2]) *
        Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu.ReadParameter2_o1;

      // Update for DiscreteIntegrator: '<S578>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_j +=
        Hummingbird_Flight_Controller_P.Filter_gainval_d *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;

      // Update for DiscreteIntegrator: '<S692>/Filter' incorporates:
      //   Constant: '<S546>/Constant1'
      //   DataTypeConversion: '<S5>/Cast To Double3'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //   Product: '<S690>/DProd Out'
      //   Product: '<S700>/NProd Out'
      //   Sum: '<S546>/Sum5'
      //   Sum: '<S692>/SumD'
      //
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_bl[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_p *
        Hummingbird_Flight_Controller_B.Filter_os[0];
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_bl[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_p *
        Hummingbird_Flight_Controller_B.Filter_os[1];
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_bl[2] +=
        ((Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
          Hummingbird_Flight_Controller_B.a_n) *
         Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3a.ReadParameter2_o1
         - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_bl[2]) *
        Hummingbird_Flight_Controller_P.Constant1_Value_d *
        Hummingbird_Flight_Controller_P.Filter_gainval_p;
    }
  } else if ((Hummingbird_Flight_Controller_B.RC_Flight_Mode_prev_g !=
              Hummingbird_Flight_Controlle_DW.RC_Flight_Mode_start_m) ||
             (Hummingbird_Flight_Controller_B.RC_VTOL_Mode_prev_i !=
              Hummingbird_Flight_Controlle_DW.RC_VTOL_Mode_start_l)) {
    if (Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode < 1200) {
      if (Hummingbird_Flight_Controller_B.BusCreator.Flight_Mode > 1800) {
        exit_internal_Flight_controller();
        Hummingbird_Flight_Controlle_DW.is_Flight_controller =
          Hummingbir_IN_Set_mission_start;
        Hummingbird_Flight_Controlle_DW.mission_start[0] =
          Hummingbird_Flight_Controller_B.In1_a.lat;
        Hummingbird_Flight_Controlle_DW.mission_start[1] =
          Hummingbird_Flight_Controller_B.In1_a.lon;
        Hummingbird_Flight_Controlle_DW.mission_start[2] =
          Hummingbird_Flight_Controller_B.CastToDouble25_f;
      } else {
        exit_internal_Flight_controller();
        Hummingbird_Flight_Controlle_DW.is_Flight_controller =
          Hummingbird_Fli_IN_FW_Stabilize;

        // Merge: '<S1>/ Merge ' incorporates:
        //   Constant: '<S7>/Constant10'
        //   SignalConversion generated from: '<S7>/dtFW'

        Hummingbird_Flight_Controller_B.dtFW =
          Hummingbird_Flight_Controller_P.Constant10_Value;

        // Gain: '<S1168>/Gain5' incorporates:
        //   Constant: '<S7>/Constant11'
        //   Merge: '<S1>/ Merge 1'
        //   SignalConversion generated from: '<S7>/dtMR'

        Hummingbird_Flight_Controller_B.dtMR =
          Hummingbird_Flight_Controller_P.Constant11_Value_b;
        Hummingbird_Fl_PX4Timestamp
          (&Hummingbird_Flight_Controller_B.PX4Timestamp_l);

        // Gain: '<S376>/Gain10' incorporates:
        //   Constant: '<S376>/Constant7'
        //   Sum: '<S376>/Sum8'

        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Roll)
           - Hummingbird_Flight_Controller_P.Constant7_Value_l) *
          Hummingbird_Flight_Controller_P.Gain10_Gain_e;

        // Saturate: '<S376>/Saturation'
        if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_k) {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_k;
        } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                   Hummingbird_Flight_Controller_P.Saturation_LowerSat_i) {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
            Hummingbird_Flight_Controller_P.Saturation_LowerSat_i;
        }

        // Gain: '<S367>/Gain1' incorporates:
        //   Saturate: '<S376>/Saturation'

        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
          Hummingbird_Flight_Controller_P.Gain1_Gain_j *
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;

        // Gain: '<S377>/Gain10' incorporates:
        //   Constant: '<S377>/Constant7'
        //   Sum: '<S377>/Sum8'

        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Pitch)
           - Hummingbird_Flight_Controller_P.Constant7_Value_m) *
          Hummingbird_Flight_Controller_P.Gain10_Gain_j;

        // Saturate: '<S377>/Saturation'
        if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_n) {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_n;
        } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                   Hummingbird_Flight_Controller_P.Saturation_LowerSat_l) {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
            Hummingbird_Flight_Controller_P.Saturation_LowerSat_l;
        }

        // Gain: '<S367>/Gain2' incorporates:
        //   Saturate: '<S377>/Saturation'

        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          Hummingbird_Flight_Controller_P.Gain2_Gain_l *
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;

        // Gain: '<S378>/Gain10' incorporates:
        //   Constant: '<S378>/Constant7'
        //   Sum: '<S378>/Sum8'

        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Yaw) -
           Hummingbird_Flight_Controller_P.Constant7_Value_ne) *
          Hummingbird_Flight_Controller_P.Gain10_Gain_m;

        // Saturate: '<S378>/Saturation'
        if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_j) {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_j;
        } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                   Hummingbird_Flight_Controller_P.Saturation_LowerSat_ly) {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
            Hummingbird_Flight_Controller_P.Saturation_LowerSat_ly;
        }

        // Gain: '<S367>/Gain3' incorporates:
        //   Saturate: '<S378>/Saturation'

        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 *=
          Hummingbird_Flight_Controller_P.Gain3_Gain_j;

        // Sum: '<S367>/Sum' incorporates:
        //   BusCreator generated from: '<Root>/Chart'
        //   Gain: '<S367>/Gain4'
        //   Product: '<S367>/Divide'
        //   Trigonometry: '<S367>/Trigonometric Function1'
        //   Trigonometry: '<S367>/Trigonometric Function3'

        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_P.Gain4_Gain_n * tan
          (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0) * cos
          (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1) /
          Hummingbird_Flight_Controller_B.CastToDouble8 +
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;

        // BusAssignment: '<S372>/Bus Assignment' incorporates:
        //   Constant: '<S367>/Constant2'
        //   DataTypeConversion: '<S367>/Cast To Single7'
        //   DataTypeConversion: '<S367>/Cast To Single8'
        //   DataTypeConversion: '<S367>/Cast To Single9'
        //   MATLABSystem: '<S372>/PX4 Timestamp'

        Hummingbird_Flight_Controller_B.BusAssignment_nb.timestamp =
          Hummingbird_Flight_Controller_B.PX4Timestamp_l.PX4Timestamp;
        Hummingbird_Flight_Controller_B.BusAssignment_nb.roll =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);
        Hummingbird_Flight_Controller_B.BusAssignment_nb.pitch =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
        Hummingbird_Flight_Controller_B.BusAssignment_nb.yaw_rate =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1);
        Hummingbird_Flight_Controller_B.BusAssignment_nb._padding0[0] =
          Hummingbird_Flight_Controller_P.Constant2_Value_j[0];
        Hummingbird_Flight_Controller_B.BusAssignment_nb._padding0[1] =
          Hummingbird_Flight_Controller_P.Constant2_Value_j[1];
        Hummingbird_Flight_Controller_B.BusAssignment_nb._padding0[2] =
          Hummingbird_Flight_Controller_P.Constant2_Value_j[2];
        Hummingbird_Flight_Controller_B.BusAssignment_nb._padding0[3] =
          Hummingbird_Flight_Controller_P.Constant2_Value_j[3];
        Hummingbird_Fligh_SinkBlock
          (&Hummingbird_Flight_Controller_B.BusAssignment_nb,
           &Hummingbird_Flight_Controlle_DW.SinkBlock_l);
        Hummingbird_Fl_PX4Timestamp
          (&Hummingbird_Flight_Controller_B.PX4Timestamp_p5);

        // Sum: '<S367>/Sum5' incorporates:
        //   DataTypeConversion: '<S5>/Cast To Double3'
        //   DataTypeConversion: '<S5>/Cast To Double4'
        //   DataTypeConversion: '<S5>/Cast To Double5'
        //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
        //
        Hummingbird_Flight_Controller_B.prev_waypoint[0] =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 -
          Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0;
        Hummingbird_Flight_Controller_B.prev_waypoint[1] =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
          Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1;
        Hummingbird_Flight_Controller_B.prev_waypoint[2] =
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 -
          Hummingbird_Flight_Controller_B.a_n;
        Hummingbird__ReadParameter1
          (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb,
           &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb);
        Hummingbird_F_ReadParameter
          (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb,
           &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb);
        Hummingbir_ReadParameter1_b
          (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3,
           &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3);
        Hummingbird_ReadParameter_b
          (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3,
           &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3);

        // Product: '<S472>/NProd Out' incorporates:
        //   Constant: '<S367>/Constant1'
        //   Constant: '<S379>/Constant'
        //   DiscreteIntegrator: '<S464>/Filter'
        //   Product: '<S462>/DProd Out'
        //   Sum: '<S464>/SumD'

        Hummingbird_Flight_Controller_B.Filter_os[0] =
          (Hummingbird_Flight_Controller_B.prev_waypoint[0] *
           Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3.ReadParameter1_o1
           - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_d[0]) *
          Hummingbird_Flight_Controller_P.Constant1_Value_c;
        Hummingbird_Flight_Controller_B.Filter_os[1] =
          (Hummingbird_Flight_Controller_B.prev_waypoint[1] *
           Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3.ReadParameter_o1
           - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_d[1]) *
          Hummingbird_Flight_Controller_P.Constant1_Value_c;
        Hummingbird_Flight_Controller_B.Filter_os[2] =
          (Hummingbird_Flight_Controller_B.prev_waypoint[2] *
           Hummingbird_Flight_Controller_P.Constant_Value_bs -
           Hummingbird_Flight_Controlle_DW.Filter_DSTATE_d[2]) *
          Hummingbird_Flight_Controller_P.Constant1_Value_c;

        // Sum: '<S478>/Sum' incorporates:
        //   Constant: '<S375>/Constant'
        //   Product: '<S474>/PProd Out'

        Hummingbird_Flight_Controller_B.DProdOut_n[0] =
          Hummingbird_Flight_Controller_B.prev_waypoint[0] *
          Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb.ReadParameter1_o1
          + Hummingbird_Flight_Controller_B.Filter_os[0];
        Hummingbird_Flight_Controller_B.DProdOut_n[1] =
          Hummingbird_Flight_Controller_B.prev_waypoint[1] *
          Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb.ReadParameter_o1
          + Hummingbird_Flight_Controller_B.Filter_os[1];
        Hummingbird_Flight_Controller_B.DProdOut_n[2] =
          Hummingbird_Flight_Controller_B.prev_waypoint[2] *
          Hummingbird_Flight_Controller_P.Constant_Value_lw +
          Hummingbird_Flight_Controller_B.Filter_os[2];

        // MATLAB Function: '<S367>/MATLAB Function'
        Hummingbird__MATLABFunction
          (&Hummingbird_Flight_Controller_B.BusConversion_InsertedFor_Chart,
           &Hummingbird_Flight_Controller_B.DProdOut_n[0],
           Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1,
           Hummingbird_Flight_Controller_B.prev_waypoint,
           &Hummingbird_Flight_Controller_B.sf_MATLABFunction_b);

        // BusAssignment: '<S373>/Bus Assignment' incorporates:
        //   Constant: '<S367>/Constant3'
        //   DataTypeConversion: '<S367>/Cast To Single1'
        //   DataTypeConversion: '<S367>/Cast To Single2'
        //   DataTypeConversion: '<S367>/Cast To Single6'
        //   MATLABSystem: '<S373>/PX4 Timestamp'

        Hummingbird_Flight_Controller_B.BusAssignment_j1.timestamp =
          Hummingbird_Flight_Controller_B.PX4Timestamp_p5.PX4Timestamp;
        Hummingbird_Flight_Controller_B.BusAssignment_j1.roll_rate =
          static_cast<real32_T>(Hummingbird_Flight_Controller_B.prev_waypoint[0]);
        Hummingbird_Flight_Controller_B.BusAssignment_j1.pitch_rate =
          static_cast<real32_T>(Hummingbird_Flight_Controller_B.prev_waypoint[1]);
        Hummingbird_Flight_Controller_B.BusAssignment_j1.yaw_rate = static_cast<
          real32_T>(Hummingbird_Flight_Controller_B.prev_waypoint[2]);
        Hummingbird_Flight_Controller_B.BusAssignment_j1._padding0[0] =
          Hummingbird_Flight_Controller_P.Constant3_Value_c[0];
        Hummingbird_Flight_Controller_B.BusAssignment_j1._padding0[1] =
          Hummingbird_Flight_Controller_P.Constant3_Value_c[1];
        Hummingbird_Flight_Controller_B.BusAssignment_j1._padding0[2] =
          Hummingbird_Flight_Controller_P.Constant3_Value_c[2];
        Hummingbird_Flight_Controller_B.BusAssignment_j1._padding0[3] =
          Hummingbird_Flight_Controller_P.Constant3_Value_c[3];
        Hummingbird_Fli_SinkBlock_h
          (&Hummingbird_Flight_Controller_B.BusAssignment_j1,
           &Hummingbird_Flight_Controlle_DW.SinkBlock_c);
        Hummingbird_Fl_PX4Timestamp
          (&Hummingbird_Flight_Controller_B.PX4Timestamp_ct);

        // Sum: '<S367>/Sum4' incorporates:
        //   DataTypeConversion: '<S5>/Cast To Double7'

        Hummingbird_Flight_Controller_B.DProdOut_n[0] =
          Hummingbird_Flight_Controller_B.prev_waypoint[0] -
          Hummingbird_Flight_Controller_B.In1_f.gyro_rad[0];
        Hummingbird_Flight_Controller_B.DProdOut_n[1] =
          Hummingbird_Flight_Controller_B.prev_waypoint[1] -
          Hummingbird_Flight_Controller_B.In1_f.gyro_rad[1];
        Hummingbird_Flight_Controller_B.DProdOut_n[2] =
          Hummingbird_Flight_Controller_B.prev_waypoint[2] -
          Hummingbird_Flight_Controller_B.In1_f.gyro_rad[2];
        Hummingbi_ReadParameter1_b3
          (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3a,
           &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3a);
        Hummingbir_ReadParameter_b3
          (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3a,
           &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3a);
        Hummingbird__ReadParameter2
          (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgae,
           &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgae);
        Hummingbir_ReadParameter3_b
          (&Hummingbird_Flight_Controller_B.ReadParameter3_b3,
           &Hummingbird_Flight_Controlle_DW.ReadParameter3_b3);
        Hummingbir_ReadParameter2_b
          (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaen,
           &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaen);
        Hummingbird__ReadParameter4
          (&Hummingbird_Flight_Controller_B.ReadParameter4_b,
           &Hummingbird_Flight_Controlle_DW.ReadParameter4_b);

        // Product: '<S420>/NProd Out' incorporates:
        //   Constant: '<S367>/Constant4'
        //   DiscreteIntegrator: '<S412>/Filter'
        //   Product: '<S410>/DProd Out'
        //   Sum: '<S412>/SumD'

        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          (Hummingbird_Flight_Controller_B.DProdOut_n[0] *
           Hummingbird_Flight_Controller_B.ReadParameter3_b3.ReadParameter3_o1 -
           Hummingbird_Flight_Controlle_DW.Filter_DSTATE_p[0]) *
          Hummingbird_Flight_Controller_P.Constant4_Value_p;
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          (Hummingbird_Flight_Controller_B.DProdOut_n[1] *
           Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaen.ReadParameter2_o1
           - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_p[1]) *
          Hummingbird_Flight_Controller_P.Constant4_Value_p;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
          (Hummingbird_Flight_Controller_B.DProdOut_n[2] *
           Hummingbird_Flight_Controller_B.ReadParameter4_b.ReadParameter4_o1 -
           Hummingbird_Flight_Controlle_DW.Filter_DSTATE_p[2]) *
          Hummingbird_Flight_Controller_P.Constant4_Value_p;

        // Sum: '<S426>/Sum' incorporates:
        //   Product: '<S422>/PProd Out'

        Hummingbird_Flight_Controller_B.prev_waypoint[0] =
          Hummingbird_Flight_Controller_B.DProdOut_n[0] *
          Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3a.ReadParameter1_o1
          + Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1;
        Hummingbird_Flight_Controller_B.prev_waypoint[1] =
          Hummingbird_Flight_Controller_B.DProdOut_n[1] *
          Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3a.ReadParameter_o1
          + Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;
        Hummingbird_Flight_Controller_B.prev_waypoint[2] =
          Hummingbird_Flight_Controller_B.DProdOut_n[2] *
          Hummingbird_Flight_Controller_B.ReadParameter2_b3rgae.ReadParameter2_o1
          + Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;

        // BusAssignment: '<S374>/Bus Assignment' incorporates:
        //   Constant: '<S367>/Constant'
        //   DataTypeConversion: '<S367>/Cast To Single3'
        //   DataTypeConversion: '<S367>/Cast To Single4'
        //   DataTypeConversion: '<S367>/Cast To Single5'
        //   MATLABSystem: '<S374>/PX4 Timestamp'

        Hummingbird_Flight_Controller_B.BusAssignment_ia.timestamp =
          Hummingbird_Flight_Controller_B.PX4Timestamp_ct.PX4Timestamp;
        Hummingbird_Flight_Controller_B.BusAssignment_ia.roll_rate_error =
          static_cast<real32_T>(Hummingbird_Flight_Controller_B.prev_waypoint[0]);
        Hummingbird_Flight_Controller_B.BusAssignment_ia.pitch_rate_error =
          static_cast<real32_T>(Hummingbird_Flight_Controller_B.prev_waypoint[1]);
        Hummingbird_Flight_Controller_B.BusAssignment_ia.yaw_rate_error =
          static_cast<real32_T>(Hummingbird_Flight_Controller_B.prev_waypoint[2]);
        Hummingbird_Flight_Controller_B.BusAssignment_ia._padding0[0] =
          Hummingbird_Flight_Controller_P.Constant_Value_c4[0];
        Hummingbird_Flight_Controller_B.BusAssignment_ia._padding0[1] =
          Hummingbird_Flight_Controller_P.Constant_Value_c4[1];
        Hummingbird_Flight_Controller_B.BusAssignment_ia._padding0[2] =
          Hummingbird_Flight_Controller_P.Constant_Value_c4[2];
        Hummingbird_Flight_Controller_B.BusAssignment_ia._padding0[3] =
          Hummingbird_Flight_Controller_P.Constant_Value_c4[3];
        Hummingbird_Fli_SinkBlock_j
          (&Hummingbird_Flight_Controller_B.BusAssignment_ia,
           &Hummingbird_Flight_Controlle_DW.SinkBlock_cp);

        // Sum: '<S367>/Sum3'
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_B.prev_waypoint[0];
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
          Hummingbird_Flight_Controller_B.prev_waypoint[1];
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 =
          Hummingbird_Flight_Controller_B.prev_waypoint[2];
        Hummingb_ReadParameter1_b3r
          (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ay,
           &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ay);
        Hummingbi_ReadParameter_b3r
          (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ay,
           &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ay);
        Hummingbi_ReadParameter2_b3
          (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb,
           &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb);

        // Merge: '<S1>/ Merge 2' incorporates:
        //   BusCreator: '<S5>/Bus Creator6'
        //   Product: '<S526>/PProd Out'
        //   Sum: '<S367>/Sum3'

        Hummingbird_Flight_Controller_B.dM[0] =
          (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 -
           Hummingbird_Flight_Controller_B.Sum_e[0]) *
          Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ay.ReadParameter1_o1;
        Hummingbird_Flight_Controller_B.dM[1] =
          (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 -
           Hummingbird_Flight_Controller_B.Sum_e[1]) *
          Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ay.ReadParameter_o1;
        Hummingbird_Flight_Controller_B.dM[2] =
          (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 -
           Hummingbird_Flight_Controller_B.Sum_e[2]) *
          Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb.ReadParameter2_o1;

        // Update for DiscreteIntegrator: '<S464>/Filter'
        Hummingbird_Flight_Controlle_DW.Filter_DSTATE_d[0] +=
          Hummingbird_Flight_Controller_P.Filter_gainval_n *
          Hummingbird_Flight_Controller_B.Filter_os[0];

        // Update for DiscreteIntegrator: '<S412>/Filter'
        Hummingbird_Flight_Controlle_DW.Filter_DSTATE_p[0] +=
          Hummingbird_Flight_Controller_P.Filter_gainval_bd *
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1;

        // Update for DiscreteIntegrator: '<S464>/Filter'
        Hummingbird_Flight_Controlle_DW.Filter_DSTATE_d[1] +=
          Hummingbird_Flight_Controller_P.Filter_gainval_n *
          Hummingbird_Flight_Controller_B.Filter_os[1];

        // Update for DiscreteIntegrator: '<S412>/Filter'
        Hummingbird_Flight_Controlle_DW.Filter_DSTATE_p[1] +=
          Hummingbird_Flight_Controller_P.Filter_gainval_bd *
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;

        // Update for DiscreteIntegrator: '<S464>/Filter'
        Hummingbird_Flight_Controlle_DW.Filter_DSTATE_d[2] +=
          Hummingbird_Flight_Controller_P.Filter_gainval_n *
          Hummingbird_Flight_Controller_B.Filter_os[2];

        // Update for DiscreteIntegrator: '<S412>/Filter'
        Hummingbird_Flight_Controlle_DW.Filter_DSTATE_p[2] +=
          Hummingbird_Flight_Controller_P.Filter_gainval_bd *
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;
      }
    } else if (Hummingbird_Flight_Controller_B.BusCreator.Flight_Mode > 1800) {
      exit_internal_Flight_controller();
      Hummingbird_Flight_Controlle_DW.is_Flight_controller =
        Hummingbird_Flight_Co_IN_MR_Nav;

      // Merge: '<S1>/ Merge ' incorporates:
      //   Constant: '<S9>/Constant10'
      //   SignalConversion generated from: '<S9>/dtFW'

      Hummingbird_Flight_Controller_B.dtFW =
        Hummingbird_Flight_Controller_P.Constant10_Value_b;

      // MATLAB Function: '<S780>/MATLAB Function2'
      if (rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lat)
          || rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lon))
      {
        Hummingbird_Flight_Controller_B.prev_lat[0] =
          Hummingbird_Flight_Controlle_DW.mission_start[0];
        Hummingbird_Flight_Controller_B.prev_lat[1] =
          Hummingbird_Flight_Controlle_DW.mission_start[1];
        Hummingbird_Flight_Controller_B.prev_lat[2] =
          Hummingbird_Flight_Controlle_DW.mission_start[2];
      } else {
        Hummingbird_Flight_Controller_B.prev_lat[0] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lat;
        Hummingbird_Flight_Controller_B.prev_lat[1] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lon;
        Hummingbird_Flight_Controller_B.prev_lat[2] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.altitude;
      }

      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[0] =
        Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lat;
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[1] =
        Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lon;
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[2] =
        Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.altitude;
      Hummingbird_Flight_Cont_lla2ned(Hummingbird_Flight_Controller_B.prev_lat,
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c,
        Hummingbird_Flight_Controller_B.current_lat);
      if (rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lat))
      {
        Hummingbird_Flight_Controller_B.DProdOut_n[0] = 0.0;
        Hummingbird_Flight_Controller_B.DProdOut_n[1] = 0.0;
        Hummingbird_Flight_Controller_B.DProdOut_n[2] = 0.0;
      } else if (rtIsNaN
                 (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lon))
      {
        Hummingbird_Flight_Controller_B.DProdOut_n[0] = 0.0;
        Hummingbird_Flight_Controller_B.DProdOut_n[1] = 0.0;
        Hummingbird_Flight_Controller_B.DProdOut_n[2] = 0.0;
      } else {
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[0] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lat;
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[1] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lon;
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[2] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.altitude;
        Hummingbird_Flight_Controller_B.prev_lat[0] =
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lat;
        Hummingbird_Flight_Controller_B.prev_lat[1] =
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lon;
        Hummingbird_Flight_Controller_B.prev_lat[2] =
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.altitude;
        Hummingbird_Flight_Cont_lla2ned
          (Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c,
           Hummingbird_Flight_Controller_B.prev_lat,
           Hummingbird_Flight_Controller_B.dv);
        Hummingbird_Flight_Controller_B.DProdOut_n[0] = 3.28084 *
          Hummingbird_Flight_Controller_B.dv[0] +
          Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.X;
        Hummingbird_Flight_Controller_B.DProdOut_n[1] = 3.28084 *
          Hummingbird_Flight_Controller_B.dv[1] +
          Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.Y;
        Hummingbird_Flight_Controller_B.DProdOut_n[2] = 3.28084 *
          Hummingbird_Flight_Controller_B.dv[2] +
          Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.Z;
      }

      // Sum: '<S777>/Sum20' incorporates:
      //   BusCreator: '<S5>/Bus Creator9'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        Hummingbird_Flight_Controller_B.DProdOut_n[2] -
        Hummingbird_Flight_Controller_B.CastToDouble25_f;

      // Gain: '<S872>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S864>/Filter'
      //   Gain: '<S862>/Derivative Gain'
      //   Sum: '<S864>/SumD'

      Hummingbird_Flight_Controller_B.Esp_dot =
        (Hummingbird_Flight_Controller_P.PIDController5_D *
         Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_fu) *
        Hummingbird_Flight_Controller_P.PIDController5_N;

      // Sum: '<S878>/Sum' incorporates:
      //   DiscreteIntegrator: '<S869>/Integrator'
      //   Gain: '<S874>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (Hummingbird_Flight_Controller_P.PIDController5_P *
         Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_n) +
        Hummingbird_Flight_Controller_B.Esp_dot;

      // Saturate: '<S876>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.PIDController5_UpperSaturationL) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.PIDController5_UpperSaturationL;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.PIDController5_LowerSaturationL)
      {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.PIDController5_LowerSaturationL;
      }

      // Sum: '<S777>/Sum21' incorporates:
      //   BusCreator: '<S5>/Bus Creator4'
      //   Saturate: '<S876>/Saturation'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2;

      // Gain: '<S820>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S812>/Filter'
      //   Gain: '<S810>/Derivative Gain'
      //   Sum: '<S812>/SumD'

      Hummingbird_Flight_Controller_B.V =
        (Hummingbird_Flight_Controller_P.PIDController3_D *
         Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_l) *
        Hummingbird_Flight_Controller_P.PIDController3_N;

      // Gain: '<S1168>/Gain5' incorporates:
      //   DiscreteIntegrator: '<S817>/Integrator'
      //   Gain: '<S777>/Gain5'
      //   Gain: '<S822>/Proportional Gain'
      //   Merge: '<S1>/ Merge 1'
      //   Sum: '<S826>/Sum'

      Hummingbird_Flight_Controller_B.dtMR =
        ((Hummingbird_Flight_Controller_P.PIDController3_P *
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 +
          Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_j) +
         Hummingbird_Flight_Controller_B.V) * -Hummingbird_Flight_Controller_P.m;

      // Gain: '<S814>/Integral Gain'
      Hummingbird_Flight_Controller_B.IntegralGain_k =
        Hummingbird_Flight_Controller_P.PIDController3_I *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;

      // Gain: '<S866>/Integral Gain'
      Hummingbird_Flight_Controller_B.CastToDouble25_f =
        Hummingbird_Flight_Controller_P.PIDController5_I *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1;

      // MATLAB Function: '<S9>/MATLAB Function2' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double3'
      //   MATLAB Function: '<S780>/MATLAB Function2'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //
      Hummingbird_MATLABFunction2(static_cast<real_T>
        (Hummingbird_Flight_Controller_B.a_n), Hummingbird_Fligh_rt_atan2d_snf
        (Hummingbird_Flight_Controller_B.DProdOut_n[1] - (3.28084 *
        Hummingbird_Flight_Controller_B.current_lat[1] +
        Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.Y),
         Hummingbird_Flight_Controller_B.DProdOut_n[0] - (3.28084 *
        Hummingbird_Flight_Controller_B.current_lat[0] +
        Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.X)),
        &Hummingbird_Flight_Controller_B.course);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_pb);

      // Sum: '<S780>/Sum14' incorporates:
      //   BusCreator: '<S5>/Bus Creator9'

      Hummingbird_Flight_Controller_B.Filter_os[0] =
        Hummingbird_Flight_Controller_B.DProdOut_n[0] -
        Hummingbird_Flight_Controller_B.In1_a.lat;
      Hummingbird_Flight_Controller_B.Filter_os[1] =
        Hummingbird_Flight_Controller_B.DProdOut_n[1] -
        Hummingbird_Flight_Controller_B.In1_a.lon;
      Hummingbird_Flight_Controller_B.Filter_os[2] =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1;

      // Gain: '<S1101>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1093>/Filter'
      //   Gain: '<S1091>/Derivative Gain'
      //   Sum: '<S1093>/SumD'

      Hummingbird_Flight_Controller_B.scale =
        (Hummingbird_Flight_Controller_P.PIDController8_D[0] *
         Hummingbird_Flight_Controller_B.Filter_os[0] -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_b[0]) *
        Hummingbird_Flight_Controller_P.PIDController8_N;
      Hummingbird_Flight_Controller_B.DProdOut_n[0] =
        Hummingbird_Flight_Controller_B.scale;

      // Sum: '<S1107>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1098>/Integrator'
      //   Gain: '<S1091>/Derivative Gain'
      //   Gain: '<S1103>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        (Hummingbird_Flight_Controller_P.PIDController8_P[0] *
         Hummingbird_Flight_Controller_B.Filter_os[0] +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[0]) +
        Hummingbird_Flight_Controller_B.scale;

      // Gain: '<S1101>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1093>/Filter'
      //   Gain: '<S1091>/Derivative Gain'
      //   Sum: '<S1093>/SumD'

      Hummingbird_Flight_Controller_B.scale =
        (Hummingbird_Flight_Controller_P.PIDController8_D[1] *
         Hummingbird_Flight_Controller_B.Filter_os[1] -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_b[1]) *
        Hummingbird_Flight_Controller_P.PIDController8_N;
      Hummingbird_Flight_Controller_B.DProdOut_n[1] =
        Hummingbird_Flight_Controller_B.scale;

      // Sum: '<S1107>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1098>/Integrator'
      //   Gain: '<S1091>/Derivative Gain'
      //   Gain: '<S1103>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
        (Hummingbird_Flight_Controller_P.PIDController8_P[1] *
         Hummingbird_Flight_Controller_B.Filter_os[1] +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[1]) +
        Hummingbird_Flight_Controller_B.scale;

      // Gain: '<S1101>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1093>/Filter'
      //   Gain: '<S1091>/Derivative Gain'
      //   Sum: '<S1093>/SumD'
      //   Sum: '<S780>/Sum14'

      Hummingbird_Flight_Controller_B.scale =
        (Hummingbird_Flight_Controller_P.PIDController8_D[2] *
         Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_b[2]) *
        Hummingbird_Flight_Controller_P.PIDController8_N;

      // Sum: '<S1107>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1098>/Integrator'
      //   Gain: '<S1103>/Proportional Gain'
      //   Sum: '<S780>/Sum14'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        (Hummingbird_Flight_Controller_P.PIDController8_P[2] *
         Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[2]) +
        Hummingbird_Flight_Controller_B.scale;

      // MATLAB Function: '<S780>/MATLAB Function'
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_p[0] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_p[1] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1;
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        Hummingbird_Flight_Contr_norm_j
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_p);
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 > 30.0) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 /
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 * 30.0;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 /
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 * 30.0;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 /
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 * 30.0;
      }

      // Sum: '<S780>/Sum1' incorporates:
      //   BusCreator: '<S5>/Bus Creator4'

      Hummingbird_Flight_Controller_B.prev_waypoint[0] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;
      Hummingbird_Flight_Controller_B.prev_waypoint[1] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      Hummingbird_Flight_Controller_B.prev_waypoint[2] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2;

      // Gain: '<S1153>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1145>/Filter'
      //   Gain: '<S1143>/Derivative Gain'
      //   Sum: '<S1145>/SumD'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 =
        (Hummingbird_Flight_Controller_P.PIDController9_D[0] *
         Hummingbird_Flight_Controller_B.prev_waypoint[0] -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_e[0]) *
        Hummingbird_Flight_Controller_P.PIDController9_N;
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;

      // Sum: '<S1159>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1150>/Integrator'
      //   Gain: '<S1143>/Derivative Gain'
      //   Gain: '<S1155>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (Hummingbird_Flight_Controller_P.PIDController9_P[0] *
         Hummingbird_Flight_Controller_B.prev_waypoint[0] +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[0]) +
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;

      // Saturate: '<S1157>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturationL) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturationL;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerSaturationL)
      {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.PIDController9_LowerSaturationL;
      }

      // Gain: '<S1153>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1145>/Filter'
      //   Gain: '<S1143>/Derivative Gain'
      //   Sum: '<S1145>/SumD'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 =
        (Hummingbird_Flight_Controller_P.PIDController9_D[1] *
         Hummingbird_Flight_Controller_B.prev_waypoint[1] -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_e[1]) *
        Hummingbird_Flight_Controller_P.PIDController9_N;
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;

      // Sum: '<S1159>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1150>/Integrator'
      //   Gain: '<S1143>/Derivative Gain'
      //   Gain: '<S1155>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        (Hummingbird_Flight_Controller_P.PIDController9_P[1] *
         Hummingbird_Flight_Controller_B.prev_waypoint[1] +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[1]) +
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;

      // Saturate: '<S1157>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturationL) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturationL;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerSaturationL)
      {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_P.PIDController9_LowerSaturationL;
      }

      // Gain: '<S1153>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1145>/Filter'
      //   Gain: '<S1143>/Derivative Gain'
      //   Sum: '<S1145>/SumD'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 =
        (Hummingbird_Flight_Controller_P.PIDController9_D[2] *
         Hummingbird_Flight_Controller_B.prev_waypoint[2] -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_e[2]) *
        Hummingbird_Flight_Controller_P.PIDController9_N;

      // Sum: '<S1159>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1150>/Integrator'
      //   Gain: '<S1143>/Derivative Gain'
      //   Gain: '<S1155>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
        (Hummingbird_Flight_Controller_P.PIDController9_P[2] *
         Hummingbird_Flight_Controller_B.prev_waypoint[2] +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[2]) +
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;

      // Saturate: '<S1157>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturationL) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturationL;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerSaturationL)
      {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
          Hummingbird_Flight_Controller_P.PIDController9_LowerSaturationL;
      }

      // MATLAB Function: '<S780>/MATLAB Function1' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double3'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 = cos
        (static_cast<real_T>(Hummingbird_Flight_Controller_B.a_n));
      Hummingbird_Flight_Controller_B.t = sin(static_cast<real_T>
        (Hummingbird_Flight_Controller_B.a_n));
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 = asin
        ((-Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 *
          Hummingbird_Flight_Controller_B.t +
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 *
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1) / sqrt
         ((Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 *
           Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 +
           Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 *
           Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1) +
          (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 - 32.174) *
          (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 - 32.174)));

      // Saturate: '<S780>/Saturation1'
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 >
          Hummingbird_Flight_Controller_P.Saturation1_UpperSat_i) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_P.Saturation1_UpperSat_i;
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 <
                 Hummingbird_Flight_Controller_P.Saturation1_LowerSat_l) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_P.Saturation1_LowerSat_l;
      }

      // MATLAB Function: '<S780>/MATLAB Function1'
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 = atan
        ((-Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 *
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 -
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 *
          Hummingbird_Flight_Controller_B.t) / fabs
         (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 - 32.174));

      // Saturate: '<S780>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_p) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_p;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_l5) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_l5;
      }

      // BusAssignment: '<S890>/Bus Assignment' incorporates:
      //   Constant: '<S779>/Constant5'
      //   DataTypeConversion: '<S779>/Cast To Single16'
      //   DataTypeConversion: '<S779>/Cast To Single17'
      //   DataTypeConversion: '<S779>/Cast To Single18'
      //   MATLABSystem: '<S890>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_ov.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_pb.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_ov.roll =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment_ov.pitch = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_ov.yaw_rate = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.course);
      Hummingbird_Flight_Controller_B.BusAssignment_ov._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant5_Value_d[0];
      Hummingbird_Flight_Controller_B.BusAssignment_ov._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant5_Value_d[1];
      Hummingbird_Flight_Controller_B.BusAssignment_ov._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant5_Value_d[2];
      Hummingbird_Flight_Controller_B.BusAssignment_ov._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant5_Value_d[3];
      Hummingbird_Fligh_SinkBlock
        (&Hummingbird_Flight_Controller_B.BusAssignment_ov,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_ir);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_a);

      // Sum: '<S779>/Sum6' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double3'
      //   DataTypeConversion: '<S5>/Cast To Double4'
      //   DataTypeConversion: '<S5>/Cast To Double5'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0;
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1;
      Hummingbird_Flight_Controller_B.course -=
        Hummingbird_Flight_Controller_B.a_n;
      Hummin_ReadParameter1_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter1_o,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_o);
      Humming_ReadParameter_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter_o,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_o);
      Hummingb_ReadParameter2_b3r
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu5,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ayu5);
      Hummi_ReadParameter1_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter1_l,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_l);
      Hummin_ReadParameter_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter_l,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_l);
      Humming_ReadParameter2_b3rg
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu5d,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ayu5d);

      // Product: '<S1038>/NProd Out' incorporates:
      //   Constant: '<S779>/Constant4'
      //   DiscreteIntegrator: '<S1030>/Filter'
      //   Product: '<S1028>/DProd Out'
      //   Sum: '<S1030>/SumD'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 *
         Hummingbird_Flight_Controller_B.ReadParameter1_l.ReadParameter1_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_k[0]) *
        Hummingbird_Flight_Controller_P.Constant4_Value_e;
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 *
         Hummingbird_Flight_Controller_B.ReadParameter_l.ReadParameter_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_k[1]) *
        Hummingbird_Flight_Controller_P.Constant4_Value_e;
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
        (Hummingbird_Flight_Controller_B.course *
         Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu5d.ReadParameter2_o1
         - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_k[2]) *
        Hummingbird_Flight_Controller_P.Constant4_Value_e;

      // Sum: '<S1044>/Sum' incorporates:
      //   Product: '<S1040>/PProd Out'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 *
        Hummingbird_Flight_Controller_B.ReadParameter1_o.ReadParameter1_o1 +
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 *
        Hummingbird_Flight_Controller_B.ReadParameter_o.ReadParameter_o1 +
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1;
      Hummingbird_Flight_Controller_B.course =
        Hummingbird_Flight_Controller_B.course *
        Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu5.ReadParameter2_o1
        + Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2;

      // BusAssignment: '<S891>/Bus Assignment' incorporates:
      //   Constant: '<S779>/Constant6'
      //   DataTypeConversion: '<S779>/Cast To Single10'
      //   DataTypeConversion: '<S779>/Cast To Single11'
      //   DataTypeConversion: '<S779>/Cast To Single15'
      //   MATLABSystem: '<S891>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_mv.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_a.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_mv.roll_rate = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_mv.pitch_rate = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment_mv.yaw_rate =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.course);
      Hummingbird_Flight_Controller_B.BusAssignment_mv._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant6_Value[0];
      Hummingbird_Flight_Controller_B.BusAssignment_mv._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant6_Value[1];
      Hummingbird_Flight_Controller_B.BusAssignment_mv._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant6_Value[2];
      Hummingbird_Flight_Controller_B.BusAssignment_mv._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant6_Value[3];
      Hummingbird_Fli_SinkBlock_h
        (&Hummingbird_Flight_Controller_B.BusAssignment_mv,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_fv);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_ac);

      // Sum: '<S779>/Sum2' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double7'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 -=
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[0];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 -=
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[1];
      Hummingbird_Flight_Controller_B.course -=
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[2];

      // BusAssignment: '<S892>/Bus Assignment' incorporates:
      //   Constant: '<S779>/Constant1'
      //   DataTypeConversion: '<S779>/Cast To Single12'
      //   DataTypeConversion: '<S779>/Cast To Single13'
      //   DataTypeConversion: '<S779>/Cast To Single14'
      //   MATLABSystem: '<S892>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_f.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_ac.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_f.roll_rate_error =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_f.pitch_rate_error =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment_f.yaw_rate_error =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.course);
      Hummingbird_Flight_Controller_B.BusAssignment_f._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant1_Value_f[0];
      Hummingbird_Flight_Controller_B.BusAssignment_f._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant1_Value_f[1];
      Hummingbird_Flight_Controller_B.BusAssignment_f._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant1_Value_f[2];
      Hummingbird_Flight_Controller_B.BusAssignment_f._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant1_Value_f[3];
      Hummingbird_Fli_SinkBlock_j
        (&Hummingbird_Flight_Controller_B.BusAssignment_f,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_fw);
      Humm_ReadParameter1_b3rgaen
        (&Hummingbird_Flight_Controller_B.ReadParameter1_px,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_px);
      Hummi_ReadParameter_b3rgaen
        (&Hummingbird_Flight_Controller_B.ReadParameter_px,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_px);
      Hummin_ReadParameter2_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu5da,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ayu5da);
      Hum_ReadParameter1_b3rgaenb
        (&Hummingbird_Flight_Controller_B.ReadParameter1_i,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_i);
      Humm_ReadParameter_b3rgaenb
        (&Hummingbird_Flight_Controller_B.ReadParameter_i,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_i);
      Hummi_ReadParameter2_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter2_j,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_j);

      // Merge: '<S1>/ Merge 2' incorporates:
      //   BusCreator: '<S5>/Bus Creator6'
      //   Product: '<S936>/PProd Out'
      //   Product: '<S988>/PProd Out'
      //   Sum: '<S779>/Sum1'

      Hummingbird_Flight_Controller_B.dM[0] =
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 *
         Hummingbird_Flight_Controller_B.ReadParameter1_px.ReadParameter1_o1 -
         Hummingbird_Flight_Controller_B.Sum_e[0]) *
        Hummingbird_Flight_Controller_B.ReadParameter1_i.ReadParameter1_o1;
      Hummingbird_Flight_Controller_B.dM[1] =
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 *
         Hummingbird_Flight_Controller_B.ReadParameter_px.ReadParameter_o1 -
         Hummingbird_Flight_Controller_B.Sum_e[1]) *
        Hummingbird_Flight_Controller_B.ReadParameter_i.ReadParameter_o1;
      Hummingbird_Flight_Controller_B.dM[2] =
        (Hummingbird_Flight_Controller_B.course *
         Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu5da.ReadParameter2_o1
         - Hummingbird_Flight_Controller_B.Sum_e[2]) *
        Hummingbird_Flight_Controller_B.ReadParameter2_j.ReadParameter2_o1;

      // Update for DiscreteIntegrator: '<S869>/Integrator'
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_n +=
        Hummingbird_Flight_Controller_P.Integrator_gainval_n *
        Hummingbird_Flight_Controller_B.CastToDouble25_f;

      // Update for DiscreteIntegrator: '<S864>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_fu +=
        Hummingbird_Flight_Controller_P.Filter_gainval_k *
        Hummingbird_Flight_Controller_B.Esp_dot;

      // Update for DiscreteIntegrator: '<S817>/Integrator'
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_j +=
        Hummingbird_Flight_Controller_P.Integrator_gainval_m *
        Hummingbird_Flight_Controller_B.IntegralGain_k;

      // Update for DiscreteIntegrator: '<S812>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_l +=
        Hummingbird_Flight_Controller_P.Filter_gainval_i *
        Hummingbird_Flight_Controller_B.V;

      // Update for DiscreteIntegrator: '<S1098>/Integrator' incorporates:
      //   Gain: '<S1095>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_P.PIDController8_I *
        Hummingbird_Flight_Controller_B.Filter_os[0] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_b +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[0];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[0] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController8_UpperIntegratorS) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[0] =
          Hummingbird_Flight_Controller_P.PIDController8_UpperIntegratorS;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController8_LowerIntegratorS)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[0] =
          Hummingbird_Flight_Controller_P.PIDController8_LowerIntegratorS;
      }

      // Update for DiscreteIntegrator: '<S1093>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_b[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_e *
        Hummingbird_Flight_Controller_B.DProdOut_n[0];

      // Update for DiscreteIntegrator: '<S1150>/Integrator' incorporates:
      //   Gain: '<S1147>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_P.PIDController9_I[0] *
        Hummingbird_Flight_Controller_B.prev_waypoint[0] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_m2 +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[0];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[0] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegratorS) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[0] =
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegratorS;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerIntegratorS)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[0] =
          Hummingbird_Flight_Controller_P.PIDController9_LowerIntegratorS;
      }

      // Update for DiscreteIntegrator: '<S1145>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_e[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_l *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;

      // Update for DiscreteIntegrator: '<S1030>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_k[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_io *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;

      // Update for DiscreteIntegrator: '<S1098>/Integrator' incorporates:
      //   Gain: '<S1095>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_P.PIDController8_I *
        Hummingbird_Flight_Controller_B.Filter_os[1] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_b +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[1];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[1] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController8_UpperIntegratorS) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[1] =
          Hummingbird_Flight_Controller_P.PIDController8_UpperIntegratorS;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController8_LowerIntegratorS)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[1] =
          Hummingbird_Flight_Controller_P.PIDController8_LowerIntegratorS;
      }

      // Update for DiscreteIntegrator: '<S1093>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_b[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_e *
        Hummingbird_Flight_Controller_B.DProdOut_n[1];

      // Update for DiscreteIntegrator: '<S1150>/Integrator' incorporates:
      //   Gain: '<S1147>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_P.PIDController9_I[1] *
        Hummingbird_Flight_Controller_B.prev_waypoint[1] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_m2 +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[1];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[1] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegratorS) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[1] =
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegratorS;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerIntegratorS)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[1] =
          Hummingbird_Flight_Controller_P.PIDController9_LowerIntegratorS;
      }

      // Update for DiscreteIntegrator: '<S1145>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_e[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_l *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1;

      // Update for DiscreteIntegrator: '<S1030>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_k[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_io *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1;

      // Update for DiscreteIntegrator: '<S1098>/Integrator' incorporates:
      //   Gain: '<S1095>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_P.PIDController8_I *
        Hummingbird_Flight_Controller_B.Filter_os[2] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_b +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[2];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[2] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController8_UpperIntegratorS) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[2] =
          Hummingbird_Flight_Controller_P.PIDController8_UpperIntegratorS;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController8_LowerIntegratorS)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[2] =
          Hummingbird_Flight_Controller_P.PIDController8_LowerIntegratorS;
      }

      // Update for DiscreteIntegrator: '<S1093>/Filter' incorporates:
      //   Gain: '<S1101>/Filter Coefficient'

      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_b[2] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_e *
        Hummingbird_Flight_Controller_B.scale;

      // Update for DiscreteIntegrator: '<S1150>/Integrator' incorporates:
      //   Gain: '<S1147>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_P.PIDController9_I[2] *
        Hummingbird_Flight_Controller_B.prev_waypoint[2] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_m2 +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[2];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[2] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegratorS) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[2] =
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegratorS;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerIntegratorS)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[2] =
          Hummingbird_Flight_Controller_P.PIDController9_LowerIntegratorS;
      }

      // Update for DiscreteIntegrator: '<S1145>/Filter' incorporates:
      //   Gain: '<S1153>/Filter Coefficient'

      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_e[2] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_l *
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;

      // Update for DiscreteIntegrator: '<S1030>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_k[2] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_io *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2;
    } else if (Hummingbird_Flight_Controller_B.BusCreator.Flight_Mode > 1200) {
      exit_internal_Flight_controller();
      Hummingbird_Flight_Controlle_DW.is_Flight_controller =
        Hummingbird_Flight_C_IN_MR_Vel1;

      // Merge: '<S1>/ Merge ' incorporates:
      //   Constant: '<S10>/Constant14'
      //   SignalConversion generated from: '<S10>/dtFW'

      Hummingbird_Flight_Controller_B.dtFW =
        Hummingbird_Flight_Controller_P.Constant14_Value_p;
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_d);

      // Sum: '<S1168>/Sum21' incorporates:
      //   BusCreator: '<S5>/Bus Creator4'
      //   Constant: '<S1402>/Constant'
      //   Gain: '<S1402>/Gain'
      //   Sum: '<S1402>/Sum'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
        (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Throttle)
         - Hummingbird_Flight_Controller_P.Constant_Value_f5) *
        Hummingbird_Flight_Controller_P.Gain_Gain_n -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2;
      Hummingb_ReadParameter_b3rg
        (&Hummingbird_Flight_Controller_B.ReadParameter_ld,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_ld);
      Humming_ReadParameter1_b3rg
        (&Hummingbird_Flight_Controller_B.ReadParameter1_ld,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_ld);

      // Product: '<S1211>/NProd Out' incorporates:
      //   Constant: '<S1168>/Constant'
      //   DiscreteIntegrator: '<S1203>/Filter'
      //   Product: '<S1201>/DProd Out'
      //   Sum: '<S1203>/SumD'

      Hummingbird_Flight_Controller_B.V =
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 *
         Hummingbird_Flight_Controller_B.ReadParameter1_ld.ReadParameter1_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_f) *
        Hummingbird_Flight_Controller_P.Constant_Value_p5;

      // Gain: '<S1168>/Gain5' incorporates:
      //   Product: '<S1213>/PProd Out'
      //   Sum: '<S1217>/Sum'

      Hummingbird_Flight_Controller_B.dtMR =
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 *
         Hummingbird_Flight_Controller_B.ReadParameter_ld.ReadParameter_o1 +
         Hummingbird_Flight_Controller_B.V) * -Hummingbird_Flight_Controller_P.m;

      // BusAssignment: '<S1171>/Bus Assignment' incorporates:
      //   Constant: '<S10>/Constant'
      //   Constant: '<S10>/Constant2'
      //   Constant: '<S10>/Constant7'
      //   Constant: '<S10>/Constant9'
      //   DataTypeConversion: '<S10>/Cast To Single'
      //   MATLABSystem: '<S1171>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_n.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_d.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_n.x =
        Hummingbird_Flight_Controller_P.Constant_Value_jh;
      Hummingbird_Flight_Controller_B.BusAssignment_n.y =
        Hummingbird_Flight_Controller_P.Constant2_Value_p;
      Hummingbird_Flight_Controller_B.BusAssignment_n.z = static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.dtMR);
      for (Hummingbird_Flight_Controller_B.i = 0;
           Hummingbird_Flight_Controller_B.i < 10;
           Hummingbird_Flight_Controller_B.i++) {
        Hummingbird_Flight_Controller_B.BusAssignment_n.name[Hummingbird_Flight_Controller_B.i]
          =
          Hummingbird_Flight_Controller_P.Constant7_Value_g[Hummingbird_Flight_Controller_B.i];
      }

      Hummingbird_Flight_Controller_B.BusAssignment_n._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant9_Value_c[0];
      Hummingbird_Flight_Controller_B.BusAssignment_n._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant9_Value_c[1];

      // MATLABSystem: '<S1399>/SinkBlock' incorporates:
      //   BusAssignment: '<S1171>/Bus Assignment'

      uORB_write_step(Hummingbird_Flight_Controlle_DW.obj_hh.orbMetadataObj,
                      &Hummingbird_Flight_Controlle_DW.obj_hh.orbAdvertiseObj,
                      &Hummingbird_Flight_Controller_B.BusAssignment_n);

      // MATLAB Function: '<S10>/MATLAB Function2' incorporates:
      //   Constant: '<S1405>/Constant'
      //   DataTypeConversion: '<S5>/Cast To Double3'
      //   Gain: '<S1172>/Gain'
      //   Gain: '<S1405>/Gain'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //   Sum: '<S1405>/Sum'
      //
      Hummingbird_MATLABFunction2(static_cast<real_T>
        (Hummingbird_Flight_Controller_B.a_n),
        Hummingbird_Flight_Controller_P.Gain_Gain_j2 *
        (Hummingbird_Flight_Controller_P.Gain_Gain_j * (static_cast<real_T>
        (Hummingbird_Flight_Controller_B.BusCreator.Yaw) -
        Hummingbird_Flight_Controller_P.Constant_Value_lu)),
        &Hummingbird_Flight_Controller_B.Esp_dot);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_g);

      // Sum: '<S1172>/Sum1' incorporates:
      //   BusCreator: '<S5>/Bus Creator4'
      //   Constant: '<S1403>/Constant'
      //   Constant: '<S1404>/Constant'
      //   Gain: '<S1172>/Gain1'
      //   Gain: '<S1172>/Gain2'
      //   Gain: '<S1403>/Gain'
      //   Gain: '<S1404>/Gain'
      //   Sum: '<S1403>/Sum'
      //   Sum: '<S1404>/Sum'

      Hummingbird_Flight_Controller_B.Filter_os[0] = (static_cast<real_T>
        (Hummingbird_Flight_Controller_B.BusCreator.Pitch) -
        Hummingbird_Flight_Controller_P.Constant_Value_mb) *
        Hummingbird_Flight_Controller_P.Gain_Gain_e *
        Hummingbird_Flight_Controller_P.Gain2_Gain_j -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;
      Hummingbird_Flight_Controller_B.Filter_os[1] = (static_cast<real_T>
        (Hummingbird_Flight_Controller_B.BusCreator.Roll) -
        Hummingbird_Flight_Controller_P.Constant_Value_mbi) *
        Hummingbird_Flight_Controller_P.Gain_Gain_d *
        Hummingbird_Flight_Controller_P.Gain1_Gain_b -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;

      // Gain: '<S1443>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1435>/Filter'
      //   Gain: '<S1433>/Derivative Gain'
      //   Sum: '<S1435>/SumD'

      Hummingbird_Flight_Controller_B.scale =
        (Hummingbird_Flight_Controller_P.PIDController9_D_d[0] *
         Hummingbird_Flight_Controller_B.Filter_os[0] -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_h[0]) *
        Hummingbird_Flight_Controller_P.PIDController9_N_j;
      Hummingbird_Flight_Controller_B.DProdOut_n[0] =
        Hummingbird_Flight_Controller_B.scale;

      // Sum: '<S1449>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1440>/Integrator'
      //   Gain: '<S1433>/Derivative Gain'
      //   Gain: '<S1445>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (Hummingbird_Flight_Controller_P.PIDController9_P_b[0] *
         Hummingbird_Flight_Controller_B.Filter_os[0] +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[0]) +
        Hummingbird_Flight_Controller_B.scale;

      // Saturate: '<S1447>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturatio_o) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturatio_o;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerSaturatio_a)
      {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.PIDController9_LowerSaturatio_a;
      }

      // Gain: '<S1443>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1435>/Filter'
      //   Gain: '<S1433>/Derivative Gain'
      //   Sum: '<S1435>/SumD'

      Hummingbird_Flight_Controller_B.scale =
        (Hummingbird_Flight_Controller_P.PIDController9_D_d[1] *
         Hummingbird_Flight_Controller_B.Filter_os[1] -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_h[1]) *
        Hummingbird_Flight_Controller_P.PIDController9_N_j;
      Hummingbird_Flight_Controller_B.DProdOut_n[1] =
        Hummingbird_Flight_Controller_B.scale;

      // Sum: '<S1449>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1440>/Integrator'
      //   Gain: '<S1433>/Derivative Gain'
      //   Gain: '<S1445>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        (Hummingbird_Flight_Controller_P.PIDController9_P_b[1] *
         Hummingbird_Flight_Controller_B.Filter_os[1] +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[1]) +
        Hummingbird_Flight_Controller_B.scale;

      // Saturate: '<S1447>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturatio_o) {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturatio_o;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerSaturatio_a)
      {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          Hummingbird_Flight_Controller_P.PIDController9_LowerSaturatio_a;
      }

      // Gain: '<S1443>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1435>/Filter'
      //   Gain: '<S1433>/Derivative Gain'
      //   Sum: '<S1172>/Sum1'
      //   Sum: '<S1435>/SumD'

      Hummingbird_Flight_Controller_B.scale =
        (Hummingbird_Flight_Controller_P.PIDController9_D_d[2] *
         Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_h[2]) *
        Hummingbird_Flight_Controller_P.PIDController9_N_j;

      // Sum: '<S1449>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1440>/Integrator'
      //   Gain: '<S1445>/Proportional Gain'
      //   Sum: '<S1172>/Sum1'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
        (Hummingbird_Flight_Controller_P.PIDController9_P_b[2] *
         Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[2]) +
        Hummingbird_Flight_Controller_B.scale;

      // Saturate: '<S1447>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturatio_o) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturatio_o;
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerSaturatio_a)
      {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          Hummingbird_Flight_Controller_P.PIDController9_LowerSaturatio_a;
      }

      // MATLAB Function: '<S1172>/MATLAB Function1' incorporates:
      //   Saturate: '<S1447>/Saturation'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 = asin
        ((-Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 * 0.0 +
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1) / sqrt
         ((Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 *
           Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 +
           Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 *
           Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1) +
          (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 - 32.174)
          * (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
             32.174)));

      // Saturate: '<S1172>/Saturation1'
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation1_UpperSat_a) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation1_UpperSat_a;
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation1_LowerSat_a) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation1_LowerSat_a;
      }

      // MATLAB Function: '<S1172>/MATLAB Function1' incorporates:
      //   Saturate: '<S1447>/Saturation'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 = atan
        ((-Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 -
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 * 0.0) / fabs
         (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 - 32.174));

      // Saturate: '<S1172>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_h) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_h;
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_a) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_a;
      }

      // BusAssignment: '<S1229>/Bus Assignment' incorporates:
      //   Constant: '<S1170>/Constant5'
      //   DataTypeConversion: '<S1170>/Cast To Single16'
      //   DataTypeConversion: '<S1170>/Cast To Single17'
      //   DataTypeConversion: '<S1170>/Cast To Single18'
      //   MATLABSystem: '<S1229>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_ip.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_g.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_ip.roll = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_ip.pitch =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_ip.yaw_rate =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.Esp_dot);
      Hummingbird_Flight_Controller_B.BusAssignment_ip._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant5_Value_l[0];
      Hummingbird_Flight_Controller_B.BusAssignment_ip._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant5_Value_l[1];
      Hummingbird_Flight_Controller_B.BusAssignment_ip._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant5_Value_l[2];
      Hummingbird_Flight_Controller_B.BusAssignment_ip._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant5_Value_l[3];
      Hummingbird_Fligh_SinkBlock
        (&Hummingbird_Flight_Controller_B.BusAssignment_ip,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_hd);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_j);

      // Sum: '<S1170>/Sum6' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double4'
      //   DataTypeConversion: '<S5>/Cast To Double5'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0;
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1;
      Hummin_ReadParameter1_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter1_k,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_k);
      Humming_ReadParameter_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter_k,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_k);
      Hummingb_ReadParameter2_b3r
        (&Hummingbird_Flight_Controller_B.ReadParameter2_o,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_o);
      Hummi_ReadParameter1_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter1_lu,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_lu);
      Hummin_ReadParameter_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter_lu,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_lu);
      Humming_ReadParameter2_b3rg
        (&Hummingbird_Flight_Controller_B.ReadParameter2_l,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_l);

      // Product: '<S1377>/NProd Out' incorporates:
      //   Constant: '<S1170>/Constant4'
      //   DiscreteIntegrator: '<S1369>/Filter'
      //   Product: '<S1367>/DProd Out'
      //   Sum: '<S1369>/SumD'

      Hummingbird_Flight_Controller_B.prev_waypoint[0] =
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 *
         Hummingbird_Flight_Controller_B.ReadParameter1_lu.ReadParameter1_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_c[0]) *
        Hummingbird_Flight_Controller_P.Constant4_Value_ey;
      Hummingbird_Flight_Controller_B.prev_waypoint[1] =
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 *
         Hummingbird_Flight_Controller_B.ReadParameter_lu.ReadParameter_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_c[1]) *
        Hummingbird_Flight_Controller_P.Constant4_Value_ey;

      // Sum: '<S1383>/Sum' incorporates:
      //   Product: '<S1379>/PProd Out'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 *
        Hummingbird_Flight_Controller_B.ReadParameter1_k.ReadParameter1_o1 +
        Hummingbird_Flight_Controller_B.prev_waypoint[0];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 *
        Hummingbird_Flight_Controller_B.ReadParameter_k.ReadParameter_o1 +
        Hummingbird_Flight_Controller_B.prev_waypoint[1];

      // BusAssignment: '<S1230>/Bus Assignment' incorporates:
      //   Constant: '<S1170>/Constant6'
      //   DataTypeConversion: '<S1170>/Cast To Single10'
      //   DataTypeConversion: '<S1170>/Cast To Single11'
      //   DataTypeConversion: '<S1170>/Cast To Single15'
      //   MATLABSystem: '<S1230>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_j.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_j.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_j.roll_rate =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_j.pitch_rate = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_j.yaw_rate =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.Esp_dot);
      Hummingbird_Flight_Controller_B.BusAssignment_j._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant6_Value_k[0];
      Hummingbird_Flight_Controller_B.BusAssignment_j._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant6_Value_k[1];
      Hummingbird_Flight_Controller_B.BusAssignment_j._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant6_Value_k[2];
      Hummingbird_Flight_Controller_B.BusAssignment_j._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant6_Value_k[3];
      Hummingbird_Fli_SinkBlock_h
        (&Hummingbird_Flight_Controller_B.BusAssignment_j,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_o);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_k);

      // Sum: '<S1170>/Sum2' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double7'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 -=
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[0];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -=
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[1];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        Hummingbird_Flight_Controller_B.Esp_dot -
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[2];

      // BusAssignment: '<S1231>/Bus Assignment' incorporates:
      //   Constant: '<S1170>/Constant1'
      //   DataTypeConversion: '<S1170>/Cast To Single12'
      //   DataTypeConversion: '<S1170>/Cast To Single13'
      //   DataTypeConversion: '<S1170>/Cast To Single14'
      //   MATLABSystem: '<S1231>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_i.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_k.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_i.roll_rate_error =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_i.pitch_rate_error =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_i.yaw_rate_error =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment_i._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant1_Value_fj[0];
      Hummingbird_Flight_Controller_B.BusAssignment_i._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant1_Value_fj[1];
      Hummingbird_Flight_Controller_B.BusAssignment_i._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant1_Value_fj[2];
      Hummingbird_Flight_Controller_B.BusAssignment_i._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant1_Value_fj[3];
      Hummingbird_Fli_SinkBlock_j
        (&Hummingbird_Flight_Controller_B.BusAssignment_i,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_jf);
      Humm_ReadParameter1_b3rgaen
        (&Hummingbird_Flight_Controller_B.ReadParameter1_m,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_m);
      Hummi_ReadParameter_b3rgaen
        (&Hummingbird_Flight_Controller_B.ReadParameter_m,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_m);
      Hummin_ReadParameter2_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter2_p,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_p);
      Hum_ReadParameter1_b3rgaenb
        (&Hummingbird_Flight_Controller_B.ReadParameter1_kh,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_kh);
      Humm_ReadParameter_b3rgaenb
        (&Hummingbird_Flight_Controller_B.ReadParameter_kh,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_kh);
      Hummi_ReadParameter2_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter2_i,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_i);

      // Merge: '<S1>/ Merge 2' incorporates:
      //   BusCreator: '<S5>/Bus Creator6'
      //   Product: '<S1275>/PProd Out'
      //   Product: '<S1327>/PProd Out'
      //   Sum: '<S1170>/Sum1'

      Hummingbird_Flight_Controller_B.dM[0] =
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 *
         Hummingbird_Flight_Controller_B.ReadParameter1_m.ReadParameter1_o1 -
         Hummingbird_Flight_Controller_B.Sum_e[0]) *
        Hummingbird_Flight_Controller_B.ReadParameter1_kh.ReadParameter1_o1;
      Hummingbird_Flight_Controller_B.dM[1] =
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 *
         Hummingbird_Flight_Controller_B.ReadParameter_m.ReadParameter_o1 -
         Hummingbird_Flight_Controller_B.Sum_e[1]) *
        Hummingbird_Flight_Controller_B.ReadParameter_kh.ReadParameter_o1;
      Hummingbird_Flight_Controller_B.dM[2] =
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 *
         Hummingbird_Flight_Controller_B.ReadParameter2_p.ReadParameter2_o1 -
         Hummingbird_Flight_Controller_B.Sum_e[2]) *
        Hummingbird_Flight_Controller_B.ReadParameter2_i.ReadParameter2_o1;

      // Update for DiscreteIntegrator: '<S1203>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_f +=
        Hummingbird_Flight_Controller_P.Filter_gainval_pt *
        Hummingbird_Flight_Controller_B.V;

      // Update for DiscreteIntegrator: '<S1440>/Integrator' incorporates:
      //   Gain: '<S1437>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        Hummingbird_Flight_Controller_P.PIDController9_I_i[0] *
        Hummingbird_Flight_Controller_B.Filter_os[0] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_ma +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[0];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[0] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegrato_e) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[0] =
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegrato_e;
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerIntegrato_p)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[0] =
          Hummingbird_Flight_Controller_P.PIDController9_LowerIntegrato_p;
      }

      // Update for DiscreteIntegrator: '<S1435>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_h[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_kc *
        Hummingbird_Flight_Controller_B.DProdOut_n[0];

      // Update for DiscreteIntegrator: '<S1369>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_c[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_o *
        Hummingbird_Flight_Controller_B.prev_waypoint[0];

      // Update for DiscreteIntegrator: '<S1440>/Integrator' incorporates:
      //   Gain: '<S1437>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        Hummingbird_Flight_Controller_P.PIDController9_I_i[1] *
        Hummingbird_Flight_Controller_B.Filter_os[1] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_ma +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[1];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[1] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegrato_e) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[1] =
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegrato_e;
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerIntegrato_p)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[1] =
          Hummingbird_Flight_Controller_P.PIDController9_LowerIntegrato_p;
      }

      // Update for DiscreteIntegrator: '<S1435>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_h[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_kc *
        Hummingbird_Flight_Controller_B.DProdOut_n[1];

      // Update for DiscreteIntegrator: '<S1369>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_c[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_o *
        Hummingbird_Flight_Controller_B.prev_waypoint[1];

      // Update for DiscreteIntegrator: '<S1440>/Integrator' incorporates:
      //   Gain: '<S1437>/Integral Gain'
      //   Sum: '<S1172>/Sum1'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        Hummingbird_Flight_Controller_P.PIDController9_I_i[2] *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 *
        Hummingbird_Flight_Controller_P.Integrator_gainval_ma +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[2];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[2] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegrato_e) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[2] =
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegrato_e;
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerIntegrato_p)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[2] =
          Hummingbird_Flight_Controller_P.PIDController9_LowerIntegrato_p;
      }

      // Update for DiscreteIntegrator: '<S1435>/Filter' incorporates:
      //   Gain: '<S1443>/Filter Coefficient'

      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_h[2] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_kc *
        Hummingbird_Flight_Controller_B.scale;

      // Update for DiscreteIntegrator: '<S1369>/Filter' incorporates:
      //   Constant: '<S1170>/Constant4'
      //   DataTypeConversion: '<S5>/Cast To Double3'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //   Product: '<S1367>/DProd Out'
      //   Product: '<S1377>/NProd Out'
      //   Sum: '<S1170>/Sum6'
      //   Sum: '<S1369>/SumD'
      //
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_c[2] +=
        ((Hummingbird_Flight_Controller_B.Esp_dot -
          Hummingbird_Flight_Controller_B.a_n) *
         Hummingbird_Flight_Controller_B.ReadParameter2_l.ReadParameter2_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_c[2]) *
        Hummingbird_Flight_Controller_P.Constant4_Value_ey *
        Hummingbird_Flight_Controller_P.Filter_gainval_o;
    } else {
      exit_internal_Flight_controller();
      Hummingbird_Flight_Controlle_DW.is_Flight_controller =
        Hummingbird_Flig_IN_MR_Attitude;

      // Merge: '<S1>/ Merge ' incorporates:
      //   Constant: '<S8>/Constant14'
      //   SignalConversion generated from: '<S8>/dtFW'

      Hummingbird_Flight_Controller_B.dtFW =
        Hummingbird_Flight_Controller_P.Constant14_Value;

      // Sum: '<S545>/Sum21' incorporates:
      //   BusCreator: '<S5>/Bus Creator4'
      //   Constant: '<S773>/Constant'
      //   Gain: '<S773>/Gain'
      //   Sum: '<S773>/Sum'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 = (
        static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Throttle)
        - Hummingbird_Flight_Controller_P.Constant_Value_ct) *
        Hummingbird_Flight_Controller_P.Gain_Gain -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2;
      Hummingb_ReadParameter_b3rg
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ayu);
      Humming_ReadParameter1_b3rg
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ayu);

      // Product: '<S586>/NProd Out' incorporates:
      //   Constant: '<S545>/Constant'
      //   DiscreteIntegrator: '<S578>/Filter'
      //   Product: '<S576>/DProd Out'
      //   Sum: '<S578>/SumD'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 *
         Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu.ReadParameter1_o1
         - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_j) *
        Hummingbird_Flight_Controller_P.Constant_Value_fn;

      // Gain: '<S1168>/Gain5' incorporates:
      //   Gain: '<S545>/Gain5'
      //   Merge: '<S1>/ Merge 1'
      //   Product: '<S588>/PProd Out'
      //   Sum: '<S592>/Sum'

      Hummingbird_Flight_Controller_B.dtMR =
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 *
         Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu.ReadParameter_o1
         + Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0) *
        -Hummingbird_Flight_Controller_P.m;
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_m);

      // Gain: '<S547>/Gain1' incorporates:
      //   Constant: '<S774>/Constant'
      //   Gain: '<S774>/Gain'
      //   Sum: '<S774>/Sum'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Roll) -
         Hummingbird_Flight_Controller_P.Constant_Value_ag) *
        Hummingbird_Flight_Controller_P.Gain_Gain_m *
        Hummingbird_Flight_Controller_P.Gain1_Gain_h;

      // Saturate: '<S547>/Saturation1'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation1_UpperSat) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation1_UpperSat;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation1_LowerSat) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation1_LowerSat;
      }

      // Gain: '<S547>/Gain2' incorporates:
      //   Constant: '<S775>/Constant'
      //   Gain: '<S775>/Gain'
      //   Sum: '<S775>/Sum'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Pitch) -
         Hummingbird_Flight_Controller_P.Constant_Value_oq) *
        Hummingbird_Flight_Controller_P.Gain_Gain_i *
        Hummingbird_Flight_Controller_P.Gain2_Gain_c;

      // Saturate: '<S547>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_l) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_l;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_f) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_f;
      }

      // Gain: '<S547>/Gain' incorporates:
      //   Constant: '<S776>/Constant'
      //   Gain: '<S776>/Gain'
      //   Sum: '<S776>/Sum'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 = (
        static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Yaw) -
        Hummingbird_Flight_Controller_P.Constant_Value_l4) *
        Hummingbird_Flight_Controller_P.Gain_Gain_o *
        Hummingbird_Flight_Controller_P.Gain_Gain_ii;

      // BusAssignment: '<S604>/Bus Assignment' incorporates:
      //   Constant: '<S546>/Constant2'
      //   DataTypeConversion: '<S546>/Cast To Single7'
      //   DataTypeConversion: '<S546>/Cast To Single8'
      //   DataTypeConversion: '<S546>/Cast To Single9'
      //   MATLABSystem: '<S604>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_d.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_m.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_d.roll =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_d.pitch =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_d.yaw_rate =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_d._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant2_Value_b[0];
      Hummingbird_Flight_Controller_B.BusAssignment_d._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant2_Value_b[1];
      Hummingbird_Flight_Controller_B.BusAssignment_d._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant2_Value_b[2];
      Hummingbird_Flight_Controller_B.BusAssignment_d._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant2_Value_b[3];
      Hummingbird_Fligh_SinkBlock
        (&Hummingbird_Flight_Controller_B.BusAssignment_d,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_lp);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_ef);

      // Sum: '<S546>/Sum5' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double4'
      //   DataTypeConversion: '<S5>/Cast To Double5'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //
      Hummingbird_Flight_Controller_B.prev_waypoint[0] =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0;
      Hummingbird_Flight_Controller_B.prev_waypoint[1] =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1;
      Hummin_ReadParameter1_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu5,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ayu5);
      Humming_ReadParameter_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu5,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ayu5);
      Hummingb_ReadParameter2_b3r
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3);
      Hummi_ReadParameter1_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu5d,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ayu5d);
      Hummin_ReadParameter_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu5d,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ayu5d);
      Humming_ReadParameter2_b3rg
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3a,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3a);

      // Product: '<S700>/NProd Out' incorporates:
      //   Constant: '<S546>/Constant1'
      //   DiscreteIntegrator: '<S692>/Filter'
      //   Product: '<S690>/DProd Out'
      //   Sum: '<S692>/SumD'

      Hummingbird_Flight_Controller_B.Filter_os[0] =
        (Hummingbird_Flight_Controller_B.prev_waypoint[0] *
         Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu5d.ReadParameter1_o1
         - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_bl[0]) *
        Hummingbird_Flight_Controller_P.Constant1_Value_d;
      Hummingbird_Flight_Controller_B.Filter_os[1] =
        (Hummingbird_Flight_Controller_B.prev_waypoint[1] *
         Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu5d.ReadParameter_o1
         - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_bl[1]) *
        Hummingbird_Flight_Controller_P.Constant1_Value_d;

      // Sum: '<S706>/Sum' incorporates:
      //   Product: '<S702>/PProd Out'

      Hummingbird_Flight_Controller_B.DProdOut_n[0] =
        Hummingbird_Flight_Controller_B.prev_waypoint[0] *
        Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu5.ReadParameter1_o1
        + Hummingbird_Flight_Controller_B.Filter_os[0];
      Hummingbird_Flight_Controller_B.DProdOut_n[1] =
        Hummingbird_Flight_Controller_B.prev_waypoint[1] *
        Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu5.ReadParameter_o1
        + Hummingbird_Flight_Controller_B.Filter_os[1];

      // BusAssignment: '<S605>/Bus Assignment' incorporates:
      //   Constant: '<S546>/Constant3'
      //   DataTypeConversion: '<S546>/Cast To Single1'
      //   DataTypeConversion: '<S546>/Cast To Single2'
      //   DataTypeConversion: '<S546>/Cast To Single6'
      //   MATLABSystem: '<S605>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_kl.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_ef.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_kl.roll_rate =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[0]);
      Hummingbird_Flight_Controller_B.BusAssignment_kl.pitch_rate =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[1]);
      Hummingbird_Flight_Controller_B.BusAssignment_kl.yaw_rate = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_kl._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant3_Value_i[0];
      Hummingbird_Flight_Controller_B.BusAssignment_kl._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant3_Value_i[1];
      Hummingbird_Flight_Controller_B.BusAssignment_kl._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant3_Value_i[2];
      Hummingbird_Flight_Controller_B.BusAssignment_kl._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant3_Value_i[3];
      Hummingbird_Fli_SinkBlock_h
        (&Hummingbird_Flight_Controller_B.BusAssignment_kl,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_d);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_cf);

      // Sum: '<S546>/Sum4' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double7'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        Hummingbird_Flight_Controller_B.DProdOut_n[0];
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        Hummingbird_Flight_Controller_B.DProdOut_n[1];
      Hummingbird_Flight_Controller_B.DProdOut_n[0] =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 -
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[0];
      Hummingbird_Flight_Controller_B.DProdOut_n[1] =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 -
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[1];
      Hummingbird_Flight_Controller_B.DProdOut_n[2] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[2];

      // BusAssignment: '<S606>/Bus Assignment' incorporates:
      //   Constant: '<S546>/Constant'
      //   DataTypeConversion: '<S546>/Cast To Single3'
      //   DataTypeConversion: '<S546>/Cast To Single4'
      //   DataTypeConversion: '<S546>/Cast To Single5'
      //   MATLABSystem: '<S606>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_ox.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_cf.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_ox.roll_rate_error =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[0]);
      Hummingbird_Flight_Controller_B.BusAssignment_ox.pitch_rate_error =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[1]);
      Hummingbird_Flight_Controller_B.BusAssignment_ox.yaw_rate_error =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[2]);
      Hummingbird_Flight_Controller_B.BusAssignment_ox._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant_Value_pq[0];
      Hummingbird_Flight_Controller_B.BusAssignment_ox._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant_Value_pq[1];
      Hummingbird_Flight_Controller_B.BusAssignment_ox._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant_Value_pq[2];
      Hummingbird_Flight_Controller_B.BusAssignment_ox._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant_Value_pq[3];
      Hummingbird_Fli_SinkBlock_j
        (&Hummingbird_Flight_Controller_B.BusAssignment_ox,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_a);
      Humm_ReadParameter1_b3rgaen
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu5da,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ayu5da);
      Hummi_ReadParameter_b3rgaen
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu5da,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ayu5da);
      Hummin_ReadParameter2_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ay,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ay);
      Hum_ReadParameter1_b3rgaenb
        (&Hummingbird_Flight_Controller_B.ReadParameter1_j,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_j);
      Humm_ReadParameter_b3rgaenb
        (&Hummingbird_Flight_Controller_B.ReadParameter_j,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_j);
      Hummi_ReadParameter2_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ayu);

      // Merge: '<S1>/ Merge 2' incorporates:
      //   BusCreator: '<S5>/Bus Creator6'
      //   Product: '<S650>/PProd Out'
      //   Product: '<S754>/PProd Out'
      //   Sum: '<S546>/Sum3'

      Hummingbird_Flight_Controller_B.dM[0] =
        (Hummingbird_Flight_Controller_B.DProdOut_n[0] *
         Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu5da.ReadParameter1_o1
         - Hummingbird_Flight_Controller_B.Sum_e[0]) *
        Hummingbird_Flight_Controller_B.ReadParameter1_j.ReadParameter1_o1;
      Hummingbird_Flight_Controller_B.dM[1] =
        (Hummingbird_Flight_Controller_B.DProdOut_n[1] *
         Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu5da.ReadParameter_o1
         - Hummingbird_Flight_Controller_B.Sum_e[1]) *
        Hummingbird_Flight_Controller_B.ReadParameter_j.ReadParameter_o1;
      Hummingbird_Flight_Controller_B.dM[2] =
        (Hummingbird_Flight_Controller_B.DProdOut_n[2] *
         Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ay.ReadParameter2_o1
         - Hummingbird_Flight_Controller_B.Sum_e[2]) *
        Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu.ReadParameter2_o1;

      // Update for DiscreteIntegrator: '<S578>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_j +=
        Hummingbird_Flight_Controller_P.Filter_gainval_d *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;

      // Update for DiscreteIntegrator: '<S692>/Filter' incorporates:
      //   Constant: '<S546>/Constant1'
      //   DataTypeConversion: '<S5>/Cast To Double3'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //   Product: '<S690>/DProd Out'
      //   Product: '<S700>/NProd Out'
      //   Sum: '<S546>/Sum5'
      //   Sum: '<S692>/SumD'
      //
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_bl[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_p *
        Hummingbird_Flight_Controller_B.Filter_os[0];
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_bl[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_p *
        Hummingbird_Flight_Controller_B.Filter_os[1];
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_bl[2] +=
        ((Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
          Hummingbird_Flight_Controller_B.a_n) *
         Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3a.ReadParameter2_o1
         - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_bl[2]) *
        Hummingbird_Flight_Controller_P.Constant1_Value_d *
        Hummingbird_Flight_Controller_P.Filter_gainval_p;
    }
  } else {
    switch (Hummingbird_Flight_Controlle_DW.is_Flight_controller) {
     case Hummingbird_Flight_C_IN_FW_Nav1:
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_n);

      // MATLAB Function: '<S13>/MATLAB Function2'
      if (rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lat)
          || rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lon))
      {
        Hummingbird_Flight_Controller_B.prev_lat[0] =
          Hummingbird_Flight_Controlle_DW.mission_start[0];
        Hummingbird_Flight_Controller_B.prev_lat[1] =
          Hummingbird_Flight_Controlle_DW.mission_start[1];
        Hummingbird_Flight_Controller_B.prev_lat[2] =
          Hummingbird_Flight_Controlle_DW.mission_start[2];
      } else {
        Hummingbird_Flight_Controller_B.prev_lat[0] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lat;
        Hummingbird_Flight_Controller_B.prev_lat[1] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lon;
        Hummingbird_Flight_Controller_B.prev_lat[2] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.altitude;
      }

      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[0] =
        Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lat;
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[1] =
        Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lon;
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[2] =
        Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.altitude;
      Hummingbird_Flight_Cont_lla2ned(Hummingbird_Flight_Controller_B.prev_lat,
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c,
        Hummingbird_Flight_Controller_B.current_lat);
      Hummingbird_Flight_Controller_B.prev_waypoint[0] = 3.28084 *
        Hummingbird_Flight_Controller_B.current_lat[0] +
        Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.X;
      Hummingbird_Flight_Controller_B.prev_waypoint[1] = 3.28084 *
        Hummingbird_Flight_Controller_B.current_lat[1] +
        Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.Y;
      if (rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lat))
      {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 = 0.0;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 = 0.0;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 = 0.0;
      } else if (rtIsNaN
                 (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lon))
      {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 = 0.0;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 = 0.0;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 = 0.0;
      } else {
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[0] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lat;
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[1] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lon;
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[2] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.altitude;
        Hummingbird_Flight_Controller_B.prev_lat[0] =
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lat;
        Hummingbird_Flight_Controller_B.prev_lat[1] =
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lon;
        Hummingbird_Flight_Controller_B.prev_lat[2] =
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.altitude;
        Hummingbird_Flight_Cont_lla2ned
          (Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c,
           Hummingbird_Flight_Controller_B.prev_lat,
           Hummingbird_Flight_Controller_B.dv);
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 = 3.28084 *
          Hummingbird_Flight_Controller_B.dv[0] +
          Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.X;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 = 3.28084 *
          Hummingbird_Flight_Controller_B.dv[1] +
          Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.Y;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 = 3.28084 *
          Hummingbird_Flight_Controller_B.dv[2] +
          Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.Z;
      }

      if (rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.next.gps_pos.lat))
      {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 = 1.0;
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 = 1.0;
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 = 0.0;
      } else if (rtIsNaN
                 (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.next.gps_pos.lon))
      {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 = 1.0;
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 = 1.0;
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 = 0.0;
      } else {
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[0] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.next.gps_pos.lat;
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[1] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.next.gps_pos.lon;
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[2] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.next.gps_pos.altitude;
        Hummingbird_Flight_Controller_B.prev_lat[0] =
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lat;
        Hummingbird_Flight_Controller_B.prev_lat[1] =
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lon;
        Hummingbird_Flight_Controller_B.prev_lat[2] =
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.altitude;
        Hummingbird_Flight_Cont_lla2ned
          (Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c,
           Hummingbird_Flight_Controller_B.prev_lat,
           Hummingbird_Flight_Controller_B.dv);
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 = 3.28084 *
          Hummingbird_Flight_Controller_B.dv[0] +
          Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.X;
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 = 3.28084 *
          Hummingbird_Flight_Controller_B.dv[1] +
          Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.Y;
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 = 3.28084 *
          Hummingbird_Flight_Controller_B.dv[2] +
          Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.Z;
      }

      // SignalConversion generated from: '<S15>/ SFunction ' incorporates:
      //   BusCreator generated from: '<Root>/Chart'
      //   BusCreator: '<S5>/Bus Creator3'
      //   MATLAB Function: '<S13>/MATLAB Function1'

      Hummingbird_Flight_Controller_B.DProdOut_n[0] =
        Hummingbird_Flight_Controller_B.b_t;
      Hummingbird_Flight_Controller_B.DProdOut_n[1] =
        Hummingbird_Flight_Controller_B.CastToDouble25;
      Hummingbird_Flight_Controller_B.DProdOut_n[2] =
        Hummingbird_Flight_Controller_B.r_c;

      // MATLAB Function: '<S13>/MATLAB Function1' incorporates:
      //   BusCreator generated from: '<Root>/Chart'
      //   BusCreator: '<S5>/Bus Creator3'
      //   BusCreator: '<S5>/Bus Creator4'
      //   MATLAB Function: '<S14>/MATLAB Function'

      Hummingbird_Flight_Controller_B.scale = 3.3121686421112381E-170;
      Hummingbird_Flight_Controller_B.Esp_dot = fabs
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0);
      if (Hummingbird_Flight_Controller_B.Esp_dot > 3.3121686421112381E-170) {
        Hummingbird_Flight_Controller_B.V = 1.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.Esp_dot;
      } else {
        Hummingbird_Flight_Controller_B.t =
          Hummingbird_Flight_Controller_B.Esp_dot / 3.3121686421112381E-170;
        Hummingbird_Flight_Controller_B.V = Hummingbird_Flight_Controller_B.t *
          Hummingbird_Flight_Controller_B.t;
      }

      Hummingbird_Flight_Controller_B.IntegralGain_k = fabs
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1);
      if (Hummingbird_Flight_Controller_B.IntegralGain_k >
          Hummingbird_Flight_Controller_B.scale) {
        Hummingbird_Flight_Controller_B.t =
          Hummingbird_Flight_Controller_B.scale /
          Hummingbird_Flight_Controller_B.IntegralGain_k;
        Hummingbird_Flight_Controller_B.V = Hummingbird_Flight_Controller_B.V *
          Hummingbird_Flight_Controller_B.t * Hummingbird_Flight_Controller_B.t
          + 1.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.IntegralGain_k;
      } else {
        Hummingbird_Flight_Controller_B.t =
          Hummingbird_Flight_Controller_B.IntegralGain_k /
          Hummingbird_Flight_Controller_B.scale;
        Hummingbird_Flight_Controller_B.V += Hummingbird_Flight_Controller_B.t *
          Hummingbird_Flight_Controller_B.t;
      }

      Hummingbird_Flight_Controller_B.absxk = fabs
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2);
      if (Hummingbird_Flight_Controller_B.absxk >
          Hummingbird_Flight_Controller_B.scale) {
        Hummingbird_Flight_Controller_B.t =
          Hummingbird_Flight_Controller_B.scale /
          Hummingbird_Flight_Controller_B.absxk;
        Hummingbird_Flight_Controller_B.V = Hummingbird_Flight_Controller_B.V *
          Hummingbird_Flight_Controller_B.t * Hummingbird_Flight_Controller_B.t
          + 1.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.absxk;
      } else {
        Hummingbird_Flight_Controller_B.t =
          Hummingbird_Flight_Controller_B.absxk /
          Hummingbird_Flight_Controller_B.scale;
        Hummingbird_Flight_Controller_B.V += Hummingbird_Flight_Controller_B.t *
          Hummingbird_Flight_Controller_B.t;
      }

      Hummingbird_Flight_Controller_B.V = Hummingbird_Flight_Controller_B.scale *
        sqrt(Hummingbird_Flight_Controller_B.V);
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[0] =
        Hummingbird_Flight_Controller_B.b_t -
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[1] =
        Hummingbird_Flight_Controller_B.CastToDouble25 -
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1;
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[2] =
        Hummingbird_Flight_Controller_B.r_c -
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
      Hummingbird_Flight_Controller_B.t = 1.0 / (exp
        ((Hummingbird_Flight_Control_norm
          (Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c) - 300.0) / 50.0) +
        1.0) * 100.0;
      Hummingbird_Flight_Controller_B.absxk =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 -
        Hummingbird_Flight_Controller_B.prev_waypoint[0];
      Hummingbird_Flight_Controller_B.b_gamma =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 -
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;
      Hummingbird_Flight_Controller_B.eta =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
        Hummingbird_Flight_Controller_B.prev_waypoint[1];
      Hummingbird_Flight_Controller_B.Add1 =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1;
      Hummingbird_Flight_Controller_B.b_t -=
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 -
        (Hummingbird_Flight_Controller_B.absxk +
         Hummingbird_Flight_Controller_B.b_gamma) / sqrt
        (Hummingbird_Flight_Controller_B.absxk *
         Hummingbird_Flight_Controller_B.absxk +
         Hummingbird_Flight_Controller_B.b_gamma *
         Hummingbird_Flight_Controller_B.b_gamma) *
        Hummingbird_Flight_Controller_B.t;
      Hummingbird_Flight_Controller_B.r_c =
        Hummingbird_Flight_Controller_B.CastToDouble25 -
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
         (Hummingbird_Flight_Controller_B.eta +
          Hummingbird_Flight_Controller_B.Add1) / sqrt
         (Hummingbird_Flight_Controller_B.eta *
          Hummingbird_Flight_Controller_B.eta +
          Hummingbird_Flight_Controller_B.Add1 *
          Hummingbird_Flight_Controller_B.Add1) *
         Hummingbird_Flight_Controller_B.t);
      Hummingbird_Flight_Controller_B.theta = Hummingbird_Fligh_rt_atan2d_snf
        (Hummingbird_Flight_Controller_B.r_c,
         Hummingbird_Flight_Controller_B.b_t);
      Hummingbird_Flight_Controller_B.scale = 3.3121686421112381E-170;
      Hummingbird_Flight_Controller_B.CastToDouble25 = fabs
        (Hummingbird_Flight_Controller_B.b_t);
      if (Hummingbird_Flight_Controller_B.CastToDouble25 >
          3.3121686421112381E-170) {
        Hummingbird_Flight_Controller_B.absx = 1.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.CastToDouble25;
      } else {
        Hummingbird_Flight_Controller_B.b_t =
          Hummingbird_Flight_Controller_B.CastToDouble25 /
          3.3121686421112381E-170;
        Hummingbird_Flight_Controller_B.absx =
          Hummingbird_Flight_Controller_B.b_t *
          Hummingbird_Flight_Controller_B.b_t;
      }

      Hummingbird_Flight_Controller_B.CastToDouble25 = fabs
        (Hummingbird_Flight_Controller_B.r_c);
      if (Hummingbird_Flight_Controller_B.CastToDouble25 >
          Hummingbird_Flight_Controller_B.scale) {
        Hummingbird_Flight_Controller_B.b_t =
          Hummingbird_Flight_Controller_B.scale /
          Hummingbird_Flight_Controller_B.CastToDouble25;
        Hummingbird_Flight_Controller_B.absx =
          Hummingbird_Flight_Controller_B.absx *
          Hummingbird_Flight_Controller_B.b_t *
          Hummingbird_Flight_Controller_B.b_t + 1.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.CastToDouble25;
      } else {
        Hummingbird_Flight_Controller_B.b_t =
          Hummingbird_Flight_Controller_B.CastToDouble25 /
          Hummingbird_Flight_Controller_B.scale;
        Hummingbird_Flight_Controller_B.absx +=
          Hummingbird_Flight_Controller_B.b_t *
          Hummingbird_Flight_Controller_B.b_t;
      }

      Hummingbird_Flight_Controller_B.r_c =
        Hummingbird_Flight_Controller_B.scale * sqrt
        (Hummingbird_Flight_Controller_B.absx);
      Hummingbird_Flight_Controller_B.CastToDouble25 = sin
        (Hummingbird_Flight_Controller_B.theta);
      Hummingbird_Flight_Controller_B.b_t = cos
        (Hummingbird_Flight_Controller_B.theta);
      Hummingbird_Flight_Controller_B.theta = 0.0;
      for (Hummingbird_Flight_Controller_B.i = 0;
           Hummingbird_Flight_Controller_B.i < 3;
           Hummingbird_Flight_Controller_B.i++) {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.DProdOut_n[Hummingbird_Flight_Controller_B.i];
        Hummingbird_Flight_Controller_B.absx =
          Hummingbird_Flight_Controller_B.scale -
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;
        Hummingbird_Flight_Controller_B.x[3 * Hummingbird_Flight_Controller_B.i]
          = Hummingbird_Flight_Controller_B.absx;
        Hummingbird_Flight_Controller_B.absx = fabs
          (Hummingbird_Flight_Controller_B.absx);
        if (rtIsNaN(Hummingbird_Flight_Controller_B.absx)) {
          Hummingbird_Flight_Controller_B.theta = (rtNaN);
        } else if (Hummingbird_Flight_Controller_B.absx >
                   Hummingbird_Flight_Controller_B.theta) {
          Hummingbird_Flight_Controller_B.theta =
            Hummingbird_Flight_Controller_B.absx;
        }

        Hummingbird_Flight_Controller_B.absx =
          Hummingbird_Flight_Controller_B.scale -
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1;
        Hummingbird_Flight_Controller_B.x[3 * Hummingbird_Flight_Controller_B.i
          + 1] = Hummingbird_Flight_Controller_B.absx;
        Hummingbird_Flight_Controller_B.absx = fabs
          (Hummingbird_Flight_Controller_B.absx);
        if (rtIsNaN(Hummingbird_Flight_Controller_B.absx)) {
          Hummingbird_Flight_Controller_B.theta = (rtNaN);
        } else if (Hummingbird_Flight_Controller_B.absx >
                   Hummingbird_Flight_Controller_B.theta) {
          Hummingbird_Flight_Controller_B.theta =
            Hummingbird_Flight_Controller_B.absx;
        }

        Hummingbird_Flight_Controller_B.absx =
          Hummingbird_Flight_Controller_B.scale -
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
        Hummingbird_Flight_Controller_B.x[3 * Hummingbird_Flight_Controller_B.i
          + 2] = Hummingbird_Flight_Controller_B.absx;
        Hummingbird_Flight_Controller_B.absx = fabs
          (Hummingbird_Flight_Controller_B.absx);
        if (rtIsNaN(Hummingbird_Flight_Controller_B.absx)) {
          Hummingbird_Flight_Controller_B.theta = (rtNaN);
        } else if (Hummingbird_Flight_Controller_B.absx >
                   Hummingbird_Flight_Controller_B.theta) {
          Hummingbird_Flight_Controller_B.theta =
            Hummingbird_Flight_Controller_B.absx;
        }
      }

      if ((!rtIsInf(Hummingbird_Flight_Controller_B.theta)) && (!rtIsNaN
           (Hummingbird_Flight_Controller_B.theta))) {
        Hummingbird_Flight_Controll_svd(Hummingbird_Flight_Controller_B.x,
          Hummingbird_Flight_Controller_B.dv);
        Hummingbird_Flight_Controller_B.theta =
          Hummingbird_Flight_Controller_B.dv[0];
      }

      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_B.absxk *
        Hummingbird_Flight_Controller_B.Add1 -
        Hummingbird_Flight_Controller_B.b_gamma *
        Hummingbird_Flight_Controller_B.eta;
      if (rtIsNaN(Hummingbird_Flight_Controller_B.scale)) {
        Hummingbird_Flight_Controller_B.scale = (rtNaN);
      } else if (Hummingbird_Flight_Controller_B.scale < 0.0) {
        Hummingbird_Flight_Controller_B.scale = -1.0;
      } else {
        Hummingbird_Flight_Controller_B.scale =
          (Hummingbird_Flight_Controller_B.scale > 0.0);
      }

      Hummingbird_Flight_Controller_B.b_gamma = -(1.0 / (exp
        ((Hummingbird_Flight_Controller_B.theta - 300.0) / 50.0) + 1.0)) * 0.7 *
        Hummingbird_Flight_Controller_B.scale;
      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_B.r_c - Hummingbird_Flight_Controller_B.t;
      Hummingbird_Flight_Controller_B.absxk =
        Hummingbird_Flight_Controller_B.b_gamma *
        Hummingbird_Flight_Controller_B.r_c;
      Hummingbird_Flight_Controller_B.eta = sqrt
        (Hummingbird_Flight_Controller_B.scale *
         Hummingbird_Flight_Controller_B.scale +
         Hummingbird_Flight_Controller_B.absxk *
         Hummingbird_Flight_Controller_B.absxk) * (1.0 /
        Hummingbird_Flight_Controller_B.V);
      Hummingbird_Flight_Controller_B.Add1 = 1.0 /
        Hummingbird_Flight_Controller_B.eta;
      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_B.Add1 *
        -Hummingbird_Flight_Controller_B.scale;
      Hummingbird_Flight_Controller_B.absxk *=
        Hummingbird_Flight_Controller_B.Add1;
      Hummingbird_Flight_Controller_B.V = ((Hummingbird_Flight_Controller_B.t -
        Hummingbird_Flight_Controller_B.r_c) * Hummingbird_Flight_Controller_B.t
        / (Hummingbird_Flight_Controller_B.V * Hummingbird_Flight_Controller_B.V
           * (Hummingbird_Flight_Controller_B.eta *
              Hummingbird_Flight_Controller_B.eta)) + 1.0) *
        (Hummingbird_Flight_Controller_B.b_gamma /
         Hummingbird_Flight_Controller_B.eta);
      Hummingbird_Flight_Controller_B.t = Hummingbird_Fligh_rt_atan2d_snf
        (Hummingbird_Flight_Controller_B.absxk,
         Hummingbird_Flight_Controller_B.scale);
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 =
        Hummingbird_Fligh_rt_atan2d_snf
        (-Hummingbird_Flight_Controller_B.CastToDouble25 *
         Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 +
         Hummingbird_Flight_Controller_B.b_t *
         Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1,
         Hummingbird_Flight_Controller_B.b_t *
         Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 +
         Hummingbird_Flight_Controller_B.CastToDouble25 *
         Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1);
      if (Hummingbird_Flight_Controller_B.t > 0.0) {
        if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 >= 0.0) {
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
            -(Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 -
              Hummingbird_Flight_Controller_B.t);
        } else {
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
            -((Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 +
               6.2831853071795862) - Hummingbird_Flight_Controller_B.t);
        }
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 >= 0.0)
      {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          -(Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 -
            (Hummingbird_Flight_Controller_B.t + 6.2831853071795862));
      } else {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          -(Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 -
            Hummingbird_Flight_Controller_B.t);
      }

      // BusAssignment: '<S17>/Bus Assignment' incorporates:
      //   DataTypeConversion: '<S13>/Cast To Single'
      //   DataTypeConversion: '<S13>/Cast To Single1'
      //   DataTypeConversion: '<S13>/Cast To Single2'
      //   DataTypeConversion: '<S13>/Cast To Single5'
      //   DataTypeConversion: '<S13>/Cast To Single6'
      //   DataTypeConversion: '<S13>/Cast To Single7'
      //   MATLAB Function: '<S13>/MATLAB Function1'
      //   MATLAB Function: '<S13>/MATLAB Function2'
      //   MATLABSystem: '<S17>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_o.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_n.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_o.prev_waypoint[0] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.prev_waypoint[0]);
      Hummingbird_Flight_Controller_B.BusAssignment_o.current_waypoint[0] =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_o.next_waypoint[0] =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_o.prev_waypoint[1] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.prev_waypoint[1]);
      Hummingbird_Flight_Controller_B.BusAssignment_o.current_waypoint[1] =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_o.next_waypoint[1] =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_o.prev_waypoint[2] =
        static_cast<real32_T>(3.28084 *
        Hummingbird_Flight_Controller_B.current_lat[2] +
        Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.Z);
      Hummingbird_Flight_Controller_B.BusAssignment_o.current_waypoint[2] =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment_o.next_waypoint[2] =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment_o.angle_desired =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.t);
      Hummingbird_Flight_Controller_B.BusAssignment_o.angle_actual =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_o.alpha =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1);

      // MATLAB Function: '<S13>/MATLAB Function1'
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 = sin
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 / 2.0) *
        96.521999999999991;

      // BusAssignment: '<S17>/Bus Assignment' incorporates:
      //   DataTypeConversion: '<S13>/Cast To Single4'
      //   MATLAB Function: '<S13>/MATLAB Function1'

      Hummingbird_Flight_Controller_B.BusAssignment_o.as_a = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);

      // MATLAB Function: '<S13>/MATLAB Function1' incorporates:
      //   BusCreator generated from: '<Root>/Chart'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
        (Hummingbird_Flight_Controller_B.V *
         -Hummingbird_Flight_Controller_B.absxk * -sin
         (Hummingbird_Flight_Controller_B.course) +
         Hummingbird_Flight_Controller_B.V *
         Hummingbird_Flight_Controller_B.scale * cos
         (Hummingbird_Flight_Controller_B.course)) +
        Hummingbird_Flight_Controller_B.V * 0.0 * 0.0;

      // BusAssignment: '<S17>/Bus Assignment' incorporates:
      //   DataTypeConversion: '<S13>/Cast To Single3'
      //   MATLAB Function: '<S13>/MATLAB Function1'

      Hummingbird_Flight_Controller_B.BusAssignment_o.as_b =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);

      // MATLABSystem: '<S19>/SinkBlock' incorporates:
      //   BusAssignment: '<S17>/Bus Assignment'

      uORB_write_step(Hummingbird_Flight_Controlle_DW.obj_h3.orbMetadataObj,
                      &Hummingbird_Flight_Controlle_DW.obj_h3.orbAdvertiseObj,
                      &Hummingbird_Flight_Controller_B.BusAssignment_o);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_c);

      // MATLAB Function: '<S14>/MATLAB Function1' incorporates:
      //   BusCreator: '<S5>/Bus Creator9'

      if (rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lat)
          || rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lon))
      {
        Hummingbird_Flight_Controller_B.prev_lat_b[0] =
          Hummingbird_Flight_Controlle_DW.mission_start[0];
        Hummingbird_Flight_Controller_B.prev_lat_b[1] =
          Hummingbird_Flight_Controlle_DW.mission_start[1];
        Hummingbird_Flight_Controller_B.prev_lat_b[2] =
          Hummingbird_Flight_Controlle_DW.mission_start[2];
      } else {
        Hummingbird_Flight_Controller_B.prev_lat_b[0] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lat;
        Hummingbird_Flight_Controller_B.prev_lat_b[1] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lon;
        Hummingbird_Flight_Controller_B.prev_lat_b[2] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.altitude;
      }

      if (rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lat)
          || rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lon))
      {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          Hummingbird_Flight_Controller_B.In1_a.lat;
        Hummingbird_Flight_Controller_B.V =
          Hummingbird_Flight_Controller_B.In1_a.lon;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_B.CastToDouble25_f;
      } else {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lat;
        Hummingbird_Flight_Controller_B.V =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lon;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.altitude;
      }

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        -(Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 -
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.altitude);
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        -(Hummingbird_Flight_Controller_B.CastToDouble25_f -
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.altitude);
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[0] =
        Hummingbird_Flight_Controller_B.In1_a.lat;
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[1] =
        Hummingbird_Flight_Controller_B.In1_a.lon;
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[2] =
        Hummingbird_Flight_Controller_B.CastToDouble25_f;
      Hummingbird_Flight_Controller_B.current_lat[0] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      Hummingbird_Flight_Controller_B.current_lat[1] =
        Hummingbird_Flight_Controller_B.V;
      Hummingbird_Flight_Controller_B.current_lat[2] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
      Hummingbird_Flight_Co_lla2ned_f
        (Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c,
         Hummingbird_Flight_Controller_B.current_lat,
         Hummingbird_Flight_Controller_B.DProdOut_n);
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 = sqrt
        (Hummingbird_Flight_Controller_B.DProdOut_n[0] *
         Hummingbird_Flight_Controller_B.DProdOut_n[0] +
         Hummingbird_Flight_Controller_B.DProdOut_n[1] *
         Hummingbird_Flight_Controller_B.DProdOut_n[1]);
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 == 0.0) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 = 1.0;
      }

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 = atan
        (Hummingbird_Flight_Controller_B.DProdOut_n[2] /
         Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2);
      Hummingbird_Flight_Controller_B.current_lat[0] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      Hummingbird_Flight_Controller_B.current_lat[1] =
        Hummingbird_Flight_Controller_B.V;
      Hummingbird_Flight_Controller_B.current_lat[2] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
      Hummingbird_Flight_Co_lla2ned_f(Hummingbird_Flight_Controller_B.prev_lat_b,
        Hummingbird_Flight_Controller_B.current_lat,
        Hummingbird_Flight_Controller_B.DProdOut_n);
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 = sqrt
        (Hummingbird_Flight_Controller_B.DProdOut_n[0] *
         Hummingbird_Flight_Controller_B.DProdOut_n[0] +
         Hummingbird_Flight_Controller_B.DProdOut_n[1] *
         Hummingbird_Flight_Controller_B.DProdOut_n[1]);
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 == 0.0) {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 = 1.0;
      }

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 = atan
        (Hummingbird_Flight_Controller_B.DProdOut_n[2] /
         Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1);

      // MATLABSystem: '<S14>/Read Parameter'
      b_varargout_1 = MW_ParamRead_Step
        (Hummingbird_Flight_Controlle_DW.obj_lp.MW_PARAMHANDLE, MW_SINGLE,
         &Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2);
      if (b_varargout_1) {
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2 = 0.0F;
      }

      // Gain: '<S14>/Gain' incorporates:
      //   MATLABSystem: '<S14>/Read Parameter'
      //
      Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2 *=
        Hummingbird_Flight_Controller_P.Gain_Gain_h;

      // BusAssignment: '<S25>/Bus Assignment' incorporates:
      //   BusCreator generated from: '<Root>/Chart'
      //   Constant: '<S14>/Constant3'
      //   DataTypeConversion: '<S14>/Cast To Single1'
      //   DataTypeConversion: '<S14>/Cast To Single10'
      //   DataTypeConversion: '<S14>/Cast To Single11'
      //   DataTypeConversion: '<S14>/Cast To Single13'
      //   DataTypeConversion: '<S14>/Cast To Single8'
      //   DataTypeConversion: '<S14>/Cast To Single9'
      //   MATLAB Function: '<S14>/MATLAB Function1'
      //   MATLABSystem: '<S25>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_og.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_c.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_og.h_sp =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_og.h = static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_og.climb_angle_sp =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_og.climb_angle_ideal =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_og.horz_dist =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment_og.v_sp =
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2;
      Hummingbird_Flight_Controller_B.BusAssignment_og.v = static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.CastToDouble8);
      Hummingbird_Flight_Controller_B.BusAssignment_og._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant3_Value_h[0];
      Hummingbird_Flight_Controller_B.BusAssignment_og._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant3_Value_h[1];
      Hummingbird_Flight_Controller_B.BusAssignment_og._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant3_Value_h[2];
      Hummingbird_Flight_Controller_B.BusAssignment_og._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant3_Value_h[3];

      // MATLABSystem: '<S187>/SinkBlock' incorporates:
      //   BusAssignment: '<S25>/Bus Assignment'

      uORB_write_step(Hummingbird_Flight_Controlle_DW.obj_lf.orbMetadataObj,
                      &Hummingbird_Flight_Controlle_DW.obj_lf.orbAdvertiseObj,
                      &Hummingbird_Flight_Controller_B.BusAssignment_og);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_e);

      // MATLAB Function: '<S14>/MATLAB Function' incorporates:
      //   BusCreator generated from: '<Root>/Chart'
      //   BusCreator: '<S5>/Bus Creator4'
      //   Constant: '<S14>/Constant'

      Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3 =
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2;
      Hummingbird_Flight_Controller_B.V =
        Hummingbird_Flight_Controller_B.CastToDouble8;
      Hummingbird_Flight_Controller_B.scale = 3.3121686421112381E-170;
      if (Hummingbird_Flight_Controller_B.Esp_dot > 3.3121686421112381E-170) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 = 1.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.Esp_dot;
      } else {
        Hummingbird_Flight_Controller_B.t =
          Hummingbird_Flight_Controller_B.Esp_dot / 3.3121686421112381E-170;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_B.t * Hummingbird_Flight_Controller_B.t;
      }

      if (Hummingbird_Flight_Controller_B.IntegralGain_k >
          Hummingbird_Flight_Controller_B.scale) {
        Hummingbird_Flight_Controller_B.t =
          Hummingbird_Flight_Controller_B.scale /
          Hummingbird_Flight_Controller_B.IntegralGain_k;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 *
          Hummingbird_Flight_Controller_B.t * Hummingbird_Flight_Controller_B.t
          + 1.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.IntegralGain_k;
      } else {
        Hummingbird_Flight_Controller_B.t =
          Hummingbird_Flight_Controller_B.IntegralGain_k /
          Hummingbird_Flight_Controller_B.scale;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 +=
          Hummingbird_Flight_Controller_B.t * Hummingbird_Flight_Controller_B.t;
      }

      Hummingbird_Flight_Controller_B.IntegralGain_k = atan
        (-Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 /
         (Hummingbird_Flight_Controller_B.scale * sqrt
          (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2)));
      Hummingbird_Flight_Controller_B.scale = 3.3121686421112381E-170;
      Hummingbird_Flight_Controller_B.CastToDouble25 = fabs
        (Hummingbird_Flight_Controller_B.X);
      if (Hummingbird_Flight_Controller_B.CastToDouble25 >
          3.3121686421112381E-170) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 = 1.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.CastToDouble25;
      } else {
        Hummingbird_Flight_Controller_B.b_t =
          Hummingbird_Flight_Controller_B.CastToDouble25 /
          3.3121686421112381E-170;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_B.b_t *
          Hummingbird_Flight_Controller_B.b_t;
      }

      Hummingbird_Flight_Controller_B.CastToDouble25 = fabs
        (Hummingbird_Flight_Controller_B.Y);
      if (Hummingbird_Flight_Controller_B.CastToDouble25 >
          Hummingbird_Flight_Controller_B.scale) {
        Hummingbird_Flight_Controller_B.b_t =
          Hummingbird_Flight_Controller_B.scale /
          Hummingbird_Flight_Controller_B.CastToDouble25;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 *
          Hummingbird_Flight_Controller_B.b_t *
          Hummingbird_Flight_Controller_B.b_t + 1.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.CastToDouble25;
      } else {
        Hummingbird_Flight_Controller_B.b_t =
          Hummingbird_Flight_Controller_B.CastToDouble25 /
          Hummingbird_Flight_Controller_B.scale;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 +=
          Hummingbird_Flight_Controller_B.b_t *
          Hummingbird_Flight_Controller_B.b_t;
      }

      Hummingbird_Flight_Controller_B.CastToDouble25 = fabs
        (Hummingbird_Flight_Controller_B.Z);
      if (Hummingbird_Flight_Controller_B.CastToDouble25 >
          Hummingbird_Flight_Controller_B.scale) {
        Hummingbird_Flight_Controller_B.b_t =
          Hummingbird_Flight_Controller_B.scale /
          Hummingbird_Flight_Controller_B.CastToDouble25;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 *
          Hummingbird_Flight_Controller_B.b_t *
          Hummingbird_Flight_Controller_B.b_t + 1.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.CastToDouble25;
      } else {
        Hummingbird_Flight_Controller_B.b_t =
          Hummingbird_Flight_Controller_B.CastToDouble25 /
          Hummingbird_Flight_Controller_B.scale;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 +=
          Hummingbird_Flight_Controller_B.b_t *
          Hummingbird_Flight_Controller_B.b_t;
      }

      Hummingbird_Flight_Controller_B.Esp_dot =
        Hummingbird_Flight_Controller_P.Constant_Value_h / 32.2 + sin
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0);
      Hummingbird_Flight_Controller_B.scale =
        (Hummingbird_Flight_Controller_B.scale * sqrt
         (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) - 9.81) /
        32.2;
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        Hummingbird_Flight_Controller_B.scale + sin
        (Hummingbird_Flight_Controller_B.IntegralGain_k);
      if (Hummingbird_Flight_Controller_B.CastToDouble8 == 0.0) {
        Hummingbird_Flight_Controller_B.V = 1.0;
      }

      if (Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2 == 0.0F) {
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3 = 1.0F;
      }

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 -=
        Hummingbird_Flight_Controller_P.Constant_Value_h / 32.2;
      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_B.IntegralGain_k -
        Hummingbird_Flight_Controller_B.scale;

      // BusAssignment: '<S26>/Bus Assignment' incorporates:
      //   BusCreator generated from: '<Root>/Chart'
      //   DataTypeConversion: '<S14>/Cast To Single'
      //   MATLAB Function: '<S14>/MATLAB Function'
      //   MATLABSystem: '<S26>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_k.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_e.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_k.energy = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.CastToDouble8 *
                  Hummingbird_Flight_Controller_B.CastToDouble8 *
                  0.6211180124223602 + 40.0 *
                  -Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);

      // MATLAB Function: '<S14>/MATLAB Function' incorporates:
      //   MATLAB Function: '<S14>/MATLAB Function1'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        -Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 -
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 * tan
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1);

      // BusAssignment: '<S26>/Bus Assignment' incorporates:
      //   Constant: '<S14>/Constant1'
      //   DataTypeConversion: '<S14>/Cast To Single14'
      //   DataTypeConversion: '<S14>/Cast To Single3'
      //   DataTypeConversion: '<S14>/Cast To Single4'
      //   DataTypeConversion: '<S14>/Cast To Single5'
      //   DataTypeConversion: '<S14>/Cast To Single6'
      //   DataTypeConversion: '<S14>/Cast To Single7'
      //   MATLAB Function: '<S14>/MATLAB Function'

      Hummingbird_Flight_Controller_B.BusAssignment_k.energy_setpoint =
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2 *
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2 * 0.621118F +
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 * 40.0);
      Hummingbird_Flight_Controller_B.BusAssignment_k.energy_setpoint_dot =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.Esp_dot);
      Hummingbird_Flight_Controller_B.BusAssignment_k.energy_dot =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment_k.energy_ratio =
        static_cast<real32_T>(32.2 *
        -Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 /
        (Hummingbird_Flight_Controller_B.V * Hummingbird_Flight_Controller_B.V *
         0.5));
      Hummingbird_Flight_Controller_B.BusAssignment_k.energy_ratio_sp =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 * 32.2) /
        (Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3 *
         Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3 * 0.5F);
      Hummingbird_Flight_Controller_B.BusAssignment_k.energy_ratio_dot =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.scale);
      Hummingbird_Flight_Controller_B.BusAssignment_k.energy_ratio_setpoint_dot =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_k.climb_angle = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.IntegralGain_k);
      Hummingbird_Flight_Controller_B.BusAssignment_k._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant1_Value_a[0];
      Hummingbird_Flight_Controller_B.BusAssignment_k._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant1_Value_a[1];
      Hummingbird_Flight_Controller_B.BusAssignment_k._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant1_Value_a[2];
      Hummingbird_Flight_Controller_B.BusAssignment_k._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant1_Value_a[3];

      // MATLABSystem: '<S189>/SinkBlock' incorporates:
      //   BusAssignment: '<S26>/Bus Assignment'

      uORB_write_step(Hummingbird_Flight_Controlle_DW.obj_cx.orbMetadataObj,
                      &Hummingbird_Flight_Controlle_DW.obj_cx.orbAdvertiseObj,
                      &Hummingbird_Flight_Controller_B.BusAssignment_k);

      // Sum: '<S14>/Sum3'
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 -
        Hummingbird_Flight_Controller_B.scale;
      Hummingbird__ReadParameter3
        (&Hummingbird_Flight_Controller_B.ReadParameter3,
         &Hummingbird_Flight_Controlle_DW.ReadParameter3);

      // Product: '<S113>/IProd Out'
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 *
        Hummingbird_Flight_Controller_B.ReadParameter3.ReadParameter3_o1;

      // MATLABSystem: '<S27>/Read Parameter2'
      b_varargout_1 = MW_ParamRead_Step
        (Hummingbird_Flight_Controlle_DW.obj_kb.MW_PARAMHANDLE, MW_SINGLE,
         &Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2);
      if (b_varargout_1) {
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2 = 0.0F;
      }

      // Sum: '<S125>/Sum' incorporates:
      //   DiscreteIntegrator: '<S116>/Integrator'
      //   MATLABSystem: '<S27>/Read Parameter2'
      //   Product: '<S121>/PProd Out'
      //
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 *
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2 +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_l;

      // Sum: '<S14>/Sum4'
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        Hummingbird_Flight_Controller_B.Esp_dot -
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;

      // MATLABSystem: '<S29>/Read Parameter1'
      b_varargout_1 = MW_ParamRead_Step
        (Hummingbird_Flight_Controlle_DW.obj_mt.MW_PARAMHANDLE, MW_SINGLE,
         &Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2);
      if (b_varargout_1) {
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2 = 0.0F;
      }

      // MATLABSystem: '<S29>/Read Parameter'
      b_varargout_1 = MW_ParamRead_Step
        (Hummingbird_Flight_Controlle_DW.obj_ee.MW_PARAMHANDLE, MW_SINGLE,
         &Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3);
      if (b_varargout_1) {
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3 = 0.0F;
      }

      // MATLABSystem: '<S27>/Read Parameter1'
      b_varargout_1 = MW_ParamRead_Step
        (Hummingbird_Flight_Controlle_DW.obj_eq.MW_PARAMHANDLE, MW_SINGLE,
         &Hummingbird_Flight_Controller_B.ParamStep);
      if (b_varargout_1) {
        Hummingbird_Flight_Controller_B.ParamStep = 0.0F;
      }

      // MATLABSystem: '<S29>/Read Parameter2'
      b_varargout_1 = MW_ParamRead_Step
        (Hummingbird_Flight_Controlle_DW.obj_oy.MW_PARAMHANDLE, MW_SINGLE,
         &Hummingbird_Flight_Controller_B.ParamStep_i);
      if (b_varargout_1) {
        Hummingbird_Flight_Controller_B.ParamStep_i = 0.0F;
      }

      // Sum: '<S177>/Sum' incorporates:
      //   DiscreteIntegrator: '<S168>/Integrator'
      //   MATLABSystem: '<S29>/Read Parameter'
      //   Product: '<S173>/PProd Out'
      //
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 *
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3 +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_ld;

      // Saturate: '<S175>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController3_UpperSaturationL) {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          Hummingbird_Flight_Controller_P.PIDController3_UpperSaturationL;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController3_LowerSaturationL)
      {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          Hummingbird_Flight_Controller_P.PIDController3_LowerSaturationL;
      }

      // Merge: '<S1>/ Merge ' incorporates:
      //   MATLABSystem: '<S29>/Read Parameter2'
      //   Product: '<S14>/Product1'
      //   Saturate: '<S175>/Saturation'
      //   Sum: '<S14>/Sum5'
      //
      Hummingbird_Flight_Controller_B.dtFW =
        Hummingbird_Flight_Controller_B.Esp_dot *
        Hummingbird_Flight_Controller_B.ParamStep_i +
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;

      // MATLABSystem: '<S28>/Read Parameter'
      MW_ParamRead_Step(Hummingbird_Flight_Controlle_DW.obj_io.MW_PARAMHANDLE,
                        MW_SINGLE,
                        &Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3);
      Hummingbird__ReadParameter3
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3);

      // MATLABSystem: '<S28>/Read Parameter2'
      MW_ParamRead_Step(Hummingbird_Flight_Controlle_DW.obj_ou.MW_PARAMHANDLE,
                        MW_SINGLE,
                        &Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_i);

      // Trigonometry: '<S13>/Trigonometric Function2' incorporates:
      //   Gain: '<S13>/Gain3'
      //   MATLAB Function: '<S13>/MATLAB Function1'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 = atan
        ((Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 +
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0) * (1.0 /
          Hummingbird_Flight_Controller_P.g));

      // Saturate: '<S13>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat) {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat) {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat;
      }

      // Gain: '<S198>/Gain10' incorporates:
      //   Constant: '<S198>/Constant7'
      //   Saturate: '<S13>/Saturation'
      //   Sum: '<S198>/Sum8'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 -
         Hummingbird_Flight_Controller_P.Constant7_Value) *
        Hummingbird_Flight_Controller_P.Gain10_Gain;

      // Saturate: '<S198>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_f) {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_f;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_j) {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_j;
      }

      // Gain: '<S12>/Gain1' incorporates:
      //   Saturate: '<S198>/Saturation'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        Hummingbird_Flight_Controller_P.Gain1_Gain *
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;

      // Saturate: '<S123>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.PIDController2_UpperSaturationL) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.PIDController2_UpperSaturationL;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.PIDController2_LowerSaturationL)
      {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.PIDController2_LowerSaturationL;
      }

      // Sum: '<S14>/Sum2' incorporates:
      //   MATLABSystem: '<S27>/Read Parameter1'
      //   Product: '<S14>/Product'
      //   Saturate: '<S123>/Saturation'
      //
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 +=
        Hummingbird_Flight_Controller_B.ParamStep *
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;

      // Saturate: '<S14>/Saturation2'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation2_UpperSat) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation2_UpperSat;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation2_LowerSat) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation2_LowerSat;
      }

      // Gain: '<S199>/Gain10' incorporates:
      //   Constant: '<S199>/Constant7'
      //   Saturate: '<S14>/Saturation2'
      //   Sum: '<S199>/Sum8'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 -
         Hummingbird_Flight_Controller_P.Constant7_Value_i) *
        Hummingbird_Flight_Controller_P.Gain10_Gain_n;

      // Saturate: '<S199>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_fz) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_fz;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_b) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_b;
      }

      // Gain: '<S12>/Gain2' incorporates:
      //   Saturate: '<S199>/Saturation'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
        Hummingbird_Flight_Controller_P.Gain2_Gain *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;

      // Gain: '<S200>/Gain10' incorporates:
      //   Constant: '<S200>/Constant7'
      //   Constant: '<S6>/Constant'
      //   Sum: '<S200>/Sum8'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (Hummingbird_Flight_Controller_P.Constant_Value_mf -
         Hummingbird_Flight_Controller_P.Constant7_Value_n) *
        Hummingbird_Flight_Controller_P.Gain10_Gain_a;

      // Saturate: '<S200>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_e) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_e;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_p) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_p;
      }

      // Gain: '<S12>/Gain3' incorporates:
      //   Saturate: '<S200>/Saturation'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 *=
        Hummingbird_Flight_Controller_P.Gain3_Gain;

      // Sum: '<S12>/Sum' incorporates:
      //   BusCreator generated from: '<Root>/Chart'
      //   Gain: '<S12>/Gain4'
      //   Product: '<S12>/Divide'
      //   Trigonometry: '<S12>/Trigonometric Function1'
      //   Trigonometry: '<S12>/Trigonometric Function3'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 =
        Hummingbird_Flight_Controller_P.Gain4_Gain * tan
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0) * cos
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1) /
        Hummingbird_Flight_Controller_B.CastToDouble8 +
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;

      // BusAssignment: '<S194>/Bus Assignment' incorporates:
      //   Constant: '<S12>/Constant2'
      //   DataTypeConversion: '<S12>/Cast To Single7'
      //   DataTypeConversion: '<S12>/Cast To Single8'
      //   DataTypeConversion: '<S12>/Cast To Single9'
      //   MATLABSystem: '<S194>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_fn.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_i.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_fn.roll =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_fn.pitch =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_fn.yaw_rate =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_fn._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant2_Value_pj[0];
      Hummingbird_Flight_Controller_B.BusAssignment_fn._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant2_Value_pj[1];
      Hummingbird_Flight_Controller_B.BusAssignment_fn._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant2_Value_pj[2];
      Hummingbird_Flight_Controller_B.BusAssignment_fn._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant2_Value_pj[3];
      Hummingbird_Fligh_SinkBlock
        (&Hummingbird_Flight_Controller_B.BusAssignment_fn,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_f);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_p);

      // Sum: '<S12>/Sum5' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double3'
      //   DataTypeConversion: '<S5>/Cast To Double4'
      //   DataTypeConversion: '<S5>/Cast To Double5'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //
      Hummingbird_Flight_Controller_B.DProdOut_n[0] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0;
      Hummingbird_Flight_Controller_B.DProdOut_n[1] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1;
      Hummingbird_Flight_Controller_B.DProdOut_n[2] =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 -
        Hummingbird_Flight_Controller_B.a_n;
      Hummingbird__ReadParameter1
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rg,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rg);
      Hummingbird_F_ReadParameter
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rg,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rg);
      Hummingbir_ReadParameter1_b
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rga,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rga);
      Hummingbird_ReadParameter_b
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rga,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rga);

      // Product: '<S294>/NProd Out' incorporates:
      //   Constant: '<S12>/Constant1'
      //   Constant: '<S201>/Constant'
      //   DiscreteIntegrator: '<S286>/Filter'
      //   Product: '<S284>/DProd Out'
      //   Sum: '<S286>/SumD'

      Hummingbird_Flight_Controller_B.prev_waypoint[0] =
        (Hummingbird_Flight_Controller_B.DProdOut_n[0] *
         Hummingbird_Flight_Controller_B.ReadParameter1_b3rga.ReadParameter1_o1
         - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_js[0]) *
        Hummingbird_Flight_Controller_P.Constant1_Value;
      Hummingbird_Flight_Controller_B.prev_waypoint[1] =
        (Hummingbird_Flight_Controller_B.DProdOut_n[1] *
         Hummingbird_Flight_Controller_B.ReadParameter_b3rga.ReadParameter_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_js[1]) *
        Hummingbird_Flight_Controller_P.Constant1_Value;
      Hummingbird_Flight_Controller_B.prev_waypoint[2] =
        (Hummingbird_Flight_Controller_B.DProdOut_n[2] *
         Hummingbird_Flight_Controller_P.Constant_Value_ic -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_js[2]) *
        Hummingbird_Flight_Controller_P.Constant1_Value;

      // Sum: '<S300>/Sum' incorporates:
      //   Constant: '<S197>/Constant'
      //   Product: '<S296>/PProd Out'

      Hummingbird_Flight_Controller_B.Filter_os[0] =
        Hummingbird_Flight_Controller_B.DProdOut_n[0] *
        Hummingbird_Flight_Controller_B.ReadParameter1_b3rg.ReadParameter1_o1 +
        Hummingbird_Flight_Controller_B.prev_waypoint[0];
      Hummingbird_Flight_Controller_B.Filter_os[1] =
        Hummingbird_Flight_Controller_B.DProdOut_n[1] *
        Hummingbird_Flight_Controller_B.ReadParameter_b3rg.ReadParameter_o1 +
        Hummingbird_Flight_Controller_B.prev_waypoint[1];
      Hummingbird_Flight_Controller_B.Filter_os[2] =
        Hummingbird_Flight_Controller_B.DProdOut_n[2] *
        Hummingbird_Flight_Controller_P.Constant_Value_d +
        Hummingbird_Flight_Controller_B.prev_waypoint[2];

      // MATLAB Function: '<S12>/MATLAB Function'
      Hummingbird__MATLABFunction
        (&Hummingbird_Flight_Controller_B.BusConversion_InsertedFor_Chart,
         &Hummingbird_Flight_Controller_B.Filter_os[0],
         Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0,
         Hummingbird_Flight_Controller_B.DProdOut_n,
         &Hummingbird_Flight_Controller_B.sf_MATLABFunction_n);

      // BusAssignment: '<S195>/Bus Assignment' incorporates:
      //   Constant: '<S12>/Constant3'
      //   DataTypeConversion: '<S12>/Cast To Single1'
      //   DataTypeConversion: '<S12>/Cast To Single2'
      //   DataTypeConversion: '<S12>/Cast To Single6'
      //   MATLABSystem: '<S195>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_p.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_p.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_p.roll_rate = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[0]);
      Hummingbird_Flight_Controller_B.BusAssignment_p.pitch_rate = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[1]);
      Hummingbird_Flight_Controller_B.BusAssignment_p.yaw_rate =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[2]);
      Hummingbird_Flight_Controller_B.BusAssignment_p._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant3_Value_n[0];
      Hummingbird_Flight_Controller_B.BusAssignment_p._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant3_Value_n[1];
      Hummingbird_Flight_Controller_B.BusAssignment_p._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant3_Value_n[2];
      Hummingbird_Flight_Controller_B.BusAssignment_p._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant3_Value_n[3];
      Hummingbird_Fli_SinkBlock_h
        (&Hummingbird_Flight_Controller_B.BusAssignment_p,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_h);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_b);

      // Sum: '<S12>/Sum4' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double7'

      Hummingbird_Flight_Controller_B.Filter_os[0] =
        Hummingbird_Flight_Controller_B.DProdOut_n[0] -
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[0];
      Hummingbird_Flight_Controller_B.Filter_os[1] =
        Hummingbird_Flight_Controller_B.DProdOut_n[1] -
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[1];
      Hummingbird_Flight_Controller_B.Filter_os[2] =
        Hummingbird_Flight_Controller_B.DProdOut_n[2] -
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[2];
      Hummingbi_ReadParameter1_b3
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgae,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgae);
      Hummingbir_ReadParameter_b3
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgae,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgae);
      Hummingbird__ReadParameter2
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3r,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3r);
      Hummingbir_ReadParameter3_b
        (&Hummingbird_Flight_Controller_B.ReadParameter3_b,
         &Hummingbird_Flight_Controlle_DW.ReadParameter3_b);
      Hummingbir_ReadParameter2_b
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rg,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rg);
      Hummingbird__ReadParameter4
        (&Hummingbird_Flight_Controller_B.ReadParameter4,
         &Hummingbird_Flight_Controlle_DW.ReadParameter4);

      // Product: '<S242>/NProd Out' incorporates:
      //   Constant: '<S12>/Constant4'
      //   DiscreteIntegrator: '<S234>/Filter'
      //   Product: '<S232>/DProd Out'
      //   Sum: '<S234>/SumD'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
        (Hummingbird_Flight_Controller_B.Filter_os[0] *
         Hummingbird_Flight_Controller_B.ReadParameter3_b.ReadParameter3_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_o[0]) *
        Hummingbird_Flight_Controller_P.Constant4_Value;
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (Hummingbird_Flight_Controller_B.Filter_os[1] *
         Hummingbird_Flight_Controller_B.ReadParameter2_b3rg.ReadParameter2_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_o[1]) *
        Hummingbird_Flight_Controller_P.Constant4_Value;
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        (Hummingbird_Flight_Controller_B.Filter_os[2] *
         Hummingbird_Flight_Controller_B.ReadParameter4.ReadParameter4_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_o[2]) *
        Hummingbird_Flight_Controller_P.Constant4_Value;

      // Sum: '<S248>/Sum' incorporates:
      //   Product: '<S244>/PProd Out'

      Hummingbird_Flight_Controller_B.DProdOut_n[0] =
        Hummingbird_Flight_Controller_B.Filter_os[0] *
        Hummingbird_Flight_Controller_B.ReadParameter1_b3rgae.ReadParameter1_o1
        + Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1;
      Hummingbird_Flight_Controller_B.DProdOut_n[1] =
        Hummingbird_Flight_Controller_B.Filter_os[1] *
        Hummingbird_Flight_Controller_B.ReadParameter_b3rgae.ReadParameter_o1 +
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;
      Hummingbird_Flight_Controller_B.DProdOut_n[2] =
        Hummingbird_Flight_Controller_B.Filter_os[2] *
        Hummingbird_Flight_Controller_B.ReadParameter2_b3r.ReadParameter2_o1 +
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;

      // BusAssignment: '<S196>/Bus Assignment' incorporates:
      //   Constant: '<S12>/Constant'
      //   DataTypeConversion: '<S12>/Cast To Single3'
      //   DataTypeConversion: '<S12>/Cast To Single4'
      //   DataTypeConversion: '<S12>/Cast To Single5'
      //   MATLABSystem: '<S196>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_b.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_b.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_b.roll_rate_error =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[0]);
      Hummingbird_Flight_Controller_B.BusAssignment_b.pitch_rate_error =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[1]);
      Hummingbird_Flight_Controller_B.BusAssignment_b.yaw_rate_error =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[2]);
      Hummingbird_Flight_Controller_B.BusAssignment_b._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant_Value_e4[0];
      Hummingbird_Flight_Controller_B.BusAssignment_b._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant_Value_e4[1];
      Hummingbird_Flight_Controller_B.BusAssignment_b._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant_Value_e4[2];
      Hummingbird_Flight_Controller_B.BusAssignment_b._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant_Value_e4[3];
      Hummingbird_Fli_SinkBlock_j
        (&Hummingbird_Flight_Controller_B.BusAssignment_b,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_j);

      // Sum: '<S12>/Sum3'
      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_B.DProdOut_n[0];
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 =
        Hummingbird_Flight_Controller_B.DProdOut_n[1];
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_B.DProdOut_n[2];
      Hummingb_ReadParameter1_b3r
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaen,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaen);
      Hummingbi_ReadParameter_b3r
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaen,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaen);
      Hummingbi_ReadParameter2_b3
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rga,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rga);

      // Merge: '<S1>/ Merge 2' incorporates:
      //   BusCreator: '<S5>/Bus Creator6'
      //   Product: '<S348>/PProd Out'
      //   Sum: '<S12>/Sum3'

      Hummingbird_Flight_Controller_B.dM[0] =
        (Hummingbird_Flight_Controller_B.scale -
         Hummingbird_Flight_Controller_B.Sum_e[0]) *
        Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaen.ReadParameter1_o1;
      Hummingbird_Flight_Controller_B.dM[1] =
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 -
         Hummingbird_Flight_Controller_B.Sum_e[1]) *
        Hummingbird_Flight_Controller_B.ReadParameter_b3rgaen.ReadParameter_o1;
      Hummingbird_Flight_Controller_B.dM[2] =
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 -
         Hummingbird_Flight_Controller_B.Sum_e[2]) *
        Hummingbird_Flight_Controller_B.ReadParameter2_b3rga.ReadParameter2_o1;

      // Gain: '<S1168>/Gain5' incorporates:
      //   Constant: '<S6>/Constant11'
      //   Merge: '<S1>/ Merge 1'
      //   SignalConversion generated from: '<S6>/dtMR'

      Hummingbird_Flight_Controller_B.dtMR =
        Hummingbird_Flight_Controller_P.Constant11_Value;

      // Update for DiscreteIntegrator: '<S116>/Integrator'
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_l +=
        Hummingbird_Flight_Controller_P.Integrator_gainval *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2;
      if (Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_l >
          Hummingbird_Flight_Controller_P.PIDController2_UpperIntegratorS) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_l =
          Hummingbird_Flight_Controller_P.PIDController2_UpperIntegratorS;
      } else if (Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_l <
                 Hummingbird_Flight_Controller_P.PIDController2_LowerIntegratorS)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_l =
          Hummingbird_Flight_Controller_P.PIDController2_LowerIntegratorS;
      }

      // Update for DiscreteIntegrator: '<S168>/Integrator' incorporates:
      //   MATLABSystem: '<S29>/Read Parameter1'
      //   Product: '<S165>/IProd Out'
      //
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_ld +=
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 *
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2 *
        Hummingbird_Flight_Controller_P.Integrator_gainval_k;
      if (Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_ld >
          Hummingbird_Flight_Controller_P.PIDController3_UpperIntegratorS) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_ld =
          Hummingbird_Flight_Controller_P.PIDController3_UpperIntegratorS;
      } else if (Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_ld <
                 Hummingbird_Flight_Controller_P.PIDController3_LowerIntegratorS)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_ld =
          Hummingbird_Flight_Controller_P.PIDController3_LowerIntegratorS;
      }

      // Update for DiscreteIntegrator: '<S286>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_js[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval *
        Hummingbird_Flight_Controller_B.prev_waypoint[0];

      // Update for DiscreteIntegrator: '<S234>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_o[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_b *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1;

      // Update for DiscreteIntegrator: '<S286>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_js[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval *
        Hummingbird_Flight_Controller_B.prev_waypoint[1];

      // Update for DiscreteIntegrator: '<S234>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_o[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_b *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;

      // Update for DiscreteIntegrator: '<S286>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_js[2] +=
        Hummingbird_Flight_Controller_P.Filter_gainval *
        Hummingbird_Flight_Controller_B.prev_waypoint[2];

      // Update for DiscreteIntegrator: '<S234>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_o[2] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_b *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;
      break;

     case Hummingbird_Fli_IN_FW_Stabilize:
      // Merge: '<S1>/ Merge ' incorporates:
      //   Constant: '<S7>/Constant10'
      //   SignalConversion generated from: '<S7>/dtFW'

      Hummingbird_Flight_Controller_B.dtFW =
        Hummingbird_Flight_Controller_P.Constant10_Value;

      // Gain: '<S1168>/Gain5' incorporates:
      //   Constant: '<S7>/Constant11'
      //   Merge: '<S1>/ Merge 1'
      //   SignalConversion generated from: '<S7>/dtMR'

      Hummingbird_Flight_Controller_B.dtMR =
        Hummingbird_Flight_Controller_P.Constant11_Value_b;
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_l);

      // Gain: '<S376>/Gain10' incorporates:
      //   Constant: '<S376>/Constant7'
      //   Sum: '<S376>/Sum8'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Roll) -
         Hummingbird_Flight_Controller_P.Constant7_Value_l) *
        Hummingbird_Flight_Controller_P.Gain10_Gain_e;

      // Saturate: '<S376>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_k) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_k;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_i) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_i;
      }

      // Gain: '<S367>/Gain1' incorporates:
      //   Saturate: '<S376>/Saturation'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        Hummingbird_Flight_Controller_P.Gain1_Gain_j *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;

      // Gain: '<S377>/Gain10' incorporates:
      //   Constant: '<S377>/Constant7'
      //   Sum: '<S377>/Sum8'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Pitch) -
         Hummingbird_Flight_Controller_P.Constant7_Value_m) *
        Hummingbird_Flight_Controller_P.Gain10_Gain_j;

      // Saturate: '<S377>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_n) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_n;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_l) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_l;
      }

      // Gain: '<S367>/Gain2' incorporates:
      //   Saturate: '<S377>/Saturation'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
        Hummingbird_Flight_Controller_P.Gain2_Gain_l *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;

      // Gain: '<S378>/Gain10' incorporates:
      //   Constant: '<S378>/Constant7'
      //   Sum: '<S378>/Sum8'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Yaw) -
         Hummingbird_Flight_Controller_P.Constant7_Value_ne) *
        Hummingbird_Flight_Controller_P.Gain10_Gain_m;

      // Saturate: '<S378>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_j) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_j;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_ly) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_ly;
      }

      // Gain: '<S367>/Gain3' incorporates:
      //   Saturate: '<S378>/Saturation'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 *=
        Hummingbird_Flight_Controller_P.Gain3_Gain_j;

      // Sum: '<S367>/Sum' incorporates:
      //   BusCreator generated from: '<Root>/Chart'
      //   Gain: '<S367>/Gain4'
      //   Product: '<S367>/Divide'
      //   Trigonometry: '<S367>/Trigonometric Function1'
      //   Trigonometry: '<S367>/Trigonometric Function3'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        Hummingbird_Flight_Controller_P.Gain4_Gain_n * tan
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0) * cos
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1) /
        Hummingbird_Flight_Controller_B.CastToDouble8 +
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;

      // BusAssignment: '<S372>/Bus Assignment' incorporates:
      //   Constant: '<S367>/Constant2'
      //   DataTypeConversion: '<S367>/Cast To Single7'
      //   DataTypeConversion: '<S367>/Cast To Single8'
      //   DataTypeConversion: '<S367>/Cast To Single9'
      //   MATLABSystem: '<S372>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_nb.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_l.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_nb.roll =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_nb.pitch =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_nb.yaw_rate =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_nb._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant2_Value_j[0];
      Hummingbird_Flight_Controller_B.BusAssignment_nb._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant2_Value_j[1];
      Hummingbird_Flight_Controller_B.BusAssignment_nb._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant2_Value_j[2];
      Hummingbird_Flight_Controller_B.BusAssignment_nb._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant2_Value_j[3];
      Hummingbird_Fligh_SinkBlock
        (&Hummingbird_Flight_Controller_B.BusAssignment_nb,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_l);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_p5);

      // Sum: '<S367>/Sum5' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double3'
      //   DataTypeConversion: '<S5>/Cast To Double4'
      //   DataTypeConversion: '<S5>/Cast To Double5'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //
      Hummingbird_Flight_Controller_B.prev_waypoint[0] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0;
      Hummingbird_Flight_Controller_B.prev_waypoint[1] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1;
      Hummingbird_Flight_Controller_B.prev_waypoint[2] =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 -
        Hummingbird_Flight_Controller_B.a_n;
      Hummingbird__ReadParameter1
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb);
      Hummingbird_F_ReadParameter
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb);
      Hummingbir_ReadParameter1_b
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3);
      Hummingbird_ReadParameter_b
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3);

      // Product: '<S472>/NProd Out' incorporates:
      //   Constant: '<S367>/Constant1'
      //   Constant: '<S379>/Constant'
      //   DiscreteIntegrator: '<S464>/Filter'
      //   Product: '<S462>/DProd Out'
      //   Sum: '<S464>/SumD'

      Hummingbird_Flight_Controller_B.Filter_os[0] =
        (Hummingbird_Flight_Controller_B.prev_waypoint[0] *
         Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3.ReadParameter1_o1
         - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_d[0]) *
        Hummingbird_Flight_Controller_P.Constant1_Value_c;
      Hummingbird_Flight_Controller_B.Filter_os[1] =
        (Hummingbird_Flight_Controller_B.prev_waypoint[1] *
         Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3.ReadParameter_o1
         - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_d[1]) *
        Hummingbird_Flight_Controller_P.Constant1_Value_c;
      Hummingbird_Flight_Controller_B.Filter_os[2] =
        (Hummingbird_Flight_Controller_B.prev_waypoint[2] *
         Hummingbird_Flight_Controller_P.Constant_Value_bs -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_d[2]) *
        Hummingbird_Flight_Controller_P.Constant1_Value_c;

      // Sum: '<S478>/Sum' incorporates:
      //   Constant: '<S375>/Constant'
      //   Product: '<S474>/PProd Out'

      Hummingbird_Flight_Controller_B.DProdOut_n[0] =
        Hummingbird_Flight_Controller_B.prev_waypoint[0] *
        Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb.ReadParameter1_o1
        + Hummingbird_Flight_Controller_B.Filter_os[0];
      Hummingbird_Flight_Controller_B.DProdOut_n[1] =
        Hummingbird_Flight_Controller_B.prev_waypoint[1] *
        Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb.ReadParameter_o1
        + Hummingbird_Flight_Controller_B.Filter_os[1];
      Hummingbird_Flight_Controller_B.DProdOut_n[2] =
        Hummingbird_Flight_Controller_B.prev_waypoint[2] *
        Hummingbird_Flight_Controller_P.Constant_Value_lw +
        Hummingbird_Flight_Controller_B.Filter_os[2];

      // MATLAB Function: '<S367>/MATLAB Function'
      Hummingbird__MATLABFunction
        (&Hummingbird_Flight_Controller_B.BusConversion_InsertedFor_Chart,
         &Hummingbird_Flight_Controller_B.DProdOut_n[0],
         Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1,
         Hummingbird_Flight_Controller_B.prev_waypoint,
         &Hummingbird_Flight_Controller_B.sf_MATLABFunction_b);

      // BusAssignment: '<S373>/Bus Assignment' incorporates:
      //   Constant: '<S367>/Constant3'
      //   DataTypeConversion: '<S367>/Cast To Single1'
      //   DataTypeConversion: '<S367>/Cast To Single2'
      //   DataTypeConversion: '<S367>/Cast To Single6'
      //   MATLABSystem: '<S373>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_j1.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_p5.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_j1.roll_rate =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.prev_waypoint[0]);
      Hummingbird_Flight_Controller_B.BusAssignment_j1.pitch_rate =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.prev_waypoint[1]);
      Hummingbird_Flight_Controller_B.BusAssignment_j1.yaw_rate =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.prev_waypoint[2]);
      Hummingbird_Flight_Controller_B.BusAssignment_j1._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant3_Value_c[0];
      Hummingbird_Flight_Controller_B.BusAssignment_j1._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant3_Value_c[1];
      Hummingbird_Flight_Controller_B.BusAssignment_j1._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant3_Value_c[2];
      Hummingbird_Flight_Controller_B.BusAssignment_j1._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant3_Value_c[3];
      Hummingbird_Fli_SinkBlock_h
        (&Hummingbird_Flight_Controller_B.BusAssignment_j1,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_c);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_ct);

      // Sum: '<S367>/Sum4' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double7'

      Hummingbird_Flight_Controller_B.DProdOut_n[0] =
        Hummingbird_Flight_Controller_B.prev_waypoint[0] -
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[0];
      Hummingbird_Flight_Controller_B.DProdOut_n[1] =
        Hummingbird_Flight_Controller_B.prev_waypoint[1] -
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[1];
      Hummingbird_Flight_Controller_B.DProdOut_n[2] =
        Hummingbird_Flight_Controller_B.prev_waypoint[2] -
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[2];
      Hummingbi_ReadParameter1_b3
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3a,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3a);
      Hummingbir_ReadParameter_b3
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3a,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3a);
      Hummingbird__ReadParameter2
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgae,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgae);
      Hummingbir_ReadParameter3_b
        (&Hummingbird_Flight_Controller_B.ReadParameter3_b3,
         &Hummingbird_Flight_Controlle_DW.ReadParameter3_b3);
      Hummingbir_ReadParameter2_b
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaen,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaen);
      Hummingbird__ReadParameter4
        (&Hummingbird_Flight_Controller_B.ReadParameter4_b,
         &Hummingbird_Flight_Controlle_DW.ReadParameter4_b);

      // Product: '<S420>/NProd Out' incorporates:
      //   Constant: '<S367>/Constant4'
      //   DiscreteIntegrator: '<S412>/Filter'
      //   Product: '<S410>/DProd Out'
      //   Sum: '<S412>/SumD'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
        (Hummingbird_Flight_Controller_B.DProdOut_n[0] *
         Hummingbird_Flight_Controller_B.ReadParameter3_b3.ReadParameter3_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_p[0]) *
        Hummingbird_Flight_Controller_P.Constant4_Value_p;
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (Hummingbird_Flight_Controller_B.DProdOut_n[1] *
         Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaen.ReadParameter2_o1
         - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_p[1]) *
        Hummingbird_Flight_Controller_P.Constant4_Value_p;
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        (Hummingbird_Flight_Controller_B.DProdOut_n[2] *
         Hummingbird_Flight_Controller_B.ReadParameter4_b.ReadParameter4_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_p[2]) *
        Hummingbird_Flight_Controller_P.Constant4_Value_p;

      // Sum: '<S426>/Sum' incorporates:
      //   Product: '<S422>/PProd Out'

      Hummingbird_Flight_Controller_B.prev_waypoint[0] =
        Hummingbird_Flight_Controller_B.DProdOut_n[0] *
        Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3a.ReadParameter1_o1
        + Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1;
      Hummingbird_Flight_Controller_B.prev_waypoint[1] =
        Hummingbird_Flight_Controller_B.DProdOut_n[1] *
        Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3a.ReadParameter_o1
        + Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;
      Hummingbird_Flight_Controller_B.prev_waypoint[2] =
        Hummingbird_Flight_Controller_B.DProdOut_n[2] *
        Hummingbird_Flight_Controller_B.ReadParameter2_b3rgae.ReadParameter2_o1
        + Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;

      // BusAssignment: '<S374>/Bus Assignment' incorporates:
      //   Constant: '<S367>/Constant'
      //   DataTypeConversion: '<S367>/Cast To Single3'
      //   DataTypeConversion: '<S367>/Cast To Single4'
      //   DataTypeConversion: '<S367>/Cast To Single5'
      //   MATLABSystem: '<S374>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_ia.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_ct.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_ia.roll_rate_error =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.prev_waypoint[0]);
      Hummingbird_Flight_Controller_B.BusAssignment_ia.pitch_rate_error =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.prev_waypoint[1]);
      Hummingbird_Flight_Controller_B.BusAssignment_ia.yaw_rate_error =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.prev_waypoint[2]);
      Hummingbird_Flight_Controller_B.BusAssignment_ia._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant_Value_c4[0];
      Hummingbird_Flight_Controller_B.BusAssignment_ia._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant_Value_c4[1];
      Hummingbird_Flight_Controller_B.BusAssignment_ia._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant_Value_c4[2];
      Hummingbird_Flight_Controller_B.BusAssignment_ia._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant_Value_c4[3];
      Hummingbird_Fli_SinkBlock_j
        (&Hummingbird_Flight_Controller_B.BusAssignment_ia,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_cp);

      // Sum: '<S367>/Sum3'
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        Hummingbird_Flight_Controller_B.prev_waypoint[0];
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
        Hummingbird_Flight_Controller_B.prev_waypoint[1];
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 =
        Hummingbird_Flight_Controller_B.prev_waypoint[2];
      Hummingb_ReadParameter1_b3r
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ay,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ay);
      Hummingbi_ReadParameter_b3r
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ay,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ay);
      Hummingbi_ReadParameter2_b3
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb);

      // Merge: '<S1>/ Merge 2' incorporates:
      //   BusCreator: '<S5>/Bus Creator6'
      //   Product: '<S526>/PProd Out'
      //   Sum: '<S367>/Sum3'

      Hummingbird_Flight_Controller_B.dM[0] =
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 -
         Hummingbird_Flight_Controller_B.Sum_e[0]) *
        Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ay.ReadParameter1_o1;
      Hummingbird_Flight_Controller_B.dM[1] =
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 -
         Hummingbird_Flight_Controller_B.Sum_e[1]) *
        Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ay.ReadParameter_o1;
      Hummingbird_Flight_Controller_B.dM[2] =
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 -
         Hummingbird_Flight_Controller_B.Sum_e[2]) *
        Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb.ReadParameter2_o1;

      // Update for DiscreteIntegrator: '<S464>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_d[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_n *
        Hummingbird_Flight_Controller_B.Filter_os[0];

      // Update for DiscreteIntegrator: '<S412>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_p[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_bd *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1;

      // Update for DiscreteIntegrator: '<S464>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_d[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_n *
        Hummingbird_Flight_Controller_B.Filter_os[1];

      // Update for DiscreteIntegrator: '<S412>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_p[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_bd *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;

      // Update for DiscreteIntegrator: '<S464>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_d[2] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_n *
        Hummingbird_Flight_Controller_B.Filter_os[2];

      // Update for DiscreteIntegrator: '<S412>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_p[2] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_bd *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;
      break;

     case Hummingbird_Flig_IN_MR_Attitude:
      // Merge: '<S1>/ Merge ' incorporates:
      //   Constant: '<S8>/Constant14'
      //   SignalConversion generated from: '<S8>/dtFW'

      Hummingbird_Flight_Controller_B.dtFW =
        Hummingbird_Flight_Controller_P.Constant14_Value;

      // Sum: '<S545>/Sum21' incorporates:
      //   BusCreator: '<S5>/Bus Creator4'
      //   Constant: '<S773>/Constant'
      //   Gain: '<S773>/Gain'
      //   Sum: '<S773>/Sum'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 = (
        static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Throttle)
        - Hummingbird_Flight_Controller_P.Constant_Value_ct) *
        Hummingbird_Flight_Controller_P.Gain_Gain -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2;
      Hummingb_ReadParameter_b3rg
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ayu);
      Humming_ReadParameter1_b3rg
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ayu);

      // Product: '<S586>/NProd Out' incorporates:
      //   Constant: '<S545>/Constant'
      //   DiscreteIntegrator: '<S578>/Filter'
      //   Product: '<S576>/DProd Out'
      //   Sum: '<S578>/SumD'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 *
         Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu.ReadParameter1_o1
         - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_j) *
        Hummingbird_Flight_Controller_P.Constant_Value_fn;

      // Gain: '<S1168>/Gain5' incorporates:
      //   Gain: '<S545>/Gain5'
      //   Merge: '<S1>/ Merge 1'
      //   Product: '<S588>/PProd Out'
      //   Sum: '<S592>/Sum'

      Hummingbird_Flight_Controller_B.dtMR =
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 *
         Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu.ReadParameter_o1
         + Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0) *
        -Hummingbird_Flight_Controller_P.m;
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_m);

      // Gain: '<S547>/Gain1' incorporates:
      //   Constant: '<S774>/Constant'
      //   Gain: '<S774>/Gain'
      //   Sum: '<S774>/Sum'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Roll) -
         Hummingbird_Flight_Controller_P.Constant_Value_ag) *
        Hummingbird_Flight_Controller_P.Gain_Gain_m *
        Hummingbird_Flight_Controller_P.Gain1_Gain_h;

      // Saturate: '<S547>/Saturation1'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation1_UpperSat) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation1_UpperSat;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation1_LowerSat) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation1_LowerSat;
      }

      // Gain: '<S547>/Gain2' incorporates:
      //   Constant: '<S775>/Constant'
      //   Gain: '<S775>/Gain'
      //   Sum: '<S775>/Sum'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Pitch) -
         Hummingbird_Flight_Controller_P.Constant_Value_oq) *
        Hummingbird_Flight_Controller_P.Gain_Gain_i *
        Hummingbird_Flight_Controller_P.Gain2_Gain_c;

      // Saturate: '<S547>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_l) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_l;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_f) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_f;
      }

      // Gain: '<S547>/Gain' incorporates:
      //   Constant: '<S776>/Constant'
      //   Gain: '<S776>/Gain'
      //   Sum: '<S776>/Sum'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 = (
        static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Yaw) -
        Hummingbird_Flight_Controller_P.Constant_Value_l4) *
        Hummingbird_Flight_Controller_P.Gain_Gain_o *
        Hummingbird_Flight_Controller_P.Gain_Gain_ii;

      // BusAssignment: '<S604>/Bus Assignment' incorporates:
      //   Constant: '<S546>/Constant2'
      //   DataTypeConversion: '<S546>/Cast To Single7'
      //   DataTypeConversion: '<S546>/Cast To Single8'
      //   DataTypeConversion: '<S546>/Cast To Single9'
      //   MATLABSystem: '<S604>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_d.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_m.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_d.roll =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_d.pitch =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_d.yaw_rate =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_d._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant2_Value_b[0];
      Hummingbird_Flight_Controller_B.BusAssignment_d._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant2_Value_b[1];
      Hummingbird_Flight_Controller_B.BusAssignment_d._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant2_Value_b[2];
      Hummingbird_Flight_Controller_B.BusAssignment_d._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant2_Value_b[3];
      Hummingbird_Fligh_SinkBlock
        (&Hummingbird_Flight_Controller_B.BusAssignment_d,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_lp);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_ef);

      // Sum: '<S546>/Sum5' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double4'
      //   DataTypeConversion: '<S5>/Cast To Double5'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //
      Hummingbird_Flight_Controller_B.prev_waypoint[0] =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0;
      Hummingbird_Flight_Controller_B.prev_waypoint[1] =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1;
      Hummin_ReadParameter1_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu5,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ayu5);
      Humming_ReadParameter_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu5,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ayu5);
      Hummingb_ReadParameter2_b3r
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3);
      Hummi_ReadParameter1_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu5d,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ayu5d);
      Hummin_ReadParameter_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu5d,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ayu5d);
      Humming_ReadParameter2_b3rg
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3a,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3a);

      // Product: '<S700>/NProd Out' incorporates:
      //   Constant: '<S546>/Constant1'
      //   DiscreteIntegrator: '<S692>/Filter'
      //   Product: '<S690>/DProd Out'
      //   Sum: '<S692>/SumD'

      Hummingbird_Flight_Controller_B.Filter_os[0] =
        (Hummingbird_Flight_Controller_B.prev_waypoint[0] *
         Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu5d.ReadParameter1_o1
         - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_bl[0]) *
        Hummingbird_Flight_Controller_P.Constant1_Value_d;
      Hummingbird_Flight_Controller_B.Filter_os[1] =
        (Hummingbird_Flight_Controller_B.prev_waypoint[1] *
         Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu5d.ReadParameter_o1
         - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_bl[1]) *
        Hummingbird_Flight_Controller_P.Constant1_Value_d;

      // Sum: '<S706>/Sum' incorporates:
      //   Product: '<S702>/PProd Out'

      Hummingbird_Flight_Controller_B.DProdOut_n[0] =
        Hummingbird_Flight_Controller_B.prev_waypoint[0] *
        Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu5.ReadParameter1_o1
        + Hummingbird_Flight_Controller_B.Filter_os[0];
      Hummingbird_Flight_Controller_B.DProdOut_n[1] =
        Hummingbird_Flight_Controller_B.prev_waypoint[1] *
        Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu5.ReadParameter_o1
        + Hummingbird_Flight_Controller_B.Filter_os[1];

      // BusAssignment: '<S605>/Bus Assignment' incorporates:
      //   Constant: '<S546>/Constant3'
      //   DataTypeConversion: '<S546>/Cast To Single1'
      //   DataTypeConversion: '<S546>/Cast To Single2'
      //   DataTypeConversion: '<S546>/Cast To Single6'
      //   MATLABSystem: '<S605>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_kl.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_ef.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_kl.roll_rate =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[0]);
      Hummingbird_Flight_Controller_B.BusAssignment_kl.pitch_rate =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[1]);
      Hummingbird_Flight_Controller_B.BusAssignment_kl.yaw_rate = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_kl._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant3_Value_i[0];
      Hummingbird_Flight_Controller_B.BusAssignment_kl._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant3_Value_i[1];
      Hummingbird_Flight_Controller_B.BusAssignment_kl._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant3_Value_i[2];
      Hummingbird_Flight_Controller_B.BusAssignment_kl._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant3_Value_i[3];
      Hummingbird_Fli_SinkBlock_h
        (&Hummingbird_Flight_Controller_B.BusAssignment_kl,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_d);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_cf);

      // Sum: '<S546>/Sum4' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double7'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        Hummingbird_Flight_Controller_B.DProdOut_n[0];
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        Hummingbird_Flight_Controller_B.DProdOut_n[1];
      Hummingbird_Flight_Controller_B.DProdOut_n[0] =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 -
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[0];
      Hummingbird_Flight_Controller_B.DProdOut_n[1] =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 -
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[1];
      Hummingbird_Flight_Controller_B.DProdOut_n[2] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[2];

      // BusAssignment: '<S606>/Bus Assignment' incorporates:
      //   Constant: '<S546>/Constant'
      //   DataTypeConversion: '<S546>/Cast To Single3'
      //   DataTypeConversion: '<S546>/Cast To Single4'
      //   DataTypeConversion: '<S546>/Cast To Single5'
      //   MATLABSystem: '<S606>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_ox.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_cf.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_ox.roll_rate_error =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[0]);
      Hummingbird_Flight_Controller_B.BusAssignment_ox.pitch_rate_error =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[1]);
      Hummingbird_Flight_Controller_B.BusAssignment_ox.yaw_rate_error =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[2]);
      Hummingbird_Flight_Controller_B.BusAssignment_ox._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant_Value_pq[0];
      Hummingbird_Flight_Controller_B.BusAssignment_ox._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant_Value_pq[1];
      Hummingbird_Flight_Controller_B.BusAssignment_ox._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant_Value_pq[2];
      Hummingbird_Flight_Controller_B.BusAssignment_ox._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant_Value_pq[3];
      Hummingbird_Fli_SinkBlock_j
        (&Hummingbird_Flight_Controller_B.BusAssignment_ox,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_a);
      Humm_ReadParameter1_b3rgaen
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu5da,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ayu5da);
      Hummi_ReadParameter_b3rgaen
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu5da,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ayu5da);
      Hummin_ReadParameter2_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ay,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ay);
      Hum_ReadParameter1_b3rgaenb
        (&Hummingbird_Flight_Controller_B.ReadParameter1_j,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_j);
      Humm_ReadParameter_b3rgaenb
        (&Hummingbird_Flight_Controller_B.ReadParameter_j,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_j);
      Hummi_ReadParameter2_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ayu);

      // Merge: '<S1>/ Merge 2' incorporates:
      //   BusCreator: '<S5>/Bus Creator6'
      //   Product: '<S650>/PProd Out'
      //   Product: '<S754>/PProd Out'
      //   Sum: '<S546>/Sum3'

      Hummingbird_Flight_Controller_B.dM[0] =
        (Hummingbird_Flight_Controller_B.DProdOut_n[0] *
         Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaenb3ayu5da.ReadParameter1_o1
         - Hummingbird_Flight_Controller_B.Sum_e[0]) *
        Hummingbird_Flight_Controller_B.ReadParameter1_j.ReadParameter1_o1;
      Hummingbird_Flight_Controller_B.dM[1] =
        (Hummingbird_Flight_Controller_B.DProdOut_n[1] *
         Hummingbird_Flight_Controller_B.ReadParameter_b3rgaenb3ayu5da.ReadParameter_o1
         - Hummingbird_Flight_Controller_B.Sum_e[1]) *
        Hummingbird_Flight_Controller_B.ReadParameter_j.ReadParameter_o1;
      Hummingbird_Flight_Controller_B.dM[2] =
        (Hummingbird_Flight_Controller_B.DProdOut_n[2] *
         Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ay.ReadParameter2_o1
         - Hummingbird_Flight_Controller_B.Sum_e[2]) *
        Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu.ReadParameter2_o1;

      // Update for DiscreteIntegrator: '<S578>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_j +=
        Hummingbird_Flight_Controller_P.Filter_gainval_d *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;

      // Update for DiscreteIntegrator: '<S692>/Filter' incorporates:
      //   Constant: '<S546>/Constant1'
      //   DataTypeConversion: '<S5>/Cast To Double3'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //   Product: '<S690>/DProd Out'
      //   Product: '<S700>/NProd Out'
      //   Sum: '<S546>/Sum5'
      //   Sum: '<S692>/SumD'
      //
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_bl[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_p *
        Hummingbird_Flight_Controller_B.Filter_os[0];
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_bl[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_p *
        Hummingbird_Flight_Controller_B.Filter_os[1];
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_bl[2] +=
        ((Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
          Hummingbird_Flight_Controller_B.a_n) *
         Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3a.ReadParameter2_o1
         - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_bl[2]) *
        Hummingbird_Flight_Controller_P.Constant1_Value_d *
        Hummingbird_Flight_Controller_P.Filter_gainval_p;
      break;

     case Hummingbird_Flight_Co_IN_MR_Nav:
      // Merge: '<S1>/ Merge ' incorporates:
      //   Constant: '<S9>/Constant10'
      //   SignalConversion generated from: '<S9>/dtFW'

      Hummingbird_Flight_Controller_B.dtFW =
        Hummingbird_Flight_Controller_P.Constant10_Value_b;

      // MATLAB Function: '<S780>/MATLAB Function2'
      if (rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lat)
          || rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lon))
      {
        Hummingbird_Flight_Controller_B.prev_lat[0] =
          Hummingbird_Flight_Controlle_DW.mission_start[0];
        Hummingbird_Flight_Controller_B.prev_lat[1] =
          Hummingbird_Flight_Controlle_DW.mission_start[1];
        Hummingbird_Flight_Controller_B.prev_lat[2] =
          Hummingbird_Flight_Controlle_DW.mission_start[2];
      } else {
        Hummingbird_Flight_Controller_B.prev_lat[0] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lat;
        Hummingbird_Flight_Controller_B.prev_lat[1] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lon;
        Hummingbird_Flight_Controller_B.prev_lat[2] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.altitude;
      }

      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[0] =
        Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lat;
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[1] =
        Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lon;
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[2] =
        Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.altitude;
      Hummingbird_Flight_Cont_lla2ned(Hummingbird_Flight_Controller_B.prev_lat,
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c,
        Hummingbird_Flight_Controller_B.current_lat);
      if (rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lat))
      {
        Hummingbird_Flight_Controller_B.DProdOut_n[0] = 0.0;
        Hummingbird_Flight_Controller_B.DProdOut_n[1] = 0.0;
        Hummingbird_Flight_Controller_B.DProdOut_n[2] = 0.0;
      } else if (rtIsNaN
                 (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lon))
      {
        Hummingbird_Flight_Controller_B.DProdOut_n[0] = 0.0;
        Hummingbird_Flight_Controller_B.DProdOut_n[1] = 0.0;
        Hummingbird_Flight_Controller_B.DProdOut_n[2] = 0.0;
      } else {
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[0] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lat;
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[1] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lon;
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[2] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.altitude;
        Hummingbird_Flight_Controller_B.prev_lat[0] =
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lat;
        Hummingbird_Flight_Controller_B.prev_lat[1] =
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lon;
        Hummingbird_Flight_Controller_B.prev_lat[2] =
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.altitude;
        Hummingbird_Flight_Cont_lla2ned
          (Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c,
           Hummingbird_Flight_Controller_B.prev_lat,
           Hummingbird_Flight_Controller_B.dv);
        Hummingbird_Flight_Controller_B.DProdOut_n[0] = 3.28084 *
          Hummingbird_Flight_Controller_B.dv[0] +
          Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.X;
        Hummingbird_Flight_Controller_B.DProdOut_n[1] = 3.28084 *
          Hummingbird_Flight_Controller_B.dv[1] +
          Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.Y;
        Hummingbird_Flight_Controller_B.DProdOut_n[2] = 3.28084 *
          Hummingbird_Flight_Controller_B.dv[2] +
          Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.Z;
      }

      // Sum: '<S777>/Sum20' incorporates:
      //   BusCreator: '<S5>/Bus Creator9'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        Hummingbird_Flight_Controller_B.DProdOut_n[2] -
        Hummingbird_Flight_Controller_B.CastToDouble25_f;

      // Gain: '<S872>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S864>/Filter'
      //   Gain: '<S862>/Derivative Gain'
      //   Sum: '<S864>/SumD'

      Hummingbird_Flight_Controller_B.Esp_dot =
        (Hummingbird_Flight_Controller_P.PIDController5_D *
         Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_fu) *
        Hummingbird_Flight_Controller_P.PIDController5_N;

      // Sum: '<S878>/Sum' incorporates:
      //   DiscreteIntegrator: '<S869>/Integrator'
      //   Gain: '<S874>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (Hummingbird_Flight_Controller_P.PIDController5_P *
         Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_n) +
        Hummingbird_Flight_Controller_B.Esp_dot;

      // Saturate: '<S876>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.PIDController5_UpperSaturationL) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.PIDController5_UpperSaturationL;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.PIDController5_LowerSaturationL)
      {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.PIDController5_LowerSaturationL;
      }

      // Sum: '<S777>/Sum21' incorporates:
      //   BusCreator: '<S5>/Bus Creator4'
      //   Saturate: '<S876>/Saturation'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2;

      // Gain: '<S820>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S812>/Filter'
      //   Gain: '<S810>/Derivative Gain'
      //   Sum: '<S812>/SumD'

      Hummingbird_Flight_Controller_B.V =
        (Hummingbird_Flight_Controller_P.PIDController3_D *
         Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_l) *
        Hummingbird_Flight_Controller_P.PIDController3_N;

      // Gain: '<S1168>/Gain5' incorporates:
      //   DiscreteIntegrator: '<S817>/Integrator'
      //   Gain: '<S777>/Gain5'
      //   Gain: '<S822>/Proportional Gain'
      //   Merge: '<S1>/ Merge 1'
      //   Sum: '<S826>/Sum'

      Hummingbird_Flight_Controller_B.dtMR =
        ((Hummingbird_Flight_Controller_P.PIDController3_P *
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 +
          Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_j) +
         Hummingbird_Flight_Controller_B.V) * -Hummingbird_Flight_Controller_P.m;

      // Gain: '<S814>/Integral Gain'
      Hummingbird_Flight_Controller_B.IntegralGain_k =
        Hummingbird_Flight_Controller_P.PIDController3_I *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;

      // Gain: '<S866>/Integral Gain'
      Hummingbird_Flight_Controller_B.CastToDouble25_f =
        Hummingbird_Flight_Controller_P.PIDController5_I *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1;

      // MATLAB Function: '<S9>/MATLAB Function2' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double3'
      //   MATLAB Function: '<S780>/MATLAB Function2'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //
      Hummingbird_MATLABFunction2(static_cast<real_T>
        (Hummingbird_Flight_Controller_B.a_n), Hummingbird_Fligh_rt_atan2d_snf
        (Hummingbird_Flight_Controller_B.DProdOut_n[1] - (3.28084 *
        Hummingbird_Flight_Controller_B.current_lat[1] +
        Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.Y),
         Hummingbird_Flight_Controller_B.DProdOut_n[0] - (3.28084 *
        Hummingbird_Flight_Controller_B.current_lat[0] +
        Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.X)),
        &Hummingbird_Flight_Controller_B.course);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_pb);

      // Sum: '<S780>/Sum14' incorporates:
      //   BusCreator: '<S5>/Bus Creator9'

      Hummingbird_Flight_Controller_B.Filter_os[0] =
        Hummingbird_Flight_Controller_B.DProdOut_n[0] -
        Hummingbird_Flight_Controller_B.In1_a.lat;
      Hummingbird_Flight_Controller_B.Filter_os[1] =
        Hummingbird_Flight_Controller_B.DProdOut_n[1] -
        Hummingbird_Flight_Controller_B.In1_a.lon;
      Hummingbird_Flight_Controller_B.Filter_os[2] =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1;

      // Gain: '<S1101>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1093>/Filter'
      //   Gain: '<S1091>/Derivative Gain'
      //   Sum: '<S1093>/SumD'

      Hummingbird_Flight_Controller_B.scale =
        (Hummingbird_Flight_Controller_P.PIDController8_D[0] *
         Hummingbird_Flight_Controller_B.Filter_os[0] -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_b[0]) *
        Hummingbird_Flight_Controller_P.PIDController8_N;
      Hummingbird_Flight_Controller_B.DProdOut_n[0] =
        Hummingbird_Flight_Controller_B.scale;

      // Sum: '<S1107>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1098>/Integrator'
      //   Gain: '<S1091>/Derivative Gain'
      //   Gain: '<S1103>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        (Hummingbird_Flight_Controller_P.PIDController8_P[0] *
         Hummingbird_Flight_Controller_B.Filter_os[0] +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[0]) +
        Hummingbird_Flight_Controller_B.scale;

      // Gain: '<S1101>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1093>/Filter'
      //   Gain: '<S1091>/Derivative Gain'
      //   Sum: '<S1093>/SumD'

      Hummingbird_Flight_Controller_B.scale =
        (Hummingbird_Flight_Controller_P.PIDController8_D[1] *
         Hummingbird_Flight_Controller_B.Filter_os[1] -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_b[1]) *
        Hummingbird_Flight_Controller_P.PIDController8_N;
      Hummingbird_Flight_Controller_B.DProdOut_n[1] =
        Hummingbird_Flight_Controller_B.scale;

      // Sum: '<S1107>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1098>/Integrator'
      //   Gain: '<S1091>/Derivative Gain'
      //   Gain: '<S1103>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
        (Hummingbird_Flight_Controller_P.PIDController8_P[1] *
         Hummingbird_Flight_Controller_B.Filter_os[1] +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[1]) +
        Hummingbird_Flight_Controller_B.scale;

      // Gain: '<S1101>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1093>/Filter'
      //   Gain: '<S1091>/Derivative Gain'
      //   Sum: '<S1093>/SumD'
      //   Sum: '<S780>/Sum14'

      Hummingbird_Flight_Controller_B.scale =
        (Hummingbird_Flight_Controller_P.PIDController8_D[2] *
         Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_b[2]) *
        Hummingbird_Flight_Controller_P.PIDController8_N;

      // Sum: '<S1107>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1098>/Integrator'
      //   Gain: '<S1103>/Proportional Gain'
      //   Sum: '<S780>/Sum14'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        (Hummingbird_Flight_Controller_P.PIDController8_P[2] *
         Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[2]) +
        Hummingbird_Flight_Controller_B.scale;

      // MATLAB Function: '<S780>/MATLAB Function'
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_p[0] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_p[1] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1;
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        Hummingbird_Flight_Contr_norm_j
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_p);
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 > 30.0) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 /
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 * 30.0;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 /
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 * 30.0;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 /
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 * 30.0;
      }

      // Sum: '<S780>/Sum1' incorporates:
      //   BusCreator: '<S5>/Bus Creator4'

      Hummingbird_Flight_Controller_B.prev_waypoint[0] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;
      Hummingbird_Flight_Controller_B.prev_waypoint[1] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      Hummingbird_Flight_Controller_B.prev_waypoint[2] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2;

      // Gain: '<S1153>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1145>/Filter'
      //   Gain: '<S1143>/Derivative Gain'
      //   Sum: '<S1145>/SumD'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 =
        (Hummingbird_Flight_Controller_P.PIDController9_D[0] *
         Hummingbird_Flight_Controller_B.prev_waypoint[0] -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_e[0]) *
        Hummingbird_Flight_Controller_P.PIDController9_N;
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;

      // Sum: '<S1159>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1150>/Integrator'
      //   Gain: '<S1143>/Derivative Gain'
      //   Gain: '<S1155>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (Hummingbird_Flight_Controller_P.PIDController9_P[0] *
         Hummingbird_Flight_Controller_B.prev_waypoint[0] +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[0]) +
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;

      // Saturate: '<S1157>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturationL) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturationL;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerSaturationL)
      {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.PIDController9_LowerSaturationL;
      }

      // Gain: '<S1153>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1145>/Filter'
      //   Gain: '<S1143>/Derivative Gain'
      //   Sum: '<S1145>/SumD'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 =
        (Hummingbird_Flight_Controller_P.PIDController9_D[1] *
         Hummingbird_Flight_Controller_B.prev_waypoint[1] -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_e[1]) *
        Hummingbird_Flight_Controller_P.PIDController9_N;
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;

      // Sum: '<S1159>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1150>/Integrator'
      //   Gain: '<S1143>/Derivative Gain'
      //   Gain: '<S1155>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        (Hummingbird_Flight_Controller_P.PIDController9_P[1] *
         Hummingbird_Flight_Controller_B.prev_waypoint[1] +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[1]) +
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;

      // Saturate: '<S1157>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturationL) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturationL;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerSaturationL)
      {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_P.PIDController9_LowerSaturationL;
      }

      // Gain: '<S1153>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1145>/Filter'
      //   Gain: '<S1143>/Derivative Gain'
      //   Sum: '<S1145>/SumD'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 =
        (Hummingbird_Flight_Controller_P.PIDController9_D[2] *
         Hummingbird_Flight_Controller_B.prev_waypoint[2] -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_e[2]) *
        Hummingbird_Flight_Controller_P.PIDController9_N;

      // Sum: '<S1159>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1150>/Integrator'
      //   Gain: '<S1143>/Derivative Gain'
      //   Gain: '<S1155>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
        (Hummingbird_Flight_Controller_P.PIDController9_P[2] *
         Hummingbird_Flight_Controller_B.prev_waypoint[2] +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[2]) +
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;

      // Saturate: '<S1157>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturationL) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturationL;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerSaturationL)
      {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
          Hummingbird_Flight_Controller_P.PIDController9_LowerSaturationL;
      }

      // MATLAB Function: '<S780>/MATLAB Function1' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double3'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 = cos
        (static_cast<real_T>(Hummingbird_Flight_Controller_B.a_n));
      Hummingbird_Flight_Controller_B.t = sin(static_cast<real_T>
        (Hummingbird_Flight_Controller_B.a_n));
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 = asin
        ((-Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 *
          Hummingbird_Flight_Controller_B.t +
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 *
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1) / sqrt
         ((Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 *
           Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 +
           Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 *
           Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1) +
          (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 - 32.174) *
          (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 - 32.174)));

      // Saturate: '<S780>/Saturation1'
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 >
          Hummingbird_Flight_Controller_P.Saturation1_UpperSat_i) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_P.Saturation1_UpperSat_i;
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 <
                 Hummingbird_Flight_Controller_P.Saturation1_LowerSat_l) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_P.Saturation1_LowerSat_l;
      }

      // MATLAB Function: '<S780>/MATLAB Function1'
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 = atan
        ((-Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 *
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 -
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 *
          Hummingbird_Flight_Controller_B.t) / fabs
         (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 - 32.174));

      // Saturate: '<S780>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_p) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_p;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_l5) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_l5;
      }

      // BusAssignment: '<S890>/Bus Assignment' incorporates:
      //   Constant: '<S779>/Constant5'
      //   DataTypeConversion: '<S779>/Cast To Single16'
      //   DataTypeConversion: '<S779>/Cast To Single17'
      //   DataTypeConversion: '<S779>/Cast To Single18'
      //   MATLABSystem: '<S890>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_ov.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_pb.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_ov.roll =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment_ov.pitch = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_ov.yaw_rate = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.course);
      Hummingbird_Flight_Controller_B.BusAssignment_ov._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant5_Value_d[0];
      Hummingbird_Flight_Controller_B.BusAssignment_ov._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant5_Value_d[1];
      Hummingbird_Flight_Controller_B.BusAssignment_ov._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant5_Value_d[2];
      Hummingbird_Flight_Controller_B.BusAssignment_ov._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant5_Value_d[3];
      Hummingbird_Fligh_SinkBlock
        (&Hummingbird_Flight_Controller_B.BusAssignment_ov,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_ir);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_a);

      // Sum: '<S779>/Sum6' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double3'
      //   DataTypeConversion: '<S5>/Cast To Double4'
      //   DataTypeConversion: '<S5>/Cast To Double5'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0;
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1;
      Hummingbird_Flight_Controller_B.course -=
        Hummingbird_Flight_Controller_B.a_n;
      Hummin_ReadParameter1_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter1_o,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_o);
      Humming_ReadParameter_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter_o,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_o);
      Hummingb_ReadParameter2_b3r
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu5,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ayu5);
      Hummi_ReadParameter1_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter1_l,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_l);
      Hummin_ReadParameter_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter_l,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_l);
      Humming_ReadParameter2_b3rg
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu5d,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ayu5d);

      // Product: '<S1038>/NProd Out' incorporates:
      //   Constant: '<S779>/Constant4'
      //   DiscreteIntegrator: '<S1030>/Filter'
      //   Product: '<S1028>/DProd Out'
      //   Sum: '<S1030>/SumD'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 *
         Hummingbird_Flight_Controller_B.ReadParameter1_l.ReadParameter1_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_k[0]) *
        Hummingbird_Flight_Controller_P.Constant4_Value_e;
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 *
         Hummingbird_Flight_Controller_B.ReadParameter_l.ReadParameter_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_k[1]) *
        Hummingbird_Flight_Controller_P.Constant4_Value_e;
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
        (Hummingbird_Flight_Controller_B.course *
         Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu5d.ReadParameter2_o1
         - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_k[2]) *
        Hummingbird_Flight_Controller_P.Constant4_Value_e;

      // Sum: '<S1044>/Sum' incorporates:
      //   Product: '<S1040>/PProd Out'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 *
        Hummingbird_Flight_Controller_B.ReadParameter1_o.ReadParameter1_o1 +
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 *
        Hummingbird_Flight_Controller_B.ReadParameter_o.ReadParameter_o1 +
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1;
      Hummingbird_Flight_Controller_B.course =
        Hummingbird_Flight_Controller_B.course *
        Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu5.ReadParameter2_o1
        + Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2;

      // BusAssignment: '<S891>/Bus Assignment' incorporates:
      //   Constant: '<S779>/Constant6'
      //   DataTypeConversion: '<S779>/Cast To Single10'
      //   DataTypeConversion: '<S779>/Cast To Single11'
      //   DataTypeConversion: '<S779>/Cast To Single15'
      //   MATLABSystem: '<S891>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_mv.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_a.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_mv.roll_rate = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_mv.pitch_rate = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment_mv.yaw_rate =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.course);
      Hummingbird_Flight_Controller_B.BusAssignment_mv._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant6_Value[0];
      Hummingbird_Flight_Controller_B.BusAssignment_mv._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant6_Value[1];
      Hummingbird_Flight_Controller_B.BusAssignment_mv._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant6_Value[2];
      Hummingbird_Flight_Controller_B.BusAssignment_mv._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant6_Value[3];
      Hummingbird_Fli_SinkBlock_h
        (&Hummingbird_Flight_Controller_B.BusAssignment_mv,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_fv);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_ac);

      // Sum: '<S779>/Sum2' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double7'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 -=
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[0];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 -=
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[1];
      Hummingbird_Flight_Controller_B.course -=
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[2];

      // BusAssignment: '<S892>/Bus Assignment' incorporates:
      //   Constant: '<S779>/Constant1'
      //   DataTypeConversion: '<S779>/Cast To Single12'
      //   DataTypeConversion: '<S779>/Cast To Single13'
      //   DataTypeConversion: '<S779>/Cast To Single14'
      //   MATLABSystem: '<S892>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_f.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_ac.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_f.roll_rate_error =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_f.pitch_rate_error =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment_f.yaw_rate_error =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.course);
      Hummingbird_Flight_Controller_B.BusAssignment_f._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant1_Value_f[0];
      Hummingbird_Flight_Controller_B.BusAssignment_f._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant1_Value_f[1];
      Hummingbird_Flight_Controller_B.BusAssignment_f._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant1_Value_f[2];
      Hummingbird_Flight_Controller_B.BusAssignment_f._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant1_Value_f[3];
      Hummingbird_Fli_SinkBlock_j
        (&Hummingbird_Flight_Controller_B.BusAssignment_f,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_fw);
      Humm_ReadParameter1_b3rgaen
        (&Hummingbird_Flight_Controller_B.ReadParameter1_px,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_px);
      Hummi_ReadParameter_b3rgaen
        (&Hummingbird_Flight_Controller_B.ReadParameter_px,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_px);
      Hummin_ReadParameter2_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu5da,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ayu5da);
      Hum_ReadParameter1_b3rgaenb
        (&Hummingbird_Flight_Controller_B.ReadParameter1_i,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_i);
      Humm_ReadParameter_b3rgaenb
        (&Hummingbird_Flight_Controller_B.ReadParameter_i,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_i);
      Hummi_ReadParameter2_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter2_j,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_j);

      // Merge: '<S1>/ Merge 2' incorporates:
      //   BusCreator: '<S5>/Bus Creator6'
      //   Product: '<S936>/PProd Out'
      //   Product: '<S988>/PProd Out'
      //   Sum: '<S779>/Sum1'

      Hummingbird_Flight_Controller_B.dM[0] =
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 *
         Hummingbird_Flight_Controller_B.ReadParameter1_px.ReadParameter1_o1 -
         Hummingbird_Flight_Controller_B.Sum_e[0]) *
        Hummingbird_Flight_Controller_B.ReadParameter1_i.ReadParameter1_o1;
      Hummingbird_Flight_Controller_B.dM[1] =
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 *
         Hummingbird_Flight_Controller_B.ReadParameter_px.ReadParameter_o1 -
         Hummingbird_Flight_Controller_B.Sum_e[1]) *
        Hummingbird_Flight_Controller_B.ReadParameter_i.ReadParameter_o1;
      Hummingbird_Flight_Controller_B.dM[2] =
        (Hummingbird_Flight_Controller_B.course *
         Hummingbird_Flight_Controller_B.ReadParameter2_b3rgaenb3ayu5da.ReadParameter2_o1
         - Hummingbird_Flight_Controller_B.Sum_e[2]) *
        Hummingbird_Flight_Controller_B.ReadParameter2_j.ReadParameter2_o1;

      // Update for DiscreteIntegrator: '<S869>/Integrator'
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_n +=
        Hummingbird_Flight_Controller_P.Integrator_gainval_n *
        Hummingbird_Flight_Controller_B.CastToDouble25_f;

      // Update for DiscreteIntegrator: '<S864>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_fu +=
        Hummingbird_Flight_Controller_P.Filter_gainval_k *
        Hummingbird_Flight_Controller_B.Esp_dot;

      // Update for DiscreteIntegrator: '<S817>/Integrator'
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_j +=
        Hummingbird_Flight_Controller_P.Integrator_gainval_m *
        Hummingbird_Flight_Controller_B.IntegralGain_k;

      // Update for DiscreteIntegrator: '<S812>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_l +=
        Hummingbird_Flight_Controller_P.Filter_gainval_i *
        Hummingbird_Flight_Controller_B.V;

      // Update for DiscreteIntegrator: '<S1098>/Integrator' incorporates:
      //   Gain: '<S1095>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_P.PIDController8_I *
        Hummingbird_Flight_Controller_B.Filter_os[0] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_b +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[0];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[0] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController8_UpperIntegratorS) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[0] =
          Hummingbird_Flight_Controller_P.PIDController8_UpperIntegratorS;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController8_LowerIntegratorS)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[0] =
          Hummingbird_Flight_Controller_P.PIDController8_LowerIntegratorS;
      }

      // Update for DiscreteIntegrator: '<S1093>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_b[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_e *
        Hummingbird_Flight_Controller_B.DProdOut_n[0];

      // Update for DiscreteIntegrator: '<S1150>/Integrator' incorporates:
      //   Gain: '<S1147>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_P.PIDController9_I[0] *
        Hummingbird_Flight_Controller_B.prev_waypoint[0] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_m2 +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[0];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[0] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegratorS) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[0] =
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegratorS;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerIntegratorS)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[0] =
          Hummingbird_Flight_Controller_P.PIDController9_LowerIntegratorS;
      }

      // Update for DiscreteIntegrator: '<S1145>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_e[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_l *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;

      // Update for DiscreteIntegrator: '<S1030>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_k[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_io *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;

      // Update for DiscreteIntegrator: '<S1098>/Integrator' incorporates:
      //   Gain: '<S1095>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_P.PIDController8_I *
        Hummingbird_Flight_Controller_B.Filter_os[1] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_b +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[1];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[1] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController8_UpperIntegratorS) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[1] =
          Hummingbird_Flight_Controller_P.PIDController8_UpperIntegratorS;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController8_LowerIntegratorS)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[1] =
          Hummingbird_Flight_Controller_P.PIDController8_LowerIntegratorS;
      }

      // Update for DiscreteIntegrator: '<S1093>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_b[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_e *
        Hummingbird_Flight_Controller_B.DProdOut_n[1];

      // Update for DiscreteIntegrator: '<S1150>/Integrator' incorporates:
      //   Gain: '<S1147>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_P.PIDController9_I[1] *
        Hummingbird_Flight_Controller_B.prev_waypoint[1] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_m2 +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[1];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[1] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegratorS) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[1] =
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegratorS;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerIntegratorS)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[1] =
          Hummingbird_Flight_Controller_P.PIDController9_LowerIntegratorS;
      }

      // Update for DiscreteIntegrator: '<S1145>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_e[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_l *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1;

      // Update for DiscreteIntegrator: '<S1030>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_k[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_io *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1;

      // Update for DiscreteIntegrator: '<S1098>/Integrator' incorporates:
      //   Gain: '<S1095>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_P.PIDController8_I *
        Hummingbird_Flight_Controller_B.Filter_os[2] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_b +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[2];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[2] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController8_UpperIntegratorS) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[2] =
          Hummingbird_Flight_Controller_P.PIDController8_UpperIntegratorS;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController8_LowerIntegratorS)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[2] =
          Hummingbird_Flight_Controller_P.PIDController8_LowerIntegratorS;
      }

      // Update for DiscreteIntegrator: '<S1093>/Filter' incorporates:
      //   Gain: '<S1101>/Filter Coefficient'

      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_b[2] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_e *
        Hummingbird_Flight_Controller_B.scale;

      // Update for DiscreteIntegrator: '<S1150>/Integrator' incorporates:
      //   Gain: '<S1147>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_P.PIDController9_I[2] *
        Hummingbird_Flight_Controller_B.prev_waypoint[2] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_m2 +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[2];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[2] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegratorS) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[2] =
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegratorS;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerIntegratorS)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[2] =
          Hummingbird_Flight_Controller_P.PIDController9_LowerIntegratorS;
      }

      // Update for DiscreteIntegrator: '<S1145>/Filter' incorporates:
      //   Gain: '<S1153>/Filter Coefficient'

      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_e[2] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_l *
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;

      // Update for DiscreteIntegrator: '<S1030>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_k[2] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_io *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2;
      break;

     case Hummingbird_Flight_C_IN_MR_Vel1:
      // Merge: '<S1>/ Merge ' incorporates:
      //   Constant: '<S10>/Constant14'
      //   SignalConversion generated from: '<S10>/dtFW'

      Hummingbird_Flight_Controller_B.dtFW =
        Hummingbird_Flight_Controller_P.Constant14_Value_p;
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_d);

      // Sum: '<S1168>/Sum21' incorporates:
      //   BusCreator: '<S5>/Bus Creator4'
      //   Constant: '<S1402>/Constant'
      //   Gain: '<S1402>/Gain'
      //   Sum: '<S1402>/Sum'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
        (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Throttle)
         - Hummingbird_Flight_Controller_P.Constant_Value_f5) *
        Hummingbird_Flight_Controller_P.Gain_Gain_n -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2;
      Hummingb_ReadParameter_b3rg
        (&Hummingbird_Flight_Controller_B.ReadParameter_ld,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_ld);
      Humming_ReadParameter1_b3rg
        (&Hummingbird_Flight_Controller_B.ReadParameter1_ld,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_ld);

      // Product: '<S1211>/NProd Out' incorporates:
      //   Constant: '<S1168>/Constant'
      //   DiscreteIntegrator: '<S1203>/Filter'
      //   Product: '<S1201>/DProd Out'
      //   Sum: '<S1203>/SumD'

      Hummingbird_Flight_Controller_B.V =
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 *
         Hummingbird_Flight_Controller_B.ReadParameter1_ld.ReadParameter1_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_f) *
        Hummingbird_Flight_Controller_P.Constant_Value_p5;

      // Gain: '<S1168>/Gain5' incorporates:
      //   Product: '<S1213>/PProd Out'
      //   Sum: '<S1217>/Sum'

      Hummingbird_Flight_Controller_B.dtMR =
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 *
         Hummingbird_Flight_Controller_B.ReadParameter_ld.ReadParameter_o1 +
         Hummingbird_Flight_Controller_B.V) * -Hummingbird_Flight_Controller_P.m;

      // BusAssignment: '<S1171>/Bus Assignment' incorporates:
      //   Constant: '<S10>/Constant'
      //   Constant: '<S10>/Constant2'
      //   Constant: '<S10>/Constant7'
      //   Constant: '<S10>/Constant9'
      //   DataTypeConversion: '<S10>/Cast To Single'
      //   MATLABSystem: '<S1171>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_n.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_d.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_n.x =
        Hummingbird_Flight_Controller_P.Constant_Value_jh;
      Hummingbird_Flight_Controller_B.BusAssignment_n.y =
        Hummingbird_Flight_Controller_P.Constant2_Value_p;
      Hummingbird_Flight_Controller_B.BusAssignment_n.z = static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.dtMR);
      for (Hummingbird_Flight_Controller_B.i = 0;
           Hummingbird_Flight_Controller_B.i < 10;
           Hummingbird_Flight_Controller_B.i++) {
        Hummingbird_Flight_Controller_B.BusAssignment_n.name[Hummingbird_Flight_Controller_B.i]
          =
          Hummingbird_Flight_Controller_P.Constant7_Value_g[Hummingbird_Flight_Controller_B.i];
      }

      Hummingbird_Flight_Controller_B.BusAssignment_n._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant9_Value_c[0];
      Hummingbird_Flight_Controller_B.BusAssignment_n._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant9_Value_c[1];

      // MATLABSystem: '<S1399>/SinkBlock' incorporates:
      //   BusAssignment: '<S1171>/Bus Assignment'

      uORB_write_step(Hummingbird_Flight_Controlle_DW.obj_hh.orbMetadataObj,
                      &Hummingbird_Flight_Controlle_DW.obj_hh.orbAdvertiseObj,
                      &Hummingbird_Flight_Controller_B.BusAssignment_n);

      // MATLAB Function: '<S10>/MATLAB Function2' incorporates:
      //   Constant: '<S1405>/Constant'
      //   DataTypeConversion: '<S5>/Cast To Double3'
      //   Gain: '<S1172>/Gain'
      //   Gain: '<S1405>/Gain'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //   Sum: '<S1405>/Sum'
      //
      Hummingbird_MATLABFunction2(static_cast<real_T>
        (Hummingbird_Flight_Controller_B.a_n),
        Hummingbird_Flight_Controller_P.Gain_Gain_j2 *
        (Hummingbird_Flight_Controller_P.Gain_Gain_j * (static_cast<real_T>
        (Hummingbird_Flight_Controller_B.BusCreator.Yaw) -
        Hummingbird_Flight_Controller_P.Constant_Value_lu)),
        &Hummingbird_Flight_Controller_B.Esp_dot);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_g);

      // Sum: '<S1172>/Sum1' incorporates:
      //   BusCreator: '<S5>/Bus Creator4'
      //   Constant: '<S1403>/Constant'
      //   Constant: '<S1404>/Constant'
      //   Gain: '<S1172>/Gain1'
      //   Gain: '<S1172>/Gain2'
      //   Gain: '<S1403>/Gain'
      //   Gain: '<S1404>/Gain'
      //   Sum: '<S1403>/Sum'
      //   Sum: '<S1404>/Sum'

      Hummingbird_Flight_Controller_B.Filter_os[0] = (static_cast<real_T>
        (Hummingbird_Flight_Controller_B.BusCreator.Pitch) -
        Hummingbird_Flight_Controller_P.Constant_Value_mb) *
        Hummingbird_Flight_Controller_P.Gain_Gain_e *
        Hummingbird_Flight_Controller_P.Gain2_Gain_j -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;
      Hummingbird_Flight_Controller_B.Filter_os[1] = (static_cast<real_T>
        (Hummingbird_Flight_Controller_B.BusCreator.Roll) -
        Hummingbird_Flight_Controller_P.Constant_Value_mbi) *
        Hummingbird_Flight_Controller_P.Gain_Gain_d *
        Hummingbird_Flight_Controller_P.Gain1_Gain_b -
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;

      // Gain: '<S1443>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1435>/Filter'
      //   Gain: '<S1433>/Derivative Gain'
      //   Sum: '<S1435>/SumD'

      Hummingbird_Flight_Controller_B.scale =
        (Hummingbird_Flight_Controller_P.PIDController9_D_d[0] *
         Hummingbird_Flight_Controller_B.Filter_os[0] -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_h[0]) *
        Hummingbird_Flight_Controller_P.PIDController9_N_j;
      Hummingbird_Flight_Controller_B.DProdOut_n[0] =
        Hummingbird_Flight_Controller_B.scale;

      // Sum: '<S1449>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1440>/Integrator'
      //   Gain: '<S1433>/Derivative Gain'
      //   Gain: '<S1445>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (Hummingbird_Flight_Controller_P.PIDController9_P_b[0] *
         Hummingbird_Flight_Controller_B.Filter_os[0] +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[0]) +
        Hummingbird_Flight_Controller_B.scale;

      // Saturate: '<S1447>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturatio_o) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturatio_o;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerSaturatio_a)
      {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.PIDController9_LowerSaturatio_a;
      }

      // Gain: '<S1443>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1435>/Filter'
      //   Gain: '<S1433>/Derivative Gain'
      //   Sum: '<S1435>/SumD'

      Hummingbird_Flight_Controller_B.scale =
        (Hummingbird_Flight_Controller_P.PIDController9_D_d[1] *
         Hummingbird_Flight_Controller_B.Filter_os[1] -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_h[1]) *
        Hummingbird_Flight_Controller_P.PIDController9_N_j;
      Hummingbird_Flight_Controller_B.DProdOut_n[1] =
        Hummingbird_Flight_Controller_B.scale;

      // Sum: '<S1449>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1440>/Integrator'
      //   Gain: '<S1433>/Derivative Gain'
      //   Gain: '<S1445>/Proportional Gain'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        (Hummingbird_Flight_Controller_P.PIDController9_P_b[1] *
         Hummingbird_Flight_Controller_B.Filter_os[1] +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[1]) +
        Hummingbird_Flight_Controller_B.scale;

      // Saturate: '<S1447>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturatio_o) {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturatio_o;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerSaturatio_a)
      {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          Hummingbird_Flight_Controller_P.PIDController9_LowerSaturatio_a;
      }

      // Gain: '<S1443>/Filter Coefficient' incorporates:
      //   DiscreteIntegrator: '<S1435>/Filter'
      //   Gain: '<S1433>/Derivative Gain'
      //   Sum: '<S1172>/Sum1'
      //   Sum: '<S1435>/SumD'

      Hummingbird_Flight_Controller_B.scale =
        (Hummingbird_Flight_Controller_P.PIDController9_D_d[2] *
         Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_h[2]) *
        Hummingbird_Flight_Controller_P.PIDController9_N_j;

      // Sum: '<S1449>/Sum' incorporates:
      //   DiscreteIntegrator: '<S1440>/Integrator'
      //   Gain: '<S1445>/Proportional Gain'
      //   Sum: '<S1172>/Sum1'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
        (Hummingbird_Flight_Controller_P.PIDController9_P_b[2] *
         Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 +
         Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[2]) +
        Hummingbird_Flight_Controller_B.scale;

      // Saturate: '<S1447>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturatio_o) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          Hummingbird_Flight_Controller_P.PIDController9_UpperSaturatio_o;
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerSaturatio_a)
      {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          Hummingbird_Flight_Controller_P.PIDController9_LowerSaturatio_a;
      }

      // MATLAB Function: '<S1172>/MATLAB Function1' incorporates:
      //   Saturate: '<S1447>/Saturation'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 = asin
        ((-Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 * 0.0 +
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1) / sqrt
         ((Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 *
           Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 +
           Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 *
           Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1) +
          (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 - 32.174)
          * (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
             32.174)));

      // Saturate: '<S1172>/Saturation1'
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation1_UpperSat_a) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation1_UpperSat_a;
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation1_LowerSat_a) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation1_LowerSat_a;
      }

      // MATLAB Function: '<S1172>/MATLAB Function1' incorporates:
      //   Saturate: '<S1447>/Saturation'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 = atan
        ((-Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 -
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 * 0.0) / fabs
         (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 - 32.174));

      // Saturate: '<S1172>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_h) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_h;
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_a) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_a;
      }

      // BusAssignment: '<S1229>/Bus Assignment' incorporates:
      //   Constant: '<S1170>/Constant5'
      //   DataTypeConversion: '<S1170>/Cast To Single16'
      //   DataTypeConversion: '<S1170>/Cast To Single17'
      //   DataTypeConversion: '<S1170>/Cast To Single18'
      //   MATLABSystem: '<S1229>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_ip.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_g.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_ip.roll = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_ip.pitch =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_ip.yaw_rate =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.Esp_dot);
      Hummingbird_Flight_Controller_B.BusAssignment_ip._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant5_Value_l[0];
      Hummingbird_Flight_Controller_B.BusAssignment_ip._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant5_Value_l[1];
      Hummingbird_Flight_Controller_B.BusAssignment_ip._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant5_Value_l[2];
      Hummingbird_Flight_Controller_B.BusAssignment_ip._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant5_Value_l[3];
      Hummingbird_Fligh_SinkBlock
        (&Hummingbird_Flight_Controller_B.BusAssignment_ip,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_hd);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_j);

      // Sum: '<S1170>/Sum6' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double4'
      //   DataTypeConversion: '<S5>/Cast To Double5'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0;
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1;
      Hummin_ReadParameter1_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter1_k,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_k);
      Humming_ReadParameter_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter_k,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_k);
      Hummingb_ReadParameter2_b3r
        (&Hummingbird_Flight_Controller_B.ReadParameter2_o,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_o);
      Hummi_ReadParameter1_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter1_lu,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_lu);
      Hummin_ReadParameter_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter_lu,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_lu);
      Humming_ReadParameter2_b3rg
        (&Hummingbird_Flight_Controller_B.ReadParameter2_l,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_l);

      // Product: '<S1377>/NProd Out' incorporates:
      //   Constant: '<S1170>/Constant4'
      //   DiscreteIntegrator: '<S1369>/Filter'
      //   Product: '<S1367>/DProd Out'
      //   Sum: '<S1369>/SumD'

      Hummingbird_Flight_Controller_B.prev_waypoint[0] =
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 *
         Hummingbird_Flight_Controller_B.ReadParameter1_lu.ReadParameter1_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_c[0]) *
        Hummingbird_Flight_Controller_P.Constant4_Value_ey;
      Hummingbird_Flight_Controller_B.prev_waypoint[1] =
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 *
         Hummingbird_Flight_Controller_B.ReadParameter_lu.ReadParameter_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_c[1]) *
        Hummingbird_Flight_Controller_P.Constant4_Value_ey;

      // Sum: '<S1383>/Sum' incorporates:
      //   Product: '<S1379>/PProd Out'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 *
        Hummingbird_Flight_Controller_B.ReadParameter1_k.ReadParameter1_o1 +
        Hummingbird_Flight_Controller_B.prev_waypoint[0];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 *
        Hummingbird_Flight_Controller_B.ReadParameter_k.ReadParameter_o1 +
        Hummingbird_Flight_Controller_B.prev_waypoint[1];

      // BusAssignment: '<S1230>/Bus Assignment' incorporates:
      //   Constant: '<S1170>/Constant6'
      //   DataTypeConversion: '<S1170>/Cast To Single10'
      //   DataTypeConversion: '<S1170>/Cast To Single11'
      //   DataTypeConversion: '<S1170>/Cast To Single15'
      //   MATLABSystem: '<S1230>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_j.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_j.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_j.roll_rate =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_j.pitch_rate = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_j.yaw_rate =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.Esp_dot);
      Hummingbird_Flight_Controller_B.BusAssignment_j._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant6_Value_k[0];
      Hummingbird_Flight_Controller_B.BusAssignment_j._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant6_Value_k[1];
      Hummingbird_Flight_Controller_B.BusAssignment_j._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant6_Value_k[2];
      Hummingbird_Flight_Controller_B.BusAssignment_j._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant6_Value_k[3];
      Hummingbird_Fli_SinkBlock_h
        (&Hummingbird_Flight_Controller_B.BusAssignment_j,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_o);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_k);

      // Sum: '<S1170>/Sum2' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double7'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 -=
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[0];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -=
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[1];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        Hummingbird_Flight_Controller_B.Esp_dot -
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[2];

      // BusAssignment: '<S1231>/Bus Assignment' incorporates:
      //   Constant: '<S1170>/Constant1'
      //   DataTypeConversion: '<S1170>/Cast To Single12'
      //   DataTypeConversion: '<S1170>/Cast To Single13'
      //   DataTypeConversion: '<S1170>/Cast To Single14'
      //   MATLABSystem: '<S1231>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_i.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_k.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_i.roll_rate_error =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_i.pitch_rate_error =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_i.yaw_rate_error =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment_i._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant1_Value_fj[0];
      Hummingbird_Flight_Controller_B.BusAssignment_i._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant1_Value_fj[1];
      Hummingbird_Flight_Controller_B.BusAssignment_i._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant1_Value_fj[2];
      Hummingbird_Flight_Controller_B.BusAssignment_i._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant1_Value_fj[3];
      Hummingbird_Fli_SinkBlock_j
        (&Hummingbird_Flight_Controller_B.BusAssignment_i,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_jf);
      Humm_ReadParameter1_b3rgaen
        (&Hummingbird_Flight_Controller_B.ReadParameter1_m,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_m);
      Hummi_ReadParameter_b3rgaen
        (&Hummingbird_Flight_Controller_B.ReadParameter_m,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_m);
      Hummin_ReadParameter2_b3rga
        (&Hummingbird_Flight_Controller_B.ReadParameter2_p,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_p);
      Hum_ReadParameter1_b3rgaenb
        (&Hummingbird_Flight_Controller_B.ReadParameter1_kh,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_kh);
      Humm_ReadParameter_b3rgaenb
        (&Hummingbird_Flight_Controller_B.ReadParameter_kh,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_kh);
      Hummi_ReadParameter2_b3rgae
        (&Hummingbird_Flight_Controller_B.ReadParameter2_i,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_i);

      // Merge: '<S1>/ Merge 2' incorporates:
      //   BusCreator: '<S5>/Bus Creator6'
      //   Product: '<S1275>/PProd Out'
      //   Product: '<S1327>/PProd Out'
      //   Sum: '<S1170>/Sum1'

      Hummingbird_Flight_Controller_B.dM[0] =
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 *
         Hummingbird_Flight_Controller_B.ReadParameter1_m.ReadParameter1_o1 -
         Hummingbird_Flight_Controller_B.Sum_e[0]) *
        Hummingbird_Flight_Controller_B.ReadParameter1_kh.ReadParameter1_o1;
      Hummingbird_Flight_Controller_B.dM[1] =
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 *
         Hummingbird_Flight_Controller_B.ReadParameter_m.ReadParameter_o1 -
         Hummingbird_Flight_Controller_B.Sum_e[1]) *
        Hummingbird_Flight_Controller_B.ReadParameter_kh.ReadParameter_o1;
      Hummingbird_Flight_Controller_B.dM[2] =
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 *
         Hummingbird_Flight_Controller_B.ReadParameter2_p.ReadParameter2_o1 -
         Hummingbird_Flight_Controller_B.Sum_e[2]) *
        Hummingbird_Flight_Controller_B.ReadParameter2_i.ReadParameter2_o1;

      // Update for DiscreteIntegrator: '<S1203>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_f +=
        Hummingbird_Flight_Controller_P.Filter_gainval_pt *
        Hummingbird_Flight_Controller_B.V;

      // Update for DiscreteIntegrator: '<S1440>/Integrator' incorporates:
      //   Gain: '<S1437>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        Hummingbird_Flight_Controller_P.PIDController9_I_i[0] *
        Hummingbird_Flight_Controller_B.Filter_os[0] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_ma +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[0];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[0] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegrato_e) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[0] =
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegrato_e;
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerIntegrato_p)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[0] =
          Hummingbird_Flight_Controller_P.PIDController9_LowerIntegrato_p;
      }

      // Update for DiscreteIntegrator: '<S1435>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_h[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_kc *
        Hummingbird_Flight_Controller_B.DProdOut_n[0];

      // Update for DiscreteIntegrator: '<S1369>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_c[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_o *
        Hummingbird_Flight_Controller_B.prev_waypoint[0];

      // Update for DiscreteIntegrator: '<S1440>/Integrator' incorporates:
      //   Gain: '<S1437>/Integral Gain'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        Hummingbird_Flight_Controller_P.PIDController9_I_i[1] *
        Hummingbird_Flight_Controller_B.Filter_os[1] *
        Hummingbird_Flight_Controller_P.Integrator_gainval_ma +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[1];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[1] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegrato_e) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[1] =
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegrato_e;
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerIntegrato_p)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[1] =
          Hummingbird_Flight_Controller_P.PIDController9_LowerIntegrato_p;
      }

      // Update for DiscreteIntegrator: '<S1435>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_h[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_kc *
        Hummingbird_Flight_Controller_B.DProdOut_n[1];

      // Update for DiscreteIntegrator: '<S1369>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_c[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_o *
        Hummingbird_Flight_Controller_B.prev_waypoint[1];

      // Update for DiscreteIntegrator: '<S1440>/Integrator' incorporates:
      //   Gain: '<S1437>/Integral Gain'
      //   Sum: '<S1172>/Sum1'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        Hummingbird_Flight_Controller_P.PIDController9_I_i[2] *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 *
        Hummingbird_Flight_Controller_P.Integrator_gainval_ma +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[2];
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[2] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 >
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegrato_e) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[2] =
          Hummingbird_Flight_Controller_P.PIDController9_UpperIntegrato_e;
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 <
                 Hummingbird_Flight_Controller_P.PIDController9_LowerIntegrato_p)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[2] =
          Hummingbird_Flight_Controller_P.PIDController9_LowerIntegrato_p;
      }

      // Update for DiscreteIntegrator: '<S1435>/Filter' incorporates:
      //   Gain: '<S1443>/Filter Coefficient'

      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_h[2] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_kc *
        Hummingbird_Flight_Controller_B.scale;

      // Update for DiscreteIntegrator: '<S1369>/Filter' incorporates:
      //   Constant: '<S1170>/Constant4'
      //   DataTypeConversion: '<S5>/Cast To Double3'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //   Product: '<S1367>/DProd Out'
      //   Product: '<S1377>/NProd Out'
      //   Sum: '<S1170>/Sum6'
      //   Sum: '<S1369>/SumD'
      //
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_c[2] +=
        ((Hummingbird_Flight_Controller_B.Esp_dot -
          Hummingbird_Flight_Controller_B.a_n) *
         Hummingbird_Flight_Controller_B.ReadParameter2_l.ReadParameter2_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_c[2]) *
        Hummingbird_Flight_Controller_P.Constant4_Value_ey *
        Hummingbird_Flight_Controller_P.Filter_gainval_o;
      break;

     default:
      // case IN_Set_mission_start:
      Hummingbird_Flight_Controlle_DW.is_Flight_controller =
        Hummingbird_Flight_C_IN_FW_Nav1;
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_n);

      // MATLAB Function: '<S13>/MATLAB Function2'
      if (rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lat)
          || rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lon))
      {
        Hummingbird_Flight_Controller_B.prev_lat[0] =
          Hummingbird_Flight_Controlle_DW.mission_start[0];
        Hummingbird_Flight_Controller_B.prev_lat[1] =
          Hummingbird_Flight_Controlle_DW.mission_start[1];
        Hummingbird_Flight_Controller_B.prev_lat[2] =
          Hummingbird_Flight_Controlle_DW.mission_start[2];
      } else {
        Hummingbird_Flight_Controller_B.prev_lat[0] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lat;
        Hummingbird_Flight_Controller_B.prev_lat[1] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lon;
        Hummingbird_Flight_Controller_B.prev_lat[2] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.altitude;
      }

      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[0] =
        Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lat;
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[1] =
        Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lon;
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[2] =
        Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.altitude;
      Hummingbird_Flight_Cont_lla2ned(Hummingbird_Flight_Controller_B.prev_lat,
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c,
        Hummingbird_Flight_Controller_B.current_lat);
      Hummingbird_Flight_Controller_B.prev_waypoint[0] = 3.28084 *
        Hummingbird_Flight_Controller_B.current_lat[0] +
        Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.X;
      Hummingbird_Flight_Controller_B.prev_waypoint[1] = 3.28084 *
        Hummingbird_Flight_Controller_B.current_lat[1] +
        Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.Y;
      if (rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lat))
      {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 = 0.0;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 = 0.0;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 = 0.0;
      } else if (rtIsNaN
                 (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lon))
      {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 = 0.0;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 = 0.0;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 = 0.0;
      } else {
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[0] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lat;
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[1] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lon;
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[2] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.altitude;
        Hummingbird_Flight_Controller_B.prev_lat[0] =
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lat;
        Hummingbird_Flight_Controller_B.prev_lat[1] =
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lon;
        Hummingbird_Flight_Controller_B.prev_lat[2] =
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.altitude;
        Hummingbird_Flight_Cont_lla2ned
          (Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c,
           Hummingbird_Flight_Controller_B.prev_lat,
           Hummingbird_Flight_Controller_B.dv);
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 = 3.28084 *
          Hummingbird_Flight_Controller_B.dv[0] +
          Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.X;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 = 3.28084 *
          Hummingbird_Flight_Controller_B.dv[1] +
          Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.Y;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 = 3.28084 *
          Hummingbird_Flight_Controller_B.dv[2] +
          Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.Z;
      }

      if (rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.next.gps_pos.lat))
      {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 = 1.0;
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 = 1.0;
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 = 0.0;
      } else if (rtIsNaN
                 (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.next.gps_pos.lon))
      {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 = 1.0;
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 = 1.0;
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 = 0.0;
      } else {
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[0] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.next.gps_pos.lat;
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[1] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.next.gps_pos.lon;
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[2] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.next.gps_pos.altitude;
        Hummingbird_Flight_Controller_B.prev_lat[0] =
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lat;
        Hummingbird_Flight_Controller_B.prev_lat[1] =
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.lon;
        Hummingbird_Flight_Controller_B.prev_lat[2] =
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.altitude;
        Hummingbird_Flight_Cont_lla2ned
          (Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c,
           Hummingbird_Flight_Controller_B.prev_lat,
           Hummingbird_Flight_Controller_B.dv);
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 = 3.28084 *
          Hummingbird_Flight_Controller_B.dv[0] +
          Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.X;
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 = 3.28084 *
          Hummingbird_Flight_Controller_B.dv[1] +
          Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.Y;
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 = 3.28084 *
          Hummingbird_Flight_Controller_B.dv[2] +
          Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.Z;
      }

      // SignalConversion generated from: '<S15>/ SFunction ' incorporates:
      //   BusCreator generated from: '<Root>/Chart'
      //   BusCreator: '<S5>/Bus Creator3'
      //   MATLAB Function: '<S13>/MATLAB Function1'

      Hummingbird_Flight_Controller_B.DProdOut_n[0] =
        Hummingbird_Flight_Controller_B.b_t;
      Hummingbird_Flight_Controller_B.DProdOut_n[1] =
        Hummingbird_Flight_Controller_B.CastToDouble25;
      Hummingbird_Flight_Controller_B.DProdOut_n[2] =
        Hummingbird_Flight_Controller_B.r_c;

      // MATLAB Function: '<S13>/MATLAB Function1' incorporates:
      //   BusCreator generated from: '<Root>/Chart'
      //   BusCreator: '<S5>/Bus Creator3'
      //   BusCreator: '<S5>/Bus Creator4'
      //   MATLAB Function: '<S14>/MATLAB Function'

      Hummingbird_Flight_Controller_B.scale = 3.3121686421112381E-170;
      Hummingbird_Flight_Controller_B.Esp_dot = fabs
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0);
      if (Hummingbird_Flight_Controller_B.Esp_dot > 3.3121686421112381E-170) {
        Hummingbird_Flight_Controller_B.V = 1.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.Esp_dot;
      } else {
        Hummingbird_Flight_Controller_B.t =
          Hummingbird_Flight_Controller_B.Esp_dot / 3.3121686421112381E-170;
        Hummingbird_Flight_Controller_B.V = Hummingbird_Flight_Controller_B.t *
          Hummingbird_Flight_Controller_B.t;
      }

      Hummingbird_Flight_Controller_B.IntegralGain_k = fabs
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1);
      if (Hummingbird_Flight_Controller_B.IntegralGain_k >
          Hummingbird_Flight_Controller_B.scale) {
        Hummingbird_Flight_Controller_B.t =
          Hummingbird_Flight_Controller_B.scale /
          Hummingbird_Flight_Controller_B.IntegralGain_k;
        Hummingbird_Flight_Controller_B.V = Hummingbird_Flight_Controller_B.V *
          Hummingbird_Flight_Controller_B.t * Hummingbird_Flight_Controller_B.t
          + 1.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.IntegralGain_k;
      } else {
        Hummingbird_Flight_Controller_B.t =
          Hummingbird_Flight_Controller_B.IntegralGain_k /
          Hummingbird_Flight_Controller_B.scale;
        Hummingbird_Flight_Controller_B.V += Hummingbird_Flight_Controller_B.t *
          Hummingbird_Flight_Controller_B.t;
      }

      Hummingbird_Flight_Controller_B.absxk = fabs
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2);
      if (Hummingbird_Flight_Controller_B.absxk >
          Hummingbird_Flight_Controller_B.scale) {
        Hummingbird_Flight_Controller_B.t =
          Hummingbird_Flight_Controller_B.scale /
          Hummingbird_Flight_Controller_B.absxk;
        Hummingbird_Flight_Controller_B.V = Hummingbird_Flight_Controller_B.V *
          Hummingbird_Flight_Controller_B.t * Hummingbird_Flight_Controller_B.t
          + 1.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.absxk;
      } else {
        Hummingbird_Flight_Controller_B.t =
          Hummingbird_Flight_Controller_B.absxk /
          Hummingbird_Flight_Controller_B.scale;
        Hummingbird_Flight_Controller_B.V += Hummingbird_Flight_Controller_B.t *
          Hummingbird_Flight_Controller_B.t;
      }

      Hummingbird_Flight_Controller_B.V = Hummingbird_Flight_Controller_B.scale *
        sqrt(Hummingbird_Flight_Controller_B.V);
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[0] =
        Hummingbird_Flight_Controller_B.b_t -
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[1] =
        Hummingbird_Flight_Controller_B.CastToDouble25 -
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1;
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[2] =
        Hummingbird_Flight_Controller_B.r_c -
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
      Hummingbird_Flight_Controller_B.t = 1.0 / (exp
        ((Hummingbird_Flight_Control_norm
          (Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c) - 300.0) / 50.0) +
        1.0) * 100.0;
      Hummingbird_Flight_Controller_B.absxk =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 -
        Hummingbird_Flight_Controller_B.prev_waypoint[0];
      Hummingbird_Flight_Controller_B.b_gamma =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 -
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;
      Hummingbird_Flight_Controller_B.eta =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
        Hummingbird_Flight_Controller_B.prev_waypoint[1];
      Hummingbird_Flight_Controller_B.Add1 =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1;
      Hummingbird_Flight_Controller_B.b_t -=
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 -
        (Hummingbird_Flight_Controller_B.absxk +
         Hummingbird_Flight_Controller_B.b_gamma) / sqrt
        (Hummingbird_Flight_Controller_B.absxk *
         Hummingbird_Flight_Controller_B.absxk +
         Hummingbird_Flight_Controller_B.b_gamma *
         Hummingbird_Flight_Controller_B.b_gamma) *
        Hummingbird_Flight_Controller_B.t;
      Hummingbird_Flight_Controller_B.r_c =
        Hummingbird_Flight_Controller_B.CastToDouble25 -
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
         (Hummingbird_Flight_Controller_B.eta +
          Hummingbird_Flight_Controller_B.Add1) / sqrt
         (Hummingbird_Flight_Controller_B.eta *
          Hummingbird_Flight_Controller_B.eta +
          Hummingbird_Flight_Controller_B.Add1 *
          Hummingbird_Flight_Controller_B.Add1) *
         Hummingbird_Flight_Controller_B.t);
      Hummingbird_Flight_Controller_B.theta = Hummingbird_Fligh_rt_atan2d_snf
        (Hummingbird_Flight_Controller_B.r_c,
         Hummingbird_Flight_Controller_B.b_t);
      Hummingbird_Flight_Controller_B.scale = 3.3121686421112381E-170;
      Hummingbird_Flight_Controller_B.CastToDouble25 = fabs
        (Hummingbird_Flight_Controller_B.b_t);
      if (Hummingbird_Flight_Controller_B.CastToDouble25 >
          3.3121686421112381E-170) {
        Hummingbird_Flight_Controller_B.absx = 1.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.CastToDouble25;
      } else {
        Hummingbird_Flight_Controller_B.b_t =
          Hummingbird_Flight_Controller_B.CastToDouble25 /
          3.3121686421112381E-170;
        Hummingbird_Flight_Controller_B.absx =
          Hummingbird_Flight_Controller_B.b_t *
          Hummingbird_Flight_Controller_B.b_t;
      }

      Hummingbird_Flight_Controller_B.CastToDouble25 = fabs
        (Hummingbird_Flight_Controller_B.r_c);
      if (Hummingbird_Flight_Controller_B.CastToDouble25 >
          Hummingbird_Flight_Controller_B.scale) {
        Hummingbird_Flight_Controller_B.b_t =
          Hummingbird_Flight_Controller_B.scale /
          Hummingbird_Flight_Controller_B.CastToDouble25;
        Hummingbird_Flight_Controller_B.absx =
          Hummingbird_Flight_Controller_B.absx *
          Hummingbird_Flight_Controller_B.b_t *
          Hummingbird_Flight_Controller_B.b_t + 1.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.CastToDouble25;
      } else {
        Hummingbird_Flight_Controller_B.b_t =
          Hummingbird_Flight_Controller_B.CastToDouble25 /
          Hummingbird_Flight_Controller_B.scale;
        Hummingbird_Flight_Controller_B.absx +=
          Hummingbird_Flight_Controller_B.b_t *
          Hummingbird_Flight_Controller_B.b_t;
      }

      Hummingbird_Flight_Controller_B.r_c =
        Hummingbird_Flight_Controller_B.scale * sqrt
        (Hummingbird_Flight_Controller_B.absx);
      Hummingbird_Flight_Controller_B.CastToDouble25 = sin
        (Hummingbird_Flight_Controller_B.theta);
      Hummingbird_Flight_Controller_B.b_t = cos
        (Hummingbird_Flight_Controller_B.theta);
      Hummingbird_Flight_Controller_B.theta = 0.0;
      for (Hummingbird_Flight_Controller_B.i = 0;
           Hummingbird_Flight_Controller_B.i < 3;
           Hummingbird_Flight_Controller_B.i++) {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.DProdOut_n[Hummingbird_Flight_Controller_B.i];
        Hummingbird_Flight_Controller_B.absx =
          Hummingbird_Flight_Controller_B.scale -
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;
        Hummingbird_Flight_Controller_B.x[3 * Hummingbird_Flight_Controller_B.i]
          = Hummingbird_Flight_Controller_B.absx;
        Hummingbird_Flight_Controller_B.absx = fabs
          (Hummingbird_Flight_Controller_B.absx);
        if (rtIsNaN(Hummingbird_Flight_Controller_B.absx)) {
          Hummingbird_Flight_Controller_B.theta = (rtNaN);
        } else if (Hummingbird_Flight_Controller_B.absx >
                   Hummingbird_Flight_Controller_B.theta) {
          Hummingbird_Flight_Controller_B.theta =
            Hummingbird_Flight_Controller_B.absx;
        }

        Hummingbird_Flight_Controller_B.absx =
          Hummingbird_Flight_Controller_B.scale -
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1;
        Hummingbird_Flight_Controller_B.x[3 * Hummingbird_Flight_Controller_B.i
          + 1] = Hummingbird_Flight_Controller_B.absx;
        Hummingbird_Flight_Controller_B.absx = fabs
          (Hummingbird_Flight_Controller_B.absx);
        if (rtIsNaN(Hummingbird_Flight_Controller_B.absx)) {
          Hummingbird_Flight_Controller_B.theta = (rtNaN);
        } else if (Hummingbird_Flight_Controller_B.absx >
                   Hummingbird_Flight_Controller_B.theta) {
          Hummingbird_Flight_Controller_B.theta =
            Hummingbird_Flight_Controller_B.absx;
        }

        Hummingbird_Flight_Controller_B.absx =
          Hummingbird_Flight_Controller_B.scale -
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
        Hummingbird_Flight_Controller_B.x[3 * Hummingbird_Flight_Controller_B.i
          + 2] = Hummingbird_Flight_Controller_B.absx;
        Hummingbird_Flight_Controller_B.absx = fabs
          (Hummingbird_Flight_Controller_B.absx);
        if (rtIsNaN(Hummingbird_Flight_Controller_B.absx)) {
          Hummingbird_Flight_Controller_B.theta = (rtNaN);
        } else if (Hummingbird_Flight_Controller_B.absx >
                   Hummingbird_Flight_Controller_B.theta) {
          Hummingbird_Flight_Controller_B.theta =
            Hummingbird_Flight_Controller_B.absx;
        }
      }

      if ((!rtIsInf(Hummingbird_Flight_Controller_B.theta)) && (!rtIsNaN
           (Hummingbird_Flight_Controller_B.theta))) {
        Hummingbird_Flight_Controll_svd(Hummingbird_Flight_Controller_B.x,
          Hummingbird_Flight_Controller_B.dv);
        Hummingbird_Flight_Controller_B.theta =
          Hummingbird_Flight_Controller_B.dv[0];
      }

      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_B.absxk *
        Hummingbird_Flight_Controller_B.Add1 -
        Hummingbird_Flight_Controller_B.b_gamma *
        Hummingbird_Flight_Controller_B.eta;
      if (rtIsNaN(Hummingbird_Flight_Controller_B.scale)) {
        Hummingbird_Flight_Controller_B.scale = (rtNaN);
      } else if (Hummingbird_Flight_Controller_B.scale < 0.0) {
        Hummingbird_Flight_Controller_B.scale = -1.0;
      } else {
        Hummingbird_Flight_Controller_B.scale =
          (Hummingbird_Flight_Controller_B.scale > 0.0);
      }

      Hummingbird_Flight_Controller_B.b_gamma = -(1.0 / (exp
        ((Hummingbird_Flight_Controller_B.theta - 300.0) / 50.0) + 1.0)) * 0.7 *
        Hummingbird_Flight_Controller_B.scale;
      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_B.r_c - Hummingbird_Flight_Controller_B.t;
      Hummingbird_Flight_Controller_B.absxk =
        Hummingbird_Flight_Controller_B.b_gamma *
        Hummingbird_Flight_Controller_B.r_c;
      Hummingbird_Flight_Controller_B.eta = sqrt
        (Hummingbird_Flight_Controller_B.scale *
         Hummingbird_Flight_Controller_B.scale +
         Hummingbird_Flight_Controller_B.absxk *
         Hummingbird_Flight_Controller_B.absxk) * (1.0 /
        Hummingbird_Flight_Controller_B.V);
      Hummingbird_Flight_Controller_B.Add1 = 1.0 /
        Hummingbird_Flight_Controller_B.eta;
      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_B.Add1 *
        -Hummingbird_Flight_Controller_B.scale;
      Hummingbird_Flight_Controller_B.absxk *=
        Hummingbird_Flight_Controller_B.Add1;
      Hummingbird_Flight_Controller_B.V = ((Hummingbird_Flight_Controller_B.t -
        Hummingbird_Flight_Controller_B.r_c) * Hummingbird_Flight_Controller_B.t
        / (Hummingbird_Flight_Controller_B.V * Hummingbird_Flight_Controller_B.V
           * (Hummingbird_Flight_Controller_B.eta *
              Hummingbird_Flight_Controller_B.eta)) + 1.0) *
        (Hummingbird_Flight_Controller_B.b_gamma /
         Hummingbird_Flight_Controller_B.eta);
      Hummingbird_Flight_Controller_B.t = Hummingbird_Fligh_rt_atan2d_snf
        (Hummingbird_Flight_Controller_B.absxk,
         Hummingbird_Flight_Controller_B.scale);
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 =
        Hummingbird_Fligh_rt_atan2d_snf
        (-Hummingbird_Flight_Controller_B.CastToDouble25 *
         Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 +
         Hummingbird_Flight_Controller_B.b_t *
         Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1,
         Hummingbird_Flight_Controller_B.b_t *
         Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 +
         Hummingbird_Flight_Controller_B.CastToDouble25 *
         Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1);
      if (Hummingbird_Flight_Controller_B.t > 0.0) {
        if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 >= 0.0) {
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
            -(Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 -
              Hummingbird_Flight_Controller_B.t);
        } else {
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
            -((Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 +
               6.2831853071795862) - Hummingbird_Flight_Controller_B.t);
        }
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 >= 0.0)
      {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          -(Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 -
            (Hummingbird_Flight_Controller_B.t + 6.2831853071795862));
      } else {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          -(Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 -
            Hummingbird_Flight_Controller_B.t);
      }

      // BusAssignment: '<S17>/Bus Assignment' incorporates:
      //   DataTypeConversion: '<S13>/Cast To Single'
      //   DataTypeConversion: '<S13>/Cast To Single1'
      //   DataTypeConversion: '<S13>/Cast To Single2'
      //   DataTypeConversion: '<S13>/Cast To Single5'
      //   DataTypeConversion: '<S13>/Cast To Single6'
      //   DataTypeConversion: '<S13>/Cast To Single7'
      //   MATLAB Function: '<S13>/MATLAB Function1'
      //   MATLAB Function: '<S13>/MATLAB Function2'
      //   MATLABSystem: '<S17>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_o.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_n.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_o.prev_waypoint[0] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.prev_waypoint[0]);
      Hummingbird_Flight_Controller_B.BusAssignment_o.current_waypoint[0] =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_o.next_waypoint[0] =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_o.prev_waypoint[1] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.prev_waypoint[1]);
      Hummingbird_Flight_Controller_B.BusAssignment_o.current_waypoint[1] =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_o.next_waypoint[1] =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_o.prev_waypoint[2] =
        static_cast<real32_T>(3.28084 *
        Hummingbird_Flight_Controller_B.current_lat[2] +
        Hummingbird_Flight_Controller_B.BusCreator2.Home.local_pos.Z);
      Hummingbird_Flight_Controller_B.BusAssignment_o.current_waypoint[2] =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment_o.next_waypoint[2] =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment_o.angle_desired =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.t);
      Hummingbird_Flight_Controller_B.BusAssignment_o.angle_actual =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_o.alpha =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1);

      // MATLAB Function: '<S13>/MATLAB Function1'
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 = sin
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 / 2.0) *
        96.521999999999991;

      // BusAssignment: '<S17>/Bus Assignment' incorporates:
      //   DataTypeConversion: '<S13>/Cast To Single4'
      //   MATLAB Function: '<S13>/MATLAB Function1'

      Hummingbird_Flight_Controller_B.BusAssignment_o.as_a = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);

      // MATLAB Function: '<S13>/MATLAB Function1' incorporates:
      //   BusCreator generated from: '<Root>/Chart'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
        (Hummingbird_Flight_Controller_B.V *
         -Hummingbird_Flight_Controller_B.absxk * -sin
         (Hummingbird_Flight_Controller_B.course) +
         Hummingbird_Flight_Controller_B.V *
         Hummingbird_Flight_Controller_B.scale * cos
         (Hummingbird_Flight_Controller_B.course)) +
        Hummingbird_Flight_Controller_B.V * 0.0 * 0.0;

      // BusAssignment: '<S17>/Bus Assignment' incorporates:
      //   DataTypeConversion: '<S13>/Cast To Single3'
      //   MATLAB Function: '<S13>/MATLAB Function1'

      Hummingbird_Flight_Controller_B.BusAssignment_o.as_b =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);

      // MATLABSystem: '<S19>/SinkBlock' incorporates:
      //   BusAssignment: '<S17>/Bus Assignment'

      uORB_write_step(Hummingbird_Flight_Controlle_DW.obj_h3.orbMetadataObj,
                      &Hummingbird_Flight_Controlle_DW.obj_h3.orbAdvertiseObj,
                      &Hummingbird_Flight_Controller_B.BusAssignment_o);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_c);

      // MATLAB Function: '<S14>/MATLAB Function1' incorporates:
      //   BusCreator: '<S5>/Bus Creator9'

      if (rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lat)
          || rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lon))
      {
        Hummingbird_Flight_Controller_B.prev_lat_b[0] =
          Hummingbird_Flight_Controlle_DW.mission_start[0];
        Hummingbird_Flight_Controller_B.prev_lat_b[1] =
          Hummingbird_Flight_Controlle_DW.mission_start[1];
        Hummingbird_Flight_Controller_B.prev_lat_b[2] =
          Hummingbird_Flight_Controlle_DW.mission_start[2];
      } else {
        Hummingbird_Flight_Controller_B.prev_lat_b[0] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lat;
        Hummingbird_Flight_Controller_B.prev_lat_b[1] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.lon;
        Hummingbird_Flight_Controller_B.prev_lat_b[2] =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.previous.gps_pos.altitude;
      }

      if (rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lat)
          || rtIsNaN
          (Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lon))
      {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          Hummingbird_Flight_Controller_B.In1_a.lat;
        Hummingbird_Flight_Controller_B.V =
          Hummingbird_Flight_Controller_B.In1_a.lon;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_B.CastToDouble25_f;
      } else {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lat;
        Hummingbird_Flight_Controller_B.V =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.lon;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_B.BusCreator2.Setpoints.current.gps_pos.altitude;
      }

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        -(Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 -
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.altitude);
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        -(Hummingbird_Flight_Controller_B.CastToDouble25_f -
          Hummingbird_Flight_Controller_B.BusCreator2.Home.GPS.altitude);
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[0] =
        Hummingbird_Flight_Controller_B.In1_a.lat;
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[1] =
        Hummingbird_Flight_Controller_B.In1_a.lon;
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[2] =
        Hummingbird_Flight_Controller_B.CastToDouble25_f;
      Hummingbird_Flight_Controller_B.current_lat[0] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      Hummingbird_Flight_Controller_B.current_lat[1] =
        Hummingbird_Flight_Controller_B.V;
      Hummingbird_Flight_Controller_B.current_lat[2] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
      Hummingbird_Flight_Co_lla2ned_f
        (Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c,
         Hummingbird_Flight_Controller_B.current_lat,
         Hummingbird_Flight_Controller_B.DProdOut_n);
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 = sqrt
        (Hummingbird_Flight_Controller_B.DProdOut_n[0] *
         Hummingbird_Flight_Controller_B.DProdOut_n[0] +
         Hummingbird_Flight_Controller_B.DProdOut_n[1] *
         Hummingbird_Flight_Controller_B.DProdOut_n[1]);
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 == 0.0) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 = 1.0;
      }

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 = atan
        (Hummingbird_Flight_Controller_B.DProdOut_n[2] /
         Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2);
      Hummingbird_Flight_Controller_B.current_lat[0] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
      Hummingbird_Flight_Controller_B.current_lat[1] =
        Hummingbird_Flight_Controller_B.V;
      Hummingbird_Flight_Controller_B.current_lat[2] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
      Hummingbird_Flight_Co_lla2ned_f(Hummingbird_Flight_Controller_B.prev_lat_b,
        Hummingbird_Flight_Controller_B.current_lat,
        Hummingbird_Flight_Controller_B.DProdOut_n);
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 = sqrt
        (Hummingbird_Flight_Controller_B.DProdOut_n[0] *
         Hummingbird_Flight_Controller_B.DProdOut_n[0] +
         Hummingbird_Flight_Controller_B.DProdOut_n[1] *
         Hummingbird_Flight_Controller_B.DProdOut_n[1]);
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 == 0.0) {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 = 1.0;
      }

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 = atan
        (Hummingbird_Flight_Controller_B.DProdOut_n[2] /
         Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1);

      // MATLABSystem: '<S14>/Read Parameter'
      b_varargout_1 = MW_ParamRead_Step
        (Hummingbird_Flight_Controlle_DW.obj_lp.MW_PARAMHANDLE, MW_SINGLE,
         &Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2);
      if (b_varargout_1) {
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2 = 0.0F;
      }

      // Gain: '<S14>/Gain' incorporates:
      //   MATLABSystem: '<S14>/Read Parameter'
      //
      Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2 *=
        Hummingbird_Flight_Controller_P.Gain_Gain_h;

      // BusAssignment: '<S25>/Bus Assignment' incorporates:
      //   BusCreator generated from: '<Root>/Chart'
      //   Constant: '<S14>/Constant3'
      //   DataTypeConversion: '<S14>/Cast To Single1'
      //   DataTypeConversion: '<S14>/Cast To Single10'
      //   DataTypeConversion: '<S14>/Cast To Single11'
      //   DataTypeConversion: '<S14>/Cast To Single13'
      //   DataTypeConversion: '<S14>/Cast To Single8'
      //   DataTypeConversion: '<S14>/Cast To Single9'
      //   MATLAB Function: '<S14>/MATLAB Function1'
      //   MATLABSystem: '<S25>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_og.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_c.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_og.h_sp =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_og.h = static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_og.climb_angle_sp =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_og.climb_angle_ideal =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_og.horz_dist =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment_og.v_sp =
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2;
      Hummingbird_Flight_Controller_B.BusAssignment_og.v = static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.CastToDouble8);
      Hummingbird_Flight_Controller_B.BusAssignment_og._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant3_Value_h[0];
      Hummingbird_Flight_Controller_B.BusAssignment_og._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant3_Value_h[1];
      Hummingbird_Flight_Controller_B.BusAssignment_og._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant3_Value_h[2];
      Hummingbird_Flight_Controller_B.BusAssignment_og._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant3_Value_h[3];

      // MATLABSystem: '<S187>/SinkBlock' incorporates:
      //   BusAssignment: '<S25>/Bus Assignment'

      uORB_write_step(Hummingbird_Flight_Controlle_DW.obj_lf.orbMetadataObj,
                      &Hummingbird_Flight_Controlle_DW.obj_lf.orbAdvertiseObj,
                      &Hummingbird_Flight_Controller_B.BusAssignment_og);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_e);

      // MATLAB Function: '<S14>/MATLAB Function' incorporates:
      //   BusCreator generated from: '<Root>/Chart'
      //   BusCreator: '<S5>/Bus Creator4'
      //   Constant: '<S14>/Constant'

      Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3 =
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2;
      Hummingbird_Flight_Controller_B.V =
        Hummingbird_Flight_Controller_B.CastToDouble8;
      Hummingbird_Flight_Controller_B.scale = 3.3121686421112381E-170;
      if (Hummingbird_Flight_Controller_B.Esp_dot > 3.3121686421112381E-170) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 = 1.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.Esp_dot;
      } else {
        Hummingbird_Flight_Controller_B.t =
          Hummingbird_Flight_Controller_B.Esp_dot / 3.3121686421112381E-170;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_B.t * Hummingbird_Flight_Controller_B.t;
      }

      if (Hummingbird_Flight_Controller_B.IntegralGain_k >
          Hummingbird_Flight_Controller_B.scale) {
        Hummingbird_Flight_Controller_B.t =
          Hummingbird_Flight_Controller_B.scale /
          Hummingbird_Flight_Controller_B.IntegralGain_k;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 *
          Hummingbird_Flight_Controller_B.t * Hummingbird_Flight_Controller_B.t
          + 1.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.IntegralGain_k;
      } else {
        Hummingbird_Flight_Controller_B.t =
          Hummingbird_Flight_Controller_B.IntegralGain_k /
          Hummingbird_Flight_Controller_B.scale;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 +=
          Hummingbird_Flight_Controller_B.t * Hummingbird_Flight_Controller_B.t;
      }

      Hummingbird_Flight_Controller_B.IntegralGain_k = atan
        (-Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 /
         (Hummingbird_Flight_Controller_B.scale * sqrt
          (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2)));
      Hummingbird_Flight_Controller_B.scale = 3.3121686421112381E-170;
      Hummingbird_Flight_Controller_B.CastToDouble25 = fabs
        (Hummingbird_Flight_Controller_B.X);
      if (Hummingbird_Flight_Controller_B.CastToDouble25 >
          3.3121686421112381E-170) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 = 1.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.CastToDouble25;
      } else {
        Hummingbird_Flight_Controller_B.b_t =
          Hummingbird_Flight_Controller_B.CastToDouble25 /
          3.3121686421112381E-170;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_B.b_t *
          Hummingbird_Flight_Controller_B.b_t;
      }

      Hummingbird_Flight_Controller_B.CastToDouble25 = fabs
        (Hummingbird_Flight_Controller_B.Y);
      if (Hummingbird_Flight_Controller_B.CastToDouble25 >
          Hummingbird_Flight_Controller_B.scale) {
        Hummingbird_Flight_Controller_B.b_t =
          Hummingbird_Flight_Controller_B.scale /
          Hummingbird_Flight_Controller_B.CastToDouble25;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 *
          Hummingbird_Flight_Controller_B.b_t *
          Hummingbird_Flight_Controller_B.b_t + 1.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.CastToDouble25;
      } else {
        Hummingbird_Flight_Controller_B.b_t =
          Hummingbird_Flight_Controller_B.CastToDouble25 /
          Hummingbird_Flight_Controller_B.scale;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 +=
          Hummingbird_Flight_Controller_B.b_t *
          Hummingbird_Flight_Controller_B.b_t;
      }

      Hummingbird_Flight_Controller_B.CastToDouble25 = fabs
        (Hummingbird_Flight_Controller_B.Z);
      if (Hummingbird_Flight_Controller_B.CastToDouble25 >
          Hummingbird_Flight_Controller_B.scale) {
        Hummingbird_Flight_Controller_B.b_t =
          Hummingbird_Flight_Controller_B.scale /
          Hummingbird_Flight_Controller_B.CastToDouble25;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 *
          Hummingbird_Flight_Controller_B.b_t *
          Hummingbird_Flight_Controller_B.b_t + 1.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.CastToDouble25;
      } else {
        Hummingbird_Flight_Controller_B.b_t =
          Hummingbird_Flight_Controller_B.CastToDouble25 /
          Hummingbird_Flight_Controller_B.scale;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 +=
          Hummingbird_Flight_Controller_B.b_t *
          Hummingbird_Flight_Controller_B.b_t;
      }

      Hummingbird_Flight_Controller_B.Esp_dot =
        Hummingbird_Flight_Controller_P.Constant_Value_h / 32.2 + sin
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0);
      Hummingbird_Flight_Controller_B.scale =
        (Hummingbird_Flight_Controller_B.scale * sqrt
         (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) - 9.81) /
        32.2;
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        Hummingbird_Flight_Controller_B.scale + sin
        (Hummingbird_Flight_Controller_B.IntegralGain_k);
      if (Hummingbird_Flight_Controller_B.CastToDouble8 == 0.0) {
        Hummingbird_Flight_Controller_B.V = 1.0;
      }

      if (Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2 == 0.0F) {
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3 = 1.0F;
      }

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 -=
        Hummingbird_Flight_Controller_P.Constant_Value_h / 32.2;
      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_B.IntegralGain_k -
        Hummingbird_Flight_Controller_B.scale;

      // BusAssignment: '<S26>/Bus Assignment' incorporates:
      //   BusCreator generated from: '<Root>/Chart'
      //   DataTypeConversion: '<S14>/Cast To Single'
      //   MATLAB Function: '<S14>/MATLAB Function'
      //   MATLABSystem: '<S26>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_k.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_e.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_k.energy = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.CastToDouble8 *
                  Hummingbird_Flight_Controller_B.CastToDouble8 *
                  0.6211180124223602 + 40.0 *
                  -Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);

      // MATLAB Function: '<S14>/MATLAB Function' incorporates:
      //   MATLAB Function: '<S14>/MATLAB Function1'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        -Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 -
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 * tan
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1);

      // BusAssignment: '<S26>/Bus Assignment' incorporates:
      //   Constant: '<S14>/Constant1'
      //   DataTypeConversion: '<S14>/Cast To Single14'
      //   DataTypeConversion: '<S14>/Cast To Single3'
      //   DataTypeConversion: '<S14>/Cast To Single4'
      //   DataTypeConversion: '<S14>/Cast To Single5'
      //   DataTypeConversion: '<S14>/Cast To Single6'
      //   DataTypeConversion: '<S14>/Cast To Single7'
      //   MATLAB Function: '<S14>/MATLAB Function'

      Hummingbird_Flight_Controller_B.BusAssignment_k.energy_setpoint =
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2 *
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2 * 0.621118F +
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 * 40.0);
      Hummingbird_Flight_Controller_B.BusAssignment_k.energy_setpoint_dot =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.Esp_dot);
      Hummingbird_Flight_Controller_B.BusAssignment_k.energy_dot =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment_k.energy_ratio =
        static_cast<real32_T>(32.2 *
        -Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 /
        (Hummingbird_Flight_Controller_B.V * Hummingbird_Flight_Controller_B.V *
         0.5));
      Hummingbird_Flight_Controller_B.BusAssignment_k.energy_ratio_sp =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 * 32.2) /
        (Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3 *
         Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3 * 0.5F);
      Hummingbird_Flight_Controller_B.BusAssignment_k.energy_ratio_dot =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.scale);
      Hummingbird_Flight_Controller_B.BusAssignment_k.energy_ratio_setpoint_dot =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_k.climb_angle = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.IntegralGain_k);
      Hummingbird_Flight_Controller_B.BusAssignment_k._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant1_Value_a[0];
      Hummingbird_Flight_Controller_B.BusAssignment_k._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant1_Value_a[1];
      Hummingbird_Flight_Controller_B.BusAssignment_k._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant1_Value_a[2];
      Hummingbird_Flight_Controller_B.BusAssignment_k._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant1_Value_a[3];

      // MATLABSystem: '<S189>/SinkBlock' incorporates:
      //   BusAssignment: '<S26>/Bus Assignment'

      uORB_write_step(Hummingbird_Flight_Controlle_DW.obj_cx.orbMetadataObj,
                      &Hummingbird_Flight_Controlle_DW.obj_cx.orbAdvertiseObj,
                      &Hummingbird_Flight_Controller_B.BusAssignment_k);

      // Sum: '<S14>/Sum3'
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 -
        Hummingbird_Flight_Controller_B.scale;
      Hummingbird__ReadParameter3
        (&Hummingbird_Flight_Controller_B.ReadParameter3,
         &Hummingbird_Flight_Controlle_DW.ReadParameter3);

      // Product: '<S113>/IProd Out'
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 *
        Hummingbird_Flight_Controller_B.ReadParameter3.ReadParameter3_o1;

      // MATLABSystem: '<S27>/Read Parameter2'
      b_varargout_1 = MW_ParamRead_Step
        (Hummingbird_Flight_Controlle_DW.obj_kb.MW_PARAMHANDLE, MW_SINGLE,
         &Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2);
      if (b_varargout_1) {
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2 = 0.0F;
      }

      // Sum: '<S125>/Sum' incorporates:
      //   DiscreteIntegrator: '<S116>/Integrator'
      //   MATLABSystem: '<S27>/Read Parameter2'
      //   Product: '<S121>/PProd Out'
      //
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 *
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2 +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_l;

      // Sum: '<S14>/Sum4'
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
        Hummingbird_Flight_Controller_B.Esp_dot -
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;

      // MATLABSystem: '<S29>/Read Parameter1'
      b_varargout_1 = MW_ParamRead_Step
        (Hummingbird_Flight_Controlle_DW.obj_mt.MW_PARAMHANDLE, MW_SINGLE,
         &Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2);
      if (b_varargout_1) {
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2 = 0.0F;
      }

      // MATLABSystem: '<S29>/Read Parameter'
      b_varargout_1 = MW_ParamRead_Step
        (Hummingbird_Flight_Controlle_DW.obj_ee.MW_PARAMHANDLE, MW_SINGLE,
         &Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3);
      if (b_varargout_1) {
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3 = 0.0F;
      }

      // MATLABSystem: '<S27>/Read Parameter1'
      b_varargout_1 = MW_ParamRead_Step
        (Hummingbird_Flight_Controlle_DW.obj_eq.MW_PARAMHANDLE, MW_SINGLE,
         &Hummingbird_Flight_Controller_B.ParamStep);
      if (b_varargout_1) {
        Hummingbird_Flight_Controller_B.ParamStep = 0.0F;
      }

      // MATLABSystem: '<S29>/Read Parameter2'
      b_varargout_1 = MW_ParamRead_Step
        (Hummingbird_Flight_Controlle_DW.obj_oy.MW_PARAMHANDLE, MW_SINGLE,
         &Hummingbird_Flight_Controller_B.ParamStep_i);
      if (b_varargout_1) {
        Hummingbird_Flight_Controller_B.ParamStep_i = 0.0F;
      }

      // Sum: '<S177>/Sum' incorporates:
      //   DiscreteIntegrator: '<S168>/Integrator'
      //   MATLABSystem: '<S29>/Read Parameter'
      //   Product: '<S173>/PProd Out'
      //
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 *
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3 +
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_ld;

      // Saturate: '<S175>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.PIDController3_UpperSaturationL) {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          Hummingbird_Flight_Controller_P.PIDController3_UpperSaturationL;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.PIDController3_LowerSaturationL)
      {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          Hummingbird_Flight_Controller_P.PIDController3_LowerSaturationL;
      }

      // Merge: '<S1>/ Merge ' incorporates:
      //   MATLABSystem: '<S29>/Read Parameter2'
      //   Product: '<S14>/Product1'
      //   Saturate: '<S175>/Saturation'
      //   Sum: '<S14>/Sum5'
      //
      Hummingbird_Flight_Controller_B.dtFW =
        Hummingbird_Flight_Controller_B.Esp_dot *
        Hummingbird_Flight_Controller_B.ParamStep_i +
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;

      // MATLABSystem: '<S28>/Read Parameter'
      MW_ParamRead_Step(Hummingbird_Flight_Controlle_DW.obj_io.MW_PARAMHANDLE,
                        MW_SINGLE,
                        &Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3);
      Hummingbird__ReadParameter3
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3);

      // MATLABSystem: '<S28>/Read Parameter2'
      MW_ParamRead_Step(Hummingbird_Flight_Controlle_DW.obj_ou.MW_PARAMHANDLE,
                        MW_SINGLE,
                        &Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_i);

      // Trigonometry: '<S13>/Trigonometric Function2' incorporates:
      //   Gain: '<S13>/Gain3'
      //   MATLAB Function: '<S13>/MATLAB Function1'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 = atan
        ((Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 +
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0) * (1.0 /
          Hummingbird_Flight_Controller_P.g));

      // Saturate: '<S13>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat) {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat) {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat;
      }

      // Gain: '<S198>/Gain10' incorporates:
      //   Constant: '<S198>/Constant7'
      //   Saturate: '<S13>/Saturation'
      //   Sum: '<S198>/Sum8'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 -
         Hummingbird_Flight_Controller_P.Constant7_Value) *
        Hummingbird_Flight_Controller_P.Gain10_Gain;

      // Saturate: '<S198>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_f) {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_f;
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_j) {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_j;
      }

      // Gain: '<S12>/Gain1' incorporates:
      //   Saturate: '<S198>/Saturation'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        Hummingbird_Flight_Controller_P.Gain1_Gain *
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;

      // Saturate: '<S123>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.PIDController2_UpperSaturationL) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.PIDController2_UpperSaturationL;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.PIDController2_LowerSaturationL)
      {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.PIDController2_LowerSaturationL;
      }

      // Sum: '<S14>/Sum2' incorporates:
      //   MATLABSystem: '<S27>/Read Parameter1'
      //   Product: '<S14>/Product'
      //   Saturate: '<S123>/Saturation'
      //
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 +=
        Hummingbird_Flight_Controller_B.ParamStep *
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0;

      // Saturate: '<S14>/Saturation2'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation2_UpperSat) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation2_UpperSat;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation2_LowerSat) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation2_LowerSat;
      }

      // Gain: '<S199>/Gain10' incorporates:
      //   Constant: '<S199>/Constant7'
      //   Saturate: '<S14>/Saturation2'
      //   Sum: '<S199>/Sum8'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 -
         Hummingbird_Flight_Controller_P.Constant7_Value_i) *
        Hummingbird_Flight_Controller_P.Gain10_Gain_n;

      // Saturate: '<S199>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_fz) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_fz;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_b) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_b;
      }

      // Gain: '<S12>/Gain2' incorporates:
      //   Saturate: '<S199>/Saturation'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
        Hummingbird_Flight_Controller_P.Gain2_Gain *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;

      // Gain: '<S200>/Gain10' incorporates:
      //   Constant: '<S200>/Constant7'
      //   Constant: '<S6>/Constant'
      //   Sum: '<S200>/Sum8'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (Hummingbird_Flight_Controller_P.Constant_Value_mf -
         Hummingbird_Flight_Controller_P.Constant7_Value_n) *
        Hummingbird_Flight_Controller_P.Gain10_Gain_a;

      // Saturate: '<S200>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_e) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_e;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_p) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_p;
      }

      // Gain: '<S12>/Gain3' incorporates:
      //   Saturate: '<S200>/Saturation'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 *=
        Hummingbird_Flight_Controller_P.Gain3_Gain;

      // Sum: '<S12>/Sum' incorporates:
      //   BusCreator generated from: '<Root>/Chart'
      //   Gain: '<S12>/Gain4'
      //   Product: '<S12>/Divide'
      //   Trigonometry: '<S12>/Trigonometric Function1'
      //   Trigonometry: '<S12>/Trigonometric Function3'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 =
        Hummingbird_Flight_Controller_P.Gain4_Gain * tan
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0) * cos
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1) /
        Hummingbird_Flight_Controller_B.CastToDouble8 +
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;

      // BusAssignment: '<S194>/Bus Assignment' incorporates:
      //   Constant: '<S12>/Constant2'
      //   DataTypeConversion: '<S12>/Cast To Single7'
      //   DataTypeConversion: '<S12>/Cast To Single8'
      //   DataTypeConversion: '<S12>/Cast To Single9'
      //   MATLABSystem: '<S194>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_fn.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_i.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_fn.roll =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_fn.pitch =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_fn.yaw_rate =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_fn._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant2_Value_pj[0];
      Hummingbird_Flight_Controller_B.BusAssignment_fn._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant2_Value_pj[1];
      Hummingbird_Flight_Controller_B.BusAssignment_fn._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant2_Value_pj[2];
      Hummingbird_Flight_Controller_B.BusAssignment_fn._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant2_Value_pj[3];
      Hummingbird_Fligh_SinkBlock
        (&Hummingbird_Flight_Controller_B.BusAssignment_fn,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_f);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_p);

      // Sum: '<S12>/Sum5' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double3'
      //   DataTypeConversion: '<S5>/Cast To Double4'
      //   DataTypeConversion: '<S5>/Cast To Double5'
      //   MATLABSystem: '<S5>/Coordinate Transformation Conversion1'
      //
      Hummingbird_Flight_Controller_B.DProdOut_n[0] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0;
      Hummingbird_Flight_Controller_B.DProdOut_n[1] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1;
      Hummingbird_Flight_Controller_B.DProdOut_n[2] =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 -
        Hummingbird_Flight_Controller_B.a_n;
      Hummingbird__ReadParameter1
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rg,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rg);
      Hummingbird_F_ReadParameter
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rg,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rg);
      Hummingbir_ReadParameter1_b
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rga,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rga);
      Hummingbird_ReadParameter_b
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rga,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rga);

      // Product: '<S294>/NProd Out' incorporates:
      //   Constant: '<S12>/Constant1'
      //   Constant: '<S201>/Constant'
      //   DiscreteIntegrator: '<S286>/Filter'
      //   Product: '<S284>/DProd Out'
      //   Sum: '<S286>/SumD'

      Hummingbird_Flight_Controller_B.prev_waypoint[0] =
        (Hummingbird_Flight_Controller_B.DProdOut_n[0] *
         Hummingbird_Flight_Controller_B.ReadParameter1_b3rga.ReadParameter1_o1
         - Hummingbird_Flight_Controlle_DW.Filter_DSTATE_js[0]) *
        Hummingbird_Flight_Controller_P.Constant1_Value;
      Hummingbird_Flight_Controller_B.prev_waypoint[1] =
        (Hummingbird_Flight_Controller_B.DProdOut_n[1] *
         Hummingbird_Flight_Controller_B.ReadParameter_b3rga.ReadParameter_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_js[1]) *
        Hummingbird_Flight_Controller_P.Constant1_Value;
      Hummingbird_Flight_Controller_B.prev_waypoint[2] =
        (Hummingbird_Flight_Controller_B.DProdOut_n[2] *
         Hummingbird_Flight_Controller_P.Constant_Value_ic -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_js[2]) *
        Hummingbird_Flight_Controller_P.Constant1_Value;

      // Sum: '<S300>/Sum' incorporates:
      //   Constant: '<S197>/Constant'
      //   Product: '<S296>/PProd Out'

      Hummingbird_Flight_Controller_B.Filter_os[0] =
        Hummingbird_Flight_Controller_B.DProdOut_n[0] *
        Hummingbird_Flight_Controller_B.ReadParameter1_b3rg.ReadParameter1_o1 +
        Hummingbird_Flight_Controller_B.prev_waypoint[0];
      Hummingbird_Flight_Controller_B.Filter_os[1] =
        Hummingbird_Flight_Controller_B.DProdOut_n[1] *
        Hummingbird_Flight_Controller_B.ReadParameter_b3rg.ReadParameter_o1 +
        Hummingbird_Flight_Controller_B.prev_waypoint[1];
      Hummingbird_Flight_Controller_B.Filter_os[2] =
        Hummingbird_Flight_Controller_B.DProdOut_n[2] *
        Hummingbird_Flight_Controller_P.Constant_Value_d +
        Hummingbird_Flight_Controller_B.prev_waypoint[2];

      // MATLAB Function: '<S12>/MATLAB Function'
      Hummingbird__MATLABFunction
        (&Hummingbird_Flight_Controller_B.BusConversion_InsertedFor_Chart,
         &Hummingbird_Flight_Controller_B.Filter_os[0],
         Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0,
         Hummingbird_Flight_Controller_B.DProdOut_n,
         &Hummingbird_Flight_Controller_B.sf_MATLABFunction_n);

      // BusAssignment: '<S195>/Bus Assignment' incorporates:
      //   Constant: '<S12>/Constant3'
      //   DataTypeConversion: '<S12>/Cast To Single1'
      //   DataTypeConversion: '<S12>/Cast To Single2'
      //   DataTypeConversion: '<S12>/Cast To Single6'
      //   MATLABSystem: '<S195>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_p.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_p.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_p.roll_rate = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[0]);
      Hummingbird_Flight_Controller_B.BusAssignment_p.pitch_rate = static_cast<
        real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[1]);
      Hummingbird_Flight_Controller_B.BusAssignment_p.yaw_rate =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[2]);
      Hummingbird_Flight_Controller_B.BusAssignment_p._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant3_Value_n[0];
      Hummingbird_Flight_Controller_B.BusAssignment_p._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant3_Value_n[1];
      Hummingbird_Flight_Controller_B.BusAssignment_p._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant3_Value_n[2];
      Hummingbird_Flight_Controller_B.BusAssignment_p._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant3_Value_n[3];
      Hummingbird_Fli_SinkBlock_h
        (&Hummingbird_Flight_Controller_B.BusAssignment_p,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_h);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_b);

      // Sum: '<S12>/Sum4' incorporates:
      //   DataTypeConversion: '<S5>/Cast To Double7'

      Hummingbird_Flight_Controller_B.Filter_os[0] =
        Hummingbird_Flight_Controller_B.DProdOut_n[0] -
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[0];
      Hummingbird_Flight_Controller_B.Filter_os[1] =
        Hummingbird_Flight_Controller_B.DProdOut_n[1] -
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[1];
      Hummingbird_Flight_Controller_B.Filter_os[2] =
        Hummingbird_Flight_Controller_B.DProdOut_n[2] -
        Hummingbird_Flight_Controller_B.In1_f.gyro_rad[2];
      Hummingbi_ReadParameter1_b3
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgae,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgae);
      Hummingbir_ReadParameter_b3
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgae,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgae);
      Hummingbird__ReadParameter2
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3r,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3r);
      Hummingbir_ReadParameter3_b
        (&Hummingbird_Flight_Controller_B.ReadParameter3_b,
         &Hummingbird_Flight_Controlle_DW.ReadParameter3_b);
      Hummingbir_ReadParameter2_b
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rg,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rg);
      Hummingbird__ReadParameter4
        (&Hummingbird_Flight_Controller_B.ReadParameter4,
         &Hummingbird_Flight_Controlle_DW.ReadParameter4);

      // Product: '<S242>/NProd Out' incorporates:
      //   Constant: '<S12>/Constant4'
      //   DiscreteIntegrator: '<S234>/Filter'
      //   Product: '<S232>/DProd Out'
      //   Sum: '<S234>/SumD'

      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
        (Hummingbird_Flight_Controller_B.Filter_os[0] *
         Hummingbird_Flight_Controller_B.ReadParameter3_b.ReadParameter3_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_o[0]) *
        Hummingbird_Flight_Controller_P.Constant4_Value;
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (Hummingbird_Flight_Controller_B.Filter_os[1] *
         Hummingbird_Flight_Controller_B.ReadParameter2_b3rg.ReadParameter2_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_o[1]) *
        Hummingbird_Flight_Controller_P.Constant4_Value;
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
        (Hummingbird_Flight_Controller_B.Filter_os[2] *
         Hummingbird_Flight_Controller_B.ReadParameter4.ReadParameter4_o1 -
         Hummingbird_Flight_Controlle_DW.Filter_DSTATE_o[2]) *
        Hummingbird_Flight_Controller_P.Constant4_Value;

      // Sum: '<S248>/Sum' incorporates:
      //   Product: '<S244>/PProd Out'

      Hummingbird_Flight_Controller_B.DProdOut_n[0] =
        Hummingbird_Flight_Controller_B.Filter_os[0] *
        Hummingbird_Flight_Controller_B.ReadParameter1_b3rgae.ReadParameter1_o1
        + Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1;
      Hummingbird_Flight_Controller_B.DProdOut_n[1] =
        Hummingbird_Flight_Controller_B.Filter_os[1] *
        Hummingbird_Flight_Controller_B.ReadParameter_b3rgae.ReadParameter_o1 +
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;
      Hummingbird_Flight_Controller_B.DProdOut_n[2] =
        Hummingbird_Flight_Controller_B.Filter_os[2] *
        Hummingbird_Flight_Controller_B.ReadParameter2_b3r.ReadParameter2_o1 +
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;

      // BusAssignment: '<S196>/Bus Assignment' incorporates:
      //   Constant: '<S12>/Constant'
      //   DataTypeConversion: '<S12>/Cast To Single3'
      //   DataTypeConversion: '<S12>/Cast To Single4'
      //   DataTypeConversion: '<S12>/Cast To Single5'
      //   MATLABSystem: '<S196>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_b.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_b.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_b.roll_rate_error =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[0]);
      Hummingbird_Flight_Controller_B.BusAssignment_b.pitch_rate_error =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[1]);
      Hummingbird_Flight_Controller_B.BusAssignment_b.yaw_rate_error =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.DProdOut_n[2]);
      Hummingbird_Flight_Controller_B.BusAssignment_b._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant_Value_e4[0];
      Hummingbird_Flight_Controller_B.BusAssignment_b._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant_Value_e4[1];
      Hummingbird_Flight_Controller_B.BusAssignment_b._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant_Value_e4[2];
      Hummingbird_Flight_Controller_B.BusAssignment_b._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant_Value_e4[3];
      Hummingbird_Fli_SinkBlock_j
        (&Hummingbird_Flight_Controller_B.BusAssignment_b,
         &Hummingbird_Flight_Controlle_DW.SinkBlock_j);

      // Sum: '<S12>/Sum3'
      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_B.DProdOut_n[0];
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 =
        Hummingbird_Flight_Controller_B.DProdOut_n[1];
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 =
        Hummingbird_Flight_Controller_B.DProdOut_n[2];
      Hummingb_ReadParameter1_b3r
        (&Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaen,
         &Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaen);
      Hummingbi_ReadParameter_b3r
        (&Hummingbird_Flight_Controller_B.ReadParameter_b3rgaen,
         &Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaen);
      Hummingbi_ReadParameter2_b3
        (&Hummingbird_Flight_Controller_B.ReadParameter2_b3rga,
         &Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rga);

      // Merge: '<S1>/ Merge 2' incorporates:
      //   BusCreator: '<S5>/Bus Creator6'
      //   Product: '<S348>/PProd Out'
      //   Sum: '<S12>/Sum3'

      Hummingbird_Flight_Controller_B.dM[0] =
        (Hummingbird_Flight_Controller_B.scale -
         Hummingbird_Flight_Controller_B.Sum_e[0]) *
        Hummingbird_Flight_Controller_B.ReadParameter1_b3rgaen.ReadParameter1_o1;
      Hummingbird_Flight_Controller_B.dM[1] =
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 -
         Hummingbird_Flight_Controller_B.Sum_e[1]) *
        Hummingbird_Flight_Controller_B.ReadParameter_b3rgaen.ReadParameter_o1;
      Hummingbird_Flight_Controller_B.dM[2] =
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 -
         Hummingbird_Flight_Controller_B.Sum_e[2]) *
        Hummingbird_Flight_Controller_B.ReadParameter2_b3rga.ReadParameter2_o1;

      // Gain: '<S1168>/Gain5' incorporates:
      //   Constant: '<S6>/Constant11'
      //   Merge: '<S1>/ Merge 1'
      //   SignalConversion generated from: '<S6>/dtMR'

      Hummingbird_Flight_Controller_B.dtMR =
        Hummingbird_Flight_Controller_P.Constant11_Value;

      // Update for DiscreteIntegrator: '<S116>/Integrator'
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_l +=
        Hummingbird_Flight_Controller_P.Integrator_gainval *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2;
      if (Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_l >
          Hummingbird_Flight_Controller_P.PIDController2_UpperIntegratorS) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_l =
          Hummingbird_Flight_Controller_P.PIDController2_UpperIntegratorS;
      } else if (Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_l <
                 Hummingbird_Flight_Controller_P.PIDController2_LowerIntegratorS)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_l =
          Hummingbird_Flight_Controller_P.PIDController2_LowerIntegratorS;
      }

      // Update for DiscreteIntegrator: '<S168>/Integrator' incorporates:
      //   MATLABSystem: '<S29>/Read Parameter1'
      //   Product: '<S165>/IProd Out'
      //
      Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_ld +=
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 *
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2 *
        Hummingbird_Flight_Controller_P.Integrator_gainval_k;
      if (Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_ld >
          Hummingbird_Flight_Controller_P.PIDController3_UpperIntegratorS) {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_ld =
          Hummingbird_Flight_Controller_P.PIDController3_UpperIntegratorS;
      } else if (Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_ld <
                 Hummingbird_Flight_Controller_P.PIDController3_LowerIntegratorS)
      {
        Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_ld =
          Hummingbird_Flight_Controller_P.PIDController3_LowerIntegratorS;
      }

      // Update for DiscreteIntegrator: '<S286>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_js[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval *
        Hummingbird_Flight_Controller_B.prev_waypoint[0];

      // Update for DiscreteIntegrator: '<S234>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_o[0] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_b *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1;

      // Update for DiscreteIntegrator: '<S286>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_js[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval *
        Hummingbird_Flight_Controller_B.prev_waypoint[1];

      // Update for DiscreteIntegrator: '<S234>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_o[1] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_b *
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;

      // Update for DiscreteIntegrator: '<S286>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_js[2] +=
        Hummingbird_Flight_Controller_P.Filter_gainval *
        Hummingbird_Flight_Controller_B.prev_waypoint[2];

      // Update for DiscreteIntegrator: '<S234>/Filter'
      Hummingbird_Flight_Controlle_DW.Filter_DSTATE_o[2] +=
        Hummingbird_Flight_Controller_P.Filter_gainval_b *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0;
      break;
    }
  }

  // End of Chart: '<Root>/Chart'

  // MATLABSystem: '<S1490>/SourceBlock'
  b_varargout_1 = uORB_read_step
    (Hummingbird_Flight_Controlle_DW.obj_im.orbMetadataObj,
     &Hummingbird_Flight_Controlle_DW.obj_im.eventStructObj,
     &Hummingbird_Flight_Controller_B.r4, false, 1.0);

  // Outputs for Enabled SubSystem: '<S1490>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S1563>/Enable'

  // Start for MATLABSystem: '<S1490>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S1563>/In1'
    Hummingbird_Flight_Controller_B.In1_m = Hummingbird_Flight_Controller_B.r4;
  }

  // End of Outputs for SubSystem: '<S1490>/Enabled Subsystem'

  // Math: '<Root>/Square' incorporates:
  //   SignalConversion generated from: '<S2>/ SFunction '

  for (Hummingbird_Flight_Controller_B.i = 0; Hummingbird_Flight_Controller_B.i <
       8; Hummingbird_Flight_Controller_B.i++) {
    Hummingbird_Flight_Controller_B.a_n =
      Hummingbird_Flight_Controller_B.In1_m.positions[Hummingbird_Flight_Controller_B.i
      + 4];
    Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[Hummingbird_Flight_Controller_B.i]
      = Hummingbird_Flight_Controller_B.a_n *
      Hummingbird_Flight_Controller_B.a_n;
  }

  // End of Math: '<Root>/Square'

  // Gain: '<S4>/Gain1'
  Hummingbird_Flight_Controller_B.ParamStep_i =
    Hummingbird_Flight_Controller_P.Gain1_Gain_l *
    Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[2];

  // Gain: '<S4>/Gain2'
  Hummingbird_Flight_Controller_B.Gain6_h =
    Hummingbird_Flight_Controller_P.Gain2_Gain_k *
    Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[3];

  // Gain: '<S4>/Gain3'
  Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0 =
    Hummingbird_Flight_Controller_P.Gain3_Gain_c0 *
    Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[4];

  // Gain: '<S4>/Gain9'
  Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1 =
    Hummingbird_Flight_Controller_P.Gain9_Gain_g *
    Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[5];

  // Gain: '<S4>/Gain10'
  Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2 =
    Hummingbird_Flight_Controller_P.Gain10_Gain_l *
    Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[6];

  // Gain: '<S4>/Gain11'
  Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3 =
    Hummingbird_Flight_Controller_P.Gain11_Gain_c *
    Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[7];

  // Sum: '<S4>/Add' incorporates:
  //   Gain: '<S4>/Gain'
  //   Gain: '<S4>/Gain8'
  //   Sum: '<S4>/Add2'
  //   Sum: '<S4>/Add3'

  Hummingbird_Flight_Controller_B.Add_tmp =
    Hummingbird_Flight_Controller_P.Gain_Gain_dj *
    Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[0] +
    Hummingbird_Flight_Controller_P.Gain8_Gain_d *
    Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[1];
  Hummingbird_Flight_Controller_B.ParamStep =
    (Hummingbird_Flight_Controller_B.Add_tmp +
     Hummingbird_Flight_Controller_B.ParamStep_i) +
    Hummingbird_Flight_Controller_B.Gain6_h;

  // Sum: '<S4>/Add'
  Hummingbird_Flight_Controller_B.a_n =
    (((Hummingbird_Flight_Controller_B.ParamStep +
       Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0) +
      Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1) +
     Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2) +
    Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3;

  // Product: '<S4>/Product1' incorporates:
  //   Constant: '<S4>/Constant2'
  //   Sum: '<S4>/Add3'

  Hummingbird_Flight_Controller_B.ParamStep_i =
    ((((((Hummingbird_Flight_Controller_B.Add_tmp -
          Hummingbird_Flight_Controller_B.ParamStep_i) -
         Hummingbird_Flight_Controller_B.Gain6_h) -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0) -
       Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1) +
      Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2) +
     Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3) *
    Hummingbird_Flight_Controller_P.Constant2_Value_c;

  // Product: '<S4>/Product' incorporates:
  //   Constant: '<S4>/Constant1'
  //   Sum: '<S4>/Add2'

  Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0 =
    ((((Hummingbird_Flight_Controller_B.ParamStep -
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0) -
       Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1) -
      Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_2) -
     Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_3) *
    Hummingbird_Flight_Controller_P.Constant1_Value_h;

  // Sum: '<S4>/Add1' incorporates:
  //   Gain: '<S4>/Gain12'
  //   Gain: '<S4>/Gain13'
  //   Gain: '<S4>/Gain14'
  //   Gain: '<S4>/Gain15'
  //   Gain: '<S4>/Gain4'
  //   Gain: '<S4>/Gain5'
  //   Gain: '<S4>/Gain6'
  //   Gain: '<S4>/Gain7'

  Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1 =
    ((((((Hummingbird_Flight_Controller_P.Gain4_Gain_o *
          Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[0] -
          Hummingbird_Flight_Controller_P.Gain12_Gain_j *
          Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[1]) -
         Hummingbird_Flight_Controller_P.Gain5_Gain_o *
         Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[2]) +
        Hummingbird_Flight_Controller_P.Gain13_Gain_k *
        Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[3]) +
       Hummingbird_Flight_Controller_P.Gain6_Gain_m *
       Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[4]) -
      Hummingbird_Flight_Controller_P.Gain14_Gain_o *
      Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[5]) -
     Hummingbird_Flight_Controller_P.Gain7_Gain_i *
     Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[6]) +
    Hummingbird_Flight_Controller_P.Gain15_Gain_f *
    Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[7];

  // Chart: '<Root>/Chart1'
  Hummingbird_Flight_Controller_B.RC_Flight_Mode_prev_g =
    Hummingbird_Flight_Controlle_DW.RC_Flight_Mode_start;
  Hummingbird_Flight_Controlle_DW.RC_Flight_Mode_start =
    Hummingbird_Flight_Controller_B.BusCreator.Flight_Mode;
  Hummingbird_Flight_Controller_B.RC_VTOL_Mode_prev_i =
    Hummingbird_Flight_Controlle_DW.RC_VTOL_Mode_start;
  Hummingbird_Flight_Controlle_DW.RC_VTOL_Mode_start =
    Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode;
  if (Hummingbird_Flight_Controlle_DW.is_active_c1_Hummingbird_Flight == 0) {
    Hummingbird_Flight_Controlle_DW.RC_Flight_Mode_start =
      Hummingbird_Flight_Controller_B.BusCreator.Flight_Mode;
    Hummingbird_Flight_Controlle_DW.RC_VTOL_Mode_start =
      Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode;
    Hummingbird_Flight_Controlle_DW.is_active_c1_Hummingbird_Flight = 1U;
    Hummingbird_Flight_Controlle_DW.is_Controller =
      Hummingbird_Flight_Con_IN_Start;
    Hummingbird_Flight_Controller_B.Actuator_output.rotor_1 = 0.0F;
    Hummingbird_Flight_Controller_B.Actuator_output.rotor_2 = 0.0F;
    Hummingbird_Flight_Controller_B.Actuator_output.rotor_3 = 0.0F;
    Hummingbird_Flight_Controller_B.Actuator_output.rotor_4 = 0.0F;
    Hummingbird_Flight_Controller_B.Actuator_output.rotor_5 = 0.0F;
    Hummingbird_Flight_Controller_B.Actuator_output.rotor_6 = 0.0F;
    Hummingbird_Flight_Controller_B.Actuator_output.rotor_7 = 0.0F;
    Hummingbird_Flight_Controller_B.Actuator_output.rotor_8 = 0.0F;
    Hummingbird_Flight_Controller_B.Actuator_output.throttle = -1.0F;
    Hummingbird_Flight_Controller_B.Actuator_output.ailerons = 0.0F;
    Hummingbird_Flight_Controller_B.Actuator_output.elevator = 0.0F;
    Hummingbird_Flight_Controller_B.Actuator_output.rudder = 0.0F;
    Hummingbird_Flight_Controller_B.Actuator_output.arm_1 = -1.0F;
    Hummingbird_Flight_Controller_B.Actuator_output.arm_2 = -1.0F;
    Hummingbird_Flight_Controller_B.Actuator_output.arm_3 = -1.0F;
    Hummingbird_Flight_Controller_B.Actuator_output.arm_4 = -1.0F;
  } else if ((Hummingbird_Flight_Controller_B.RC_Flight_Mode_prev_g !=
              Hummingbird_Flight_Controlle_DW.RC_Flight_Mode_start) ||
             (Hummingbird_Flight_Controller_B.RC_VTOL_Mode_prev_i !=
              Hummingbird_Flight_Controlle_DW.RC_VTOL_Mode_start)) {
    if ((Hummingbird_Flight_Controller_B.BusCreator.Flight_Mode < 1200) &&
        (Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode < 1200)) {
      Hummingbird_Flight_Controlle_DW.is_Controller =
        Hummingbird_Flight_IN_FW_Manual;

      // DataTypeConversion: '<S1459>/Cast To Boolean4' incorporates:
      //   Constant: '<S1459>/Constant1'

      for (Hummingbird_Flight_Controller_B.i = 0;
           Hummingbird_Flight_Controller_B.i < 8;
           Hummingbird_Flight_Controller_B.i++) {
        Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[Hummingbird_Flight_Controller_B.i]
          = static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant1_Value_o[Hummingbird_Flight_Controller_B.i]);
      }

      // BusCreator: '<S1459>/Bus Creator'
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_1 =
        Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[0];
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_2 =
        Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[1];
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_3 =
        Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[2];
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_4 =
        Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[3];
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_5 =
        Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[4];
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_6 =
        Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[5];
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_7 =
        Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[6];
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_8 =
        Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[7];

      // If: '<S1477>/If' incorporates:
      //   BusCreator generated from: '<Root>/Chart1'

      if (Hummingbird_Flight_Controller_B.In1_fv.armed) {
        // Gain: '<S1476>/Gain10' incorporates:
        //   Constant: '<S1476>/Constant7'
        //   Sum: '<S1476>/Sum8'

        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          (static_cast<real_T>
           (Hummingbird_Flight_Controller_B.BusCreator.Throttle) -
           Hummingbird_Flight_Controller_P.Constant7_Value_a) *
          Hummingbird_Flight_Controller_P.Gain10_Gain_bn;

        // Saturate: '<S1476>/Saturation'
        if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_lz) {
          // BusCreator: '<S1459>/Bus Creator' incorporates:
          //   DataTypeConversion: '<S1459>/Cast To Boolean5'

          Hummingbird_Flight_Controller_B.Actuator_output.throttle =
            static_cast<real32_T>
            (Hummingbird_Flight_Controller_P.Saturation_UpperSat_lz);
        } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                   Hummingbird_Flight_Controller_P.Saturation_LowerSat_o) {
          // BusCreator: '<S1459>/Bus Creator' incorporates:
          //   DataTypeConversion: '<S1459>/Cast To Boolean5'

          Hummingbird_Flight_Controller_B.Actuator_output.throttle =
            static_cast<real32_T>
            (Hummingbird_Flight_Controller_P.Saturation_LowerSat_o);
        } else {
          // BusCreator: '<S1459>/Bus Creator' incorporates:
          //   DataTypeConversion: '<S1459>/Cast To Boolean5'

          Hummingbird_Flight_Controller_B.Actuator_output.throttle =
            static_cast<real32_T>
            (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);
        }
      } else {
        // BusCreator: '<S1459>/Bus Creator' incorporates:
        //   Constant: '<S1459>/Constant2'
        //   DataTypeConversion: '<S1459>/Cast To Boolean5'

        Hummingbird_Flight_Controller_B.Actuator_output.throttle =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant2_Value_o);
      }

      // Gain: '<S1473>/Gain10' incorporates:
      //   Constant: '<S1473>/Constant7'
      //   Sum: '<S1473>/Sum8'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Roll) -
         Hummingbird_Flight_Controller_P.Constant7_Value_p) *
        Hummingbird_Flight_Controller_P.Gain10_Gain_ap;

      // Saturate: '<S1473>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_dq) {
        // BusCreator: '<S1459>/Bus Creator' incorporates:
        //   DataTypeConversion: '<S1459>/Cast To Boolean2'

        Hummingbird_Flight_Controller_B.Actuator_output.ailerons =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Saturation_UpperSat_dq);
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_du) {
        // BusCreator: '<S1459>/Bus Creator' incorporates:
        //   DataTypeConversion: '<S1459>/Cast To Boolean2'

        Hummingbird_Flight_Controller_B.Actuator_output.ailerons =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Saturation_LowerSat_du);
      } else {
        // BusCreator: '<S1459>/Bus Creator' incorporates:
        //   DataTypeConversion: '<S1459>/Cast To Boolean2'

        Hummingbird_Flight_Controller_B.Actuator_output.ailerons =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);
      }

      // Gain: '<S1474>/Gain10' incorporates:
      //   Constant: '<S1474>/Constant7'
      //   Sum: '<S1474>/Sum8'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Pitch) -
         Hummingbird_Flight_Controller_P.Constant7_Value_kf) *
        Hummingbird_Flight_Controller_P.Gain10_Gain_nx;

      // Saturate: '<S1474>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_i) {
        // BusCreator: '<S1459>/Bus Creator' incorporates:
        //   DataTypeConversion: '<S1459>/Cast To Boolean1'

        Hummingbird_Flight_Controller_B.Actuator_output.elevator =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Saturation_UpperSat_i);
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_bn) {
        // BusCreator: '<S1459>/Bus Creator' incorporates:
        //   DataTypeConversion: '<S1459>/Cast To Boolean1'

        Hummingbird_Flight_Controller_B.Actuator_output.elevator =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Saturation_LowerSat_bn);
      } else {
        // BusCreator: '<S1459>/Bus Creator' incorporates:
        //   DataTypeConversion: '<S1459>/Cast To Boolean1'

        Hummingbird_Flight_Controller_B.Actuator_output.elevator =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);
      }

      // Gain: '<S1475>/Gain10' incorporates:
      //   Constant: '<S1475>/Constant7'
      //   Sum: '<S1475>/Sum8'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Yaw) -
         Hummingbird_Flight_Controller_P.Constant7_Value_l3) *
        Hummingbird_Flight_Controller_P.Gain10_Gain_f;

      // Saturate: '<S1475>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_oe) {
        // BusCreator: '<S1459>/Bus Creator' incorporates:
        //   DataTypeConversion: '<S1459>/Cast To Boolean3'

        Hummingbird_Flight_Controller_B.Actuator_output.rudder =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Saturation_UpperSat_oe);
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_e) {
        // BusCreator: '<S1459>/Bus Creator' incorporates:
        //   DataTypeConversion: '<S1459>/Cast To Boolean3'

        Hummingbird_Flight_Controller_B.Actuator_output.rudder =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Saturation_LowerSat_e);
      } else {
        // BusCreator: '<S1459>/Bus Creator' incorporates:
        //   DataTypeConversion: '<S1459>/Cast To Boolean3'

        Hummingbird_Flight_Controller_B.Actuator_output.rudder =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);
      }

      // BusCreator: '<S1459>/Bus Creator' incorporates:
      //   Constant: '<S1459>/Constant'
      //   DataTypeConversion: '<S1459>/Cast To Boolean6'

      Hummingbird_Flight_Controller_B.Actuator_output.arm_1 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant_Value_ej);
      Hummingbird_Flight_Controller_B.Actuator_output.arm_2 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant_Value_ej);
      Hummingbird_Flight_Controller_B.Actuator_output.arm_3 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant_Value_ej);
      Hummingbird_Flight_Controller_B.Actuator_output.arm_4 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant_Value_ej);
    } else {
      Hummingbird_Flight_Controlle_DW.is_Controller =
        Hummingbird_Fligh_IN_Controlled;
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_j2);

      // Chart: '<S1458>/Chart'
      Hummingbird_Flight_Controller_B.RC_Flight_Mode_prev_g =
        Hummingbird_Flight_Controlle_DW.RC_VTOL_Mode_start_b;
      Hummingbird_Flight_Controlle_DW.RC_VTOL_Mode_start_b =
        Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode;
      Hummingbird_Flight_Controller_B.RC_VTOL_Mode_prev_i =
        Hummingbird_Flight_Controlle_DW.RC_Flight_Mode_start_d;
      Hummingbird_Flight_Controlle_DW.RC_Flight_Mode_start_d =
        Hummingbird_Flight_Controller_B.BusCreator.Flight_Mode;
      if (Hummingbird_Flight_Controlle_DW.is_active_c9_Hummingbird_Flight == 0)
      {
        Hummingbird_Flight_Controlle_DW.RC_VTOL_Mode_start_b =
          Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode;
        Hummingbird_Flight_Controlle_DW.RC_Flight_Mode_start_d =
          Hummingbird_Flight_Controller_B.BusCreator.Flight_Mode;
        Hummingbird_Flight_Controlle_DW.is_active_c9_Hummingbird_Flight = 1U;
        if (Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode < 1200) {
          Hummingbird_Flight_Controlle_DW.is_Mixer_Control =
            Hummingbird_Flight_Contro_IN_FW;
          Hummingbird_Flight_Controller_B.i = 1;
        } else if (Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode < 1700)
        {
          Hummingbird_Flight_Controlle_DW.is_Mixer_Control =
            Hummingbird_Flight_Con_IN_Mixed;
          Hummingbird_Flight_Controller_B.i = 1;
        } else {
          Hummingbird_Flight_Controlle_DW.is_Mixer_Control =
            Hummingbird_Flight_Contro_IN_MR;
          Hummingbird_Flight_Controller_B.i = 0;
        }
      } else if ((Hummingbird_Flight_Controller_B.RC_Flight_Mode_prev_g !=
                  Hummingbird_Flight_Controlle_DW.RC_VTOL_Mode_start_b) ||
                 (Hummingbird_Flight_Controller_B.RC_VTOL_Mode_prev_i !=
                  Hummingbird_Flight_Controlle_DW.RC_Flight_Mode_start_d)) {
        if (Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode < 1200) {
          Hummingbird_Flight_Controlle_DW.is_Mixer_Control =
            Hummingbird_Flight_Contro_IN_FW;
          Hummingbird_Flight_Controller_B.i = 1;
        } else if (Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode < 1700)
        {
          Hummingbird_Flight_Controlle_DW.is_Mixer_Control =
            Hummingbird_Flight_Con_IN_Mixed;
          Hummingbird_Flight_Controller_B.i = 1;
        } else {
          Hummingbird_Flight_Controlle_DW.is_Mixer_Control =
            Hummingbird_Flight_Contro_IN_MR;
          Hummingbird_Flight_Controller_B.i = 0;
        }
      } else {
        switch (Hummingbird_Flight_Controlle_DW.is_Mixer_Control) {
         case Hummingbird_Flight_Contro_IN_FW:
          Hummingbird_Flight_Controller_B.i = 1;
          break;

         case Hummingbird_Flight_Contro_IN_MR:
          Hummingbird_Flight_Controller_B.i = 0;
          break;

         default:
          // case IN_Mixed:
          Hummingbird_Flight_Controller_B.i = 1;
          break;
        }
      }

      // Product: '<S1458>/Product1'
      Hummingbird_Flight_Controller_B.Sum_e[0] =
        Hummingbird_Flight_Controller_B.dM[0] * static_cast<real_T>
        (Hummingbird_Flight_Controller_B.i);
      Hummingbird_Flight_Controller_B.Sum_e[1] =
        Hummingbird_Flight_Controller_B.dM[1] * static_cast<real_T>
        (Hummingbird_Flight_Controller_B.i);
      Hummingbird_Flight_Controller_B.Sum_e[2] =
        Hummingbird_Flight_Controller_B.dM[2] * static_cast<real_T>
        (Hummingbird_Flight_Controller_B.i);

      // Switch: '<S1458>/Switch3' incorporates:
      //   BusCreator generated from: '<Root>/Chart1'
      //   Constant: '<S1458>/Constant29'

      if (!(Hummingbird_Flight_Controller_B.CastToDouble8 >
            Hummingbird_Flight_Controller_P.Switch3_Threshold)) {
        Hummingbird_Flight_Controller_B.CastToDouble8 =
          Hummingbird_Flight_Controller_P.Constant29_Value;
      }

      // MATLAB Function: '<S1458>/Control input Calculation' incorporates:
      //   Constant: '<S1458>/Constant2'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        Hummingbird_Flight_Controller_B.CastToDouble8 *
        Hummingbird_Flight_Controller_B.CastToDouble8;
      for (Hummingbird_Flight_Controller_B.i = 0;
           Hummingbird_Flight_Controller_B.i < 9;
           Hummingbird_Flight_Controller_B.i++) {
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i] =
          b_a[Hummingbird_Flight_Controller_B.i] *
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;
      }

      Hummingbird_Flight_Controller_B.i = 0;
      Hummingbird_Flight_Controller_B.r2_o = 1;
      Hummingbird_Flight_Controller_B.r3_n = 2;
      if (fabs(Hummingbird_Flight_Controller_B.x[2]) >
          Hummingbird_Flight_Controller_B.x[0]) {
        Hummingbird_Flight_Controller_B.i = 2;
        Hummingbird_Flight_Controller_B.r3_n = 0;
      }

      Hummingbird_Flight_Controller_B.x[1] /=
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];
      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n] /=
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];
      Hummingbird_Flight_Controller_B.x[4] -=
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i + 3]
        * Hummingbird_Flight_Controller_B.x[1];
      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n + 3]
        -= Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
        3] *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n];
      Hummingbird_Flight_Controller_B.x[7] -=
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i + 6]
        * Hummingbird_Flight_Controller_B.x[1];
      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n + 6]
        -= Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
        6] *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n];
      if (fabs
          (Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n
           + 3]) > fabs(Hummingbird_Flight_Controller_B.x[4])) {
        Hummingbird_Flight_Controller_B.r2_o =
          Hummingbird_Flight_Controller_B.r3_n;
        Hummingbird_Flight_Controller_B.r3_n = 1;
      }

      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n + 3]
        /=
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o +
        3];
      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n + 6]
        -=
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n +
        3] *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o +
        6];
      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.i];
      Hummingbird_Flight_Controller_B.Esp_dot =
        Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.r2_o]
        - Hummingbird_Flight_Controller_B.scale *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
      Hummingbird_Flight_Controller_B.V =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n +
        3];
      Hummingbird_Flight_Controller_B.IntegralGain_k =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n +
        6];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        ((Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.r3_n]
          - Hummingbird_Flight_Controller_B.scale *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n])
         - Hummingbird_Flight_Controller_B.V *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.IntegralGain_k;
      Hummingbird_Flight_Controller_B.a[2] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
      Hummingbird_Flight_Controller_B.CastToDouble25_f =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o +
        6];
      Hummingbird_Flight_Controller_B.course =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o +
        3];
      Hummingbird_Flight_Controller_B.Esp_dot =
        (Hummingbird_Flight_Controller_B.Esp_dot -
         Hummingbird_Flight_Controller_B.CastToDouble25_f *
         Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) /
        Hummingbird_Flight_Controller_B.course;
      Hummingbird_Flight_Controller_B.a[1] =
        Hummingbird_Flight_Controller_B.Esp_dot;
      Hummingbird_Flight_Controller_B.t =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i + 6];
      Hummingbird_Flight_Controller_B.CastToDouble25 =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i + 3];
      Hummingbird_Flight_Controller_B.a[0] =
        ((Hummingbird_Flight_Controller_B.scale -
          Hummingbird_Flight_Controller_B.t *
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) -
         Hummingbird_Flight_Controller_B.CastToDouble25 *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 = 0.0;
      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.i
        + 3];
      Hummingbird_Flight_Controller_B.Esp_dot =
        Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.r2_o
        + 3] - Hummingbird_Flight_Controller_B.scale *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        ((Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.r3_n
          + 3] - Hummingbird_Flight_Controller_B.scale *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n])
         - Hummingbird_Flight_Controller_B.V *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.IntegralGain_k;
      Hummingbird_Flight_Controller_B.a[5] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
      Hummingbird_Flight_Controller_B.Esp_dot =
        (Hummingbird_Flight_Controller_B.Esp_dot -
         Hummingbird_Flight_Controller_B.CastToDouble25_f *
         Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) /
        Hummingbird_Flight_Controller_B.course;
      Hummingbird_Flight_Controller_B.a[4] =
        Hummingbird_Flight_Controller_B.Esp_dot;
      Hummingbird_Flight_Controller_B.a[3] =
        ((Hummingbird_Flight_Controller_B.scale -
          Hummingbird_Flight_Controller_B.t *
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) -
         Hummingbird_Flight_Controller_B.CastToDouble25 *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 = 0.0;
      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.i
        + 6];
      Hummingbird_Flight_Controller_B.Esp_dot =
        Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.r2_o
        + 6] - Hummingbird_Flight_Controller_B.scale *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        ((Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.r3_n
          + 6] - Hummingbird_Flight_Controller_B.scale *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n])
         - Hummingbird_Flight_Controller_B.V *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.IntegralGain_k;
      Hummingbird_Flight_Controller_B.a[8] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
      Hummingbird_Flight_Controller_B.Esp_dot =
        (Hummingbird_Flight_Controller_B.Esp_dot -
         Hummingbird_Flight_Controller_B.CastToDouble25_f *
         Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) /
        Hummingbird_Flight_Controller_B.course;
      Hummingbird_Flight_Controller_B.a[7] =
        Hummingbird_Flight_Controller_B.Esp_dot;
      Hummingbird_Flight_Controller_B.a[6] =
        ((Hummingbird_Flight_Controller_B.scale -
          Hummingbird_Flight_Controller_B.t *
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) -
         Hummingbird_Flight_Controller_B.CastToDouble25 *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 = 0.0;
      for (Hummingbird_Flight_Controller_B.i = 0;
           Hummingbird_Flight_Controller_B.i < 3;
           Hummingbird_Flight_Controller_B.i++) {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.Sum_e[Hummingbird_Flight_Controller_B.i];
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 +=
          Hummingbird_Flight_Controller_B.a[3 *
          Hummingbird_Flight_Controller_B.i] *
          Hummingbird_Flight_Controller_B.scale;
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 +=
          Hummingbird_Flight_Controller_B.a[3 *
          Hummingbird_Flight_Controller_B.i + 1] *
          Hummingbird_Flight_Controller_B.scale;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 +=
          Hummingbird_Flight_Controller_B.a[3 *
          Hummingbird_Flight_Controller_B.i + 2] *
          Hummingbird_Flight_Controller_B.scale;
      }

      // Switch: '<S1458>/Switch' incorporates:
      //   Constant: '<S1458>/Constant7'
      //   RelationalOperator: '<S1458>/IsNaN'

      if (rtIsNaN(Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0)) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Constant7_Value_k;
      }

      // Switch: '<S1458>/Switch4' incorporates:
      //   Constant: '<S1458>/Constant4'
      //   RelationalOperator: '<S1458>/IsNaN3'

      if (rtIsNaN(Hummingbird_Flight_Controller_B.dtFW)) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_P.Constant4_Value_g;
      } else {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_B.dtFW;
      }

      // Switch: '<S1458>/Switch1' incorporates:
      //   Constant: '<S1458>/Constant8'
      //   RelationalOperator: '<S1458>/IsNaN1'

      if (rtIsNaN(Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1))
      {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          Hummingbird_Flight_Controller_P.Constant8_Value;
      }

      // Switch: '<S1458>/Switch2' incorporates:
      //   Constant: '<S1458>/Constant9'
      //   RelationalOperator: '<S1458>/IsNaN2'

      if (rtIsNaN(Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0))
      {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
          Hummingbird_Flight_Controller_P.Constant9_Value;
      }

      // BusAssignment: '<S1464>/Bus Assignment' incorporates:
      //   DataTypeConversion: '<S1458>/Cast To Boolean1'
      //   MATLABSystem: '<S1464>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_c.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_j2.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_c.de = static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_c.dt = static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_c.da = static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_c.dr = static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);

      // MATLABSystem: '<S1470>/SinkBlock' incorporates:
      //   BusAssignment: '<S1464>/Bus Assignment'

      uORB_write_step(Hummingbird_Flight_Controlle_DW.obj_c.orbMetadataObj,
                      &Hummingbird_Flight_Controlle_DW.obj_c.orbAdvertiseObj,
                      &Hummingbird_Flight_Controller_B.BusAssignment_c);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_pm);

      // Sum: '<S1460>/Sum17'
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
        Hummingbird_Flight_Controller_B.dtMR +
        Hummingbird_Flight_Controller_B.a_n;

      // Saturate: '<S1460>/Saturation3'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 >
          Hummingbird_Flight_Controller_P.Saturation3_UpperSat) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
          Hummingbird_Flight_Controller_P.Saturation3_UpperSat;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 <
                 Hummingbird_Flight_Controller_P.Saturation3_LowerSat) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
          Hummingbird_Flight_Controller_P.Saturation3_LowerSat;
      }

      // Gain: '<S1468>/Gain' incorporates:
      //   Constant: '<S1468>/Constant'
      //   Product: '<S1468>/Divide'

      Hummingbird_Flight_Controller_B.CastToDouble8 =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 /
        Hummingbird_Flight_Controller_P.Constant_Value_li *
        Hummingbird_Flight_Controller_P.Gain_Gain_b;

      // MATLAB Function: '<S1458>/Control input Calculation1' incorporates:
      //   Constant: '<S1458>/Constant12'
      //   Constant: '<S1458>/Constant13'

      memcpy(&Hummingbird_Flight_Controller_B.x[0],
             &Hummingbird_Flight_Controller_P.Constant12_Value[0], 9U * sizeof
             (real_T));
      Hummingbird_Flight_Controller_B.i = 0;
      Hummingbird_Flight_Controller_B.r2_o = 1;
      Hummingbird_Flight_Controller_B.r3_n = 2;
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 = fabs
        (Hummingbird_Flight_Controller_P.Constant12_Value[0]);
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 = fabs
        (Hummingbird_Flight_Controller_P.Constant12_Value[1]);
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0) {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 =
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
        Hummingbird_Flight_Controller_B.i = 1;
        Hummingbird_Flight_Controller_B.r2_o = 0;
      }

      if (fabs(Hummingbird_Flight_Controller_P.Constant12_Value[2]) >
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0) {
        Hummingbird_Flight_Controller_B.i = 2;
        Hummingbird_Flight_Controller_B.r2_o = 1;
        Hummingbird_Flight_Controller_B.r3_n = 0;
      }

      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o] =
        Hummingbird_Flight_Controller_P.Constant12_Value[Hummingbird_Flight_Controller_B.r2_o]
        /
        Hummingbird_Flight_Controller_P.Constant12_Value[Hummingbird_Flight_Controller_B.i];
      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n] /=
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];
      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o + 3]
        -= Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
        3] *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n + 3]
        -= Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
        3] *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n];
      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o + 6]
        -= Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
        6] *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n + 6]
        -= Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
        6] *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n];
      if (fabs
          (Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n
           + 3]) > fabs
          (Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o
           + 3])) {
        Hummingbird_Flight_Controller_B.rtemp =
          Hummingbird_Flight_Controller_B.r2_o;
        Hummingbird_Flight_Controller_B.r2_o =
          Hummingbird_Flight_Controller_B.r3_n;
        Hummingbird_Flight_Controller_B.r3_n =
          Hummingbird_Flight_Controller_B.rtemp;
      }

      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n + 3]
        /=
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o +
        3];
      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n + 6]
        -=
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n +
        3] *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o +
        6];
      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.i];
      Hummingbird_Flight_Controller_B.Esp_dot =
        Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.r2_o]
        - Hummingbird_Flight_Controller_B.scale *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
      Hummingbird_Flight_Controller_B.V =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n +
        3];
      Hummingbird_Flight_Controller_B.IntegralGain_k =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n +
        6];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        ((Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.r3_n]
          - Hummingbird_Flight_Controller_B.scale *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n])
         - Hummingbird_Flight_Controller_B.V *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.IntegralGain_k;
      Hummingbird_Flight_Controller_B.a_m[2] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
      Hummingbird_Flight_Controller_B.CastToDouble25_f =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o +
        6];
      Hummingbird_Flight_Controller_B.course =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o +
        3];
      Hummingbird_Flight_Controller_B.Esp_dot =
        (Hummingbird_Flight_Controller_B.Esp_dot -
         Hummingbird_Flight_Controller_B.CastToDouble25_f *
         Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) /
        Hummingbird_Flight_Controller_B.course;
      Hummingbird_Flight_Controller_B.a_m[1] =
        Hummingbird_Flight_Controller_B.Esp_dot;
      Hummingbird_Flight_Controller_B.t =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i + 6];
      Hummingbird_Flight_Controller_B.CastToDouble25 =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i + 3];
      Hummingbird_Flight_Controller_B.a_m[0] =
        ((Hummingbird_Flight_Controller_B.scale -
          Hummingbird_Flight_Controller_B.t *
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) -
         Hummingbird_Flight_Controller_B.CastToDouble25 *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];

      // Sum: '<S1458>/Sum8'
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[0] =
        Hummingbird_Flight_Controller_B.dM[0] -
        Hummingbird_Flight_Controller_B.Sum_e[0];

      // MATLAB Function: '<S1458>/Control input Calculation1' incorporates:
      //   Constant: '<S1458>/Constant13'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 = 0.0;
      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.i + 3];
      Hummingbird_Flight_Controller_B.Esp_dot =
        Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.r2_o
        + 3] - Hummingbird_Flight_Controller_B.scale *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        ((Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.r3_n
          + 3] - Hummingbird_Flight_Controller_B.scale *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n])
         - Hummingbird_Flight_Controller_B.V *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.IntegralGain_k;
      Hummingbird_Flight_Controller_B.a_m[5] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
      Hummingbird_Flight_Controller_B.Esp_dot =
        (Hummingbird_Flight_Controller_B.Esp_dot -
         Hummingbird_Flight_Controller_B.CastToDouble25_f *
         Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) /
        Hummingbird_Flight_Controller_B.course;
      Hummingbird_Flight_Controller_B.a_m[4] =
        Hummingbird_Flight_Controller_B.Esp_dot;
      Hummingbird_Flight_Controller_B.a_m[3] =
        ((Hummingbird_Flight_Controller_B.scale -
          Hummingbird_Flight_Controller_B.t *
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) -
         Hummingbird_Flight_Controller_B.CastToDouble25 *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];

      // Sum: '<S1458>/Sum8'
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[1] =
        Hummingbird_Flight_Controller_B.dM[1] -
        Hummingbird_Flight_Controller_B.Sum_e[1];

      // MATLAB Function: '<S1458>/Control input Calculation1' incorporates:
      //   Constant: '<S1458>/Constant13'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 = 0.0;
      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.i + 6];
      Hummingbird_Flight_Controller_B.Esp_dot =
        Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.r2_o
        + 6] - Hummingbird_Flight_Controller_B.scale *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        ((Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.r3_n
          + 6] - Hummingbird_Flight_Controller_B.scale *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n])
         - Hummingbird_Flight_Controller_B.V *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.IntegralGain_k;
      Hummingbird_Flight_Controller_B.a_m[8] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
      Hummingbird_Flight_Controller_B.Esp_dot =
        (Hummingbird_Flight_Controller_B.Esp_dot -
         Hummingbird_Flight_Controller_B.CastToDouble25_f *
         Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) /
        Hummingbird_Flight_Controller_B.course;
      Hummingbird_Flight_Controller_B.a_m[7] =
        Hummingbird_Flight_Controller_B.Esp_dot;
      Hummingbird_Flight_Controller_B.a_m[6] =
        ((Hummingbird_Flight_Controller_B.scale -
          Hummingbird_Flight_Controller_B.t *
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) -
         Hummingbird_Flight_Controller_B.CastToDouble25 *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];

      // Sum: '<S1458>/Sum8'
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[2] =
        Hummingbird_Flight_Controller_B.dM[2] -
        Hummingbird_Flight_Controller_B.Sum_e[2];

      // MATLAB Function: '<S1458>/Control input Calculation1'
      Hummingbird_Flight_Controller_B.b_t = 0.0;
      for (Hummingbird_Flight_Controller_B.i = 0;
           Hummingbird_Flight_Controller_B.i < 3;
           Hummingbird_Flight_Controller_B.i++) {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[Hummingbird_Flight_Controller_B.i];
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 +=
          Hummingbird_Flight_Controller_B.a_m[3 *
          Hummingbird_Flight_Controller_B.i] *
          Hummingbird_Flight_Controller_B.scale;
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 +=
          Hummingbird_Flight_Controller_B.a_m[3 *
          Hummingbird_Flight_Controller_B.i + 1] *
          Hummingbird_Flight_Controller_B.scale;
        Hummingbird_Flight_Controller_B.b_t +=
          Hummingbird_Flight_Controller_B.a_m[3 *
          Hummingbird_Flight_Controller_B.i + 2] *
          Hummingbird_Flight_Controller_B.scale;
      }

      // Sum: '<S1460>/Sum10' incorporates:
      //   MATLAB Function: '<S1458>/Control input Calculation1'

      Hummingbird_Flight_Controller_B.Sum_e[0] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 +
        Hummingbird_Flight_Controller_B.ParamStep_i;
      Hummingbird_Flight_Controller_B.Sum_e[1] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 +
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0;
      Hummingbird_Flight_Controller_B.Sum_e[2] =
        Hummingbird_Flight_Controller_B.b_t +
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1;

      // Saturate: '<S1468>/Saturation9'
      if (Hummingbird_Flight_Controller_B.Sum_e[0] >
          Hummingbird_Flight_Controller_P.Saturation9_UpperSat) {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_P.Saturation9_UpperSat;
      } else if (Hummingbird_Flight_Controller_B.Sum_e[0] <
                 Hummingbird_Flight_Controller_P.Saturation9_LowerSat) {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_P.Saturation9_LowerSat;
      } else {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.Sum_e[0];
      }

      // Product: '<S1468>/Divide3' incorporates:
      //   Constant: '<S1468>/Constant2'
      //   Saturate: '<S1468>/Saturation9'

      Hummingbird_Flight_Controller_B.CastToDouble25 =
        Hummingbird_Flight_Controller_B.scale /
        Hummingbird_Flight_Controller_P.Constant2_Value_a;

      // Saturate: '<S1468>/Saturation8'
      if (Hummingbird_Flight_Controller_B.Sum_e[1] >
          Hummingbird_Flight_Controller_P.Saturation8_UpperSat) {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_P.Saturation8_UpperSat;
      } else if (Hummingbird_Flight_Controller_B.Sum_e[1] <
                 Hummingbird_Flight_Controller_P.Saturation8_LowerSat) {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_P.Saturation8_LowerSat;
      } else {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.Sum_e[1];
      }

      // Product: '<S1468>/Divide2' incorporates:
      //   Constant: '<S1468>/Constant1'
      //   Saturate: '<S1468>/Saturation8'

      Hummingbird_Flight_Controller_B.t = Hummingbird_Flight_Controller_B.scale /
        Hummingbird_Flight_Controller_P.Constant1_Value_p;

      // Saturate: '<S1468>/Saturation10'
      if (Hummingbird_Flight_Controller_B.Sum_e[2] >
          Hummingbird_Flight_Controller_P.Saturation10_UpperSat) {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_P.Saturation10_UpperSat;
      } else if (Hummingbird_Flight_Controller_B.Sum_e[2] <
                 Hummingbird_Flight_Controller_P.Saturation10_LowerSat) {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_P.Saturation10_LowerSat;
      } else {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.Sum_e[2];
      }

      // Product: '<S1468>/Divide1' incorporates:
      //   Constant: '<S1468>/Constant3'
      //   Saturate: '<S1468>/Saturation10'

      Hummingbird_Flight_Controller_B.scale /=
        Hummingbird_Flight_Controller_P.Constant3_Value_k;

      // Sum: '<S1468>/Add'
      Hummingbird_Flight_Controller_B.Esp_dot =
        ((Hummingbird_Flight_Controller_B.scale -
          Hummingbird_Flight_Controller_B.CastToDouble8) -
         Hummingbird_Flight_Controller_B.CastToDouble25) -
        Hummingbird_Flight_Controller_B.t;

      // Saturate: '<S1468>/Saturation'
      if (Hummingbird_Flight_Controller_B.Esp_dot >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_o) {
        Hummingbird_Flight_Controller_B.Esp_dot =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_o;
      } else if (Hummingbird_Flight_Controller_B.Esp_dot <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_n) {
        Hummingbird_Flight_Controller_B.Esp_dot =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_n;
      }

      // Sum: '<S1468>/Add4'
      Hummingbird_Flight_Controller_B.V = (((0.0 -
        Hummingbird_Flight_Controller_B.CastToDouble8) -
        Hummingbird_Flight_Controller_B.CastToDouble25) -
        Hummingbird_Flight_Controller_B.t) -
        Hummingbird_Flight_Controller_B.scale;

      // Saturate: '<S1468>/Saturation4'
      if (Hummingbird_Flight_Controller_B.V >
          Hummingbird_Flight_Controller_P.Saturation4_UpperSat) {
        Hummingbird_Flight_Controller_B.V =
          Hummingbird_Flight_Controller_P.Saturation4_UpperSat;
      } else if (Hummingbird_Flight_Controller_B.V <
                 Hummingbird_Flight_Controller_P.Saturation4_LowerSat) {
        Hummingbird_Flight_Controller_B.V =
          Hummingbird_Flight_Controller_P.Saturation4_LowerSat;
      }

      // Sum: '<S1468>/Add1' incorporates:
      //   Sum: '<S1468>/Add2'
      //   Sum: '<S1468>/Add5'

      Hummingbird_Flight_Controller_B.CastToDouble25_f =
        Hummingbird_Flight_Controller_B.CastToDouble25 -
        Hummingbird_Flight_Controller_B.CastToDouble8;
      Hummingbird_Flight_Controller_B.r_c =
        Hummingbird_Flight_Controller_B.CastToDouble25_f -
        Hummingbird_Flight_Controller_B.t;
      Hummingbird_Flight_Controller_B.IntegralGain_k =
        Hummingbird_Flight_Controller_B.r_c -
        Hummingbird_Flight_Controller_B.scale;

      // Saturate: '<S1468>/Saturation1'
      if (Hummingbird_Flight_Controller_B.IntegralGain_k >
          Hummingbird_Flight_Controller_P.Saturation1_UpperSat_e) {
        Hummingbird_Flight_Controller_B.IntegralGain_k =
          Hummingbird_Flight_Controller_P.Saturation1_UpperSat_e;
      } else if (Hummingbird_Flight_Controller_B.IntegralGain_k <
                 Hummingbird_Flight_Controller_P.Saturation1_LowerSat_b) {
        Hummingbird_Flight_Controller_B.IntegralGain_k =
          Hummingbird_Flight_Controller_P.Saturation1_LowerSat_b;
      }

      // Sum: '<S1468>/Add5'
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        Hummingbird_Flight_Controller_B.r_c +
        Hummingbird_Flight_Controller_B.scale;

      // Saturate: '<S1468>/Saturation5'
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 >
          Hummingbird_Flight_Controller_P.Saturation5_UpperSat) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_P.Saturation5_UpperSat;
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 <
                 Hummingbird_Flight_Controller_P.Saturation5_LowerSat) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_P.Saturation5_LowerSat;
      }

      // Sum: '<S1468>/Add2' incorporates:
      //   Sum: '<S1468>/Add6'

      Hummingbird_Flight_Controller_B.r_c =
        Hummingbird_Flight_Controller_B.CastToDouble25_f +
        Hummingbird_Flight_Controller_B.t;
      Hummingbird_Flight_Controller_B.CastToDouble25_f =
        Hummingbird_Flight_Controller_B.r_c +
        Hummingbird_Flight_Controller_B.scale;

      // Saturate: '<S1468>/Saturation2'
      if (Hummingbird_Flight_Controller_B.CastToDouble25_f >
          Hummingbird_Flight_Controller_P.Saturation2_UpperSat_o) {
        Hummingbird_Flight_Controller_B.CastToDouble25_f =
          Hummingbird_Flight_Controller_P.Saturation2_UpperSat_o;
      } else if (Hummingbird_Flight_Controller_B.CastToDouble25_f <
                 Hummingbird_Flight_Controller_P.Saturation2_LowerSat_g) {
        Hummingbird_Flight_Controller_B.CastToDouble25_f =
          Hummingbird_Flight_Controller_P.Saturation2_LowerSat_g;
      }

      // Sum: '<S1468>/Add6'
      Hummingbird_Flight_Controller_B.course =
        Hummingbird_Flight_Controller_B.r_c -
        Hummingbird_Flight_Controller_B.scale;

      // Saturate: '<S1468>/Saturation6'
      if (Hummingbird_Flight_Controller_B.course >
          Hummingbird_Flight_Controller_P.Saturation6_UpperSat) {
        Hummingbird_Flight_Controller_B.course =
          Hummingbird_Flight_Controller_P.Saturation6_UpperSat;
      } else if (Hummingbird_Flight_Controller_B.course <
                 Hummingbird_Flight_Controller_P.Saturation6_LowerSat) {
        Hummingbird_Flight_Controller_B.course =
          Hummingbird_Flight_Controller_P.Saturation6_LowerSat;
      }

      // Sum: '<S1468>/Add3' incorporates:
      //   Sum: '<S1468>/Add7'

      Hummingbird_Flight_Controller_B.r_c = (Hummingbird_Flight_Controller_B.t -
        Hummingbird_Flight_Controller_B.CastToDouble8) -
        Hummingbird_Flight_Controller_B.CastToDouble25;
      Hummingbird_Flight_Controller_B.t = Hummingbird_Flight_Controller_B.r_c -
        Hummingbird_Flight_Controller_B.scale;

      // Saturate: '<S1468>/Saturation3'
      if (Hummingbird_Flight_Controller_B.t >
          Hummingbird_Flight_Controller_P.Saturation3_UpperSat_a) {
        Hummingbird_Flight_Controller_B.t =
          Hummingbird_Flight_Controller_P.Saturation3_UpperSat_a;
      } else if (Hummingbird_Flight_Controller_B.t <
                 Hummingbird_Flight_Controller_P.Saturation3_LowerSat_o) {
        Hummingbird_Flight_Controller_B.t =
          Hummingbird_Flight_Controller_P.Saturation3_LowerSat_o;
      }

      // Sum: '<S1468>/Add7'
      Hummingbird_Flight_Controller_B.CastToDouble8 =
        Hummingbird_Flight_Controller_B.r_c +
        Hummingbird_Flight_Controller_B.scale;

      // Saturate: '<S1468>/Saturation7'
      if (Hummingbird_Flight_Controller_B.CastToDouble8 >
          Hummingbird_Flight_Controller_P.Saturation7_UpperSat) {
        Hummingbird_Flight_Controller_B.CastToDouble8 =
          Hummingbird_Flight_Controller_P.Saturation7_UpperSat;
      } else if (Hummingbird_Flight_Controller_B.CastToDouble8 <
                 Hummingbird_Flight_Controller_P.Saturation7_LowerSat) {
        Hummingbird_Flight_Controller_B.CastToDouble8 =
          Hummingbird_Flight_Controller_P.Saturation7_LowerSat;
      }

      // Gain: '<S1467>/Gain1'
      Hummingbird_Flight_Controller_B.CastToDouble25 =
        Hummingbird_Flight_Controller_P.Gain1_Gain_hu *
        Hummingbird_Flight_Controller_B.IntegralGain_k;

      // Gain: '<S1467>/Gain2'
      Hummingbird_Flight_Controller_B.r_c =
        Hummingbird_Flight_Controller_P.Gain2_Gain_p *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;

      // Gain: '<S1467>/Gain3'
      Hummingbird_Flight_Controller_B.absxk =
        Hummingbird_Flight_Controller_P.Gain3_Gain_h *
        Hummingbird_Flight_Controller_B.CastToDouble25_f;

      // Gain: '<S1467>/Gain9'
      Hummingbird_Flight_Controller_B.b_gamma =
        Hummingbird_Flight_Controller_P.Gain9_Gain *
        Hummingbird_Flight_Controller_B.course;

      // Gain: '<S1467>/Gain10'
      Hummingbird_Flight_Controller_B.eta =
        Hummingbird_Flight_Controller_P.Gain10_Gain_b *
        Hummingbird_Flight_Controller_B.t;

      // Gain: '<S1467>/Gain11'
      Hummingbird_Flight_Controller_B.Add1 =
        Hummingbird_Flight_Controller_P.Gain11_Gain *
        Hummingbird_Flight_Controller_B.CastToDouble8;

      // BusAssignment: '<S1465>/Bus Assignment' incorporates:
      //   BusCreator: '<S5>/Bus Creator4'
      //   Constant: '<S1458>/Constant14'
      //   DataTypeConversion: '<S1458>/Cast To Boolean4'
      //   DataTypeConversion: '<S1458>/Cast To Boolean5'
      //   MATLAB Function: '<S1458>/Control input Calculation1'
      //   MATLABSystem: '<S1465>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_pm.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment.data[0] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.Esp_dot);
      Hummingbird_Flight_Controller_B.BusAssignment.data[1] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.V);
      Hummingbird_Flight_Controller_B.BusAssignment.data[2] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.IntegralGain_k);
      Hummingbird_Flight_Controller_B.BusAssignment.data[3] =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment.data[4] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.CastToDouble25_f);
      Hummingbird_Flight_Controller_B.BusAssignment.data[5] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.course);
      Hummingbird_Flight_Controller_B.BusAssignment.data[6] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.t);
      Hummingbird_Flight_Controller_B.BusAssignment.data[7] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.CastToDouble8);
      Hummingbird_Flight_Controller_B.BusAssignment.data[8] =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment.data[12] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.dtMR);
      Hummingbird_Flight_Controller_B.BusAssignment.data[9] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.Sum_e[0]);
      Hummingbird_Flight_Controller_B.BusAssignment.data[13] =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment.data[10] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.Sum_e[1]);
      Hummingbird_Flight_Controller_B.BusAssignment.data[14] =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment.data[11] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.Sum_e[2]);
      Hummingbird_Flight_Controller_B.BusAssignment.data[15] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.b_t);
      Hummingbird_Flight_Controller_B.BusAssignment.data[16] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[17] =
        Hummingbird_Flight_Controller_B.a_n;
      Hummingbird_Flight_Controller_B.BusAssignment.data[18] =
        Hummingbird_Flight_Controller_B.ParamStep_i;
      Hummingbird_Flight_Controller_B.BusAssignment.data[19] =
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0;
      Hummingbird_Flight_Controller_B.BusAssignment.data[20] =
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1;
      Hummingbird_Flight_Controller_B.BusAssignment.data[21] =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2);

      // Sum: '<S1467>/Add' incorporates:
      //   Gain: '<S1467>/Gain'
      //   Gain: '<S1467>/Gain8'
      //   Sum: '<S1467>/Add2'
      //   Sum: '<S1467>/Add3'

      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_P.Gain_Gain_l *
        Hummingbird_Flight_Controller_B.Esp_dot +
        Hummingbird_Flight_Controller_P.Gain8_Gain *
        Hummingbird_Flight_Controller_B.V;
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 =
        (Hummingbird_Flight_Controller_B.scale +
         Hummingbird_Flight_Controller_B.CastToDouble25) +
        Hummingbird_Flight_Controller_B.r_c;

      // BusAssignment: '<S1465>/Bus Assignment' incorporates:
      //   Constant: '<S1458>/Constant1'
      //   Constant: '<S1458>/Constant10'
      //   Constant: '<S1458>/Constant14'
      //   Constant: '<S1458>/Constant15'
      //   Constant: '<S1467>/Constant1'
      //   Constant: '<S1467>/Constant2'
      //   DataTypeConversion: '<S1458>/Cast To Boolean4'
      //   Gain: '<S1467>/Gain12'
      //   Gain: '<S1467>/Gain13'
      //   Gain: '<S1467>/Gain14'
      //   Gain: '<S1467>/Gain15'
      //   Gain: '<S1467>/Gain4'
      //   Gain: '<S1467>/Gain5'
      //   Gain: '<S1467>/Gain6'
      //   Gain: '<S1467>/Gain7'
      //   Product: '<S1467>/Product'
      //   Product: '<S1467>/Product1'
      //   Sum: '<S1467>/Add'
      //   Sum: '<S1467>/Add1'
      //   Sum: '<S1467>/Add2'
      //   Sum: '<S1467>/Add3'

      Hummingbird_Flight_Controller_B.BusAssignment.data[22] =
        static_cast<real32_T>
        ((((Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 +
            Hummingbird_Flight_Controller_B.absxk) +
           Hummingbird_Flight_Controller_B.b_gamma) +
          Hummingbird_Flight_Controller_B.eta) +
         Hummingbird_Flight_Controller_B.Add1);
      Hummingbird_Flight_Controller_B.BusAssignment.data[23] =
        static_cast<real32_T>(((((((Hummingbird_Flight_Controller_B.scale -
        Hummingbird_Flight_Controller_B.CastToDouble25) -
        Hummingbird_Flight_Controller_B.r_c) -
        Hummingbird_Flight_Controller_B.absxk) -
        Hummingbird_Flight_Controller_B.b_gamma) +
        Hummingbird_Flight_Controller_B.eta) +
        Hummingbird_Flight_Controller_B.Add1) *
        Hummingbird_Flight_Controller_P.Constant2_Value_i);
      Hummingbird_Flight_Controller_B.BusAssignment.data[24] =
        static_cast<real32_T>
        (((((Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 -
             Hummingbird_Flight_Controller_B.absxk) -
            Hummingbird_Flight_Controller_B.b_gamma) -
           Hummingbird_Flight_Controller_B.eta) -
          Hummingbird_Flight_Controller_B.Add1) *
         Hummingbird_Flight_Controller_P.Constant1_Value_n);
      Hummingbird_Flight_Controller_B.BusAssignment.data[25] =
        static_cast<real32_T>(((((((Hummingbird_Flight_Controller_P.Gain4_Gain_k
        * Hummingbird_Flight_Controller_B.Esp_dot -
        Hummingbird_Flight_Controller_P.Gain12_Gain *
        Hummingbird_Flight_Controller_B.V) -
        Hummingbird_Flight_Controller_P.Gain5_Gain *
        Hummingbird_Flight_Controller_B.IntegralGain_k) +
        Hummingbird_Flight_Controller_P.Gain13_Gain *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) +
        Hummingbird_Flight_Controller_P.Gain6_Gain *
        Hummingbird_Flight_Controller_B.CastToDouble25_f) -
        Hummingbird_Flight_Controller_P.Gain14_Gain *
        Hummingbird_Flight_Controller_B.course) -
        Hummingbird_Flight_Controller_P.Gain7_Gain *
        Hummingbird_Flight_Controller_B.t) +
        Hummingbird_Flight_Controller_P.Gain15_Gain *
        Hummingbird_Flight_Controller_B.CastToDouble8);
      Hummingbird_Flight_Controller_B.BusAssignment.data[26] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[27] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[28] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[29] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[30] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[31] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[32] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[33] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[34] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[35] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[36] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[37] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[38] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[39] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[40] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[41] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[42] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[43] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[44] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[45] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[46] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[47] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[48] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[49] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[50] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[51] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[52] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[53] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[54] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[55] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[56] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[57] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.id =
        Hummingbird_Flight_Controller_P.Constant15_Value;
      for (Hummingbird_Flight_Controller_B.i = 0;
           Hummingbird_Flight_Controller_B.i < 10;
           Hummingbird_Flight_Controller_B.i++) {
        Hummingbird_Flight_Controller_B.BusAssignment.name[Hummingbird_Flight_Controller_B.i]
          =
          Hummingbird_Flight_Controller_P.Constant10_Value_n[Hummingbird_Flight_Controller_B.i];
      }

      Hummingbird_Flight_Controller_B.BusAssignment._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant1_Value_ab[0];
      Hummingbird_Flight_Controller_B.BusAssignment._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant1_Value_ab[1];
      Hummingbird_Flight_Controller_B.BusAssignment._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant1_Value_ab[2];
      Hummingbird_Flight_Controller_B.BusAssignment._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant1_Value_ab[3];

      // MATLABSystem: '<S1472>/SinkBlock' incorporates:
      //   BusAssignment: '<S1465>/Bus Assignment'

      uORB_write_step(Hummingbird_Flight_Controlle_DW.obj_l.orbMetadataObj,
                      &Hummingbird_Flight_Controlle_DW.obj_l.orbAdvertiseObj,
                      &Hummingbird_Flight_Controller_B.BusAssignment);

      // Sum: '<S1458>/Sum7'
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 +
        Hummingbird_Flight_Controller_B.In1_m.positions[1];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 +=
        Hummingbird_Flight_Controller_B.In1_m.positions[0];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 +=
        Hummingbird_Flight_Controller_B.In1_m.positions[2];

      // Switch: '<S1458>/Switch6' incorporates:
      //   Constant: '<S1458>/Constant3'
      //   Switch: '<S1458>/Switch5'

      if (Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode >
          Hummingbird_Flight_Controller_P.Switch6_Threshold) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Constant3_Value;
      } else if (Hummingbird_Flight_Controller_B.BusCreator.Flight_Mode >
                 Hummingbird_Flight_Controller_P.Switch5_Threshold) {
        // Switch: '<S1458>/Switch5' incorporates:
        //   Sum: '<S1458>/Sum7'

        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 +
          Hummingbird_Flight_Controller_B.In1_m.positions[3];
      } else {
        // Gain: '<S1466>/Gain10' incorporates:
        //   Constant: '<S1466>/Constant7'
        //   Sum: '<S1466>/Sum8'
        //   Switch: '<S1458>/Switch5'

        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          (static_cast<real_T>
           (Hummingbird_Flight_Controller_B.BusCreator.Throttle) -
           Hummingbird_Flight_Controller_P.Constant7_Value_c) *
          Hummingbird_Flight_Controller_P.Gain10_Gain_mz;

        // Saturate: '<S1466>/Saturation' incorporates:
        //   Switch: '<S1458>/Switch5'

        if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_js) {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_js;
        } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                   Hummingbird_Flight_Controller_P.Saturation_LowerSat_d) {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
            Hummingbird_Flight_Controller_P.Saturation_LowerSat_d;
        }
      }

      // BusCreator: '<S1458>/Bus Creator' incorporates:
      //   DataTypeConversion: '<S1458>/Cast To Boolean7'
      //   Gain: '<S1458>/Gain'

      Hummingbird_Flight_Controller_B.Actuator_output.rotor_1 = static_cast<
        real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
                  Hummingbird_Flight_Controller_B.Esp_dot);
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_2 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
        Hummingbird_Flight_Controller_B.V);
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_3 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
        Hummingbird_Flight_Controller_B.IntegralGain_k);
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_4 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2);
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_5 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
        Hummingbird_Flight_Controller_B.CastToDouble25_f);
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_6 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
        Hummingbird_Flight_Controller_B.course);
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_7 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
        Hummingbird_Flight_Controller_B.t);
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_8 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
        Hummingbird_Flight_Controller_B.CastToDouble8);

      // Saturate: '<S1458>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[1]) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[1];
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[1]) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[1];
      }

      // BusCreator: '<S1458>/Bus Creator' incorporates:
      //   Constant: '<S1458>/Constant5'
      //   DataTypeConversion: '<S1458>/Cast To Boolean10'
      //   Saturate: '<S1458>/Saturation'
      //   Sum: '<S1458>/Sum'

      Hummingbird_Flight_Controller_B.Actuator_output.throttle =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0) -
        Hummingbird_Flight_Controller_P.Constant5_Value;

      // Saturate: '<S1458>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[2]) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[2];
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[2]) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[2];
      }

      // BusCreator: '<S1458>/Bus Creator' incorporates:
      //   DataTypeConversion: '<S1458>/Cast To Boolean10'
      //   Gain: '<S1458>/Gain3'
      //   Saturate: '<S1458>/Saturation'

      Hummingbird_Flight_Controller_B.Actuator_output.ailerons =
        Hummingbird_Flight_Controller_P.Gain3_Gain_f * static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);

      // Saturate: '<S1458>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[0]) {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[0];
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[0]) {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[0];
      }

      // BusCreator: '<S1458>/Bus Creator' incorporates:
      //   DataTypeConversion: '<S1458>/Cast To Boolean10'
      //   Gain: '<S1458>/Gain2'
      //   Saturate: '<S1458>/Saturation'

      Hummingbird_Flight_Controller_B.Actuator_output.elevator =
        Hummingbird_Flight_Controller_P.Gain2_Gain_cf * static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2);

      // Saturate: '<S1458>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[3]) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[3];
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[3]) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[3];
      }

      // BusCreator: '<S1458>/Bus Creator' incorporates:
      //   Constant: '<S1458>/Constant'
      //   DataTypeConversion: '<S1458>/Cast To Boolean10'
      //   DataTypeConversion: '<S1458>/Cast To Boolean3'
      //   DataTypeConversion: '<S1458>/Cast To Boolean6'
      //   DataTypeConversion: '<S1458>/Cast To Boolean8'
      //   DataTypeConversion: '<S1458>/Cast To Boolean9'
      //   Gain: '<S1458>/Gain4'
      //   Saturate: '<S1458>/Saturation'

      Hummingbird_Flight_Controller_B.Actuator_output.rudder =
        Hummingbird_Flight_Controller_P.Gain4_Gain_ki * static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);
      Hummingbird_Flight_Controller_B.Actuator_output.arm_1 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant_Value_n5);
      Hummingbird_Flight_Controller_B.Actuator_output.arm_2 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant_Value_n5);
      Hummingbird_Flight_Controller_B.Actuator_output.arm_3 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant_Value_n5);
      Hummingbird_Flight_Controller_B.Actuator_output.arm_4 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant_Value_n5);
    }
  } else {
    switch (Hummingbird_Flight_Controlle_DW.is_Controller) {
     case Hummingbird_Fligh_IN_Controlled:
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_j2);

      // Chart: '<S1458>/Chart'
      Hummingbird_Flight_Controller_B.RC_Flight_Mode_prev_g =
        Hummingbird_Flight_Controlle_DW.RC_VTOL_Mode_start_b;
      Hummingbird_Flight_Controlle_DW.RC_VTOL_Mode_start_b =
        Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode;
      Hummingbird_Flight_Controller_B.RC_VTOL_Mode_prev_i =
        Hummingbird_Flight_Controlle_DW.RC_Flight_Mode_start_d;
      Hummingbird_Flight_Controlle_DW.RC_Flight_Mode_start_d =
        Hummingbird_Flight_Controller_B.BusCreator.Flight_Mode;
      if (Hummingbird_Flight_Controlle_DW.is_active_c9_Hummingbird_Flight == 0)
      {
        Hummingbird_Flight_Controlle_DW.RC_VTOL_Mode_start_b =
          Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode;
        Hummingbird_Flight_Controlle_DW.RC_Flight_Mode_start_d =
          Hummingbird_Flight_Controller_B.BusCreator.Flight_Mode;
        Hummingbird_Flight_Controlle_DW.is_active_c9_Hummingbird_Flight = 1U;
        if (Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode < 1200) {
          Hummingbird_Flight_Controlle_DW.is_Mixer_Control =
            Hummingbird_Flight_Contro_IN_FW;
          Hummingbird_Flight_Controller_B.i = 1;
        } else if (Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode < 1700)
        {
          Hummingbird_Flight_Controlle_DW.is_Mixer_Control =
            Hummingbird_Flight_Con_IN_Mixed;
          Hummingbird_Flight_Controller_B.i = 1;
        } else {
          Hummingbird_Flight_Controlle_DW.is_Mixer_Control =
            Hummingbird_Flight_Contro_IN_MR;
          Hummingbird_Flight_Controller_B.i = 0;
        }
      } else if ((Hummingbird_Flight_Controller_B.RC_Flight_Mode_prev_g !=
                  Hummingbird_Flight_Controlle_DW.RC_VTOL_Mode_start_b) ||
                 (Hummingbird_Flight_Controller_B.RC_VTOL_Mode_prev_i !=
                  Hummingbird_Flight_Controlle_DW.RC_Flight_Mode_start_d)) {
        if (Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode < 1200) {
          Hummingbird_Flight_Controlle_DW.is_Mixer_Control =
            Hummingbird_Flight_Contro_IN_FW;
          Hummingbird_Flight_Controller_B.i = 1;
        } else if (Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode < 1700)
        {
          Hummingbird_Flight_Controlle_DW.is_Mixer_Control =
            Hummingbird_Flight_Con_IN_Mixed;
          Hummingbird_Flight_Controller_B.i = 1;
        } else {
          Hummingbird_Flight_Controlle_DW.is_Mixer_Control =
            Hummingbird_Flight_Contro_IN_MR;
          Hummingbird_Flight_Controller_B.i = 0;
        }
      } else {
        switch (Hummingbird_Flight_Controlle_DW.is_Mixer_Control) {
         case Hummingbird_Flight_Contro_IN_FW:
          Hummingbird_Flight_Controller_B.i = 1;
          break;

         case Hummingbird_Flight_Contro_IN_MR:
          Hummingbird_Flight_Controller_B.i = 0;
          break;

         default:
          // case IN_Mixed:
          Hummingbird_Flight_Controller_B.i = 1;
          break;
        }
      }

      // Product: '<S1458>/Product1'
      Hummingbird_Flight_Controller_B.Sum_e[0] =
        Hummingbird_Flight_Controller_B.dM[0] * static_cast<real_T>
        (Hummingbird_Flight_Controller_B.i);
      Hummingbird_Flight_Controller_B.Sum_e[1] =
        Hummingbird_Flight_Controller_B.dM[1] * static_cast<real_T>
        (Hummingbird_Flight_Controller_B.i);
      Hummingbird_Flight_Controller_B.Sum_e[2] =
        Hummingbird_Flight_Controller_B.dM[2] * static_cast<real_T>
        (Hummingbird_Flight_Controller_B.i);

      // Switch: '<S1458>/Switch3' incorporates:
      //   BusCreator generated from: '<Root>/Chart1'
      //   Constant: '<S1458>/Constant29'

      if (!(Hummingbird_Flight_Controller_B.CastToDouble8 >
            Hummingbird_Flight_Controller_P.Switch3_Threshold)) {
        Hummingbird_Flight_Controller_B.CastToDouble8 =
          Hummingbird_Flight_Controller_P.Constant29_Value;
      }

      // MATLAB Function: '<S1458>/Control input Calculation' incorporates:
      //   Constant: '<S1458>/Constant2'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        Hummingbird_Flight_Controller_B.CastToDouble8 *
        Hummingbird_Flight_Controller_B.CastToDouble8;
      for (Hummingbird_Flight_Controller_B.i = 0;
           Hummingbird_Flight_Controller_B.i < 9;
           Hummingbird_Flight_Controller_B.i++) {
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i] =
          b_a[Hummingbird_Flight_Controller_B.i] *
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;
      }

      Hummingbird_Flight_Controller_B.i = 0;
      Hummingbird_Flight_Controller_B.r2_o = 1;
      Hummingbird_Flight_Controller_B.r3_n = 2;
      if (fabs(Hummingbird_Flight_Controller_B.x[2]) >
          Hummingbird_Flight_Controller_B.x[0]) {
        Hummingbird_Flight_Controller_B.i = 2;
        Hummingbird_Flight_Controller_B.r3_n = 0;
      }

      Hummingbird_Flight_Controller_B.x[1] /=
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];
      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n] /=
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];
      Hummingbird_Flight_Controller_B.x[4] -=
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i + 3]
        * Hummingbird_Flight_Controller_B.x[1];
      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n + 3]
        -= Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
        3] *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n];
      Hummingbird_Flight_Controller_B.x[7] -=
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i + 6]
        * Hummingbird_Flight_Controller_B.x[1];
      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n + 6]
        -= Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
        6] *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n];
      if (fabs
          (Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n
           + 3]) > fabs(Hummingbird_Flight_Controller_B.x[4])) {
        Hummingbird_Flight_Controller_B.r2_o =
          Hummingbird_Flight_Controller_B.r3_n;
        Hummingbird_Flight_Controller_B.r3_n = 1;
      }

      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n + 3]
        /=
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o +
        3];
      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n + 6]
        -=
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n +
        3] *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o +
        6];
      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.i];
      Hummingbird_Flight_Controller_B.Esp_dot =
        Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.r2_o]
        - Hummingbird_Flight_Controller_B.scale *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
      Hummingbird_Flight_Controller_B.V =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n +
        3];
      Hummingbird_Flight_Controller_B.IntegralGain_k =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n +
        6];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        ((Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.r3_n]
          - Hummingbird_Flight_Controller_B.scale *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n])
         - Hummingbird_Flight_Controller_B.V *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.IntegralGain_k;
      Hummingbird_Flight_Controller_B.a[2] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
      Hummingbird_Flight_Controller_B.CastToDouble25_f =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o +
        6];
      Hummingbird_Flight_Controller_B.course =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o +
        3];
      Hummingbird_Flight_Controller_B.Esp_dot =
        (Hummingbird_Flight_Controller_B.Esp_dot -
         Hummingbird_Flight_Controller_B.CastToDouble25_f *
         Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) /
        Hummingbird_Flight_Controller_B.course;
      Hummingbird_Flight_Controller_B.a[1] =
        Hummingbird_Flight_Controller_B.Esp_dot;
      Hummingbird_Flight_Controller_B.t =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i + 6];
      Hummingbird_Flight_Controller_B.CastToDouble25 =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i + 3];
      Hummingbird_Flight_Controller_B.a[0] =
        ((Hummingbird_Flight_Controller_B.scale -
          Hummingbird_Flight_Controller_B.t *
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) -
         Hummingbird_Flight_Controller_B.CastToDouble25 *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 = 0.0;
      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.i
        + 3];
      Hummingbird_Flight_Controller_B.Esp_dot =
        Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.r2_o
        + 3] - Hummingbird_Flight_Controller_B.scale *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        ((Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.r3_n
          + 3] - Hummingbird_Flight_Controller_B.scale *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n])
         - Hummingbird_Flight_Controller_B.V *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.IntegralGain_k;
      Hummingbird_Flight_Controller_B.a[5] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
      Hummingbird_Flight_Controller_B.Esp_dot =
        (Hummingbird_Flight_Controller_B.Esp_dot -
         Hummingbird_Flight_Controller_B.CastToDouble25_f *
         Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) /
        Hummingbird_Flight_Controller_B.course;
      Hummingbird_Flight_Controller_B.a[4] =
        Hummingbird_Flight_Controller_B.Esp_dot;
      Hummingbird_Flight_Controller_B.a[3] =
        ((Hummingbird_Flight_Controller_B.scale -
          Hummingbird_Flight_Controller_B.t *
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) -
         Hummingbird_Flight_Controller_B.CastToDouble25 *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 = 0.0;
      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.i
        + 6];
      Hummingbird_Flight_Controller_B.Esp_dot =
        Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.r2_o
        + 6] - Hummingbird_Flight_Controller_B.scale *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        ((Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.r3_n
          + 6] - Hummingbird_Flight_Controller_B.scale *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n])
         - Hummingbird_Flight_Controller_B.V *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.IntegralGain_k;
      Hummingbird_Flight_Controller_B.a[8] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
      Hummingbird_Flight_Controller_B.Esp_dot =
        (Hummingbird_Flight_Controller_B.Esp_dot -
         Hummingbird_Flight_Controller_B.CastToDouble25_f *
         Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) /
        Hummingbird_Flight_Controller_B.course;
      Hummingbird_Flight_Controller_B.a[7] =
        Hummingbird_Flight_Controller_B.Esp_dot;
      Hummingbird_Flight_Controller_B.a[6] =
        ((Hummingbird_Flight_Controller_B.scale -
          Hummingbird_Flight_Controller_B.t *
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) -
         Hummingbird_Flight_Controller_B.CastToDouble25 *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 = 0.0;
      for (Hummingbird_Flight_Controller_B.i = 0;
           Hummingbird_Flight_Controller_B.i < 3;
           Hummingbird_Flight_Controller_B.i++) {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.Sum_e[Hummingbird_Flight_Controller_B.i];
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 +=
          Hummingbird_Flight_Controller_B.a[3 *
          Hummingbird_Flight_Controller_B.i] *
          Hummingbird_Flight_Controller_B.scale;
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 +=
          Hummingbird_Flight_Controller_B.a[3 *
          Hummingbird_Flight_Controller_B.i + 1] *
          Hummingbird_Flight_Controller_B.scale;
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 +=
          Hummingbird_Flight_Controller_B.a[3 *
          Hummingbird_Flight_Controller_B.i + 2] *
          Hummingbird_Flight_Controller_B.scale;
      }

      // Switch: '<S1458>/Switch' incorporates:
      //   Constant: '<S1458>/Constant7'
      //   RelationalOperator: '<S1458>/IsNaN'

      if (rtIsNaN(Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0)) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Constant7_Value_k;
      }

      // Switch: '<S1458>/Switch4' incorporates:
      //   Constant: '<S1458>/Constant4'
      //   RelationalOperator: '<S1458>/IsNaN3'

      if (rtIsNaN(Hummingbird_Flight_Controller_B.dtFW)) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_P.Constant4_Value_g;
      } else {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
          Hummingbird_Flight_Controller_B.dtFW;
      }

      // Switch: '<S1458>/Switch1' incorporates:
      //   Constant: '<S1458>/Constant8'
      //   RelationalOperator: '<S1458>/IsNaN1'

      if (rtIsNaN(Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1))
      {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          Hummingbird_Flight_Controller_P.Constant8_Value;
      }

      // Switch: '<S1458>/Switch2' incorporates:
      //   Constant: '<S1458>/Constant9'
      //   RelationalOperator: '<S1458>/IsNaN2'

      if (rtIsNaN(Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0))
      {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
          Hummingbird_Flight_Controller_P.Constant9_Value;
      }

      // BusAssignment: '<S1464>/Bus Assignment' incorporates:
      //   DataTypeConversion: '<S1458>/Cast To Boolean1'
      //   MATLABSystem: '<S1464>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment_c.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_j2.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment_c.de = static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment_c.dt = static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_c.da = static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment_c.dr = static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);

      // MATLABSystem: '<S1470>/SinkBlock' incorporates:
      //   BusAssignment: '<S1464>/Bus Assignment'

      uORB_write_step(Hummingbird_Flight_Controlle_DW.obj_c.orbMetadataObj,
                      &Hummingbird_Flight_Controlle_DW.obj_c.orbAdvertiseObj,
                      &Hummingbird_Flight_Controller_B.BusAssignment_c);
      Hummingbird_Fl_PX4Timestamp
        (&Hummingbird_Flight_Controller_B.PX4Timestamp_pm);

      // Sum: '<S1460>/Sum17'
      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
        Hummingbird_Flight_Controller_B.dtMR +
        Hummingbird_Flight_Controller_B.a_n;

      // Saturate: '<S1460>/Saturation3'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 >
          Hummingbird_Flight_Controller_P.Saturation3_UpperSat) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
          Hummingbird_Flight_Controller_P.Saturation3_UpperSat;
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 <
                 Hummingbird_Flight_Controller_P.Saturation3_LowerSat) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
          Hummingbird_Flight_Controller_P.Saturation3_LowerSat;
      }

      // Gain: '<S1468>/Gain' incorporates:
      //   Constant: '<S1468>/Constant'
      //   Product: '<S1468>/Divide'

      Hummingbird_Flight_Controller_B.CastToDouble8 =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 /
        Hummingbird_Flight_Controller_P.Constant_Value_li *
        Hummingbird_Flight_Controller_P.Gain_Gain_b;

      // MATLAB Function: '<S1458>/Control input Calculation1' incorporates:
      //   Constant: '<S1458>/Constant12'
      //   Constant: '<S1458>/Constant13'

      memcpy(&Hummingbird_Flight_Controller_B.x[0],
             &Hummingbird_Flight_Controller_P.Constant12_Value[0], 9U * sizeof
             (real_T));
      Hummingbird_Flight_Controller_B.i = 0;
      Hummingbird_Flight_Controller_B.r2_o = 1;
      Hummingbird_Flight_Controller_B.r3_n = 2;
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 = fabs
        (Hummingbird_Flight_Controller_P.Constant12_Value[0]);
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 = fabs
        (Hummingbird_Flight_Controller_P.Constant12_Value[1]);
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0) {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 =
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
        Hummingbird_Flight_Controller_B.i = 1;
        Hummingbird_Flight_Controller_B.r2_o = 0;
      }

      if (fabs(Hummingbird_Flight_Controller_P.Constant12_Value[2]) >
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0) {
        Hummingbird_Flight_Controller_B.i = 2;
        Hummingbird_Flight_Controller_B.r2_o = 1;
        Hummingbird_Flight_Controller_B.r3_n = 0;
      }

      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o] =
        Hummingbird_Flight_Controller_P.Constant12_Value[Hummingbird_Flight_Controller_B.r2_o]
        /
        Hummingbird_Flight_Controller_P.Constant12_Value[Hummingbird_Flight_Controller_B.i];
      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n] /=
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];
      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o + 3]
        -= Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
        3] *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n + 3]
        -= Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
        3] *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n];
      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o + 6]
        -= Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
        6] *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n + 6]
        -= Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
        6] *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n];
      if (fabs
          (Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n
           + 3]) > fabs
          (Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o
           + 3])) {
        Hummingbird_Flight_Controller_B.rtemp =
          Hummingbird_Flight_Controller_B.r2_o;
        Hummingbird_Flight_Controller_B.r2_o =
          Hummingbird_Flight_Controller_B.r3_n;
        Hummingbird_Flight_Controller_B.r3_n =
          Hummingbird_Flight_Controller_B.rtemp;
      }

      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n + 3]
        /=
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o +
        3];
      Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n + 6]
        -=
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n +
        3] *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o +
        6];
      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.i];
      Hummingbird_Flight_Controller_B.Esp_dot =
        Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.r2_o]
        - Hummingbird_Flight_Controller_B.scale *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
      Hummingbird_Flight_Controller_B.V =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n +
        3];
      Hummingbird_Flight_Controller_B.IntegralGain_k =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n +
        6];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        ((Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.r3_n]
          - Hummingbird_Flight_Controller_B.scale *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n])
         - Hummingbird_Flight_Controller_B.V *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.IntegralGain_k;
      Hummingbird_Flight_Controller_B.a_m[2] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
      Hummingbird_Flight_Controller_B.CastToDouble25_f =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o +
        6];
      Hummingbird_Flight_Controller_B.course =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o +
        3];
      Hummingbird_Flight_Controller_B.Esp_dot =
        (Hummingbird_Flight_Controller_B.Esp_dot -
         Hummingbird_Flight_Controller_B.CastToDouble25_f *
         Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) /
        Hummingbird_Flight_Controller_B.course;
      Hummingbird_Flight_Controller_B.a_m[1] =
        Hummingbird_Flight_Controller_B.Esp_dot;
      Hummingbird_Flight_Controller_B.t =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i + 6];
      Hummingbird_Flight_Controller_B.CastToDouble25 =
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i + 3];
      Hummingbird_Flight_Controller_B.a_m[0] =
        ((Hummingbird_Flight_Controller_B.scale -
          Hummingbird_Flight_Controller_B.t *
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) -
         Hummingbird_Flight_Controller_B.CastToDouble25 *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];

      // Sum: '<S1458>/Sum8'
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[0] =
        Hummingbird_Flight_Controller_B.dM[0] -
        Hummingbird_Flight_Controller_B.Sum_e[0];

      // MATLAB Function: '<S1458>/Control input Calculation1' incorporates:
      //   Constant: '<S1458>/Constant13'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 = 0.0;
      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.i + 3];
      Hummingbird_Flight_Controller_B.Esp_dot =
        Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.r2_o
        + 3] - Hummingbird_Flight_Controller_B.scale *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        ((Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.r3_n
          + 3] - Hummingbird_Flight_Controller_B.scale *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n])
         - Hummingbird_Flight_Controller_B.V *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.IntegralGain_k;
      Hummingbird_Flight_Controller_B.a_m[5] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
      Hummingbird_Flight_Controller_B.Esp_dot =
        (Hummingbird_Flight_Controller_B.Esp_dot -
         Hummingbird_Flight_Controller_B.CastToDouble25_f *
         Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) /
        Hummingbird_Flight_Controller_B.course;
      Hummingbird_Flight_Controller_B.a_m[4] =
        Hummingbird_Flight_Controller_B.Esp_dot;
      Hummingbird_Flight_Controller_B.a_m[3] =
        ((Hummingbird_Flight_Controller_B.scale -
          Hummingbird_Flight_Controller_B.t *
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) -
         Hummingbird_Flight_Controller_B.CastToDouble25 *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];

      // Sum: '<S1458>/Sum8'
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[1] =
        Hummingbird_Flight_Controller_B.dM[1] -
        Hummingbird_Flight_Controller_B.Sum_e[1];

      // MATLAB Function: '<S1458>/Control input Calculation1' incorporates:
      //   Constant: '<S1458>/Constant13'

      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 = 0.0;
      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.i + 6];
      Hummingbird_Flight_Controller_B.Esp_dot =
        Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.r2_o
        + 6] - Hummingbird_Flight_Controller_B.scale *
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        ((Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.r3_n
          + 6] - Hummingbird_Flight_Controller_B.scale *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n])
         - Hummingbird_Flight_Controller_B.V *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.IntegralGain_k;
      Hummingbird_Flight_Controller_B.a_m[8] =
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
      Hummingbird_Flight_Controller_B.Esp_dot =
        (Hummingbird_Flight_Controller_B.Esp_dot -
         Hummingbird_Flight_Controller_B.CastToDouble25_f *
         Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) /
        Hummingbird_Flight_Controller_B.course;
      Hummingbird_Flight_Controller_B.a_m[7] =
        Hummingbird_Flight_Controller_B.Esp_dot;
      Hummingbird_Flight_Controller_B.a_m[6] =
        ((Hummingbird_Flight_Controller_B.scale -
          Hummingbird_Flight_Controller_B.t *
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) -
         Hummingbird_Flight_Controller_B.CastToDouble25 *
         Hummingbird_Flight_Controller_B.Esp_dot) /
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];

      // Sum: '<S1458>/Sum8'
      Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[2] =
        Hummingbird_Flight_Controller_B.dM[2] -
        Hummingbird_Flight_Controller_B.Sum_e[2];

      // MATLAB Function: '<S1458>/Control input Calculation1'
      Hummingbird_Flight_Controller_B.b_t = 0.0;
      for (Hummingbird_Flight_Controller_B.i = 0;
           Hummingbird_Flight_Controller_B.i < 3;
           Hummingbird_Flight_Controller_B.i++) {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[Hummingbird_Flight_Controller_B.i];
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 +=
          Hummingbird_Flight_Controller_B.a_m[3 *
          Hummingbird_Flight_Controller_B.i] *
          Hummingbird_Flight_Controller_B.scale;
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 +=
          Hummingbird_Flight_Controller_B.a_m[3 *
          Hummingbird_Flight_Controller_B.i + 1] *
          Hummingbird_Flight_Controller_B.scale;
        Hummingbird_Flight_Controller_B.b_t +=
          Hummingbird_Flight_Controller_B.a_m[3 *
          Hummingbird_Flight_Controller_B.i + 2] *
          Hummingbird_Flight_Controller_B.scale;
      }

      // Sum: '<S1460>/Sum10' incorporates:
      //   MATLAB Function: '<S1458>/Control input Calculation1'

      Hummingbird_Flight_Controller_B.Sum_e[0] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 +
        Hummingbird_Flight_Controller_B.ParamStep_i;
      Hummingbird_Flight_Controller_B.Sum_e[1] =
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 +
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0;
      Hummingbird_Flight_Controller_B.Sum_e[2] =
        Hummingbird_Flight_Controller_B.b_t +
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1;

      // Saturate: '<S1468>/Saturation9'
      if (Hummingbird_Flight_Controller_B.Sum_e[0] >
          Hummingbird_Flight_Controller_P.Saturation9_UpperSat) {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_P.Saturation9_UpperSat;
      } else if (Hummingbird_Flight_Controller_B.Sum_e[0] <
                 Hummingbird_Flight_Controller_P.Saturation9_LowerSat) {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_P.Saturation9_LowerSat;
      } else {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.Sum_e[0];
      }

      // Product: '<S1468>/Divide3' incorporates:
      //   Constant: '<S1468>/Constant2'
      //   Saturate: '<S1468>/Saturation9'

      Hummingbird_Flight_Controller_B.CastToDouble25 =
        Hummingbird_Flight_Controller_B.scale /
        Hummingbird_Flight_Controller_P.Constant2_Value_a;

      // Saturate: '<S1468>/Saturation8'
      if (Hummingbird_Flight_Controller_B.Sum_e[1] >
          Hummingbird_Flight_Controller_P.Saturation8_UpperSat) {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_P.Saturation8_UpperSat;
      } else if (Hummingbird_Flight_Controller_B.Sum_e[1] <
                 Hummingbird_Flight_Controller_P.Saturation8_LowerSat) {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_P.Saturation8_LowerSat;
      } else {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.Sum_e[1];
      }

      // Product: '<S1468>/Divide2' incorporates:
      //   Constant: '<S1468>/Constant1'
      //   Saturate: '<S1468>/Saturation8'

      Hummingbird_Flight_Controller_B.t = Hummingbird_Flight_Controller_B.scale /
        Hummingbird_Flight_Controller_P.Constant1_Value_p;

      // Saturate: '<S1468>/Saturation10'
      if (Hummingbird_Flight_Controller_B.Sum_e[2] >
          Hummingbird_Flight_Controller_P.Saturation10_UpperSat) {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_P.Saturation10_UpperSat;
      } else if (Hummingbird_Flight_Controller_B.Sum_e[2] <
                 Hummingbird_Flight_Controller_P.Saturation10_LowerSat) {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_P.Saturation10_LowerSat;
      } else {
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_B.Sum_e[2];
      }

      // Product: '<S1468>/Divide1' incorporates:
      //   Constant: '<S1468>/Constant3'
      //   Saturate: '<S1468>/Saturation10'

      Hummingbird_Flight_Controller_B.scale /=
        Hummingbird_Flight_Controller_P.Constant3_Value_k;

      // Sum: '<S1468>/Add'
      Hummingbird_Flight_Controller_B.Esp_dot =
        ((Hummingbird_Flight_Controller_B.scale -
          Hummingbird_Flight_Controller_B.CastToDouble8) -
         Hummingbird_Flight_Controller_B.CastToDouble25) -
        Hummingbird_Flight_Controller_B.t;

      // Saturate: '<S1468>/Saturation'
      if (Hummingbird_Flight_Controller_B.Esp_dot >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_o) {
        Hummingbird_Flight_Controller_B.Esp_dot =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_o;
      } else if (Hummingbird_Flight_Controller_B.Esp_dot <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_n) {
        Hummingbird_Flight_Controller_B.Esp_dot =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_n;
      }

      // Sum: '<S1468>/Add4'
      Hummingbird_Flight_Controller_B.V = (((0.0 -
        Hummingbird_Flight_Controller_B.CastToDouble8) -
        Hummingbird_Flight_Controller_B.CastToDouble25) -
        Hummingbird_Flight_Controller_B.t) -
        Hummingbird_Flight_Controller_B.scale;

      // Saturate: '<S1468>/Saturation4'
      if (Hummingbird_Flight_Controller_B.V >
          Hummingbird_Flight_Controller_P.Saturation4_UpperSat) {
        Hummingbird_Flight_Controller_B.V =
          Hummingbird_Flight_Controller_P.Saturation4_UpperSat;
      } else if (Hummingbird_Flight_Controller_B.V <
                 Hummingbird_Flight_Controller_P.Saturation4_LowerSat) {
        Hummingbird_Flight_Controller_B.V =
          Hummingbird_Flight_Controller_P.Saturation4_LowerSat;
      }

      // Sum: '<S1468>/Add1' incorporates:
      //   Sum: '<S1468>/Add2'
      //   Sum: '<S1468>/Add5'

      Hummingbird_Flight_Controller_B.CastToDouble25_f =
        Hummingbird_Flight_Controller_B.CastToDouble25 -
        Hummingbird_Flight_Controller_B.CastToDouble8;
      Hummingbird_Flight_Controller_B.r_c =
        Hummingbird_Flight_Controller_B.CastToDouble25_f -
        Hummingbird_Flight_Controller_B.t;
      Hummingbird_Flight_Controller_B.IntegralGain_k =
        Hummingbird_Flight_Controller_B.r_c -
        Hummingbird_Flight_Controller_B.scale;

      // Saturate: '<S1468>/Saturation1'
      if (Hummingbird_Flight_Controller_B.IntegralGain_k >
          Hummingbird_Flight_Controller_P.Saturation1_UpperSat_e) {
        Hummingbird_Flight_Controller_B.IntegralGain_k =
          Hummingbird_Flight_Controller_P.Saturation1_UpperSat_e;
      } else if (Hummingbird_Flight_Controller_B.IntegralGain_k <
                 Hummingbird_Flight_Controller_P.Saturation1_LowerSat_b) {
        Hummingbird_Flight_Controller_B.IntegralGain_k =
          Hummingbird_Flight_Controller_P.Saturation1_LowerSat_b;
      }

      // Sum: '<S1468>/Add5'
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
        Hummingbird_Flight_Controller_B.r_c +
        Hummingbird_Flight_Controller_B.scale;

      // Saturate: '<S1468>/Saturation5'
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 >
          Hummingbird_Flight_Controller_P.Saturation5_UpperSat) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_P.Saturation5_UpperSat;
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 <
                 Hummingbird_Flight_Controller_P.Saturation5_LowerSat) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_P.Saturation5_LowerSat;
      }

      // Sum: '<S1468>/Add2' incorporates:
      //   Sum: '<S1468>/Add6'

      Hummingbird_Flight_Controller_B.r_c =
        Hummingbird_Flight_Controller_B.CastToDouble25_f +
        Hummingbird_Flight_Controller_B.t;
      Hummingbird_Flight_Controller_B.CastToDouble25_f =
        Hummingbird_Flight_Controller_B.r_c +
        Hummingbird_Flight_Controller_B.scale;

      // Saturate: '<S1468>/Saturation2'
      if (Hummingbird_Flight_Controller_B.CastToDouble25_f >
          Hummingbird_Flight_Controller_P.Saturation2_UpperSat_o) {
        Hummingbird_Flight_Controller_B.CastToDouble25_f =
          Hummingbird_Flight_Controller_P.Saturation2_UpperSat_o;
      } else if (Hummingbird_Flight_Controller_B.CastToDouble25_f <
                 Hummingbird_Flight_Controller_P.Saturation2_LowerSat_g) {
        Hummingbird_Flight_Controller_B.CastToDouble25_f =
          Hummingbird_Flight_Controller_P.Saturation2_LowerSat_g;
      }

      // Sum: '<S1468>/Add6'
      Hummingbird_Flight_Controller_B.course =
        Hummingbird_Flight_Controller_B.r_c -
        Hummingbird_Flight_Controller_B.scale;

      // Saturate: '<S1468>/Saturation6'
      if (Hummingbird_Flight_Controller_B.course >
          Hummingbird_Flight_Controller_P.Saturation6_UpperSat) {
        Hummingbird_Flight_Controller_B.course =
          Hummingbird_Flight_Controller_P.Saturation6_UpperSat;
      } else if (Hummingbird_Flight_Controller_B.course <
                 Hummingbird_Flight_Controller_P.Saturation6_LowerSat) {
        Hummingbird_Flight_Controller_B.course =
          Hummingbird_Flight_Controller_P.Saturation6_LowerSat;
      }

      // Sum: '<S1468>/Add3' incorporates:
      //   Sum: '<S1468>/Add7'

      Hummingbird_Flight_Controller_B.r_c = (Hummingbird_Flight_Controller_B.t -
        Hummingbird_Flight_Controller_B.CastToDouble8) -
        Hummingbird_Flight_Controller_B.CastToDouble25;
      Hummingbird_Flight_Controller_B.t = Hummingbird_Flight_Controller_B.r_c -
        Hummingbird_Flight_Controller_B.scale;

      // Saturate: '<S1468>/Saturation3'
      if (Hummingbird_Flight_Controller_B.t >
          Hummingbird_Flight_Controller_P.Saturation3_UpperSat_a) {
        Hummingbird_Flight_Controller_B.t =
          Hummingbird_Flight_Controller_P.Saturation3_UpperSat_a;
      } else if (Hummingbird_Flight_Controller_B.t <
                 Hummingbird_Flight_Controller_P.Saturation3_LowerSat_o) {
        Hummingbird_Flight_Controller_B.t =
          Hummingbird_Flight_Controller_P.Saturation3_LowerSat_o;
      }

      // Sum: '<S1468>/Add7'
      Hummingbird_Flight_Controller_B.CastToDouble8 =
        Hummingbird_Flight_Controller_B.r_c +
        Hummingbird_Flight_Controller_B.scale;

      // Saturate: '<S1468>/Saturation7'
      if (Hummingbird_Flight_Controller_B.CastToDouble8 >
          Hummingbird_Flight_Controller_P.Saturation7_UpperSat) {
        Hummingbird_Flight_Controller_B.CastToDouble8 =
          Hummingbird_Flight_Controller_P.Saturation7_UpperSat;
      } else if (Hummingbird_Flight_Controller_B.CastToDouble8 <
                 Hummingbird_Flight_Controller_P.Saturation7_LowerSat) {
        Hummingbird_Flight_Controller_B.CastToDouble8 =
          Hummingbird_Flight_Controller_P.Saturation7_LowerSat;
      }

      // Gain: '<S1467>/Gain1'
      Hummingbird_Flight_Controller_B.CastToDouble25 =
        Hummingbird_Flight_Controller_P.Gain1_Gain_hu *
        Hummingbird_Flight_Controller_B.IntegralGain_k;

      // Gain: '<S1467>/Gain2'
      Hummingbird_Flight_Controller_B.r_c =
        Hummingbird_Flight_Controller_P.Gain2_Gain_p *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;

      // Gain: '<S1467>/Gain3'
      Hummingbird_Flight_Controller_B.absxk =
        Hummingbird_Flight_Controller_P.Gain3_Gain_h *
        Hummingbird_Flight_Controller_B.CastToDouble25_f;

      // Gain: '<S1467>/Gain9'
      Hummingbird_Flight_Controller_B.b_gamma =
        Hummingbird_Flight_Controller_P.Gain9_Gain *
        Hummingbird_Flight_Controller_B.course;

      // Gain: '<S1467>/Gain10'
      Hummingbird_Flight_Controller_B.eta =
        Hummingbird_Flight_Controller_P.Gain10_Gain_b *
        Hummingbird_Flight_Controller_B.t;

      // Gain: '<S1467>/Gain11'
      Hummingbird_Flight_Controller_B.Add1 =
        Hummingbird_Flight_Controller_P.Gain11_Gain *
        Hummingbird_Flight_Controller_B.CastToDouble8;

      // BusAssignment: '<S1465>/Bus Assignment' incorporates:
      //   BusCreator: '<S5>/Bus Creator4'
      //   Constant: '<S1458>/Constant14'
      //   DataTypeConversion: '<S1458>/Cast To Boolean4'
      //   DataTypeConversion: '<S1458>/Cast To Boolean5'
      //   MATLAB Function: '<S1458>/Control input Calculation1'
      //   MATLABSystem: '<S1465>/PX4 Timestamp'

      Hummingbird_Flight_Controller_B.BusAssignment.timestamp =
        Hummingbird_Flight_Controller_B.PX4Timestamp_pm.PX4Timestamp;
      Hummingbird_Flight_Controller_B.BusAssignment.data[0] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.Esp_dot);
      Hummingbird_Flight_Controller_B.BusAssignment.data[1] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.V);
      Hummingbird_Flight_Controller_B.BusAssignment.data[2] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.IntegralGain_k);
      Hummingbird_Flight_Controller_B.BusAssignment.data[3] =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment.data[4] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.CastToDouble25_f);
      Hummingbird_Flight_Controller_B.BusAssignment.data[5] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.course);
      Hummingbird_Flight_Controller_B.BusAssignment.data[6] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.t);
      Hummingbird_Flight_Controller_B.BusAssignment.data[7] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.CastToDouble8);
      Hummingbird_Flight_Controller_B.BusAssignment.data[8] =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2);
      Hummingbird_Flight_Controller_B.BusAssignment.data[12] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.dtMR);
      Hummingbird_Flight_Controller_B.BusAssignment.data[9] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.Sum_e[0]);
      Hummingbird_Flight_Controller_B.BusAssignment.data[13] =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0);
      Hummingbird_Flight_Controller_B.BusAssignment.data[10] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.Sum_e[1]);
      Hummingbird_Flight_Controller_B.BusAssignment.data[14] =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1);
      Hummingbird_Flight_Controller_B.BusAssignment.data[11] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.Sum_e[2]);
      Hummingbird_Flight_Controller_B.BusAssignment.data[15] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_B.b_t);
      Hummingbird_Flight_Controller_B.BusAssignment.data[16] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[17] =
        Hummingbird_Flight_Controller_B.a_n;
      Hummingbird_Flight_Controller_B.BusAssignment.data[18] =
        Hummingbird_Flight_Controller_B.ParamStep_i;
      Hummingbird_Flight_Controller_B.BusAssignment.data[19] =
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0;
      Hummingbird_Flight_Controller_B.BusAssignment.data[20] =
        Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1;
      Hummingbird_Flight_Controller_B.BusAssignment.data[21] =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2);

      // Sum: '<S1467>/Add' incorporates:
      //   Gain: '<S1467>/Gain'
      //   Gain: '<S1467>/Gain8'
      //   Sum: '<S1467>/Add2'
      //   Sum: '<S1467>/Add3'

      Hummingbird_Flight_Controller_B.scale =
        Hummingbird_Flight_Controller_P.Gain_Gain_l *
        Hummingbird_Flight_Controller_B.Esp_dot +
        Hummingbird_Flight_Controller_P.Gain8_Gain *
        Hummingbird_Flight_Controller_B.V;
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 =
        (Hummingbird_Flight_Controller_B.scale +
         Hummingbird_Flight_Controller_B.CastToDouble25) +
        Hummingbird_Flight_Controller_B.r_c;

      // BusAssignment: '<S1465>/Bus Assignment' incorporates:
      //   Constant: '<S1458>/Constant1'
      //   Constant: '<S1458>/Constant10'
      //   Constant: '<S1458>/Constant14'
      //   Constant: '<S1458>/Constant15'
      //   Constant: '<S1467>/Constant1'
      //   Constant: '<S1467>/Constant2'
      //   DataTypeConversion: '<S1458>/Cast To Boolean4'
      //   Gain: '<S1467>/Gain12'
      //   Gain: '<S1467>/Gain13'
      //   Gain: '<S1467>/Gain14'
      //   Gain: '<S1467>/Gain15'
      //   Gain: '<S1467>/Gain4'
      //   Gain: '<S1467>/Gain5'
      //   Gain: '<S1467>/Gain6'
      //   Gain: '<S1467>/Gain7'
      //   Product: '<S1467>/Product'
      //   Product: '<S1467>/Product1'
      //   Sum: '<S1467>/Add'
      //   Sum: '<S1467>/Add1'
      //   Sum: '<S1467>/Add2'
      //   Sum: '<S1467>/Add3'

      Hummingbird_Flight_Controller_B.BusAssignment.data[22] =
        static_cast<real32_T>
        ((((Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 +
            Hummingbird_Flight_Controller_B.absxk) +
           Hummingbird_Flight_Controller_B.b_gamma) +
          Hummingbird_Flight_Controller_B.eta) +
         Hummingbird_Flight_Controller_B.Add1);
      Hummingbird_Flight_Controller_B.BusAssignment.data[23] =
        static_cast<real32_T>(((((((Hummingbird_Flight_Controller_B.scale -
        Hummingbird_Flight_Controller_B.CastToDouble25) -
        Hummingbird_Flight_Controller_B.r_c) -
        Hummingbird_Flight_Controller_B.absxk) -
        Hummingbird_Flight_Controller_B.b_gamma) +
        Hummingbird_Flight_Controller_B.eta) +
        Hummingbird_Flight_Controller_B.Add1) *
        Hummingbird_Flight_Controller_P.Constant2_Value_i);
      Hummingbird_Flight_Controller_B.BusAssignment.data[24] =
        static_cast<real32_T>
        (((((Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 -
             Hummingbird_Flight_Controller_B.absxk) -
            Hummingbird_Flight_Controller_B.b_gamma) -
           Hummingbird_Flight_Controller_B.eta) -
          Hummingbird_Flight_Controller_B.Add1) *
         Hummingbird_Flight_Controller_P.Constant1_Value_n);
      Hummingbird_Flight_Controller_B.BusAssignment.data[25] =
        static_cast<real32_T>(((((((Hummingbird_Flight_Controller_P.Gain4_Gain_k
        * Hummingbird_Flight_Controller_B.Esp_dot -
        Hummingbird_Flight_Controller_P.Gain12_Gain *
        Hummingbird_Flight_Controller_B.V) -
        Hummingbird_Flight_Controller_P.Gain5_Gain *
        Hummingbird_Flight_Controller_B.IntegralGain_k) +
        Hummingbird_Flight_Controller_P.Gain13_Gain *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) +
        Hummingbird_Flight_Controller_P.Gain6_Gain *
        Hummingbird_Flight_Controller_B.CastToDouble25_f) -
        Hummingbird_Flight_Controller_P.Gain14_Gain *
        Hummingbird_Flight_Controller_B.course) -
        Hummingbird_Flight_Controller_P.Gain7_Gain *
        Hummingbird_Flight_Controller_B.t) +
        Hummingbird_Flight_Controller_P.Gain15_Gain *
        Hummingbird_Flight_Controller_B.CastToDouble8);
      Hummingbird_Flight_Controller_B.BusAssignment.data[26] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[27] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[28] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[29] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[30] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[31] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[32] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[33] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[34] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[35] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[36] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[37] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[38] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[39] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[40] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[41] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[42] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[43] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[44] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[45] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[46] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[47] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[48] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[49] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[50] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[51] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[52] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[53] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[54] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[55] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[56] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.data[57] =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant14_Value_e);
      Hummingbird_Flight_Controller_B.BusAssignment.id =
        Hummingbird_Flight_Controller_P.Constant15_Value;
      for (Hummingbird_Flight_Controller_B.i = 0;
           Hummingbird_Flight_Controller_B.i < 10;
           Hummingbird_Flight_Controller_B.i++) {
        Hummingbird_Flight_Controller_B.BusAssignment.name[Hummingbird_Flight_Controller_B.i]
          =
          Hummingbird_Flight_Controller_P.Constant10_Value_n[Hummingbird_Flight_Controller_B.i];
      }

      Hummingbird_Flight_Controller_B.BusAssignment._padding0[0] =
        Hummingbird_Flight_Controller_P.Constant1_Value_ab[0];
      Hummingbird_Flight_Controller_B.BusAssignment._padding0[1] =
        Hummingbird_Flight_Controller_P.Constant1_Value_ab[1];
      Hummingbird_Flight_Controller_B.BusAssignment._padding0[2] =
        Hummingbird_Flight_Controller_P.Constant1_Value_ab[2];
      Hummingbird_Flight_Controller_B.BusAssignment._padding0[3] =
        Hummingbird_Flight_Controller_P.Constant1_Value_ab[3];

      // MATLABSystem: '<S1472>/SinkBlock' incorporates:
      //   BusAssignment: '<S1465>/Bus Assignment'

      uORB_write_step(Hummingbird_Flight_Controlle_DW.obj_l.orbMetadataObj,
                      &Hummingbird_Flight_Controlle_DW.obj_l.orbAdvertiseObj,
                      &Hummingbird_Flight_Controller_B.BusAssignment);

      // Sum: '<S1458>/Sum7'
      Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 =
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 +
        Hummingbird_Flight_Controller_B.In1_m.positions[1];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 +=
        Hummingbird_Flight_Controller_B.In1_m.positions[0];
      Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 +=
        Hummingbird_Flight_Controller_B.In1_m.positions[2];

      // Switch: '<S1458>/Switch6' incorporates:
      //   Constant: '<S1458>/Constant3'
      //   Switch: '<S1458>/Switch5'

      if (Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode >
          Hummingbird_Flight_Controller_P.Switch6_Threshold) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Constant3_Value;
      } else if (Hummingbird_Flight_Controller_B.BusCreator.Flight_Mode >
                 Hummingbird_Flight_Controller_P.Switch5_Threshold) {
        // Switch: '<S1458>/Switch5' incorporates:
        //   Sum: '<S1458>/Sum7'

        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 +
          Hummingbird_Flight_Controller_B.In1_m.positions[3];
      } else {
        // Gain: '<S1466>/Gain10' incorporates:
        //   Constant: '<S1466>/Constant7'
        //   Sum: '<S1466>/Sum8'
        //   Switch: '<S1458>/Switch5'

        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          (static_cast<real_T>
           (Hummingbird_Flight_Controller_B.BusCreator.Throttle) -
           Hummingbird_Flight_Controller_P.Constant7_Value_c) *
          Hummingbird_Flight_Controller_P.Gain10_Gain_mz;

        // Saturate: '<S1466>/Saturation' incorporates:
        //   Switch: '<S1458>/Switch5'

        if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_js) {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_js;
        } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                   Hummingbird_Flight_Controller_P.Saturation_LowerSat_d) {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
            Hummingbird_Flight_Controller_P.Saturation_LowerSat_d;
        }
      }

      // BusCreator: '<S1458>/Bus Creator' incorporates:
      //   DataTypeConversion: '<S1458>/Cast To Boolean7'
      //   Gain: '<S1458>/Gain'

      Hummingbird_Flight_Controller_B.Actuator_output.rotor_1 = static_cast<
        real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
                  Hummingbird_Flight_Controller_B.Esp_dot);
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_2 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
        Hummingbird_Flight_Controller_B.V);
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_3 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
        Hummingbird_Flight_Controller_B.IntegralGain_k);
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_4 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2);
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_5 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
        Hummingbird_Flight_Controller_B.CastToDouble25_f);
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_6 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
        Hummingbird_Flight_Controller_B.course);
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_7 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
        Hummingbird_Flight_Controller_B.t);
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_8 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
        Hummingbird_Flight_Controller_B.CastToDouble8);

      // Saturate: '<S1458>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[1]) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[1];
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[1]) {
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[1];
      }

      // BusCreator: '<S1458>/Bus Creator' incorporates:
      //   Constant: '<S1458>/Constant5'
      //   DataTypeConversion: '<S1458>/Cast To Boolean10'
      //   Saturate: '<S1458>/Saturation'
      //   Sum: '<S1458>/Sum'

      Hummingbird_Flight_Controller_B.Actuator_output.throttle =
        static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0) -
        Hummingbird_Flight_Controller_P.Constant5_Value;

      // Saturate: '<S1458>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[2]) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[2];
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[2]) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[2];
      }

      // BusCreator: '<S1458>/Bus Creator' incorporates:
      //   DataTypeConversion: '<S1458>/Cast To Boolean10'
      //   Gain: '<S1458>/Gain3'
      //   Saturate: '<S1458>/Saturation'

      Hummingbird_Flight_Controller_B.Actuator_output.ailerons =
        Hummingbird_Flight_Controller_P.Gain3_Gain_f * static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);

      // Saturate: '<S1458>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[0]) {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[0];
      } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[0]) {
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[0];
      }

      // BusCreator: '<S1458>/Bus Creator' incorporates:
      //   DataTypeConversion: '<S1458>/Cast To Boolean10'
      //   Gain: '<S1458>/Gain2'
      //   Saturate: '<S1458>/Saturation'

      Hummingbird_Flight_Controller_B.Actuator_output.elevator =
        Hummingbird_Flight_Controller_P.Gain2_Gain_cf * static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2);

      // Saturate: '<S1458>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[3]) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[3];
      } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[3]) {
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
          Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[3];
      }

      // BusCreator: '<S1458>/Bus Creator' incorporates:
      //   Constant: '<S1458>/Constant'
      //   DataTypeConversion: '<S1458>/Cast To Boolean10'
      //   DataTypeConversion: '<S1458>/Cast To Boolean3'
      //   DataTypeConversion: '<S1458>/Cast To Boolean6'
      //   DataTypeConversion: '<S1458>/Cast To Boolean8'
      //   DataTypeConversion: '<S1458>/Cast To Boolean9'
      //   Gain: '<S1458>/Gain4'
      //   Saturate: '<S1458>/Saturation'

      Hummingbird_Flight_Controller_B.Actuator_output.rudder =
        Hummingbird_Flight_Controller_P.Gain4_Gain_ki * static_cast<real32_T>
        (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);
      Hummingbird_Flight_Controller_B.Actuator_output.arm_1 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant_Value_n5);
      Hummingbird_Flight_Controller_B.Actuator_output.arm_2 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant_Value_n5);
      Hummingbird_Flight_Controller_B.Actuator_output.arm_3 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant_Value_n5);
      Hummingbird_Flight_Controller_B.Actuator_output.arm_4 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant_Value_n5);
      break;

     case Hummingbird_Flight_IN_FW_Manual:
      // DataTypeConversion: '<S1459>/Cast To Boolean4' incorporates:
      //   Constant: '<S1459>/Constant1'

      for (Hummingbird_Flight_Controller_B.i = 0;
           Hummingbird_Flight_Controller_B.i < 8;
           Hummingbird_Flight_Controller_B.i++) {
        Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[Hummingbird_Flight_Controller_B.i]
          = static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant1_Value_o[Hummingbird_Flight_Controller_B.i]);
      }

      // BusCreator: '<S1459>/Bus Creator'
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_1 =
        Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[0];
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_2 =
        Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[1];
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_3 =
        Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[2];
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_4 =
        Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[3];
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_5 =
        Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[4];
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_6 =
        Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[5];
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_7 =
        Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[6];
      Hummingbird_Flight_Controller_B.Actuator_output.rotor_8 =
        Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[7];

      // If: '<S1477>/If' incorporates:
      //   BusCreator generated from: '<Root>/Chart1'

      if (Hummingbird_Flight_Controller_B.In1_fv.armed) {
        // Gain: '<S1476>/Gain10' incorporates:
        //   Constant: '<S1476>/Constant7'
        //   Sum: '<S1476>/Sum8'

        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          (static_cast<real_T>
           (Hummingbird_Flight_Controller_B.BusCreator.Throttle) -
           Hummingbird_Flight_Controller_P.Constant7_Value_a) *
          Hummingbird_Flight_Controller_P.Gain10_Gain_bn;

        // Saturate: '<S1476>/Saturation'
        if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_lz) {
          // BusCreator: '<S1459>/Bus Creator' incorporates:
          //   DataTypeConversion: '<S1459>/Cast To Boolean5'

          Hummingbird_Flight_Controller_B.Actuator_output.throttle =
            static_cast<real32_T>
            (Hummingbird_Flight_Controller_P.Saturation_UpperSat_lz);
        } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                   Hummingbird_Flight_Controller_P.Saturation_LowerSat_o) {
          // BusCreator: '<S1459>/Bus Creator' incorporates:
          //   DataTypeConversion: '<S1459>/Cast To Boolean5'

          Hummingbird_Flight_Controller_B.Actuator_output.throttle =
            static_cast<real32_T>
            (Hummingbird_Flight_Controller_P.Saturation_LowerSat_o);
        } else {
          // BusCreator: '<S1459>/Bus Creator' incorporates:
          //   DataTypeConversion: '<S1459>/Cast To Boolean5'

          Hummingbird_Flight_Controller_B.Actuator_output.throttle =
            static_cast<real32_T>
            (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);
        }
      } else {
        // BusCreator: '<S1459>/Bus Creator' incorporates:
        //   Constant: '<S1459>/Constant2'
        //   DataTypeConversion: '<S1459>/Cast To Boolean5'

        Hummingbird_Flight_Controller_B.Actuator_output.throttle =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant2_Value_o);
      }

      // Gain: '<S1473>/Gain10' incorporates:
      //   Constant: '<S1473>/Constant7'
      //   Sum: '<S1473>/Sum8'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Roll) -
         Hummingbird_Flight_Controller_P.Constant7_Value_p) *
        Hummingbird_Flight_Controller_P.Gain10_Gain_ap;

      // Saturate: '<S1473>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_dq) {
        // BusCreator: '<S1459>/Bus Creator' incorporates:
        //   DataTypeConversion: '<S1459>/Cast To Boolean2'

        Hummingbird_Flight_Controller_B.Actuator_output.ailerons =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Saturation_UpperSat_dq);
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_du) {
        // BusCreator: '<S1459>/Bus Creator' incorporates:
        //   DataTypeConversion: '<S1459>/Cast To Boolean2'

        Hummingbird_Flight_Controller_B.Actuator_output.ailerons =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Saturation_LowerSat_du);
      } else {
        // BusCreator: '<S1459>/Bus Creator' incorporates:
        //   DataTypeConversion: '<S1459>/Cast To Boolean2'

        Hummingbird_Flight_Controller_B.Actuator_output.ailerons =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);
      }

      // Gain: '<S1474>/Gain10' incorporates:
      //   Constant: '<S1474>/Constant7'
      //   Sum: '<S1474>/Sum8'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Pitch) -
         Hummingbird_Flight_Controller_P.Constant7_Value_kf) *
        Hummingbird_Flight_Controller_P.Gain10_Gain_nx;

      // Saturate: '<S1474>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_i) {
        // BusCreator: '<S1459>/Bus Creator' incorporates:
        //   DataTypeConversion: '<S1459>/Cast To Boolean1'

        Hummingbird_Flight_Controller_B.Actuator_output.elevator =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Saturation_UpperSat_i);
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_bn) {
        // BusCreator: '<S1459>/Bus Creator' incorporates:
        //   DataTypeConversion: '<S1459>/Cast To Boolean1'

        Hummingbird_Flight_Controller_B.Actuator_output.elevator =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Saturation_LowerSat_bn);
      } else {
        // BusCreator: '<S1459>/Bus Creator' incorporates:
        //   DataTypeConversion: '<S1459>/Cast To Boolean1'

        Hummingbird_Flight_Controller_B.Actuator_output.elevator =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);
      }

      // Gain: '<S1475>/Gain10' incorporates:
      //   Constant: '<S1475>/Constant7'
      //   Sum: '<S1475>/Sum8'

      Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
        (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Yaw) -
         Hummingbird_Flight_Controller_P.Constant7_Value_l3) *
        Hummingbird_Flight_Controller_P.Gain10_Gain_f;

      // Saturate: '<S1475>/Saturation'
      if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
          Hummingbird_Flight_Controller_P.Saturation_UpperSat_oe) {
        // BusCreator: '<S1459>/Bus Creator' incorporates:
        //   DataTypeConversion: '<S1459>/Cast To Boolean3'

        Hummingbird_Flight_Controller_B.Actuator_output.rudder =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Saturation_UpperSat_oe);
      } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                 Hummingbird_Flight_Controller_P.Saturation_LowerSat_e) {
        // BusCreator: '<S1459>/Bus Creator' incorporates:
        //   DataTypeConversion: '<S1459>/Cast To Boolean3'

        Hummingbird_Flight_Controller_B.Actuator_output.rudder =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Saturation_LowerSat_e);
      } else {
        // BusCreator: '<S1459>/Bus Creator' incorporates:
        //   DataTypeConversion: '<S1459>/Cast To Boolean3'

        Hummingbird_Flight_Controller_B.Actuator_output.rudder =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);
      }

      // BusCreator: '<S1459>/Bus Creator' incorporates:
      //   Constant: '<S1459>/Constant'
      //   DataTypeConversion: '<S1459>/Cast To Boolean6'

      Hummingbird_Flight_Controller_B.Actuator_output.arm_1 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant_Value_ej);
      Hummingbird_Flight_Controller_B.Actuator_output.arm_2 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant_Value_ej);
      Hummingbird_Flight_Controller_B.Actuator_output.arm_3 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant_Value_ej);
      Hummingbird_Flight_Controller_B.Actuator_output.arm_4 =
        static_cast<real32_T>(Hummingbird_Flight_Controller_P.Constant_Value_ej);
      break;

     default:
      // case IN_Start:
      if ((Hummingbird_Flight_Controller_B.BusCreator.Flight_Mode < 1200) &&
          (Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode < 1200)) {
        Hummingbird_Flight_Controlle_DW.is_Controller =
          Hummingbird_Flight_IN_FW_Manual;

        // DataTypeConversion: '<S1459>/Cast To Boolean4' incorporates:
        //   Constant: '<S1459>/Constant1'

        for (Hummingbird_Flight_Controller_B.i = 0;
             Hummingbird_Flight_Controller_B.i < 8;
             Hummingbird_Flight_Controller_B.i++) {
          Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[Hummingbird_Flight_Controller_B.i]
            = static_cast<real32_T>
            (Hummingbird_Flight_Controller_P.Constant1_Value_o[Hummingbird_Flight_Controller_B.i]);
        }

        // BusCreator: '<S1459>/Bus Creator'
        Hummingbird_Flight_Controller_B.Actuator_output.rotor_1 =
          Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[0];
        Hummingbird_Flight_Controller_B.Actuator_output.rotor_2 =
          Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[1];
        Hummingbird_Flight_Controller_B.Actuator_output.rotor_3 =
          Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[2];
        Hummingbird_Flight_Controller_B.Actuator_output.rotor_4 =
          Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[3];
        Hummingbird_Flight_Controller_B.Actuator_output.rotor_5 =
          Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[4];
        Hummingbird_Flight_Controller_B.Actuator_output.rotor_6 =
          Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[5];
        Hummingbird_Flight_Controller_B.Actuator_output.rotor_7 =
          Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[6];
        Hummingbird_Flight_Controller_B.Actuator_output.rotor_8 =
          Hummingbird_Flight_Controller_B.TmpSignalConversionAtSFunct[7];

        // If: '<S1477>/If' incorporates:
        //   BusCreator generated from: '<Root>/Chart1'

        if (Hummingbird_Flight_Controller_B.In1_fv.armed) {
          // Gain: '<S1476>/Gain10' incorporates:
          //   Constant: '<S1476>/Constant7'
          //   Sum: '<S1476>/Sum8'

          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 = (
            static_cast<real_T>
            (Hummingbird_Flight_Controller_B.BusCreator.Throttle) -
            Hummingbird_Flight_Controller_P.Constant7_Value_a) *
            Hummingbird_Flight_Controller_P.Gain10_Gain_bn;

          // Saturate: '<S1476>/Saturation'
          if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
              Hummingbird_Flight_Controller_P.Saturation_UpperSat_lz) {
            // BusCreator: '<S1459>/Bus Creator' incorporates:
            //   DataTypeConversion: '<S1459>/Cast To Boolean5'

            Hummingbird_Flight_Controller_B.Actuator_output.throttle =
              static_cast<real32_T>
              (Hummingbird_Flight_Controller_P.Saturation_UpperSat_lz);
          } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                     Hummingbird_Flight_Controller_P.Saturation_LowerSat_o) {
            // BusCreator: '<S1459>/Bus Creator' incorporates:
            //   DataTypeConversion: '<S1459>/Cast To Boolean5'

            Hummingbird_Flight_Controller_B.Actuator_output.throttle =
              static_cast<real32_T>
              (Hummingbird_Flight_Controller_P.Saturation_LowerSat_o);
          } else {
            // BusCreator: '<S1459>/Bus Creator' incorporates:
            //   DataTypeConversion: '<S1459>/Cast To Boolean5'

            Hummingbird_Flight_Controller_B.Actuator_output.throttle =
              static_cast<real32_T>
              (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);
          }
        } else {
          // BusCreator: '<S1459>/Bus Creator' incorporates:
          //   Constant: '<S1459>/Constant2'
          //   DataTypeConversion: '<S1459>/Cast To Boolean5'

          Hummingbird_Flight_Controller_B.Actuator_output.throttle =
            static_cast<real32_T>
            (Hummingbird_Flight_Controller_P.Constant2_Value_o);
        }

        // Gain: '<S1473>/Gain10' incorporates:
        //   Constant: '<S1473>/Constant7'
        //   Sum: '<S1473>/Sum8'

        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 = (static_cast<
          real_T>(Hummingbird_Flight_Controller_B.BusCreator.Roll) -
          Hummingbird_Flight_Controller_P.Constant7_Value_p) *
          Hummingbird_Flight_Controller_P.Gain10_Gain_ap;

        // Saturate: '<S1473>/Saturation'
        if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_dq) {
          // BusCreator: '<S1459>/Bus Creator' incorporates:
          //   DataTypeConversion: '<S1459>/Cast To Boolean2'

          Hummingbird_Flight_Controller_B.Actuator_output.ailerons =
            static_cast<real32_T>
            (Hummingbird_Flight_Controller_P.Saturation_UpperSat_dq);
        } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                   Hummingbird_Flight_Controller_P.Saturation_LowerSat_du) {
          // BusCreator: '<S1459>/Bus Creator' incorporates:
          //   DataTypeConversion: '<S1459>/Cast To Boolean2'

          Hummingbird_Flight_Controller_B.Actuator_output.ailerons =
            static_cast<real32_T>
            (Hummingbird_Flight_Controller_P.Saturation_LowerSat_du);
        } else {
          // BusCreator: '<S1459>/Bus Creator' incorporates:
          //   DataTypeConversion: '<S1459>/Cast To Boolean2'

          Hummingbird_Flight_Controller_B.Actuator_output.ailerons =
            static_cast<real32_T>
            (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);
        }

        // Gain: '<S1474>/Gain10' incorporates:
        //   Constant: '<S1474>/Constant7'
        //   Sum: '<S1474>/Sum8'

        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Pitch)
           - Hummingbird_Flight_Controller_P.Constant7_Value_kf) *
          Hummingbird_Flight_Controller_P.Gain10_Gain_nx;

        // Saturate: '<S1474>/Saturation'
        if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_i) {
          // BusCreator: '<S1459>/Bus Creator' incorporates:
          //   DataTypeConversion: '<S1459>/Cast To Boolean1'

          Hummingbird_Flight_Controller_B.Actuator_output.elevator =
            static_cast<real32_T>
            (Hummingbird_Flight_Controller_P.Saturation_UpperSat_i);
        } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                   Hummingbird_Flight_Controller_P.Saturation_LowerSat_bn) {
          // BusCreator: '<S1459>/Bus Creator' incorporates:
          //   DataTypeConversion: '<S1459>/Cast To Boolean1'

          Hummingbird_Flight_Controller_B.Actuator_output.elevator =
            static_cast<real32_T>
            (Hummingbird_Flight_Controller_P.Saturation_LowerSat_bn);
        } else {
          // BusCreator: '<S1459>/Bus Creator' incorporates:
          //   DataTypeConversion: '<S1459>/Cast To Boolean1'

          Hummingbird_Flight_Controller_B.Actuator_output.elevator =
            static_cast<real32_T>
            (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);
        }

        // Gain: '<S1475>/Gain10' incorporates:
        //   Constant: '<S1475>/Constant7'
        //   Sum: '<S1475>/Sum8'

        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          (static_cast<real_T>(Hummingbird_Flight_Controller_B.BusCreator.Yaw) -
           Hummingbird_Flight_Controller_P.Constant7_Value_l3) *
          Hummingbird_Flight_Controller_P.Gain10_Gain_f;

        // Saturate: '<S1475>/Saturation'
        if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_oe) {
          // BusCreator: '<S1459>/Bus Creator' incorporates:
          //   DataTypeConversion: '<S1459>/Cast To Boolean3'

          Hummingbird_Flight_Controller_B.Actuator_output.rudder =
            static_cast<real32_T>
            (Hummingbird_Flight_Controller_P.Saturation_UpperSat_oe);
        } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                   Hummingbird_Flight_Controller_P.Saturation_LowerSat_e) {
          // BusCreator: '<S1459>/Bus Creator' incorporates:
          //   DataTypeConversion: '<S1459>/Cast To Boolean3'

          Hummingbird_Flight_Controller_B.Actuator_output.rudder =
            static_cast<real32_T>
            (Hummingbird_Flight_Controller_P.Saturation_LowerSat_e);
        } else {
          // BusCreator: '<S1459>/Bus Creator' incorporates:
          //   DataTypeConversion: '<S1459>/Cast To Boolean3'

          Hummingbird_Flight_Controller_B.Actuator_output.rudder =
            static_cast<real32_T>
            (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);
        }

        // BusCreator: '<S1459>/Bus Creator' incorporates:
        //   Constant: '<S1459>/Constant'
        //   DataTypeConversion: '<S1459>/Cast To Boolean6'

        Hummingbird_Flight_Controller_B.Actuator_output.arm_1 =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant_Value_ej);
        Hummingbird_Flight_Controller_B.Actuator_output.arm_2 =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant_Value_ej);
        Hummingbird_Flight_Controller_B.Actuator_output.arm_3 =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant_Value_ej);
        Hummingbird_Flight_Controller_B.Actuator_output.arm_4 =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant_Value_ej);
      } else {
        Hummingbird_Flight_Controlle_DW.is_Controller =
          Hummingbird_Fligh_IN_Controlled;
        Hummingbird_Fl_PX4Timestamp
          (&Hummingbird_Flight_Controller_B.PX4Timestamp_j2);

        // Chart: '<S1458>/Chart'
        Hummingbird_Flight_Controller_B.RC_Flight_Mode_prev_g =
          Hummingbird_Flight_Controlle_DW.RC_VTOL_Mode_start_b;
        Hummingbird_Flight_Controlle_DW.RC_VTOL_Mode_start_b =
          Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode;
        Hummingbird_Flight_Controller_B.RC_VTOL_Mode_prev_i =
          Hummingbird_Flight_Controlle_DW.RC_Flight_Mode_start_d;
        Hummingbird_Flight_Controlle_DW.RC_Flight_Mode_start_d =
          Hummingbird_Flight_Controller_B.BusCreator.Flight_Mode;
        if (Hummingbird_Flight_Controlle_DW.is_active_c9_Hummingbird_Flight == 0)
        {
          Hummingbird_Flight_Controlle_DW.RC_VTOL_Mode_start_b =
            Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode;
          Hummingbird_Flight_Controlle_DW.RC_Flight_Mode_start_d =
            Hummingbird_Flight_Controller_B.BusCreator.Flight_Mode;
          Hummingbird_Flight_Controlle_DW.is_active_c9_Hummingbird_Flight = 1U;
          if (Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode < 1200) {
            Hummingbird_Flight_Controlle_DW.is_Mixer_Control =
              Hummingbird_Flight_Contro_IN_FW;
            Hummingbird_Flight_Controller_B.i = 1;
          } else if (Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode < 1700)
          {
            Hummingbird_Flight_Controlle_DW.is_Mixer_Control =
              Hummingbird_Flight_Con_IN_Mixed;
            Hummingbird_Flight_Controller_B.i = 1;
          } else {
            Hummingbird_Flight_Controlle_DW.is_Mixer_Control =
              Hummingbird_Flight_Contro_IN_MR;
            Hummingbird_Flight_Controller_B.i = 0;
          }
        } else if ((Hummingbird_Flight_Controller_B.RC_Flight_Mode_prev_g !=
                    Hummingbird_Flight_Controlle_DW.RC_VTOL_Mode_start_b) ||
                   (Hummingbird_Flight_Controller_B.RC_VTOL_Mode_prev_i !=
                    Hummingbird_Flight_Controlle_DW.RC_Flight_Mode_start_d)) {
          if (Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode < 1200) {
            Hummingbird_Flight_Controlle_DW.is_Mixer_Control =
              Hummingbird_Flight_Contro_IN_FW;
            Hummingbird_Flight_Controller_B.i = 1;
          } else if (Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode < 1700)
          {
            Hummingbird_Flight_Controlle_DW.is_Mixer_Control =
              Hummingbird_Flight_Con_IN_Mixed;
            Hummingbird_Flight_Controller_B.i = 1;
          } else {
            Hummingbird_Flight_Controlle_DW.is_Mixer_Control =
              Hummingbird_Flight_Contro_IN_MR;
            Hummingbird_Flight_Controller_B.i = 0;
          }
        } else {
          switch (Hummingbird_Flight_Controlle_DW.is_Mixer_Control) {
           case Hummingbird_Flight_Contro_IN_FW:
            Hummingbird_Flight_Controller_B.i = 1;
            break;

           case Hummingbird_Flight_Contro_IN_MR:
            Hummingbird_Flight_Controller_B.i = 0;
            break;

           default:
            // case IN_Mixed:
            Hummingbird_Flight_Controller_B.i = 1;
            break;
          }
        }

        // Product: '<S1458>/Product1'
        Hummingbird_Flight_Controller_B.Sum_e[0] =
          Hummingbird_Flight_Controller_B.dM[0] * static_cast<real_T>
          (Hummingbird_Flight_Controller_B.i);
        Hummingbird_Flight_Controller_B.Sum_e[1] =
          Hummingbird_Flight_Controller_B.dM[1] * static_cast<real_T>
          (Hummingbird_Flight_Controller_B.i);
        Hummingbird_Flight_Controller_B.Sum_e[2] =
          Hummingbird_Flight_Controller_B.dM[2] * static_cast<real_T>
          (Hummingbird_Flight_Controller_B.i);

        // Switch: '<S1458>/Switch3' incorporates:
        //   BusCreator generated from: '<Root>/Chart1'
        //   Constant: '<S1458>/Constant29'

        if (!(Hummingbird_Flight_Controller_B.CastToDouble8 >
              Hummingbird_Flight_Controller_P.Switch3_Threshold)) {
          Hummingbird_Flight_Controller_B.CastToDouble8 =
            Hummingbird_Flight_Controller_P.Constant29_Value;
        }

        // MATLAB Function: '<S1458>/Control input Calculation' incorporates:
        //   Constant: '<S1458>/Constant2'

        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
          Hummingbird_Flight_Controller_B.CastToDouble8 *
          Hummingbird_Flight_Controller_B.CastToDouble8;
        for (Hummingbird_Flight_Controller_B.i = 0;
             Hummingbird_Flight_Controller_B.i < 9;
             Hummingbird_Flight_Controller_B.i++) {
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i] =
            b_a[Hummingbird_Flight_Controller_B.i] *
            Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0;
        }

        Hummingbird_Flight_Controller_B.i = 0;
        Hummingbird_Flight_Controller_B.r2_o = 1;
        Hummingbird_Flight_Controller_B.r3_n = 2;
        if (fabs(Hummingbird_Flight_Controller_B.x[2]) >
            Hummingbird_Flight_Controller_B.x[0]) {
          Hummingbird_Flight_Controller_B.i = 2;
          Hummingbird_Flight_Controller_B.r3_n = 0;
        }

        Hummingbird_Flight_Controller_B.x[1] /=
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n] /=
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];
        Hummingbird_Flight_Controller_B.x[4] -=
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
          3] * Hummingbird_Flight_Controller_B.x[1];
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n +
          3] -=
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
          3] *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n];
        Hummingbird_Flight_Controller_B.x[7] -=
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
          6] * Hummingbird_Flight_Controller_B.x[1];
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n +
          6] -=
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
          6] *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n];
        if (fabs
            (Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n
             + 3]) > fabs(Hummingbird_Flight_Controller_B.x[4])) {
          Hummingbird_Flight_Controller_B.r2_o =
            Hummingbird_Flight_Controller_B.r3_n;
          Hummingbird_Flight_Controller_B.r3_n = 1;
        }

        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n +
          3] /=
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o
          + 3];
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n +
          6] -=
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n
          + 3] *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o
          + 6];
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.i];
        Hummingbird_Flight_Controller_B.Esp_dot =
          Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.r2_o]
          - Hummingbird_Flight_Controller_B.scale *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
        Hummingbird_Flight_Controller_B.V =
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n
          + 3];
        Hummingbird_Flight_Controller_B.IntegralGain_k =
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n
          + 6];
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          ((Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.r3_n]
            - Hummingbird_Flight_Controller_B.scale *
            Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n])
           - Hummingbird_Flight_Controller_B.V *
           Hummingbird_Flight_Controller_B.Esp_dot) /
          Hummingbird_Flight_Controller_B.IntegralGain_k;
        Hummingbird_Flight_Controller_B.a[2] =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
        Hummingbird_Flight_Controller_B.CastToDouble25_f =
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o
          + 6];
        Hummingbird_Flight_Controller_B.course =
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o
          + 3];
        Hummingbird_Flight_Controller_B.Esp_dot =
          (Hummingbird_Flight_Controller_B.Esp_dot -
           Hummingbird_Flight_Controller_B.CastToDouble25_f *
           Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) /
          Hummingbird_Flight_Controller_B.course;
        Hummingbird_Flight_Controller_B.a[1] =
          Hummingbird_Flight_Controller_B.Esp_dot;
        Hummingbird_Flight_Controller_B.t =
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
          6];
        Hummingbird_Flight_Controller_B.CastToDouble25 =
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
          3];
        Hummingbird_Flight_Controller_B.a[0] =
          ((Hummingbird_Flight_Controller_B.scale -
            Hummingbird_Flight_Controller_B.t *
            Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) -
           Hummingbird_Flight_Controller_B.CastToDouble25 *
           Hummingbird_Flight_Controller_B.Esp_dot) /
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 = 0.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.i
          + 3];
        Hummingbird_Flight_Controller_B.Esp_dot =
          Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.r2_o
          + 3] - Hummingbird_Flight_Controller_B.scale *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          ((Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.r3_n
            + 3] - Hummingbird_Flight_Controller_B.scale *
            Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n])
           - Hummingbird_Flight_Controller_B.V *
           Hummingbird_Flight_Controller_B.Esp_dot) /
          Hummingbird_Flight_Controller_B.IntegralGain_k;
        Hummingbird_Flight_Controller_B.a[5] =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
        Hummingbird_Flight_Controller_B.Esp_dot =
          (Hummingbird_Flight_Controller_B.Esp_dot -
           Hummingbird_Flight_Controller_B.CastToDouble25_f *
           Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) /
          Hummingbird_Flight_Controller_B.course;
        Hummingbird_Flight_Controller_B.a[4] =
          Hummingbird_Flight_Controller_B.Esp_dot;
        Hummingbird_Flight_Controller_B.a[3] =
          ((Hummingbird_Flight_Controller_B.scale -
            Hummingbird_Flight_Controller_B.t *
            Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) -
           Hummingbird_Flight_Controller_B.CastToDouble25 *
           Hummingbird_Flight_Controller_B.Esp_dot) /
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 = 0.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.i
          + 6];
        Hummingbird_Flight_Controller_B.Esp_dot =
          Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.r2_o
          + 6] - Hummingbird_Flight_Controller_B.scale *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          ((Hummingbird_Flight_Controller_P.Constant2_Value[Hummingbird_Flight_Controller_B.r3_n
            + 6] - Hummingbird_Flight_Controller_B.scale *
            Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n])
           - Hummingbird_Flight_Controller_B.V *
           Hummingbird_Flight_Controller_B.Esp_dot) /
          Hummingbird_Flight_Controller_B.IntegralGain_k;
        Hummingbird_Flight_Controller_B.a[8] =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
        Hummingbird_Flight_Controller_B.Esp_dot =
          (Hummingbird_Flight_Controller_B.Esp_dot -
           Hummingbird_Flight_Controller_B.CastToDouble25_f *
           Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) /
          Hummingbird_Flight_Controller_B.course;
        Hummingbird_Flight_Controller_B.a[7] =
          Hummingbird_Flight_Controller_B.Esp_dot;
        Hummingbird_Flight_Controller_B.a[6] =
          ((Hummingbird_Flight_Controller_B.scale -
            Hummingbird_Flight_Controller_B.t *
            Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) -
           Hummingbird_Flight_Controller_B.CastToDouble25 *
           Hummingbird_Flight_Controller_B.Esp_dot) /
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 = 0.0;
        for (Hummingbird_Flight_Controller_B.i = 0;
             Hummingbird_Flight_Controller_B.i < 3;
             Hummingbird_Flight_Controller_B.i++) {
          Hummingbird_Flight_Controller_B.scale =
            Hummingbird_Flight_Controller_B.Sum_e[Hummingbird_Flight_Controller_B.i];
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 +=
            Hummingbird_Flight_Controller_B.a[3 *
            Hummingbird_Flight_Controller_B.i] *
            Hummingbird_Flight_Controller_B.scale;
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 +=
            Hummingbird_Flight_Controller_B.a[3 *
            Hummingbird_Flight_Controller_B.i + 1] *
            Hummingbird_Flight_Controller_B.scale;
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 +=
            Hummingbird_Flight_Controller_B.a[3 *
            Hummingbird_Flight_Controller_B.i + 2] *
            Hummingbird_Flight_Controller_B.scale;
        }

        // Switch: '<S1458>/Switch' incorporates:
        //   Constant: '<S1458>/Constant7'
        //   RelationalOperator: '<S1458>/IsNaN'

        if (rtIsNaN(Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0)) {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
            Hummingbird_Flight_Controller_P.Constant7_Value_k;
        }

        // Switch: '<S1458>/Switch4' incorporates:
        //   Constant: '<S1458>/Constant4'
        //   RelationalOperator: '<S1458>/IsNaN3'

        if (rtIsNaN(Hummingbird_Flight_Controller_B.dtFW)) {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
            Hummingbird_Flight_Controller_P.Constant4_Value_g;
        } else {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 =
            Hummingbird_Flight_Controller_B.dtFW;
        }

        // Switch: '<S1458>/Switch1' incorporates:
        //   Constant: '<S1458>/Constant8'
        //   RelationalOperator: '<S1458>/IsNaN1'

        if (rtIsNaN(Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1))
        {
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
            Hummingbird_Flight_Controller_P.Constant8_Value;
        }

        // Switch: '<S1458>/Switch2' incorporates:
        //   Constant: '<S1458>/Constant9'
        //   RelationalOperator: '<S1458>/IsNaN2'

        if (rtIsNaN(Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0))
        {
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
            Hummingbird_Flight_Controller_P.Constant9_Value;
        }

        // BusAssignment: '<S1464>/Bus Assignment' incorporates:
        //   DataTypeConversion: '<S1458>/Cast To Boolean1'
        //   MATLABSystem: '<S1464>/PX4 Timestamp'

        Hummingbird_Flight_Controller_B.BusAssignment_c.timestamp =
          Hummingbird_Flight_Controller_B.PX4Timestamp_j2.PX4Timestamp;
        Hummingbird_Flight_Controller_B.BusAssignment_c.de = static_cast<
          real32_T>(Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0);
        Hummingbird_Flight_Controller_B.BusAssignment_c.dt =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1);
        Hummingbird_Flight_Controller_B.BusAssignment_c.da =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);
        Hummingbird_Flight_Controller_B.BusAssignment_c.dr =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);

        // MATLABSystem: '<S1470>/SinkBlock' incorporates:
        //   BusAssignment: '<S1464>/Bus Assignment'

        uORB_write_step(Hummingbird_Flight_Controlle_DW.obj_c.orbMetadataObj,
                        &Hummingbird_Flight_Controlle_DW.obj_c.orbAdvertiseObj,
                        &Hummingbird_Flight_Controller_B.BusAssignment_c);
        Hummingbird_Fl_PX4Timestamp
          (&Hummingbird_Flight_Controller_B.PX4Timestamp_pm);

        // Sum: '<S1460>/Sum17'
        Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
          Hummingbird_Flight_Controller_B.dtMR +
          Hummingbird_Flight_Controller_B.a_n;

        // Saturate: '<S1460>/Saturation3'
        if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 >
            Hummingbird_Flight_Controller_P.Saturation3_UpperSat) {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
            Hummingbird_Flight_Controller_P.Saturation3_UpperSat;
        } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 <
                   Hummingbird_Flight_Controller_P.Saturation3_LowerSat) {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 =
            Hummingbird_Flight_Controller_P.Saturation3_LowerSat;
        }

        // Gain: '<S1468>/Gain' incorporates:
        //   Constant: '<S1468>/Constant'
        //   Product: '<S1468>/Divide'

        Hummingbird_Flight_Controller_B.CastToDouble8 =
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2 /
          Hummingbird_Flight_Controller_P.Constant_Value_li *
          Hummingbird_Flight_Controller_P.Gain_Gain_b;

        // MATLAB Function: '<S1458>/Control input Calculation1' incorporates:
        //   Constant: '<S1458>/Constant12'
        //   Constant: '<S1458>/Constant13'

        memcpy(&Hummingbird_Flight_Controller_B.x[0],
               &Hummingbird_Flight_Controller_P.Constant12_Value[0], 9U * sizeof
               (real_T));
        Hummingbird_Flight_Controller_B.i = 0;
        Hummingbird_Flight_Controller_B.r2_o = 1;
        Hummingbird_Flight_Controller_B.r3_n = 2;
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 = fabs
          (Hummingbird_Flight_Controller_P.Constant12_Value[0]);
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 = fabs
          (Hummingbird_Flight_Controller_P.Constant12_Value[1]);
        if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 >
            Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0) {
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 =
            Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1;
          Hummingbird_Flight_Controller_B.i = 1;
          Hummingbird_Flight_Controller_B.r2_o = 0;
        }

        if (fabs(Hummingbird_Flight_Controller_P.Constant12_Value[2]) >
            Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0) {
          Hummingbird_Flight_Controller_B.i = 2;
          Hummingbird_Flight_Controller_B.r2_o = 1;
          Hummingbird_Flight_Controller_B.r3_n = 0;
        }

        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o] =
          Hummingbird_Flight_Controller_P.Constant12_Value[Hummingbird_Flight_Controller_B.r2_o]
          /
          Hummingbird_Flight_Controller_P.Constant12_Value[Hummingbird_Flight_Controller_B.i];
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n] /=
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o +
          3] -=
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
          3] *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n +
          3] -=
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
          3] *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n];
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o +
          6] -=
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
          6] *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n +
          6] -=
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
          6] *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n];
        if (fabs
            (Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n
             + 3]) > fabs
            (Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o
             + 3])) {
          Hummingbird_Flight_Controller_B.rtemp =
            Hummingbird_Flight_Controller_B.r2_o;
          Hummingbird_Flight_Controller_B.r2_o =
            Hummingbird_Flight_Controller_B.r3_n;
          Hummingbird_Flight_Controller_B.r3_n =
            Hummingbird_Flight_Controller_B.rtemp;
        }

        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n +
          3] /=
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o
          + 3];
        Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n +
          6] -=
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n
          + 3] *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o
          + 6];
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.i];
        Hummingbird_Flight_Controller_B.Esp_dot =
          Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.r2_o]
          - Hummingbird_Flight_Controller_B.scale *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
        Hummingbird_Flight_Controller_B.V =
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n
          + 3];
        Hummingbird_Flight_Controller_B.IntegralGain_k =
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n
          + 6];
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          ((Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.r3_n]
            - Hummingbird_Flight_Controller_B.scale *
            Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n])
           - Hummingbird_Flight_Controller_B.V *
           Hummingbird_Flight_Controller_B.Esp_dot) /
          Hummingbird_Flight_Controller_B.IntegralGain_k;
        Hummingbird_Flight_Controller_B.a_m[2] =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
        Hummingbird_Flight_Controller_B.CastToDouble25_f =
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o
          + 6];
        Hummingbird_Flight_Controller_B.course =
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o
          + 3];
        Hummingbird_Flight_Controller_B.Esp_dot =
          (Hummingbird_Flight_Controller_B.Esp_dot -
           Hummingbird_Flight_Controller_B.CastToDouble25_f *
           Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) /
          Hummingbird_Flight_Controller_B.course;
        Hummingbird_Flight_Controller_B.a_m[1] =
          Hummingbird_Flight_Controller_B.Esp_dot;
        Hummingbird_Flight_Controller_B.t =
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
          6];
        Hummingbird_Flight_Controller_B.CastToDouble25 =
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i +
          3];
        Hummingbird_Flight_Controller_B.a_m[0] =
          ((Hummingbird_Flight_Controller_B.scale -
            Hummingbird_Flight_Controller_B.t *
            Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) -
           Hummingbird_Flight_Controller_B.CastToDouble25 *
           Hummingbird_Flight_Controller_B.Esp_dot) /
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];

        // Sum: '<S1458>/Sum8'
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[0] =
          Hummingbird_Flight_Controller_B.dM[0] -
          Hummingbird_Flight_Controller_B.Sum_e[0];

        // MATLAB Function: '<S1458>/Control input Calculation1' incorporates:
        //   Constant: '<S1458>/Constant13'

        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 = 0.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.i +
          3];
        Hummingbird_Flight_Controller_B.Esp_dot =
          Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.r2_o
          + 3] - Hummingbird_Flight_Controller_B.scale *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          ((Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.r3_n
            + 3] - Hummingbird_Flight_Controller_B.scale *
            Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n])
           - Hummingbird_Flight_Controller_B.V *
           Hummingbird_Flight_Controller_B.Esp_dot) /
          Hummingbird_Flight_Controller_B.IntegralGain_k;
        Hummingbird_Flight_Controller_B.a_m[5] =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
        Hummingbird_Flight_Controller_B.Esp_dot =
          (Hummingbird_Flight_Controller_B.Esp_dot -
           Hummingbird_Flight_Controller_B.CastToDouble25_f *
           Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) /
          Hummingbird_Flight_Controller_B.course;
        Hummingbird_Flight_Controller_B.a_m[4] =
          Hummingbird_Flight_Controller_B.Esp_dot;
        Hummingbird_Flight_Controller_B.a_m[3] =
          ((Hummingbird_Flight_Controller_B.scale -
            Hummingbird_Flight_Controller_B.t *
            Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) -
           Hummingbird_Flight_Controller_B.CastToDouble25 *
           Hummingbird_Flight_Controller_B.Esp_dot) /
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];

        // Sum: '<S1458>/Sum8'
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[1] =
          Hummingbird_Flight_Controller_B.dM[1] -
          Hummingbird_Flight_Controller_B.Sum_e[1];

        // MATLAB Function: '<S1458>/Control input Calculation1' incorporates:
        //   Constant: '<S1458>/Constant13'

        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 = 0.0;
        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.i +
          6];
        Hummingbird_Flight_Controller_B.Esp_dot =
          Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.r2_o
          + 6] - Hummingbird_Flight_Controller_B.scale *
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r2_o];
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          ((Hummingbird_Flight_Controller_P.IB[Hummingbird_Flight_Controller_B.r3_n
            + 6] - Hummingbird_Flight_Controller_B.scale *
            Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.r3_n])
           - Hummingbird_Flight_Controller_B.V *
           Hummingbird_Flight_Controller_B.Esp_dot) /
          Hummingbird_Flight_Controller_B.IntegralGain_k;
        Hummingbird_Flight_Controller_B.a_m[8] =
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;
        Hummingbird_Flight_Controller_B.Esp_dot =
          (Hummingbird_Flight_Controller_B.Esp_dot -
           Hummingbird_Flight_Controller_B.CastToDouble25_f *
           Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) /
          Hummingbird_Flight_Controller_B.course;
        Hummingbird_Flight_Controller_B.a_m[7] =
          Hummingbird_Flight_Controller_B.Esp_dot;
        Hummingbird_Flight_Controller_B.a_m[6] =
          ((Hummingbird_Flight_Controller_B.scale -
            Hummingbird_Flight_Controller_B.t *
            Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) -
           Hummingbird_Flight_Controller_B.CastToDouble25 *
           Hummingbird_Flight_Controller_B.Esp_dot) /
          Hummingbird_Flight_Controller_B.x[Hummingbird_Flight_Controller_B.i];

        // Sum: '<S1458>/Sum8'
        Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[2] =
          Hummingbird_Flight_Controller_B.dM[2] -
          Hummingbird_Flight_Controller_B.Sum_e[2];

        // MATLAB Function: '<S1458>/Control input Calculation1'
        Hummingbird_Flight_Controller_B.b_t = 0.0;
        for (Hummingbird_Flight_Controller_B.i = 0;
             Hummingbird_Flight_Controller_B.i < 3;
             Hummingbird_Flight_Controller_B.i++) {
          Hummingbird_Flight_Controller_B.scale =
            Hummingbird_Flight_Controller_B.rtb_DProdOut_n_c[Hummingbird_Flight_Controller_B.i];
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 +=
            Hummingbird_Flight_Controller_B.a_m[3 *
            Hummingbird_Flight_Controller_B.i] *
            Hummingbird_Flight_Controller_B.scale;
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 +=
            Hummingbird_Flight_Controller_B.a_m[3 *
            Hummingbird_Flight_Controller_B.i + 1] *
            Hummingbird_Flight_Controller_B.scale;
          Hummingbird_Flight_Controller_B.b_t +=
            Hummingbird_Flight_Controller_B.a_m[3 *
            Hummingbird_Flight_Controller_B.i + 2] *
            Hummingbird_Flight_Controller_B.scale;
        }

        // Sum: '<S1460>/Sum10' incorporates:
        //   MATLAB Function: '<S1458>/Control input Calculation1'

        Hummingbird_Flight_Controller_B.Sum_e[0] =
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0 +
          Hummingbird_Flight_Controller_B.ParamStep_i;
        Hummingbird_Flight_Controller_B.Sum_e[1] =
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1 +
          Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0;
        Hummingbird_Flight_Controller_B.Sum_e[2] =
          Hummingbird_Flight_Controller_B.b_t +
          Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1;

        // Saturate: '<S1468>/Saturation9'
        if (Hummingbird_Flight_Controller_B.Sum_e[0] >
            Hummingbird_Flight_Controller_P.Saturation9_UpperSat) {
          Hummingbird_Flight_Controller_B.scale =
            Hummingbird_Flight_Controller_P.Saturation9_UpperSat;
        } else if (Hummingbird_Flight_Controller_B.Sum_e[0] <
                   Hummingbird_Flight_Controller_P.Saturation9_LowerSat) {
          Hummingbird_Flight_Controller_B.scale =
            Hummingbird_Flight_Controller_P.Saturation9_LowerSat;
        } else {
          Hummingbird_Flight_Controller_B.scale =
            Hummingbird_Flight_Controller_B.Sum_e[0];
        }

        // Product: '<S1468>/Divide3' incorporates:
        //   Constant: '<S1468>/Constant2'
        //   Saturate: '<S1468>/Saturation9'

        Hummingbird_Flight_Controller_B.CastToDouble25 =
          Hummingbird_Flight_Controller_B.scale /
          Hummingbird_Flight_Controller_P.Constant2_Value_a;

        // Saturate: '<S1468>/Saturation8'
        if (Hummingbird_Flight_Controller_B.Sum_e[1] >
            Hummingbird_Flight_Controller_P.Saturation8_UpperSat) {
          Hummingbird_Flight_Controller_B.scale =
            Hummingbird_Flight_Controller_P.Saturation8_UpperSat;
        } else if (Hummingbird_Flight_Controller_B.Sum_e[1] <
                   Hummingbird_Flight_Controller_P.Saturation8_LowerSat) {
          Hummingbird_Flight_Controller_B.scale =
            Hummingbird_Flight_Controller_P.Saturation8_LowerSat;
        } else {
          Hummingbird_Flight_Controller_B.scale =
            Hummingbird_Flight_Controller_B.Sum_e[1];
        }

        // Product: '<S1468>/Divide2' incorporates:
        //   Constant: '<S1468>/Constant1'
        //   Saturate: '<S1468>/Saturation8'

        Hummingbird_Flight_Controller_B.t =
          Hummingbird_Flight_Controller_B.scale /
          Hummingbird_Flight_Controller_P.Constant1_Value_p;

        // Saturate: '<S1468>/Saturation10'
        if (Hummingbird_Flight_Controller_B.Sum_e[2] >
            Hummingbird_Flight_Controller_P.Saturation10_UpperSat) {
          Hummingbird_Flight_Controller_B.scale =
            Hummingbird_Flight_Controller_P.Saturation10_UpperSat;
        } else if (Hummingbird_Flight_Controller_B.Sum_e[2] <
                   Hummingbird_Flight_Controller_P.Saturation10_LowerSat) {
          Hummingbird_Flight_Controller_B.scale =
            Hummingbird_Flight_Controller_P.Saturation10_LowerSat;
        } else {
          Hummingbird_Flight_Controller_B.scale =
            Hummingbird_Flight_Controller_B.Sum_e[2];
        }

        // Product: '<S1468>/Divide1' incorporates:
        //   Constant: '<S1468>/Constant3'
        //   Saturate: '<S1468>/Saturation10'

        Hummingbird_Flight_Controller_B.scale /=
          Hummingbird_Flight_Controller_P.Constant3_Value_k;

        // Sum: '<S1468>/Add'
        Hummingbird_Flight_Controller_B.Esp_dot =
          ((Hummingbird_Flight_Controller_B.scale -
            Hummingbird_Flight_Controller_B.CastToDouble8) -
           Hummingbird_Flight_Controller_B.CastToDouble25) -
          Hummingbird_Flight_Controller_B.t;

        // Saturate: '<S1468>/Saturation'
        if (Hummingbird_Flight_Controller_B.Esp_dot >
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_o) {
          Hummingbird_Flight_Controller_B.Esp_dot =
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_o;
        } else if (Hummingbird_Flight_Controller_B.Esp_dot <
                   Hummingbird_Flight_Controller_P.Saturation_LowerSat_n) {
          Hummingbird_Flight_Controller_B.Esp_dot =
            Hummingbird_Flight_Controller_P.Saturation_LowerSat_n;
        }

        // Sum: '<S1468>/Add4'
        Hummingbird_Flight_Controller_B.V = (((0.0 -
          Hummingbird_Flight_Controller_B.CastToDouble8) -
          Hummingbird_Flight_Controller_B.CastToDouble25) -
          Hummingbird_Flight_Controller_B.t) -
          Hummingbird_Flight_Controller_B.scale;

        // Saturate: '<S1468>/Saturation4'
        if (Hummingbird_Flight_Controller_B.V >
            Hummingbird_Flight_Controller_P.Saturation4_UpperSat) {
          Hummingbird_Flight_Controller_B.V =
            Hummingbird_Flight_Controller_P.Saturation4_UpperSat;
        } else if (Hummingbird_Flight_Controller_B.V <
                   Hummingbird_Flight_Controller_P.Saturation4_LowerSat) {
          Hummingbird_Flight_Controller_B.V =
            Hummingbird_Flight_Controller_P.Saturation4_LowerSat;
        }

        // Sum: '<S1468>/Add1' incorporates:
        //   Sum: '<S1468>/Add2'
        //   Sum: '<S1468>/Add5'

        Hummingbird_Flight_Controller_B.CastToDouble25_f =
          Hummingbird_Flight_Controller_B.CastToDouble25 -
          Hummingbird_Flight_Controller_B.CastToDouble8;
        Hummingbird_Flight_Controller_B.r_c =
          Hummingbird_Flight_Controller_B.CastToDouble25_f -
          Hummingbird_Flight_Controller_B.t;
        Hummingbird_Flight_Controller_B.IntegralGain_k =
          Hummingbird_Flight_Controller_B.r_c -
          Hummingbird_Flight_Controller_B.scale;

        // Saturate: '<S1468>/Saturation1'
        if (Hummingbird_Flight_Controller_B.IntegralGain_k >
            Hummingbird_Flight_Controller_P.Saturation1_UpperSat_e) {
          Hummingbird_Flight_Controller_B.IntegralGain_k =
            Hummingbird_Flight_Controller_P.Saturation1_UpperSat_e;
        } else if (Hummingbird_Flight_Controller_B.IntegralGain_k <
                   Hummingbird_Flight_Controller_P.Saturation1_LowerSat_b) {
          Hummingbird_Flight_Controller_B.IntegralGain_k =
            Hummingbird_Flight_Controller_P.Saturation1_LowerSat_b;
        }

        // Sum: '<S1468>/Add5'
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
          Hummingbird_Flight_Controller_B.r_c +
          Hummingbird_Flight_Controller_B.scale;

        // Saturate: '<S1468>/Saturation5'
        if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 >
            Hummingbird_Flight_Controller_P.Saturation5_UpperSat) {
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
            Hummingbird_Flight_Controller_P.Saturation5_UpperSat;
        } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 <
                   Hummingbird_Flight_Controller_P.Saturation5_LowerSat) {
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2 =
            Hummingbird_Flight_Controller_P.Saturation5_LowerSat;
        }

        // Sum: '<S1468>/Add2' incorporates:
        //   Sum: '<S1468>/Add6'

        Hummingbird_Flight_Controller_B.r_c =
          Hummingbird_Flight_Controller_B.CastToDouble25_f +
          Hummingbird_Flight_Controller_B.t;
        Hummingbird_Flight_Controller_B.CastToDouble25_f =
          Hummingbird_Flight_Controller_B.r_c +
          Hummingbird_Flight_Controller_B.scale;

        // Saturate: '<S1468>/Saturation2'
        if (Hummingbird_Flight_Controller_B.CastToDouble25_f >
            Hummingbird_Flight_Controller_P.Saturation2_UpperSat_o) {
          Hummingbird_Flight_Controller_B.CastToDouble25_f =
            Hummingbird_Flight_Controller_P.Saturation2_UpperSat_o;
        } else if (Hummingbird_Flight_Controller_B.CastToDouble25_f <
                   Hummingbird_Flight_Controller_P.Saturation2_LowerSat_g) {
          Hummingbird_Flight_Controller_B.CastToDouble25_f =
            Hummingbird_Flight_Controller_P.Saturation2_LowerSat_g;
        }

        // Sum: '<S1468>/Add6'
        Hummingbird_Flight_Controller_B.course =
          Hummingbird_Flight_Controller_B.r_c -
          Hummingbird_Flight_Controller_B.scale;

        // Saturate: '<S1468>/Saturation6'
        if (Hummingbird_Flight_Controller_B.course >
            Hummingbird_Flight_Controller_P.Saturation6_UpperSat) {
          Hummingbird_Flight_Controller_B.course =
            Hummingbird_Flight_Controller_P.Saturation6_UpperSat;
        } else if (Hummingbird_Flight_Controller_B.course <
                   Hummingbird_Flight_Controller_P.Saturation6_LowerSat) {
          Hummingbird_Flight_Controller_B.course =
            Hummingbird_Flight_Controller_P.Saturation6_LowerSat;
        }

        // Sum: '<S1468>/Add3' incorporates:
        //   Sum: '<S1468>/Add7'

        Hummingbird_Flight_Controller_B.r_c = (Hummingbird_Flight_Controller_B.t
          - Hummingbird_Flight_Controller_B.CastToDouble8) -
          Hummingbird_Flight_Controller_B.CastToDouble25;
        Hummingbird_Flight_Controller_B.t = Hummingbird_Flight_Controller_B.r_c
          - Hummingbird_Flight_Controller_B.scale;

        // Saturate: '<S1468>/Saturation3'
        if (Hummingbird_Flight_Controller_B.t >
            Hummingbird_Flight_Controller_P.Saturation3_UpperSat_a) {
          Hummingbird_Flight_Controller_B.t =
            Hummingbird_Flight_Controller_P.Saturation3_UpperSat_a;
        } else if (Hummingbird_Flight_Controller_B.t <
                   Hummingbird_Flight_Controller_P.Saturation3_LowerSat_o) {
          Hummingbird_Flight_Controller_B.t =
            Hummingbird_Flight_Controller_P.Saturation3_LowerSat_o;
        }

        // Sum: '<S1468>/Add7'
        Hummingbird_Flight_Controller_B.CastToDouble8 =
          Hummingbird_Flight_Controller_B.r_c +
          Hummingbird_Flight_Controller_B.scale;

        // Saturate: '<S1468>/Saturation7'
        if (Hummingbird_Flight_Controller_B.CastToDouble8 >
            Hummingbird_Flight_Controller_P.Saturation7_UpperSat) {
          Hummingbird_Flight_Controller_B.CastToDouble8 =
            Hummingbird_Flight_Controller_P.Saturation7_UpperSat;
        } else if (Hummingbird_Flight_Controller_B.CastToDouble8 <
                   Hummingbird_Flight_Controller_P.Saturation7_LowerSat) {
          Hummingbird_Flight_Controller_B.CastToDouble8 =
            Hummingbird_Flight_Controller_P.Saturation7_LowerSat;
        }

        // Gain: '<S1467>/Gain1'
        Hummingbird_Flight_Controller_B.CastToDouble25 =
          Hummingbird_Flight_Controller_P.Gain1_Gain_hu *
          Hummingbird_Flight_Controller_B.IntegralGain_k;

        // Gain: '<S1467>/Gain2'
        Hummingbird_Flight_Controller_B.r_c =
          Hummingbird_Flight_Controller_P.Gain2_Gain_p *
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2;

        // Gain: '<S1467>/Gain3'
        Hummingbird_Flight_Controller_B.absxk =
          Hummingbird_Flight_Controller_P.Gain3_Gain_h *
          Hummingbird_Flight_Controller_B.CastToDouble25_f;

        // Gain: '<S1467>/Gain9'
        Hummingbird_Flight_Controller_B.b_gamma =
          Hummingbird_Flight_Controller_P.Gain9_Gain *
          Hummingbird_Flight_Controller_B.course;

        // Gain: '<S1467>/Gain10'
        Hummingbird_Flight_Controller_B.eta =
          Hummingbird_Flight_Controller_P.Gain10_Gain_b *
          Hummingbird_Flight_Controller_B.t;

        // Gain: '<S1467>/Gain11'
        Hummingbird_Flight_Controller_B.Add1 =
          Hummingbird_Flight_Controller_P.Gain11_Gain *
          Hummingbird_Flight_Controller_B.CastToDouble8;

        // BusAssignment: '<S1465>/Bus Assignment' incorporates:
        //   BusCreator: '<S5>/Bus Creator4'
        //   Constant: '<S1458>/Constant14'
        //   DataTypeConversion: '<S1458>/Cast To Boolean4'
        //   DataTypeConversion: '<S1458>/Cast To Boolean5'
        //   MATLAB Function: '<S1458>/Control input Calculation1'
        //   MATLABSystem: '<S1465>/PX4 Timestamp'

        Hummingbird_Flight_Controller_B.BusAssignment.timestamp =
          Hummingbird_Flight_Controller_B.PX4Timestamp_pm.PX4Timestamp;
        Hummingbird_Flight_Controller_B.BusAssignment.data[0] =
          static_cast<real32_T>(Hummingbird_Flight_Controller_B.Esp_dot);
        Hummingbird_Flight_Controller_B.BusAssignment.data[1] =
          static_cast<real32_T>(Hummingbird_Flight_Controller_B.V);
        Hummingbird_Flight_Controller_B.BusAssignment.data[2] =
          static_cast<real32_T>(Hummingbird_Flight_Controller_B.IntegralGain_k);
        Hummingbird_Flight_Controller_B.BusAssignment.data[3] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2);
        Hummingbird_Flight_Controller_B.BusAssignment.data[4] =
          static_cast<real32_T>(Hummingbird_Flight_Controller_B.CastToDouble25_f);
        Hummingbird_Flight_Controller_B.BusAssignment.data[5] =
          static_cast<real32_T>(Hummingbird_Flight_Controller_B.course);
        Hummingbird_Flight_Controller_B.BusAssignment.data[6] =
          static_cast<real32_T>(Hummingbird_Flight_Controller_B.t);
        Hummingbird_Flight_Controller_B.BusAssignment.data[7] =
          static_cast<real32_T>(Hummingbird_Flight_Controller_B.CastToDouble8);
        Hummingbird_Flight_Controller_B.BusAssignment.data[8] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_2);
        Hummingbird_Flight_Controller_B.BusAssignment.data[12] =
          static_cast<real32_T>(Hummingbird_Flight_Controller_B.dtMR);
        Hummingbird_Flight_Controller_B.BusAssignment.data[9] =
          static_cast<real32_T>(Hummingbird_Flight_Controller_B.Sum_e[0]);
        Hummingbird_Flight_Controller_B.BusAssignment.data[13] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_0);
        Hummingbird_Flight_Controller_B.BusAssignment.data[10] =
          static_cast<real32_T>(Hummingbird_Flight_Controller_B.Sum_e[1]);
        Hummingbird_Flight_Controller_B.BusAssignment.data[14] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_1);
        Hummingbird_Flight_Controller_B.BusAssignment.data[11] =
          static_cast<real32_T>(Hummingbird_Flight_Controller_B.Sum_e[2]);
        Hummingbird_Flight_Controller_B.BusAssignment.data[15] =
          static_cast<real32_T>(Hummingbird_Flight_Controller_B.b_t);
        Hummingbird_Flight_Controller_B.BusAssignment.data[16] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[17] =
          Hummingbird_Flight_Controller_B.a_n;
        Hummingbird_Flight_Controller_B.BusAssignment.data[18] =
          Hummingbird_Flight_Controller_B.ParamStep_i;
        Hummingbird_Flight_Controller_B.BusAssignment.data[19] =
          Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_0;
        Hummingbird_Flight_Controller_B.BusAssignment.data[20] =
          Hummingbird_Flight_Controller_B.rtb_CastToBoolean1_d_idx_1;
        Hummingbird_Flight_Controller_B.BusAssignment.data[21] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2);

        // Sum: '<S1467>/Add' incorporates:
        //   Gain: '<S1467>/Gain'
        //   Gain: '<S1467>/Gain8'
        //   Sum: '<S1467>/Add2'
        //   Sum: '<S1467>/Add3'

        Hummingbird_Flight_Controller_B.scale =
          Hummingbird_Flight_Controller_P.Gain_Gain_l *
          Hummingbird_Flight_Controller_B.Esp_dot +
          Hummingbird_Flight_Controller_P.Gain8_Gain *
          Hummingbird_Flight_Controller_B.V;
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 =
          (Hummingbird_Flight_Controller_B.scale +
           Hummingbird_Flight_Controller_B.CastToDouble25) +
          Hummingbird_Flight_Controller_B.r_c;

        // BusAssignment: '<S1465>/Bus Assignment' incorporates:
        //   Constant: '<S1458>/Constant1'
        //   Constant: '<S1458>/Constant10'
        //   Constant: '<S1458>/Constant14'
        //   Constant: '<S1458>/Constant15'
        //   Constant: '<S1467>/Constant1'
        //   Constant: '<S1467>/Constant2'
        //   DataTypeConversion: '<S1458>/Cast To Boolean4'
        //   Gain: '<S1467>/Gain12'
        //   Gain: '<S1467>/Gain13'
        //   Gain: '<S1467>/Gain14'
        //   Gain: '<S1467>/Gain15'
        //   Gain: '<S1467>/Gain4'
        //   Gain: '<S1467>/Gain5'
        //   Gain: '<S1467>/Gain6'
        //   Gain: '<S1467>/Gain7'
        //   Product: '<S1467>/Product'
        //   Product: '<S1467>/Product1'
        //   Sum: '<S1467>/Add'
        //   Sum: '<S1467>/Add1'
        //   Sum: '<S1467>/Add2'
        //   Sum: '<S1467>/Add3'

        Hummingbird_Flight_Controller_B.BusAssignment.data[22] =
          static_cast<real32_T>
          ((((Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 +
              Hummingbird_Flight_Controller_B.absxk) +
             Hummingbird_Flight_Controller_B.b_gamma) +
            Hummingbird_Flight_Controller_B.eta) +
           Hummingbird_Flight_Controller_B.Add1);
        Hummingbird_Flight_Controller_B.BusAssignment.data[23] =
          static_cast<real32_T>(((((((Hummingbird_Flight_Controller_B.scale -
          Hummingbird_Flight_Controller_B.CastToDouble25) -
          Hummingbird_Flight_Controller_B.r_c) -
          Hummingbird_Flight_Controller_B.absxk) -
          Hummingbird_Flight_Controller_B.b_gamma) +
          Hummingbird_Flight_Controller_B.eta) +
          Hummingbird_Flight_Controller_B.Add1) *
          Hummingbird_Flight_Controller_P.Constant2_Value_i);
        Hummingbird_Flight_Controller_B.BusAssignment.data[24] =
          static_cast<real32_T>
          (((((Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 -
               Hummingbird_Flight_Controller_B.absxk) -
              Hummingbird_Flight_Controller_B.b_gamma) -
             Hummingbird_Flight_Controller_B.eta) -
            Hummingbird_Flight_Controller_B.Add1) *
           Hummingbird_Flight_Controller_P.Constant1_Value_n);
        Hummingbird_Flight_Controller_B.BusAssignment.data[25] =
          static_cast<real32_T>
          (((((((Hummingbird_Flight_Controller_P.Gain4_Gain_k *
                 Hummingbird_Flight_Controller_B.Esp_dot -
                 Hummingbird_Flight_Controller_P.Gain12_Gain *
                 Hummingbird_Flight_Controller_B.V) -
                Hummingbird_Flight_Controller_P.Gain5_Gain *
                Hummingbird_Flight_Controller_B.IntegralGain_k) +
               Hummingbird_Flight_Controller_P.Gain13_Gain *
               Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2) +
              Hummingbird_Flight_Controller_P.Gain6_Gain *
              Hummingbird_Flight_Controller_B.CastToDouble25_f) -
             Hummingbird_Flight_Controller_P.Gain14_Gain *
             Hummingbird_Flight_Controller_B.course) -
            Hummingbird_Flight_Controller_P.Gain7_Gain *
            Hummingbird_Flight_Controller_B.t) +
           Hummingbird_Flight_Controller_P.Gain15_Gain *
           Hummingbird_Flight_Controller_B.CastToDouble8);
        Hummingbird_Flight_Controller_B.BusAssignment.data[26] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[27] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[28] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[29] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[30] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[31] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[32] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[33] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[34] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[35] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[36] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[37] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[38] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[39] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[40] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[41] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[42] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[43] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[44] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[45] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[46] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[47] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[48] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[49] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[50] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[51] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[52] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[53] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[54] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[55] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[56] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.data[57] =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant14_Value_e);
        Hummingbird_Flight_Controller_B.BusAssignment.id =
          Hummingbird_Flight_Controller_P.Constant15_Value;
        for (Hummingbird_Flight_Controller_B.i = 0;
             Hummingbird_Flight_Controller_B.i < 10;
             Hummingbird_Flight_Controller_B.i++) {
          Hummingbird_Flight_Controller_B.BusAssignment.name[Hummingbird_Flight_Controller_B.i]
            =
            Hummingbird_Flight_Controller_P.Constant10_Value_n[Hummingbird_Flight_Controller_B.i];
        }

        Hummingbird_Flight_Controller_B.BusAssignment._padding0[0] =
          Hummingbird_Flight_Controller_P.Constant1_Value_ab[0];
        Hummingbird_Flight_Controller_B.BusAssignment._padding0[1] =
          Hummingbird_Flight_Controller_P.Constant1_Value_ab[1];
        Hummingbird_Flight_Controller_B.BusAssignment._padding0[2] =
          Hummingbird_Flight_Controller_P.Constant1_Value_ab[2];
        Hummingbird_Flight_Controller_B.BusAssignment._padding0[3] =
          Hummingbird_Flight_Controller_P.Constant1_Value_ab[3];

        // MATLABSystem: '<S1472>/SinkBlock' incorporates:
        //   BusAssignment: '<S1465>/Bus Assignment'

        uORB_write_step(Hummingbird_Flight_Controlle_DW.obj_l.orbMetadataObj,
                        &Hummingbird_Flight_Controlle_DW.obj_l.orbAdvertiseObj,
                        &Hummingbird_Flight_Controller_B.BusAssignment);

        // Sum: '<S1458>/Sum7'
        Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 =
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 +
          Hummingbird_Flight_Controller_B.In1_m.positions[1];
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 +=
          Hummingbird_Flight_Controller_B.In1_m.positions[0];
        Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 +=
          Hummingbird_Flight_Controller_B.In1_m.positions[2];

        // Switch: '<S1458>/Switch6' incorporates:
        //   Constant: '<S1458>/Constant3'
        //   Switch: '<S1458>/Switch5'

        if (Hummingbird_Flight_Controller_B.BusCreator.VTOL_Mode >
            Hummingbird_Flight_Controller_P.Switch6_Threshold) {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
            Hummingbird_Flight_Controller_P.Constant3_Value;
        } else if (Hummingbird_Flight_Controller_B.BusCreator.Flight_Mode >
                   Hummingbird_Flight_Controller_P.Switch5_Threshold) {
          // Switch: '<S1458>/Switch5' incorporates:
          //   Sum: '<S1458>/Sum7'

          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
            Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_1 +
            Hummingbird_Flight_Controller_B.In1_m.positions[3];
        } else {
          // Gain: '<S1466>/Gain10' incorporates:
          //   Constant: '<S1466>/Constant7'
          //   Sum: '<S1466>/Sum8'
          //   Switch: '<S1458>/Switch5'

          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 = (
            static_cast<real_T>
            (Hummingbird_Flight_Controller_B.BusCreator.Throttle) -
            Hummingbird_Flight_Controller_P.Constant7_Value_c) *
            Hummingbird_Flight_Controller_P.Gain10_Gain_mz;

          // Saturate: '<S1466>/Saturation' incorporates:
          //   Switch: '<S1458>/Switch5'

          if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
              Hummingbird_Flight_Controller_P.Saturation_UpperSat_js) {
            Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
              Hummingbird_Flight_Controller_P.Saturation_UpperSat_js;
          } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                     Hummingbird_Flight_Controller_P.Saturation_LowerSat_d) {
            Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
              Hummingbird_Flight_Controller_P.Saturation_LowerSat_d;
          }
        }

        // BusCreator: '<S1458>/Bus Creator' incorporates:
        //   DataTypeConversion: '<S1458>/Cast To Boolean7'
        //   Gain: '<S1458>/Gain'

        Hummingbird_Flight_Controller_B.Actuator_output.rotor_1 = static_cast<
          real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
                    Hummingbird_Flight_Controller_B.Esp_dot);
        Hummingbird_Flight_Controller_B.Actuator_output.rotor_2 =
          static_cast<real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
          Hummingbird_Flight_Controller_B.V);
        Hummingbird_Flight_Controller_B.Actuator_output.rotor_3 =
          static_cast<real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
          Hummingbird_Flight_Controller_B.IntegralGain_k);
        Hummingbird_Flight_Controller_B.Actuator_output.rotor_4 =
          static_cast<real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_2);
        Hummingbird_Flight_Controller_B.Actuator_output.rotor_5 =
          static_cast<real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
          Hummingbird_Flight_Controller_B.CastToDouble25_f);
        Hummingbird_Flight_Controller_B.Actuator_output.rotor_6 =
          static_cast<real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
          Hummingbird_Flight_Controller_B.course);
        Hummingbird_Flight_Controller_B.Actuator_output.rotor_7 =
          static_cast<real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
          Hummingbird_Flight_Controller_B.t);
        Hummingbird_Flight_Controller_B.Actuator_output.rotor_8 =
          static_cast<real32_T>(Hummingbird_Flight_Controller_P.Gain_Gain_mx *
          Hummingbird_Flight_Controller_B.CastToDouble8);

        // Saturate: '<S1458>/Saturation'
        if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 >
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[1]) {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[1];
        } else if (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 <
                   Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[1]) {
          Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0 =
            Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[1];
        }

        // BusCreator: '<S1458>/Bus Creator' incorporates:
        //   Constant: '<S1458>/Constant5'
        //   DataTypeConversion: '<S1458>/Cast To Boolean10'
        //   Saturate: '<S1458>/Saturation'
        //   Sum: '<S1458>/Sum'

        Hummingbird_Flight_Controller_B.Actuator_output.throttle =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_next_waypoint_idx_0) -
          Hummingbird_Flight_Controller_P.Constant5_Value;

        // Saturate: '<S1458>/Saturation'
        if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 >
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[2]) {
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[2];
        } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 <
                   Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[2]) {
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1 =
            Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[2];
        }

        // BusCreator: '<S1458>/Bus Creator' incorporates:
        //   DataTypeConversion: '<S1458>/Cast To Boolean10'
        //   Gain: '<S1458>/Gain3'
        //   Saturate: '<S1458>/Saturation'

        Hummingbird_Flight_Controller_B.Actuator_output.ailerons =
          Hummingbird_Flight_Controller_P.Gain3_Gain_f * static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_1);

        // Saturate: '<S1458>/Saturation'
        if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 >
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[0]) {
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 =
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[0];
        } else if (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 <
                   Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[0]) {
          Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2 =
            Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[0];
        }

        // BusCreator: '<S1458>/Bus Creator' incorporates:
        //   DataTypeConversion: '<S1458>/Cast To Boolean10'
        //   Gain: '<S1458>/Gain2'
        //   Saturate: '<S1458>/Saturation'

        Hummingbird_Flight_Controller_B.Actuator_output.elevator =
          Hummingbird_Flight_Controller_P.Gain2_Gain_cf * static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_ConvertTofts_idx_2);

        // Saturate: '<S1458>/Saturation'
        if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 >
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[3]) {
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
            Hummingbird_Flight_Controller_P.Saturation_UpperSat_d[3];
        } else if (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 <
                   Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[3]) {
          Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0 =
            Hummingbird_Flight_Controller_P.Saturation_LowerSat_jf[3];
        }

        // BusCreator: '<S1458>/Bus Creator' incorporates:
        //   Constant: '<S1458>/Constant'
        //   DataTypeConversion: '<S1458>/Cast To Boolean10'
        //   DataTypeConversion: '<S1458>/Cast To Boolean3'
        //   DataTypeConversion: '<S1458>/Cast To Boolean6'
        //   DataTypeConversion: '<S1458>/Cast To Boolean8'
        //   DataTypeConversion: '<S1458>/Cast To Boolean9'
        //   Gain: '<S1458>/Gain4'
        //   Saturate: '<S1458>/Saturation'

        Hummingbird_Flight_Controller_B.Actuator_output.rudder =
          Hummingbird_Flight_Controller_P.Gain4_Gain_ki * static_cast<real32_T>
          (Hummingbird_Flight_Controller_B.rtb_current_waypoint_b_idx_0);
        Hummingbird_Flight_Controller_B.Actuator_output.arm_1 =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant_Value_n5);
        Hummingbird_Flight_Controller_B.Actuator_output.arm_2 =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant_Value_n5);
        Hummingbird_Flight_Controller_B.Actuator_output.arm_3 =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant_Value_n5);
        Hummingbird_Flight_Controller_B.Actuator_output.arm_4 =
          static_cast<real32_T>
          (Hummingbird_Flight_Controller_P.Constant_Value_n5);
      }
      break;
    }
  }

  // End of Chart: '<Root>/Chart1'

  // MATLABSystem: '<Root>/PX4 Actuator Write1' incorporates:
  //   Constant: '<Root>/Constant7'
  //   DataTypeConversion: '<Root>/Cast To Boolean17'

  for (Hummingbird_Flight_Controller_B.i = 0; Hummingbird_Flight_Controller_B.i <
       12; Hummingbird_Flight_Controller_B.i++) {
    Hummingbird_Flight_Controller_B.motorValues[Hummingbird_Flight_Controller_B.i]
      = (rtNaNF);
  }

  Hummingbird_Flight_Controller_B.motorValues[0] =
    Hummingbird_Flight_Controller_B.Actuator_output.rotor_1;
  Hummingbird_Flight_Controller_B.motorValues[1] =
    Hummingbird_Flight_Controller_B.Actuator_output.rotor_2;
  Hummingbird_Flight_Controller_B.motorValues[2] =
    Hummingbird_Flight_Controller_B.Actuator_output.rotor_3;
  Hummingbird_Flight_Controller_B.motorValues[3] =
    Hummingbird_Flight_Controller_B.Actuator_output.rotor_4;
  Hummingbird_Flight_Controller_B.motorValues[4] =
    Hummingbird_Flight_Controller_B.Actuator_output.rotor_5;
  Hummingbird_Flight_Controller_B.motorValues[5] =
    Hummingbird_Flight_Controller_B.Actuator_output.rotor_6;
  Hummingbird_Flight_Controller_B.motorValues[6] =
    Hummingbird_Flight_Controller_B.Actuator_output.rotor_7;
  Hummingbird_Flight_Controller_B.motorValues[7] =
    Hummingbird_Flight_Controller_B.Actuator_output.rotor_8;
  Hummingbird_Flight_Controller_B.servoValues[0] =
    Hummingbird_Flight_Controller_B.Actuator_output.throttle;
  Hummingbird_Flight_Controller_B.servoValues[1] =
    Hummingbird_Flight_Controller_B.Actuator_output.ailerons;
  Hummingbird_Flight_Controller_B.servoValues[2] =
    Hummingbird_Flight_Controller_B.Actuator_output.elevator;
  Hummingbird_Flight_Controller_B.servoValues[3] =
    Hummingbird_Flight_Controller_B.Actuator_output.rudder;
  Hummingbird_Flight_Controller_B.servoValues[4] =
    Hummingbird_Flight_Controller_B.Actuator_output.arm_1;
  Hummingbird_Flight_Controller_B.servoValues[5] =
    Hummingbird_Flight_Controller_B.Actuator_output.arm_2;
  Hummingbird_Flight_Controller_B.servoValues[6] =
    Hummingbird_Flight_Controller_B.Actuator_output.arm_3;
  Hummingbird_Flight_Controller_B.servoValues[7] =
    Hummingbird_Flight_Controller_B.Actuator_output.arm_4;
  MW_actuators_set(Hummingbird_Flight_Controller_P.Constant7_Value_b != 0.0,
                   &Hummingbird_Flight_Controller_B.motorValues[0],
                   &Hummingbird_Flight_Controller_B.servoValues[0]);

  // End of MATLABSystem: '<Root>/PX4 Actuator Write1'
  Hummingbird_Fl_PX4Timestamp(&Hummingbird_Flight_Controller_B.PX4Timestamp);

  // BusAssignment: '<S3>/Bus Assignment' incorporates:
  //   MATLABSystem: '<S3>/PX4 Timestamp'

  Hummingbird_Flight_Controller_B.BusAssignment_m.timestamp =
    Hummingbird_Flight_Controller_B.PX4Timestamp.PX4Timestamp;
  for (Hummingbird_Flight_Controller_B.i = 0; Hummingbird_Flight_Controller_B.i <
       12; Hummingbird_Flight_Controller_B.i++) {
    Hummingbird_Flight_Controller_B.BusAssignment_m.positions[Hummingbird_Flight_Controller_B.i]
      =
      Hummingbird_Flight_Controller_B.In1_m.positions[Hummingbird_Flight_Controller_B.i];
  }

  // End of BusAssignment: '<S3>/Bus Assignment'

  // MATLABSystem: '<S1481>/SinkBlock' incorporates:
  //   BusAssignment: '<S3>/Bus Assignment'

  uORB_write_step(Hummingbird_Flight_Controlle_DW.obj_j.orbMetadataObj,
                  &Hummingbird_Flight_Controlle_DW.obj_j.orbAdvertiseObj,
                  &Hummingbird_Flight_Controller_B.BusAssignment_m);

  // Update for DiscreteIntegrator: '<S1535>/Filter' incorporates:
  //   Gain: '<S1543>/Filter Coefficient'
  //
  Hummingbird_Flight_Controlle_DW.Filter_DSTATE[0] +=
    Hummingbird_Flight_Controller_P.Filter_gainval_a *
    Hummingbird_Flight_Controller_B.rtb_FilterCoefficient_idx_0;
  Hummingbird_Flight_Controlle_DW.Filter_DSTATE[1] +=
    Hummingbird_Flight_Controller_P.Filter_gainval_a *
    Hummingbird_Flight_Controller_B.rtb_FilterCoefficient_idx_1;
  Hummingbird_Flight_Controlle_DW.Filter_DSTATE[2] +=
    Hummingbird_Flight_Controller_P.Filter_gainval_a *
    Hummingbird_Flight_Controller_B.rtb_FilterCoefficient_g2;
}

// Model step function for TID1
void Hummingbird_Flight_Controller_Lower_Memory_step1(void) // Sample time: [0.004s, 0.0s] 
{
  real_T rtb_CastToDouble10;
  real_T rtb_CastToDouble11;
  real_T rtb_CastToDouble9;
  boolean_T b_varargout_1;

  // MATLABSystem: '<S1504>/SourceBlock'
  b_varargout_1 = uORB_read_step
    (Hummingbird_Flight_Controlle_DW.obj_gv.orbMetadataObj,
     &Hummingbird_Flight_Controlle_DW.obj_gv.eventStructObj,
     &Hummingbird_Flight_Controller_B.r6, false, 1.0);

  // Outputs for Enabled SubSystem: '<S1504>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S1505>/Enable'

  // Start for MATLABSystem: '<S1504>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S1505>/In1'
    Hummingbird_Flight_Controller_B.In1_i = Hummingbird_Flight_Controller_B.r6;
  }

  // End of Outputs for SubSystem: '<S1504>/Enabled Subsystem'

  // DataTypeConversion: '<S5>/Cast To Double10' incorporates:
  //   Gain: '<S5>/Convert To ft//s4'

  rtb_CastToDouble10 = Hummingbird_Flight_Controller_P.ConvertTofts4_Gain *
    Hummingbird_Flight_Controller_B.In1_i.y;

  // DataTypeConversion: '<S5>/Cast To Double11' incorporates:
  //   Gain: '<S5>/Convert To ft//s5'

  rtb_CastToDouble11 = Hummingbird_Flight_Controller_P.ConvertTofts5_Gain *
    Hummingbird_Flight_Controller_B.In1_i.z;

  // DataTypeConversion: '<S5>/Cast To Double9' incorporates:
  //   Gain: '<S5>/Convert To ft//s3'

  rtb_CastToDouble9 = Hummingbird_Flight_Controller_P.ConvertTofts3_Gain *
    Hummingbird_Flight_Controller_B.In1_i.x;

  // RateTransition generated from: '<S5>/Rate Transition'
  Hummingbird_Flight_Controlle_DW.RateTransition_1_Buffer0 = rtb_CastToDouble9;

  // RateTransition generated from: '<S5>/Rate Transition'
  Hummingbird_Flight_Controlle_DW.RateTransition_2_Buffer0 = rtb_CastToDouble10;

  // RateTransition generated from: '<S5>/Rate Transition'
  Hummingbird_Flight_Controlle_DW.RateTransition_3_Buffer0 = rtb_CastToDouble11;
}

// Model step function for TID2
void Hummingbird_Flight_Controller_Lower_Memory_step2(void) // Sample time: [0.5s, 0.0s] 
{
  real32_T ParamStep;
  real32_T rtb_ReadParameter_o1;
  real32_T rtb_ReadParameter_o1_h;
  real32_T rtb_ReadParameter_o1_h2;
  real32_T rtb_ReadParameter_o1_it;
  real32_T rtb_ReadParameter_o1_kh;
  real32_T rtb_ReadParameter_o1_kx;
  real32_T rtb_ReadParameter_o1_l3;
  real32_T rtb_ReadParameter_o1_lo;
  real32_T rtb_ReadParameter_o1_n;
  boolean_T b_varargout_2;

  // MATLABSystem: '<S1491>/Read Parameter'
  b_varargout_2 = MW_ParamRead_Step
    (Hummingbird_Flight_Controlle_DW.obj_ns.MW_PARAMHANDLE, MW_SINGLE,
     &rtb_ReadParameter_o1_h);
  if (b_varargout_2) {
    rtb_ReadParameter_o1_h = 0.0F;
  }

  // End of MATLABSystem: '<S1491>/Read Parameter'

  // MATLABSystem: '<S1491>/Read Parameter1'
  b_varargout_2 = MW_ParamRead_Step
    (Hummingbird_Flight_Controlle_DW.obj_g0.MW_PARAMHANDLE, MW_SINGLE,
     &ParamStep);
  if (b_varargout_2) {
    ParamStep = 0.0F;
  }

  // RateTransition generated from: '<S1491>/Divide' incorporates:
  //   MATLABSystem: '<S1491>/Read Parameter1'
  //   Sum: '<S1491>/Sum1'
  //
  Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_Buffer0_l = ParamStep -
    rtb_ReadParameter_o1_h;

  // RateTransition generated from: '<S1491>/Sum'
  Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buffer0_o =
    rtb_ReadParameter_o1_h;

  // MATLABSystem: '<S1492>/Read Parameter'
  b_varargout_2 = MW_ParamRead_Step
    (Hummingbird_Flight_Controlle_DW.obj_er.MW_PARAMHANDLE, MW_SINGLE,
     &rtb_ReadParameter_o1_h2);
  if (b_varargout_2) {
    rtb_ReadParameter_o1_h2 = 0.0F;
  }

  // End of MATLABSystem: '<S1492>/Read Parameter'

  // MATLABSystem: '<S1492>/Read Parameter1'
  b_varargout_2 = MW_ParamRead_Step
    (Hummingbird_Flight_Controlle_DW.obj_ez.MW_PARAMHANDLE, MW_SINGLE,
     &ParamStep);
  if (b_varargout_2) {
    ParamStep = 0.0F;
  }

  // RateTransition generated from: '<S1492>/Divide' incorporates:
  //   MATLABSystem: '<S1492>/Read Parameter1'
  //   Sum: '<S1492>/Sum1'
  //
  Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_Buffer_lz = ParamStep -
    rtb_ReadParameter_o1_h2;

  // RateTransition generated from: '<S1492>/Sum'
  Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buffer0_os =
    rtb_ReadParameter_o1_h2;

  // MATLABSystem: '<S1493>/Read Parameter'
  b_varargout_2 = MW_ParamRead_Step
    (Hummingbird_Flight_Controlle_DW.obj_ar.MW_PARAMHANDLE, MW_SINGLE,
     &rtb_ReadParameter_o1_kx);
  if (b_varargout_2) {
    rtb_ReadParameter_o1_kx = 0.0F;
  }

  // End of MATLABSystem: '<S1493>/Read Parameter'

  // MATLABSystem: '<S1493>/Read Parameter1'
  b_varargout_2 = MW_ParamRead_Step
    (Hummingbird_Flight_Controlle_DW.obj_iy.MW_PARAMHANDLE, MW_SINGLE,
     &ParamStep);
  if (b_varargout_2) {
    ParamStep = 0.0F;
  }

  // RateTransition generated from: '<S1493>/Divide' incorporates:
  //   MATLABSystem: '<S1493>/Read Parameter1'
  //   Sum: '<S1493>/Sum1'
  //
  Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_Buffer0 = ParamStep -
    rtb_ReadParameter_o1_kx;

  // RateTransition generated from: '<S1493>/Sum'
  Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buffer0 =
    rtb_ReadParameter_o1_kx;

  // MATLABSystem: '<S1494>/Read Parameter'
  b_varargout_2 = MW_ParamRead_Step
    (Hummingbird_Flight_Controlle_DW.obj_mb.MW_PARAMHANDLE, MW_SINGLE,
     &rtb_ReadParameter_o1_l3);
  if (b_varargout_2) {
    rtb_ReadParameter_o1_l3 = 0.0F;
  }

  // End of MATLABSystem: '<S1494>/Read Parameter'

  // MATLABSystem: '<S1494>/Read Parameter1'
  b_varargout_2 = MW_ParamRead_Step
    (Hummingbird_Flight_Controlle_DW.obj_e.MW_PARAMHANDLE, MW_SINGLE, &ParamStep);
  if (b_varargout_2) {
    ParamStep = 0.0F;
  }

  // RateTransition generated from: '<S1494>/Divide' incorporates:
  //   MATLABSystem: '<S1494>/Read Parameter1'
  //   Sum: '<S1494>/Sum1'
  //
  Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_Buffe_lzh = ParamStep -
    rtb_ReadParameter_o1_l3;

  // RateTransition generated from: '<S1494>/Sum'
  Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buffer0_osg =
    rtb_ReadParameter_o1_l3;

  // MATLABSystem: '<S1495>/Read Parameter'
  b_varargout_2 = MW_ParamRead_Step
    (Hummingbird_Flight_Controlle_DW.obj_iw.MW_PARAMHANDLE, MW_SINGLE,
     &rtb_ReadParameter_o1_kh);
  if (b_varargout_2) {
    rtb_ReadParameter_o1_kh = 0.0F;
  }

  // End of MATLABSystem: '<S1495>/Read Parameter'

  // MATLABSystem: '<S1495>/Read Parameter1'
  b_varargout_2 = MW_ParamRead_Step
    (Hummingbird_Flight_Controlle_DW.obj_hw.MW_PARAMHANDLE, MW_SINGLE,
     &ParamStep);
  if (b_varargout_2) {
    ParamStep = 0.0F;
  }

  // RateTransition generated from: '<S1495>/Divide' incorporates:
  //   MATLABSystem: '<S1495>/Read Parameter1'
  //   Sum: '<S1495>/Sum1'
  //
  Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_Buff_lzhx = ParamStep -
    rtb_ReadParameter_o1_kh;

  // RateTransition generated from: '<S1495>/Sum'
  Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buffer0_osgb =
    rtb_ReadParameter_o1_kh;

  // MATLABSystem: '<S1496>/Read Parameter'
  b_varargout_2 = MW_ParamRead_Step
    (Hummingbird_Flight_Controlle_DW.obj_n.MW_PARAMHANDLE, MW_SINGLE,
     &rtb_ReadParameter_o1_lo);
  if (b_varargout_2) {
    rtb_ReadParameter_o1_lo = 0.0F;
  }

  // End of MATLABSystem: '<S1496>/Read Parameter'

  // MATLABSystem: '<S1496>/Read Parameter1'
  b_varargout_2 = MW_ParamRead_Step
    (Hummingbird_Flight_Controlle_DW.obj_b.MW_PARAMHANDLE, MW_SINGLE, &ParamStep);
  if (b_varargout_2) {
    ParamStep = 0.0F;
  }

  // RateTransition generated from: '<S1496>/Divide' incorporates:
  //   MATLABSystem: '<S1496>/Read Parameter1'
  //   Sum: '<S1496>/Sum1'
  //
  Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_Buf_lzhxe = ParamStep -
    rtb_ReadParameter_o1_lo;

  // RateTransition generated from: '<S1496>/Sum'
  Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buffer_osgbz =
    rtb_ReadParameter_o1_lo;

  // MATLABSystem: '<S1497>/Read Parameter'
  b_varargout_2 = MW_ParamRead_Step
    (Hummingbird_Flight_Controlle_DW.obj_ip.MW_PARAMHANDLE, MW_SINGLE,
     &rtb_ReadParameter_o1_n);
  if (b_varargout_2) {
    rtb_ReadParameter_o1_n = 0.0F;
  }

  // End of MATLABSystem: '<S1497>/Read Parameter'

  // MATLABSystem: '<S1497>/Read Parameter1'
  b_varargout_2 = MW_ParamRead_Step
    (Hummingbird_Flight_Controlle_DW.obj_j1.MW_PARAMHANDLE, MW_SINGLE,
     &ParamStep);
  if (b_varargout_2) {
    ParamStep = 0.0F;
  }

  // Sum: '<S1497>/Sum1' incorporates:
  //   MATLABSystem: '<S1497>/Read Parameter1'
  //
  rtb_ReadParameter_o1_lo = ParamStep - rtb_ReadParameter_o1_n;

  // RateTransition generated from: '<S1497>/Divide'
  Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_Bu_lzhxel =
    rtb_ReadParameter_o1_lo;

  // RateTransition generated from: '<S1497>/Sum'
  Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buffe_osgbzt =
    rtb_ReadParameter_o1_n;

  // MATLABSystem: '<S1498>/Read Parameter'
  b_varargout_2 = MW_ParamRead_Step
    (Hummingbird_Flight_Controlle_DW.obj_ci.MW_PARAMHANDLE, MW_SINGLE,
     &rtb_ReadParameter_o1_it);
  if (b_varargout_2) {
    rtb_ReadParameter_o1_it = 0.0F;
  }

  // End of MATLABSystem: '<S1498>/Read Parameter'

  // MATLABSystem: '<S1498>/Read Parameter1'
  b_varargout_2 = MW_ParamRead_Step
    (Hummingbird_Flight_Controlle_DW.obj_lk.MW_PARAMHANDLE, MW_SINGLE,
     &ParamStep);
  if (b_varargout_2) {
    ParamStep = 0.0F;
  }

  // Sum: '<S1498>/Sum1' incorporates:
  //   MATLABSystem: '<S1498>/Read Parameter1'
  //
  rtb_ReadParameter_o1_n = ParamStep - rtb_ReadParameter_o1_it;

  // RateTransition generated from: '<S1498>/Divide'
  Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_B_lzhxel2 =
    rtb_ReadParameter_o1_n;

  // RateTransition generated from: '<S1498>/Sum'
  Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buff_osgbztg =
    rtb_ReadParameter_o1_it;

  // MATLABSystem: '<S1499>/Read Parameter'
  b_varargout_2 = MW_ParamRead_Step
    (Hummingbird_Flight_Controlle_DW.obj_d.MW_PARAMHANDLE, MW_SINGLE,
     &rtb_ReadParameter_o1);
  if (b_varargout_2) {
    rtb_ReadParameter_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S1499>/Read Parameter'

  // MATLABSystem: '<S1499>/Read Parameter1'
  b_varargout_2 = MW_ParamRead_Step
    (Hummingbird_Flight_Controlle_DW.obj_ii.MW_PARAMHANDLE, MW_SINGLE,
     &ParamStep);
  if (b_varargout_2) {
    ParamStep = 0.0F;
  }

  // Sum: '<S1499>/Sum1' incorporates:
  //   MATLABSystem: '<S1499>/Read Parameter1'
  //
  rtb_ReadParameter_o1_it = ParamStep - rtb_ReadParameter_o1;

  // RateTransition generated from: '<S1499>/Divide'
  Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2__lzhxel2b =
    rtb_ReadParameter_o1_it;

  // RateTransition generated from: '<S1499>/Sum'
  Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buf_osgbztgq =
    rtb_ReadParameter_o1;
}

// Use this function only if you need to maintain compatibility with an existing static main program.
void Hummingbird_Flight_Controller_Lower_Memory_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Hummingbird_Flight_Controller_Lower_Memory_step0();
    break;

   case 1 :
    Hummingbird_Flight_Controller_Lower_Memory_step1();
    break;

   case 2 :
    Hummingbird_Flight_Controller_Lower_Memory_step2();
    break;

   default :
    // do nothing
    break;
  }
}

// Model initialize function
void Hummingbird_Flight_Controller_Lower_Memory_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    static const char_T ParameterNameStr[8] = "RC1_MIN";
    static const char_T ParameterNameStr_0[8] = "RC1_MAX";
    static const char_T ParameterNameStr_1[8] = "RC2_MIN";
    static const char_T ParameterNameStr_2[8] = "RC2_MAX";
    static const char_T ParameterNameStr_3[8] = "RC3_MIN";
    static const char_T ParameterNameStr_4[8] = "RC3_MAX";
    static const char_T ParameterNameStr_5[8] = "RC4_MIN";
    static const char_T ParameterNameStr_6[8] = "RC4_MAX";
    static const char_T ParameterNameStr_7[8] = "RC5_MIN";
    static const char_T ParameterNameStr_8[8] = "RC5_MAX";
    static const char_T ParameterNameStr_9[8] = "RC6_MIN";
    static const char_T ParameterNameStr_a[8] = "RC6_MAX";
    static const char_T ParameterNameStr_b[8] = "RC7_MIN";
    static const char_T ParameterNameStr_c[8] = "RC7_MAX";
    static const char_T ParameterNameStr_d[8] = "RC8_MIN";
    static const char_T ParameterNameStr_e[8] = "RC8_MAX";
    static const char_T ParameterNameStr_f[8] = "RC9_MIN";
    static const char_T ParameterNameStr_g[8] = "RC9_MAX";
    static const char_T ParameterNameStr_h[15] = "FW_AIRSPD_TRIM";
    static const char_T ParameterNameStr_i[16] = "PITCH_SP_P_GAIN";
    static const char_T ParameterNameStr_j[16] = "THROTTLE_I_GAIN";
    static const char_T ParameterNameStr_k[16] = "THROTTLE_P_GAIN";
    static const char_T ParameterNameStr_l[17] = "PITCH_SP_FF_GAIN";
    static const char_T ParameterNameStr_m[16] = "THROTTLE_D_GAIN";
    static const char_T ParameterNameStr_n[9] = "B_P_GAIN";
    static const char_T ParameterNameStr_o[9] = "B_D_GAIN";
    int32_T i;

    // Start for RateTransition generated from: '<S5>/Rate Transition'
    Hummingbird_Flight_Controller_B.X =
      Hummingbird_Flight_Controller_P.RateTransition_1_InitialConditi;

    // Start for RateTransition generated from: '<S5>/Rate Transition'
    Hummingbird_Flight_Controller_B.Y =
      Hummingbird_Flight_Controller_P.RateTransition_2_InitialConditi;

    // Start for RateTransition generated from: '<S5>/Rate Transition'
    Hummingbird_Flight_Controller_B.Z =
      Hummingbird_Flight_Controller_P.RateTransition_3_InitialConditi;

    // Start for RateTransition generated from: '<S1493>/Sum'
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2 =
      Hummingbird_Flight_Controller_P.TmpRTBAtSumInport2_InitialCondi;

    // Start for RateTransition generated from: '<S1493>/Divide'
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2 =
      Hummingbird_Flight_Controller_P.TmpRTBAtDivideInport2_InitialCo;

    // Start for RateTransition generated from: '<S1491>/Sum'
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_m =
      Hummingbird_Flight_Controller_P.TmpRTBAtSumInport2_InitialCon_j;

    // Start for RateTransition generated from: '<S1491>/Divide'
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_p =
      Hummingbird_Flight_Controller_P.TmpRTBAtDivideInport2_Initial_j;

    // Start for RateTransition generated from: '<S1492>/Sum'
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_mb =
      Hummingbird_Flight_Controller_P.TmpRTBAtSumInport2_InitialCo_jx;

    // Start for RateTransition generated from: '<S1492>/Divide'
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_py =
      Hummingbird_Flight_Controller_P.TmpRTBAtDivideInport2_Initia_jx;

    // Start for RateTransition generated from: '<S1494>/Sum'
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_mbd =
      Hummingbird_Flight_Controller_P.TmpRTBAtSumInport2_InitialC_jxk;

    // Start for RateTransition generated from: '<S1494>/Divide'
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_pyt =
      Hummingbird_Flight_Controller_P.TmpRTBAtDivideInport2_Initi_jxk;

    // Start for RateTransition generated from: '<S1495>/Sum'
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_mbdz =
      Hummingbird_Flight_Controller_P.TmpRTBAtSumInport2_Initial_jxkx;

    // Start for RateTransition generated from: '<S1495>/Divide'
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_pyts =
      Hummingbird_Flight_Controller_P.TmpRTBAtDivideInport2_Init_jxkx;

    // Start for RateTransition generated from: '<S1496>/Sum'
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_mbdzh =
      Hummingbird_Flight_Controller_P.TmpRTBAtSumInport2_Initia_jxkxj;

    // Start for RateTransition generated from: '<S1496>/Divide'
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_pytsl =
      Hummingbird_Flight_Controller_P.TmpRTBAtDivideInport2_Ini_jxkxj;

    // Start for RateTransition generated from: '<S1497>/Sum'
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_mbdzha =
      Hummingbird_Flight_Controller_P.TmpRTBAtSumInport2_Initi_jxkxj0;

    // Start for RateTransition generated from: '<S1497>/Divide'
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_pytslg =
      Hummingbird_Flight_Controller_P.TmpRTBAtDivideInport2_In_jxkxj0;

    // Start for RateTransition generated from: '<S1498>/Sum'
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_mbdzhaq =
      Hummingbird_Flight_Controller_P.TmpRTBAtSumInport2_Init_jxkxj0l;

    // Start for RateTransition generated from: '<S1498>/Divide'
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_pytslgw =
      Hummingbird_Flight_Controller_P.TmpRTBAtDivideInport2_I_jxkxj0l;

    // Start for RateTransition generated from: '<S1499>/Sum'
    Hummingbird_Flight_Controller_B.TmpRTBAtSumInport2_mbdzhaqa =
      Hummingbird_Flight_Controller_P.TmpRTBAtSumInport2_Ini_jxkxj0lw;

    // Start for RateTransition generated from: '<S1499>/Divide'
    Hummingbird_Flight_Controller_B.TmpRTBAtDivideInport2_pytslgwp =
      Hummingbird_Flight_Controller_P.TmpRTBAtDivideInport2__jxkxj0lw;

    // Start for DataStoreMemory: '<Root>/Data Store Memory'
    Hummingbird_Flight_Controlle_DW.mission_start[0] =
      Hummingbird_Flight_Controller_P.DataStoreMemory_InitialValue;
    Hummingbird_Flight_Controlle_DW.mission_start[1] =
      Hummingbird_Flight_Controller_P.DataStoreMemory_InitialValue;
    Hummingbird_Flight_Controlle_DW.mission_start[2] =
      Hummingbird_Flight_Controller_P.DataStoreMemory_InitialValue;

    // InitializeConditions for RateTransition generated from: '<S5>/Rate Transition' 
    Hummingbird_Flight_Controlle_DW.RateTransition_1_Buffer0 =
      Hummingbird_Flight_Controller_P.RateTransition_1_InitialConditi;

    // InitializeConditions for RateTransition generated from: '<S5>/Rate Transition' 
    Hummingbird_Flight_Controlle_DW.RateTransition_2_Buffer0 =
      Hummingbird_Flight_Controller_P.RateTransition_2_InitialConditi;

    // InitializeConditions for RateTransition generated from: '<S5>/Rate Transition' 
    Hummingbird_Flight_Controlle_DW.RateTransition_3_Buffer0 =
      Hummingbird_Flight_Controller_P.RateTransition_3_InitialConditi;

    // InitializeConditions for RateTransition generated from: '<S1493>/Sum'
    Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buffer0 =
      Hummingbird_Flight_Controller_P.TmpRTBAtSumInport2_InitialCondi;

    // InitializeConditions for RateTransition generated from: '<S1493>/Divide'
    Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_Buffer0 =
      Hummingbird_Flight_Controller_P.TmpRTBAtDivideInport2_InitialCo;

    // InitializeConditions for RateTransition generated from: '<S1491>/Sum'
    Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buffer0_o =
      Hummingbird_Flight_Controller_P.TmpRTBAtSumInport2_InitialCon_j;

    // InitializeConditions for RateTransition generated from: '<S1491>/Divide'
    Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_Buffer0_l =
      Hummingbird_Flight_Controller_P.TmpRTBAtDivideInport2_Initial_j;

    // InitializeConditions for RateTransition generated from: '<S1492>/Sum'
    Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buffer0_os =
      Hummingbird_Flight_Controller_P.TmpRTBAtSumInport2_InitialCo_jx;

    // InitializeConditions for RateTransition generated from: '<S1492>/Divide'
    Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_Buffer_lz =
      Hummingbird_Flight_Controller_P.TmpRTBAtDivideInport2_Initia_jx;

    // InitializeConditions for RateTransition generated from: '<S1494>/Sum'
    Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buffer0_osg =
      Hummingbird_Flight_Controller_P.TmpRTBAtSumInport2_InitialC_jxk;

    // InitializeConditions for RateTransition generated from: '<S1494>/Divide'
    Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_Buffe_lzh =
      Hummingbird_Flight_Controller_P.TmpRTBAtDivideInport2_Initi_jxk;

    // InitializeConditions for RateTransition generated from: '<S1495>/Sum'
    Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buffer0_osgb =
      Hummingbird_Flight_Controller_P.TmpRTBAtSumInport2_Initial_jxkx;

    // InitializeConditions for RateTransition generated from: '<S1495>/Divide'
    Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_Buff_lzhx =
      Hummingbird_Flight_Controller_P.TmpRTBAtDivideInport2_Init_jxkx;

    // InitializeConditions for RateTransition generated from: '<S1496>/Sum'
    Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buffer_osgbz =
      Hummingbird_Flight_Controller_P.TmpRTBAtSumInport2_Initia_jxkxj;

    // InitializeConditions for RateTransition generated from: '<S1496>/Divide'
    Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_Buf_lzhxe =
      Hummingbird_Flight_Controller_P.TmpRTBAtDivideInport2_Ini_jxkxj;

    // InitializeConditions for RateTransition generated from: '<S1497>/Sum'
    Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buffe_osgbzt =
      Hummingbird_Flight_Controller_P.TmpRTBAtSumInport2_Initi_jxkxj0;

    // InitializeConditions for RateTransition generated from: '<S1497>/Divide'
    Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_Bu_lzhxel =
      Hummingbird_Flight_Controller_P.TmpRTBAtDivideInport2_In_jxkxj0;

    // InitializeConditions for RateTransition generated from: '<S1498>/Sum'
    Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buff_osgbztg =
      Hummingbird_Flight_Controller_P.TmpRTBAtSumInport2_Init_jxkxj0l;

    // InitializeConditions for RateTransition generated from: '<S1498>/Divide'
    Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2_B_lzhxel2 =
      Hummingbird_Flight_Controller_P.TmpRTBAtDivideInport2_I_jxkxj0l;

    // InitializeConditions for RateTransition generated from: '<S1499>/Sum'
    Hummingbird_Flight_Controlle_DW.TmpRTBAtSumInport2_Buf_osgbztgq =
      Hummingbird_Flight_Controller_P.TmpRTBAtSumInport2_Ini_jxkxj0lw;

    // InitializeConditions for RateTransition generated from: '<S1499>/Divide'
    Hummingbird_Flight_Controlle_DW.TmpRTBAtDivideInport2__lzhxel2b =
      Hummingbird_Flight_Controller_P.TmpRTBAtDivideInport2__jxkxj0lw;

    // SystemInitialize for IfAction SubSystem: '<S1>/Flight_controller.MR_Nav'
    // InitializeConditions for DiscreteIntegrator: '<S869>/Integrator' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_n =
      Hummingbird_Flight_Controller_P.PIDController5_InitialConditi_i;

    // InitializeConditions for DiscreteIntegrator: '<S864>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_fu =
      Hummingbird_Flight_Controller_P.PIDController5_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S817>/Integrator' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_j =
      Hummingbird_Flight_Controller_P.PIDController3_InitialConditi_a;

    // InitializeConditions for DiscreteIntegrator: '<S812>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_l =
      Hummingbird_Flight_Controller_P.PIDController3_InitialConditi_f;

    // End of SystemInitialize for SubSystem: '<S1>/Flight_controller.MR_Nav'

    // InitializeConditions for DiscreteIntegrator: '<S1535>/Filter'
    Hummingbird_Flight_Controlle_DW.Filter_DSTATE[0] =
      Hummingbird_Flight_Controller_P.PIDController_InitialConditi_gy;

    // SystemInitialize for IfAction SubSystem: '<S1>/Flight_controller.MR_Nav'
    // InitializeConditions for DiscreteIntegrator: '<S1098>/Integrator' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[0] =
      Hummingbird_Flight_Controller_P.PIDController8_InitialConditi_g;

    // InitializeConditions for DiscreteIntegrator: '<S1093>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_b[0] =
      Hummingbird_Flight_Controller_P.PIDController8_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S1150>/Integrator' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[0] =
      Hummingbird_Flight_Controller_P.PIDController9_InitialConditi_i;

    // InitializeConditions for DiscreteIntegrator: '<S1145>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_e[0] =
      Hummingbird_Flight_Controller_P.PIDController9_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S1030>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_k[0] =
      Hummingbird_Flight_Controller_P.PIDController3_InitialConditi_g;

    // End of SystemInitialize for SubSystem: '<S1>/Flight_controller.MR_Nav'

    // InitializeConditions for DiscreteIntegrator: '<S1535>/Filter'
    Hummingbird_Flight_Controlle_DW.Filter_DSTATE[1] =
      Hummingbird_Flight_Controller_P.PIDController_InitialConditi_gy;

    // SystemInitialize for IfAction SubSystem: '<S1>/Flight_controller.MR_Nav'
    // InitializeConditions for DiscreteIntegrator: '<S1098>/Integrator' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[1] =
      Hummingbird_Flight_Controller_P.PIDController8_InitialConditi_g;

    // InitializeConditions for DiscreteIntegrator: '<S1093>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_b[1] =
      Hummingbird_Flight_Controller_P.PIDController8_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S1150>/Integrator' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[1] =
      Hummingbird_Flight_Controller_P.PIDController9_InitialConditi_i;

    // InitializeConditions for DiscreteIntegrator: '<S1145>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_e[1] =
      Hummingbird_Flight_Controller_P.PIDController9_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S1030>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_k[1] =
      Hummingbird_Flight_Controller_P.PIDController3_InitialConditi_g;

    // End of SystemInitialize for SubSystem: '<S1>/Flight_controller.MR_Nav'

    // InitializeConditions for DiscreteIntegrator: '<S1535>/Filter'
    Hummingbird_Flight_Controlle_DW.Filter_DSTATE[2] =
      Hummingbird_Flight_Controller_P.PIDController_InitialConditi_gy;

    // SystemInitialize for IfAction SubSystem: '<S1>/Flight_controller.MR_Nav'
    // InitializeConditions for DiscreteIntegrator: '<S1098>/Integrator' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_h[2] =
      Hummingbird_Flight_Controller_P.PIDController8_InitialConditi_g;

    // InitializeConditions for DiscreteIntegrator: '<S1093>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_b[2] =
      Hummingbird_Flight_Controller_P.PIDController8_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S1150>/Integrator' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_c[2] =
      Hummingbird_Flight_Controller_P.PIDController9_InitialConditi_i;

    // InitializeConditions for DiscreteIntegrator: '<S1145>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_e[2] =
      Hummingbird_Flight_Controller_P.PIDController9_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S1030>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_k[2] =
      Hummingbird_Flight_Controller_P.PIDController3_InitialConditi_g;

    // SystemInitialize for Chart: '<Root>/Chart'
    Hummingbi_PX4Timestamp_Init(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_pb);
    Hummingbird__SinkBlock_Init
      (&Hummingbird_Flight_Controller_B.BusAssignment_ov,
       &Hummingbird_Flight_Controlle_DW.SinkBlock_ir);
    Hummingbi_PX4Timestamp_Init(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_a);
    Hummi_ReadParameter1_b_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter1_o);
    Hummi_ReadParameter_cb_Init(&Hummingbird_Flight_Controlle_DW.ReadParameter_o);
    Hummi_ReadParameter2_c_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ayu5);
    Hummi_ReadParameter1_o_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter1_l);
    Hummin_ReadParameter_g_Init(&Hummingbird_Flight_Controlle_DW.ReadParameter_l);
    Humm_ReadParameter2_cs_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ayu5d);
    Hummingbir_SinkBlock_b_Init
      (&Hummingbird_Flight_Controller_B.BusAssignment_mv,
       &Hummingbird_Flight_Controlle_DW.SinkBlock_fv);
    Hummingbi_PX4Timestamp_Init(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_ac);
    Hummingbir_SinkBlock_a_Init(&Hummingbird_Flight_Controller_B.BusAssignment_f,
      &Hummingbird_Flight_Controlle_DW.SinkBlock_fw);
    Humm_ReadParameter1_kn_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter1_px);
    Hummin_ReadParameter_h_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter_px);
    Hummi_ReadParameter2_o_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ayu5da);
    Humm_ReadParameter1_l5_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter1_i);
    Hummi_ReadParameter_cl_Init(&Hummingbird_Flight_Controlle_DW.ReadParameter_i);
    Humm_ReadParameter2_ow_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter2_j);

    // End of SystemInitialize for SubSystem: '<S1>/Flight_controller.MR_Nav'

    // SystemInitialize for IfAction SubSystem: '<S1>/Flight_controller.MR_Vel1' 
    // InitializeConditions for DiscreteIntegrator: '<S1203>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_f =
      Hummingbird_Flight_Controller_P.PIDController3_InitialConditi_m;

    // InitializeConditions for DiscreteIntegrator: '<S1440>/Integrator' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[0] =
      Hummingbird_Flight_Controller_P.PIDController9_InitialConditi_b;

    // InitializeConditions for DiscreteIntegrator: '<S1435>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_h[0] =
      Hummingbird_Flight_Controller_P.PIDController9_InitialConditi_h;

    // InitializeConditions for DiscreteIntegrator: '<S1369>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_c[0] =
      Hummingbird_Flight_Controller_P.PIDController3_InitialConditi_b;

    // InitializeConditions for DiscreteIntegrator: '<S1440>/Integrator' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[1] =
      Hummingbird_Flight_Controller_P.PIDController9_InitialConditi_b;

    // InitializeConditions for DiscreteIntegrator: '<S1435>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_h[1] =
      Hummingbird_Flight_Controller_P.PIDController9_InitialConditi_h;

    // InitializeConditions for DiscreteIntegrator: '<S1369>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_c[1] =
      Hummingbird_Flight_Controller_P.PIDController3_InitialConditi_b;

    // InitializeConditions for DiscreteIntegrator: '<S1440>/Integrator' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Integrator_DSTATE[2] =
      Hummingbird_Flight_Controller_P.PIDController9_InitialConditi_b;

    // InitializeConditions for DiscreteIntegrator: '<S1435>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_h[2] =
      Hummingbird_Flight_Controller_P.PIDController9_InitialConditi_h;

    // InitializeConditions for DiscreteIntegrator: '<S1369>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_c[2] =
      Hummingbird_Flight_Controller_P.PIDController3_InitialConditi_b;

    // SystemInitialize for Chart: '<Root>/Chart'
    Hummingbi_PX4Timestamp_Init(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_d);
    Hummin_ReadParameter_a_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter_ld);
    Hummi_ReadParameter1_k_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter1_ld);

    // Start for MATLABSystem: '<S1399>/SinkBlock' incorporates:
    //   BusAssignment: '<S1171>/Bus Assignment'
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.obj_hh.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_hh.isSetupComplete = false;
    Hummingbird_Flight_Controlle_DW.obj_hh.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_hh.orbMetadataObj = ORB_ID(debug_vect);
    uORB_write_initialize(Hummingbird_Flight_Controlle_DW.obj_hh.orbMetadataObj,
                          &Hummingbird_Flight_Controlle_DW.obj_hh.orbAdvertiseObj,
                          &Hummingbird_Flight_Controller_B.BusAssignment_n, 1);
    Hummingbird_Flight_Controlle_DW.obj_hh.isSetupComplete = true;

    // SystemInitialize for Chart: '<Root>/Chart'
    Hummingbi_PX4Timestamp_Init(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_g);
    Hummingbird__SinkBlock_Init
      (&Hummingbird_Flight_Controller_B.BusAssignment_ip,
       &Hummingbird_Flight_Controlle_DW.SinkBlock_hd);
    Hummingbi_PX4Timestamp_Init(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_j);
    Hummi_ReadParameter1_b_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter1_k);
    Hummi_ReadParameter_cb_Init(&Hummingbird_Flight_Controlle_DW.ReadParameter_k);
    Hummi_ReadParameter2_c_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter2_o);
    Hummi_ReadParameter1_o_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter1_lu);
    Hummin_ReadParameter_g_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter_lu);
    Humm_ReadParameter2_cs_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter2_l);
    Hummingbir_SinkBlock_b_Init(&Hummingbird_Flight_Controller_B.BusAssignment_j,
      &Hummingbird_Flight_Controlle_DW.SinkBlock_o);
    Hummingbi_PX4Timestamp_Init(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_k);
    Hummingbir_SinkBlock_a_Init(&Hummingbird_Flight_Controller_B.BusAssignment_i,
      &Hummingbird_Flight_Controlle_DW.SinkBlock_jf);
    Humm_ReadParameter1_kn_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter1_m);
    Hummin_ReadParameter_h_Init(&Hummingbird_Flight_Controlle_DW.ReadParameter_m);
    Hummi_ReadParameter2_o_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter2_p);
    Humm_ReadParameter1_l5_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter1_kh);
    Hummi_ReadParameter_cl_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter_kh);
    Humm_ReadParameter2_ow_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter2_i);

    // End of SystemInitialize for SubSystem: '<S1>/Flight_controller.MR_Vel1'

    // SystemInitialize for IfAction SubSystem: '<S1>/Flight_controller.MR_Attitude' 
    // InitializeConditions for DiscreteIntegrator: '<S578>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_j =
      Hummingbird_Flight_Controller_P.PIDController3_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S692>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_bl[0] =
      Hummingbird_Flight_Controller_P.PIDController1_InitialConditi_f;
    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_bl[1] =
      Hummingbird_Flight_Controller_P.PIDController1_InitialConditi_f;
    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_bl[2] =
      Hummingbird_Flight_Controller_P.PIDController1_InitialConditi_f;

    // SystemInitialize for Chart: '<Root>/Chart'
    Hummin_ReadParameter_a_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ayu);
    Hummi_ReadParameter1_k_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ayu);
    Hummingbi_PX4Timestamp_Init(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_m);
    Hummingbird__SinkBlock_Init(&Hummingbird_Flight_Controller_B.BusAssignment_d,
      &Hummingbird_Flight_Controlle_DW.SinkBlock_lp);
    Hummingbi_PX4Timestamp_Init(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_ef);
    Hummi_ReadParameter1_b_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ayu5);
    Hummi_ReadParameter_cb_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ayu5);
    Hummi_ReadParameter2_c_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3);
    Hummi_ReadParameter1_o_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ayu5d);
    Hummin_ReadParameter_g_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ayu5d);
    Humm_ReadParameter2_cs_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3a);
    Hummingbir_SinkBlock_b_Init
      (&Hummingbird_Flight_Controller_B.BusAssignment_kl,
       &Hummingbird_Flight_Controlle_DW.SinkBlock_d);
    Hummingbi_PX4Timestamp_Init(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_cf);
    Hummingbir_SinkBlock_a_Init
      (&Hummingbird_Flight_Controller_B.BusAssignment_ox,
       &Hummingbird_Flight_Controlle_DW.SinkBlock_a);
    Humm_ReadParameter1_kn_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ayu5da);
    Hummin_ReadParameter_h_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ayu5da);
    Hummi_ReadParameter2_o_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ay);
    Humm_ReadParameter1_l5_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter1_j);
    Hummi_ReadParameter_cl_Init(&Hummingbird_Flight_Controlle_DW.ReadParameter_j);
    Humm_ReadParameter2_ow_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ayu);

    // End of SystemInitialize for SubSystem: '<S1>/Flight_controller.MR_Attitude' 

    // SystemInitialize for IfAction SubSystem: '<S1>/Flight_controller.FW_Nav1' 
    // InitializeConditions for DiscreteIntegrator: '<S116>/Integrator' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_l =
      Hummingbird_Flight_Controller_P.PIDController2_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S168>/Integrator' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Integrator_DSTATE_ld =
      Hummingbird_Flight_Controller_P.PIDController3_InitialConditi_j;

    // InitializeConditions for DiscreteIntegrator: '<S286>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_js[0] =
      Hummingbird_Flight_Controller_P.PIDController1_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S234>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_o[0] =
      Hummingbird_Flight_Controller_P.PIDController_InitialConditionF;

    // InitializeConditions for DiscreteIntegrator: '<S286>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_js[1] =
      Hummingbird_Flight_Controller_P.PIDController1_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S234>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_o[1] =
      Hummingbird_Flight_Controller_P.PIDController_InitialConditionF;

    // InitializeConditions for DiscreteIntegrator: '<S286>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_js[2] =
      Hummingbird_Flight_Controller_P.PIDController1_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S234>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_o[2] =
      Hummingbird_Flight_Controller_P.PIDController_InitialConditionF;

    // SystemInitialize for Chart: '<Root>/Chart'
    Hummingbi_PX4Timestamp_Init(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_n);

    // Start for MATLABSystem: '<S19>/SinkBlock' incorporates:
    //   BusAssignment: '<S17>/Bus Assignment'
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.obj_h3.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_h3.isSetupComplete = false;
    Hummingbird_Flight_Controlle_DW.obj_h3.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_h3.orbMetadataObj = ORB_ID
      (waypoint_nav_debug);
    uORB_write_initialize(Hummingbird_Flight_Controlle_DW.obj_h3.orbMetadataObj,
                          &Hummingbird_Flight_Controlle_DW.obj_h3.orbAdvertiseObj,
                          &Hummingbird_Flight_Controller_B.BusAssignment_o, 1);
    Hummingbird_Flight_Controlle_DW.obj_h3.isSetupComplete = true;

    // SystemInitialize for Chart: '<Root>/Chart'
    Hummingbi_PX4Timestamp_Init(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_c);

    // Start for MATLABSystem: '<S14>/Read Parameter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.obj_lp.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_lp.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_lp.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_h[0], true, 200.0);
    Hummingbird_Flight_Controlle_DW.obj_lp.isSetupComplete = true;

    // Start for MATLABSystem: '<S187>/SinkBlock' incorporates:
    //   BusAssignment: '<S25>/Bus Assignment'
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.obj_lf.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_lf.isSetupComplete = false;
    Hummingbird_Flight_Controlle_DW.obj_lf.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_lf.orbMetadataObj = ORB_ID(tecs_debug);
    uORB_write_initialize(Hummingbird_Flight_Controlle_DW.obj_lf.orbMetadataObj,
                          &Hummingbird_Flight_Controlle_DW.obj_lf.orbAdvertiseObj,
                          &Hummingbird_Flight_Controller_B.BusAssignment_og, 1);
    Hummingbird_Flight_Controlle_DW.obj_lf.isSetupComplete = true;

    // SystemInitialize for Chart: '<Root>/Chart'
    Hummingbi_PX4Timestamp_Init(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_e);

    // Start for MATLABSystem: '<S189>/SinkBlock' incorporates:
    //   BusAssignment: '<S26>/Bus Assignment'
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.obj_cx.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_cx.isSetupComplete = false;
    Hummingbird_Flight_Controlle_DW.obj_cx.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_cx.orbMetadataObj = ORB_ID
      (vehicle_energy);
    uORB_write_initialize(Hummingbird_Flight_Controlle_DW.obj_cx.orbMetadataObj,
                          &Hummingbird_Flight_Controlle_DW.obj_cx.orbAdvertiseObj,
                          &Hummingbird_Flight_Controller_B.BusAssignment_k, 1);
    Hummingbird_Flight_Controlle_DW.obj_cx.isSetupComplete = true;

    // SystemInitialize for Chart: '<Root>/Chart'
    Humming_ReadParameter3_Init(&Hummingbird_Flight_Controlle_DW.ReadParameter3);

    // Start for MATLABSystem: '<S27>/Read Parameter2' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.obj_kb.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_kb.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_kb.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_i[0], true, 200.0);
    Hummingbird_Flight_Controlle_DW.obj_kb.isSetupComplete = true;

    // Start for MATLABSystem: '<S29>/Read Parameter1' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.obj_mt.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_mt.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_mt.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_j[0], true, 200.0);
    Hummingbird_Flight_Controlle_DW.obj_mt.isSetupComplete = true;

    // Start for MATLABSystem: '<S29>/Read Parameter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.obj_ee.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_ee.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_ee.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_k[0], true, 200.0);
    Hummingbird_Flight_Controlle_DW.obj_ee.isSetupComplete = true;

    // Start for MATLABSystem: '<S27>/Read Parameter1' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.obj_eq.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_eq.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_eq.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_l[0], true, 200.0);
    Hummingbird_Flight_Controlle_DW.obj_eq.isSetupComplete = true;

    // Start for MATLABSystem: '<S29>/Read Parameter2' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.obj_oy.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_oy.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_oy.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_m[0], true, 200.0);
    Hummingbird_Flight_Controlle_DW.obj_oy.isSetupComplete = true;

    // Start for MATLABSystem: '<S28>/Read Parameter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.obj_io.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_io.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_io.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_n[0], true, 200.0);
    Hummingbird_Flight_Controlle_DW.obj_io.isSetupComplete = true;

    // SystemInitialize for Chart: '<Root>/Chart'
    Humming_ReadParameter3_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3);

    // Start for MATLABSystem: '<S28>/Read Parameter2' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.obj_ou.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_ou.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_ou.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_o[0], true, 200.0);
    Hummingbird_Flight_Controlle_DW.obj_ou.isSetupComplete = true;

    // SystemInitialize for Chart: '<Root>/Chart'
    Hummingbi_PX4Timestamp_Init(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_i);
    Hummingbird__SinkBlock_Init
      (&Hummingbird_Flight_Controller_B.BusAssignment_fn,
       &Hummingbird_Flight_Controlle_DW.SinkBlock_f);
    Hummingbi_PX4Timestamp_Init(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_p);
    Humming_ReadParameter1_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rg);
    Hummingb_ReadParameter_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rg);
    Hummi_ReadParameter1_l_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rga);
    Hummin_ReadParameter_c_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rga);
    Hummingbir_SinkBlock_b_Init(&Hummingbird_Flight_Controller_B.BusAssignment_p,
      &Hummingbird_Flight_Controlle_DW.SinkBlock_h);
    Hummingbi_PX4Timestamp_Init(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_b);
    Hummi_ReadParameter1_c_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgae);
    Hummin_ReadParameter_l_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgae);
    Humming_ReadParameter2_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3r);
    Hummi_ReadParameter3_c_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter3_b);
    Hummi_ReadParameter2_h_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rg);
    Humming_ReadParameter4_Init(&Hummingbird_Flight_Controlle_DW.ReadParameter4);
    Hummingbir_SinkBlock_a_Init(&Hummingbird_Flight_Controller_B.BusAssignment_b,
      &Hummingbird_Flight_Controlle_DW.SinkBlock_j);
    Hummi_ReadParameter1_i_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaen);
    Hummin_ReadParameter_j_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaen);
    Hummi_ReadParameter2_e_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rga);

    // End of SystemInitialize for SubSystem: '<S1>/Flight_controller.FW_Nav1'

    // SystemInitialize for IfAction SubSystem: '<S1>/Flight_controller.FW_Stabilize' 
    // InitializeConditions for DiscreteIntegrator: '<S464>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_d[0] =
      Hummingbird_Flight_Controller_P.PIDController1_InitialConditi_i;

    // InitializeConditions for DiscreteIntegrator: '<S412>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_p[0] =
      Hummingbird_Flight_Controller_P.PIDController_InitialConditio_g;

    // InitializeConditions for DiscreteIntegrator: '<S464>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_d[1] =
      Hummingbird_Flight_Controller_P.PIDController1_InitialConditi_i;

    // InitializeConditions for DiscreteIntegrator: '<S412>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_p[1] =
      Hummingbird_Flight_Controller_P.PIDController_InitialConditio_g;

    // InitializeConditions for DiscreteIntegrator: '<S464>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_d[2] =
      Hummingbird_Flight_Controller_P.PIDController1_InitialConditi_i;

    // InitializeConditions for DiscreteIntegrator: '<S412>/Filter' incorporates:
    //   Chart: '<Root>/Chart'

    Hummingbird_Flight_Controlle_DW.Filter_DSTATE_p[2] =
      Hummingbird_Flight_Controller_P.PIDController_InitialConditio_g;

    // SystemInitialize for Chart: '<Root>/Chart'
    Hummingbi_PX4Timestamp_Init(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_l);
    Hummingbird__SinkBlock_Init
      (&Hummingbird_Flight_Controller_B.BusAssignment_nb,
       &Hummingbird_Flight_Controlle_DW.SinkBlock_l);
    Hummingbi_PX4Timestamp_Init(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_p5);
    Humming_ReadParameter1_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb);
    Hummingb_ReadParameter_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb);
    Hummi_ReadParameter1_l_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3);
    Hummin_ReadParameter_c_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3);
    Hummingbir_SinkBlock_b_Init
      (&Hummingbird_Flight_Controller_B.BusAssignment_j1,
       &Hummingbird_Flight_Controlle_DW.SinkBlock_c);
    Hummingbi_PX4Timestamp_Init(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_ct);
    Hummi_ReadParameter1_c_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3a);
    Hummin_ReadParameter_l_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3a);
    Humming_ReadParameter2_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgae);
    Hummi_ReadParameter3_c_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter3_b3);
    Hummi_ReadParameter2_h_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaen);
    Humming_ReadParameter4_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter4_b);
    Hummingbir_SinkBlock_a_Init
      (&Hummingbird_Flight_Controller_B.BusAssignment_ia,
       &Hummingbird_Flight_Controlle_DW.SinkBlock_cp);
    Hummi_ReadParameter1_i_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ay);
    Hummin_ReadParameter_j_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ay);
    Hummi_ReadParameter2_e_Init
      (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb);

    // End of SystemInitialize for SubSystem: '<S1>/Flight_controller.FW_Stabilize' 

    // SystemInitialize for IfAction SubSystem: '<S2>/Controller.Controlled'
    // SystemInitialize for Chart: '<Root>/Chart1'
    Hummingbi_PX4Timestamp_Init(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_j2);

    // Start for MATLABSystem: '<S1470>/SinkBlock' incorporates:
    //   BusAssignment: '<S1464>/Bus Assignment'
    //   Chart: '<Root>/Chart1'

    Hummingbird_Flight_Controlle_DW.obj_c.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_c.isSetupComplete = false;
    Hummingbird_Flight_Controlle_DW.obj_c.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_c.orbMetadataObj = ORB_ID
      (delta_fixed_wing);
    uORB_write_initialize(Hummingbird_Flight_Controlle_DW.obj_c.orbMetadataObj,
                          &Hummingbird_Flight_Controlle_DW.obj_c.orbAdvertiseObj,
                          &Hummingbird_Flight_Controller_B.BusAssignment_c, 1);
    Hummingbird_Flight_Controlle_DW.obj_c.isSetupComplete = true;

    // SystemInitialize for Chart: '<Root>/Chart1'
    Hummingbi_PX4Timestamp_Init(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_pm);

    // Start for MATLABSystem: '<S1472>/SinkBlock' incorporates:
    //   BusAssignment: '<S1465>/Bus Assignment'
    //   Chart: '<Root>/Chart1'

    Hummingbird_Flight_Controlle_DW.obj_l.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_l.isSetupComplete = false;
    Hummingbird_Flight_Controlle_DW.obj_l.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_l.orbMetadataObj = ORB_ID(debug_array);
    uORB_write_initialize(Hummingbird_Flight_Controlle_DW.obj_l.orbMetadataObj,
                          &Hummingbird_Flight_Controlle_DW.obj_l.orbAdvertiseObj,
                          &Hummingbird_Flight_Controller_B.BusAssignment, 1);
    Hummingbird_Flight_Controlle_DW.obj_l.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S2>/Controller.Controlled'

    // SystemInitialize for Enabled SubSystem: '<S1504>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S1505>/In1' incorporates:
    //   Outport: '<S1505>/Out1'

    Hummingbird_Flight_Controller_B.In1_i =
      Hummingbird_Flight_Controller_P.Out1_Y0_c;

    // End of SystemInitialize for SubSystem: '<S1504>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S1485>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S1558>/In1' incorporates:
    //   Outport: '<S1558>/Out1'

    Hummingbird_Flight_Controller_B.In1_fv =
      Hummingbird_Flight_Controller_P.Out1_Y0_n3;

    // End of SystemInitialize for SubSystem: '<S1485>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S1487>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S1560>/In1' incorporates:
    //   Outport: '<S1560>/Out1'

    Hummingbird_Flight_Controller_B.In1_p =
      Hummingbird_Flight_Controller_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S1487>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S1500>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S1564>/In1' incorporates:
    //   Outport: '<S1564>/Out1'

    Hummingbird_Flight_Controller_B.In1_l =
      Hummingbird_Flight_Controller_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S1500>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S1501>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S1565>/In1' incorporates:
    //   Outport: '<S1565>/Out1'

    Hummingbird_Flight_Controller_B.In1_f =
      Hummingbird_Flight_Controller_P.Out1_Y0_ds;

    // End of SystemInitialize for SubSystem: '<S1501>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S1502>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S1566>/In1' incorporates:
    //   Outport: '<S1566>/Out1'

    Hummingbird_Flight_Controller_B.In1_j =
      Hummingbird_Flight_Controller_P.Out1_Y0_n;

    // End of SystemInitialize for SubSystem: '<S1502>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S1503>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S1567>/In1' incorporates:
    //   Outport: '<S1567>/Out1'

    Hummingbird_Flight_Controller_B.In1_a =
      Hummingbird_Flight_Controller_P.Out1_Y0_g;

    // End of SystemInitialize for SubSystem: '<S1503>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S1486>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S1559>/In1' incorporates:
    //   Outport: '<S1559>/Out1'

    Hummingbird_Flight_Controller_B.In1_d =
      Hummingbird_Flight_Controller_P.Out1_Y0_ns;

    // End of SystemInitialize for SubSystem: '<S1486>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S1488>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S1561>/In1' incorporates:
    //   Outport: '<S1561>/Out1'

    Hummingbird_Flight_Controller_B.In1 =
      Hummingbird_Flight_Controller_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S1488>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S1489>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S1562>/In1' incorporates:
    //   Outport: '<S1562>/Out1'

    Hummingbird_Flight_Controller_B.In1_i4 =
      Hummingbird_Flight_Controller_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S1489>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S1490>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S1563>/In1' incorporates:
    //   Outport: '<S1563>/Out1'

    Hummingbird_Flight_Controller_B.In1_m =
      Hummingbird_Flight_Controller_P.Out1_Y0_l;

    // End of SystemInitialize for SubSystem: '<S1490>/Enabled Subsystem'

    // Start for MATLABSystem: '<S1502>/SourceBlock'
    Hummingbird_Flight_Controlle_DW.obj_o.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_o.isSetupComplete = false;
    Hummingbird_Flight_Controlle_DW.obj_o.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_o.orbMetadataObj = ORB_ID
      (vehicle_local_position);
    uORB_read_initialize(Hummingbird_Flight_Controlle_DW.obj_o.orbMetadataObj,
                         &Hummingbird_Flight_Controlle_DW.obj_o.eventStructObj);
    Hummingbird_Flight_Controlle_DW.obj_o.isSetupComplete = true;

    // Start for MATLABSystem: '<S1500>/SourceBlock'
    Hummingbird_Flight_Controlle_DW.obj_k.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_k.isSetupComplete = false;
    Hummingbird_Flight_Controlle_DW.obj_k.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_k.orbMetadataObj = ORB_ID
      (vehicle_attitude);
    uORB_read_initialize(Hummingbird_Flight_Controlle_DW.obj_k.orbMetadataObj,
                         &Hummingbird_Flight_Controlle_DW.obj_k.eventStructObj);
    Hummingbird_Flight_Controlle_DW.obj_k.isSetupComplete = true;

    // Start for MATLABSystem: '<S1501>/SourceBlock'
    Hummingbird_Flight_Controlle_DW.obj_a.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_a.isSetupComplete = false;
    Hummingbird_Flight_Controlle_DW.obj_a.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_a.orbMetadataObj = ORB_ID
      (sensor_combined);
    uORB_read_initialize(Hummingbird_Flight_Controlle_DW.obj_a.orbMetadataObj,
                         &Hummingbird_Flight_Controlle_DW.obj_a.eventStructObj);
    Hummingbird_Flight_Controlle_DW.obj_a.isSetupComplete = true;

    // Start for MATLABSystem: '<S1487>/SourceBlock'
    Hummingbird_Flight_Controlle_DW.obj_m.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_m.isSetupComplete = false;
    Hummingbird_Flight_Controlle_DW.obj_m.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_m.orbMetadataObj = ORB_ID(airspeed);
    uORB_read_initialize(Hummingbird_Flight_Controlle_DW.obj_m.orbMetadataObj,
                         &Hummingbird_Flight_Controlle_DW.obj_m.eventStructObj);
    Hummingbird_Flight_Controlle_DW.obj_m.isSetupComplete = true;

    // Start for MATLABSystem: '<S1485>/SourceBlock'
    Hummingbird_Flight_Controlle_DW.obj_h.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_h.isSetupComplete = false;
    Hummingbird_Flight_Controlle_DW.obj_h.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_h.orbMetadataObj = ORB_ID(actuator_armed);
    uORB_read_initialize(Hummingbird_Flight_Controlle_DW.obj_h.orbMetadataObj,
                         &Hummingbird_Flight_Controlle_DW.obj_h.eventStructObj);
    Hummingbird_Flight_Controlle_DW.obj_h.isSetupComplete = true;

    // Start for MATLABSystem: '<S1503>/SourceBlock'
    Hummingbird_Flight_Controlle_DW.obj_i.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_i.isSetupComplete = false;
    Hummingbird_Flight_Controlle_DW.obj_i.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_i.orbMetadataObj = ORB_ID
      (vehicle_global_position);
    uORB_read_initialize(Hummingbird_Flight_Controlle_DW.obj_i.orbMetadataObj,
                         &Hummingbird_Flight_Controlle_DW.obj_i.eventStructObj);
    Hummingbird_Flight_Controlle_DW.obj_i.isSetupComplete = true;

    // Start for MATLABSystem: '<S1486>/SourceBlock'
    Hummingbird_Flight_Controlle_DW.obj_p.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_p.isSetupComplete = false;
    Hummingbird_Flight_Controlle_DW.obj_p.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_p.orbMetadataObj = ORB_ID(input_rc);
    uORB_read_initialize(Hummingbird_Flight_Controlle_DW.obj_p.orbMetadataObj,
                         &Hummingbird_Flight_Controlle_DW.obj_p.eventStructObj);
    Hummingbird_Flight_Controlle_DW.obj_p.isSetupComplete = true;

    // Start for MATLABSystem: '<S1488>/SourceBlock'
    Hummingbird_Flight_Controlle_DW.obj_az.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_az.isSetupComplete = false;
    Hummingbird_Flight_Controlle_DW.obj_az.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_az.orbMetadataObj = ORB_ID
      (position_setpoint_triplet);
    uORB_read_initialize(Hummingbird_Flight_Controlle_DW.obj_az.orbMetadataObj,
                         &Hummingbird_Flight_Controlle_DW.obj_az.eventStructObj);
    Hummingbird_Flight_Controlle_DW.obj_az.isSetupComplete = true;

    // Start for MATLABSystem: '<S1489>/SourceBlock'
    Hummingbird_Flight_Controlle_DW.obj_g.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_g.isSetupComplete = false;
    Hummingbird_Flight_Controlle_DW.obj_g.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_g.orbMetadataObj = ORB_ID(home_position);
    uORB_read_initialize(Hummingbird_Flight_Controlle_DW.obj_g.orbMetadataObj,
                         &Hummingbird_Flight_Controlle_DW.obj_g.eventStructObj);
    Hummingbird_Flight_Controlle_DW.obj_g.isSetupComplete = true;

    // Start for MATLABSystem: '<S1490>/SourceBlock'
    Hummingbird_Flight_Controlle_DW.obj_im.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_im.isSetupComplete = false;
    Hummingbird_Flight_Controlle_DW.obj_im.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_im.orbMetadataObj = ORB_ID
      (actuator_position);
    uORB_read_initialize(Hummingbird_Flight_Controlle_DW.obj_im.orbMetadataObj,
                         &Hummingbird_Flight_Controlle_DW.obj_im.eventStructObj);
    Hummingbird_Flight_Controlle_DW.obj_im.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/PX4 Actuator Write1'
    for (i = 0; i < 12; i++) {
      Hummingbird_Flight_Controlle_DW.obj.ValidMotorIdx[i] = false;
    }

    for (i = 0; i < 8; i++) {
      Hummingbird_Flight_Controlle_DW.obj.ValidServoIdx[i] = false;
    }

    Hummingbird_Flight_Controlle_DW.obj.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj.isSetupComplete = false;
    Hummingbird_Flight_Controlle_DW.obj.isInitialized = 1;
    Hummingb_PX4Actuators_setupImpl(&Hummingbird_Flight_Controlle_DW.obj);
    Hummingbird_Flight_Controlle_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/PX4 Actuator Write1'
    Hummingbi_PX4Timestamp_Init(&Hummingbird_Flight_Controlle_DW.PX4Timestamp);

    // Start for MATLABSystem: '<S1481>/SinkBlock' incorporates:
    //   BusAssignment: '<S3>/Bus Assignment'

    Hummingbird_Flight_Controlle_DW.obj_j.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_j.isSetupComplete = false;
    Hummingbird_Flight_Controlle_DW.obj_j.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_j.orbMetadataObj = ORB_ID
      (actuator_position);
    uORB_write_initialize(Hummingbird_Flight_Controlle_DW.obj_j.orbMetadataObj,
                          &Hummingbird_Flight_Controlle_DW.obj_j.orbAdvertiseObj,
                          &Hummingbird_Flight_Controller_B.BusAssignment_m, 1);
    Hummingbird_Flight_Controlle_DW.obj_j.isSetupComplete = true;

    // Start for MATLABSystem: '<S1504>/SourceBlock'
    Hummingbird_Flight_Controlle_DW.obj_gv.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_gv.isSetupComplete = false;
    Hummingbird_Flight_Controlle_DW.obj_gv.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_gv.orbMetadataObj = ORB_ID(sensor_accel);
    uORB_read_initialize(Hummingbird_Flight_Controlle_DW.obj_gv.orbMetadataObj,
                         &Hummingbird_Flight_Controlle_DW.obj_gv.eventStructObj);
    Hummingbird_Flight_Controlle_DW.obj_gv.isSetupComplete = true;

    // Start for MATLABSystem: '<S1491>/Read Parameter'
    Hummingbird_Flight_Controlle_DW.obj_ns.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_ns.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_ns.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr[0], true, 500.0);
    Hummingbird_Flight_Controlle_DW.obj_ns.isSetupComplete = true;

    // Start for MATLABSystem: '<S1491>/Read Parameter1'
    Hummingbird_Flight_Controlle_DW.obj_g0.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_g0.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_g0.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_0[0], true, 500.0);
    Hummingbird_Flight_Controlle_DW.obj_g0.isSetupComplete = true;

    // Start for MATLABSystem: '<S1492>/Read Parameter'
    Hummingbird_Flight_Controlle_DW.obj_er.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_er.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_er.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_1[0], true, 500.0);
    Hummingbird_Flight_Controlle_DW.obj_er.isSetupComplete = true;

    // Start for MATLABSystem: '<S1492>/Read Parameter1'
    Hummingbird_Flight_Controlle_DW.obj_ez.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_ez.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_ez.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_2[0], true, 500.0);
    Hummingbird_Flight_Controlle_DW.obj_ez.isSetupComplete = true;

    // Start for MATLABSystem: '<S1493>/Read Parameter'
    Hummingbird_Flight_Controlle_DW.obj_ar.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_ar.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_ar.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_3[0], true, 500.0);
    Hummingbird_Flight_Controlle_DW.obj_ar.isSetupComplete = true;

    // Start for MATLABSystem: '<S1493>/Read Parameter1'
    Hummingbird_Flight_Controlle_DW.obj_iy.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_iy.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_iy.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_4[0], true, 500.0);
    Hummingbird_Flight_Controlle_DW.obj_iy.isSetupComplete = true;

    // Start for MATLABSystem: '<S1494>/Read Parameter'
    Hummingbird_Flight_Controlle_DW.obj_mb.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_mb.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_mb.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_5[0], true, 500.0);
    Hummingbird_Flight_Controlle_DW.obj_mb.isSetupComplete = true;

    // Start for MATLABSystem: '<S1494>/Read Parameter1'
    Hummingbird_Flight_Controlle_DW.obj_e.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_e.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_e.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_6[0], true, 500.0);
    Hummingbird_Flight_Controlle_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<S1495>/Read Parameter'
    Hummingbird_Flight_Controlle_DW.obj_iw.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_iw.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_iw.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_7[0], true, 500.0);
    Hummingbird_Flight_Controlle_DW.obj_iw.isSetupComplete = true;

    // Start for MATLABSystem: '<S1495>/Read Parameter1'
    Hummingbird_Flight_Controlle_DW.obj_hw.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_hw.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_hw.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_8[0], true, 500.0);
    Hummingbird_Flight_Controlle_DW.obj_hw.isSetupComplete = true;

    // Start for MATLABSystem: '<S1496>/Read Parameter'
    Hummingbird_Flight_Controlle_DW.obj_n.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_n.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_n.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_9[0], true, 500.0);
    Hummingbird_Flight_Controlle_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<S1496>/Read Parameter1'
    Hummingbird_Flight_Controlle_DW.obj_b.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_b.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_b.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_a[0], true, 500.0);
    Hummingbird_Flight_Controlle_DW.obj_b.isSetupComplete = true;

    // Start for MATLABSystem: '<S1497>/Read Parameter'
    Hummingbird_Flight_Controlle_DW.obj_ip.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_ip.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_ip.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_b[0], true, 500.0);
    Hummingbird_Flight_Controlle_DW.obj_ip.isSetupComplete = true;

    // Start for MATLABSystem: '<S1497>/Read Parameter1'
    Hummingbird_Flight_Controlle_DW.obj_j1.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_j1.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_j1.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_c[0], true, 500.0);
    Hummingbird_Flight_Controlle_DW.obj_j1.isSetupComplete = true;

    // Start for MATLABSystem: '<S1498>/Read Parameter'
    Hummingbird_Flight_Controlle_DW.obj_ci.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_ci.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_ci.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_d[0], true, 500.0);
    Hummingbird_Flight_Controlle_DW.obj_ci.isSetupComplete = true;

    // Start for MATLABSystem: '<S1498>/Read Parameter1'
    Hummingbird_Flight_Controlle_DW.obj_lk.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_lk.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_lk.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_e[0], true, 500.0);
    Hummingbird_Flight_Controlle_DW.obj_lk.isSetupComplete = true;

    // Start for MATLABSystem: '<S1499>/Read Parameter'
    Hummingbird_Flight_Controlle_DW.obj_d.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_d.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_d.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_f[0], true, 500.0);
    Hummingbird_Flight_Controlle_DW.obj_d.isSetupComplete = true;

    // Start for MATLABSystem: '<S1499>/Read Parameter1'
    Hummingbird_Flight_Controlle_DW.obj_ii.matlabCodegenIsDeleted = false;
    Hummingbird_Flight_Controlle_DW.obj_ii.isInitialized = 1;
    Hummingbird_Flight_Controlle_DW.obj_ii.MW_PARAMHANDLE = MW_Init_Param
      (&ParameterNameStr_g[0], true, 500.0);
    Hummingbird_Flight_Controlle_DW.obj_ii.isSetupComplete = true;
  }
}

// Model terminate function
void Hummingbird_Flight_Controller_Lower_Memory_terminate(void)
{
  int32_T i;
  real32_T servoValues[8];

  // Terminate for MATLABSystem: '<S1502>/SourceBlock'
  if (!Hummingbird_Flight_Controlle_DW.obj_o.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Hummingbird_Flight_Controlle_DW.obj_o.isInitialized == 1) &&
        Hummingbird_Flight_Controlle_DW.obj_o.isSetupComplete) {
      uORB_read_terminate(&Hummingbird_Flight_Controlle_DW.obj_o.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S1502>/SourceBlock'

  // Terminate for MATLABSystem: '<S1500>/SourceBlock'
  if (!Hummingbird_Flight_Controlle_DW.obj_k.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((Hummingbird_Flight_Controlle_DW.obj_k.isInitialized == 1) &&
        Hummingbird_Flight_Controlle_DW.obj_k.isSetupComplete) {
      uORB_read_terminate(&Hummingbird_Flight_Controlle_DW.obj_k.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S1500>/SourceBlock'

  // Terminate for MATLABSystem: '<S1501>/SourceBlock'
  if (!Hummingbird_Flight_Controlle_DW.obj_a.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Hummingbird_Flight_Controlle_DW.obj_a.isInitialized == 1) &&
        Hummingbird_Flight_Controlle_DW.obj_a.isSetupComplete) {
      uORB_read_terminate(&Hummingbird_Flight_Controlle_DW.obj_a.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S1501>/SourceBlock'

  // Terminate for MATLABSystem: '<S1487>/SourceBlock'
  if (!Hummingbird_Flight_Controlle_DW.obj_m.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Hummingbird_Flight_Controlle_DW.obj_m.isInitialized == 1) &&
        Hummingbird_Flight_Controlle_DW.obj_m.isSetupComplete) {
      uORB_read_terminate(&Hummingbird_Flight_Controlle_DW.obj_m.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S1487>/SourceBlock'

  // Terminate for MATLABSystem: '<S1485>/SourceBlock'
  if (!Hummingbird_Flight_Controlle_DW.obj_h.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Hummingbird_Flight_Controlle_DW.obj_h.isInitialized == 1) &&
        Hummingbird_Flight_Controlle_DW.obj_h.isSetupComplete) {
      uORB_read_terminate(&Hummingbird_Flight_Controlle_DW.obj_h.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S1485>/SourceBlock'

  // Terminate for MATLABSystem: '<S1503>/SourceBlock'
  if (!Hummingbird_Flight_Controlle_DW.obj_i.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((Hummingbird_Flight_Controlle_DW.obj_i.isInitialized == 1) &&
        Hummingbird_Flight_Controlle_DW.obj_i.isSetupComplete) {
      uORB_read_terminate(&Hummingbird_Flight_Controlle_DW.obj_i.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S1503>/SourceBlock'

  // Terminate for MATLABSystem: '<S1486>/SourceBlock'
  if (!Hummingbird_Flight_Controlle_DW.obj_p.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Hummingbird_Flight_Controlle_DW.obj_p.isInitialized == 1) &&
        Hummingbird_Flight_Controlle_DW.obj_p.isSetupComplete) {
      uORB_read_terminate(&Hummingbird_Flight_Controlle_DW.obj_p.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S1486>/SourceBlock'

  // Terminate for MATLABSystem: '<S1488>/SourceBlock'
  if (!Hummingbird_Flight_Controlle_DW.obj_az.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_az.matlabCodegenIsDeleted = true;
    if ((Hummingbird_Flight_Controlle_DW.obj_az.isInitialized == 1) &&
        Hummingbird_Flight_Controlle_DW.obj_az.isSetupComplete) {
      uORB_read_terminate(&Hummingbird_Flight_Controlle_DW.obj_az.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S1488>/SourceBlock'

  // Terminate for MATLABSystem: '<S1489>/SourceBlock'
  if (!Hummingbird_Flight_Controlle_DW.obj_g.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((Hummingbird_Flight_Controlle_DW.obj_g.isInitialized == 1) &&
        Hummingbird_Flight_Controlle_DW.obj_g.isSetupComplete) {
      uORB_read_terminate(&Hummingbird_Flight_Controlle_DW.obj_g.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S1489>/SourceBlock'

  // Terminate for IfAction SubSystem: '<S1>/Flight_controller.MR_Nav'
  // Terminate for Chart: '<Root>/Chart'
  Hummingbi_PX4Timestamp_Term(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_pb);
  Hummingbird__SinkBlock_Term(&Hummingbird_Flight_Controlle_DW.SinkBlock_ir);
  Hummingbi_PX4Timestamp_Term(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_a);
  Hummi_ReadParameter1_n_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter1_o);
  Hummin_ReadParameter_l_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter_o);
  Hummi_ReadParameter2_a_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ayu5);
  Humm_ReadParameter1_gu_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter1_l);
  Hummin_ReadParameter_k_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter_l);
  Hummi_ReadParameter2_h_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ayu5d);
  Hummingbir_SinkBlock_i_Term(&Hummingbird_Flight_Controlle_DW.SinkBlock_fv);
  Hummingbi_PX4Timestamp_Term(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_ac);
  Hummingbir_SinkBlock_f_Term(&Hummingbird_Flight_Controlle_DW.SinkBlock_fw);
  Humm_ReadParameter1_n2_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter1_px);
  Hummin_ReadParameter_e_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter_px);
  Hummi_ReadParameter2_o_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ayu5da);
  Hummi_ReadParameter1_k_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter1_i);
  Hummi_ReadParameter_ms_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter_i);
  Hummi_ReadParameter2_j_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter2_j);

  // End of Terminate for SubSystem: '<S1>/Flight_controller.MR_Nav'

  // Terminate for IfAction SubSystem: '<S1>/Flight_controller.MR_Vel1'
  Hummingbi_PX4Timestamp_Term(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_d);
  Hummin_ReadParameter_m_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter_ld);
  Hummi_ReadParameter1_f_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter1_ld);

  // Terminate for MATLABSystem: '<S1399>/SinkBlock' incorporates:
  //   Chart: '<Root>/Chart'

  if (!Hummingbird_Flight_Controlle_DW.obj_hh.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_hh.matlabCodegenIsDeleted = true;
    if ((Hummingbird_Flight_Controlle_DW.obj_hh.isInitialized == 1) &&
        Hummingbird_Flight_Controlle_DW.obj_hh.isSetupComplete) {
      uORB_write_terminate
        (&Hummingbird_Flight_Controlle_DW.obj_hh.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S1399>/SinkBlock'

  // Terminate for Chart: '<Root>/Chart'
  Hummingbi_PX4Timestamp_Term(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_g);
  Hummingbird__SinkBlock_Term(&Hummingbird_Flight_Controlle_DW.SinkBlock_hd);
  Hummingbi_PX4Timestamp_Term(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_j);
  Hummi_ReadParameter1_n_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter1_k);
  Hummin_ReadParameter_l_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter_k);
  Hummi_ReadParameter2_a_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter2_o);
  Humm_ReadParameter1_gu_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter1_lu);
  Hummin_ReadParameter_k_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter_lu);
  Hummi_ReadParameter2_h_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter2_l);
  Hummingbir_SinkBlock_i_Term(&Hummingbird_Flight_Controlle_DW.SinkBlock_o);
  Hummingbi_PX4Timestamp_Term(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_k);
  Hummingbir_SinkBlock_f_Term(&Hummingbird_Flight_Controlle_DW.SinkBlock_jf);
  Humm_ReadParameter1_n2_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter1_m);
  Hummin_ReadParameter_e_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter_m);
  Hummi_ReadParameter2_o_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter2_p);
  Hummi_ReadParameter1_k_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter1_kh);
  Hummi_ReadParameter_ms_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter_kh);
  Hummi_ReadParameter2_j_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter2_i);

  // End of Terminate for SubSystem: '<S1>/Flight_controller.MR_Vel1'

  // Terminate for IfAction SubSystem: '<S1>/Flight_controller.MR_Attitude'
  Hummin_ReadParameter_m_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ayu);
  Hummi_ReadParameter1_f_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ayu);
  Hummingbi_PX4Timestamp_Term(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_m);
  Hummingbird__SinkBlock_Term(&Hummingbird_Flight_Controlle_DW.SinkBlock_lp);
  Hummingbi_PX4Timestamp_Term(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_ef);
  Hummi_ReadParameter1_n_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ayu5);
  Hummin_ReadParameter_l_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ayu5);
  Hummi_ReadParameter2_a_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3);
  Humm_ReadParameter1_gu_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ayu5d);
  Hummin_ReadParameter_k_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ayu5d);
  Hummi_ReadParameter2_h_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3a);
  Hummingbir_SinkBlock_i_Term(&Hummingbird_Flight_Controlle_DW.SinkBlock_d);
  Hummingbi_PX4Timestamp_Term(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_cf);
  Hummingbir_SinkBlock_f_Term(&Hummingbird_Flight_Controlle_DW.SinkBlock_a);
  Humm_ReadParameter1_n2_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ayu5da);
  Hummin_ReadParameter_e_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ayu5da);
  Hummi_ReadParameter2_o_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ay);
  Hummi_ReadParameter1_k_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter1_j);
  Hummi_ReadParameter_ms_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter_j);
  Hummi_ReadParameter2_j_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb3ayu);

  // End of Terminate for SubSystem: '<S1>/Flight_controller.MR_Attitude'

  // Terminate for IfAction SubSystem: '<S1>/Flight_controller.FW_Nav1'
  Hummingbi_PX4Timestamp_Term(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_n);

  // Terminate for MATLABSystem: '<S19>/SinkBlock' incorporates:
  //   Chart: '<Root>/Chart'

  if (!Hummingbird_Flight_Controlle_DW.obj_h3.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_h3.matlabCodegenIsDeleted = true;
    if ((Hummingbird_Flight_Controlle_DW.obj_h3.isInitialized == 1) &&
        Hummingbird_Flight_Controlle_DW.obj_h3.isSetupComplete) {
      uORB_write_terminate
        (&Hummingbird_Flight_Controlle_DW.obj_h3.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S19>/SinkBlock'

  // Terminate for Chart: '<Root>/Chart'
  Hummingbi_PX4Timestamp_Term(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_c);

  // Terminate for MATLABSystem: '<S14>/Read Parameter' incorporates:
  //   Chart: '<Root>/Chart'

  if (!Hummingbird_Flight_Controlle_DW.obj_lp.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_lp.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/Read Parameter'

  // Terminate for MATLABSystem: '<S187>/SinkBlock' incorporates:
  //   Chart: '<Root>/Chart'

  if (!Hummingbird_Flight_Controlle_DW.obj_lf.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_lf.matlabCodegenIsDeleted = true;
    if ((Hummingbird_Flight_Controlle_DW.obj_lf.isInitialized == 1) &&
        Hummingbird_Flight_Controlle_DW.obj_lf.isSetupComplete) {
      uORB_write_terminate
        (&Hummingbird_Flight_Controlle_DW.obj_lf.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S187>/SinkBlock'

  // Terminate for Chart: '<Root>/Chart'
  Hummingbi_PX4Timestamp_Term(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_e);

  // Terminate for MATLABSystem: '<S189>/SinkBlock' incorporates:
  //   Chart: '<Root>/Chart'

  if (!Hummingbird_Flight_Controlle_DW.obj_cx.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_cx.matlabCodegenIsDeleted = true;
    if ((Hummingbird_Flight_Controlle_DW.obj_cx.isInitialized == 1) &&
        Hummingbird_Flight_Controlle_DW.obj_cx.isSetupComplete) {
      uORB_write_terminate
        (&Hummingbird_Flight_Controlle_DW.obj_cx.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S189>/SinkBlock'

  // Terminate for Chart: '<Root>/Chart'
  Humming_ReadParameter3_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter3);

  // Terminate for MATLABSystem: '<S27>/Read Parameter2' incorporates:
  //   Chart: '<Root>/Chart'

  if (!Hummingbird_Flight_Controlle_DW.obj_kb.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_kb.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S27>/Read Parameter2'

  // Terminate for MATLABSystem: '<S29>/Read Parameter1' incorporates:
  //   Chart: '<Root>/Chart'

  if (!Hummingbird_Flight_Controlle_DW.obj_mt.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_mt.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S29>/Read Parameter1'

  // Terminate for MATLABSystem: '<S29>/Read Parameter' incorporates:
  //   Chart: '<Root>/Chart'

  if (!Hummingbird_Flight_Controlle_DW.obj_ee.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_ee.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S29>/Read Parameter'

  // Terminate for MATLABSystem: '<S27>/Read Parameter1' incorporates:
  //   Chart: '<Root>/Chart'

  if (!Hummingbird_Flight_Controlle_DW.obj_eq.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_eq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S27>/Read Parameter1'

  // Terminate for MATLABSystem: '<S29>/Read Parameter2' incorporates:
  //   Chart: '<Root>/Chart'

  if (!Hummingbird_Flight_Controlle_DW.obj_oy.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_oy.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S29>/Read Parameter2'

  // Terminate for MATLABSystem: '<S28>/Read Parameter' incorporates:
  //   Chart: '<Root>/Chart'

  if (!Hummingbird_Flight_Controlle_DW.obj_io.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_io.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S28>/Read Parameter'

  // Terminate for Chart: '<Root>/Chart'
  Humming_ReadParameter3_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3);

  // Terminate for MATLABSystem: '<S28>/Read Parameter2' incorporates:
  //   Chart: '<Root>/Chart'

  if (!Hummingbird_Flight_Controlle_DW.obj_ou.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_ou.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S28>/Read Parameter2'

  // Terminate for Chart: '<Root>/Chart'
  Hummingbi_PX4Timestamp_Term(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_i);
  Hummingbird__SinkBlock_Term(&Hummingbird_Flight_Controlle_DW.SinkBlock_f);
  Hummingbi_PX4Timestamp_Term(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_p);
  Humming_ReadParameter1_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rg);
  Hummingb_ReadParameter_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rg);
  Hummi_ReadParameter1_c_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rga);
  Hummin_ReadParameter_o_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rga);
  Hummingbir_SinkBlock_i_Term(&Hummingbird_Flight_Controlle_DW.SinkBlock_h);
  Hummingbi_PX4Timestamp_Term(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_b);
  Hummi_ReadParameter1_g_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgae);
  Hummin_ReadParameter_c_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgae);
  Humming_ReadParameter2_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3r);
  Hummi_ReadParameter3_a_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter3_b);
  Hummi_ReadParameter2_b_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rg);
  Humming_ReadParameter4_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter4);
  Hummingbir_SinkBlock_f_Term(&Hummingbird_Flight_Controlle_DW.SinkBlock_j);
  Hummi_ReadParameter1_h_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaen);
  Hummin_ReadParameter_g_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaen);
  Hummi_ReadParameter2_l_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rga);

  // End of Terminate for SubSystem: '<S1>/Flight_controller.FW_Nav1'

  // Terminate for IfAction SubSystem: '<S1>/Flight_controller.FW_Stabilize'
  Hummingbi_PX4Timestamp_Term(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_l);
  Hummingbird__SinkBlock_Term(&Hummingbird_Flight_Controlle_DW.SinkBlock_l);
  Hummingbi_PX4Timestamp_Term(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_p5);
  Humming_ReadParameter1_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb);
  Hummingb_ReadParameter_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb);
  Hummi_ReadParameter1_c_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3);
  Hummin_ReadParameter_o_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3);
  Hummingbir_SinkBlock_i_Term(&Hummingbird_Flight_Controlle_DW.SinkBlock_c);
  Hummingbi_PX4Timestamp_Term(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_ct);
  Hummi_ReadParameter1_g_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3a);
  Hummin_ReadParameter_c_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3a);
  Humming_ReadParameter2_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgae);
  Hummi_ReadParameter3_a_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter3_b3);
  Hummi_ReadParameter2_b_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaen);
  Humming_ReadParameter4_Term(&Hummingbird_Flight_Controlle_DW.ReadParameter4_b);
  Hummingbir_SinkBlock_f_Term(&Hummingbird_Flight_Controlle_DW.SinkBlock_cp);
  Hummi_ReadParameter1_h_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter1_b3rgaenb3ay);
  Hummin_ReadParameter_g_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter_b3rgaenb3ay);
  Hummi_ReadParameter2_l_Term
    (&Hummingbird_Flight_Controlle_DW.ReadParameter2_b3rgaenb);

  // End of Terminate for SubSystem: '<S1>/Flight_controller.FW_Stabilize'

  // Terminate for MATLABSystem: '<S1490>/SourceBlock'
  if (!Hummingbird_Flight_Controlle_DW.obj_im.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_im.matlabCodegenIsDeleted = true;
    if ((Hummingbird_Flight_Controlle_DW.obj_im.isInitialized == 1) &&
        Hummingbird_Flight_Controlle_DW.obj_im.isSetupComplete) {
      uORB_read_terminate(&Hummingbird_Flight_Controlle_DW.obj_im.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S1490>/SourceBlock'

  // Terminate for IfAction SubSystem: '<S2>/Controller.Controlled'
  // Terminate for Chart: '<Root>/Chart1'
  Hummingbi_PX4Timestamp_Term(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_j2);

  // Terminate for MATLABSystem: '<S1470>/SinkBlock' incorporates:
  //   Chart: '<Root>/Chart1'

  if (!Hummingbird_Flight_Controlle_DW.obj_c.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((Hummingbird_Flight_Controlle_DW.obj_c.isInitialized == 1) &&
        Hummingbird_Flight_Controlle_DW.obj_c.isSetupComplete) {
      uORB_write_terminate
        (&Hummingbird_Flight_Controlle_DW.obj_c.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S1470>/SinkBlock'

  // Terminate for Chart: '<Root>/Chart1'
  Hummingbi_PX4Timestamp_Term(&Hummingbird_Flight_Controlle_DW.PX4Timestamp_pm);

  // Terminate for MATLABSystem: '<S1472>/SinkBlock' incorporates:
  //   Chart: '<Root>/Chart1'

  if (!Hummingbird_Flight_Controlle_DW.obj_l.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Hummingbird_Flight_Controlle_DW.obj_l.isInitialized == 1) &&
        Hummingbird_Flight_Controlle_DW.obj_l.isSetupComplete) {
      uORB_write_terminate
        (&Hummingbird_Flight_Controlle_DW.obj_l.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S1472>/SinkBlock'
  // End of Terminate for SubSystem: '<S2>/Controller.Controlled'

  // Terminate for MATLABSystem: '<Root>/PX4 Actuator Write1'
  if (!Hummingbird_Flight_Controlle_DW.obj.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj.matlabCodegenIsDeleted = true;
    if ((Hummingbird_Flight_Controlle_DW.obj.isInitialized == 1) &&
        Hummingbird_Flight_Controlle_DW.obj.isSetupComplete) {
      for (i = 0; i < 12; i++) {
        Hummingbird_Flight_Controller_B.motorValues_c[i] = (rtNaNF);
      }

      for (i = 0; i < 8; i++) {
        servoValues[i] = (rtNaNF);
      }

      for (i = 0; i < 12; i++) {
        if (Hummingbird_Flight_Controlle_DW.obj.ValidMotorIdx[i]) {
          Hummingbird_Flight_Controller_B.motorValues_c[i] = 0.0F;
        }
      }

      for (i = 0; i < 8; i++) {
        if (Hummingbird_Flight_Controlle_DW.obj.ValidServoIdx[i]) {
          servoValues[i] = 0.0F;
        }
      }

      MW_actuators_set(false, &Hummingbird_Flight_Controller_B.motorValues_c[0],
                       &servoValues[0]);
      MW_actuators_terminate();
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 Actuator Write1'
  Hummingbi_PX4Timestamp_Term(&Hummingbird_Flight_Controlle_DW.PX4Timestamp);

  // Terminate for MATLABSystem: '<S1481>/SinkBlock'
  if (!Hummingbird_Flight_Controlle_DW.obj_j.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Hummingbird_Flight_Controlle_DW.obj_j.isInitialized == 1) &&
        Hummingbird_Flight_Controlle_DW.obj_j.isSetupComplete) {
      uORB_write_terminate
        (&Hummingbird_Flight_Controlle_DW.obj_j.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S1481>/SinkBlock'

  // Terminate for MATLABSystem: '<S1504>/SourceBlock'
  if (!Hummingbird_Flight_Controlle_DW.obj_gv.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_gv.matlabCodegenIsDeleted = true;
    if ((Hummingbird_Flight_Controlle_DW.obj_gv.isInitialized == 1) &&
        Hummingbird_Flight_Controlle_DW.obj_gv.isSetupComplete) {
      uORB_read_terminate(&Hummingbird_Flight_Controlle_DW.obj_gv.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S1504>/SourceBlock'

  // Terminate for MATLABSystem: '<S1491>/Read Parameter'
  if (!Hummingbird_Flight_Controlle_DW.obj_ns.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_ns.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1491>/Read Parameter'

  // Terminate for MATLABSystem: '<S1491>/Read Parameter1'
  if (!Hummingbird_Flight_Controlle_DW.obj_g0.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_g0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1491>/Read Parameter1'

  // Terminate for MATLABSystem: '<S1492>/Read Parameter'
  if (!Hummingbird_Flight_Controlle_DW.obj_er.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_er.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1492>/Read Parameter'

  // Terminate for MATLABSystem: '<S1492>/Read Parameter1'
  if (!Hummingbird_Flight_Controlle_DW.obj_ez.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_ez.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1492>/Read Parameter1'

  // Terminate for MATLABSystem: '<S1493>/Read Parameter'
  if (!Hummingbird_Flight_Controlle_DW.obj_ar.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_ar.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1493>/Read Parameter'

  // Terminate for MATLABSystem: '<S1493>/Read Parameter1'
  if (!Hummingbird_Flight_Controlle_DW.obj_iy.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_iy.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1493>/Read Parameter1'

  // Terminate for MATLABSystem: '<S1494>/Read Parameter'
  if (!Hummingbird_Flight_Controlle_DW.obj_mb.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_mb.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1494>/Read Parameter'

  // Terminate for MATLABSystem: '<S1494>/Read Parameter1'
  if (!Hummingbird_Flight_Controlle_DW.obj_e.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1494>/Read Parameter1'

  // Terminate for MATLABSystem: '<S1495>/Read Parameter'
  if (!Hummingbird_Flight_Controlle_DW.obj_iw.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_iw.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1495>/Read Parameter'

  // Terminate for MATLABSystem: '<S1495>/Read Parameter1'
  if (!Hummingbird_Flight_Controlle_DW.obj_hw.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_hw.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1495>/Read Parameter1'

  // Terminate for MATLABSystem: '<S1496>/Read Parameter'
  if (!Hummingbird_Flight_Controlle_DW.obj_n.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1496>/Read Parameter'

  // Terminate for MATLABSystem: '<S1496>/Read Parameter1'
  if (!Hummingbird_Flight_Controlle_DW.obj_b.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1496>/Read Parameter1'

  // Terminate for MATLABSystem: '<S1497>/Read Parameter'
  if (!Hummingbird_Flight_Controlle_DW.obj_ip.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_ip.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1497>/Read Parameter'

  // Terminate for MATLABSystem: '<S1497>/Read Parameter1'
  if (!Hummingbird_Flight_Controlle_DW.obj_j1.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_j1.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1497>/Read Parameter1'

  // Terminate for MATLABSystem: '<S1498>/Read Parameter'
  if (!Hummingbird_Flight_Controlle_DW.obj_ci.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_ci.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1498>/Read Parameter'

  // Terminate for MATLABSystem: '<S1498>/Read Parameter1'
  if (!Hummingbird_Flight_Controlle_DW.obj_lk.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_lk.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1498>/Read Parameter1'

  // Terminate for MATLABSystem: '<S1499>/Read Parameter'
  if (!Hummingbird_Flight_Controlle_DW.obj_d.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1499>/Read Parameter'

  // Terminate for MATLABSystem: '<S1499>/Read Parameter1'
  if (!Hummingbird_Flight_Controlle_DW.obj_ii.matlabCodegenIsDeleted) {
    Hummingbird_Flight_Controlle_DW.obj_ii.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1499>/Read Parameter1'
}

uint16_T &RT_MODEL_Hummingbird_Flight_C_T::TaskCounter(int32_T idx)
{
  return (Timing.TaskCounters.TID[(idx)]);
}

boolean_T RT_MODEL_Hummingbird_Flight_C_T::StepTask(int32_T idx) const
{
  return (Timing.TaskCounters.TID[(idx)] == 0);
}

const char_T* RT_MODEL_Hummingbird_Flight_C_T::getErrorStatus() const
{
  return (errorStatus);
}

void RT_MODEL_Hummingbird_Flight_C_T::setErrorStatus(const char_T* const
  volatile aErrorStatus)
{
  (errorStatus = aErrorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
