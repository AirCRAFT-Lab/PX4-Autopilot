/****************************************************************************
 *
 *   Copyright 2024 The MathWorks, Inc.
 *   This file is used to create the added Parameter metadata.
 *
 ****************************************************************************/

/**
 * New group testing parameter 1.
 *
 * To check if it reflects.
 *
 * @min -1000000
 * @max 1000000
 * @group Simulink Module
 */
PARAM_DEFINE_INT32(SL_INT32_PARAM, 0);

/**
 * New group testing parameter 2.
 *
 * To check if it reflects.
 *
 * @min -1000000
 * @max 1000000
 * @group Simulink Module
 */
PARAM_DEFINE_FLOAT(SL_FLOAT_PARAM, 0.0);

/**
 * Proportional Attitude Gain
 *
 * Proportional Attitude Gain
 *
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(ATTITUDE_P_GAIN, 4);

/**
 * Derivative Attitude Gain
 *
 * Derivative Attitude Gain
 *
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(ATTITUDE_D_GAIN, 0.4);

/**
 * Proportional Rate Gain
 *
 * Proportional Rate Gain
 *
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(RATE_P_GAIN, 10);

/**
 * Derivative Rate Gain
 *
 * Derivative Rate Gain
 *
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(RATE_D_GAIN, 0);

/**
 * Proportional Accel Gain
 *
 * Proportional Accel Gain
 *
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(ACCEL_P_GAIN, 1);


/**
 * Derivative gain for throttle
 *
 * Derivative gain to go from energy error to change in throttle command
 *
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(THROTTLE_D_GAIN, 0.0001);

/**
 * Proportional gain for throttle
 *
 * Proportional gain to go from energy error to change in throttle command
 *
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(THROTTLE_P_GAIN, 0.001);

/**
 * Integral gain for throttle
 *
 * Integral gain to go from energy error to change in throttle command
 *
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(THROTTLE_I_GAIN, 0.0002);

/**
 * Feed forward gain for pitch setpoint
 *
 * Feed forward gain for energy ratio adjustment using pitch command
 *
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(PITCH_SP_FF_GAIN, 5);

/**
 * Proportional gain for pitch setpoint
 *
 * Proportional gain for energy ratio adjustment using pitch command
 *
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(PITCH_SP_P_GAIN, 0.2);


/**
 * Energy Ratio Tracking P Gain
 *
 * Energy Ratio Tracking P Gain
 *
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(B_P_GAIN, 0.2);

/**
 * Energy Ratio Tracking D Gain
 *
 * Energy Ratio Tracking D Gain
 *
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(B_D_GAIN, 0.02);

/**
 * Energy Ratio Tracking I Gain
 *
 * Energy Ratio Tracking I Gain
 *
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(B_I_GAIN, 0.002);

/**
 * Multirotor Pitch Proportional Gain
 *
 * Multirotor Pitch Proportional Gain
 *
 * @min 0
 * @max 99999
 * @group Multi Rotor Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(PITCH_P_GAIN, 4);

/**
 * Multirotor Roll Proportional Gain
 *
 * Multirotor Roll Proportional Gain
 *
 * @min 0
 * @max 99999
 * @group Multi Rotor Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(ROLL_P_GAIN, 4);

/**
 * Multirotor Yaw Proportional Gain
 *
 * Multirotor Yaw Proportional Gain
 *
 * @min 0
 * @max 99999
 * @group Multi Rotor Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(YAW_P_GAIN, 4);

/**
 * Multirotor Yaw Derivative Gain
 *
 * Multirotor Yaw Derivative Gain
 *
 * @min 0
 * @max 99999
 * @group Multi Rotor Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(YAW_D_GAIN, 1);

/**
 * Multirotor Roll Derivative Gain
 *
 * Multirotor Roll Derivative Gain
 *
 * @min 0
 * @max 99999
 * @group Multi Rotor Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(ROLL_D_GAIN, 1);

/**
 * Multirotor Pitch Derivative Gain
 *
 * Multirotor Pitch Derivative Gain
 *
 * @min 0
 * @max 99999
 * @group Multi Rotor Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(PITCH_D_GAIN, 1);

/**
 * Multirotor Pitch Rate Proportional Gain
 *
 * Multirotor Pitch Rate Proportional Gain
 *
 * @min 0
 * @max 99999
 * @group Multi Rotor Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(PITCH_R_P_GAIN, 10);

/**
 * Multirotor Roll Rate Proportional Gain
 *
 * Multirotor Roll Rate Proportional Gain
 *
 * @min 0
 * @max 99999
 * @group Multi Rotor Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(ROLL_R_P_GAIN, 10);

/**
 * Multirotor Yaw Rate Proportional Gain
 *
 * Multirotor Yaw Rate Proportional Gain
 *
 * @min 0
 * @max 99999
 * @group Multi Rotor Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(YAW_R_P_GAIN, 10);

/**
 * Alititude Control Proportional Gain
 *
 * Alititude Control Proportional Gain
 *
 * @min 0
 * @max 99999
 * @group Multi Rotor Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(MR_ALT_P_GAIN, 1);

/**
 * Alititude Control Derivative Gain
 *
 * Alititude Control Derivative Gain
 *
 * @min 0
 * @max 99999
 * @group Multi Rotor Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(MR_ALT_D_GAIN, 0.05);

/**
 * Climb Rate Derivative Gain
 *
 * Climb Rate Derivative Gain
 *
 * @min 0
 * @max 99999
 * @group Multi Rotor Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(MR_CR_D_GAIN, 0.1);

/**
 * Climb Rate Propotional Gain
 *
 * Climb Rate Proportional Gain
 *
 * @min 0
 * @max 99999
 * @group Multi Rotor Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(MR_CR_P_GAIN, 1);


/**
 * Change in thrust Gain for Multi Rotor
 *
 * Change in thrust Gain for Multi Rotor
 *
 * @min 0
 * @max 99999
 * @group Multi Rotor Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(MR_DT_GAIN, 0.1);

/**
 * Change in pitching moment Gain for Multi Rotor
 *
 * Change in pitching moment Gain for Multi Rotor
 *
 * @min 0
 * @max 99999
 * @group Multi Rotor Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(MR_DM_PITCH_GAIN, 0.2);

/**
 * Change in rolling moment Gain for Multi Rotor
 *
 * Change in rolling moment Gain for Multi Rotor
 *
 * @min 0
 * @max 99999
 * @group Multi Rotor Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(MR_DM_ROLL_GAIN, 0.2);

/**
 * Change in yawing moment Gain for Multi Rotor
 *
 * Change in yawing moment Gain for Multi Rotor
 *
 * @min 0
 * @max 99999
 * @group Multi Rotor Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(MR_DM_YAW_GAIN, 0.2);

/**
 * Proportional gain for fixed wing pitch control
 *
 * Proportional gain for fixed wing pitch control
 *
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(FW_PITCH_P_GAIN, 4);

/**
 * Derivative gain for fixed wing pitch control
 *
 * Derivative gain for fixed wing pitch control
 *
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(FW_PITCH_D_GAIN, 0.4);

/**
 * Derivative gain for fixed wing roll control
 *
 * Derivative gain for fixed wing roll control
 *
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(FW_ROLL_D_GAIN, 0.4);


/**
 * Proportional gain for fixed wing roll control
 *
 * Proportional gain for fixed wing roll control
 *
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(FW_ROLL_P_GAIN, 4);

/**
 * Proportional gain for fixed wing roll rate control
 *
 * Proportional gain for fixed wing roll rate control
 *
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(FW_ROLL_R_P_GAIN, 10);

/**
 * Proportional gain for fixed wing pitch rate control
 *
 * Proportional gain for fixed wing pitch rate control
 *
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(FW_PITCH_RP_GAIN, 10);

/**
 * Derivative gain for fixed wing pitch rate control
 *
 * Derivative gain for fixed wing pitch rate control
 *
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(FW_PITCH_RD_GAIN, 0);

/**
 * Derivative gain for fixed wing roll rate control
 *
 * Derivative gain for fixed wing roll rate control
 *
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(FW_ROLL_R_D_GAIN, 0);

/**
 * Derivative gain for fixed wing yaw rate control
 *
 * Derivative gain for fixed wing yaw rate control
 *
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(FW_YAW_R_D_GAIN, 0);


/**
 * Proportional gain for fixed wing yaw rate control
 *
 * Proportional gain for fixed wing yaw rate control
 *
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(FW_YAW_R_P_GAIN, 10);

/**
 * Fixed wing gain for DL
 * 
 * Fixed wing gain for change in rolling moment
 * 
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(FW_DL_P_GAIN, 1);

/**
 * Fixed wing gain for DM
 * 
 * Fixed wing gain for change in pitching moment
 * 
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(FW_DM_P_GAIN, 1);

/**
 * Fixed wing gain for DN
 * 
 * Fixed wing gain for change in yawing moment
 * 
 * @min 0
 * @max 99999
 * @group Gains
 * @category Developer
 */
PARAM_DEFINE_FLOAT(FW_DN_P_GAIN, 1);
