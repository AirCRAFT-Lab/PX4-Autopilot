//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Modular_HITL_data.cpp
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

// Block parameters (default storage)
P_Modular_HITL_T Modular_HITL_P = {
  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S28>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_last_signal
    0,                                 // rssi
    0.0F,                              // rssi_dbm
    0U,                                // rc_lost_frame_count
    0U,                                // rc_total_frame_count
    0U,                                // rc_ppm_frame_length

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // values
    0U,                                // channel_count
    false,                             // rc_failsafe
    false,                             // rc_lost
    0U,                                // input_source
    0,                                 // link_quality
    0U                                 // _padding0
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S27>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_last_signal
    0,                                 // rssi
    0.0F,                              // rssi_dbm
    0U,                                // rc_lost_frame_count
    0U,                                // rc_total_frame_count
    0U,                                // rc_ppm_frame_length

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // values
    0U,                                // channel_count
    false,                             // rc_failsafe
    false,                             // rc_lost
    0U,                                // input_source
    0,                                 // link_quality
    0U                                 // _padding0
  },

  // Computed Parameter: Out1_Y0_m
  //  Referenced by: '<S23>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0U,                                // device_id
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // temperature
    0U,                                // error_count

    {
      0U, 0U, 0U }
    ,                                  // clip_counter
    0U,                                // samples

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S22>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0U,                                // device_id
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // temperature
    0U,                                // error_count

    {
      0U, 0U, 0U }
    ,                                  // clip_counter
    0U,                                // samples

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_c
  //  Referenced by: '<S24>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // yaw_rate
    0.0F,                              // yaw_rate_command
    0.0F,                              // filtered_yaw_rate
    0.0F                               // gain
  },

  // Computed Parameter: Out1_Y0_b
  //  Referenced by: '<S19>/Out1'

  {
    (0ULL),                            // timestamp
    false,                             // armed
    false,                             // prearmed
    false,                             // ready_to_arm
    false,                             // lockdown
    false,                             // manual_lockdown
    false,                             // force_failsafe
    false,                             // in_esc_calibration_mode
    0U                                 // _padding0
  },

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S32>/Out1'

  {
    (0ULL),                            // timestamp
    false,                             // armed
    false,                             // prearmed
    false,                             // ready_to_arm
    false,                             // lockdown
    false,                             // manual_lockdown
    false,                             // force_failsafe
    false,                             // in_esc_calibration_mode
    0U                                 // _padding0
  },

  // Computed Parameter: Constant_Value_f
  //  Referenced by: '<S29>/Constant'

  {
    (0ULL),                            // timestamp
    false,                             // armed
    false,                             // prearmed
    false,                             // ready_to_arm
    false,                             // lockdown
    false,                             // manual_lockdown
    false,                             // force_failsafe
    false,                             // in_esc_calibration_mode
    0U                                 // _padding0
  },

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S16>/Constant'

  {
    (0ULL),                            // timestamp
    false,                             // armed
    false,                             // prearmed
    false,                             // ready_to_arm
    false,                             // lockdown
    false,                             // manual_lockdown
    false,                             // force_failsafe
    false,                             // in_esc_calibration_mode
    0U                                 // _padding0
  },

  // Expression: 0.7
  //  Referenced by: '<S12>/Constant'

  0.7,

  // Expression: 1500
  //  Referenced by: '<S30>/Constant7'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S30>/Gain10'

  0.002,

  // Expression: 1
  //  Referenced by: '<S30>/Saturation'

  1.0,

  // Expression: -0.9
  //  Referenced by: '<S30>/Saturation'

  -0.9,

  // Expression: -1
  //  Referenced by: '<S9>/Constant1'

  -1.0,

  // Expression: 1500
  //  Referenced by: '<S7>/Constant7'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S7>/Gain10'

  0.002,

  // Expression: -1
  //  Referenced by: '<Root>/Gain9'

  -1.0,

  // Expression: 1
  //  Referenced by: '<Root>/Constant'

  1.0,

  // Expression: 1500
  //  Referenced by: '<S6>/Constant7'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S6>/Gain10'

  0.002,

  // Expression: 1000
  //  Referenced by: '<S36>/Constant2'

  1000.0,

  // Expression: 1/1000
  //  Referenced by: '<S36>/Gain2'

  0.001,

  // Expression: 1500
  //  Referenced by: '<S37>/Constant7'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S37>/Gain10'

  0.002,

  // Expression: 0
  //  Referenced by:

  0.0,

  // Expression: 1500
  //  Referenced by: '<S26>/Constant1'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S26>/Gain1'

  0.002,

  // Expression: 1/(pi/6)
  //  Referenced by: '<S10>/Normalize Rudder Command'

  1.9098593171027443,

  // Expression: 1
  //  Referenced by: '<S10>/Saturation'

  1.0,

  // Expression: -1
  //  Referenced by: '<S10>/Saturation'

  -1.0,

  // Expression: -1
  //  Referenced by: '<S2>/Constant2'

  -1.0,

  // Expression: 1500
  //  Referenced by: '<S18>/Constant7'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S18>/Gain10'

  0.002,

  // Expression: 1
  //  Referenced by: '<S18>/Saturation'

  1.0,

  // Expression: -0.9
  //  Referenced by: '<S18>/Saturation'

  -0.9,

  // Expression: 0
  //  Referenced by: '<Root>/Rate Transition2'

  0.0,

  // Expression: [1 0]
  //  Referenced by: '<S5>/Washout Filter'

  { 1.0, 0.0 },

  // Expression: [1 0.25]
  //  Referenced by: '<S5>/Washout Filter'

  { 1.0, 0.25 },

  // Expression: 0
  //  Referenced by: '<S5>/Washout Filter'

  0.0,

  // Computed Parameter: TmpRTBAtProductInport1_InitialC
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_InitialCo
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport3_InitialCo
  //  Referenced by:

  0.0F,

  // Computed Parameter: RateTransition_InitialCondition
  //  Referenced by: '<Root>/Rate Transition'

  0.0F,

  // Computed Parameter: RateTransition3_InitialConditio
  //  Referenced by: '<Root>/Rate Transition3'

  0.0F,

  // Computed Parameter: Gain6_Gain
  //  Referenced by: '<S5>/Gain6'

  -1.0F
};

//
// File trailer for generated code.
//
// [EOF]
//
