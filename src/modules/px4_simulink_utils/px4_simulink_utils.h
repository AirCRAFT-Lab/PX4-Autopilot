/****************************************************************************
 *
 *   Copyright 2024 The MathWorks, Inc.
 *   This file is used to define the added Parameter metadata.
 *
 ****************************************************************************/

#pragma once

#include <px4_platform_common/module.h>
#include <px4_platform_common/module_params.h>
#include <px4_platform_common/getopt.h>
#include <px4_platform_common/log.h>
#include <px4_platform_common/posix.h>

#include <uORB/Subscription.hpp>
#include <uORB/topics/parameter_update.h>
#include <uORB/SubscriptionCallback.hpp>
#include <uORB/topics/sensor_combined.h>

using namespace time_literals;

extern "C" __EXPORT int px4_simulink_utils_main(int argc, char *argv[]);

class PX4SimulinkUtilityModule : public ModuleBase<PX4SimulinkUtilityModule>, public ModuleParams
{
public:
	PX4SimulinkUtilityModule(int example_param, bool example_flag);

	virtual ~PX4SimulinkUtilityModule() = default;

	/** @see ModuleBase */
	static int task_spawn(int argc, char *argv[]);

	/** @see ModuleBase */
	static PX4SimulinkUtilityModule *instantiate(int argc, char *argv[]);

	/** @see ModuleBase */
	static int custom_command(int argc, char *argv[]);

	/** @see ModuleBase */
	static int print_usage(const char *reason = nullptr);

	/** @see ModuleBase::run() */
	void run() override;

	/** @see ModuleBase::print_status() */
	int print_status() override;

private:

	/**
	 * Check for parameter changes and update them if needed.
	 * @param parameter_update_sub uorb subscription to parameter_update
	 * @param force for a parameter update
	 */
	void parameters_update(bool force = false);


	DEFINE_PARAMETERS(
		(ParamFloat<px4::params::FW_DN_P_GAIN>) _param_fw_dn_p_gain,
		(ParamFloat<px4::params::FW_DM_P_GAIN>) _param_fw_dm_p_gain,
		(ParamFloat<px4::params::FW_DL_P_GAIN>) _param_fw_dl_p_gain,
		(ParamFloat<px4::params::FW_YAW_R_P_GAIN>) _param_fw_yaw_r_p_gain,
		(ParamFloat<px4::params::FW_YAW_R_D_GAIN>) _param_fw_yaw_r_d_gain,
		(ParamFloat<px4::params::FW_ROLL_R_D_GAIN>) _param_fw_roll_r_d_gain,
		(ParamFloat<px4::params::FW_PITCH_RD_GAIN>) _param_fw_pitch_rd_gain,
		(ParamFloat<px4::params::FW_PITCH_RP_GAIN>) _param_fw_pitch_rp_gain,
		(ParamFloat<px4::params::FW_ROLL_R_P_GAIN>) _param_fw_roll_r_p_gain,
		(ParamFloat<px4::params::FW_ROLL_P_GAIN>) _param_fw_roll_p_gain,
		(ParamFloat<px4::params::FW_ROLL_D_GAIN>) _param_fw_roll_d_gain,
		(ParamFloat<px4::params::FW_PITCH_D_GAIN>) _param_fw_pitch_d_gain,
		(ParamFloat<px4::params::FW_PITCH_P_GAIN>) _param_fw_pitch_p_gain,
		(ParamFloat<px4::params::MR_DM_YAW_GAIN>) _param_mr_dm_yaw_gain,
		(ParamFloat<px4::params::MR_DM_ROLL_GAIN>) _param_mr_dm_roll_gain,
		(ParamFloat<px4::params::MR_DM_PITCH_GAIN>) _param_mr_dm_pitch_gain,
		(ParamFloat<px4::params::MR_DT_GAIN>) _param_mr_dt_gain,
		(ParamFloat<px4::params::MR_CR_P_GAIN>) _param_mr_cr_p_gain,
		(ParamFloat<px4::params::MR_CR_D_GAIN>) _param_mr_cr_d_gain,
		(ParamFloat<px4::params::MR_ALT_D_GAIN>) _param_mr_alt_d_gain,
		(ParamFloat<px4::params::MR_ALT_P_GAIN>) _param_mr_alt_p_gain,
		(ParamFloat<px4::params::YAW_R_P_GAIN>) _param_yaw_r_p_gain,
		(ParamFloat<px4::params::ROLL_R_P_GAIN>) _param_roll_r_p_gain,
		(ParamFloat<px4::params::PITCH_R_P_GAIN>) _param_pitch_r_p_gain,
		(ParamFloat<px4::params::PITCH_D_GAIN>) _param_pitch_d_gain,
		(ParamFloat<px4::params::ROLL_D_GAIN>) _param_roll_d_gain,
		(ParamFloat<px4::params::YAW_D_GAIN>) _param_yaw_d_gain,
		(ParamFloat<px4::params::YAW_P_GAIN>) _param_yaw_p_gain,
		(ParamFloat<px4::params::ROLL_P_GAIN>) _param_roll_p_gain,
		(ParamFloat<px4::params::PITCH_P_GAIN>) _param_pitch_p_gain,
		(ParamFloat<px4::params::B_I_GAIN>) _param_b_i_gain,
		(ParamFloat<px4::params::B_D_GAIN>) _param_b_d_gain,
		(ParamFloat<px4::params::B_P_GAIN>) _param_b_p_gain,
		(ParamFloat<px4::params::PITCH_SP_P_GAIN>) _param_pitch_sp_p_gain,
		(ParamFloat<px4::params::PITCH_SP_FF_GAIN>) _param_pitch_sp_ff_gain,
		(ParamFloat<px4::params::THROTTLE_I_GAIN>) _param_throttle_i_gain,
		(ParamFloat<px4::params::THROTTLE_P_GAIN>) _param_throttle_p_gain,
		(ParamFloat<px4::params::THROTTLE_D_GAIN>) _param_throttle_d_gain,
		(ParamFloat<px4::params::ACCEL_P_GAIN>) _param_accel_p_gain,
		(ParamFloat<px4::params::RATE_D_GAIN>) _param_rate_d_gain,
		(ParamFloat<px4::params::RATE_P_GAIN>) _param_rate_p_gain,
		(ParamFloat<px4::params::ATTITUDE_D_GAIN>) _param_attitude_d_gain,
		(ParamFloat<px4::params::ATTITUDE_P_GAIN>) _param_attitude_p_gain,
		(ParamFloat<px4::params::SL_FLOAT_PARAM>) _param_sl_float_param,
	        (ParamInt<px4::params::SL_INT32_PARAM>) _param_sl_int32_param
	)

	// Subscriptions
	uORB::SubscriptionInterval _parameter_update_sub{ORB_ID(parameter_update), 1_s};

};

