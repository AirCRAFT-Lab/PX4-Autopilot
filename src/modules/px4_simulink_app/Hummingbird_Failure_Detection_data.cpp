//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Hummingbird_Failure_Detection_data.cpp
//
// Code generated for Simulink model 'Hummingbird_Failure_Detection'.
//
// Model version                  : 2.287
// Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
// C/C++ source code generated on : Tue Dec  2 21:57:40 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Hummingbird_Failure_Detection.h"

// Block parameters (default storage)
P_Hummingbird_Failure_Detecti_T Hummingbird_Failure_Detection_P = {
  // Variable: IB
  //  Referenced by: '<S1410>/Constant13'

  { 1.4365636849630137, 0.0, 0.21166159010381053, 0.0, 3.3499098651084727, 0.0,
    0.21166159010381053, 0.0, 4.6320009945919063 },

  // Variable: g
  //  Referenced by: '<S22>/Gain3'

  32.174,

  // Variable: m
  //  Referenced by:
  //    '<S497>/Gain5'
  //    '<S729>/Gain5'
  //    '<S1120>/Gain5'

  1.243239883135451,

  // Mask Parameter: PIDController5_D
  //  Referenced by: '<S814>/Derivative Gain'

  0.05,

  // Mask Parameter: PIDController3_D
  //  Referenced by: '<S762>/Derivative Gain'

  0.1,

  // Mask Parameter: PIDController8_D
  //  Referenced by: '<S1043>/Derivative Gain'

  { 0.2, 0.2, 5.0E-5 },

  // Mask Parameter: PIDController9_D
  //  Referenced by: '<S1095>/Derivative Gain'

  { 0.015, 0.015, 0.0 },

  // Mask Parameter: PIDController9_D_d
  //  Referenced by: '<S1385>/Derivative Gain'

  { 0.015, 0.015, 0.0 },

  // Mask Parameter: PIDController_D
  //  Referenced by: '<S1517>/Derivative Gain'

  1.0,

  // Mask Parameter: PIDController3_I
  //  Referenced by: '<S766>/Integral Gain'

  0.0,

  // Mask Parameter: PIDController5_I
  //  Referenced by: '<S818>/Integral Gain'

  0.0,

  // Mask Parameter: PIDController8_I
  //  Referenced by: '<S1047>/Integral Gain'

  0.0,

  // Mask Parameter: PIDController9_I
  //  Referenced by: '<S1099>/Integral Gain'

  { 0.02505936168136361, 0.02505936168136361, 0.05011872336272722 },

  // Mask Parameter: PIDController9_I_i
  //  Referenced by: '<S1389>/Integral Gain'

  { 0.0, 0.0, 0.0 },

  // Mask Parameter: PIDController_InitialConditionF
  //  Referenced by: '<S66>/Filter'

  0.0,

  // Mask Parameter: PIDController1_InitialCondition
  //  Referenced by: '<S118>/Filter'

  0.0,

  // Mask Parameter: PIDController1_InitialConditi_l
  //  Referenced by: '<S238>/Filter'

  0.0,

  // Mask Parameter: PIDController_InitialConditio_a
  //  Referenced by: '<S186>/Filter'

  0.0,

  // Mask Parameter: PIDController1_InitialCondit_lu
  //  Referenced by: '<S416>/Filter'

  0.0,

  // Mask Parameter: PIDController_InitialConditio_g
  //  Referenced by: '<S364>/Filter'

  0.0,

  // Mask Parameter: PIDController3_InitialCondition
  //  Referenced by: '<S530>/Filter'

  0.0,

  // Mask Parameter: PIDController1_InitialConditi_f
  //  Referenced by: '<S644>/Filter'

  0.0,

  // Mask Parameter: PIDController5_InitialCondition
  //  Referenced by: '<S816>/Filter'

  0.0,

  // Mask Parameter: PIDController3_InitialConditi_f
  //  Referenced by: '<S764>/Filter'

  0.0,

  // Mask Parameter: PIDController8_InitialCondition
  //  Referenced by: '<S1045>/Filter'

  0.0,

  // Mask Parameter: PIDController9_InitialCondition
  //  Referenced by: '<S1097>/Filter'

  0.0,

  // Mask Parameter: PIDController3_InitialConditi_g
  //  Referenced by: '<S982>/Filter'

  0.0,

  // Mask Parameter: PIDController3_InitialConditi_m
  //  Referenced by: '<S1155>/Filter'

  0.0,

  // Mask Parameter: PIDController9_InitialConditi_h
  //  Referenced by: '<S1387>/Filter'

  0.0,

  // Mask Parameter: PIDController3_InitialConditi_b
  //  Referenced by: '<S1321>/Filter'

  0.0,

  // Mask Parameter: PIDController_InitialConditi_gy
  //  Referenced by: '<S1519>/Filter'

  0.0,

  // Mask Parameter: PIDController_InitialConditio_p
  //  Referenced by: '<S71>/Integrator'

  0.0,

  // Mask Parameter: PIDController1_InitialConditi_m
  //  Referenced by: '<S123>/Integrator'

  0.0,

  // Mask Parameter: PIDController5_InitialConditi_i
  //  Referenced by: '<S821>/Integrator'

  0.0,

  // Mask Parameter: PIDController3_InitialConditi_a
  //  Referenced by: '<S769>/Integrator'

  0.0,

  // Mask Parameter: PIDController8_InitialConditi_g
  //  Referenced by: '<S1050>/Integrator'

  0.0,

  // Mask Parameter: PIDController9_InitialConditi_i
  //  Referenced by: '<S1102>/Integrator'

  0.0,

  // Mask Parameter: PIDController9_InitialConditi_b
  //  Referenced by: '<S1392>/Integrator'

  0.0,

  // Mask Parameter: PIDController_LowerIntegratorSa
  //  Referenced by: '<S71>/Integrator'

  -0.5,

  // Mask Parameter: PIDController1_LowerIntegratorS
  //  Referenced by: '<S123>/Integrator'

  -2.0,

  // Mask Parameter: PIDController8_LowerIntegratorS
  //  Referenced by: '<S1050>/Integrator'

  -5.0,

  // Mask Parameter: PIDController9_LowerIntegratorS
  //  Referenced by: '<S1102>/Integrator'

  -4.0,

  // Mask Parameter: PIDController9_LowerIntegrato_p
  //  Referenced by: '<S1392>/Integrator'

  -4.0,

  // Mask Parameter: PIDController_LowerSaturationLi
  //  Referenced by: '<S78>/Saturation'

  -5.0,

  // Mask Parameter: PIDController1_LowerSaturationL
  //  Referenced by: '<S130>/Saturation'

  -5.0,

  // Mask Parameter: PIDController5_LowerSaturationL
  //  Referenced by: '<S828>/Saturation'

  -15.0,

  // Mask Parameter: PIDController9_LowerSaturationL
  //  Referenced by: '<S1109>/Saturation'

  -5.0,

  // Mask Parameter: PIDController9_LowerSaturatio_a
  //  Referenced by: '<S1399>/Saturation'

  -5.0,

  // Mask Parameter: PIDController5_N
  //  Referenced by: '<S824>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController3_N
  //  Referenced by: '<S772>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController8_N
  //  Referenced by: '<S1053>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController9_N
  //  Referenced by: '<S1105>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController9_N_j
  //  Referenced by: '<S1395>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController_N
  //  Referenced by: '<S1527>/Filter Coefficient'

  100.0,

  // Mask Parameter: PIDController5_P
  //  Referenced by: '<S826>/Proportional Gain'

  1.0,

  // Mask Parameter: PIDController3_P
  //  Referenced by: '<S774>/Proportional Gain'

  1.0,

  // Mask Parameter: PIDController8_P
  //  Referenced by: '<S1055>/Proportional Gain'

  { 0.21, 0.21, 0.00035 },

  // Mask Parameter: PIDController9_P
  //  Referenced by: '<S1107>/Proportional Gain'

  { 0.60000000000000009, 0.60000000000000009, 0.1 },

  // Mask Parameter: PIDController9_P_b
  //  Referenced by: '<S1397>/Proportional Gain'

  { 0.60000000000000009, 0.60000000000000009, 0.1 },

  // Mask Parameter: PIDController_P
  //  Referenced by: '<S1529>/Proportional Gain'

  0.0,

  // Mask Parameter: PIDController_UpperIntegratorSa
  //  Referenced by: '<S71>/Integrator'

  2.0,

  // Mask Parameter: PIDController1_UpperIntegratorS
  //  Referenced by: '<S123>/Integrator'

  2.0,

  // Mask Parameter: PIDController8_UpperIntegratorS
  //  Referenced by: '<S1050>/Integrator'

  5.0,

  // Mask Parameter: PIDController9_UpperIntegratorS
  //  Referenced by: '<S1102>/Integrator'

  4.0,

  // Mask Parameter: PIDController9_UpperIntegrato_e
  //  Referenced by: '<S1392>/Integrator'

  4.0,

  // Mask Parameter: PIDController_UpperSaturationLi
  //  Referenced by: '<S78>/Saturation'

  5.0,

  // Mask Parameter: PIDController1_UpperSaturationL
  //  Referenced by: '<S130>/Saturation'

  5.0,

  // Mask Parameter: PIDController5_UpperSaturationL
  //  Referenced by: '<S828>/Saturation'

  15.0,

  // Mask Parameter: PIDController9_UpperSaturationL
  //  Referenced by: '<S1109>/Saturation'

  5.0,

  // Mask Parameter: PIDController9_UpperSaturatio_o
  //  Referenced by: '<S1399>/Saturation'

  5.0,

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S1432>/Constant'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // data
    0U,                                // id

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // name

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S1549>/Out1'

  {
    (0ULL),                            // timestamp

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      false,                           // loiter_direction_counter_clockwise
      false,                           // gliding_enabled
      false,                           // disable_weather_vane
      0U                               // _padding0
    },                                 // previous

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      false,                           // loiter_direction_counter_clockwise
      false,                           // gliding_enabled
      false,                           // disable_weather_vane
      0U                               // _padding0
    },                                 // current

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      false,                           // loiter_direction_counter_clockwise
      false,                           // gliding_enabled
      false,                           // disable_weather_vane
      0U                               // _padding0
    }                                  // next
  },

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<S1468>/Constant'

  {
    (0ULL),                            // timestamp

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      false,                           // loiter_direction_counter_clockwise
      false,                           // gliding_enabled
      false,                           // disable_weather_vane
      0U                               // _padding0
    },                                 // previous

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      false,                           // loiter_direction_counter_clockwise
      false,                           // gliding_enabled
      false,                           // disable_weather_vane
      0U                               // _padding0
    },                                 // current

    {
      (0ULL),                          // timestamp
      0.0,                             // lat
      0.0,                             // lon
      0.0F,                            // vx
      0.0F,                            // vy
      0.0F,                            // vz
      0.0F,                            // alt
      0.0F,                            // yaw
      0.0F,                            // yawspeed
      0.0F,                            // loiter_radius
      0.0F,                            // acceptance_radius
      0.0F,                            // cruising_speed
      0.0F,                            // cruising_throttle
      false,                           // valid
      0U,                              // type
      false,                           // yaw_valid
      false,                           // yawspeed_valid
      false,                           // loiter_direction_counter_clockwise
      false,                           // gliding_enabled
      false,                           // disable_weather_vane
      0U                               // _padding0
    }                                  // next
  },

  // Computed Parameter: Out1_Y0_n
  //  Referenced by: '<S1557>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    (0ULL),                            // ref_timestamp
    0.0,                               // ref_lat
    0.0,                               // ref_lon
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F }
    ,                                  // delta_xy
    0.0F,                              // delta_z
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // z_deriv

    {
      0.0F, 0.0F }
    ,                                  // delta_vxy
    0.0F,                              // delta_vz
    0.0F,                              // ax
    0.0F,                              // ay
    0.0F,                              // az
    0.0F,                              // heading
    0.0F,                              // delta_heading
    0.0F,                              // ref_alt
    0.0F,                              // dist_bottom
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // evh
    0.0F,                              // evv
    0.0F,                              // vxy_max
    0.0F,                              // vz_max
    0.0F,                              // hagl_min
    0.0F,                              // hagl_max
    false,                             // xy_valid
    false,                             // z_valid
    false,                             // v_xy_valid
    false,                             // v_z_valid
    0U,                                // xy_reset_counter
    0U,                                // z_reset_counter
    0U,                                // vxy_reset_counter
    0U,                                // vz_reset_counter
    0U,                                // heading_reset_counter
    false,                             // heading_good_for_control
    false,                             // xy_global
    false,                             // z_global
    false,                             // dist_bottom_valid
    0U,                                // dist_bottom_sensor_bitfield
    false,                             // dead_reckoning
    0U                                 // _padding0
  },

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<S1485>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    (0ULL),                            // ref_timestamp
    0.0,                               // ref_lat
    0.0,                               // ref_lon
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F }
    ,                                  // delta_xy
    0.0F,                              // delta_z
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // z_deriv

    {
      0.0F, 0.0F }
    ,                                  // delta_vxy
    0.0F,                              // delta_vz
    0.0F,                              // ax
    0.0F,                              // ay
    0.0F,                              // az
    0.0F,                              // heading
    0.0F,                              // delta_heading
    0.0F,                              // ref_alt
    0.0F,                              // dist_bottom
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // evh
    0.0F,                              // evv
    0.0F,                              // vxy_max
    0.0F,                              // vz_max
    0.0F,                              // hagl_min
    0.0F,                              // hagl_max
    false,                             // xy_valid
    false,                             // z_valid
    false,                             // v_xy_valid
    false,                             // v_z_valid
    0U,                                // xy_reset_counter
    0U,                                // z_reset_counter
    0U,                                // vxy_reset_counter
    0U,                                // vz_reset_counter
    0U,                                // heading_reset_counter
    false,                             // heading_good_for_control
    false,                             // xy_global
    false,                             // z_global
    false,                             // dist_bottom_valid
    0U,                                // dist_bottom_sensor_bitfield
    false,                             // dead_reckoning
    0U                                 // _padding0
  },

  // Computed Parameter: Out1_Y0_ns
  //  Referenced by: '<S1547>/Out1'

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

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S1466>/Constant'

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

  // Computed Parameter: Out1_Y0_g
  //  Referenced by: '<S1556>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0,                               // lat
    0.0,                               // lon
    0.0F,                              // alt
    0.0F,                              // alt_ellipsoid
    0.0F,                              // delta_alt
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // terrain_alt
    0U,                                // lat_lon_reset_counter
    0U,                                // alt_reset_counter
    false,                             // terrain_alt_valid
    false,                             // dead_reckoning

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_k
  //  Referenced by: '<S1484>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0,                               // lat
    0.0,                               // lon
    0.0F,                              // alt
    0.0F,                              // alt_ellipsoid
    0.0F,                              // delta_alt
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // terrain_alt
    0U,                                // lat_lon_reset_counter
    0U,                                // alt_reset_counter
    false,                             // terrain_alt_valid
    false,                             // dead_reckoning

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S27>/Constant'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // prev_waypoint

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // current_waypoint

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // next_waypoint
    0.0F,                              // angle_desired
    0.0F,                              // angle_actual
    0.0F,                              // alpha
    0.0F,                              // as_a
    0.0F                               // as_b
  },

  // Computed Parameter: Out1_Y0_l
  //  Referenced by: '<S1551>/Out1'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    // positions
  },

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S1470>/Constant'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    // positions
  },

  // Computed Parameter: Constant_Value_h
  //  Referenced by: '<S1443>/Constant'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    // positions
  },

  // Computed Parameter: Out1_Y0_k
  //  Referenced by: '<S1554>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // delta_q_reset
    0U,                                // quat_reset_counter

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_e
  //  Referenced by: '<S1482>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // delta_q_reset
    0U,                                // quat_reset_counter

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S1550>/Out1'

  {
    (0ULL),                            // timestamp
    0.0,                               // lat
    0.0,                               // lon
    0.0F,                              // alt
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // yaw
    false,                             // valid_alt
    false,                             // valid_hpos
    false,                             // valid_lpos
    false                              // manual_home
  },

  // Computed Parameter: Constant_Value_p
  //  Referenced by: '<S1469>/Constant'

  {
    (0ULL),                            // timestamp
    0.0,                               // lat
    0.0,                               // lon
    0.0F,                              // alt
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // yaw
    false,                             // valid_alt
    false,                             // valid_hpos
    false,                             // valid_lpos
    false                              // manual_home
  },

  // Computed Parameter: Out1_Y0_c
  //  Referenced by: '<S1487>/Out1'

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

  // Computed Parameter: Constant_Value_bd
  //  Referenced by: '<S1486>/Constant'

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

  // Computed Parameter: Out1_Y0_ds
  //  Referenced by: '<S1555>/Out1'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // gyro_rad
    0U,                                // gyro_integral_dt
    0,                                 // accelerometer_timestamp_relative

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // accelerometer_m_s2
    0U,                                // accelerometer_integral_dt
    0U,                                // accelerometer_clipping
    0U,                                // gyro_clipping
    0U,                                // accel_calibration_count
    0U                                 // gyro_calibration_count
  },

  // Computed Parameter: Constant_Value_os
  //  Referenced by: '<S1483>/Constant'

  {
    (0ULL),                            // timestamp

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // gyro_rad
    0U,                                // gyro_integral_dt
    0,                                 // accelerometer_timestamp_relative

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // accelerometer_m_s2
    0U,                                // accelerometer_integral_dt
    0U,                                // accelerometer_clipping
    0U,                                // gyro_clipping
    0U,                                // accel_calibration_count
    0U                                 // gyro_calibration_count
  },

  // Computed Parameter: Out1_Y0_o
  //  Referenced by: '<S1553>/Out1'

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

  // Computed Parameter: Constant_Value_ht
  //  Referenced by: '<S1472>/Constant'

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

  // Computed Parameter: Constant_Value_bo
  //  Referenced by: '<S143>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // energy
    0.0F,                              // energy_setpoint
    0.0F,                              // energy_setpoint_dot
    0.0F,                              // energy_dot
    0.0F,                              // energy_ratio
    0.0F,                              // energy_ratio_sp
    0.0F,                              // energy_ratio_dot
    0.0F,                              // energy_ratio_setpoint_dot
    0.0F,                              // climb_angle

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_eb
  //  Referenced by: '<S141>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // h_sp
    0.0F,                              // h
    0.0F,                              // climb_angle_sp
    0.0F,                              // climb_angle_ideal
    0.0F,                              // horz_dist
    0.0F,                              // v_sp
    0.0F,                              // v

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_f
  //  Referenced by: '<S1548>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0F,                              // indicated_airspeed_m_s
    0.0F,                              // true_airspeed_m_s
    0.0F,                              // air_temperature_celsius
    0.0F                               // confidence
  },

  // Computed Parameter: Constant_Value_e2
  //  Referenced by: '<S1467>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0F,                              // indicated_airspeed_m_s
    0.0F,                              // true_airspeed_m_s
    0.0F,                              // air_temperature_celsius
    0.0F                               // confidence
  },

  // Computed Parameter: Constant_Value_c
  //  Referenced by: '<S1350>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // name

    {
      0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_m
  //  Referenced by: '<S1544>/Constant'

  {
    (0ULL),                            // timestamp
    0.0,                               // double_a
    0.0,                               // double_b
    0.0F,                              // single_a
    0.0F                               // single_b
  },

  // Computed Parameter: Constant_Value_ay
  //  Referenced by: '<S313>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll
    0.0F,                              // pitch
    0.0F,                              // yaw_rate

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_km
  //  Referenced by: '<S491>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll
    0.0F,                              // pitch
    0.0F,                              // yaw_rate

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_l
  //  Referenced by: '<S719>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll
    0.0F,                              // pitch
    0.0F,                              // yaw_rate

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_p1
  //  Referenced by: '<S1005>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll
    0.0F,                              // pitch
    0.0F,                              // yaw_rate

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_bh
  //  Referenced by: '<S1344>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll
    0.0F,                              // pitch
    0.0F,                              // yaw_rate

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_k2
  //  Referenced by: '<S1430>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // de
    0.0F,                              // dt
    0.0F,                              // da
    0.0F                               // dr
  },

  // Computed Parameter: Out1_Y0_fu
  //  Referenced by: '<S1454>/Out1'

  {
    (0ULL),                            // timestamp
    0.0F,                              // normal
    0.0F,                              // roll_failure
    0.0F,                              // pitch_failure
    0.0F                               // yaw_failure
  },

  // Computed Parameter: Constant_Value_g
  //  Referenced by: '<S1449>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // normal
    0.0F,                              // roll_failure
    0.0F,                              // pitch_failure
    0.0F                               // yaw_failure
  },

  // Computed Parameter: Constant_Value_ou
  //  Referenced by: '<S11>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // normal
    0.0F,                              // roll_failure
    0.0F,                              // pitch_failure
    0.0F                               // yaw_failure
  },

  // Computed Parameter: Constant_Value_hc
  //  Referenced by: '<S1428>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll
    0.0F,                              // pitch
    0.0F,                              // yaw

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_c5
  //  Referenced by: '<S1542>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // p
    0.0F,                              // q
    0.0F,                              // r

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_mw
  //  Referenced by: '<S315>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll_rate
    0.0F,                              // pitch_rate
    0.0F,                              // yaw_rate

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_j
  //  Referenced by: '<S493>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll_rate
    0.0F,                              // pitch_rate
    0.0F,                              // yaw_rate

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_g3
  //  Referenced by: '<S721>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll_rate
    0.0F,                              // pitch_rate
    0.0F,                              // yaw_rate

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_g5
  //  Referenced by: '<S1007>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll_rate
    0.0F,                              // pitch_rate
    0.0F,                              // yaw_rate

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_ib
  //  Referenced by: '<S1346>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll_rate
    0.0F,                              // pitch_rate
    0.0F,                              // yaw_rate

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_f
  //  Referenced by: '<S317>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll_rate_error
    0.0F,                              // pitch_rate_error
    0.0F,                              // yaw_rate_error

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_av
  //  Referenced by: '<S495>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll_rate_error
    0.0F,                              // pitch_rate_error
    0.0F,                              // yaw_rate_error

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_jn
  //  Referenced by: '<S723>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll_rate_error
    0.0F,                              // pitch_rate_error
    0.0F,                              // yaw_rate_error

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_c1
  //  Referenced by: '<S1009>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll_rate_error
    0.0F,                              // pitch_rate_error
    0.0F,                              // yaw_rate_error

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_cm
  //  Referenced by: '<S1348>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // roll_rate_error
    0.0F,                              // pitch_rate_error
    0.0F,                              // yaw_rate_error

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_b
  //  Referenced by: '<S1453>/Out1'

  {
    (0ULL),                            // timestamp
    0.0F,                              // p
    0.0F,                              // q
    0.0F,                              // r

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_k2
  //  Referenced by: '<S1552>/Out1'

  {
    (0ULL),                            // timestamp
    0.0F,                              // p
    0.0F,                              // q
    0.0F,                              // r

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_cc
  //  Referenced by: '<S1471>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // p
    0.0F,                              // q
    0.0F,                              // r

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_ej
  //  Referenced by: '<S1447>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // p
    0.0F,                              // q
    0.0F,                              // r

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_jy
  //  Referenced by: '<S10>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // p
    0.0F,                              // q
    0.0F,                              // r

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_n3
  //  Referenced by: '<S1546>/Out1'

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

  // Computed Parameter: Constant_Value_pi
  //  Referenced by: '<S1465>/Constant'

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

  // Computed Parameter: Out1_Y0_oz
  //  Referenced by: '<S1451>/Out1'

  {
    (0ULL),                            // timestamp
    0U,                                // failure_id

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_ox
  //  Referenced by: '<S1441>/Constant'

  {
    (0ULL),                            // timestamp
    0U,                                // failure_id

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_fj
  //  Referenced by: '<S8>/Constant'

  {
    (0ULL),                            // timestamp
    0U,                                // failure_id

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_go
  //  Referenced by: '<S1452>/Out1'

  {
    (0ULL),                            // timestamp
    0.0F,                              // aoa
    0.0F                               // aos
  },

  // Computed Parameter: Constant_Value_gb
  //  Referenced by: '<S1445>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // aoa
    0.0F                               // aos
  },

  // Computed Parameter: Constant_Value_om
  //  Referenced by: '<S9>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // aoa
    0.0F                               // aos
  },

  // Expression: 0
  //  Referenced by: '<S14>/Constant'

  0.0,

  // Expression: pi/4
  //  Referenced by: '<S22>/Saturation'

  0.78539816339744828,

  // Expression: -pi/4
  //  Referenced by: '<S22>/Saturation'

  -0.78539816339744828,

  // Expression: 0
  //  Referenced by: '<S23>/Constant'

  0.0,

  // Computed Parameter: Filter_gainval
  //  Referenced by: '<S66>/Filter'

  0.001,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S71>/Integrator'

  0.001,

  // Expression: 1
  //  Referenced by: '<S35>/Constant2'

  1.0,

  // Computed Parameter: Filter_gainval_c
  //  Referenced by: '<S118>/Filter'

  0.001,

  // Computed Parameter: Integrator_gainval_k
  //  Referenced by: '<S123>/Integrator'

  0.001,

  // Expression: 1
  //  Referenced by: '<S36>/Constant2'

  1.0,

  // Expression: 15*pi/180
  //  Referenced by: '<S23>/Saturation1'

  0.26179938779914941,

  // Expression: -10*pi/180
  //  Referenced by: '<S23>/Saturation1'

  -0.17453292519943295,

  // Expression: 0
  //  Referenced by: '<S21>/Gain3'

  0.0,

  // Expression: 32.174
  //  Referenced by: '<S21>/Gain4'

  32.174,

  // Computed Parameter: Filter_gainval_j
  //  Referenced by: '<S238>/Filter'

  0.001,

  // Expression: 100
  //  Referenced by: '<S21>/Constant1'

  100.0,

  // Computed Parameter: Filter_gainval_b
  //  Referenced by: '<S186>/Filter'

  0.001,

  // Expression: 100
  //  Referenced by: '<S21>/Constant4'

  100.0,

  // Expression: 0
  //  Referenced by: '<S14>/Constant11'

  0.0,

  // Expression: 0
  //  Referenced by: '<S15>/Constant10'

  0.0,

  // Expression: 0
  //  Referenced by: '<S15>/Constant11'

  0.0,

  // Expression: 1500
  //  Referenced by: '<S328>/Constant7'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S328>/Gain10'

  0.002,

  // Expression: 1
  //  Referenced by: '<S328>/Saturation'

  1.0,

  // Expression: -1
  //  Referenced by: '<S328>/Saturation'

  -1.0,

  // Expression: 60*pi/180
  //  Referenced by: '<S319>/Gain1'

  1.0471975511965976,

  // Expression: 1500
  //  Referenced by: '<S329>/Constant7'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S329>/Gain10'

  0.002,

  // Expression: 1
  //  Referenced by: '<S329>/Saturation'

  1.0,

  // Expression: -1
  //  Referenced by: '<S329>/Saturation'

  -1.0,

  // Expression: 20*pi/180
  //  Referenced by: '<S319>/Gain2'

  0.3490658503988659,

  // Expression: 32.174
  //  Referenced by: '<S319>/Gain4'

  32.174,

  // Expression: 1500
  //  Referenced by: '<S330>/Constant7'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S330>/Gain10'

  0.002,

  // Expression: 1
  //  Referenced by: '<S330>/Saturation'

  1.0,

  // Expression: -1
  //  Referenced by: '<S330>/Saturation'

  -1.0,

  // Expression: 0.2
  //  Referenced by: '<S319>/Gain3'

  0.2,

  // Computed Parameter: Filter_gainval_l
  //  Referenced by: '<S416>/Filter'

  0.001,

  // Expression: 100
  //  Referenced by: '<S319>/Constant1'

  100.0,

  // Computed Parameter: Filter_gainval_bd
  //  Referenced by: '<S364>/Filter'

  0.001,

  // Expression: 100
  //  Referenced by: '<S319>/Constant4'

  100.0,

  // Expression: 0
  //  Referenced by: '<S16>/Constant14'

  0.0,

  // Expression: 100
  //  Referenced by: '<S497>/Constant'

  100.0,

  // Expression: 1500
  //  Referenced by: '<S725>/Constant'

  1500.0,

  // Expression: 5/500
  //  Referenced by: '<S725>/Gain'

  0.01,

  // Computed Parameter: Filter_gainval_d
  //  Referenced by: '<S530>/Filter'

  0.001,

  // Expression: 1500
  //  Referenced by: '<S726>/Constant'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S726>/Gain'

  0.002,

  // Expression: pi/8
  //  Referenced by: '<S499>/Gain1'

  0.39269908169872414,

  // Expression: 15*pi/180
  //  Referenced by: '<S499>/Saturation1'

  0.26179938779914941,

  // Expression: -15*pi/180
  //  Referenced by: '<S499>/Saturation1'

  -0.26179938779914941,

  // Expression: 1500
  //  Referenced by: '<S727>/Constant'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S727>/Gain'

  0.002,

  // Expression: pi/8
  //  Referenced by: '<S499>/Gain2'

  0.39269908169872414,

  // Expression: 15*pi/180
  //  Referenced by: '<S499>/Saturation'

  0.26179938779914941,

  // Expression: -15*pi/180
  //  Referenced by: '<S499>/Saturation'

  -0.26179938779914941,

  // Expression: 1500
  //  Referenced by: '<S728>/Constant'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S728>/Gain'

  0.002,

  // Expression: pi/3
  //  Referenced by: '<S499>/Gain'

  1.0471975511965976,

  // Computed Parameter: Filter_gainval_p
  //  Referenced by: '<S644>/Filter'

  0.001,

  // Expression: 100
  //  Referenced by: '<S498>/Constant1'

  100.0,

  // Expression: 0
  //  Referenced by: '<S17>/Constant10'

  0.0,

  // Computed Parameter: Integrator_gainval_n
  //  Referenced by: '<S821>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval_k
  //  Referenced by: '<S816>/Filter'

  0.001,

  // Computed Parameter: Integrator_gainval_m
  //  Referenced by: '<S769>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval_i
  //  Referenced by: '<S764>/Filter'

  0.001,

  // Computed Parameter: Integrator_gainval_b
  //  Referenced by: '<S1050>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval_e
  //  Referenced by: '<S1045>/Filter'

  0.001,

  // Computed Parameter: Integrator_gainval_m2
  //  Referenced by: '<S1102>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval_lu
  //  Referenced by: '<S1097>/Filter'

  0.001,

  // Expression: 15*pi/180
  //  Referenced by: '<S732>/Saturation1'

  0.26179938779914941,

  // Expression: -15*pi/180
  //  Referenced by: '<S732>/Saturation1'

  -0.26179938779914941,

  // Expression: 15*pi/180
  //  Referenced by: '<S732>/Saturation'

  0.26179938779914941,

  // Expression: -15*pi/180
  //  Referenced by: '<S732>/Saturation'

  -0.26179938779914941,

  // Computed Parameter: Filter_gainval_io
  //  Referenced by: '<S982>/Filter'

  0.001,

  // Expression: 1
  //  Referenced by: '<S731>/Constant4'

  1.0,

  // Expression: 0
  //  Referenced by: '<S18>/Constant14'

  0.0,

  // Expression: 1500
  //  Referenced by: '<S1354>/Constant'

  1500.0,

  // Expression: 5/500
  //  Referenced by: '<S1354>/Gain'

  0.01,

  // Computed Parameter: Filter_gainval_pt
  //  Referenced by: '<S1155>/Filter'

  0.001,

  // Expression: 100
  //  Referenced by: '<S1120>/Constant'

  100.0,

  // Expression: 1500
  //  Referenced by: '<S1357>/Constant'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S1357>/Gain'

  0.002,

  // Expression: pi/3
  //  Referenced by: '<S1124>/Gain'

  1.0471975511965976,

  // Expression: 1500
  //  Referenced by: '<S1356>/Constant'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S1356>/Gain'

  0.002,

  // Expression: 10
  //  Referenced by: '<S1124>/Gain2'

  10.0,

  // Expression: 1500
  //  Referenced by: '<S1355>/Constant'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S1355>/Gain'

  0.002,

  // Expression: 10
  //  Referenced by: '<S1124>/Gain1'

  10.0,

  // Computed Parameter: Integrator_gainval_ma
  //  Referenced by: '<S1392>/Integrator'

  0.001,

  // Computed Parameter: Filter_gainval_kc
  //  Referenced by: '<S1387>/Filter'

  0.001,

  // Expression: 15*pi/180
  //  Referenced by: '<S1124>/Saturation1'

  0.26179938779914941,

  // Expression: -15*pi/180
  //  Referenced by: '<S1124>/Saturation1'

  -0.26179938779914941,

  // Expression: 15*pi/180
  //  Referenced by: '<S1124>/Saturation'

  0.26179938779914941,

  // Expression: -15*pi/180
  //  Referenced by: '<S1124>/Saturation'

  -0.26179938779914941,

  // Computed Parameter: Filter_gainval_o
  //  Referenced by: '<S1321>/Filter'

  0.001,

  // Expression: 100
  //  Referenced by: '<S1122>/Constant4'

  100.0,

  // Expression: 0
  //  Referenced by: '<S19>/Constant'

  0.0,

  // Expression: -120
  //  Referenced by: '<S19>/Constant1'

  -120.0,

  // Expression: [0 0 0]
  //  Referenced by: '<S19>/Constant2'

  { 0.0, 0.0, 0.0 },

  // Expression: 1
  //  Referenced by: '<S1424>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<S1410>/Constant8'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1410>/Constant9'

  0.0,

  // Expression: 1
  //  Referenced by: '<S1410>/Constant29'

  1.0,

  // Expression: 0
  //  Referenced by: '<S1410>/Constant4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1410>/Constant3'

  0.0,

  // Expression: 1000
  //  Referenced by: '<S1419>/Constant7'

  1000.0,

  // Expression: 1/500
  //  Referenced by: '<S1419>/Gain10'

  0.002,

  // Expression: 2
  //  Referenced by: '<S1419>/Saturation'

  2.0,

  // Expression: 0
  //  Referenced by: '<S1419>/Saturation'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1410>/Constant7'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1410>/Memory1'

  0.0,

  // Expression: [1, 1, 1]
  //  Referenced by: '<S1410>/Saturation1'

  { 1.0, 1.0, 1.0 },

  // Expression: [0, 0, 0]
  //  Referenced by: '<S1410>/Saturation1'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S1410>/Switch3'

  0.0,

  // Expression: IBmat(:,:,1,1)
  //  Referenced by: '<S1410>/Constant2'

  { 2.92525710891472, -0.0060651112354350991, 0.2809484711602882,
    -0.0060651112354350991, 4.5510371556052851, -0.0011029437157677353,
    0.2809484711602882, -0.0011029437157677353, 7.2341711388768024 },

  // Expression: 0
  //  Referenced by: '<S1422>/Constant1'

  0.0,

  // Expression: 120
  //  Referenced by: '<S1412>/Saturation3'

  120.0,

  // Expression: 0
  //  Referenced by: '<S1412>/Saturation3'

  0.0,

  // Expression: 8*0.000017484269645*.75
  //  Referenced by: '<S1423>/Constant'

  0.00010490561787000001,

  // Expression: -1
  //  Referenced by: '<S1423>/Gain'

  -1.0,

  // Expression: [0; 0; 0]
  //  Referenced by: '<S1421>/Constant1'

  { 0.0, 0.0, 0.0 },

  // Expression: eye(3)
  //  Referenced by: '<S1410>/Constant12'

  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  // Expression: -8*ly*0.000017484269645
  //  Referenced by: '<S1423>/Constant2'

  -0.00015153033692333332,

  // Expression: -8*0.000017484269645*lx
  //  Referenced by: '<S1423>/Constant1'

  -0.00026809213455666669,

  // Expression: 8*0.000001178991825
  //  Referenced by: '<S1423>/Constant3'

  9.4319346E-6,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1423>/Saturation'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1423>/Saturation'

  0.0,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1423>/Saturation4'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1423>/Saturation4'

  0.0,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1423>/Saturation1'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1423>/Saturation1'

  0.0,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1423>/Saturation5'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1423>/Saturation5'

  0.0,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1423>/Saturation2'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1423>/Saturation2'

  0.0,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1423>/Saturation6'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1423>/Saturation6'

  0.0,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1423>/Saturation3'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1423>/Saturation3'

  0.0,

  // Expression: (10075*pi/30)^2
  //  Referenced by: '<S1423>/Saturation7'

  1.1131337369281398E+6,

  // Expression: 0
  //  Referenced by: '<S1423>/Saturation7'

  0.0,

  // Expression: 1
  //  Referenced by: '<S1412>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<S1410>/Constant14'

  0.0,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1420>/Gain'

  1.3113202233750001E-5,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1420>/Gain8'

  1.3113202233750001E-5,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1420>/Gain1'

  1.3113202233750001E-5,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1420>/Gain2'

  1.3113202233750001E-5,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1420>/Gain3'

  1.3113202233750001E-5,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1420>/Gain9'

  1.3113202233750001E-5,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1420>/Gain10'

  1.3113202233750001E-5,

  // Expression: 0.000017484269645*.75
  //  Referenced by: '<S1420>/Gain11'

  1.3113202233750001E-5,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1420>/Gain4'

  1.178991825E-6,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1420>/Gain12'

  1.178991825E-6,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1420>/Gain5'

  1.178991825E-6,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1420>/Gain13'

  1.178991825E-6,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1420>/Gain6'

  1.178991825E-6,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1420>/Gain14'

  1.178991825E-6,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1420>/Gain7'

  1.178991825E-6,

  // Expression: 0.000001178991825
  //  Referenced by: '<S1420>/Gain15'

  1.178991825E-6,

  // Expression: 1/(10075*pi/30)
  //  Referenced by: '<S1410>/Gain'

  0.00094782100104354552,

  // Expression: [pi/6 2 pi/6 pi/6]
  //  Referenced by: '<S1410>/Saturation'

  { 0.52359877559829882, 2.0, 0.52359877559829882, 0.52359877559829882 },

  // Expression: -[pi/6 0 pi/6 pi/6]
  //  Referenced by: '<S1410>/Saturation'

  { -0.52359877559829882, -0.0, -0.52359877559829882, -0.52359877559829882 },

  // Expression: 1
  //  Referenced by: '<S1410>/Constant'

  1.0,

  // Expression: [0;0;0;0;0;0;0;0]
  //  Referenced by: '<S1411>/Constant1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: -1
  //  Referenced by: '<S1411>/Constant2'

  -1.0,

  // Expression: 1500
  //  Referenced by: '<S1437>/Constant7'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S1437>/Gain10'

  0.002,

  // Expression: 1
  //  Referenced by: '<S1437>/Saturation'

  1.0,

  // Expression: -0.9
  //  Referenced by: '<S1437>/Saturation'

  -0.9,

  // Expression: 1500
  //  Referenced by: '<S1434>/Constant7'

  1500.0,

  // Expression: 1/500
  //  Referenced by: '<S1434>/Gain10'

  0.002,

  // Expression: 1
  //  Referenced by: '<S1434>/Saturation'

  1.0,

  // Expression: -0.9
  //  Referenced by: '<S1434>/Saturation'

  -0.9,

  // Expression: 1500
  //  Referenced by: '<S1435>/Constant7'

  1500.0,

  // Expression: -1/500
  //  Referenced by: '<S1435>/Gain10'

  -0.002,

  // Expression: 1
  //  Referenced by: '<S1435>/Saturation'

  1.0,

  // Expression: -0.9
  //  Referenced by: '<S1435>/Saturation'

  -0.9,

  // Expression: 1500
  //  Referenced by: '<S1436>/Constant7'

  1500.0,

  // Expression: -1/500
  //  Referenced by: '<S1436>/Gain10'

  -0.002,

  // Expression: 1
  //  Referenced by: '<S1436>/Saturation'

  1.0,

  // Expression: -0.9
  //  Referenced by: '<S1436>/Saturation'

  -0.9,

  // Expression: -1
  //  Referenced by: '<S1411>/Constant'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S1460>/Constant1'

  0.0,

  // Expression: 1
  //  Referenced by: '<S1456>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<S1457>/Constant'

  0.0,

  // Expression: 1
  //  Referenced by: '<Root>/Constant7'

  1.0,

  // Expression: 3.28084
  //  Referenced by: '<S13>/Convert To ft//s'

  3.28084,

  // Computed Parameter: Filter_gainval_a
  //  Referenced by: '<S1519>/Filter'

  0.001,

  // Expression: 3.28084
  //  Referenced by: '<S13>/Gain13'

  3.28084,

  // Expression: 1000
  //  Referenced by: '<S1475>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1473>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1474>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1476>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1477>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1478>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1479>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1480>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S1481>/Constant'

  1000.0,

  // Expression: 3.28084
  //  Referenced by: '<S13>/Gain'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S13>/Gain1'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S13>/Gain2'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S13>/Gain3'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S13>/Gain4'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S13>/Gain5'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S13>/Gain6'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S13>/Gain7'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S13>/Gain8'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S13>/Gain12'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S13>/Gain9'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S13>/Gain10'

  3.28084,

  // Expression: 3.28084
  //  Referenced by: '<S13>/Gain11'

  3.28084,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S13>/Discrete-Time Integrator'

  0.001,

  // Expression: 0
  //  Referenced by: '<S13>/Discrete-Time Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S13>/Delay'

  0.0,

  // Expression: 1
  //  Referenced by: '<S13>/Constant2'

  1.0,

  // Expression: 0
  //  Referenced by: '<Root>/Data Store Memory'

  0.0,

  // Computed Parameter: Constant_Value_he
  //  Referenced by: '<S1460>/Constant'

  0,

  // Computed Parameter: Constant_Value_ho0
  //  Referenced by: '<S1458>/Constant'

  1,

  // Computed Parameter: Gain_Gain_h
  //  Referenced by: '<S23>/Gain'

  3.2808F,

  // Computed Parameter: Constant_Value_d
  //  Referenced by: '<S152>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_ic
  //  Referenced by: '<S153>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_lw
  //  Referenced by: '<S327>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_bs
  //  Referenced by: '<S331>/Constant'

  0.0F,

  // Computed Parameter: Constant_Value_jh
  //  Referenced by: '<S18>/Constant'

  0.0F,

  // Computed Parameter: Constant2_Value_p
  //  Referenced by: '<S18>/Constant2'

  0.0F,

  // Expression: ly
  //  Referenced by: '<S1420>/Constant2'

  1.08333337F,

  // Expression: lx
  //  Referenced by: '<S1420>/Constant1'

  1.91666663F,

  // Computed Parameter: Constant5_Value
  //  Referenced by: '<S1410>/Constant5'

  1.0F,

  // Computed Parameter: Gain3_Gain_f
  //  Referenced by: '<S1410>/Gain3'

  1.9098593F,

  // Computed Parameter: Gain2_Gain_cf
  //  Referenced by: '<S1410>/Gain2'

  1.9098593F,

  // Computed Parameter: Gain4_Gain_ki
  //  Referenced by: '<S1410>/Gain4'

  1.9098593F,

  // Computed Parameter: Converttoft1_Gain
  //  Referenced by: '<S13>/Convert to ft1'

  3.28084F,

  // Computed Parameter: Converttoft2_Gain
  //  Referenced by: '<S13>/Convert to ft2'

  3.28084F,

  // Computed Parameter: Converttoft3_Gain
  //  Referenced by: '<S13>/Convert to ft3'

  3.28084F,

  // Computed Parameter: Switch_Threshold
  //  Referenced by: '<S13>/Switch'

  0.0F,

  // Computed Parameter: ConvertTofts1_Gain
  //  Referenced by: '<S13>/Convert To ft//s1'

  3.28084F,

  // Computed Parameter: ConvertTofts3_Gain
  //  Referenced by: '<S13>/Convert To ft//s3'

  3.28084F,

  // Computed Parameter: ConvertTofts4_Gain
  //  Referenced by: '<S13>/Convert To ft//s4'

  3.28084F,

  // Computed Parameter: ConvertTofts5_Gain
  //  Referenced by: '<S13>/Convert To ft//s5'

  3.28084F,

  // Computed Parameter: TmpRTBAtSumInport2_InitialCondi
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_InitialCo
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_gt
  //  Referenced by: '<S1475>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_InitialCon_j
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_Initial_j
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_f
  //  Referenced by: '<S1473>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_InitialCo_jx
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_Initia_jx
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_gl
  //  Referenced by: '<S1474>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_InitialC_jxk
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_Initi_jxk
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_nm
  //  Referenced by: '<S1476>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_Initial_jxkx
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_Init_jxkx
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_dx
  //  Referenced by: '<S1477>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_Initia_jxkxj
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_Ini_jxkxj
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_f1
  //  Referenced by: '<S1478>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_Initi_jxkxj0
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_In_jxkxj0
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_a
  //  Referenced by: '<S1479>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_Init_jxkxj0l
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2_I_jxkxj0l
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_n2
  //  Referenced by: '<S1480>/Gain'

  1000.0F,

  // Computed Parameter: TmpRTBAtSumInport2_Ini_jxkxj0lw
  //  Referenced by:

  0.0F,

  // Computed Parameter: TmpRTBAtDivideInport2__jxkxj0lw
  //  Referenced by:

  0.0F,

  // Computed Parameter: Gain_Gain_gn
  //  Referenced by: '<S1481>/Gain'

  1000.0F,

  // Computed Parameter: Gain_Gain_dj
  //  Referenced by: '<S12>/Gain'

  1.31132019E-5F,

  // Computed Parameter: Gain8_Gain_d
  //  Referenced by: '<S12>/Gain8'

  1.31132019E-5F,

  // Computed Parameter: Gain1_Gain_l
  //  Referenced by: '<S12>/Gain1'

  1.31132019E-5F,

  // Computed Parameter: Gain2_Gain_k
  //  Referenced by: '<S12>/Gain2'

  1.31132019E-5F,

  // Computed Parameter: Gain3_Gain_c0
  //  Referenced by: '<S12>/Gain3'

  1.31132019E-5F,

  // Computed Parameter: Gain9_Gain_g
  //  Referenced by: '<S12>/Gain9'

  1.31132019E-5F,

  // Computed Parameter: Gain10_Gain_l
  //  Referenced by: '<S12>/Gain10'

  1.31132019E-5F,

  // Computed Parameter: Gain11_Gain_c
  //  Referenced by: '<S12>/Gain11'

  1.31132019E-5F,

  // Expression: ly
  //  Referenced by: '<S12>/Constant2'

  1.08333337F,

  // Expression: lx
  //  Referenced by: '<S12>/Constant1'

  1.91666663F,

  // Computed Parameter: Gain4_Gain_o
  //  Referenced by: '<S12>/Gain4'

  1.17899185E-6F,

  // Computed Parameter: Gain12_Gain_j
  //  Referenced by: '<S12>/Gain12'

  1.17899185E-6F,

  // Computed Parameter: Gain5_Gain_o
  //  Referenced by: '<S12>/Gain5'

  1.17899185E-6F,

  // Computed Parameter: Gain13_Gain_k
  //  Referenced by: '<S12>/Gain13'

  1.17899185E-6F,

  // Computed Parameter: Gain6_Gain_m
  //  Referenced by: '<S12>/Gain6'

  1.17899185E-6F,

  // Computed Parameter: Gain14_Gain_o
  //  Referenced by: '<S12>/Gain14'

  1.17899185E-6F,

  // Computed Parameter: Gain7_Gain_i
  //  Referenced by: '<S12>/Gain7'

  1.17899185E-6F,

  // Computed Parameter: Gain15_Gain_f
  //  Referenced by: '<S12>/Gain15'

  1.17899185E-6F,

  // Computed Parameter: Constant_Value_al
  //  Referenced by: '<S13>/Constant'

  { 0.0F, 0.0F, 0.0F, 0.0F },

  // Computed Parameter: UnitDelay_InitialCondition
  //  Referenced by: '<S13>/Unit Delay'

  0.0F,

  // Computed Parameter: Switch5_Threshold
  //  Referenced by: '<S1410>/Switch5'

  1800U,

  // Computed Parameter: Constant15_Value
  //  Referenced by: '<S1410>/Constant15'

  0U,

  // Computed Parameter: Switch6_Threshold
  //  Referenced by: '<S1410>/Switch6'

  1800U,

  // Computed Parameter: Constant3_Value_h
  //  Referenced by: '<S23>/Constant3'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant1_Value_ab
  //  Referenced by: '<S23>/Constant1'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant2_Value_pj
  //  Referenced by: '<S21>/Constant2'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant3_Value_n
  //  Referenced by: '<S21>/Constant3'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant_Value_e4
  //  Referenced by: '<S21>/Constant'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant2_Value_j
  //  Referenced by: '<S319>/Constant2'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant3_Value_c
  //  Referenced by: '<S319>/Constant3'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant_Value_c4q
  //  Referenced by: '<S319>/Constant'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant2_Value_by
  //  Referenced by: '<S498>/Constant2'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant3_Value_i
  //  Referenced by: '<S498>/Constant3'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant_Value_pq
  //  Referenced by: '<S498>/Constant'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant5_Value_d
  //  Referenced by: '<S731>/Constant5'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant6_Value
  //  Referenced by: '<S731>/Constant6'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant1_Value_f
  //  Referenced by: '<S731>/Constant1'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant7_Value_g
  //  Referenced by: '<S18>/Constant7'

  { 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 0U },

  // Computed Parameter: Constant9_Value_c
  //  Referenced by: '<S18>/Constant9'

  { 0U, 0U },

  // Computed Parameter: Constant5_Value_l
  //  Referenced by: '<S1122>/Constant5'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant6_Value_k
  //  Referenced by: '<S1122>/Constant6'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant1_Value_fj
  //  Referenced by: '<S1122>/Constant1'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant6_Value_b
  //  Referenced by: '<S1410>/Constant6'

  { 0U, 0U, 0U, 0U },

  // Computed Parameter: Constant10_Value_n
  //  Referenced by: '<S1410>/Constant10'

  { 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 0U },

  // Computed Parameter: Constant1_Value_abx
  //  Referenced by: '<S1410>/Constant1'

  { 0U, 0U, 0U, 0U }
};

//
// File trailer for generated code.
//
// [EOF]
//
